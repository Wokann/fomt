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
extern void func_0804EEFC(void);
extern void func_0804F19C(void);
extern void func_080E0F48(void);
extern void func_080E0F90(void);
extern void func_080E0EF0(void);
extern void method_0803EFD8__13AScriptEngine(void);
#if defined(REGION_JP)
extern void func_0803EB3C(void);
extern void func_0803F550(void);
extern void func_0804E8A8(void);
extern void func_0804EBC8(void);
extern void func_0804EC34(void);
extern void func_0804EC48(void);
extern void func_0804EC68(void);
extern void func_0804EEEC(void);
extern void func_080E07B8(void);
extern void func_080E07C4(void);
extern void func_080E07D0(void);
extern void func_080E07DC(void);
extern void func_0804ED38(void);
extern void func_0804EDE4(void);
extern void func_0804EE6C(void);
extern void func_080E0880(void);
extern void func_080E0890(void);
extern void func_080E0894(void);
extern void func_080E0898(void);
extern void func_080E08B8(void);
extern void func_080E08BC(void);
extern void func_080E08C0(void);
extern void func_080E08C4(void);
extern void func_080E08C8(void);
extern void func_080E11EC(void);
extern void func_080E0C38_vtable_target(void);
extern void func_080E118C(void);
extern void func_08057BAC(void);
extern void func_08057BEC(void);
extern void func_080E0D60(void);
extern void func_080E0FC4(void);
extern void func_0805E39C(void);
extern void func_0805E3DC(void);
extern void func_080E1044(void);
extern void func_080E0FE4(void);
extern void func_080E1104(void);
extern void func_080E1124(void);
extern void func_080E1198(void);
extern void func_080E14B8(void);
extern void func_0805E4D4(void);
#else
extern void func_0803F8DC(void);
extern void func_0804EA80(void);
extern void func_0804EDA0(void);
extern void func_0804EE1C(void);
extern void func_0804EE88(void);
extern void func_0804EE9C(void);
extern void func_0804EEBC(void);
extern void func_0804EEDC(void);
extern void func_080E1018(void);
extern void func_080E1024(void);
extern void func_080E1030(void);
extern void func_0804F058(void);
extern void func_080E10F0(void);
extern void func_080E10F4(void);
extern void func_080E1118(void);
extern void func_080E111C(void);
extern void func_080E1120(void);
extern void func_080E1124(void);
extern void func_080521BC(void);
extern void func_080521FC(void);
extern void func_080E11EC(void);
extern void func_080E1498(void);
extern void func_080E118C(void);
extern void func_08057E1C(void);
extern void func_08057E5C(void);
extern void func_080E15C0(void);
extern void func_080E1824(void);
extern void func_080E14B8(void);
extern void func_0805CEFC(void);
extern void func_0805CF3C(void);
extern void func_080E18A4(void);
extern void func_080E1844(void);
extern void func_080E1964(void);
extern void func_080E1984(void);
extern void func_080E19F8(void);
extern void func_0805E658(void);
extern void func_0805E698(void);
extern void func_0805E790(void);
#endif
extern void Resolve__C22IndexedResourceArchiveUi(void);
extern void func_0804EF20(void);
extern void func_0804EFAC(void);
extern void func_0804F060(void);
extern void func_0804F0E0(void);
extern void func_0804F15C(void);
extern void func_0804F160(void);
extern void func_0804F174(void);
extern void func_0804F178(void);
extern void func_080E103C(void);
extern void func_080E105C(void);
extern void func_080E10E0(void);
extern void func_080E10EC(void);
extern void func_080E10F8(void);
extern void func_080E1128(void);
extern void func_080E1148(void);
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
extern void func_08011FE8(void);
extern void func_08012028(void);
extern void func_080179CC(void);
extern void func_08017C30(void);
extern void func_080182C8(void);
extern void func_0801FD58(void);
extern void func_0801FD50(void);
extern void func_0801FD48(void);
extern void func_0801FD6C(void);
extern void func_0801FD60(void);
extern void func_0801FD3C(void);
extern void func_08019F7C(void);
extern void func_08019FE8(void);
extern void func_0801A054(void);
extern void func_0801A8E0(void);
extern void func_0801FD0C(void);
extern void func_0801FD00(void);
extern void func_0801FCF4(void);
extern void func_0801B5C0(void);
extern void func_0801FCDC(void);
extern void func_0801FCB4(void);
extern void func_0801B9E8(void);
extern void func_0801FD30(void);
extern void func_0801FC54(void);
extern void func_0801FC48(void);
extern void func_0801FC60(void);
extern void func_0801FC6C(void);
extern void func_0801FC3C(void);
extern void func_0801FC0C(void);
extern void func_0801FC00(void);
extern void func_0801FBF4(void);
extern void func_0801FBE8(void);
extern void func_0801DD78(void);
extern void func_0801DD18(void);
extern void func_0801DD24(void);
extern void func_0801DD30(void);
extern void func_0801DD3C(void);
extern void func_0801DD48(void);
extern void func_0801DD54(void);
extern void func_0801DD60(void);
extern void func_0801DD6C(void);
extern void func_0801DD84(void);
extern void func_0801DE54(void);
extern void func_0801DE24(void);
extern void func_08017C00(void);
extern void func_08019BEC(void);
extern void func_08019B90(void);
extern void func_0801EAA0(void);
extern void func_0801C29C(void);
extern void func_0801CA1C(void);
extern void func_0801C49C(void);
extern void func_0801CAD8(void);
extern void func_0801CEFC(void);
extern void func_0801D23C(void);
extern void func_0801D3FC(void);
extern void func_0801D4E0(void);
extern void func_0801D5BC(void);
extern void func_0801D7B0(void);
extern void func_0801D88C(void);
extern void func_0801CBB0(void);
extern void func_0801CFB8(void);
extern void func_0801C3DC(void);
extern void func_0801C3E0(void);
extern void func_0801DE30(void);
extern void func_0801DE3C(void);
extern void func_0801DE48(void);
extern void func_0801DEB4(void);
extern void func_0801DDCC(void);
extern void func_0801DDF8(void);
extern void func_0801DCD4(void);
extern void func_0801DC24(void);
extern void func_0801DCA8(void);
extern void func_08019F38(void);
extern void func_0801D8CC(void);
extern void func_0801D948(void);
extern void func_0801FAA8(void);
extern void func_0801FAB8(void);
extern void func_0801B498(void);
extern void func_0801E084(void);
extern void func_0801C0E0(void);
extern void func_0801D9A8(void);
extern void func_0801FCA4(void);
extern void func_0801D9BC(void);
extern void func_0801DB44(void);
extern void func_0801F518(void);
extern void func_0801F5F0(void);
extern void func_0801EE00(void);
extern void func_0801F924(void);
extern void func_0801C550(void);
extern void func_0801C69C(void);
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
extern void func_080DBC0C(void);
extern void func_080DBC50(void);
extern void func_080DBC78(void);
extern void func_080DBCC0(void);
extern void func_080DBCE8(void);
extern void func_080DBD30(void);
extern void func_080DBD58(void);
extern void func_080DBDA0(void);
extern void func_080DBDC8(void);
extern void func_080DBE10(void);
extern void func_080DBE38(void);
extern void func_080DBE80(void);
extern void func_080DBEA8(void);
extern void func_080DBEF0(void);
extern void func_080DBF18(void);
extern void func_080DBF60(void);
extern void func_080DBF88(void);
extern void func_080DBFD0(void);
extern void func_080DBFF8(void);
extern void func_080DC040(void);
extern void func_080DC068(void);
extern void func_080DC0C0(void);
extern void func_080DC0E8(void);
extern void func_080DC130(void);
extern void func_080DC158(void);
extern void func_080DC1A0(void);
extern void func_080DC1C8(void);
extern void func_080DC1D4(void);
extern void func_080DC21C(void);
extern void func_080DC244(void);
extern void func_080DC288(void);
extern void func_080DC3A0(void);
extern void func_080DC404(void);
extern void func_080DC42C(void);
extern void func_080DC474(void);
extern void func_080DC49C(void);
extern void func_080DC4E4(void);
extern void func_080DC50C(void);
extern void func_080DC554(void);
extern void func_080DC5A8(void);
extern void func_080DC5B4(void);
extern void func_080DC5D4(void);
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

extern RawVTableFunction const vtable_unk_080E5D74[] = {
    nullptr,
    nullptr,
    func_080DBC50,
    func_080DBC0C,
};

extern RawVTableFunction const vtable_unk_080E5D84[] = {
    nullptr,
    nullptr,
    func_080DBCC0,
    func_080DBC78,
};

extern RawVTableFunction const vtable_unk_080E5D94[] = {
    nullptr,
    nullptr,
    func_080DBD30,
    func_080DBCE8,
};

extern RawVTableFunction const vtable_unk_080E5DA4[] = {
    nullptr,
    nullptr,
    func_080DBDA0,
    func_080DBD58,
};

extern RawVTableFunction const vtable_unk_080E5DB4[] = {
    nullptr,
    nullptr,
    func_080DBE10,
    func_080DBDC8,
};

extern RawVTableFunction const vtable_unk_080E5DC4[] = {
    nullptr,
    nullptr,
    func_080DBE80,
    func_080DBE38,
};

extern RawVTableFunction const vtable_unk_080E5DD4[] = {
    nullptr,
    nullptr,
    func_080DBEF0,
    func_080DBEA8,
};

extern RawVTableFunction const vtable_unk_080E5DE4[] = {
    nullptr,
    nullptr,
    func_080DBF60,
    func_080DBF18,
};

extern RawVTableFunction const vtable_unk_080E5DF4[] = {
    nullptr,
    nullptr,
    func_080DBFD0,
    func_080DBF88,
};

extern RawVTableFunction const vtable_unk_080E5E04[] = {
    nullptr,
    nullptr,
    func_080DC040,
    func_080DBFF8,
};

extern RawVTableFunction const vtable_unk_080E5E14[] = {
    nullptr,
    nullptr,
    func_080DC0C0,
    func_080DC068,
};

extern RawVTableFunction const vtable_unk_080E5E24[] = {
    nullptr,
    nullptr,
    func_080DC130,
    func_080DC0E8,
};

extern RawVTableFunction const vtable_unk_080E5E34[] = {
    nullptr,
    nullptr,
    func_080DC1A0,
    func_080DC158,
};

extern RawVTableFunction const vtable_unk_080E5E44[] = {
    nullptr,
    nullptr,
    func_080DC1C8,
    __pure_virtual,
};

extern RawVTableFunction const vtable_unk_080E5E54[] = {
    nullptr,
    nullptr,
    func_080DC21C,
    func_080DC1D4,
};

extern RawVTableFunction const vtable_unk_080E5E64[] = {
    nullptr,
    nullptr,
    func_08011FE8,
    func_08012028,
};

extern RawVTableFunction const vtable_unk_080E5E74[] = {
    nullptr,
    nullptr,
    func_080DC288,
    func_080DC244,
};

extern RawVTableFunction const vtable_unk_080E5E84[] = {
    nullptr,
    nullptr,
    func_080DC404,
    func_080DC3A0,
};

extern RawVTableFunction const vtable_unk_080E5E94[] = {
    nullptr,
    nullptr,
    func_080DC474,
    func_080DC42C,
};

extern RawVTableFunction const vtable_unk_080E5EA4[] = {
    nullptr,
    nullptr,
    func_080DC4E4,
    func_080DC49C,
};

extern RawVTableFunction const vtable_unk_080E5EB4[] = {
    nullptr,
    nullptr,
    func_080DC554,
    func_080DC50C,
};

extern RawVTableFunction const vtable_unk_080E5EC4[] = {
    nullptr,
    nullptr,
    func_080179CC,
    func_08017C30,
    func_080182C8,
    func_0801FD58,
    func_0801FD50,
    func_0801FD48,
    func_0801FD6C,
    func_0801FD60,
    func_0801FD3C,
    func_08019F7C,
    func_08019FE8,
    func_0801A054,
    func_0801A8E0,
    func_0801FD0C,
    func_0801FD00,
    func_0801FCF4,
    func_0801B5C0,
    func_0801FCDC,
    func_0801FCB4,
    func_0801B9E8,
    func_0801FD30,
    func_0801FC54,
    func_0801FC48,
    func_0801FC60,
    func_0801FC6C,
    func_0801FC3C,
    func_0801FC0C,
    func_0801FC00,
    func_0801FBF4,
    func_0801FBE8,
    func_0801DD78,
    func_0801DD18,
    func_0801DD24,
    func_0801DD30,
    func_0801DD3C,
    func_0801DD48,
    func_0801DD54,
    func_0801DD60,
    func_0801DD6C,
    func_0801DD84,
    func_0801DE54,
    func_0801DE24,
    func_08017C00,
    func_08019BEC,
    func_08019B90,
    func_0801EAA0,
    func_0801C29C,
    func_0801CA1C,
    func_0801C49C,
    func_0801CAD8,
    func_0801CEFC,
    func_0801D23C,
    func_0801D3FC,
    func_0801D4E0,
    func_0801D5BC,
    func_0801D7B0,
    func_0801D88C,
    func_0801CBB0,
    func_0801CFB8,
    func_0801C3DC,
    func_0801C3E0,
    func_0801DE30,
    func_0801DE3C,
    func_0801DE48,
    func_0801DEB4,
    func_0801DDCC,
    func_0801DDF8,
    func_0801DCD4,
    func_0801DC24,
    func_0801DCA8,
    func_08019F38,
    func_0801D8CC,
    func_0801D948,
    func_0801FAA8,
    func_0801FAB8,
    func_0801B498,
    func_0801E084,
    func_0801C0E0,
    func_0801D9A8,
    func_0801FCA4,
    func_0801D9BC,
    func_0801DB44,
    func_0801F518,
    func_0801F5F0,
    func_0801EE00,
    func_0801F924,
    func_0801C550,
    func_0801C69C,
};

extern RawVTableFunction const vtable_unk_080E602C[] = {
    nullptr,
    nullptr,
    func_080DC5A8,
};

extern RawVTableFunction const vtable_unk_080E6038[] = {
    nullptr,
    nullptr,
    func_080DC5B4,
    // 0x03-0x0A: pure virtual slots.
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    // 0x0B-0x12: pure virtual slots.
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    // 0x13-0x1A: pure virtual slots.
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    // 0x1B-0x22: pure virtual slots.
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    // 0x23-0x2A: pure virtual slots.
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    // 0x2B-0x32: pure virtual slots.
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    // 0x33-0x3A: pure virtual slots.
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    // 0x3B-0x42: pure virtual slots.
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    // 0x43-0x4A: pure virtual slots.
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    // 0x4B-0x52: pure virtual slots.
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    // 0x53-0x59: pure virtual slots.
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    __pure_virtual, __pure_virtual, __pure_virtual,
};

extern RawVTableFunction const vtable_unk_080E61A0[] = {
    nullptr,
    nullptr,
    func_080DC5D4,
    // 0x03-0x0A: pure virtual slots.
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    // 0x0B-0x12: pure virtual slots.
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    // 0x13-0x1A: pure virtual slots.
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    // 0x1B-0x22: pure virtual slots.
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    // 0x23-0x2A: pure virtual slots.
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    __pure_virtual, __pure_virtual, __pure_virtual, __pure_virtual,
    // 0x2B: pure virtual slot.
    __pure_virtual,
};

#if defined(REGION_JP)
// The JP Script Engine code is still retained as a raw code range, but this
// ABI table has the same five logical slots as the compiled US table.
extern RawVTableFunction const __vt_13AScriptEngine[]
    SECTION(".rodata.vtable_ascript_engine") = {
        nullptr,
        nullptr,
        func_0803EB3C,
        method_0803EFD8__13AScriptEngine,
        __pure_virtual,
    };
#endif

// The base Script Engine table follows the AScriptEngine table in both ROMs.
// JP keeps its implementation code raw, but all five ABI slots are known.
extern RawVTableFunction const __vt_12ScriptEngine[]
    SECTION(".rodata.vtable_script_engine") = {
        nullptr,
        nullptr,
        func_080E0EF0,
        method_0803EFD8__13AScriptEngine,
#if defined(REGION_JP)
        func_0803F550,
#else
        func_0803F8DC,
#endif
    };

// Seven adjacent two-method dispatch tables.  The table shapes are shared;
// only their raw code entry points differ between the two regional ROMs.
extern RawVTableFunction const vtable_unk_080E7838[]
    SECTION(".rodata.vtable_script_engine_adjacent") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_0804EC48,
        func_0804EC34,
#else
        func_0804EE9C,
        func_0804EE88,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7848[]
    SECTION(".rodata.vtable_script_engine_adjacent") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_0804EC68,
        func_0804EBC8,
#else
        func_0804EEBC,
        func_0804EE1C,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7858[]
    SECTION(".rodata.vtable_script_engine_adjacent") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_0804EEFC,
        func_0804E8A8,
#else
        func_0804EEDC,
        func_0804EDA0,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7868[]
    SECTION(".rodata.vtable_script_engine_adjacent") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_0804F19C,
        func_080E07B8,
#else
        func_0804EEFC,
        func_0804EA80,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7878[]
    SECTION(".rodata.vtable_script_engine_adjacent") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E0F90,
        func_080E07C4,
#else
        func_0804F19C,
        func_080E1018,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7888[]
    SECTION(".rodata.vtable_script_engine_adjacent") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E0F48,
        func_080E07D0,
#else
        func_080E0F90,
        func_080E1024,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7898[]
    SECTION(".rodata.vtable_script_engine_adjacent") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E07DC,
        func_0804EEEC,
#else
        func_080E0F48,
        func_080E1030,
#endif
    };

// The next dispatch blocks have region-specific slot layouts. Keep their
// real pointer order without assigning unsupported class or ABI semantics.
extern RawVTableFunction const vtable_unk_080E78A8[]
    SECTION(".rodata.vtable_script_engine_adjacent") = {
#if defined(REGION_JP)
        func_0804F174,
        func_0804F178,
        nullptr,
        nullptr,
        func_080E105C,
        func_0804ED38,
#else
        nullptr,
        nullptr,
        func_080E103C,
        func_0804F160,
        func_0804F174,
        func_0804F178,
#endif
    };

extern RawVTableFunction const vtable_unk_080E78C0[]
    SECTION(".rodata.vtable_script_engine_adjacent") = {
#if defined(REGION_JP)
        func_0804EDE4,
        func_0804F060,
        func_0804EE6C,
        func_0804F15C,
        nullptr,
        nullptr,
        func_0804EF20,
        func_080E0880,
#else
        nullptr,
        nullptr,
        func_080E105C,
        func_0804EFAC,
        func_0804F058,
        func_0804F060,
        func_0804F0E0,
        func_0804F15C,
#endif
    };

extern RawVTableFunction const vtable_unk_080E78E0[]
    SECTION(".rodata.vtable_script_engine_adjacent") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E0898,
        func_080E0894,
#else
        func_0804EF20,
        func_080E10E0,
#endif
    };

extern RawVTableFunction const vtable_unk_080E78F0[]
    SECTION(".rodata.vtable_script_engine_adjacent") = {
#if defined(REGION_JP)
        func_080E0890,
        func_080E10EC,
        nullptr,
        nullptr,
        func_080E08C8,
        __pure_virtual,
#else
        nullptr,
        nullptr,
        func_080E10F8,
        func_080E10F4,
        func_080E10F0,
        func_080E10EC,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7908[]
    SECTION(".rodata.vtable_script_engine_adjacent") = {
#if defined(REGION_JP)
        func_080E08C4,
        func_080E08C0,
        func_080E08BC,
        func_080E08B8,
        nullptr,
        nullptr,
        func_080E1148,
        nullptr,
#else
        nullptr,
        nullptr,
        func_080E1128,
        __pure_virtual,
        func_080E1124,
        func_080E1120,
        func_080E111C,
        func_080E1118,
#endif
    };

// This following four-slot block stays between raw table ranges, so it is
// emitted separately while retaining its original physical order.
extern RawVTableFunction const vtable_unk_080E7934[]
    SECTION(".rodata.vtable_7934") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_080E11EC,
        nullptr,
#else
        nullptr,
        func_080521BC,
        func_080521FC,
        nullptr,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7944[]
    SECTION(".rodata.vtable_7944") = {
#if defined(REGION_JP)
        nullptr,
        func_080E0C38_vtable_target,
        func_080E118C,
#else
        nullptr,
        nullptr,
        func_080E11EC,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7950[]
    SECTION(".rodata.vtable_7950") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_08057BAC,
        func_08057BEC,
#else
        func_080E1498,
        func_080E118C,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7960[]
    SECTION(".rodata.vtable_7960") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E0D60,
        nullptr,
#else
        func_08057E1C,
        func_08057E5C,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7970[]
    SECTION(".rodata.vtable_7970") = {
#if defined(REGION_JP)
        nullptr,
        func_080E0FC4,
        func_080E14B8,
#else
        nullptr,
        nullptr,
        func_080E15C0,
#endif
    };

extern RawVTableFunction const vtable_unk_080E797C[]
    SECTION(".rodata.vtable_797c") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_0805CC44,
        func_0805CC84,
#else
        func_080E1824,
        func_080E14B8,
#endif
    };

extern RawVTableFunction const vtable_unk_080E798C[]
    SECTION(".rodata.vtable_798c") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E1044,
        nullptr,
#else
        func_0805CEFC,
        func_0805CF3C,
#endif
    };

extern RawVTableFunction const vtable_unk_080E799C[]
    SECTION(".rodata.vtable_799c") = {
        nullptr,
#if defined(REGION_JP)
        func_080E1104,
        func_080E0FE4,
#else
        nullptr,
        func_080E18A4,
#endif
    };

extern RawVTableFunction const vtable_unk_080E79A8[]
    SECTION(".rodata.vtable_79a8") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_0805E39C,
        func_0805E3DC,
#else
        func_080E1964,
        func_080E1844,
#endif
    };

extern RawVTableFunction const vtable_unk_080E79B8[]
    SECTION(".rodata.vtable_79b8") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E1124,
        Resolve__C22IndexedResourceArchiveUi,
#else
        func_0805E658,
        func_0805E698,
#endif
    };

extern RawVTableFunction const vtable_unk_080E79C8[]
    SECTION(".rodata.vtable_79c8") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E1124,
        Resolve__C22IndexedResourceArchiveUi,
        func_0805E4D4,
#else
        func_080E1984,
        Resolve__C22IndexedResourceArchiveUi,
        func_0805E790,
#endif
    };

extern RawVTableFunction const vtable_unk_080E79DC[]
    SECTION(".rodata.vtable_79dc") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E1198,
#else
        func_080E19F8,
#endif
    };

EXTERN_C_END
