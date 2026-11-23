#ifndef SCENE_TEXT_VARIABLES_HH
#define SCENE_TEXT_VARIABLES_HH

#include "scene_text_variable_lifetimes.hh"

struct GameStateSaveImage;

extern char const gText_Moneybags[];
extern char const gText_EmptyUiLabel[];
extern char const gText_UnnamedSetting[];


#pragma interface "scene_text_variables.hh"

// Borrow the save image and own the four encoded strings substituted for Var1-4.
// Limits count bytes, not characters; native setters do not validate slot IDs.
struct GameSceneTextVariables : ScriptTextVariableStore
{
    enum Code {
        PLAYER = 0xFF21, HORSE, DOG, PLACE1, VAR1, VAR2, VAR3, VAR4,
        NICKNAME, BABY, PLACE2, PASSERBY1, PASSERBY2,
    };
#if defined(REGION_JP)
    enum { MAX_VALUE_BYTES = 20 };
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    enum { MAX_VALUE_BYTES = 22 };
#endif
    GameSceneTextVariables(GameStateSaveImage * image);
    virtual UiTextSubstitution Lookup(u32 code);
    void Set(u32 slot, char const * text);

    GameStateSaveImage const * save;
    FixedStr<MAX_VALUE_BYTES> values[4];
};

typedef char GameSceneTextVariableStrideCheck[sizeof(FixedStr<GameSceneTextVariables::MAX_VALUE_BYTES>) == 24 ? 1 : -1];
typedef char GameSceneTextVariablesSizeCheck[sizeof(GameSceneTextVariables) == 0x68 ? 1 : -1];
typedef char GameSceneTextVariablesSaveCheck[offsetof(GameSceneTextVariables, save) == 4 ? 1 : -1];
typedef char GameSceneTextVariablesValuesCheck[offsetof(GameSceneTextVariables, values) == 8 ? 1 : -1];


#endif
