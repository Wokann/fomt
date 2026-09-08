#include "prelude.h"

EXTERN_C

// These early C++ ABI tables have two null metadata slots followed by opaque
// function targets. The functions are not called through these declarations;
// their no-argument types retain only the original pointer relocations.
typedef void (*RawVTableFunction)(void);

struct RawVTableWithOffset {
    i32 offset;
    RawVTableFunction entries[2];
};

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
extern void func_08008B0C(void);
extern void func_08008B18(void);
extern void func_080094AC(void);
extern void func_080094B8(void);
extern void func_0800956C(void);
extern void func_0800959C(void);
extern void func_080095C0(void);
extern void func_080095FC(void);
extern void func_08009638(void);
extern void func_08009674(void);
extern void func_080098AC(void);
extern void func_080098D8(void);
extern void func_080098DC(void);
extern void func_08009908(void);
extern void func_08009940(void);
extern void func_08009968(void);
extern void func_08009984(void);
extern void func_080099B0(void);
extern void func_080099D4(void);
extern void func_0801004C(void);
extern void func_08010158(void);
extern void func_080D7944(void);
extern void func_080D79CC(void);
extern void func_080D7AAC(void);
extern void func_080D7AD4(void);
extern void func_080D7B04(void);
extern void func_080D7B2C(void);
extern void func_080D7B38(void);
extern void func_080D7B44(void);
extern void func_080DB0EC(void);
extern void func_080DB1E4(void);
extern void func_080DB238(void);
extern void func_080DB2EC(void);
extern void func_080DB314(void);
extern void func_080DB320(void);
extern void func_080DB36C(void);
extern void func_080DB394(void);
extern void func_080DB3DC(void);
extern void func_080DB404(void);
extern void func_080DB44C(void);
extern void func_080DB474(void);
extern void func_080DB4C8(void);
extern void func_080DB4F0(void);
extern void func_080DB540(void);
extern void func_080DB568(void);
extern void func_080DB5B8(void);
extern void func_080DB5E0(void);
extern void func_080DB630(void);
extern void func_080DB658(void);
extern void func_080DB6A4(void);
extern void func_080DB6CC(void);
extern void func_080DB714(void);
extern void func_080DB73C(void);
extern void func_080DB784(void);
extern void func_080DB7AC(void);
extern void func_080DB7F4(void);
extern void func_080DB81C(void);
extern void func_080DB864(void);
extern void func_080DB88C(void);
extern void func_080DB8D4(void);
extern void func_080DB8FC(void);
extern void func_080DB944(void);
extern void func_080DB96C(void);
extern void func_080DB9B4(void);
extern void func_080DB9DC(void);
extern void func_080DBA24(void);
extern void func_080DBA4C(void);
extern void func_080DBA94(void);
extern void func_080DBABC(void);
extern void func_080DBB04(void);
extern void func_080DBB2C(void);
extern void func_080DBB74(void);
extern void func_080DBB9C(void);
extern void func_080DBBE4(void);
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

extern RawVTableWithOffset const vtable_unk_080E5B0C = {
    -28,
    {
        nullptr,
        func_080D79CC,
    },
};

extern RawVTableFunction const vtable_unk_080E5B18[] = {
    nullptr,
    nullptr,
    func_08009908,
    func_080D7AD4,
    func_080095C0,
    func_080095FC,
    func_0800956C,
    func_08009638,
    func_08009674,
};

extern RawVTableFunction const vtable_unk_080E5B3C[] = {
    nullptr,
    nullptr,
    func_080D7944,
};

extern RawVTableFunction const vtable_unk_080E5B48[] = {
    nullptr,
    nullptr,
    func_080D7B04,
};

extern RawVTableFunction const vtable_unk_080E5B54[] = {
    nullptr,
    nullptr,
    func_080D7AAC,
};

extern RawVTableFunction const vtable_unk_080E5B60[] = {
    nullptr,
    nullptr,
    func_08008B18,
    func_080D7B2C,
};

extern RawVTableFunction const vtable_unk_080E5B70[] = {
    nullptr,
    nullptr,
    func_08008B0C,
    func_080D7B38,
};

extern RawVTableFunction const vtable_unk_080E5B80[] = {
    nullptr,
    nullptr,
    func_080094AC,
    func_080094B8,
};

extern RawVTableFunction const vtable_unk_080E5B90[] = {
    nullptr,
    nullptr,
    func_08009908,
    func_0800959C,
    func_080095C0,
    func_080095FC,
    func_0800956C,
    func_08009638,
    func_08009674,
};

extern RawVTableFunction const vtable_unk_080E5BB4[] = {
    nullptr,
    nullptr,
    func_08009908,
    func_080098DC,
    func_08009940,
    func_08009968,
    func_08009984,
    func_080099B0,
    func_080099D4,
};

extern RawVTableFunction const vtable_unk_080E5BD8[] = {
    nullptr,
    nullptr,
    func_080098D8,
    func_080D7B44,
};

extern RawVTableFunction const vtable_unk_080E5BE8[] = {
    nullptr,
    nullptr,
    __pure_virtual,
    func_080098AC,
};

extern RawVTableFunction const vtable_unk_080E5BF8[] = {
    nullptr,
    nullptr,
    func_08010158,
    func_0801004C,
};

extern RawVTableFunction const vtable_unk_080E5C08[] = {
    nullptr,
    nullptr,
    func_080DB0EC,
};

extern RawVTableFunction const vtable_unk_080E5C14[] = {
    nullptr,
    nullptr,
    func_080DB2EC,
    func_080DB1E4,
};

extern RawVTableFunction const vtable_unk_080E5C24[] = {
    nullptr,
    nullptr,
    func_080DB314,
    func_080DB238,
};

extern RawVTableFunction const vtable_unk_080E5C34[] = {
    nullptr,
    nullptr,
    func_080DB36C,
    func_080DB320,
};

extern RawVTableFunction const vtable_unk_080E5C44[] = {
    nullptr,
    nullptr,
    func_080DB3DC,
    func_080DB394,
};

extern RawVTableFunction const vtable_unk_080E5C54[] = {
    nullptr,
    nullptr,
    func_080DB44C,
    func_080DB404,
};

extern RawVTableFunction const vtable_unk_080E5C64[] = {
    nullptr,
    nullptr,
    func_080DB4C8,
    func_080DB474,
};

extern RawVTableFunction const vtable_unk_080E5C74[] = {
    nullptr,
    nullptr,
    func_080DB540,
    func_080DB4F0,
};

extern RawVTableFunction const vtable_unk_080E5C84[] = {
    nullptr,
    nullptr,
    func_080DB5B8,
    func_080DB568,
};

extern RawVTableFunction const vtable_unk_080E5C94[] = {
    nullptr,
    nullptr,
    func_080DB630,
    func_080DB5E0,
};

extern RawVTableFunction const vtable_unk_080E5CA4[] = {
    nullptr,
    nullptr,
    func_080DB6A4,
    func_080DB658,
};

extern RawVTableFunction const vtable_unk_080E5CB4[] = {
    nullptr,
    nullptr,
    func_080DB714,
    func_080DB6CC,
};

extern RawVTableFunction const vtable_unk_080E5CC4[] = {
    nullptr,
    nullptr,
    func_080DB784,
    func_080DB73C,
};

extern RawVTableFunction const vtable_unk_080E5CD4[] = {
    nullptr,
    nullptr,
    func_080DB7F4,
    func_080DB7AC,
};

extern RawVTableFunction const vtable_unk_080E5CE4[] = {
    nullptr,
    nullptr,
    func_080DB864,
    func_080DB81C,
};

extern RawVTableFunction const vtable_unk_080E5CF4[] = {
    nullptr,
    nullptr,
    func_080DB8D4,
    func_080DB88C,
};

extern RawVTableFunction const vtable_unk_080E5D04[] = {
    nullptr,
    nullptr,
    func_080DB944,
    func_080DB8FC,
};

extern RawVTableFunction const vtable_unk_080E5D14[] = {
    nullptr,
    nullptr,
    func_080DB9B4,
    func_080DB96C,
};

extern RawVTableFunction const vtable_unk_080E5D24[] = {
    nullptr,
    nullptr,
    func_080DBA24,
    func_080DB9DC,
};

extern RawVTableFunction const vtable_unk_080E5D34[] = {
    nullptr,
    nullptr,
    func_080DBA94,
    func_080DBA4C,
};

extern RawVTableFunction const vtable_unk_080E5D44[] = {
    nullptr,
    nullptr,
    func_080DBB04,
    func_080DBABC,
};

extern RawVTableFunction const vtable_unk_080E5D54[] = {
    nullptr,
    nullptr,
    func_080DBB74,
    func_080DBB2C,
};

extern RawVTableFunction const vtable_unk_080E5D64[] = {
    nullptr,
    nullptr,
    func_080DBBE4,
    func_080DBB9C,
};

EXTERN_C_END
