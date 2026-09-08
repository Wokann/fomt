#include "prelude.h"

EXTERN_C

// These early C++ ABI tables have two null metadata slots followed by opaque
// function targets. The functions are not called through these declarations;
// their no-argument types retain only the original pointer relocations.
typedef void (*RawVTableFunction)(void);

extern void __pure_virtual(void);
extern void func_080D3BE8(void);
extern void func_080D3C24(void);
extern void func_080D3C60(void);
extern void func_080D3C6C(void);
extern void func_080D3C78(void);
extern void func_080D3ED4(void);
extern void func_080D3EF4(void);
extern void func_080D4004(void);
extern void func_080D4040(void);
extern void func_080D404C(void);
extern void func_080D406C(void);
extern void func_0800371C(void);
extern void func_0800374C(void);

extern RawVTableFunction const vtable_unk_080E59EC[] = {
    nullptr,
    nullptr,
    func_080D3C60,
    func_080D3C24,
};

extern RawVTableFunction const vtable_unk_080E59FC[] = {
    nullptr,
    nullptr,
    func_080D3C6C,
    func_080D3BE8,
};

extern RawVTableFunction const vtable_unk_080E5A0C[] = {
    nullptr,
    nullptr,
    func_080D3C78,
};

extern RawVTableFunction const vtable_unk_080E5A18[] = {
    nullptr,
    nullptr,
    func_0800371C,
    func_0800374C,
};

extern RawVTableFunction const vtable_unk_080E5A28[] = {
    nullptr,
    nullptr,
    func_080D3ED4,
    __pure_virtual,
    __pure_virtual,
};

extern RawVTableFunction const vtable_unk_080E5A3C[] = {
    nullptr,
    nullptr,
    func_080D4040,
    func_080D4004,
};

extern RawVTableFunction const vtable_unk_080E5A4C[] = {
    nullptr,
    nullptr,
    func_080D404C,
    func_080D3EF4,
};

extern RawVTableFunction const vtable_unk_080E5A5C[] = {
    nullptr,
    nullptr,
    func_080D406C,
};

EXTERN_C_END
