# 矿石镇四版差异

以下对照以仓库当前 JP、US、EU、DE 四份原版实现为准。表中记录能定位到实现的机制、布局或脚本差异。后续发现可单独增行，属于缺陷的条目链接到[原版问题与可选修复](BUGFIX.md)。

| 主题 | JP | US | EU | DE | 实现与影响 |
| --- | --- | --- | --- | --- | --- |
| GBA / GameCube 联机识别 | A4NJ / GYWJ | A4NE / GYWE | A4NP / GYWP | A4ND / GYWP | 左列为本机游戏代码，右列为对端代码。德版与欧版共用对端代码；这些是协议字节。[连接代码](src/gamecube_link_save.cc) |
| 命名键盘 | 每页 6 行 | 6 行 | 6 行 | 7 行 | 每版都存 3 页，每行 15 个双字节槽与结束符。德版额外一行，按钮在画面上也下移一格。[数据布局](include/new_game_data.hh) · [键盘绘制](src/new_game_name_input.cc) |
| 新游戏控制选项 | 复用 Data1、Data2 两个标签 | 独立标签 | 独立标签 | 独立标签 | 行表中的两条指针随地区选择，表结构一致。[菜单行表](src/new_game_menu.cc) |
| 指南续页 | 无独立续页表 | 道具操作 | 道具操作 | 使用工具、克里夫与琳的新生儿贺信 | 137 项主目录分别对应 137、138、138、139 张物理页面行表。续页与首页共用图书 ID，仅首页进入目录。[指南清单](src/reference_guide.cc) |
| 特殊字模 | 0x81CD 的 24 字节字模 | 14 组 12 字节字模与 0xC3 字模 | 同 US | 同 US | 这些是渲染资源的地区分支；单双字节通用字库也各自有独立索引。[字模声明](include/font.hh) |
| 小／中／大鱼出货价 | 200／120／50 G | 50／120／200 G | 同 US | 同 US | 日版数据与本版游戏内指南矛盾。[鱼价条目](BUGFIX.md#fish-prices) |
| 炒荞麦面、X 级羊毛的文本指针 | 两条记录各有独立文本 | 分别复用炒乌冬、P 级羊毛的文本 | 同 US | 同 US | 影响物品名与说明。[料理](BUGFIX.md#fried-soba) · [羊毛](BUGFIX.md#wool-x) |
| 收集用宝玉和成品秘宝 | 不同名 | 不同名 | 不同名 | 两组各自同名 | 德版收集物复用成品名字，说明仍指向本物品。[宝玉条目](BUGFIX.md#de-jewels) |
| 加强药与失败料理 | 加强药名称含 XL，失败料理说明为本地语言 | 同 JP | 同 JP | 加强药与普通药同名，三种失败料理说明为英文 | [德版食物文本](BUGFIX.md#de-food) |
| 04:44／16:44 电视事件 | 两个入口都调用隐藏节目 | 两个入口均缺少调用 | 同 US | 同 US | 四版都含有节目本体，差异在调用方。[电视条目](BUGFIX.md#tv-444) |

上述表格及下文索引描述的是默认关闭 `BUGFIX` 的原版行为。艾利昵称、德版两处电视流程和鱼名复用也已提供可选修复；开启后的行为见 [BUGFIX 文档](BUGFIX.md#elli-nickname)，不据此改写原版差异索引。

四版共通的脚本问题分别见[旅馆后屋琳的爱心](BUGFIX.md#ann-heart)与[脚本加载器的终点读取](BUGFIX.md#riff-end)。

## 四版原版的全仓扫描

基线为 `97f83743`，默认关闭 `BUGFIX`。四个链接产物逐字节对照各自 baserom。四版识别出的游戏脚本各有 1,328 个，首槽为空，所有非空槽位的脚本名和顺序逐项一致。仓库中每版另存的 `EventScript_0000.mary.c` 不占运行时槽位。[脚本目录](data/scripts/jp/fomt_scripts.mary.h) · [四版差异逐项索引](REGIONAL_DIFFERENCES.tsv)

| 对照单位 | 四版合并后的条数 | 内容或成员不同 |
| --- | ---: | ---: |
| 具名原生函数 | 4,062 | 619 |
| 原生目标代码 | 342 | 73 |
| 原生目标数据 | 290 | 74 |
| 具名文本对象 | 13,339 | 13,281 |
| 全指针表候选 | 475 | 138 |
| 物品及鱼名表指针 | 406 | 10 |
| 物品表标量 | 450 | 2 |
| 脚本槽位 | 1,328 | 0 |
| 脚本指令和跳转 | 1,328 | 98 |
| 脚本字符串块 | 1,328 | 1,166 |
| 脚本文本槽数 | 1,328 | 83 |
| 脚本源控制流候选 | 1,328 | 27 |
| 脚本接口源文件 | 2 | 0 |
| 地区文本源 | 99 | 86 |
| 指南页面源 | 141 | 141 |
| 美术地区来源 | 233 | 163 |
| 图形构建依赖 | 723 | 43 |
| 链接输入大小 | 635 | 97 |
| 链接输出段 | 11 | 8 |
| 输出段内容 | 9 | 6 |

**如何读索引。** TSV 每行给出一个可检索的符号、槽位、路径或对象段，等号表示本行四版对照结果相同。目标段与函数比较链接前的字节和重定位目标，地区地址移动本身不会触发差异；函数键为对象路径与导出符号名，无符号大小的入口取到同一输入段的下一函数入口。619 个差异键中有 269 个只在部分版本找到同名入口，不能据此判断游戏新增或删除了 269 个功能。同一改动可能同时出现在函数、段和脚本三个统计层，不能跨行加总。

文本按带大小的导出 `gText_` 对象比较原始内容和大小，包含编码、尾部填充与标签拆分。脚本另直接从 ROM 指针表读取 RIFF，分别核对 CODE/JUMP、STR 和文本槽数。98 个指令或跳转差异中，27 个在源码忽略文本操作数的名字后仍有语句差异，见下表；其余 71 个保留逐槽记录，仅凭二进制差异无法断言改变了玩法。相同源码操作名也可能引用不同文本。

源文件统计使用 Git 跟踪的输入。地区资源包括 `us_eu`、`overseas` 共用来源；同一路径内容一致而构建选择不同也有记录。图形构建依赖从实际含有非空输入段的对象依赖中提取，按构建输入的真实路径比较。独立美术参考图不等于已链接的图块。指南按源文件名对照，DE 另有未列入图书清单的 `tool_and_item_controls_additional.cc`。链接输入按 map 中的对象与输入段大小对照，输出段地址为运行地址（IWRAM 代码另有 ROM 装载地址）。全量链接后的字节比较也包括段内填充与指针值，不能据此归因于机制变化。TSV 的四版数值列在函数、原生段与文本对象行表示字节长度；在指针行给出实际目标，标量行给出去除指针字段影响的原始字节。仅记录分组的行用 “—” 留空。

另从链接后的 ROM 检出 475 个全指针表候选。筛选条件为已知大小、至少两个对齐的 32 位槽，每个槽均为零或恰好匹配已导出 ROM 符号，且至少一项非零。比较目标符号与顺序时接受同址别名。337 个四版一致，其余 138 个逐表列出，TSV 数值列为槽数。这项筛选不覆盖含整数的混合结构、内部偏移指针及匿名目标；已知的物品混合结构另外逐字段比较。缺项也可能表示该版不满足筛选条件。

另外登记了 142 个文件中 3,004 处显式地区条件的位置，覆盖 C/C++、原生和内嵌汇编、资源清单、码表、工具与构建规则。它们按**条件行数**计，同一机制可能用到多行；按语言目录选文件的差异已另计。不同语言下所有可达游戏路径、内嵌数据的用途及美术画面的视觉效果仍需逐项验证。本表不把字节相等当成玩法相等，也不把译文字节不同列为缺陷。

## 已定位的其他数据与显示差异

| 主题 | JP | US、EU | DE | 依据 |
| --- | --- | --- | --- | --- |
| ROM 头标题／厂商 | BOKUMONOGBA／99 | HARVESTMOGBA／E9 | HARVESTMOGER／E9 | [构建配置](config.mk) |
| 生日输入的季节选项 | 选项值 1、2 映射到夏、秋 | 4、8 映射到夏、秋 | 同 US | [选择逻辑](src/new_game_birthday_input.cc) |
| 赛马轮次数字的横坐标 | 16 | 32 | 136 | 数字相同，使用不同画面位置。[赛马界面](src/horse_race.cc) |
| 玩家自己参赛时的购票提示 | 使用参赛鼓励文本 | 仍用一般购票确认文本 | 同 US | 影响台词选择，未发现影响购票本身。[购票状态机](src/horse_race.cc) |
| 钓鱼记录 22 与 37 | 两个指针、两种鱼名 | 37 复用 22，两条同名 | 同 US | [鱼名复用](BUGFIX.md#fish-record-names) |
| 钓鱼记录 18 与 46 | 鲣、金枪鱼分别显示 | Bonito、Tuna 分别显示 | 46 复用 18，两条均为 Thunfisch | [鱼名复用](BUGFIX.md#fish-record-names) |
| 地区字符映射 | 基础表 | 附加单字节符号和西文字符 | 同 US，可用 ä、ü、ö、ß | [地区码表](charmap.txt) |

## 逐槽脚本语句差异

分组按保留调用和操作数、忽略文本标签名后的语句序列。槽号链接到实际脚本，同一文件名可在其他语言目录中核对。对于文本播放和排版，表中仅记录已确认的调用变化。

| 槽号 | 分组 | 已核对的变化 |
| --- | --- | --- |
| [004F](data/scripts/us/EventScript_LoveEvent_Elli_NicknameChoice.mary.c) | JP=DE / US=EU | 第二个昵称选项：US/EU 显示确认，却没有写回所选昵称。[缺陷记录](BUGFIX.md#elli-nickname) |
| [00E1](data/scripts/de/EventScript_SystemMenu_ClockCalendarDisplay.mary.c) | JP=US=EU / DE | 下午小时数在 DE 直接取原值，其他版减 12。 |
| [011E](data/scripts/de/EventScript_LocationInteraction_InspectBasilHouse1FChair.mary.c) | JP=US=EU / DE | DE 对一段文字重新调用 TalkMessage，其他版使用 TalkAppendMessage 追加。 |
| [015A](data/scripts/us/EventScript_LocationInteraction_InspectUpgradedFarmhouseChair.mary.c) | JP / US=EU=DE | 海外版本追加一段文字，JP 调用 TalkMessage。 |
| [015B](data/scripts/de/EventScript_SystemMenu_CalendarDateAndTimeDisplay.mary.c) | JP=US=EU / DE | DE 的日期时间界面按 24 小时制传入下午小时数。 |
| [0164](data/scripts/us/EventScript_TV_ChannelDispatcher.mary.c) | JP / US=EU=DE | 海外版本缺少转入隐藏节目的调用。[4:44 电视](BUGFIX.md#tv-444) |
| [0193](data/scripts/de/EventScript_SystemMenu_FestivalCalendar.mary.c) | JP=US=EU / DE | DE 在节日日历的一段文字中使用 TalkMessage，其他版追加。 |
| [01AB](data/scripts/de/EventScript_LocationInteraction_InspectBeachCottageClock.mary.c) | JP=US=EU / DE | DE 的海边别墅时钟保留下午小时数。 |
| [0217](data/scripts/us/EventScript_LocationInteraction_InspectTownCottageChair.mary.c) | JP=DE / US=EU | US/EU 在镇上别墅椅子的对话中追加文字。 |
| [0218](data/scripts/de/EventScript_LocationInteraction_InspectTownCottageClock.mary.c) | JP=US=EU / DE | DE 的镇上别墅时钟保留下午小时数。 |
| [021B](data/scripts/us/EventScript_LocationInteraction_InspectTownCottageDesk.mary.c) | JP=DE / US=EU | US/EU 在镇上别墅书桌的对话中追加文字。 |
| [021C](data/scripts/us/EventScript_TV_EntertainmentChannel.mary.c) | JP / US=EU=DE | 换台入口也有同样的隐藏节目调用差异。[4:44 电视](BUGFIX.md#tv-444) |
| [02CD](data/scripts/de/EventScript_NPCEvent_Cliff_PermanentWineryJob.mary.c) | JP / US=EU / DE | 克里夫酒庄就职事件中，多处普通和慢速对话调用不同。 |
| [02D1](data/scripts/de/EventScript_NPCEvent_Manna_FlattersJeff.mary.c) | JP=US=EU / DE | DE 将玛娜的三处慢速对话改用普通对话。 |
| [02EF](data/scripts/us/EventScript_NPCEvent_Jeff_WonOffersToBuyPainting.mary.c) | JP / US=EU=DE | 海外版本多调用一次 TalkMessage。 |
| [02F4](data/scripts/de/EventScript_NPCEvent_Manna_AjasDepartureAdviceFromFriends.mary.c) | JP / US=EU / DE | 讨论阿雅离家时，部分台词的播放速度不同。 |
| [03DC](data/scripts/us/EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay.mary.c) | JP / US=EU=DE | JP 先设 06:00 再保存次日位置，海外版先保存位置再设时间。 |
| [03E1](data/scripts/de/EventScript_NPCEvent_Popuri_DialogueAndGiftResponses.mary.c) | JP=US=EU / DE | DE 在珀布利日常对话中多一次 TalkMessage。 |
| [03E5](data/scripts/us/EventScript_NPCEvent_Zack_DialogueAndGiftResponses.mary.c) | JP=DE / US=EU | US/EU 在扎克日常对话中多一次 TalkMessage。 |
| [03F0](data/scripts/de/EventScript_NPCEvent_Karen_DialogueAndGiftResponses.mary.c) | JP / US=EU / DE | 卡莲的对话在头像表情、切换次数和 DE 文本分段上存在差异。 |
| [03FD](data/scripts/us/EventScript_NPCEvent_Manna_DialogueAndGiftResponses.mary.c) | JP=DE / US=EU | US/EU 将玛娜日常对话中的一处慢速文本改用普通对话。 |
| [0414](data/scripts/de/EventScript_TV_LifeOnTheFarm_Beginner.mary.c) | JP=US=EU / DE | 德版春 19 日节目少一个 break，会继续播放 20 日节目。[缺陷记录](BUGFIX.md#de-farm-tv) |
| [0418](data/scripts/de/EventScript_TV_MineralTownFriends_CharacterProfiles.mary.c) | JP / US=EU / DE | 人物介绍节目中的慢速台词数和调用类型不同；DE 第 36 号人物节目没有读取频道输入，随后分派到天气频道。[缺陷记录](BUGFIX.md#de-profile-tv) |
| [0432](data/scripts/us/EventScript_FestivalEvent_NewYearsDayFestivalDialogue_Manna.mary.c) | JP / US=EU=DE | 海外版本改变玛娜新年对话中一处文本速度。 |
| [0445](data/scripts/de/EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Manna.mary.c) | JP / US=EU / DE | 玛娜赛马场对话的慢速台词数不同。 |
| [0468](data/scripts/de/EventScript_FestivalEvent_CookingFestival_Judging.mary.c) | JP=US=EU / DE | 料理祭评审的一次等待由其他版的 240 帧变为 DE 的 480 帧。 |
| [04B4](data/scripts/us/EventScript_FestivalEvent_MusicFestival_EntryCheck_Carter.mary.c) | JP / US=EU=DE | 海外版在转入音乐祭开幕脚本前显式写入 FESTIVAL_PHASE_INITIAL。 |
