#include "reference_guide.hh"

// Reference Guide page 63: Woodcutter's House. Fixed field capacities and
// physical order match the US ROM.

char const gText_ReferenceGuide_WoodcuttersHouse_Title[20] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "Woodcutter's House";
char const gText_ReferenceGuide_WoodcuttersHouse_Overview_Line01[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·Here you can buy Lumber";
char const gText_ReferenceGuide_WoodcuttersHouse_Overview_Line02[24] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " or ask for expansions.";
char const gText_ReferenceGuide_WoodcuttersHouse_StoreHours_Value[12] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " 11AM-4PM";
char const gText_ReferenceGuide_Saturdays_Value[12] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " Saturdays";

char const gText_ReferenceGuide_WoodcuttersHouse_Lumber_Title[12] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "☆Lumber";
char const gText_ReferenceGuide_WoodcuttersHouse_Lumber_Requirements_Line01[32] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·Lumber as well as gold for";
char const gText_ReferenceGuide_WoodcuttersHouse_Lumber_Requirements_Line02[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " expansions. The amount of";
char const gText_ReferenceGuide_WoodcuttersHouse_Lumber_Requirements_Line03[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " Lumber required depends";
char const gText_ReferenceGuide_WoodcuttersHouse_Lumber_Requirements_Line04[20] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " on the expansion. ";
char const gText_ReferenceGuide_WoodcuttersHouse_Lumber_Delivery_Line01[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·Lumber is shipped to your";
char const gText_ReferenceGuide_WoodcuttersHouse_Lumber_Delivery_Line02[24] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " Wood Bin as soon as ";
char const gText_ReferenceGuide_WoodcuttersHouse_Lumber_Delivery_Line03[16] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " you buy it. ";
char const gText_ReferenceGuide_WoodcuttersHouse_Lumber_Acquisition_Line01[24] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "You can also get Lumber";
char const gText_ReferenceGuide_WoodcuttersHouse_Lumber_Acquisition_Line02[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "by chopping up Branches ";
char const gText_ReferenceGuide_WoodcuttersHouse_Lumber_Acquisition_Line03[16] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "and Stumps. ";

char const gText_ReferenceGuide_WoodcuttersHouse_Expansions_Title[16] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "☆Expansions";
char const gText_ReferenceGuide_WoodcuttersHouse_Expansions_Description_Line01[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·Gotz will begin work on ";
char const gText_ReferenceGuide_WoodcuttersHouse_Expansions_Description_Line02[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " your expansion the day ";
char const gText_ReferenceGuide_WoodcuttersHouse_Expansions_Description_Line03[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " after you ask. You can't ";
char const gText_ReferenceGuide_WoodcuttersHouse_Expansions_Description_Line04[24] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " buy anything from him ";
char const gText_ReferenceGuide_WoodcuttersHouse_Expansions_Description_Line05[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " or ask for more expansions";
char const gText_ReferenceGuide_WoodcuttersHouse_Expansions_Description_Line06[24] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " while he's working. ";

char const gText_ReferenceGuide_WoodcuttersHouse_HomeExpansion_Title[24] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "☆Expanding Your Home";
char const gText_ReferenceGuide_WoodcuttersHouse_HomeExpansion_Description_Line01[32] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·You must expand your house";
char const gText_ReferenceGuide_WoodcuttersHouse_HomeExpansion_Description_Line02[24] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " to make room for a ";
char const gText_ReferenceGuide_WoodcuttersHouse_HomeExpansion_Description_Line03[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " Refrigerator and other ";
char const gText_ReferenceGuide_WoodcuttersHouse_HomeExpansion_Description_Line04[12] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " things. ";
char const gText_ReferenceGuide_WoodcuttersHouse_HomeExpansion_SecondFloor_Line01[24] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·You can also build a ";
char const gText_ReferenceGuide_WoodcuttersHouse_HomeExpansion_SecondFloor_Line02[16] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " second floor. ";
char const gText_ReferenceGuide_WoodcuttersHouse_HomeExpansion_Rebuild_Line01[32] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·After expanding your home ";
char const gText_ReferenceGuide_WoodcuttersHouse_HomeExpansion_Rebuild_Line02[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " twice, you will become ";
char const gText_ReferenceGuide_WoodcuttersHouse_HomeExpansion_Rebuild_Line03[24] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " able to rebuild your ";
char const gText_ReferenceGuide_WoodcuttersHouse_HomeExpansion_Rebuild_Line04[24] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " Window, Doghouse, and ";
char const gText_ReferenceGuide_WoodcuttersHouse_HomeExpansion_Rebuild_Line05[12] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " Mailbox.";

char const gText_ReferenceGuide_WoodcuttersHouse_ChickenCoopExpansion_Title[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "☆Expanding Chicken Coop";
char const gText_ReferenceGuide_WoodcuttersHouse_ChickenCoopExpansion_Capacity_Line01[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·Enables you to care for ";
char const gText_ReferenceGuide_WoodcuttersHouse_ChickenCoopExpansion_Capacity_Line02[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " 8 Chickens, up from 4. ";
char const gText_ReferenceGuide_WoodcuttersHouse_ChickenCoopExpansion_Incubators_Line01[24] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·Enables you to buy 2 ";
char const gText_ReferenceGuide_WoodcuttersHouse_ChickenCoopExpansion_Incubators_Line02[16] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " Incubators.";
char const gText_ReferenceGuide_WoodcuttersHouse_ChickenCoopExpansion_MayonnaiseMaker_Line01[24] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·Enables you to buy a ";
char const gText_ReferenceGuide_WoodcuttersHouse_ChickenCoopExpansion_MayonnaiseMaker_Line02[20] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " Mayonnaise Maker.";

char const gText_ReferenceGuide_WoodcuttersHouse_BarnExpansion_Title[24] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "☆Expanding Your Barn";
char const gText_ReferenceGuide_WoodcuttersHouse_BarnExpansion_Capacity_Line01[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·Enables you to care for";
char const gText_ReferenceGuide_WoodcuttersHouse_BarnExpansion_Capacity_Line02[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " 16 Cows and Sheep total,";
char const gText_ReferenceGuide_WoodcuttersHouse_BarnExpansion_Capacity_Line03[16] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " up from 8. ";
char const gText_ReferenceGuide_WoodcuttersHouse_BarnExpansion_PregnancySpace_Line01[24] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·Expands space for 2 ";
char const gText_ReferenceGuide_WoodcuttersHouse_BarnExpansion_PregnancySpace_Line02[20] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " pregnant animals, ";
char const gText_ReferenceGuide_WoodcuttersHouse_BarnExpansion_PregnancySpace_Line03[16] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " up from 1. ";
char const gText_ReferenceGuide_WoodcuttersHouse_BarnExpansion_Makers_Line02[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    " Cheese or a Yarn Maker.";

char const gText_ReferenceGuide_WoodcuttersHouse_Cottage_Title[20] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "☆Build a Cottage";
char const gText_ReferenceGuide_WoodcuttersHouse_Cottage_Description_Line01[28] SECTION(".rodata.reference_guide_woodcutters_house_text") =
    "·Build a Cottage in town.";
