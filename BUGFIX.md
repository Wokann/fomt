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
