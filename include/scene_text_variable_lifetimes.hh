#ifndef SCENE_TEXT_VARIABLE_LIFETIMES_HH
#define SCENE_TEXT_VARIABLE_LIFETIMES_HH

#include "utility/fixed_str.hh"


struct UiTextSubstitution
{
    bool found;
    FixedStr<31> text;

    UiTextSubstitution(bool const & value, FixedStr<31> const & replacement)
        : found(value), text(replacement) {}
};

typedef char UiTextSubstitutionSizeCheck[sizeof(UiTextSubstitution) == 36 ? 1 : -1];
typedef char UiTextSubstitutionTextCheck[offsetof(UiTextSubstitution, text) == 4 ? 1 : -1];

#pragma interface "scene_text_variable_lifetimes.hh"

struct ScriptTextVariableStore
{
    virtual ~ScriptTextVariableStore();
    virtual inline UiTextSubstitution Lookup(u32 code);
};

inline ScriptTextVariableStore::~ScriptTextVariableStore() {}

inline UiTextSubstitution ScriptTextVariableStore::Lookup(u32)
{
    return UiTextSubstitution(false, FixedStr<31>());
}


#endif // SCENE_TEXT_VARIABLE_LIFETIMES_HH
