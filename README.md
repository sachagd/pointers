Pointers is a mod that allows item edit trigger and spawn trigger to use itemID as pointers

## This mod was only made as a helper for me to make C2gdasm (another project of mine) possible so it's probably not usefull for you.

### Item edit trigger : 
    It adds 3 new boolean properties to the item edit trigger, respectively for the itemID 1, the itemID2 and the target itemID.
    To modify the properties, copy an item edit trigger, paste it in some random txt, modify the value of the properties : 0 to disable it and 1 to unable it. By default, the properties are set to 0 meaning it will behave exactly like vanilla GD.
    The properties in question are the last three one : 241, 242 and 243

    Now whenever the item edit trigger is activated, for each of the properties set to 1, the corresponding itemID that will be used in the operation is the one defined based on the value stored in the itemID specified.
    Here the operation will be "target itemID = itemID 1 + itemID 2"

    Example : you do item id 1 = item id 2 + item id 3 with the property set to 1 only for the target itemID and let say right before that itemdID 1 = 100 then instead of saving the result in itemID 1, it will save it in itemID 100.  
    Example : you do item id 1 = item id 2 + item id 3 with the property set to 1 only for the itemID 1 and let say right before that itemdID 2 = 100 then instead of doing itemid 2 + item id 3, it will do itemid 100 + item id 3.  

### Spawn trigger : 
    It adds a new boolean property to the spawn trigger
    To modify the property, copy a spawn trigger, paste it in some random txt, modify the value of the property : 0 to disable it and 1 to unable it. By default, the property is set to 0 meaning it will behave exactly like vanilla GD.
    The property in question is the last one : 244

    Now whenever the spawn is activated, if the property is set to 1, instead of activating some group "n", it will look for the value inside item id n, let say "m" and spawn group m. Like the value stored inside the spawn trigger will be interpreted as an item id and proceed based on that.

    Example : a spawn trigger set with value 10 with the property set to 1 and let say right before that item id 10 = 50 then instead of spawning group id 10 it will spawn group id 50