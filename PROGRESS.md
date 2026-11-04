# 反编译进度

## 当前优先目标：完整边界与动态链接（2026-11-04）

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

随后核查 name_entry 的三项既有 C++ 入口及 identity 的十二项入口；已知入向
调用、switch 表、虚表及数值候选均分类。确认画面及混合控制器补用既有
GBA 硬件宏，四版原位 compare 通过；代码覆盖不增加。identity 的 RAM 字段
偏移与缓冲尺寸依赖仍待类型派生，下一步先补这一项；尚不标记完全动态布局，
不移除后续 LDS 锚点。详见 CODE_ROM_LAYOUT.md 与 RELOCATION_AUDIT.md。

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
| [src/hardware.cc](src/hardware.cc) | 612 | 612 | 612 | 612 |
| [src/hardware_allocator.cc](src/hardware_allocator.cc) | 520 | 520 | 520 | 520 |
| [src/hardware_resource.cc](src/hardware_resource.cc) | 826 | 826 | 826 | 826 |
| [src/hardware_mask.cc](src/hardware_mask.cc) | 148 | 148 | 148 | 148 |
| [src/hardware_refcount.cc](src/hardware_refcount.cc) | 3,078 | 3,078 | 3,078 | 3,078 |
| [src/hardware_state_properties.cc](src/hardware_state_properties.cc) | 764 | 764 | 764 | 764 |
| [src/hardware_state_clear.cc](src/hardware_state_clear.cc) | 450 | 450 | 450 | 450 |
| [src/hardware_bootstrap.cc](src/hardware_bootstrap.cc) | 1,092 | 1,092 | 1,092 | 1,092 |
| [src/hardware_display_commands.c](src/hardware_display_commands.c) | 164 | 164 | 164 | 164 |
| [src/hardware_state_accessors.c](src/hardware_state_accessors.c) | 174 | 174 | 174 | 174 |
| [src/hardware_manager.cc](src/hardware_manager.cc) | 856 | 856 | 856 | 856 |
| [src/hardware_nested_accessors.c](src/hardware_nested_accessors.c) | 12 | 12 | 12 | 12 |
| [src/hardware_sound.cc](src/hardware_sound.cc) | 118 | 118 | 118 | 118 |
| [src/hardware_music_player.cc](src/hardware_music_player.cc) | 452 | 452 | 452 | 452 |
| [src/hardware_song.cc](src/hardware_song.cc) | 234 | 234 | 234 | 234 |
| [src/hardware_dma.c](src/hardware_dma.c) | 226 | 226 | 226 | 226 |
| [src/hardware_dma_descriptor.cc](src/hardware_dma_descriptor.cc) | 538 | 538 | 538 | 538 |
| [src/hardware_input.cc](src/hardware_input.cc) | 310 | 310 | 310 | 310 |
| [src/hardware_input_repeat.c](src/hardware_input_repeat.c) | 150 | 150 | 150 | 150 |
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
