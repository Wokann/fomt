# 原版问题与可选修复

在 [include/config.h](include/config.h) 中取消 `#define BUGFIX` 的注释，以 `make -j16 GAME_REGION=JP all` 构建。将 JP 换成 US、EU 或 DE 即可选择其他基底。修改同一开关后直接重新构建，原生代码的头文件依赖和 Mary 的 bundle 依赖都会生效。关闭开关再运行对应区域的 `compare`，检验原版 SHA-1。开启时的 ROM 含有修复，SHA-1 会改变。[构建规则](Makefile) · [四版差异](REGIONAL_DIFFERENCES.md)

| 修复条目 | JP | US | EU | DE |
| --- | --- | --- | --- | --- |
| [脚本块末尾读取](#riff-end) | 有 | 有 | 有 | 有 |
| [小鱼、大鱼出货价](#fish-prices) | 有 | 正常 | 正常 | 正常 |
| [炒荞麦面](#fried-soba) | 正常 | 有 | 有 | 有 |
| [X 级羊毛](#wool-x) | 正常 | 有 | 有 | 有 |
| [两类宝玉与秘宝同名](#de-jewels) | 正常 | 正常 | 正常 | 有 |
| [德版加强药、失败料理](#de-food) | 正常 | 正常 | 正常 | 有 |
| [旅馆后屋琳的爱心](#ann-heart) | 有 | 有 | 有 | 有 |
| [4:44 电视无法退出](#tv-444) | 正常 | 有 | 有 | 有 |
| [艾利的第二个昵称](#elli-nickname) | 正常 | 有 | 有 | 正常 |
| [春 19 日入门节目贯穿](#de-farm-tv) | 正常 | 正常 | 正常 | 有 |
| [不同鱼种共用名字](#fish-record-names) | 正常 | 22／37 | 22／37 | 22／37、18／46 |
| [人物介绍节目频道输入](#de-profile-tv) | 正常 | 正常 | 正常 | 有 |

<a id="riff-end"></a>
### 脚本块末尾读取

此游戏 RIFF 脚本中的 `length` 给出从脚本开头起算的结束位置。读完最后一个块时 `offset == length`，此处已没有下一块头。原版循环仍取八字节，在所有四版的 1,328 个正常脚本上都会读到块外。原始布局中多取的字节没有命中已知块类型。修复将循环条件改为 `offset < length`，仅处理合法脚本的终点问题。[加载器](src/script_vm.cc) · [原 ROM 检查](RELOCATION_AUDIT.md)

<a id="fish-prices"></a>
### 小鱼和大鱼售价相反

日版出货表的小、中、大鱼分别为 200、120、50 G，日版游戏内《出货价格》写的是 50、120、200 G。其他三版的数据与指南顺序一致。开启修复仅更正日版小鱼和大鱼的价格。[出货表](src/item.cc) · [日版指南](data/text/jp/reference_guide/sell_price.cc) · [美版指南](data/text/us/reference_guide/sell_price.cc)

<a id="fried-soba"></a>
### 炒荞麦面显示成炒乌冬面

食物 `0x89` 对应日版「焼きそば」（炒荞麦面），海外版的名字和说明指针与 `0x86` 共用，两个菜谱因此显示相同的成品名。修复为 `0x89` 增加独立地区文本；英文采用 Fried Soba，德文采用 Gebratene Soba，均为本工程补译。图标和食物属性保持原版值。[食物表](src/item.cc) · [日版料理](data/text/jp/item_2.cc) · [英文料理](data/text/us/item_2.cc) · [德文料理](data/text/de/item_2.cc)

<a id="wool-x"></a>
### X 级羊毛显示成 P 级

物品 `0x0A` 有自己的图标，三个海外版却为名字和说明选用了 `0x09` 的 P 级文本。开启修复后两处均显示 X 等级，沿用各版其他羊毛的措辞。[物品表](src/item.cc) · [日版羊毛](data/text/jp/item_3.cc) · [欧版羊毛](data/text/eu/item_3.cc)

<a id="de-jewels"></a>
### 德版宝玉与集齐后的秘宝同名

德版的收集物 `0x26` 和 `0x27` 分别取用对应成品工具的名字，而两件收集物的独立说明仍写着「集齐九个」。这会让同一套宝物的零件与成品显示同名。修复采用 Kappa-Juwelteil 和 Wahrheitsjuwelteil（河童宝玉部件、真实宝玉部件）作为收集物的名字，并同步说明首行；两件成品保留原名。这两个德文名称是本工程补译。[收集物表](src/item.cc) · [德版成品](data/text/de/item_1.cc) · [德版收集物](data/text/de/item_3.cc)

<a id="de-food"></a>
### 德版加强药缺少 XL、三种失败料理显示英文

食物 `0x3A` 的说明首行写着 Bodigizer XL，但名字指针复用普通药。修复直接采用德版说明中的名称。失败料理 `0x9B–0x9D` 的说明仍为英文，修复将它们指向同表已有的德文 Misserfolg（失败）说明。两处修改均保留原有玩法属性。[食物表](src/item.cc) · [德文名称与说明](data/text/de/item_2.cc)

<a id="ann-heart"></a>
### 玩家已娶别人，琳仍在旅馆后屋显示爱心

琳未与克里夫成婚，玩家已娶其他候补，在旅馆后屋与琳交谈，然后在仍属于重复对话的状态下再交谈一次。首谈检查其他四位普通候补和女神的婚姻标志，重复对话却直接调用 `ShowTalkHeartIndicator(CHARACTER_ANN)`。四版在此处相同。修复让重复对话使用首谈已有的条件。琳本人是配偶时的正常显示以及她与克里夫的婚后对话沿用原逻辑。天气与时段只影响能否遇见她，该对话分支直接判断的是地图与交谈状态。[日版](data/scripts/jp/EventScript_NPCEvent_Ann_DialogueAndGiftResponses.mary.c) · [美版](data/scripts/us/EventScript_NPCEvent_Ann_DialogueAndGiftResponses.mary.c) · [欧版](data/scripts/eu/EventScript_NPCEvent_Ann_DialogueAndGiftResponses.mary.c) · [德版](data/scripts/de/EventScript_NPCEvent_Ann_DialogueAndGiftResponses.mary.c)

<a id="tv-444"></a>
### 海外版 4:44 电视反复开关

电视初始入口和换台入口都检查 04:44、16:44。日版设为无信号后调用隐藏节目。US、EU、DE 仍完整保存该节目，但两个入口都漏掉了调用。于是程序走到公共收尾，用本分支从未赋值的 `var_1` 判断频道。载入脚本会清零 VM 变量，0 恰好是天气频道；换台脚本因此再次调用自身。如果游戏时间保持在原分钟，会持续重入。[日版入口](data/scripts/jp/EventScript_TV_ChannelDispatcher.mary.c) · [海外初始入口](data/scripts/us/EventScript_TV_ChannelDispatcher.mary.c) · [海外换台入口](data/scripts/us/EventScript_TV_EntertainmentChannel.mary.c) · [频道枚举](include/fomt_constants.mary.h) · [VM 清零](src/script_vm.cc)

修复让三个海外版的两个入口像日版一样调用本版已有的隐藏节目。`GameScene::CallScript` 在当前脚本引擎载入目标，重置程序计数器；隐藏节目自行结束电视和对话。节目原有的星期、日期、重复次数和文字都得以保留。[事件切换](src/game_scene.cc) · [脚本加载](src/script_engine.cc) · [隐藏节目](data/scripts/us/EventScript_TV_4AMHiddenBroadcast.mary.c)

## 全仓对照后补充的可选修复

以下四组也由同一个 `BUGFIX` 开关控制，只更改表中列出的受影响版本。

<a id="elli-nickname"></a>
### US、EU 选择艾利的第二个昵称后未写回

第二个选项显示 Honey（亲爱的），随后艾利会确认选择。JP、DE 在确认前调用 `SetPlayerNicknameForSpouse`；US、EU 的同一分支漏掉调用，只执行显示与动作，旧昵称会保留。其他昵称选择走各自的分支。修复只在 US／EU 的第二选项补上写入，并采用该选项已有的 Honey 字符串，位置与 JP、DE 相同。[日版](data/scripts/jp/EventScript_LoveEvent_Elli_NicknameChoice.mary.c) · [美版](data/scripts/us/EventScript_LoveEvent_Elli_NicknameChoice.mary.c) · [欧版](data/scripts/eu/EventScript_LoveEvent_Elli_NicknameChoice.mary.c) · [德版](data/scripts/de/EventScript_LoveEvent_Elli_NicknameChoice.mary.c)

<a id="de-farm-tv"></a>
### DE 春季 19 日的农场入门节目连续播放两天

德版在 19 日消息和 20 日分支之间少了 `break`，因此 19 日会连续执行两次 `ShowTelevisionMessage`，后一次返回值也会覆盖前一次的输入结果。JP、US、EU 在 19 日消息后结束本分支。修复在德版 19 日消息后补上分支结束，保留该次频道输入。此问题与 4:44 隐藏节目独立。[德版](data/scripts/de/EventScript_TV_LifeOnTheFarm_Beginner.mary.c) · [美版](data/scripts/us/EventScript_TV_LifeOnTheFarm_Beginner.mary.c)

<a id="fish-record-names"></a>
### 海外版不同鱼种共用显示名

记录 22 和 37 在 JP 分别显示「ギンブナ」和「ハクレン」，三个海外版的 37 均取记录 22 的名字。记录 18 和 46 在 JP 分别是「カツオ」（鲣）和「マグロ」（金枪鱼），US、EU 各有独立名字；DE 的两项都指向 Thunfisch（金枪鱼）。记录 ID 与名称表下标仍然独立，已证实的影响在名称显示。修复为三个海外版的 37 增加独立文本并更正指针：22 采用 Ginbuna，37 采用 Silver Carp（DE 为 Silberkarpfen）；DE 的 18 改为 Bonito，46 使用独立的 Thunfisch。Ginbuna 是本工程补充的名称，按日文鱼种作区分，旧导出符号保留兼容性，不改变钓鱼记录编号、捕获数量或体长。[记录编号](include/fomt_constants.mary.h) · [名称指针表](src/fishing_results_data.cc) · [日文](data/text/jp/fishing_results_data.cc) · [德文](data/text/de/fishing_results_data.cc)

<a id="de-profile-tv"></a>
### DE 第 36 号人物介绍节目未读取频道键

人物节目按索引进入 `case 36` 时，另外三版执行 `var_0 = ShowTelevisionMessage(...)`，让观众选择频道或继续观看。德版改用无返回值的慢速对话，随即关闭文本框并读取尚未赋值的 `var_0`。脚本载入时变量清零，0 对应天气频道，程序因此转交给换台脚本。修复仅将德版这次调用恢复为接收返回值的电视消息调用，与另外三版相同；其余德文台词播放速度保持原样。这个入口与 4:44 无关。[德版](data/scripts/de/EventScript_TV_MineralTownFriends_CharacterProfiles.mary.c) · [美版](data/scripts/us/EventScript_TV_MineralTownFriends_CharacterProfiles.mary.c) · [频道枚举](include/fomt_constants.mary.h) · [变量初始化](src/script_vm.cc)

## 验证范围

以上修复已以 WSL、make -j16 验证四版开关构建。默认关闭时，完整产物逐字节等于对应基准 ROM：

| 版本 | SHA-1 |
| --- | --- |
| JP | a655b2789aed14a6ac78c6075fbc533d3062dbe3 |
| US | a2fc3574f0a65a4fcf7682fb274b9d7eebdef963 |
| EU | 7ba1ec1e46ce424e3c6fd72e4e8d5e9eb5ede247 |
| DE | 60f2a30b55c0e32754897b4d5df6ce06f8b71a37 |

开启后，四版脚本总表仍含 1,328 个有效入口，每一项均指向对应脚本；各脚本 STR 字符串块保持原样。相对原版，JP 有 1 个、US／EU 各 4 个、DE 有 5 个脚本的指令或跳转发生变化，恰好覆盖本页列出的受影响脚本。再次解码编译产物，确认 US／EU 艾利第二选项写入 Honey、DE 春 19 日分支结束、DE 人物节目第 36 项保存频道输入。原生物品及鱼名表的相关指针均核对到预期符号，鱼名 22／37 及 18／46 分别独立。

这些是编译、ROM、脚本指令及指针检查，不代表已在模拟器中逐个游玩复现所有事件。
