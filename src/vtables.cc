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
extern void func_08004BDC(void);
extern void func_08004C0C(void);
extern void func_08004C54(void);
extern void func_08004C68(void);
extern void func_080050C8(void);
extern void func_080059D0(void);
extern void func_08005A00(void);
extern void func_08005B38(void);
extern void func_080070A4(void);
extern void func_080070D4(void);
extern void func_080086BC(void);
extern void func_080D6C58(void);
extern void func_080D6D8C(void);
extern void func_080D780C(void);
extern void func_080D781C(void);
extern void func_080D782C(void);
extern void func_080D7868(void);
extern void func_080D7874(void);
extern void func_080D7880(void);
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

extern RawVTableFunction const vtable_unk_080E5A68[] = {
    nullptr,
    nullptr,
    func_08004BDC,
    func_08004C0C,
};

extern RawVTableFunction const vtable_unk_080E5A78[] = {
    nullptr,
    nullptr,
    func_080D6D8C,
    func_080D6C58,
};

extern RawVTableFunction const vtable_unk_080E5A88[] = {
    nullptr,
    nullptr,
    func_08004C54,
    func_08004C68,
};

extern RawVTableFunction const vtable_unk_080E5A98[] = {
    nullptr,
    nullptr,
    func_080050C8,
};

extern RawVTableFunction const vtable_unk_080E5AA4[] = {
    nullptr,
    nullptr,
    func_080059D0,
    func_08005A00,
};

extern RawVTableFunction const vtable_unk_080E5AB4[] = {
    nullptr,
    nullptr,
    func_08005B38,
};

extern RawVTableFunction const vtable_unk_080E5AC0[] = {
    nullptr,
    nullptr,
    func_080070A4,
    func_080070D4,
};

extern RawVTableFunction const vtable_unk_080E5AD0[] = {
    nullptr,
    nullptr,
    func_080D782C,
    func_080D7868,
};

extern RawVTableFunction const vtable_unk_080E5AE0[] = {
    nullptr,
    nullptr,
    func_080D781C,
    func_080D7874,
};

extern RawVTableFunction const vtable_unk_080E5AF0[] = {
    nullptr,
    nullptr,
    func_080D780C,
    func_080D7880,
};

extern RawVTableFunction const vtable_unk_080E5B00[] = {
    nullptr,
    nullptr,
    func_080086BC,
};

EXTERN_C_END
