# 反编译进度

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
