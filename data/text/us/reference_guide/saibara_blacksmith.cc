#include "reference_guide.hh"

// Reference Guide page 61: Saibara the blacksmith. Fixed field capacities and
// physical order match the US ROM.

char const gText_ReferenceGuide_SaibaraBlacksmith_Title[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "Saibara the blacksmith";

char const gText_ReferenceGuide_SaibaraBlacksmith_Overview_Line01[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·Saibara can upgrade sell,";
char const gText_ReferenceGuide_SaibaraBlacksmith_Overview_Line02[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " or upgrade farm Tools.";
char const gText_ReferenceGuide_SaibaraBlacksmith_Overview_Line03[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " He also sells jewelry and ";
char const gText_ReferenceGuide_SaibaraBlacksmith_Overview_Line04[20] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " various Makers. ";

char const gText_ReferenceGuide_SaibaraBlacksmith_StoreHours_Heading[16] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·Store Hours:";
char const gText_ReferenceGuide_SaibaraBlacksmith_StoreHours_Value[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " 10AM-4PM";
char const gText_ReferenceGuide_SaibaraBlacksmith_ClosedDay_Heading[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·Closed:";
char const gText_ReferenceGuide_SaibaraBlacksmith_ClosedDay_Value[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " Thursdays";

char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Title[20] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "☆Upgrading Tools";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Benefits_Line01[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·When you upgrade Tools, ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Benefits_Line02[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " you will be able to ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Benefits_Line03[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " 'charge' their power by ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Benefits_Line04[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " holding down the button. ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Benefits_Line05[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " By charging Tools, you ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Benefits_Line06[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " can increase their range";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Benefits_Line07[16] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " or strength.";

char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Heading[20] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·To Upgrade Tools";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line01[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " Put the tool you want to ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line02[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " upgrade in your Rucksack";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line03[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " (no need to be equipped),";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line04[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " then put an Ore equivalent";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line05[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " to the level of upgrade ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line06[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " you want in your Rucksack";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line07[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " as well. ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line08[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " Next, talk to Saibara, and";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line09[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " select 'Upgrade Tool' when";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line10[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " he asks what you want. ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line11[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " Next, select Tool to ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line12[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " upgrade and the Ore to do";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line13[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " it with. You won't be able";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line14[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " to use the Tool while it's";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line15[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " being upgraded, so ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line16[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " you must plan well. ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line17[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " Saibara's will be closed ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line18[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " while he's working on your ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line19[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " Tool, and he'll open the ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line20[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " shop again when it's done.";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line21[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " Just talk to him to ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line22[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " receive your Tool. Just";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line23[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " make sure your hands ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line24[16] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " aren't full. ";

char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_EligibleTools_Heading[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·Tools you can upgrade:";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_EligibleTools_Hoe[8] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " Hoe";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_EligibleTools_Scythe[8] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " Scythe";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_EligibleTools_Axe[8] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " Axe";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_EligibleTools_Hammer[8] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " Hammer";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_EligibleTools_WateringCan[16] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " Watering Can";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_EligibleTools_FishingRod[16] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " Fishing Rod";

char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Duration_Line01[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·The number of days ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Duration_Line02[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " required to upgrade a Tool";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Duration_Line03[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " depends on the current ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Duration_Line04[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " level and the level ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Duration_Line05[16] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " upgraded to. ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Duration_Line06[20] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " The greater the ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Duration_Line07[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " difference, the longer ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Duration_Line08[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " required. ";

char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Cost_Line01[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·The upgrade price raises";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Cost_Line02[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " along with the level you";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Cost_Line03[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " want to upgrade to. ";

char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Experience_Line01[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·A Tool's experience level";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Experience_Line02[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " determines whether or not";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Experience_Line03[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " you can upgrade it. ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Experience_Line04[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " Check how high your Tools";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Experience_Line05[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " can be upgraded in the ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Experience_Line06[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " Tool Level List in  ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Experience_Line07[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " Earnings. ";

char const gText_ReferenceGuide_SaibaraBlacksmith_Brush_Title[8] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "☆Brush";
char const gText_ReferenceGuide_SaibaraBlacksmith_Brush_Description_Line01[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·Use to brush Cows, Sheep,";
char const gText_ReferenceGuide_SaibaraBlacksmith_Brush_Description_Line02[16] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " and Horses. ";
char const gText_ReferenceGuide_SaibaraBlacksmith_Milker_Title[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "☆Milker";
char const gText_ReferenceGuide_SaibaraBlacksmith_Milker_Description_Line01[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·Use to milk healthy ";
char const gText_ReferenceGuide_SaibaraBlacksmith_Milker_Description_Line02[16] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " adult Cows. ";
char const gText_ReferenceGuide_SaibaraBlacksmith_Clippers_Title[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "☆Clippers";
char const gText_ReferenceGuide_SaibaraBlacksmith_Clippers_Description_Line02[16] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " adult Sheep. ";
char const gText_ReferenceGuide_SaibaraBlacksmith_AnimalTools_PurchaseLimit_Line01[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·These 3 Tools may be ";
char const gText_ReferenceGuide_SaibaraBlacksmith_AnimalTools_PurchaseLimit_Line02[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " purchased only one ";
char const gText_ReferenceGuide_SaibaraBlacksmith_AnimalTools_PurchaseLimit_Line03[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " at a time.";

char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Bracelet_Title[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "☆Bracelet";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Necklace_Title[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "☆Necklace";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Earrings_Title[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "☆Earrings";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Broach_Title[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "☆Broach";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Gift_Line01[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·These make great gifts";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Gift_Line02[16] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " for girls. ";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Requirements_Line01[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·These cost 1000G, and also";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Requirements_Line02[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " require an Ore called ";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Requirements_Line03[20] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " Orichalc. As with ";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Requirements_Line04[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " upgrading Tools, all you";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Requirements_Line05[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " need to do is put them in ";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Requirements_Line06[20] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " your Rucksack and ";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Requirements_Line07[20] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " approach Saibara. ";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_CompletionTime_Line01[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·Jewelry requires 2 ";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_CompletionTime_Line02[20] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " days to complete. ";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Pickup_Line01[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·The store will be closed";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Pickup_Line02[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " until the jewelry is ";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Pickup_Line03[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " finished. Just talk to him";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Pickup_Line04[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    " to receive your Tool. Just";
