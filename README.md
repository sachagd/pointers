Pointers is a mod that allows item edit trigger to use itemID as pointers

## This mod was only made as a helper for me to make C2gdasm (another project of mine) possible so it's probably not usefull for you.

It adds 3 new boolean properties to the item edit trigger, respectively for the itemID 1, the itemID2 and the target itemID.
To modify the properties, copy an item edit trigger, paste it in some random txt, modify the value of the properties : 0 to disable it and 1 to unable it.
The properties in question are the last three one.

Now whenever the item edit trigger is activated, for each of the properties set to 1, the corresponding itemID that will be used in the operation is the one defined based on the value stored in the itemID specified.
Example : you do item id 1 = item id 2 + item id 3 with the property set to 1 only for the target itemID and let say right before that itemdID 1 = 100 then instead of saving the result in itemID 1, it will save it in itemID 100.  
Example : you do item id 1 = item id 2 + item id 3 with the property set to 1 only for the itemID 1 and let say right before that itemdID 2 = 100 then instead of doing itemid 2 + item id 3, it will do itemid 100 + item id 3.  
