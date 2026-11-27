#ifndef SCENE_COOKING_HH
#define SCENE_COOKING_HH

#include "scene.hh"
#include "fomt_constants.hh"

#include "game_menu.hh"
#include "cooking_recipe_types.hh"
#include "rucksack_item.hh"
#include "obj_palette_pool.hh"
#include "obj_tile_pool.hh"
#include "ui_state.hh"
struct CookingSceneCore;

struct CookingSceneCoreOwner {
    explicit CookingSceneCoreOwner(CookingSceneCore * input) : value(input) {}
    ~CookingSceneCoreOwner();
    CookingSceneCore * value;
};

#pragma interface "scene_cooking.hh"



#pragma interface "scene_cooking.hh"
struct CookingScene : AScene {
    CookingScene(SceneTransitionOwner next, GameStateSaveImage * image, u8 show_recipes);
    virtual ~CookingScene();
    virtual SceneTransitionOwner Run();

    CookingSceneCoreOwner core;
    SceneTransitionOwner continuation;
};

// Supplies the cooking result's item name and recovery descriptions to the
// dialogue renderer. The item code is food index + 1 or article index + 0xAC.
#pragma interface "scene_cooking.hh"
struct CookingTextVariables : ScriptTextVariableStore {
    virtual ~CookingTextVariables() {}
    virtual inline UiTextSubstitution Lookup(u32 code);

    u16 item_code;
    u8 stamina_description;
    u8 fatigue_description;
};


#pragma interface "scene_cooking.hh"

// The seven native sprite records have a 0x38-byte stride. The word at
// +0x30 is not initialized by the constructor; its purpose remains unknown.
struct CookingSpriteState {
    IndexedResourceHandle resource;
    IndexedResourceSpriteParameters parameters;
    u32 unk_30;
    u8 unk_34;
};

// Each recipe row keeps twenty by two 4bpp tiles after an unknown word.
struct CookingRecipeLabelTiles {
    u32 unk_00;
    u32 tiles[20 * 2 * 8];
};

struct CookingSceneCore : GameSceneMenuCorePrefix {
    CookingSceneCore(GameStateSaveImage * image, u8 show_recipes);
    // The implicit virtual destructor releases the actual owned members.
    SceneTransitionOwner Run();

    GameStateSaveImage * image;
    HardwareMusicPlayerSlot music_players[2];
    IndexedResourceArchive archive_98;
    IndexedResourceArchive hand_cursor_archive;
    IndexedResourceArchive archive_F8;
    IndexedResourceArchive archive_128;
    CookingSpriteState sprites[7];
    ObjTileCollectionEntry tiles_2E0;
    ObjPaletteCollectionEntry palette_2E8;
    ObjTileCollectionEntry tiles_2F0;
    ObjPaletteCollectionEntry palette_2F8;
    ObjTileCollectionEntry tiles_300;
    ObjPaletteCollectionEntry palette_308;
    ObjTileCollectionEntry tiles_310;
    ObjTileCollectionEntry tiles_318;
    ObjPaletteCollectionEntry palette_320;
    ObjTileCollectionEntry tiles_328;
    u16 owned_utensils;
    CookingRecipeRecord recipe_334;
    CookingRecipeRecord recipe_348;
    u8 unk_35C;
    u8 unk_35D;
    u8 show_recipes;
    i16 cursor_x;
    i16 cursor_y;
    u8 selected_recipe_row;
    u8 last_recipe_row;
    u8 recipe_page;
    u8 last_recipe_page;
    u8 recipe_count;
    u8 page_glyphs[5];
    CookingRecipeLabelTiles recipe_labels[8];
    // Zero selects the rucksack; 1..8 select refrigerator pages.
    u8 ingredient_page;
    // Runtime RAM between two verified fields. No use has yet established
    // the internal types; this is not ROM padding or freely reusable space.
    u8 unk_2B91[15];
    u32 rucksack_capacity;
    u8 selectable_rows[3];
    u8 selected_slots[9];
    RucksackItem ingredients[8];
    u16 tilemap[32][32];
    i16 phase;
    i8 dialogue_phase;
    u8 dialogue_choice;
    i16 dialogue_id;
    CookingTextVariables text_variables;
};


#pragma interface "scene_cooking.hh"

#pragma interface "scene_cooking.hh"


EXTERN_C

// The recipe screen indexes all eight utensil flags.
extern char const gText_Cooking_Recipe_PageBreak[];
extern u16 const gCookingRecipeInventoryUtensilValues[8];

// Direct reference to the actual GCC 2.9 continuation-slot constructor ABI.
CookingScene * __12CookingSceneG20SceneTransitionOwnerP18GameStateSaveImageUc(
    void * object, SceneTransition ** next, GameStateSaveImage * image, u8 show_recipes);

EXTERN_C_END

#pragma interface "scene_cooking.hh"


// The native formatter indexes these fixed 29-byte recovery descriptions.
extern char const gText_StaminaRecoveryStatus[9][29];
extern char const gText_FatigueRecoveryStatus[18][29];

extern char const gText_Cooking_SeasoningSet[];
extern char const gText_Cooking_CompleteUtensilSelection[];
extern char const gText_Cooking_WrappedGiftDescription[];
extern char const gText_Cooking_FollowRecipe[];
extern char const gText_Cooking_ImproviseRecipe[];
extern char const gText_Cooking_MakeAnotherRecipe[];
extern char const gText_Cooking_NotEnoughIngredients[];
extern char const gText_Cooking_UseTheseIngredients[];
extern char const gText_Cooking_RestartIngredients[];
extern char const gText_Cooking_RestartUtensils[];
extern char const gText_Cooking_Recipe_MakeThis[];
extern char const gText_Cooking_Recipe_ViewCurrent[];
extern char const gText_Cooking_Recipe_Rewrite[];
extern char const gText_Cooking_Recipe_ViewNew[];
extern char const gText_Cooking_Recipe_ListTitle[];
extern char const gText_Cooking_Recipe_Utensils[];
extern char const gText_Cooking_Recipe_Ingredients[];
extern char const gText_Cooking_Recipe_UseIngredients[];
extern char const gText_Cooking_Recipe_IngredientsRequired[];
extern char const gText_Cooking_Recipe_Empty[];
extern char const gText_Cooking_Recipe_StorageHeader[];
extern char const gText_Cooking_Recipe_SelectionNames[13][11];
extern char const gText_Cooking_ResultFailure[];
extern char const gText_Cooking_ResultSuccessNewRecipe[];
extern char const gText_Cooking_ResultSuccess[];
extern char const gText_Cooking_ResultComparison[];

#if defined(REGION_JP)
extern char const gText_Cooking_Recipe_LeavePreviousAsIs[];
extern char const gText_Cooking_Recipe_LeaveNewAsIs[];
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
extern char const gText_Cooking_ImproviseAnyway[];
extern char const gText_Cooking_Recipe_LeaveAsIs[];
#endif

#pragma interface "scene_cooking.hh"
inline UiTextSubstitution CookingTextVariables::Lookup(u32 code)
{
    switch (static_cast<i32>(code)) {
    case 0xF0:
        return UiTextSubstitution(true, FixedStr<31>(gText_StaminaRecoveryStatus[stamina_description]));
    case 0xF1:
        return UiTextSubstitution(true, FixedStr<31>(gText_FatigueRecoveryStatus[fatigue_description]));
    case 0xFF:
        if (item_code <= 0xAB)
            return UiTextSubstitution(true, FixedStr<31>(Food(item_code - 1).GetName()));
        return UiTextSubstitution(true, FixedStr<31>(Article(item_code - 0xAC).GetName()));
    }
    return UiTextSubstitution(false, FixedStr<31>());
}


#endif // SCENE_COOKING_HH
