## 四版入口边界对齐：内部跳转与独立子程序（1740–1747，2026-11-10）

game_world 的 15 个、animal_actor 的 24 个 JP 内部跳转标签原先被错误导出为 Thumb 函数。逐项检索 src/include/asm 的精确符号引用后，确认这些标签只有同文件内 B/条件 B 入向引用，没有 BL、数据指针或外部引用；其控制流继续使用所属函数的栈帧。现归回实际局部标签；原位置已有 .Lauto 标签的直接复用该标签，不增设别名。20 个真正被调用或需进一步核实的 loc 入口继续保留。

JP horse_race 的 6 个独立子程序此前藏在较大汇编定义内，以局部标签接收 BL 调用。核实完整保存寄存器的入口后，以真实入口位置命名并显式标注函数。只读重汇编保留局部符号，验证所有分配段的大小、对齐及字节保持后取得这些入口位置；没有猜测偏移、.set 别名或修改机器指令。三模块四版选出的指令序列均保持。

WSL make -j16 阶段 1746 四版均完成：JP/US/EU/DE 的完整 8,388,608 字节分别与对应 baserom 一致，四个 SHA-1 全部匹配。未修改编译器、预处理器或 LDS。此处完成的是函数边界及符号分类修正，不计为新增高级语言反编译量，也不据此宣称 11 个模块及所有资源已全部完成四版层级对齐。

下一步继续核实剩余模块中真正的地区专有入口、异名对应函数、类内汇编及误标的跨范围跳转；第一优先级仍是四版实际层级统一，地址候选审计暂不恢复。证据：branch-boundaries-plan-1740.json、branch-boundaries-applied-1741.json、horse-entries-plan-1744.json、horse-entries-applied-1745.json、full-build-1746/results.json。

## 四版载荷边界与结构字段核实（1733–1735，2026-11-10）

四版各核实 106 个 M4A 波形及 220 段地形数据范围。波形头的 +0x0C 样本数、源码 Samples/SamplesEnd 标签差、显式样本字节数及每版 ROM 中的实际载荷均一致；只将样本区内完整四字节窗口归为 PCM 数值，不覆盖波形头或填充。地形范围取自实际 ELF 对象大小，并核对源码网格行宽及属性记录大小；实际碰撞读取方按 u8 索引和属性位读取。原始数值扫描中，每版据此解释 11,490 个样本窗口、9,610 个地形索引窗口、12 个属性位窗口。

同时核实钓鱼、配方、闪屏和地图补丁参数的 106 个窗口。配方的 20 字节记录只解释前 8 字节的半字标量，后面的三个指针字段仍按真实重定位处理；钓鱼的 32 字节记录只解释前 30 字节，尾部 ABI 填充不混入字段。其余三表按实际字节读取和成员边界核对，没有按文件名整块忽略。

连同 1731 的已核实项，四版各有 21,226 个候选窗口得到格式解释。尚待核查的数值窗口为 JP 12,170、US 12,145、EU 12,144、DE 12,152；这些均不是已经确认的遗漏指针。仍保留音频的 19 个头部/序列窗口和地形的 3 个跨对象窗口，以及图形、字形、Mary 脚本和其他数据的候选。格式边界证据不能替代编码引用、字段容量、全部调用方及动态长度关系的后续审计。

本轮只读取已匹配的 1721 产物、当前源码和现有结构定义，没有改动程序、编译器、预处理器或 LDS，没有重复整版构建。证据：payload-classifications-1733-<region>.json、scalar-field-classifications-1734-<region>.json 及两个 summary，均位于本任务外部分析目录。

## 四版全 ROM 原始地址形态复核（1730–1731，2026-11-10）

在已验收的 1721 四版 ELF/map/ROM 上，对所有装载到 ROM 的数据和数据标记常量池扫描每一种字节对齐，检查未被真实重定位覆盖、值落在本版 ROM 范围内的四字节窗口。本轮同时覆盖未命名目标和对象内部位置，不再只检查发生位移的已知符号。JP/US/EU/DE 分别得到 33,396 / 33,371 / 33,370 / 33,378 个数值候选；这些数目不是遗漏指针数。资源、脚本和音频仍保留在完整清单中，未因所属文件而自动排除。

已结合读取代码明确三类非指针：出货初始产品/农作物列表中的 u8 产品编号；IWRAM 中 3×4 组、每项两字节的 OBJ 宽高表；ui_text_window 和 ui_state 常量池里的 0x08083F40。后者被 OR 入图层位后写到 HardwareDisplayState+0x50，实际是 BLDCNT=0x3F40 与 BLDALPHA=0x0808 的打包寄存器值，不是被解引用的 ROM 地址。IWRAM 对象边界使用 ELF 的装载地址解析，不能把其执行地址与 ROM 位置混用。

本轮没有发现足以直接修改的指针遗漏，也没有根据数值相似性改写源码。其余候选仍须按实际格式、字段边界与读取宽度分类；非对齐窗口、编码/压缩引用和未识别结构不能据本次扫描宣称审计完成。四版 1721 字节匹配继续有效；本轮只增加审计证据，没有改动程序或重复构建。

证据：raw-rom-values-1730-<region>.json、confirmed-nonpointers-1731-<region>.json；列表保存在本任务外部分析目录，未加入正式工具链。

## 四版统一源码构建全部匹配（1661–1724，2026-11-10）

JP 单独推进期间的源码、头文件、真实编译单元、文本归属和普通 LDS 组织已整体同步到 US、EU、DE。海外文本、实际结构尺寸、独有入口和显示参数分别保留；没有把 JP 的差异数据覆盖到海外版。

阶段 1721 使用同一份最终源码，在 WSL 依次执行四版正常 Make `-j16`。四个新生成的 ELF、map、ROM 均完成，所有 ROM 均为 8,388,608 字节，直接与对应 baserom 全量比较：

| 版本 | 完整 ROM 字节差异 | SHA-1（与各自 baserom 相同） |
| --- | ---: | --- |
| JP | 0 | `a655b2789aed14a6ac78c6075fbc533d3062dbe3` |
| US | 0 | `a2fc3574f0a65a4fcf7682fb274b9d7eebdef963` |
| EU | 0 | `7ba1ec1e46ce424e3c6fd72e4e8d5e9eb5ede247` |
| DE | 0 | `60f2a30b55c0e32754897b4d5df6ce06f8b71a37` |

构建使用现有 CPP、文本转码、agbcc/agbcp、通用段末对齐、汇编器和链接器；最后由普通 objcopy/gbafix 处理镜像及 ROM 头。没有使用函数或资源输出补丁、绝对 ROM 地址补位、手写 bad_alloc 副本或新增逐符号 LDS 子节。本轮海外同步没有修改编译器或预处理器规则。

本阶段完成的是：JP 独立阶段整组同步海外三版、真实地区差异恢复、四版正常构建及 baserom 完整字节/SHA-1 验收。早期 1685/1709/1712/1716 的失败或不匹配记录均为历史状态，以本次 1721 完整结果为准。

下一阶段是四版统一的未知边界、原始引用和动态尺寸关系审计。高级语言化继续渐进推进；不把符号化汇编当作已经完成的 C/C++，不把 SHA-1 一致等同于所有动态修改能力已验收。

证据：`full-build-1721/results.json`、四份 `global-report-<region>.json`、`source-sweep-inventory-1722.json`。通用编译器源码已在同级 agbcc/cp 本地提交 `b24094061ea76525206db659d6cdac853512bf27`，未推送。

## JP 完整字节匹配；海外同步尚未验收（1634–1643）

game_world 的既有世界创建入口及紧随其后的资源、实体、镜头接口归入 game_world_interface；世界状态更新和生命周期实现仍在 game_world。134个函数／35180字节及全部代码重定位在拆分前后完全一致，未增删调用；同名接口头只迁移既有外部声明。独立创建接口以原有 new 表达式自然生成库内容，world_sprite_effects的普通只读归属回到其世界效果代码所在模块群。没有手写bad_alloc、额外调用、无用依赖、特殊section、地址补位或输出修补；不声称已唯一还原历史文件名。

WSL make -j16 阶段1640完整构建通过。JP输出与baserom_jp.gba的8388608字节全部一致，差异0字节，SHA-1均为a655b2789aed14a6ac78c6075fbc533d3062dbe3。全局符号核对中18544个直接配对符号地址全部相同；加入1203项既有有据更名后，所有19691个覆盖区间均原字节一致，没有重定位映射问题。

JP编译匹配这一项已通过；US/EU/DE同步、四版解析层级及完整动态引用审计尚未完成，不能据此宣称整个目标完成。代码仍含正常符号化汇编。证据：world-interface-1634/checks-1636.json、world-interface-promotion-1638.json、full-build-1640/global-report.json。未提交、未推送。

## JP 环境对象创建接口拆分与整版结果（1623–1633）

现有 C++ 的 CreateWorldAmbientEntity 独立为 world_ambient_entity_factory；紧随其后的七个索引动画接口归入 world_ambient_animation。环境精灵本体及其位置、正弦、权重数据仍在 world_ambient_sprites。按真实类型和 API 边界拆分，未增加分配调用、无用头文件或手写库文本，也不声称这些就是原始文件名。

三个实际对象合计17个函数、2572字节代码及全部代码重定位与拆分前一致；原有608字节只读内容和引用保持。创建接口通过原有 new 表达式自然生成一份库字面量，动画接口没有新增只读内容。普通 LDS 对象顺序恢复对应归属，不增加子 section 或固定地址。

WSL make -j16 完整 JP 阶段1630编译、链接成功，剩余一组库生成／归属缺口由24缩为12字节，SHA-1仍未匹配：e455c89f3b75db954a0e86a710847b763382c99c，对照a655b2789aed14a6ac78c6075fbc533d3062dbe3。全局19133个区间原字节一致、556个引用变化已解释、2个长度／填充区间；没有新增未解释等长差异或重定位映射问题。44条补充引用通过，IWRAM的2120字节与baserom一致，加载地址仍提前12字节。

本阶段完整构建已使用1577安装的通用模板查找修复。海外三版尚未同步验收；四版整体目标与原始引用总审计未完成。证据：ambient-api-units-1623/checks-1625.json、ambient-api-promotion-1627.json、full-build-1630/global-report.json、uncovered-relocations-verified-1633.json。未提交、未推送。

## JP 末组缺口的依赖与编译单元核查（1587–1621）

最后完整构建仍为1555；JP仍有一组24字节运行库生成／归属缺口，SHA-1未匹配。此轮没有合入游戏、编译器、预处理器或LDS修改，没有整版重建或海外版构建。

环境控制器的外部候选已复核：绘制、更新、析构3个函数共236字节匹配，54个完整函数中仅创建入口仍不同；它还会在原有虚表前增加库内容，因此不能算整个对象通过，更不能算补齐末组缺口。调色板缓存的外部C++候选确认了实际资源槽／保留槽访问方式，但函数指令仍不同，未据此拆分源文件。UI析构的标准库头传播、标量placement new和填充、公共string头等未通过整体影响核查的方案均未采用。

早前环境只读区所选world_runtime、world_sprite_effects库输出的字节匹配，不代表已经唯一确定原始编译单元；直接后移只会在前面重新产生缺口。后续不得将这两份输出或其他未选入的SDK对象按数量搬来补位。正式源文件和安装编译器的接续哈希核对通过；局部匹配、归属假设与整版验收仍分别记录。证据：probe-decisions-1621.json、ambient-slots-1606/checks-1620.json、palette-cache-1614/checks-1619.json、continuation-1621.json。未提交、未推送。

## JP 剩余库内容核查；没有新增匹配成果（1580–1586）

最后完整构建仍为1555，剩余同一组24字节，JP SHA-1仍未匹配。方向评分中以std::max表达绝对值的实际对象试验改变两个完整函数，未采用。当前11个无库字面量但含实际分配引用的链接对象，以及19个有真实链接代码但未选入只读段的库输出对象已分别记录；后者不能按数量挑选补位。已排除陈旧.o造成的分配归属误判。

本轮未修改游戏源码、编译器、预处理器或LDS，没有完整重编译，也未开始海外构建。未确认的原始编译单元归属继续保留为缺口，不以头文件引入、机械拆分或移动无关库副本宣称解决。证据：remaining-library-1580.json、direction-magnitude-1581/checks-1583.json、unused-runtime-sections-1585.json、probe-decisions-1586.json。布局及重定位验收仍以1555／1558为准；未提交、未推送。

## 通用命名空间模板查找修复；JP 缺口未改变（1567–1579）

本轮核对发现：类模板实例化后，命名空间限定的显式函数模板调用仍可能保留 LOOKUP_EXPR。旧 agbcp 直接把它当作已解析的重载集合，触发内部断言980519。已在同级 agbcc/cp 的 Thumb、ARM 两份 cp/init.c 中，沿原有名称查找路径解析限定命名空间，再进行正常模板重载处理。没有游戏名、函数地址、字符串或输出字节规则；临时诊断已移除。

两份编译器的小范围命名空间／全局同名函数例子通过，限定模板调用与直接调用选择同一命名空间函数，独立全局重载保持不同。六个未改动的实际JP对象、37个完整函数的指令、重定位、只读数据、其他数据及COMMON均保持。经原 install.sh ../fomt 安装，安装树仅agbcp与agbcp_arm二进制内容改变。

FixedStr 改用标准 min 的源码方案仍被拒绝：虽然编译器不再断言，Animal的构造与SetName两个函数依然改变指令；未推广该头文件或仅借其产生库字面量。UI命令头依赖盘点也未作为补位依据，未新增无用途include。

本轮没有改动游戏源码、LDS、预处理器，也没有重新进行整版构建。最后完整JP报告仍为1555，仍有一组24字节库生成／归属缺口，SHA-1尚未匹配；该完整报告使用的是此前编译器，不能冒充新编译器的整版验证。US/EU/DE继续等待JP修复收敛；没有提交或推送。

证据：compiler-qualified-template-1571/promoted-1577.json、qualified-regression-1574/checks-1576.json、fixed-string-current-1567/checks-1570.json、ui-command-consumers-1578.json。

## JP 日历读取接口与剩余一组缺口（1548–1565）

已有矿洞调用实际执行 min(200, 解码年份)。将这项带上限的读取归入 GameCalendar::GetYear(maximum)，使用普通 std::min；无参 GetYear() 保留原始八位年份解码，不给所有读取强行加上限。time_of_day_types.hh 提供布局与声明，time_of_day.hh 提供实际算法实现和时段接口，虚表／类型消费者使用前者。这是等价源码组织，不宣称还原了未知的原始文件名。

81个实际JP依赖对象、1203个完整函数及全部其他数据／引用局部核对通过；只有time_of_day新增真实算法依赖自然生成的12字节。整个2016字节只读窗口0x08105244–0x08105A24解析重定位后直接匹配baserom。没有改动编译器、预处理器、LDS或编译产物。

WSL make -j16 整版阶段1555完成，SHA-1为c3b7a0be4edc4fd2ca6b23fb15e2b36ad6ffba08，尚未匹配基准a655b2789aed14a6ac78c6075fbc533d3062dbe3。全局报告中19133个区间字节相同，556个仅为已解释引用变化；没有无法解释的等长差异或重定位映射错误。44条补充重定位复核通过，IWRAM的2120字节与baserom一致。

剩余一组24字节：原版gUnk_FieldRenderLookupValues至gCppRuntimeError_FieldRenderRuntime之间两份库字面量的真实生成／归属尚未恢复。尾部多24字节是累计移位后果。方向候选容器及逐元素construct两种局部方案均改变SelectApproachFacing/SelectRetreatFacing，未合入；不为补位加入无用库依赖。US/EU/DE本阶段尚未验证，JP通过后再同步。未提交、未推送；全ROM原始引用／边界总审计仍未完成。

证据：calendar-consumers-1552/checks-1553.json、calendar-promotion-1554.json、full-build-1555/global-report.json、uncovered-relocations-verified-1558.json。

## JP 地图位集合恢复与剩余两组缺口（1524–1546）

MapPatchFlags 的真实存储为一个32位字、有效索引0..13，原指令在范围检查后仍保留字内位索引掩码。本轮用SGI数值bitset恢复这项值语义；游戏接口与存档大小仍为4字节，查询辅助函数仅留在本模块内部。库将类型布局声明与模板操作实现分开，保留通用单字／多字存储；不在只需存档类型的单元中引入未使用的算法实现。const字访问返回引用，没有地址、游戏名、字符串或指令序列补正。

完整候选头文件树及实际每对象参数验证了75个JP消费者、1182个完整函数：代码、引用、其他分配段和COMMON均保持。仅map_patch_flags增加由真实库依赖自然生成的12字节；完整180字节只读内容解析重定位后直接匹配baserom。14/32/65位及unsigned long／unsigned char字存储的小范围实例编译通过；这项编译检查不冒充运行测试。

正式JP阶段1542已用WSL make -j16完成，最新SHA-1为0a35bea10ee4d39c5b662326ea642994e6cbffad，尚未匹配基准a655b2789aed14a6ac78c6075fbc533d3062dbe3。19747个有证据配对区间中19105个字节相同，583个只有已解释引用变化；无新增无法解释的等长字节差异或重定位映射错误。44条报告外重定位复核通过，IWRAM整段2120字节与baserom一致。

运行库布局缺口从三组48字节降为两组36字节：钓鱼区域边界表与时段表之间12字节；地图渲染查找数据与Error之间24字节。尾部额外36字节填充是累计移位结果。仍须确认真实依赖／编译单元归属；不能加入无用途的库include或挑选未链接的字面量对象补位。本轮没有修改编译器、预处理器或LDS，也没有改写编译产物。

US/EU/DE暂不构建，本阶段共享源码的海外验证待JP匹配后同步。全ROM未知原始引用与资源边界总审计仍未完成；未提交、未推送。证据：bitset-consumers-1538/checks-1540.json、bitset-promotion-1541.json、full-build-1542/global-report.json、uncovered-relocations-verified-1545.json。

## JP 食谱编译单元、模板重载及依赖范围收尾（1492–1522）

优先处理JP的正常编译匹配，再将成立的修复同步验证US/EU/DE；统一审计在四版匹配后继续。本阶段没有推进汉化或扩展资源扫描。

同级agbcc的cp分支以最小通用修改区分函数模板偏序与精确实例匹配：仅在偏序比较中的引用／值参数配对时执行必要归一化，保持两侧引用的cv规则和精确实例ABI。Thumb／ARM编译器均通过两个独立的普通模板重载示例，并通过未修改的install.sh安装。没有游戏符号、地址、字符串或输出指令序列补正。

标准库fill_n的指针重载按元素类型传递整数值；非整数及volatile元素保留引用参数。局部检查发现旧编译器不能可靠地把不存在的类型成员作为候选替换失败，因此已用有效的引用参数回退，普通结构体／volatile元素示例可编译。没有将这个问题转嫁给预处理器或链接结果修补。

食谱定义／求值与持久化库存按实际职责分为cooking_recipe.cc、cooking_recipe_inventory.cc，各自有同名接口。cooking_recipe_types.hh仅提供共享的存档记录布局和声明，完整的算法构造实现仍由cooking_recipe_inventory.hh提供。仅需类型布局／虚表的场景与存档类型接口不再解析算法构造体；实际构造单元仍保留实现。这项分离是实测依赖边界，不能通过抑制某个字符串代替。

早期1497局部对照的嵌套引号include会优先读正式树，未完整覆盖候选头文件传播，故不能扩大解释为完整推广验证。1507／1514已复制完整候选头文件树，按真实每对象编译参数验证：79个受影响类型消费者、130个算法消费者的全部函数均保持，只有新游戏菜单、菜单跳转、烹饪生命周期三份额外库字面量各减少12字节。真实食谱区间0x08100C24–0x08103194的9,584字节通过直接baserom对照；食谱求值和库存的8个完整函数保持。

最新正式JP整版1517已以WSL make -j16完成编译／链接／生成，compare因SHA-1不一致返回2。产物SHA-1为1765b3dbe9279f61799b55d5909ce104e1bc08d0，基准为a655b2789aed14a6ac78c6075fbc533d3062dbe3。19,747个有证据配对的符号区间中，19,082个字节相同，605个仅为已解释引用变化；没有剩余的无法解释等长字节差异、未解决已变化引用或重定位映射错误。原报告外44条重定位补核通过；IWRAM镜像2,120字节与baserom相同，执行基址不变。此结果不证明全ROM未知原始引用已经审计完毕。

真正未关闭的布局缺口由四组72字节降为三组48字节：

|基准JP区间|内容|未恢复字节|
|---|---|---:|
|0x081031FC–0x08103210|诅咒工具阈值之后、地图标志选择表之前的自然库字面量归属|12|
|0x08105184–0x08105250|钓鱼区域边界表之后、时段表之前的自然库字面量归属|12|
|0x08106FA0–0x08107024|地图渲染查找数据之后、Error之前的原编译单元／库字面量归属|24|

全ROM原始差异字节很多来自这48字节累计移位，不能当作独立错误计数。尾部填充多48字节是结果，不是新的修复对象。const整数find候选改变原函数与事件实例且对类类型失败，已拒绝，未进入正式源码。19个未选择的SDK-only对象也不是可搬来补缺口的空白，未按数量插入LDS。

海外三版共享源码／LDS已有对应食谱组织，但未通过本阶段整版验证，不能称为四版完成或进度已验收一致。下一步仍集中查清以上三组真实来源；不恢复手写bad_alloc、不补无用途的new、不填字节、不修改简洁LDS来硬贴地址。未提交或推送。

证据：compiler-partial-order-1492、recipe-production-1501、recipe-unit-ownership-1495/checks-1496.json、recipe-header-closure-1507/checks-1509.json、algorithm-header-closure-1514/checks-1515.json、full-build-1517/global-report.json、uncovered-relocations-verified-1521.json。

## 地图补片混合块边界整理（1464–1471）

将旧 map_state_tilemap_templates.bin 的50,408字节按真实读取方式拆清为62段：46份u16背景地图、16份MapTilePatchFrameHeader与4bpp帧图块。JP、DE、US/EU共享分支共186处切片在原asm/data/graphics.s位置展开；保留原符号与顺序，没有新建资源目录、宏、LDS子项、构建工具或补丁。地图依照描述符宽高分行；10处共20字节尾零由.align 2, 0补齐。帧头保留实际每帧tile数，帧数由像素边界标签差除以每帧字节数计算。

JP正式WSL make -j16图形对象通过：全部2,308,848字节.rodata、各分配段大小／对齐／重定位、全局符号及COMMON不变；62段50,408字节也通过原始符号地址直接与baserom对照。海外三版仅更新依赖清单，尚未重编对象，不能算作海外验证通过。四版依赖清单与正式源码均不再引用旧bin，确认外部审计备份后移除该未用混合块。

此前最后1个待定地址形数值0x08080999位于资源011的9 tiles × 2 frames像素中，经gMapTilePatch7及QueueMapTilePatch实际读取证明不是函数指针。319个有限候选均已定位存储类型；6个编码流候选仍未证明解码后无引用，其他未知、非对齐、算术或RAM引用也不能据此算作全部查清。16份帧图块仍为原位像素字节，尚未接入PNG编辑链。

最新完整构建仍为1428，四组72字节运行库／布局缺口与SHA-1不匹配仍未解决；相同对象载荷未重复整版构建。本次未修改编译器／预处理器／LDS，未提交或推送。证据：native-template-slice-formats-1465.json、native-template-production-1466/actual-checks-1468.json、baserom-checks-1470.json、raw-address-classifications-1471.json。

## JP 初始化回调对象与全ROM原始地址候选（1451–1463）

new.cc的__new_handler、allocation_failure.cc的gAllocationFailureHandler从内联汇编零字改为真实可变函数指针定义；二者维持原有普通.data归属及初始化RAM镜像顺序，没有新增子section或修改LDS。第二个回调保留原声明的C语言链接／参数规则，没有将两个独立回调混成同一类型。正式WSL make -j16的两个对象、13个已有函数及全部分配段的原字节、大小、对齐、重定位和COMMON均保持。符号对象大小由0补为正确4字节，不计为新增C++函数。共享源码的海外验证仍待JP阶段完成后进行。

另对当前JP整版数据和常量池统一筛查无重定位地址数值：函数目标检查3987个实际函数值（四字节对齐），旧数据目标检查13715个已移动配对地址（所有字节对齐），与50733个真实重定位位置分开处理。319项候选已有318项定位至已知存储格式；余1项落在尚未解码的map_state_tilemap_templates.bin，不能按文件名猜其含义。已知项包括波形、像素、位置字节、归档半字索引、OAM属性、字模索引及跨VM指令边界的数值。6项仅证明位于编码资源流内，不代表已审计解码后的引用。

图形与字体按正常Makefile ASFLAGS生成诊断清单，两个对象所有分配段及重定位与现有产物相同；759处图形incbin及2处字模incbin逐项对照实际资源文件。没有按地址数值批量替换，也没有宣称整个ROM引用已全部查清。Mary仅核对两个命中脚本的局部CODE指令边界，未重新导出或修改脚本。

最新完整构建仍为1428，四组72字节运行库／布局缺口未关闭，SHA-1未匹配。此次完整对象载荷与重定位相同，未重复整版构建；新对象的符号大小信息将在下次链接进入ELF。未修改编译器、预处理器、库或构建参数；未提交／推送。证据：new-handler-production-1458/actual-checks-1462.json、allocation-handler-production-1461/actual-checks-1462.json、raw-address-classifications-1462.json、stage-1463/evidence.json。

## JP 道具标准接口与剩余引用补核（1432–1443）

道具六处容量最小值运算改用已有依赖提供的 std::min，以 u32 参数推导保留原有引用语义，删除本地重复的 FomtMin 模板。54 个已有函数不是新增高级语言成果。实际 WSL make -j16 对象通过；全部分配段的原始字节、大小、对齐、重定位及 COMMON 均与已验证对象一致。本批只改游戏实现，不改编译器、预处理器、库头、LDS 或参数。共享源码的海外验证仍待 JP 完成后进行。

针对1428报告保留的28条未支持记录和16条等长区间外记录，现已逐项补核44条：22条两字节Thumb条件跳转直接解析到实际符号，17条R_ARM_V4BX保留BX指令／寄存器／条件，另3条RAM对象指针及2条ARM调用均按IWRAM执行地址解析。IWRAM整段2120字节直接与baserom一致；ROM加载起点由0x0877F610变为0x0877F5C8，执行基址仍0x03000490。没有增加地址补偿、修改输出或改变全局符号配对；这是补充审计，不是新增44条符号化引用，也不证明没有其他未记录的原始引用。

最新完整构建仍为1428；本次实际对象载荷与重定位完全相同，未重复整版编译。四组72字节运行库／布局缺口及尾部补位仍未关闭，SHA-1仍未匹配，不能宣称完成。六项祝福状态find候选改变目标函数及事件实例顺序，已拒绝且未推广。原ROM对剩余库字面量与相邻Error／なし未发现直接绝对地址指针，但不据此认定无用途或确定来源。未提交／推送。

证据：item-min-production-1438/actual-checks-1439.json、uncovered-relocations-verified-1442.json、remaining-runtime-absolute-readers-1439.json、cursed-find-1432/decision-1443.json、stage-1443/toolchain-review.json。编译器和预处理器本轮为只读审查，未重新构建编译器；不将源码审查等同四版验收。

## JP 通用指针查找接口与原生调用方式（1420–1431）

当前库新增一个适用于任意T*/const T*范围的std::find重载，沿用既有四路搜索及余数处理顺序，裸指针无需向独立工作函数传递类别对象。原有通用迭代器／四参数类别实现及接口保持。JP精灵工作目标、事件变量登记和删除使用真实std::find，三个显式实例化维持原三参数调用方式；没有游戏类型／地址／变量名分支、伪别名、编译后改写或新增游戏操作。此前共享析构头方案因纯元数据对象增加12字节而未采用。

123个实际JP头文件依赖及元数据控制对象、1936个完整函数、490004字节代码、命名数据、其他分配段与COMMON全部核对通过；正式make -j16产物也一致。三个工作函数分别164、116、116字节，其完整原生函数均直接与baserom核实，再依据原型和模板类型完成真实符号身份配对。它们此前已经是C++，本次是库接口与依赖恢复，不计新增高级语言函数。

精灵模块正常只读输出成为40字节：库输出10字节、自然对齐2字节、小屋位置表28字节，整窗0x08103BD4–0x08103BFC直接匹配baserom。LDS无需改动。两个显式实例化单元的新增只读内容仅有本地未用库字面量，无分配段读取或外部数据定义，继续原先仅链接.text的方式，没有按副本数量给它们安排ROM位置。

1428完整JP构建／1429全局报告：19076区间原字节一致、610引用变化区间已解释、5长度／填充区间，重定位映射问题0、未解释字节区间0。剩四组运行库／布局缺口72字节，外加ROM尾部累计补位；原11344字节元数据仍原位一致。新增三项已证实的函数身份使可配对符号达到19747，这属于审计覆盖完善，未修改ROM或掩盖差异。SHA-1为5630fb1e2dc942df66aed4202e3648ffa12d63ff，尚不等于baserom的a655b2789aed14a6ac78c6075fbc533d3062dbe3。

原有JP四参数u8入口以原生汇编保持；海外分支的显式四参数模板未重编译，不能将其计为海外验收。共享库头仍待JP完成后统一海外验证，海外游戏源码保留。未改编译器、预处理器、构建参数、LDS或ROM输出；未提交／推送。证据：pointer-find-consumers-1423/checks-1425.json、pointer-find-production-1426/actual-checks-1427.json、baseline-identities-1430.json、full-build-1428/global-report.json。

## JP 事件变量复制与通用POD字节长度（1401–1415）

GameEventState删除已登记变量时，已有空范围检查后向左搬移u16条目。源码现使用真实std::copy；当前库的POD分派仍调用memmove，三参数查找及事件状态其余逻辑保持。tools/libagbc++/stl_algobase.h仅修改一行：搬移长度由sizeof(T)*(last-first)改为char指针字节差；对目标平台的有效数组范围二者相等，公共接口、返回值、类型特征和分派均未变，不依赖任何游戏地址、符号、字符串或指令模式。此举避免旧编译器保留多余的除以元素大小再乘回去指令。不是编译后改写，也未改编译器／预处理器／构建参数。

123个实际JP头文件依赖对象、1949个完整函数、491908字节代码、全部既有只读载荷、其他分配段及COMMON核对通过；当前map无遗漏的外部依赖对象。正式make -j16对象再次核对一致。已有事件实现模块在.text中本就位于map_patch_flags与fishing_results之间，其正常.rodata以同序加入；12字节输出／对齐窗口0x081032B8–0x081032C4直接匹配baserom。相同匿名字节不能独自证明历史编译单元，本次同时依据实际复制API和原有模块顺序。

1412完整JP构建与1413全局报告：19072区间原字节一致、610引用变化区间已解释、6长度／填充区间，映射问题0、未解释字节区间0。剩五组运行库／布局缺口84字节，另有ROM尾部累计补位；原11344字节元数据仍原位一致。SHA-1为0b1003110e0062aa1f2ded9ffd66b24aceee1969，尚不等于baserom的a655b2789aed14a6ac78c6075fbc533d3062dbe3。原来落在长度不等区间外的28项指针现在可纳入全局核对，这是审计覆盖增加，不是新增了28个符号化指针。

海外游戏源码未修改；共享库头这一行仍须在JP完成后进行海外验证，不能视为四版通过。未提交／推送。证据：copy-header-consumers-1407/checks-1409.json、copy-header-production-1410/actual-checks-1411.json、full-build-1412/global-report.json。

通用字节复制模式可参照[STLport _algobase.h](https://android.googlesource.com/platform/external/stlport/+/f93b0c8350e72556faa137400cc955440654d29e/stlport/stl/_algobase.h)；这是库实现模式的一手源码证据，不是游戏使用该特定版本的证明。

## JP 精灵小屋位置表实际归属（1392–1400）

gHarvestSpriteHutPositions的唯一已确认可执行读者为harvest_sprite.cc内的InitializeHarvestSpriteHutLocation。28字节位置表及其四字节记录类型／声明已从actor_runtime_data移到harvest_sprite.cc／harvest_sprite.hh，仍使用原符号与X、Y、朝向及尾对齐；LDS在同一物理顺序只换成普通harvest_sprite.o(.rodata)。没有新增文件、算法、库依赖、函数或地址补偿。海外原实现保留，当前仅验收JP。

78个实际.d依赖对象、1203个完整函数、308436字节代码、全部命名数据、其他分配段和COMMON核对通过，28字节数据直接匹配baserom。正式make -j16的78个对象也与候选一致。1397完整JP构建及1398全局报告确认：19072区间原字节一致、609引用变化区间已解释、7长度／填充区间，映射问题0、未解释字节区间0；11344字节元数据仍原位匹配。SHA-1仍为e63f704533b40d815d940fe49a26538b7dbd9831，不等于baserom的a655b2789aed14a6ac78c6075fbc533d3062dbe3。本次仅修正归属，不计为关闭六组96字节缺口。

三项实际库API候选均未推广：数组std::fill改变构造函数；标准std::find引入第四类别参数并改变调用指令；FixedStr标准min改变两个函数（显式模板写法另触发旧编译器错误，普通推导写法可编译但仍不匹配）。详情保存在probe-decisions-1391.json，避免重复尝试等价变体。未修改工具链或海外版，未提交／推送。验收证据：hut-data-owner-1392/checks-1394.json、hut-data-production-1395/actual-checks-1396.json、full-build-1397/global-report.json。

## JP 姓名录入实现依赖与相邻模块输出（1373–1381）

姓名录入的六项提示保持由name_entry.cc及同名JP文本维护。轻量声明之后先定义真实文本，再包含Run实际使用的键盘、场景与存档实现API；不新增头文件、类型、调用或分配。已有scene_minigames保持源码不变，其普通只读输出按现有代码模块顺序列在name_entry前。相同匿名库字面量不足以唯一证明历史编译单元身份，本次依据真实实现依赖、现有相邻代码顺序和整窗结果，不按副本数随意安排。

两个实际对象的13个完整函数、1768字节代码、全部命名载荷、其他分配段及COMMON保持。72字节窗口0x0810494C–0x08104994直接匹配baserom：相邻场景正常库输出、六项提示、姓名录入实现依赖的正常库输出及自然对齐。正式对象与局部候选一致。

1378完整JP构建及1379全局审计：19072区间原字节一致、609引用变化区间已解释、7长度／填充区间；未解释区间0，映射问题0。实际库输出／布局缺口合计108→96字节，六组未完成区间外加ROM尾部累计补位。11344字节元数据仍原位匹配。SHA-1为e63f704533b40d815d940fe49a26538b7dbd9831，尚不等于baserom的a655b2789aed14a6ac78c6075fbc533d3062dbe3。

此前recipe count_if试验因完整函数指令变化而拒绝，未进入源码；库头中的Error线索不足以证明孤立字段的来源，仍保留未完成。1380引用图检查371个实际链接输入，不能据此宣称任意立即数地址和全ROM引用已经全部动态化。未修改编译器、预处理器、库、构建参数或海外版，未提交／推送。证据：name-entry-owner-1373/checks-1375.json、name-entry-production-1376/actual-checks-1377.json、full-build-1378/global-report.json。

## JP 文本输出／数字文本／UI状态归属（1360–1369）

本阶段关闭原0x080F978C附近的12字节缺口。十个连续文本输出、输入及窗口虚拟方法归入`src/ui_text_rows.cc`／`include/ui_text_rows.hh`；两段既有十进制格式化函数及实际读取的数字／空格／连字号对象归入`src/decimal_text.cc`／`include/decimal_text.hh`，文本由同名`data/text/jp/decimal_text.cc` include。`src/ui_state.cc`保留状态对象、选项布局、所有原先在末尾生成的内联入口；原`ui_text_commands.hh`逻辑元数据定义归属不变。旧JP的ui_state文本文件已移动，海外原实现保持。

文本输出类型本身已有真实的行／像素缓冲new构造，标准声明仅在实现源中提供；没有添加假分配、假类型、假调用或不使用的DMA队列API。前段绘制仍使用实际CpuFastSet。公共绘制小函数随文本输出API维护，OAM追加辅助函数继续留在状态实现，避免给所有使用者引入不相关的硬件依赖。

90个实际依赖对象、1563个完整函数、501436字节代码及全部具名数据／元数据／COMMON核对通过。对象拆分后的本地跳表坐标按真实重定位核对，目标指令不变；未修改编译输出。132字节完整窗口0x080F9758–0x080F97DC直接匹配baserom，使用三个普通对象和自然对齐恢复，没有新增LDS地址或子section。原font_decimal剩余tilemap命令与32字节元数据保持，不把模块移动计作新增高级语言函数。

WSL正式`make -j16`对象验证后，1366完整JP构建生成新ELF/map/8MiB ROM。1367全局报告：19071个区间原字节一致、609个引用变化区间已解释、8个长度／填充区间；未解释字节区间0，重定位映射问题0。有效缺口合计120→108字节；另外保留一处ROM尾部累计补位。11344字节元数据仍在0x080E4E0C–0x080E7A5C原位与baserom一致。SHA-1仍未匹配：34343e9240f57a9be718c2ede54d1bcbae84dc1d，对照a655b2789aed14a6ac78c6075fbc533d3062dbe3。

未修改编译器、预处理器、库、Make参数或输出；未提交、未推送。证据：ui-text-owner-1360/checks-1362.json；ui-text-production-1364/actual-checks-1365.json；full-build-1366/global-report.json；layout-mechanisms-1368.json、remaining-boundary-readers-1368.json。剩余七个库输出／布局区间继续按真实依赖追查，未把18个未选库输出对象按数量随意放入。

## JP 保存地图图形查询及真实分配API（1348–1357）

保存地图尾部四个连续图形查询／传输入口共160字节移至`src/saved_map_graphics.cc`／`include/saved_map_graphics.hh`，原`src/world_saved_map.cc`保留前段19124字节。两张实际季节范围、双列查找表从纯数据文件归入新模块，相关声明及必要packed布局也由同名头文件维护。双列表由首个查询函数直接读取，季节表仍由保存地图前段读取；通过真实外部符号共享。新头文件只依赖基础类型／常量与前置声明，完整保存镜像、地图选择和DMA实现API放在物理上较早的数据定义之后。

`ui_portrait.cc`原本已有两处真实C++ new表达式，现使用标准new声明。`farming_tutorial_world.cc`保留完整原生函数及其真实C++虚拟控制器分配定义，补齐原生DMA描述符构造、复制和扩展所需的既有API。没有添加假类型、假分配、假调用或无用途库依赖。两个旧数据所有者的全部具名对象、引用及数据保持；原Error／回退文本的直接调用和历史类型归属仍未查明，没有据相邻位置将它们改成编译器字符串。

30个实际依赖对象、687个完整函数、133916字节代码通过局部及正式WSL对象核对。160字节拆出内容包含既有C++与原生汇编，不能计为新增四个高级语言反编译函数。现有GCC逻辑元数据归属不变，LDS只增加普通对象输入。114字节数据及自然输出前缀与baserom一致，随后由下一普通输入自然对齐；本组补回36字节库输出及对齐，原60字节缺口缩为24字节。三个匿名输出在原版中彼此同内容，不能仅凭字节重复确定每一份的历史编译单元；本次只证明实际源码API依赖与正常编译产物，不宣称该历史归属唯一成立。

1354阶段JP完整构建及1355全局报告通过产物新鲜度检查，仍有9处长度／填充区间，其中8处库输出／布局缺口合计由156缩为120字节，另一处为ROM末尾累计补位；18956区间原字节一致、723区间引用变化已解释，未解释字节区间0、重定位映射问题0。11344字节元数据继续在0x080E4E0C–0x080E7A5C原位等于baserom。SHA-1尚未匹配：d858fbdf2df38a517d445fa0951020192b0afee3，对照a655b2789aed14a6ac78c6075fbc533d3062dbe3。原151份／现141份库字面量仅作观测，不按数量随意选择未链接对象。

未修改编译器、预处理器、库、Make参数或输出，没有新增地址／子section补偿；海外原实现保持。未提交、未推送。证据：saved-graphics-api-1348/checks-1351.json；saved-graphics-production-1352/applied.json、actual-checks-1353.json；full-build-1354/global-report.json；layout-mechanisms-1356.json、remaining-boundary-readers-1356.json。后者已覆盖369个实际输入，两侧数据目标和第二跳数据引用均重新读取，仍不等于全部立即数组址均已证明。

## JP 菜单面板／场景归属及整版验证（1337–1346）

实际面板／图标类的完整前段实现（10504字节）及坐标、未知布局数组归入`src/game_menu_panels.cc`／`include/game_menu_panels.hh`。`src/game_menu.cc`／`include/game_menu.hh`保留从真实场景核心构造函数开始的9764字节实现、光标导航与状态说明文本。后续删除上下文中的原面板析构入口保持在原调用顺序；既有`game_menu.hh`／`game_menu_lifetimes.hh`逻辑元数据定义归属不变，没有按库字面量数量随意切函数。

面板原生函数实际构造、复制及扩展DMA描述符队列，现使用既有的真实队列API依赖；场景使用自身保存镜像API，不再依赖不相关的新游戏菜单接口。没有新增无用途的new、类型、分配或调用。普通文本仍在场景源码按原顺序include `game_menu_1.cc`至`game_menu_4.cc`，面板没有另造文本文件。海外原实现保持。

18个实际依赖对象、464个完整函数、134008字节代码及全部命名数据、元数据和COMMON核对通过。两份菜单对象合计20268字节代码不增不减；拆分改变的是49个实际ABS32 `.text`段跳表项的对象内坐标，按真实重定位解析后指向完全相同的指令。该解析只用于只读核验，没有修改编译输出或掩盖字节差异。736字节完整只读窗口0x08118A14–0x08118CF4与baserom逐字节一致，包含两处自然库输出、真实数组、文本及指针；靠源码／输入顺序和普通对齐获得。

WSL正式`make -j16`对象全部分配段与候选一致。1343阶段完整JP构建生成新ELF/map/8MiB ROM，1344全局报告长度／填充区间由10降为9：18956个区间原字节一致、723个区间引用变化已解释，未解释字节区间0、重定位映射问题0。11344字节元数据继续在0x080E4E0C–0x080E7A5C原位与baserom一致。SHA-1仍未匹配：c75ee65683e8eb29a775d788932b21f07c2bb877，对照a655b2789aed14a6ac78c6075fbc533d3062dbe3。剩余为8个库输出／布局区间及ROM尾部累计差异，不把同内容字面量数量当作来源证明。

此前钓鱼默认文本的唯一真实定义归属整理已纳入本次整版。动物／精灵钳制改写成标准min/max的外部探针因额外栈读写不匹配而拒绝，没有写入工程。未修改编译器、预处理器、库、Make参数或ROM输出；JP LDS仅在两个普通输出段各加一次面板对象。未提交、未推送。

证据：menu-panel-owner-1337/checks-1339.json、text-reloc-detail-1340.json；menu-panel-production-1341/actual-checks-1342.json；full-build-1343/global-report.json；layout-mechanisms-1345.json、remaining-boundary-readers-1345.json。当前源／对象／整版产物一致。

## JP 钓鱼默认文本归属整理（1330–1332）

`gText_Fishing_NoCatch` 的唯一真实定义改由 `src/fishing.cc` include 同名 `data/text/jp/fishing.cc`；`include/fishing.hh` 只保留外部声明。文本仍为“なし”，没有改变内容、长度或物理顺序，也没有增加别名。实际 JP 依赖仅一个钓鱼对象。

两个完整原生函数共1816字节保持；所有分配段的字节、尺寸及对齐不变。原本指向对象段起点的重定位改为指向真实全局文本符号，目标存储与加数等价。2030字节完整只读载荷直接匹配 baserom 的0x08104994–0x08105182（结束地址不包含）。WSL正式对象与已验证候选的分配段及重定位一致。未修改运行库生成来源，SDK字面量仍为原一份，不能将本项计为布局缺口修复。

最新整版结论仍为1323报告的10处长度／填充差异，SHA-1未匹配。当前钓鱼对象比该整版ELF/map更新，后续统一构建前不混用它们进行全局验收。没有重启WSL，没有重复启动已结束的构建；未修改海外版、编译器、预处理器、LDS或构建参数，未提交、未推送。证据：fishing-text-owner-1327/checks-1329.json；fishing-text-production-1330/applied.json、actual-checks-1331.json。

## JP 日历核心／场景与滚动菜单整版验证（1318–1325）

日历的八个完整原生核心函数（5432字节）归入`src/scene_calendar_core.cc`／`include/scene_calendar_core.hh`，原有两个C++场景方法（100字节）保留在`src/scene_calendar.cc`／`include/scene_calendar.hh`。核心继续包含实际读取的保存镜像API，场景使用标准new声明进行现有的`new CalendarSceneCore`分配；没有加入日历不使用的DMA队列API，没有为输出字面量添加无用途的new头、类型或调用。完整932字节原生构造函数保留，没有使用未匹配的C++试验版本。

核心按物理顺序include同名`scene_calendar_core_1.cc`、17项实际packed季节／日期表（34字节、ALIGN(1)）、`scene_calendar_core_2.cc`。场景段尾的单份回退文本使用同名`data/text/jp/scene_calendar.cc`，保留原“なし”及原符号；当前未建立其直接src读取，不臆测其精确历史类归属或将其改称编译器字符串。旧JP的scene_calendar_1/_2/_3已移动，海外原实现保持。

七个实际依赖对象、275个完整函数入口、50848字节原始.text及全部代码重定位保持，虚表／析构接口仍由原逻辑接口`scene_calendar.hh`和既有生命周期源统一定义。正式WSL `make -j16`对象所有分配段与验证候选一致。完整1244字节窗口0x08104470–0x0810494C直接等于baserom，靠源码顺序、普通输入对齐及下一对象自然对齐得到。JP LDS只增一次普通Core .text和.rodata输入，无地址、子section或输出补偿。

本次1323完整JP构建也纳入此前滚动菜单局部修复：其十四个原生函数保持，实际队列API依赖的标准库输出与自然四字节对齐恢复58字节窗口。1324全局报告的长度／填充区间由12降至10，18955个区间原字节一致、723个区间引用变化已解释，重定位映射问题0、未解释字节区间0。完整SHA-1仍不匹配：20bb5ef1b2f6f6b35360686832421d388c4ea3b5，对照a655b2789aed14a6ac78c6075fbc533d3062dbe3。原元数据11344字节继续在0x080E4E0C–0x080E7A5C原位匹配。原151份／现137份运行库字面量只作观测，不按数量放置。

剩余边界审计同时检查缺口左右两侧目标，并解析实际对象段ABS32重定位指向的具名数据，避免仅按前一数据表推断库输出归属。367个当前实际链接输入均可读取；这是有界引用图，不包括全部立即数组合、任意指针算术或所有ROM引用的完备证明。姓名末尾缺口的右侧目标为SelectFishingCatch读取的私有默认文本；之前仅按符号名搜索会漏掉其标准对象段重定位。未据此添加库头或推断完整历史编译单元。

未修改编译器、预处理器、库、Make参数或ROM输出；未提交、未推送。证据：calendar-native-owners-1318/checks-1320.json；calendar-owner-production-1321/applied.json、actual-checks-1322.json；full-build-1323/global-report.json；remaining-boundary-readers-1326.json。

## JP 滚动菜单真实队列 API 依赖：局部通过（1312–1317）

`src/scroll_menu.cc`的原生菜单和分页绘制多处保留真实16字节DMA描述符构造、队列扩容、placement-copy及销毁／释放展开，现与已验证的飞盘核心、商店一样，引用现有`hardware_dma_queue.hh`操作API。未改构造函数、类型、头文件、文本片段、LDS或工具链，也未添加分配调用、手工库字符串或独立无用途的new头。

十四个完整原生函数、5448字节.text及全部原始代码重定位不变；具名数据、其他分配段和COMMON不变。标准库真实依赖正常产生一份字面量，普通.rodata自然取得四字节输入对齐。渲染器／缓存／滚动菜单串接窗口0x080FB8F0–0x080FB92A的58字节与baserom完全一致，包括全部具名对象原位置；不补固定零字节或LDS对齐条目。正式WSL `make -j16`对象与局部验证候选全部分配段一致。

本项仅完成局部及正式对象验证，尚未纳入新的完整JP构建。最后完整1309报告仍是12处长度／填充差异；不要把预期关闭的一处直接计成已整版确认的11处。当前Root对象已更新，Root ELF/map/GBA仍属1309；下一次全局审计必须先完成新一批完整链接，不能把旧map与新对象混用。

证据：scroll-native-api-1312/checks-1314.json；scroll-native-production-1315/applied.json、actual-checks-1316.json。未提交、未推送。

## JP 真实 DMA 使用者与混合语言编译单元（1299–1311）

飞盘核心的23264字节连续原生实现归入`src/frisbee_core.cc`／`include/frisbee_core.hh`，六表及十五项游戏文本仍依物理顺序维护，文本改为同名`data/text/jp/frisbee_core.cc`。`src/frisbee.cc`／`include/frisbee.hh`保留原有三函数、184字节的C++场景包装器和真实的`new FrisbeeCore`及后续场景生命周期。既有GCC逻辑接口`frisbee.hh`和析构／虚表定义归属不变；没有新增类、分配调用或虚表。旧JP文本文件已移走，海外的实际指令和C++方法保持原实现，待JP通过后再同步。

核心的`UpdatePowerGauge`与商店显示更新中含有真实的DMA队列内联展开：取得队列、构造16字节描述符、按0/4/12字段及16字节步长扩容、placement-copy、销毁和释放。这两个实现现在声明实际依赖现有`hardware_dma_queue.hh`操作API。该API使用`std::construct`，其标准库依赖是`memory`→`stl_construct.h`→`new.h`→`new`；旧头文件中的`bad_alloc::what()`字面量由编译器正常输出。并非单独添加无用途的`<new>`，也没有用ASM的BL假定编译器会生成缺失定义；完整原生函数和真实类型/API同时保留，未将未匹配C++替代品混入正式源码。

八个实际对象、284个完整函数入口、78596字节原始.text和全部原代码重定位保持不变，正式WSL `make -j16`对象的所有分配段（含尺寸、对齐、重定位和COMMON）与验证候选一致。排名／飞盘／场景的完整1456字节原版窗口0x080F99AC–0x080F9F5C，以及商店64字节窗口0x081189D4–0x08118A14，均按普通输入对齐及真实文本指针重定位与baserom完全一致。商店后紧接game_menu原有12字节运行库前缀，然后才是0x08118A20的首个具名坐标对象；不应把中间数组0x08118A48当成game_menu块起点。

JP LDS仅在既有场景对象之前各增加一次普通`src/frisbee_core.o(.text)`及`src/frisbee_core.o(.rodata)`，没有地址、逐变量section、GNU子项或补偿填充。工具链、库、Make参数、生成器和ROM输出均未补丁。

1309完整JP构建得到新鲜ELF、map及8MiB ROM；与baserom的SHA-1仍不一致：3b22d3f64b6eb1c12a831dff9964568bfb38c931，对照a655b2789aed14a6ac78c6075fbc533d3062dbe3。1310全局报告中19744个对照符号形成的区间有18953项原字节一致、723项引用变化已解释、12项长度／填充差异；上一完整报告为16项，现关闭了飞盘与商店的两处运行库缺口及其两处关联对齐差异。重定位映射问题0，新增未解释字节区间0；原元数据0x080E4E0C–0x080E7A5C的11344字节继续在原绝对位置匹配。运行库字面量原151份／现135份仅作观测，不按计数放置。

半高级语言化仍可按正常C++加完整汇编推进，不将局部库依赖恢复扩大为整个ROM已完成动态化。前次440字节力度条C++尝试依旧未采用，其寄存器调度差异不靠输出补丁处理。未提交、未推送。

证据：frisbee-core-1299/checks-1304.json、shop-native-DMA-evidence-1303.json、foreign-source-extraction-proof-1302.txt；dma-owner-production-1307/applied.json、actual-checks-1308.json；full-build-1309/global-report.json。

## JP 飞盘力度条真实入口与 RAM 布局（1285–1298）

`loc_08054CD0`此前被统计为804字节，实际上包含两个独立入口：0x08054CD0开始的364字节背景初始化，以及0x08054E3C开始的440字节力度条更新。后者有自己的保存寄存器／返回序列，并被两个BL直接调用；现声明为`FrisbeeCore::UpdatePowerGauge(i32)`，汇编定义为真实的`UpdatePowerGauge__11FrisbeeCorei`入口，两处调用改用该符号，无别名。此前局部标签调用在同一汇编块内本来就会随组装调整，不能将此次命名边界恢复宣称为修复了两个硬编码绝对地址。

`include/frisbee.hh`将原未知RAM中的+0x1D5A标为20×32个u16的`background_tilemap`，对应初始化解包目标、力度条两列访问及0x500字节DMA上传；+0x22DC标为一字节`power_gauge_endpoint_y`。剩余未知RAM不猜测命名；总尺寸、后续文本变量偏移及普通对象布局保持不变。没有新增源码／头文件、section或LDS条目，也没有改变JP文本存放顺序。海外条件分支保持原样。

六个真实.d消费者经外部候选和正式WSL `make -j16`对象核对：原276个函数块现为277个真实函数入口（是补明一个既有边界，并非新增440字节代码），68896字节完整.text及所有原重定位保持等价；仅两处已证实的局部BL变为独立函数符号重定位。所有分配段的字节、尺寸、对齐、重定位及COMMON与验证候选一致，原只读数据及元数据不变。

完整C++力度条尝试未采用：其203条解码指令仍有一条`mov r0,sp`在描述符构造参数求值中的调度位置不同。原生函数继续保留，未改编译器、预处理器、库、参数或输出凑字节。此批没有进行新的完整ROM构建；最后完整报告仍为1269，16处长度／填充差异没有减少，不宣称JP SHA-1已经匹配。

证据：frisbee-gauge-1285/native-boundary-check-1287.json、native-consumer-checks-1294.json及unaccepted-cpp-1292；frisbee-boundary-production-1295/applied.json、actual-checks-1296.json。未提交或推送。

## JP 排名与飞盘查找表回归真实使用模块（1258–1271）

gAnimalFestivalRankingScoreTable的200字节分数表只由AnimalFestivalOpponents::Generate读取，现直接定义在src/animal_festival_ranking.cc，同名include/animal_festival_ranking.hh声明。原animal_festival_ranking_score_data中其余六张表只由飞盘核心读取，现按原先物理顺序定义在src/frisbee.cc，声明统一归include/frisbee.hh，随后接现有data/text/jp/frisbee.cc文本include。没有新增源码、头文件、类型或独立文本文件；旧纯数据源码／头仅保留海外原定义，待JP通过后再同步。

六表包括gUnk_080FA246、gUnk_080FA264、gUnk_080FA2E8、gUnk_080FA36C、gAnimalFestivalRewardChanceWeights、gAnimalFestivalRewardArticleIds。未知轴含义继续保留gUnk名称。gUnk_080FA36C的两处真实读取均为索引乘二后LDRH，因此其最小对齐由ALIGN(1)恢复为ALIGN(2)，避免前方字节表变长后产生奇地址；所有现有分配段字节、尺寸和重定位不变。没有插入填充数组。

LDS只把原纯数据输入替换为src/animal_festival_ranking.o(.rodata)，后面仍为一次src/frisbee.o(.rodata)。79个实际.d依赖对象、1291个完整函数、357196字节原始.text及代码重定位保持一致；正式WSL make -j16对象的所有分配段与候选一致。两对象串接的1442字节当前只读内容及全部重定位保持一致。前方记分牌对象自然四字节对齐、实际463字节，旧四字节与新两字节输入对齐都补同一个一字节间隙，不靠固定地址或额外LDS对齐。

按1269新map扫描365个实际链接输入（包括实际libgcc调用跳板成员），合计7871685字节分配段；这七张表的原版／当前链接基址及每个内部地址均纳入原始地址候选筛选。九处已识别引用均为真实符号重定位，数据及GAS标明的代码常量池未发现固定地址候选。ARM/Thumb指令编码不当作数据指针扫描，因此不能将这项有界检查扩大为整个ROM已完成动态化，也没有证明所有立即数组合构造地址的情况。

1269完整JP编译与baserom直接对照：SHA-1 cf3d12c9dd5ca14e9ac2290abcdb599f6236e5e4，仍不匹配a655b2789aed14a6ac78c6075fbc533d3062dbe3。1270全局19744配对区间中18950完全一致、722引用变化已解释、16处长度／填充差异，重定位映射问题为0。原元数据0x080E4E0C–0x080E7A5C的11344字节在原绝对地址继续完全匹配。

本批是实际归属及半字访问对齐修正，没有补回排名表与飞盘表之间尚未恢复的运行库输出，也不把当前1442字节保持一致宣称为原版整个主题窗口通过。海外实现、工具链、库、Make参数和ROM输出均未作本批补丁；未提交或推送。滚动菜单构造的外部尝试仍未匹配，未应用到主源码。

证据：ranking-frisbee-1258/checks-1260.json及objects-before；ranking-frisbee-production-1262/applied.json、actual-checks-1264.json、halfword-alignment-1267.json、table-reference-audit-1263.json；full-build-1269/global-report.json。

## JP 资源缓存真实节点构造与返回 ABI（1224–1242）

src/resource_sprite_cache.cc 的 InsertResourceSpriteTileNode 和 InsertResourceSpritePaletteNode 已恢复为正常 C++。实际24字节树节点在+16处保存八字节条目；请求键可变，已链接节点键保持不可变。malloc/失败重试后对该真实条目进行placement复制构造，随后更新根／首／末链接、重平衡及计数。类型化节点链接通过共享基类字段的引用访问；迭代器的真实复制构造让编译器按原ABI使用r0返回存储。没有输出改写、寄存器绑定、地址补偿或手写运行库字符串。

11个实际.d依赖对象的249个完整函数、45928字节原始.text及全部代码重定位均与保存的原实现完全一致。正式Make对象的所有分配段字节、尺寸、对齐和重定位逐一与通过验证的候选一致；原具名数据和COMMON不变。LDS只增加一次src/resource_sprite_cache.o(.rodata)，放在资源渲染对象后面，使用真实节点构造自然产生的运行库只读输出；未增加固定地址、子section、Make参数或编译器／预处理器／库补丁。

1239通过WSL make -j16生成完整8 MiB JP ROM，SHA-1为cf3d12c9dd5ca14e9ac2290abcdb599f6236e5e4，仍不同于baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。全局19744个配对区间中18950完全一致、722引用变化已解释、16处长度／填充差异（此前17）。重定位映射问题为0；28处审计暂不支持的位置、61处等长区间外引用以及362/259个未配对名称仍未通过完整验收。原元数据0x080E4E0C–0x080E7A5C的11344字节在原绝对地址继续与baserom逐字节一致。

运行库文本统计为133/151，只记录机制结果，不据此安排副本。缓存后的独立滚动菜单输出仍未恢复，不能把整个cell-to-digits区间视为完成。滚动菜单构造函数的外部C++尝试仍有完整指令差异，已保存分析并排除，主源码继续保留原生汇编。海外实现未改，待JP通过后同步；尚未提交或推送。

证据：cache-nodes-1224/whole-consumer-proof-1234.json；cache-production-1238/applied.json、actual-checks-1241.json；full-build-1239/global-report.json；滚动菜单未接受尝试cache-nodes-1224/scroll-constructor-1236/decision.json。

## JP 基础地图／存档地图真实实现与数据归属（1206–1216）

原world_map.cc的基础地图38个函数与存档地图25个函数具有连续的真实实现边界。JP现在分别归入src/world_map.cc、include/world_map.hh，以及src/world_saved_map.cc、include/world_saved_map.hh。旧world_map公共头通过正常include继续提供完整API；GameSceneSavedMap的完整真实定义只移动一次，继承、虚方法ABI、字段、固定容量及检查均不变。其编译器元数据继续由原saved_map_tree.hh接口及实际实现所有者提供，没有将虚表硬移入新对象。基础地图直接引用实际Location接口并保留实际new[]及std::fill；存档地图保留真实完整GameStateSaveImage API，读取其农场和事件字段。海外原定义／代码本批保留。

五张视口寄存器／优先级／屏幕表和槽料坐标参数归入实际读取它们的基础地图源码、同名头；九字节屋型高半字节查找对象归入实际读取者LoadSavedWorldMapTiles所在的存档地图源码、同名头。查找对象保持原packed类型，只增加原ROM字节访问所需ALIGN(1)，不扩大数组或添加填充数据。field_render_resource_data仅保留四个真实被描述符引用的阻挡／清空属性和索引对象；它们的全零值不是匿名填充。

按完整实际.text顺序，scene_sprite的原普通只读输出在基础地图及存档地图之前。LDS使用其不变的真实C++对象输出，再列基础／存档地图的普通.rodata；没有创建用于输出字面量的对象或按数量生成副本。代码段只在基础地图后增加存档地图普通.text。没有固定地址、子section、Make专用参数、工具链或输出补丁。

28个实际.d依赖对象、681个完整函数完成候选及正式Make -j16验证，所有分配段字节、大小、对齐和重定位均与候选一致。另有一份farming_tutorial_lifetimes.d为陈旧缓存：源码已不存在、当前map和LDS均不选择该对象，因此记录后排除，不算实际消费者。原地图25908字节.text顺序保持，拆分后222个实际局部跳表项逐个验证仍指向相同指令；其余字节不变。只读验证没有修改对象或ROM。

完整原版数据窗口0x08106E98–0x08106F80共232字节（下表右端不含）通过真实原符号重定位后直接匹配baserom，每个具名对象都处于原窗口内位置。填充仅来自输入／下一对象的正常编译对齐。

| 原版JP区间 | 实际对象／内容 |
| --- | --- |
| 0x08106E98–0x08106EB7 | field_render_resource_data：31字节真实属性／索引 |
| 0x08106EB8–0x08106EC2 | scene_sprite：原C++运行库输出 |
| 0x08106EC4–0x08106F6C | world_map：168字节自然运行库输出、视口和参数表 |
| 0x08106F6C–0x08106F7F | world_saved_map：19字节自然运行库输出及九字节查找对象 |
| 0x08106F80 | 下一主题gMarriageCandidateCharacterIds起点 |

1213使用WSL make -j16生成完整8 MiB JP ROM，SHA-1 9da39e5ee71a362ae6c7f0d654734bac9baa28e0，仍不同于baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。1214全局19744配对区间中18949完全一致、722引用变化已解释、17长度／填充区间（此前20）；无新增未解释字节或重定位映射问题。28处不支持审计位置、61处等长区间外引用、362/259未配对名称及16处声明尺寸变化仍需独立验收。运行库文本统计132/151只作机制检查，不用计数决定归属。原元数据0x080E4E0C–0x080E7A5C全部11344字节在相同绝对地址仍与baserom原字节一致；1215完整1628字节钓鱼函数继续通过。尚未提交或推送，海外待JP通过后同步。

证据：world-map-1206/checks-1208.json、internal-targets-1208.json、whole-window-1208.json、dependency-review-1209.json、stale-dependencies-1209.json；world-map-production-1210/actual-checks-1211.json及whole-window-1211.json；full-build-1213/global-report.json；complete-fishing-reference-1215.json。

## JP 赛马奖品兑换真实功能单元（1191–1202）

赛马竞赛／购票与奖品兑换本来就有独立的核心、场景和数据。原horse_race.cc中物理连续的兑换核心5个完整汇编函数，以及已恢复的兑换场景构造、析构、Run三个C++函数，现整体归入src/horse_race_medal_exchange.cc；对应真实类型、外部声明及布局检查归include/horse_race_medal_exchange.hh。赛马头在JP通过正常include提供兼容的完整API，不保留重复类型。海外分支的原定义／代码本批不变。

兑换目录、物品ID表和兑换文本同归新模块；data/text/jp/horse_race_medal_exchange_1.cc为内嵌名称的原生目录，_2.cc为其后兑换提示和字符码，中间的真实u16物品ID表留在所属源码。旧horse_race_3.cc、_4.cc退休，赛马自己的_1.cc、_2.cc保留原顺序。所有符号、固定字段宽度、数组容量和文本内容不变。

真实的new HorseRaceMedalExchangeCore(image)继续由普通C++构造编译，因此本实现直接包含标准分配声明，不是为字面量添加假调用／类型。其自然运行库输出正好恢复购票控制表与兑换目录之间的原缺口。原horse_race_lifetimes.cc显式实现两份实际接口，仍是唯一编译器元数据所有者；六个原函数及虚表全部字节、指针和顺序不变。整段原始元数据0x080E4E0C–0x080E7A5C的11344字节在新ROM同一绝对地址仍与baserom完全一致。

7个实际.d相关对象合计294个完整函数通过候选及正式Make -j16核对，所有分配段与候选一致。原赛马／兑换共26608字节.text顺序保留；拆分编译单元后32个局部跳表项的段内加数正常改变，逐项验证新段基址加真实局部标签仍指向原相同指令，其余字节完全不变。这是只读重定位验证，没有修改任何编译输出或ROM。原0x080F9F5C–0x080FAA60完整2820字节数据窗口按真实原版符号重定位后直接匹配，所有具名对象保持原窗口内位置。

JP LDS只在原赛马后各增加一次普通src/horse_race_medal_exchange.o(.text)和(.rodata)，无固定地址或子项。Makefile、编译器、库、预处理器和生成器均未修改，未新增任何匹配专用规则。

1199完整JP构建生成8 MiB ROM，SHA-1 3b64c47813b13472d743b7fde0fe646fc4c6524b，尚不匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。1200全局19744配对区间为18946字节完全一致、722引用变化已解释、20长度／填充区间（此前21）。重定位映射问题与未解释字节区间为0；28处不支持审计位置、61处等长区间外引用、362/259未配对名称及16处声明尺寸变化仍未完成独立验收。1201完整1628字节钓鱼函数通过。运行库文本统计129/151只作检查，不能按数量补齐。尚未提交或推送；海外版在JP通过后再同步。

证据：prize-exchange-1191/checks-1195.json、jump-table-identity-1195.json、whole-window-1195.json、dependency-review-1196.json；prize-exchange-production-1197/actual-checks-1198.json及whole-window-1198.json；full-build-1199/global-report.json；complete-fishing-reference-1201.json。

## JP 记分牌名称、字符码和标题的真实归属（1177–1186）

原名gText_NameEntry_PresetAnimalNames的30×13字节名称行，以及gNewGameNameEntryUiCharacterCodes的40字节字符码区，JP的实际读取者均是FrisbeeScoreboard，不属于姓名输入。两个JP汇编操作数和实际数据定义分别使用gText_FrisbeeScoreboard_ContestantNames、gFrisbeeScoreboardCharacterCodes；保留一基ID减去完整行宽的原生索引，不是任意文本内部偏移。

三组相邻数据统一归入src/frisbee_scoreboard.cc、include/frisbee_scoreboard.hh和唯一文本片段data/text/jp/frisbee_scoreboard.cc，顺序是固定名称行、字符码、标题。名称行保持真实ALIGN(1)和13字节容量，字符码保留原20个u16槽位（13个有效码，余项为原零槽），没有调整容量来凑尺寸。实现直接引用其实际存档模型game_state.hh。由真实依赖自然产生的运行库文本位于名称行之前，未添加孤立<new>或手写bad_alloc。旧JP文本片段退休，旧源码／声明只留海外分支，JP LDS删除旧数据对象输入，保留记分牌一次普通.rodata。

全部7份实际.d依赖和邻接模块合计9个对象、338个完整函数通过外部候选和正式Make -j16两轮对象核对，分配段的字节、对齐、大小和重定位一致。两项真实数据改名之外，原函数代码与顺序、全部具名数据均保留。原版0x080F97DC–0x080F99AC完整464字节数据窗口（包含下一对象前1字节自然填充）按真实原版引用直接与baserom一致。

独立尝试的字体std::copy方案改变FormatFullWidthDecimal的实际机器码，已拒绝，未进入正式源码。编译器、库、文本工具、预处理器、Makefile均未改；不使用别名、固定地址、输出补丁或逐项子section。

1183完整JP构建生成8 MiB ROM，SHA-1 e484a8c2856806eb660b84f343dccae541b33c01，仍不同于baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。1184全局19744配对区间中18946完全一致、721引用变化已解释、21长度／填充区间；上轮为23。未解释字节区间及重定位映射问题均为0，但28处不支持审计位置、71处等长区间外引用、362/259未配对名称、16处声明尺寸变化仍须独立验收。1200项名称配对只用于确认真实身份，不能作为接受不同字节的规则。1185完整1628字节钓鱼函数仍通过。四版同步尚待JP通过后处理，未提交或推送。

证据：scoreboard-1177/checks-1179.json、whole-window-1179.json、dependency-review.json；scoreboard-production-1180/actual-checks-1181.json；full-build-1183/global-report.json；complete-fishing-reference-1185.json。

## JP 最后一组多余虚表前缀与完整公共API／类型声明分层（1158–1172）

NewGameMenu生命周期仍需实际删除拥有的完整GameStateSaveImage，不能用不完整类型delete、ABI辅助调用或假布局替换。单纯重复1089的工厂／生命周期分离仍会导入完整模型的无关容器操作；1137广泛移出操作则已证明会丢失大量正确输出。本批保留每一个普通公共头的原依赖和完整操作能力，另将真实类的完整声明维护为唯一可独立使用的类型定义。

JP的rucksack、money_account、farmer、game_state、new_game_menu公共头仍提供原有全部操作；对应_types.hh存放其唯一活动的真实完整类型和不依赖分配算法的定义。字段、继承、固定容量、所有权、对齐检查和类型名不变，没有新增占位或复制的布局类型。Rucksack构造复制、MoneyAccount的std::copy/fill/uninitialized_fill实现继续由公共头提供，所有既有消费者均不必改为某种特殊编译模式。存档拥有者仍在完整模型可见后执行原普通C++ delete。纯生命周期只需真实类型、析构和布局，不再解析不使用的容器操作。

原NewGameMenu的两个CreateScene工厂归入new_game_menu_factory.cc，保留完整操作API及实际控制器构造；三个隐式析构函数仍由编译器根据完整真实类型在new_game_menu_lifetimes.cc生成。两对象拼接后的全部原.text字节、函数顺序和重定位一致，未改为显式析构或汇编。原四张虚表60字节及其所有函数指针保留，12字节多余前缀自然消失。LDS仅在原生命周期.text前增加一次普通工厂.text输入，原.rodata行不变；新工厂沿用原生命周期的常规-fno-weak模式。

16对象初步验证扩大至全部94个实际.d消费者及相邻模块，共1529个完整函数。1165正式Make -j16再次对照不可变修改前输入及候选，所有分配段的内容、大小、对齐、重定位相同；所有普通公共API消费者的代码、数据及运行库输出均保持。其余语言保留原定义，待JP通过后统一同步；本批仅JP验证。

IndexedResourceProvider及四张NewGameMenu相关表组成0x080E4E68–0x080E4EB8完整80字节窗口，按真实原版符号重定位后直接匹配baserom。更进一步，1172直接在原绝对地址比较整段0x080E4E0C–0x080E7A5C：全部11344字节原始元数据与baserom完全一致，未使用归一化、引用遮罩或名字配对来接受字节，包含未命名区域。此结论只覆盖该元数据区间，不代表后续普通数据或全ROM已完成。

1167使用WSL make -j16生成完整JP ELF/map及8 MiB ROM，SHA-1 414dd97f8f1b11361a49f19497ce87992fbd1c1c，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。1168全局19744配对区间中18944完全一致、721引用变化已解释、23长度／填充区间（上轮24）。重定位映射问题和未解释字节区间为0，但28处不支持审计位置、362/259未配对名称及16处声明尺寸变化仍需独立验收。1169完整1628字节钓鱼函数继续通过。

已盘点的多余虚表前缀现为0；库文本统计由128降至127，是元数据中无关输出消失，不能按原版151份计数补齐。接下来处理其他运行库真实归属、五处对齐差额与镜像末尾累计差额，不再反复检查已逐字节通过的元数据区。编译器、预处理器、库、生成器及输出均未修改，没有假调用、别名、固定地址或人为GNU／子section。尚未提交或推送。

证据：menu-schema-1158/checks-1160.json、dependency-review-1161.json及whole-metadata-window-1162.json；menu-production-1164/actual-checks-1165.json与whole-metadata-window-1165.json；full-build-1167/global-report.json；complete-fishing-reference-1169.json；complete-metadata-prefix-1172.json。

## JP 控制器真实所有权接口与编译器附带对象分离（1137–1155）

先验证了广泛移动内联操作的候选：Rucksack复制、MoneyAccount填充／移动和脚本队列插入保持原操作，放入实际使用的实现单元。93对象、1530个完整函数均保持原码，但多处已经正确的普通只读区域丢失原运行库输出。因此该候选未推广，未通过额外new头、假调用或修改数据补救；原MoneyAccount、Rucksack全部API及实现保持不变。

正式方案只分离控制器真正需要的所有权接口与构造定义。GameStateSaveImageOwner的四字节完整类型在同名职责的game_state_owner.hh中唯一维护；普通delete的原内联实现仍在完整存档模型可见之后定义，未换成ABI辅助调用、模板假类型或不完整类型删除。GameSceneScriptController字段、布局和两种构造逻辑完全不变。构造定义放入自己的game_scene_controller_lifetimes.hh，由实际控制器实现、载入存档工厂及新存档工厂共享，保证工厂仍能进行原本的内联。

使用该生命周期接口的正常implementation pragma保留控制器原有两个独立构造入口。最初只移走原类implementation的版本丢失这两个入口，已保存未采用的证据；不能以工厂内联正确代替全部入口完整。原GameSceneScriptController实现仍包含11个函数，代码和顺序不变。新的game_scene_controller_tables.cc只从真实完整控制器类型生成16字节虚表，沿用既有纯表目标模式，不导入构造所需的完整存档操作。脚本队列的原placement-new插入定义归回唯一实际C++调用者GameScene，未修改插入、析构或边界语义。

73个实际.d消费者和相邻对象共1241个完整函数通过候选检查；1150真实Make -j16对象再对照不可变修改前输入与全部候选分配段。所有既有普通只读内容、函数、其他段及COMMON均保留，只有本来未链接的队列独立库副本随真实插入定义移动而消失。控制器正文仍自然产生实际依赖的库副本，但该无引用输出不再随元数据链接。JP LDS仅把一个普通.rodata输入改为真实table所有者，没有固定地址、GNU或子section；没有添加.text入口，因为纯表单元不含代码。

HardwareLinkBase、GameSceneScriptController、GameSceneState三个相邻真实虚表组成0x080E5028–0x080E5054完整44字节窗口。按原版真实符号重定位后直接与baserom一致，三个表各自边界、内容及相邻关系均通过；未用临时ROM修改进行验证。

1152使用WSL make -j16生成完整JP ELF/map及8 MiB ROM，SHA-1 24daf0234b48b7163674898f3fa4d943fe817a4e，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。1153全局19744配对区间中18235完全一致、1429引用变化已解释、24长度／填充区间（上轮25）。重定位映射问题与未解释字节区间为0，但28处不支持审计位置、362/259未配对名称及16处声明尺寸变化仍需独立验收。1154完整1628字节钓鱼函数继续通过。

实际库文本统计从129降至128，原因是元数据中多余的控制器前缀不再进入ROM，不是手工去重。仍有NewGameMenu生命周期一处多余元数据前缀；其余运行库归属、对齐余数及末尾累计差额继续处理。编译器、预处理器、库、生成器及输出均未修改。海外仍保持原代码和依赖；JP尚未通过整版SHA，不提交、不推送。

证据：layout-operations-1137/checks-1139.json及decision-1142.json；controller-api-1142/checks-1144.json、unassigned-inline-constructors-1145/、dependency-review-1146.json、whole-metadata-window-1147.json；controller-production-1149/actual-checks-1150.json与whole-metadata-window-1150.json；full-build-1152/global-report.json；complete-fishing-reference-1154.json。

## JP 赛马参赛者数据与实际调用方合并（1123–1134）

1123先总览上轮剩余26个非镜像末尾差异邻域，按真实map所选代码对象的重定位记录入向调用，而非只检查第一处差异或按bad_alloc数量分配。旧animal_festival模块中的随机范围、40行13字节名称及40行4字节数值均由赛马生成／名称显示／更新流程使用。PrepareHorseRaceEntries按40取余生成参赛者ID，HorseRaceTextVariables显示对应名字；未发现独立动物祭模块使用这些对象。旧符号名保留，不以未经充分分析的字段名替换未知含义。

JP把这一完整连续区间归回既有src/horse_race.cc及include/horse_race.hh，不新建源码模块。范围表位于真实实现依赖之前，参赛者名称及数值表在其后；原有账户与场景依赖、实际SubtractMoneyFromAccount调用及所有C++分配／析构仍保持。编译器自然输出从错误的后置前缀归回范围表与名称之间，不添加无用途库头或手写运行库文本。

参赛者名称现在为data/text/jp/horse_race_1.cc；原三段赛马文本按真实非文本断点顺延为_2、_3、_4。原JP animal_festival文本退休，旧模块仅保留海外原实现。JP LDS删除animal_festival.o(.rodata)，只保留一次horse_race.o(.rodata)。所有既有符号、数组容量、行宽、数据和指针重定位不变，没有使用别名或新增地址限制。

六对象局部验证扩大到十个真实.d消费者和相邻模块，共313个完整函数。1129正式Make -j16产物对照不可变修改前对象和候选，全部分配段的字节、大小、对齐、重定位均相同。0x080F9F5C–0x080FA280完整804字节与baserom直接一致，三个具名表的相对位置均匹配。该证据只覆盖参赛者区至首条购票文本，不包含后面票据控制表之后仍未解决的运行库归属缺口。

1131使用WSL make -j16生成完整JP ELF/map及8 MiB ROM。SHA-1为0c15862987ff15e51f260b1d5af61a9ed5ad00f1，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。1132全局19744配对区间中18226完全一致、1437引用变化已解释、25长度／填充区间（上轮27）。未解释字节区间和重定位映射问题为0；28处不支持审计位置、362/259未配对名称及16处声明尺寸变化仍未扩大验收。1133完整1628字节钓鱼函数继续通过。

本批库文本总数仍129，属于真实归属／输出顺序调整，不按原版151份计数补齐。编译器、预处理器、库、生成器、Make编译选项和ROM输出均未改。继续JP优先，未提交或推送。1122五处两字节邻域审查表明若干差额与前方缺失输出／绝对对齐余数耦合，不能靠改容量或额外补零独立修复。

证据：batch-owner-graph-1123.json；race-owner-1124/checks-1126.json和dependency-review-1127.json；race-production-1128/actual-checks-1129.json；full-build-1131/global-report.json；complete-fishing-reference-1133.json；alignment-review-1122.json。

## JP 场景状态接口、运行操作与加载／帮助文本归属（1102–1118）

先以真实依赖区分GameSceneState完整布局与运行操作。JP布局头保留全部字段、分配结构、Grow逻辑及ABI；原std::construct形式的PushBack与实际声音槽选择、实体位置更新一起归入已有game_scene_actions.hh。AnimalActor真实声音调用使用该接口；教学场景持有同一运行时声音池，也使用完整运行接口。World显式引用其实际使用的脚本请求类型。没有通过无用途的new头、类型或调用补齐运行库字面量。

最初的标量指针赋值简化虽通过小范围验证，扩大消费者后丢失三份已经正确的运行库输出，因此未推广；正式版本保留原std::construct语义。17个实际消费者及相邻模块共539个完整函数保持全部指令、池内容、重定位和顺序；动物与教学模块已有的只读输出均保留。场景状态的编译器虚表由完整原类定义的game_scene_state_tables.cc自然生成，仅沿用原状态对象的常规生成参数，不伪造类或虚表。

JP原help_menu中的七个连续字符串归入实际调用它们的game_scene_state实现，声明统一在同名头文件。data/text/jp/game_scene_state_1.cc保留加载失败提示，第二份文本在真实实现依赖之后include，运行库字面量由编译器自然生成于两段文本之间；_2.cc保留其余加载状态和四个帮助菜单标签。旧JP help_menu文本已移除，海外版本保持原组织。LDS只将原虚表位置交给普通state_tables.o(.rodata)，原帮助文本位置交给普通state.o(.rodata)，不添加子section、地址或填充。

212字节完整物理窗口已直接对照baserom：0x080EFDD0开始的状态文本／自然运行库输出共91字节，下一独立120字节闪色数组从原生未对齐地址0x080EFE2B开始，下一主题按自身对齐到0x080EFEA4。七条文本标签的相对位置和完整字节均正确；未将闪色数组强行四字节对齐。1113实际Make -j16产物对照不可变修改前对象和外部候选，全部17对象的分配段内容、大小、对齐和重定位一致。

1115以WSL make -j16生成完整JP ELF/map及8 MiB ROM。SHA-1 cad76281ff09f74c9ed4a1d70c07905dda194206，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。1116全局19744配对区间中18224完全一致、1437引用变化已解释、27长度／填充区间（上轮29）；未解释字节区间与重定位映射问题为0。28处不支持审计位置、362/259未配对名称及16处声明尺寸变化仍需单独验收，不能由局部验证推成完整动态编译已通过。1117完整1628字节钓鱼函数继续通过。

运行库文本总数仍129，属于从错误虚表前缀移回真实实现位置，不是按副本数量补齐。仍待解决两组虚表前缀、其他运行库生成／归属区间、五组对齐问题及镜像末尾累计差额。编译器、预处理器、库、生成器和链接后输出均未修改。继续JP优先；未提交、未推送，也未处理汉化。

证据：state-interface-1102/checks-1107.json、dependency-review-1111.json及scalar-store-candidate-1110/；state-production-1112/actual-checks-1113.json；full-build-1115/global-report.json；complete-fishing-reference-1117.json。

## JP 返回参数接口与菜单虚表依赖联合整理（1080–1099）

本批首先总览五组实际虚表编译单元的函数／表排列。返回场景的两个函数可以按真实工厂与编译器隐式析构自然分离；菜单过渡的66个函数则为33组工厂／隐式析构交错，不能照搬分组或手工拼表。保持已有高级语言实现，按实际类型和依赖修正两组问题。

GameSceneResumeRequest与GameSceneTownMapSelection是GameScene构造函数及返回过渡共享的真实API数据，JP定义从实现状态头归回game_scene.hh；全部字段、原始未初始化区域、枚举及布局检查不变。ReturnToGameScene工厂仍为原C++，编译器自然生成的隐式析构和16字节虚表由同头文件的game_scene_return_lifetimes.cc拥有。原80字节完整.text、所有重定位及函数顺序保持一致。LDS只续接普通.text并更换普通.rodata所属对象，没有恢复子section或GNU条目。新生命周期目标沿用原返回单元的-fno-weak模式，没有新匹配参数。

GameCubeLinkScene和TownMapTransition实现实际使用GameStateSaveImage存档类型，现直接包含game_state.hh，保留原先经返回接口间接获得的模型依赖及原只读输出。避免历史875那种仅轻量化头文件、随后丢失既有GameCube库输出的遗漏；未添加无用途的new头、调用或虚表。

菜单过渡接口的工厂创建GameCubeLinkScene，却包含了另一层UI协议实现头。JP改为引用真正创建的场景接口，并去掉没有placement-new、nothrow或handler用途的独立new头；普通分配运算符仍按语言机制声明。66个完整工厂／隐式析构函数及全部528字节虚表、顺序、函数指针重定位均不变，12字节多余库前缀自然消失。

初步内联UI核心分配候选虽然通过七对象检查，扩大到.d消费者后暴露纯协议生命周期单元新增入口／库文本，因此完整退回该候选，最终未修改UI核心所有者。另一标题工厂拆分虽保持五函数原码，但生命周期仍有真实库依赖，未解决问题，因此未推广或增加对应源码文件。保留失败证据，不能把局部通过计为整版完成。

1092联合候选覆盖32个实际对象、1072个完整函数。正式推广后1094用真实Make -j16重编全部消费者，逐一对照不可变修改前对象及候选；所有分配段的字节、大小、对齐和重定位均与候选一致。32对象包含新增生命周期，函数总量不因拆文件增加。除两组明确去掉的前缀外，其余只读数据、代码、其他段和COMMON全部保持。修改限定于四个接口头、四份对应实现／生命周期源码、常规Make目标归属及JP LDS；编译器、库、预处理器、生成器和ROM输出都没有补丁。

1096以WSL make -j16生成完整JP ELF/map/8 MiB ROM，SHA-1 fd009c8755fbe9a5d1615b52167d8dd1dbfb9cc8，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。1097全局19744配对区间中18222完全一致、1437引用变化已解释、29长度／填充区间（上轮31）。未解释字节区间与重定位映射问题为0，但28处不支持审计位置、362/259未配对名称及16处声明尺寸变化仍未扩大验收。1098独立完整1628字节钓鱼函数通过。

两组修正消除了错误前缀，所以库文本统计由131降至129；原版151份不是按数量填补的目标。仍有三处虚表前缀需要真实字段类型与实现依赖分析：new_game_menu_lifetimes、game_scene_controller、game_scene_state。海外分支保持原有定义和规则，待JP通过后同步，尚未海外整版验收。布局记录已更新，未提交或推送。

证据：metadata-functions-1080.json；return-interface-1081/checks-1092.json及rejected-inline-ui-owner-1086/；menu-interface-1087/checks-1088.json；menu-factory-1089/checks-1090.json与decision-1091.json；metadata-production-1093/actual-checks-1094.json；full-build-1096/global-report.json；complete-fishing-reference-1098.json。

## JP 既有分配／场景工厂及辅助精灵输出入链（1068–1078）

对上一轮33个区间按共同机制总览后，先核对真实代码对象及完整相邻边界，再联合构建。本批只修改JP LDS，增加allocation_failure、intro_scene_factory、entity_auxiliary_sprites三条普通.rodata条目。八个实际输入对象的SHA-256及126个完整函数均保持不变，没有额外编译或制造库副本。

RetryMemoryAllocation真实使用std::new_handler和malloc；IntroNameEntryTransition与IntroMenuTransition真实分配对应场景，二者已有库输出和代码原先均已编译。现在将其普通.rodata与既有new运行库一起排列，SRAM签名0x080E7A5C至开场BG指针表0x080E7AA4之间72字节全部匹配原ROM，下一表无须固定地址或额外对齐条目。既有nothrow对象的四个零字节和位置保持不变；基线没有同名符号，未臆造历史名称或增加审计映射。相同未引用库字面量不能唯一证明历史源码文件／顺序，本项证明当前真实实现输出和完整字节边界。

EntityAuxiliarySprites的现有C++析构、资源准备和绘制管理三组具名资源；世界、场景及资源头文件对应真实成员和ABI。其既有输出在EntityActor屏幕偏移表之后链接，0x080F0B88–0x080F0C94共268字节（含原有偏移表）与原版完整一致，后续HarvestSprite错误文本没有已匹配前缀被覆盖。没有增加头文件、调用、类型、库文本、别名、地址补偿、填充、子section或输出修补。

1074以WSL make -j16生成完整JP ELF/map/8 MiB ROM。SHA-1 c33652cdf8e745bb72653b2dfd38f750f3cb2ec7，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。1075全局19744配对区间中18220完全一致、1437引用变化已解释、31长度／填充区间（上轮33）。没有未解释字节区间或重定位映射问题；28处不支持的审计位置、362/259未配对名称及16处声明尺寸变化仍保留，不能计为全ROM验收。1076独立钓鱼完整1628字节函数及本地默认文本通过。

同时总览21个上一轮未入链SDK-only对象的真实源代码、原版函数地址及分配表达式。未将它们按副本数量机械填入缺口。1077将五处多余前缀精确归到后续虚表所属输入：new_game_menu_lifetimes、game_scene_controller、game_scene_state、scene_menu_transitions、game_scene_return。原报告的区间owner是前一锚点，不能据此修改前一个对象。五组的实际前缀均为12字节，应从真实类型／实现依赖与编译单元划分解决，不能删字符串或退回GNU逐项链接。

原版自然库文本151份、当前131份仅为统计。代码、头文件、Makefile、参数、编译器、预处理器均未修改；文本来源亦未改变。JP优先，未提交或推送。证据：existing-owner-sources-1068.json；entity-owner-1069/checks-1069.json；startup-runtime-1070/checks-1070.json；runtime-owner-production-1072/plan.json；full-build-1074/global-report.json；complete-fishing-reference-1076.json；metadata-prefix-owners-1077.json。

## JP 菜单控件及童年开场归属联合验证（1056–1066）

本批先核对两段完整原版相邻边界，再合并进行一次JP整版验证。MainMenuWidget已有正常C++构造、分配及释放MainMenuData的实现；其既有自然库输出原先没有进入普通.rodata链接。现以单条src/main_menu_widget.o(.rodata)在菜单数据之后、字体之前链接。0x08118CF0–0x08118D00的16字节（含原有末尾指针及自然对齐）完整对应原版，后续字体没有被覆盖的既有前缀。相同未引用库字面量不能唯一证明历史源码文件名，本项只证明真实实现输出、完整边界及当前正常链接关系。

童年开场的实际读取者是intro_story_scene.cc：它直接读取10x2背景图指针表和28条对话文本。JP定义及声明归回该源码／同名头文件，文本由data/text/jp/intro_story_scene.cc在函数之后include，保留真实指针重定位。旧JP intro_scene_data文本已备份退役，旧数据单元及头文件的海外分支保留，等待JP完成后同步。LDS以src/intro_story_scene.o(.rodata)替换旧JP数据对象，现有自然库前缀、背景指针和正文按原版连续存放。0x080FAA60–0x080FB110共1712字节与所有具名对象边界完整一致，保留相邻FarmStatusScreen原有12字节前缀。

1059四个候选对象181个完整函数和42个具名对象载荷／指针不变，真实对象中的库副本数修改前后均为2，没有制造新字面量。1061按实际.d重编10个消费者，365个完整函数、29个移动对象的载荷与引用、其他数据段及COMMON均通过。没有修改Makefile、编译参数、编译器、预处理器或生成器，没有手写库字符串、假调用、别名、补偿偏移、固定地址、填充条目、GNU子项或输出补丁。

1063经WSL make -j16生成完整JP ELF/map/8 MiB ROM。SHA-1 bc6bd94fbf454c5d7b7b2a4cf15319476e45a714，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。1064全局19744配对区间中18226完全一致、1429引用变化已解释，33个长度／填充区间（此前35）；重定位映射问题为0，没有未解释字节区间。28处不支持的审计位置及362/259未配对名称仍保留，不将本报告扩大解释为所有边界已验收。1065独立完整1628字节钓鱼函数通过，未恢复重复默认文本。

原版自然库文本151份、当前128份仅为统计，不能据此推导唯一历史编译单元。剩余问题继续按共同机制分类，JP优先；未提交或推送，海外尚未验收。

证据：scene-owners-1056/checks-1056.json；story-owner-1057/checks-1059.json；scene-owner-production-1060/actual-checks-1061.json；full-build-1063/global-report.json；complete-fishing-reference-1065.json。

## JP 追悼消息及动物行为数据归回读取方（1039–1053）

本批以同一动物岛为单位处理两组归属，局部通过后才做一次联合整版。追悼消息的实际拼装者是game_scene.cc，JP十条消息及声明由animal_data移入同名game_scene文本和头文件；文本定义在真实实现依赖之前，已有的自然库输出随后生成。相邻的游戏错误/空值文本和剩余动物数据保留。1041四候选对象206函数不变，172字节前缀匹配原版；1043按.d重编27个实际消费者，864个完整函数及指针/数据通过。

同时，十组行为／计时与索引数组的读取者是animal_actor.cc。定义及声明归回该源码／同名头文件，两条相邻错误文本经同名区域文本include；剩余animal_data只有一份JP文本，取消原_1后缀，旧_1/_2文件已备份退役。海外分支及原有定义暂保留，待JP通过后同步，未改变数组的已知格式、步长或容量。未知含义仍沿用gUnk标签，不臆测命名。

1046五个候选对象保留310个完整函数与49个具名载荷。实际对象中的自然库输出数量修改前后均为三份，没有新增副本；已有Livestock和AnimalActor实现输出以普通.rodata链接。0x080EFF50–0x080F06CC的1916字节及所有具名边界完整匹配原版，并保留后续PlayerActor已有前缀。1048按.d重编17个消费者，679个完整函数、其他数据/段/COMMON不变。两组消费者有重叠，函数数不能相加作为独立总量。

追悼起点0x080EFEA4至后续玩家对象前缀0x080F06CC共2088字节自然衔接。源码没有手写库文本、额外库头、假调用、别名、地址补偿或输出补丁；LDS只增加所属对象的普通.rodata条目。没有修改Makefile、编译参数、编译器、预处理器或格式生成器。固定格式的数组不等于可任意扩缩，修改其容量仍需审查原生读取规则。

1050用WSL make -j16完成JP整版ELF/map/8 MiB ROM，SHA-1 ef657aad489aaf43a4fdac7a6b69a2cd11048ea9，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。1051全局19744配对区间中18225完全一致、1428引用变化已解释、35长度/填充区间（上轮37），未解释字节区间与变化引用仍为0。28处不支持审计位置及362/259未配对名称仍保留；1052独立1628字节钓鱼函数通过，未恢复重复默认文本。原版库字面量151份、当前126份，仅作统计，不以数量证明唯一历史归属。

当前JP文本来源更正另列TEXT_ROM_LAYOUT.md。尚未整版验收，不提交或推送，继续JP。证据：memorial-owner-1039/checks-1041.json；memorial-owner-production-1042/actual-checks-1043.json；animal-behavior-1044/checks-1046.json；animal-behavior-production-1047/actual-checks-1048.json；full-build-1050/global-report.json；complete-fishing-reference-1052.json。

## JP 环境／天气的真实渲染所有者输出（1032–1038）

环境与天气实现实际依赖世界状态记录、精灵提交缓冲、精灵效果及世界类。对应world_runtime、world_sprite_buffer、world_sprite_effects、game_world四个真实代码对象已自然生成运行库只读内容，此前未被链接。1032检查七个已选代码对象的170个完整函数和精确对象哈希；本批没有改动任何源码、头文件、类型、生成参数或工具。

JP LDS在环境数据之后按普通对象列出三个渲染实现的.rodata，保留天气对象已有前缀与运动表，再列世界类的.rodata。夜间权重尾部至文本变量首个标签的112字节完整匹配baserom 0x080F1164–0x080F11D4；所有具名边界相符，下一文本对象没有被已有前缀覆盖。只增加四个普通对象条目，没有地址、填充、逐符号或GNU子项。相同未引用库字符串仍不作为唯一历史文件顺序的证明。

1035用WSL make -j16生成JP整版ELF/map/8 MiB ROM，SHA-1 a052957170da6560e2e4e264f46b0b8a559e17bf，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。1036全局19744配对区间中18215完全一致、1436引用变化已解释、37长度/填充区间（上轮39），未解释字节区间与变化引用仍为0。28处不支持审计位置及362/259未配对名称仍保留；1037独立1628字节钓鱼函数通过。库字面量原版151份、当前123份，仅作统计。

尚未整版验收，不提交或推送，继续JP。证据：world-owners-1032/validated-1032.json；world-owner-production-1033/plan.json；full-build-1035/global-report.json；complete-fishing-reference-1037.json。

## JP 日历读取方与保存数据实现归属（1022–1031）

日历季节、空值、星期标签的实际读取方是calendar.cc，此前定义仍在game_state文本中。JP三组标签及声明现归回calendar.cc/calendar.hh，继续经同名区域文本include；错误/空值游戏文本仍由game_state维护，在真实实现依赖之前定义，随后自然输出库内容及晴天日期数组。没有恢复手写bad_alloc，也没有增加任何为了输出字节而存在的头文件或调用。

日历、玩家记录、金额记录、保存数据和复制实现的五个真实对象按正常.rodata顺序连接。本批实际对象中的自然库输出总数修改前后均为五份，差别是四个原来未进入ROM的对象输出现在归入这一连续区域，而非新造副本。1024六对象候选保留116个完整函数、13个具名载荷及重定位；从原有日历前缀到HelpMenu首个对象的136字节完整匹配baserom 0x080EFD48–0x080EFDD0。源头与旧保存对象前缀一致，后续菜单没有已有前缀，不覆盖相邻对象。

1025正式修改两个头文件、两个源码、两份JP文本及JP LDS。1026按真实.d重编75个消费者，1305个完整函数、顺序、重定位、其他段、COMMON和所有具名数据保持；6个移动定义的归属变化独立核对通过。区域文本仍由正常通配/include流程识别，不修改Makefile、编译参数、编译器或预处理器。海外标签及源码分支保留。

1028使用WSL make -j16完成JP整版ELF/map/8 MiB ROM；SHA-1为05e101ee760a65cb83698ae17b1f928c2fce16c6，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。1029全局19744配对区间中18213完全一致、1436引用变化已解释、39长度/填充区间（上轮42）。未解释字节区间与变化引用仍为0；28处不支持审计位置及362/259未配对名称仍保留。1030独立1628字节钓鱼函数核对通过。原版自然库字面量151份、当前119份，数量仅供统计。

所有LDS改动仍为普通对象.rodata，不增加地址、填充或逐符号子项。相同未引用字面量不足以还原唯一历史文件顺序；这里验证的是有真实实现和依赖的正常模块组织及完整ROM字节。尚未整版验收，不提交或推送，继续JP。

证据：save-calendar-1022/checks-1024.json；save-calendar-production-1025/actual-checks-1026.json；full-build-1028/global-report.json；complete-fishing-reference-1030.json。

## JP 启动资源所有权批次与相邻边界联合验证（1001–1021）

1008先总览上轮43个区间：37项涉及自然运行库内容数量及对齐，5项是其他布局/对齐，末尾1项吸收累计位移。按真实map筛选，40个已链接代码对象还存在未选入ROM的独立运行库只读输出；另9个陈旧/未选代码对象排除，不按构建目录中的.o文件直接计数。清单是归属审计，不是按数量安放常量的许可。

1002–1005两个声明候选保留了7个函数。姓名流程单独34字节看似匹配，但1015联合检查证明其末尾会与后续身份模块已有的库前缀重叠10字节；该候选已完整撤回，未进入整版。普通new表达式本身具有隐式全局分配声明，并非每处都必须引入new头文件。硬件管理器单独的匿名库输出也不按数量随意插入，而纳入下面真实启动模块组的完整验证。

1009–1014成组检查资源池与硬件初始化。ObjPalettePool、HardwareContext、HardwareManagerOwner及HardwareBlendController均已有真实C++ new，恢复标准分配声明。HardwareContext类表由独立的正常C++类定义所有者输出12字节；HardwareBlend类所有者输出16字节类表及原有末尾内联构造函数。最初仅输出表的混色类方案漏掉构造函数，已拒绝；最终由编译器自然生成该函数，未改成汇编或复制实现。

12个候选与正式对象共128个完整函数全部保持指令、真实重定位和顺序。两主体与类所有者拼接后的整个.text（包括函数间对齐）亦与修改前一致；类表内容/重定位、其他段及COMMON保持。六个原有资源/田地对象的库输出与四个恢复声明的真实对象现在各以普通.rodata链接一次。顺序按资源池及其存储实现、硬件上下文/管理器/混色、田地初始化组织，128字节的“键盘No文本至下一字段数据”整体逐字节匹配baserom 0x080E80E4–0x080E8164，其中120字节为此次恢复的自然库输出及对象对齐。前一个对象确实止于No文本，后一个对象无既有前缀，不覆盖相邻内容。

这些相同且未被引用的库字面量不能唯一反推出历史源码文件名或其相互顺序；本批采用的是有真实代码依赖、正常编译输出的模块组织，不宣称恢复了原始map。源码没有手工库字符串、假调用、占位类型或别名。LDS仍是普通对象的.text/.rodata，各只列一次，没有地址、填充、逐符号或GNU子项。只新增两个必要的类所有者，并沿用正常C++类生成参数；不修改编译器、预处理器、格式生成器或链接后输出。

1017使用WSL make -j16完成JP整版ELF/map/8 MiB ROM；SHA-1为9e3771befcf59436b4cec85c7ff137738c6cc91a，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。1018全局19744配对区间中18210完全一致、1436引用变化已解释、42长度/填充区间（上轮43）。未解释字节区间与变化引用仍为0，28处不支持审计位置及362/259未配对名称仍保留。此次一次修复了十个自然库输出所在的大区间，不等于仅修复一个对象。1019独立核对完整1628字节钓鱼函数仍通过。原版库字面量151份、当前115份，数量仅作统计，不作单独归属依据。

海外源码分支保留，完整海外验证待JP通过后同步。整版尚未验收，不提交或推送。后续继续按全局区间及真实所有权批量处理，并对每个候选检查相邻已选对象，不能再用孤立载荷匹配证明新增库副本正确。

证据：early-allocations-1001.json；layout-mechanisms-1008.json；allocation-declarations-1002/rejected-adjacent-overlap-1015.json；startup-owners-1009/checks-1011.json；startup-owner-production-1013/actual-checks-1014.json；full-build-1017/global-report.json；complete-fishing-reference-1019.json。

## JP 动物选择类型布局及 UI 实际分配声明（989–1000）

按同类入口批量检查动物选择与UI。发现FestivalAnimalSelectionCore此前的C++声明仍按海外版0x4178字节布局，JP Native实际只分配0x3BF8字节。JP构造与析构共同确认：两组计数记录位于0x3920/0x3A24，资源句柄从0x3B30开始，行tile/palette从0x3B50/0x3BA0开始，音乐和末字段位于0x3BF0/0x3BF4。因而只修正JP真实未知存储区边界及已有尺寸/偏移检查；海外定义保留，不以加减地址或假分配长度补偿。

为该已有真实类型声明原Native构造入口，保持同一调用ABI。JP外层场景构造函数恢复为core(new FestivalAnimalSelectionCore(next,image,kind))，保留原位置与完整Native核心函数。自然分配依赖及其数据形成1012字节完整块，匹配baserom 0x080FB224。

UI原有行与payload构造函数已经使用真实C++ new；补齐标准分配声明后，其原有数字文本前的52字节前缀及后续68字节布局表/资源记录分别匹配原ROM，全部8个具名对象及指针的内容保持一致。两部分之间仍缺原版另一编译单元的12字节运行库内容，本批不伪造这一缺口，不把UI整体计作完成。

992隔离候选保留74个完整函数。993正式修改一个头文件与两个源码，994重编.d关联的7个实际对象，336个完整函数的指令、重定位、顺序及其他具名数据、其他段、COMMON均保持一致。没有改LDS、Makefile、编译参数、编译器、预处理器、格式生成器或编译后输出。

997使用WSL make -j16完成JP整版ELF/map/8 MiB ROM；SHA-1为734a839575b0a0cfc5db6a9856c5f17cd7234a29，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。998全局19744配对区间中18209完全一致、1436引用变化已解释、43长度/填充区间（上轮45）。未解释字节区间与变化引用仍为0；28处不支持审计位置及362/259未配对名称仍在。999独立1628字节钓鱼函数验证继续通过。库字面量数量原版151、当前105，仅作统计。仍未整版验收，不提交或推送，先继续JP。

证据：allocation-layout-989/validated-992.json；allocation-layout-production-993/actual-checks-994.json；full-build-997/global-report.json；complete-fishing-reference-999.json。

## JP 实际分配入口批量恢复及工作人员字段对齐（977–988）

本批一起处理农场状态、记录画面和工作人员名单。前两个模块将原Native场景构造函数原位恢复为真实C++的core(new Core(...))与continuation初始化；已有准确类型和布局，不新增占位类型、包装或别名。工作人员场景已有真实C++分配，仅补齐其标准分配声明。三个模块各自自然生成库字面量，未恢复手写bad_alloc。

初次候选验证拒绝工作人员数据：生成器将已经按四字节扩足的文本字段显式标成一字节对齐，恢复真实库依赖后第一条文本提前两字节。单独加强存储类型的对齐不能覆盖生成器的显式一字节请求，该探针未进入源码。最终只将工作人员格式生成器的这一条字段输出规则改为四字节对齐；字段内容、容量推导、共享指针和显示顺序不变。该规则不检查特定标签、地址或字符串，也不处理编译后输出。原始失败和隔离验证均保存在977目录。

981候选与983正式对象核对：三个对象的52个完整函数（包括构造函数常量池）、顺序、真实重定位、其他段及COMMON保持一致。275、408、1372字节的三块完整只读内容（含自然库字面量和文本指针）分别匹配baserom 0x080FB110、0x080FB758、0x080FB92C。正式改动仅三个游戏源码及一条格式生成规则；不改头文件、LDS、Makefile、编译参数、编译器或fomt-preproc。

985使用WSL make -j16完成JP ELF/map/8 MiB ROM。SHA-1为e4371caf9e650502352d23fdd17c742fb8a32313，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。986全局19744配对区间中18207完全一致、1436引用变化已解释、45长度/填充区间（上轮47），未解释字节区间与变化引用仍为0；28处不支持审计位置、362/259未配对名称仍保留。三个完整模块通过不等于整版通过；工作人员前面的独立滚动菜单缺口尚未解决，因此布局区间减少2而非3。

987独立核对完整1628字节钓鱼函数与其默认文本仍通过。自然库字面量数量原版151、当前103，数量只作统计，不能代替真实来源证明。海外游戏源码分支保留，工作人员对齐规则海外验证待JP完成后同步。没有修改名称对应表、审计掩码、ROM输出或链接布局；整版尚未验收，不提交或推送。

证据：scene-allocation-977/validated-981.json、diagnosis-984.json；scene-allocation-production-982/actual-checks-983.json；full-build-985/global-report.json；complete-fishing-reference-987.json。

## JP 资源精灵构造与自然分配库依赖（961–976）

先检查菜单过渡类整体生成：其33组工厂函数和隐式析构函数在文本段交错，不能拆成两个大组。962–964真实对象探针确认，单独输出表而保留原表会产生33个强符号重复；该方案没有进入源码，没有用链接器忽略重复、改弱符号或新增LDS子项。现有匹配的66个C++函数保持原样。

随后恢复资源精灵渲染器的实际分配语义。原Native构造函数先写真实虚表，分配40字节，再调用ConstructResourceSpriteRendererStorage。该存储已有准确字段和40字节布局，Native入口与其C++构造ABI相同。因此在resource_sprite_cache.hh为真实类型声明该构造入口；JP ResourceSpriteRenderer构造改为storage(new ResourceSpriteRendererStorage)，正常使用new头文件，不引入额外入口、包装、别名或假调用。海外Native分支及类型声明不变。

967–968确认三个候选对象的22个完整函数不变，C++构造函数含常量池的32字节精确等于原实现，缓存函数及虚表也未变化。真实分配依赖自然生成bad_alloc；它与原有六字节尺寸表组成连续16字节，完整匹配baserom 0x080FB8F0。尺寸表仍按字节自然排列，不额外强制四字节对齐；不用手工字符串或填充。969正式仅改两个文件；970重编实际.d涉及的10个对象，235个完整函数的指令、重定位和顺序、其他段与COMMON不变。

972使用WSL make -j16完成JP ELF/map/8 MiB ROM，SHA-1为74ebb82e215148efd573c7241e9e590e9aa8503d，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。973全局19744配对区间中18205完全一致、1436引用变化已解释、47长度/填充区间，未解释字节区间和变化引用仍为0。未修改1198条既有名称对应、审计掩码或ROM。974独立验证完整1628字节钓鱼函数及本地默认文本仍通过。

本批没有修改LDS、Makefile、编译参数、编译器或预处理器。自然库文本数量为原版151、当前100；数量不作为归属证明。尚有47个布局区间、28处审计器不支持位置和未配对名称，整版仍未验收，不提交或推送。976已从真实分配调用与当前只读输出筛出16个对象，其中10个有构造入口候选；后续必须先证明真实类型、C++依赖及原始数据位置，不能对名单统一添加new头。

证据：menu-interface-962/probe-checks-963.json和partial-964.log（未应用）；renderer-constructor-965/validated-968.json；renderer-production-969/actual-checks-970.json；full-build-972/global-report.json；complete-fishing-reference-974.json；allocating-no-library-976.json。

## JP 主场景接口、虚表与无调用文本（945–958）

本批从全部49个剩余长度区间出发，处理早段GameScene元数据衔接。GameScene本身只存储GameSceneState指针，公开方法使用指针、引用或已有Mary常量类型；其接口不需要完整状态和返回场景实现。JP的game_scene.hh因此保留场景基础接口、常量及真实类型前置声明。没有改写GameSceneState、GameStateSaveImage或ReturnToGameScene的定义，没有重做曾导致GameCube库输出缺失的返回记录全局迁移。

调用者所需完整类型按真实使用补齐：动物及世界代码读取音乐池，教学场景实际嵌入状态所有权与音乐池，姓名/背包/小游戏代码访问存档字段，玩家构建脚本请求，场景工厂和返回逻辑使用具体控制器或返回类型。鸡祭场景确实执行new，明确包含new。不是为了字面量数量添加无用依赖；这些改变在候选及实际构建中逐个核对。

game_scene_tables.cc通过同一真实类声明及原有强虚表生成参数自然输出16字节表，完整指针与baserom 0x080E52A4一致，无函数副本。GameScene的171个原函数仍留在实现对象内；JP LDS仅将原game_scene.o(.rodata)替换为game_scene_tables.o(.rodata)，没有加地址、GNU子项或逐符号选择。Make为新表对象沿用既有类表所有者参数；原实现参数不变。

同时纠正一项旧归属：GameScene::GetCaughtFish只转发PlayerActor返回的指针，不构造或读取FishingCatchResult字段。完整扫描实际对象的可执行段重定位，证实game_scene.o中gText_Fishing_NoCatch没有代码入向引用；这是fishing.hh顺带产生的无调用本地副本，不能因为同一头文件被包含就保留。JP去掉该处不必要的完整fishing.hh，使用真实类型前置声明；fishing.o里被SelectFishingCatch调用的默认文本保持。没有移动或复制这份多余文本来填ROM。

951验证候选25对象、829个完整函数，除预期表归属及无调用副本外所有数据、指令重定位、顺序、非只读段及COMMON不变。952正式应用17文件；953正常Make通道复核全部对象，与候选及原函数一致。实现对象仍由真实new依赖自然输出10字节库文本，其原版后段归属尚未查明，目前没有凭数量选一个缺口放入；这一边界仍是未完成项。

955使用WSL make -j16完成新JP整版ELF/map/8 MiB ROM，SHA-1为01d1df25200d705348fb0aab9e94b73272f2670f，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。956全局19744配对区间：18205完全一致、1435引用变化已解释、48长度/填充区间；剩余字节差异区间和未解释已变化引用均为0。仍有28处审计器不支持、362个基线名和259个当前名未配对，不能据此宣称全ROM完成。

既有名称证据未修改。移除GameScene无调用副本后，gText_Fishing_NoCatch在实际ROM只有一个有效对象，历史217轮已记录的gText_RandomItem_NotAvailable对应关系自动由歧义变为唯一，名称配对从1197变1198。这使之前全局未识别的最后一条引用正常解释，并非新增跳过规则。957独立由原始相邻数组和实际对象重定位重建地址，核对SelectFishingCatch全部1628字节仍匹配，没有依赖全局未解释列表是否为空。

当前自然库字面量原版151份、链接结果99份；数量只说明后续归属仍未完成，不能作为补字符串的理由。原始不同字节5849032受全局位置移动影响，不代表函数退步。未改编译器、预处理器或ROM输出，未重编海外整版、未提交或推送。下一批按48个布局区间继续核查真实代码/数据编译单元和库输出顺序。

证据：game-scene-interface-945/validated-951.json及local-data-949.json；game-scene-production-952/actual-checks-953.json；full-build-955/global-report.json；complete-fishing-reference-957.json。

## JP 环境精灵半字坐标类型对齐（935–944）

先总览930报告的50个剩余长度区间及实际输入对象。六个早段元数据衔接中的库前缀并不一定属于区间名称对应的对象，935已逐项记录前后输入归属，不能按区间owner直接删字符串或抽表。另有少量两字节差异，必须区分真实类型布局与前面缺口造成的累计对齐变化。

在环境精灵数据中，WorldAmbientSpawnPosition确实是连续两个i16坐标，Native读取为半字。源码虽给变量ALIGN(2)，旧C++的聚合类型仍使实际输出按四字节对齐，坐标表从对象内12开始；ROM所需为10。937–938验证JP将实际类型设为PACKED ALIGN(2)，不改记录大小、数值、库依赖或函数。整个608字节数据块（自然库字面量、坐标、正弦表和昼夜权重）精确匹配baserom 0x080F0F18，四个具名对象载荷与引用不变、17个完整函数不变。没有新增零数组、填充宏或工具补正。

939仅修改include/world_ambient_sprites.hh的JP类型约束，海外类型不变。按实际.d重编全部79个依赖对象；940核对1426个完整函数、指令重定位和顺序、其他分配段及COMMON全部不变，只有环境精灵只读块从610变608字节，其余对象只读数据一致。库字面量数量保持原版151、当前100。

941用WSL make -j16完成JP整版链接并生成8 MiB ROM，SHA-1为065e64dc6283411ecdfffe743772fad115dc2b3b，尚未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。942全局19743配对区间中：18203完全一致，1434引用变化已解释，49长度/填充区间、1剩余字节区间。相比本次重启前912的52个长度区间，两批修复累计消除3个。未新增名称映射或字节掩码；原始不同字节5800476不能作反编译比例。

943在新产物下重验SelectFishingCatch完整1628字节及本地文本引用，仍全部与baserom一致；原全局工具的一条本地符号歧义继续显式保留。本批不改编译器、预处理器、Makefile、LDS或编译参数；未提交、未推送。下一批以全部49区间为依据分析真实编译单元及生成来源，不给其余两字节差异机械补零，也不把剩余区间数量当成函数数量。

证据：metadata-inputs-935.json；ambient-alignment-937/validated-938.json；ambient-production-939/actual-checks-940.json；full-build-941/global-report.json；complete-fishing-reference-943.json。

## JP 婚礼日期与标准字节查找归属（916–934）

从912全局结果继续，先在工作树外验证，再应用到真实构建。婚礼排除日期表唯一读取者为IsWeddingDateUnavailable，原调用将季节乘30加日期作为32位无符号键，保留r3中的无状态比较对象及栈中的距离类型参数，与现有旧标准库的五参数__lower_bound一致。JP恢复真实std::lower_bound调用，终点由数组元素数计算；原25字节表从field_render_runtime_data移到wedding_date。海外原表及调用暂保持。

byte_search.c改为byte_search.cc，JP在真实标准模板特化的C++声明下保留完整52字节Native实现，已有C接口使用同一实际入口；没有定义额外别名或跳转包装。通用模板直接高级语言编译的循环目前并不匹配原指令，未采用该候选，亦未为此修改编译器。婚礼判断已是正常C++，完整76字节与原版一致。两者实际标准库依赖自然生成字面量，未手写bad_alloc、添加假调用或仅为补字节而包含无关头文件。

927确认完整35字节婚礼数据（自然库输出及25字节排除表）对应baserom 0x08107034，表从0x0810703E开始；查找实现的10字节库输出对应0x08107058。928应用到主工作树；929按实际.d依赖重编四个对象，全部六个完整函数、相关重定位、非只读段和COMMON均保持，数据与候选一致。语言驱动改为C++还核对了US/EU/DE三个小型查找对象，原Native代码及数据未变；没有重编海外整版。普通JP LDS仅增加wedding_date.o(.rodata)和byte_search.o(.rodata)，没有固定地址、子段或输出修补。

930使用WSL make -j16成功生成完整JP ELF/map/8 MiB ROM，SHA-1为07e40626005738ffd8a85af61a3ecf688185aaeb，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。931全局报告为19743配对区间：18202完全相同、1434引用变化已解释、50长度/填充区间、1剩余字节区间。比912减少两个长度区间，没有添加名称配对或字节掩码；原版151份库字面量、当前100份。数量仅作旁证，不能据此任意添加库依赖。

932再次按实际本地符号核对SelectFishingCatch完整1628字节，全部符合baserom；全局工具仍保留原有一条局部符号歧义，未修改统计。933已汇总全部50个长度区间，后续按真实输入对象及生成来源分类处理，不能把每个区间当作独立函数错误。尚余六处早段元数据衔接及多处普通只读内容的归属/自然库输出问题，整版SHA未通过，不提交或推送。

证据：wedding-916/validated-927.json；wedding-production-928/actual-checks-929.json；full-build-930/global-report.json；complete-fishing-reference-932.json；remaining-cohorts-933.json。编译器、预处理器、Makefile和编译参数没有修改。

## JP 人物姓名与自然库输出顺序（905–915）

在901全局报告中，npc_collection既存在姓名前多余的库前缀，又缺少生日指针表后的同类自然输出。其自身npc_collection.hh只包含真实NPC布局、日期和姓名记录声明，不引入分配库；完整game_state.hh、npc_schedule.hh和algorithm是后续构造/实现的真实依赖。因此不增删库内容，而在JP源码中先定义全部姓名文本和生日表，再读取原有完整实现依赖，使自然生成的库字面量跟随表尾。海外原有包含与定义顺序保留，没有修改文本或新增类型、别名、假调用、无用头文件。

905–908先验证候选。909正式只改src/npc_collection.cc；910确认39个完整既有函数的指令、重定位和顺序不变，42个具名只读对象的载荷及指针保持，其他数据和COMMON不变。库字面量仍为一份，数量不变。911确认完整738字节（姓名、生日指针表及末尾自然库文本）匹配baserom 0x08103C1C。对象从740变为738字节是前置与末尾的对齐位置变化，物理模块衔接仍由普通对象对齐完成，未加填充对象、section或固定地址。

912使用WSL make -j16生成新的JP ELF/map/8 MiB ROM；SHA-1 fc215b0b9864314ec73e8f87c01d33460aa3b3f5仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。913先符号后字节：19743配对区间，18200 exact、1434已解释引用、52长度/填充区间、1剩余字节区间；1条全局工具未识别引用、28处审计器不支持。仍沿用1197项已有名称对应，363个基线名、261个当前名未配对，无新增掩码或配对。相对901，本次同时消除两个长度区间；原始不同字节5849522不是进度比例。

914在912新产物下重新验证最后那条fishing.o本地文本引用及整个SelectFishingCatch的1628字节，全部按真实引用匹配baserom，未修改源码、全局统计或产物。原始全局1条继续保留。原版151份bad_alloc、当前98份没有变化，证明本批通过真实源码组织恢复位置，而不是补数、手写或替换字符串。

静态核查同时保留了后续线索，但尚未应用：resource_sprite_renderer的6字节尺寸表实际由resource_sprite_cache.cc的DrawCachedResourceSprites读取，当前独立只读段为1字节对齐；不能贸然给同一不完整模块加分配库并以4字节段对齐硬套。婚礼排除日期数组仍在field_render_runtime_data.cc，而唯一实际读取者是wedding_date.cc，按season*30+day做无符号字节lower_bound；其当前原生调用固定使用JP25/海外27项。应继续从真实数据归属和可推导长度处理这组，若恢复标准C++算法，需要先验证与既有原生字节查找函数的真实ABI，不添加仅为制造库输出的头文件或假参数。npc_collection默认实际编译参数没有-fno-weak也能生成该库文本，不能将缺口简单归咎于这一个选项并全局改旗标。

证据：npc-order-905/resolved-flags.json、checks-907.json及data-checks-908.json；npc-order-production-909/actual-checks-910.json及actual-data-checks-911.json；full-build-912/global-report.json；complete-fishing-reference-914.json。本批未改头文件、Make、参数、LDS、编译器、预处理器或链接后输出，只验证JP；未提交、未推送，目标继续。

## JP 地图界面与容器实现依赖（894–904）

以889完整报告为依据，核实TownMapMarkers::PushBack的实际C++使用者是town_map.cc的AddTownMapMarker；JP界面头为声明/存储布局所需的是Scene、资源、硬件和Location类型，不需要完整GameScene实现。将既有三个内联容器方法原样移到town_map.cc并保留memory/algorithm真实依赖；JP头仅保留原类、字段、内联声明及轻量scene.hh，不再把整套GameScene与无关STL实现带入只生成表和原生生命周期的单位。海外头中的原定义及包含链保留。没有新增类、别名、假调用、源码单位或替换算法。

896先验证6个候选对象、265个现有函数；898按实际.d推广，仅改include/town_map.hh和src/town_map.cc。899重建4个正式依赖对象并确认191个完整函数的字节、重定位和顺序不变，普通具名数据、非只读数据与COMMON不变。地图主实现的真实存档/背包/STL依赖和原有普通只读数据保持；town_map_lifetimes的多余库前缀自然消失，两个具名虚表及回调保持。900确认其28字节完整匹配baserom 0x080E6FE4。没有修改Make、编译选项、LDS、文本、资源、编译器、预处理器或链接后输出。

901使用WSL make -j16完成JP完整链接，生成新的ELF/map/8 MiB ROM；SHA-1为9ae7cc6b95f813f785eff52a1ba9b201e3df395e，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。902全局先符号后字节：19743配对区间，18199 exact、1433已解释引用、54长度/填充区间、1剩余字节区间；1条全局工具未识别的变化引用及28处审计器不支持。仍为1197项既有名称配对，363个基线名及261个当前名未配对，没有为降低统计添加名称或掩码。原始不同字节5849560受全局布局移动影响，不作为完成比例。

903在901新布局下重新验证SelectFishingCatch整段1628字节：原文本对象0x08104994对应当前fishing.o本地文本0x081047D4，具名下一数组、文本及对齐区、函数内跳表和全部真实重定位均核对，完整函数匹配baserom。全局工具原始1条仍保留；这是对象本地符号身份尚未被全局审计器表达，不是新发现的指令错误。没有修改源码或构建产物来消除这项统计。

原版151份bad_alloc，当前98份；差值不代表应手写53份字符串或随意选择SDK-only对象链接。剩余工作重点转向原版正常只读数据之间库内容的真实代码/数据归属及语言依赖，而非仅继续剥离前部虚表前缀。结合剩余全局范围、实际数据读取者与C++依赖确定编译单元；尚未恢复必要语言机制的原生构造析构需要按证据处理。保留已拒绝的全局存档依赖删减及返回接口删减记录，不能机械减少正常C++生成内容。

证据：town-map-ui-894/checks-896.json及data-checks-897.json；town-map-production-898/actual-checks-899.json及actual-data-checks-900.json；full-build-901/global-report.json；complete-fishing-reference-903.json。本阶段只构建JP，海外未改有效实现；未提交、未推送。目标仍未完成。

## JP 片头／世界／地图元数据归属（881–893）

881以878完整产物重新总览58个长度/填充区间及实际预处理包含链。确认片头生命周期的库前缀来自具体新游戏菜单依赖；世界实现确实需要完整背包、存档与STL；地图已有独立正确虚表单位，另一个world_map.o仅有库字面量的只读段被错误插进虚表区。本批不再次删减真实存档依赖，也不把所有SDK-only对象按字符串数量重新塞入LDS。

片头新增intro_scene_factory.cc，保留两个真正创建菜单/姓名场景的C++工厂及其完整依赖；intro_scene_lifetimes.cc在JP仅包含自己的既有接口，自然生成两个转换析构、IntroSceneCore析构和原有三张虚表。三个析构仍是原有隐式生成。884/887证明完整.text按工厂、生命周期连接后，全部字节、重定位和原始函数顺序一致，未把匹配C++替换成汇编或显式空析构。片头主实现和普通启动数据未改动。

game_world.cc保留全部134个既有函数和真实依赖，由新增game_world_tables.cc仅包含完整既有接口，自然输出360字节虚表，不生成函数。world_map.cc及其63个函数、真实std::fill/分配逻辑、存档访问完全未改；其仅含bad_alloc的10字节只读对象没有重定位或对象内入向引用。LDS删除它在虚表区的不当链接位置，地图虚表仍由既有world_map_tables.cc、world_map_command_lifetimes.cc、saved_map_tree.cc和farming_tutorial_world_lifetimes.cc负责。实现单位的库内容仍正常生成，其后续物理归属未证明，不据此宣称整个运行库内容已恢复。

882–885为9个候选对象、221个函数核对；886推广后，887核对10个正式对象、222个既有函数，全部指令、引用、顺序、普通数据、非只读数据和COMMON保持。888对960字节完整虚表进行baserom对照：片头60字节@0x080E4E2C，世界360字节@0x080E5304；地图40字节@0x080E7714、命令16字节@0x080E773C、存档地图40字节@0x080E774C、教学世界444字节@0x080E7774组成连续540字节，直至0x080E7930，无未解释回调。所有既有符号按真实原版引用核对，没有新增全局名称配对、掩码、别名或补偿偏移。

正式只改6个文件：4个源码（含2个新单位）、Makefile及JP LDS。没有头文件、编译器、预处理器、文本或资源更改；沿用原-fno-weak/-fno-implement-inlines规则，仅列普通对象，不恢复GNU/子section、固定地址、填充或链接后修补。海外仍为原实现，本阶段未构建海外。

889使用WSL make -j16生成新的JP ELF/map/8 MiB ROM，SHA-1为207497c8bd3c3b416b925b985f9878c7f04e9111，尚未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。890全局先符号后字节：19743配对区间，18198 exact、1433已解释引用、55长度/填充区间、1剩余字节区间；1条变化引用未解释、28处审计器不支持。仍为1197项既有名称配对，363个基线名及261个当前名未配对。相对878，长度区间58→55、字节区间6→1、未解释引用7→1；原始不同字节5756856受整体布局移动影响，不作为进度比例。原版151份bad_alloc、当前99份，不能靠手写52份字符串或选择无依据的SDK对象补数。

891/892另行核实最后一条全局工具未识别的引用：SelectFishingCatch的0x080A3A10为R_ARM_ABS32，原目标0x08104994（原符号gText_RandomItem_NotAvailable），当前目标0x081047E0为fishing.o自己的本地gText_Fishing_NoCatch。该对象的5字节原文及其对齐区共8字节与baserom一致；随后具名gFishingCatchArticleIds的原版锚点为0x0810499C，明确了对象身份和物理关系，并非仅凭同内容猜测。按真实命名引用、该本地目标及保持不变的函数内跳表入口核对整个1628字节函数后，完整指令/常量池均匹配baserom，没有剩余差异。不改源码、编译器、编译结果或全局配对来消除统计；890原始全局报告仍保留1条，后续不要误把它当作新增指令错误。审计器需按对象区分重复本地符号，当前证据不等于整版SHA通过。

证据：world-intro-882/checks-884.json及data-checks-885.json；world-intro-production-886/actual-checks-887.json及actual-data-checks-888.json；full-build-889/global-report.json；remaining-reference-891.json及complete-fishing-reference-892.json。初次892核对尚未处理函数内本地跳表的记录保留在.partial.json；最终覆盖完整1628字节，不使用部分通过代替全部通过。布局/重定位/进度均更新，目标继续；未提交、未推送。

## JP 转换工厂与隐式生命周期归属（860–880）

重启后先确认WSL、multi-language工作树及857完整报告；860总览61个长度/填充区间，其中41个的大小差与库字面量数量变化吻合。这只用于分类，不用于按数量补字符串或选择SDK-only对象。

本批最终保留三组真实工厂/生命周期分工：new_game_name_entry_factory.cc负责实际创建存档控制器，既有new_game_name_entry_lifetimes.cc仅包含自身接口，自然生成新存档转换的隐式析构和两张既有虚表；scene_clock_transition.cc及town_map_transition.cc保留全部工厂实现和实际依赖，各自的同名_lifetimes.cc包含已有接口，自然生成隐式析构和虚表。没有新增类、别名、假调用或手写运行库字面量，未把已匹配C++改为汇编。海外原实现保持，新增单位在海外为空。

局部实验明确拒绝显式空析构：旧agbcp会为其增加虚表写入，改变原版指令。最终四个析构仍由编译器按原有隐式机制生成。867验证15个候选对象、292个函数；三组拆分后完整.text字节、全部重定位和函数顺序与拆分前一致，不仅比较函数长度。工厂仍保留真实具体场景和存档依赖及正常生成的库内容。

869按实际.d推广。最初同时尝试把GameSceneResumeRequest移入轻量返回接口并分离ReturnToGameScene生命周期；872完整报告发现它会让此前匹配的GameCube联机物理范围少一份库字面量。虽然Run只借用存档指针、普通代码能够编译，仍不足以证明原版编译单元归属。875撤回这一整项试验：game_scene_state.hh、game_scene_return.hh、game_scene_return.cc逐字节恢复869前的精确快照，移除新增返回生命周期单位，恢复联机原有SDK-only输出；没有添加无用<new>或其他假依赖补回字节。该失败试验及完整报告保留，后续不要重复删除这层依赖来凑早段布局。

最终只有8个正式文件变化：6个源码（含3个新单位）、Makefile及JP LDS；没有本批头文件改动。Make沿用原有-fno-weak，LDS在对应位置只列普通.text/.rodata对象，不增加子section、GNU条目、固定地址、别名或填充。876重建并核对32个正式依赖对象、850个现有函数，完整指令/引用/顺序、具名数据、非只读数据及COMMON均保留。877确认80字节虚表完整匹配baserom：新建存档32字节@0x080E4EB8，时钟16字节@0x080E5294，地图转换32字节@0x080E5054，回调均解析到已有原版符号；未增加全局名称配对或掩码。

878使用WSL make -j16完成最终JP整版链接，生成新的ELF/map/8 MiB ROM；compare仅SHA-1未通过。当前SHA-1为546bd296d2e9ed478009cdabac8f7ab9396dab2c，baserom为a655b2789aed14a6ac78c6075fbc533d3062dbe3。879先符号后字节审计：19743配对区间，18170 exact、1453已解释引用、58长度/填充区间、6剩余字节区间；7条变化引用未解释、28处审计器不支持。363个基线名及261个当前名未配对，仍沿用1197项已验证名称对应。原始不同字节5813093受全局位移影响，不能作为完成比例。

原版151份bad_alloc，当前102份；差值不是待手写49份字符串的任务。其他早段生命周期接口、实际实现库字面量的后续归属及原版十份连续库内容等仍待证明。保持此前800–807全局存档依赖删减方案及本次返回接口删减方案的拒绝记录，不因轻量声明可编译就删掉原版已匹配的真实附带内容。

证据：transition-tables-861/checks-867.json、data-checks-868.json；transition-production-869/plan.json、rejected-return-875/decision.json、actual-checks-876.json、actual-data-checks-877.json；full-build-878/global-report.json。861–868仅候选目录试验，最终状态以875恢复、876/877正式核对和878/879完整报告为准。本批未修改编译器、预处理器或链接后输出，未构建海外、未提交、未推送。目标仍在推进。

## JP 小游戏接口与独立 C++ 表归属（843–859）

将上一批共享UI依赖规则推广到鸡祭、照料动物、收获、浇水及对应流程接口。五个接口仅声明自己实际需要的场景、UI、资源和参数类型；需要读取完整存档并实例化小游戏核心的scene_minigames.cc直接包含真实实现依赖，三种精灵小游戏源码中的实际C++分配使用正常<new>接口。没有削弱存档/背包/资金记录的真实定义，没有新增类型、别名或假调用，海外保留原分支。

12个代表对象、406个函数验证后，847按实际.d重建14个正式对象。848核对430个函数、顺序、重定位、非只读数据及COMMON不变。五个生命周期单位的176字节虚表完整匹配原版：scene_minigames 64字节@0x080E76B8，动物照料28字节@0x080E7930，鸡祭28字节@0x080E794C，收获28字节@0x080E7968，浇水28字节@0x080E7984。只有这些接口不再解析无关完整实现所产生的库前缀自然消失，实际实现中的正常库生成保留。

进一步处理animal_actor.cc和scene_sprite.cc：函数实现确实需要完整动物/世界/队列依赖，但其独立虚表位于另一只读物理范围。使用两个仅包含既有接口的正常C++表归属单位animal_actor_tables.cc和scene_sprite_tables.cc；它们不生成函数，分别自然输出860和12字节虚表。原源码保留全部函数、真实依赖和自然生成的库字面量；没有将函数改成Native，也没有删除或手写运行库内容。JP LDS只将两条普通.rodata对象路径替换为真实表单位，没有子section、GNU项、固定地址或补偿填充。Make仅沿用对应实现原有-fno-weak及-fno-implement-inlines规则，未新增特殊编译行为。

851/855验证175个既有函数不变，IWRAM内容、其他非只读数据和COMMON不变；表载荷及全部重定位与原有定义相同，排除原先表前多出的库前缀后，872字节完整匹配原版0x080E56C4和0x080E7708。为避免依赖未确认的函数名，853单独核实三个原版表槽的真实回调：CanReceiveSheepMiraclePotion为40字节@0x08023F90，RespondToPush为92字节@0x080241FC，AnimalActor析构为52字节@0x080DBDDC。入口/Thumb状态与当前函数一致，完整函数直接匹配baserom；析构仅按其真实__vt_7AEntity重定位解释。没有向全局审计添加配对或掩码。

两批共18个互不重叠的正式对象、605个函数完成局部核对后，857只进行一次合并的JP完整构建，生成新ELF/map/8 MiB ROM。SHA-1 7ca862c9968297f129f2ddd7b6dc36f2d672d835，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。858先符号后字节：19743配对区间，18167 exact、1453已解释引用、61长度/填充、6剩余字节区间；7条变化引用未解释、28处审计器不支持。相对840的66/6/7，本轮长度区间降至61，其余两项不变。363个基线名、261个当前名未配对，仍为1197项已有名称对应，未靠扩展配对降低统计。原始不同字节5736979受全局布局移动影响，不作为完成比例。

原版151份bad_alloc、当前105份，差值不能等同于“再加入46份字符串”。本批两个完整实现仍自然生成自己的库只读内容，但其正确后续物理归属尚需继续证明，不能只按数量将SDK-only对象塞回LDS。剩余6个字节区间的7条引用也仍需按真实对象验证，不能因此改动已匹配的函数或使用补偿地址。

证据：minigame-ui-843/checks-845.json及data-checks-846.json，minigame-production-847/actual-checks-848.json及actual-vtable-data-848.json，actor-tables-849/checks-851.json、callback-checks-853.json及data-checks-852.json，actor-tables-production-854/actual-checks-855.json及actual-data-checks-856.json，full-build-857/global-report.json。本批未改编译器、预处理器或ROM输出；未构建海外、未提交或推送。继续以857完整报告为准，不重做已通过的数据范围或已拒绝的全局存档头依赖删减。

## JP 飞盘数据顺序与共享 UI 接口（828–842）

依据823完整报告，先总览7个剩余字节区间和9条未解释引用，确认均集中在既有符号引用与布局归属，而非看到第一个差异就改函数。随后选择有明确读取者和接口依赖证据的一组，只改7个既有游戏源码/头文件，没有新增源码单位、类型、别名、宏或构建规则。

飞盘本体先包含自己的完整轻量接口和普通文本，再包含实际分配FrisbeeCore所需的<new>，以正常源文件定义顺序让自然生成的库字面量排在文本之后。原先直接包含的完整GameScene/背包实现并非这些C++方法所需，JP不再引入；海外保留原分支。成绩页只借用GameStateSaveImage指针，其自身接口已提供全部资源/硬件类型，移除JP源码中不需要的game_scene.hh，没有补充假声明或调用。902字节飞盘数据匹配原版0x080F9BD4–0x080F9F5A，23字节成绩页文本匹配0x080F9994–0x080F99AB；原有20个函数保持不变。文本仍由同名源码include，未改文本或增加逐文本段。

GameSceneTalkWindowOwner仅持有并释放UiStateOwner，名称、字段、构造、析构和赋值方法均保持原样，JP定义移到既有ui_state.hh，海外原定义留在game_scene_state.hh。赛马和日历接口分别只引入实际UI类型或日期类型，不再为了这个共享所有者导入整套GameScene实现。日历源码直接包含其实际读取的完整game_state.hh，保留原有真实实现依赖；没有对存档、背包或资金记录重复执行已拒绝的800–807删减方案。

12个代表对象的330个函数通过后，838按实际.d使用WSL make -j16重建85个正式对象。839确认1656个函数的字节、重定位和顺序不变，非只读数据及COMMON不变，全部具名只读对象载荷及指针保持。赛马88字节虚表范围匹配原版0x080E6DA0，日历44字节虚表范围匹配0x080E768C。日历回调Lookup的原版身份复用761已经独立验证过的完整函数证据；本地范围审计解释真实重定位，没有修改全局名称配对、掩码或构建输出。日历/赛马生命周期中多出的库字面量因不再解析无关实现自然消失；实际源代码的合法STL依赖保留。

840完整生成JP ELF/map/8 MiB ROM，SHA-1 9fc82651fcff9b5b5c1c372863ea29fc8642b79f，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。841先符号再字节：19743配对区间，18162 exact、1453已解释引用、66长度/填充、6剩余字节区间；7条变化引用未解释、28处审计器不支持。相对823的70/7/9分别降至66/6/7。363个基线名、261个当前名未配对，沿用1197项已有名称对应，没有为降低计数增加配对或掩码。原始不同字节5764915受整体布局移动影响，不用作完成比例或反编译完成度。

证据：frisbee-829/checks-832.json、ui-checks-836.json及ui-data-checks-837.json；ui-owner-production-838/actual-checks-839.json、actual-frisbee-data-839.json、actual-vtable-data-839.json；full-build-840/global-report.json。本批没有修改编译器、预处理器、编译参数、Makefile或LDS，也没有手写运行库文本、链接后修补、固定地址或子section。仅JP，未构建海外、未提交或推送。

接续使用840报告，继续批量核实余下运行库内容的真实归属及7条未解释引用。纯函数/对象局部匹配不能扩大为整版地址相同；源文件虽然没有直接C++字段访问，也不代表其保留Native实现可以忽略真实类型/存档布局依赖。不能仅凭字面量数量选择SDK-only对象链接位置，不能重试已否定的全局存档头依赖删减。

## JP 新游戏编译单元与连续数据归属（800–827）

本批先验证“收缩存档头的模板实现依赖”候选：10个代表对象函数不变后，按实际.d扩大到112个对象、1833个函数，发现仍会删除至少50处原ROM实际存在的库字面量。因此800–807方案明确拒绝，4个文件从精确快照恢复，808重编译确认112个完整.o与调整前逐字节相同；没有把函数匹配误当作整块布局通过，也没有留下该项依赖删减。

实际采用809之后的新游戏组织：仅将共用图块缓冲/OAM类型归入new_game_ui.hh，身份页、键盘页和生日输入接口直接引用各自需要的UI类型，不再为这些声明引入整个菜单和存档实现。存档、背包、资金记录的原有真实依赖保持不变。身份页和名称输入的C++虚表分别由new_game_identity_lifetimes.cc、new_game_name_input_lifetimes.cc生成，均为零代码的真实表归属单位，使用项目既有-fno-weak方式，没有手工虚表、别名或SDK副本。

JP文本、行表和相关代码按实际读取者收回new_game_menu、new_game_name_entry、new_game_identity、new_game_name_input各自源码，外部声明在同名头文件。新游戏菜单的连续文本与6行标签表最终合入同一个new_game_menu.cc；三份文本片段为new_game_menu_1/2/3.cc，分别位于标签表前、表后、实际实现依赖之后。旧JP new_game_data_1/2.cc和无编号new_game_menu.cc片段删除；new_game_data.cc只保留原海外分支，JP不再单独链接其.rodata。普通LDS中每个实际主题只列一次.rodata，没有固定起点、子section、GNU项或补偿填充。共享键盘格式/菜单行类型仍在既有new_game_data.hh，JP外部对象声明已经归回实际所属头文件。

三个库字面量分别由菜单、身份页、名称输入的真实分配实现自然生成。名称输入单位先解析实际<new>依赖，再定义ALIGN(1)键盘数组，因此键盘在该单位内自然紧接10字节库文本，保持原版非字对齐起点；后面的13字节占位符仍有已验证的ALIGN(4)和格式检查。Error仍作为未证明可自动生成的普通保留字面量维护，不因名字或相邻bad_alloc就将它当作自动运行库内容。

815按实际.d重建54个对象，816核对1203个函数不变，1571字节数据和56字节虚表全部直接匹配baserom。819–822完成菜单同一单位合并，再重建52个依赖对象，1202个函数及所有其他数据保持不变。原版坐标0x080E7AC8–0x080E80EB的整个1571字节范围由四个普通.rodata对象自然组成：菜单714、流程前缀23、身份119、名称输入711字节，正常输入对齐补足对象间间隙。两组虚表各28字节分别匹配原版0x080E4ED8和0x080E4EF4。

823完整生成JP ELF/map/8 MiB ROM，SHA-1 52372a759a7eff441041c0f3c2c38866446a5108，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。菜单合并前817与合并后823的ROM完全相同；这是组织合并的等价性证据，基准验收始终直接使用baserom。824全局先符号后字节：19743配对区间，18158 exact、1452已解释引用、70长度/填充、7剩余字节区间；9条变化引用未解释、28处审计器不支持，363个基线名和261个当前名未配对。相对794的77/8/10，分别降至70/7/9。没有增加配对或掩码，数量是区间统计而非独立bug数。

局部范围匹配不代表整版已回到原址：823 map中新游戏菜单实际起点0x080E7BC0，身份/名称输入虚表实际起点0x080E4EFC/0x080E4F18，仍受前面未恢复的布局影响。未强行固定这些地址。826总览原版151份bad_alloc、当前115份，70个长度区间中50个变化量与12字节副本数量差相符；这只能分类，不能据此插入字符串、盲目链接SDK-only对象或去掉合法依赖。

证据：save-header-production-804/rejection-807.json与restored-808.json，newgame-809/checks-811.json及data-checks-813.json，newgame-production-815/actual-checks-816.json，menu-production-821/actual-checks-822.json及actual-data-822.json，full-build-823/global-report.json，remaining-layout-826。仅JP，未改编译器或预处理器，未构建海外，未提交或推送。继续用823全局报告批量核实剩余运行库来源/边界和9条未解释引用，不能再次尝试已拒绝的全局存档头依赖删减。

## JP 真实依赖与共用界面数据归属（781–796）

781先总览112个单位的645个具名数据对象：按已存在的真实重定位解释后，全部载荷与baserom相符；这仅证明已具名对象内容，不证明原始边界、编译单元归属或隐藏指针全部完成。782结合355个实际LOAD对象及50条入向符号引用，确定共用界面数据的真实读取者，再进行整组整理。

ObjPaletteCollection的JP接口只保留池、句柄及存储指针所需类型；实际分配实现直接包含存储头，避免将完整分配后端带入所有调用者。主菜单数据类型归入main_menu_data.hh，虚组件的真实C++虚表由main_menu_widget_lifetimes.cc生成。原common_ui的16个外部对象分别归入文本变量、教学脚本、主菜单数据和NPC日程模块。教学根模块原有回调及64字节虚表保持原样；只将原stack单位的真实Push方法与VM辅助数据合入farming_tutorial_script.cc。所有新引用均为普通符号，文本以同名片段include，海外分支保持原状。

790按实际.d依赖使用WSL make -j16重建114个对象。791核对1809个函数，除明确的Push所属单位调整外，代码、顺序、非只读数据和COMMON均保持。792–793逐对象核对数据及重定位：16个迁移对象保持载荷，Moneybags和空串取消指定数组容量，原填充由自然对齐保留；五个普通输入对象形成的252字节连续范围与baserom 0x080F11D4–0x080F12D0完全一致。另有7个单位移除无关库依赖产生的前缀；商店字形表为半字对齐，删除10字节库文本后还自然少2字节旧相位填充，其6个具名对象和全部指针重定位逐项不变。没有添加填充对象、假调用、无用途头文件或内容专用补丁。

794生成JP完整ELF/map/8 MiB ROM，SHA-1 f8f24f7d975e7375a0e061415c3c6f10c4b9cb65，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。795按原审计规则先符号后字节：19743配对区间，18151 exact、1451已解释引用、77长度/填充、8剩余字节区间；10条变化引用未解释、28处审计器不支持。长度区间由777报告的79降至77，不能当作77个独立bug。363个基线名、261个当前名未配对；未增加配对、掩码或别名。原始不同字节5790412受整体布局变化影响，不用作完成比例。本批未修改编译器、预处理器或海外LDS，也未做链接后修补。

证据保存在外部审计目录的data-objects-781、common-ui-782、collection-api-783、common-production-790及full-build-794/global-report.json。C盘满只中断了编译结束后的辅助脚本写入；完整新产物已保存I盘，全局审计随后从I盘完成。没有删除用户文件。继续按794全局报告批量核实剩余运行库生成来源及实际编译单元边界；JP尚未验收，不提交、不推送，不构建海外。

## JP 运行库归属总览、脚本查找实例与钓鱼完整入口（763–780）

以759完整报告的82个长度区间为总览，而非逐地址试改。763发现59个区间的长度变化恰与12字节bad_alloc副本数量变化相等；其余多为小幅边界相位变化，另有钓鱼代码和镜像末端区间。该统计只用于归类，不证明具体编译单元归属，也不能据此给每个位置补零或加ALIGN。原ROM151份bad_alloc、当时完整输出116份；数量差不等于可以机械增加35个头文件或数据副本。

764遍历完整map的实际LOAD对象，找到39个既有对象：它们的未被LDS选择的.rodata全部恰为自然生成的10字节bad_alloc，没有其他定义或资源。这解释了部分来源已经生成却未进入ROM的情况，但没有把39份全部盲目链接，也没有依照旧手工标签名字认定原始归属。证据留在unselected-rodata-764/inventory.json，后续需要结合实际代码/依赖/原始范围逐组恢复。

先完成一个来源明确的组织修正：ScriptVm的switch分支使用std::__lower_bound<JumpTableEnt>，该真实算法实例此前和ScriptEngine隐式生命周期共同放在script_engine_lifetimes.cc。后者因无关算法依赖产生了虚表前的运行库字面量。JP现在以src/script_jump_table_search.cc及同名include/script_jump_table_search.hh维护实际算法实例和8字节条目/比较器类型；ScriptEngine生命周期仍由其既有C++接口正常生成，算法依赖随真实实例移动。海外原定义仍保留原分支。

普通Make给这个显式模板实例单位使用既有同类的-fno-weak归属规则。JP LDS仅在原代码顺序列一次script_jump_table_search.o(.text)，在script_vm之后列一次该对象的.rodata，没有子section、GNU条目、固定地址或手工字符串。局部766和正式768验证：普通输入对齐后，算法60字节和隐式析构12字节及代码重定位完全保持；20字节ScriptEngine虚表匹配baserom 0x080E6C64，真正算法依赖自然生成的10字节字面量匹配0x080F9708。按实际.d共重建49个对象，其余1100个函数及数据/重定位/COMMON均不变。770完整JP输出SHA-1 f84d58f61c900559e9c3b067cc9920c2d6de1808；771全局长度82→80、字节8→7。没有改编译器或预处理器，没有手写库字面量。

钓鱼此前的共享全局默认文本方案已明确拒绝，因为它删除了GameScene原有的独立默认文本。772–775采用真实的逐编译单元默认对象：data/text/jp/fishing.cc中的无指定长度static char const gText_Fishing_NoCatch[]仍是普通UTF-8文本“なし”，由fishing.hh内的真实默认构造函数引用；每个包含该内联构造的单位保留自己的本地对象，而非共享extern数组。没有used属性、强制发射、汇编别名、显式补零、假调用或SDK副本。文本仍走普通转码通道。为支持这种头文件中的真实文本片段，Make现有通用片段发现同时扫描src与include，未添加特定文件规则；实测该文本被识别为片段，不产生独立对象。海外三个文本目录均没有新增fishing.cc，默认构造原文保持原分支。

在保留实际默认构造语义及两个独立默认对象的基础上，将未匹配的JP SelectFishingCatch从1564字节C++恢复为完整1628字节符号化Native（原版0x080A3984），旧C++继续保留海外分支和外部分析。该项不计为高级语言完成。所有分支、调用和常量池均使用真实标签；配置表的+2及7字节季节行偏移对应已定义结构的实际字段和数组维度，不是地区补偿。全部2030字节钓鱼.rodata与baserom连续载荷一致；GetFishingAttemptParameters的188字节现有Native保留匹配。两个实际依赖对象验证：只改变SelectFishingCatch，GameScene的171个函数和两对象所有数据及数据重定位不变；默认文本各5字节加自然对齐保持原位置和总空间，不恢复共享全局文本。本组没有改编译器、预处理器、编译参数或LDS。

777完成新JP整版ELF/map/8 MiB ROM，SHA-1 eb88f563500a90439fa3afdf20032071ad198b92，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。778先符号再字节：19743配对区间，18149 exact、1451已解释引用、79长度/填充、8未解释字节；10条变化引用未解释、28处审计器不支持，363个基线名和261个当前名未配对。当前多出的两个未配对名字是两个真实逐单位本地默认对象，不是新增运行时载荷；没有为压低统计添加原版符号、配对或掩码。恢复64字节代码后，大量后续代码原址与字节自然重合。最近报告中的最后一处已知代码长度差异已解决，但不能由此宣布全ROM边界、未配对函数或动态引用已经全部验收。8个全局字节区间含已局部验证的真实引用身份，不能当作8个指令bug。原始不同字节5716399受布局变化影响，不作为完成比例。

779使用完整777 map的355个LOAD对象，提取new_game_data的54个外部对象、64条已符号化入向重定位，并沿文本指针表追踪读取者。得到四组：32个对象由new_game_menu读取；3个身份前缀由new_game_name_entry读取；9个身份摘要对象由new_game_identity读取；9个键盘/名称输入对象由new_game_name_input读取。gCppRuntimeError_NewGameSave没有已符号化代码入向。该图只覆盖现有符号重定位，不证明原始字节里没有隐藏地址，也不能单凭一个未引用Error或相同SDK文本断定原编译单元。它为下一批真实类型/模块归属提供具体入口，避免只按相邻字符串数量拆分。

证据：remaining-layout-763、unselected-rodata-764、script-search-765/checks-766.json、script-search-production-767/actual-checks-768.json、full-build-770/global-report.json、fishing-private-default-772/checks-773.json、fishing-private-production-774/actual-checks-775.json、full-build-777/global-report.json、newgame-ownership-779/ownership.json。仅验证JP；未构建海外，未提交或推送。工具链未增加任何内容专用补正。

接续：使用777全局报告，继续批量处理剩余79个数据布局区间，优先根据真实读取者和类依赖梳理new-game等运行库来源；39个未选择的SDK-only对象与虚表前字面量、同一单位合并的多个原始副本需要分别证明归属，不能全部加入LDS或按数量机械拆文件。小幅对齐差异先检查缺失字面量导致的相位变化，不添加补偿ALIGN或手工零数组。SelectFishingCatch已完成完整Native与独立默认对象验证，不再重复此前共享全局文本试验。完整四版目标仍未完成。

## JP 四处代码差异、日历紧凑记录及真实引用核验（739–762）

按733全局差异区间批量展开实际入口。外部局部审计器原来将所有函数指针强行设为Thumb，错误地把ARM的SubmitWorldSpriteRecords从0x030004DC解释成0x030004DD。742改为保留ELF真实函数状态后，三份绘制函数均匹配，游戏源码保持原样。全局审计器564原本就使用真实符号值，没有该错误，因此本轮全局统计没有靠更换规则降低。

在既有两个源码文件内一次处理四个实际指令差异：SouthTownRoamingNpc2构造0x0803799C/96字节、SouthTownRoamingNpc1构造0x080379FC/92字节、EntityEventEffectController构造0x080385B4/264字节采用完整符号化Native，共452字节，外部调用和常量池使用真实符号，海外原C++保留。这三项不计为新增高级语言进度。有限的正常C++构造写法试编译仍不匹配，没有推广，也没有修改编译器。ShippingBasketEntity::IsFull在函数调用完成后再给布尔结果赋值，普通C++即可自然匹配原版0x08038EB0的24字节，继续保留C++。

正式WSL make -j16构建两个实际对象，748确认仅四个预期入口改变，同文件其余88个函数、全部非代码数据及数据重定位不变，没有新增或删除函数。749阶段完整生成JP ELF/map/ROM，SHA-1为412b89ed57429798f39f78a33faff52be31709f1；750全局字节区间13→10、长度区间83不变。

继续核查剩余引用时发现真实的日历表格式错误：原版BuildMonthGrid按2字节步长读取17组季节/日期，当前CalendarFestivalDate虽然只有两个u8成员，却被旧ARM结构布局填成4字节，导致表变成68字节、还产生一个错误的表前对齐字节。JP类型使用PACKED恢复实际存储格式，增加2字节格式约束；数组仍由初始化内容推导长度，未写固定17项容量。修正后34字节全部匹配baserom 0x0810448B。表前错误对齐自然消失，后续普通对象对齐自然补齐，总.rodata减少32字节，没有添加补偿字节或LDS地址。海外类型分支保持现状，待JP完成后再按证据同步。

755先验证代表对象全部10个函数不变，表前有效内容及表后全部数据保持不变；756按实际.d重建全部6个依赖对象，757确认共275个函数不变，其余5个对象的所有数据、重定位不变，日历对象等于已验证候选。没有改编译器、预处理器、编译参数、Makefile或LDS。

759完成本阶段JP完整构建，SHA-1为2f7f1b862e90d27c2f1c6f6d9ed06e8b9e233317，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。760先符号后字节：19743个配对区间中17041个exact、2556个已解释引用变化、82个长度/填充、8个未解释字节区间；10条变化引用未解释、28处审计器不支持，363个基线名和259个当前名未配对。全局沿用1197项有证据名称对应，本轮没有增加配对、掩码、别名或输出修补。原始不同字节6025906受全局位置变化影响，不作为完成比例。

761另外核实7张真实C++虚表共500字节的全部元数据与回调目标，及34字节日期表；ScriptVm的匿名Error由include/script_vm.hh中的正常C++返回表达式自然生成，含bad_alloc的整个18字节局部.rodata与原版对应内容一致，保留原始生成关系。此组区间跨多个对象实际覆盖47个完整入口、共7912字节，按验证过的真实引用地址及ELF ARM/Thumb状态逐字节均匹配。该外部身份核验没有在游戏源码添加地址别名，也没有虚构原版ELF符号；未将外部局部证明直接当作全局报告已清零。不能将剩余8个区间说成8个指令bug，也不能据此宣布全ROM已匹配。

本轮正式源码仅修改src/roaming_npc_actor.cc、src/world_prop_entities.cc、include/scene_calendar.hh，及三份进度/布局/引用记录。证据remaining-cpp-743/checks-744.json、remaining-native-745/checks-746.json、remaining-production-747/actual-checks-748.json、calendar-record-754/checks-755.json、calendar-record-production-756/actual-checks-757.json、remaining-references-752/{table-proof-761.json,complete-entry-checks-761.json}、full-build-749/global-report.json与full-build-759/global-report.json。仅构建JP，海外有效定义未改；未提交或推送。

接续重点：以759的82个长度/填充区间按真实编译单元和对象范围归类，区分运行库字面量归属、数据格式、自然对齐及尾部镜像差异；不要把锚点owner当作整个区间的唯一归属。SelectFishingCatch仍为原C++1564字节、原版1628字节，其每编译单元独立默认文本生成关系尚未解决，不恢复共享全局文本、手写SDK副本或无用途依赖来凑大小。此组47入口已通过局部引用身份核验，不重复替换已匹配函数。完整目标仍未完成。

## JP 跨对象边界、状态页工厂及滚动副本（719–735）

713剩余代码区间先按实际map和两份ELF逐项跨对象展开。全局差异区间的owner只是首个具名锚点，不能代表整个区间归属：resource_handle末尾后的短缺实际是intro_story_scene构造；animal_festival_selection之后是生日输入核心；GameCube析构之后是三组状态页工厂/析构；Cooking文本变量析构之后则是三份已匹配模板查找和日历查询。所有前导已匹配函数均保留，没有错误拆改首个owner。

两个构造函数对应的12字节虚表，通过原版构造存储位置、零元数据、当前真实类声明及完整析构回调交叉验证：IntroStorySceneCore析构48字节、NewGameBirthdayInputCore析构108字节均匹配。四个季节文本各3字节含终止符，4字节存储连续，通过原版switch目标及实际文本载荷验证。记录页构造的48字节现有Native也与工厂的实际调用目标一致。这些是外部分析器中的引用身份验证，不在源码增加地址别名，也没有修改全局审计配对或创造原版符号。

| 完整入口 | 原版地址 | 字节 | 当前实现 |
|---|---|---:|---|
| IntroStorySceneCore构造 | 0x0805EA90 | 248 | 完整符号化Native |
| NewGameBirthdayInputCore构造 | 0x0806D788 | 428 | 完整符号化Native |
| FarmMapScreenTransition::CreateScene | 0x080DBBE0 | 72 | 完整符号化Native |
| FarmMapScreenTransition析构 | 0x080DBC28 | 40 | 完整符号化Native |
| RecordsScreenTransition::CreateScene | 0x080DBC50 | 72 | 完整符号化Native |
| RecordsScreenTransition析构 | 0x080DBC98 | 40 | 完整符号化Native |
| FarmStatusScreenTransition::CreateScene | 0x080DBCC0 | 72 | 保留原本匹配C++ |
| FarmStatusScreenTransition析构 | 0x080DBD08 | 40 | 完整符号化Native |
| CalendarTextVariables::Lookup | 0x080E36D8 | 352 | 完整符号化Native |

八个新Native入口共1292字节，保留未匹配C++分析及海外实现，不计作新增高级语言进度。状态页六个入口从0x080DBBE0至0x080DBD30共336字节，普通源码顺序即原版物理顺序。对日历同类有符号switch作一次有限正常C++试编译，仍为328字节且不匹配，未推广；现有匹配的农场状态工厂在身份确认后明确保留C++，没有因为初期未配对而一并替换。

三份模板查找116、116、164字节共396字节全部匹配，继续使用原C++。ScrollBufferUploadCommand原有IsQueued成员产生了一份原版没有的12字节外部副本。所有已链接对象入向重定位扫描为零；唯一源码调用已内联。直接改写为if中的指针条件会改变原本匹配的上传函数，因此未推广该试验。将同一个布尔查询移为scroll_state.cc内的私有static inline函数，保留布尔返回语义和现有192字节调用方代码，去掉多余外部副本。没有改编译选项、插入填充或删掉被调用实现。

最终修改两个既有头文件和五个既有源文件：scene_calendar.hh、scroll_state.hh、intro_story_scene.cc、new_game_birthday_input.cc、status_screen_transitions.cc、scene_calendar_lifetimes.cc和scroll_state.cc。候选729验证后，正式WSL make -j16重建全部66个实际依赖对象；731确认仅预期八个函数改变、一个无引用副本移除，其余代码、所有数据及数据重定位、COMMON均不变。17个入口共2172字节全部匹配，其中新增Native1292字节、保留匹配C++784字节、保留现有Native96字节。所有虚表仍由实际C++类型正常生成，LDS未增加子项。

733完成本阶段唯一一次JP整版构建，生成新ELF/map/8 MiB ROM，SHA-1 32102b89d39ffb840c177072a16baeeb6fa78707，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。734先全符号再全字节：19743个配对区间中17039个exact、2552个已解释引用变化、83个长度/填充、13个字节差异；17条变化引用未解释、37处审计器不支持，363个基线名和259个当前名未配对。相对713消除5个长度和5个字节差异区间；没有新增审计配对、别名或掩码。区间不是独立bug，原始不同字节数量受全局位置变化影响，不作为完成比例。

证据remaining-boundaries-719/{overview.json,cross-owner-current-720.json}、boundary-native-721/{helper-checks-before.json,verified-bindings-723.json,scroll-upload-checks-726.json,old-native-planned-checks-728.json,candidate-checks-729.json}、boundary-production-730/{plan.json,removed-entry-incoming.json,actual-checks-731.json}、full-build-733/global-report.json。编译器、预处理器、Makefile、LDS均未修改；海外有效定义保留、未构建海外、未提交或推送。SelectFishingCatch的正常C++及其真实逐编译单元默认文本生成关系保留待后续；早段运行库字面量、其他数据归属和未解释引用仍需继续，完整目标未完成。

## JP 类型布局、地图／搜索完整函数批次（700–715）

根据693全局报告的32个代码差异区间，总览实际函数后区分真实指令差异、后续相邻对象和未解释的引用身份。对先前已验证的有符号控制码switch方式进行一次有限赛马查询试编译，仍未匹配，因此没有推广，也没有修改编译器。随后按完整边界处理九个尚未匹配的函数，保留其他已匹配C++。

赛马核心发现真实地区布局错误：JP场景原版分配0x11DC字节，构造/Run访问player_horse位于0x11BC，析构清理文本变量区位于0x11C0；原头文件却在JP也沿用海外0x14FC、0x14DC、0x14E0。只修正JP尾部未知存储范围和已有布局检查，未猜测未知字段含义。该修正使原有612字节HorseRaceCore C++析构直接匹配baserom，不需要Native替换或指令补丁。海外布局保留原样。

| 完整Native函数 | 原版起点 | 字节 |
|---|---|---:|
| FarmMapScreenScene构造 | 0x0806FE18 | 2076 |
| ReferencePageSceneCore::IsTopLineStarred | 0x0807AB98 | 68 |
| AddTownMapMarker | 0x08077E74 | 732 |
| GetFishingAttemptParameters | 0x080A38C8 | 188 |
| UpdateMoneyAccountRecordHistory | 0x0809A8A4 | 428 |
| GameSceneMenuCursorData::MoveDown | 0x080CD318 | 248 |
| std::find字节迭代器实例 | 0x080DBE30 | 116 |
| HorseRaceTextVariables::Lookup | 0x080E0C58 | 264 |
| SavedMapTree构造 | 0x080E3B94 | 60 |

九个Native入口共4180字节，使用实际调用、数组、资源和硬件符号。原生switch表的所有内部地址恢复为局部标签，保持Thumb状态和真实边界；不使用ROM地址常量、别名或链接后修补。未匹配C++分析保留在海外分支及外部记录，不计作新增高级语言进度。

赛马生命周期组另保留五个普通C++入口共964字节：核心析构612、文本变量析构32、奖品查询96、兑换核心析构192、奖品变量析构32。连同Native查询，该对象从0x080E0C58至0x080E1124的1228字节完整函数组及顺序全部匹配。只在原有horse_race.hh中维护真实区域布局及方法声明；没有增加头文件、模块或section。

钓鱼选择函数的1628字节Native候选虽然在自身对象中匹配，但其默认结果文本“なし”的归属不能单独合并：FishingCatchResult内联构造使fishing和game_scene两个编译单元各自然输出一份独立8字节文本对象。改为共同具名文本后，GameScene从36字节rodata变为28字节，移除了原有一份真实生成记录。实际依赖核验发现后，已恢复原头文件和生成关系，移除本批试建的JP文本文件；没有手写一份无引用文本补回。SelectFishingCatch仍保留原C++，此问题未完成。不能将这次普通默认文本的证据推广为所有Error、N/A或bad_alloc都同源。

本批最终只修改horse_race.hh及九个现有源文件。正式WSL make -j16重建全部14个实际依赖对象；711确认仅预期十个函数改变，其他代码、所有数据及数据重定位、COMMON定义和函数顺序均不变。Fishing头文件逐字节恢复本批之前状态，GameScene代码及36字节数据也恢复不变。14个核验入口共5144字节全部匹配，候选阶段的局部通过没有被扩大解释为全依赖通过。

713是本阶段唯一一次整版JP构建，产生新ELF/map/8 MiB ROM，SHA-1 3dfbc822462dffbf0a4b73bcbfebafe5605c36d0，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。714先总符号再总字节：19743个配对区间中16831个exact、2750个已解释引用变化、88个长度/填充、18个字节差异；21条变化引用未解释、37处审计器不支持，363个基线名和260个当前名未配对。相对693消除6个长度和4个字节差异区间；没有新增审计配对、别名或掩码。区间不是独立函数/bug，原始不同字节数受全局地址移动影响，不能作为完成比例。

证据control-lookup-700/{signed-switch-checks-before-701.json,regional-layout-evidence-701.json,layout-checks-702.json}、scalar-boundaries-702、scalar-native-703/{candidate-checks-706.json,rejected-shared-no-catch-710/reason.json}、scalar-production-707/{plan.json,game-scene-data-difference-709.json,actual-checks-711.json}、full-build-713/global-report.json。编译器、预处理器、Makefile、LDS不变；海外有效定义未改、未构建海外、未提交或推送。保留完整目标，后续继续处理引用身份、真实运行库归属、相邻边界和SelectFishingCatch，不宣称整ROM匹配或动态化完成。

## JP 小游戏生命周期完整边界与调用组（684–695）

承接681全局报告，按同类核心生命周期整组处理动物参赛选择、照料、鸡祭、收获和浇水，不按第一个不同字节逐项补正。先核对原版核心析构和相邻辅助入口的真实边界；已存在的四个C++辅助函数全部先直接对照baserom，并结合核心调用、实际成员偏移、11/9/12个独立tile句柄的正向构造/逆向析构确认身份，没有凭相同字节随意别名。

| 完整入口 | 原版地址 | 字节 | 当前实现 |
|---|---|---:|---|
| FestivalAnimalSelectionCore析构 | 0x080E15C8 | 388 | 完整符号化Native |
| HarvestSpriteAnimalCareCore析构 | 0x080E3CFC | 764 | 完整符号化Native |
| AnimalCareMinigameTileHandles析构 | 0x080E3FF8 | 224 | 保留普通C++成员清理 |
| ChickenFestivalMinigameCore析构 | 0x080E40D8 | 1040 | 完整符号化Native |
| HarvestSpriteHarvestingCore析构 | 0x080E44E8 | 484 | 完整符号化Native |
| HarvestingMinigameTileHandles析构 | 0x080E46CC | 188 | 保留普通C++成员清理 |
| HarvestSpriteWateringCore构造 | 0x080C07F8 | 1260 | 完整符号化Native |
| HarvestSpriteWateringCore析构 | 0x080E4788 | 688 | 完整符号化Native |
| WateringMinigameTileHandles构造 | 0x080E4A38 | 132 | 保留普通C++成员构造 |
| WateringMinigameTileHandles析构 | 0x080E4ABC | 244 | 保留普通C++成员清理 |

五个生命周期对象中，核心析构先出现，随后才是原版对应辅助入口；浇水组为核心析构、辅助构造、辅助析构。通过现有头文件中的真实声明和现有生命周期源文件中的普通C++空函数体恢复编译器的成员构造/清理，不增加文件或section。所有辅助函数内容保持既有匹配结果。JP显式声明核心析构并用完整Native定义，防止再生成未匹配的隐式副本。未匹配C++实现和类型分析保留在海外分支及外部记录，不计作新增高级语言进度。

浇水核心构造原来同样未匹配；将辅助构造改为真实独立入口后，单独保留原C++核心构造仍不匹配，因此没有机械推广这个局部结果。按完整调用组恢复1260字节Native核心构造，正常调用132字节C++辅助构造；资源、虚表、分配与硬件接口均使用既有真实符号。仅在JP提前一次导入既有汇编宏，海外仍在原处导入，不改工具或输出。

动物选择的普通持有者类型移出JP接口pragma范围，去掉76字节多余ScrollOwner独立副本。全部当前链接对象的入向重定位扫描未发现该副本的引用；没有删除被调用入口或补地址别名。其余数据、虚表及已匹配函数保留。

候选689先通过10个完整入口、5412字节核验，其中Native六个共4624字节、保留C++四个共788字节。随后修改现有五个头文件、五个生命周期源文件和一个浇水主源文件，以WSL make -j16重建全部16个真实依赖对象。691确认仅六个预期函数改变、一个无引用副本移除，其他代码、所有数据、数据重定位和COMMON定义均不变。普通局部.text绝对重定位在对象比较时按实际所属函数+偏移解释；没有修改任何编译输出或ROM字节。

693完成本阶段唯一一次JP整版构建，生成全新ELF/map/8 MiB ROM，SHA-1 2dda375add10bb018cbf83c419a97ef4c73804b1，仍不等于baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。694先总符号再总字节：19743个配对区间中16823个exact、2748个已解释引用变化、94个长度/填充、22个字节差异；24条变化引用未解释、44处审计器不支持，363个基线名与260个当前名未配对。相对681消除6个长度和1个字节差异区间；相对本次恢复前660合计消除8个长度和5个字节差异区间。未增加审计配对、别名、掩码或补丁。区间不是独立函数/bug，原始字节差数量受全局地址移动影响，不能作为进度比例。

证据minigame-boundaries-684、minigame-native-685/{cpp-helper-original-checks.json,candidate-checks-689.json,reference-map.json}、minigame-production-690/{plan.json,removed-entry-incoming.json,actual-checks-691.json}、full-build-693/global-report.json。所有实际修改保持JP范围，海外有效定义未变；编译器、预处理器、Makefile、LDS均未改，未构建海外、未做移址试验、未提交或推送。后续继续按最新全局分类处理真实代码、运行库归属和未解释引用，完整目标未完成。

## JP 范围析构与完整生命周期组（664–683）

先总览660报告的45个代码差异区间，区分真实指令差异、同一区间包含的后续对象，以及审计器尚不能解释的匿名常量/虚表引用；没有把区间数当作函数数，或将引用身份未解决误报为代码错误。本批按已确认完整边界处理脚本队列、记录列表、飞盘生命周期、VCount绑定和中断表交换入口。

脚本队列和记录页仅有已构造范围内的元素需要析构，未用容量不属于对象生命周期。JP记录页列表采用原有固定容量的原始存储，保留84字节大小、8字节条目步长和真实字段偏移；没有将ROM文本改为固定容量。两个范围使用从现有SGI stl_construct.h分离出的通用按值trait/value-type析构模板destroy_ptrs。它位于既有utility/container_algorithms.hh，不含游戏名、符号名、地址或指令识别规则；既有三参数STLport析构接口不变。没有为了匹配而引入额外分配器依赖、手写bad_alloc或修改编译器。脚本队列保持正常C++析构，未采用候选阶段的Native方案。

| 完整入口 | 原版地址 | 字节 | 当前实现 |
|---|---|---:|---|
| GameSceneScriptQueues析构 | 0x080D761C | 104 | C++，三个真实已构造范围 |
| FrisbeeTextVariables::Lookup | 0x080E092C | 96 | 保留匹配C++，正常源文件定义先于Core析构 |
| FrisbeeCore析构 | 0x080E098C | 684 | 完整符号化Native |
| FrisbeeTextVariables析构 | 0x080E0C38 | 32 | 保留自然生成C++ |
| RecordsScreenCore析构 | 0x080E18BC | 84 | C++，通用范围析构 |
| UiVCountBinding析构 | 0x080E4C10 | 76 | 完整符号化Native |
| ExchangeInterruptHandler | 0x080D07C4 | 16 | 完整符号化Native，真实RAM数组引用 |
| ExchangeInterruptNestingMask | 0x080D07D4 | 16 | 完整符号化Native，真实RAM数组引用 |

八个入口共1108字节直接匹配baserom，其中四个C++共316字节、四个Native共792字节。Native只替换尚未匹配的完整函数，不计入新增C++反编译进度；原C/C++分析保留在海外分支和外部候选记录。飞盘组的普通C++Lookup、Native Core析构、自然生成TextVariables析构按原物理次序连续排列，不靠section或额外LDS条目。所有Native调用、RAM指针和虚表均为实际符号；结构固定偏移仍是当前ABI限制，不表示类型可任意扩缩。

修改七个既有文件：include/records_screen.hh、include/utility/container_algorithms.hh、include/frisbee.hh、include/game_scene_script_queue.hh、src/frisbee_lifetimes.cc、src/ui_vcount.cc和src/interrupt_table.c。使用正式WSL make -j16重建全部114个实际依赖对象；只有预期六个函数改变，无新增或消失入口，其余代码、所有数据、非代码重定位和COMMON定义均不变。编译器、预处理器、Makefile、LDS不变，海外有效定义保留，未构建海外版。

681完成本阶段唯一一次JP整版构建，产生全新ELF/map/8 MiB ROM。SHA-1 c6d82532cece343ee6c14233490fb5d16df726e5，仍未匹配baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。682按全符号后全字节核查：19743个配对区间中16800个exact、2764个已解释引用变化、100个长度/填充、23个字节差异；25条变化引用未解释、91处审计器不支持，363个基线名和261个当前名未配对。相对660消除2个长度和4个字节差异区间，没有新增审计配对、别名、掩码或链接后修补。区间不是独立bug；全局地址移动导致原始不同字节数量变化，不能作为完成百分比。

证据remaining-code-overview-664、cleanup-native-670/{checks-672.json,records-rodata-675.json}、cleanup-production-678/{plan.json,actual-checks-679.json}、full-build-681/global-report.json。局部候选和正式全部依赖均分别核对。仍有运行库字面量真实归属、其他代码/对象边界及未解释引用需要继续处理；未提交、未推送，不宣称整ROM动态链接或SHA-1完成。

## JP 地图容器完整边界与内联副本（653–662）

先根据649全局报告总览new_game_data、common_ui和animal_data三个数据岛的对象、物理间隙及当前工程重定位调用者，再选择边界已确认的地图容器整组推进。数据岛分析是只读记录，不算源码修复：新游戏53个非指针载荷与原版相同，另有一张真实重定位指针表；通用UI也是一张指针表不能按未链接原始零值判断错误，动物数据31个具名载荷相同。该盘点未扫描或声称消除了所有潜在二进制硬编码指针。

新游戏的键盘表保持原生558字节固定行格式；原版从0x080E7E2E开始，恰好在0x080E805C的字边界结束。当前字符内容相同，后面的多余对齐与前面未恢复的库记录/布局有关，不能据此删掉必要对齐或改表宽。原版0x080E80EC–0x080E8164实际是十份连续的bad_alloc记录，每份含自然终止与对齐共12字节，不是普通零填充。真实生成来源与编译单元仍待确认，没有按字面量数量增建文件或手工补回。其他两个数据岛也继续按实际调用和生成关系处理，未宣称完成。

本批实际只修改include/town_map.hh和src/town_map_lifetimes.cc。地图标记容器的普通内联类型及方法定义，在JP中位于显式虚函数接口的pragma范围之前；所有声明仍在现有town_map.hh。JP显式声明TownMapUiCore析构入口，并保留完整符号化原生实现，防止同时重复生成隐式C++副本。海外的类型定义顺序与C++实现保留原样。没有新增头文件、源文件、section、编译选项或工具。

| 完整函数 | 原版起点 | 字节 | 当前实现与验收 |
|---|---|---:|---|
| EraseTownMapMarkerNodes | 0x080E2618 | 44 | 保留已有匹配C++ |
| InsertTownMapMarkerNode | 0x080E2644 | 208 | 完整Native，调用与内部跳转均符号化 |
| InsertTownMapMarkerCount | 0x080E2714 | 224 | 完整Native，保持结构返回ABI |
| InsertTownMapMarkerCountWithHint | 0x080E27F4 | 660 | 完整Native，不把未命名尾部误分为另一函数 |
| TownMapUiCore析构 | 0x080E2A88 | 176 | 完整Native，含真实容器清理和虚表引用 |

五个入口合计1312字节，位置连续至0x080E2B38；全部指令、相对顺序、调用和常量池引用直接匹配baserom。四个尚未匹配的C++实现/隐式生成分析继续保留在外语分支和外部记录，不算新增高级语言反编译进度。所有实际ROM引用均用既有malloc/free、树遍历与平衡入口、实际资源提供者虚表等真实符号，不使用地址别名、ROM起点补偿或编译后修补。Native中的结构偏移遵守现有真实布局及尺寸检查，不表示结构可在不更新Native的情况下任意扩缩。

清理四份独立内联副本：标记PushBack（264字节）、标记容器析构（52）、计数容器析构（64）和标记构造（32），共412字节。旧工程存在两条指向这些副本的已链接调用，均来自本批替换的TownMapUiCore析构；没有外部引用。原版完整析构在自身内部清理两个容器，不需要另加这两份独立入口。因此不能将它们误报为旧工程全局完全无引用。新的原生实现恢复了正确内联边界，既有C++擦除函数保留。

正式Make流程使用WSL make -j16重建全部4个实际依赖对象：game_scene、town_map、town_map_lifetimes、town_map_transition。除生命周期组的预期代码替换/副本清理外，其余三个对象的整段代码、数据和全部可分配重定位均不变；生命周期对象的其他数据及引用也不变。地图主模块13个真实函数保持原样。候选与正式对象分别验证，没有因一个局部样例通过就跳过调用方检查。

660完成本批唯一一次JP整版构建，生成新ELF/map/8 MiB ROM；SHA-1为f774403d2fb27caf322c9f5a98bfa308d1b94b01，仍不等于baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。661先全符号再全字节：19743个配对区间中16796个exact、2762个已解释引用变化、102个长度/填充、27个字节差异；27条变化引用未解释、97处审计器暂不支持，363个基线名和261个当前名未配对。本批消除4个长度差异区间，没有增加审计配对或掩码；字节差异区间27不变。区间不是独立bug，原始不同字节数受地址移动影响，不作为完成比例。

证据early-data-overview-653、new-game-ownership-654/early-tables.json、town-map-native-655/{native-functions.json,reference-map.json,candidate-checks-657.json}、town-map-production-658/{plan.json,removed-entry-incoming.json,actual-checks-659.json}、full-build-660/global-report.json、global-cohorts-663。编译器、预处理器、Makefile、LDS均未改，未进行移址试验，未构建或修改海外版本，未提交或推送。完整目标仍未完成，不能把这一段匹配扩大为整ROM或所有数据岛完成。

## JP UI 命令内联生成与完整函数边界（633–651）

依据629全局差异先总览script_vm、UI命令、游戏菜单和Town Map生命周期。此次实际推广只修改ui_text_commands.hh、ui_text_commands.cc和game_menu.cc；不改编译器、预处理器、Makefile、LDS或海外版本的有效源码。开发分支仍为multi-language，未提交、未推送。

UI命令头内的三组普通内联存储类型原先位于显式pragma interface/implementation范围内，导致命令实现额外输出17个未需要独立入口的辅助副本。最终将JP的普通内联类型放在同一头文件首次显式虚函数接口之前；原有虚函数及隐式析构仍由原实现正常生成。海外声明顺序保留原样，待JP验收后再移植。没有新增工具/头文件，没有将类型寄托于一个虚构的实现文件，也没有保留实验中的编译选项修改。

早期只改变接口归属会把这17个副本转移到UI主对象，未采用；强制取消内联、显式空析构等候选也会抑制所需方法或改变原机器码，未采用。经正式依赖验证，最终17个独立副本共424字节确实消失，没有转移到其他对象。实际内联行为和既有68个UI主对象函数保持不变。

DMA命令的C++指针范围/清理形式尚未逐字节匹配，保留完整72字节符号化Native函数，调用ExecuteBiosTransfers而非固定地址，内部控制流使用本地标签。C++分析保留在原外语分支及外部候选记录中；未以指令补丁或伪填充拼接C++输出。其余16个命令方法/隐式析构的C++输出共440字节继续保留且不变。整个命令输入.text共512字节，原版对应0x080E06E8–0x080E08E8，所有入口相对位置及全部重定位直接匹配baserom。

GameSceneMenuCursorData构造函数复用已有RefreshBounds内联实现，修正了原来边界刷新部分的寄存器输出；完整148字节C++函数匹配baserom，对应0x080CD1C0–0x080CD254。JP分支外保留原构造表达式。菜单MoveDown及该主题数据的其他差异不在本批解决范围，不能把这个构造函数通过扩大为整个菜单完成。

84个实际依赖对象使用正式Make流程、WSL make -j16复核。除这两个预期函数外，其余共同入口的机器码和代码重定位不变；未修改对象的整段.text也不变。所有对象的其他可分配段字节及数据重定位均不变，没有新增人工/GNU子段。命令的全部17个函数加菜单构造共18个完整入口、660字节与baserom匹配；这是本批核验范围，不是18个新反编译函数。

649完成本批唯一一次JP整版构建，获得新ELF/map/8 MiB ROM；SHA-1为c93ed47369b5ba19c9a17b56ac884a64f955ba67，仍不等于baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。650先全符号再全字节：19743个配对区间中16793个exact、2761个已解释引用变化、106个长度/填充、27个字节差异；27条变化引用未解释、97处审计器暂不支持，363个基线名和265个当前名未配对。相较629减少3个长度区间和2个字节区间；未增加审计配对，当前未配对名减少17对应删除的辅助副本。区间不是独立bug，原始不同字节数受整体地址移动影响，不用来计算完成比例。

脚本GetString的原版指令另已只读核实，当前逻辑一致；匿名Error地址的审计身份仍需单独梳理，不据此改动字符串索引条件或声称运行库来源已确认。小精灵缺失SDK12、AnimalData内部库前缀及此前未解决的其他全局问题继续保留为未完成。

证据：command-overview-633/checks.json、ui-scopes-646/checks-645.json、ui-production-640/{plan.json,actual-checks-641.json}、full-build-649/global-report.json、global-cohorts-652。候选中不正确的组织方式保留在外部分析记录；当前工程只使用最终声明顺序方案。完整目标仍未完成，下一批从652总览选择实际数据/编译单元共同原因，不重做本批已通过的命令入口，也不提前处理海外版本。

## JP 实体数据回归功能模块（606–632）

完成604所列七组连续功能数据的整块归属调整：49个旧Entity-UI对象归入现有player_actor、entity_actor、harvest_sprite_actor、npc_entity、roaming_npc_actor、world_prop_entities与wild_dog_actor。结构及外部声明迁入各自同名头；JP文本改为上述同名文件，每个功能只include一次。旧JP entity_ui_1…7与animal_data_3移除，Entity-UI源/头仅保留海外旧组织。没有新建源码模块或工具目录。

原先把无引用库记录当作上一数据组尾部的假设未采用。完整物理范围和2/4字节字段对齐共同证明这些内容须作为下一功能输入的前缀检查：玩家前缀包括原AnimalData末尾的既有Error记录；其后六个Error分别在实体动画、小精灵、NPC、游荡NPC、特效、野狗的表前。所有现有Error均仍为显式普通C字符串，来源未确证，不能宣称已自然生成或直接归为标准库。没有恢复手写bad_alloc；实际new/algorithm依赖正常生成库字面量。

为保持每个普通.rodata连续，原生玩家主ABI表及编译器表归入现有player_actor_lifetimes；小精灵表由harvest_sprite_actor_lifetimes拥有，场景道具表由world_prop_lifetimes拥有，野狗表由现有animal_actor_lifetimes拥有。定义用的pragma先于首次读取对应接口。生命周期不再为未使用的原始存储插入方法包含new，插入实现留在其实际实现源中；所需布局和析构保持不变。四个已有道具C++小方法改为所属源文件的普通定义，保留原机器码和ROM顺序。仅JP增加必要的普通目标编译选项，海外选项及LDS未改。

特效坐标记录经原版2字节地址和半字读取确认，使用packed记录配合现有ALIGN(2)，后面的字参数自然4字节对齐；没有伪造零数组、绝对地址或带相位依赖的填充。LDS中七个功能各一个普通.rodata，早段表也各归一次生命周期对象，不新增GNU/逐符号/人工子段。

三个真正分配对象的工厂恢复为普通C++：ScriptVisualEffectActor::CreateVisualController（24字节）、InnSecondFloorRoamingNpc::CreateVisualController（44字节）、WildDogActor::CreateVisualController（44字节）；完整函数及调用重定位直接匹配baserom。小精灵工厂的C++分支/寄存器形式尚不匹配，已恢复完整100字节原生函数，移除候选中的无用new，非匹配C++分析仅保存在外部。它的12字节库前缀仍未恢复，不手工补字节。

先按全体依赖编译候选，再推广至正式源码。64个实际工程对象make -j16通过；所有机器码和代码重定位与修改前一致，所有可分配段与已验证候选一致，没有新非普通段。外围只有教学玩家生命周期因真实依赖变轻去掉多余SDK12，其100字节表也匹配baserom。已有早段表整体匹配；七组普通数据从原版080F06CC到080F0F18共2124字节，当前生成2112字节，唯一缺口是小精灵前缀12。此前AnimalData内部差异仍独立保留，不宣称该整个上游岛完成。

| JP 普通输入 | 原版对应起点 | 当前字节 | 验收边界 |
|---|---|---:|---|
| player_actor | 080F06CC | 1192 | 完整匹配 |
| entity_actor | 080F0B74 | 276 | 完整匹配 |
| harvest_sprite_actor | 080F0C94 | 204 | 有效对象匹配；其前080F0C88的SDK12仍缺 |
| npc_entity | 080F0D60 | 36 | 完整匹配 |
| roaming_npc_actor | 080F0D84 | 296 | 完整匹配 |
| world_prop_entities | 080F0EAC | 80 | 完整匹配，含必要2/4字节布局 |
| wild_dog_actor | 080F0EFC | 28 | 完整匹配 |

这些是baserom中的对应位置与独立对象比较，不表示当前整体链接已全部回到原址。629完成新JP ELF/map/8 MiB ROM，SHA-1为3fceb90598846b11476a802beb93c15d0707442b，仍不等于baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3。630先全符号再全字节：19743个配对区间中16793个exact、2756个已解释引用变化、109个长度/填充、29个字节差异；27条变化引用未解释、98处审计器暂不支持，363个基线名和282个当前名未配对。相较600，本轮减少12个长度区间，未新增审计配对，29个字节区间不变；区间不是独立bug或工程百分比，原始不同字节数受地址移动影响不能作为进度比例。

证据entity-ownership-607/{data-checks-612.json,cpp-factories-625.json,consumer-report-623.json,harvest-native-status-621.json}、entity-production-626/{applied.json,actual-checks-628.json,data-checks-612.json}、full-build-629/global-report.json、global-cohorts-631。编译器和预处理器未改，未做移址试验，未构建海外版，没有提交或推送。完整目标仍未完成。

## JP 精灵公开类型与保存记录归属（590–602）

后续604已整块盘点entity_ui：它当前只有只读数据，没有函数。49个具名对象自身的有效载荷全部匹配baserom；检索全部已链接对象的重定位，归属指向player_actor、entity_actor、harvest_sprite_actor、npc_entity、roaming_npc_actor、world_prop_entities/world_prop_lifetimes与wild_dog_actor，共七组连续功能内容、八个现有调用方源码。六个夹在其中的Error标签没有实际入向引用；原版六个明确的12字节间隔均为自然bad_alloc，其他1/2/3字节间隔为已记录的自然对齐候选。不能据此机械创建六个字符串生成单元；应按上述实际功能归属、源码接口与编译器所有权一起恢复。Error的真实源码线索是既有script_vm.hh中AScriptEngine::GetString的失败返回，不是std::exception头的定义。当前未迁移这些数据、未修改该接口，600仍是最新冻结整版报告。详细逐对象/逐调用证据entity-ui-ownership-604/{data-owners.json,owner-groups.json,summary.json}。

环境行为中多出的SDK前缀来自真实但过宽的声明依赖：scene_sprite为一个20字节调色板索引值类型包含完整world_runtime，后者再包含私有调色板容器和memory/new；环境行为为三条16字节保存记录包含完整GameState。JP将GameScenePaletteIndices归入实际包含它的scene_sprite.hh，world_runtime使用该公开类型；GameStateActorRecord归入拥有这些记录的world_ambient_sprites.hh，GameState通过该接口存放三条记录。字段、构造逻辑、布局和全部尺寸检查未变。

环境行为实现保留实际使用的actor_movement与random接口，JP不再包含仅供旧恢复工厂C++或完整存档使用的接口；基础环境精灵实现保留其真实GameObject和new依赖。海外分支保留原有类型定义位置及原始include顺序，未构建海外版。仅修改四个既有头文件和两个既有源文件，没有新建源码模块、宏、工具或构建层，没有修改编译器、预处理器、Makefile、LDS或输出。

先验证六个实际候选对象，再盘点所有依赖。127条缓存依赖记录中，排除三条旧独立文本/失效记录后，有124个现存源码对象；全部在外部候选中编译，再推广后使用实际工程make -j16复核。124个正式对象的所有可分配段与候选一致，全部机器码及代码重定位与修改前一致。110个对象完全不变；14个对象仅移除由不必要声明依赖引入的SDK内容：9个普通只读对象去掉12字节前缀，另5个本来未链接只读段的对象不再生成10字节孤立前缀。

九个有具名数据的对象中，entity、entity_actor_lifetimes、harvest_sprite_actor、npc_actor_lifetimes、scene_sprite_group、scene_sprite_indexed、wild_dog_actor、world_ambient_behaviors的完整3564字节只读对象及749条指针均直接匹配baserom。环境行为的既有12字节缺口问题在本批闭合；14张表完整384字节。entity_ui仅确认原版gText_NotAvailable前没有该SDK前缀，内部多个物理边界仍有差异，未宣称其整块完成。

原虚表槽位及整函数比较另确认六个NPC/野狗入口身份（2156字节）、一张野狗虚表身份；仅进入外部审计关系，不创建源码别名、不更改程序。整版审计实际新增六组有效配对，因此统计改善不能全部视为源码修改。

600完成新JP ELF/map/8 MiB ROM，compare仍失败：SHA-1为3086758ef9396f7158c2c075b0f7d71df35eb87d，baserom为a655b2789aed14a6ac78c6075fbc533d3062dbe3。601先全符号再全字节报告：19743个配对区间中16783个exact、2754个已解释引用变化、121个长度/填充、29个字节差异区间；27条变化引用未解释、98处暂不受审计器支持，363个基线名和282个当前名未配对。相较586，长度区间减少9个；字节/引用统计还受已验证符号身份补充影响。这些是审计区间数，不是独立bug数或工程百分比。

证据sprite-interfaces-590/{consumer-report-595.json,data-checks-596.json,entry-checks-598.json}、sprite-production-597/{applied.json,actual-consumer-checks-599.json}、full-build-600/global-report.json、global-cohorts-603。上述帮助脚本和报告均在仓库外。没有提交或推送，整版SHA-1及全目标仍未完成。

## JP 环境精灵完整入口批次（580–588）

先依据576全局报告总览环境精灵、游荡NPC、世界道具、野狗和状态画面转换六个模块，没有把审计器尚未配对的名字直接当成源码错误。环境精灵行为模块的54个函数中，46个原已匹配；将剩余8个入口作为一批恢复成完整符号化Thumb汇编（2460字节），原C++分析仍在海外分支及外部接续证据中保留。没有增加别名、原址指针、逐函数LDS项或工具补丁；不把这8个入口计作高级语言完成。

实际工程对象make -j16后，54个完整函数共4820字节均与baserom匹配，范围080DC700–080DD9D4。内部跳转、常量池、跳表及全部外部函数/虚表引用使用真实符号。已有基础精灵构造184字节和七个原基线未单独标名的原生辅助入口也完成独立整函数核对；后者只用于本地审计入口证明，不伪造旧ELF符号。

只读数据没有宣称闭合：14张虚表384字节和66条指针逐项匹配，原版范围080E69A8–080E6B28；当前对象仍在这些表前多出12字节运行库内容。该对象的只读字节及重定位与本批修改前完全相同。预处理包含链已确认从world_ambient_sprites → entity → scene_sprite → world_runtime → 私有调色板集合存储 → memory/new引入。后续应按真实声明/实现依赖处理，不能删除匿名输出、手工补文字或改变LDS吞掉差异。

586阶段完整JP构建、链接及8 MiB ROM生成完成；SHA-1为e300caed4914c9271a0f20cf039a3afeff02525e，与baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3仍不一致。587先全符号再全字节报告：19737个配对区间中16776个exact、2745个已解释引用变化、130个长度/填充差异、30个字节差异；29条变化引用未解释、98处暂不受审计器支持，369个基线名与288个当前名未配对。相较576，本批减少7个长度区间和1个字节区间；这是区间统计，不是独立bug或项目百分比。

本批只改src/world_ambient_behaviors.cc。海外源码分支、头文件、编译器、预处理器、Makefile与LDS均未改。没有提交或推送；完整SHA-1尚未通过。证据entity-cohort-580、ambient-native-582/{native-entries.json,verified-reference-map.json,dependencies-584.json}、ambient-production-585/{applied.json,complete-checks-583.json}、full-build-586/global-report.json。

## JP cooking and return-scene ownership stage (569–579)

JP-only local probes were promoted to six production files, then eleven actual dependent objects passed normal WSL make -j16. Cooking keeps handle-only interfaces in its declaration header and includes the real save/palette/tile APIs in its implementation. Its text-variable lookup preserves the public ABI and uses the original signed switch comparison for JP; foreign branches are unchanged. All 29 cooking functions, three lifecycle functions, eight recipe-inventory functions, and their complete data match baserom with all references resolved.

The twelve bytes before cooking's own runtime prefix were not a missing cooking text object. The existing GameCube return-scene Run implementation genuinely depends on the return/save APIs, while its compiler-owned destructor/vtable need only the minimal scene interface. JP now gives that lifecycle definition a normal implementation unit; Run remains normal C++. Both functions (140 bytes), the sixteen-byte vtable and the naturally generated ten-byte runtime literal match baserom. The next ordinary input's alignment and the existing zero-filled .rodata supply the two-byte gap. No literal was hand-added, no unused dependency was introduced, and no compiler/preprocessor/output patch was used.

JP LDS lists each ordinary object section once. The lifecycle vtable remains at its early class-table position; the implementation's runtime content follows gamecube_link_save before cooking, matching the original physical organization. Existing overseas implementation and linker ownership are unchanged. The prior 568 record's cooking-boundary hypothesis is superseded by these whole-object results.

Stage 576 completed a fresh JP ELF/map/8 MiB ROM and compare. SHA-1 is 4081fee0d1aaa7550f96c5416e3354166e6a1094, not baserom a655b2789aed14a6ac78c6075fbc533d3062dbe3. Full-symbol then byte audit 577 found 19,737 paired intervals: 16,775 exact, 2,738 with explained reference changes, 137 length/padding and 31 remaining byte intervals; 29 changed references unresolved, 101 unsupported audit sites; 369 baseline and 288 current names remain unpaired. These are interval/audit counts, not independent bugs or completion percentages. All 42 local functions and their data passed; full-ROM SHA-1 did not. No commit or push.

Evidence: cooking-production-574/{consumer-checks-575.json,checks.json,checks-573.json}, cooking-interfaces-570/checks.json, return-scene-owner-572/checks-573.json, full-build-576/global-report.json, global-cohorts-578. Audit reports and helper scripts are external to the repository/build chain.

# 反编译进度

## JP GameCube 只读归属闭合与新整版报告（批次 559–568）

声明头在JP仅需GameStateSaveImage前置声明，不再引入完整GameScene；真正读取保存布局、调用图块/调色板集合API的实现直接包含其真实接口。生命周期对象因无关声明依赖多出的12字节SDK随之消失，原有1436字节代码与6张虚表1084字节完整匹配；没有删除编译输出或设置通配链接项。

保存数据、收发包及名字编解码的20个连续函数位于代码尾部，其字符表/协议标识也在独立连续只读范围。JP据此恢复src/gamecube_link_save.cc和include/gamecube_link_save.hh，相关类型和声明归入同名头；实现包含实际使用的保存布局。普通工程编译自然生成字符表前10字节库字面量。502字节字符表原址为2字节对齐，明确ALIGN(2)后其后协议标识自然4字节对齐，字符内容与原显式零条目均未改动。不是按字符串数量机械拆分，也没有新增无用类型、调用或new头制造字节。JP文本按模块名归入scene_gamecube_link.cc与gamecube_link_save.cc，移除旧_1/_2名称，海外文本维持原状。

8个实际JP工程对象make -j16验证通过：三个整理对象的179个函数、7588字节代码、2968字节只读数据及259条虚表指针均匹配baserom，其余依赖完整对象不变。JP LDS只在原顺序加入普通src/gamecube_link_save.o(.text)与(.rodata)，各列一次，没有地址、子section、GNU项或别名。编译器、预处理器和Makefile未改，海外版未构建。证据gamecube-save-unit-560/whole-objects.json、ownership.json、gamecube-save-production-562/consumer-checks.json。

此后冻结代码完成565整版JP make -k -j16、链接和8 MiB ROM生成；compare仍失败，SHA-1为79b54ab0c93baf5b014e1de13917edc0a2ae795d，baserom为a655b2789aed14a6ac78c6075fbc533d3062dbe3。566使用同轮ELF/map/对象，先全符号后全字节审计：19737个配对区间中16774个exact、2734个仅已解释引用变化，剩140个长度/填充、33个字节差异区间；30条变化引用未解释、101个位置暂不受审计器支持；369个基线名和288个当前名未配对。区间与引用统计不是独立bug数、函数数或项目百分比。

外部审计记录了179个已独立验证的函数身份，并让有实际区域证据的名字关系优先于旧的无区域猜测。90个新增配对及旧名字纠正会影响报告统计，不能把所有数字改善都算成代码修复。此规则只在临时审计工具中，不进入项目编译链，不更改ROM、对象、链接结果或编译器。完整证据full-build-565/global-report.json、gamecube-identities-564.json、global-cohorts-567。

全局仍标在GameCube末项的两个区间实际跨模块：LinkWordProtocol最后260字节虚表之后，烹饪核心表先于烹饪文本变量表，当前烹饪生命周期头多引入12字节SDK；协议GYW对象之后，原版烹饪文本前有两份12字节自然库边界，当前只有一份。三个GameCube对象本身完整匹配，不为闭合这些跨区间而改动它们。下一步同时核查烹饪正文/生命周期及只读边界，不能手工补字符串。没有提交或推送。

## JP GameCube 入口、返回 ABI 与代码连续性（批次 544–557，局部推广）

按6张原版虚表的259个槽位核实132个无冲突方法身份，纠正外部分析中7条旧名字对应关系；再结合实际构造调用、独有虚表/初始状态指针及完整函数字节，补齐两种协议构造与UiStateOwner更新接口的身份。SetMode的196字节主体和内部跳表原已一致，之前仅为审计器未处理函数内段相对重定位，不能算新增源码修复。533全局报表仍保留当时的配对规则，尚未重算其GameCube区间数。

原有163个入口之外，连续性检查发现SetPhase与GetUiResult之间漏了16个非调整入口，共648字节。其源码意义来自实际回调头中的16个定义，14个普通C++入口直接匹配原版；两个轮询入口保留原生条件返回形式，C++调整入口则已匹配。真实生成与输出位置试验551/552会把普通内联入口延后、反序，强制保留还产生两个无用入口，均未采用；没有为此修改编译器或LDS。

JP在原源码物理位置提供这16个完整、符号化的普通ABI汇编入口，头文件真实C++逻辑仍用于编译器生成多继承调整入口；每个实际入口只有一个定义，没有.set、包装跳转或逐函数链接条目。另5个原本不匹配的函数（核心构造及4个状态方法，共520字节）保留完整原生实现，旧C++保留在海外分支及审计。4处C++条件表达/轮询调整入口完成修正。这些汇编实现及补齐入口不冒计为C++进度。

HeldKeys公共接口在JP使用ABI字返回，保持与真实按键掩码及调用方一致；提供者的代码、真实数据及重定位均不变，其余海外声明/定义保留。103个实际JP依赖对象make -j16构建及完整分配段/重定位/导出核对通过：两个GameCube对象等于已验证候选，其余101个对象保持不变。现在两份对象全部179个函数与原版匹配、物理顺序一致，原648字节缺口已补齐。编译器、预处理器、Makefile及LDS没有修改，没有整版重编译、提交或推送。证据gamecube-production-555/consumer-checks.json、gamecube-entries-553/complete-checks.json、normal-entries.json。

本批代码已推广，整个GameCube主题仍未验收：只读区在协议状态表与字符编码表之间缺少原版10字节库生成边界，字符表原址为2字节对齐；其后4字节协议标识产生不同填充。已直接确认字符表自身502字节与baserom一致，显式零条目并非本次差异，不先删除。继续核实保存数据/名字编码的真实模块边界及依赖，不能手工补运行库文本。当前源码/对象已比533 ELF/map/ROM更新，不得混用它们重跑533全局报告。

只读区补充核对558：生命周期对象的1436字节代码完整匹配，6张虚表合计1084字节及259条指针关系也完整匹配；其前额外12字节bad_alloc来自当前头依赖，原版该地址实际属于前一张表末尾，不能把它算成该对象应有前缀。整个1096字节对象仍判为不匹配，未通过遮掉前12字节来验收。下一步精简声明侧无用途GameScene/调色板实现依赖，并把真正实现所需API直接包含于实现；同时核实保存数据/名字编码单元，恢复字符表前真正需要的10字节自然生成边界。显式字符零条目已核对为502字节正确载荷，不擅自删除。

## JP NPC 日程功能归属及搜索边界修复（批次 520–536）

从513全局报告的共性组推进，没有逐函数重建整版。两处upper_bound候选C++调整仍生成64字节，未采用；JP保留完整原生五参数模板入口，各60字节直接匹配baserom，保持已有C++声明、比较器、参数ABI及调用方不变。海外版继续使用原模板实例；此项不计为新增C++高级语言完成。实际npc_entity对象的全部分配段、重定位和导出不变，证据npc-search-523、npc-verification-526/checks.json。

32个人物日程回调的代码顺序与其描述符/路径数据顺序完全一致，已符号化的数据引用没有跨人物组。逐组完整对象核对后，JP按真实人物功能拆为npc_schedule_<人物>.cc及同名.hh，297个数据符号和25个专有存储结构归入各自头文件。npc_schedule.cc保留公共日期/初始化引擎；npc_entity.cc的真实构造调用直接包含对应日程接口。每个人物的原生回调解释GameStateSaveImage上下文，使用其真实布局声明；没有新增无用new头、调用、占位类型或手写运行库字符串。两处原有C++回调保持C++，其余30处仍为原生汇编，不冒计高级语言进度。

42个实际JP对象按正常make -j16规则构建通过：32组共5232字节代码及28512字节只读数据逐项匹配baserom，公共引擎1272字节、其余9个依赖对象的完整分配段/重定位/导出均不变。32组各自真实头依赖自然产生原版SDK前缀，消除31个重复边界缺口；公共引擎自身剩余10字节无引用库生成物不选入数据区。JP LDS按相同物理顺序各列一次普通.text/.rodata，不添加地址、子section、GNU项、别名或补丁。海外版源码逻辑及LDS保持，未构建海外版。证据npc-functional-units-528/manifest.json、core-and-dependencies.json、npc-production-530/consumer-checks.json。

本阶段完成后冻结源码，533使用WSL make -k -j16完成JP链接及8 MiB ROM生成，compare仍未通过，SHA-1为5f6a1a4dbb6cfb875b168c7f187df5eac4c36950，baserom为a655b2789aed14a6ac78c6075fbc533d3062dbe3。使用同轮新ELF/map/对象完成全部符号再字节审计：19647个配对区间中，16716个exact、2675个仅已解释引用变化；剩154个长度/填充、46个字节差异区间（513为186/47）。175条变化引用未解释、115个位置暂不受审计器支持，459个基线名与362个当前名尚未配对。区间不是函数数、独立bug数或全ROM完成比例。原第一批30区间现4个exact、26个仅引用变化，已无剩余字节区间。完整证据full-build-533/global-report.json、global-cohorts-534。未改编译器/预处理器，未提交或推送。

下一共性组为GameCube主模块/生命周期；先总览真实方法、成员函数指针与继承接口的对应关系。当前533产物保持冻结，后续新对象不能混入533全局审计。

GameCube原版6张虚表共259个槽位推导出132个无冲突的函数身份，其中7条旧名字配对错误。按槽位身份重新作完整函数对照，两模块149/163个函数匹配baserom；这是外部审计名字关系修正，不是新增源码修复，尚未回写533全局报表，154/46仍是原533命名规则下的区间计数，不能把其中全部GameCube条目视作独立代码错误。源代码及产物未改变。

局部候选以原工程参数编译两对象：显式分支整理、按键截断表达使PollConnect/PollDecision两个编译器调整入口，以及Unk_58/Unk_5C两方法匹配；原149个已匹配函数无回归。候选仍有返回宽度、布尔控制流、构造函数内联可见性等未完成内容，因此4处尚未推广到工程。noinline属性被实际旧编译器忽略且Werror拒绝，已从候选移除，没有为此修改编译器；把GetHeldKeys改为u16也未解决该调整入口，未采用。下一轮先补全构造函数/成员表身份及SetMode局部引用分析，再完善同组候选，不能按错误旧名字修改已经正确的汇编。证据gamecube-overview-535/vtable-contracts.json、contract-checks.json、gamecube-candidate-540/contract-checks.json。当前工程源码及对象仍与533整版报告配套，未再构建整版。

## JP 第一批整版核查与新全局报告（批次 512–519）

512的启动命令在进入Make前因嵌套shell展开Windows PATH而解析失败，没有新ELF/map/ROM，不能计作编译结果。513改为执行独立WSL脚本，冻结游戏源码，使用make -k -j16完成JP全部编译、链接和8 MiB ROM生成。compare未通过：当前SHA-1为1a85db6ba3cde3aad6a7072427934c7b5833d4f0，baserom为a655b2789aed14a6ac78c6075fbc533d3062dbe3。没有分析/构建海外版，没有改动编译器或预处理器，没有提交或推送。

新513报告先检查全部符号及已记录改名，再审计字节和重定位。当前19644个已配对区间中，16706个原始字节一致、2649个仅为已解释引用变化，仍有186个长度/填充区间与47个字节差异区间；175条变化引用未解释，115个引用位置暂不受审计器支持；462个基线名字和365个当前名字尚未配对。区间并不是独立函数数、bug数或全ROM完成百分比。全局证据使用同轮新ELF/map/ROM及生成报告当时的对象，不混用旧451输入。

第一批30个目标修改均已局部验证；整版中对应原区间4个exact、25个仅引用变化、1个仍有字节差异。最后一个区间从HarvestSpriteController析构到ChildNpcActor，实际横跨64字节已匹配析构和后一个独立npc_path_search对象的60字节upper_bound模板实现。差异从区间+64开始，不能把这一整个124字节区间都算作析构已匹配，也不能把旧报表归属当作真实函数边界。该相邻模板仍待处理，第一批全区间验收不标为完成。证据global-cohorts-515/first-batch-global-results.json及513 map的两个对象边界。

全局复查同时发现492调整头依赖时，动物参赛选择主模块本来需要的12字节原版SDK前缀被移除；此前26个文本/表对象自身匹配，不能证明它们前面的边界正确。516按主实现真实调用ObjPaletteCollection构造/析构的依赖，直接包含集合公共API，生命周期声明继续只使用池句柄。实际主对象的完整函数、数据、导出及重定位恢复为492声明精简前对象；12字节前缀直接匹配baserom，函数全部不变。证据animal-api-516/checks.json。此修复在513完整报告之后，只做了该JP对象验证；当前对象已比513 ELF/map更新，不能重跑513全局审计来混算修复后的结果，也未再整版链接。

已对513所有差异重新总览归组，不盯着第一差异反复处理：npc_schedule有31个长度区间；GameCube主模块和生命周期各14个差异区间；另有entity_ui、环境实体、菜单/文本命令及只读区真实依赖等组。131个长度区间中观察到SDK字符串数量不同（85个区间减少、46个区间增多；合计108份缺少、49份增多），这只是冻结ROM中的计数线索，不等于每处语义已经确定，不能因此手工加字符串、盲目补头或机械拆文件。优先继续查明日程等重复缺口的真实编译单元/类型来源，并将未配对的60字节模板归入下一组代码分析。完整分组证据global-cohorts-515/owner-overview.json、runtime-literal-cohort-517.json。

## JP 第一批30区间局部闭合（批次 503–511，整版验证待512）

两处绑定派生析构分别恢复为完整40字节原生ABI入口，借用既有NAKED函数方式输出真实的GCC析构符号。显式asm名称是该入口本身的ABI命名，不产生第二个符号或.set/alias；虚表和调用方仍引用原有真实析构符号。保留类继承、全部头内内联体、已匹配的3个C++基类/命令组函数，调整派生内联体的实际实现归属，避免重复独立输出。两个生命周期对象5个函数共208字节匹配baserom；按实际依赖make -j16构建105个JP对象，105/105符合预期，调用方没有此前459那样的回归。没有更改编译器、预处理器、编译选项或LDS；不计为新增C++高级语言完成。证据binding-native-owner-504/checks.json、binding-promotion-505/consumer-checks.json。

商店批次沿真实依赖整理15个既有声明头：指针仅需要前置声明，句柄使用已有池接口，移除声明端无实际用途的完整GameScene/背包/私有调色板分配实现。34个实现源码按已有对象的实际方法重定位直接包含所调用的背包、场景、调色板接口；14个实现再按其真实账本C API调用直接包含money_account.hh。不是给表单元添加无用途的new头来制造字节。旅馆与海边餐馆的原版前缀区间在451报告已经完全一致，必须保留；通过实际扣款等账本API的正常库依赖恢复其自然生成物，不能机械删除每一个SDK出现。缺失的AScene声明由铁匠升级头直接包含scene.hh补齐。候选文件时间戳早于其后505重建对象，推广时刷新实际头时间后重新完成同一依赖集合，不能把Make未重编译的旧对象当作验证成果。

最终66/66实际JP依赖对象验证通过，全部函数、真实数据和调用关系保持原样，仅商店总虚表、商店基础虚表和VCount虚表前3份额外12字节生成物消失；另两份原本已丢弃且无导出/已分配引用的10字节孤立生成物不再产生。后两表合计48字节直接匹配baserom，520字节商店总表实际内容和符号关系不变。证据shop-api-510/consumer-checks.json、shop-validation-508/boundary-evidence.json。没有新建项目接口文件、通配子section、地址补偿、后处理或新的编译生成层。

第一批30个原报告区间已全部应用并局部验证；这仅是所选共同原因批次，不代表全ROM已经通过。当前最新完整报告仍是451。接下来仅对JP进行512整版构建，冻结游戏源码，再用同轮新ELF/map/ROM做全局符号与字节审计；不能混用旧451镜像和新对象。没有处理海外版、提交或推送。

## JP 回忆场景真实虚表归属与飞盘依赖整理（批次 494–502，局部验证）

回忆场景主源码真实使用placement new，保留其new头依赖及自然生成的10字节库字面量。三张类虚表由已有intro_story_lifetimes实现拥有；头文件按真实类/成员分别声明实现归属，构造及UiOwner内联实现仍只在实际调用源码可见。直接更换整个implementation归属的494候选、未取消主实现重复认领的495候选都会产生无用辅助入口，因此未应用；496的选择性归属保留原有10个函数，未增加入口，全部指令字节及符号调用保持不变。全局符号从本对象定义变为外部引用是正常归属变化，审计按符号身份比较，不把这一变化当作代码差异，也不掩盖真实指令变化。

6个JP实际依赖对象make -j16构建验证通过。核心、文本变量及场景三张虚表44字节一起直接匹配baserom，三个符号在相关依赖中均只由生命周期对象定义。JP LDS在原位置将唯一的src/intro_story_scene.o(.rodata)替换为src/intro_story_lifetimes.o(.rodata)，没有添加子section、GNU选择器或地址限定。主对象剩余库字面量无导出或已分配重定位引用，不选入此虚表区域；这是保留真实库依赖、由正常对象/段归属选入实际数据，不是手工删字面量或输出修补。IndexedResourceArchive前表实际大小20字节，核心表12字节，其后接文本变量表；验证使用基线实际符号与大小，不假定前表都是16字节。证据intro-ownership-497/probe-checks.json、consumer-checks.json。

飞盘核心原来的GameSceneTalkWindowOwner只是同样的单指针拥有/释放操作，但其声明把完整GameSceneState及无关存储分配实现带入生命周期对象。JP复用现有SmartPtr<UiStateOwner>，仅引入真实UiState接口与既有模板，字段大小、偏移、默认初始化、Get及赋值/释放行为保持；原生构造与全部既有C++函数的产物不变，不声称原版模板名相同。6个实际依赖对象make -j16验证全部通过，唯一变化为生命周期少12字节无关SDK前缀，44字节真实虚表匹配baserom，主模块及调用方均不变。该模块原本684字节核心析构仍不匹配原版，保持现状，明确不计为新函数匹配成果；另外96字节Lookup和32字节变量析构匹配。证据frisbee-ownership-500/probe-checks.json、consumer-checks.json。

第一批30个区间累计27个已应用并局部验证、3个待处理：HardwareManagerPreviousBinding和UiVCountContextRegistration两处派生析构，以及shop_scene_tables前的无关运行库内容。此数字仅指原批次抽样，不能当作全部JP差异只剩3处。451仍是最后完整全局报告，当前对象不是与其配套的旧对象；尚未整版链接或验证新SHA-1。后续继续处理余下共同原因后再作新的完整JP结果。海外版、编译器、预处理器和编译参数未修改；没有提交或推送。

## JP 句柄依赖批量推广与原生绘制边界恢复（批次 486–493，局部验证）

JP的ui_state.hh与ui_text_commands.hh仅依赖ObjPaletteCollectionEntry句柄，改为引用已有obj_palette_pool.hh；真实使用集合Get等API的ui_state.cc仍直接引用集合公共接口，完整对象保持不变。参考页头移除未使用的game_scene.hh并前置声明GameStateSaveImage，改用同一真实句柄声明；其生命周期源码的JP搜索已是完整原生函数，不再引入只给海外模板实例使用的algorithm。没有新增接口文件、占位类型或生成物补丁。

按真实.d依赖一次make -j16构建86个JP对象，86/86符合预期。发生变化的9个对象函数均不变，变化仅为不需要的SDK字面量及其对齐。参考页与菜单选择的真实虚表逐字节匹配baserom；工作人员60个文本/表对象全部逐项直接匹配baserom。工作人员文本本身按字节对齐，旧SDK为10字节，后续指针表另有对齐，因此不能简单用所有符号减12判断；实际文本标签移10字节、后部表及总大小移12字节。ui_text_window没有数据符号的10字节SDK与后续2字节对齐，通过完整451报告中前后真实虚表原间隔16、当前28验证为多余；另两份10字节孤立生成物原本已在451 map中丢弃。证据entry-clients-487/data-checks.json及entry-clients-488/consumer-checks.json。

两个农场Draw的OAM原始视图候选486未匹配，没有应用。JP改为保留完整可读的424/228字节原生函数体，采用项目已有NAKED成员函数写法，保持正常成员/虚表生成顺序。所有BL指向真实Draw/GetHardwareSpriteBuffer/InitializeMosaicSpriteOam符号；常量池的页内RAM字段偏移保留原生数值，不使用ROM地址载荷、别名或链接补偿。已匹配的其余11个C++函数完全保留，未完成C++绘制实现仍留在非JP分支供后续分析。本项只计入原生符号化与布局修复，不计为C++反编译完成。3个实际依赖对象make -j16验证通过；生命周期对象13个函数均直接匹配baserom，真实只读数据不变，主模块及另外调用方全部不变。证据farm-native-489/checks.json、farm-native-490/consumer-checks.json。

动物参赛选择头同样只需要句柄和存档前置声明，JP移除未使用game_scene.hh及集合私有实现依赖。只推广491候选中的animal_festival_selection.hh，其余8个商店主题头候选未推广。6个实际依赖对象验证通过，唯新增变化是主模块和生命周期各少12字节SDK；主模块26个真实数据对象匹配baserom，生命周期原有12字节核心虚表与16字节场景虚表完整保留并一起匹配baserom。前者在旧基线无具名标签，审计使用已确认前后表边界确定其原地址，没有在工程添加任何别名。证据scene-interfaces-491/data-checks.json、animal-interface-492/consumer-checks.json。

第一批30个原报告区间现在25个已应用并局部验证，5个待处理：HardwareManagerPreviousBinding与UiVCountContextRegistration析构、frisbee_lifetimes/intro_story_scene/shop_scene_tables三处运行库边界。参考页生命周期自身、菜单生命周期、工作人员主文本和UI文本相关多余前缀在原30区间抽样之外，单独记录，不能挤入25/30。商店491较大候选未消除shop_scene_tables前缀，因此没有推广；不能按头文件精简数量宣称边界修好。

本批未修改编译器、预处理器、编译参数或LDS；未处理海外版、未提交或推送。尚未整版链接，最新完整全局报告仍为451；当前对象已更新，不能将新对象与451 ELF/map混合重算全局比例。下一步集中分析余下两种析构生成与三处真实库依赖/虚表归属，再择机作完整JP验证。

## JP 真实头文件依赖与生成常量批量核查（批次 480–485，局部验证）

WSL会话错误0x80072747中断候选编译后，用户恢复环境，继续了相同候选验证，没有重复启动未确认结束的构建。工作人员声明实际不使用game_scene.hh，JP移除这条间接依赖，主源码改为直接include其真正使用UnkUiSelectionDimensions的ui_text_commands.hh。生命周期对象不再生成额外12字节SDK字面量，真实12字节C++析构和两张虚表不变；主对象的全部代码、文本、表、导出与重定位不变。按真实依赖make -j16构建的6个JP对象均与预期一致，证据staff-dependencies-480/match.json、consumer-checks.json。

对较大公共接口精简候选先作121个JP编译单元的预处理依赖评估。直接将整个调色板集合公共头变成薄接口，会同时影响原版UI模块确有的生成常量，故481没有推广。审计已区分十字节字符串本体与后续对齐，不能把所有出现都固定认作十二字节；无基线数据符号的对象仍记为不确定，不能凭预处理结果宣称ROM匹配。原始评估输入与后续对象快照分开保存，482使用484构建前快照，避免混用重建后的目标。

最终只应用484的三个真实类型依赖调整：JP将八字节ObjPaletteCollectionEntry的既有定义移到已经提供其句柄分配/引用/释放接口的obj_palette_pool.hh，私有存储头继续引用同一真实类型；记分板声明仅含这些句柄字段，因此直接include池接口，不引入未使用的集合分配实现。集合公共头及真正使用集合API的实现保持原有依赖；没有新增头文件、占位类型、别名符号或编译选项。其他地区的原定义路径保持不变。

按实际依赖一次make -j16构建129个JP对象，129/129与构建前或已有验证过的批内修复一致；唯一新增数据变化是记分板生命周期对象少了不属于原版的12字节SDK字面量。该对象的68字节C++析构及28字节真实虚表均逐字节匹配baserom。其余真实数据、函数、导出和重定位保持原样；不是宣称129个对象都已直接匹配原版。对少数过期缓存，明确使用此前已验证的453–477修复对象对照，不将既有源码修复误判为本轮回归。证据palette-handles-484/consumer-checks.json。

483更大范围的六头候选没有整体应用：其参考页仍经game_scene引入SDK，不能按预设的12字节变化去统计。后续只能基于真实类型需求继续精简，不能盲目删SDK包含、补字面量或用工具特化来抵消。编译器、预处理器及LDS均未修改。

第一批30个原报告区间现为21个已应用并局部验证，9个待处理：两处绑定清理、两个农场绘制函数、其余5个只读/运行库边界。另消除记分板生命周期对象开头的一份额外生成物，此项在原抽样区间之外，不挤入21/30统计。尚未重新链接ROM，最新完整全局结果仍为451；未处理海外版、未提交或推送。

## JP 第一批滚动精灵、页面所有权与只读边界总览（批次 473–479，局部验证）

先将第一批余下12个区间按实际函数与对象边界归组核查。JP事件滚动精灵构造保留为完整432字节原生指令，rand、取模、实际精灵构造/复制/析构和三张参数表均通过真实符号引用，没有ROM地址载荷或输出补丁。其余3个C++函数与此前454–456恢复的4个原生析构保持原样；整个world_prop_lifetimes对象8个函数均匹配baserom，数据不变。当前普通对象缓存起初仍有451旧实现，因此4个已修复函数以456验证对象为对照，不能把缓存差异误判成新回归。正常make -j16目标构建后，正式对象与474验证对象的全部已分配内容、导出及重定位相同。

ScrollMenu的真实C++析构本来就是56字节，额外52字节来自没有外部调用的非模板页面Owner清理入口。JP改为复用既有SmartPtr<ScrollMenuPage>的单指针、虚析构所有权操作，保留有含义的ScrollMenuPageOwner类型名；这是C++类型组合，不是汇编符号别名，不声称原版使用了该模板名称。两个位置访问函数通过已有operator->读取页面，编译结果不变。匹配的ScrollMenu析构仍由正常C++生成，虚表/数据及整个主对象不变；所有现存JP目标的已分配重定位中没有删除入口的调用。按实际依赖使用make -j16构建7个JP对象，7/7符合预期，农场状态与记录页面等调用方没有代码或数据回归。没有修改编译器、预处理器、选项或LDS。

6个只读区间现在明确归属后一个对象开头的12字节自然生成bad_alloc及其对齐：frisbee_lifetimes、intro_story_scene、animal_festival_selection_lifetimes、staff_credits_lifetimes、shop_scene_tables、game_menu_selection。不能据旧区间所属的前一个虚表去修表大小。其中两段区间还包含原版已有的12字节核心虚表，不能把那部分误删为填充。476核查使用完整451 ROM与对应map，已核对其SHA-1；没有混用当前新目标与旧ELF进行全局统计。这6段来源/排列仍未修好，不能计入完成，更不能手工恢复/删除运行库字面量来凑齐。

两个绘制函数的坐标/临时计数器表达候选473尚未匹配，未应用。475移动页面Owner清理定义仍输出独立入口，未应用；478移除两个绑定层显式空析构会遗漏独立派生入口，同样未应用，原有共享inline可见性保持不变。候选结果仅用于排除假设，不计入进度。

第一批30个原报告区间累计20个已应用并局部验证，10个待处理：两处绑定清理、两个农场绘制函数、6个只读/运行库边界。最新完整结果仍为451，尚未链接整版，不宣称SHA-1一致。证据：外部scrolling-native-474/match.json、scroll-ownership-477/match.json及consumer-checks.json、runtime-boundaries-476/boundaries.json。未处理海外版、未提交或推送。

## JP 第一批辅助入口与计数容器批量修正（批次 463–472，局部验证）

先总览四个生命周期对象的所有函数，而非按旧差异标签逐个替换。飞盘核心68字节、参考页核心196字节、ScrollMenu核心56字节均已是匹配的C++；旧区间长度还包含随后多余辅助输出，不能据此恢复成汇编。飞盘Owner构造和箭头运算符、参考页Owner构造的inline定义迁回实际调用它们的同名主源码，头文件保留JP声明；两个生命周期对象不再强制生成这3个无外部引用的入口，两个匹配的核心析构保持C++。参考页搜索模板暂以完整56字节原生指令保留，其他地区实例化不变。

466的4个实际JP目标探针匹配预期；两个主模块代码、数据、导出、重定位均不变，两个生命周期对象数据不变。扫描全部现有build/jp目标的已分配段重定位，未发现对删除辅助入口的调用；按真实依赖使用make -j16构建并核对8个JP对象，8/8符合预期。关闭inline输出会同时删除真实隐式析构，显式空析构又会额外写入派生虚表，这些候选均未应用；没有修改编译选项、编译器或预处理器。

农场状态模块按整个对象核查5处实际函数差异，发现收益页旧头文件误用了海外布局：JP原生构造初始化两张标记表的count于0xDE8和0x11BC，而非0x1264和0x1638；JP对象实际大小为0x1580。已对JP恢复正确RAM arena边界，并保持海外定义不变。计数存储的终点以sizeof(count)+count*sizeof(T)从容器起点计算，先固定终点后遍历活动元素，真实的固定容量不变。该通用容器表达同时使收益页88字节、小矮人页56字节、农场核心84字节三个析构全部由正常C++匹配baserom；未用地址补偿或工具输出修补。其余8个函数体（含小矮人绘制）、虚表/数据和主模块均不变；收益页绘制同步使用正确字段布局，但两个Draw函数仍未匹配，未计为完成。按真实依赖make -j16构建的3个JP对象均符合预期。

第一批30个原差异区间中，18个已应用并通过局部验证，12个待处理；这不是全局差异数，也不是完整ROM通过。剩余包括两处绑定清理、事件滚动精灵构造、ScrollMenu额外辅助输出、两个农场绘制函数，以及6个只读数据/运行库边界区间。最新完整构建仍为451，本轮没有链接ROM；未处理海外版、未修改LDS、未提交或推送。

证据：外部cohort-overview-463/overview.json、owner-bodies-466/match.json及consumer-checks.json、farm-layout-470/match.json及consumer-checks.json。中间候选467–469、471仅作局部假设验证，最终应用的是466与470；不能把候选的匹配数量算作工作树成果。

## JP 第一批童年故事清理边界恢复（批次 462，局部验证）

对原报告Lookup区间132/140字节差异重新核对后，确认84字节的IntroStoryTextVariables::Lookup已经匹配，差异来自随后尚未配对的核心析构，不能修改UiTextSubstitution或FixedStr来凑齐。本轮保留该查询和32字节文本变量析构的正常C++编译，仅恢复48字节完整原生核心清理，使用真实成员基类虚表、UiStateOwner析构与HardwareContext析构符号；当前固定成员偏移0x6428仍遵循已验证类布局。

实际JP模块三函数共164字节全部与baserom匹配；两个C++函数体、数据及重定位不变，导出集合和函数顺序不变。旧DestroyIntroStorySceneCore名称与真实C++析构入口的对应已记录在外部证据中，没有增加源码别名。证据为intro-cleanup-462/match.json。

第一批累计12个原盘点区间已应用局部修复，尚未链接整版；全局统计继续沿用451。未修改共享返回结构、工具链或LDS，未处理海外版，未提交或推送。

## JP 第一批菜单内联归属与清理循环（批次 460–461，局部验证）

菜单生命周期模块的较大差异区间包含12个额外生成的共享辅助成员。直接关闭 inline 输出会遗漏真实隐式核心析构，因此460候选未应用。461将三组共享内联辅助类型的接口归属指向已有 game_menu.hh，具体清理类仍由 game_menu_lifetimes.hh 所有；不新增头文件、工具或链接段。归属选择仅用于JP，海外定义不变。

同时纠正 GameMenuIconList 的JP清理逻辑：原版先固定构造项终点，再按该边界遍历；旧源码在for条件中重复计算终点。现在采用普通C++的固定last指针与while遍历，匹配真实计数容器行为。原先对SpritePanel函数本体已匹配的初步判断仅依据长度，实际逐字节核对发现这段循环不同，已在本轮修复，不能以相同长度当作匹配证明。

结果：GameMenuSpritePanel和GameSceneMenuCorePrefix两个析构均保留正常C++生成，212+84=296字节全部匹配baserom；虚表／数据不变。12个无外部调用的独立辅助输出不再由生命周期模块强制产生。菜单主对象不变，按实际依赖用make -j16构建17个JP对象并核对，全部与预期一致；除修复目标外的调用模块代码、导出、数据及重定位不变。没有修改编译选项、编译器、预处理器或LDS。

证据位于外部 menu-interface-461/match.json、consumer-checks.json、production-build-status.json；当前所有JP源码对象的重定位中未发现对移除辅助入口的外部调用。本轮未链接ROM，第一批累计11个原盘点区间通过局部修复，尚待整批全局验收。最新完整结果仍为451。未处理海外版、未提交或推送。

## JP 第一批绑定清理的依赖验收（批次 458–459，候选未保留）

458以完整原生入口取得两个绑定生命周期模块5个函数208字节匹配，但会替代三个此前匹配的C++独立函数，故未应用。459改为保留三个普通C++函数和两个原生派生入口，模块局部内容、顺序与数据匹配；随后按实际依赖文件检查106个JP对象，发现hardware_manager、hardware_manager_tables、ui_vcount三个调用方因共享inline定义迁移而发生代码变化。不能用五个局部函数的通过代替共享接口整体通过，因此459候选全部撤回。

撤回后使用正常make -j16只重建受影响对象，没有链接ROM。106个对象均已确认与其原快照或此前已验证的453–457批内修复对象一致，三处调用方变化已消除；之前累计九个局部修复区间保留。证据：binding-entries-458/match.json、binding-cpp-459/consumer-checks.json、reverted-consumer-checks.json、conclusion.json。

这组问题仍未解决：独立函数恢复必须同时保留其他翻译单元对基类inline定义的可见性和已有函数输出顺序，不能统一从共享头文件移走定义，也不能仅靠局部匹配推广。未新增工具链补丁或LDS重排，未处理海外版，未提交或推送。

当前build/jp对象已包含通过普通规则构建的批内修改，旧451 ELF/map/GBA尚未重新链接，不能将新对象和旧ELF混合生成新的全局报告。整批完成前沿用已保存451全局报告。

## JP 第一批室内地图容器边界恢复（批次 457，局部验证）

原报告中从室内标记构造函数起的100字节区间，实际由44字节构造和56字节析构组成，后者原标签为 loc_080E1860，现明确为真实析构入口 _._26FarmMapScreenIndoorMarkers。连同地图核心124字节析构，共三个完整原生函数224字节已恢复为符号化指令；释放行数组的顺序、循环和条件删除均按原版保留。

调用方仍使用原有 C++ inline 构造定义；JP生命周期所有者以普通 -fno-implement-inlines 参数禁止额外生成重复独立构造副本。主地图模块与生命周期模块均按实际选项局部构建：三个函数全部匹配 baserom；生命周期虚表／数据不变，地图调用方所有函数体、导出、数据及重定位不变。将构造改为非内联声明的首个候选改变了调用方，未应用。

头文件仅为JP显式声明真实析构；没有改变类布局或海外版定义，没有新增 LDS 子段或工具链补丁。原 C++ 结构及 inline 构造仍保留；原生实现不计为高级语言完成。字段偏移、三行容器和四组室内标记属于当前固定类布局；修改这些结构容量时仍需同步恢复高层清理逻辑，不能据此宣称任意结构扩缩已自动支持。

证据为外部 map-lifetimes-457/match.json。第一批累计九个原盘点区间已具备局部修复证据，尚未整批链接；最新完整报告仍为451。继续处理其余清理和辅助生成问题，未提交或推送。

## JP 第一批成员清理恢复（批次 455–456，局部验证）

同批完成 HorseSpriteController（52字节）、HarvestSpriteController（64字节）和 EntityEventEffectController（176字节）的完整 JP 原生析构恢复。前两项依原顺序销毁各成员精灵；后一项保留两组带计数的数组释放，以及日出、月见对象和基类的清理顺序。所有外部调用和虚表均使用真实符号，内部跳转使用局部标签；没有地址补丁或新增 section。海外版保留原实现。

实际 JP 对象核对：三个函数共292字节全部匹配 baserom；对应对象其他函数体、导出、数据与重定位不变。原 C++ 版本保存在外部变更前快照，未把恢复原生实现计为高级语言反编译完成。证据：actor-native-455/match.json、effect-native-456/match.json。

第一批累计已应用并局部验证一个4字节独立 getter、六个共424字节的原生析构，覆盖原盘点的七个区间；这些不是新的全局统计。逐项状态存于外部 jp-ownership-batch-452-status.json。本批尚有其他容器、辅助函数和运行库后缀问题未完成，因此没有整版重建。最新完整结果仍为451的222个长度／填充和51个字节差异区间。未处理海外版、未提交或推送。

## JP 第一批控制器析构修复（批次 454，局部验证）

按共同原因一起处理 DogBallVisualController、ShippingBasketVisualController、CoopEggVisualController 的三个显式空析构。当前 C++ 生成的每个函数多出派生虚表写入，原版44字节函数只清理成员精灵、恢复基类虚表并按真实析构标志释放对象。已将 JP 的三个完整函数恢复为可读原生指令，引用 GameSceneSpriteBase 析构、EntityVisualController 虚表及普通删除符号，无地址常量、别名或输出补丁；海外版原 C++ 实现保持原样。

实际正常 JP 模块局部核对：三个完整函数共132字节与 baserom 匹配，同模块其他函数体、导出集合、数据及重定位保持一致。没有更改编译器、预处理器或 LDS。这属于完整原生混合实现恢复，不能计为三个 C++ 函数完成。证据为外部 prop-native-454/match.json；原 C++ 候选和变更前对象也保留于该目录。

本项与453独立计数入口一起纳入正在进行的第一批，尚未对整批进行完整构建。最新完整报告仍为451，不能据局部结果宣称全局差异数已下降；继续处理同批其他生成归属问题，最后一起整版验证。未处理海外版、未提交或推送。

## JP 第一批首项修复（批次 453，局部验证）

资源归档模块恢复 JP 原生独立 GetEntryDescriptorCount 入口，保留头文件既有 C++ inline 实现供真实调用方使用。当前编译参数抑制该 inline 的独立副本，因此新增完整符号化汇编入口不会产生重复定义；这是一项混合实现恢复，不计为新增 C++ 反编译。实际模块5个函数、344字节均与 baserom 匹配，其他函数体、数据及重定位未变。证据为外部 archive-entry-453/match.json。未修改 LDS、编译器或预处理器；未处理海外版。

第一批仍在进行中，本次没有整版构建，最新完整结果仍为451。前述定义顺序候选未应用；编译器 saved_inlines 按链表头插入并输出，其后端输出流程会关闭 inline 并使用保存的RTL，不能只修改标志位来假定可以继续安全内联。需结合真实类型与定义归属处理整批剩余项。

## JP 第一批生成归属问题盘点（批次 452，尚未推广）

按用户要求切换为共同原因批量处理，已从 451 全局结果提取 13 个模块、30 个相关差异区间，覆盖缺失 inline getter、基类清理可见性、空派生析构、容器清理、辅助成员输出及运行库后缀。它们是本批调查范围，不表示已经完成 13 个模块修复，也不能按相同长度差直接套用一种规则。

对硬件管理 PreviousBinding 和 UI VCount 注册层做了两个实际模块试验：将派生析构定义移到基类 inline 析构之后，能使基类恢复逻辑展开，但同时将派生析构移到模块前部。保留显式 inline 声明也未恢复原输出顺序。因此候选未推广，生产源码未修改；不通过 LDS 逐函数重排解决。需要把定义可见性与真实生成顺序一起处理。

记录为外部 `jp-ownership-batch-452-input.json`、`ownership-batch-452/batch-report.json` 及候选源码和实际对象。本批没有整版构建，最新完整结果仍为 451（222 个长度／填充差异区间、51 个字节差异区间）。完成共同机制的局部验证及整批修改后，才进行下一次 JP 整版验证。海外版未处理，未提交或推送。

## JP 硬件混合辅助类型归属修复（批次 449–451）

449 实际对象试验确认，给硬件混合模块添加 `-fno-implement-inlines` 会连同原版已有的 36 字节 `HardwareBlendObject` 构造函数一起移除，故未应用该编译参数。该构造函数本身的完整指令及重定位已与 baserom 匹配；不能为了移除额外代码而丢弃它。

450 将供场景内联使用的一字所有权辅助类型 `HardwareBlendOwner` 从 JP 硬件实现接口中分离，存于 `hardware_blend_owner.hh`，由真正使用该类型的六个场景直接包含。它是共享的纯头文件类型，没有新增 ROM 对象或声明转发层。硬件模块仍采用原有编译参数，其原始构造函数自然保留，额外的 12+44+4 字节辅助成员不再被该模块强制输出。海外区域原来的定义保持原样。

实际正常 JP 对象核对：硬件模块 17 个函数、620 字节全部匹配 baserom；非代码数据及引用不变。开场、新游戏身份、动物照顾、鸡祭、收获和浇水小游戏共六个使用方的所有已分配段、重定位和导出符号与修复前完全相同。局部证据为 `blend-inline-449/conclusion.json`、`blend-owner-450/match.json`、`blend-owner-450/clients.json`。

451 已使用 WSL `make -k -j16` 完成 JP 整版编译、链接及新 ROM 生成。SHA-1：`3cdd7327ba7dddf0f3b793f2bbe334a6f5f527ab`；baserom：`a655b2789aed14a6ac78c6075fbc533d3062dbe3`。整版匹配状态：False。当前剩余 222 个长度／填充差异区间、51 个字节差异区间；180 条变化引用未解释，117 个引用位置不受审计器支持。区间不能当作独立函数或完成百分比。

本轮没有修改 LDS、编译器或预处理器，没有分析或编译海外版，未提交或推送。完整全局证据为 `full-build-451/global-report.json` 与 `global-451-jp-*.json`。

另已查明，`GetGroupDescriptorCount` 报告中的 4 字节缺口不在该函数本体：其 4 字节本体已经匹配，原版随后还存在 `GetEntryDescriptorCount`。当前后者仅以 header inline 形式提供，被所在模块的 inline 输出选项抑制；调用方 `UiStatePayload::ShowHeartIndicator` 实际使用该内联 getter。该项尚未修改，需同时保留调用方正确代码及原始独立入口，不能改返回类型或补零凑齐。

## JP 滚动菜单修复整版验证（批次 448）

446 的 JP 页构造入口修复已通过 WSL `make -k -j16` 完整编译和链接，compare 尚未通过。ROM SHA-1 为 `1b7b0c62fb48cb81ab4d362949c71bfd32627e56`，JP baserom 为 `a655b2789aed14a6ac78c6075fbc533d3062dbe3`。

采用 447 的区域证据与精确同址旧名称处理，并补充已经完整核对的菜单构造身份后，当前有 223 个长度／填充差异区间、51 个字节差异区间；16,573 个区间字节完全相同，2,738 个区间仅存在已解释引用变化。仍有 180 条变化引用未解释、117 个引用位置不受审计器支持，465 个基线名称和 385 个当前名称尚未配对。这些数量不是函数完成率，名称与边界补齐造成的区间重分也不能计为源码修复。

本阶段源码只将 JP 页构造入口换成既有 `thumb_func_start`，模块长度不变；完整函数及表的局部证据见 446。未修改海外版、LDS、编译器或预处理器，未提交或推送。完整报告为外部审计目录 `full-build-448/global-report.json` 与 `global-448-jp-*.json`。

下一项只读检查确认 `hardware_blend` 早段 60 字节增量对应三个额外生成的 `HardwareBlendOwner` 成员：`IsQueued` 12 字节、析构 44 字节、构造 4 字节。其后 `HardwareBlendObject` 的 36 字节构造入口也由当前头文件生成，不能简单关闭全部 inline 输出而遗漏真实入口。该项尚未修改，应核对实际调用与编译单元归属，不以删除机器码或改 LDS 处理。

## JP 滚动菜单入口及引用核对（批次 446–447）

JP `ScrollMenuPage` 构造函数位于 14 字节的 C++ 取值函数后，此前裸汇编入口缺少对齐，函数前少 2 字节、函数内部却因常量池对齐多 2 字节。将该 JP 入口改用现有 `thumb_func_start` 后，模块总长度不变，构造函数指令及常量池布局恢复。没有在 LDS 定位、添加子 section 或修改编译工具。

实际 JP 模块局部核对：菜单构造 1,044 字节、页构造 488 字节、页析构 156 字节、页绘制 1,308 字节，共 2,996 字节与 baserom 匹配；页虚表 16 字节及其调用的 OAM 初始化函数 208 字节也完整匹配。其他函数体及非代码数据／引用未变。记录为 `scroll-entry-446/match.json`；整版验证另行记录。

外部审计还修正了参考 ELF 中同地址旧名称的处理：仅当 section、value、kind、size 完全相同，才将它们视为同一物理对象的历史名称，报告保留名称列表，不新增游戏源码别名。原来无法配对的部分函数因双名称被排除，现已纳入字节核对。牧场状态界面 10 张虚表共 160 字节均通过实际对象重定位与 baserom 核对；这不表示其所有析构函数指令已经匹配。

对未包含入口修复的 444 产物，447 审计得到 225 个长度／填充差异区间、53 个字节差异区间；新边界会拆分旧区间，不能把区间数量变化直接算成代码修复量。仍有 182 条未解释变化引用、117 个不支持的位置。该审计没有新构建，没有修改 ROM；证据位于 `jp-evidence-scope-447.json`、`jp-status-table-evidence-447.json`。

只处理 JP；海外版、编译器和预处理器未修改，未提交或推送。

## JP 历史名称证据的区域范围核对（批次 445，无新构建）

检查 444 剩余引用时发现，外部审计脚本此前将历史记录中 `/maps/jp` 与其他区域的同名地址标签合并成候选集合，导致部分实际对应的 JP 名称因冲突而未配对。现仅依据证据记录中明确的区域路径筛选；没有明确区域的记录仍保留为候选，不自动视为正确。该修正只影响仓库外的分析脚本，不属于游戏编译链，也不修改 ROM。

对同一份 444 JP 产物重新核对后，配对符号为 19,614，仍有 220 个长度／填充差异区间、59 个字节差异区间；85 条未解释变化引用变为 202 条，因细化边界使更多位置进入逐引用核查，不能把新增配对全部称为通过。另有 126 个引用位置仍不受审计器支持。区间数变化中的 66→59 是证据归属修正，不是又修复了 7 个函数。

对牧场状态界面单独使用实际对象重定位及 baserom 复核：10 张候选虚表中 8 张共 128 字节匹配；另外 2 张存在尚未确定对应符号的槽位，继续保留未验收。报告为 `jp-evidence-scope-445.json`、`jp-status-table-evidence-445.json`、`global-445-jp-*.json`。

后续候选：JP `ScrollMenuPage` 构造入口位于一段 C++ 函数后，源码使用未带对齐的裸入口，原版入口则为 4 字节边界；先完整核对该模块及相关名称对应，再决定修复，不修改 LDS 凑地址。JP 优先要求不变；尚未提交或推送。

## JP 返回类型修复整版验证（批次 444）

443 的 JP 返回类型修正已通过 WSL `make -k -j16` 整版编译与链接，8 个调用函数共 1,076 字节的局部匹配结果在整版报告中成立。与 442 同一审计口径比较，长度／填充差异区间由 227 降为 220，剩余字节差异区间由 67 降为 66。整版 SHA-1 为 `887329ca30826dd0ac350ad8be2e5b39a169ff4b`，尚不等于 JP baserom 的 `a655b2789aed14a6ac78c6075fbc533d3062dbe3`。

本轮源码仅调整 JP 的 `UpdateWorldAmbientMotion` 返回声明；没有游戏特定编译器补丁、预处理器补丁或 LDS 调整，也没有海外版分析、修改或构建。完整结果保存在外部审计目录 `full-build-444/global-report.json`。

## JP 环境移动返回类型修复（批次 443，局部验证）

依据 442 全局报告核对 8 个环境对象更新函数：JP 原调用点直接检查完整 `r0`，原生移动函数通过完整寄存器返回 0/1；此前 `bool UpdateWorldAmbientMotion` 声明使 C++ 调用方额外截取低字节。JP 声明改为 `u32`，海外版声明暂不变。此处恢复的是原生调用约定，不修改编译器或预处理器。

使用实际模块及正常编译选项验证，8 个 C++ 调用函数共 1,076 字节与 JP baserom 完全匹配；原生被调函数也已完整核对。同对象另外 46 个函数、定义顺序、导出集合及非代码数据／重定位未变。外部证据：`ambient-return-443/match.json`。尚待下一次 JP 阶段整版验证，不能用局部结果替代 SHA-1。

## JP 环境对象析构整版验证（批次 442）

441 的 12 个 JP 原生析构修复后，WSL `make -k -j16` 已完成 JP 编译、链接及 ROM 生成，compare 尚未通过。构建 SHA-1 为 `8dd07d8d05ce2a77aa17cb1b1ee758ea3b9218dc`；baserom 为 `a655b2789aed14a6ac78c6075fbc533d3062dbe3`。本轮没有编译或分析 US/EU/DE，没有修改编译器、预处理器或 LDS。

全局核对：长度／填充变化区间由 239 降为 227，剩余字节差异区间为 67；16,564 个区间字节相同，2,668 个区间仅有已解释的引用变化，已配对区间中没有顺序分裂。尚有 85 条变化引用未解释、128 个引用位置不受现有审计器支持；这些不能计为通过。区间不是函数数或独立问题数。

12 个析构的长度差异已消除，属于完整原生汇编的匹配恢复，不计为完成 C++ 反编译。全局仍有未匹配内容，不能声称 ROM 已经可无条件动态修改。报告为外部审计目录 `full-build-442/global-report.json` 与 `global-442-jp-*.json`。

后续只集中处理 JP；JP 完成后再将已验证的修复方法同步到海外版。按完整报告归类、局部验证、推广后进行阶段构建，不因记录报告再次构建。未提交或推送。

## JP 环境对象析构的混合实现修复（批次 440–441）

基于 439 全局报告，确认 12 个 WorldAmbientKind 显式空析构当前各 20 字节，而原版各为 10 字节指令加 2 字节对齐。差异为当前 C++ 自动写入了派生类虚表；原版这12个函数仅调用基类析构并返回。

进行了实际模块的最小 C++ 组织试验：删除显式析构后，当前 -fno-implement-inlines 留下12个未定义析构；改为输出内联实现则增加18个不应出现的全局入口且改变顺序；具体类私有化候选在 -fno-weak 下产生局部绑定，不满足外部汇编的真实表引用。这些候选未应用，保存在外部 ambient-dtor-440，不能视为 C++ 恢复成功。

按目标允许的过渡方式，仅 JP 的12个析构采用完整原生 Thumb 汇编，保持真实 C++ 名称、删除标志 ABI、对基类析构的符号调用及正常入口/末尾对齐。海外分支原有实现未改；没有新增工具补丁、地址常量、别名、子 section 或 LDS 条目。12个完整区间共144字节与 JP baserom 匹配。既有基类 C++ 析构完整64字节也与原版匹配，因此补充其旧地址名到类析构名的审计对应，不改源码名字。

同一实际对象的其余42个函数在保留局部标签关系后内容和引用均未改变；导出集合、函数顺序、非代码数据及引用符号不变。此轮计为12个原生函数边界/实现恢复，不计为高级语言反编译进度，其他已知不匹配的 C++ 方法仍需处理。未提交或推送。

## JP 函数入口对齐整版验证（批次 439）

438 的 10 个入口对齐修复后，WSL make -k -j16 已完成 JP 编译、链接及新 ROM 生成；仅 compare 失败，未产生新的链接错误。SHA-1 为 0bf8dcbd276da65136b7b5d5011200ea51f2fc18，baserom 为 a655b2789aed14a6ac78c6075fbc533d3062dbe3，整版尚未匹配。

全局报告的长度/填充变化由 255 降为 239，剩余字节差异区间由 68 降为 67，已配对范围内的顺序变化仍为 0。16,564 个区间字节相同，2,655 个区间仅有已解释的引用变化；尚有 85 条变化引用未解释、128 个引用位置未受审计器支持。区间不是函数数或完成百分比，不把尚未配对的名称及边界视为通过。

本轮按固定绝对位置比较有 6,273,438 个差异字节，包含入口补齐后向后传导的位置变化；它不是尚未恢复代码量的度量，不能用删除必要对齐来压低这个数。直接 SHA-1、全符号对应、引用及各区间内容继续分别记录。

报告位于外部审计目录 full-build-439/global-report.json 及 global-439-jp-*.json。下一组只读分析发现多个 WorldAmbientKind 空析构在当前对象中额外写入虚表；尚未修改，需核对显式/隐式析构和声明归属。未提交或推送。

## JP 原生函数入口对齐（批次 438）

对 437 的全部代码长度变化区间及源码入口进行联合检索，确认 game_state、game_world、npc_collection、player_actor、town_map 共 10 个手写 Thumb 入口缺少四字节对齐。原版均为四字节入口，7 处已有海外版 thumb_func_start 对照；其余保留真实函数及地区条件，只使用本项目现有的 thumb_func_start 替换裸 global/thumb_func。没有修改宏实现、编译器、预处理器、函数指令或 LDS。

用正常目标编译参数分别编译五个 JP 对象，覆盖受影响入口及相邻区间：18 个区间合计 2464 字节均匹配 baserom，其中 16 个此前的长度变化消除；两个原本等长的邻接入口也通过核对。匿名的函数内部跳表通过同一函数内的标签偏移计算，未忽略其指针字节。五个对象的非代码字节、指针符号及加数均不变；player_actor 的具名函数指针随入口地址正常变化，不当作数据内容变更。

10 处中只有 UpdateWhileSuspended 的入口为四版共享，因此另编译 US/EU/DE 的 player_actor 对象，三版该完整 76 字节函数区间均匹配各自 baserom；未进行海外整版构建。其它差异仍待处理，不从本轮局部结果推导全模块或全 ROM 匹配。

## JP 阶段全局验证（批次 437）

435–436 的类声明及私有 ABI 声明修复后，WSL make -k -j16 再次完成 JP 编译、链接及 ROM 生成，仅 compare 未通过。新 SHA-1：df4d7de338008a4396a6ac1179670e21701e5647；baserom：a655b2789aed14a6ac78c6075fbc533d3062dbe3。未使用链接后修补或新的工具链规则。

本轮全部符号及字节区间核查：19,581 对有依据的符号对应；16,520 个区间直接相同，2,682 个区间差异可由已验证引用变化解释；68 个区间仍有字节差异，255 个区间有长度/填充变化。434 的 12 个顺序变化区间已全部消除。长度类多出的两项是原先被顺序变化分类覆盖的边界，不将分类转换当作新增代码错误，也不计成已解决。86 条变化引用和 128 个审计器未支持的引用位置仍未验收。

这是本轮已配对符号范围的结果，不代表全 ROM 所有对象顺序、边界或动态引用均已完成。未配对名称清单继续保留；正常库字面量的数量及实际编译单元归属尚未恢复。完整报告在外部审计目录 full-build-437/global-report.json 及 global-437-jp-*.json。海外版尚未重建，未提交、未推送。

## JP 类声明与虚表输出顺序（批次 435–436）

以 434 全局报告为依据，修正菜单切换类声明次序：ToolChestTransition 移到 ShelfTransition 之前，构造函数定义也按同一声明次序排列。实际 JP 对象的完整 .text 3752 字节及全部 33 张连续虚表 528 字节均匹配 baserom，包含其相对顺序。函数体和 LDS 未改。局部比对修正了对当前符号重复应用历史改名映射的问题；旧名只在对照侧转换，不以改错游戏调用来消除审计器差异。

两个共享头文件中对编译器虚表的显式 extern 声明使旧编译器提前输出对应表。new_game_menu 的调用仅在汇编内，移除无用的 C++ 声明；intro_scene 的声明改为仅在实际使用该 ABI 符号的源文件内可见，表仍由真实类实现生成，未新增别名。intro/new_game_menu 的两组四张表各 60 字节，与 baserom 连续内容及顺序匹配。四个相关 JP 对象的函数代码与重定位保持不变，两个主模块的 rodata 也保持不变。

另以已确认虚表的析构槽及完整 604 字节核对，补齐 DestroyIntroSceneCore 到自然生成 _._14IntroSceneCore 的审计名称对应；不修改源符号或 ROM。各对象前置运行库字面量的归属仍未解决，不算入虚表通过范围。共享源码已修改，海外验证仍待 JP 稳定后执行。本阶段不修改编译器、预处理器和 LDS，不提交或推送。

## JP 阶段完整构建（批次 434）

按用户新增授权，在 430–433 的符号、虚表归属及分配运行库修复完成后，使用 WSL make -k -j16 构建 JP；海外版未重建。普通链接仅使用标准 --strip-debug，不修改任何分配段或 ROM 字节。已生成本轮新的 ELF、map 和 8 MiB ROM，上一轮的重复定义及未定义引用错误均已消除；make 最终失败仅为 compare 的 SHA-1 不一致。

当前 JP SHA-1 为 f6350ae8d31f60b141f2078c986ce1f8bc748ebe，baserom 为 a655b2789aed14a6ac78c6075fbc533d3062dbe3。尚未整版匹配，未提交或推送。绝对位置比较有 5,960,592 字节不同，此数包含位置偏移产生的连带变化，不能当作未解析字节数。

先核对全部符号，再比较字节：19,580 对有名称或已记录改名依据的符号；符号间区间中，16,520 段直接相同、2,671 段的差异由已验证的符号引用变化解释、253 段长度或填充变化、68 段仍有字节差异、12 段顺序变化。区间不等同于函数或独立问题。另有 86 条变化引用仍未由审计解释、128 个引用位置未由当前审计器支持解释；不能视为已通过。未配对名称也保留清单，不自动认为缺失实现。

全局问题分为：真实编译单元/运行库字面量归属，类声明与构造析构/虚表输出顺序，函数代码与局部对齐，以及引用配对证据尚不完整。当前 ROM 有 108 份 bad_alloc，原版 151 份；这只是盘点，不按差额插入字符串。代码段长度比基准多 456 字节；后部资源受上游位移影响，必须结合符号对应检查，不能逐个原址硬贴。

详细报告保存于外部审计目录 full-build-434/global-report.json、global-434-jp-symbols.json、global-434-jp-renames.json、global-434-jp-bytes.json。下一阶段依据这份全局结果修复共同原因，先局部验证再推广。JP 每完成明确阶段可整版验证；US/EU/DE 待 JP 稳定后同步。

## JP 运行库全局盘点及分配对象恢复（批次 433）

重新按 429 的全部 JP 只读输入对象及 baserom 盘点：原版 151 份 bad_alloc，429 输入对象 107 份，其中 58 份排在 main.o 的首份运行库文本之前；原 ROM 首份为 0x080E7A50。这说明不能将问题简化成“补 44 份”：数量、真实归属、相对位置需要分别处理。58 份位置在前不等于确定多出 58 份，不能据此删除。逐对象/逐原址清单为 runtime-inventory-433/inventory.json，旧标签也不当作原始编译单元的证明。

425 已验证的分配运行库候选现落实到 JP：按实际旧运行库 new.cc 的定义恢复 const std::nothrow_t std::nothrow = { };，移除 JP SRAM 文本中的四字节“空文本”表示，将 new.o 的普通 .rodata 放在 SRAM 签名之后。没有手写 bad_alloc、虚构调用或填充。保留其他三版现有文本/链接配置，待 JP 邻接归属确认后推广；公共运行库定义已更新，海外目前未链接此 .rodata。

JP 新实际对象的 .text 180、.data 4、.rodata 16 字节均匹配 baserom。SRAM 签名为正确的 32 字节，函数代码及其重定位不变。此为运行库源码与局部字节共同支持的重建，没有原始 ELF 证明四字节对象的历史符号名；此限制继续保留。紧接的两份运行库字面量及海外 Error/N/A 归属仍未解决，不用填充掩盖，也未声称整个相邻区域或全 ROM 匹配。未整版编译、未提交、未推送。

## JP 地图虚表顺序恢复（批次 432）

确认基础地图和保存地图表之间的 16 字节为 MapViewportTilemapCommand 虚表，并非填充。保存地图表现在由实际保存地图析构所在的 saved_map_tree.cc 自然生成；基础地图表仍由 world_map_tables.cc 生成，视口命令表归属不变。使用现有接口/实现 pragma 和普通 -fno-weak -fno-implement-inlines 选项，没有新增源码文件、伪调用、手写表、编译器补丁或 LDS 子 section。

JP 局部对象验证三张表按 40 + 16 + 40 字节连续排列，整个 96 字节与 baserom 一致。saved_map_tree 的 .text 492 字节及重定位与 429 完全不变，没有新增代码入口。四份 LDS 只增加这个现有对象的普通 .rodata 条目；海外使用共享修正，尚未执行海外验证。完整构建仍未重跑。

world_map.cc 自身自然生成的运行库文本仍保留，未因恢复表顺序而偷偷丢弃。该 12 字节的最终归属/位置仍是全局运行库文本问题的一部分，因此本轮只验收三表内容和相对顺序，不宣称整个相邻 rodata 或整版 ROM 匹配。证据 map-owner-432/match.json；未提交、未推送。

## JP 玩家生命周期归属恢复（批次 431）

429 的 25 个 PlayerActor 未解析成员不是缺少原生实现，而是部分 C++ 接口被生命周期单元同时生成了第二张、未正确覆盖原生槽位的表。完整 PlayerActor 原生表继续位于 player_actor.cc，部分接口继续位于 player_actor.hh，不为其虚构析构实现、别名或补桩。

已有 player_actor_lifetimes.cc 的完整基类和渲染控制器类型移入其同名头文件。普通内联存储辅助类型放在实现归属 pragma 之前，使它们按普通内联规则使用；只有三个完整类接口由该单元拥有实现。源码中没有增加新 cc、LDS 项、编译参数、编译器或预处理器特殊规则。

JP 实际对象验证：三张表共 276 字节、三个析构函数共 208 字节，逐项匹配 baserom，彼此次序正确。玩家主对象的整个 .text 55972 字节、.rodata 188 字节及重定位与 429 保持一致，原生表未改；这只证明此修改没有改变主对象，不扩大为其整块代码都已匹配 baserom。25 个未解析引用已从新生命周期对象消失。11 个多余导出（重复表、重复析构、9 个内联辅助入口）不再生成；JP 当前链接输入对象中没有对这些被移除导出的有效段重定位引用。

试验过的 -fno-implement-inlines 会同时抑制三个所需隐式析构，因此未采用。最终修正在源码声明归属中完成。生命周期对象前端自然生成的 12 字节运行库文本/对齐仍需与全局物理顺序一并处理；本轮没有声称整个 rodata 或全 ROM 完成。只编译 JP，海外验证留到 JP 规则进一步稳定后推广。证据 player-owner-431/{review,match}.json，未整版编译、未提交、未推送。

## 链接归属局部修正（批次 430）

根据 429 的全局链接诊断，教学场景保留汇编中的两个过时入口改为现有 CreateFarmingTutorialWorld 与 HardwareInputState 参数版 UiStateOwner::Update。四版真实定义均存在，未添加别名或补桩。四版局部对象比较：JP .text 10024 字节、海外 10044 字节，及各自 .rodata 64 字节，全部匹配 baserom。

world_map.cc 删除了仍手工定义的 SavedMap 虚表及无调用者的表布局声明，保留 world_map_tables.cc 的真实编译器输出和实际析构入口。四版局部编译确认 .text 字节不变，构造函数从本对象的重复定义改为外部真实表引用；两张生成虚表各 40 字节内容匹配原版。布局仍未完成：生成对象中 SavedMap 在 WorldMap 前，原 ROM 是 WorldMap 在前，二者之间还有 16 字节内容，不能将其视为已完成整体匹配。

PlayerActor 的 25 个未解析成员来自自动生成表，但 player_actor.cc 仍有原生完整表，且自动生成表还继承了未正确覆盖的基类槽。不能仅补 25 个名字后宣告完成；需先确认原生表、部分 C++ 类接口与生成归属。此项未修改。

以上局部四版编译在用户要求 JP 优先前已经启动，已收完结果。后续先以 JP 分析、修正和局部验证，再按成立的依据推广海外。未重新执行完整构建，最后全局报告仍为 429 的链接失败报告。外部证据 link-references-430/{source-change,match}.json；未提交、未推送。

## 本次完整构建结果（批次 429）

按用户本次明确要求，执行一次四区域 WSL `make -k -j16 ... compare` 批次。使用 `-W tools/textproc/fomt-preproc` 强制更新依赖该工具的编译通道；正常图形及脚本依赖按 Makefile 构建。此为按当前依赖执行的完整目标构建，非删除全部产物后的 clean build。链接使用标准 `--strip-debug`，未加入 ROM 修补、特殊符号替换或 LDS 子段选择。

四版均在链接阶段失败，未产生本轮 ELF / ROM，不能进行本轮 SHA-1 或 ROM 字节差异统计。磁盘上既有 GBA 均已根据生成时间排除。此次是完整构建尝试，不是成功的完整字节验收；374 仅保留为历史成功生成 ROM 后的差异报告，不能将其剩余数量当作当前结果。

| 区域 | C++ 编译命令 | 汇编命令 | 未解析符号（去重） | 重复定义（去重） | 新 ELF / ROM |
| --- | ---: | ---: | ---: | ---: | --- |
| JP | 185 | 12 | 27 | 1 | 未生成 |
| US | 185 | 12 | 27 | 1 | 未生成 |
| EU | 185 | 12 | 27 | 1 | 未生成 |
| DE | 185 | 12 | 27 | 1 | 未生成 |

## 已确认的链接阻塞

各区域的完整符号清单见外部审计目录 `full-build-429/global-report.json`。按当前链接诊断分为：

1. `__vt_17GameSceneSavedMap` 同时在 `world_map.o` 与 `world_map_tables.o` 定义，需要统一真实虚表生成归属。
2. `player_actor_lifetimes.o` 中的虚表仍引用无法解析的 PlayerActor 成员入口，需要核对现有实现与 ABI 声明，不能靠伪别名补齐。
3. 另有一个分区域地址名函数和 `UiStateOwner::Update` 入口引用未解析，需恢复实际实现与调用名的联系。

链接器另报告损坏的 DWARF 行号信息。这是独立的调试信息诊断，不算 ROM 内容差异，也不能据此忽略上述链接错误。

## 全局符号和字面量盘点的边界

本轮四份 map 都是新生成、包含最终 OUTPUT 行的失败链接布局；已保存哈希并与经 baserom 校验的基准 ELF 做同名全局符号地址比较。明细为 `<region>-same-name-map-address-changes.json`。这只是当前链接尝试的布局，不能代替最终 ELF；符号地址改变不是错误数量，改名也未猜测配对。

已读取 map 实际选中的只读输入对象，统计 `bad_alloc`、`Error`、`N/A ` 的 NUL 终止字节出现次数，逐对象保留归属。统计不是手写文本定义数，数量相同也不能证明顺序和归属正确。

| 区域 | 同名基准符号 | 地址相同 | 地址变化 | bad_alloc | Error | N/A | 未读取的只读输入项 |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| JP | 18508 | 301 | 18207 | 107 | 17 | 0 | 0 |
| US | 18593 | 301 | 18292 | 107 | 18 | 13 | 0 |
| EU | 18593 | 301 | 18292 | 107 | 18 | 13 | 0 |
| DE | 18765 | 301 | 18464 | 107 | 18 | 13 | 0 |

原基准只读输入范围的字节统计为：四版 bad_alloc 均为 151，JP Error 为 17、海外为 18，JP N/A 为 0、海外为 12。与本轮相同范围类别的实际输入对象相比，bad_alloc 每版少 44 份；Error 数量相同；海外 N/A 多 1 份。所有本轮只读输入项均已读取，未跳过对象。这些是数量差，不是可以补填的字节配额，仍需逐归属定位。先前完成的是手写 bad_alloc 清除及部分真实编译单元恢复，不能表述为全部自然生成已验收完成。

## 尚待调整与验收

- 上述链接阻塞必须先消除；它们是本轮可以准确计数的阻塞，不是整个项目剩余任务总数。
- 425 的分配运行库 / `std::nothrow` 候选已通过局部匹配，但尚未推广；附近剩余运行库文本归属仍需确认。
- 428 的 NPC、漫游 NPC、世界道具、野狗对象已完成四版局部编译，比较分析尚未完成，不计作匹配通过。
- 其他历史差异组须以本轮新对象、符号及局部基准比较继续核对；本轮没有新 ROM，不能声称这些差异都消失或仅剩链接错误。
- 427 硬件上下文完整对象和 426 开场代码的局部验证结论仍保留，但不等于整个 ROM 匹配。

此批次后不自动进行第二次完整编译。仅当整个目标的修改完成，或用户再次明确要求时，才进行下一次完整编译。后续继续按全局报告分析、最小局部验证、推广的流程处理，不重新生成目标。

构建记录和 map、对象证据保留在外部审计目录。已完成区域的可再生成中间文件经逐文件 SHA-256 校验后归档到 I 盘；源码、对象、依赖、图形、脚本、ROM、审计记录均保留。未提交、未推送。


## 硬件帧操作的混合实现匹配（2026-11-08，批次 427）

全局报告中的 EnableHardwareForcedBlank / DisableHardwareForcedBlank 确认是实际指令调度差异，而非符号改名。两个入口及后续边界正确，但原 C++ 在更新显示状态和初始化临时命令时使用不同的寄存器顺序。直接半字字段、已有寄存器值访问器及提前构造命令的普通 C++ 候选均未匹配，未以寄存器绑定位或函数专用编译器规则处理。

两个入口现保留完整的四版共用符号化 Thumb 实现，共 164 字节；原 C++ 及局部候选保存于外部审计目录。原已匹配的硬件上下文构造/析构、帧更新及访问器继续使用 C++，三个命令的 Run/析构和四张类表仍正常由编译器生成。LDS、编译器、预处理器和 Makefile 均未改变。

使用 WSL make -j16 验证四版实际对象，hardware_context 的整个 .text 1340、.rodata 12 字节，以及 hardware_context_commands 的整个 .text 128、.rodata 48 字节，全部匹配各自 baserom；所有导出入口/数据位置一致。此轮改善匹配和动态引用覆盖，不计为新增 C++ 反编译进度。证据 hardware-context-427/{match,applied,probe,before-native-match}.json。未整版构建或提交，最后完整报告仍为 374。

## 启动场景完整代码的现状核验（2026-11-08，批次 426）

此前 423 仅验证 intro_scene 的 34 字节普通只读数据。本轮复用该轮实际对象，逐字节核对其整个 .text：JP 11924 字节，US/EU/DE 各 11892 字节，四版均匹配 baserom，所有导出函数边界也一致。四版当前源码及全部头文件经过预处理后与缓存编译输入完全相同，因此没有重复编译。

374 全局报告曾把 ConstructIntroSceneCore 列为同长度代码差异；其核心问题是审计对应表未识别旧 gIntroSceneCoreVTable 与恢复真实继承后 __vt_14IntroSceneCore 的关系。本轮依据类定义、初始化器和原表布局补充只读比较对应关系，未改游戏符号、LDS、编译器或 ROM。不能把审计中的旧名对应当成项目中新增别名。

这一结果覆盖 intro_scene 主体完整代码及既有已验证数据，不覆盖独立 intro_scene_lifetimes 的全部析构/表生成，亦不代表最终链接地址或整版 SHA-1 通过。SRAM 尾部待定来源继续保留；未因这一局部匹配恢复手写库字符串。证据 intro-code-review-426.json、intro-code-current-evidence-426.json。最后完整报告仍为 374。

## 分配运行库零对象的候选归属（2026-11-08，批次 425；尚未应用）

旧 GCC 自身的 g++/cp/new.cc 定义 const std::nothrow_t std::nothrow = { };，项目使用的同版 <new> 也声明了它。当前 src/new.cc 保留相应分配接口，却缺少该对象定义。临时恢复这一标准库对象后，旧编译器自然输出 10 字节 bad_alloc、2 字节对齐和 4 字节 nothrow 对象；不是手写空字符串或填充数组。

四版候选整个 .text 180 字节、.data 4 字节、.rodata 16 字节均直接匹配 baserom；原有代码和数据与控制对象一致。只读数据位置对应 SRAM 签名后第一份库字面量及此前命名为 EmptyText 的零对象。这是结合旧库源码与实际编译结果的候选识别，原 ROM 没有提供证明对象名称的原始符号表，不能仅凭零字节把它视为已最终确认。

此轮没有改游戏源码或 LDS。邻接的另外两份库字面量及海外版 Error/N/A 归属仍未解决；目前不能把 new.o 简单加在含整段尾随内容的 sram_image.o 后面。先保存候选与对照证据，待相邻归属理顺后一起恢复普通对象顺序。未整版构建，最后完整报告仍为 374（0/4 SHA-1）；最新已应用启动改动仍是 424。证据 allocation-runtime-425/{match,conclusion}.json。

## 启动入口的真实分配依赖及普通数据条目（2026-11-08，批次 424）

AgbMain 原有 new GameIntroScene 是实际场景创建路径。本轮为它显式引入同一旧标准库的 <new> 分配声明，保留原调用与类型；没有新增用于产生字节的分配动作、类型、异常或字符串。该编译单元自然输出 10 字节库字面量。四版 LDS 在 crt0_data 普通数据之后补上遗漏的 src/main.o(.rodata)，对应初始化数组与 SRAM 签名之间的原始位置，不使用固定地址或细分 section。

WSL make -j16 对四版实际 main.cc 局部编译。整个 .text（JP/US 340、EU/DE 360 字节）、.rodata（10 字节）和 .iwram（48 字节）均直接匹配各自 baserom。检查卡带移除回调的重定位时使用真实 IWRAM 运行地址，ROM 装载地址仅用于读取对照字节。数据末尾两个零由下一对象既有对齐承担，未增设填充数组或手工字符串。

此项恢复启动入口的正常源码依赖及链接归属，不代表 SRAM 后续字面量或完整 ROM 已匹配。编译器、预处理器、Makefile 均未改变；未整版构建或提交。证据 main-dependency-424/{match,applied,source-before}.json。最后完整四版报告仍为 374。

## 启动场景数据归回真实调用模块（2026-11-08，批次 423）

InitializeIntroSceneSequenceResources 直接消费 gIntroSceneStartupBgTilemaps，而该表此前单独位于 intro_scene_startup.cc；intro_scene.cc 自身有真实的场景转换/淡入对象分配，但其普通 .rodata 未列入 LDS。本轮将表并入实际调用模块，定义放在实现依赖之前；已有 <new> 及间接依赖按正常编译规则输出后续库字面量，没有新增无用依赖或手写副本。

四版实际源码经 WSL make -j16 局部编译后，整个普通 .rodata 均为 34 字节：四项真实资源指针在 +0，编译器自然生成的 bad_alloc 在 +16，原有 Error 文本在 +28。四版载荷和具名对象偏移均直接匹配各自 baserom；下一对象的 4 字节对齐对应原版两个零，沿用输出段既有零填充，不新增 LDS 对齐、固定地址或 section 子项。本轮不以数据通过宣称整个 .text 或 ROM 通过。

删除独立的 src/intro_scene_startup.cc/include/intro_scene_startup.hh，声明并入 include/intro_scene.hh；四份区域文本改为 data/text/<region>/intro_scene.cc。每份 LDS 仅把原独立对象替换为 src/intro_scene.o(.rodata)。源码未增加 Error 或 bad_alloc 文本内容，保留的 Error 来源尚未定性为库生成内容。未改编译器、预处理器和 Makefile，未整版构建或提交。证据 intro-data-423/{match,applied,source-before}.json。

## 教学场景完整原生生成单元（2026-11-08，批次 420–422）

420 的临时虚表归属拆分试验未推广。它将身份确认虚表移入另一个对象，但经开始菜单、存档、背包模板间接引入 <new>，同时增加字面量。背包模板实际使用 placement new，不能为排除输出而删掉真实依赖。这不是已应用修改的回退，也没有重新增加手写 bad_alloc。

421 将四版原 ROM 的全部 bad_alloc/Error/N/A 空格结尾字面量与绝对地址候选进行交叉核查，包含内部偏移及未对齐位置。每版 151 个 bad_alloc 均没有位于基准 .text 的绝对地址候选；不能由此排除间接地址计算。三个被代码引用的 Error 分别对应教学回调 35 处、AScriptEngine::GetString 1 处及 ScriptEngine 回调 39 处。音频/资源内碰撞值只记录为候选，未修改数据。此项是引用范围证据，不是编译单元归属完成。

根据 419 已排除的生成方案，422 将教学回调、Run、两项析构调整入口、派生/基类析构及四张 ABI 表作为完整原生单元恢复到 src/farming_tutorial.cc。原版融合回调只做一次 this 调整，不再生成独立普通 OnCall 副本或额外包装。C++ 类接口、真实构造及工厂保持现有实现。此前已匹配的隐式析构在本单元中改为相同字节的原生实现，以免虚表生成再次带出重复调整入口；完整 C++ 候选保存在外部 farming-tutorial-cpp-before-422.cc，没有将这一项计为高级语言推进。

四版共享回调、析构和虚表源码，Run 仅对实际差异使用地区条件。WSL make -j16 编译实际项目路径中的四版教学对象及原 C++ 构造调用方共八个对象。整个普通 .text 为 JP 10024 / 海外 10044 字节，普通 .rodata 为每版 64 字节，全部直接匹配各自 baserom。每个原生对象恰有六个全局代码入口及四张虚表，构造调用方引用这些表且无重复定义。局部比较只读解析重定位，没有改写编译输出。

未添加运行库文本、固定 ROM 地址、别名、LDS 子项或工具特判，未改编译器/预处理器/Makefile/LDS。证据 metadata-header-trace-420.json、runtime-reference-ownership-421.json、tutorial-native-422/{original,match,applied}.json。尚未执行新一轮完整构建或提交；全局验收仍以 374 为最后完整报告，不能把本轮对象匹配扩大成整版匹配。

## 教学回调归属的局部排除验证（2026-11-08，批次 419）

读取当前编译器 import_export_class / import_export_decl / finish_file / emit_thunk，结合三个临时实际源码对象核查普通类归属的替代方式。取消教学场景的 interface/implementation 且保持 Run、OnCall inline 时，回调对象不生成所需入口和虚表；将 Run 改为普通函数可恢复类归属，但仍输出 7702 字节普通 OnCall 和 7706 字节调整入口，且 Run 移到调整入口之前。工厂对象还会额外生成基类 GNU linkonce 项，不能推广这一方案。

上述试验仅在外部临时源码中进行，项目源码、编译器、预处理器、LDS 均未因此修改。不以删除生成结果或特殊符号规则掩盖重复入口。当前已匹配的隐式析构保留；回调、虚表、析构及运行函数的整体归属仍未解决。本轮是排除证据，不计为新增匹配字节或完整构建通过。证据 tutorial-emission-review-419.json / tutorial-emission-419。

## 菜单与世界构造的四版共享原生实现（2026-11-08，批次 418）

综合 415 的实际对象差异，菜单构造为原版 914 / C++ 候选 902 字节，世界构造为原版 1048 / 候选 1044 字节，涉及临时对象布局及寄存器分配。核对四版原 ROM 后，这两个函数各自的完整指令、成员常量和真实符号表达均完全一致；没有地区补偿或独立二进制分支。

在各自 src/new_game_menu.cc、src/game_world.cc 原位保留完整共享汇编入口，移除只服务于未匹配候选的局部 inline 辅助函数，候选完整保存在外部接续记录。其他 C++ 函数和既有类型保持不变；菜单虚表仍由 new_game_menu_lifetimes.cc 的真实实现归属产生，世界虚表继续由 game_world.cc 的 C++ 定义产生。此项不能计为新增高级语言完成量。

WSL make -j16 编译八个实际对象。四版菜单 914 字节函数及 2 字节自然对齐、世界 1048 字节函数均直接匹配各自 baserom。前者 39 处、后者 41 处调用/指针均通过真实符号重定位；世界全局控制器使用现有 gCurrentGameSceneScriptController 名称。首次局部组装发现同一文件重复 include asm/macro.inc，已按单个汇编单元仅引入一次修正，无工具链特判。

证据 constructors-native-original-418.json、constructors-native-match-418.json、limited-runtime-418。未改变编译器、预处理器、Makefile 或 LDS；未整版编译、提交、推送。教学场景的回调重复入口、运行库字面量归属等问题仍待处理；完整四版报告仍为 374。

## 身份初始化的完整符号化入口（2026-11-08，批次 415–417）

依据全局 374 报告，局部重编译身份初始化、菜单初始化和世界对象构造三个 JP 对象。当前尺寸分别为 556/902/1044 字节，原版为 548/914/1048 字节；本轮没有据此重建整版。身份初始化直接读取 GameDate 位域可以消除参数栈存取并恢复 548 字节，但完整指令仍不匹配，不能把尺寸一致当作完成。

保存 C++ 候选与诊断后，在 src/new_game_identity.cc 原位恢复完整身份初始化汇编。所有调用、虚表及 JP 月/日文本使用符号；成员偏移使用现有头文件布局定义，未恢复固定 ROM 指针。US/EU/DE 的指令和符号表达完全一致，共用一份实现；JP 保留实际格式差异。现有 C++ 析构、场景实现及编译器生成的虚表保持各自唯一归属。

WSL make -j16 编译四版实际对象。构造入口到下一函数边界分别为 JP 548 字节、其他三版 460 字节，按基准符号只读解析重定位后全部直接匹配各自 baserom，差异字节为零。此项是恢复匹配汇编，不计新增 C++ 完成；菜单、世界构造和教学回调等剩余问题仍未完成。

证据 constructor-instruction-review-415.json、identity-actual-match-416.json、identity-native-original-417.json、identity-actual-match-417.json 及 limited-runtime-417；候选保存在外部 new-game-identity-cpp-before-417.cc。未修改编译器、预处理器或 LDS，未整版构建、提交或推送。最后完整四版报告仍为 374，0/4 SHA-1 匹配。

## 混合实现修复铁匠铺结果转换入口（2026-11-08，批次 414）

按更新目标采用匹配的 C++ 与符号化汇编共存。全局 374 报告中的 BlacksmithShopResultTransition 析构为原版 38 字节、当时生成 48 字节；原版完整函数在四版仅有两处调用重定位差异，清理 continuation 后转入 SceneTransition 基类析构，没有重新写入自身虚表。不能为它修改所有显式析构的通用语义。

保留 scene_blacksmith_transition.cc 中已经恢复的 CreateScene C++，将尚未匹配的空析构定义替换为原版完整可读汇编，使用真实成员 ABI、局部分支和 _call_via_r2 / SceneTransition 析构符号。未添加原址、字节补丁、别名、自定义 section 或独立源文件。原候选 C++ 定义和差异保存在外部接续记录中；这项是恢复匹配汇编，不能计为新增 C++ 反编译完成。

WSL make -j16 只编译四版该实际对象。CreateScene 72 字节、析构 38 字节均与对应 baserom 相同，整个普通 .text 含末尾对齐共 112 字节、相对顺序和全部字节均匹配。比较仅在内存中按 baserom 目标解析重定位，没有修改构建输出。模块其他数据归属及完整 ROM SHA-1 不在本轮验收范围内。

证据 blacksmith-hybrid-original-414.json / blacksmith-hybrid-review-414.json、limited-runtime-414。未改编译器、预处理器或 LDS，未整版构建、未提交、未推送。教学回调的独立公开 inline 输出仍未解决，不能用预处理器删除；接续目标已更新为 e8cc48a9 对应版本。

## 钓鱼查询的真实依赖纠正（2026-11-08，批次 413）

移除 fishing_area.cc 独立引入的 <new>：完整查询函数只读取 Location 和八条边界记录，没有分配或库类型依赖。此前 408/412 的 202 字节数据匹配仅证明输出字节一致，不能证明这个头文件具有真实用途，不能把它作为已恢复自然生成的证据。

WSL make -j16 局部编译四版实际 fishing_area 对象。直接对照各自 baserom，166 字节 GetFishingArea 完整指令及常量池均一致；对象偏移 140 的表引用是 gFishingAreaBoundaries 的 ABS32 重定位、加数为零。192 字节八记录边界表也全部一致。原版表后另有 10 字节 bad_alloc，其真实编译单元归属仍未解决，没有以文本、填充、无用依赖或链接补丁恢复。当前普通 .rodata 为 192 字节，不能继续把这个模块计为 202 字节全块匹配。

证据 runtime-dependency-review-413.json 与 limited-runtime-413 四版原始产物。未整版构建、未提交、未推送。早段六模块的运行库字面量/次序缺口，以及教学回调重复入口仍待处理。

## C++ 普通数据段默认输出及预处理简化（2026-11-08，批次 409–412）

409 使用四版既有对象及基准符号作全局候选盘点：101 个模块此前已显式关闭数据拆分，另外 77 个候选模块仍出现多个普通 .rodata 输入段，其中 72 个有四版既有对象、5 个只有三版。既有对象可能早于当前源码，这些数字只表示候选覆盖，不能计为当前构建通过率。记录 ordinary-rodata-inventory-409.json。

410 在 8 个实际早段模块上局部验证普通数据输出。field_data 和 new_game_name_entry_ui_data 的整个 JP 数据载荷及具名对象偏移匹配；后者起点 0x080F97E6、输入对齐 2，不需要强行按 4 字节抬高。其余 6 个存在尚未恢复的库字面量或内部次序差异，已保存不同锚点基址，不能误判为删除拆分参数就全部恢复。

依据 408/410 对普通数组、匿名库字面量、混合文本以及 2/4 字节对齐的验证，将 C++ 默认输出改回普通数据段：移除全局 -fdata-sections，同时删除各目标冗余的 -fno-data-sections（此前给 fishing 两对象新增的临时参数条目也移除）。弱符号及实际接口实现选项保持原有区分，不改变类所有权。预处理器删除具名段改写为同名 unique .rodata 的函数、仅服务它的源码标签扫描及相关旧自检片段；不再靠变量名推断和改写数据段。保留普通可执行段收尾、现有可选 reservation 接口及其边界判断，不开展汉化工作。

WSL 重新编译 fomt-preproc 并通过已有 self-test。412 使用更新后的工具和实际默认参数 -j16，仅编译 field_data、new_game_name_entry_ui_data、fishing、fishing_area 四模块四版共 16 个对象。四个版本每模块的数据载荷均为单一普通 .rodata 并与 baserom 一致：农田规则 2312 字节，名字输入 UI 为 JP 430/海外 462 字节，钓鱼两块为 2030/202 字节。前两模块同时核对具名对象偏移，后两模块以完整载荷在基准 ROM 中唯一出现的位置核对；不把临时报告里缺少旧符号名映射当成字节差异。

此批完成通用输出方式推广，不代表其他 77 个候选或整 ROM 已验证。库字面量缺口、原合并主题的真实编译单元边界、匿名常量次序、函数指令差异仍须处理，尤其 fishing_area 的独立 <new> 来源尚未证明。未改 LDS 或编译器，未整 ROM 构建、未提交、未推送。证据 ordinary-rodata-review-410/412.json、fishing-natural-rodata-412.json 和 limited-runtime-410/412 原始输出。

## 普通只读段顺序及钓鱼数据验证（2026-11-08，批次 405–408）

405 对教学回调及 Run 的完整原版/当前对象指令序列作差异索引，区分栈临时值、调用、寄存器分配、常量池和布局问题；该索引只用于定位，忽略部分分支目标，不能作为匹配证明。旧 cp 的 import_export_decl/finish_file 证实，明确实现方会输出公开 inline 成员；不能仅因当前调整入口已内联，就通过预处理器删除独立 OnCall 副本，否则未证明其他调用方仍可用。此副本仍未解决，未修改编译器。

Run 的初始 DISPCNT/BLDCNT 写入在原 ROM 中有半字值临时对象；恢复为已有 HardwareDisplayRegisterValue 接口，并为 HardwareDisplayState 增加对应 SetDisplayControl 普通成员。406 JP 局部输出恢复相关临时值写入，Run 为 2138 字节（原版完整范围 2144），仍存在寄存器/指令差异，不能按接近长度认定匹配；四个已经匹配的析构/调整入口保持匹配，OnCall 副本仍为 7702 字节。

407 编译此前恢复的钓鱼实际源码，发现 -fdata-sections 与普通 .rodata 混用会把后生成的 bad_alloc 追加到最早的普通段，排在独立数组段之前；现有同名 unique 规范化没有解决这一顺序问题。408 在实际两个对象上取消数据拆分，不修改预处理器或 LDS：四版 fishing 的单一 .rodata 均为 2030 字节，fishing_area 均为 202 字节，完整数据载荷各自与 baserom 唯一范围逐字节相同。JP 起点分别 0x08104994/0x08105184，US 0x08104E4C/0x0810563C，EU 0x08104EA4/0x08105694，DE 0x08105870/0x08106060。上述地址仅用于审计，没有写入构建规则。

验证后这两个对象已使用 Makefile 的 -fno-data-sections，普通对象内部自然保存文本/表/库字面量次序，不增加工具或逐变量属性。不能直接全局去掉此标志：现存未对齐模块起点、不同对象对齐关系仍需整体筛选。当前三个钓鱼函数分别为 180/1562/166 字节，不将数据匹配计为代码匹配；钓鱼选择器原版 1628 字节。区域模块已有的独立 <new> include 仍缺少充分的实际依赖/原编译单元证据，匹配其字面量不能证明源码归属已完成。

记录为 tutorial-instruction-diff-405.json、interface-review-406/407.json、fishing-natural-rodata-408.json，保留局部原始输出。未整 ROM 构建、未提交、未推送。下一步优先筛选普通 C++ 数据段的可合并范围，并继续核对真实运行库依赖；教学回调与钓鱼指令差异保持未完成记录。

## 隐式析构的局部验证与 NPC 家族推广（2026-11-08，批次 401–404）

农业教程中两个没有额外清理逻辑的类不再声明/定义手写空析构，改由真实继承关系和成员生成隐式析构。401 的 JP 实际对象验证：两个调整入口各 12 字节、派生析构 168 字节、基类析构 10 字节，尺寸及非重定位字节与 baserom 一致；不再生成独立 44 字节 world-owner 清理入口。两个创建流程函数继续匹配。此前 400 记录中的过度展开析构入口及该 44 字节入口已解决；完整回调副本、回调/Run 指令差异及虚表和字面量归属仍未解决。

402 对当前源码的空析构作全局盘点；无自身虚表地址字面量只能作为筛选线索，不能直接决定删除。403 对 35 个定居 NPC 和 4 个游走 NPC 的四版原 ROM 共 156 个入口核对，全部为实际基类析构调用及返回；保持其本来的虚析构语义，删除冗余的 39 份派生声明与空正文。npc_actor_lifetimes.cc 仍是两套具名接口的唯一实现单元，没有拆新文件。

首轮使用原正式参数编译成功但 .text 为空，说明旧 -fno-implement-inlines 会抑制隐式析构；这不是成功生成的证据。随后将该对象移到 Makefile 已有的 -fno-weak -fno-data-sections 组，移除这项抑制，不新增编译参数或工具补丁。404 使用 WSL make -j16，仅编译四版这个实际对象。每版均生成 39 个所需函数和 41 张虚表；按各版 baserom 的真实目标解析调用/表项重定位后，全部对象内容一致，函数之间及虚表之间的相对物理顺序一致。没有未解析的比较目标。此结果是对象级验证，不是整 ROM 链接或 SHA-1 验收，前缀字面量的全局摆放仍须统一核对。

本批未修改编译器、预处理器或 LDS，未提交、未推送。最近完整四版报告仍为 374，0/4 匹配；393 为取消/失败记录而非完整报告。证据为 interface-review-401.json、empty-destructor-inventory-402.json、npc-implicit-403-evidence.json、npc-implicit-review-404.json 及 limited-runtime-403/404 原始输出。

## 实现归属修正及局部推广（2026-11-08，批次 394–400）

继续采用用户确认的流程：复用全局报告，按通用问题局部验证、推广，再处理下一类，全部完成后才进行整体构建。此前 393 提前开始的构建已停止：JP 链接失败、US 中途取消，EU/DE 未运行；它不是新一轮完整四版结果。最近完整四版对照仍是 374，四版均未匹配 baserom。

核对实际旧 cp 的 handle_cp_pragma、interface_strcmp 后，确认无参数 implementation 并不是局部“恢复普通头文件状态”的指令；它会登记当前主文件为实现方，造成与显式 lifetimes 实现方重叠。先在仓库外头文件副本及两个实际启动场景对象上验证，再删除工程 include/src 中 230 条这种无参数声明。现有具名实现声明保留；script_vm、farming_tutorial 补上其真实头文件的显式实现归属；普通按键参数结构不再使用多态类接口 pragma。当前 116 个具名接口目标均有显式实现声明，此静态覆盖不等于所有生成顺序已验证。

局部编译使用正式编译参数和 WSL make -j16，产物留在仓库外，不链接 ROM。394–400 的选定 JP 对象集合覆盖此前报错的 11 组、22 个对象；原日志中的 25 个重复符号在这组对象中均只剩一个强定义，未发现新的重复强定义。启动场景、飞盘、VM、硬件输入等可按原符号准确配对的函数分别核对 baserom 的尺寸与非重定位字节；它们不能替代最终重定位及完整 ROM 验收。new_game_menu 的核心初始化仍为 902 字节，原版为 914，该差异在本轮修改前已存在。

同时发现普通辅助类型被错误纳入接口实现范围会额外生成独立方法。飞盘清理实现移回唯一实际使用的 cc 后，多余 44 字节入口消失，12 个原函数仍通过非重定位字节核对；按相同使用关系推广另外 18 处。联机、料理、日历的普通 owner 声明移到本头文件的接口范围前，日历清理正文归实际生成场景析构的单元。农业教程世界的普通转移/所有权类型也与虚接口分开，依赖完整世界类型的清理和赋值正文归实际使用的教学场景。未新增源码文件、编译参数、编译器/预处理器补丁、LDS 子项或地址补偿。

此批仍有明确未完成项：教学场景继续生成大回调副本、过度展开的调整入口，以及一份实际被使用但原版无独立入口的 44 字节 world-owner 清理函数；虚表和字面量次序仍待解决。木匠及牧场商店的场景析构仍含原生汇编，未盲套正文移动。其他无参数声明清理所影响的辅助类型仍需归属复核。四版共享源码均已更新，但当前局部输出仅为 JP；尚无新的四版 SHA-1 验收，不提交或推送。

证据：interface-source-395/changes.json、interface-inventory-395.json、owner-inline-plan-397.json、helper-ownership-399/files.json、interface-review-394/395/396/400.json、interface-summary-398/400.json，以及对应原始预处理输出、汇编、对象和日志。

## 全局运行库引用核查与获准的最小编译验证（2026-11-08，批次 390–392）

用户允许在整 ROM 静态阶段完成前，进行最小范围模拟编译，以提前判定当前调整是否正确。此授权取代此前“任何局部编译均禁止”的限制；不代表恢复反复整 ROM 构建或扩大到无关测试。本轮在 WSL 中通过临时 Makefile -j16，仅按正式管线和现有编译参数编译实际 US 源文件，产物置于仓库外的审计目录，不覆盖基准或正式 build 产物，没有链接 ROM。

先完成四版原 ROM 运行库字面量的全局绝对地址候选核查，包含指向文本内部及结束零的值、四种字节对齐，并结合既有可执行范围的 Thumb PC 相对读取筛选。每版 151 份 bad_alloc 均未发现这类代码常量池读取；少量原始字节命中位于其他数据范围，不能直接认定是指针。Error 的代码常量池读取均集中于三份：基础 AScriptEngine::GetString、ScriptEngine::OnCall、FarmingTutorialScene 的调整后回调；各对应 1、39、35 处池项。N/A / 日文“なし”的相应读取集中于玩家钓鱼状态和钓鱼结果选择器。无绝对地址命中不证明无计算型引用，此报告不授权删除对象；相关原始数据命中尚未逐个完成资源语义判定。结果保存 runtime-pointer-candidates-390.json。

批次 391 的两个实际对象都成功编译，但结果不同。script_vm 的 .text 为 0x970 字节，13 个函数相对地址和长度与 US baserom 一致；排除 ELF 标出的 ABS32/Thumb 调用重定位字段后，其余字节完全一致。普通 .rodata 自然输出 bad_alloc、对齐以及 Error；GetString 未成为未定义外部引用。该比较未解析重定位，不是完整字节或 SHA-1 验收。

教学场景同样编译成功，但验证否定了先前仅凭可见 inline 就足够的假设：多出完整 OnCall 普通副本（7702 字节）和构造函数（248 字节）；两份析构调整入口各展开为 180 字节，而原版为 12 字节。融合回调为 7706 字节，原 ROM 实际完整范围为 7676 字节，不能拿旧 ELF 上错误的 12 字节 size 当作回调体长。普通 .rodata 同时含字面量和四份表，物理顺序问题仍在。没有据此添加编译器特化或 LDS 子项。

已将 FarmingTutorialScene 构造函数的实际 inline 定义从类头移到唯一创建调用所在 src/farming_tutorial_transition.cc；类头保留普通声明，初始化顺序和表达式不变。批次 392 仅重编译受影响的场景及创建流程对象：248 字节独立构造副本消失，创建流程的两个函数分别为 28 和 296 字节，与原版尺寸及非重定位代码字节一致。没有新增构造包装、别名、宏、编译选项或源码文件；编译器与预处理器未改动。

证据为 limited-runtime-review-391.json、limited-runtime-review-392.json，以及对应目录下原始汇编、对象、重定位记录和日志。尚待处理：回调独立副本、析构调整入口展开与顺序、真实析构差异、教学虚表与字面量的分别归属、其他运行库输出单元。JP/EU/DE 共享源码但本次未编译，不声称四版已匹配；整 ROM 统一验证仍未开始。未提交或推送。

## 脚本解释器与游戏分发器的源码边界（2026-11-08，批次 389）

按四版基准 ELF 定位并与各自 baserom 的实际代码逐字节核对：AScriptEngine 构造到 GetString 末尾均为 0x970 字节，包含 13 个方法，下一函数均为 ScriptEngine(void*) 构造。JP 为 [0x0803EB08, 0x0803F478)，US 为 [0x0803EE94, 0x0803F804)，EU 为 [0x0803EEA8, 0x0803F818)，DE 为 [0x0803ED8C, 0x0803F6FC)。这里核对的是既有原版参考，不是本轮新编译结果。

字节码装载、操作数解码、栈和指令执行已归入 src/script_vm.cc；游戏场景相关的 ScriptEngine 构造、native callable、VarGet/VarSet 留在 src/script_engine.cc。前者原有函数主体未重写，后者原生汇编完整保留，未因为拆分而新增代理、函数或指令。std::__lower_bound 的 extern template 声明随真正使用方一起移动；显式实例与类虚表的已有所属文件不变。源码拆分依据实际功能和连续函数边界，不仅依据相同字符串出现次数；不能据此声称已经证明原作者的源文件组织。

include/script_vm.hh 提供真正的 AScriptEngine::GetString inline 实现，script_vm.cc 为它的同名实现单元；include/script_engine_base.hh 继续提供基类声明与布局，独立的虚表所属文件仍仅包含这个声明头。GetString 保留原有 <= 判断和 Error 返回分支。教学回调包含真实实现头，不再必须依赖一个不可见的外部函数体；没有以宏、匿名字符串重写或编译器函数名判断补偿内联。四份 LDS 各增加普通 script_vm.o(.text) 与 script_vm.o(.rodata)，紧邻 script_engine；没有增加固定地址、GNU 子项或逐符号 section。

静态核对旧 cp 的 cp/decl.c、cp/decl2.c、cp/lex.c、cp/method.c 和 varasm.c 后，仍有明确限制：inline 声明归属与 class/vtable 归属不是同一个决定；mark_vtable_entries 会产生调整入口，字符串在表达式展开时进入本编译单元常量池。教学场景的虚表与函数字面量在原 ROM 中处于不同物理区间，目前合并对象的组织尚不能证明恢复该顺序。旧 common_ui Error/N/A 与 native ScriptEngine 的相应符号暂未盲删，也没有为了补出 bad_alloc 而添加不使用的库 include。此处仍是未完成项，不以 LDS 外观整洁代替恢复输出顺序。

审计记录为 script-vm-ownership-389.json。未运行 CPP、编译器、汇编器、链接器或测试；未修改编译器/预处理器，未提交或推送。完整静态阶段未完成，四版 SHA-1 尚未重新验证；后续统一验证仍使用 WSL make -j16。

## 完整教学回调恢复为四版共用 C++（2026-11-08，批次 388）

从两套既有原生主体提取完整分发表、物理分支、调用和共享出口，依据项目内 Mary callable 清单对照。JP/海外均为 322 个槽位、54 个独立实现；支持 ID 集合相同，规范化后的各分支外部调用序列无差异。提取器已处理“标签与首条 .word 同行”的 JP 表头，避免漏掉第一项导致所有 ID 错位。原始读取材料和逐分支索引保存在 farming-tutorial-*-native-388.s 与 farming-tutorial-dispatch-388.json；这些临时审计材料不参与正式构建。

完整 OnCall 已写成 src/farming_tutorial.cc 内四版共用的普通 C++，不是部分分支代理。覆盖对白开闭、三种速度、带提示/不带提示的二至六选项、等待、淡入淡出、地图/镜头、音乐池、实体坐标/朝向/动作、脚本装载、教学农田/鸡蛋及玩家物品动作。保留 Top 后 Pop 的原顺序、空栈已有行为、GetString 的原有 <= 比较、16 位时间/资源截断、缺失实体判断、有效/无效参数路径及脚本继续返回 0 / 等待返回 1 的区别。没有把所有已实现分支统一改为等待，也没有增加原版不存在的边界钳制。

原先误作为独立函数导出的 sub_080DFE84 实际没有自身栈帧和返回，而是调用寄存器里的目标后直接跳到整个回调的公共结束路径。镜头移动等分支以 BL 当作长跳转进入它；不能据此推断返回后会继续落入后面的等待分支。现由各真实世界虚函数调用和返回 0 表达，不保留假函数、别名或地址补偿。

OnCall 与 Run 定义均使用实际 C++ inline，使原有 thunk 生成路径能够看见回调主体。已静态核对实际 cp 的 emit_thunk 与显式 inline 大函数规则，没有修改编译器来识别某个游戏函数。配套消息适配器 func_08050DB4 改用 UiStateOwner const*、char const* 和 u16 参数，移除其文本整数化；C 符号/寄存器 ABI 不变。func_080323F0 的真实声明归入 entity_actor.hh，不创建额外包装。当前 farming_tutorial.cc 已无内嵌汇编。

此批解决源码完整性及可见实现，不能预先声称编译器已经输出原版融合形态。GetString 的跨编译单元内联、旧独立 Error 对象的收回、潜在独立成员副本和完整函数/析构/表的顺序仍需继续核实；旧 Error 数据尚未盲删。farming-tutorial-callback-388-coverage.json 同时记录这些限制，54 个槽位覆盖不等于字节或运行验证。未执行 CPP、编译、汇编、链接或测试，未修改 LDS、编译器、预处理器，未提交或推送；完整静态阶段仍未结束。

## 教学脚本回调的真实成员入口与自然虚表（2026-11-08，批次 387）

先核对开头的初始化表及 SRAM 范围。init_array 的首字确实由启动循环作为计数读取，但后面三个零字的原始生成形式仍未定性；SRAM 标识后的三份库副本及海外 Error/N/A 也缺少足够的真实编译单元归属证据。本轮没有按副本数量拆分这些内容，没有添加假调用或仅凭相邻关系恢复头依赖；这些缺口仍保留在运行库归属审计中。

教学场景的重复入口则已具备实际 ABI 证据：原版完整回调先把 AScriptEngine 子对象指针减 12，再通过完整场景地址访问成员；381 既有编译输出会额外生成同名短 thunk，调用此前并未实现的 OnCall__20FarmingTutorialScenei。现把完整原生主体恢复为这个真实成员入口，两套地区分支各移除一次入口处 this 调整。由类的真实继承关系生成虚表调整入口，避免重复调整。对照上轮快照，除 ABI 入口名称、对应旧地址注释和这条入口调整外，整个原生主体的指令/跳表/常量池内容未变。

删除四张手工虚表和两个手工析构调整跳板，原有空析构函数体原样归回 farming_tutorial.hh。移除 farming_tutorial_tables.cc、farming_tutorial_lifetimes.cc 和额外 lifetimes 头，使用已有普通 C++ 所有者选项由 farming_tutorial.cc 生成。四份 LDS 只各保留一条该对象的 .text 和 .rodata；没有恢复 GNU 子项、特定 section、地址限定、别名或编译器特化。

这一步恢复的是类接口、成员 ABI、自然表生成及动态链接归属，不等于原版生成已经匹配。原版融合了调整和大回调主体；目前独立成员主体加自然短调整入口仍会有代码生成/顺序差异，后续必须继续恢复真实可见的 C++ 回调/内联关系，不能用短跳板阶段替代最终匹配。原始符号表把融合入口 size 标成 12，实际 ROM 主体远大于 12；本轮证据按完整入口到 Run 的真实边界记录，不能再用该 size 当完整函数长度。

farming-tutorial-abi-owner-387.json 保存四版原入口、真实范围、四张表、普通 LDS 条目和源码变化核对。静态引用与 diff --check 已检查，没有启动 CPP、编译器、汇编器、链接器或测试，没有修改编译器/预处理器，没有提交或推送。运行库归属、回调融合及完整 ROM 匹配仍未完成；完整静态阶段结束后才统一 make -j16。

## 库字面量总览与钓鱼区域独立归属（2026-11-08，批次 386）

复用已保存的原版字符串位置，并回读四版 baserom 确认字节，再结合既有 ELF、删除记录、当前定义和 include 关系建立 runtime-source-ownership-386.json。四版各有 151 处 bad_alloc；JP 有 17 处 ASCII Error，海外版各有 18 处 Error 和 12 处 N/A。这是字节出现数，不代表有对应数量的实际调用或已证明的编译单元；JP なし 等地区文本不在此 ASCII 总数中。全局候选表明确区分已有自然接替证据、源码归属候选和仅沿用旧链接对象名的较弱推断，尚不能全部定性。

用户已允许：只有证据充分时，连续同主题内容也可按真实功能/编译单元边界拆分。钓鱼区域判定满足完整独立入口、连续八条矩形记录、独立调用及四版第二份库字面量等证据，恢复 src/fishing_area.cc + include/fishing_area.hh；钓鱼抽选仍由 fishing.cc/.hh 管理。区域数据和 GetFishingArea 的既有实现原样迁移，边界表的 192 字节逐版与原 ROM 一致。四份 LDS 的 .text/.rodata 均将新对象紧接 fishing.o，各对象各列一次，没有新增地址、子 section、补偿或链接后处理。game_world.cc 直接包含所需的 fishing_area.hh，不再为区域查询引入默认鱼获构造。

同时将 188 字节原生 GetFishingAttemptParameters 恢复为共用 C++：无效区域清零两项时间；06..08、09..16、17..19 及其余时段选择原延迟列；秒数转为 60 帧，保留一次原随机调用、带符号区域检查及六帧单位的反应窗口。连同上批选择函数，fishing.cc 中已无整函数汇编。只表示源码已恢复，当前生成字节尚未验证。

源码组织现在先定义真实默认结果和捕获数据，再引入实现所需的完整 game_state 依赖；区域模块先定义边界表，再包含原版字面量来源的实际 <new> 库头。由普通头文件解析/函数展开承担库字面量生成，不添加本地 bad_alloc 定义、假调用或伪造类型，不改编译器/预处理器。该顺序是待统一验证的正常源码方案，不能先宣称字面量位置或 SHA-1 已匹配。

FarmingTutorialScene 的另一问题已追到实际 cp 的 auto-implementation 和 mark_vtable_entries/emit_thunk 路径；既有 381 汇编显示，自动生成的短调整入口与手工保留的完整入口同名。真实回调主体和自然虚表归属仍需恢复，不通过篡改 pragma 目标、删除实际虚函数接口或改名别名规避。静态记录和接续快照已更新，未编译、测试、提交或推送；完整静态阶段完成后才运行 make -j16。

## 默认鱼获文本随真实选择逻辑生成（2026-11-08，批次 385）

SelectFishingCatch 已由完整原生汇编恢复为四版共用的 C++，直接构造既有 FishingCatchResult。恢复了类别权重、正负候选池、随机调用顺序、稀有鱼条件、Article/Food 结果和记录更新；常量使用现有 Mary 定义，存档读取使用现有真实成员。没有添加生成字符串用的假调用或伪造类型。移除了 gText_Fishing_NoCatch 声明及四份独立区域文本文件，其原生引用已随该函数的恢复收回；玩家主体汇编使用的另一份 gText_NotAvailable 仍有真实调用，未删除。

逐分支核对明确：存档 +0x12 属于时钟小时，鮟鱇排除 08..19 小时；不是按日期限制。伊富鱼检查的是三个已学会的鱼料理，保存的料理编号为食物 ID + 1。候选失败直接返回默认结果，不重新抽选；首次记录与后续尺寸纪录的处理保持区分。原版四版该函数均覆盖 1628 字节，具体地址、原始字节哈希和审阅要点记录于 fishing-source-385.json。这是源码恢复，生成指令和完整 SHA-1 尚未验证。

同时检查实际 cp 的 STRING_CST 展开、常量哈希、延迟输出、内联收尾和 ARM 字符串对齐规则，记录在 literal-emission-385.json。Error、区域 N/A 与 bad_alloc 的真实源码来源不同，不能新增按字符串内容自动插入的编译器规则。另发现现有 fishing 合并范围保留过两份独立原版 bad_alloc；同一翻译单元的只读字符串常量池通常会合并相同字面量，因此仍需复核该合并范围的真实编译单元归属，不能靠重新手写副本填回。此疑点尚未以拆文件或编译器补丁处理。

普通源码字符转换已静态确认覆盖构造函数中的字符串。被删除的鱼获文本标签及 include 路径检索为空，相关源码 diff --check 通过。没有运行预处理器、编译器、汇编器、链接器或测试，没有修改 LDS、编译器和预处理工具，没有提交或推送。完整静态阶段仍未完成，后续统一验证使用 make -j16。

## 钓鱼结果默认值与实际记录归属（2026-11-08，批次 384）

静态追踪 N/A/なし 的实际使用。SelectFishingCatch 原生入口先构造 24 字节结果：name 指向地区默认名称、size 为零、RucksackItem 正常构造、两个状态字节为零、记录 ID 为 59、最后状态字节为零。玩家原生构造及钓鱼动作中存在相同的字段初始化；选择函数返回后，以两次三字复制把完整结果写入玩家 +0x60。

现给既有 FishingCatchResult 补齐对应的真实默认构造函数，地区名称直接作为其初始化字面量，记录哨兵使用已核对值为 59 的 FISHING_RECORD_COUNT。没有增加数据成员、无用调用、伪造类型或额外生成工具；现有 24 字节布局及字段偏移检查保留。SelectFishingCatch 与玩家主体仍是原生汇编，尚未将它们计为 C++ 恢复；其仍在引用的 gText_Fishing_NoCatch / gText_NotAvailable 不能在这一步假定已经收回。

四版 getter 的真实 ROM 字节均为 60307047，即 adds r0,#0x60; bx lr。结合完整结果复制、虚表 +0x90 槽及 GameScene 包装调用，PlayerActor 与 GameScene 的 GetCaughtFish 返回类型统一改为 FishingCatchResult const*，删除未定义的 GameSceneCaughtFish 占位。头文件只前置声明所借用的真实记录，不引入无关重型依赖。

两套旧地址函数名 func_08031DBC / func_08032028 已改成与实际 C++ 成员接口一致的 GetCaughtFish__11PlayerActor，四版共用一次完整汇编定义，虚表直接引用该符号。没有 .set、地址别名或 +offset 补偿。原版对应地址 JP 0x08031DBC、US 0x08032028、EU 0x0803203C、DE 0x08031F3C；catch-record-384-evidence.json 保存逐版字节和归属，改名证据同步进入后续全符号对照清单。

此批确认了一个区域默认字符串的真实业务构造来源，不能据此把所有 N/A、Error 当成标准库内容，也未证明每个编译单元的常量输出位置已经正确。匿名字面量的自然生成、旧汇编引用收回及完整 ROM 排列仍待后续静态整理和统一验证。

旧占位类型、旧 getter 地址名及手写 bad_alloc 的源码残留检索为空，diff --check 通过。只读取既有 ELF/ROM，没有运行 CPP、编译器、汇编器、链接器或测试。未修改 LDS 或编译器，未提交或推送；后续构建仍遵守完整静态阶段完成后的 make -j16 门槛。

## Error 默认返回值来源恢复（2026-11-08，批次 383）

本轮静态核对 Error、N/A 和 JP なし 的定义及源码调用候选，完整索引保存在 error-fallback-origins-383.json。索引同时包含实际游戏文本，不能把同词条出现次数当作运行库副本数量；没有源码候选也不证明不存在原始或间接引用。

确认 AScriptEngine::GetString 的无效 ID 分支是 Error 的真实生成来源之一。原函数返回单独维护的 gText_AScriptEngine_InvalidStringId；现恢复为 return "Error"，删除四版手写数组和所属基类头文件中的声明。此函数仍保留原版 id <= string_count 比较及其 BUG 注释，没有顺手更改边界行为。字面量由真实函数的普通 C++ 编译生成，没有通过额外调用、静态对象或预处理器补字节。

原生 ScriptEngine 和农业教程调度中还看到相同的 string_count / string_offset_table / string_pool 字段读取及 Error 分支；这些内联读法与真实 GetString 语义相符。由于相应调用仍是原生汇编，不能仅凭相似代码就清空其具名常量或臆造匿名编译器标签。其他 Error 副本及各区域 N/A/なし 的生成位置仍需恢复，不能宣称全部完成。

ScriptTextVariableStore::Lookup 的现有默认分支返回空 FixedStr，不含 N/A；FixedStr 默认构造也仅清首字节。实际库 <exception> 仅声明 what，不能根据声明猜出 Error 实现。上述证据排除了靠修改这些无关方法来人为补串的方案；没有作这类修改。

同步移除 game_scene_records.hh 中多余的 implementation pragma：该头只定义普通记录及小型访问方法，构造实现本来就在同名 cc 中，没有对应接口/虚表归属需要该指令。农业教程手写原生调整入口与自动入口的所有权问题仍保留待办，未用别名、额外 section 或编译器特化规避。

回读核对旧数组符号与手写 bad_alloc 源码检索均为空，diff --check 通过。本轮没有 CPP、编译、汇编、链接、测试或移址实验；自然生成的具体地址和 ROM 匹配仍未验证。继续全量静态阶段，后续统一编译参数为 -j16，未提交或推送。

## 全量移除手写 bad_alloc（2026-11-08，批次 382）

用户已更新目标文件并明确要求全部移除本地手工维护的 bad_alloc，而非继续保留过渡数据。现已一次删除当前四版源码中的二百四十个手写字符串定义（涉及一百一十四个符号）和一百一十条文本声明。另删除 JP 行程数据中以八个字符元素加独立 c 字符串拼出的旧副本及两条声明。合计删除二百四十二处手写对象定义、一百一十二条文本声明；工具链自身 <new> 中 bad_alloc::what() 的真实定义没有改动。

src/include/data 中 bad_alloc、BadAlloc 及相应十六进制/八进制字符串转义的源码检索已清空，清除四个变空的区域文本文件、废弃 include 和空区域条件块。之前移回 owning cc 的十四组过渡定义也在这次全量删除范围内，不再保留其过渡方案。ScheduleInfo 中有三个地址名在 JP 曾被用于运行库字符串、在海外版却指向真实行程结构；仅删除其 char 定义和声明，结构体定义及其调用保留，没有误删实际行程表。

all-manual-runtime-382-plan.json、all-manual-runtime-382-removal-check.json 和 all-manual-runtime-382-applied.json 保存完整定义、引用检查、原文件哈希及删除清单；八字节/c 补充删除保存在当前源码差异和快照中。data/text/README.md 已更新维护规则。此项证明源码手写内容已清理，不能代替生成位置、数量、边界或 ROM 字节验证。

Error 与 N/A 进入后续生成来源和位置审计。实际 <exception> 头文件只声明 exception::what()，已查的库头没有对应字符串，不能据此假定其实现；AScriptEngine::GetString 的无效 ID 返回值以及脚本 UI 的 Error 已有真实游戏调用，另有 JP なし / 海外 N/A 的地区回退内容。需核对是否应由真实内联方法或默认返回值自然产生，并恢复正确模块归属；禁止在编译器按字符串内容补字节，不能将全部相邻短串盲目当作同一个标准库对象。

批次 381 是一次启动过早的构建：四版均因相同两类问题在链接前失败，没有产生本轮新 ROM。问题为 game_scene_records.hh 中不适用的 implementation pragma，以及 farming_tutorial 的原生调整入口与自动入口重复。用户指出时该轮已自行结束；已读取真实 Windows/WSL 进程及会话终态确认没有本任务残留构建。不得将此记录报告为成功、SHA-1 匹配或用户要求的全 ROM 静态阶段完成。

按最新要求，后续统一构建使用 make -j16；现仅更新外部构建驱动参数，未再次启动构建。继续全 ROM 静态整理，不能因几批局部修改就自行宣布具备编译条件。编译归属、Error/N/A 来源及输出位置仍未完成；未提交或推送。

## 独立运行库片段归回所属源码（2026-11-08，批次 380）

本轮继续静态整理，没有编译或测试。确认十份区域片段只含 bad_alloc 普通定义，四版声明、初始化内容和对齐逐项一致；片段引入的声明头此前已在所属源码包含，或片段没有额外头文件。将十四个独立定义按原 include 所在位置原样放回七个 owning cc，删除四版共四十个只为运行库字符串存在的文本文件。没有增加调用、类型、宏、编译选项或工具链补丁。

涉及 common_ui、cooking_recipe_inventory、crt0_data、field_render_resource_data、field_render_runtime_data、game_state 和 map_patch_flags。原符号及头文件声明继续保留，定义顺序和初始化表达式未变。本步骤明确是过渡数据归属整理，不是恢复自然生成，也没有将十四组定义从 ROM 删除；之前真正由自然字面量接替并删掉手写副本的累计数量仍为十七组。

清理后，通用 UI 的两份游戏文本依物理顺序为 common_ui_1.cc 和 common_ui_2.cc；game_state 和 field_render_runtime_data 各只剩一份区域文本，恢复同名无后缀 .cc。四版共十二次文本文件改名及 owning include 同步，没有空文本占位或人为 section。data/text/README.md 同步目录示例。

runtime-source-plan-380.json 保存原区域定义及归属，runtime-source-380-edit.json 保存修改前源码哈希、文件删除和改名清单。源码回读确认十四个定义均在原 owning cc 中，已不在区域文本根目录；删除、改名及 diff --check 核查通过。其他混合有游戏文本、Error 或区域差异的文件没有按本规则搬动，来源和边界仍需分别核对。

allocation_failure.hh 的真实接口是分配失败回调与 RetryMemoryAllocation，不是带 what() 的异常类，不能凭名称补出 Error 字符串。含 placement new 或 STL construct 的现有头文件确实使用标准 new 相关定义，没有为减少字面量而删掉这些依赖。

LDS、编译器和预处理器本批未修改。运行库生成归属、批次 378–379 的编译通道修正及当前十四组过渡定义仍待整批处理后统一构建；本批不更新 SHA-1 验证状态，未提交或推送。

## 文件边界下的编码数组词法处理（2026-11-08，批次 379）

延续真实 CPP 文件边界的静态整理，本批未运行编译器、CPP、汇编器、链接器或测试。

检查发现，旧数组转换器会吞掉相邻引号之后的空白；保留 CPP 行标记后，标记可能被接在数字后面。行标记或注释还会分断原有的字符串收集循环，导致两个数字片段之间缺逗号。现改为逐个引号转换，原样保留其间空白、注释和指令，只有同一相邻字符串序列的有效元素之间补逗号；源码原有逗号、括号和数字会正常结束序列。空字符串可作为非空相邻序列的一部分；完全空的元素序列仍报错，不添加隐式终止符或无语义数字。

声明的前瞻也跳过但不丢弃空白、注释和行标记，支持这些内容位于类型、const、数组名、维度和初始化体之前。所有扫描依据正常词法位置，不识别游戏变量、地址、字符串内容或地区名。data/text/README.md 同步了维护规则。

另外只读核对了现有四版 *lifetimes 对象，未发现四版均为空或仅含 bad_alloc 的可直接删除实现模块，记录在 empty-lifetime-379-candidates.json。没有因源文件短小就移除其实现归属，也未改头文件 pragma、游戏源码、LDS 或编译器。剩余运行库归属仍需继续静态核对。

本批仅完成源码修正和 diff --check；这些变化与前两批十七组副本删除仍待统一构建验证，当前 SHA-1 不得报告通过。没有提交或推送。

## 恢复真实预处理文件边界（2026-11-08，批次 378）

本轮保持静态整理，没有运行 CPP、编译器、汇编器、链接器或测试。核对当前 Makefile 与实际旧 agbcp 源码后，发现普通 C/C++ 通道用 CPP -P 去掉了全部文件边界，只在最前面伪设生成文件名。agbcc/g++/cp/lex.c 的 extract_interface_info 按 input_filename 恢复接口状态，pragma 处理也把状态存入当前输入文件的 FILEINFO；扁平化输入因此不能正常保留头文件和调用方各自的状态。

Makefile 的两条通用 C/C++ 规则现保留 CPP 原生行标记，移除 -P 与合成的首行文件名。文本通道原有通用解析已经能原样复制指令；补齐 u8/u16 编码数组初始化体内部的指令复制，避免把行标记中的路径引号当作游戏字形。该修改依据 C/C++ 指令语法，不检查 bad_alloc、游戏符号或地址。

没有宣称该问题已解释所有重复字面量、入口缺失或 ROM 差异。原有显式接口/实现声明仍保留，尚需继续核对源码归属；不通过无条件删掉所有 pragma 来凑顺序。批次 376–377 已删除的十七组副本证据来自既有对象，改用真实文件边界后的生成和顺序必须在整批静态整理结束后统一复核，不能沿用旧结果当作当前编译验证。

data/text/README.md 同步了编译通道要求。LDS、编译器源码和安装文件本批未变，没有提交或推送。完整目标仍未完成，SHA-1 状态仍为上一轮失败/中断，不能报告匹配。

## 跨模块运行库副本清理（2026-11-08，批次 377）

继续静态整理，没有编译、汇编、链接或移址实验。四版分别核对前一对象的最终手写 bad_alloc、后一对象已有的自然生成前缀、原版后续对象边界、对齐和直接地址候选，新增删除十一组定义及对应声明；加上批次 376，累计删除十七组。不能把源码删除数量当作 ROM 已匹配或全部运行库来源已恢复。

本批删除的手写尾串依次涉及 WorldAmbientSprites_5、MenuThird、FarmStatus、AnimalContestBoundary、NewGameBirthdayInput、ScrollMenuTrailer、StaffCredits、LinkCommunicationGYW、FishingResultsTrailer、FieldItemRecordsTrailer、FieldRenderSortedValuesSecond。替代字面量已经存在于相邻模块的真实编译对象中，没有为制造输出增加 include、调用或编译选项。初始化对象无旧符号可配对时，核对其在已确认的原版字符串之后、按自身对齐计算的位置上的完整无指针字节，而非猜测偏移。

删除各语言 common_ui_5.cc、fishing_results_data_2.cc 和 field_item_data.cc 共十二个废弃文本文件，清理 owning cc 的 include。钓鱼结果只剩一份文本，各语言 fishing_results_data_1.cc 均改为同名 fishing_results_data.cc，并同步 include；通用 UI 仍保持连续的 _1 到 _4。其余真实独立副本继续保留。

EU 联机尾串出现一处原始四字节地址候选 0x081BBAC0（值为 0x08100B0E）。它位于 gM4aWaveData_027 的 kind=0 波形头部指定的 signed 8-bit PCM 数据范围；WaveData 结构与 m4a 播放代码按采样计数读取该区。该候选是音频数值巧合，不是运行库文本指针，原采样字节未改。没有仅因数值类似地址就符号化。

四十四个区域案例记录于 runtime-cross-prefix-377-evidence.json，source-edit 清单记录首批八组的原文件哈希；随后两组与联机一组的实际源码也纳入本批快照。被删符号、废弃 include 的源码残留检查及 diff --check 通过。data/text/README.md 同步了文件名和运行库生成/过渡定义的维护说明。

当前自然生成前缀与手写副本不相邻的模块、仅保留多份手写文本的数据模块及其他附带运行库内容仍待处理。本批没有更新 ROM 验证状态；批次 375 仍是 JP 未匹配、US 中断、EU/DE 未启动，不得将旧产物宣称为本批源码结果。未改 LDS、编译器或预处理器，未提交或推送。

## 运行库重复字面量静态清理（2026-11-08，批次 376）

本批没有运行编译器、汇编器或链接器。保留批次 375 中断状态，未将既有 ROM 宣称为本批验证结果。

依据四版实际对象、原 ROM 及已有符号改名记录，删除 WorldAmbientSprites_1、ChickenFestival、HarvestingMinigame、WateringMinigame、GameMenu 五组手写 bad_alloc 定义及头文件声明。现有对象中已有来自旧 <new> 的十字节、四字节对齐字面量，紧邻手写副本之前；保留自然生成，删除重复的源码定义。WorldAmbient 的原始独立标签缺失，由已确认的出生位置表边界及紧邻字符串字节确定，未新增别名。

另删除四个语言目录中的 item_4.cc、item.cc 的该 include 和 ProductInfo 运行库文本声明。原版该字面量之后立即是日历季节名（JP 0x080EFD48→0x080EFD52；US 0x080F04E4→0x080F04EE；EU 0x080F0530→0x080F053A；DE 0x080F09A8→0x080F09B2）。game_state 实际对象已有自然生成前缀，可接替此跨模块边界的手写副本；没有为生成字符串增加 include 或无用调用。

六组定义与声明的源码残留检索已清空。四版原 ROM 中这些字面量及其内部字节地址均没有直接四字节地址候选；对象中没有针对被删前缀符号的已分配代码/数据重定位。该检查不等同于全 ROM 间接引用审计完成。

证据存于 runtime-prefix-376-evidence.json（二十个区域模块案例）及 runtime-item-prefix-376-evidence.json（四个跨模块案例）。源码已经调整，ROM 大小、后续对齐与四版完整匹配仍待整批静态修正结束后统一验证。未修改 LDS、编译器、预处理器，未提交或推送。

仍有其他手写运行库字面量留在源码及 data/text；未把同内容全局去重。后续先检查其余跨模块“前块手写尾串／后块自然前缀”候选，核实原版下一对象边界，再删除确属重复的定义。自然前缀与手写副本之间夹有其他对象时，需要先恢复来源和顺序。

## 构建中止与源码接续（2026-11-08，批次 375）

运行库手写副本清理尚未完成时启动了验证；按用户反馈已停止该轮后续构建。JP 完成但 SHA-1 未匹配 baserom，US 中途停止，EU/DE 未开始；不能将本轮报告为四版验证完成。已核实对应 Windows 驱动进程和 WSL 构建进程组均结束，未停止或重启 WSL。

本轮源码将 HardwareManagerBindingRestore 和 UiVCountContextScope 的内联析构定义放回各自现有的 lifetime 头文件。JP 对象中实际顺序已分别为 Restore / CommandGroup / PreviousBinding 和 Scope / Registration，与原版符号顺序一致；四版一致性及完整 ROM 匹配尚未验证。没有修改 LDS 或编译器，没有执行合成探针。

下一步先完成运行库附带内容的静态整理和手写重复定义清理。上一轮 374 的全局对照作为已归档分析依据，当前工作树和部分输出已有后续变化，不得称为当前全部产物的验证结果。不得仅为微小修改反复构建；整批来源、定义、声明与顺序调整完成后再统一验证。

## 全局符号与字节核对、编译职责修正（2026-11-08，批次 374）

四版均完成 WSL `make -j4` 编译、链接和 ROM 生成；构建日志没有未定义符号、重复定义或丢弃段引用错误。四版 SHA-1 仍未匹配各自 baserom，目标未完成，未提交或推送。

| 版本 | 原字节相同区间 | 引用变化可解释区间 | 尚有字节差异 | 长度/填充差异 | 顺序/别名差异 |
| --- | ---: | ---: | ---: | ---: | ---: |
| JP | 16685 | 2662 | 71 | 215 | 15 |
| US | 16768 | 2786 | 62 | 202 | 15 |
| EU | 16768 | 2786 | 62 | 202 | 15 |
| DE | 16940 | 2787 | 62 | 202 | 15 |

上述区间是已配对标签之间的物理范围，不能等同于函数、对象数量或动态化完成率；区间内偏移推断与真实具名重定位仍分别记录。未配对符号也未被忽略。


| 版本 | 当前 SHA-1 | baserom SHA-1 |
| --- | --- | --- |
| JP | `da26332fded39b1c5ed38496798a6908c3785628` | `a655b2789aed14a6ac78c6075fbc533d3062dbe3` |
| US | `47c5a72bfacafee017194fe222efe4b30e98d414` | `a2fc3574f0a65a4fcf7682fb274b9d7eebdef963` |
| EU | `f6cbb52cf14ca0af4fccfd5d10ac8b8a423c4c13` | `7ba1ec1e46ce424e3c6fd72e4e8d5e9eb5ede247` |
| DE | `36f6900dc40befcf6601ad99bb19030b878b7d1b` | `60f2a30b55c0e32754897b4d5df6ce06f8b71a37` |

先对照四版完整符号表，再检查整 ROM 字节、重定位和符号区间。用于解释原版符号的归档 ELF 已逐段对照实际 baserom；比较对象始终是 baserom。完整结果保存在 `global-374-*-symbols.json`、`global-374-*-bytes.json` 及运行库字面量清单中。

本批保留两项修正：`WorldAmbientSpawnWeights` 按读取方确认的五字节步长声明为 PACKED；编译器的顶层汇编输出会使当前段状态未知，四套 C/C++、ARM/Thumb 前端均在输出后清除段状态缓存，后续对象由原有段选择机制输出。未识别游戏符号、地址、目标字节或汇编指令模式。

扩大空析构优化的改动已撤回：整 ROM 对照显示它也改变了原版中应保留的析构序列。39 个 NPC 派生类的隐式、类内定义在当前 pragma/编译归属下均未产生所需入口，相关源码变动已经恢复；保留原定义及失败日志，后续核查真实定义归属，不添加无用调用或强制引用。不能将这组析构问题算作完成。

`scene_special_merchant_shop.cc` 删除了完全未使用的 `video.s` 汇编包含，四版实际编译验证覆盖此修改。汇编包含文件的换行转换没有解决报错，已全部还原；未保留第三方头文件改动。

当前实际使用的 `tools/libagbc++/new:27` 与编译器源码 `g++/cp/inc/new:27` 均由 `bad_alloc::what()` 返回该字面量。它应随真实运行库代码生成，不属于本地化文本；本批没有按名称去重或删除手写副本。运行库副本的模块归属、独立对象顺序和自然生成仍待完成。

LDS 未增加固定地址或逐符号/GNU 子段。现有预处理器的 unique `.rodata` 规范化、剩余函数定义顺序与指针审计仍是未完成项。未添加测试用例、移址实验或合成测试工程；验证为现有工程的正常构建（包括失败对象的诊断重编译）及只读产物分析。

## 编译器与预处理器职责调整（2026-11-08，批次 366）

四版完成 WSL `make -j4` 编译、链接和 ROM 生成，没有未定义、重复定义、丢弃段引用或其他已识别构建错误。 与各自 baserom 的匹配尚未全部通过，具体结果如下。只有原版基准匹配才计为 ROM 匹配完成。

| 版本 | 当前 SHA-1 | baserom SHA-1 | 匹配 |
| --- | --- | --- | --- |
| JP | `5f6c8552375561a2e2ce9ef6d226b0388bf6d36f` | `a655b2789aed14a6ac78c6075fbc533d3062dbe3` | 否 |
| US | `2c5615fc57351b00045ed04fc46510c45388f02e` | `a2fc3574f0a65a4fcf7682fb274b9d7eebdef963` | 否 |
| EU | `464665ac4196ba6e020ddbc45c2cd0d706ce085c` | `7ba1ec1e46ce424e3c6fd72e4e8d5e9eb5ede247` | 否 |
| DE | `660200dd1a58200e72596d65c93fa47673893780` | `60f2a30b55c0e32754897b4d5df6ce06f8b71a37` | 否 |

编译器只修正语言/ABI/目标约束层的问题。本批在 C、C++ 及 ARM、Thumb 前端增加显式声明对齐标记，并在再次声明时保留；目标偏好对齐不再覆盖该请求。移除旧 Thumb C++ 前端在切换函数段之前追加的对齐，保留函数段内原有的正常对齐，避免改变前一个数据段。

`fomt-preproc` 删除仅识别特定字符数组声明的 ALIGN(1) 修补，以及根据相邻汇编行形状删除数据尾对齐的逻辑，连同失效自测片段共减少 234 行。未新增或执行测试用例、编译探针或移址实验。源码端的显式对齐仍须有真实类型和原始布局依据，不因匹配需求擅自增加。

新游戏构造、上下文析构入口顺序、菜单指令差异和城镇地图等既有问题，继续从游戏源码的真实类型、表达式、内联可见性及模块归属修正；不能通过编译器识别这些函数，也不能由预处理器匹配指令序列来替换。

预处理器当前仍有普通数据段规范化及可执行段收尾对齐。尤其 `-fdata-sections` 到同名 unique `.rodata` 的转换仍需结合对象起点、源码属性和符号拼写审查，尚未宣称整个工具链及对象内部组织已经完成。没有游戏名或 ROM 地址硬编码，不等于已证明所有格式假设足够通用。

编译器从 FoMT 同级 `agbcc/cp` 构建并安装。LDS、游戏源码和资源本批未修改；没有为匹配增加地址限制、逐函数/GNU 选择器或链接后指令补丁。尚未提交或推送。

## 工具链目录与 SHA-1 比较对象更正（2026-11-08）

重新读取当前四个 ROM 计算 SHA-1，仍分别等于下表的批次 365 产物，均不等于对应原 ROM。此前“与安装前一致”仅指工具链迁移前后的输出一致，不能解释为已恢复原版匹配。

按用户要求，将 `agbcc-pret` 整个目录复制为 FoMT 同级的 `agbcc`，包括 `.git`、`cp` 分支、24 个文件的未提交修改、符号链接及已有构建产物。完整目录内容比对一致；从该副本执行 `install.sh ../fomt`，五个编译器和两个库与源文件的 SHA-256 分别一致。原目录和已改名的 `agbcc-notyourav` 均保留。

安装脚本默认读取 `../agbcc`，教程使用并列目录下的常规构建、安装命令，不再包含个人编译器路径。此轮未修改编译器规则、游戏源码或 LDS，未重新编译 ROM、未运行测试用例，未提交或推送。已复核的编译器改动依据类型、声明属性及目标约束；未发现 FoMT 名称、ROM 地址或目标字节特化规则。预处理器仍有通用对齐和输入段格式处理，不能表述为“没有任何工具链补正”。

## 本地 cp 工具链接续与完整构建（2026-11-08，批次 365）

四版均完成 WSL `make -j4` 编译、链接和 ROM 生成，没有未定义、重复定义或丢弃段引用错误。完整 SHA-1 仍未匹配原 ROM，尚未提交或推送。 新编译器生成的四个 ROM 均与安装前批次 360 的产物逐版 SHA-1 一致；已有差异仍待修复。

| 版本 | 构建产物 SHA-1 | 与安装前一致 |
| --- | --- | --- |
| JP | `5f6c8552375561a2e2ce9ef6d226b0388bf6d36f` | 是 |
| US | `2c5615fc57351b00045ed04fc46510c45388f02e` | 是 |
| EU | `464665ac4196ba6e020ddbc45c2cd0d706ce085c` | 是 |
| DE | `660200dd1a58200e72596d65c93fa47673893780` | 是 |

批次 355–360 已恢复 UI 的十三个入口、文本窗口边框、NPC 查找调用和三个世界对象方法的指令与重定位。存档储物场景先前存在循环误命名；已按真实调用修正比较关系和物理顺序，不能再用旧名称同名比较反向调整。

批次 360 的有限同名非零尺寸函数审计中，JP 有 2094 项、海外各版 2097 项字节及已识别重定位一致；各版另有六项尺寸差异、四项同尺寸指令差异。此范围不覆盖全部改名入口、零尺寸汇编符号、待配对引用和数据，不能将它当作全 ROM 完成率。上下文恢复的两组独立析构入口还存在生成顺序差异，城镇地图及后续数据布局也尚未完成。

编译器本批次在用户 `agbcc-pret` 仓库的本地 `cp` 分支构建，基线 `1caa6bec`；已从该目录完成构建并安装到 FoMT。源代码通用修正与构建兼容修正共 24 个文件、147 行增加及 57 行删除，没有新增测试目录，本批次未运行测试用例。FoMT 安装脚本不再下载、检出或应用补丁；重复补丁文件已转存审计备份。栈调整的十六进制格式由编译器正确生成，预处理器对应指令改写已移除。

普通 LDS 对象保持单条 `.text` / `.rodata` 等输入，未增加原址限定、人工细分 section 或具名 GNU 条目。后续差异在真实源码和通用编译器规则中处理，不以定向地址、符号或字节替换配平。较早批次的临时结论以本节更正为准。

## 普通段统一构建与顺序修正（2026-11-08，批次 353）

四版均完成 WSL `make -j4` 编译、链接和 ROM 生成，无未定义、重复定义或丢弃段引用错误；完整 SHA-1 仍不匹配，尚未提交或推送。普通对象的人工 `.text.*`、`.rodata.*`、具名 GNU 选择项及逐对象 LDS 对齐项保持为 0，Mary 生成的两类脚本输入段保持原有接口。

| 版本 | 可比较同名函数中长度相同 | 长度不同 |
| --- | ---: | ---: |
| JP | 2205 | 9 |
| US | 2209 | 9 |
| EU | 2209 | 9 |
| DE | 2209 | 9 |

此统计仅覆盖两份 ELF 中均存在且大小非零的同名函数，排除了改名入口、零大小汇编符号和数据；长度相同不代表字节匹配，不能将九个长度差异当作整个目标只剩九项。城镇地图改名入口仍有已知差异。

已修正四版工具箱、背包、冰箱、柜子场景的对象顺序，以及 GameScene 的五个相邻打开入口和控制器构造顺序。当前可比同名函数的对象间与对象内顺序均无倒置。三种范围查找实例及新游戏姓名输入核心构造通过四版指令与重定位对照；66 个菜单转接入口保持原相对顺序及长度。标题核心隐式清理恢复原 604 字节长度，精灵特效所有者不再输出原版不存在的 1320 字节独立内联副本。

新游戏菜单与身份核心改回真实构造函数，移除 placement-new 带来的额外空指针分支；仍有栈布局和指令长度差异。UI 三个命令构造体可见性、上下文恢复与教学/商店清理、城镇地图辅助入口，以及后续普通数据和运行库布局尚需继续核对。JP 当前 `.text` 比原版短 824 字节；启动常量池的首字节差异反映 IWRAM 加载地址移动，首个实际代码差异在新游戏菜单初始化。

以下旧批次记录保留其当时的静态结论；最新构建状态以上述结果为准。相邻小模块的最终精简合并尚未开始。

## 动态镜像尾部与统一验证开始

四版 LDS 的地址统一补足八位；普通对象继续按顺序链接。移除末尾固定到 `0x08800000` 的限制，保留四版原 ROM 镜像末尾实际存在的一个零字，剩余 `FF` 填充交给既有 `gbafix -p` 按实际镜像大小生成。内存区的硬件基址和容量仍保留。

逐对象的 LDS `ALIGN(4)` 已移除；相关只读对象本身具有四字节节对齐，局部确需对齐的汇编入口在源码内声明。输出段开头的对齐保留。通用 C/C++ 通道用标准行标记初始化旧前端的主文件名，使 `#pragma implementation` 正常识别类实现归属。具名数组修正同时覆盖文件作用域的静态文本及整数数组，ARM／Thumb、O0／O2 的跨翻译单元检查均通过。

更新后的 ARM／Thumb C++ 前端已构建，具名数组身份的跨翻译单元回归在 ARM／Thumb、O0／O2 四种组合下通过；文本工具和预处理器自测通过。四版完整 ROM 验证开始，尚未取得本轮 ROM 匹配结论，未提交或推送。

## GNU 具名选择项清零与四版链接格式统一（静态批次 GW）

脚本引擎、玩家／教学角色、教学场景、教学世界／地图及 GameCube 联机的剩余组已完成源码归属整理。四版分别核对 53 个原入口（JP 2296 字节，其余三版 2304 字节）和 22 张表、2064 字节；普通玩家的现有 176 字节原生表仍夹在两组真实类表之间，未重排或复制。四版 LDS 具名 GNU 选择项现为 0；JP 两条被末尾通配丢弃规则覆盖的旧 GNU 丢弃项也已移除。

联机核心的内联回调保持对真实多重继承跳板可见，不新增未调整 this 的独立副本。联机报文按真实线格式紧凑排列；两套协议使用公共虚接口保持原 vptr 与字段位置。教学场景的空析构体承担实际成员和基类清理；其 OnCall 目前只有原生调整入口，因此四张原始表及两条短析构跳板保留在普通对象中，直接引用真实方法，避免生成原版不存在的 OnCall 包装调用。实际输出与四版 ROM 匹配仍待统一验证。

参照本地 pokeemerald（9a83a2bbe8）的链接组织，统一四版 MEMORY、段起点、ALIGN、调试和丢弃区格式，并将连续的音频、脚本、字体、图形和库数据列为独立输出段。US/EU 两份内容相同，JP/DE 两份内容相同；两组之间仅保留原图形块的真实先后差异。普通对象的物理顺序保持不变，JP 的商店资源映射对象仍由源区域条件产生空代码。本批未编译、提交或推送，不能把选择项清零当作四版 ROM 匹配通过。

## 料理、日历与小游戏家族（静态批次 GV）

四版整组核对 19 个晚期入口、5444 字节及 19 张类表、276 字节。料理和日历的文本变量、核心清理，鸡祭与精灵小游戏清理，以及实际被调用的事件变量／工作目标查找实例，现归入普通对象段；商店基类表也不再使用 GNU 选择项。每版剩余具名 GNU 规则为 18 条（代码 9、表／数据 9），集中在玩家／教学、脚本引擎和联机家族。

小游戏转接层的三个已有显式析构仍在较早的主实现中，鸡祭隐式析构保留晚期位置；四个转接构造继续对实际工厂可见以供内联。浇水小游戏的十二个句柄构造与清理均纳入晚期接口，保留真实成员的默认构造顺序。标准库查找仅显式实例化真实调用的类型，不添加虚假调用。最终输出、重定位和 ROM 相等尚待统一验证。

## 滚动界面、城镇地图和指南的生成关联（静态批次 GU）

四版核对同一连续晚期代码区的 9 个入口、1632 字节，包括滚动菜单与工作人员核心清理、地图标记树的四个操作及核心清理、指南查找模板及核心清理。九张相关类表共 128 字节，位于含既有滚动上传命令表的 144 字节连续区。原 GNU 选择项改由真实接口所有者的普通段承担，现每版剩 35 条（代码 18、表／数据 17）。

指南实际调用的 `std::__lower_bound` 采用正常显式实例化与外部实例声明，未添加人为调用；地图辅助函数仍保留真实内联体和单一实现归属。原较早函数及普通文本保持所属文件。源码及原 ROM 边界已核对，新实例的实际生成顺序和完整匹配尚待统一构建。

## 状态页、参赛选择、生日和地图的关联归属（静态批次 GT）

将牧场状态、动物参赛选择、生日输入、牧场地图、记录页作为连续家族核对。四版原 ROM 均含 22 个晚期入口、1832 字节，以及 22 张类表、340 字节；各主题通过自己的 lifetimes 对象生成普通 `.text` 和 `.rodata`，原文件保留早期实现及后段数据。

牧场地图的室内标记数组还含独立的 44 字节构造与 56 字节清理入口，已一并纳入实际类接口归属，保留原成员构造、析构与内联体。JP 旧 map 将场景表拆成 4 与 12 字节两项，本次按真实连续的 16 字节虚表核对，没有将旧分段误认为两个对象。四版具名 GNU 规则各剩 44 条（代码 22、表／数据 22）。以上是静态归属核查，新输出及 ROM 相等仍待统一构建。

## 飞盘和赛马的连续晚期入口（静态批次 GS）

将飞盘成绩表、飞盘游戏、赛马与奖品交换作为同一组核对：原 ROM 连续晚期代码共 2108 字节、10 个入口，相应类表共 160 字节、11 张。四版均按真实表槽确定各核心析构、文本变量查询与清理的边界。各主题的 lifetimes 对象现在持有这一晚段代码与类表，原文件继续持有较早的构造、运行、绘制和后段文本，不再用 GNU 通配选择器跨物理范围取内容。

三个文本变量类归入各自真实类接口；保留原有内联查询／清理体及核心的隐式析构，以继续为成员清理提供相同的内联依据。源码没有重写业务逻辑，也没有新增人工虚表。四版具名 GNU 规则各剩 54 条（代码 27、表／数据 27）。新对象生成顺序与 ROM 字节一致性仍待统一构建。

## 场景状态、世界对象和精灵家族（静态批次 GR）

整组处理场景状态、游戏场景、世界对象、地图选择基类和两种资源精灵的关联归属。七张表合计 440 字节，三条隐式清理入口各 12 字节；四版原始表槽、物理边界和清理指令（排除实际 BL 目标差异）已核对。场景状态、游戏场景、世界对象及精灵基类的表回归各自现有对象的普通 `.rodata`；地图选择、分组精灵、索引精灵按各自不连续的清理／表位置确定真实类所有者。

三条清理继续由编译器生成隐式析构，没有改写为空的用户析构。地图选择构造仍供派生过渡内联；精灵构造与动画访问器保留原方法体和内联可见性，独立类所有者不强制输出原 ROM 中没有的构造或访问器。早期构造、绘制代码和 IWRAM 提交入口均未迁移。移除了旧总头文件的间接场景汇总依赖，具体类型由实际使用方 include。

四版具名 GNU 规则现各剩 60 条（代码 30、表／数据 30），JP 丢弃规则另计。以上为静态归属进度，新的编译器输出、重定位与 ROM 匹配仍待本轮统一构建。

## 商店与收纳界面连续类表（静态批次 GQ）

一次整理鸡舍商店至礼物包装的完整连续虚表区：四版各 37 张表、520 字节，覆盖 17 个功能模块。表由实际 C++ 类定义统一交给 shop_scene_tables 对象生成，LDS 中原来的 19 条 GNU 数据选择规则合为一条普通 `.rodata`；各场景后段的文本、目录和原有函数仍在所属对象中。没有手写虚表、别名或编译后重排。

锻冶屋的核心、购入结果过渡、场景三表在原 ROM 中连续交错，因此一起调整真实类声明次序；过渡类的创建和清理两个原入口共 112 字节，归入 scene_blacksmith_transition 普通 `.text`。其构造体仍对实际调用者可见，不增加无原入口的独立构造副本。冰箱、柜子和工具箱沿用已由实际访问代码纠正的名称，不按旧 map 中的错位名称重新排列。

四版具名 GNU 规则现各剩 70 条（代码 33、表／数据 37），JP 的两条丢弃规则另计。本批仅完成原 ROM 槽位、边界、源接口和链接归属静态核查；新生成顺序及完整 ROM 匹配仍待本轮统一编译，尚未提交或推送。

表生成次序检查还发现 game_scene.hh 仍间接汇总了旧场景头文件，会抢先改变声明顺序；这些无依赖的汇总 include 已删除，使用方的显式类型引用检查未发现缺失头文件。

## 启动场景家族整组归属（静态批次 GP）

将标题、载入菜单、新游戏姓名输入、童年场景和保存姓名界面一起整理。原 ROM 的五组晚期代码共 1744 字节、16 个入口，相应 14 张表共 212 字节；四版的连续边界、表顺序与析构槽已核对。前面三组工厂／清理和表由各自 lifetimes 对象负责，童年场景表留在原场景对象，晚期变量查询／清理由独立 lifetimes 对象负责。保存姓名的普通文本留在原文件，表和晚期清理归 lifetimes 对象。每个对象在对应输出段中只链接一次。

同时处理了两项跨组依赖：保存姓名的构造函数继续对工厂可见以供内联，并由原 name_entry 对象保留位于 Run 后面的 32 字节独立入口；童年文本变量与资源归档的析构通过实际方法接口保留内联体。资源归档表回归原 resource_archive 对象，表所有者抑制无原独立入口的内联访问器导出，晚期清理由其方法所有者负责。没有增加伪对象、别名、手工虚表或编译后重排。

四版具名 GNU 规则由 100 条减至 90 条（代码 34、表／数据 56），启动与运行库家族的具名 GNU 选择项已全部替换。JP 的两条丢弃项另计。以上是源码归属与原 ROM 静态核对；新对象顺序、内联行为和完整 ROM 匹配仍待整轮结束后的统一编译，尚未提交或推送。

## GNU 剩余组的物理交错与资源归档（静态批次 GO）

先对全部剩余具名 GNU 规则与保存的原始输入段做物理交错复查：每版有 19 条规则匹配多个旧输入段，其中 10 条跨越其他对象的内容。全部 41 条代码规则及 63 条数据规则中的 45 条，其原对象在别处还有普通 `.text` 或 `.rodata`。因此不能只把 LDS 选择器改名，必须连同生成类表、析构代码和原对象的其他内容确定实际所有者。JP 末尾另有两条 `/DISCARD/` 通配项，它们不是 ROM 布局选择规则，不能与 104 条具名剩余规则混计。

资源归档组按同一来源的两处实际物理岛整理：四版提供者基类的 32 字节清理入口与 20 字节虚表在启动岛，派生归档的对应入口与虚表在晚段。原表槽分别指向各自清理函数、纯虚查询或真实归档查询；四版 ROM 与保存的输入段均已核对。提供者的真实类声明和实现由 `resource_archive_provider.hh/.cc` 管理；归档的虚析构由 `resource_archive_lifetimes.cc` 按原类接口生成，原 `resource_archive.cc` 继续管理其早期构造和查询。两处链接都使用普通 `.text/.rodata`，保持类继承、原有查询及内联清理。US/EU/DE 具名 GNU 规则现各剩 100 条（代码 39、数据 61），JP 另有前述两个丢弃项。新旧编译器输出与完整 ROM 相等仍待统一构建验证；本批未编译、提交或推送。

## 剩余 GNU 段的全局归属交叉核对

以当前四版 LDS 与保存的原始输入段 map 交叉核对，四版各剩 104 条 GNU 选择规则（代码 41、数据 63）。41 条代码规则对应的原对象在其他物理位置都还使用普通 `.text`；63 条数据规则中有 45 条的原对象还在其他位置使用普通 `.rodata`。因此不能把这些规则直接改成同一对象的 `.text`／`.rodata`，否则会把相隔很远的内容一起提前链接。商店与收纳的 20 条数据规则全部属于此类，必须同时核对表和后段文本的归属。其余规则、无原输入命中的候选及相邻手工表已列入本任务 `gnu-owner-ranges-312.json` 和 `gnu-family-matrix-311.json`；无命中不代表可直接删除。以上仅是静态排布审计，未运行编译。

## 世界地图命令与相邻表归属（静态批次 GN）

从全量 GNU 清单中将世界地图视为连续依赖组处理：四版各有一个 12 字节 MapViewportTilemapCommand 析构入口，晚段有 40 字节 GameSceneWorldMap 虚表、16 字节 MapViewport 命令虚表及紧接的 40 字节原生 GameSceneSavedMap 虚表。已按原 ROM 逐槽核实派生析构及保存地图析构指针。

世界地图的早期函数和原生保存地图表仍由 `world_map.cc` 定义；新的 `world_map_tables.cc` 只承担两张真实类表的普通 .rodata，`world_map_command_lifetimes.cc` 承担原 12 字节入口的普通 .text。这样不把位于表后面的显式原生表提前拉入编译器虚表段。四版 LDS 各减少一条 GNU 代码及一条 GNU 数据规则，现各剩 104 条（代码 41、数据 63）；编译器新输出留待全 ROM 静态整理完毕后统一验证。

## 硬件上下文命令与虚表归属（静态批次 GM）

在完整硬件组中继续处理 HardwareContext 的三种帧命令。四版原 ROM 的后段代码依次是 Display、SpriteBuffer、DmaQueue 三个 Run 入口，紧接 DmaQueue、SpriteBuffer、Display 三个 12 字节派生析构；四张表依次是 DmaQueue、SpriteBuffer、Display 命令表与 HardwareContext 表，合计 60 字节。各表的 Run／析构槽位与原 ROM 符号地址逐项对应。

早期 HardwareContext 构造和析构仍归原 `hardware_context.cc`，同一对象输出普通 .rodata 中的四张真实类表。相邻后段命令由 `hardware_context_commands.cc` 输出一段普通 .text，内联方法与析构仍对调用方可见。LDS 不再分别选择这组 GNU 函数和虚表段；四版各剩 106 条 GNU 规则（代码 42、数据 64）。这是静态归属安排，旧 agbcp 的实际输出顺序及四版 ROM 一致性留待最终统一构建确认。

## 硬件管理器的调整跳板与清理归属（静态批次 GL）

在全局硬件组中，四版原有一个 44 字节的多重继承调整跳板，随后夹有 180 字节 VBlank 操作，再跟着三个连续的 40/48/40 字节管理器清理入口。五张连续管理器虚表共 84 字节，位于尚未清理的硬件上下文命令表与已整理的音频命令表之间。对应的真实类、基类及调用关系已跨四版核对。

现由 hardware_manager_tables.cc 持有真实类的五张普通虚表及其自然产生的调整跳板；hardware_manager_lifetimes.cc 持有三个真实内联析构，按旧前端的反向输出顺序排列。原管理器所有权函数、VBlank 操作与汇编析构正文保留，未加入手工跳板、伪对象或别名。旧 agbcp 源码的 mark_vtable_entries 会在表引用调整跳板时调用 emit_thunk；自然输出位置与大小仍须最终统一编译确认。四版各去除四条 GNU 代码和一条 GNU 表规则，目前剩代码 43、数据 65、共 108 条；未编译、提交或推送。

## GNU 全局归属总览与音频命令组（静态批次 GK）

四版 LDS 各有 117 条待整理的 GNU 选择规则：代码 49 条、数据 68 条。已按启动与运行库（7/7）、硬件与联机（8/5）、场景及精灵基类（6/13）、教程与小游戏（27/23）、商店与收纳（1/20）建立全量交叉表。与保存的原版输入段对照后，每版有 51 条规则未匹配原版输入段；其余 66 条规则匹配 106 个不同输入段，其中一张脚本引擎虚表被两条规则重复覆盖。规则数量不能直接视为尚待生成的函数或虚表数量。

原版 US/EU/DE 另有 209 段、JP 有 217 段手工虚表输入，均合计 9180 字节；其中 32 段在物理地址上紧邻尚由 GNU 规则匹配的表。商店区尤其交错，必须连同其相邻类型一并确认真实编译归属。完整的四版规则、原输入段及家族关系保存在本任务的静态审计记录；它们不代表修改后的编译器输出。

先将硬件音频命令和底层链表一起处理：四版各三条相邻的派生析构入口共 36 字节；音频的两张相邻虚表共 32 字节，链表的三张相邻虚表共 68 字节。原代码去除实际 BL 目标差异后相同，三个析构都调用真实 HardwareLinkBase 析构；音频表的函数槽依次是 Run、析构。实际类型由原两个模块生成普通表，两个清理模块输出相邻的普通 .text；原 Run、链表方法及构造正文保留，内联清理仍可供调用方使用。LDS 每版减少两条 GNU 代码和两条 GNU 数据规则，当前为代码 47、数据 66、共 113 条。新编译输出与四版字节匹配留到全 ROM 静态整理完成后统一验证；本批未编译、提交或推送。

## Shared menu core and panel ownership (static batch GJ)

将物品／收纳／料理等界面共用的菜单面板、公共核心和选择核心整组梳理。四版原有三个后段清理入口合计 512 字节，五张相邻虚表合计 72 字节；已核实独立入口、虚表槽、直接调用及全部原成员布局。前两个清理入口在 ROM 连续，选择核心入口位于较早位置；表顺序则是公共核心、三个面板、选择核心，不将不同物理职责硬并到同一对象。

`game_menu_lifetimes.hh/.cc` 负责真实公共类型、两个连续清理入口及四张连续表；`game_menu_selection.hh/.cc` 负责实际派生选择核心及其独立入口／表。原游戏菜单构造、导航、更新、绘制和数据源码正文未改动；原调用头仍提供相同公开接口及 GameScene 依赖，清理模块则只 include 自身实际需要的类型，避免引入无关场景对象。成员／基类清理由编译器生成，并继续对派生调用方可见，不使用手工虚表、强制实例或编译后重排。

四版各移除三条 GNU 代码、三条 GNU 数据规则，剩余 117 条（代码 49、虚表／数据 68）。新对象的自然输出顺序、隐式选择清理、调用方内联及四版完整字节匹配仍待最终统一编译；本批没有编译、提交或推送。

## Shared UI VCOUNT lifetime ownership (static batch GI)

将商店／UI 共用 VCOUNT 绑定与两个上下文恢复层一起整理。四版原独立恢复入口各为 40 字节，连续排列；其虚表与外层 UiVCountBinding 虚表也连续排列，共 36 字节。字段、构造、实际中断处理、上下文恢复顺序和绑定析构正文均保留，两个上下文层没有原 ROM 独立构造入口。

真实类与三张表继续由原 `ui_vcount.hh/.cc` 负责，表使用普通 rodata；两个内联析构由实际 `ui_vcount_lifetimes.hh/.cc` 定义并输出连续普通 text，调用方继续内联恢复，不增加伪调用、别名或手工表。类表 owner 抑制无用 inline 导出，实际函数 owner 保留正常 inline 输出。

四版各移除一条 GNU 代码和一条 GNU 数据规则，剩余 123 条（代码 52、虚表／数据 71）。静态匹配与引用证据已记录；生成顺序、绑定内联及四版完整 ROM 尚待最终统一构建。本批未编译、提交或推送。

## Shared UI command and adapter family (static batch GH)

整组整理 UI 文本输入／输出基类、选择行缓冲及四种硬件命令，共八个真实类型。四版原 ROM 中，17 个共享执行／清理入口连续占 512 字节，八张编译器虚表连续占 176 字节。函数指针命中均与实际虚表槽对应；US 另一个相同四字节模式位于 gM4aWaveData_065 的 PCM 采样内，整个采样已与现有源码逐字节核对后排除。已一并记录直接调用、成员清理及原早期构造入口；归一化后的四版方法一致。

共享类布局、内联入口及对应虚表统一由 `ui_text_commands.hh/.cc` 正常生成。保持原类声明顺序，以原 ROM 反序排列共享内联定义，使旧 agbcp 的自然 EOF 输出形成连续范围；不手写表、不添加调用或编译后重排。六个原隐式清理入口用真实空析构定义表达，继续让编译器清理实际基类和成员。实际旧编译器 `method.c`／`decl.c` 明确对无复杂继承的空析构省略无意义的入口虚表写入，而不是以现代 ABI 推测。

原已有独立地址的三个 UI 构造移除误用的 inline 标记，正文和源码位置保持；另两个没有独立入口、仅由 UiStatePayload 使用的短构造继续在实际调用模块内联。原渲染、payload 构造／析构、指令、区域差异及普通数据均未改动正文。不强迫未使用的构造导出，也不重复检查已完成的普通 text。

四版各移除一条 GNU 代码和一条 GNU 表规则，剩余 125 条（代码 53、虚表／数据 72）。新的自然输出顺序、构造代码、调用方内联及完整四版 ROM 尚待统一构建验证；当前没有运行编译器、汇编器或链接器，没有提交或推送。

## Shared text-variable lifetime ownership (static batch GG)

将共同文本替换基类 ScriptTextVariableStore、替换结果布局及 GameSceneTextVariables 的后段清理作为一个真实依赖组整理。四版原 ROM 均为三个连续 32 字节入口（场景变量析构、基类默认 Lookup、基类析构），及两个连续 16 字节虚表；去除已确认符号重定位后代码一致。此基类还供飞盘、赛马、开场、料理和日历等替换器继承，不能只改某个调用文件的 GNU 条目。

`scene_text_variable_lifetimes.hh/.cc` 持有这一连续入口／表范围，保留真实基类析构和默认查找的内联定义。场景变量保持隐式派生析构，原构造、Lookup、Set、字段顺序和区域长度规则不变。该实际类型模块使用普通编译器 text/rodata，不手工定义虚表，不增加强制调用或编译后调整；也不引入无关 UI 类型的表副本。

四版各去除两条 GNU 代码、两条 GNU 数据规则，剩余 127 条（代码 54、虚表/数据 73）。自然输出顺序、调用方内联及四版完整匹配仍待整 ROM 静态整理完成后统一编译；当前未编译、提交或推送。

## Shared DMA commands and clock cleanup (static batch GF)

整组整理菜单/HUD 共用的 HardwareDmaCopyLink、时钟数据清理与时钟控件虚表。四版原代码归一化后一致：DMA Run 为 20 字节，DMA 析构为 12 字节，紧随其后的 MapClockStatusHudData 析构为 272 字节。前两项只有虚表引用，最后一项只有 HUD content 析构内的一处直接调用。相邻 DMA 与时钟控件虚表分别为 16、48 字节。

DMA 类由真实 `hardware_dma_copy.hh/.cc` 负责其虚表；实际内联 Run 和析构定义放在同名命令接口 `hardware_dma_copy_commands.hh/.cc`，继续供菜单/HUD 嵌入节点内联，同时生成原有连续虚入口。时钟缓冲/数据布局及清理归入 `map_clock_status_lifetimes.hh/.cc`，原有成员声明顺序不变，普通空析构自然清理七个 DMA 节点及资源成员。时钟控件虚表随这一实际清理模块持有，原主模块仍保留早期渲染函数及后段字形数据。

只对确需生成虚表的类保留具名接口，非多态的缓冲、content 和数据辅助类型保留正常内联行为，避免为没有原 ROM 独立入口的构造及 SetTile 生成多余公共实现。不添加强制调用、虚表数组或编译器补丁，也不改变菜单与时钟的构造、渲染正文。

四版各移除 1 条 GNU 代码和 1 条 GNU 数据规则，剩余 131 条：代码 56、虚表/数据 75。新对象、嵌入节点的内联清理、独立输出及完整 ROM 匹配仍须统一编译验证；当前未编译、提交或推送。

## Shared entity visual interface and actor tables (static batch GE)

整组处理 EntityVisualController 的共享构造/析构依赖与其后实体表的归属。四版独立析构均为 32 字节，只有自身虚表的入口指针，没有直接 BL；原 ROM 没有该基类构造的独立入口。它的 20 字节虚表与后面四张实体表（160 字节）处于两个不同的物理范围，分别保留对应普通对象。

真实类型和内联构造移入 `entity_visual_controller.hh`，由同名 `.cc` 持有编译器生成的普通虚表，并抑制不需要的独立内联副本。基类空析构仍向派生类提供内联正文，其真实定义由 `animal_actor_lifetimes.hh/.cc` 负责；独立入口自然排在原本连续的 HorseSpriteController、AnimalActor 两个清理入口之后，构成 136 字节代码块。这两个物理/生成职责不能通过统一关闭内联输出代替，未添加伪调用、别名、手工虚表或新的编译器补丁。

`entity_actor.cc` 的早期方法和访问函数保持原样，仅沿用普通虚表编译选项，使 ScriptVisualEffectActor、DefaultEntitySpriteController、AActorEntity、EntitySpriteController 四表按原声明逆序进入同一 `.rodata`。不对该模块关闭内联输出，以保留原有的独立访问入口。

四版各移除 1 条 GNU 代码、2 条 GNU 数据规则，剩余 133 条：代码 57、虚表/数据 76。具名函数接口、虚表成员和旧编译器 ARM 弱符号机制均已静态核对；新对象的实际生成、无额外构造副本、既有调用方以及完整 ROM 匹配仍待统一编译，未编译、提交或推送。

## Status screen transition family (static batch GD)

将农场地图、记录与牧场状态三类连续的切换请求作为一组整理，共 6 个已恢复的工厂/析构方法（336 字节）和 3 张虚表（48 字节）。四版原 ROM 调用地址归一化后完全一致，每个独立入口仅由自身虚表引用，没有直接 BL 候选。

`status_screen_transitions.hh/.cc` 统一承载这段连续内容，按实际 ROM 顺序定义工厂和析构；三个构造仍在真实调用方内联，虚表由原生 C++ 类型自然产生。原有三个屏幕模块的主实现和资源不移动；移除它们分别列出的早期切换 GNU 条目，四版各改为一条普通 `.text` 和一条普通 `.rodata`。没有保留地址别名、复制虚表、强制调用或分节后处理。

本组移除每版 6 条 GNU 规则，当前共剩 136 条：代码 58、虚表/数据 78。主体 UI 类的内联析构、调整跳板及分散表仍按全局依赖总览继续处理；本批为静态整理，编译器实际输出和完整 ROM 匹配尚未验证，未编译、提交或推送。

## Map, clock, return and link scene ownership (static batch GC)

按共同依赖整组整理城镇地图进入/返回、时钟菜单、返回游戏与 GameCube 联机场景，共 10 个原生方法（648 字节）和 5 张虚表（80 字节）。四版每个独立方法仅被其真实虚表引用，未发现直接 BL 调用；地址/调用归一化后，差异均位于城镇地图返回工厂：AFTER_TOWN_MAP 为 JP 0x29 / 海外版 0x2A，输入模式 1 对应的返回值为 JP 4 / 海外版 5，均保留已有区域条件。

四个真实模块 `town_map_transition`、`scene_clock_transition`、`game_scene_return`、`gamecube_link_scene` 各以同名头文件声明类型，普通 `.cc` 按各自连续的 ROM 顺序定义方法。构造继续在真实调用点内联；普通虚方法和空析构归入所属对象，编译器拥有其虚表。沿用已有叶子场景的编译选项抑制未使用的独立内联副本，不添加伪调用、手写虚表、section 属性或编译器专用补丁。

城镇地图共享选择基类仍保留内联析构，因为返回工厂的清理必须直接到达 SceneTransition。GameScene 自身和该共享基类的 GNU 表仍待处理，未将它们一并冒算完成。五条 GNU 代码规则移除，虚表规则因保留这些物理间隔中的真实依赖而净数量不变；四版各剩 142 条：代码 61、虚表/数据 81。当前为静态修改，普通输出、内联调用方、表顺序及完整 ROM 匹配均待整轮统一验证；未编译、提交或推送。

## Shared actor inline lifetime implementation (static batch GB)

沿用窗口命令组已梳理的真实函数接口机制，整组整理 `DefaultEntitySpriteController`、`AActorEntity`、`EntitySpriteController` 三个连续虚析构入口，共 156 字节。四版实际调用及常量池指针归一化后一致，独立入口只有各自虚表的一处指针，没有直接 BL 候选。

与叶子析构不同，这三个基类清理必须继续向 NPC 和具体控制器提供内联正文。将真实空析构定义放入 `entity_actor_lifetimes.hh`，并由同名 `.cc` 实现其独立入口；原始类、构造、早期访问函数及表归属仍留在 `entity_actor`。编译器按自己的内联定义逆序输出三个入口；没有新增伪调用、汇编替身、手写虚表或后处理顺序补丁，也没有对原类模块笼统添加编译选项。

本批只移除一条包含这三个真实入口的 GNU 代码规则。共享 EntityVisualController 的构造/析构及分散的实体表仍有独立归属依赖，明确保留为未完成，不将代码入口的整理冒充整组表也已解决。四版各剩 147 条 GNU 规则：代码 66、虚表/数据 81。新输出顺序、原有内联调用方和完整 ROM 匹配仍待统一编译；未编译、未提交、未推送。

## Window commands and main-menu data ownership (static batch GA)

将相邻的窗口命令与主菜单状态作为一组处理：原 ROM 的贴图上传 Run、边框命令析构、贴图命令析构、主菜单状态构造/析构连续共 840 字节；四张相关虚表连续共 120 字节。四版真实指令中的调用与常量池指针归一化后一致。三个命令入口仅被自身虚表引用，两个菜单状态入口分别只有早期菜单构造、析构的一处直接调用。

窗口不能简单将两个析构改为外部调用：既有 ControlWidget 清理路径直接内联了它们。实际的 `ui_text_window_commands.hh` 因而保留这两个内联正文，使用旧编译器原有具名接口机制，使独立入口归 `ui_text_window_commands.cc`；既有窗口函数仍可内联使用。上传 Run 正文原样移为该模块的普通函数。窗口类型与三张虚表仍归原主题，已存在的早期边框构造也不移动。该做法依据实际旧编译器的函数接口判定、内联保存及输出机制，没有增加编译器补丁、假调用或按名字重排。

主菜单状态的原构造/析构正文移为 `main_menu_data.cc` 中按 ROM 顺序排列的普通定义，其原调用方继续调用相同真实成员。原菜单模块仍拥有自己的虚表。LDS 以两个普通代码对象及原主题的一次 `.rodata` 替代四条 GNU 规则；共享 DMA 类和时钟族保留原状态，下一批连同其构造内联、表位置依赖处理。

当前四版各剩 148 条 GNU 规则：代码 67、虚表/数据 81。本批只完成源码与原 ROM 的静态核查；内联路径、实际输出顺序、额外隐式对象和完整字节匹配均待整轮统一编译。未运行编译器、汇编器或链接器，未提交、未推送。

## Animal and harvest-sprite lifetime/table owners (static batch FZ)

在共享实体依赖总览中，将可独立恢复的动物/精灵生命周期与仍需保持内联的共享基类分开处理：`HorseSpriteController`、`AnimalActor`、`HarvestSpriteController` 的真实析构入口共 168 字节，四版调用及常量池指针归一化后一致；逐版扫描仅发现各自虚表的一处入口指针，没有直接 BL 候选。`AnimalActor` 的派生动物析构仍为既有原生实现，没有改动 NPC 或共享精灵基类的内联清理。

三个析构采用普通 C++ 空函数体，由原有成员/基类完成清理；两个实际连续的晚期代码范围分别归入动物和精灵生命周期模块。原实体、动物、精灵模块继续拥有各自虚表，仅关闭 weak 和数据子段，使十张表共 992 字节自然进入各主题的 `.rodata`。动物七表、精灵两表的实际顺序与原类声明逆序吻合；`AEntity` 继续由已有非内联虚方法确定表的归属。未手写虚表、别名或伪造调用，也未迁动原有早期代码。

四版各剩 GNU 规则 152 条：代码 69、虚表/数据 83。此计数描述静态链接规则，不代表新编译输出已验证。具体析构指令、既有内联调用、实际表归属与完整 ROM 匹配留待整轮统一编译；本批未运行编译器、汇编器或链接器，未提交、未推送。

## Ambient entity behavior and virtual-table owner (static batch FY)

环境精灵的实体、控制器、12 个具体类型及其基类作为一个完整依赖族处理。原 ROM 中连续的 54 个方法共 4820 字节，15 张虚表共 384 字节；四版核对 BL、真实指针常量池和函数内部 switch 跳表后内容一致。全部方法的入向指针均在该组虚表，没有额外直接 BL 候选。

既有方法正文按实际物理顺序移入 `world_ambient_behaviors.cc`，取消虚方法的 inline 标识；12 个真实的空派生析构按原顺序成为普通定义。恢复工厂使用的 12 个具体构造函数保留原有 inline 正文并与工厂同一翻译单元，不为导出代码制造调用或实例。已有 `world_ambient_sprites.hh` 保留全部真实类、布局和声明，由行为模块作为唯一具名实现生成虚表，使用前端既有的普通输出选项。

原 `world_ambient_sprites.cc` 的基类构造析构、底层汇编函数、资源数据以及 5 个待恢复自然来源的运行库字面量保持原来的连续范围；没有将这段较晚的数据塞进前面的虚表范围。每版 LDS 以行为对象的一次 `.text`、一次 `.rodata` 替换该组两条 GNU 规则，原资源对象继续使用其已有普通位置。

当前四版各剩 157 条 GNU 规则：代码 71、数据 86。现有正文的静态搬移和原 ROM 审核已经完成；实际虚方法输出、构造内联、跳表和四版完整匹配尚待整轮统一编译。未编译、未提交、未推送。

## World prop and event-effect lifetime block (static batch FX)

继 NPC 两族后，整组处理其后连续的场景物件/事件效果生命周期，而非逐条调整 GNU 选择器。原 ROM 的 8 个入口依次为滚动精灵集合构造、单条精灵复制、事件效果控制器/宿主以及狗球、出货篮、鸡蛋的具体清理，共 976 字节；对应 8 张虚表共 288 字节。四版 BL 与真实常量池指针归一化后全部一致。

集合构造的既有正文原样移到 `world_prop_lifetimes.cc` 并改为普通定义；精灵复制按真实成员初始化，不复制填充、不伪造 vptr；6 个派生析构由普通空函数体触发既有成员/基类清理。原始集合构造只有事件控制器中的一处直接调用，复制只有该集合构造中的两处调用，6 个派生析构仅被各自虚表引用，均已在四版原 ROM 核对。

与 NPC 组不同，此处保留 `world_prop_entities.cc` 的具名实现归属，因为同一头内还有早期普通内联访问函数；没有为了移动虚表而连带挪走这些入口。原类序的逆序正好生成 8 张表，目标选项只关闭 weak/data 子段。LDS 每版改为实际晚期生命周期对象的一次 `.text` 和原主题对象的一次 `.rodata`，没有新增包装头、手写表、别名或后处理重排。

当前四版各剩 159 条 GNU 规则：代码 72、数据 87。此为静态整理；实际复制指令、析构、早期调用方、内联访问函数和完整 ROM 匹配仍待统一编译。未运行构建，未提交、未推送。

## Scheduled and roaming NPC lifetime ownership (static batch FW)

在实体组总览中联合核对计划 NPC、游走 NPC、动物/玩家、实体视觉控制器、场景物件及环境精灵的共享析构依赖。本批完成 NPC 两族的静态归属：35 个计划人物和 4 个游走人物的连续析构入口，以及包含两个实际基类在内的 41 张连续虚表，由真实 `npc_actor_lifetimes.cc` 一次接管。

39 个派生析构显式声明并使用普通空函数体，由编译器调用既有的 `ANpcEntity` 或 `RoamingNpcActor` 基类清理。两个头文件的类型、布局和已有普通函数体保持原样，具名实现归属移到实际定义这些析构的模块；没有新建包装头、假实例、手写虚表或别名。包含顺序与旧前端逆序生成虚表的规则共同保留原表序。

四版原 ROM 逐条确认全部 39 个析构均为 12 字节、仅 BL 既有基类，归一化后相同；468 字节代码连续，41 张表共 2644 字节连续。每个派生析构的原始指针仅出现在其自己的虚表槽，没有额外直接 BL 候选；已核对所有表槽均落到已知 Thumb 符号。源码中也不存在其他按值具体 NPC 实例或直接 C++ 析构调用。共享 `AEntity/AActorEntity` 内联清理和其他实体族保持既有行为，不顺带改动。

四份 LDS 各用一次 `src/npc_actor_lifetimes.o(.text)` 和一次 `.rodata` 替换 4 条 GNU 规则。当前各剩 161 条：代码 73、数据 88。这只是整轮静态修改；实际编译器生成的析构、公开虚表、附带内容及四版完整匹配仍待统一构建。未运行编译器、汇编器或链接器，未提交、未推送。

## Saved-map erase and sprite-copy definitions (static batch FV)

承接全局 GNU 入口的整体清单，将最后两条全局通配代码规则换为真实定义。EraseSavedMapTreeNodes 的递归删除 body 原样从头文件移到 saved_map_tree_erase.cc，保留右子树递归、左链遍历和真实 free 调用；声明仍在拥有树类型的原头文件。

场景精灵基类复制改为 scene_sprite_copy.cc 中的常规成员复制构造，声明归入现有 scene_sprite.hh。按真实成员顺序借用 world、复制引用计数 tile entry、复制 tile_index、复制有 count 限制的 palette 容器；vptr 仍由真实类生成。不用 memcpy 替代带所有权的对象复制，也不创建原始字节数组或手写虚表。

两处原 ROM 代码共 124 字节（44+80），四版核实 BL 和真实虚表字面量后归一化完全一致，入向对象重定位也已记录。由于这两处与各自主要实现不连续，作为明确职责的 helper 定义在原物理位置各用一次 .text；不拆原类型为重复声明头文件，不用编号文件或额外编译选项。

四版现在不再有全局 *(.gnu.linkonce.t...) 代码收集，剩每版 165 条具名对象 GNU 规则：代码 75、虚表/数据 90。递归调用方的内联、复制指令选择及完整 ROM 匹配仍待最终统一编译；这是静态源码组织进展，未编译、提交或推送。

## Scene controller record and queue lifetimes (static batch FU)

将全部剩余全局 GNU 入口一起核对后，先恢复控制器记录与三队列生命周期这一完整依赖组。两条相邻记录构造原 body 原样移入 game_scene_records.cc；真实 ActorRecord/EventIconRecord 结构和布局检查归入同名头文件。三队列容器、请求及 Push 模板归入 game_scene_script_queue.hh，非内联空析构在同名 .cc 由三个真实队列成员自动执行逆序销毁，未手写删除标志处理或替代循环。

两段原代码分别为连续记录构造 172 字节、队列析构 104 字节。四版 BL 归一化后均完全一致，旧对象的实际重定位调用已保留。外层 GameSceneScriptController 的 Run 与析构保持原体，其两个构造既在调用方内联，也确有位于本模块末尾的 200/224 字节独立入口，两种用法均保留。该对象只用 -fno-weak -fno-data-sections，不使用会抑制这两个真实入口的 -fno-implement-inlines；唯一 16 字节表进入普通 .rodata，不添加构造实例。

每版 LDS 移除两条全局 GNU 代码规则及一条控制器 GNU 表规则，分别按既有物理位置写普通对象。两段本来不连续，因此保留有实际职责且各有同名头文件的记录/队列模块；没有把它们塞入控制器早期代码范围，也没有增加编号源码或人工 section。仍未处理的两个全局入口是存档地图树递归删除和场景精灵基类复制，已记录各自调用方内联/资源复制依赖，不漏算为完成。

同时核实旧 agbcp finish_function：空析构且非复杂继承时省略 vptr 重设，不能仅凭显式空析构就断言会多写虚表；实际生成仍须最终验证。当前每版 GNU 剩 167 条（代码 77、数据 90），全局通配代码规则剩 2。此轮只做静态整理，未编译、提交或推送。

## Complete identity, keyboard, wild-dog and decimal table owners (static batch FT)

承接全部 174 条 GNU 规则的总览，复核剩余 8 个只有虚表规则的候选及文本窗口/主菜单/时钟窗口的共同生命周期依赖。本批将已经具备完整函数归属的 4 个主题整体改为普通虚表生成：new_game_identity、new_game_name_input、wild_dog_actor、font_decimal。没有单独移动函数，也没有修改类布局、内联语义或函数体。

四版原 ROM、既有符号和先前野狗类型审计逐字复核虚表：JP 12 张/308 字节，US/EU/DE 各 13 张/324 字节。每张表的两个元数据字及所有 Thumb 函数入口均有对应；各主题内物理连续，既有类声明的逆序与原表顺序一致。海外版额外一张 1×2 数字绘制表保持原有区域条件。

使用旧 agbcp 已有的 -fno-weak -fno-data-sections 目标选项，表仍由真实虚函数/具名实现确定唯一归属并正常生成。四份 LDS 各以该对象的一次 .rodata 替换 4 条 GNU 数据选择，源码和头文件不增加新层。仅引入 <new> 不能证明会生成 bad_alloc 副本，本批不凭该依赖一概拒绝，也不修改库头或预处理器。

其余 4 个候选保留明确依赖：控制器记录/脚本队列、场景状态成员生命周期、world 的独立运行库字面量、实体基类内联析构。UI 连续代码/虚表组也已完整记录；ControlWidget 基类表先于派生表、嵌入成员析构以及 map_clock_status 的另一段资源范围，决定不能把三个 UI 对象粗暴合成一个普通段。这些仍属于未完成项目，不用通配规则或假表绕过。

当前每版剩 170 条 GNU 规则：代码 79、数据 91。已完成的是源码/链接组织的静态修改，未运行编译器、汇编器或链接器；自然输出、额外局部副本、原代码字节和四版 ROM 匹配留到整轮统一验证。未提交、未推送。

## Explicit value assignment dependencies (static batch FS)

将剩余四条全局赋值运算 GNU 选择规则作为完整依赖组处理。连续的 Sheep、Cow、Livestock 赋值入口归入 src/livestock_copy.cc；真实类声明仍在各类型原有头文件中，不增加空包装头文件。羊/牛通过真实 BarnAnimal 基类赋值后复制自身生产状态位；Livestock 先调用 Animal 赋值，再按已确认位域顺序复制饲养、健康、疾病和户外时间字段。

WorldSpriteEffectFrames 已有的两个资源组、两个 tile 句柄复制方法体原样移入 src/world_sprite_effect_frames.cc，去除 inline，类型与字段声明保留原所属头文件。两段各由一次普通 .text 链接，不增加编译参数、GNU 包装、显式假实例或中转函数。

每版原函数大小分别为 116、124、188、128 字节，共 556 字节。四版经过真实 BL 归一化后均逐字节一致；原 ROM 中羊/牛到 Livestock、Livestock 到 Animal 的调用链已核实，既有对象入向重定位记录保留在审计文件中。字段未知部分仍保留原 unk 名称。

- JP: livestock `0x080D7308–0x080D74B4`；sprite frames `0x080E3BD0–0x080E3C50`。
- US: livestock `0x080D7B50–0x080D7CFC`；sprite frames `0x080E4438–0x080E44B8`。
- EU: livestock `0x080D7B9C–0x080D7D48`；sprite frames `0x080E4484–0x080E4504`。
- DE: livestock `0x080D7AB4–0x080D7C60`；sprite frames `0x080E439C–0x080E441C`。

剩余 GNU 规则每版 174 条：代码 79、虚表/数据 95。当前完成静态组织，新的逐成员赋值指令、位域掩码、调用方内联及完整 ROM 匹配仍待整轮统一编译验证；未运行编译器、汇编器或链接器，未提交、推送。

## Contiguous scene menu transition owners (static batch FR)

对整组 37 种场景切换对象核对物理顺序和共享依赖后，将其中连续且直接继承 SceneTransition 的 33 种菜单/活动切换对象归入 src/scene_menu_transitions.cc 与同名头文件。33 个原有 CreateScene 方法体原样移出主题头文件，33 个对应析构由真实成员和基类生成；构造函数仍保持 inline，60 项对应布局断言随类定义一起迁移；故事场景自身的 phase 断言保留在原头文件。主题头文件引用共享声明，不再各自生成这些切换虚表。

66 个原 ROM 函数在四版中经过 BL 与真实具名 ROM 常量池指针归一化后逐字节一致。每版 33 张虚表均核对为两个零元数据槽、真实析构指针和真实工厂指针，共检查 132 张原表。源码函数定义按该连续区间的物理顺序排列，同时修正旧清单把工具箱、冰箱、橱柜排错的顺序。

新模块使用旧编译器已有的 -fno-weak -fno-data-sections -fno-implement-inlines：以具名接口归属生成公开的普通只读虚表，保留调用方构造内联，避免所属模块额外输出未被原 ROM 保留的构造入口。旧 agbcp 的全局声明链反向遍历虚表，所以头文件按相反类声明顺序组织，未手写表初始化、别名或编译后重排。LDS 中新模块仅各出现一次 .text 和 .rodata。

- JP: `.text` `0x080DAAD4–0x080DB97C`；虚表 `0x080E5074–0x080E5284`（均为左闭右开）。
- US: `.text` `0x080DB320–0x080DC1C8`；虚表 `0x080E5C34–0x080E5E44`（均为左闭右开）。
- EU: `.text` `0x080DB36C–0x080DC214`；虚表 `0x080E5C80–0x080E5E90`（均为左闭右开）。
- DE: `.text` `0x080DB284–0x080DC12C`；虚表 `0x080E5B98–0x080E5DA8`（均为左闭右开）。

镇地图三个类型的抽象基类析构存在实际内联依赖；Clock/ReturnToGameScene 的表又与 GameScene 表交错，未强行并入本组，也未改变继承结构。其余 GNU 规则剩每版 178 条：代码 83、虚表/数据 95。数据规则数增加 1，是旧 game_scene 合并条目在已移出的连续区间两侧仍各有未解决内容；不是新增虚表，不能视为该 owner 已清理完成。

本批只完成静态源码组织与原 ROM 对照。新输出的析构标志/成员销毁顺序、现有调用方内联、自然表顺序、符号可见性、额外内联副本与运行库字面量仍须在整轮统一编译时验证。未运行编译器、汇编器、链接器，未提交或推送。

## Ordinary read-only tables for complete class owners (static batch FQ)

完成 14 个“只有虚表 GNU 规则、没有晚期 GNU 代码规则和其他已选普通 rodata”候选模块的整批依赖检查。本批处理其中归属明确且未引入 <new> 字面量路径的 6 个模块：scene、hardware_blend、hardware_interrupt_guard、font_draw、scroll_state、game_object，共 8 张真实编译器虚表。

依据旧 agbcp 的 import_export_class/import_export_vtable/finish_vtable_vardecl 及 build_vtable 实现，对上述 6 个目标使用已有 -fno-weak -fno-data-sections 选项。具名接口或真实非 inline 虚函数继续确定唯一公开归属，表内容、函数指针及只读属性仍由编译器生成，直接进入普通 .rodata。保留全部函数体、ARM/IWRAM 原生代码和源码顺序；没有手写虚表、编译后重排、预处理器新规则或全局关闭 weak。

四版 LDS 在原来位置各把这 6 条 GNU 数据规则替换为对应对象一次普通 .rodata。另将 WildDogBehavior 的纯协议声明放回未指定输出归属的范围；原生实现只创建 WildDogActor 和 5 个具体状态，没有安装纯协议自身虚表。具体类的生成归属保持，避免具名 implementation 额外输出一个无原 ROM 对应的抽象接口表。

GNU 规则剩每版 207 条：代码 113、虚表/数据 94。其余 8 个候选仍涉及 <new> 的潜在匿名常量、共享容器/成员生命周期或尚未完整证明的生成输出，继续保留当前设置并纳入后续依赖组。当前是源码与编译器机制的静态整理；表可见性、自然输出顺序、局部 inline 副本、普通 .text 字节及最终 ROM 匹配仍待整轮统一编译确认，未编译、提交或推送。

## VBlank binding table generation ownership (static batch FP)

对当前全部具名接口与 GNU 虚表选择规则进行整体对照，243 个具名接口类候选中，确认 HardwareManagerVBlankBinding 一处实际虚表生成单元与链接选择不一致：头文件指定由 hardware_vblank_binding.cc 实现，但 LDS 的整组硬件管理器虚表从 hardware_manager.o 收集。

将该具名 implementation 声明移到真正构造管理器状态及多继承组的 hardware_manager.cc，使主/次基类、VBlank 绑定及恢复对象的虚表归属与当前物理组一致。绑定构造、原生析构、列表操作及其源顺序不变；没有额外强制实例、虚假调用、别名或链接位置修改。

这一步修复生成归属，尚未解决整个管理器族的普通段排列，GNU 规则数量仍为每版 213 条（代码 113、虚表/数据 100）。静态候选检查不能替代编译结果，完整多继承析构、调整跳板与虚表顺序仍待继续处理并统一验证。

## Explicit template instance ownership (static batch FO)

把 3 个查找实例和背包的 4 个轮换操作作为一组核查真实生成归属。背包 4 项在每版连续占 360 字节；NPC 日程、路径和玩家字节查找分别为 60、60、116 字节，物理位置各自独立。四版逐函数按 BL 目标归一化后一致，旧对象各版合计有 8 处真实 Thumb 调用重定位。

依据本项目旧 agbcp 的显式模板实例、外部实例声明和待生成队列实现，将已有实例放入对应物理位置的普通编译单元。背包两个模板函数体、NPC 两个比较器和所有调用目标保持；比较器归入已有 npc_schedule.hh，Slots 仍由 rucksack.hh 声明。NPC 的 C++ 调用方显式声明共享实例在外部，避免其 GNU 通配规则再收进隐式副本。不复制 STL 算法，不添加包装函数、虚假调用、section 属性或 Makefile 特例。

四版 LDS 各用普通 .text 替换 4 条 GNU 选择器；GNU 剩每版 213 条：代码 113、虚表/数据 100。新实例单元分别位于原有不连续位置，不将它们挤入早期业务模块改变 ROM 顺序。

本次仅静态核查并整理源码。显式实例的最终出段、顺序、调用方副本抑制、ABI 名称和指令字节仍待整轮统一编译确认；没有运行编译、汇编、链接、提交或推送。

## Contiguous saved-image copy dependencies (static batch FN)

把整条连续的存档复制链作为一个依赖组处理：GameStateSaveImage 复制/析构、完整 GameEventState 原生复制，以及 NPC、农场、畜舍、鸡舍、狗、动物基类、农夫、背包和账本的复制/析构入口，共 14 个连续入口。四版该范围均为 10,976 字节；逐入口按真实 BL 目标归一化后字节一致。

原有 7 个头文件函数体移入既有 game_state_copy.cc，账本空析构移为常规独立定义；畜舍、鸡舍的成员复制和 Animal 赋值按现有真实字段/数组表达，不改变结构布局。事件状态的完整汇编原样归入该模块，删除原 asm/event_state.s；只移除已经包含过的宏头，不重写指令。原 ROM 的顶层析构明确调用背包/账本析构，狗赋值明确调用 Animal 赋值，均保留直接函数关系。

四版 LDS 现在用已有 src/game_state_copy.o(.text) 承接整个连续复制范围，各删除 11 条 GNU 手工选择和一条独立事件复制对象。移除 dog.o / money_account.o 的 -fkeep-inline-functions 例外：这些真实被调用的操作有常规独立定义，不再依赖强制保留头文件副本。GNU 规则剩每版 217 条：代码 117、虚表/数据 100。

当前只完成静态源码、边界、调用及四版归一化核查；旧编译器数组复制、析构标志、其他调用方内联以及最终指令匹配仍待统一构建。不将迁入 .cc 的两段原生复制计作高级语言反编译，也未编译、提交或推送。

## Inline definition scopes and shared DMA consumer (static batch FM)

对当前全部头文件和 C++ 源码统一筛查，覆盖 847 个类/结构定义及 285 个类外 inline 定义。检出并成组修正 6 份头文件中 8 个作用域冲突：类处于 implementation 未知归属模式，函数体却落在另一类的 named interface 范围。修正仅限定旧编译器 pragma 的有效范围，不改变函数体、成员布局或定义顺序；涉及主菜单、UI 上传、飞盘、飞盘成绩、图书页面和联机界面的完整调用链。

HardwareDmaCopyLink 的实际构造来自主菜单/HUD 的成员对象，hardware_dma.cc 只有 DMA 操作函数，不会凭空生成这个类的 GNU 成员。四版旧 ROM 的 DMA Run/析构入口及虚表槽已核对，代码和虚表均紧随主菜单相应组。因此把错误的 hardware_dma 对象选择归回实际 main_menu_widget 消费者，并将两条紧邻重复选择合并；不添加虚假对象或强制实例。

当前每版 GNU 选择规则为 228 条：代码 128、虚表/数据 100。这仍是待清理的 GNU 组织，不把归属纠正或 whole-owner 通配算成最终普通 .text/.rodata。最终统一构建还须核对内联决定、实际发出顺序及重复合并；当前没有执行编译器、汇编器、链接器、提交或推送。

## Contiguous map and tilemap callback definitions (static batch FL)

继续按完整依赖及 ROM 连续性，将已有的三个真实 C++ 定义收回现有普通模块，不增加源文件或生成层：FontTilemapRectCommand::Run 跟随相邻的数字 tilemap 命令执行函数，进入 font_decimal.cc；DestroySavedWorldMap 与 SavedMapTree 构造跟随树插入函数，进入 saved_map_tree.cc。头文件保留常规声明，函数体和结构成员不变。

四版原 ROM 均确认了两张真实虚表的回调地址，并确认 GameSceneSavedMap 构造在 +0x20 直接 BL 到 SavedMapTree 构造；后者原本就是独立调用，不能依赖头文件内联定义碰巧保留一个 GNU 副本。DestroySavedWorldMap 仍是原来的带标志清理入口，未改成会增加 vptr 写入的另一种析构实现。

四版各移除三条人工独立 GNU 选择器，现有 src/font_decimal.o(.text) 和 src/saved_map_tree.o(.text) 自然承接这些紧邻的定义。GNU 规则剩 230 条：代码 129、数据 101。字体虚表仍由实际定义构造/析构的 font_draw 生成；不把仅指定对象或通配符视为完成剩余 GNU 整理。

静态核查保留了原函数地址、真实 BL、虚表槽及函数体等价证据。输出指令、对齐、调用方和递归内联实例仍须在最终四版统一构建中验证；未运行新的编译探针、未提交或推送。

## Contiguous save and scene-state lifetimes (static batch FK)

全组依赖梳理后，先将两个已经具备真实 C++ 成员生命周期、且物理位置直接相邻的析构入口收回普通源码顺序：存档复制后的 GameStateSaveImage 析构，以及场景状态主块后的 GameSceneState 析构。

src/game_state_copy.s 改为同名 .cc，保留原有 776 字节复制函数的完整 native 汇编文本；其后的析构由实际类成员自然生成。GameSceneState 的析构定义从头文件移至 src/game_scene_state.cc 末尾，作为普通非内联虚析构，同时让该真实 key function 拥有对应虚表。没有增加伪造调用、包装类、别名、section 属性或编译选项。

四版各移除两条独立 GNU 析构选择器；普通 .text 对象条目仍各占原有位置，后一个模块顺序不变。GNU 总规则由 235 减为 233（代码 132、数据 101）；其余成员和虚表组织尚未完成，不能据此报告完整动态化。

静态核对保存了四版原复制/析构地址、原字节哈希，以及迁移前后逐字符一致的 native 汇编。析构的实际指令、调用方内联变化、成员清理和弱副本选择仍需最终统一构建确认；本轮没有调用编译器、汇编器或链接器。

## Transition-family emission ownership (static batch FJ)

承接全 GNU 总览，进一步追踪完整的 48 个场景切换派生类，包括先前直接继承扫描漏掉的 TownMapReturnTransition。核对当前真实 C++ 构造调用、定义所在的 pragma 范围，以及固定版本 agbcp 的 lex.c / decl.c / decl2.c；没有运行编译探针。

此前 FI 将链接规则绑定到同名场景文件，只证明了文件存在，不能证明该文件会输出对应弱定义。本批纠正这项不足：游戏主场景实际构造的切换对象，其内联工厂、隐式析构和虚表按真实使用方 game_scene 归属；锻冶屋结果切换按真实使用方 scene_blacksmith_shop 归属。链接规则仍在原位置，未移动代码或表的物理顺序。

24 个头文件内工厂定义原先错误落入界面实现的 named interface 范围，现与所属的无参 implementation 类定义保持同样的内联语义，并在函数后恢复原范围，避免影响其他类型。RucksackMenuTransition 的内联定义从独立 .cc 移回声明头文件，使真实调用方能够看到定义。所有函数体、成员、参数和布局保持不变，不增加虚假调用、强制实例、别名或编译选项。

本批仍有 235 条 GNU 链接规则，不能把“归属纠正”计为普通段清理完成。当前规则虽覆盖四版，但实际生成副本、顺序及字节仍待整个静态批次完成后的统一验证。尚余存档复制/模板、硬件生命周期、跨位置对象等组；不回头检查已完成的普通 .text，也不开始后续相邻模块精简。

## GNU dependency overview and paired ownership (static batch FI)

先对全部四版 GNU 规则进行总览：每版 235 条，代码 134 条、数据 101 条；其中 63 条虽已按对象收集，仍属于过渡状态。四版选择器及次序完全一致。84 个明确对象中，19 个仍在同类输入中跨位置出现（18 个涉及代码、10 个涉及数据，两者有交集），不能只处理重复行或前一处入口。

| 物理组 | GNU 规则数 | 关联处理内容 |
|---|---:|---|
| 早段字体 | 1 | Run 内联方法和后段字体虚表同属一类 |
| 启动及存档复制 | 17 | 复制/析构依赖、实际调用和生成来源 |
| 硬件及动物复制 | 11 | 命令方法、多继承调整入口、共享赋值 |
| 场景切换代码 | 42 | 工厂、转换对象、状态清理与后段虚表 |
| 实体及模板代码 | 16 | 控制器析构、模板及同一类的表 |
| UI/场景及晚段支持代码 | 47 | 隐式入口、回调、显示/教程场景 |
| 启动及硬件虚表 | 15 | 与前述类的生命周期一起核对 |
| 场景切换虚表 | 4 | 包含一条跨多个模块的长规则，不能当成一张表 |
| 实体虚表 | 17 | 与实体/控制器和模板一起处理 |
| UI/场景虚表 | 65 | 与前述方法、析构及调整入口一起处理 |

保存对象提供 JP 762、其余三版各 768 条指向既有 GNU 符号的重定位记录。旧对象中的重复定义为 FontTilemapRectCommand 表、Animal 赋值、Livestock 赋值三类；不能因此断言当前待编译源码只会产生这些重复。97 条当前选择规则没有匹配的旧 GNU 成员，包含本静态批次新恢复/改名的类型，必须结合当前源码与既有转换记录核对，不能直接计为缺失或已验证。

在总览后成批将每版 41 条全局符号匹配绑定到已恢复的真实源对象，剩余全局规则 25 条。工厂、析构、调整入口和对应虚表一并处理；保留所有现有物理位置及成员选择范围，不将后段条目提前收走。未确定生成链的存档/容器复制和跨对象场景虚表长规则暂保留，不虚构生成调用。

全局接口扫描覆盖 78 组显式 interface 声明。font_draw.hh 有外部虚表和 Run 的真实需求，但 font_draw.cc 缺少配套 implementation；当前 Makefile 用 -P 后从标准输入交给 agbcp，不能依赖源文件名自动配对。补齐该真实实现文件的声明，字体表明确由 font_draw.o 收集。另一处 hardware_input.hh 仅用于完全内联的参数构造，没有独立 GNU 对象需求，保持其原有抑制副本安排。依据为现用 agbcp 的 lex.c 接口配对逻辑及实际源码/旧对象，不采用现代 ABI 推断。

本轮未改变函数体、类型布局、函数/虚表次序或编译选项。GNU 总条目仍为 235，不能把绑定对象当作最终普通 .text/.rodata 清理完成。接续按整组处理跨位置的生成关系与自然输出顺序；相邻模块精简在 GNU 完成后进行。尚未运行编译器、汇编器、链接器、提交或推送。

## NPC class groups and actual template callers (static batch FH)

定点 NPC 的 35 个派生类、游走 NPC 的 4 个派生类，连同两类基类虚表，按各自真实源码归属收集自然生成的 GNU 内容。四版原 ROM 均核实 39 个 12 字节析构入口：每个只转到对应基类清理，随后返回；41 张虚表的首个虚函数槽指向相应析构入口。原先已恢复的完整类声明顺序与物理表序一致。
每版核对 80 个代码/表对象，共 3112 字节；四个连续范围的边界不变。NPC 与游走 NPC 的四条逐类代码/虚表规则改为各自对象收集，源码、成员、函数体、ABI 和全部普通段条目不变。
两个 upper_bound 实例分别比较日程时间及路径节点时间。它们在 npc_entity.cc 中已有实际调用及显式模板实例化；将仍全局匹配的两个入口改由 npc_entity.o 提供，并保留原有较早的两个物理位置。这样后面的 NPC GNU 收集不会把这两个实例吸入析构块，也不新增无用途的实例或调用。
硬件上下文的三个 Run 方法与析构生成顺序尚需核对，未在本轮扩大其 GNU 通配范围。本轮仍是静态组织与引用核查，GNU 对象级收集是过渡状态，不能视为最终普通段布局已完成；尚未运行编译器、汇编器、链接器或提交。

## Hardware sound and list compiler ownership (static batch FG)

四版中，音频命令的两个自然析构入口（24 字节）和两张虚表（32 字节），以及硬件链表的自然 HardwareLink 析构入口（12 字节）和三张虚表（68 字节），均由实际所属的 hardware_sound / hardware_linked_list 对象生成。
既有四版对象的 GNU 成员清单、输入段物理次序和原 ROM 边界已逐项核对；每版覆盖 8 个输入段、136 字节。四条全局按类名匹配的链接规则改为这两个实际对象的代码/数据收集，位置不变。两份源码和头文件保持原样，不添加 pragma、虚构的类、强制实例、段属性或编译选项。
这是生成归属和链接选择的收敛，仍保留编译器自然 GNU 输入，不能算作最终普通 .text/.rodata 组织已经完成。其余 GNU 条目及完整代码生成验证继续处理；整批静态完成前没有运行编译器、汇编器或链接器。

## VBlank physical code ranges without custom text sections (static batch FF)

优先处理最后三个人工 .text 子段。四版的物理顺序相同：中断保护的清理副本 84 字节、VBlank 绑定回调/构造/析构 176 字节、追加操作 60 字节，合计连续 320 字节；随后是真实的 44 字节多继承析构调整入口；再后为移除、拼接、交换三项链表操作，共 180 字节。
前一连续块归入已有 hardware_vblank_binding.cc：将清理副本放在绑定回调之前，追加操作放在绑定析构之后。后面独立的 180 字节范围由同名 hardware_vblank_list.cc/.hh 管理。这样只新增一套按实际功能命名的源码/头文件，不机械为三个 section 各建一个文件，也不跨过中间真实的析构跳板。
六个既有函数的实现、名字和 ABI 原样保留，声明归入其所在模块头文件。hardware_interrupt_guard 和 hardware_manager 保留各自早期的普通代码；三处 SECTION 属性全部删除。四版 LDS 只按两个连续块列 hardware_vblank_binding.o(.text) 与 hardware_vblank_list.o(.text)，中间编译器生成的调整入口及后续 GNU 条目保持原位。无需修改通配的 Makefile，不新增生成器、别名、填充、编译选项或地址限定。
保留副本的最初发出编译单元仍未确定；这里依据已知的中断保护和链表操作功能安排维护归属，不虚构第二套类或额外调用。代码组织改成普通输入段，不等于这些副本的历史生成来源已经恢复。
四版原 ROM/旧 map 确认全部 544 字节范围的边界，现有函数和原生绑定析构文本逐字保留；静态差异检查通过。当前 LDS 的人工 .text.* 条目降为零。尚未运行编译器，移动编译单元后的实际输出、GNU 副本选择和完整 SHA-1 仍留待整批统一验证。

## Reconnect compiler-owned former ordinary vtables (static batch FE)

按历史匹配对象检查原来作为普通 .rodata 手工输出的 54 张虚表，发现两个模块的源码已经恢复正常虚函数，LDS 却仍沿用旧普通表入口：new_game_identity 的两张表，以及 hardware_interrupt_guard 的一张表。四版均改为在原物理位置接收对应对象的自然 GNU 数据；不恢复手工表、不改预处理器、不添加别名。
四版原 ROM 逐槽核对确认画面的 12/16 字节表及中断链表的 36 字节表，共 64 字节/版。确认画面的两段完整类声明改为 Scene 在前、Core 在后，并保留 Core 前置声明，遵循现用旧编译器的声明链顺序来生成 ROM 所需的 Core、Scene 表序。继承、成员、方法签名、方法体和字段检查均不改变。删除已经没有调用方的手工 Scene 虚表声明及其专用 typedef；原生 Core 初始化仍直接引用编译器的真实表。
历史大虚表文件的其他候选已分别核实为前序整理移入真实模块：世界/对象、动物实体、NPC、脚本引擎、参赛选择和地图场景；其中 AudioActorEntity 已恢复为 AnimalActor。不能因为旧对象名已经消失就误判为未链接。
此次修复的是手工表删除后的生成/链接衔接。GNU 按对象收集仍是过渡组织，最终普通段要求不变；未运行编译器，实际表序和全部字节仍待统一验证。

进一步对照四版历史符号：JP 的 161 张主虚表、海外各 162 张主虚表，以及每版三张多继承次级虚表，在当前真实类归属和 LDS 的 GNU 收集入口之间均有对应关系。EntityVisualController 的内联基类由 entity_actor.cc 中两个实际派生类构造使用，不能仅按声明所在 entity.hh 推断发出对象。这里核对的是已知表名是否漏接；新增或多余的编译器实例、弱副本选择、表内顺序及实际输出仍须统一构建确认，不能据此宣称 GNU 已清理完成。

## Actual menu bases and pause-menu ownership (static batch FD)

清理 .text/GNU 生成关系时，发现 GameSceneUiComponent 将 HardwareContext 的构造、析构入口套在另一占位类名下，同时又被用于完全不同的暂停菜单指针。恢复为两条真实关系：GameSceneMenuCorePrefix 直接继承 HardwareContext；GameSceneState 的 +0xB8 成员使用 GameScenePauseMenuOwner，持有 MainMenuWidget*。
四版原 ROM 的物品菜单核心构造和析构都直接调用 HardwareContext 对应入口；其 12 字节虚表末项指向自身析构。游戏场景两段原生控制代码中，每版八次暂停菜单创建均调用 MainMenuWidget 构造，再写入 +0xB8；更新和关闭流程亦调用该类型，删除时使用 +4 虚表中的 +8 析构槽。MainMenuWidget 实际继承 ControlWidget，并不继承 HardwareContext，不能因为两个基类均为八字节就混用。
此次只修正声明和所有权类型，不改变菜单核心成员顺序、场景 +0xB8 槽、现有虚调用实现、原生代码或 LDS。移除两个借用其他类 ABI 的 asm 声明；不增加伪类、别名、手工虚表或强制生成调用。原有对象大小/字段偏移检查保留，生成的析构代码和虚表顺序仍须在整批统一编译中验证。GNU 剩余条目数量不因此减少，不记作已完成链接清理。

## Event registration copy member boundary (static batch FC)

继续沿存档复制的 .text/GNU 依赖检查。原事件状态的 +00 计数、+04 三个 u16 ID 构成容量为三的列表；注册、删除和复制均按 count 处理有效范围。四版 7132 字节事件复制体除唯一 memmove 调用的相对距离外逐字节相同，开头先清零目的 count，缓存源 count，只复制有效 ID，再写回 count；+0A 的两字节没有被该路径初始化或复制。
在原 event_state.hh 中将其恢复为一个 12 字节 GameEventVariableList 成员，末尾两字节由结构自然对齐承担，移除误作字段的 unk_0A。原来的三个 ID、计数和 +0C 活动恋爱事件标记位置不变；后续全部位域声明原样保留。默认构造只清零计数，成员复制保留仅复制有效项的规则；注册/删除函数仍在原 event_state.cc，既有操作顺序不变。
这一步补齐的是原生复制依赖的成员边界，不把新的列表类型直接等同于已匹配的 GameEventState 复制函数。src/game_state_copy.s 和 asm/event_state.s 及它们的 LDS 条目仍保留：后者目前只由前者的汇编调用，单独删除原生体不会让编译器自动生成替代；GameStateSaveImage 中 Dog 的复制/赋值关系也尚未充分恢复。没有通过假调用、强制保留或自创 section 让隐式入口出现。
依据是四版 ROM、现有复制/注册/删除实现，以及 docs/mary-native-audit/events/event_state_registration.md 的独立路径结论。未运行编译器；完整指令输出和所有现有字段偏移检查留到整批统一验证。

## Base scene vtable declaration order (static batch FB)

场景基类的两张虚表仍分别由全局 GNU 选择式排列。核对四版原 ROM，AScene 与 SceneTransition 的两张 16 字节表连续，各自包含两个零元数据字、对应析构入口和 __pure_virtual 入口；不存在普通数据夹在其中。
两条非内联虚析构的定义均在 src/scene.cc。旧 scene.o 的自然表顺序却为 SceneTransition、AScene，与 ROM 相反。依据现用旧编译器的虚表声明链遍历，将两段完整类定义调整为 SceneTransition 在前、AScene 在后；已有前置声明和所有权类型足以满足依赖，未改变继承、成员、函数签名或实现。
四版 LDS 改由实际定义析构的 src/scene.o 接收这一连续组，移除全局逐表指定。此步骤属于 GNU 生成关系整理，尚不是最终只列普通 .text/.rodata 的链接结构。编译器实际输出、COMDAT 副本选择和四版 ROM 一致性仍待整批统一验证。
相邻小模块的精简合并按用户最新要求留待 .text/GNU 整理完成后进行；本轮未合并源码模块，未运行编译器、汇编器或链接器。

## Natural new-game menu vtables (static batch FA)

新游戏菜单的三条数据链接语句仍包含旧手写核心表的 `.rodata` 插入位置。当前核心已经是 HardwareContext 的真实派生类，拥有隐式虚析构；源码只引用编译器的 __vt_15NewGameMenuCore，不再定义这张普通数组。
核对旧对象，其普通 rodata 恰为这张 12 字节核心表。四版原 ROM 中 MenuIntro、LoadedSave、核心、菜单场景四张表连续排列，长度依次为 16/16/12/16 字节，所有函数槽均对应现有符号加 Thumb 状态位。
本轮将场景声明放在核心定义之前，以指针前置声明解除声明顺序依赖，成员、继承、函数体、布局检查及 ABI 保持原样。结合现用旧 GCC 的虚表生成及逆序声明遍历机制，让四张表按类定义自然产生；LDS 只保留 `src/new_game_menu.o(.gnu.linkonce.d.*)`，移除旧普通表插入位置及无用的手写虚表元素 typedef。
四版各减少两条 GNU 数据链接语句。没有新增 section、别名、重排工具或编译选项。当前没有运行编译器，实际 GNU 输出、弱副本和附带常量仍待整批验证，不能将这一静态修正视为已经通过 ROM 比对。

## Intro/menu transition ownership (static batch EZ)

MenuIntroTransition 的唯一创建点是 NewGameMenuScene 的标题菜单构造函数；它将菜单的 continuation 接回 GameIntroScene。
原来的类型和内联 CreateScene 定义却位于 intro_scene.hh，导致 LDS 在启动核心之后又单独抽取这个返回入口。本轮把同一个真实类型移入 new_game_menu.hh，实现放入 new_game_menu.cc；名称、ABI、函数体及调用不变，没有新增类型或伪造调用。
四版启动与新游戏菜单的晚段代码各由所属对象一次收集 GNU 代码，启动虚表也按所属对象一次收集。原生顺序仍要求 IntroNameEntry/IntroMenu 两个工厂在前，随后各析构；菜单则为 LoadedSave 工厂、返回标题工厂、返回类型析构、LoadedSave 和核心析构。当前声明及定义按该顺序组织，实际输出尚待统一编译验证。
菜单的 rodata 仍有一处真实交错：MenuIntro、LoadedSave 两个虚表之后，是普通核心表和 GNU 场景表。本轮保留其选择条目，未将这部分标为完成；不为减少行数而提前后面的场景表。普通代码、普通数据条目及硬件模块间隔不变。
四版既有符号表确认返回工厂 60 字节、析构 12 字节及相邻 16/16/12/16 字节表的边界；此证据不替代当前编译结果。本轮只做静态整理，未编译、提交或推送。

## Scene-owned GNU collection (static batch EY)

飞盘成绩、动物参赛选择、生日输入、滚动菜单、工作人员名单，以及动物照料、鸡祭、收获、浇水四个小游戏，合计九个真实模块，继续按原有物理位置收集编译器生成的 GNU 代码及虚表。
四版各 18 条链接语句移除逐类或逐函数后缀，使用对应对象的 `.gnu.linkonce.t.*` / `.gnu.linkonce.d.*`；前面已经排列的场景切换代码和全部普通 `.text/.rodata/.data/.bss` 条目保持原顺序。
这些类的成员和生命周期已在前序静态整理中按原生构造、析构和调用关系恢复；本轮不添加类、节属性、强制实例化、别名或编译选项，也不以普通 `.text.*` 通配替代模块整理。
既有对象文件只用于核对历史 GNU 成员和已选入的场景切换副本；六个当前新模块没有基线对象，不能将旧产物当作当前代码生成结果。所有九个模块的实际隐式实例、弱副本选择、虚表和析构顺序仍须统一四版编译验证。本轮没有运行编译器、汇编器、链接器，没有提交。

另将飞盘、主菜单控件、烹饪、背包菜单、场景文本变量和文本窗口六个模块纳入同批整理：四版旧对象的所有非空 GNU 输入段仍匹配同一个原有链接位置，没有额外前移条目。
本批合计十五个模块，四版各 30 条 GNU 语句按真实对象收集。启动模块未照搬此规则：它的 MenuIntroTransition 晚于 IntroSceneCore，整体收集会提前该入口，仍须追查生成归属。
此项历史对象核对不替代当前源码的统一编译验证；没有运行编译器或改变普通段顺序。

## ROM trailer numeric-limits candidate

静态批次 EX：核对 ROM 尾部 numeric_limits 线索。四版字节相同，旧编译器默认无符号 char；
GCC/SGI/STLport 的定义分别核对，未找到足以认定原库版本与对象排列的证据。
源码显式显示 12 个已知字值并保留全部 84 个尾零，静态还原与四版原 ROM 一致。
未将未知块计作已解析；没有运行编译器或提交。继续剩余 .text/GNU 的共同整理。

## 场景实体连续模块与四个尾部成员（静态批次 EW）

旧 asm/code_entities_08034CEC.s 的主体此前已迁入各功能模块，最后留下的并非未反汇编字节，
而是 4 个完整尾部入口（36/8/20/24 字节）。结合真实类偏移、狗球携带动画中的内联操作、
篮子 GetBox 的同一矩形，以及 MoreItems 的 30 项容量，将它们恢复为 DogBallVisualController::SetAnimation、
DogBallEntity::IsCarried、ShippingBasketEntity::GetBoxAt 和 IsFull。命名表示已恢复的功能，不声称取得了原作者的符号名。

鸡蛋、出货篮、狗球、场景事件效果及这些尾部方法在四版均为连续的场景实体实现。
合并为 src/world_prop_entities.cc 和 include/world_prop_entities.hh，保留每种实际类的身份及布局；
移除 4 套碎片文件和最后的地址命名汇编文件。没有为输出尾部入口添加假调用、虚构新类、
人为 section 或 -fkeep-inline-functions；采用当前项目已有的类实现声明和正常内联成员机制。

四版普通 .text 的这 5 个对象选择器收为 1 个；相邻的 8 个 GNU 代码选择模式和 4 个虚表选择模式，
分别收为该真实模块的整体自然 GNU 输入。原 25 个显式汇编实现按顺序逐项一致，未加副本或改动指令。
4 个小方法改写为 C++，其 88 字节不能计作已通过匹配的高级语言成果。

| 版本 | 连续主实现（终点不含） | 四个尾部入口（终点不含） |
| --- | --- | --- |
| JP | 08037A58–08038EC8 | 08038E70–08038EC8 |
| US | 08037CC4–08039134 | 080390DC–08039134 |
| EU | 08037CD8–08039148 | 080390F0–08039148 |
| DE | 08037BD8–08039048 | 08038FF0–08039048 |

尾部四版除两个 BL 位移外逐字节一致；调用目标分别是资源句柄解析和 MoreItems::GetSize。
原 ROM 的逐字节绝对地址扫描，以及保存 ELF 的所有可执行区间中 ARM/Thumb BL 检查，均未发现
进入这 88 字节的外部直接引用。未把这个静态结论当作任意扩缩或运行验证的证明。

本批未调用编译器、汇编器、链接器，未提交或推送。四个成员的实际生成、析构及虚表自然顺序，
与上一批预处理器/编译器补丁一起进入统一四版验证。其余硬件普通 .text 和 GNU 组织仍未完成。

## 编译器保留数组身份，撤销字符串猜测修补（静态批次 EV）

已通读 fomt_preproc 的实际处理路径。bad_alloc 原本仅出现于自测，但结构解析限制 g 前缀、按同内容推断表达式目标、补造未输出数组及首部匿名字符串去重，仍包含会受源码增改影响的假设。本批整体移除这条修补链及旧测试，不将其换成另一套变量名或地址规则。

固定 cp 基准的 decl_constant_value 会把只读数组声明替换成 STRING_CST，随后数组退化转换取到匿名字面量地址。新增 agbcp-const-array-identity.patch，在 ARM/Thumb 两份前端仅按 ARRAY_TYPE 保留原数组声明；标量折叠不变。接入已有安装脚本；预处理器只保留汇编语法兼容、普通数据段及显式对象/可执行段对齐，不再选择或改写文本指针。

补丁已对固定基准源码通过 git apply --check。新增的单一跨翻译单元回归涵盖同内容独立数组、空文本、内嵌零、直接指针、数组/结构表、返回值、偏移及引用；尚未执行。工具源码从 2113 行缩至 861 行。本批未重装或编译工具链，未运行自测、四版构建，未提交推送；统一验证前必须先安装带此补丁的编译器。

## 相邻模块前缀与 GNU 尾段联合整理（静态批次 EU）

按同一模块联合核对普通代码、GNU 生成函数、虚表及库字面量。时钟状态、世界地图、日历和命名界面的晚段生成函数与虚表，改由所属对象收集；较早的场景转换入口保持原先物理位置。已有四版对象的 GNU 段仍由相同位置首次接收，普通 `.text/.rodata/.data/.bss` 顺序和函数体未改。新编译输出、弱符号副本选择及成员顺序仍待统一验证。

17 处先前归在上一模块末尾的手工 `bad_alloc` 定义及声明已移除，改由紧接模块已有的真实 `<new>` 依赖产生前缀。四版各槽均为十字节字符串加两字节对齐，未新增 include、调用、类型或手工 section。源文件只有定义与声明引用；原 ROM 的六处同值字节已按完整 PCM 采样或字体位图核实为非指针。自然前缀及后续符号地址尚待统一编译确认。

本批仍属静态修改，不计为构建匹配或全 ROM 动态化完成；硬件交错条目、其他逐函数 GNU 清单和未知库副本继续保留在同一待办。未编译、提交或推送。

## 普通代码与 GNU 生成内容联合归属（静态批次 ET）

脚本引擎、指南场景、事件状态、精灵工作目标和 VCount 五个模块按同一物理区间核对普通代码、生成函数与相关虚表。
五组晚段函数改由所属对象正常收集 `.gnu.linkonce.t.*`，其中三个有虚表的模块同时改用所属对象的 `.gnu.linkonce.d.*`。
这不是将自定义 `.text.*` 改名藏入 GNU：本轮没有新增任何 section 属性或编译选项，普通 `.text/.rodata/.data/.bss` 条目及相对顺序保持不变。
脚本查找与指南二分查找的真实 C++ 调用、事件的 const/非 const 查找实例和 VCount 实际析构顺序已核对；模板与隐式成员的实际输出仍需统一编译确认。

GNU 清理仍未全部完成，不能仅以硬件剩余三条自定义 `.text` 衡量剩余工作。其他逐函数 GNU 条目、跨对象副本选择及硬件重复入口继续在同一流程中处理。
`Error` 的脚本错误返回与 `N/A `/JP“なし”区域占位文本不能仅因邻接 `bad_alloc` 归为运行库；修正了相应过度断言的注释，独立字面量及原始排列未删除或合并。
本批只做静态整理，没有运行编译器、汇编器、链接器，没有提交或推送。

## 存档复制内联归属与运行库前缀（静态批次 ES）

静态批次 ES：四版人工 text 子项 9 → 3；账户与 Dog 的普通 text 各只列一次，
两个真实复制入口交由正常内联输出。保留原函数体，未增加高级语言化字节计数。
剩余三项仍为硬件晚段六个入口，未通过伪造覆盖或通配收集掩盖。

本批新增两处/版运行库前缀候选，累计六处/版回到真实已有的库依赖路径。
同时修正预处理器跨越普通数组/定长文本误删同内容库前缀的条件。
独立尾部副本、ScrollMenu 无库依赖的当前原生实现，以及其他运行库来源仍待完善。

这是静态组织进展，未进行编译、汇编或链接，未宣称 ROM 已匹配或可任意扩缩。
继续完成整批静态工作后统一使用 WSL -j4 验证四版，再按主题提交；不推送。

## 当前源码复核、池对齐与 UI 库前缀（静态批次 ER）

本批修改四个现有源码/头文件：八处 JP 常量池填充改为真实对齐，ui_state
首部库字符串交回现有库定义；不增加人工 section、虚假调用、类型或保留属性。
自然库前缀候选累计处理四处/版，独立副本未合并。

当前 4695 个旧入口名称的来源复核完成，60 个额外候选均找到对应来源；实际生成
仍待统一构建。该结果不代表全 ROM 已完整动态化，也不增加已验证字节匹配比例。

人工 text 子项仍为 9 项/版：账户三项、Dog 三项、硬件晚段三项。复制对象的真实
生命周期、硬件重复入口归属及运行库补正还未解决；没有用通配符或 GNU 改名隐藏。
维持先完成静态批次、后统一 WSL -j4 四版验证的流程。未提交、未推送。

## 运行库前缀与账户析构归属（静态批次 EQ）

本批静态修改移除每版三处手工 bad_alloc 首部副本，保留由真实库依赖
正常生成的路径；删除相关声明。独立尾部副本及旧通用预处理补正仍未全部
恢复，不宣称运行库字面量已经清理完毕。

账户析构改为类内定义，由真实存档析构依赖生成；四版人工 text 子项从 10
减为 9。余下为账户三项、Dog 三项和硬件晚段三项。普通 text/rodata 对象数
不变；自然 GNU 选择增加一项，与被删除的人工析构选择对应。

本批为静态候选修改，尤其内联决定和自然字面量顺序须待统一构建确认。
不增加已验证动态重编译、字节匹配或高级语言反编译进度。未提交、未推送。

## 世界虚接口与自然虚表归属（静态批次 EP）

本批完成四张世界相关虚表的来源与接口静态整理：每版 908 字节、17 处
既有入向重定位；60 个已恢复的实现归为真实成员，19 个占位方法补齐参数或
返回类型。移除 vtables.cc，以及 game_object.cc 中手工列举的纯虚表和析构
汇编副本，改由原有真实类型定义生成。未把接口归属整理算作新增高级语言
反编译或字节匹配。

人工 text 子项仍为每版 10 项（账户四、Dog 三、硬件晚段三），尚未解决。
GNU 选择模式现为 JP 309、其余各 307；本批增加的三种选择对应被移除的
手写表，是恢复自然类型输出，不是新增人工函数子段。普通 rodata 选择为
每版 102 项。其余自然 GNU 家族仍需按实际生成顺序统一核对。

剩余实质性静态待办集中为：存档/事件复制与真实内联依赖、三项硬件晚段
归属、四个实体辅助入口的最终归属、132 字节 SRAM 尾部含义，以及运行库
字面量和通用数据预处理的必要性。此前各批次已补全的类与布局转入最终
编译验收清单，避免继续以陈旧占位记录重复处理。

未编译、未提交、未推送；目标继续进行。

## 音频归并与账户排段整理（静态批次 EO）

本批静态归并硬件音频的三段连续实现（每版 824 字节），移除两个零散源码及
两个冗余头文件。账户历史更新恢复共享 C++ 表达（原函数每版 428 字节），清除
两个人工 text 子段和四处 SECTION 声明；这部分尚未编译匹配，不增加已验证比例。

当前人工 .text 子项为每版 10 项：MoneyAccount 四项、Dog 三项、硬件晚段三项。
普通 text 选择项为 JP 208、其余各 209；GNU 选择模式为 JP 306、其余各 304。
背包四个模板实例现按真实对象中的一个自然模板族接收。GNU 模式数量不等于
未解析函数数量，仍须分别检查自然生成内容和待处理的手工排段。

本次未完成剩余 asm 的归属工作；存档/事件复制和四个无充分归属证据的实体
辅助入口仍保留。已统一三个原生入口写法，指令与常量池未改动。
未编译、未提交、未推送；整批静态整理和最终验证继续。

## 连续硬件模块与头文件归并（静态批次 EN）

完成两组物理连续硬件源码归并，移除两个零散源码文件和三个冗余头文件。
每版少两个普通 text 输入、两个 GNU 选择模式；人工 text 子项仍为每版 12 项，
集中在存档复制相关的 MoneyAccount/Dog 和硬件晚段独立副本，没有把它们算作已解决。

这次是模块归属、声明和链接组织的静态整理，不增加已匹配高级语言或全 ROM
动态引用的统计。原生存档/事件复制及四个实体辅助入口仍保留，未为清空 asm
目录创建机械碎片。未编译、未提交、未推送。

## 浇水构造及小游戏文本图块缓冲（静态批次 EM）

四版同时移除浇水模块最后的人工 text 子段：每版尚存人工 text 选择器由
13 减至 12，仍集中在 MoneyAccount、Dog 与 HardwareManager/中断保护的
非连续实现。浇水主构造及十二个图块句柄构造已用真实成员表达；计时与结果
缓冲边界同时补入浇水、收获、照顾动物三个模块。未增加新源码模块。

这批没有运行编译器、汇编器、链接器或移址实验；源代码等价性和保留原生
后缀已静态核对，四版 SHA-1、内联决定及自然 GNU 顺序尚待统一构建。
未提交、未推送。EL 中“未知前段/132 字节构造仍未恢复”的状态由本节更新。

## 浇水小游戏的资源成员与清理边界（静态批次 EL）

四版浇水核心的构造与清理共同确认了九个独立归档所有者、十个精灵记录、
两组各 25 个独立绘制参数及十二个独立图块句柄。普通精灵的两个指针拥有分配，
后续四组范围借用归档载荷；25 项集合共享一个资源句柄。清理先逆序释放绘制
参数，再释放句柄，最后依次清理混合器、归档、UI 与硬件基类。

这些真实成员归入 scene_watering_minigame.hh，保持原始偏移及 0x98C 的核心
对象尺寸。原核心析构 688 字节、图块句柄析构 244 字节，改由成员生命周期
自然生成，未添加人为 GNU section、强制使用或伪别名。未知前段、+548 的
8 字节、+778 的 32 字节及其他未分类 RAM 均继续保留 unk，不虚构用途。

晚段原本共 1064 字节，目前仍有 132 字节真实图块句柄构造保留原生实现。
入口及唯一调用同步采用真实类构造的 ABI 符号；其指令逐行不变。主构造中的
四次无写入循环及所有其他原生方法不变，没有为匹配创建空类或额外调用。
因此人工 text 选择器仍是每版 13 项，本项尚不能算作该 section 已清理完毕。

原段顺序保持为核心析构、图块构造、图块析构；两项自然 GNU 输入暂居构造
两侧。后续需要在真实主构造恢复后解决剩余普通段归属，不能用通配吞掉它。
本次确认的是边界和源代码关系，932 字节不能提前计入已匹配 C++ 进度。

当前仅完成静态核对；实际布局、析构内联与生成顺序仍等待整批统一四版构建。
未运行编译、汇编、链接或移址实验，未提交或推送。

| 版本 | 原晚段范围（末端不含） |
| --- | --- |
| JP | `0x080E4788–0x080E4BB0` |
| US | `0x080E4FF0–0x080E5418` |
| EU | `0x080E503C–0x080E5464` |
| DE | `0x080E4F54–0x080E537C` |

## VBlank 注册范围的独立功能归属（静态批次 EK）

晚段的 VBlank 回调、注册构造和完整恢复析构为连续 176 字节，现归入
hardware_vblank_binding.cc/.hh，四版各以一条普通 .text 输入链接。早段管理器
仍负责声音、帧命令和生命周期组合，通过真实绑定类型调用该模块；没有因原
文件名相同而继续将不连续实现用人工 section 绑在一起。绑定的唯一四字节当前
对象指针也移到同一模块，LDS 的 .bss COMMON 输入在原位置同步更换。

原有构造/回调 C++ 函数体、76 字节析构指令、常量池和中断恢复顺序均未改变。
成员类型和尺寸校验随所属类型移动，没有新增类型、别名、手写 GNU section
或强制生成调用。pragma implementation 的所属文件同步改名；自然虚表、内联
副本归属及最终顺序仍须由统一构建验证，不能据静态迁移宣布字节匹配。

教学场景的两项真实多继承析构跳板、两项场景析构分别按自然族收集，四项 GNU
选择器缩为两项。四版既有对象中的成员与顺序完全相同；模式没有纳入 Push、
Transition 或其他函数。未扩张到缺少既有对象顺序证据的其他类族。

四版当前各剩 13 项人工 text 选择器。硬件列表的独立保留副本、MoneyAccount、
Dog 和浇水场景仍待处理。asm 中四个 88 字节实体辅助入口的原始归属，以及事件
状态复制的自然 C++ 输出尚未解决；不为清空目录而虚构模块、调用或别名。

本批未运行编译、汇编、链接、移址实验，未提交或推送。

| 版本 | VBlank 连续范围（末端不含） |
| --- | --- |
| JP | `0x080D7098–0x080D7148` |
| US | `0x080D78E0–0x080D7990` |
| EU | `0x080D792C–0x080D79DC` |
| DE | `0x080D7844–0x080D78F4` |

## 教学场景主循环与按键输入边界（静态批次 EJ）

FarmingTutorialScene::Run 的原生范围为 JP 2144 字节、其余三版各 2164 字节。
已按原调用顺序恢复四个音效槽、脚本装入、世界所有权转移、十二个脚本状态、
淡入淡出、对话按键及逐帧绘制。海外版在退出状态跳过重复 Start 处理，JP
没有该条件；其余状态操作共用实现。保留的教学分派与辅助汇编逐版核对一致。

Push 由实际 C++ 调用方触发内联机制，定义位于调用之后；移除教学模块专用
-ffunction-sections 及人工 .text.Push 子项。四版各剩 14 项人工 text 选择器。
Push 的自然输出和主循环编译字节仍待统一验证，不视为已经匹配。

UiStatePayload 的输入参数仅在覆盖前读取 +4/+8 两个半字，教学调用方构造的是
HardwareInputState。修正 Owner/Payload 声明及真实符号名；六个既有 C++ 调用点
明确传入硬件状态的 input 成员，汇编调用同步改名，没有伪别名或 ABI 参数改位。
原生函数体保持原指令。教学世界使用独立的四字节所有权类型和八字节转移记录，
与工厂及消费者的清空源槽、缓存指针、虚析构相符，不再将其当作普通 GameObject。

尚未运行编译、链接或移址实验。旧编译器内联、共享容器增长、所有权返回 ABI、
自然 GNU 输出顺序和最终四版 ROM 字节均列入整批验证。

## 牧场地图的构造与成员生命周期（静态批次 EI）

场景构造、场景析构以及核心和室内标记容器的生命周期归回 farm_map_screen
对应的 C++ 类型。室内三个独立行成员与四个建筑容器保持已确认的原偏移；
标记列表仅释放有效元素及自有分配，资源归档仍借用原图像资源。

四版构造逻辑对照一致，唯一地区内容差异保留为 JP/海外标记归档符号。
原晚段人工 .text.new_game_birthday_core_cleanup_after 选择器已移除，
改为收集真实类型的自然 GNU 实现；普通 .text 仍只收集一次。剩余汇编
逐版对照修改前保持一致，没有移动数据段或新增辅助源文件。

新游戏菜单两个相邻析构也按原对象内的真实类族收拢；四版基线对象的
成员集合及顺序均已核对，不扩大到另一个对象中的 FreshSaveTransition。

本批仅静态整理。牧场地图大型构造的内联、隐式生命周期的生成顺序、
原室内容器构造保留的 12 字节栈帧和最终 ROM 字节尚待整批编译确认；
不能将本记录视为 SHA-1 已通过。没有加入伪造的成员、手写 GNU 段或强制生成调用。

## 硬件与菜单的自然 GNU 类族归组（静态批次 EH）

四版中硬件管理器的五张主/次基类虚表、声音命令的虚表与析构、链表虚表和
菜单面板虚表，按现有真实类族收集。15 条逐项选择缩为 5 条，保留原有弱符号
选择范围。完整类定义顺序已核对；没有改字段、函数体、普通段位置或增加手写
GNU section。菜单核心与选择核心依赖仍单独保留，未强行并入面板类族。

新模式逐项对照四版基线对象的段名，未匹配到额外成员。实际自然输出顺序及弱
副本选择仍待统一构建，不据此宣称普通人工 text 子项已清零。

地形属性区补充引用核查：四版每版 260 项实际目录重定位已确认。其余数值命中
已逐项归为指令重叠、对齐与整数重叠、PCM 样本、归档索引/OAM/图块/色板、字体
索引、现有资源工具生成的图像载荷及 Mary 脚本范围。无未归属数值命中；其中
Mary 范围仅记录归属，不等同于证明脚本内部的动态引用。没有将图像或指令的
偶然四字节组合改成虚假指针。普通 CPU 目录引用无需再补写原始地址。

## 地形属性与索引网格归属（静态批次 EG）

原 static_resources 汇编区的 220 个对象已逐项对应实际调用：110 份四字节地形属性
字典及 110 份行优先索引网格，合计每版 138,932 字节。全部按原物理顺序归入
map_terrain.cc，外部声明归入同名头文件；删除原汇编及重复的资源声明头，四版
LDS 只在原位置收集一次 map_terrain.o(.rodata)。没有新增资源目录或编译步骤。

四版源码字节及全部标签边界均与基线 ROM/sym 对照一致，属性字段可无损还原，
网格元素数量逐项对照描述符宽高，尾部 0..3 字节仅由 ALIGN(4) 补足。六份季节
共用网格保留“一方少读取一行”的真实约束；只有 MapDataResource_243 存在 JP
专有网格差异。未擅自给未知属性位命名，改变网格尺寸仍须同步描述符。

已核对每版 260 项目录重定位。全 ROM 数值扫描中其余重叠数值命中另行保留核查，
不把这些数值直接视为指针，也不据此宣称全域入向引用审计完毕。编译输出顺序、
位域布局及最终四版字节尚待本轮统一验证。

## 场景切换目录的自然 GNU 组织（静态批次 EF）

超市与购买场景保留原工厂函数体及成员布局，按实际物理顺序调整完整类的定义顺序；
工厂实现归入对应类内，所调用的既有 ABI 声明提前到使用之前。四版两组创建/析构
函数及虚表改为自然类族收集。小游戏、赛马的切换虚表也按已核对的类顺序归组。

单个切换类型的创建与析构不再各列精确函数名，匹配限于其真实旧 ABI 类名后缀；
保持原有弱符号选择，不添加强制生成或伪别名。LDS 中本批产生的多余空行已清理。
普通代码与数据范围没有移动；自然输出成员、顺序及四版 ROM 字节仍待统一验证。

## 小游戏场景切换的 GNU 连续组（静态批次 EE）

浇水、收获、动物照料和鸡祭四个现有 CreateScene 实现移回对应类内，实际函数体
及所有权传递保持不变；场景类型在对应 new 表达式之前已完整定义。现有类顺序
配合旧编译器的内联输出规则，对应原 ROM 每项“创建场景、析构”的相邻排列。

四版的八个切换函数改为 scene_minigames 的一个自然 GNU 组，四张场景虚表同样
按其已正确的类顺序收集一次。切换目录自身的虚表仍保留原物理位置。
此次没有移动任何普通 `.text`、生成伪别名或修改玩法；最终机器码待统一构建验证。

## 帧命令、地图和日历的 GNU 归属（静态批次 ED）

显示、精灵和 DMA 三个帧命令的现有 Run 实现按旧编译器的实际输出顺序组织，
其类定义顺序仍保持不变。对应函数、析构和虚表明确由 hardware_context 对象收集，
不再依赖全工程任意对象命中各条链接项；其他硬件命令不并入这组。

城镇地图四个既有标记树函数只调整定义顺序，前置声明及函数体保持不变；地图、
料理和日历的晚段函数按真实类族收集。普通代码和数据的物理范围没有跨主题合并。
保存了既有对象段清单；自然输出、弱符号副本选择及四版字节仍待整批完成后验证。

## UI 命令和文字接口的自然顺序（静态批次 EC）

UI 六个实际命令/适配器类按原虚表及析构顺序组织，类内成员、函数体、继承及
链接属性保持不变。上传和 DMA 的两个 Run 实现在各命令类型完整定义之后；DMA
队列在读取它的成员前已有完整定义。UI 基础接口的现有内联顺序不变。

四版九条 UI GNU 函数链接行和八张虚表选择分别合为所属模块的一组自然输出。
脚本文本变量基类仍在自己的原物理范围内先行收集；普通 `.text` 未采用通配合并。
保存的旧对象清单与新源码顺序共同作为统一验证依据，尚不宣称最终字节已匹配。

## 屏幕与教程对象的 GNU 自然顺序（静态批次 EB）

牧场状态页的四个现有 Draw 实现移回各自类内；主菜单数据的构造/析构定义顺序
与旧 agbcp 的内联输出机制对应。赛马与兑换页按各自场景、文本变量、核心的真实
依赖组织，Lookup 放在相应核心定义之后，持有者的 delete 仍在类型完整后定义。
函数体、数据成员顺序、继承及普通 `.text` 均未改变。

连同原顺序已正确的动物角色、教程世界、童年场景和飞盘核心，八组逐函数 GNU
选择改为所属类族；赛马六张虚表合为一个真实类型族。不是把普通代码改名为 GNU，
也不以通配符跳过源码顺序整理。四版原物理组顺序逐项一致。
四份 LDS 同时去除整理遗留的注释与空行，逐字符核对其余链接命令不变。

GNU 的实际生成、重复实例选择及字节匹配仍待统一构建；人工普通 `.text` 子项仍为
16 项，剩余汇编归属问题继续单列，不据此宣称全 ROM 动态化完成。

## 鸡祭核心的资源与调色板拥有关系（静态批次 EA）

根据构造、阶段初始化、渲染和析构四类路径，恢复鸡祭核心的两个独立调色板句柄、
两组调色板句柄数组、九个独立归档拥有者、六组精灵资源布局，以及具有实际 2/5/10
元素计数的句柄和绘制参数数组。资源范围本身借用归档内容，不添加释放行为。

这些成员按真实偏移和声明顺序保存在 `scene_chicken_festival.hh`；未知 RAM 仍保留。
原晚置析构 1040 字节/版改由 C++ 成员析构生成，移除该模块的人工晚置 `.text` 子项。
主程序汇编与普通 rodata 不变。四版人工普通 `.text` 子项由 17 项降至 16 项。

本批未运行编译器，隐式析构的内联选择、字节及 GNU 输出顺序等待统一四版构建；
已确认的成员边界与尚未确认的编译匹配分开记录。

| 版本 | 原版范围（终点不含） |
| --- | --- |
| JP | `080E40D8–080E44E8` |
| US | `080E4940–080E4D50` |
| EU | `080E498C–080E4D9C` |
| DE | `080E48A4–080E4CB4` |

## 动物照料小游戏的成员边界与晚置析构（静态批次 DZ）

依据构造、资源准备、渲染及释放路径，将核心内部恢复为八个独立精灵资源布局、
七组各含五个元素的拥有者数组、三组借用资源范围、八个归档拥有者及十一个图块句柄。
其中 `+0x6E0` 是绘制参数数组，`+0x6F4` 才是资源句柄数组；不以相邻地址猜测相同类型。
`+0x7BC` 保留已确认的初始化/释放布局，其具体游戏用途尚不明确，不进一步命名。

原晚置核心析构 764 字节、图块句柄析构 224 字节由实际成员的 C++ 析构关系表达，
移除 `.text.world_sprite_effect_frames_after`；保留真正由编译器产生的 GNU 析构段。
同一核心与场景的两个虚表依照真实类型顺序合为一个 GNU 类型族条目。
主汇编代码、区域差异及普通 rodata 未改动。人工普通 `.text` 子项由每版 18 项降至 17 项。

此批仅完成静态实现，尚未编译；对象布局、析构内联及 GNU 输出顺序、原版字节匹配
仍须统一四版构建确认，不将这 988 字节计入已通过匹配的高级语言进度。

| 版本 | 原版范围（终点不含） |
| --- | --- |
| JP | `080E3CFC–080E40D8` |
| US | `080E4564–080E4940` |
| EU | `080E45B0–080E498C` |
| DE | `080E44C8–080E48A4` |

## 收获小游戏的所有权与晚置析构（静态批次 DY）

收获小游戏从构造、资源准备及释放三条路径确认了八个归档拥有者、七组资源句柄与
绘制参数拥有者，以及九个独立图块句柄。组内四个资源范围借用归档数据，不负责释放。
在同名头文件中表达这些真实成员，保留其顺序、大小及偏移；未知 RAM 继续保留 unk。

原核心析构 484 字节及图块句柄析构 188 字节，共 672 字节/版，改由这些真实成员的
C++ 析构关系生成。移除手写 `.text.world_sprite_effect_frames_after`，由同一对象
接收对应的自然 GNU 析构段；主程序中的原有汇编指令、地区差异、数据和引用不变。
不增加强制生成的调用、别名或编译后重排。普通人工 `.text` 子项由每版 19 项降至 18 项。

这是静态实现，尚未验证生成字节：析构内联选择、输出顺序、寄存器分配及完整 ROM
匹配留待整批统一构建；不能将这 672 字节提前计为已通过匹配的高级语言进度。

| 版本 | 原版范围（终点不含） |
| --- | --- |
| JP | `080E44E8–080E4788` |
| US | `080E4D50–080E4FF0` |
| EU | `080E4D9C–080E503C` |
| DE | `080E4CB4–080E4F54` |

## 连续场景虚表的类型顺序与归属（静态批次 DX）

飞盘与成绩、童年回忆、指南页面、参赛动物选择、镇地图、滚动菜单、世界地图和
教学场景共 25 张真实虚表，按各版原 ROM 的十个连续类组接收。调整场景、核心及
文本变量类型的实际定义顺序；原有成员、继承关系、虚槽和 pragma 归属不变。
前置声明只用于实际指针；拥有者的 delete 实现仍位于核心完整定义之后。

没有改写普通函数体，没有新增 GNU section、别名或强制生成用的调用。
普通人工 `.text` 子项仍有每版 19 项，存档复制和四个实体辅助入口仍待解决。
本批只通过源码顺序、完整类体及四版链接范围的静态检查；尚未编译或验证 ROM 字节。

## 中断表 C 模块与专用 ARM 分派器（静态批次 DW）


原 `asm/interrupt.s` 中的两个普通 Thumb 表项交换入口共 32 字节，恢复为
`src/interrupt_table.c` 的 C 函数；对应的中断回调表与嵌套使能掩码表一起归入
该模块，统一在 `include/interrupt_table.h` 声明。保留原先 16 槽硬件表容量、
字段宽度、声明次序、返回旧值和不额外检查索引的行为。

真正采用 ARM 状态、SPSR/CPSR 与中断寄存器协议的部分保留为
`asm/interrupt_dispatch.s`。它的两段 ARM 指令、常量池、符号引用完全不变。
启动侧的普通中断 API 继续在 `src/interrupt.c`，头文件改用对应的 C `.h`。
四份 LDS 各自只更换这两个完整所有者的普通 `.text`、`.bss COMMON` 和
`.iwram` 输入，不新增人工 section，也不改变它们的原链接位置。

32 字节是旧基线中的范围，不是新 C 输出已经匹配的声明；寄存器选择、COMMON
顺序与完整 ROM 字节等待统一编译。本批仍未编译、提交或推送。

## 启动与窗口类的剩余虚表归组（静态批次 DV）


启动画面、姓名输入、文本窗口和 VCount 绑定共十张真实虚表，分别按四个连续类族
接收。窗口对象与场景对象通过真实指针前置声明安排类型顺序，完整类成员、虚槽、
构造参数及布局不变；窗口的两个内嵌命令仍在窗口本体前完整定义。

文本窗口的三段弱函数与 VCount 的两段弱析构改为两个类族输入。VCount 上下文
恢复析构保持同一函数体，只在类外定义，使自然输出顺序与原 ROM 顺序一致。
独立压缩解码器已确认内部使用自定义寄存器调用协议，继续保留命名汇编文件。
普通存档复制与四个实体辅助入口的最终归属仍未完成，不因文件已读而计为已迁移。

本批未运行编译器、汇编器或链接器。普通人工 `.text` 子项仍有每版 19 项；
新组织的 GNU 生成顺序与 ROM 字节匹配仍待整批统一验证。

## UI 与联机内联函数的自然输出顺序（静态批次 DU）


UI 基础接口的 11 个内联成员与 JoyBus 协议的 18 个内联成员，保留原函数体，
按旧 agbcp `finish_function` / `saved_inlines` 的逆序输出规则组织定义。
两段 UI 基础接口、联机 thunk/协议成员和记录页面析构的 50 条逐函数选择器，
改为六条真实类族选择模式；不把普通 `.text` 改名成 GNU 段。

GameCube 场景通过现有的核心指针持有者提前声明，核心完整定义仍先于持有者的
`delete` 实现。六张真实虚表按类声明顺序自然生成，在 LDS 中按所属对象收集一次。
多重继承的两个核心虚表和调整 thunk 继续由真实 C++ 继承产生。

这一步只完成源码/链接组织的静态整理；内联选择、最终自然输出顺序和完整字节
仍待四版统一编译验证。每版普通人工 `.text` 子项仍有 19 项，未计作已经清完。

## 实体类族与原生字声明整理（静态批次 DT）


动物、精灵、事件特效、狗球、篮子、鸡蛋、野狗和玩家的 30 张真实虚表，
按九个实际连续组接收。狗球/篮子/鸡蛋的控制器通过实体前置声明提前定义，
野狗本体放在各行为子类前，教学玩家放在两种显示控制器后；完整类体保持不变。
类声明次序与旧编译器的逆序虚表遍历相配，不手工重建虚表。

玩家两组虚表之间确有普通只读数据，保留这个物理断点；未将它们跨过数据合并。
五个玩家隐式析构入口按同一真实类族收集。事件复制、JoyBus 和 M4A 剩余的
`.4byte` 统一为 `.word`，字值、指针表达式、指令和常量池边界均不变。

存档复制的类型限制继续保留：原调用包含 Dog 的赋值操作，物品/事件列表只复制
有效条目且保留未使用存储。不能用普通整对象复制或伪造构造调用代替。
事件复制与四个实体辅助入口的最终源码归属尚未完成；本批不将这些算作已解决。
普通人工 `.text` 子项仍是每版 19 项。所有自然 GNU 输出与字节匹配待统一验证。

## 商店与菜单的自然虚表组织（静态批次 DS）


十七组商店/菜单（含烹饪、日历）把场景声明放到核心类之前，核心类的字段、
函数声明和场景本体保持不变。既有 CoreOwner 只提前指针声明；其 `delete value`
实现仍放在完整核心类型之后，保留真实析构调用，未创建新的所有权包装。
烹饪和日历的实际文本变量类也保持在核心成员定义前。

四版逐组核对原清单中的物理连续性，36 个逐类型虚表项归入 17 条所属模块选择式，
前方的真实 Transition 虚表保留原顺序。角色模块的四张虚表和三条隐式析构入口
也分别按该真实模块收集，前方已经接收的基类/接口 COMDAT 不重复输出。
此处仅收集编译器自然产生的 GNU 内容，不恢复人工子 section 或改变普通数据布局。

本批没有新增 ROM 解析覆盖；虚表、隐式函数和内联析构的实际顺序仍待统一编译。

## 角色与显示实现的连续模块（静态批次 DR）


四版相同的连续角色范围，现在由 `src/entity_actor.cc` 和 `include/entity_actor.hh`
管理：角色运动/动画、精灵控制器、默认控制器、脚本显示实体和渲染位置判定。
原来十条普通 `.text` 条目缩为一条，删除 `entity_sprite`、`script_visual_actor`
两套碎片源码/头文件；`entity_ui` 的独立只读数据仍原位保留，没有混进角色模块。
基础 `EntityVisualController` 接口回到 `entity.hh`，供非角色实体同样使用。

两段完整原生汇编保持所有指令、常量池、局部标签和引用不变。76 字节的九个
角色字段访问入口改为对应的真实内联成员；当前源码没有调用其旧自由函数标签。
旧编译器的接口实现机制负责输出成员，没有伪调用、别名或手工 GNU 段。
渲染位置判定的输入已由马/玩家 Draw 调用确认；返回值的视觉含义仍未确认，
保留未知函数名。既有四版内联范围边界独立核对，未改变相关数据布局。

这是静态源码/链接组织修改。普通方法、内联尾部、隐式析构/虚表的实际生成顺序，
以及九个恢复成员的机器码，均留待全局批次结束后统一验证；不计为已匹配进度。

## 六组场景与核心虚表归并（静态批次 DQ）


生日输入、农场地图、工作人员、鸡祭、收获小游戏和浇水小游戏的 Scene 声明，
已通过真实 Core 前置声明移到其核心类之前。Scene/Core 的完整类体、字段顺序、
函数声明和方法实现均不变；原有指针/SmartPtr 成员不需要提前定义 Core。

四版原清单中每组 Core/Scene 虚表均相邻，沿用已记录的边界和所属关系。现在六个
对象分别使用一条实际类族 GNU 选择式，取代十二个逐类型选择项；真实 Transition
虚表继续在前方工厂区域接收。源文件没有增加 section、伪别名或用于强制输出的调用。
声明顺序使旧编译器的逆序虚表遍历对应原 ROM 的 Core、Scene 次序。

本批不增加代码、资源或引用解析覆盖。实际隐式成员生成和四版 ROM 字节匹配仍待
统一编译，人工 .text 选择项仍为每版 25，剩余原生汇编归属继续处理。

## GNU 虚表输入的重复对齐清理（静态批次 DP）

重复虚表对齐移除数量：JP 115 条、US 116 条、EU 116 条、DE 116 条。

既有四版对象中，JP 的 175 个、海外各版的 176 个实际编译器虚表输入段，全部自带
至少四字节的节对齐；旧 agbcp 的 build_vtable 也为虚表设置真实类型对齐。因此删除
LDS 在这些真实 GNU 虚表输入前重复写出的 `. = ALIGN(4)`，由输入段自身对齐生效。
各输入及选择顺序不变，普通数据、RAM/输出段和有独立用途的对齐保留。同步删去
同一输出段输入清单内部的空行；不增添逐项注释。

本批只清理冗余链接控制，不增加动态引用或高级语言恢复进度，不宣称剩余 GNU/人工
子段已全部解决。未启动编译；输入段实际对齐仍随最终四版统一验证检查。

## 状态页、记录页与超市虚表的自然组织（静态批次 DO）

| 连续虚表范围（末址不含） | JP | US | EU | DE |
| --- | --- | --- | --- | --- |
| 牧场状态：10 张 | `080E6E38–080E6ED8` | `080E7A08–080E7AA8` | `080E7A54–080E7AF4` | `080E796C–080E7A0C` |
| 记录：6 张 | `080E6F2C–080E6F8C` | `080E7AFC–080E7B5C` | `080E7B48–080E7BA8` | `080E7A60–080E7AC0` |
| 超市：4 张 | `080E7038–080E7070` | `080E7C08–080E7C40` | `080E7C54–080E7C8C` | `080E7B6C–080E7BA4` |


三套模块把拥有者 Scene 声明放到其 Core/页面声明前，使用实际指针成员所允许的
前置声明解决依赖；类内每个字段和方法声明原样保留。完整类型的逆声明顺序与原 ROM
的 20 张虚表顺序对应，不添加人工 GNU section、虚表数组、别名或额外调用。

四版沿用原生对象及此前分类记录核实表长和连续性，共 312 字节。LDS 由 20 个
逐类型 GNU 名字改为三条限定所属对象和真实类型族的选择式；相关 Transition 虚表
仍在更前方的原工厂区被接收，不会被后续类型族重复纳入。普通 .text 未改为通配。

本批属于真实 C++ 类型及链接组织整理，不增加代码或引用解析字节。四版编译器实际
虚表发射顺序、隐式成员和完整 ROM 匹配仍待最后统一构建。普通 .text 人工项仍为 25。

## 普通 C 数据段与农事教学入口归属（静态批次 DN）

| 教学入口连续范围（末址不含） | JP | US | EU | DE |
| --- | --- | --- | --- | --- |
| 324 字节 | `0803B490–0803B5D4` | `0803B6FC–0803B840` | `0803B710–0803B854` | `0803B610–0803B754` |


普通 C 通道移除 -fdata-sections，沿用本地 pokeemerald 的普通对象组织。
这同时消除新归位的 gRandomSeed 被生成到 .data.gRandomSeed、而 LDS 只选择
.data 的不一致。SRAM 库不再需要单独排除此标志；其 -O1 保留。m4a 的 16 个
现有只读对象已逐版核对：从四字节边界开始，源码顺序与逐对象自然对齐得到的地址
完全对应既有 ELF。显式 EWRAM/BSS 存储、符号引用及普通 C 函数体不改。

FarmingTutorialTransition 的 28 字节构造和 296 字节工厂，四版均构成独立连续段，
现在由 farming_tutorial_transition.cc/.hh 管理，保持真实类及 C++ 方法体不变。
GameScene 直接包含它实际使用的入口头文件；教学脚本主体留在 farming_tutorial。
四版早段两条逐函数选择改为一次普通 .text，真实析构和虚表转由入口对象提供。
该模块晚段 Push 与原生脚本主体的分段尚未解决，不伪造内联引用来强行合并。

C++ 通道暂仍保留 -fdata-sections 及预处理器的同名 unique .rodata：它们仍需核对
未对齐主题起点和后续对象对齐，不能把 LDS 只有一行认定为对象内部已经合并。
本批无编译、汇编、链接或移址实验；实际自然段和编译器隐式成员顺序待统一验证。
普通 .text 人工选择项从每版 27 减为 25，不增加高级语言或动态引用覆盖。

## 环境精灵类族的自然 GNU 输出组织（静态批次 DM）

| 范围（末址不含） | JP | US | EU | DE |
| --- | --- | --- | --- | --- |
| 54 个内联成员 | `080DC700–080DD9D4` | `080DCF4C–080DE220` | `080DCF98–080DE26C` | `080DCEB0–080DE184` |
| 15 张虚表 | `080E69A8–080E6B28` | `080E7568–080E76E8` | `080E75B4–080E7734` | `080E74CC–080E764C` |


world_ambient_sprites 中控制器持有精灵、Entity 持有控制器的真实关系不变。
控制器声明移到精灵类型之前，只通过前置声明解决指针依赖；其构造函数定义放到
Entity 完整声明后，初始化内容不变。完整类的逆声明顺序与原 ROM 的 Entity、
Kind12 至 Kind1、Sprite 基类、Controller 虚表顺序一致。

四版 54 个内联成员和 15 张虚表的原始范围均连续，沿用已有三份完整引用审计。
LDS 的 69 个逐符号 GNU 选择项收为该对象的两条真实 WorldAmbient 类族选择式；
普通 .text 不改成通配，不新增人为 GNU section、别名或强制输出调用。
现有 C++ 方法实现保持不变。这是链接组织准备，不新增 C++ 或引用解析覆盖；
实际编译器的内联输出顺序、隐式依赖及完整 ROM 匹配仍待统一验证。

## 农场地图及四个小游戏的生命周期汇编归属（静态批次 DL）


旧 asm/code_linkonce.s 最后两组共 3988 字节、11 个完整函数已回到五个实际
模块的 .cc，常量池、局部跳转和原有顺序一起迁移；四版共用已核对相同的指令。
JP 浇水图块句柄初始化器后原本只标局部标签的析构入口，已明确为独立函数。
动物照料 11 个、浇水 12 个句柄的初始化/释放使用实际功能名；浇水 +0x83C
的 12 项成员布局已补出，仍按原析构 ABI 保留 flags，不伪装为普通 free。

这次只完成完整边界和归属，不计入高级语言恢复或新增全 ROM 引用覆盖。
晚段与各自普通主代码仍物理分离，沿用已有两个临时子段名，不伪造 linkonce。
一个混合小游戏输入改为四个所属对象，人工 .text 选择项暂由 24 增为 27；
它们仍明确列为未完成，须在真实内联/生命周期组织恢复后移除。
未运行编译、汇编、链接或移址实验，实际生成及完整 ROM 匹配待统一验证。

## NPC 自然 GNU 析构与虚表按类族收集（静态批次 DK）

npc_entity 的 35 个真实派生类型和 roaming_npc_actor 的四个真实派生类型，已有完整
类声明、普通方法和隐式析构关系。头文件类声明的逆序分别对应原 ROM 的析构及虚表顺序；
四版逐项核对连续边界：NPC 析构 420 字节、含基类的虚表 2304 字节，巡游 NPC 析构
48 字节、含基类的虚表 340 字节。沿用此前已经完成的入口/虚表引用审计，没有新造类型。

LDS 删除两组逐类析构、两组逐类虚表的 80 个名字，按对应对象的实际类族使用五个 GNU
选择式收集。普通 .text 和其他模板仍独立按原位置组织，不收集宽泛的 .text.*，也不
把其他模块的模板或虚表提前纳入。源代码不增加任何 section 属性、别名或生成工具。

这是自然 C++ 产物的链接组织整理，不增加函数/数据解析字节，也不等于整个 GNU 区域
已经完成。真实编译器发射次序和完整字节匹配仍在最后的统一验证中检查。

## 地图资源树哨兵构造归属（静态批次 DJ）

SavedMapTree 的四版构造均为 60 字节，只有 malloc 与 RetryMemoryAllocation 两个 BL。
逐版保存对象去除这两处重定位字段后，全部指令字节相同。构造先清空 header，申请一个
24 字节真实节点，设置计数/未知状态为零，清除节点颜色和 parent，并令左右子树指向哨兵。
next_tile_index、next_palette_index、state.unk_00 和哨兵 entry 均保持未初始化。

该行为已写回 saved_map_tree.hh 的真实类构造，继续由 world_map.cc 中既有的
GameSceneSavedMap 成员初始化调用。删除 code_linkonce.s 内两套地区汇编及四版 LDS 的
after_* 人为子段；链接位置改为该真实内联构造的自然 GNU 实例。未增加伪类型、调用或
源码 GNU section。普通 .text 人为选择项每版从 25 降为 24。

构造语义和既有输入已核对；自然输出、原生八字节栈帧以及完整字节匹配尚待最终统一构建。
不将本项计为已验证的高级语言恢复，也不把剩余 GNU 排列认定为完成。

## VBlank 原生析构与随机数运行库归位（静态批次 DI）

HardwareManagerVBlankBinding 的完整 76 字节原生析构及三个池引用移回
hardware_manager.cc，紧接实际构造函数。移除 asm/hardware_manager.s 和四版
LDS 的对应独立输入；沿用已有的绑定段，未增加子 section。该模块其余不连续普通
方法和既有细分段仍待后续整理，不能据此报告已完成常规链接组织。

rand/srand 的 40 字节完整原生实现及共享常量池归入 libc_random.c；gRandomSeed
以同文件的普通 u32 初始化对象定义，声明归入 libc_random.h。位于 ROM 较前位置的
游戏缩放函数 RandomBelow 仍属于 random.c，其头文件引用库接口。两者被其他功能
隔开，不强行合成一个跨位置反复链接的普通 .text。

BIOS SVC 包装保留必要的独立汇编，code_lib_syscall.s 改名 gbasvc.s，对应已有
gbasvc.h 接口；六个入口、48 字节内容及顺序不变。移除两个已空原生实现文件。
本批为所属模块整理，不增加高级语言恢复字节；四版最终输出仍待统一构建。

## 商店扫描线处理与 VCount 绑定归位（静态批次 DH）

商店 BG2 扫描线处理 UpdateUiVCount 四版均为 124 字节，与商店主体末尾直接相接。
其现有 C++ 实现及内联比较行设置函数移入 shop_common.cc，声明归入 shop_common.hh，
由已有一次 src/shop_common.o(.text) 连续承载。源函数体未改。

后部 VCount 中断入口、绑定构造、绑定析构连续为 20+76+76 字节，改为一次
src/ui_vcount.o(.text)，移除该对象的 -ffunction-sections。原来真正写在类内的
ContextScope/ContextRegistration 两个虚析构保留真实类关系，恢复自然 inline/weak
归属；不手写 GNU section，也不新增假类型或强制调用。

四版各清掉六个逐函数 .text 选择项：全局普通 .text 的自定义选择项从 31 降至 25，
同段重复普通对象从 9 降至 8。这里不把两项实际 GNU 析构的生成和物理摆放视为已验证；
自然输出、虚表及最终顺序仍待全局统一构建。JP 析构前无额外模块，海外三版夹着
856 字节商店资源槽实现，原有区别保持。

## IWRAM 普通 BSS 的真实对象与自然顺序（静态批次 DG）

四版普通 BSS 均覆盖 `0x03000000–0x03000490`。SoundMainRam 仍为硬件
IWRAM 起点的 0x400 字节音频工作区；其后的 SRAM 状态、对象池、场景控制器、
硬件/UI 绑定、堆、JoyBus 和中断表改为十个常规对象输入，移除十处数值定位。

原 `gUnk_0300040C = .` 并非填充：两个场景控制器构造函数保存 this，析构清空，
各访问函数读取其成员。现由 game_scene_controller.cc 定义真实的
`GameSceneScriptController * gCurrentGameSceneScriptController`，头文件同名声明，
全部汇编池和 C++ 使用点直接引用该符号；没有保留地址别名。

保存的四版 ELF/对象证明：SRAM 三字节后的间隙来自后续四字节指针对齐；JoyBus
末尾至中断表的十二字节间隙来自原 COMMON 的十六字节对齐。按实际大小和对齐
顺序排列，全部十三个对象的地址和后续 .iwram 起点仍为原值，无需填充数组。
该结论为静态布局核对，实际输出仍待全局统一编译。

## 音频 EWRAM 的统一输入段（静态批次 DF）

四版音频状态对象均为 EWRAM `0x02000000–0x02001F10`（终点不含），共 7952 字节。
原先十四个逐变量输入段改为一个 `src/m4a.o(ewram_data)`；声明按实际内存顺序
集中在 m4a.c，五个 MusicPlayer 定义从配置头移回该源码，外部声明统一归入 m4a.h。
顺序为五组 track、SoundInfo、跳转表、CGB 通道、播放器 A/B/C/E、MemAccArea、播放器 D。

使用本地 pokeemerald 的 EWRAM_DATA/ewram_data 约定，表达真实硬件内存归属。
EWRAM 与 IWRAM 的输出映射保持；SoundMainRam 仍为 IWRAM 中 0x400 字节的独立 .bss。
不是把普通对象人为改名为新细分 section，也不新增固定地址或填充。

保存对象文件的十四个大小、对齐与全零初始化逐版核对，按上述顺序计算出的每个符号
地址均与基线一致。实际编译输出待全局验证；本批不增加 ROM 函数解析字节或宣称所有
RAM 引用已重新审计。四版 LDS 各减少十三行逐变量链接安排。

## 连续 DMA 操作与描述符合并（静态批次 DE）

JP `0x08008E30–0x08009134`，US `0x08008E28–0x0800912C`，EU `0x08008E3C–0x08009140`，DE `0x08008E48–0x0800914C`（终点不含）。

即时 DMA 的三个入口与紧随的六个描述符函数属于同一传输功能；四版两对象直接
相接，共 772 字节，基线没有相互隔开的 rodata/data/bss 输入。统一到
src/hardware_dma.cc + include/hardware_dma.hh，按原顺序保留全部函数体。
移除 hardware_dma_descriptor.cc/.hh 和旧 hardware_dma.c，调用方改用统一头文件；
四版 LDS 仅保留一次 src/hardware_dma.o(.text)。

模块保留两个真实 C++ 构造函数，七个普通接口继续使用原有 C linkage 声明。
ROM 后部的四字节 MMIO 写入叶函数仍在独立底层汇编，不跨越其他功能强行搬到前部。
没有改动函数签名、数据布局、指针或调用行为；三段原 C 实现改走 C++ 编译通道，
其精确输出待统一构建，不能将源码合并当作已验证的字节匹配或新增解析字节。

## 记录页面的真实成员生命周期与 LDS 排版（静态批次 DD）

JP `0x080E1898–0x080E1910`，US `0x080E20F8–0x080E2170`，EU `0x080E2144–0x080E21BC`，DE `0x080E205C–0x080E20D4`（终点不含）。

三种派生记录页面的析构仅转调 RecordsScreenPage；RecordsScreenCore 的析构先
遍历活动页面条目，再清理 ScrollMenu 的页面、资源对象及 HardwareContext 基类。
恢复同名头文件内的 RecordsScreenPageList，保留十项实际容量及原有计数/数组偏移，
不把未启用的容量当作活动对象。四个析构由真实类成员生命周期承担，原生重复体移除。

四版各 120 字节、四个虚表指针已与保存的原实现及引用证据静态对照；没有直接 BL 或
内部入口。隐式析构的生成、内联和精确字节仍待统一构建，不能计为已经验证的 C++ 恢复。
原混合段剩余 224 字节 FarmMap 生命周期尚未清除，人工 .text 子项计数仍为各 31。

四版 LDS 统一全部输出段的缩进，移除说明性注释、段内零散空行及同一输出段中
重复设置相同值的 FILL；段之间保留分隔。对照本地 pokeemerald 的链接脚本排版。
对象顺序、符号表达式、地址、输出段归属和有效填充值不变。此排版清理不计为
边界或引用动态化；BSS 的音频专用输入项及剩余 GNU linkonce 排列仍需随所属模块核实。

## 资源精灵缓存的连续原生模块归属（静态批次 DC）

JP `0x080E1910–0x080E25D4`，US `0x080E2170–0x080E2E34`，EU `0x080E21BC–0x080E2E80`，DE `0x080E20D4–0x080E2D98`（终点不含）。

四版各 3268 字节、16 个连续原生函数迁入 `resource_sprite_cache.cc/.hh`，
包括红黑树操作、tile/palette 缓存插入与释放、缓存精灵绘制及存储初始化。
各版在原位置只链接一次 `src/resource_sprite_cache.o(.text)`；函数类型和真实引用保留，
共同指令流及原段拼接顺序静态一致。未将迁入 .cc 的汇编计为高级语言恢复。

原混合段仍保留前面的 344 字节类生命周期实现，本批不计为整个子段清除。
四版 .text 自定义选择项仍各 31 个、重复普通对象各 9 个；未编译、提交或推送。

## 四版基线命名入口的来源对照（静态审计 DB）

对照保存的四版 ELF 中 4695 个不同名称的 STT_FUNC 条目与当前源码、迁移记录。
47 个名称解析器未关联的候选已逐项归类：24 个函数内分支、7 个已改名的实际实现、
8 个真实 STL 实例来源，以及 8 个由现有类承担的隐式析构。
这批未发现新的确定漏迁函数；没有改动程序源码或 LDS，也不增加已解析字节数。

这只是旧命名入口的来源对照，不覆盖全部未命名字节缺口。隐式成员、模板实际输出、
精确签名及地区条件仍待后续核验，不能据此认定整 ROM 已能动态编译。
详细口径及证据见 RELOCATION_AUDIT.md 同名条目；未运行编译器。

## 存档地图资源槽树的边界与连续模块归属（静态批次 DA）

JP `0x080E39DC–0x080E3B50`，US `0x080E4244–0x080E43B8`，EU `0x080E4290–0x080E4404`，DE `0x080E41A8–0x080E431C`（终点不含）。

四版两段插入函数统一为 `saved_map_tree.cc/.hh`，保留实际 Thumb 指令，在原始位置仅链接 `src/saved_map_tree.o(.text)`。移除 `.text.after_saved_name_scene_destructor`，JP/海外版旧地址名统一为真实函数名。

节点为 16 字节红黑树链接前缀、4 字节有符号键和 4 字节图形槽：`u16 tile_index`、`u8 palette_index` 与隐式填充。tile 读取方按 32 字节 tile 单位送入 VRAM，palette 读取方按 32 字节 bank 单位写入地图缓冲。缺失键分配四个 tile 与一个 palette；键 13 的固定槽保持原逻辑。树状态的未知字段保留 `unk`。

原有查询、遍历及重置仍位于前部地图模块，使用明确类型和符号；递归释放的既有 inline 实现原样归入容器头文件。构造函数仍保留原生实现，其与析构的物理交错尚未完成，不计为已清理。

入向引用静态核对：JP 0 ABS32 / 3 BL；US 0 ABS32 / 3 BL；EU 0 ABS32 / 3 BL；DE 0 ABS32 / 3 BL。没有未分类窗口或函数内部入口；未编译，不新增高级语言恢复字节计数。

## OBJ 调色板池存储初始化的普通对象归属（静态批次 CZ）

JP `0x080D6550–0x080D6570`，US `0x080D6D98–0x080D6DB8`，EU `0x080D6DE4–0x080D6E04`，DE `0x080D6CFC–0x080D6D1C`（终点不含）。

与既有 OBJ tile/调色板集合的存储模块采用同一组织：`obj_palette_pool_storage.cc/.hh` 管理四字节池条目、池状态及后置 free-list 初始化；前部 `obj_palette_pool.cc` 继续管理池的所有者、预留和句柄操作。只是按实际物理范围归属，C++ 函数体、类型和所有符号均未改写。

四版移除 `.text.obj_palette_free_list` 属性与 LDS 子项，原位置只链接 `src/obj_palette_pool_storage.o(.text)`。16 个硬件 bank、世代计数和 count>0 的原有前提保留；全局池指针仍归前部模块。

引用静态核对：JP 0 ABS32 / 1 BL；US 0 ABS32 / 1 BL；EU 0 ABS32 / 1 BL；DE 0 ABS32 / 1 BL。没有未分类窗口或函数内部入口。未编译，不新增 C/C++ 恢复字节计数。证据：`palette-storage-owner-plan/reference-audit/static-review/applied.json`。

## 商店临时资源槽索引的连续模块归属（静态批次 CY）

US `0x080E54C4–0x080E581C`，EU `0x080E5510–0x080E5868`，DE `0x080E5428–0x080E5780`（终点不含）。

海外三版各 4 个函数、856 字节，归入 `src/shop_resource_slots.cc` / `include/shop_resource_slots.hh`。它们维护商店绘制时的两张临时树：以行的 tile/palette 源指针为键，以九个 OBJ 槽中的位置为值。24 字节节点含既有 16 字节红黑树前缀和 8 字节键值；未解释的两个容器字仍保留 unk。JP 使用原有直接绘制流程。

LDS 将 `.text.after_ui_vcount_binding` 替换为一次 `src/shop_resource_slots.o(.text)`。函数、局部跳转、真实调用和原物理次序保持不变，旧地址函数名替换为实际操作名称；没有新增子 section。

每个海外版本核对 13 个真实 BL，未发现本范围的真实 ABS32 入向指针或内部偏移入口。4 个形似指针的 ROM 窗口由既有资源/字段证据排除，未分类项为 0。本批仅完成原生代码归属、类型与引用静态整理，不计入 C/C++ 实现或编译通过。

证据：`shop-resource-slots-plan.json`、`shop-resource-slots-reference-audit.json`、`shop-resource-slots-static-review.json`。未运行编译器、提交或推送。

## 地址命名入口存活核对与未使用属性清理（接续静态批次）

当前 src/asm/include 中共检出 845 个地址命名入口。初筛四个无定义候选均只在
历史证据注释中出现，没有实际调用；另十八个入口通过已有 asm 名称声明绑定到
hardware_linked_list/hardware_interrupt_guard 的真实 C++ 方法，已逐个核对方法体。
本次筛查仅覆盖地址命名入口，不能代替语义名、旧 C++ 修饰名、生成实体及各区域
条件分支的完整存活审计；教学运行块的漏迁仍说明需要单独完成那一轮核对。

EntityVisualController 的内联构造器已无保留的独立入口；四版基线 ELF、输入段清单
和当前 LDS 均没有其旧人工子段，删除声明中遗留的 section 属性，保留原有构造语义。
本次未运行编译器，也没有改变现有方法的 ABI 名称。

## 补回教学脚本宿主与字节查找的遗漏实现（接续静态批次）

对历史 LDS 清理逐项追溯后发现：当时以“旧 section 已无定义”判断为失效，
没有核实函数实现是否在新模块存活，导致两段真实代码缺失。这不是正常的段合并。
现已从保存的源码和四版 ELF/ROM 补回完整范围：教学脚本派发/Run（JP 9820 字节，
海外各 9840 字节，包含内部入口、跳表、常量池和共享退出路径）归回 farming_tutorial.cc；
52 字节的无符号字节 lower-bound 查找归入 byte_search.c，并更新 NPC 排程和婚期调用。
两处 LDS 都使用普通 .text，没有恢复位置命名的旧子段。

教学模块现有的构造/Push 编译顺序仍未整理完成，不将本次恢复计为该模块的 LDS 清理完成。
恢复内容与保存的源指令及每版 ELF 范围静态核对一致；未运行编译器。
同批删除的 ui_output_base_after 在基线对象中也不存在，不能与这两处缺失混为一类。
后续全局审计必须独立核对基线函数/数据的存活与替代关系，不能仅检查 section 名是否存在。

## IWRAM 原生代码与初始化状态的实际归属（接续静态批次）

IWRAM 两个人工子段已移除；七个原生函数及三个初始化状态归回现有模块。
七个原生 ARM/Thumb 入口与三个初始化字共 1624 字节，迁回现有 main、new、
scene_sprite、font、interrupt、random、hardware_blend、allocation_failure 模块。
未新增源码文件。字形、精灵提交、混色与中断保留 IWRAM 执行位置；初始化状态使用
普通 .data，按原位置装入同一 IWRAM 镜像。每个对象在该输出段只列一次。

移除了 after_dimensions/after_sort 两个人工子段和已清空的 code_iwram.s。
既有尺寸表 24 字节及排序代码 472 字节保持在原顺序，完整镜像仍为 2120 字节。
四版保存的 ELF 镜像与各自原 ROM 完全一致；迁移前后原生指令、常量池和三个初值
逐块静态一致。仅整理实际模块归属，未计入 C/C++ 高级语言恢复。
尚未运行编译器，最终输出及引用全覆盖仍以统一验证和全局审计为准。

## 实体视觉更新、字段访问与默认动作的归属（接续静态批次）

实体视觉与属性访问器原生实现已归回所属模块；默认动作子段并入普通 .text。
| 版本 | ABS32 | 入口 BL | 未分类窗口 |
| --- | ---: | ---: | ---: |
| JP | 5 | 7 | 0 |
| US | 5 | 7 | 0 |
| EU | 5 | 7 | 0 |
| DE | 5 | 7 | 0 |

人工 .text 子项 JP 33、海外各 34；内联输出顺序仍待整理，未编译。

## 玩家原生表的模块归属与最后一项手工只读子段（接续静态批次）

普通手工 .rodata 子项已清除；LDS 还保留 Mary 工具输出的两个专用段。
四版各两处 ABS32 均指向玩家表起点，无内部偏移引用或未分类地址窗口。

本批为归属与链接整理，玩家实际类型恢复、世界原生表及全局编译验证仍未完成。

## 野狗实体的完整动物基类与自然虚表（接续静态批次）

野狗手工实体表已由实际类型承接，原生实现保持；未编译、未提交。
复用已完成的整段引用审计：四版各 30 处 ABS32、13 处入口调用，无未分类窗口；本次同步替换所有旧符号并核对原生指令未变。

## 动物实体共享接口与连续代码段（接续静态批次）

动物连续模块 17,832 字节和六张实际虚表完成静态归属；普通 .text 已合并为一项。
四版各核对 211 处 ABS32、196 处入口 BL 和 5 处已有局部 BL；本批目标没有未分类地址窗口。
额外数值窗口逐项验证为权重、天气/坐标/时间记录、食谱数值、字形索引、压缩流或 Mary CODE/STR 的局部数据；未修改脚本或资源。

当前人工子项：text JP 35，US/EU/DE 36；rodata 各版 3（玩家实体一项、Mary 生成段两项）。

## 小精灵工作实体的完整边界、借用数据和自然虚表（接续静态批次）

小精灵工作实体的完整类型、借用成员和自然表已整理；七个原生实现保持。
四版各有 22 处 ABS32 和 7 处入口调用。剩余数值窗口已核实为 7×5 钓鱼权重或压缩图形流，无未分类引用。

人为子项 text JP 43、海外各 44；rodata 四版各 9。未编译或提交。

## 农耕教学世界的真实接口、成员布局和三个自然虚表（接续静态批次）

教程世界/角色/基类三张手工表已由真实类型承接，修正暂停判断的继承归属。
每版确认 97 处 ABS32 引用、3 处入口 BL；待分类地址窗口和内部 BL 均为零。

人为子项 text JP 43、海外各 44；rodata 四版各 10。自然输出待统一构建，未提交。

## 三个精灵小游戏核心的真实继承、部分成员布局和自然虚表（接续静态批次）

三个小游戏核心的接口、已知 RAM 成员和自然虚表归属已整理；原生晚段析构仍待处理。
四版 ABS32 / 入口调用 / 内部 BL：JP 56 / 13 / 4, US 56 / 13 / 4, EU 56 / 13 / 4, DE 56 / 13 / 4；未分类引用为零。

人为子项 text JP 43、海外各 44；rodata 四版各 13。未编译或提交。

## 收获与浇水小游戏 UI 虚表的完整边界和类型归属（接续静态批次）

两张 UI 自然虚表和 JP 收获场景边界已整理，核心表仍待补齐。
四版 ABS32 / 入口调用：JP 8 / 10, US 8 / 10, EU 8 / 10, DE 8 / 10；未分类引用为零。

人为子项 text JP 43、海外各 44；rodata 四版各 16。未编译或提交。

## 菜单 tilemap 与精灵面板的真实类型和资源生命周期（接续静态批次）

两种菜单面板、图标结构和真实所有者已恢复；两张自然虚表与隐式析构等待统一构建。
四版 ABS32 / 入口调用：JP 7 / 93, US 7 / 93, EU 7 / 93, DE 7 / 93；未分类引用为零。

人为子项 text JP 43、海外各 44；rodata 四版各 18。未运行编译器或提交。

## 菜单公共面板的真实存储、命令清理与自然虚表（接续静态批次）

四版各恢复一个 16 字节基类自然虚表；三个方法仍为完整汇编。
四版 ABS32/入口调用：JP 5/6, US 5/6, EU 5/6, DE 5/6；未分类地址窗口为零。

当前人为子项 text JP 44、海外各 45；rodata JP 21、海外各 20。
未编译、提交或推送。

## 农耕教学地图的独立模块、耕地布局和自然虚表（接续静态批次）

四版各 1720 字节教学地图代码已从 game_menu 分回真实模块，恢复 0x1E4 字节
地图/耕地类型。消除一个晚段人为 text 条目和 JP 三个、海外各一个人为 rodata 条目。
当前人为子项：text JP 44、US/EU/DE 各 45；rodata JP 22、其余各 21。
尚未运行编译器；不计为完成 C++ 实现或四版动态构建验证。未提交、推送。

## 农场地图核心、标记容器和自然虚表（接续静态批次）

四版同步恢复农场地图核心、28 字节标记元素和三行室内 ID 列表的真实布局。
每版 16 个原生入口/8664 字节的边界与次序静态不变，核心手工表已删除。
LDS 人为 rodata 子项为 JP 25、US/EU/DE 各 22；text 仍为 45/46/46/46。
晚段三个原生生命周期函数仍待归属整理；自然虚表/ABI 和整体输出待全局
静态批次后的统一构建。本轮未编译、提交、推送。

## 记录界面页面类型、虚表和 JP 独立函数边界（接续静态批次）

四版同步恢复记录界面的五个真实类型及五张自然虚表；JP 补出一个 264 字节
独立函数入口。17 个函数的原生大小、顺序和 64 个指针/72 个入口调用已静态核对。
LDS 人为 rodata 子项：JP 31 → 26，US/EU/DE 各 28 → 23；text 仍为 45/46/46/46。
四个晚段析构的物理归属仍未完成；本轮不计入高级语言实现或已完成动态构建。
完整 ROM/自然虚表输出留待全局批量后的统一编译。未提交、推送。

## 缓存迭代器返回 ABI 的静态修正（接续静态批次）

核对实际工具链后修正 renderer/town_map 的四字节迭代器结果参数，避免
原生调用与普通结构返回的 ABI 错位。原生字节和 LDS 未改，未运行编译或提交。

## 资源精灵缓存的独立函数边界和节点布局（接续静态批次）

补齐四版各 2 个查询函数边界及 JP 2 个缓存插入入口，明确缓存节点、handle 与
源资源指针的区别。17 函数/3968 字节的原生实现与顺序静态不变，164 个调用已核对。
LDS 子项计数不变；晚段模块归属尚未完成。未编译、提交或推送。

## 牧场状态页与动物参赛选择后段归属（接续静态批次）

静态批次CF：四版各移除完整1380字节人工后段及10处人工虚表子项，
恢复真实类型、成员生命周期和直接引用。源码改动已应用，字节验证尚未执行。

| 区域 | 剩余人工 .text 选择项 | 剩余人工 .rodata 选择项 |
| --- | ---: | ---: |
| JP | 45 | 31 |
| US | 46 | 28 |
| EU | 46 | 28 |
| DE | 46 | 28 |

上述计数不包含编译器自然linkonce，也不是整个ROM动态化的完成比例。

## 飞盘、赛马与奖品兑换后段归属（接续静态批次）


静态批次CE：四版各移除完整2040字节的人工后段及七处人工虚表子项，恢复实际
模块/类型和直接引用。普通模块归属不等于高级语言或字节匹配验收：主体保留
原生汇编，新增C++查询和成员析构仍待统一验证。

本轮清理范围包括只出现一次的人工 .text.* / .rodata.*，不以对象重复次数筛选。
Mary生成的两个单独对象仍使用专有rodata段，须同步处理实际生成来源；自然
虚表、模板及linkonce采用编译器机制，不能机械改名或用通配符掩盖未完成部分。

剩余人工选择项（不把自然linkonce算入）：

| 区域 | .text | .rodata |
| --- | ---: | ---: |
| JP | 46 | 41 |
| US | 47 | 38 |
| EU | 47 | 38 |
| DE | 47 | 38 |

上述数量是LDS结构清理计数，不是全ROM动态化比例；尚未编译、提交或推送。

## 联机多继承接口与完整后段归属（接续静态批次）

四版移除整组40入口的人工后段：JP2232字节，US/EU/DE各2240字节；
两张共280字节的联机核心虚表改由真实继承生成。核心构造、小方法、
JoyBus适配、烹饪清理和事件检索已有真实归属，尚未统一编译，不计入
已匹配的高级语言完成字节。未改变其他语言的解析层级或ROM物理顺序要求。

LDS检查同时覆盖重复对象与只出现一次的人工子项；唯一出现不代表完成。
剩余每条普通段子选择器都记录在link-late-owner-remaining-subselectors，
后续需同步去掉源码分段并核对自然输出，不能只改LDS后缀或通配收集。
编译器生成的虚表/模板/调整入口与人工section分别验收。

## 城镇地图标记调用、树与数组的真实归属（接续静态批次）

四版各移除城镇地图1312字节后段的人工 section；恢复添加标记的真实调用方、
四个树操作和容器生命周期。对应原生范围共2044字节/版，新 C++ 尚未编译匹配，
不计入已验收的高级语言字节。130个坐标字段的表示已与原 ROM 静态核对。

人工 .text 子项现为 JP 48、US/EU/DE 各49，.rodata 仍为 JP50、海外各47。
GameCube 接口、其他后段方法、运行库附带内容及剩余全局边界仍需整理；
不编译、不提交、不推送，按既定流程等整个静态批次完成后统一验证。

## 共用红黑树操作与 JP 遗漏入口（接续静态批次）

补齐 JP 两个真实函数入口，统一第三个已存在入口与海外对应名称，明确五个
共用树操作；四版各1216字节原生实现保持静态一致。核对175个入口调用及
78个非指针窗口，没有编译、提交或推送。城镇地图后段归属仍在处理中，
人工 section 数量本轮未减少，不将此次入口修复计为已完成 LDS 收敛。

## 日历后段真实内联归属与人工分段移除（接续静态批次）

四版各移除一个 624 字节后段人工 section，将其中三个日历方法归回实际
类型。查询和析构已有正常 C++ 表达，尚未经过统一编译，不计为已匹配的
高级语言完成量。其他原生输入段静态保持一致；剩余普通模块/资源/运行库
审计仍在继续，没有提交或推送。

## 日历核心完整布局与共有成员入口（接续静态批次）

日历 0x228 字节核心布局、8 个主函数和析构入口完成本轮静态整理，四版
各 5672 字节汇编共用源码，移除一项手工核心虚表。核对 192 处真实引用和
192 个非指针窗口。没有把这些共有汇编计成高级语言完成量。
后段三个日历方法的自然输出与最终归属继续处理，四版构建尚未开始。

## 日历文本变量虚表真实边界与直接引用（接续静态批次）

四版日历的两个相邻虚表恢复为真实 12/16 字节边界，移除 JP 构造中错误的
“相邻表 + 12”引用。恢复 12 字节文本变量对象和两个实际成员入口，每版
移除一条手工虚表 section。12 个真实引用、2 个非指针窗口完成静态核对。
384 字节方法仍计汇编；新增高级语言函数字节为 0。

核心完整布局、后段原生方法最终归属与自然虚表输出继续保留为未验收项。
统一四版编译尚未开始，不能将本项静态完成当作整 ROM 动态构建已通过。

## 料理核心实际类型、生命周期与自然虚表（接续静态批次）

料理核心完成真实类型、所有权和三个生命周期入口的静态整理，移除一个
人工虚表子项。四版合计 52 处引用、34 个非指针窗口核对完成。2124 字节
生命周期实现仍计汇编，新增高级语言函数字节为 0。15 字节未知运行时字段、
后段析构的最终文件归属及整批四版输出验证明确保留为待办。

## 料理界面连续数据、固定行宽与引用归属（接续静态批次）

料理普通只读数据由每版三个输入对象合为一个；每版 32 个对象、共 200
处实际引用和 785 个非指针窗口完成静态核查。四版范围分别为 1612、1576、
1576、1616 字节。函数实现不变，新增高级语言函数字节为 0。料理核心完整
类布局、后段析构归属及整批输出验证仍未完成，不把本批计为全模块验收。

## 料理文本变量完整边界与精灵缓冲引用（接续静态批次）

精灵缓冲 1 个函数、料理主范围 26 个函数和文本变量 2 个后置方法完成本轮
边界/引用静态核查。恢复 8 字节文本变量对象及完整 16 字节虚表，核对
516 处真实引用、413 个非指针窗口和 28 个常量池误报。四版各减少一个
手工虚表 section；精灵缓冲实现四版共有。新增高级语言函数字节为 0。

料理核心完整类、后置方法归属和自然生成结果尚未完成验收。本轮没有编译、
提交或推送，不能将静态核查数字视为已验证的动态构建完成率。

## JoyBus 协议适配器与完整继承虚表（接续静态批次）

四版各 18 个 JoyBus 方法、780 字节代码和 268 字节虚表完成继承/引用静态整理，
核对 172 处真实引用及 12 个非指针窗口。方法实现仍计为汇编，新增高级语言
函数字节为 0。JP 手工表子项减少 2 处，US/EU/DE 各减少 1 处；
场景核心及其多重继承回调尚未完成，编译匹配尚未验证，不提交、不推送。

## 联机协议成员指针、状态对象与两套自然虚表（接续静态批次）

已恢复两套协议的 96 个真实成员入口、16 个状态结构及 80 个成员函数引用，
并以两个自然虚表替代对应手工碎片。四版各 1160 字节表内容完成静态核对，
184 处引用和 312 个非指针窗口已核实。函数实现仍计为汇编，新增高级语言
函数字节为 0；成员指针/虚表最终编译输出仍待整批四版统一验证。
联机派生类和后段回调尚未完成，不提交、不推送。

## GameCube 联机函数边界、传输包与四版共用指令（接续静态批次）

GameCube 联机完成 140 段原生函数的四版边界与共同指令整理，补齐海外各
19 个局部入口；恢复 0x4C 传输对象及 JP/海外固定包格式，28 个入口采用
已验证的功能名。核对 904 处真实引用、170 个非指针窗口。

这些代码仍计为汇编：JP 6000 字节、US/EU/DE 各 5992 字节。本批没有增加
C/C++ 实现字节，人工 section 计数不变。GameCube 协议继承/虚表与
code_linkonce 回调仍待处理，不能报告为整个模块已完成。没有编译、提交或推送。

## 礼物包装核心、地区工具图标差异与自然虚表（接续静态批次）

礼物包装完成八个原生成员、0x10C 核心和自然虚表归属。JP/US 各 2928、
EU/DE 各 2956 字节仍计为汇编；76 处引用、83 个非指针窗口已静态核对。
人工 .rodata 子项降为 JP 58、海外各 54。最终成员 ABI 与对象输出留待整批
统一构建，没有新增高级语言恢复字节，没有提交或推送。

## 工具箱菜单核心、工具栈接口与自然虚表（接续静态批次）

工具箱四版各 8432 字节仍计为汇编；完成十一段真实成员、核心字段和自然虚表
归属，不计新增 C/C++ 恢复字节。128 处引用/内部跳转及 7345 个非指针窗口
已静态核对。人工 .rodata 子项降为 JP 59、海外各 55；.text 仍为 JP 50、
海外各 51。尚未运行编译、提交或推送。

## 置物棚菜单核心、物品接口与自然虚表（接续静态批次）

置物棚四版各 9952 字节仍为汇编，完成真实核心结构、十三个成员入口及自然
虚表归属，不计新增 C/C++ 恢复字节。276 处引用/内部跳转、275 个非指针窗口
已静态核对。人工 .rodata 子项降为 JP 60、海外各 56；没有运行编译或提交。

## 背包菜单原生成员、说明缓冲与引用（接续静态批次）

八段背包原生成员四版各 6468 字节仍计为汇编，不计新增 C/C++ 恢复字节。
124 处引用或内部跳转、50 个非指针窗口完成静态核对。现有自然虚表保留，
没有新增自定义 section。接口、说明缓冲构造和最终布局待全 ROM 批次后统一验证。
未编译、提交或推送。

## 冰箱菜单核心、物品转移接口与自然虚表（接续静态批次）

冰箱完成真实 0x10C 核心、十三个原生成员接口、借用库存指针及自然虚表归属。
每版 10380 字节仍计为汇编；本批没有新增高级语言恢复字节。四版共 240 处
引用或内部跳转、192 个非指针窗口已静态核对。人工 .rodata 子项为 JP 61、
海外各 57；.text 为 JP 50、海外各 51。尚未编译、提交或推送。

## 铁匠升级选择核心、隐藏函数边界与原生接口（接续静态批次）

铁匠升级选择核心完成实际 0x1B8 布局、十个原生函数接口、两处隐藏函数边界及
自然虚表归属。四版 416 处引用或内部跳转、1092 个非指针窗口已静态核对；
本批没有新增高级语言恢复字节。人工 .rodata 子项为 JP 62、海外各 58；
.text 为 JP 50、海外各 51。全局静态整理未结束，尚未编译、提交或推送。

## 牧场商店核心、牲畜列表与状态说明缓存（接续静态批次）

牧场商店完成真实 0x43E0 核心、牲畜条目/名字缓冲/状态缓存边界、十二个
原生函数接口及自然虚表归属。四版 328 处引用或内部跳转、569 个非指针
窗口已静态核对；本批没有新增高级语言恢复字节。
人工 .rodata 子项为 JP 63、海外各 59；.text 仍为 JP 50、海外各 51。
全局静态整理继续；尚未编译、提交或推送。

## 木匠铺核心、改建目录与固定图块缓冲（接续静态批次）

木匠铺完成 0x61F4 核心、二十份标签图块缓冲、三项改建索引、真实成员
接口与自然虚表归属。6496 字节仍计汇编实现，没有新增 C/C++ 恢复字节。
四版静态核对 336 处真实引用/内部跳转及 380 个非指针窗口。
人工 .rodata 子项为 JP 64、海外各 60；.text 仍为 JP 50、海外各 51。
未运行编译、提交或推送；下一连续模块为牧场商店。

## 铁匠铺核心、图块缓冲与委托接口（接续静态批次）

铁匠铺完成真实 0x48E8 核心、十一份图块缓冲、九个原生成员接口及自然
虚表归属。6316 字节仍计汇编，没有新增高级语言恢复字节。四版 324 处
真实引用/内部跳转、230 个非指针窗口已静态核对。
人工 .rodata 子项为 JP 65、海外各 61；.text 仍为 JP 50、海外各 51。
尚未编译、提交或推送。继续按 ROM 顺序处理木匠铺及牧场商店。

## 海滨餐馆核心、订单持有与共有指令（接续静态批次）

海滨餐馆完成 0x6B0 核心、16 字节订单持有/转移 ABI、六段共有原生函数及
自然虚表归属。核对 32 处引用与 208 个非指针窗口，1656 字节仍计汇编。
人工 .rodata 子项现为 JP 66、海外各 62；.text 仍为 JP 50、海外各 51。
全局静态整理继续，未运行编译，未提交或推送。

## 特殊商人商店核心、目录边界与真实接口（接续静态批次）

特殊商人完成 0x710 核心结构、实际绘制/说明接口、类型化持有与自然虚表
归属。五段 3104 字节仍为汇编实现；四版核对 64 处引用及 1632 个非指针窗口。
人工 .rodata 子项为 JP 67、海外各 63；.text 仍为 JP 50、海外各 51。
全局静态整理继续，未开始统一编译，未提交或推送。

## 酒庄商店核心、配送分支与共享指令（接续静态批次）

酒庄核心完成 0x710 对象边界、类型化持有、三段四版共有原生实现和自然虚表
归属，保留 JP/DE 的额外配送选择。确认 44 处引用/调用，排除 41105 个非指针
窗口；没有增加 C/C++ 恢复字节。人工 .rodata 子项现为 JP 68、海外各 64；
.text 仍为 JP 50、海外各 51。全局静态整理继续，统一构建尚未开始。

## 霍安商店核心、完整函数边界与共享指令（接续静态批次）

霍安商店完成 0x710 核心类型、目录绘制/商品分类接口、四版共有原生实现与函数
内部标签修复；3696 字节仍计为汇编。确认 72 处跨对象引用/调用和 16 个内部长分支，
排除 4144 个非指针窗口。人工 .rodata 子项为 JP 69、海外各 65；.text 为 JP 50、
海外各 51。普通段每模块一次，自然虚表单独按旧 ABI 组织。全局编译尚未开始。

## 旅馆点餐核心、结果所有权与共享指令（接续静态批次）

旅馆核心 0x6B0、16 字节点餐结果及两级所有权转移完成静态整理；六个原生函数
1808 字节仍按汇编计，不计入高级语言恢复。核对 32 处真实引用/调用，排除 166 个
非指针窗口。人工 .rodata 子项降为 JP 70、海外各 66；.text 仍为 JP 50、海外各 51。
类型布局、自然虚表和 C++ 所有权输出待全 ROM 静态批次完成后统一编译，尚未提交。

## 诊所商店核心边界、类型化持有与共享指令（接续静态批次）

诊所核心完成 0x710 RAM 对象边界、真实成员接口和类型化持有，四个
原生函数共享四版内容，三处实际区域差异局部保留。静态核对 60 处
真实引用/调用与 102 个非指针窗口，2368 字节仍计为汇编实现。

人工 .rodata 子项为 JP 71、US/EU/DE 各 67；人工 .text 子项保持 JP 50、
海外各 51。统一编译尚未开始，未提交、未推送。

## 超市两种核心、四张虚表与共享原生实现（接续静态批次）

完成两种 0x710 核心的实际字段布局、四张虚表边界与真实成员调用。
12 个原生函数合并共有部分，仅九处保留实际区域差异。四版 120 处
真实引用/调用与 117 个非指针窗口已静态核对。4872 字节原生实现未
计为新增 C/C++ 恢复；两个 Run 的 56 字节仍属此前已恢复内容。

人工 .rodata 子项降为 JP 72、US/EU/DE 各 68；人工 .text 子项仍为
JP 50、海外各 51。尚未统一编译，未提交、未推送。

## 鸡舍商店核心、出售条目与名称缓冲边界（接续静态批次）

四版鸡舍商店完成 0x231C 核心布局、出售列表、图块及运行时文本缓冲边界，
核对 199 处真实引用/跳转与 153 个非指针窗口。原生函数全部保留，
不将改名、类型恢复或迁入 .cc 计为新增高级语言反编译字节。

人工 .rodata 子项为 JP 76、US/EU/DE 各 72；人工 .text 子项仍为 JP 50、
海外各 51。普通 .text/.rodata 每模块各列一次，真实虚表单独遵循自然
C++ 输出顺序。统一编译尚未开始；未提交、未推送。

## 共享商店核心、数量选择器与 VCount 所有者（接续静态批次）

四版共享商店核心完成 0x6A4 类型边界、十二个派生流程、数量选择器和
VCount 的所有者关系整理。核对 116 处真实引用与 50 个非指针窗口，移除
重复前缀类型和一份手工虚表；未将原生构造、析构计为已恢复 C++。

人工 .rodata 子项为 JP 77、US/EU/DE 各 73；人工 .text 子项仍为 JP 50、
海外各 51。真实类型布局及自然虚表输出待整批统一编译；原生函数仍含
固定字段偏移，不表示对象可以任意改动大小。未编译、未提交、未推送。

## 参考指南界面核心、星号行索引与清理归属（接续静态批次）

四版指南界面核心完成 0xA74 布局、真实成员入口、星号行索引、清理关系及
虚表归属的静态整理；核对 96 处真实引用与 71 个非指针窗口。每版 68 字节
查询、56 字节 STL 查找和 196 字节析构已有 C++ 表达，合计 320 字节暂列
待编译验证，尚不计入已验证 C/C++ 字节。构造和运行共 2592 字节仍为汇编。

人工 .rodata 子项降为 JP 78、US/EU/DE 各 74；人工 .text 子项仍为 JP 50、
海外各 51。整 ROM 静态批次继续；未编译、未提交、未推送。

## 城镇地图核心与标记容器的真实边界（接续静态批次）

四版城镇地图完成实际 0x1EC 核心布局、28 字节标记及 24 字节树节点边界的
静态整理；核对 72 处实际引用及 28 处非指针候选，移除各版一处手工虚表。
人工 .rodata 子项现为 JP 79、海外各 75；人工 .text 子项仍 JP 50、海外各 51。

本批 2044 字节原生代码（标记添加 732 + 晚期树操作/析构 1312）仍是汇编，
没有计入 C/C++ 完成字节。晚期实现的模块归属、剩余表和关联基础容器接口
仍未完成；全局静态批次继续，未编译、未提交、未推送。

## 滚动菜单、页面边界与真实虚表归属（接续静态批次）

四版滚动菜单和页面的对象边界、116 处实际引用及 69 处非指针候选已静态
核对。36 字节原生尾部访问方法现在有独立函数入口；两张虚表由实际类拥有，
56 字节菜单析构改为正常成员生命周期，输出尚待全局统一编译。

人工 .text 子项仍为 JP 50、海外各 51；人工 .rodata 子项降至 JP 80、海外各 76。
JP 多移除一个来自错误拆表的子项，未重复计算解析字节数。此批未增加已验证
C/C++ 覆盖率；全局静态批次、剩余手工虚表及晚期模板归属仍继续处理。

## 资源精灵渲染器的实际类边界与虚表归属（接续静态批次）

四版完成 8 字节渲染器对象边界、28 处实际引用和对应自然虚表归属的静态
整理。312 字节构造/析构仍是汇编，未增加已验证 C/C++ 字节数。
人工 .text 子项仍 JP 50、海外各 51；.rodata 子项减为 JP 83、海外各 78。
其中 JP 多移除一条原本不输出数据的 LDS 选择项，未将它计作解析字节进度。
全局静态批次、其他手工虚表、晚期模板归属及运行库来源仍未完成；未编译。

## 童年回忆场景核心恢复实际成员所有权（接续静态批次）

四版童年回忆核心恢复实际构造、独占 UI 成员和隐式虚析构，清除手写核心
虚表及自由函数 ABI 适配。12 处真实引用和 26 处非指针窗口已核实。
原生动画、背景地图、保存数据引用及文本变量布局保持原样。

人工 .text 子项仍 JP 50、海外各 51，.rodata 仍 JP 85、海外各 79；
原属于手工核心虚表的一个普通 .rodata 链接项改为真实类型的自然输出。
本批不增加已验证 C/C++ 或动态链接完成比例，输出仍待统一构建。

## 生日输入核心恢复实际构造与成员生命周期（接续静态批次）

四版生日输入核心的构造、独占 UI 成员及隐式清理已恢复真实类型关系，
移除一个人为虚表分节和自由函数析构适配。12 处实际引用、14 处非指针
窗口已核实；普通汇编、文本、对象容量及其余虚表未改。
人工 .text 子项仍 JP 50、海外各 51；.rodata 降为 JP 85、海外各 79。
普通 .text 重复对象仍 12 个，.rodata 仍 1 个。没有新增已验证匹配比例，
新输出留待全局静态批次结束后统一验证。

## 清理已经没有定义的 LDS 残留选择项（接续静态批次）

按当前源文件逐项核对 LDS，清理三种已经失去定义的旧选择项：四版的
code_linkonce.o(.text.farming_tutorial_runtime)、
code_linkonce.o(.text.map_clock_status_lifecycle_after)，以及海外三版的
vtables.o(.rodata.ui_output_base_after)，共十一条。后续 CW 核查发现前两项
对应实现并未完整迁移，原“均已归入实际模块”的结论错误；已补回完整函数和链接项，
详见“补回教学脚本宿主与字节查找的遗漏实现”。

这是失效链接条目清理，不增加代码恢复或引用恢复百分比。其余有效人工
子项继续保留待解决；未通过通配符隐藏它们。静态记录见
stale-linker-selectors-static-review，实际构建仍留到整批完成后。

## UI 传输队列执行方法恢复实际 C++ 归属（接续静态批次）

四版共用的 72 字节队列执行方法已恢复到实际 C++ 类，移除一个人工 .text
子项。四处真实虚表引用及 29 个非指针窗口已静态核实。新输出仍待统一
编译，暂不增加已验证 C/C++ 比例。人工 .text 子项剩 JP 52、海外各 53；
普通 .text 重复对象仍 12 个，.rodata 重复对象仍 1 个。

## 脚本引擎的自然析构及虚表归属（接续静态批次）

恢复现有 ScriptEngine 的真实类型输出归属，删除手工 12 字节析构和 20 字节
表。每版三处入口/表指针已静态核实；其他函数体、脚本资源和文本保持不变。
自然生成结果尚未编译验证，不增加已验证 C/C++ 百分比。

人工 .text 子项现为 JP 53、US/EU/DE 各 54；人工 .rodata 子项现为 JP 86、
US/EU/DE 各 81。普通 .text 重复对象仍 12 个，.rodata 仍 1 个。

## 精灵工作目标查找恢复旧 STL 实例（接续静态批次）

恢复一个真实 STL 查找实例，移除重复算法和函数分节选项。23 个普通函数
合并为一条 .text 对象选择；只调整已有 C++ 的组织方式，不增加高级语言
恢复字节数。四版各唯一入口调用已核实，新输出等待统一验证。

人工 .text 子项现为 JP 54、US/EU/DE 各 55；普通 .text 重复对象由 13 减至
12 个。人工 .rodata 子项仍为 JP 87、海外版各 82，重复对象仍 1 个。

## 野狗实体、五个行为接口与漏标函数边界（接续静态批次）

四版同步整理 3,428 字节、23 个汇编入口，补出原先被前一函数包住的 12 字节
叶函数。恢复五个实际行为接口及 80 字节自然虚表归属，实体自身 140 字节
表保留真实符号表达；未把不完整动物基类伪装为已完成。每版 30 处指针和
13 处调用静态核实，85 个非指针窗口排除。新构建输出尚未验证。

人工 .text 子项仍为 JP 56、US/EU/DE 各 57；人工 .rodata 子项减少六个，
现为 JP 87、US/EU/DE 各 82。普通 .text 重复对象仍 13 个，.rodata 仍 1 个。
继续处理前段实体及硬件接口的交错归属、剩余手工表和运行库字面量。

## 窗口控件的连续普通代码归属（接续静态批次）

四版同一个 1,848 字节窗口范围恢复一套 cc/hh 和单个普通 .text 条目，删除
四个过度拆分文件，修正误用的构造器 linkonce 选择。函数体不变；本项仅增加
归属整理进度，不增加 C/C++ 恢复量或已验证匹配量。全局静态整理仍未结束。

## 脚本视觉特效实体的连续模块与真实类型（接续静态批次）

204 字节、六个原生方法归入脚本视觉特效模块，四版共用同一汇编实现；
15 槽、60 字节手工虚表恢复实际类型归属。各版 7 处指针、1 处调用完成
静态核对，5 个非指针窗口已排除。此项增加边界/归属完成量，不增加已验证
C/C++ 或 ROM 匹配量。

人工 .text 子项现为 JP 56、US/EU/DE 各 57；人工 .rodata 子项现为
JP 93、US/EU/DE 各 88。普通 .text 重复对象仍 13 个，.rodata 仍 1 个。
下一步继续前段交错的通用角色/动物/精灵代码及窗口构造归属。整批未结束，
尚未编译、提交或推送。

## 旧 C++ 内联归属与硬件链表连续输入段（接续静态批次）

硬件链表合并了两个人工 .text 子项，普通 .text 重复对象由 14 减至 13；
人工 .text 子项变为 JP 58、US/EU/DE 各 59。普通 .rodata 重复对象仍为 1，
人工 .rodata 子项仍为 JP 94、海外版各 89。

修正环境精灵与 22 个相关头文件的内联/导出归属，明确显式 inline 与编译器
生成成员的区别。头文件 interface 泄漏已消除；窗口边框命令的显式构造归属
仍未完成。全部新输出待全 ROM 静态批次结束后统一验证，不增加已验证比例。

## 环境精灵十二种保存类型及晚段归属（接续静态批次）

十二种实际类型、存档字段和恢复工厂已补齐，4436 字节原晚段范围写为 C++，
十二张共 288 字节手工虚表改由类型生成。该晚段人工 section 已完全移除。
四版各 86 处原版指针完成静态核对，2597 个非指针窗口已排除；新增输出
未编译，不增加已验证匹配量。主模块的 2216 字节仍为完整原生汇编。

人工 .text 子项现为 JP 60 / US、EU、DE 各 61；人工 .rodata 子项现为
JP 94 / US、EU、DE 各 89。普通 .text 重复对象仍有 14 个、普通 .rodata
重复对象仍有 1 个。环境精灵晚段归属已整理，后续回到整 ROM 剩余交错模块、
运行库字符串及 SRAM 尾段。静态批次尚未结束，未编译、提交或推送。

## 环境精灵宿主与三个活动所有权槽（接续静态批次）

宿主和控制器恢复实际类型，492 字节原范围已写成 C++，72 字节手工虚表
改由类型生成；自然输出未编译，不增加已验证匹配量。四版各 24 处真实
指针、1 处入口调用完成静态核对，1139 个非指针窗口已分类。

人工 .rodata 子项现为 JP 106 / US、EU、DE 各 101；普通 .text 重复对象
仍有 14 个、普通 .rodata 重复对象仍有 1 个。晚段余 49 个入口/4436 字节，
接续记录恢复工厂及十二种具体行为。整 ROM 静态批次未结束，尚未编译、
提交或推送。

## 环境精灵基类与运动记录的真实布局（接续静态批次）

环境精灵抽象基类及运动记录恢复真实布局，248 字节构造/析构改为 C++，
一张 24 字节手工虚表改由类型生成。四版各 3 处真实指针、36 处入口调用
完成静态核对；四个跨动画记录的非指针窗口已排除。新编译输出尚未验证，
不增加已验证匹配量。其余主实现 2324 字节仍为汇编。

人工 .rodata 子项现在为 JP 108 / US、EU、DE 各 103；普通 .text 重复
对象仍有 14 个、普通 .rodata 重复对象仍有 1 个。环境精灵宿主、控制器、
十二种具体行为的 54 个晚段入口共 4820 字节尚未整理完，接续位置仍为
func_080DCF4C。整 ROM 静态批次未结束，没有编译、提交或推送。

## 鸡蛋、出货篮和狗球的实体及显示控制器（接续静态批次）

本批四版同步：三个实体/显示控制器模块，31 个主原生入口共 2684 字节。
其中 596 字节主实现和 184 字节晚段析构改为 C++/真实类型的自然输出，尚未
统一编译，不计入已验证匹配量；2088 字节仍为完整汇编。六张手工虚表共
216 字节改由实际类生成。每版审计 91 处真实指针及 25 处入口调用；四版
549 个非指针候选已按实际内容分类。

人工 .rodata 子项由 JP 115 / 海外各 110 降为 JP 109 / 海外各 104；人工
.text 子项仍为 JP 61 / 海外各 62。普通 .text 重复对象仍有 14 个、普通
.rodata 重复对象仍有 1 个，这些是链接组织计数，不是完整动态化比例。

npc_timed_path_search_after 尚余 4820 字节、54 个入口，下一入口为环境精灵
宿主析构 func_080DCF4C，后接宿主状态方法和控制器工厂；需结合完整环境精灵
类型及实际记录关系整理。全 ROM 静态批次尚未完成，没有编译、提交或推送。

## 实体事件效果的真实对象与集合生命周期（接续静态批次）

四版同步整理事件效果宿主、控制器及其实际集合。384 字节主构造/工厂与
792 字节晚段构造/复制/析构改为 C++ 或自然生命周期输出；两张 72 字节的
手工虚表改由真实类生成。1732 字节绘制/更新等实现仍为完整汇编，不计作
高级语言恢复。上述 1176 字节的新 C++ 输出尚未编译，不增加已验证匹配量。

每版核对 19 处真实地址引用、7 处入口调用；四版 1388 个非指针候选已有分类
证据。62 字节常量物理范围区分为 59 字节对象内容与 3 字节对齐，其中八字节
参数行的未知尾字段仍保留。原生固定分配、容量及字段访问是明确的修改限制。

人工 .text 子项仍为 JP 61、海外各 62；人工 .rodata 子项由 JP 117 / 海外112
降至 JP 115 / 海外110。普通 .text 重复对象仍有 14 个、普通 .rodata 仍有 1 个。
这些是链接组织计数，不能代替高级语言覆盖或完整动态化比例。

剩余 npc_timed_path_search_after 为 5004 字节、58 个入口。下一入口是狗球
可视控制器析构：JP 080DC648、US 080DCE94、EU 080DCEE0、DE 080DCDF8，
随后是出货篮等实际模块，继续按调用关系归属。全 ROM 静态批次及运行库附带
内容、普通对象交错、SRAM 尾段等仍未完成；不提前编译、提交或推送。

## 日程 NPC 派生类型与游走 NPC 边界（接续静态批次）

四版同步完成 35 个日程 NPC 派生类型及游走 NPC 基类/四个派生类型的静态整理。
40 张手工虚表共 2580 字节改为真实类的自然表；39 个晚段析构共 468 字节归回
实际类型。与构造和基类析构一起，共 2900 字节原版实现改用 C++ 定义或自然
生命周期生成，尚未增加已验证 C/C++ 或 ROM 匹配覆盖，统一编译没有开始。

游走模块共 3260 字节、40 个真实函数边界，其中仍有 2848 字节完整汇编；这部分
仅计算边界/模块/四版共享进度。新补齐两个独立入口，没有把汇编迁入 .cc 计为
高级语言完成。每版本轮核对 182 处真实指针及 72 处调用，619 个跨四版的地址形
非指针窗口完成分类。对象分配容量和原生字段偏移仍是明确的修改限制。

人工 .text 子项仍为 JP 61、海外各 62；人工 .rodata 子项降为 JP 117、海外各
112。普通 .text 重复对象仍有 14 个，普通 .rodata 仍有 1 个。这些是 LDS 组织
计数，不替代高级语言覆盖、匹配率或完整动态化比例。

下一处晚段入口为 JP 080DC330、US 080DCB7C、EU 080DCBC8、DE 080DCAE0：
实体事件效果的精灵集合构造及对应复制/析构依赖。npc_timed_path_search_after
原 6264 字节范围剩余 5796 字节；剩余名字仍混有多种实际模块，需要依据调用方
继续归属，不能因为旧 section 名就都归入 NPC。全局静态批次、运行库文本来源、
132 字节 SRAM 尾段和普通对象交错问题仍未完成；不提前编译、提交或推送。

## 普通玩家基类与 NPC 基类接口（接续静态批次）

四版同步归回普通玩家抽象基类和 NPC 基类真实成员，移除两张共 240 字节的
手工虚表、一项人工代码子段，并补清四字节 NPC getter 边界。112 字节玩家
基类构造/析构改为类代码或自然生命周期生成；NPC 六个已有实现仅恢复接口
归属。新增已验证 C/C++、匹配覆盖仍为零，统一编译尚未开始。

每版共核对这两组范围的 209 处真实指针及 13 处调用，19 处地址形误命中完成
分类。当前人工 .text 子项 JP 61、海外各 62；人工 .rodata 子项 JP 157、海外
各 152。普通 .text 仍有 14 个重复对象，普通 .rodata 仍有 1 个，不能将这些
链接组织计数替代动态化或高级语言百分比。

下一组为 35 个日程 NPC 与 4 个游走 NPC 的独立派生类型和自然析构；四版的
构造、虚表、析构和对应世界槽已成对记录。原始 6264 字节 npc_timed_path_search_after
剩余块尚未移除。全局静态工作仍未完成；不提前构建、提交或推送。

## 教学玩家实体接口及共同动作实现（接续静态批次）

四版恢复教学玩家的实际五项虚接口、0x5C 对象布局和手持图像运动记录。340 字节
构造/工厂/状态查询/析构改为正常 C++ 实现或生命周期生成，两个共 160 字节的
手工虚表改由类定义生成；新增已验证 C/C++ 和 ROM 匹配覆盖仍为零，等待整批构建。
1908 字节动作和绘制汇编完成四版共用，仅算模块/共享组织进度。

每版 22 处数据引用（含 12 处内部跳表引用）和 9 处调用已核对，87 处地址形
误命中完成分类。当前人工 .text 子项 JP 62、海外各 63；人工 .rodata 子项
JP 159、海外各 154。普通 .text 仍有 14 个重复对象，普通 .rodata 仍有 1 个。
0x30 未知字、普通玩家完整抽象接口及后续 NPC 类型仍待恢复，不因析构字节相同
就将它们合并为同一种对象。

接续位置：普通玩家抽象基类析构 JP 080DBFB4、US 080DC800、EU 080DC84C、
DE 080DC764，四版均为 52 字节；对应 44 槽抽象虚表与当前部分 PlayerActor
接口需要核对。其后 NPC 晚段首先有 39 个各 12 字节的派生析构，其中 35 个转调
ANpcEntity、4 个转调 RoamingNpcActor（后续复核更正），应按实际类型分别恢复。
整 ROM 静态批次未结束，未运行编译器、汇编器或链接器，未提交、未推送。

## 教学玩家绘制控制器与字节查找实例（接续静态批次）

四版同步恢复教学玩家绘制控制器的真实 0xD0 类型、工厂和构造关系，并将旧 STL
字节查找改回现有算法实例。共 320 字节实现改由常规模板/类代码生成；624 字节
Update/Draw 汇编完整保留。新增已验证高级语言和 ROM 匹配覆盖率均为零，须等
全局静态批次结束后统一验证。没有增加工具、源码目录或人工 section。

每版 6 处数据指针及 2 处调用已核对，四版合计 246 处地址形误命中完成分类。
移除一处手工虚表 section；当前人工 .text 子项 JP 63、海外各 64，人工 .rodata
子项 JP 161、海外各 156。普通 .text 重复对象仍有 14 个，普通 .rodata 仍有 1 个。
以上是链接组织统计，不是动态化百分比。教学玩家实体及两种玩家抽象基类的完整
虚接口仍待恢复，不能用相同析构指令推断它们是同一个类型。

接续位置：.text.entity_visual_controller_cleanup_after 剩余 52 字节教学玩家实体
析构；其后 .text.player_sprite_cleanup_after 是两个各 52 字节的抽象玩家基类析构。
继续依照真实构造和虚表关系处理，随后沿原 ROM 顺序推进其他晚段实例。
全局静态整理仍未完成，本批未编译、提交或推送。

## 实体精灵生命周期及世界接口归属（接续静态批次）

四版同步恢复马与小精灵控制器的实际类型，归回五个析构和四张表的模块关系。
64 字节世界接口汇编及 536 字节表归入 game_object.cc/.hh；两种控制器共 116
字节原生析构改由真实成员生命周期生成，另选入已有的 52 字节声音实体隐式析构。
原生构造/绘制指令保持，新增已验证高级语言和 ROM 匹配覆盖率均为零。

每版 13 处真实数据引用已核对；502 处跨四版的文本/资源地址形误命中已分别证明。
当前人工 .text 子项 JP 63、海外各 64；人工 .rodata 子项 JP 162、海外各 157。
普通 .text 重复对象仍有 14 个，普通 .rodata 仍有 1 个；这些是组织统计，不是
动态化百分比。声音实体 35 槽虚表和世界接口的未恢复签名仍待处理。

下一段从 JP 080DBE30、US 080DC67C、EU 080DC6C8、DE 080DC5E0 继续：它混有
旧 STL 的四项展开字节查找及其他实体析构，不能按旧 after 段名认定同一功能。
整 ROM 静态批次未结束，未启动编译或提交，目标继续保持。

## 农场地图、记录与牧场状态的转场及虚表（接续静态批次）

四版同步整理三个场景与转场类型、六个晚端入口及六张真实虚表。336 字节由
原生转场代码改为 C++ 候选，主体汇编不变；已验证高级语言/ROM 覆盖率暂不增加。
另一个已有 C++ 虚析构取消人工 section，并清除 17 个空分节。

当前人工 .text 子项为 JP 65、US/EU/DE 各 66；人工 .rodata 子项为
JP 164、海外各 159。普通 .text 重复对象仍有 14 个，说明全局整理未完成。
这些是源码组织统计，不是可动态编译或高级语言反编译百分比。

继续核对剩余原生生命周期、真实虚表归属和交错普通方法。实体精灵旧编译器
产物中有 208 字节非虚内联方法属于普通 .text，必须按实际生成规则整理。
保持整批静态阶段；全部完成后才进行 WSL -j4 四版验证与本地分类提交。


## 晚段生命周期与场景操作（接续静态批次）

本批四版各移除四处人为 .text 子项：开场核心清理、脚本队列清理、背包转场
工厂及三条场景操作。前三项按实际 C++ 生命周期/工厂机制组织；最后 268 字节
仍为共享原生汇编，归入 game_scene_actions.cc/.hh。已验证 ROM 和高级语言
覆盖率均未更新；104+72 字节 C++ 改写及开场隐式析构需要最终编译确认。

当前普通 .text 的重复对象为 14 个；人工子项 JP 68 项、海外各 69 项，
说明全局静态整理仍未结束。运行库 bad_alloc 的本地定义和现有未链接对象
证据已补充；未把所有同串当成可删除重复内容，也未改预处理工具。

接续为晚段场景工厂/析构，起于 after_gamecube_link_scene；硬件 VBlank/VCount
交错输出仍保留待办。继续静态整理，不启动逐块编译，不提交或推送。


## 商店 UI、数量选择与游戏菜单（接续静态批次）

这批每版完成 73 个原生函数的边界与模块归属整理，其中六个遗漏入口补齐。
菜单正文现集中为 67 个汇编函数与 22 个既有 C++ 入口；数量选择器保留三个
已有高级语言方法。原地址命名的大汇编文件 code_809E804.s 已清空移除。
新增高级语言恢复字节仍为 0，没有把迁入 cc 的汇编计为高级语言反编译。

菜单连续范围到 JP 080CFA64、US 080D01E0、EU 080D0210、DE 080D0128。
后续按地址核对堆、JoyBus、字体、底层库和晚段内联区域；已有可靠整理的
模块核实后跳过。UiVCountBinding 的晚段排布、菜单自然内联生成和手工虚表
仍未完成，不将本轮静态整理宣称为已通过四版 ROM 比较。
本轮未编译、未提交、未推送。


## 商店共用核心与菜单数据归属（接续静态批次）

商店共用六个函数/版完成模块归属与共享接口整理：JP 9,576 字节，其余
三版各 10,140 字节。全部仍为可读原生汇编，新增高级语言恢复字节为 0。
七个商店对象与 JP 37、海外各 36 个菜单对象按原物理顺序分属两个已有主题，
475 处数据符号引用、八处明确字段偏移和一处图块误命中已核对。

接续为商店后的 UI VCount 与游戏菜单连续代码，需处理仍在汇编中的方法、
菜单旧的逐函数 section，以及与现有 C++ 方法的自然排布。全 ROM 静态批次
尚未完成，本轮未编译、未提交、未推送；不更新已验证的 ROM 匹配比例。


## 收获与浇水小游戏（接续静态批次）

本批新增高级语言恢复字节为 **0**。收获与浇水共 57 个真实函数/版归入独立
功能模块，修正 JP 十六个缺失入口和十五个内部伪入口，海外版各修正三个。
收获正文：JP 17,548 字节，其余三版各 17,556；浇水正文：JP 29,060、
US/EU 各 29,068、DE 29,044。数据顺序、193 处真实数据指针和区域差异已
静态核对，仍未启动统一编译，未提交或推送。

接续位置是商店共用构造、析构、金额刷新和紧随其后的显示初始化；需要
继续核实其与 shop_common、菜单数据的实际归属。全 ROM 静态批次没有完成，
晚段方法、运行库来源及自然生成顺序仍有未决项，不更新已验证 ROM 比例。


## 鸡祭小游戏（接续静态批次）

本批新增高级语言恢复字节为 **0**。四版各 50 个原生函数及八个已有 C++ 方法
归回鸡祭模块，普通正文各 36,008 字节；原生指令、数据定义及 128 处实际数据
引用完成静态核对。每版正文由六行 LDS 条目改为一行，连续数据同样只链接一次。
此前三个模块的汇编 include 路径错误也已修正。

下一范围从鸡祭结束处开始，包含收获、浇水小游戏和独立资源辅助组，须先按
真实调用及边界拆清，不把这一大段笼统归为同一模块。全 ROM 静态批次未结束；
运行库生成、晚段方法及部分自然内联/虚表输出仍有待办。尚未编译、提交或推送，
现有匹配比例仍代表最近已验证基线。


## 动物照料小游戏（接续静态批次）

本批新增高级语言恢复字节为 **0**。每版 35 个旧标记归回实际小游戏模块，
其中 1 个修正为内部循环标签，实际 34 个函数入口；
普通正文为 JP 23,840 字节、US/EU/DE 各 23,844 字节；数据范围按源顺序合并，
已有符号引用的覆盖和误命中已核对。仅完成静态整理，未启动任何编译、汇编、
链接、make 或移址实验，未提交或推送。

下一段为鸡祭小游戏的连续构造、运行、UI 方法及数据；按实际功能收齐其
交错的 C++ 和 native 正文后再合并普通输入节。全 ROM 静态阶段仍未结束，
现有匹配统计继续代表上一次已验证基线，不把此次移动汇编计入 C++ 恢复。


## 教程世界与婚期筛选（接续静态批次）

本批新增高级语言恢复字节为 **0**。每版 4,628 字节已归入正确 native 模块，
补出两个独立叶函数入口，并纠正三个虚表的真实对象边界。教程世界与婚期筛选
各使用一个普通 `.text` 条目；JP 移除三个错误虚表前缀条目。共同语义入口和
JP 对应函数直接统一命名，不建立兼容别名。静态检查通过，尚未运行编译验证。

下一段从 UI 文本流之后继续：原 `.text.ui_text_stream_update_after` 含不同
功能，需要按消费者、类实例与连续物理范围划分，不能整体塞入 ui_text_stream。
原手工教程虚表、后置 native 析构、婚期表和 lower-bound 的最终归属仍待处理。
全 ROM 任务未完成，既有匹配统计仍代表最近一次已验证基线。


## 全局静态批次进行中（2026-11-06）

不再按一两个模块循环构建、提交。四版全量对象清单已建立，当前批次已调整
JoyBus、日历/昼夜表、调色板存储、解压器、指南、菜单与名称输入、图块池与
图块集合、硬件帧命令，以及 C++ 内联生成归属；
完整交错对象清单和 C/CC 判定记录见 `CODE_ROM_LAYOUT.md`。

本次再整理世界场景连续主体及其真实后段运行模块，并静态恢复 43 张原生虚表。
新增的运行库字面量审计已建立四版位置清单；来源归属仍待逐项确认。
这些都是未编译的组织调整，不改变下方已验证的字节覆盖统计。

本轮继续拆清动物、玩家和小精灵工作实体的真实连续模块，并补齐九个角色访问器入口。
保留 28 个既有 C++ 定义与 17 组原生实现；这些是源码归属和边界调整，
未将迁入 cc 的汇编计作高级语言，未更新已经验证的 ROM 字节覆盖率。

事件特效的连续主体已合为普通 .text，并从旧 NPC 汇编容器分出游走 NPC、
鸡舍地面鸡蛋、出货篮及狗球四个真实功能模块。补齐了四个游走 NPC 构造入口，
并记录特效后方四个独立短函数；均保留原生实现，不计入高级语言进度。
全容器四版有效指令与数据指令已按原顺序作静态往返核对，统一构建仍未开始。

补充批次覆盖 GameScene、存档主体、场景转场与音频/字体/图形容器。
当前普通 .text 重复对象为 18 个（基线 105）；这是组织指标，
不代表新增高级语言或已验证字节覆盖。虚表集合等全局遗留仍待继续处理。

NPC 基类、日程控制和连续角色构造已合为普通 .text；两处晚段搜索恢复为
项目自带 STL 模板实例，去掉用于手工分隔它们的函数分节选项。
末尾另识别七个完整函数入口。原生指令顺序及已有结构布局已静态核对，
模板的新生成字节尚未验证，不增加已验证覆盖率。

角色移动辅助的 2252 字节连续范围已归入 actor_movement.cc/.hh，
保留十三个 C++ 正文和一个原生函数，四版各使用一条普通 .text。
另从实际读取方式恢复场景装饰的坐标及季节权重记录；四版共用的 598 字节数据
已与既有基线核对。装饰主体及七个短访问器已归入同名模块；晚段虚函数与实际类定义仍未完成。

场景装饰的 17 个原生函数现按真实功能归入 world_ambient_sprites，四版各
2572 字节的保存对象证明指令与重定位一致，因此共用一份原生实现。相邻的
656 字节装饰数据和 44 字节天气数据分别归入所属模块的普通 .rodata；
移除十二份重复区域文本片段，保留六个尚待恢复自然生成来源的运行库字面量。
这些是静态归属和名称调整，不增加已验证字节覆盖或高级语言完成量。

辅助精灵、场景文本变量、主菜单和时钟控件的连续主体已合为四条普通 .text。
三组原生实现归回已有模块，47 个 C++ 定义静态保留；晚段生命周期改用
真实内联定义及原生 linkonce，生成结果仍待统一构建，不增加已验证进度。

文本窗口的 1444 字节连续主体现归入一条普通 .text；物理后段独立的
284 字节边框绘制改由同名 C 模块维护，命令构造/上传正文归回类型头文件。
此项只记录归属和语言选择，不将已有正文重复计算为新增反编译量。

地图三处不连续代码已按选择、资源访问和地形判定分为实际模块。NPC 日程的
6496 字节代码与 28500 字节数据按四版物理次序归入同名模块，32 个选择回调
由人物成员和描述表确定功能名，124 份运行库文本片段回归原位普通数据。
这些静态归属调整不增加已验证字节数或高级语言完成量；新的 C 前端输出、
同一对象内的函数/数据输出顺序仍待最终统一构建。

脚本引擎的六个连续输入范围合为一个普通 .text 对象。原生分派与变量
读写整体迁入 script_engine.cc，保留 17 个 C++ 正文和 20 条区域原生流；
实际生成字节尚未编译，此项不计为新增高级语言反编译或已验证覆盖。

字体合成器、数字排版、OAM 构造和较晚的无符号格式化已经按实际功能整理。
UI 的 9216 字节主体与远处头像管理拆清，85 个已有定义和 16 条区域原生流
静态保留；内联构造器的延后输出及主构造内联仍待统一编译解决。
飞盘成绩显示及四版各 23448 字节小游戏主体归回各自模块，旧场景包装
和文本同主题合并；JP 五处常量池前零填充改为有对象字节证据的对齐。
上述迁移没有新增高级语言反编译量，也不增加已验证字节覆盖。

赛马与兑换、童年开场主范围、财产界面和参赛动物选择继续按 ROM 次序
整理。财产及动物选择从原位置命名的大汇编段分回实际功能模块，并
同步拆清连续文本和固定字段；主顺序接续到生日输入入口之前。
原代码和数据顺序已作静态保留检查，十二字节尾部叶函数补齐入口。
手工开场核心虚表、生日/预览旧数据归属、晚段生命周期及运行库自然
生成仍未完成；本批不增加高级语言或已验证字节覆盖。

生日输入、农场地图、记录页面和资源精灵绘制继续按实际边界归回同名模块；
生日输入原十二条普通代码选择合为一条，相关文本与数组同步归属。
确认并修正了一个被误标为独立函数的共享收尾入口；四版绝对指针扫描
与 Thumb BL 目标检查支持内部标签表示。当前主体接续到滚动缓冲区
构造前（US 08075B00，其他区域范围见 layout）。
二十个既有 C++ 定义、原生指令和数据序列静态保留。通用页面 UI、
滚动类内联输出、晚段方法/虚表及运行库自然生成仍待处理；
本批不增加高级语言字节数或已经验证的 ROM 覆盖率。

滚动缓冲区、滚动菜单、工作人员、城镇地图和图书阅读的连续主范围
已各归为一个普通 .text；相关目录、文本和地图区域数据同步合并。
旧选择访问器实际处理滚动位置，按调用证据更名并归入共用菜单。
主顺序接续到商店代码之前（US 0807B0F0；四版范围见 layout）。
四十四组区域原生流、既有函数和数据序列完成静态保留核对，
C++ 内联/虚表发射及最终字节尚未验证，不增加已验证覆盖率。

八个商店连续主体已按各自实际功能合为普通 .text/.rodata，
数据和文本归回同名 cc/hh；删除旧数据模块与区域旧命名文件。
修正了三个功能边界、内部循环/返回标签和海外版缺失的说明入口，
并依据 FoodUi 与 Mary 枚举改正超市食品表的旧种子分类。
当前主顺序接续到铁匠铺核心（US 080821D0，其他区域见 layout）。
静态核对保留 22 个 C++ 正文、52 条区域原生流及 32 份数据序列；
尚未编译，不增加已验证覆盖率。核心类、晚段方法和运行库来源未完成。

锻冶屋、木匠、牧场和独立工具升级界面完成本轮静态归属整理；
四版合计 20 条区域原生流的指令、16 份区域数据及 13 个既有
C++ 正文保留。删除六个错误独立函数入口标记，名称按实际作用整理。
随后储物界面的旧命名错位已在下述批次修正。
未编译，不计入新的高级语言覆盖或已验证范围。

冰箱、背包、整理棚和道具箱归回四个同名模块；修正旧循环错位名称，
保持 Mary 命令编号和运行路线。四版合计 16 条原生流、16 份数据
及四个既有 C++ 模块正文保留。JP 补齐 12 个真实入口并统一 14 个
已有入口名；10 个栈内分支不再当作独立函数。原生汇编迁入 cc
不计高级语言覆盖；全部变更仍待全局静态完成后的统一验证。

礼物包装、联动、精灵绘制缓冲、料理及食谱计算完成本轮原生归属
整理；较晚的联动紧凑值方法独立排列。合计保留 24 条区域原生流
和 12 份区域数据。JP 料理新增 10 个已匹配入口、统一两个旧名；
当时另有 10 个 US 入口的地区差异待核，随后已补齐其中缺失的九个
JP 入口；地区差异指令保持。不能据此认为整个 ROM 或这些主题的类/虚表完成。

账目历史的四版原生正文各 428 字节已归回 money_account.cc，旧
code_0803EE94.s 容器移除。账目晚段复制/析构与真实存档复制调用的
发射关系仍未解决，保留原子段并明确记为未完成，没有靠 pragma 或假调用隐藏。

矿层 24 个既有 C++ 方法和四版相同的 60 字节原生选择器，按 ROM
顺序归入单个普通 .text；每版 .rodata 也仅链接一次。取消矿层专用
逐函数分节，四份重复运行库文本移回本体原位置。原生跨数组读取约束
与运行库自然生成仍待核实；本批不增加高级语言或已验证覆盖率。

NPC 集合和日历界面的普通 .text/.rodata 各合为一条，姓名目录、
生日元数据、季节名和节日日期按真实对象边界归回同名模块。补齐一个
被局部标签包住的独立 const 查询；四版 20 条原生流、26 个既有 C++
正文和原有区域文本均静态保留。日历季节名的 16 个分区域指针及日期表
的 4 个分区域指针现直接引用真实标签，移除旧的 season-name+offset
模型。NPC 晚段复制的实际 C++ 调用、日历完整核心类和运行库自然
生成仍未完成。主顺序现到日历场景之后（US 080A37A8，四版见 layout）；
没有执行编译或更新已验证覆盖率。

鸡祭与精灵小游戏的连续入口归入 scene_minigames；名称输入移除普通
函数分节；后方钓鱼函数和五份数据模块合为 fishing.cc/.hh。四版原生
实现共用一份源码，8 条原生流、6 个既有 C++ 正文和 8 份区域数据
顺序静态保留。59 项渔获配置末尾零字节恢复为结构自然对齐；四版
各 10 个数据地址候选与原对象重定位对应，资源中的字节巧合另行分类。
主顺序推进至钓鱼结束（US 080A4650、JP 080A4088、EU 080A4680、
DE 080A45B0）。后续为昼夜表、地图数据及场景精灵/世界地图交错
实现。内联生成顺序、小游戏完整类型和运行库来源仍未完成，未编译。

世界地图、场景精灵和临时地图特效的普通 .text 已分别合并；四版各保留
21,328 字节原生实现及既有 C++ 正文。普通 .text 自定义选择项本批减少
69 项/版，重复对象由 21 降到 18。四个原始地形数据对象恢复为真实
属性记录及索引网格，并核对四版共 104 处入向重定位。这里只记录静态
组织和边界改进，没有编译，已验证高级语言/ROM 覆盖统计保持不变。

**当前工作区未编译、未提交。** 已验证进度仍以 `21786ce3` 为准。
JoyBus 内嵌原生汇编不属于新增 C；过程式 cc 改成 c 也不增加高级语言覆盖。
源码归属、段选择项减少、真实符号恢复和高级语言恢复分别记录。

## 新游戏表单链接组织（2026-11-05）

四版身份确认与名称输入模块的普通代码现在各由同名 cc 按 ROM 顺序维护，
两份独立汇编文件并回所属模块；普通 .text 的 24 条选择项合为 2 条。

| 指标（每版） | 本批前 | 本批后 |
| --- | ---: | ---: |
| 身份确认 .text 链接项 | 7 | 1 |
| 名称输入 .text 链接项 | 17 | 1 |
| 全 LDS .text 中重复列出的对象 | 108 | 105 |

三处 NAKED 实现仍是原生汇编，本批新增 C/C++ 函数体字节、新恢复指令字节和
新恢复指针数量均为 **0**。它们与前批四处迁入的 NAKED 实现均须继续排除在
高级语言覆盖分子之外；对象数量变化也不能当作新增高级语言进度。
下方多维覆盖表是注明基准的历史快照，本批不改写其当时统计。

最终四版 WSL `make -j4 compare`、完整原版字节/SHA-1、全局符号及原生重定位
复核通过。迁入函数检查了 JP 84 项、US/EU/DE 各 90 项实际重定位。
新游戏菜单的转场成员、DMA 隐式析构及其他交错模块仍未完成，继续按全 ROM 清单推进。

## 内联资源表长补齐（2026-11-05）

八组原位内联归档（四版共 32 个实际实例）补齐七张表的真实边界，224 个计数
字段由标签差与原生步长计算。每版总范围 1,972 字节，其中 564 字节为
表头及元数据；selection/group/OAM/sixth/entry 按实际 u16 字段表示。
已有 tile/palette incbin 及资源构建规则保持原样，没有新建资源目录或工具。

本批新增高级语言函数、原生指令字节和绝对指针恢复量均为 **0**；推进的是
已知资源格式的内部边界和长度关系。与此前 44 组归档合计覆盖 52 组、208 个
区域实例。最终四版 WSL `make -j4 compare`、完整原版字节/SHA-1、真实全局符号
地址均通过。仍不将索引、硬件容量或跨对象复制报告为可自由扩缩。

## 对象组织与 section 整理（2026-11-05）

四版完整 LDS 对象清单已建立。本批将开场前段八条选择项合为普通 `.text`，
混色更新归入所属模块，ROM 头与启动代码合并，并清理六个连续 C++ 模块、
四个独立汇编模块和 M4A 只读表的人为子段。独立分配失败处理拥有同名 cc/hh。

| 指标（每版） | 本批前 | 本批后 |
| --- | ---: | ---: |
| `.text` 中重复列出的对象 | 114 | 108 |
| `.rodata` 中重复列出的对象 | 23 | 22 |
| 开场前段显式链接项 | 8 | 1 |
| M4A 只读数据显式链接项 | 4 | 1 |

本批新增 C/C++ 反编译量与新恢复汇编字节均为 **0**。四个已有原生汇编函数
只是归入所属 `.cc` 的正确物理位置，不能因此改算为高级语言代码。
最终四版 WSL `make -j4 compare` 及完整字节/SHA-1 通过，全部原有真实全局符号
地址保持不变，原生池 ABS32 已逐项复核。没有移址或尺寸变化实验。

开场后段清理/工厂、DMA 链隐式析构、其余交错模块和原生 C++ linkonce 组织
仍未完成；132 字节 SRAM 后置未知块等限制继续保留。详见 layout 与引用审计。

## 飞盘背景资源格式恢复（2026-11-05）

接续全 ROM 已记录的跨资源读取问题，五项载荷共 3,944 字节（每版）从未知
字节流恢复为三份 tilemap、五组 PAL 调色板和四帧动画 PNG，使用已有构建链。
静态背景图块源保持原样；四版保持相同层级、实际物理顺序及六个真实引用。

本批新增 C/C++ 函数、ARM/Thumb 指令和新恢复重定位均为 **0**。推进的是
资源用途和内部分界，不重复计算已恢复的调用。512 字节复制跨入动画的
行为已核实并保留；132 字节 SRAM 后置未知块仍明确列为未解析。
四版统一 WSL `make -j4 compare` 首次全部通过；完整 ROM 字节/SHA-1 与原版
一致。五个符号更名后地址不变，所有其他符号及输入段位置保持原样；每版六个
资源入向 ABS32 已逐项核对，生成的五项资源也与原载荷逐字节一致。

## 全 ROM 静态核查收尾与资源表长（2026-11-05）

已把上一批 m4a 之前的核查接续到四版 ROM 末尾。此次先完成全部剩余静态
核查和批量修改，最后统一 WSL `make -j4 compare`，四版首次全部通过。
ROM 字节/SHA-1、既有符号、输入段位置和核对的音频重定位均保持原样。

- 44 份归档（四版 176 个实际实例）的七类表长使用标签差计算；大型归档
  2,272 字节原始元数据恢复为实际 u16 字段及 u32 表头。
- CGB 波形明确为 32 × 16 字节，14 处引用改用数组行索引。每版 1,541 个
  音轨控制指针、421 个非空歌曲头指针和波形指针通过静态重定位核查。
- 移除末尾 21 处重复原址定位；三批合计移除 444 处普通 ROM 模块定位。
  JP/US 尾部填充改从实际 IWRAM 装载终点推导，镜像仍为原版 8 MiB。

本批新增 C/C++ 函数正文和 ARM/Thumb 指令字节均为 **0**，也不重复计算既有
音频重定位为新恢复的引用。推进的是数据内部边界、长度表达与链接自由度。
这仍不是“所有对象均可随意扩缩”：132 字节未知尾部、跨资源 512 字节复制
及格式内索引/容量等约束继续保留。详见 [CODE_ROM_LAYOUT.md](CODE_ROM_LAYOUT.md)
与 [RELOCATION_AUDIT.md](RELOCATION_AUDIT.md)。

## m4a 前置 rodata 顺序链接（2026-11-05）

四版已继续核对 rodata 起点至 `src/m4a.o(.rodata)` 前的连续范围，并移除
153 处重复原址定位（JP 5、US 63、EU 63、DE 22）。包括虚表、普通文本与
相关结构、NPC 日程、Mary 索引表、指南、工作人员名单及前置静态资源。
范围和证据见 [CODE_ROM_LAYOUT.md](CODE_ROM_LAYOUT.md)、
[RELOCATION_AUDIT.md](RELOCATION_AUDIT.md)。

DE 名单起点补上原本由绝对地址隐含的四字节对齐后，四版 WSL `make -j4 compare`
及完整 ROM 字节/SHA-1、既有符号地址和输入段位置全部通过。新增 C/C++ 正文、
汇编指令和数据重定位均为 **0**；本批推进的是已确认引用下的链接自由度。
下一连续边界是 m4a 数据，后续资源内部尺寸与未知尾部仍未宣布完成。

## 代码布局解除重复定位（2026-11-05）

全 ROM 批量恢复后的四版代码，现按原有对象顺序自然链接。已移除 270 处
普通代码固定定位（JP 103、US 55、EU 55、DE 57），覆盖从 ROM 头至 `.text`
末尾的 5,618 个输入段。完整范围及引用依据分别见
[CODE_ROM_LAYOUT.md](CODE_ROM_LAYOUT.md) 与 [RELOCATION_AUDIT.md](RELOCATION_AUDIT.md)。

四版一次统一 WSL `make -j4 compare` 全部通过，8 MiB ROM 字节、SHA-1、
符号地址和输入段位置均保持原样。本批新增高级语言字节为 **0**，也不重复
计入上一批恢复的汇编指令。下一阶段仍需按 ROM 顺序处理 rodata/资源的内部
边界、尺寸与引用约束；未知 SRAM 后置数据等保留问题尚未解决，不能报告
为整 ROM 已完全动态化。

## 全 ROM 批量阶段（2026-11-05，四版匹配）

按用户要求，以 `b83ab375` 的四版匹配 ROM、ELF、map 和输入对象为不可变基线，
先完成整 ROM 静态扫描和批量修改，中间未运行编译器、汇编器、链接器或 make。
静态阶段结束后统一执行 WSL `make -j4`，先修正汇编错误，再从最早的 ROM 差异
地址检查；最终四版均匹配原版。
不做移址实验，不改写历史，不推送。下面列出本批已验证的新增量。

| 版本 | 从原始数据恢复的指令数 | 指令字节 | 新绑定的 PC 池地址 |
| --- | ---: | ---: | ---: |
| JP | 56,036 | 117,674 | 287 |
| US | 8,196 | 16,602 | 2 |
| EU | 8,399 | 17,024 | 2 |
| DE | 8,399 | 17,024 | 2 |

修改保留在现有源码中，没有新增资源目录、构建工具或链接后补丁；新增 C/C++
反编译指令为零。统计按指令字节计算，不把常量池、跳表、样本或图像算作程序。
JP 另改正了旧映射中误归为指令的 138 字节，已与新增指令量分别记录。

本轮同时处理以下边界与引用：

- JP 的隐藏调用、PC 池和跳表恢复实际指令及标签。四组相邻虚表的边界按真实
  调用入口修正，总长度不变；五个资源目标补出真实标签。
- 每版 106 个 WaveData 头直接在实际位置定义，四版共 424 个头部，移除旧 `.set`
  偏移别名。字段按 u16/u32 表示，采样数由首尾标签差计算；原有额外采样字节
  单独保留，之后才对齐。
- 字体索引、地图属性、tilemap、资源归档头/索引/OAM/颜色字段按已经核实的
  读取宽度表达。已进入资源链的 incbin 保留，补齐 JP/DE 对已有共享资源的引用。
- EU 十个资源的旧入口误落在真实起点之后 8 字节，现将共享名称直接放在真实
  起点并更新引用。完整生成资源直接 include，不再拆出伪“头部＋余下内容”。
- 常量池、函数末尾对齐、数据对齐、空白图块槽分别处理。七组 96 字节全零内容，
  每组是三个空白 4bpp 图块槽，保留长度，不误当作对齐删除。

当前源码的直接分支和 PC 相对读取均按原目标符号化。旧 C/C++ 编译产物中 `.rodata/.data` 的完整
数值 word 已扫描，未发现未符号化的 ROM 指针。逐字节出现的地址形数值需结合
字段解释，PCM 和图像中的偶然数值不作为指针。实际构建及重定位复核结果如下。

四版完整 8 MiB ROM 已通过 WSL `make -j4 compare`，并再次逐字节确认与原版一致：

| 版本 | SHA-1 | 新增实际重定位位置 |
| --- | --- | ---: |
| JP | `a655b2789aed14a6ac78c6075fbc533d3062dbe3` | 4,087 |
| US | `a2fc3574f0a65a4fcf7682fb274b9d7eebdef963` | 103 |
| EU | `7ba1ec1e46ce424e3c6fd72e4e8d5e9eb5ede247` | 111 |
| DE | `60f2a30b55c0e32754897b4d5df6ce06f8b71a37` | 111 |

最终输入对象的重定位已与基线逐项对照：移除的旧条目只有原先把真实指令错写为
`__ewram_bss_end` 指针的 11 处，以及 JP 同函数内部、现在直接局部解析的 11 处
长跳转。其余原有调用和数据引用均保留；新增重定位数不等于独立对象数或完成率。

验证阶段纠正了 GNU Thumb 语法、五个内部跳表目标的错误函数标记，以及静态候选
误判成池字的七条原有 JP 指令。最终 ELF 的代码段数据标记再次核对后，除真实池字、
符号重定位和零填充外，每版仅有三个已知数据块：随机数常量 8 字节、精灵尺寸表
24 字节、IWRAM 随机种子初值 4 字节；均不是隐藏指令。

JP `0803A518–0803A634` 的实体函数尾部、池字及相邻方法原先跨文件截断，现归回
`asm/code_entities_08034CEC.s`，与海外版归属一致；删除了位于函数中间的虚假入口
和 `0x3A518` LDS 定位。除此之外本轮不撤销其他固定起点。

保留的限制：

- `gUnk_0875B974` 是每版 132 字节的 SRAM 库后置数据。JP/US/EU/DE 地址分别为
  `0877F58C` / `0875B974` / `0875B9D0` / `0874BDB8`。已标清整体边界，尚无可靠
  用途和入向引用证据，原始字节完整保留，不猜测为指针表，也不计作已解析结构。
- `gUnk_087399C4` 的消费者复制 512 字节，而其下一个压缩资源在 160 字节之后
  开始。这段复制依赖两者的连续物理内容，不能只凭两个标签就允许独立扩缩。
- JP 31 处、海外每版 3 处共享控制流调用之后的两字节零值暂保留；其中存在以
  BL 回到同一栈帧主循环的长跳转。它们不计为未恢复函数，也未假设每个 BL 都返回。
- 除上述错误的函数中间切点外，保留当前 LDS 定位。整 ROM 原址匹配与完全可动态
  布局是两项不同结论；
  原始尺寸依赖、上述未确定数据及尚未复核的链接约束仍需继续处理。

完整范围清单、字段分类、引用核对和不可变基线保存在本任务外部审计目录
`full-rom-batch-b83ab375`，临时分析脚本不进入正式编译链。

## 当前优先目标：完整边界与动态链接（2026-11-04）

按 ROM 地址优先处理仍包在字节里的代码和数据。JP 矿层生成、下楼及两个脚本分支合计恢复 129 条 Thumb 指令（274 字节）；五项跳表和两个脚本调用现用真实标签。四版原位匹配。此项增加汇编覆盖，新增 C/C++ 代码字节为零。

世界绘制四版共用一份汇编。JP 恢复 705 条指令（1,454 字节），30 项地图跳表及其目标全部以符号表示。四张农舍表已按实际读取宽度表示为图块坐标和实体坐标。

地图切换与受阻实体重定位在 JP 共恢复 407 条指令（848 字节）。两张 41 项跳表的表项、基址和分派上界都由标签决定，坐标表按三种农舍布局选取。四版共用实际指令。

昼夜调色板更新在 JP 恢复 845 条指令（1,716 字节）。五项天气分派、七个混合函数指针和四个外部调用均已验证。

实体槽刷新已将 94 项分派表改为直接引用 58 个真实标签。该函数在 JP 增加 772 条明示指令，US/EU/DE 各增加 674 条；JP 三个畜禽构造入口另恢复 86 条。

相邻的碰撞框实体选择函数已并入实体槽模块，JP 另恢复 107 条指令（216 字节）。当时已辨认的后续裸代码为精灵调色板设置，JP 0801B77C、US 0801B9E8、EU 0801B9FC、DE 0801B8FC，各版仍含原始代码。

按物理地址复查时，在先前记录的精灵调色板函数之前发现了 JP 参赛动物查询的裸指令。
随其脚本调用恢复的 JP 汇编覆盖如下。海外三版对应指令原已是汇编，本批新增 C/C++ 指令为零。

| JP 原始字节所在范围 | 恢复指令 | 恢复的指令字节 |
| --- | ---: | ---: |
| 参赛动物查询 | 47 | 98 |
| 脚本命令 0x03E、0x119、0x11A 及其共用入栈段 | 91 | 200 |
| 恋爱事件更新 | 541 | 1,102 |
| 脚本变量写入 | 6,771 | 14,418 |
| 合计 | 7,450 | 15,818 |

已确认四个入口的外部直接调用，并核对两张动物表、两张脚本变量表的所有分支目标。
原址四版逐字节一致。按地址接续时，首先复核 JP 启动中断对象 080004C4 的固定定位，
然后继续检查中间的常量池、跳表与未分类数据。精灵调色板仍是后续已知的裸代码候选。

按物理顺序回查启动段后，JP 的 SRAM 镜像起点现由 main 的末端决定。四版每版
11 条外部直接调用均有真实重定位；本次只修改 JP 定位并比对完整 JP ROM，
汇编和 C/C++ 的新增指令为零。


启动中断、分配运行库和纯虚入口的 376 字节已按顺序自然链接。JP 原有 080004C4 固定定位已移除。
核对每版 44 个 IRQ 调用、1,049（JP）或 1,050（海外）个分配调用，并逐项确认 266 个纯虚函数指针。
本块增加引用覆盖，新增汇编及 C/C++ 指令为零。下一处 JP 固定起点是 SRAM 读写 0800063C。

SRAM 读写对象也已移除 JP 固定定位，22 个外部调用和 18 个对象内重定位已核对。
本块增加引用覆盖，汇编和 C/C++ 新增指令均为零。

从场景主循环到硬件输入的 68 个连续输入段已复核。四版各有 80 个指向其中的绝对指针，
跨输入段直接调用分别为 JP 5,124、US/EU/DE 各 5,139。JP 场景主循环现紧随上一对象，
WSL 原位整 ROM 比对通过。

接着核对的硬件混合与显示对象尾部占九个输入段、1,864 字节，四版各有 24 个回调
指针。移除 JP 的 08009308 定位后，整 ROM 比对通过。下一处普通代码固定起点为
Farm 的 JP 08009A50。以上两块增加边界和引用覆盖，新增汇编及 C/C++ 指令均为零。

Farm 入向调用追踪已恢复小精灵更新回调。US/EU/DE 每版新增 521 条真实指令
（1,112 字节）和 35 处调用重定位，JP 同函数原本已是汇编。四版共用
`asm/harvest_sprite_actor.s`，完整 ROM 逐字节一致，新增 C/C++ 字节为零。
海外进入 Farm 的 73 处直接调用均已符号化；JP 还剩 19 处，下一步补齐这些必要依赖，
因此顺序游标仍为 JP 08009A50，未移除该起点。

脚本变量读取已整体共用：JP 新增 4,057 条汇编指令（8,968 字节）、48 处实际外部
调用和 592 个地址重定位；海外三版同层级，四版 ROM 逐字节匹配。新增 C/C++ 字节
为零。Farm 剩余的 JP 未绑定调用为 14 处；命令分派本身也有一处对 VarGet 的裸调用，
作为下一项必要依赖处理，主顺序游标不变。

原生命令分派也已整体恢复并四版共用：JP 新增 8,868 条汇编指令（19,242 字节），
新增 259 个真实外部调用及 262 个地址重定位。四版的 17 张分派表及 525 个外部调用
均从源码产生，完整 ROM 逐字节一致，新增 C/C++ 字节为零。Farm 剩余 JP 未绑定调用
为 11 处，分属赛马核心构造和木工商店主循环，顺序游标仍为 JP 08009A50。

顺着场景主循环查到的赛马购券画面已合并为四版共用的汇编。JP 的四个固定资源地址
现分别引用两张图标的图块和色板；DE 同一张 128 字节图块和 32 字节色板改从已有图源生成。
四版完整 ROM 均与原版逐字节一致。原有 408 条指令已是汇编，此块新增指令数为零。

继续追踪图标的另外两个固定地址，已恢复 12 个商店共用的显示初始化。JP 新增
1,095 条可读 Thumb 指令（2,246 字节）、28 处调用重定位和 2 处图形重定位。
三份海外版原有相应的指令和引用。四版均逐字节匹配，此块新增 C/C++ 指令为零。

硬件常量补正：对照本地 pokeemerald，将已确认的 C/C++ 显示/OAM、输入、
中断、UI/地图/精灵上传及 m4a 固定槽改用集中宏；保留真实访问宽度。
四版 WSL -j4 compare 与 SHA-1 通过。仅源码表达修正，没有新增 C/C++
恢复字节或扩大动态引用闭合范围，LDS 和顺序接续位置不变。

后续补齐四份汇编的 159 个 BG/OBJ 调色板地址字，并复核启动和声音 DMA 的寄存器偏移。
这些均属平台固定地址命名，不计入 ROM 对象重定位或 C/C++ 恢复量。

本批核对手写汇编的 276 个 OBJ 地址常量和 JoyBus、BIOS 调用中的寄存器，
以命名常量表示平台固定地址，JP JoyBus 的四条指令从原始字节恢复为汇编。

开场背景的 17 处显示寄存器影子写入已按实际寄存器命名。开场与 UI 中的 16 个 VRAM 常量池项已区分图块和屏幕块，场景的显示与淡入淡出控制位也已核对。

逐块审阅 LDS 的上次位置为硬件混合效果模块。JP 起点 `08009308`、US `08009300`、
EU `08009314`、DE `08009320`。前一块的按键采样、构造与连发计时合并为
`hardware_input.cc`，13 个入口共 468 字节。此项整理了已有高级语言代码和
调用关系，新增高级语言覆盖为零。此前核实的 9 个前部 DMA 入口共 772 字节。

已核对声音命令、播放器与歌曲接口每版
47 个函数和 2 张虚表，共 880 字节。JP 的两个原始虚表指针现为符号引用。
本批沿用已有 C/C++ 函数，增加的是已核实的边界和引用。
DMA 后置写入与整数除模已拆为两个四版共享的汇编对象。补出 JP 34 处、
海外各 1 处原始 BL。该项计入汇编边界与调用重定位，新增 C/C++ 覆盖为零。

音频目录每版 211 项已绑定 145 个真实歌曲头，其中一个为空头。
144 个非空头的 277 个轨道入口与 144 个声部表引用已在原位校验。
四版共用同一份乐谱源码，每版 1,541 个轨道控制流指针已绑定到本轨标签；
音符等事件继续以字节码存放。本项计入资源引用恢复。

IWRAM 声音混音器的末尾常量已计入装载函数边界，已核实执行所需的
`0x3A4` 字节与原版初始化复制的 `0x400` 字节。

从 `30d912e5` 开始，优先审计四版整个 ROM 的代码/数据边界和布局依赖。
已有 C/C++ 比例保持不变；可从源码构建及原版匹配不代表已经能够自由移动内容。
本轮确认仍有隐藏机器指令、错误重定位、音频内部原始指针、固定偏移标签及
资源计数/容量约束。完整目标、证据、验收与接续清单见
[RELOCATION_AUDIT.md](RELOCATION_AUDIT.md)。

顺序处理已完成启动块 `0x08000000–0x0800018C`：标准头与普通启动代码分节，
三个函数、常量池和填充边界明确；四版原位 ROM/符号地址一致。JP main 前的
固定定位已移除。随后已核查 `src/main.cc` 的两个 C++ 函数入口、17 个调用和
2 个回调引用，并统一软复位 IRQ 的语义命名；四版原位 compare 通过。
随后核查现有 SRAM 的 8 个 C++ 函数和已确认调用，整理中断所依赖的 IWRAM
入口与常量池边界，四版原位 compare 通过。随后核查 new、pure_virtual 和
sram_access 共 616 字节：两个分配回调独立命名/声明，SRAM 计时器交换入口
采用语义名和函数指针类型，纯虚钩子的每版 254 个虚表引用保持；四版 compare
通过。随后 scene 的 296 字节现有 C++、两张基类虚表和实际保留引用已审阅，
保留实现并跳过改写。随后 intro_scene 前部十一函数（八个 C++、三个 Thumb）
及已恢复引用完成核对，核心虚表按用途命名，归档七表数量由边界推导。
现已以实际 archive.bin 长度驱动同一个内嵌缓冲区，恢复 129 个汇编池偏移和
10 个移位偏移与真实字段的关系；sizeof 分配联动。原版 0x6A00 作为存储下限，
不再作为增长上限。四版原位 compare、函数地址及生成头依赖检查通过。
2707 个 intro 入向数值窗口全部分类，无新增裸指针；每版仅两条已符号化的
外部直接分支。JP 起点 0x914 锚已移除并复验通过，下一主题与后部表区仍保留
原有限制。启动至开场的明确硬件地址/位值也已按实际 GBA 定义整理。
本次不增加 C/C++ 字节覆盖，不进行移址或资源扩展编译测试；资源索引及后续
块仍需继续恢复。随后进入 new_game_menu：JP `080037A8`、US `08003788`、
EU/DE `0800379C`。

new_game_menu 已共用运行汇编（只在四个响应文本指针处区分地区），实际资源
长度驱动上传/分配，归档计数由边界推导；共享 UI palette 长度归属及姓名
一基数组引用的跨对象依赖已修正。JP 相应成绩显示和字形 helper 的 1668B
均有明确指令/池/对齐表示，新展开 523 条机器码指令；这不是新增 C/C++ 覆盖。
四版原位 compare、关键符号/重定位/生成头依赖通过。菜单数值候选 533 项
及直接分支入边已核清，未扩大为整个 ROM 的完成率。JP 锚保留以隔离未审阅
后续块；下一主题为 new_game_name_entry：JP 08004C60、US 08004C48、EU/DE 08004C5C。

随后核查 name_entry 三项既有 C++ 入口及 identity 十二项入口，已知入向
调用、switch 表、虚表和数值候选已分类。本轮让 identity 原生汇编与 C++
缓冲模板共享宽高等尺寸，并以 `sizeof` / `offsetof` 校验 RAM 成员、缓冲
步长和上传量的对应；未新增布局工具。初始化的 C++ 草稿尚未匹配，代码
覆盖不增加。本轮原位验证：四版 WSL make -j4 compare 全部通过，原版 SHA-1 一致，汇编依赖文件均追踪共享头。背景仍依赖
JP 狗名标签第二字、海外首标签第五字的空格；四业务字段、两 tile 高及
`FixedStr<12>/<15>` 等真实限制保留，不能称为任意扩容。下一主题 name_input；
保留后续 LDS 锚点，不标记完全动态布局。详见 CODE_ROM_LAYOUT.md 与
RELOCATION_AUDIT.md。

name_input 已完成同等审阅：四版分别 6148/5840/5840/5852 字节，每版 19 个
既有 C++ 函数加 2 个原生汇编入口。修正 DE 九处数字 PC 常量池读取，关联
字符页/行、buffer 步长、成员偏移及 tilemap 图块索引，补齐已知 IO/内存/
按键/OAM 宏。251 个数值候选和已知调用/虚表引用已分类；原版四版 -j4
compare 及依赖检查通过。JP 菜单 0x37A8 锚已取消，0x7130 hardware 锚仍
保留；下一主题 hardware（JP 08007130、US 08007128、EU 0800713C、DE
08007148）。本轮 C/C++ 覆盖不增加，真实屏幕/存档格式约束仍保留，未做
移址或扩容测试。

此前启动至 scene 的既有数值候选已完成字段/资源分类，没有发现新的裸指针；尚未恢复
代码的入向分支仍需继续核查，后续固定定位保留。这些块不增加 C/C++ 字节
覆盖；下方统计仍为注明基线的历史快照。

按最新要求，后续参考本地 pokeemerald，使用源码引用核查和受影响版本原位
构建比对，不再做移址验证。不发布未经证实的“全部指针动态化”比例，也不因
`.byte` 被写成数组就计为布局问题已解决。


统计基准：2026-11-04 通过四版验证的源码，含本次 `GameSceneWorldData` 构造恢复。
其源代码基线为 `7fd534adcd54c1781c5061245d019ea1a2bcbc87`；本报告与该函数恢复一同提交。

这是一份已经核对实际链接产物的快照。四版 ROM 的 SHA-1 均与仓库中的
`fomt_<region>.sha1` 一致；另逐字节核对用于统计的 ELF 全部 ROM 加载内容，
仅排除由 gbafix 写入的标准 192 字节 ROM 头。后续源码提交不会自动刷新此快照。

## 多维总览

| 指标 | JP | US | EU | DE |
| --- | ---: | ---: | ---: | ---: |
| C/C++ 代码布局字节覆盖 | 19.99% | 19.99% | 19.99% | 19.99% |
| 已标记函数入口的 C/C++ 覆盖 | 55.56%（2,192/3,945） | 55.76%（2,196/3,938） | 55.76%（2,196/3,938） | 55.76%（2,196/3,938） |
| 完整 C/C++ 代码输入单元 | 82.43%（183/222） | 82.43%（183/222） | 82.43%（183/222） | 82.43%（183/222） |
| `.rodata` 中 C/C++ 数据对象所占字节 | 3.04% | 3.00% | 3.00% | 3.16% |
| BSS 布局的 C/C++ 对象声明覆盖 | 99.81%（9,103/9,120） | 99.81%（9,103/9,120） | 99.81%（9,103/9,120） | 99.81%（9,103/9,120） |
| 原版 ROM 字节/SHA-1 验证 | 通过 | 通过 | 通过 | 通过 |

这些指标采用不同的计数单位，分别观察大函数、小函数、源代码组织、数据表示和
静态 RAM 布局，不能相加或平均。代码字节覆盖仍是主要指标。原版匹配验证说明
构建保留了原有行为和布局，不表示 C/C++、数据语义或可重定位引用均已恢复。

### 函数入口与代码输入单元的规则

- 函数分母取当前 ELF 中落在实际代码范围内的 `STT_FUNC` 已标记入口，按实际地址
  去重；分子取已确认的 C/C++ 函数入口。未标记或边界不明的代码不猜测为若干函数，
  因而这是现有入口目录的覆盖率，后续补标入口时分母也会更新。

- 一个代码输入单元是实际向链接结果提供代码的一个 `.o` 或库成员，不等同于一个
  完整游戏功能。判为完整 C/C++ 时，要求其全部已标记入口均已计入 C/C++，所有代码
  输入字节均由这些函数体覆盖，剩余空间只能是经字节检查确认的 4 字节边界零填充
  （每处 1–3 字节）。目前每版均为 183 个完整输入单元、2 个混合输入单元和
  37 个尚无计入 C/C++ 函数的代码输入单元。两个混合单元是含 `NAKED` 实现的
  `npc_entity.o`、`rucksack.o`。

大型未恢复汇编集中在少数输入对象中，所以输入单元比例明显高于代码字节比例；
不能用 82.43% 代替全项目的 C/C++ 字节覆盖率。

此前把 6,344 字节世界绘制归入独立汇编对象，使实际输入单元从 221 增至 222。
本批在已有世界运行时对象内恢复 488 字节 C++，输入对象总数保持 222；
因此完整输入单元维度仍为 183/222。函数字节与入口覆盖已据实际产物增加。

## C/C++ 代码覆盖

| 区域 | 已确认的 C/C++ 函数体字节 | 代码布局总字节 | 覆盖率 | 已统计函数区间 |
| --- | ---: | ---: | ---: | ---: |
| JP | 187,796 | 939,388 | 19.99% | 2,192 |
| US | 188,358 | 942,396 | 19.99% | 2,196 |
| EU | 188,378 | 942,472 | 19.99% | 2,196 |
| DE | 188,398 | 942,240 | 19.99% | 2,196 |

分子按真实编译的 C/C++ 函数符号大小累计，并对物理区间去重。函数体包含其编译器
生成的常量池，函数之外的对齐不计入分子；同址别名、弱定义及重复模板不会重复计数。
归属同时用链接 map 的实际输入范围和原始 `.c` / `.cc` 文件核对，不能仅按 `src/` 目录判断。
当前源码中的文件级汇编没有手工 `.size` 指令；两个具有编译器函数大小的 `NAKED`
汇编实现也已排除：`npc_entity.cc` 的 `func_08034F00`（1,152 字节）和
`rucksack.cc` 的 `Rucksack::Upgrade`（634 字节）。

分母是 `.text` 输出段扣除标准 ROM 头，加上 IWRAM 加载代码；扣除 IWRAM 中已识别的
24 字节精灵尺寸只读表。代码布局仍包含未恢复代码、常量池及对象间填充，因此这是
**代码布局的高级语言覆盖率**，并非逐条指令的识别率。原生汇编、SDK 和运行库仍在
此总分母内，未通过排除它们提高比例。尚无可靠大小的函数不猜测计入分子。

四版有 2,191 个共同的已统计函数标识。海外另有四个高字形数字绘制命令相关函数及
一个单参数场景构造函数；JP 另有一个单独链接的精灵访问器。数量差异同时受实际
区域实现和内联/链接选择影响，不能单凭总数判断四版解析层级。

## 段大小与数据审计状态

| 区域 | `.text` 输出字节（含 ROM 头） | IWRAM 输出字节（含 24 字节只读表） | `.rodata` 字节 | `.data` 字节 | EWRAM BSS 字节 | IWRAM BSS 字节 |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| JP | 937,484 | 2,120 | 6,924,292 | 0 | 7,952 | 1,168 |
| US | 940,492 | 2,120 | 6,774,828 | 0 | 7,952 | 1,168 |
| EU | 940,568 | 2,120 | 6,774,844 | 0 | 7,952 | 1,168 |
| DE | 940,336 | 2,120 | 6,710,540 | 0 | 7,952 | 1,168 |

当前 ELF 没有独立、非空的 `.data` 输出段。BSS 是 RAM 占用，不加到 ROM 字节分母中；
ROM 尾部 `.pad` 也不属于待反编译代码。

数据暂不发布“结构恢复完成率”或“指针已全部动态化”百分比。普通数组的源码化、
结构字段的语义恢复、图片/压缩资源的可编辑重建、Mary 脚本编译、引用的符号化是
不同指标，需要各自的范围审计；把原始数据写成 C 数组不足以证明这些工作完成。

### 数据对象与 BSS 的计数

| 区域 | `.rodata` 中 C/C++ 对象字节 / 段总字节 | 已声明 IWRAM 只读对象字节 / 总字节 | 已声明 EWRAM BSS 字节 / 总字节 | 已声明 IWRAM BSS 字节 / 总字节 |
| --- | ---: | ---: | ---: | ---: |
| JP | 210,223/6,924,292 | 24/24 | 7,952/7,952 | 1,151/1,168 |
| US | 203,356/6,774,828 | 24/24 | 7,952/7,952 | 1,151/1,168 |
| EU | 203,360/6,774,844 | 24/24 | 7,952/7,952 | 1,151/1,168 |
| DE | 211,790/6,710,540 | 24/24 | 7,952/7,952 | 1,151/1,168 |

对象分子取位于实际分配节内、具有真实大小且归属 C/C++ 源码的 `STT_OBJECT` 物理
范围并集；排除调试节、未链接定义、重复别名和对象外填充。未给出可靠大小的对象
不猜测计入。代码、数据和 BSS 分别计算，RAM 对象不加入 ROM 分母。

这项统计衡量**数据的 C/C++ 表示方式**，不证明每个字段已经语义化，也不证明
所有引用都已动态化；原始字节的 C 数组也属于对象声明。图像转换产物和 Mary
字节码属于其他源码表示，未计入这个 C/C++ 分子，不能据 3% 推断其余图像或脚本
尚未提取。所有静态 RAM 声明也不等于其中每个缓冲区的含义已经完全恢复。

### objdiff 对象比较

已安装并实际运行官方 [objdiff CLI 3.8.3](https://github.com/encounter/objdiff/releases/tag/v3.8.3)。
工具位于仓库外，发布二进制的 SHA-256 已核对官方元数据；未加入 ROM 构建链。
比较保留的原始汇编可重定位 `.o` 与实际编译的 C++ `.o`。

| 已验证函数 | objdiff 近似匹配（fuzzy） | 完整字节匹配 | 是否计入完成量 |
| --- | ---: | --- | --- |
| `func_08017C30` → `GameSceneWorld::Update` | 99.99% | 四版完整 1,688 字节通过 | 是 |
| `func_0803B128` → `GameSceneWeatherEffect::PrepareResources` | 100.00% | 四版完整 384 字节通过（382 字节函数体 + 2 字节对齐） | 是，仅函数体 |
| `WorldSpriteEffects::Draw` | 100.00% | 四版完整 636 字节通过 | 是 |
| `GameSceneWorldData::~GameSceneWorldData` | 100.00% | 四版完整 272 字节通过 | 是 |
| `GameSceneWorldData::GameSceneWorldData` | 100.00% | 四版完整 488 字节通过 | 是 |

这里保留工具实际给出的近似评分；正式验收使用四版完整 ROM 字节、SHA-1、符号、
输入区间及重定位校验，均已通过。`GameSceneWorld::Update` 的原汇编入口在 objdiff 中为 1,686 字节；
本工程核对并链接的完整原生范围为 1,688 字节。两个范围分别记录，不把近似评分
当作逐字节相同比例或全项目完成率，也不发布缺少完整候选对象的全项目 fuzzy 值。

## 当前推进位置

世界逐帧更新已恢复为四版共用 `GameSceneWorld::Update`，每版完整 1,688 字节，
现已计入上面的 C/C++ 分子。下一 C++ 恢复目标为 US `0x080182C8` 的 `GameSceneWorld::Draw`（仍为汇编）。
ROM 中已有分散于后续功能模块的恢复内容，当前推进地址不能换算成全项目百分比。

世界主绘制的 6,344 字节仍在 `asm/world_draw.s`。前一批已将其实际调用的
`WorldSpriteEffects::Draw` 恢复为四版共用 C++：每版完整 636 字节，合计
2,544 字节；每版两处入口调用均为符号重定位。原有 74 处绘制相关入口引用
的类型整理保持，主绘制 C++ 工作稿仍在仓库外匹配，未计入正式完成量。

世界数据析构已于前一批恢复，每版 272 字节。本批完成其配套构造函数，
共用 C++ 每版 488 字节，四版合计 1,952 字节，已计入正式完成量。地图所有权
转移、二十二项调色板记录、十三个硬件槽及十三个资源归档由成员构造初始化；
实体指针数组依原顺序最后清零。世界主绘制及尚未字节匹配的调色板获取草稿
仍不计入完成量。
实际 ROM 地址、类型证据和重定位核查见 [CODE_ROM_LAYOUT.md](CODE_ROM_LAYOUT.md)。

## 按实际源模块分布

以下数值是各模块已经确认的 C/C++ 函数体字节，不是该模块的完成百分比。模块的
其他函数可能仍在原汇编对象中；没有经过完整归属审计前，不使用单个 `.o` 的大小
充当该功能模块的总分母。表内按 US 的首个函数地址排序，IWRAM 排序模块单独置末。
已更名或合并的模块按当前文件归属展示，函数体字节仍沿用上述统计基线。

| 源模块 | JP 字节 | US 字节 | EU 字节 | DE 字节 |
| --- | ---: | ---: | ---: | ---: |
| [src/main.cc](src/main.cc) | 340 | 340 | 360 | 360 |
| [src/sram_image.cc](src/sram_image.cc) | 478 | 478 | 478 | 478 |
| [src/interrupt.c](src/interrupt.c) | 186 | 186 | 186 | 186 |
| [src/new.cc](src/new.cc) | 202 | 202 | 202 | 202 |
| [src/pure_virtual.c](src/pure_virtual.c) | 2 | 2 | 2 | 2 |
| [src/sram_access.cc](src/sram_access.cc) | 428 | 428 | 428 | 428 |
| [src/scene.cc](src/scene.cc) | 294 | 294 | 294 | 294 |
| [src/intro_scene.cc](src/intro_scene.cc) | 5,404 | 5,404 | 5,404 | 5,404 |
| [src/new_game_menu.cc](src/new_game_menu.cc) | 3,242 | 3,242 | 3,242 | 3,242 |
| [src/new_game_name_entry.cc](src/new_game_name_entry.cc) | 1,010 | 1,010 | 1,010 | 1,010 |
| [src/new_game_identity.cc](src/new_game_identity.cc) | 1,574 | 1,486 | 1,486 | 1,486 |
| [src/new_game_name_input.cc](src/new_game_name_input.cc) | 4,034 | 3,738 | 3,738 | 3,738 |
| [src/obj_palette_pool.cc](src/obj_palette_pool.cc) | 1,132 | 1,132 | 1,132 | 1,132 |
| [src/obj_palette_collection.cc](src/obj_palette_collection.cc) | 826 | 826 | 826 | 826 |
| [src/obj_tile_bitmap.cc](src/obj_tile_bitmap.cc) | 148 | 148 | 148 | 148 |
| [src/obj_tile_pool.cc](src/obj_tile_pool.cc) | 3,842 | 3,842 | 3,842 | 3,842 |
| [src/obj_tile_collection.cc](src/obj_tile_collection.cc) | 450 | 450 | 450 | 450 |
| [src/hardware_context.cc](src/hardware_context.cc) | 1,092 | 1,092 | 1,092 | 1,092 |
| [src/hardware_display_commands.c](src/hardware_display_commands.c) | 164 | 164 | 164 | 164 |
| [src/hardware_state_accessors.c](src/hardware_state_accessors.c) | 174 | 174 | 174 | 174 |
| [src/hardware_manager.cc](src/hardware_manager.cc) | 868 | 868 | 868 | 868 |
| [src/hardware_sound.cc](src/hardware_sound.cc) | 118 | 118 | 118 | 118 |
| [src/hardware_music_player.cc](src/hardware_music_player.cc) | 452 | 452 | 452 | 452 |
| [src/hardware_song.cc](src/hardware_song.cc) | 234 | 234 | 234 | 234 |
| [src/hardware_dma.c](src/hardware_dma.c) | 226 | 226 | 226 | 226 |
| [src/hardware_dma_descriptor.cc](src/hardware_dma_descriptor.cc) | 538 | 538 | 538 | 538 |
| [src/hardware_input.cc](src/hardware_input.cc) | 460 | 460 | 460 | 460 |
| [src/hardware_blend.cc](src/hardware_blend.cc) | 172 | 172 | 172 | 172 |
| [src/hardware_blend_object.cc](src/hardware_blend_object.cc) | 200 | 200 | 200 | 200 |
| [src/hardware_interrupt_guard.cc](src/hardware_interrupt_guard.cc) | 396 | 396 | 396 | 396 |
| [src/hardware_display_state.cc](src/hardware_display_state.cc) | 148 | 148 | 148 | 148 |
| [src/hardware_sprite_buffer.cc](src/hardware_sprite_buffer.cc) | 356 | 356 | 356 | 356 |
| [src/hardware_linked_list.cc](src/hardware_linked_list.cc) | 410 | 410 | 410 | 410 |
| [src/farm.cc](src/farm.cc) | 2,226 | 2,226 | 2,226 | 2,226 |
| [src/field.cc](src/field.cc) | 4,374 | 4,414 | 4,414 | 4,414 |
| [src/shipping_bin.cc](src/shipping_bin.cc) | 512 | 512 | 512 | 512 |
| [src/tool_chest.cc](src/tool_chest.cc) | 870 | 870 | 870 | 870 |
| [src/fridge.cc](src/fridge.cc) | 628 | 628 | 628 | 628 |
| [src/shelf.cc](src/shelf.cc) | 622 | 622 | 622 | 622 |
| [src/record_player.cc](src/record_player.cc) | 244 | 244 | 244 | 244 |
| [src/furniture.cc](src/furniture.cc) | 530 | 530 | 530 | 530 |
| [src/farm_house.cc](src/farm_house.cc) | 1,460 | 1,460 | 1,460 | 1,460 |
| [src/coop.cc](src/coop.cc) | 2,556 | 2,556 | 2,556 | 2,556 |
| [src/barn.cc](src/barn.cc) | 3,632 | 3,634 | 3,634 | 3,634 |
| [src/item.cc](src/item.cc) | 1,940 | 1,940 | 1,940 | 1,940 |
| [src/time_of_day.cc](src/time_of_day.cc) | 182 | 182 | 182 | 182 |
| [src/farmer.cc](src/farmer.cc) | 3,630 | 3,630 | 3,630 | 3,630 |
| [src/rucksack_item.cc](src/rucksack_item.cc) | 378 | 378 | 378 | 378 |
| [src/held_item.cc](src/held_item.cc) | 1,016 | 1,016 | 1,016 | 1,016 |
| [src/rucksack.cc](src/rucksack.cc) | 2,460 | 2,460 | 2,460 | 2,460 |
| [src/more_items.cc](src/more_items.cc) | 148 | 148 | 148 | 148 |
| [src/game_scene.cc](src/game_scene.cc) | 5,624 | 5,896 | 5,896 | 5,896 |
| [src/game_state.cc](src/game_state.cc) | 3,724 | 3,724 | 3,724 | 3,724 |
| [src/entity_location.cc](src/entity_location.cc) | 1,302 | 1,302 | 1,302 | 1,302 |
| [src/scene_audio.cc](src/scene_audio.cc) | 360 | 360 | 360 | 360 |
| [src/scene_dialogue.cc](src/scene_dialogue.cc) | 1,054 | 1,054 | 1,054 | 1,054 |
| [src/scene_supermarket.cc](src/scene_supermarket.cc) | 586 | 586 | 586 | 586 |
| [src/scene_won_shop.cc](src/scene_won_shop.cc) | 332 | 332 | 332 | 332 |
| [src/scene_carpenter_shop.cc](src/scene_carpenter_shop.cc) | 336 | 336 | 336 | 336 |
| [src/scene_blacksmith_shop.cc](src/scene_blacksmith_shop.cc) | 950 | 950 | 950 | 950 |
| [src/scene_clinic_shop.cc](src/scene_clinic_shop.cc) | 396 | 396 | 396 | 396 |
| [src/scene_beach_cafe_shop.cc](src/scene_beach_cafe_shop.cc) | 396 | 396 | 396 | 396 |
| [src/scene_yodel_ranch_shop.cc](src/scene_yodel_ranch_shop.cc) | 454 | 454 | 454 | 454 |
| [src/scene_winery_shop.cc](src/scene_winery_shop.cc) | 396 | 396 | 396 | 396 |
| [src/scene_inn_shop.cc](src/scene_inn_shop.cc) | 396 | 396 | 396 | 396 |
| [src/scene_poultry_farm_shop.cc](src/scene_poultry_farm_shop.cc) | 552 | 548 | 548 | 548 |
| [src/scene_special_merchant_shop.cc](src/scene_special_merchant_shop.cc) | 396 | 396 | 396 | 396 |
| [src/scene_gift_wrapping.cc](src/scene_gift_wrapping.cc) | 396 | 396 | 396 | 396 |
| [src/scene_reference_page.cc](src/scene_reference_page.cc) | 774 | 774 | 774 | 774 |
| [src/scene_calendar.cc](src/scene_calendar.cc) | 412 | 412 | 412 | 412 |
| [src/scene_shelf.cc](src/scene_shelf.cc) | 396 | 396 | 396 | 396 |
| [src/scene_tool_chest.cc](src/scene_tool_chest.cc) | 396 | 396 | 396 | 396 |
| [src/scene_refrigerator.cc](src/scene_refrigerator.cc) | 396 | 396 | 396 | 396 |
| [src/scene_clock.cc](src/scene_clock.cc) | 300 | 300 | 300 | 300 |
| [src/scene_cooking.cc](src/scene_cooking.cc) | 690 | 690 | 690 | 690 |
| [src/scene_gamecube_link.cc](src/scene_gamecube_link.cc) | 552 | 552 | 552 | 552 |
| [src/scene_harvest_sprite_minigames.cc](src/scene_harvest_sprite_minigames.cc) | 1,830 | 1,830 | 1,830 | 1,830 |
| [src/intro_story_scene.cc](src/intro_story_scene.cc) | 2,310 | 2,310 | 2,310 | 2,310 |
| [src/scene_rucksack.cc](src/scene_rucksack.cc) | 426 | 426 | 426 | 426 |
| [src/town_map.cc](src/town_map.cc) | 690 | 690 | 690 | 690 |
| [src/animal_festival.cc](src/animal_festival.cc) | 380 | 380 | 380 | 380 |
| [src/staff_credits.cc](src/staff_credits.cc) | 582 | 582 | 582 | 582 |
| [src/farming_tutorial.cc](src/farming_tutorial.cc) | 744 | 744 | 744 | 744 |
| [src/name_entry.cc](src/name_entry.cc) | 744 | 744 | 744 | 744 |
| [src/scene_chicken_festival.cc](src/scene_chicken_festival.cc) | 810 | 810 | 810 | 810 |
| [src/scene_horse_race.cc](src/scene_horse_race.cc) | 706 | 706 | 706 | 706 |
| [src/scene_frisbee.cc](src/scene_frisbee.cc) | 462 | 462 | 462 | 462 |
| [src/frisbee_scoreboard.cc](src/frisbee_scoreboard.cc) | 688 | 688 | 688 | 688 |
| [src/world_creation.cc](src/world_creation.cc) | 1,930 | 1,930 | 1,930 | 1,930 |
| [src/farm_terrain.cc](src/farm_terrain.cc) | 532 | 532 | 532 | 532 |
| [src/game_world.cc](src/game_world.cc) | 4,736 | 4,736 | 4,736 | 4,736 |
| [src/world_control.cc](src/world_control.cc) | 298 | 298 | 298 | 298 |
| [src/world_update.cc](src/world_update.cc) | 1,688 | 1,688 | 1,688 | 1,688 |
| [src/world_lighting.cc](src/world_lighting.cc) | 124 | 124 | 124 | 124 |
| [src/world_audio.cc](src/world_audio.cc) | 616 | 616 | 616 | 616 |
| [src/world_furniture.cc](src/world_furniture.cc) | 252 | 252 | 252 | 252 |
| [src/world_map_sprites.cc](src/world_map_sprites.cc) | 784 | 784 | 784 | 784 |
| [src/world_shipping.cc](src/world_shipping.cc) | 388 | 388 | 388 | 388 |
| [src/world_runtime.cc](src/world_runtime.cc) | 824 | 824 | 824 | 824 |
| [src/entity.cc](src/entity.cc) | 652 | 652 | 652 | 652 |
| [src/animal_response.cc](src/animal_response.cc) | 32 | 32 | 32 | 32 |
| [src/entity_audio.cc](src/entity_audio.cc) | 248 | 248 | 248 | 248 |
| [src/entity_actor.cc](src/entity_actor.cc) | 2,496 | 2,496 | 2,496 | 2,496 |
| [src/livestock_actor.cc](src/livestock_actor.cc) | 138 | 138 | 138 | 138 |
| [src/field_tool.cc](src/field_tool.cc) | 324 | 324 | 324 | 324 |
| [src/player_actor.cc](src/player_actor.cc) | 334 | 334 | 334 | 334 |
| [src/actor_facing.cc](src/actor_facing.cc) | 1,352 | 1,352 | 1,352 | 1,352 |
| [src/player_pedometer.cc](src/player_pedometer.cc) | 292 | 292 | 292 | 292 |
| [src/actor_terrain.cc](src/actor_terrain.cc) | 430 | 430 | 430 | 430 |
| [src/player_collection_events.cc](src/player_collection_events.cc) | 524 | 524 | 524 | 524 |
| [src/player_sprite.cc](src/player_sprite.cc) | 628 | 628 | 628 | 628 |
| [src/entity_sprite.cc](src/entity_sprite.cc) | 712 | 712 | 712 | 712 |
| [src/entity_ui.cc](src/entity_ui.cc) | 306 | 306 | 306 | 306 |
| [src/npc_entity.cc](src/npc_entity.cc) | 1,070 | 1,070 | 1,070 | 1,070 |
| [src/entity_event_effects.cc](src/entity_event_effects.cc) | 342 | 342 | 342 | 342 |
| [src/map_data.cc](src/map_data.cc) | 2,044 | 2,044 | 2,044 | 2,044 |
| [src/entity_auxiliary_sprites.cc](src/entity_auxiliary_sprites.cc) | 550 | 550 | 550 | 550 |
| [src/world_weather.cc](src/world_weather.cc) | 1,544 | 1,544 | 1,544 | 1,544 |
| [src/scene_text_variables.cc](src/scene_text_variables.cc) | 616 | 616 | 616 | 616 |
| [src/ui_text_window.cc](src/ui_text_window.cc) | 894 | 894 | 894 | 894 |
| [src/ui_position.cc](src/ui_position.cc) | 20 | 20 | 20 | 20 |
| [src/control_widget.cc](src/control_widget.cc) | 278 | 278 | 278 | 278 |
| [src/main_menu_widget.cc](src/main_menu_widget.cc) | 926 | 926 | 926 | 926 |
| [src/map_clock_status.cc](src/map_clock_status.cc) | 3,400 | 3,508 | 3,508 | 3,528 |
| [src/npc.cc](src/npc.cc) | 726 | 726 | 726 | 726 |
| [src/npc_collection.cc](src/npc_collection.cc) | 9,456 | 9,352 | 9,352 | 9,352 |
| [src/npc_schedule.cc](src/npc_schedule.cc) | 116 | 116 | 116 | 116 |
| [src/script_engine.cc](src/script_engine.cc) | 2,676 | 2,676 | 2,676 | 2,676 |
| [src/font_draw.cc](src/font_draw.cc) | 510 | 510 | 510 | 510 |
| [src/font.cc](src/font.cc) | 1,116 | 1,474 | 1,474 | 1,474 |
| [src/ui_state.cc](src/ui_state.cc) | 6,714 | 6,714 | 6,714 | 6,714 |
| [src/animal_festival_ranking.cc](src/animal_festival_ranking.cc) | 196 | 196 | 196 | 196 |
| [src/resource_archive.cc](src/resource_archive.cc) | 404 | 404 | 404 | 404 |
| [src/resource_handle.cc](src/resource_handle.cc) | 1,314 | 1,314 | 1,314 | 1,314 |
| [src/new_game.cc](src/new_game.cc) | 2,676 | 2,982 | 2,982 | 2,982 |
| [src/scroll_state.cc](src/scroll_state.cc) | 384 | 384 | 384 | 384 |
| [src/selection_state.cc](src/selection_state.cc) | 26 | 26 | 26 | 26 |
| [src/cooking_recipe_inventory.cc](src/cooking_recipe_inventory.cc) | 736 | 736 | 736 | 736 |
| [src/money_account.cc](src/money_account.cc) | 1,240 | 1,240 | 1,240 | 1,240 |
| [src/actor.cc](src/actor.cc) | 34 | 34 | 34 | 34 |
| [src/animal.cc](src/animal.cc) | 504 | 504 | 504 | 504 |
| [src/pet.cc](src/pet.cc) | 286 | 286 | 286 | 286 |
| [src/livestock.cc](src/livestock.cc) | 966 | 966 | 966 | 966 |
| [src/barn_animal.cc](src/barn_animal.cc) | 416 | 416 | 416 | 416 |
| [src/dog.cc](src/dog.cc) | 624 | 624 | 624 | 624 |
| [src/horse.cc](src/horse.cc) | 138 | 138 | 138 | 138 |
| [src/chicken.cc](src/chicken.cc) | 218 | 218 | 218 | 218 |
| [src/cow.cc](src/cow.cc) | 326 | 326 | 326 | 326 |
| [src/sheep.cc](src/sheep.cc) | 336 | 336 | 336 | 336 |
| [src/actor_runtime_data.cc](src/actor_runtime_data.cc) | 336 | 336 | 336 | 336 |
| [src/cursed_tool.cc](src/cursed_tool.cc) | 914 | 914 | 914 | 914 |
| [src/map_patch_flags.cc](src/map_patch_flags.cc) | 264 | 264 | 264 | 264 |
| [src/event_state.cc](src/event_state.cc) | 1,918 | 1,918 | 1,918 | 1,918 |
| [src/fishing_results_data.cc](src/fishing_results_data.cc) | 270 | 270 | 270 | 270 |
| [src/mine_floor.cc](src/mine_floor.cc) | 5,120 | 5,120 | 5,120 | 5,120 |
| [src/bachelorette.cc](src/bachelorette.cc) | 462 | 462 | 462 | 462 |
| [src/harvest_sprite.cc](src/harvest_sprite.cc) | 1,046 | 1,046 | 1,046 | 1,046 |
| [src/child.cc](src/child.cc) | 398 | 398 | 398 | 398 |
| [src/gotz.cc](src/gotz.cc) | 318 | 318 | 318 | 318 |
| [src/saibara.cc](src/saibara.cc) | 506 | 506 | 506 | 506 |
| [src/van.cc](src/van.cc) | 90 | 90 | 90 | 90 |
| [src/npc_locations.cc](src/npc_locations.cc) | 680 | 680 | 680 | 680 |
| [src/field_item_data.cc](src/field_item_data.cc) | 1,980 | 1,980 | 1,980 | 1,980 |
| [src/field_plot_position_rules.cc](src/field_plot_position_rules.cc) | 166 | 166 | 166 | 166 |
| [src/scene_sprite.cc](src/scene_sprite.cc) | 1,098 | 1,098 | 1,098 | 1,098 |
| [src/world_map.cc](src/world_map.cc) | 5,728 | 5,728 | 5,728 | 5,728 |
| [src/world_sprite_effects.cc](src/world_sprite_effects.cc) | 1,062 | 1,062 | 1,062 | 1,062 |
| [src/random.cc](src/random.cc) | 28 | 28 | 28 | 28 |
| [src/terrain_movement.cc](src/terrain_movement.cc) | 154 | 154 | 154 | 154 |
| [src/ui_text_stream.cc](src/ui_text_stream.cc) | 548 | 548 | 548 | 548 |
| [src/ui_vcount.cc](src/ui_vcount.cc) | 376 | 376 | 376 | 376 |
| [src/ui_quantity_selector.cc](src/ui_quantity_selector.cc) | 780 | 748 | 748 | 748 |
| [src/game_menu.cc](src/game_menu.cc) | 2,268 | 2,268 | 2,268 | 2,268 |
| [src/heap.cc](src/heap.cc) | 234 | 234 | 234 | 234 |
| [src/joy_bus.c](src/joy_bus.c) | 516 | 516 | 516 | 516 |
| [src/link_communication_data.cc](src/link_communication_data.cc) | 102 | 102 | 102 | 102 |
| [src/m4a.c](src/m4a.c) | 5,500 | 5,500 | 5,500 | 5,500 |
| [src/libsram.c](src/libsram.c) | 400 | 400 | 400 | 400 |
| [src/libc_string.c](src/libc_string.c) | 624 | 624 | 624 | 624 |
| [src/hardware_dma_link.cc](src/hardware_dma_link.cc) | 30 | 30 | 30 | 30 |
| [src/iwram_sort.cc](src/iwram_sort.cc) | 472 | 472 | 472 | 472 |

## 参考统计方法

- [pret/pokefirered calcrom.pl](https://github.com/pret/pokefirered/blob/master/.github/calcrom/calcrom.pl)：使用链接输入字节统计代码，数据另计。FoMT 另核验函数大小与源码归属，避免 `.cc` 内汇编被误算。
- [zeldaret/tww project.py](https://github.com/zeldaret/tww/blob/main/tools/project.py#L2032)：分别输出近似匹配（fuzzy）、精确匹配（matched）、已完成单元的链接代码（linked），并列出代码字节、函数、数据及文件数。本文分别记录这些维度中已经实际审计的项目，不将对象数比例当成 linked 代码字节比例。
- [objdiff 3.8.3 report.rs](https://github.com/encounter/objdiff/blob/v3.8.3/objdiff-cli/src/cmd/report.rs)：使用实际可重定位对象生成报告。本地已安装并用于上面的函数比较；它是反编译验证工具，不是 ROM 正式构建依赖。
