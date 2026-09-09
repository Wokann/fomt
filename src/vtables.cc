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

struct RawVTableWithOffsetThreeEntries {
    i32 offset;
    RawVTableFunction entries[3];
};

struct RawVTableWithOffsetAnd66Entries {
    i32 offset;
    RawVTableFunction entries[66];
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
extern void func_0805CC44(void);
extern void func_0805CC84(void);
extern void func_080E0D60(void);
extern void func_080E0FC4(void);
extern void func_0805E39C(void);
extern void func_0805E3DC(void);
extern void func_080E1044(void);
extern void func_080E0FE4(void);
extern void func_080E1104(void);
extern void func_080E1124(void);
extern void func_080E1144(void);
extern void func_080E1198(void);
extern void func_080E11C8(void);
extern void func_080E11E8(void);
extern void func_080E11F4(void);
extern void func_080E1210(void);
extern void func_080E13B8(void);
extern void func_080E1410(void);
extern void func_080E14F4(void);
extern void func_080E152C(void);
extern void func_080E1538(void);
extern void func_080E1544(void);
extern void func_080E1550(void);
extern void func_080E155C(void);
extern void func_080E1568(void);
extern void func_080E1574(void);
extern void func_080E15C8(void);
extern void func_080E1898(void);
extern void func_080E18A4_vtable_target(void);
extern void func_080E18B0(void);
extern void func_080E18BC(void);
extern void func_08069C14(void);
extern void func_08069CE8(void);
extern void func_08069D28(void);
extern void func_0806D710(void);
extern void func_0806D740(void);
extern void func_0806E65C(void);
extern void func_0806E68C(void);
extern void func_08070634(void);
extern void func_08070664(void);
extern void func_08071F28(void);
extern void func_08070900(void);
extern void func_080751B8(void);
extern void func_08075278(void);
extern void func_080752B8(void);
extern void func_0807532C(void);
extern void func_08075A5C(void);
extern void func_08076E0C(void);
extern void func_08076AE0(void);
extern void func_080E260C(void);
extern void func_080777F4(void);
extern void func_08077834(void);
extern void func_080E2A88(void);
extern void func_08078670(void);
extern void func_080786A0(void);
extern void func_080E2B70(void);
extern void func_0807AC20(void);
extern void func_0807AC60(void);
extern void func_0807AD18(void);
extern void func_0807CC1C(void);
extern void func_0807CC5C(void);
extern void func_0807D960(void);
extern void func_0807CD30(void);
extern void func_0807D8D0(void);
extern void func_0807D910(void);
extern void func_0807DFE0(void);
extern void func_0807E020(void);
extern void func_0807E070(void);
extern void func_0807E9AC(void);
extern void func_0807E9EC(void);
extern void func_0807EA3C(void);
extern void func_0807F118(void);
extern void func_0807F158(void);
extern void func_0807F1D8(void);
extern void func_0807FFF4(void);
extern void func_08080034(void);
extern void func_08080094(void);
extern void func_0808093C(void);
extern void func_0808097C(void);
extern void func_080809CC(void);
extern void func_080815E8(void);
extern void func_08081628(void);
extern void func_08081678(void);
extern void func_08081CBC(void);
extern void func_08081CFC(void);
extern void func_08081DC8(void);
extern void func_08083664(void);
extern void func_080836A4(void);
extern void func_080837C8(void);
extern void func_080850A0(void);
extern void func_080850E0(void);
extern void func_080851A4(void);
extern void func_08087CEC(void);
extern void func_08087D2C(void);
extern void func_08087E44(void);
extern void func_0808A6A8(void);
extern void func_0808A6E8(void);
extern void func_0808A754(void);
extern void func_0808C0DC(void);
extern void func_0808C5DC(void);
extern void func_0808C190(void);
extern void func_0808E848(void);
extern void func_0808E888(void);
extern void func_0808E8F8(void);
extern void func_080909C4(void);
extern void func_08090EC4(void);
extern void func_08090F58(void);
extern void func_08092090(void);
extern void func_08092604(void);
extern void func_0809215C(void);
extern void func_08092CAC(void);
extern void func_08093220(void);
extern void func_08093D4C(void);
extern void func_08093D80(void);
extern void func_080E2C34(void);
extern void func_080E2C7C(void);
extern void func_080E14B8(void);
extern void func_08063B90(void);
extern void func_0805E4D4(void);
extern void func_0805FA48(void);
extern void func_0805FA88(void);
extern void func_08093E4C(void);
extern void func_08093E80(void);
extern void func_08093E84(void);
extern void func_08094210(void);
extern void func_080E3224(void);
extern void func_080E30C4(void);
extern void func_080E30B8(void);
extern void func_080E30AC(void);
extern void func_080E3218(void);
extern void func_080E3204(void);
extern void func_080E31F4(void);
extern void func_080E31DC(void);
extern void func_080E3184(void);
extern void func_080E312C(void);
extern void func_080E30D0(void);
extern void func_080E31E8(void);
extern void func_080E30A8(void);
extern void func_080E3078(void);
extern void func_080E3048(void);
extern void func_080E300C(void);
extern void func_080E2D7C(void);
extern void func_08093E88(void);
extern void func_08093EA8(void);
extern void func_080E2D88(void);
extern void func_080E2DB0(void);
extern void func_08094204(void);
extern void func_08093F10(void);
extern void func_08093F30(void);
extern void func_080E2DC8(void);
extern void func_080941FC(void);
extern void func_080941F8(void);
extern void func_08093F6C(void);
extern void func_08093FAC(void);
extern void func_080E2DF0(void);
extern void func_080941F0(void);
extern void func_080941EC(void);
extern void func_08094020(void);
extern void func_08094024(void);
extern void func_080E2E18(void);
extern void func_080E2E54(void);
extern void func_080E2ED0(void);
extern void func_08094048(void);
extern void func_08094074(void);
extern void func_080E2ED4(void);
extern void func_080E2EFC(void);
extern void func_080941D4(void);
extern void func_0809410C(void);
extern void func_0809412C(void);
extern void func_080E2F14(void);
extern void func_080941CC(void);
extern void func_080E2F38(void);
extern void func_0809416C(void);
extern void func_08094180(void);
extern void func_080941C4(void);
extern void func_080941C0(void);
extern void func_080941BC(void);
extern void func_08094184(void);
extern void func_08094188(void);
extern void func_080E2F3C(void);
extern void func_080E2F74_vtable_target(void);
extern void func_080E2FF0(void);
extern void func_080E2FF4(void);
extern void func_080E3000(void);
extern void func_08092DD4(void);
extern void func_080E32F8(void);
extern void func_0809420C(void);
extern void func_08094208(void);
extern void func_08094200(void);
extern void func_080941F4(void);
extern void func_080941E8(void);
extern void func_080941E4(void);
extern void func_080941E0(void);
extern void func_080941DC(void);
extern void func_080941D8(void);
extern void func_080941D0(void);
extern void func_080941C8(void);
extern void func_080941B8(void);
extern void func_080941B4(void);
extern void func_080941B0(void);
extern void func_08093554(void);
extern void func_080935A0(void);
extern void func_08093D2C(void);
extern void func_080938B0(void);
extern void func_080938E4(void);
extern void func_08093890(void);
extern void func_080939B0(void);
extern void func_080939E4(void);
extern void func_080939E8(void);
extern void func_080939EC(void);
extern void func_08093A0C(void);
extern void func_08093A74(void);
extern void func_08093A88(void);
extern void func_08093AC4(void);
extern void func_08093B0C(void);
extern void func_08093B80(void);
extern void func_08093B84(void);
extern void func_08093BA8(void);
extern void func_08093BD4(void);
extern void func_08093C6C(void);
extern void func_08093C8C(void);
extern void func_08093CCC(void);
extern void func_08093CE0(void);
extern void func_08093CE4(void);
extern void func_08093CE8(void);
extern void func_08094278(void);
extern void func_08094274(void);
extern void func_08094270(void);
extern void func_0809426C(void);
extern void func_08094268(void);
extern void func_08094264(void);
extern void func_08094260(void);
extern void func_0809425C(void);
extern void func_08094258(void);
extern void func_08094254(void);
extern void func_08094250(void);
extern void func_0809424C(void);
extern void func_08094248(void);
extern void func_08094244(void);
extern void func_08094240(void);
extern void func_0809423C(void);
extern void func_08094238(void);
extern void func_08094234(void);
extern void func_08094230(void);
extern void func_0809422C(void);
extern void func_08094228(void);
extern void func_08094224(void);
extern void func_08094220(void);
extern void func_0809421C(void);
extern void func_08094218(void);
extern void func_080E33D4(void);
extern void func_080E352C(void);
extern void func_080E3318(void);
extern void func_08099F50(void);
extern void func_08099F90(void);
extern void func_080E3838(void);
extern void func_080E3928(void);
extern void func_080E36D8(void);
extern void func_080E3948(void);
extern void func_080A31AC(void);
extern void func_080A3530(void);
extern void func_080A362C(void);
extern void func_080A3434(void);
extern void func_080A3678(void);
extern void func_080A3338(void);
extern void func_080A36C4(void);
extern void func_080A31E0(void);
extern void func_080E3980(void);
extern void func_080E39A8(void);
extern void func_080A372C(void);
extern void func_080A41EC(void);
extern void func_080A45A4(void);
extern void func_080A4624(void);
extern void func_080A4988(void);
extern void func_080A5198(void);
extern void func_080A5E58(void);
extern void func_080A58D8(void);
extern void func_080A56F8(void);
extern void func_080A57F0(void);
extern void func_080A50A8(void);
extern void func_080E39D0(void);
extern void func_080E3B50(void);
extern void func_080A5EF0(void);
extern void func_080A5F5C(void);
extern void func_080A6078(void);
extern void func_080AA974(void);
extern void func_080A6EC4(void);
extern void func_080A6098(void);
extern void func_080A8FDC(void);
extern void func_080E3C50(void);
extern void func_080AC528(void);
#else
extern void func_0803F8DC(void);
extern void func_0804EA80(void);
extern void func_08082144(void);
extern void func_08082184(void);
extern void func_08082250(void);
extern void func_080E3494(void);
extern void func_080E34DC(void);
extern void func_08083AEC(void);
extern void func_08083B2C(void);
extern void func_08083C50(void);
extern void func_08085528(void);
extern void func_08085568(void);
extern void func_0808562C(void);
extern void func_080881AC(void);
extern void func_080881EC(void);
extern void func_08088304(void);
extern void func_0808AB68(void);
extern void func_0808ABA8(void);
extern void func_0808AC14(void);
extern void func_0808C59C(void);
extern void func_0808C5DC(void);
extern void func_0808C650(void);
extern void func_0808ED08(void);
extern void func_0808ED48(void);
extern void func_0808EDB8(void);
extern void func_08090E84(void);
extern void func_08090EC4(void);
extern void func_08090F58(void);
extern void func_080925C4(void);
extern void func_08092604(void);
extern void func_08092690(void);
extern void func_080931E0(void);
extern void func_08093220(void);
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
extern void func_080E19A4(void);
extern void func_080E1A28(void);
extern void func_080E1A48(void);
extern void func_080E1A54(void);
extern void func_080E1A70(void);
extern void func_080E1C18(void);
extern void func_080E1C70(void);
extern void func_080E1D54(void);
extern void func_080E1D8C(void);
extern void func_080E1D98(void);
extern void func_080E1DA4(void);
extern void func_080E1DB0(void);
extern void func_080E1DBC(void);
extern void func_080E1DC8(void);
extern void func_080E1DD4(void);
extern void func_08069D84(void);
extern void func_08069E58(void);
extern void func_08069E98(void);
extern void func_0806D918(void);
extern void func_0806D948(void);
extern void func_0806EA00(void);
extern void func_0806EA30(void);
extern void func_080709D8(void);
extern void func_08070A08(void);
extern void func_080E20F8(void);
extern void func_080E2104(void);
extern void func_080E2110(void);
extern void func_080722D0(void);
extern void func_08070CA4(void);
extern void func_080E211C(void);
extern void func_0807555C(void);
extern void func_0807561C(void);
extern void func_0807565C(void);
extern void func_080756D0(void);
extern void func_08075E00(void);
extern void func_080E2E34(void);
extern void func_080E2E6C(void);
extern void func_08076E0C(void);
extern void func_08076EA8(void);
extern void func_08077C6C(void);
extern void func_08077CAC(void);
extern void func_080E32E8(void);
extern void func_08078AE8(void);
extern void func_08078B18(void);
extern void func_080E33D0(void);
extern void func_0807B07C(void);
extern void func_0807B0BC(void);
extern void func_0807B174(void);
extern void func_0807D0B4(void);
extern void func_0807D0F4(void);
extern void func_0807DDF8(void);
extern void func_0807D1C8(void);
extern void func_0807E478(void);
extern void func_0807E4B8(void);
extern void func_0807DD68(void);
extern void func_0807DDA8(void);
extern void func_0807E508(void);
extern void func_0807EE44(void);
extern void func_0807EE84(void);
extern void func_0807EED4(void);
extern void func_0807F5B0(void);
extern void func_0807F5F0(void);
extern void func_0807F670(void);
extern void func_0808048C(void);
extern void func_080804CC(void);
extern void func_0808052C(void);
extern void func_08080DC4(void);
extern void func_08080E04(void);
extern void func_08080E54(void);
extern void func_08081A70(void);
extern void func_08081AB0(void);
extern void func_08081B00(void);
extern void func_080E1E28(void);
extern void func_0805E658(void);
extern void func_0805E698(void);
extern void func_0805E790(void);
extern void func_0805FD04(void);
extern void func_0805FD44(void);
extern void func_08063E58(void);
extern void func_08093308(void);
extern void func_08093A88(void);
extern void func_08093AD4(void);
extern void func_08094268(void);
extern void func_08094288(void);
extern void func_080942BC(void);
extern void func_08094388(void);
extern void func_080943BC(void);
extern void func_080943C0(void);
extern void func_0809474C(void);
extern void func_080E3A8C(void);
extern void func_080E392C(void);
extern void func_080E3920(void);
extern void func_080E3914(void);
extern void func_080E3A80(void);
extern void func_080E3A6C(void);
extern void func_080E3A5C(void);
extern void func_080E3A44(void);
extern void func_080E39EC(void);
extern void func_080E3994(void);
extern void func_080E3938(void);
extern void func_080E3A50(void);
extern void func_080E3910(void);
extern void func_080E38E0(void);
extern void func_080E38B0(void);
extern void func_080E3874(void);
extern void func_080E35DC(void);
extern void func_080943C4(void);
extern void func_080943E4(void);
extern void func_080E35E8(void);
extern void func_080E3610(void);
extern void func_08094740(void);
extern void func_0809444C(void);
extern void func_0809446C(void);
extern void func_080E3628(void);
extern void func_08094738(void);
extern void func_08094734(void);
extern void func_080944A8(void);
extern void func_080944E8(void);
extern void func_080E3650(void);
extern void func_0809472C(void);
extern void func_08094728(void);
extern void func_0809455C(void);
extern void func_08094560(void);
extern void func_080E3678(void);
extern void func_080E36B4(void);
extern void func_080E3730(void);
extern void func_08094584(void);
extern void func_080945B0(void);
extern void func_080E3734(void);
extern void func_080E375C(void);
extern void func_08094710(void);
extern void func_08094648(void);
extern void func_08094668(void);
extern void func_080E3774(void);
extern void func_08094708(void);
extern void func_080E3798(void);
extern void func_080946A8(void);
extern void func_080946BC(void);
extern void func_08094700(void);
extern void func_080946FC(void);
extern void func_080946F8(void);
extern void func_080946C0(void);
extern void func_080946C4(void);
extern void func_080E379C(void);
extern void func_080E37DC(void);
extern void func_080E3858(void);
extern void func_080E385C(void);
extern void func_080E3868(void);
extern void func_080E3B60(void);
extern void func_08094748(void);
extern void func_08094744(void);
extern void func_0809473C(void);
extern void func_08094730(void);
extern void func_08094724(void);
extern void func_08094720(void);
extern void func_0809471C(void);
extern void func_08094718(void);
extern void func_08094714(void);
extern void func_0809470C(void);
extern void func_08094704(void);
extern void func_080946F4(void);
extern void func_080946F0(void);
extern void func_080946EC(void);
extern void func_08093DEC(void);
extern void func_08093E20(void);
extern void func_08093EEC(void);
extern void func_08093F20(void);
extern void func_08093F24(void);
extern void func_08093DCC(void);
extern void func_08093F28(void);
extern void func_08093F48(void);
extern void func_08093FB0(void);
extern void func_08093FC4(void);
extern void func_08094000(void);
extern void func_08094048(void);
extern void func_080940BC(void);
extern void func_080940C0(void);
extern void func_080940E4(void);
extern void func_08094110(void);
extern void func_080941A8(void);
extern void func_080941C8(void);
extern void func_08094208(void);
extern void func_0809421C(void);
extern void func_08094220(void);
extern void func_08094224(void);
extern void func_080947B4(void);
extern void func_080947B0(void);
extern void func_080947AC(void);
extern void func_080947A8(void);
extern void func_080947A4(void);
extern void func_080947A0(void);
extern void func_0809479C(void);
extern void func_08094798(void);
extern void func_08094794(void);
extern void func_08094790(void);
extern void func_0809478C(void);
extern void func_08094788(void);
extern void func_08094784(void);
extern void func_08094780(void);
extern void func_0809477C(void);
extern void func_08094778(void);
extern void func_08094774(void);
extern void func_08094770(void);
extern void func_0809476C(void);
extern void func_08094768(void);
extern void func_08094764(void);
extern void func_08094760(void);
extern void func_0809475C(void);
extern void func_08094758(void);
extern void func_08094754(void);
extern void func_080E3C3C(void);
extern void func_080E3D94(void);
extern void func_080E3B80(void);
extern void func_0809A518(void);
extern void func_0809A558(void);
extern void func_080E40A0(void);
extern void func_080E4190(void);
extern void func_080E3F40(void);
extern void func_080E41B0(void);
extern void func_080A3774(void);
extern void func_080A3BF4(void);
extern void func_080A3AF8(void);
extern void func_080A3C40(void);
extern void func_080A39FC(void);
extern void func_080A3C8C(void);
extern void func_080A3900(void);
extern void func_080E41E8(void);
extern void func_080A37A8(void);
extern void func_080E4210(void);
extern void func_080A3CF4(void);
extern void func_080A47B4(void);
extern void func_080A4B6C(void);
extern void func_080A4BEC(void);
extern void func_080A4F50(void);
extern void func_080A5760(void);
extern void func_080A6420(void);
extern void func_080A5EA0(void);
extern void func_080A5CC0(void);
extern void func_080A5DB8(void);
extern void func_080A5670(void);
extern void func_080E4238(void);
extern void func_080E43B8(void);
extern void func_080A64B8(void);
extern void func_080A6524(void);
extern void func_080A6640(void);
extern void func_080AAF3C(void);
extern void func_080A748C(void);
extern void func_080A6660(void);
extern void func_080A95A4(void);
#endif
extern void func_080E1FAC(void);
extern void func_080E2018(void);
extern void func_080713AC(void);
extern void func_08070C88(void);
extern void func_08075DEC(void);
extern void func_08075328(void);
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
extern void func_08023688(void);
extern void func_08020034(void);
extern void vfunc_10__7AEntity(void);
extern void vfunc_14__7AEntity(void);
extern void func_08023720(void);
extern void vfunc_1C__7AEntityUi(void);
extern void vfunc_20__7AEntity(void);
extern void vfunc_24__7AEntity(void);
extern void vfunc_28__C7AEntity(void);
extern void func_0803242C(void);
extern void func_08024280(void);
extern void func_080324B8(void);
extern void func_080328D4(void);
extern void func_08023E64(void);
extern void func_08023F40(void);
extern void func_08023F8C(void);
extern void func_08020064(void);
extern void func_08023F90(void);
extern void func_08023FB8(void);
extern void func_08020070(void);
extern void func_08023FC8(void);
extern void func_08023FD4(void);
extern void func_08023FE0(void);
extern void func_08024010(void);
extern void func_08020084(void);
extern void func_080240A0(void);
extern void func_080240AC(void);
extern void func_08020090(void);
extern void func_0802410C(void);
extern void func_0802414C(void);
extern void func_08024170(void);
extern void func_080241FC(void);
extern void func_080236DC(void);
#else
extern void func_080238F4(void);
extern void func_080202A0(void);
extern void vfunc_10__7AEntity(void);
extern void vfunc_14__7AEntity(void);
extern void func_0802398C(void);
extern void vfunc_1C__7AEntityUi(void);
extern void vfunc_20__7AEntity(void);
extern void vfunc_24__7AEntity(void);
extern void vfunc_28__C7AEntity(void);
extern void func_0803242C(void);
extern void func_080244EC(void);
extern void func_080324B8(void);
extern void func_08032B40(void);
extern void func_080240D0(void);
extern void func_080241AC(void);
extern void func_080241F8(void);
extern void func_080202D0(void);
extern void func_080241FC(void);
extern void func_08024224(void);
extern void func_080202DC(void);
extern void func_08024234(void);
extern void func_08024240(void);
extern void func_0802424C(void);
extern void func_0802427C(void);
extern void func_080202F0(void);
extern void func_0802430C(void);
extern void func_08024318(void);
extern void func_080202FC(void);
extern void func_08024378(void);
extern void func_080243B8(void);
extern void func_080243DC(void);
extern void func_08024468(void);
extern void func_08023948(void);
#endif

// Preserve this 35-slot table and its region-specific callback targets in ROM order.
extern RawVTableFunction const vtable_unk_080E6284[]
    SECTION(".rodata.vtable_6284") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_08023688,
        func_08020034,
        vfunc_10__7AEntity,
        vfunc_14__7AEntity,
        func_08023720,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08024280,
        func_080324B8,
        func_080328D4,
        func_08023E64,
        func_08023F40,
        func_08023F8C,
        func_08020064,
        func_08023F90,
        func_08023FB8,
        func_08020070,
        func_08023FC8,
        func_08023FD4,
        func_08023FE0,
        func_08024010,
        func_08020084,
        func_080240A0,
        func_080240AC,
        func_08020090,
        func_0802410C,
        func_0802414C,
        func_08024170,
        func_080241FC,
        func_080236DC,
#else
        nullptr,
        nullptr,
        func_080238F4,
        func_080202A0,
        vfunc_10__7AEntity,
        vfunc_14__7AEntity,
        func_0802398C,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_080244EC,
        func_080324B8,
        func_08032B40,
        func_080240D0,
        func_080241AC,
        func_080241F8,
        func_080202D0,
        func_080241FC,
        func_08024224,
        func_080202DC,
        func_08024234,
        func_08024240,
        func_0802424C,
        func_0802427C,
        func_080202F0,
        func_0802430C,
        func_08024318,
        func_080202FC,
        func_08024378,
        func_080243B8,
        func_080243DC,
        func_08024468,
        func_08023948,
#endif
    };

#if defined(REGION_JP)
extern void func_080229F4(void);
extern void func_08022A8C(void);
extern void func_080235B4(void);
extern void func_080231A8(void);
extern void func_0802328C(void);
extern void func_080232D8(void);
extern void func_080232DC(void);
extern void func_08020068(void);
extern void func_08023304(void);
extern void func_08023314(void);
extern void func_08020074(void);
extern void func_08023320(void);
extern void func_0802332C(void);
extern void func_0802335C(void);
extern void func_080233EC(void);
extern void func_08020088(void);
extern void func_080233F8(void);
extern void func_08023458(void);
extern void func_08020094(void);
extern void func_08023478(void);
extern void func_0802349C(void);
extern void func_08023528(void);
extern void func_08022A48(void);
#else
extern void func_08022C60(void);
extern void func_08022CF8(void);
extern void func_08023820(void);
extern void func_08023414(void);
extern void func_080234F8(void);
extern void func_08023544(void);
extern void func_08023548(void);
extern void func_080202D4(void);
extern void func_08023570(void);
extern void func_08023580(void);
extern void func_080202E0(void);
extern void func_0802358C(void);
extern void func_08023598(void);
extern void func_080235C8(void);
extern void func_08023658(void);
extern void func_080202F4(void);
extern void func_08023664(void);
extern void func_080236C4(void);
extern void func_08020300(void);
extern void func_080236E4(void);
extern void func_08023708(void);
extern void func_08023794(void);
extern void func_08022CB4(void);
#endif

// Preserve this 35-slot table and its region-specific callback targets in ROM order.
extern RawVTableFunction const vtable_unk_080E6310[]
    SECTION(".rodata.vtable_6310") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_080229F4,
        func_08020034,
        vfunc_10__7AEntity,
        vfunc_14__7AEntity,
        func_08022A8C,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_080235B4,
        func_080324B8,
        func_080328D4,
        func_080231A8,
        func_0802328C,
        func_080232D8,
        func_080232DC,
        func_08020068,
        func_08023304,
        func_08023314,
        func_08020074,
        func_08023320,
        func_0802332C,
        func_0802335C,
        func_080233EC,
        func_08020088,
        func_080233F8,
        func_08023458,
        func_08020094,
        func_08023478,
        func_0802349C,
        func_08023528,
        func_08022A48,
#else
        nullptr,
        nullptr,
        func_08022C60,
        func_080202A0,
        vfunc_10__7AEntity,
        vfunc_14__7AEntity,
        func_08022CF8,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08023820,
        func_080324B8,
        func_08032B40,
        func_08023414,
        func_080234F8,
        func_08023544,
        func_08023548,
        func_080202D4,
        func_08023570,
        func_08023580,
        func_080202E0,
        func_0802358C,
        func_08023598,
        func_080235C8,
        func_08023658,
        func_080202F4,
        func_08023664,
        func_080236C4,
        func_08020300,
        func_080236E4,
        func_08023708,
        func_08023794,
        func_08022CB4,
#endif
    };

#if defined(REGION_JP)
extern void func_08022184(void);
extern void func_080228CC(void);
extern void func_0802221C(void);
extern void func_08022250(void);
extern void func_08022904(void);
extern void func_08020058(void);
extern void func_0802005C(void);
extern void func_0802274C(void);
extern void func_0802006C(void);
extern void func_08022750(void);
extern void func_0802275C(void);
extern void func_0802278C(void);
extern void func_0802008C(void);
extern void func_0802281C(void);
extern void func_08022840(void);
extern void func_080200A0(void);
extern void func_080221D8(void);
#else
extern void func_080223F0(void);
extern void func_08022B38(void);
extern void func_08022488(void);
extern void func_080224BC(void);
extern void func_08022B70(void);
extern void func_080202C4(void);
extern void func_080202C8(void);
extern void func_080229B8(void);
extern void func_080202D8(void);
extern void func_080229BC(void);
extern void func_080229C8(void);
extern void func_080229F8(void);
extern void func_080202F8(void);
extern void func_08022A88(void);
extern void func_08022AAC(void);
extern void func_0802030C(void);
extern void func_08022444(void);
#endif

// Preserve this 35-slot table and its region-specific callback targets in ROM order.
extern RawVTableFunction const vtable_unk_080E639C[]
    SECTION(".rodata.vtable_639c") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_08022184,
        func_080228CC,
        vfunc_10__7AEntity,
        vfunc_14__7AEntity,
        func_0802221C,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
        func_08022250,
        func_08022904,
        func_080324B8,
        func_080328D4,
        func_08020058,
        func_0802005C,
        func_0802274C,
        func_08020064,
        func_08020068,
        func_0802006C,
        func_08020070,
        func_08020074,
        func_08022750,
        func_0802275C,
        func_0802278C,
        func_08020084,
        func_08020088,
        func_0802008C,
        func_08020090,
        func_08020094,
        func_0802281C,
        func_08022840,
        func_080200A0,
        func_080221D8,
#else
        nullptr,
        nullptr,
        func_080223F0,
        func_08022B38,
        vfunc_10__7AEntity,
        vfunc_14__7AEntity,
        func_08022488,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
        func_080224BC,
        func_08022B70,
        func_080324B8,
        func_08032B40,
        func_080202C4,
        func_080202C8,
        func_080229B8,
        func_080202D0,
        func_080202D4,
        func_080202D8,
        func_080202DC,
        func_080202E0,
        func_080229BC,
        func_080229C8,
        func_080229F8,
        func_080202F0,
        func_080202F4,
        func_080202F8,
        func_080202FC,
        func_08020300,
        func_08022A88,
        func_08022AAC,
        func_0802030C,
        func_08022444,
#endif
    };

#if defined(REGION_JP)
extern void func_080214D0(void);
extern void func_08021580(void);
extern void func_08021C3C(void);
extern void func_080220DC(void);
extern void func_08021E94(void);
extern void func_08020060(void);
extern void func_08021EE8(void);
extern void func_08020078(void);
extern void func_0802007C(void);
extern void func_08020080(void);
extern void func_08021EF8(void);
extern void func_08020098(void);
extern void func_0802009C(void);
extern void func_08021F30(void);
extern void func_0802153C(void);
#else
extern void func_0802173C(void);
extern void func_080217EC(void);
extern void func_08021EA8(void);
extern void func_08022348(void);
extern void func_08022100(void);
extern void func_080202CC(void);
extern void func_08022154(void);
extern void func_080202E4(void);
extern void func_080202E8(void);
extern void func_080202EC(void);
extern void func_08022164(void);
extern void func_08020304(void);
extern void func_08020308(void);
extern void func_0802219C(void);
extern void func_080217A8(void);
#endif

// Preserve this 35-slot table and its region-specific callback targets in ROM order.
extern RawVTableFunction const vtable_unk_080E6428[]
    SECTION(".rodata.vtable_6428") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_080214D0,
        func_08020034,
        vfunc_10__7AEntity,
        vfunc_14__7AEntity,
        func_08021580,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
        func_08021C3C,
        func_080220DC,
        func_080324B8,
        func_080328D4,
        func_08020058,
        func_08021E94,
        func_08020060,
        func_08020064,
        func_08020068,
        func_08021EE8,
        func_08020070,
        func_08020074,
        func_08020078,
        func_0802007C,
        func_08020080,
        func_08020084,
        func_08020088,
        func_08021EF8,
        func_08020090,
        func_08020094,
        func_08020098,
        func_0802009C,
        func_08021F30,
        func_0802153C,
#else
        nullptr,
        nullptr,
        func_0802173C,
        func_080202A0,
        vfunc_10__7AEntity,
        vfunc_14__7AEntity,
        func_080217EC,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
        func_08021EA8,
        func_08022348,
        func_080324B8,
        func_08032B40,
        func_080202C4,
        func_08022100,
        func_080202CC,
        func_080202D0,
        func_080202D4,
        func_08022154,
        func_080202DC,
        func_080202E0,
        func_080202E4,
        func_080202E8,
        func_080202EC,
        func_080202F0,
        func_080202F4,
        func_08022164,
        func_080202FC,
        func_08020300,
        func_08020304,
        func_08020308,
        func_0802219C,
        func_080217A8,
#endif
    };

extern void func_080DC5F4(void);
extern void func_0803260C(void);
#if defined(REGION_JP)
extern void func_08022088(void);
#else
extern void func_080222F4(void);
#endif

// Preserve this five-slot table and its region-specific final callback in ROM order.
extern RawVTableFunction const vtable_unk_080E64B4[]
    SECTION(".rodata.vtable_64b4") = {
        nullptr,
        nullptr,
        func_080DC5F4,
        func_0803260C,
#if defined(REGION_JP)
        func_08022088,
#else
        func_080222F4,
#endif
    };

#if defined(REGION_JP)
extern void func_08020138(void);
extern void func_08021390(void);
extern void func_08020208(void);
extern void func_0802023C(void);
extern void func_080213C8(void);
extern void func_08021138(void);
extern void func_08021144(void);
extern void func_080201A4(void);
#else
extern void func_080203A4(void);
extern void func_080215FC(void);
extern void func_08020474(void);
extern void func_080204A8(void);
extern void func_08021634(void);
extern void func_080213A4(void);
extern void func_080213B0(void);
extern void func_08020410(void);
#endif

// Preserve this 35-slot table and its region-specific callback targets in ROM order.
extern RawVTableFunction const vtable_unk_080E64C8[]
    SECTION(".rodata.vtable_64c8") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_08020138,
        func_08021390,
        vfunc_10__7AEntity,
        vfunc_14__7AEntity,
        func_08020208,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
        func_0802023C,
        func_080213C8,
        func_080324B8,
        func_080328D4,
        func_08020058,
        func_0802005C,
        func_08021138,
        func_08020064,
        func_08020068,
        func_0802006C,
        func_08020070,
        func_08020074,
        func_08020078,
        func_0802007C,
        func_08021144,
        func_08020084,
        func_08020088,
        func_0802008C,
        func_08020090,
        func_08020094,
        func_08020098,
        func_0802009C,
        func_080200A0,
        func_080201A4,
#else
        nullptr,
        nullptr,
        func_080203A4,
        func_080215FC,
        vfunc_10__7AEntity,
        vfunc_14__7AEntity,
        func_08020474,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
        func_080204A8,
        func_08021634,
        func_080324B8,
        func_08032B40,
        func_080202C4,
        func_080202C8,
        func_080213A4,
        func_080202D0,
        func_080202D4,
        func_080202D8,
        func_080202DC,
        func_080202E0,
        func_080202E4,
        func_080202E8,
        func_080213B0,
        func_080202F0,
        func_080202F4,
        func_080202F8,
        func_080202FC,
        func_08020300,
        func_08020304,
        func_08020308,
        func_0802030C,
        func_08020410,
#endif
    };

extern void func_080DC6028(void);
#if defined(REGION_JP)
extern void func_08024330(void);
#else
extern void func_0802459C(void);
#endif

// Preserve this 35-slot virtual table and its region-specific callbacks in ROM order.
extern RawVTableFunction const __vt_15Entity_080E6554[]
    SECTION(".rodata.vtable_6554") = {
        nullptr,
        nullptr,
        func_080DC6028,
#if defined(REGION_JP)
        func_08020034,
#else
        func_080202A0,
#endif
        vfunc_10__7AEntity,
        vfunc_14__7AEntity,
#if defined(REGION_JP)
        func_08024330,
#else
        func_0802459C,
#endif
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
        func_0803242C,
        __pure_virtual,
        func_080324B8,
#if defined(REGION_JP)
        func_080328D4,
#else
        func_08032B40,
#endif
#if defined(REGION_JP)
        func_08020058,
        func_0802005C,
        func_08020060,
        func_08020064,
        func_08020068,
        func_0802006C,
        func_08020070,
        func_08020074,
        func_08020078,
        func_0802007C,
        func_08020080,
        func_08020084,
        func_08020088,
        func_0802008C,
        func_08020090,
        func_08020094,
        func_08020098,
        func_0802009C,
        func_080200A0,
#else
        func_080202C4,
        func_080202C8,
        func_080202CC,
        func_080202D0,
        func_080202D4,
        func_080202D8,
        func_080202DC,
        func_080202E0,
        func_080202E4,
        func_080202E8,
        func_080202EC,
        func_080202F0,
        func_080202F4,
        func_080202F8,
        func_080202FC,
        func_08020300,
        func_08020304,
        func_08020308,
        func_0802030C,
#endif
        __pure_virtual,
    };

extern void func_080DC605C(void);

// Preserve this five-slot table in ROM order.
extern RawVTableFunction const vtable_unk_080E65E0[]
    SECTION(".rodata.vtable_65e0") = {
        nullptr,
        nullptr,
        func_080DC605C,
        __pure_virtual,
        __pure_virtual,
    };

extern void func_080DC6F0(void);
extern void func_0803240C(void);
extern void func_08032A30(void);
#if defined(REGION_JP)
extern void func_0802B7BC(void);
extern void func_0802B7A4(void);
extern void func_0802C068(void);
extern void func_0802BA38(void);
extern void func_0802BAE4(void);
extern void func_0802BBFC(void);
extern void func_0802BC90(void);
#else
extern void func_0802BA28(void);
extern void func_0802BA10(void);
extern void func_0802C2D4(void);
extern void func_0802BCA4(void);
extern void func_0802BD50(void);
extern void func_0802BE68(void);
extern void func_0802BEFC(void);
#endif

// Preserve this 20-slot table and its regional entity callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E65F4[]
    SECTION(".rodata.vtable_65f4") = {
        nullptr,
        nullptr,
        func_080DC6F0,
        func_0803240C,
        vfunc_10__7AEntity,
        vfunc_14__7AEntity,
        func_08032A30,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
#if defined(REGION_JP)
        func_0802B7BC,
        func_0802B7A4,
#else
        func_0802BA28,
        func_0802BA10,
#endif
        func_080324B8,
#if defined(REGION_JP)
        func_080328D4,
        func_0802C068,
        func_0802BA38,
        func_0802BAE4,
        func_0802BBFC,
        func_0802BC90,
#else
        func_08032B40,
        func_0802C2D4,
        func_0802BCA4,
        func_0802BD50,
        func_0802BE68,
        func_0802BEFC,
#endif
    };

extern void func_080DC724(void);
#if defined(REGION_JP)
extern void func_0802BD34(void);
extern void func_0802BD78(void);
#else
extern void func_0802BFA0(void);
extern void func_0802BFE4(void);
#endif

// Preserve this five-slot table and its regional callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6644[]
    SECTION(".rodata.vtable_6644") = {
        nullptr,
        nullptr,
        func_080DC724,
#if defined(REGION_JP)
        func_0802BD34,
        func_0802BD78,
#else
        func_0802BFA0,
        func_0802BFE4,
#endif
    };

#if defined(REGION_JP)
extern void func_08024814(void);
extern void func_08024990(void);
extern void func_0802497C(void);
extern void func_08024A64(void);
extern void func_080249E8(void);
extern void func_080249F8(void);
extern void func_08024DAC(void);
extern void func_08024930(void);
extern void func_08031E08(void);
extern void func_08031DF0(void);
extern void func_08031DE8(void);
extern void func_08027990(void);
extern void func_080283D8(void);
extern void func_080288E4(void);
extern void func_08028E10(void);
extern void func_0802A194(void);
extern void func_08028E68(void);
extern void func_080292EC(void);
extern void func_08024DFC(void);
extern void func_08026AA8(void);
extern void func_08029764(void);
extern void func_08029780(void);
extern void func_08029CC4(void);
extern void func_08031DE0(void);
extern void func_080260E0(void);
extern void func_080265C4(void);
extern void func_08031DD8(void);
extern void func_08031DD0(void);
extern void func_08031DC8(void);
extern void func_08031DBC(void);
extern void func_08031DC0(void);
extern void func_08024A34(void);
extern void func_08031DB4(void);
extern void func_08031DAC(void);
extern void func_08024A08(void);
extern void func_08024A1C(void);
extern void func_08024A2C(void);
#else
extern void func_08024A80(void);
extern void func_08024BFC(void);
extern void func_08024BE8(void);
extern void func_08024CD0(void);
extern void func_08024C54(void);
extern void func_08024C64(void);
extern void func_08025018(void);
extern void func_08024B9C(void);
extern void func_08032074(void);
extern void func_0803205C(void);
extern void func_08032054(void);
extern void func_08027BFC(void);
extern void func_08028644(void);
extern void func_08028B50(void);
extern void func_0802907C(void);
extern void func_0802A400(void);
extern void func_080290D4(void);
extern void func_08029558(void);
extern void func_08025068(void);
extern void func_08026D14(void);
extern void func_080299D0(void);
extern void func_080299EC(void);
extern void func_08029F30(void);
extern void func_0803204C(void);
extern void func_0802634C(void);
extern void func_08026830(void);
extern void func_08032044(void);
extern void func_0803203C(void);
extern void func_08032034(void);
extern void func_08032028(void);
extern void func_0803202C(void);
extern void func_08024CA0(void);
extern void func_08032020(void);
extern void func_08032018(void);
extern void func_08024C74(void);
extern void func_08024C88(void);
extern void func_08024C98(void);
#endif

// Preserve this 44-slot table and its region-specific callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6658[]
    SECTION(".rodata.vtable_6658") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_08024814,
        func_08024990,
        func_0802497C,
        vfunc_14__7AEntity,
        func_08024A64,
        vfunc_1C__7AEntityUi,
        func_080249E8,
        func_080249F8,
        vfunc_28__C7AEntity,
        func_08024DAC,
        func_08024930,
        func_080324B8,
        func_080328D4,
        func_08031E08,
        func_08031DF0,
        func_08031DE8,
        func_08027990,
        func_080283D8,
        func_080288E4,
        func_08028E10,
        func_0802A194,
        func_08028E68,
        func_080292EC,
        func_08024DFC,
        func_08026AA8,
        func_08029764,
        func_08029780,
        func_08029CC4,
        func_08031DE0,
        func_080260E0,
        func_080265C4,
        func_08031DD8,
        func_08031DD0,
        func_08031DC8,
        func_08031DBC,
        func_08031DC0,
        func_08024A34,
        func_08031DB4,
        func_08031DAC,
        func_08024A08,
        func_08024A1C,
        func_08024A2C,
#else
        nullptr,
        nullptr,
        func_08024A80,
        func_08024BFC,
        func_08024BE8,
        vfunc_14__7AEntity,
        func_08024CD0,
        vfunc_1C__7AEntityUi,
        func_08024C54,
        func_08024C64,
        vfunc_28__C7AEntity,
        func_08025018,
        func_08024B9C,
        func_080324B8,
        func_08032B40,
        func_08032074,
        func_0803205C,
        func_08032054,
        func_08027BFC,
        func_08028644,
        func_08028B50,
        func_0802907C,
        func_0802A400,
        func_080290D4,
        func_08029558,
        func_08025068,
        func_08026D14,
        func_080299D0,
        func_080299EC,
        func_08029F30,
        func_0803204C,
        func_0802634C,
        func_08026830,
        func_08032044,
        func_0803203C,
        func_08032034,
        func_08032028,
        func_0803202C,
        func_08024CA0,
        func_08032020,
        func_08032018,
        func_08024C74,
        func_08024C88,
        func_08024C98,
#endif
    };

extern void func_080DC764(void);
#if defined(REGION_JP)
extern void func_0802B148(void);
extern void func_0802B2B0(void);
#else
extern void func_0802B3B4(void);
extern void func_0802B51C(void);
#endif

// Preserve this five-slot table and its regional callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6708[]
    SECTION(".rodata.vtable_6708") = {
        nullptr,
        nullptr,
        func_080DC764,
#if defined(REGION_JP)
        func_0802B148,
        func_0802B2B0,
#else
        func_0802B3B4,
        func_0802B51C,
#endif
    };

extern void func_0803240C(void);
extern void vfunc_10__7AEntity(void);
extern void vfunc_14__7AEntity(void);
extern void func_08032A30(void);
extern void vfunc_1C__7AEntityUi(void);
extern void vfunc_20__7AEntity(void);
extern void vfunc_24__7AEntity(void);
extern void vfunc_28__C7AEntity(void);
extern void func_0803242C(void);
extern void func_080324B8(void);
#if defined(REGION_JP)
extern void func_080DBF80(void);
extern void func_080328D4(void);
#else
extern void func_080DC7CC(void);
extern void func_08032B40(void);
#endif

// Preserve this 20-slot table and its region-specific callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E671C[]
    SECTION(".rodata.vtable_671c") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080DBF80,
#else
        func_080DC7CC,
#endif
        func_0803240C,
        vfunc_10__7AEntity,
        vfunc_14__7AEntity,
        func_08032A30,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
        func_0803242C,
        __pure_virtual,
        func_080324B8,
#if defined(REGION_JP)
        func_080328D4,
#else
        func_08032B40,
#endif
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
    };

#if defined(REGION_JP)
extern void func_080DBFB4(void);
#else
extern void func_080DC800(void);
#endif

// Preserve this 44-slot table and its region-specific callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E676C[]
    SECTION(".rodata.vtable_676c") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080DBFB4,
#else
        func_080DC800,
#endif
        func_0803240C,
        vfunc_10__7AEntity,
        vfunc_14__7AEntity,
        func_08032A30,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
        func_0803242C,
        __pure_virtual,
        func_080324B8,
#if defined(REGION_JP)
        func_080328D4,
#else
        func_08032B40,
#endif
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
    };

#if defined(REGION_JP)
extern void func_080DBFE8(void);
#else
extern void func_080DC834(void);
#endif

// Preserve this three-slot table and its regional callback in ROM order.
extern RawVTableFunction const vtable_unk_080E681C[]
    SECTION(".rodata.vtable_681c") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080DBFE8,
#else
        func_080DC834,
#endif
    };

#if defined(REGION_JP)
extern void func_080326F0(void);
extern void func_08032770(void);
extern void func_08032748(void);
extern void func_08032760(void);
extern void func_08032768(void);
#else
extern void func_0803295C(void);
extern void func_080329DC(void);
extern void func_080329B4(void);
extern void func_080329CC(void);
extern void func_080329D4(void);
#endif

// Preserve this 15-slot table and its regional callback entries in ROM order.
extern RawVTableFunction const vtable_unk_080E6828[]
    SECTION(".rodata.vtable_6828") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080326F0,
        func_08032770,
#else
        func_0803295C,
        func_080329DC,
#endif
        vfunc_10__7AEntity,
        vfunc_14__7AEntity,
        func_08032A30,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
        func_0803242C,
#if defined(REGION_JP)
        func_08032748,
        func_08032760,
        func_08032768,
#else
        func_080329B4,
        func_080329CC,
        func_080329D4,
#endif
    };

extern void func_0803260C(void);
extern void func_08032690(void);
#if defined(REGION_JP)
extern void func_080DC044(void);
#else
extern void func_080DC890(void);
#endif

// Preserve this five-slot table and its regional callback in ROM order.
extern RawVTableFunction const vtable_unk_080E6864[]
    SECTION(".rodata.vtable_6864") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080DC044,
#else
        func_080DC890,
#endif
        func_0803260C,
        func_08032690,
    };

#if defined(REGION_JP)
extern void func_080DC078(void);
#else
extern void func_080DC8C4(void);
#endif

// Preserve AActorEntity's 15 ABI slots in original ROM order.
extern RawVTableFunction const __vt_12AActorEntity[]
    SECTION(".rodata.vtable_aactor_entity") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080DC078,
#else
        func_080DC8C4,
#endif
        func_0803240C,
        vfunc_10__7AEntity,
        vfunc_14__7AEntity,
        func_08032A30,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
        func_0803242C,
        __pure_virtual,
        func_080324B8,
#if defined(REGION_JP)
        func_080328D4,
#else
        func_08032B40,
#endif
    };

#if defined(REGION_JP)
extern void func_080DC0AC(void);
#else
extern void func_080DC8F8(void);
#endif

// Preserve this five-slot table and its regional callback in ROM order.
extern RawVTableFunction const vtable_unk_080E68B4[]
    SECTION(".rodata.vtable_68b4") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080DC0AC,
#else
        func_080DC8F8,
#endif
        func_0803260C,
        func_08032690,
    };

extern void func_08033A2C(void);
extern void func_08033B10(void);
extern void func_08033B94(void);
extern void func_08033AE4(void);
extern void func_08033A80(void);
extern void func_08033AFC(void);

// Preserve this 15-slot table and its regional terminal callback in ROM order.
extern RawVTableFunction const vtable_unk_080E68C8[]
    SECTION(".rodata.vtable_68c8") = {
        nullptr,
        nullptr,
        func_08033A2C,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08033B10,
        func_08033B94,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08033AE4,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08033A80,
        func_08033AFC,
#if defined(REGION_JP)
        func_080328D4,
#else
        func_08032B40,
#endif
    };

extern void func_08034AA0(void);
extern void func_08034AE8(void);
#if defined(REGION_JP)
extern void func_080DC0E0(void);
#else
extern void func_080DC92C(void);
#endif

// Preserve this five-slot table and its regional callback in ROM order.
extern RawVTableFunction const vtable_unk_080E6904[]
    SECTION(".rodata.vtable_6904") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080DC0E0,
#else
        func_080DC92C,
#endif
        func_08034AA0,
        func_08034AE8,
    };

extern void func_080DC9A8(void);
extern void func_08034E8C(void);
extern void func_08036F68(void);
extern void func_08034EA0(void);
extern void func_08036F0C(void);
extern void func_08034EE0(void);
extern void func_08034EF8(void);
extern void func_08036EF0(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6918[]
    SECTION(".rodata.vtable_6918") = {
        nullptr,
        nullptr,
        func_080DC9A8,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08036F68,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08036F0C,
        func_08034EE0,
        func_08034EF8,
        func_08036EF0,
    };

extern void func_080DC9B4(void);
extern void func_08034EB4(void);
extern void func_08036E00(void);
extern void func_08034F00(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6958[]
    SECTION(".rodata.vtable_6958") = {
        nullptr,
        nullptr,
        func_080DC9B4,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08036E00,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DC9C0(void);
extern void func_08036D98(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6998[]
    SECTION(".rodata.vtable_6998") = {
        nullptr,
        nullptr,
        func_080DC9C0,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08036D98,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DC9CC(void);
extern void func_08036D3C(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E69D8[]
    SECTION(".rodata.vtable_69d8") = {
        nullptr,
        nullptr,
        func_080DC9CC,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08036D3C,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DC9D8(void);
extern void func_08036CDC(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6A18[]
    SECTION(".rodata.vtable_6a18") = {
        nullptr,
        nullptr,
        func_080DC9D8,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08036CDC,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DC9E4(void);
extern void func_08036C80(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6A58[]
    SECTION(".rodata.vtable_6a58") = {
        nullptr,
        nullptr,
        func_080DC9E4,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08036C80,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DC9F0(void);
extern void func_08036BB0(void);
extern void func_08036B80(void);
extern void func_08036BF8(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6A98[]
    SECTION(".rodata.vtable_6a98") = {
        nullptr,
        nullptr,
        func_080DC9F0,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08036BB0,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08036B80,
        func_08034EE0,
        func_08034EF8,
        func_08036BF8,
    };

extern void func_080DC9FC(void);
extern void func_08036B1C(void);
extern void func_08036B00(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6AD8[]
    SECTION(".rodata.vtable_6ad8") = {
        nullptr,
        nullptr,
        func_080DC9FC,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08036B1C,
        func_08034EE0,
        func_08034EF8,
        func_08036B00,
    };

extern void func_080DCA08(void);
extern void func_08036A4C(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6B18[]
    SECTION(".rodata.vtable_6b18") = {
        nullptr,
        nullptr,
        func_080DCA08,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08036A4C,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DCA14(void);
extern void func_080369E0(void);
extern void func_080369C4(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6B58[]
    SECTION(".rodata.vtable_6b58") = {
        nullptr,
        nullptr,
        func_080DCA14,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_080369E0,
        func_08034EE0,
        func_08034EF8,
        func_080369C4,
    };

extern void func_080DCA20(void);
extern void func_08036898(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6B98[]
    SECTION(".rodata.vtable_6b98") = {
        nullptr,
        nullptr,
        func_080DCA20,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08036898,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DCA2C(void);
extern void func_08036834(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6BD8[]
    SECTION(".rodata.vtable_6bd8") = {
        nullptr,
        nullptr,
        func_080DCA2C,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08036834,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DCA38(void);
extern void func_080367C8(void);
extern void func_080367AC(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6C18[]
    SECTION(".rodata.vtable_6c18") = {
        nullptr,
        nullptr,
        func_080DCA38,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_080367C8,
        func_08034EE0,
        func_08034EF8,
        func_080367AC,
    };

extern void func_080DCA44(void);
extern void func_08036704(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6C58[]
    SECTION(".rodata.vtable_6c58") = {
        nullptr,
        nullptr,
        func_080DCA44,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08036704,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DCA50(void);
extern void func_0803669C(void);
extern void func_08036680(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6C98[]
    SECTION(".rodata.vtable_6c98") = {
        nullptr,
        nullptr,
        func_080DCA50,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_0803669C,
        func_08034EE0,
        func_08034EF8,
        func_08036680,
    };

extern void func_080DCA5C(void);
extern void func_08036564(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6CD8[]
    SECTION(".rodata.vtable_6cd8") = {
        nullptr,
        nullptr,
        func_080DCA5C,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08036564,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DCA68(void);
extern void func_08036500(void);
extern void func_080364E4(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6D18[]
    SECTION(".rodata.vtable_6d18") = {
        nullptr,
        nullptr,
        func_080DCA68,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08036500,
        func_08034EE0,
        func_08034EF8,
        func_080364E4,
    };

extern void func_080DCA74(void);
extern void func_080363CC(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6D58[]
    SECTION(".rodata.vtable_6d58") = {
        nullptr,
        nullptr,
        func_080DCA74,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_080363CC,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DCA80(void);
extern void func_08036364(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6D98[]
    SECTION(".rodata.vtable_6d98") = {
        nullptr,
        nullptr,
        func_080DCA80,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08036364,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DCA8C(void);
extern void func_080362FC(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6DD8[]
    SECTION(".rodata.vtable_6dd8") = {
        nullptr,
        nullptr,
        func_080DCA8C,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_080362FC,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DCA98(void);
extern void func_08036290(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6E18[]
    SECTION(".rodata.vtable_6e18") = {
        nullptr,
        nullptr,
        func_080DCA98,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08036290,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DCAA4(void);
extern void func_08036228(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6E58[]
    SECTION(".rodata.vtable_6e58") = {
        nullptr,
        nullptr,
        func_080DCAA4,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08036228,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DCAB0(void);
extern void func_080361C0(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6E98[]
    SECTION(".rodata.vtable_6e98") = {
        nullptr,
        nullptr,
        func_080DCAB0,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_080361C0,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DCABC(void);
extern void func_08036154(void);
extern void func_08036138(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6ED8[]
    SECTION(".rodata.vtable_6ed8") = {
        nullptr,
        nullptr,
        func_080DCABC,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08036154,
        func_08034EE0,
        func_08034EF8,
        func_08036138,
    };

extern void func_080DCAC8(void);
extern void func_0803601C(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6F18[]
    SECTION(".rodata.vtable_6f18") = {
        nullptr,
        nullptr,
        func_080DCAC8,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_0803601C,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DCAD4(void);
extern void func_08035FB0(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6F58[]
    SECTION(".rodata.vtable_6f58") = {
        nullptr,
        nullptr,
        func_080DCAD4,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08035FB0,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DCAE0(void);
extern void func_08035F48(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6F98[]
    SECTION(".rodata.vtable_6f98") = {
        nullptr,
        nullptr,
        func_080DCAE0,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08035F48,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DCAEC(void);
extern void func_08035EE4(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E6FD8[]
    SECTION(".rodata.vtable_6fd8") = {
        nullptr,
        nullptr,
        func_080DCAEC,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08035EE4,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DCAF8(void);
extern void func_08035E7C(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E7018[]
    SECTION(".rodata.vtable_7018") = {
        nullptr,
        nullptr,
        func_080DCAF8,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08035E7C,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DCB04(void);
extern void func_08035E14(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E7058[]
    SECTION(".rodata.vtable_7058") = {
        nullptr,
        nullptr,
        func_080DCB04,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08035E14,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DCB10(void);
extern void func_08035DAC(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E7098[]
    SECTION(".rodata.vtable_7098") = {
        nullptr,
        nullptr,
        func_080DCB10,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08035DAC,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DCB1C(void);
extern void func_08035D40(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E70D8[]
    SECTION(".rodata.vtable_70d8") = {
        nullptr,
        nullptr,
        func_080DCB1C,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08035D40,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DCB28(void);
extern void func_08035CD4(void);
extern void func_08035CB8(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E7118[]
    SECTION(".rodata.vtable_7118") = {
        nullptr,
        nullptr,
        func_080DCB28,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08035CD4,
        func_08034EE0,
        func_08034EF8,
        func_08035CB8,
    };

extern void func_080DCB34(void);
extern void func_08035B9C(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E7158[]
    SECTION(".rodata.vtable_7158") = {
        nullptr,
        nullptr,
        func_080DCB34,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08035B9C,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DCB40(void);
extern void func_08035B38(void);

// Preserve this 16-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E7198[]
    SECTION(".rodata.vtable_7198") = {
        nullptr,
        nullptr,
        func_080DCB40,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_08035B38,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

// The original destructor has a legacy assembler symbol that is not a valid
// C++ identifier; retain that exact linkage name for the table relocation.
extern void destructor_ANpcEntity(void) asm("_._10ANpcEntity");

// Preserve the ANpcEntity ABI table and its exact callbacks in ROM order.
extern RawVTableFunction const __vt_10ANpcEntity[]
    SECTION(".rodata.vtable_npc_entity") = {
        nullptr,
        nullptr,
        destructor_ANpcEntity,
        func_0803240C,
        vfunc_10__7AEntity,
        func_08034E8C,
        func_08034EB4,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        func_08034EA0,
        vfunc_28__C7AEntity,
        func_0803242C,
        __pure_virtual,
        func_08034EE0,
        func_08034EF8,
        func_08034F00,
    };

extern void func_080DCB4C(void);
extern void func_08037470(void);
extern void func_08037434(void);
extern void func_0803745C(void);
extern void func_0803726C(void);
extern void func_080379D8(void);
extern void func_08037430(void);
extern void func_08037A04(void);
extern void func_08037958(void);

// Preserve this 17-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E7218[]
    SECTION(".rodata.vtable_7218") = {
        nullptr,
        nullptr,
        func_080DCB4C,
        func_08037470,
        func_08037434,
        func_0803745C,
        func_0803726C,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_080379D8,
        func_08037430,
#if defined(REGION_JP)
        func_080328D4,
#else
        func_08032B40,
#endif
        func_08037A04,
        func_08037958,
    };

extern void func_080DCB58(void);
extern void func_0803788C(void);
extern void func_080378B8(void);
extern void func_080377E8(void);

// Preserve this 17-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E725C[]
    SECTION(".rodata.vtable_725c") = {
        nullptr,
        nullptr,
        func_080DCB58,
        func_08037470,
        func_08037434,
        func_0803745C,
        func_0803726C,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_0803788C,
        func_08037430,
#if defined(REGION_JP)
        func_080328D4,
#else
        func_08032B40,
#endif
        func_080378B8,
        func_080377E8,
    };

extern void func_080DCB64(void);
extern void func_080376E4(void);
extern void func_08037714(void);
extern void func_0803763C(void);

// Preserve this 17-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E72A0[]
    SECTION(".rodata.vtable_72a0") = {
        nullptr,
        nullptr,
        func_080DCB64,
        func_08037470,
        func_08037434,
        func_0803745C,
        func_0803726C,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_080376E4,
        func_08037430,
#if defined(REGION_JP)
        func_080328D4,
#else
        func_08032B40,
#endif
        func_08037714,
        func_0803763C,
    };

extern void func_080DCB70(void);
extern void func_0803753C(void);
extern void func_08037568(void);
extern void func_08037494(void);

// Preserve this 17-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E72E4[]
    SECTION(".rodata.vtable_72e4") = {
        nullptr,
        nullptr,
        func_080DCB70,
        func_08037470,
        func_08037434,
        func_0803745C,
        func_0803726C,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_0803753C,
        func_08037430,
#if defined(REGION_JP)
        func_080328D4,
#else
        func_08032B40,
#endif
        func_08037568,
        func_08037494,
    };

extern void func_08037048(void);

// Preserve this 17-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E7328[]
    SECTION(".rodata.vtable_7328") = {
        nullptr,
        nullptr,
        func_08037048,
        func_08037470,
        func_08037434,
        func_0803745C,
        func_0803726C,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
        func_0803242C,
        __pure_virtual,
        func_08037430,
#if defined(REGION_JP)
        func_080328D4,
#else
        func_08032B40,
#endif
        __pure_virtual,
        __pure_virtual,
    };

extern void func_080DCDB0(void);
extern void func_08038928(void);
extern void func_08038A70(void);

// Preserve this five-slot table and its exact callbacks in ROM order.
extern RawVTableFunction const vtable_unk_080E736C[]
    SECTION(".rodata.vtable_736c") = {
        nullptr,
        nullptr,
        func_080DCDB0,
        func_08038928,
        func_08038A70,
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

#if defined(REGION_JP)
extern void func_08051F4C(void);
extern void func_08051F8C(void);
#else
extern void func_080E1148(void);
#endif

// Preserve this three-slot region-specific callback table in ROM order.
extern RawVTableFunction const vtable_unk_080E7928[]
    SECTION(".rodata.vtable_7928") = {
#if defined(REGION_JP)
        nullptr,
        func_08051F4C,
        func_08051F8C,
#else
        nullptr,
        nullptr,
        func_080E1148,
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
        nullptr,
        func_080521BC,
        func_080521FC,
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
#if defined(REGION_JP)
        func_0805E4D4,
        nullptr,
        nullptr,
        func_080E1198,
        nullptr,
#else
        nullptr,
        nullptr,
        func_080E1984,
        Resolve__C22IndexedResourceArchiveUi,
        func_0805E790,
#endif
    };

extern RawVTableFunction const vtable_unk_080E79DC[]
    SECTION(".rodata.vtable_79dc") = {
#if defined(REGION_JP)
        nullptr,
        func_080E11C8,
        func_080E1144,
#else
        nullptr,
        nullptr,
        func_080E19F8,
#endif
    };

extern RawVTableFunction const vtable_unk_080E79E8[]
    SECTION(".rodata.vtable_79e8") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_0805FA48,
        func_0805FA88,
#else
        func_080E1A28,
        func_080E19A4,
#endif
    };

extern RawVTableFunction const vtable_unk_080E79F8[]
    SECTION(".rodata.vtable_79f8") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E11F4,
        func_080E11E8,
#else
        func_0805FD04,
        func_0805FD44,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7A08[]
    SECTION(".rodata.vtable_7a08") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E13B8,
        func_080E1210,
#else
        func_080E1A54,
        func_080E1A48,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7A18[]
    SECTION(".rodata.vtable_7a18") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E14F4,
        func_080E1410,
#else
        func_080E1C18,
        func_080E1A70,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7A28[]
    SECTION(".rodata.vtable_7a28") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E152C,
        func_08063B90,
#else
        func_080E1D54,
        func_080E1C70,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7A38[]
    SECTION(".rodata.vtable_7a38") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E1538,
        func_08063B90,
#else
        func_080E1D8C,
        func_08063E58,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7A48[]
    SECTION(".rodata.vtable_7a48") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E1544,
        func_08063B90,
#else
        func_080E1D98,
        func_08063E58,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7A58[]
    SECTION(".rodata.vtable_7a58") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E1550,
        func_08063B90,
#else
        func_080E1DA4,
        func_08063E58,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7A68[]
    SECTION(".rodata.vtable_7a68") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E1568,
        func_080E155C,
#else
        func_080E1DB0,
        func_08063E58,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7A78[]
    SECTION(".rodata.vtable_7a78") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E1574,
        func_08069C14,
#else
        func_080E1DC8,
        func_080E1DBC,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7A88[]
    SECTION(".rodata.vtable_7a88") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_08069CE8,
        func_08069D28,
#else
        func_080E1DD4,
        func_08069D84,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7A98[]
    SECTION(".rodata.vtable_7a98") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E15C8,
#else
        func_08069E58,
        func_08069E98,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7AA8[]
    SECTION(".rodata.vtable_7aa8") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_0806D710,
        func_0806D740,
#else
        func_080E1E28,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7AB4[]
    SECTION(".rodata.vtable_7ab4") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E1FAC,
        nullptr,
#else
        func_0806D918,
        func_0806D948,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7AC4[]
    SECTION(".rodata.vtable_7ac4") = {
#if defined(REGION_JP)
        nullptr,
        func_0806E65C,
        func_0806E68C,
#else
        nullptr,
        nullptr,
        func_080E1FAC,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7AD0[]
    SECTION(".rodata.vtable_7ad0") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E2018,
        nullptr,
#else
        func_0806EA00,
        func_0806EA30,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7AE0[]
    SECTION(".rodata.vtable_7ae0") = {
#if defined(REGION_JP)
        nullptr,
        func_08070634,
        func_08070664,
#else
        nullptr,
        nullptr,
        func_080E2018,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7AEC[]
    SECTION(".rodata.vtable_7aec") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E1898,
        func_08075328,
#else
        func_080709D8,
        func_08070A08,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7AFC[]
    SECTION(".rodata.vtable_7afc") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E18A4_vtable_target,
        func_08071F28,
#else
        func_080E20F8,
        func_08075328,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7B0C[]
    SECTION(".rodata.vtable_7b0c") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E18B0,
        func_080713AC,
#else
        func_080E2104,
        func_080722D0,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7B1C[]
    SECTION(".rodata.vtable_7b1c") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_08070C88,
        func_08070900,
#else
        func_080E2110,
        func_080713AC,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7B2C[]
    SECTION(".rodata.vtable_7b2c") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E18BC,
        func_080751B8,
#else
        func_08070C88,
        func_08070CA4,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7B3C[]
    SECTION(".rodata.vtable_7b3c") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_08075278,
        func_080752B8,
#else
        func_080E211C,
        func_0807555C,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7B4C[]
    SECTION(".rodata.vtable_7b4c") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_0807532C,
        nullptr,
#else
        func_0807561C,
        func_0807565C,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7B5C[]
    SECTION(".rodata.vtable_7b5c") = {
#if defined(REGION_JP)
        nullptr,
        func_08075A5C,
        func_08075DEC,
#else
        nullptr,
        nullptr,
        func_080756D0,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7B68[]
    SECTION(".rodata.vtable_7b68") = {
#if defined(REGION_JP)
        nullptr,
#else
        nullptr,
        nullptr,
        func_08075E00,
        func_08075DEC,
#endif
    };

#if defined(REGION_JP)
extern void func_080E25D4(void);
extern void __pure_virtual(void);

// This three-slot table exists only in the JP vtable range.
extern RawVTableFunction const vtable_unk_080E6FAC[]
    SECTION(".rodata.vtable_6fac") = {
        nullptr,
        func_080E25D4,
        __pure_virtual,
    };
#endif

extern RawVTableFunction const vtable_unk_080E7B78[]
    SECTION(".rodata.vtable_7b78") = {
        nullptr,
#if defined(REGION_JP)
        nullptr,
        func_08076E0C,
        func_08076AE0,
#else
        nullptr,
        func_080E2E34,
        __pure_virtual,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7B88[]
    SECTION(".rodata.vtable_7b88") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E260C,
        nullptr,
#else
        func_08076E0C,
        func_08076EA8,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7B98[]
    SECTION(".rodata.vtable_7b98") = {
#if defined(REGION_JP)
        nullptr,
        func_080777F4,
        func_08077834,
#else
        nullptr,
        nullptr,
        func_080E2E6C,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7BA4[]
    SECTION(".rodata.vtable_7ba4") = {
        nullptr,
#if defined(REGION_JP)
        nullptr,
        func_080E2A88,
        nullptr,
#else
        nullptr,
        func_08077C6C,
        func_08077CAC,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7BB4[]
    SECTION(".rodata.vtable_7bb4") = {
#if defined(REGION_JP)
        nullptr,
        func_08078670,
        func_080786A0,
#else
        nullptr,
        nullptr,
        func_080E32E8,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7BC0[]
    SECTION(".rodata.vtable_7bc0") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_080E2B70,
        nullptr,
#else
        nullptr,
        nullptr,
        func_08078AE8,
        func_08078B18,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7BD0[]
    SECTION(".rodata.vtable_7bd0") = {
#if defined(REGION_JP)
        nullptr,
        func_0807AC20,
        func_0807AC60,
#else
        nullptr,
        nullptr,
        func_080E33D0,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7BDC[]
    SECTION(".rodata.vtable_7bdc") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_0807AD18,
        nullptr,
#else
        nullptr,
        nullptr,
        func_0807B07C,
        func_0807B0BC,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7BEC[]
    SECTION(".rodata.vtable_7bec") = {
#if defined(REGION_JP)
        nullptr,
        func_0807CC1C,
        func_0807CC5C,
#else
        nullptr,
        nullptr,
        func_0807B174,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7BF8[]
    SECTION(".rodata.vtable_7bf8") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_0807D960,
        nullptr,
#else
        nullptr,
        nullptr,
        func_0807D0B4,
        func_0807D0F4,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7C08[]
    SECTION(".rodata.vtable_7c08") = {
#if defined(REGION_JP)
        nullptr,
        func_0807CD30,
        nullptr,
#else
        nullptr,
        nullptr,
        func_0807DDF8,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7C14[]
    SECTION(".rodata.vtable_7c14") = {
#if defined(REGION_JP)
        nullptr,
        func_0807DFE0,
        func_0807E020,
#else
        nullptr,
        nullptr,
        func_0807D1C8,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7C20[]
    SECTION(".rodata.vtable_7c20") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_0807D8D0,
        func_0807D910,
#else
        nullptr,
        nullptr,
        func_0807E478,
        func_0807E4B8,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7C30[]
    SECTION(".rodata.vtable_7c30") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_0807E070,
        nullptr,
#else
        nullptr,
        nullptr,
        func_0807DD68,
        func_0807DDA8,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7C40[]
    SECTION(".rodata.vtable_7c40") = {
#if defined(REGION_JP)
        nullptr,
        func_0807E9AC,
        func_0807E9EC,
#else
        nullptr,
        nullptr,
        func_0807E508,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7C4C[]
    SECTION(".rodata.vtable_7c4c") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_0807EA3C,
        nullptr,
#else
        nullptr,
        nullptr,
        func_0807EE44,
        func_0807EE84,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7C5C[]
    SECTION(".rodata.vtable_7c5c") = {
#if defined(REGION_JP)
        nullptr,
        func_0807F118,
        func_0807F158,
#else
        nullptr,
        nullptr,
        func_0807EED4,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7C68[]
    SECTION(".rodata.vtable_7c68") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_0807F1D8,
        nullptr,
#else
        nullptr,
        nullptr,
        func_0807F5B0,
        func_0807F5F0,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7C78[]
    SECTION(".rodata.vtable_7c78") = {
#if defined(REGION_JP)
        nullptr,
        func_0807FFF4,
        func_08080034,
#else
        nullptr,
        nullptr,
        func_0807F670,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7C84[]
    SECTION(".rodata.vtable_7c84") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_08080094,
        nullptr,
#else
        nullptr,
        nullptr,
        func_0808048C,
        func_080804CC,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7C94[]
    SECTION(".rodata.vtable_7c94") = {
#if defined(REGION_JP)
        nullptr,
        func_0808093C,
        func_0808097C,
#else
        nullptr,
        nullptr,
        func_0808052C,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7CA0[]
    SECTION(".rodata.vtable_7ca0") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_080809CC,
        nullptr,
#else
        nullptr,
        nullptr,
        func_08080DC4,
        func_08080E04,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7CB0[]
    SECTION(".rodata.vtable_7cb0") = {
#if defined(REGION_JP)
        nullptr,
        func_080815E8,
        func_08081628,
#else
        nullptr,
        nullptr,
        func_08080E54,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7CBC[]
    SECTION(".rodata.vtable_7cbc") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_08081678,
        nullptr,
#else
        nullptr,
        nullptr,
        func_08081A70,
        func_08081AB0,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7CCC[]
    SECTION(".rodata.vtable_7ccc") = {
#if defined(REGION_JP)
        nullptr,
        func_08081CBC,
        func_08081CFC,
#else
        nullptr,
        nullptr,
        func_08081B00,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7CD8[]
    SECTION(".rodata.vtable_7cd8") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_08081DC8,
        nullptr,
#else
        nullptr,
        nullptr,
        func_08082144,
        func_08082184,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7CE8[]
    SECTION(".rodata.vtable_7ce8") = {
#if defined(REGION_JP)
        nullptr,
        func_080E2C7C,
        func_080E2C34,
#else
        nullptr,
        nullptr,
        func_08082250,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7CF4[]
    SECTION(".rodata.vtable_7cf4") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_08083664,
        func_080836A4,
#else
        nullptr,
        nullptr,
        func_080E34DC,
        func_080E3494,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7D04[]
    SECTION(".rodata.vtable_7d04") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_080837C8,
        nullptr,
#else
        nullptr,
        nullptr,
        func_08083AEC,
        func_08083B2C,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7D14[]
    SECTION(".rodata.vtable_7d14") = {
#if defined(REGION_JP)
        nullptr,
        func_080850A0,
        func_080850E0,
#else
        nullptr,
        nullptr,
        func_08083C50,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7D20[]
    SECTION(".rodata.vtable_7d20") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_080851A4,
        nullptr,
#else
        nullptr,
        nullptr,
        func_08085528,
        func_08085568,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7D30[]
    SECTION(".rodata.vtable_7d30") = {
#if defined(REGION_JP)
        nullptr,
        func_08087CEC,
        func_08087D2C,
#else
        nullptr,
        nullptr,
        func_0808562C,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7D3C[]
    SECTION(".rodata.vtable_7d3c") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_08087E44,
        nullptr,
#else
        nullptr,
        nullptr,
        func_080881AC,
        func_080881EC,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7D4C[]
    SECTION(".rodata.vtable_7d4c") = {
#if defined(REGION_JP)
        nullptr,
        func_0808A6A8,
        func_0808A6E8,
#else
        nullptr,
        nullptr,
        func_08088304,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7D58[]
    SECTION(".rodata.vtable_7d58") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_0808A754,
        nullptr,
#else
        nullptr,
        nullptr,
        func_0808AB68,
        func_0808ABA8,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7D68[]
    SECTION(".rodata.vtable_7d68") = {
#if defined(REGION_JP)
        nullptr,
        func_0808C0DC,
        func_0808C5DC,
#else
        nullptr,
        nullptr,
        func_0808AC14,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7D74[]
    SECTION(".rodata.vtable_7d74") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_0808C190,
        nullptr,
#else
        nullptr,
        nullptr,
        func_0808C59C,
        func_0808C5DC,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7D84[]
    SECTION(".rodata.vtable_7d84") = {
#if defined(REGION_JP)
        nullptr,
        func_0808E848,
        func_0808E888,
#else
        nullptr,
        nullptr,
        func_0808C650,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7D90[]
    SECTION(".rodata.vtable_7d90") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_0808E8F8,
        nullptr,
#else
        nullptr,
        nullptr,
        func_0808ED08,
        func_0808ED48,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7DA0[]
    SECTION(".rodata.vtable_7da0") = {
#if defined(REGION_JP)
        nullptr,
        func_080909C4,
        func_08090EC4,
#else
        nullptr,
        nullptr,
        func_0808EDB8,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7DAC[]
    SECTION(".rodata.vtable_7dac") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_08090F58,
        nullptr,
#else
        nullptr,
        nullptr,
        func_08090E84,
        func_08090EC4,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7DBC[]
    SECTION(".rodata.vtable_7dbc") = {
#if defined(REGION_JP)
        nullptr,
        func_08092090,
        func_08092604,
#else
        nullptr,
        nullptr,
        func_08090F58,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7DC8[]
    SECTION(".rodata.vtable_7dc8") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_0809215C,
        nullptr,
#else
        nullptr,
        nullptr,
        func_080925C4,
        func_08092604,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7DD8[]
    SECTION(".rodata.vtable_7dd8") = {
#if defined(REGION_JP)
        nullptr,
        func_08092CAC,
        func_08093220,
#else
        nullptr,
        nullptr,
        func_08092690,
#endif
    };

extern RawVTableWithOffsetThreeEntries const vtable_unk_080E7DE4
    SECTION(".rodata.vtable_7de4") = {
#if defined(REGION_JP)
        -8,
        {
            nullptr,
            func_08093D4C,
            func_08093D80,
        },
#else
        0,
        {
            nullptr,
            func_080931E0,
            func_08093220,
        },
#endif
    };

#if defined(REGION_JP)
extern RawVTableFunction const vtable_unk_080E7DF4[]
    SECTION(".rodata.vtable_7df4") = {
        func_08093E4C,
        func_08093E80,
        func_08093E84,
        func_08094210,
        func_080E3224,
        func_080E30C4,
        func_080E30B8,
        func_080E30AC,
        func_080E3218,
        func_080E3204,
        func_080E31F4,
        func_080E31DC,
        func_080E3184,
        func_080E312C,
        func_080E30D0,
        func_080E31E8,
        func_080E30A8,
        func_080E3078,
        func_080E3048,
        func_080E300C,
        func_080E2D7C,
        func_08093E88,
        func_08093EA8,
        func_080E2D88,
        func_080E2DB0,
        func_08094204,
        func_08093F10,
        func_08093F30,
        func_080E2DC8,
        func_080941FC,
        func_080941F8,
        func_08093F6C,
        func_08093FAC,
        func_080E2DF0,
        func_080941F0,
        func_080941EC,
        func_08094020,
        func_08094024,
        func_080E2E18,
        func_080E2E54,
        func_080E2ED0,
        func_08094048,
        func_08094074,
        func_080E2ED4,
        func_080E2EFC,
        func_080941D4,
        func_0809410C,
        func_0809412C,
        func_080E2F14,
        func_080941CC,
        func_080E2F38,
        func_0809416C,
        func_08094180,
        func_080941C4,
        func_080941C0,
        func_080941BC,
        func_08094184,
        func_08094188,
        func_080E2F3C,
        func_080E2F74_vtable_target,
        func_080E2FF0,
        func_080E2FF4,
        func_080E3000,
        nullptr,
        nullptr,
        func_08092DD4,
        nullptr,
    };
#else
extern RawVTableWithOffsetAnd66Entries const vtable_unk_080E7DF4
    SECTION(".rodata.vtable_7df4") = {
        -8,
        {
            nullptr,
            func_08094288,
            func_080942BC,
            func_08094388,
            func_080943BC,
            func_080943C0,
            func_0809474C,
            func_080E3A8C,
            func_080E392C,
            func_080E3920,
            func_080E3914,
            func_080E3A80,
            func_080E3A6C,
            func_080E3A5C,
            func_080E3A44,
            func_080E39EC,
            func_080E3994,
            func_080E3938,
            func_080E3A50,
            func_080E3910,
            func_080E38E0,
            func_080E38B0,
            func_080E3874,
            func_080E35DC,
            func_080943C4,
            func_080943E4,
            func_080E35E8,
            func_080E3610,
            func_08094740,
            func_0809444C,
            func_0809446C,
            func_080E3628,
            func_08094738,
            func_08094734,
            func_080944A8,
            func_080944E8,
            func_080E3650,
            func_0809472C,
            func_08094728,
            func_0809455C,
            func_08094560,
            func_080E3678,
            func_080E36B4,
            func_080E3730,
            func_08094584,
            func_080945B0,
            func_080E3734,
            func_080E375C,
            func_08094710,
            func_08094648,
            func_08094668,
            func_080E3774,
            func_08094708,
            func_080E3798,
            func_080946A8,
            func_080946BC,
            func_08094700,
            func_080946FC,
            func_080946F8,
            func_080946C0,
            func_080946C4,
            func_080E379C,
            func_080E37DC,
            func_080E3858,
            func_080E385C,
            func_080E3868,
        },
    };
#endif

extern RawVTableFunction const vtable_unk_080E7F00[]
    SECTION(".rodata.vtable_7f00") = {
#if defined(REGION_JP)
        nullptr,
        func_08093D4C,
        func_08093D80,
#else
        nullptr,
        nullptr,
        func_08093308,
#endif
    };

extern RawVTableFunction const vtable_unk_080E7F0C[]
    SECTION(".rodata.vtable_7f0c") = {
#if defined(REGION_JP)
        func_08093E4C,
        func_08093E80,
        func_08093E84,
        func_08094210,
        func_080E3224,
        func_080E30C4,
        func_080E30B8,
        func_080E30AC,
        func_080E3218,
        func_080E3204,
        func_080E31F4,
        func_080E31DC,
        func_080E3184,
        func_080E312C,
        func_080E30D0,
        func_080E31E8,
        func_080E30A8,
        func_080E3078,
        func_080E3048,
        func_080E300C,
        func_080E32F8,
        func_08093E88,
        func_08093EA8,
        func_0809420C,
        func_08094208,
        func_08094204,
        func_08093F10,
        func_08093F30,
        func_08094200,
        func_080941FC,
        func_080941F8,
        func_08093F6C,
        func_08093FAC,
        func_080941F4,
        func_080941F0,
        func_080941EC,
        func_08094020,
        func_08094024,
        func_080941E8,
        func_080941E4,
        func_080941E0,
        func_08094048,
        func_08094074,
        func_080941DC,
        func_080941D8,
        func_080941D4,
        func_0809410C,
        func_0809412C,
        func_080941D0,
        func_080941CC,
        func_080941C8,
        func_0809416C,
        func_08094180,
        func_080941C4,
        func_080941C0,
        func_080941BC,
        func_08094184,
        func_08094188,
        func_080941B8,
        func_080941B4,
        func_080941B0,
        __pure_virtual,
        __pure_virtual,
        nullptr,
        nullptr,
        func_08093554,
        func_080935A0,
#else
        nullptr,
        nullptr,
        func_08094288,
        func_080942BC,
        func_08094388,
        func_080943BC,
        func_080943C0,
        func_0809474C,
        func_080E3A8C,
        func_080E392C,
        func_080E3920,
        func_080E3914,
        func_080E3A80,
        func_080E3A6C,
        func_080E3A5C,
        func_080E3A44,
        func_080E39EC,
        func_080E3994,
        func_080E3938,
        func_080E3A50,
        func_080E3910,
        func_080E38E0,
        func_080E38B0,
        func_080E3874,
        func_080E3B60,
        func_080943C4,
        func_080943E4,
        func_08094748,
        func_08094744,
        func_08094740,
        func_0809444C,
        func_0809446C,
        func_0809473C,
        func_08094738,
        func_08094734,
        func_080944A8,
        func_080944E8,
        func_08094730,
        func_0809472C,
        func_08094728,
        func_0809455C,
        func_08094560,
        func_08094724,
        func_08094720,
        func_0809471C,
        func_08094584,
        func_080945B0,
        func_08094718,
        func_08094714,
        func_08094710,
        func_08094648,
        func_08094668,
        func_0809470C,
        func_08094708,
        func_08094704,
        func_080946A8,
        func_080946BC,
        func_08094700,
        func_080946FC,
        func_080946F8,
        func_080946C0,
        func_080946C4,
        func_080946F4,
        func_080946F0,
        func_080946EC,
        __pure_virtual,
        __pure_virtual,
#endif
    };

extern RawVTableFunction const vtable_unk_080E8018[]
    SECTION(".rodata.vtable_8018") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_08093D4C,
        func_08093D80,
#else
        func_08093A88,
        func_08093AD4,
#endif
    };

extern RawVTableFunction const vtable_unk_080E8028[]
    SECTION(".rodata.vtable_8028") = {
#if defined(REGION_JP)
        func_08093E4C,
        func_08093E80,
        func_08093E84,
        func_08094210,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        func_08093D2C,
        func_08093E88,
        func_08093EA8,
        func_0809420C,
        func_08094208,
        func_08094204,
        func_08093F10,
        func_08093F30,
        func_08094200,
        func_080941FC,
        func_080941F8,
        func_08093F6C,
        func_08093FAC,
        func_080941F4,
        func_080941F0,
        func_080941EC,
        func_08094020,
        func_08094024,
        func_080941E8,
        func_080941E4,
        func_080941E0,
        func_08094048,
        func_08094074,
        func_080941DC,
        func_080941D8,
        func_080941D4,
        func_0809410C,
        func_0809412C,
        func_080941D0,
        func_080941CC,
        func_080941C8,
        func_0809416C,
        func_08094180,
        func_080941C4,
        func_080941C0,
        func_080941BC,
        func_08094184,
        func_08094188,
        func_080941B8,
        func_080941B4,
        func_080941B0,
        nullptr,
        nullptr,
        func_080938B0,
        func_080938E4,
#else
        nullptr,
        nullptr,
        func_08094288,
        func_080942BC,
        func_08094388,
        func_080943BC,
        func_080943C0,
        func_0809474C,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        func_08094268,
        func_080943C4,
        func_080943E4,
        func_08094748,
        func_08094744,
        func_08094740,
        func_0809444C,
        func_0809446C,
        func_0809473C,
        func_08094738,
        func_08094734,
        func_080944A8,
        func_080944E8,
        func_08094730,
        func_0809472C,
        func_08094728,
        func_0809455C,
        func_08094560,
        func_08094724,
        func_08094720,
        func_0809471C,
        func_08094584,
        func_080945B0,
        func_08094718,
        func_08094714,
        func_08094710,
        func_08094648,
        func_08094668,
        func_0809470C,
        func_08094708,
        func_08094704,
        func_080946A8,
        func_080946BC,
        func_08094700,
        func_080946FC,
        func_080946F8,
        func_080946C0,
        func_080946C4,
        func_080946F4,
        func_080946F0,
        func_080946EC,
#endif
    };

extern RawVTableFunction const vtable_unk_080E812C[]
    SECTION(".rodata.vtable_812c") = {
#if defined(REGION_JP)
        func_080939B0,
        func_080939E4,
        func_080939E8,
        func_08094278,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        func_08093890,
        func_080939EC,
        func_08093A0C,
        func_08094274,
        func_08094270,
        func_0809426C,
        func_08093A74,
        func_08093A88,
        func_08094268,
        func_08094264,
        func_08094260,
        func_08093AC4,
        func_08093B0C,
        func_0809425C,
        func_08094258,
        func_08094254,
        func_08093B80,
        func_08093B84,
        func_08094250,
        func_0809424C,
        func_08094248,
        func_08093BA8,
        func_08093BD4,
        func_08094244,
        func_08094240,
        func_0809423C,
        func_08093C6C,
        func_08093C8C,
        func_08094238,
        func_08094234,
        func_08094230,
        func_08093CCC,
        func_08093CE0,
        func_0809422C,
        func_08094228,
        func_08094224,
        func_08093CE4,
        func_08093CE8,
        func_08094220,
        func_0809421C,
        func_08094218,
        nullptr,
        nullptr,
        func_080E33D4,
        nullptr,
#else
        nullptr,
        nullptr,
        func_08093DEC,
        func_08093E20,
        func_08093EEC,
        func_08093F20,
        func_08093F24,
        func_080947B4,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        func_08093DCC,
        func_08093F28,
        func_08093F48,
        func_080947B0,
        func_080947AC,
        func_080947A8,
        func_08093FB0,
        func_08093FC4,
        func_080947A4,
        func_080947A0,
        func_0809479C,
        func_08094000,
        func_08094048,
        func_08094798,
        func_08094794,
        func_08094790,
        func_080940BC,
        func_080940C0,
        func_0809478C,
        func_08094788,
        func_08094784,
        func_080940E4,
        func_08094110,
        func_08094780,
        func_0809477C,
        func_08094778,
        func_080941A8,
        func_080941C8,
        func_08094774,
        func_08094770,
        func_0809476C,
        func_08094208,
        func_0809421C,
        func_08094768,
        func_08094764,
        func_08094760,
        func_08094220,
        func_08094224,
        func_0809475C,
        func_08094758,
        func_08094754,
#endif
    };

extern RawVTableFunction const vtable_unk_080E8230[]
    SECTION(".rodata.vtable_8230") = {
#if defined(REGION_JP)
        nullptr,
        func_080E352C,
        func_080E3318,
#else
        nullptr,
        nullptr,
        func_080E3C3C,
#endif
    };

extern RawVTableFunction const vtable_unk_080E823C[]
    SECTION(".rodata.vtable_823c") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_08099F50,
        func_08099F90,
#else
        func_080E3D94,
        func_080E3B80,
#endif
    };

extern RawVTableFunction const vtable_unk_080E824C[]
    SECTION(".rodata.vtable_824c") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E3838,
        nullptr,
#else
        func_0809A518,
        func_0809A558,
#endif
    };

extern RawVTableFunction const vtable_unk_080E825C[]
    SECTION(".rodata.vtable_825c") = {
        nullptr,
#if defined(REGION_JP)
        func_080E3928,
        func_080E36D8,
#else
        nullptr,
        func_080E40A0,
#endif
    };

extern RawVTableFunction const vtable_unk_080E8268[]
    SECTION(".rodata.vtable_8268") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E3948,
        func_080A31AC,
#else
        func_080E4190,
        func_080E3F40,
#endif
    };

extern RawVTableFunction const vtable_unk_080E8278[]
    SECTION(".rodata.vtable_8278") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080A362C,
        func_080A3530,
#else
        func_080E41B0,
        func_080A3774,
#endif
    };

extern RawVTableFunction const vtable_unk_080E8288[]
    SECTION(".rodata.vtable_8288") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080A3678,
        func_080A3434,
#else
        func_080A3BF4,
        func_080A3AF8,
#endif
    };

extern RawVTableFunction const vtable_unk_080E8298[]
    SECTION(".rodata.vtable_8298") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080A36C4,
        func_080A3338,
#else
        func_080A3C40,
        func_080A39FC,
#endif
    };

extern RawVTableFunction const vtable_unk_080E82A8[]
    SECTION(".rodata.vtable_82a8") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E3980,
        func_080A31E0,
#else
        func_080A3C8C,
        func_080A3900,
#endif
    };

// The ROM places two four-word callback groups consecutively here. Keep the
// groups in one array so their physical order and the JP null final slot stay
// explicit without inferring an unverified class layout.
extern RawVTableFunction const vtable_unk_080E82B8[]
    SECTION(".rodata.vtable_82b8") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E39A8,
        func_080A372C,
        nullptr,
        nullptr,
        func_080A41EC,
        nullptr,
#else
        func_080E41E8,
        func_080A37A8,
        nullptr,
        nullptr,
        func_080E4210,
        func_080A3CF4,
#endif
    };

extern RawVTableFunction const vtable_unk_080E82D8[]
    SECTION(".rodata.vtable_82d8") = {
#if defined(REGION_JP)
        nullptr,
        func_080A45A4,
        func_080A4624,
#else
        nullptr,
        nullptr,
        func_080A47B4,
#endif
    };

extern RawVTableFunction const vtable_unk_080E82E4[]
    SECTION(".rodata.vtable_82e4") = {
#if defined(REGION_JP)
        func_080A4988,
        func_080A5198,
        func_080A5E58,
        func_080A58D8,
        func_080A56F8,
        func_080A57F0,
        nullptr,
        nullptr,
        func_080A50A8,
        func_080E39D0,
#else
        nullptr,
        nullptr,
        func_080A4B6C,
        func_080A4BEC,
        func_080A4F50,
        func_080A5760,
        func_080A6420,
        func_080A5EA0,
        func_080A5CC0,
        func_080A5DB8,
#endif
    };

extern RawVTableFunction const vtable_unk_080E830C[]
    SECTION(".rodata.vtable_830c") = {
        nullptr,
        nullptr,
#if defined(REGION_JP)
        func_080E3B50,
        func_080A5EF0,
#else
        func_080A5670,
        func_080E4238,
#endif
    };

extern RawVTableFunction const vtable_unk_080E831C[]
    SECTION(".rodata.vtable_831c") = {
#if defined(REGION_JP)
        func_080A5F5C,
        func_080A6078,
        func_080AA974,
        func_080A6EC4,
        func_080A6098,
        func_080A8FDC,
        nullptr,
        nullptr,
        func_080E3C50,
        func_080AC528,
#else
        nullptr,
        nullptr,
        func_080E43B8,
        func_080A64B8,
        func_080A6524,
        func_080A6640,
        func_080AAF3C,
        func_080A748C,
        func_080A6660,
        func_080A95A4,
#endif
    };

#if defined(REGION_JP)
extern void func_080AC648(void);
extern void func_080AD5CC(void);
extern void func_080AD5C4(void);
extern void func_080AD5BC(void);
extern void func_080AD5E0(void);
extern void func_080AD5D4(void);
extern void func_080AD5B0(void);
extern void func_080AD4E0(void);
extern void func_080AD4BC(void);
extern void func_080AD0D4(void);
extern void func_080ACED4(void);
extern void func_080AD58C(void);
extern void func_080AD580(void);
extern void func_080AD574(void);
extern void func_080AD010(void);
extern void func_080AD55C(void);
extern void func_080AD534(void);
extern void func_080AD504(void);
extern void func_080AD4B0(void);
extern void func_080AD48C(void);
extern void func_080AD480(void);
extern void func_080AD498(void);
extern void func_080AD4A4(void);
extern void func_080AD474(void);
extern void func_080AD444(void);
extern void func_080AD438(void);
extern void func_080AD42C(void);
extern void func_080AD420(void);
extern void func_080AD408(void);
extern void func_080AD3FC(void);
extern void func_080AD3F0(void);
extern void func_080AD3E4(void);
extern void func_080AD3D8(void);
extern void func_080AD3CC(void);
extern void func_080AD3C0(void);
extern void func_080AD3B4(void);
extern void func_080AD3A8(void);
extern void func_080AD398(void);
extern void func_080AD388(void);
extern void func_080AD37C(void);
extern void func_080ACDE8(void);
extern void func_080AD370(void);
extern void func_080AD2FC(void);
extern void func_080AD1B4(void);
extern void func_080E3CA8(void);
extern void func_0803240C(void);
#else
extern void func_080E44B8(void);
extern void func_080ACAF0(void);
extern void func_080ACC10(void);
extern void func_080ADB94(void);
extern void func_080ADB8C(void);
extern void func_080ADB84(void);
extern void func_080ADBA8(void);
extern void func_080ADB9C(void);
extern void func_080ADB78(void);
extern void func_080ADAA8(void);
extern void func_080ADA84(void);
extern void func_080AD69C(void);
extern void func_080AD49C(void);
extern void func_080ADB54(void);
extern void func_080ADB48(void);
extern void func_080ADB3C(void);
extern void func_080AD5D8(void);
extern void func_080ADB24(void);
extern void func_080ADAFC(void);
extern void func_080ADACC(void);
extern void func_080ADA78(void);
extern void func_080ADA54(void);
extern void func_080ADA48(void);
extern void func_080ADA60(void);
extern void func_080ADA6C(void);
extern void func_080ADA3C(void);
extern void func_080ADA0C(void);
extern void func_080ADA00(void);
extern void func_080AD9F4(void);
extern void func_080AD9E8(void);
extern void func_080AD9D0(void);
extern void func_080AD9C4(void);
extern void func_080AD9B8(void);
extern void func_080AD9AC(void);
extern void func_080AD9A0(void);
extern void func_080AD994(void);
extern void func_080AD988(void);
extern void func_080AD97C(void);
extern void func_080AD970(void);
extern void func_080AD960(void);
extern void func_080AD950(void);
extern void func_080AD944(void);
extern void func_080AD3B0(void);
extern void func_080AD938(void);
extern void func_080AD8C4(void);
extern void func_080AD77C(void);
#endif

// This is a single 48-slot ROM table. Its class layout remains unverified, so
// retain every callback and null slot in physical order rather than inventing
// a higher-level C++ representation.
extern RawVTableFunction const vtable_unk_080E8344[]
    SECTION(".rodata.vtable_8344") = {
#if defined(REGION_JP)
        func_080AC648,
        func_080AD5CC,
        func_080AD5C4,
        func_080AD5BC,
        func_080AD5E0,
        func_080AD5D4,
        func_080AD5B0,
        func_080AD4E0,
        func_080AD4BC,
        func_080AD0D4,
        func_080ACED4,
        func_080AD58C,
        func_080AD580,
        func_080AD574,
        func_080AD010,
        func_080AD55C,
        func_080AD534,
        func_080AD504,
        func_080AD4B0,
        func_080AD48C,
        func_080AD480,
        func_080AD498,
        func_080AD4A4,
        func_080AD474,
        func_080AD444,
        func_080AD438,
        func_080AD42C,
        func_080AD420,
        func_080AD408,
        func_080AD3FC,
        func_080AD3F0,
        func_080AD3E4,
        func_080AD3D8,
        func_080AD3CC,
        func_080AD3C0,
        func_080AD3B4,
        func_080AD3A8,
        func_080AD398,
        func_080AD388,
        func_080AD37C,
        func_080ACDE8,
        func_080AD370,
        func_080AD2FC,
        func_080AD1B4,
        nullptr,
        nullptr,
        func_080E3CA8,
        func_0803240C,
#else
        nullptr,
        nullptr,
        func_080E44B8,
        func_080ACAF0,
        func_080ACC10,
        func_080ADB94,
        func_080ADB8C,
        func_080ADB84,
        func_080ADBA8,
        func_080ADB9C,
        func_080ADB78,
        func_080ADAA8,
        func_080ADA84,
        func_080AD69C,
        func_080AD49C,
        func_080ADB54,
        func_080ADB48,
        func_080ADB3C,
        func_080AD5D8,
        func_080ADB24,
        func_080ADAFC,
        func_080ADACC,
        func_080ADA78,
        func_080ADA54,
        func_080ADA48,
        func_080ADA60,
        func_080ADA6C,
        func_080ADA3C,
        func_080ADA0C,
        func_080ADA00,
        func_080AD9F4,
        func_080AD9E8,
        func_080AD9D0,
        func_080AD9C4,
        func_080AD9B8,
        func_080AD9AC,
        func_080AD9A0,
        func_080AD994,
        func_080AD988,
        func_080AD97C,
        func_080AD970,
        func_080AD960,
        func_080AD950,
        func_080AD944,
        func_080AD3B0,
        func_080AD938,
        func_080AD8C4,
        func_080AD77C,
#endif
    };

#if defined(REGION_JP)
extern void vfunc_10__7AEntity(void);
extern void vfunc_14__7AEntity(void);
extern void func_08032A30(void);
extern void vfunc_1C__7AEntityUi(void);
extern void vfunc_20__7AEntity(void);
extern void vfunc_24__7AEntity(void);
extern void vfunc_28__C7AEntity(void);
extern void func_0803242C(void);
extern void func_080E3C7C(void);
extern void func_080324B8(void);
extern void func_080328D4(void);
extern void func_080E3CDC(void);
#else
extern void func_080E4510(void);
extern void func_0803240C(void);
extern void vfunc_10__7AEntity(void);
extern void vfunc_14__7AEntity(void);
extern void func_08032A30(void);
extern void vfunc_1C__7AEntityUi(void);
extern void vfunc_20__7AEntity(void);
extern void vfunc_24__7AEntity(void);
extern void vfunc_28__C7AEntity(void);
extern void func_0803242C(void);
extern void func_080E44E4(void);
extern void func_080324B8(void);
extern void func_08032B40(void);
#endif

// This short table has a region-dependent slot layout. Retain the opaque
// callback sequence and null slots in ROM order until its class is identified.
extern RawVTableFunction const vtable_unk_080E8404[]
    SECTION(".rodata.vtable_8404") = {
#if defined(REGION_JP)
        vfunc_10__7AEntity,
        vfunc_14__7AEntity,
        func_08032A30,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_080E3C7C,
        func_080324B8,
        func_080328D4,
        nullptr,
        nullptr,
        func_080E3CDC,
        __pure_virtual,
#else
        nullptr,
        nullptr,
        func_080E4510,
        func_0803240C,
        vfunc_10__7AEntity,
        vfunc_14__7AEntity,
        func_08032A30,
        vfunc_1C__7AEntityUi,
        vfunc_20__7AEntity,
        vfunc_24__7AEntity,
        vfunc_28__C7AEntity,
        func_0803242C,
        func_080E44E4,
        func_080324B8,
        func_08032B40,
#endif
    };

#if defined(REGION_JP)
extern void func_080E4564(void);
#else
extern void func_080E4544(void);
#endif

// Keep this abstract table as a flat 48-slot callback sequence. The virtual
// slots differ between regions, so no unverified class layout is inferred.
extern RawVTableFunction const vtable_unk_080E8440[]
    SECTION(".rodata.vtable_8440") = {
#if defined(REGION_JP)
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        nullptr,
        nullptr,
        func_080E4564,
        nullptr,
#else
        nullptr,
        nullptr,
        func_080E4544,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
        __pure_virtual,
#endif
    };

#if defined(REGION_JP)
extern void func_080B3640(void);
extern void func_080B3C3C(void);
#else
extern void func_080E4564(void);
#endif

// Preserve this three-slot region-dependent table without assigning semantics
// to the entries before the corresponding class implementation is recovered.
extern RawVTableFunction const vtable_unk_080E8500[]
    SECTION(".rodata.vtable_8500") = {
#if defined(REGION_JP)
        nullptr,
        func_080B3640,
        func_080B3C3C,
#else
        nullptr,
        nullptr,
        func_080E4564,
#endif
    };

#if defined(REGION_JP)
extern void func_080E4940(void);
#else
extern void func_080B3C0C(void);
extern void func_080B3C3C(void);
#endif

// Retain every slot of this four-entry region-dependent callback table in the
// original ROM order until the owning type has been recovered.
extern RawVTableFunction const vtable_unk_080E850C[]
    SECTION(".rodata.vtable_850c") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_080E4940,
        nullptr,
#else
        nullptr,
        nullptr,
        func_080B3C0C,
        func_080B3C3C,
#endif
    };

#if defined(REGION_JP)
extern void func_080BC2F4(void);
extern void func_080BC8FC(void);
#else
extern void func_080E4940(void);
#endif

// Keep the exact three-slot region-dependent callback sequence. Its concrete
// class is not yet known, so the source intentionally does not infer one.
extern RawVTableFunction const vtable_unk_080E851C[]
    SECTION(".rodata.vtable_851c") = {
#if defined(REGION_JP)
        nullptr,
        func_080BC2F4,
        func_080BC8FC,
#else
        nullptr,
        nullptr,
        func_080E4940,
#endif
    };

#if defined(REGION_JP)
extern void func_080E4D50(void);
#else
extern void func_080BC8C0(void);
extern void func_080BC8FC(void);
#endif

// Keep this four-slot table in physical order; only the function targets vary
// between the JP and US revisions.
extern RawVTableFunction const vtable_unk_080E8528[]
    SECTION(".rodata.vtable_8528") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_080E4D50,
        nullptr,
#else
        nullptr,
        nullptr,
        func_080BC8C0,
        func_080BC8FC,
#endif
    };

#if defined(REGION_JP)
extern void func_080C0770(void);
extern void func_080C0D90(void);
#else
extern void func_080E4D50(void);
#endif

// Keep the three original slots and region-specific target sequence intact.
extern RawVTableFunction const vtable_unk_080E8538[]
    SECTION(".rodata.vtable_8538") = {
#if defined(REGION_JP)
        nullptr,
        func_080C0770,
        func_080C0D90,
#else
        nullptr,
        nullptr,
        func_080E4D50,
#endif
    };

#if defined(REGION_JP)
extern void func_080E4FF0(void);
#else
extern void func_080C0D44(void);
extern void func_080C0D90(void);
#endif

// Preserve all four slots of this region-dependent table in ROM order.
extern RawVTableFunction const vtable_unk_080E8544[]
    SECTION(".rodata.vtable_8544") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_080E4FF0,
        nullptr,
#else
        nullptr,
        nullptr,
        func_080C0D44,
        func_080C0D90,
#endif
    };

#if defined(REGION_JP)
extern void func_080C78F4(void);
extern void func_080C7F1C(void);
#else
extern void func_080E4FF0(void);
#endif

// Preserve the original three-pointer layout instead of assigning an
// unverified class name to this regional callback table.
extern RawVTableFunction const vtable_unk_080E8554[]
    SECTION(".rodata.vtable_8554") = {
#if defined(REGION_JP)
        nullptr,
        func_080C78F4,
        func_080C7F1C,
#else
        nullptr,
        nullptr,
        func_080E4FF0,
#endif
    };

#if defined(REGION_JP)
extern void func_080C8360(void);
#else
extern void func_080C7ED0(void);
extern void func_080C7F1C(void);
#endif

// Keep this four-slot callback table in source order matching its ROM layout.
extern RawVTableFunction const vtable_unk_080E8560[]
    SECTION(".rodata.vtable_8560") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_080C8360,
        nullptr,
#else
        nullptr,
        nullptr,
        func_080C7ED0,
        func_080C7F1C,
#endif
    };

#if defined(REGION_JP)
extern void func_080E4C10(void);
#else
extern void func_080C8360(void);
#endif

// Preserve the original three-slot table, including the JP-only middle entry.
extern RawVTableFunction const vtable_unk_080E8570[]
    SECTION(".rodata.vtable_8570") = {
#if defined(REGION_JP)
        nullptr,
        func_080E4C10,
        nullptr,
#else
        nullptr,
        nullptr,
        func_080C8360,
#endif
    };

#if defined(REGION_JP)
extern void func_080E4C84(void);
#else
extern void func_080E5478(void);
#endif

// Preserve the region-specific placement of the only non-null callback.
extern RawVTableFunction const vtable_unk_080E857C[]
    SECTION(".rodata.vtable_857c") = {
#if defined(REGION_JP)
        nullptr,
        func_080E4C84,
        nullptr,
#else
        nullptr,
        nullptr,
        func_080E5478,
#endif
    };

#if defined(REGION_JP)
extern void func_080E4C5C(void);
#else
extern void func_080E5844(void);
#endif

// Preserve the original regional placement of this table's single callback.
extern RawVTableFunction const vtable_unk_080E8588[]
    SECTION(".rodata.vtable_8588") = {
#if defined(REGION_JP)
        nullptr,
        func_080E4C5C,
        nullptr,
#else
        nullptr,
        nullptr,
        func_080E5844,
#endif
    };

#if defined(REGION_JP)
extern void func_080E4DAC(void);
#else
extern void func_080E581C(void);
#endif

// Keep the region-specific slot position of this table's sole callback.
extern RawVTableFunction const vtable_unk_080E8594[]
    SECTION(".rodata.vtable_8594") = {
#if defined(REGION_JP)
        nullptr,
        func_080E4DAC,
        nullptr,
#else
        nullptr,
        nullptr,
        func_080E581C,
#endif
    };

#if defined(REGION_JP)
extern void func_080E5898(void);
extern void func_080CAF6C(void);
#else
extern void func_080E596C(void);
#endif

// Preserve the original three slots and their region-specific callbacks.
extern RawVTableFunction const vtable_unk_080E85A0[]
    SECTION(".rodata.vtable_85a0") = {
#if defined(REGION_JP)
        nullptr,
        func_080E5898,
        func_080CAF6C,
#else
        nullptr,
        nullptr,
        func_080E596C,
#endif
    };

#if defined(REGION_JP)
extern void func_080CD950(void);
extern void func_080CC150(void);
#else
extern void func_080E5898(void);
extern void func_080CAF6C(void);
#endif

// Preserve this four-slot callback sequence and its regional targets in ROM order.
extern RawVTableFunction const vtable_unk_080E85AC[]
    SECTION(".rodata.vtable_85ac") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_080CD950,
        func_080CC150,
#else
        nullptr,
        nullptr,
        func_080E5898,
        func_080CAF6C,
#endif
    };

#if defined(REGION_JP)
extern void func_080CADF0(void);
extern void func_080CAF6C(void);
#else
extern void func_080CD950(void);
extern void func_080CC150(void);
#endif

// Preserve this four-slot callback sequence and its regional targets in ROM order.
extern RawVTableFunction const vtable_unk_080E85BC[]
    SECTION(".rodata.vtable_85bc") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_080CADF0,
        func_080CAF6C,
#else
        nullptr,
        nullptr,
        func_080CD950,
        func_080CC150,
#endif
    };

#if defined(REGION_JP)
extern void func_080E3504(void);
#else
extern void func_080CADF0(void);
extern void func_080CAF6C(void);
#endif

// Preserve this four-slot callback sequence and its regional targets in ROM order.
extern RawVTableFunction const vtable_unk_080E85CC[]
    SECTION(".rodata.vtable_85cc") = {
#if defined(REGION_JP)
        nullptr,
        nullptr,
        func_080E3504,
        nullptr,
#else
        nullptr,
        nullptr,
        func_080CADF0,
        func_080CAF6C,
#endif
    };

#if defined(REGION_JP)
extern void func_080E4E00(void);
#else
extern void func_080E3504(void);
#endif

// Preserve this three-slot callback sequence and its regional targets in ROM order.
extern RawVTableFunction const vtable_unk_080E85DC[]
    SECTION(".rodata.vtable_85dc") = {
#if defined(REGION_JP)
        nullptr,
        func_080E4E00,
        func_080A4624,
#else
        nullptr,
        nullptr,
        func_080E3504,
#endif
    };

#if defined(REGION_JP)
extern void func_080CF500(void);
extern void func_080CF430(void);
extern void func_080CF3E0(void);
#else
extern void func_080E59C0(void);
extern void func_080CFC7C(void);
extern void func_080CFBAC(void);
extern void func_080CFB5C(void);
#endif

// Preserve the region-specific vtable layouts and callback order in ROM order.
extern RawVTableFunction const vtable_unk_080E85E8[]
    SECTION(".rodata.vtable_85e8") = {
#if defined(REGION_JP)
        func_080A4988,
        func_080A5198,
        func_080A5E58,
        func_080CF500,
        func_080CF430,
        func_080CF3E0,
#else
        nullptr,
        nullptr,
        func_080E59C0,
        func_080A4BEC,
        func_080A4F50,
        func_080A5760,
        func_080A6420,
        func_080CFC7C,
        func_080CFBAC,
        func_080CFB5C,
#endif
    };

EXTERN_C_END
