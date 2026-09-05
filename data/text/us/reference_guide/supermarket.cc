#include "reference_guide.hh"

// Reference Guide page 62: Supermarket. Fixed field capacities and physical
// order match the US ROM.

char const gText_ReferenceGuide_Supermarket_Title[12] SECTION(".rodata.reference_guide_supermarket_text") =
    "Supermarket";

char const gText_ReferenceGuide_Supermarket_Overview_Line01[28] SECTION(".rodata.reference_guide_supermarket_text") =
    "·The Supermarket sells ";
char const gText_ReferenceGuide_Supermarket_Overview_Line02[24] SECTION(".rodata.reference_guide_supermarket_text") =
    " Seeds, Ingredients for";
char const gText_ReferenceGuide_Supermarket_Overview_Line03[28] SECTION(".rodata.reference_guide_supermarket_text") =
    " cooking, and Baskets and ";
char const gText_ReferenceGuide_Supermarket_Overview_Line04[28] SECTION(".rodata.reference_guide_supermarket_text") =
    " Rucksacks for carrying ";
char const gText_ReferenceGuide_Supermarket_Overview_Line05[28] SECTION(".rodata.reference_guide_supermarket_text") =
    " things. You can also have";
char const gText_ReferenceGuide_Supermarket_Overview_Line06[28] SECTION(".rodata.reference_guide_supermarket_text") =
    " presents wrapped here. ";

char const gText_ReferenceGuide_Supermarket_StoreHours_Value[12] SECTION(".rodata.reference_guide_supermarket_text") =
    " 9AM-5PM";
char const gText_ReferenceGuide_Supermarket_ClosedDay_Value[20] SECTION(".rodata.reference_guide_supermarket_text") =
    " Tuesdays & Sundays";

char const gText_ReferenceGuide_Seeds_Title[8] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆Seeds";
char const gText_ReferenceGuide_SeedPlantingInstructions_Line01[28] SECTION(".rodata.reference_guide_supermarket_text") =
    "·Plant Seeds on tilled ";
char const gText_ReferenceGuide_SeedPlantingInstructions_Line02[28] SECTION(".rodata.reference_guide_supermarket_text") =
    " earth, then water them ";
char const gText_ReferenceGuide_SeedPlantingInstructions_Line03[28] SECTION(".rodata.reference_guide_supermarket_text") =
    " every day to grow crops.";
char const gText_ReferenceGuide_SeedPlantingInstructions_Line04[28] SECTION(".rodata.reference_guide_supermarket_text") =
    " Be careful, some crops ";
char const gText_ReferenceGuide_SeedPlantingInstructions_Line05[28] SECTION(".rodata.reference_guide_supermarket_text") =
    " only grow in some seasons.";
char const gText_ReferenceGuide_SeedSalesSeasonalAvailability_Line01[28] SECTION(".rodata.reference_guide_supermarket_text") =
    "·Some Seeds are only sold";
char const gText_ReferenceGuide_SeedSalesSeasonalAvailability_Line02[16] SECTION(".rodata.reference_guide_supermarket_text") =
    " seasonally. ";

char const gText_ReferenceGuide_Supermarket_Ingredients_Heading[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "·Here are some Ingredients:";
char const gText_ReferenceGuide_Supermarket_Ingredients_RiceBall_Title[12] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆Rice Ball";
char const gText_ReferenceGuide_Supermarket_Ingredients_Bread_Title[8] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆Bread";
char const gText_ReferenceGuide_Supermarket_Ingredients_Oil_Title[8] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆Oil";
char const gText_ReferenceGuide_Supermarket_Ingredients_Flour_Title[8] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆Flour";
char const gText_ReferenceGuide_Supermarket_Ingredients_CurryPowder_Title[16] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆Curry Powder";
char const gText_ReferenceGuide_Supermarket_Ingredients_Chocolate_Title[12] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆Chocolate";
char const gText_ReferenceGuide_Supermarket_Ingredients_EatDirectly_Line01[28] SECTION(".rodata.reference_guide_supermarket_text") =
    "·You can also eat these";
char const gText_ReferenceGuide_Supermarket_Ingredients_EatDirectly_Line02[28] SECTION(".rodata.reference_guide_supermarket_text") =
    " straight, without cooking";
char const gText_ReferenceGuide_Supermarket_Ingredients_EatDirectly_Line03[8] SECTION(".rodata.reference_guide_supermarket_text") =
    " them. ";
char const gText_ReferenceGuide_RefrigeratorPurchases_Line01[28] SECTION(".rodata.reference_guide_supermarket_text") =
    "·You can buy more at one";
char const gText_ReferenceGuide_RefrigeratorPurchases_Line02[24] SECTION(".rodata.reference_guide_supermarket_text") =
    " time if you have a ";
char const gText_ReferenceGuide_Supermarket_Ingredients_Refrigerator_Line03[16] SECTION(".rodata.reference_guide_supermarket_text") =
    " Refrigerator. ";
char const gText_ReferenceGuide_Supermarket_Ingredients_SeasonalAvailability_Line01[24] SECTION(".rodata.reference_guide_supermarket_text") =
    "·Some Ingredients are ";
char const gText_ReferenceGuide_Supermarket_Ingredients_SeasonalAvailability_Line02[24] SECTION(".rodata.reference_guide_supermarket_text") =
    " only sold seasonally.";

char const gText_ReferenceGuide_Supermarket_Basket_Title[12] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆Basket";
char const gText_ReferenceGuide_Supermarket_Basket_Description_Line01[28] SECTION(".rodata.reference_guide_supermarket_text") =
    "·Place up to 30 Items in ";
char const gText_ReferenceGuide_Supermarket_Basket_Description_Line02[24] SECTION(".rodata.reference_guide_supermarket_text") =
    " here to be shipped. ";
char const gText_ReferenceGuide_Supermarket_Basket_Description_Line03[24] SECTION(".rodata.reference_guide_supermarket_text") =
    " Once you put Items in,";
char const gText_ReferenceGuide_Supermarket_Basket_Description_Line04[24] SECTION(".rodata.reference_guide_supermarket_text") =
    " you cannot take them ";
char const gText_ReferenceGuide_Supermarket_Basket_Description_Line05[16] SECTION(".rodata.reference_guide_supermarket_text") =
    " out again. ";
char const gText_ReferenceGuide_Supermarket_Basket_Purchase_Line01[28] SECTION(".rodata.reference_guide_supermarket_text") =
    "·You cannot buy anything";
char const gText_ReferenceGuide_Supermarket_Basket_Purchase_Line02[24] SECTION(".rodata.reference_guide_supermarket_text") =
    " when you are holding ";
char const gText_ReferenceGuide_Supermarket_Basket_Purchase_Line03[28] SECTION(".rodata.reference_guide_supermarket_text") =
    " something, since you need";
char const gText_ReferenceGuide_Supermarket_Basket_Purchase_Line04[24] SECTION(".rodata.reference_guide_supermarket_text") =
    " your hand to hold it.";

char const gText_ReferenceGuide_Supermarket_Rucksack_Title[12] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆Rucksack";
char const gText_ReferenceGuide_Supermarket_Rucksack_Description_Line01[24] SECTION(".rodata.reference_guide_supermarket_text") =
    "·Allows you to equip ";
char const gText_ReferenceGuide_Supermarket_Rucksack_Description_Line02[28] SECTION(".rodata.reference_guide_supermarket_text") =
    " 4 Items and hold 1 Item. ";
char const gText_ReferenceGuide_Supermarket_LargeRucksack_Title[20] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆Large Rucksack";
char const gText_ReferenceGuide_Supermarket_LargeRucksack_Description_Line02[28] SECTION(".rodata.reference_guide_supermarket_text") =
    " 8 Items and hold 1 Item.";
char const gText_ReferenceGuide_Supermarket_LargeRucksack_Requirements_Line01[24] SECTION(".rodata.reference_guide_supermarket_text") =
    "·You need to have a";
char const gText_ReferenceGuide_Supermarket_LargeRucksack_Requirements_Line02[28] SECTION(".rodata.reference_guide_supermarket_text") =
    " Rucksack before a Large";
char const gText_ReferenceGuide_Supermarket_LargeRucksack_Requirements_Line03[28] SECTION(".rodata.reference_guide_supermarket_text") =
    " Rucksack goes on sale. ";
char const gText_ReferenceGuide_Supermarket_LargeRucksack_ImmediateUse_Line01[28] SECTION(".rodata.reference_guide_supermarket_text") =
    "·Used immediately when ";
char const gText_ReferenceGuide_Supermarket_LargeRucksack_ImmediateUse_Line02[28] SECTION(".rodata.reference_guide_supermarket_text") =
    " bought, so you may have ";
char const gText_ReferenceGuide_Supermarket_LargeRucksack_ImmediateUse_Line03[24] SECTION(".rodata.reference_guide_supermarket_text") =
    " other Tools equipped ";
char const gText_ReferenceGuide_Supermarket_LargeRucksack_ImmediateUse_Line04[20] SECTION(".rodata.reference_guide_supermarket_text") =
    " when you buy it.";

char const gText_ReferenceGuide_Supermarket_BlueFeather_Title[16] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆Blue Feather";
char const gText_ReferenceGuide_Supermarket_BlueFeather_Description_Line01[28] SECTION(".rodata.reference_guide_supermarket_text") =
    "·Use to propose to girls.";
char const gText_ReferenceGuide_Supermarket_BlueFeather_Availability_Line01[28] SECTION(".rodata.reference_guide_supermarket_text") =
    "·Only goes on sale when ";
char const gText_ReferenceGuide_Supermarket_BlueFeather_Availability_Line02[28] SECTION(".rodata.reference_guide_supermarket_text") =
    " there's a girl who will";
char const gText_ReferenceGuide_Supermarket_BlueFeather_Availability_Line03[24] SECTION(".rodata.reference_guide_supermarket_text") =
    " accept your proposal. ";
char const gText_ReferenceGuide_Supermarket_BlueFeather_Classification_Line01[24] SECTION(".rodata.reference_guide_supermarket_text") =
    "·Considered a Tool.";

char const gText_ReferenceGuide_Supermarket_GiftWrapping_Title[16] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆Gift Wrapping";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_Description_Line01[28] SECTION(".rodata.reference_guide_supermarket_text") =
    "·People will appreciate ";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_Description_Line02[28] SECTION(".rodata.reference_guide_supermarket_text") =
    " gifts even more when they";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_Description_Line03[24] SECTION(".rodata.reference_guide_supermarket_text") =
    " are wrapped. However, ";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_Description_Line04[28] SECTION(".rodata.reference_guide_supermarket_text") =
    " people will hate it even";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_Description_Line05[28] SECTION(".rodata.reference_guide_supermarket_text") =
    " more when you give them ";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_Description_Line06[28] SECTION(".rodata.reference_guide_supermarket_text") =
    " things they don't like ";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_Description_Line07[16] SECTION(".rodata.reference_guide_supermarket_text") =
    " gift wrapped. ";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_EligibleItems_Line01[24] SECTION(".rodata.reference_guide_supermarket_text") =
    "·Any Item that may be ";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_EligibleItems_Line02[24] SECTION(".rodata.reference_guide_supermarket_text") =
    " given to a person may";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_EligibleItems_Line03[16] SECTION(".rodata.reference_guide_supermarket_text") =
    " be wrapped.";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_Removal_Line01[28] SECTION(".rodata.reference_guide_supermarket_text") =
    "·Gift wrapping comes off ";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_Removal_Line02[28] SECTION(".rodata.reference_guide_supermarket_text") =
    " when Items are placed in ";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_Removal_Line03[28] SECTION(".rodata.reference_guide_supermarket_text") =
    " a Refrigerator or Shelves,";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_Removal_Line04[20] SECTION(".rodata.reference_guide_supermarket_text") =
    " so be careful. ";
