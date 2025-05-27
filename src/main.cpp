#include <Geode/Geode.hpp>
#include <Geode/modify/ItemTriggerGameObject.hpp>
#include <Geode/Bindings.hpp>

using namespace geode::prelude;

// ---------------------------------------------------------------------------
// Extend ItemTriggerGameObject with three boolean flags.
// ---------------------------------------------------------------------------
class $modify(ItemTriggerGameObject) {
public:
    struct Fields {
        bool m_ptrID1 = false;   // pointer mode for ItemID 1
        bool m_ptrID2 = false;   // pointer mode for ItemID 2
        bool m_ptrOut = false;   // pointer mode for Target ItemID
    };

      int resolveID(int rawID, bool ptr, GJEffectManager* mgr) {
        return ptr ? mgr->countForItem(rawID) : rawID;
    }

    void triggerObject(
        GJBaseGameLayer*          layer,
        int                       unk1,
        gd::vector<int> const*    unk2
    ) override {
        int orig1   = this->m_itemID;
        int orig2   = this->m_itemID2;
        int origOut = this->m_targetGroupID;

        auto mgr = layer->m_effectManager;
        int real1 = resolveID(orig1,   m_fields->m_ptrID1, mgr);
        int real2 = resolveID(orig2,   m_fields->m_ptrID2, mgr);
        int realOut= resolveID(origOut, m_fields->m_ptrOut,  mgr);

        this->m_itemID         = real1;
        this->m_itemID2          = real2;
        this->m_targetGroupID  = realOut;

        ItemTriggerGameObject::triggerObject(layer, unk1, unk2);

        this->m_itemID         = orig1;
        this->m_itemID2          = orig2;
        this->m_targetGroupID  = origOut;
    }


    // IDs we’ll use inside the save-string
    static constexpr int kPtrID1  = 241;
    static constexpr int kPtrID2  = 242;
    static constexpr int kPtrOut  = 243;

    // -----------------------------------------------------------------------
    // 1. save → string  (add our 3 key/value pairs to the end)
    // -----------------------------------------------------------------------
    gd::string getSaveString(GJBaseGameLayer* layer) override {
        log::info("getSaveString");
        gd::string out = ItemTriggerGameObject::getSaveString(layer);

        auto add = [&](int key, bool value) {
            out += "," + std::to_string(key) + "," +
                   std::to_string(value ? 1 : 0);
        };
        add(kPtrID1,  m_fields->m_ptrID1);
        add(kPtrID2,  m_fields->m_ptrID2);
        add(kPtrOut,  m_fields->m_ptrOut);

        return out; 
    }

    // -----------------------------------------------------------------------
    // 2. string → object  (read & remove our tokens, then call vanilla)
    // -----------------------------------------------------------------------
    void customObjectSetup(gd::vector<gd::string>& params,
                        gd::vector<void*>&      extra) override
    {
        auto getBool = [&](size_t key) -> bool {
            return !params[key].empty() && std::stoi(params[key]) != 0;
        };

        m_fields->m_ptrID1 = getBool(kPtrID1);   // 241
        m_fields->m_ptrID2 = getBool(kPtrID2);   // 242
        m_fields->m_ptrOut = getBool(kPtrOut);   // 243

        // wipe them so vanilla doesn’t revisit
        params[kPtrID1].clear();
        params[kPtrID2].clear();
        params[kPtrOut].clear();

        ItemTriggerGameObject::customObjectSetup(params, extra);
    }
};
