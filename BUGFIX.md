# 原版问题与可选修复

本页仅记录由四份 FoMT 原版实现、数据及调用关系确认的问题。分类综合问题性质与玩家影响：先列流程／边界，再列结算与事件、交互反馈、文字与身份。不把正常地区调整当作缺陷；差异见 [四版差异](REGIONAL_DIFFERENCES.md)。社区反馈仅作定位线索，已排除反馈及旧本地化版本特有问题不列入。

证据主要来自同一工程的四版源码、脚本和基准 ROM，彼此可交叉核对，但不等同于独立实机复现。未复现的运行症状会明确限定为静态结论。

在 [include/config.h](include/config.h) 中取消 `#define BUGFIX` 的注释，运行 `make -j16 GAME_REGION=JP all`；US、EU、DE 同理。[Makefile](Makefile) 从同一配置向 Mary 传递开关，不能只给原生编译器追加宏而遗漏脚本。默认关闭时保留原版行为；开启后 SHA-1 预期改变。

**验收状态（2026-11-15）：羊祭接待桌修复后，四版默认完整构建均逐字节及 SHA-1 匹配各自 baserom，四版 BUGFIX 完整构建均通过。最新消息调用核验见羊祭条目；指南及先前修复的具体核验范围见各条目和历史记录。** 这是构建、字节、结构和引用层面的验收，不等于逐个事件已经实机复现。高级语言还原、工具支持、行为修复、命名与纯排版分别提交。

**当前批次（2026-11-16）：** [合并审计清单](TEXT_SYMBOL_AUDIT.md)的71项获准修复按编号依次提交（当前至B11），E11保留不动。全部源码修复完成后统一构建四版默认及BUGFIX；最终默认ROM均与baserom逐字节及SHA-1一致，开启版通过构建和产物核对。下述2026-11-15记录仅适用于旧基线，本轮范围见[验收记录](#reviewed-text-validation-20261116)。

## 统一索引

| 分类 | 问题 | 受影响版本 | 实现状态 |
| --- | --- | --- | --- |
| 流程控制与读取边界 | [脚本加载器多读末尾块头](#riff-end) | 四版 | 已接入，构建／静态核验通过 |
| 流程控制与读取边界 | [指南名称标记漏展开与缓冲区越界](#guide-name-expansion) | 四版（标记漏展开已命中 US／EU／DE 原文） | 已接入最小修复，验收见条目 |
| 流程控制与读取边界 | [海外 4:44 电视反复重入](#tv-444) | US、EU、DE | 已接入，构建／静态核验通过 |
| 流程控制与读取边界 | [人物介绍节目未接收频道输入](#de-profile-tv) | DE | 已接入，构建／静态核验通过 |
| 流程控制与读取边界 | [联机失败消息沿用旧窗口状态](#jp-link-retry) | JP | 已接入，构建／静态核验通过 |
| 结算、养成与事件结果 | [小鱼与大鱼出货价倒置](#fish-prices) | JP | 已接入，构建／静态核验通过 |
| 结算、养成与事件结果 | [获奖牛羊的高等级售价倒置](#jp-livestock-sale-prices) | JP | 已接入，构建／静态核验通过 |
| 结算、养成与事件结果 | [入睡时间被早晨时间覆盖](#jp-sleep-time) | JP | 已接入，构建／静态核验通过 |
| 结算、养成与事件结果 | [幼畜出生好感度计算错误](#jp-birth-affection) | JP | 已接入，构建／静态核验通过 |
| 结算、养成与事件结果 | [艾利确认第二个昵称但未保存](#elli-nickname) | US、EU | 已接入，构建／静态核验通过 |
| 结算、养成与事件结果 | [婚期未完整避开双方生日](#jp-wedding-birthdays) | JP | 未接入 |
| 操作反馈、记录与选项 | [包装画面把升级农具画成基础农具](#wrapping-tool-icons) | JP、US | 已接入，构建／静态核验通过 |
| 操作反馈、记录与选项 | [联机名称拒收最后一个有效字符](#jp-link-last-character) | JP | 已接入，构建／静态核验通过 |
| 操作反馈、记录与选项 | [玩家已娶别人仍显示琳的爱心](#ann-heart) | 四版 | 已接入，构建／静态核验通过 |
| 操作反馈、记录与选项 | [春 19 日入门节目贯穿下一日分支](#de-farm-tv) | DE | 已接入，构建／静态核验通过 |
| 操作反馈、记录与选项 | [动物照料栏目显示了收获最高记录](#overseas-animal-care-record) | US、EU、DE | 未接入 |
| 操作反馈、记录与选项 | [料理材料的包装说明未送入窗口](#cooking-wrapped-description) | US、EU、DE | 未接入 |
| 操作反馈、记录与选项 | [女神猜拳显示手势与实际分支不一致](#goddess-rps-options) | US、EU、DE | 已接入，构建／静态核验通过 |
| 物品身份、文字含义与排版 | [炒荞麦面复用炒乌冬面文本](#fried-soba) | US、EU、DE | 已接入，构建／静态核验通过 |
| 物品身份、文字含义与排版 | [X 级羊毛复用 P 级文本](#wool-x) | US、EU、DE | 已接入，构建／静态核验通过 |
| 物品身份、文字含义与排版 | [收集用宝玉与合成秘宝同名](#de-jewels) | DE | 已接入，构建／静态核验通过 |
| 物品身份、文字含义与排版 | [加强药 XL 名称与失败料理语言错误](#de-food) | DE | 已接入，构建／静态核验通过 |
| 物品身份、文字含义与排版 | [道具说明残缺、错译与漏翻](#item-description-audit) | 按条目 | 已接入，验收见条目 |
| 物品身份、文字含义与排版 | [不同鱼种复用同一显示名](#fish-record-names) | US、EU、DE（第二组仅 DE） | 已接入，构建／静态核验通过 |
| 物品身份、文字含义与排版 | [羊祭接待桌使用牛祭提示](#sheep-reception-text) | US、EU、DE | 已接入，验收见条目 |
| 物品身份、文字含义与排版 | [其余原文、选项与换行修正](#localization-text) | 按条目 | 已接入，构建／静态核验通过 |

## 流程控制与读取边界

<a id="riff-end"></a>
### 脚本加载器多读末尾块头

- **原版与影响（四版）：** RIFF 的 `length` 是从脚本开头起算的结束位置；原循环仍在 `offset == length` 时读取八字节块头。四版各 1,328 个正常脚本均会读到块外。原始布局的额外内容未命中有效块类型，不能据此保证修改布局后也安全。
- **应有行为与对照：** 读到终点就停止；四版都存在此问题，没有正常地区实现可直接沿用。依据是 RIFF 边界与读取器消费关系。
- **修复范围与方式：** 四版把 `offset <= length` 改为 `offset < length`。范围仅为合法脚本的终点判定。
- **验证状态：** 已接入 `BUGFIX`；四版默认匹配，开启后的核验范围见本轮验收记录。

[加载器](src/script_vm.cc) · [原 ROM 边界审计](RELOCATION_AUDIT.md)

<a id="guide-name-expansion"></a>
### 指南名称标记漏展开与缓冲区越界

- **原版与影响（四版（标记漏展开已命中 US／EU／DE 原文））：** 普通内容固定按两个字节推进，海外落在奇数字节偏移的名称标记被漏过。四版“最多十四轮”也不限制实际写入字节数；一次名称展开可写入多字节，调用者的 32 字节缓冲区可能被越过。
- **应有行为与对照：** 正确识别现有名称标记，在字符串结束处停止读取，且现有文本展开后应容纳于调用者的缓冲区。现有海外指南有六个漏展开的地区／行组合；JP 与 DE 名称展开有静态越界证据，尚未把具体崩溃当成运行实测。
- **修复范围与方式：** JP 仅在 BUGFIX 下删除联机玩家介绍标题的尾部全角空格；接收名称占满 14 字节时，标题含结束符为 25 字节。海外保留原来的双字节复制、名称展开及 14 次循环上限，仅在普通内容第二字节为 `00` 时复制首字节后结束，为 `<` 时只复制首字节并前进一字节，让下一轮识别完整标记。`00`／`3C` 均不是合法 Shift-JIS 尾字节。DE 高仓介绍前两行按原用词重新分为三行，为正常展开的姓名留出空间。
- **边界与验证：** 不添加通用 28 字节截断、名称容量辅助函数或新的循环计数规则。代码外核对现有四版全部名称行及允许的名称长度，并检查标记后双字节字符与末尾单字节字符；720 项提取函数检查通过，原 14 次上限未提前截断这些文本。四版默认 ROM 均与各自 baserom 逐字节及 SHA-1 一致，四版 BUGFIX 完整构建通过；最终链接产物的 552 个页面、13,367 个行文本及各版 137 项总目录均通过指针与内容核对，除本项两页和既有 Kai 贺卡修复外无其他页面变化。该结论针对现有正常文本和名称，不保证任意新增超长行或损坏存档也安全；尚未将游戏运行实测作为本项验收依据。

[实现与调用者](src/scene_reference_page.cc) · [名称字段](include/game_state_types.hh) · [具体原文与边界证据](REGIONAL_DIFFERENCES.md#guide-name-boundaries)

<a id="tv-444"></a>
### 海外 4:44 电视反复重入

- **原版与影响（US、EU、DE）：** 初始入口与换台入口在 04:44、16:44 都漏调隐藏节目，随后读取本分支未赋值的 `var_1`。VM 初值 0 对应天气频道，于是重入换台脚本；若时间仍在原分钟，会重复进入。
- **应有行为与对照：** JP 在设为无信号后调用隐藏节目，由该节目处理播放和结束。海外也保留了完整节目本体，应从两处入口转入它。
- **修复范围与方式：** 只为三个海外版的两个入口补上本版隐藏节目调用；保留节目原有星期、日期、重复次数和文本。
- **验证状态：** 已接入 `BUGFIX`；四版默认匹配，开启后的核验范围见本轮验收记录。

[JP 入口](data/scripts/jp/EventScript_TV_ChannelDispatcher.mary.c) · [US 初始入口](data/scripts/us/EventScript_TV_ChannelDispatcher.mary.c) · [US 换台入口](data/scripts/us/EventScript_TV_EntertainmentChannel.mary.c) · [隐藏节目](data/scripts/us/EventScript_TV_4AMHiddenBroadcast.mary.c) · [VM 初始化](src/script_vm.cc)

<a id="de-profile-tv"></a>
### 人物介绍节目未接收频道输入

- **原版与影响（DE）：** 第 36 项改用无返回值的慢速对话，关闭窗口后又读取尚未赋值的 `var_0`；默认值 0 把流程转入天气频道，忽略本应接收的频道选择。
- **应有行为与对照：** JP、US、EU 使用 `var_0 = ShowTelevisionMessage(...)`，将本次输入送入后续分派。
- **修复范围与方式：** 仅恢复 DE 该项的电视消息调用与返回值保存；其他慢速台词保持原样。与 4:44 问题分开处理。
- **验证状态：** 已接入 `BUGFIX`；四版默认匹配，开启后的核验范围见本轮验收记录。

[DE 分派](data/scripts/de/EventScript_TV_MineralTownFriends_CharacterProfiles.mary.c) · [US 对照](data/scripts/us/EventScript_TV_MineralTownFriends_CharacterProfiles.mary.c) · [频道定义](include/fomt_constants.mary.h)

<a id="jp-link-retry"></a>
### 联机失败消息沿用旧窗口状态

- **原版与影响（JP）：** 协议同次更新先进入 `EnterRetry` 再调用 `PollRetry`。新消息只重置窗口自身，未重置场景缓存；缓存仍为完成状态 3 时，选择框可能在失败消息首次绘制前出现。
- **应有行为与对照：** 海外将场景缓存设为 4，等待新消息完成。已确认状态读写和调用顺序，未声称所有断线时序都实机复现。
- **修复范围与方式：** JP 在重试入口同步设置 `ui_state = 4`，不改变通信协议或存档内容。
- **验证状态：** 已接入 `BUGFIX`；四版默认匹配，开启后的核验范围见本轮验收记录。

[场景与协议调用顺序](src/scene_gamecube_link.cc) · [重试回调实现](include/scene_gamecube_link_callbacks.hh) · [窗口状态](src/ui_state.cc)

## 结算、养成与事件结果

<a id="fish-prices"></a>
### 小鱼与大鱼出货价倒置

- **原版与影响（JP）：** 小、中、大鱼分别卖 200、120、50 G，与日版游戏内《出货价格》矛盾。
- **应有行为与对照：** JP 指南及三个海外版数据均为 50、120、200 G。
- **修复范围与方式：** 仅交换 JP 小鱼和大鱼的出货价格，中鱼与其他物品不变。
- **验证状态：** 已接入 `BUGFIX`；四版默认匹配，开启后的核验范围见本轮验收记录。

[商品表](src/item.cc) · [JP 指南](data/text/jp/reference_guide/sell_price.cc) · [US 指南](data/text/us/reference_guide/sell_price.cc)

<a id="jp-livestock-sale-prices"></a>
### 获奖牛羊的高等级售价倒置

- **原版与影响（JP）：** 基础等级 3／4 的牛为 7,000／6,000 G，羊为 5,000／4,000 G。两档均已获奖且好感度超过 200；累计户外达到 600 小时后等级升至 4，却少卖 1,000 G。报价直接用于入账。
- **应有行为与对照：** 海外同档牛为 6,000／7,000 G，羊为 4,000／5,000 G；较高等级对应较高价格。
- **修复范围与方式：** 仅交换 JP 牛、羊两组高等级返回值，保留低等级和未知种类的原有默认值；不改变生产 X 级产物的随机过程。
- **验证状态：** 已接入 `BUGFIX`；四版默认匹配，开启后的核验范围见本轮验收记录。

[售价与入账](src/scene_yodel_ranch_shop.cc) · [等级条件](src/livestock.cc) · [完整对照表](REGIONAL_DIFFERENCES.md#livestock-sale-prices)

<a id="jp-sleep-time"></a>
### 入睡时间被早晨时间覆盖

- **原版与影响（JP）：** 先设为 06:00，再保存包含当前时间的次日状态，后续按保存的 6 计算出 24 小时恢复。小时效果为体力 +7／疲劳 −2，普通床另加 +50／−5；边界裁剪前合计 +218／−53，普通床流程因而压住了要求剩余疲劳至少 50 的睡过头分支。
- **应有行为与对照：** 海外先保存实际入睡时间，再设为 06:00；恢复小时数为 `(hour <= 5 ? 6 : 30) - hour`。JP 有睡过头代码，问题是前序过量恢复，不能概括成所有过夜路径都不晚起。
- **修复范围与方式：** 只交换 JP 次日过渡脚本的两条调用顺序；固定床效果、花瓶与早餐逻辑不改。
- **验证状态：** 已接入 `BUGFIX`；四版默认匹配，开启后的核验范围见本轮验收记录。

[JP 过渡](data/scripts/jp/EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay.mary.c) · [US 对照](data/scripts/us/EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay.mary.c) · [保存与恢复](src/game_scene.cc) · [床效果](data/scripts/jp/EventScript_LocationInteraction_FarmhouseBedSleepChoice.mary.c) · [晚起判断](data/scripts/jp/EventScript_SystemEvent_SleepRecoveryAndCursedHammerSickleBlessing.mary.c)

<a id="jp-birth-affection"></a>
### 幼畜出生好感度计算错误

- **原版与影响（JP）：** 幼牛路径无条件对母牛好感度的一半取模，低好感度可能令除数为 0；幼羊路径还以空对象作为好感度读取器的接收者。
- **应有行为与对照：** 海外读取实际母畜，且只在半好感度大于 1 时调用随机数及取模。应以正确母畜、有效除数计算。
- **修复范围与方式：** JP 对齐这两条计算路径；低好感度的随机数消耗随之与海外一致。不猜测空对象在 BIOS／开放总线环境下必然产生何种崩溃。
- **验证状态：** 已接入 `BUGFIX`；四版默认匹配，开启后的核验范围见本轮验收记录。

[四版出生实现](src/barn.cc) · [母羊路径原生取证](docs/mary-native-audit/animals/barn_birth_followup_audit.md)

<a id="elli-nickname"></a>
### 艾利确认第二个昵称但未保存

- **原版与影响（US、EU）：** 选择 Honey（亲爱的）后显示确认，却未调用写回函数，实际昵称保留旧值。
- **应有行为与对照：** JP、DE 在确认前调用 `SetPlayerNicknameForSpouse` 保存所选文本。
- **修复范围与方式：** 仅在 US、EU 第二选项补上写回，采用当前选项已有字符串；不改其他昵称分支。
- **验证状态：** 已接入 `BUGFIX`；四版默认匹配，开启后的核验范围见本轮验收记录。

[US](data/scripts/us/EventScript_LoveEvent_Elli_NicknameChoice.mary.c) · [JP](data/scripts/jp/EventScript_LoveEvent_Elli_NicknameChoice.mary.c) · [DE](data/scripts/de/EventScript_LoveEvent_Elli_NicknameChoice.mary.c)

<a id="jp-wedding-birthdays"></a>
### 婚期未完整避开双方生日

- **原版与影响（JP）：** 订婚计数达到 5 后立即查询只在计数大于 5 时返回配偶的函数，得到 0 而漏查未婚妻生日；日期经过避让表顺延后，也不重新检查全部生日条件。
- **应有行为与对照：** 海外保存本次婚约对象，并在顺延后重查双方生日及避让条件。例如候选春 17 日、玩家生日春 19 日时，JP 避开春 17、18 日后可能落在未重查的春 19 日。
- **修复范围与方式：** 待恢复整个相关文件后，修正对象来源及重新检查流程。婚期表额外避让秋 30、冬 25 是独立地区规则，不能通过直接统一表代替此修复。
- **验证状态：** 尚未接入 `BUGFIX`。先完成所属整个文件的高级语言还原与默认匹配，再实施修复。

[婚期计算](src/script_engine.cc) · [订婚／已婚查询](src/npc_collection.cc) · [日期表](src/wedding_date.cc) · [原生证据](docs/mary-native-audit/events/event_state_registration.md)

## 操作反馈、记录与选项

<a id="wrapping-tool-icons"></a>
### 包装画面把升级农具画成基础农具

- **原版与影响（JP、US）：** 背包和手持两条路径直接用基础工具编号取图标，显示未反映保存的升级等级；工具本身并未降级。
- **应有行为与对照：** EU、DE 在两条路径都通过 `Farmer::GetUpgradedTool` 转换为实际升级编号。
- **修复范围与方式：** JP、US 同步两条图标路径，保持物品状态、包装费和升级记录不变。
- **验证状态：** 已接入 `BUGFIX`；四版默认匹配，开启后的核验范围见本轮验收记录。

[包装绘制](src/scene_gift_wrapping.cc) · [升级映射](src/farmer.cc)

<a id="jp-link-last-character"></a>
### 联机名称拒收最后一个有效字符

- **原版与影响（JP）：** 编码发送一基索引，0 为结束符；接收端却按未减 1 的值检查范围，拒绝最后合法字符 `※`，并停止读取后续字符。
- **应有行为与对照：** 海外先减 1 再检查，与编码端覆盖的非终止字符范围相同。
- **修复范围与方式：** JP 按一基协议修正边界，不扩大字符表、包长或存档字段。
- **验证状态：** 已接入 `BUGFIX`；四版默认匹配，开启后的核验范围见本轮验收记录。

[编解码](src/gamecube_link_save.cc) · [JP 字符表](data/text/jp/gamecube_link_save.cc) · [协议结构](include/gamecube_link_save.hh)

<a id="ann-heart"></a>
### 玩家已娶别人仍显示琳的爱心

- **原版与影响（四版）：** 琳尚未与克里夫结婚、玩家已娶其他候补时，在旅馆后屋的重复对话直接显示琳的爱心；首谈会检查其他候补与女神的婚姻标志。
- **应有行为与对照：** 重复对话应沿用本版首谈已有的婚姻条件，而非改变琳作为玩家配偶时的正常爱心。四版此处相同。
- **修复范围与方式：** 四版重复对话加上首谈条件；保留琳与玩家及与克里夫的原有婚后分支。
- **验证状态：** 已接入 `BUGFIX`；四版默认匹配，开启后的核验范围见本轮验收记录。

[JP 对话](data/scripts/jp/EventScript_NPCEvent_Ann_DialogueAndGiftResponses.mary.c) · [US 对话](data/scripts/us/EventScript_NPCEvent_Ann_DialogueAndGiftResponses.mary.c)

<a id="de-farm-tv"></a>
### 春 19 日入门节目贯穿下一日分支

- **原版与影响（DE）：** 春 19 日消息后少 `break`，连续播放春 20 日内容，并以第二次调用返回值覆盖第一次频道输入。
- **应有行为与对照：** JP、US、EU 在春 19 日消息后结束该分支。
- **修复范围与方式：** 仅补 DE 分支结束；保持 19 日消息及本次频道选择。
- **验证状态：** 已接入 `BUGFIX`；四版默认匹配，开启后的核验范围见本轮验收记录。

[DE 节目](data/scripts/de/EventScript_TV_LifeOnTheFarm_Beginner.mary.c) · [US 对照](data/scripts/us/EventScript_TV_LifeOnTheFarm_Beginner.mary.c)

<a id="overseas-animal-care-record"></a>
### 动物照料栏目显示了收获最高记录

- **原版与影响（US、EU、DE）：** 标题是动物照料，数值却再次读取 `sprite_harvesting_record`；两个栏目显示同一收获记录。实际动物照料成绩仍独立保存，不是成绩被覆盖或奖励未结算。
- **应有行为与对照：** JP 对应行读取 `sprite_animal_care_record`；小游戏结束时四版也都写入这个独立字段。
- **修复范围与方式：** 待整个记录页文件恢复后，仅修正海外该栏的读取对象，JP 不改。
- **验证状态：** 尚未接入 `BUGFIX`。先完成所属整个文件的高级语言还原与默认匹配，再实施修复。

[记录页](src/records_screen.cc) · [字段](include/game_state_types.hh) · [读写器](src/game_state.cc) · [成绩提交](src/scene_minigames.cc)

<a id="cooking-wrapped-description"></a>
### 料理材料的包装说明未送入窗口

- **原版与影响（US、EU、DE）：** 选中已包装物品时，把包装说明及物品名拼到另一个临时缓冲区，却把原来的仅含名字的缓冲区传给窗口；包装说明不显示，物品的包装标志没有消失。
- **应有行为与对照：** JP 拼入同一个缓冲区并把它传给窗口。下游 `UiStatePayload::SetText` 直接采用所传指针，不会补上遗漏说明。
- **修复范围与方式：** 待整个料理文件恢复后修正缓冲区与传参关系，并核实其容量；目前不在汇编中加入修复分支。
- **验证状态：** 尚未接入 `BUGFIX`。先完成所属整个文件的高级语言还原与默认匹配，再实施修复。

[拼接与传参](src/scene_cooking.cc) · [窗口适配器](src/ui_state.cc) · [地区对照](REGIONAL_DIFFERENCES.md#cooking-wrapped-description)

<a id="goddess-rps-options"></a>
### 女神猜拳显示手势与实际分支不一致

- **原版与影响（US、EU、DE）：** 实际选项顺序均为石头、剪刀、布；US／EU 显示石头、布、剪刀，DE 显示剪刀、石头、布。按显示选择可能进入另一手势的结果分支。
- **应有行为与对照：** JP 的菜单显示与三条胜负／结果消息分支一致。
- **修复范围与方式：** 仅重排三个海外版 `TalkChoice3` 的文本实参，不改随机数、胜负判断、连胜累加或奖金。该三项计入下文文本／选项清单，不重复计数。
- **验证状态：** 已接入 `BUGFIX`；四版默认匹配，开启后的核验范围见本轮验收记录。

[四版选项对照](REGIONAL_DIFFERENCES.md#goddess-rps-options) · [JP 脚本](data/scripts/jp/EventScript_TV_HarvestGoddessRockPaperScissors.mary.c) · [US 脚本](data/scripts/us/EventScript_TV_HarvestGoddessRockPaperScissors.mary.c)

## 物品身份、文字含义与排版

<a id="fried-soba"></a>
### 炒荞麦面复用炒乌冬面文本

- **原版与影响（US、EU、DE）：** 食物 `0x89` 复用 `0x86` 的名字和说明，两种菜谱显示同名。
- **应有行为与对照：** JP `0x89` 为「焼きそば」（炒荞麦面），与炒乌冬面不同。
- **修复范围与方式：** 为海外 `0x89` 使用独立名称及说明；英文 Fried Soba、德文 Gebratene Soba 是本工程补译，图标与属性保持原值。
- **验证状态：** 已接入 `BUGFIX`；四版默认匹配，开启后的核验范围见本轮验收记录。

[食物表](src/item.cc) · [JP](data/text/jp/item_2.cc) · [US](data/text/us/item_2.cc) · [DE](data/text/de/item_2.cc)

<a id="wool-x"></a>
### X 级羊毛复用 P 级文本

- **原版与影响（US、EU、DE）：** 物品 `0x0A` 的图标独立，名字与说明却取 `0x09` 的 P 级文本。
- **应有行为与对照：** JP 的 X 级名称和说明与其等级一致。
- **修复范围与方式：** 海外两处均改用 X 级文本，措辞沿用各版本羊毛说明风格，不改变产物属性。
- **验证状态：** 已接入 `BUGFIX`；四版默认匹配，开启后的核验范围见本轮验收记录。

[物品表](src/item.cc) · [JP](data/text/jp/item_3.cc) · [EU](data/text/eu/item_3.cc)

<a id="de-jewels"></a>
### 收集用宝玉与合成秘宝同名

- **原版与影响（DE）：** 收集物 `0x26`、`0x27` 取用对应成品工具的名字，独立说明仍要求集齐九个，零件与成品无法从名字区分。
- **应有行为与对照：** JP、US、EU 分别命名收集物和成品。
- **修复范围与方式：** DE 收集物改用 Kappa-Juwelteil、Wahrheitsjuwelteil（河童／真实宝玉部件），同步说明首行；成品保留原名。这两个名称为本工程补译。
- **验证状态：** 已接入 `BUGFIX`；四版默认匹配，开启后的核验范围见本轮验收记录。

[收集物指针表](src/item.cc) · [DE 工具](data/text/de/item_1.cc) · [DE 收集物](data/text/de/item_3.cc)

<a id="de-food"></a>
### 加强药 XL 名称与失败料理语言错误

- **原版与影响（DE）：** 食物 `0x3A` 说明写 Bodigizer XL，名字却指向普通药；`0x9B–0x9D` 的失败料理名称和说明仍为英文。此前修复只更换了说明指针，遗漏三个名称。
- **应有行为与对照：** 另外三版加强药名称区分 XL；DE 自己的说明首行及失败料理表中已有正确德文。
- **修复范围与方式：** 采用 DE 现有 XL 名称及 Misserfolg（失败）说明。三个漏翻名称补为 `Missl. Getränk`（失败饮料）、`Missl. Topfgericht`（失败锅料理）、`Missl. Dessert`（失败甜点），沿用本作 `Missl. Gericht` 的简称形式及既有 Getränk／Dessert 词汇，锅料理按 JP「鍋に入ってるの」补译。三者最长 17 个单字节字符。重制版 DE 的对应失败料理位置为空，故这些是有本作模板依据的补译，不能标成重制版官方译名。默认分支保留英文名称及原指针。
- **验证状态：** 已接入 `BUGFIX`；四版默认匹配，开启后的核验范围见本轮验收记录。

[食物表](src/item.cc) · [DE 文本](data/text/de/item_2.cc)

<a id="item-description-audit"></a>
### 道具说明残缺、错译与漏翻

本轮逐项对照四版全部 81 项工具、171 项食物、95 项其他道具，合计 1,388 个目录条目及其 2,776 个名称／说明指针字段；同时对照独立文本的内容，避免只查共用指针而漏掉复制到不同地址的错误文字。下表按误导操作、误认物品及阅读缺损分类，编号分别属于对应的工具、食物、其他道具表。

| 分类／条目 | 受影响版与原文问题 | 正确内容与依据 | BUGFIX 处理 |
| --- | --- | --- | --- |
| 操作说明：花种 `0x42/0x43` | US／EU／DE 额外写可在秋季种植 | 月落草种仅春、猫薄荷种仅夏；JP 种子、四版成品花说明一致，`FieldPlot::DayUpdate` 的作物 15／16 分别检查春／夏 | 沿用同版种子的春／夏现成句式，移除秋季 |
| 操作说明：红色魔术草 `0x03` | US／EU／DE 写不可出货，误导玩家丢弃或不出售 | JP 写可以出货；`gProductInfo[0x42]` 为红花提供 200 的出货价 | 仅改为可以出货，蓝花仍不可出货 |
| 用途错配：金刚石 `0x17` | DE 错写用于制作首饰，与奥利哈钢说明的用途相同 | JP／US／EU 写用于制作加工机；同版加工机说明使用 Maschine | 改为用于制作机器，保留矿石名称 |
| 身份错译：赏月团子 `0x96` | US／EU 写烤蔬菜串，DE 写 Gemüse-Kebab（蔬菜烤串） | JP 是串在签上的圆团子；名称仍为 Moon Dumplings／Mondklöße | 按 JP 直译圆团子串，不更换原名称 |
| 配料遗漏：混合果汁 `0x56` | US／EU／DE 沿用水果汁配料，仅列水果 | JP 同时列蔬菜与水果；本作混合奶的配料也保留两者 | 补齐水果和蔬菜，不更改物品属性 |
| 句子残缺：混合奶 `0x59`、番茄酱 `0x60` | DE 分别停在“水果、蔬菜和”“用新鲜的” | JP／US／EU 分别明确牛奶、番茄 | 补齐遗漏的 Milch／Tomaten；混合奶配料行恰为 28 字符，保留原末行饮用／赠送说明，仍为三行 |
| 句子残缺：X 牛奶 `0x21` | DE 末行重复饮用句片段，漏掉出货说明 | 同版其他五级牛奶说明完整 | 保留 X 标题，沿用其他牛奶正文 |
| 食用类型：吐司 `0x92` | DE 沿用饮料的 Selbertrinken（自己喝） | JP／US／EU 为可食用面包；同版相邻食品已有 Selberessen | 使用同版食物的“食用或赠送”句式 |
| 漏翻：唱片 13 `0x4C` | DE 的三行说明完整遗留英文 | 同版唱片 11／12／14／15 已有相同奖励模板 | 套用邻项德文，只将胜数写为 70 |
| 排版缺损：味噌汤 `0x4F` | DE 标题直接粘到正文，缺少换行 | JP／US／EU 分隔标题与说明，同版其他汤类也如此 | 补回一个 `\r\n`，不重译 |
| 拼写：苹果 `0x28`、菠萝汁 `0x64` | US／EU 分别写 eated、Pinapple | 同版物品已有 eaten、Pineapple | 只修正错误拼写 |

**译文边界：** 优先复用同版相邻条目；团子、混合果汁等缺失内容按 JP 直译，并保留原本三行布局。新增或调整的每行不超过 28 个海外字符，不扩大窗口或改变程序读取方式。以上 29 个文本对象仅在受影响版本的 BUGFIX 分支改变；没有重命名正确的地区惯用名称，也没有改动配方、图标、价格或属性。

**指针复用结论：** 除已记录的炒荞麦面、X 羊毛、DE 加强药和宝玉错配外，本轮未发现新的名称指针错配组。六种失败料理的通用失败说明、四季太阳的通用说明属于原本一致的内容，继续直接共用符号。`Topaz` 的坏说明是独立对象，含 Ruby 标题和破损的 Topaz 正文，不等于可以复用正常 Ruby 说明的同一对象。

**验收（2026-11-15，文本校对后）：** 撤回银锤说明替换，保留德版烤苹果原名；混合奶补齐牛奶且保留原末行。四版以 `make -j16` 完整构建，均与各自 baserom 逐字节及 SHA-1 一致。另用正常编译配方开启 BUGFIX 编译四版完整的 `item.cc`；默认／BUGFIX 共八个物品对象的 2,776 项目录记录、5,552 个名称／说明指针重定位全部核对正确。四版 BUGFIX 对象中的文本与转码后的对应源字符串一致，保留的 29 项新增修复均进入预期分支；德版混合奶三行编码长度为 15／28／28 字节，不含换行符和终止零。面粉、烤苹果和餐包在默认及修复分支共用正确的物品标签。此次未重建整版 BUGFIX ROM，亦未逐一实机查看所有道具。

[目录、出货表](src/item.cc) · [季节检查](src/field.cc) · [种子对应作物](src/player_actor.cc) · [英文工具](data/text/us/item_1.cc) · [英文食物](data/text/us/item_2.cc) · [德文食物](data/text/de/item_2.cc) · [德文其他道具](data/text/de/item_3.cc)

<a id="fish-record-names"></a>
### 不同鱼种复用同一显示名

- **原版与影响（US、EU、DE（第二组仅 DE））：** 海外记录 37 复用 22 的名称；DE 记录 46 又复用 18，两项都显示 Thunfisch（金枪鱼）。记录编号和统计字段仍独立。
- **应有行为与对照：** JP 22／37 为ギンブナ／ハクレン；18／46 为カツオ／マグロ（鲣／金枪鱼）。US、EU 的后一组也分别命名。
- **修复范围与方式：** 记录 22 的英文鱼名为 Silver Crucian Carp，US／EU 采用经确认的 14 字符界面短写 Silver Crucian，避免与槽 44 的 Crucian Carp 重名；该短写不宣称是游戏官方简称。DE 沿用重制版德文 Ginbuna，37 保留正确的 Silver Carp／Silberkarpfen。DE 18 为 Bonito，46 独立为 Thunfisch。不改钓获数量、体长或编号。重制版名称来自同级 `SoSFoMTTextDump/SoSFoMTTextDump` 的 JA、US、DE `msg_Item.txt`；英文鱼名依据见[源码命名说明](REGIONAL_DIFFERENCES.md#已确认错误的源码名称整理)。
- **显示长度：** Silver Crucian 为 14 字符，原钓获提示 `You fished a {Var1}.` 展开后为 28 格；纪录界面名称复制上限为 20 字节，因此无需修改提示换行或渲染程序。英文显示文本为 `Silver Crucian`，变量采用 `SilverCrucian`，不附记录编号或日文鱼种后缀。
- **验证状态：** 已接入 `BUGFIX`；四版默认匹配，开启后的核验范围见本轮验收记录。

[名称表](src/fishing_results_data.cc) · [JP 文本](data/text/jp/fishing_results_data.cc) · [DE 文本](data/text/de/fishing_results_data.cc) · [记录编号](include/fomt_constants.mary.h)

<a id="sheep-reception-text"></a>
### 羊祭接待桌使用牛祭提示

- **原版与影响（US、EU、DE）：** 共用接待脚本 `0x0194` 在羊祭开始评审分支仍调用牛祭消息，US／EU 显示 `Cows`（牛），DE 显示 `Kühe`（牛）。这是隔着接待桌交谈的入口；直接与巴利交谈的羊祭脚本 `0x04FC` 文本正常。受影响分支没有年份判断，不能限定为第一年；错误只在提示文字，不改变羊的评审与结果。
- **应有行为与对照：** JP 在同一接待脚本分别使用牛祭和羊祭消息。海外也应在羊祭分支调用适用的消息，不能误用牛祭文字。
- **修复范围与方式：** 仅在海外三版 `BUGFIX` 下增加独立羊祭提示，并替换羊祭分支的一次 `TalkMessage`。羊祭声明与 JP 一样放在文本表末尾的 `Table` 之后；牛祭标签统一为 JP 的 `CowContestJudgingStartPrompt`，关闭开关时仍保留羊祭误用牛祭文本的原行为。完整复用各版本 `0x04FC` 已有的三行台词、换行和等待符：US／EU 为 `It's time for the judging / to begin! / Are you ready?`（评审要开始了，准备好了吗？），DE 为 `Es ist Zeit für die / Bewertung! / Bist du soweit?`（到评审时间了，准备好了吗？）。不另行补译；牛祭仍调用原消息，JP 不改。
- **验证状态：** `make -j16` 四版默认完整构建逐字节及 SHA-1 匹配各自 baserom，四版 BUGFIX 完整构建通过。最终产物中各版 1,329 项脚本目录（含空入口）及 1,328 个 RIFF 边界均有效。相对本次修复前的 BUGFIX 产物，JP 整份 ROM 不变；海外各版只改变脚本 `0x0194`，CODE 仅一个压栈文本索引操作数改变，JUMP 表不变。反解析确认仅羊祭 `TalkMessage` 改为新增项，牛祭及所有评审条件保持原样；新文字逐字节等于该版本已有羊祭台词，三行均不超 28 格。最终命名调整后重新编译的海外脚本块与上述完整构建中的脚本块逐字节一致；默认配置已恢复关闭。这是构建与静态调用核验，未作游戏内复现。

接待脚本：[JP](data/scripts/jp/EventScript_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice.mary.c) · [US](data/scripts/us/EventScript_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice.mary.c) · [EU](data/scripts/eu/EventScript_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice.mary.c) · [DE](data/scripts/de/EventScript_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice.mary.c)。现有羊祭译文：[US](data/scripts/us/EventScript_FestivalEvent_SheepFestival_StartJudgingChoice_Barley.mary.c) · [EU](data/scripts/eu/EventScript_FestivalEvent_SheepFestival_StartJudgingChoice_Barley.mary.c) · [DE](data/scripts/de/EventScript_FestivalEvent_SheepFestival_StartJudgingChoice_Barley.mary.c)。依据为四版脚本及其编译消息引用；没有把社区反馈的年份限定当作代码条件。

<a id="localization-text"></a>
### 其余原文、选项与换行修正

- **原版与影响：** 下表分别记录误导实际时间／物品身份的译文、错误选项、遗漏翻译与窗口排版。它们影响说明或反馈，不能据此推断物品属性、事件奖励也被改写。
- **应有行为与对照：** 依据 JP／其他未出错地区的文本，并核对实际日程、商品 ID、对话角色、窗口读取方式。补译是本工程修正稿，不是官方新译文。
- **修复范围与方式：** 按独立文本对象和选项调用核对；同一问题在多个地区出现时分别验证，不把文本对象数当作机制 bug 数。仅改实际受影响地区；物品名字与说明同步处理。猜拳已在上节说明，下表仅作索引。
- **验证状态：** 已接入 `BUGFIX`；四版默认匹配，146 个文本对象、三处选项实参及三张指南签名页分别核验通过。文本修复会改变对应 STR 内容，不沿用旧批次“脚本 STR 块全部不变”的结论。

| 问题 | 受影响版本 | 原版错误、修正与范围 |
| --- | --- | --- |
| 女神猜拳选项与分支错位 | US、EU、DE | 重排 `TalkChoice3` 的文本实参，使显示依次为石头、剪刀、布；随机数、胜负分支和奖金不变。[四版证据](REGIONAL_DIFFERENCES.md#goddess-rps-options) |
| 露来访星期、酒庄休息日 | US、EU、DE | Monday／Montag 改星期日；酒庄门牌星期日改星期六，与实际脚本、指南一致。[来访](data/scripts/us/EventScript_NPCEvent_LouOrRuby_Introduction.mary.c) · [酒庄](data/scripts/de/EventScript_LocationInteraction_InspectAjaWineryBusinessHoursSign.mary.c) |
| 玛娜把自己说成另一位在场者、莉莉娅声称嫁给凯 | US、EU、DE | 前者改称 Duke；后者按 JP 补译为珀布利成为新娘的感想。[玛娜](data/scripts/us/EventScript_NPCEvent_Cliff_PermanentWineryJob.mary.c) · [莉莉娅](data/scripts/de/EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue.mary.c) |
| 巨石说明误把五级锤写成玩家当前等级 | US、EU、DE | 原句误称玩家的锤已是 LV5；按 JP 改为即使五级锤也不能击碎；不改巨石事件或道具等级。[说明](data/scripts/us/EventScript_LocationInteraction_InspectHugeStoneUnbreakableWithLevel5Hammer.mary.c) |
| 畜棚及牛羊商店将牧草称作鸡饲料 | US、EU、DE | 改为 Fodder／Viehfutter。[畜棚](data/scripts/us/EventScript_LocationInteraction_InspectBarnFeedStorageEmptyNotice.mary.c) · [商店](data/text/de/scene_yodel_ranch_shop_2.cc) |
| 商人姓名栏与自我介绍不一致；面粉误作花 | US、EU、DE | 商人采用当时联机角色及本作自我介绍中的 Van，不按后世 Lou 的角色归属解释原版；面粉使用 Flour／Mehl，说明同步。[命名依据](#van-name-history) · [食品](data/text/de/item_2.cc) |
| 玩家生日问候错用婴儿语、安娜普通赠礼提到生日 | US、EU | 按 JP 原文补译工作结束问候，去除普通赠礼中的生日限定。[艾利](data/scripts/us/EventScript_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice.mary.c) · [琳](data/scripts/us/EventScript_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice.mary.c) · [安娜](data/scripts/us/EventScript_NPCEvent_Anna_DialogueAndGiftResponses.mary.c) |
| 英文脚本中残留德语、日语及日文助词 | US、EU | 卡特葡萄兼职提示与两选项补译英语；Nappy 香水答谢、扎克重复对话开头补译；去除电视中无意义的日文助词。[卡特](data/scripts/us/EventScript_NPCEvent_Carter_DialogueAndGiftResponses.mary.c) · [Nappy](data/scripts/us/EventScript_NPCEvent_Nappy_DialogueAndWorkChoices.mary.c) · [扎克](data/scripts/us/EventScript_NPCEvent_Zack_DialogueAndGiftResponses.mary.c) |
| 鱼竿说明缺少行分隔 | US、EU | 补充说明行及换行，满足菜单的两行读取，不改菜单格式化逻辑。[工具](data/text/us/item_1.cc) |
| 钓获提示超过行宽后覆盖首字母 | US、EU、DE | US／EU 特殊物品名换至下一行；DE 三个尺寸模板删去鱼名后的多余尾空格。JP 不改。[US 模板](data/scripts/us/EventScript_AchievementEvent_Fishing_MilestoneReward.mary.c) · [DE 模板](data/scripts/de/EventScript_AchievementEvent_Fishing_MilestoneReward.mary.c) |
| Topaz 说明写 Ruby、Dinner Role、Apple Souffl? | US、EU | 更正说明主体、Dinner Roll；按 JP「焼きりんご」补译 Baked Apple。[食品](data/text/us/item_2.cc) · [矿石](data/text/us/item_3.cc) |
| Sopha、Barely、Lillian、ready Basil、anythign | US、EU | 按实际对象与句意修正拼写；不变更脚本条件。[诊所](data/scripts/us/EventScript_LocationInteraction_InspectClinic1FSofa.mary.c) · [玛娜](data/scripts/us/EventScript_NPCEvent_Manna_DialogueAndGiftResponses.mary.c) · [商人](data/text/us/scene_special_merchant_shop.cc) |
| 露的料理名、通信选项、收获计数误文 | DE | Apfelauflauf 与本版食品表一致；Ja／Nein；收获栏目改 Geerntet／Fehler。[露](data/scripts/de/EventScript_NPCEvent_LouOrRuby_DailyDialogueAndCookingRecipes.mary.c) · [联机](data/text/de/scene_gamecube_link.cc) · [收获](data/text/de/scene_harvesting_minigame_2.cc) |
| 文字中残留 `ret>`／`<RET>` | US、EU、DE | 这些字面字符没有对应显示控制分支；在语句应换行处改为实际的 `\r\n`，不添加新的控制符解释器。[DE 节目提醒](data/scripts/de/EventScript_TV_MechabotUltrorZero_EpisodeReminders.mary.c) · [消息读取](src/ui_text_stream.cc) |
| 满行后的多余空格覆盖行首 | JP、US、EU、DE | 仅删除已确认正文占满 28 个半角格后溢出的尾空格；不删普通缩进和有意义空白，不自动重排其他长文本。[回绕规则](src/ui_text_rows.cc) |
| 凯生日贺卡签名前残留制表字节 | US、EU、DE | 三版原 ROM 均为 `09`，源码转义写法不同不能作为实际字节不同的依据；移除该前缀，保留签名缩进。指南此处不处理制表控制。[贺卡](data/text/us/reference_guide/birthday_card_kai.cc) |

**读取和布局边界。** US／EU 普通鱼竿原文 `Fishing RodFor fishing.`（鱼竿／用于钓鱼）缺少首行 `\r`；格式化循环不会因终止零停止，因而越过本对象读取铜鱼竿文本。修复补齐两行及分隔，不在菜单函数中另作行为修改。钓获提示则按实际物品名展开：US／EU 漂流瓶 33 格、海贼宝藏 29 格，DE 四种长鱼名所在模板 29 格，超过 28 格后回到本行覆盖开头。修复只调整这些消息的换行／尾空格，不增加游戏自动换行机制。[说明格式化](src/game_menu.cc) · [鱼竿文本](data/text/us/item_1.cc) · [钓获取名](src/fishing.cc) · [列号回绕](src/ui_text_rows.cc) · [US 消息](data/scripts/us/EventScript_AchievementEvent_Fishing_MilestoneReward.mary.c) · [DE 消息](data/scripts/de/EventScript_AchievementEvent_Fishing_MilestoneReward.mary.c)

**角色与选项依据。** 琳／艾利生日晚餐的婴儿语由妻子姓名栏与头像后的消息调用确认，发生在是否生育的分支之前，不批量替换孩子的正常婴儿语。安娜普通赠礼错称生日不会改变独立生日乘数；班的姓名栏与自我介绍不一致来自角色名表，未改变角色 ID。DE 收获栏目误用喂食词只影响标签，成绩仍读取收获／失败计数。[琳生日](data/scripts/us/EventScript_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice.mary.c) · [安娜赠礼](data/scripts/us/EventScript_NPCEvent_Anna_DialogueAndGiftResponses.mary.c) · [班介绍](data/scripts/us/EventScript_NPCEvent_Van_Introduction.mary.c) · [收获显示](src/scene_harvesting_minigame.cc)

**补译与排版原则。** 先比对本作同场景、同类型现有台词；没有可直接复用的，参考重制版相应日英对话，仍以 GBA 的上下文与日文含义为准。卡特的兼职提示参考重制版，两个选项沿用本作其他村民的英语选项；Nappy 的香水答谢参考重制版同一赠礼反应。所用本地参考为 `SoSFoMTTextDump/US/msg_Scr_Talk.txt` 与对应日文文本，属于单份游戏文本导出材料，不能据此断言每版官方措辞相同。莉莉娅的婚礼感想和扎克的夸奖按本作日文直译，后者保留原两页，不另加情绪或台词。它们是本工程补译，不冒充官方英文原文。

巨石的名称保留各地区原称，只修“即使 LV5 也无法击碎”的描述，维持三行正文及原有输入等待位置。鱼竿等物品说明以三行相邻字符串展示；空的 `""` 只是源码排版，不会额外产生换行或终止符。纯排版与变量命名调整分别提交，不混入行为修复。

**同类遗漏检查的边界。** 本轮还修正了 13 处残留换行记号及 43 处满行后多余空格，逐处保留关闭开关时的原始字节。其余静态行宽候选仍需结合具体窗口、变量长度和调用路径确认，不列为已修复，更不宣称全部文本布局问题已清除。`ret>` 的具体历史生成来源没有证据；这里只确认当前程序不会将它解释为换行。

<a id="van-name-history"></a>
**Van／Lou／Ruby 的命名取舍。** 本作海外商人的姓名栏为 Lou，而其英语自我介绍明确写 Van。这是本作内部命名不一致；不能用重制版中 Lou 的身份反推当年是“误用了另一角色的名字”。本次选择 Van，是与本作自我介绍和当时联机商人的惯用名称统一，未改角色编号或料理来访者姓名。

| 时代／作品 | 与本次判断相关的名称 | 证据与范围 |
| --- | --- | --- |
| NGC《A Wonderful Life》与 GBA 联机时期 | 商人为 Van；旅馆料理角色旧英文名 Ruby；本仓库 GBA 姓名栏另有 Lou、Lu 的写法 | GBA 的 Van 自我介绍与角色名表为直接证据；跨作品旧名由下列系列资料补充，不把 GBA 各处称呼强行当成一致。 |
| NDS《Harvest Moon DS》 | 商人 Van、旅馆经营者 Ruby | [Van](https://fogu.com/hm6/chan3/villagers/van.php) · [Ruby](https://fogu.com/hm6/chan3/villagers/ruby.php)，均为社区攻略资料。 |
| NS 等平台《Story of Seasons: Friends of Mineral Town》 | 料理来访者使用 Lou，旧系列名为 Ruby | [Lou 的身份与旧名说明](https://fogu.com/sos3/mineral_town/villagers/lou.html)。这是后来的命名沿革，不作为覆盖 GBA 全部译名的规则。 |

跨作品历史参考主要来自同一社区资料站，可靠性低于本作可直接核对的文本；此次修复的核心依据仍是 [GBA 自我介绍](data/scripts/us/EventScript_NPCEvent_Van_Introduction.mary.c) 与 [姓名栏](data/text/us/npc_collection.cc) 的不一致。

## 先前批次验收记录

以下保留早先批次的核验范围与数量；后续指南最小修复和羊祭接待桌修复的验收以各自条目为准。

| 验收层级 | 要求 | 当前状态 |
| --- | --- | --- |
| 默认四版 | 正常编译，每版逐字节与对应 baserom 相同，并确认 SHA-1 | 四版均通过 |
| 开启原生修复 | 检查受影响分支与数据／文本指针，不应改变无关地区行为 | 受影响函数的对象指令／重定位差异及表指针通过核对；不声称完整运行复现 |
| 开启 Mary 修复 | 检查每版 1,328 个脚本入口、RIFF 边界、文本及选项引用，变更集合与源码开关一致 | 四版均通过；猜拳的指令与跳转表另按下文直接核对 |
| 恢复默认 | 还原配置，确认默认产物仍匹配 | 四版均通过，提交配置保持关闭 |

本轮默认构建及恢复默认后均通过的 SHA-1：JP `a655b2789aed14a6ac78c6075fbc533d3062dbe3`；US `a2fc3574f0a65a4fcf7682fb274b9d7eebdef963`；EU `7ba1ec1e46ce424e3c6fd72e4e8d5e9eb5ede247`；DE `60f2a30b55c0e32754897b4d5df6ce06f8b71a37`。

本轮检查了四版各 1,329 项脚本索引（含首项空指针）及 1,328 个 RIFF 脚本。开关造成的脚本变更分别为 JP 4、US 36、EU 36、DE 25 个，均与源码条件分支集合一致。146 个普通／脚本文本对象逐项检查编码字节、所属 STR 范围；物品与鱼名表检查实际目标符号。

对 101 个变更脚本追加反解析，98 个成功；三个海外猜拳脚本触发当前 Mary 的字符串映射错误，不能将其记作反解析通过。这三处改用 VM 指令直接验收：每版 CODE 只改变两个 `0x23` 压栈立即数，调用仍为 `0x28`（TalkChoice3），字符串池与 JUMP 块完整不变；实际字符串索引顺序分别为 Rock／Scissors／Paper 或 Stein／Schere／Papier（石头／剪刀／布）。未修改 Mary 或增加游戏兼容补丁。

指南逐页检查 JP 137、US 138、EU 138、DE 139 张物理行表及各版 137 项总目录：行指针均有效，目录顺序和行数不变；只更改海外凯贺卡的签名前缀。名称展开的 103 个局部检查覆盖已有名称标记、数字标签、单／双字节、字段容量和输出边界，全部通过。

原生对象对照中，幼畜好感度、联机末字符、牛羊售价和失败窗口状态仅 JP 改变；包装图标仅 JP／US 改变；指南展开四版改变。其余对应版本的这些函数代码及重定位保持一致。这些比较是对修复范围的检查，不能代替实际游玩确认。

编译、字节、脚本及指针验收不等同于逐个事件的游玩复现。婚期生日、动物照料记录、料理包装说明三项仍未接入开关，不应列入已修复数量。

## 本轮新增调用与选项修复（已完成统一构建及产物核对）

<a id="audit-a01"></a>
### A01．德版琳怀孕时医生复用答谢

- **原版表现：** 医生与琳共用 `Danke.`（谢谢），医生未解释病情。
- **正确内容与依据：** JP／US／EU在此说明妻子不是生病；DE玛丽怀孕事件已有 `Deine Frau ist nicht krank.`（你的妻子不是生病）。
- **修复方式：** 在琳答谢之后新增独立医生文本，仅切换医生的那次调用，琳答谢保留。 BUGFIX关闭时保留原文本及引用。
- **验证状态：** 已在完整修复集内通过四版默认SHA-1、开启构建及实际文本／调用核对；未逐项实机复现。

[EventScript_FamilyEvent_Ann_PregnancyDiscovery.mary](data/scripts/de/EventScript_FamilyEvent_Ann_PregnancyDiscovery.mary.c) · [EventScript_FamilyEvent_Mary_PregnancyDiscovery.mary](data/scripts/de/EventScript_FamilyEvent_Mary_PregnancyDiscovery.mary.c) · [四版原文](TEXT_SYMBOL_AUDIT.md#a01)

<a id="audit-a02"></a>
### A02．德版玛丽怀孕末尾复用妻子台词

- **原版表现：** 黑屏中的玩家独白重复玛丽通知父母、邀请回家的话。
- **正确内容与依据：** JP及英文是玩家即将当父亲的喜悦；复用DE琳怀孕末尾已有的玩家独白。
- **修复方式：** 在文本表末尾恢复玩家独白，仅替换事件结尾引用，不改变玛丽先前台词。 BUGFIX关闭时保留原文本及引用。
- **验证状态：** 已在完整修复集内通过四版默认SHA-1、开启构建及实际文本／调用核对；未逐项实机复现。

[EventScript_FamilyEvent_Mary_PregnancyDiscovery.mary](data/scripts/de/EventScript_FamilyEvent_Mary_PregnancyDiscovery.mary.c) · [EventScript_FamilyEvent_Ann_PregnancyDiscovery.mary](data/scripts/de/EventScript_FamilyEvent_Ann_PregnancyDiscovery.mary.c) · [四版原文](TEXT_SYMBOL_AUDIT.md#a02)

<a id="audit-a03"></a>
### A03．德版里克婚礼重复珀布利调侃

- **原版表现：** 切换到里克姓名及肖像后仍重复珀布利的调侃。
- **正确内容与依据：** JP里克否认并邀请两人参加今天的婚礼；DE普通婚礼已有 `Unsere Hochzeit ist heute.`（今天是我们的婚礼）。重制版未找到对应情敌婚礼台词。
- **修复方式：** 沿用本作邀请句，按JP补齐否认与邀请双方；保留珀布利原调用。 BUGFIX关闭时保留原文本及引用。
- **验证状态：** 已在完整修复集内通过四版默认SHA-1、开启构建及实际文本／调用核对；未逐项实机复现。

[EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_CeremonyWithPopuriIntroduction.mary](data/scripts/de/EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_CeremonyWithPopuriIntroduction.mary.c) · [EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_Ceremony.mary](data/scripts/de/EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_Ceremony.mary.c) · [四版原文](TEXT_SYMBOL_AUDIT.md#a03)

<a id="audit-a04"></a>
### A04．德版Nappy一天收获委托说成一周

- **原版表现：** 一天与一周的确认共用一周文本，实际工作参数仍为一天。
- **正确内容与依据：** 其他版本分别提供一天和一周的收获确认。新增德文沿用既有收获确认句式，并参考一天浇水句中的 einen Tag（一天）；这些仅为措辞依据，实际只替换一天收获分支，三天和一周分支保持原样。
- **修复方式：** 增加一天收获确认，仅替换一天分支；工作参数不改。 BUGFIX关闭时保留原文本及引用。
- **验证状态：** 已在完整修复集内通过四版默认SHA-1、开启构建及实际文本／调用核对；未逐项实机复现。

[EventScript_NPCEvent_Nappy_DialogueAndWorkChoices.mary](data/scripts/de/EventScript_NPCEvent_Nappy_DialogueAndWorkChoices.mary.c) · [四版原文](TEXT_SYMBOL_AUDIT.md#a04)

<a id="audit-a05"></a>
### A05．德版一亿鱼成就复用一千万台词

- **原版表现：** 一亿阈值的分支仍显示10.000.000。
- **正确内容与依据：** 四版条件均为100000000，JP／US／EU显示一亿。
- **修复方式：** 复制本版完整成就消息，仅将数字修为100.000.000，拆开错误复用。 BUGFIX关闭时保留原文本及引用。
- **验证状态：** 已在完整修复集内通过四版默认SHA-1、开启构建及实际文本／调用核对；未逐项实机复现。

[EventScript_AchievementEvent_Fishing_MilestoneReward.mary](data/scripts/de/EventScript_AchievementEvent_Fishing_MilestoneReward.mary.c) · [四版原文](TEXT_SYMBOL_AUDIT.md#a05)

<a id="audit-a06"></a>
### A06．德版贤者锤领取提示使用秘银锤名

- **原版表现：** 领取 `ITEM_TOOL_HAMMER_MYTHIC` 时变量填入Mythrilhammer。
- **正确内容与依据：** 其他版本区分两种锤；本版物品表已有Mythischer Hammer（贤者锤）。
- **修复方式：** 新增正确工具名称，仅替换贤者锤订单的文本变量引用；实际给予物品不改。 BUGFIX关闭时保留原文本及引用。
- **验证状态：** 已在完整修复集内通过四版默认SHA-1、开启构建及实际文本／调用核对；未逐项实机复现。

[EventScript_ShopEvent_Blacksmith_OrderCounter.mary](data/scripts/de/EventScript_ShopEvent_Blacksmith_OrderCounter.mary.c) · [四版原文](TEXT_SYMBOL_AUDIT.md#a06)

<a id="audit-a07"></a>
### A07．海外艾利产后生日选项错位

- **原版表现：** 产后继续显示纪念日、玩家生日、艾利生日，但第二选项才是正确答案。
- **正确内容与依据：** JP产后为玩家、艾利、孩子生日；孩子称呼沿用同语言女神生日选项。
- **修复方式：** 恢复孩子生日选项，并按原来的正确答案位置重排产后菜单；产前菜单与好感判定不改。 BUGFIX关闭时保留原文本及引用。
- **验证状态：** 已在完整修复集内通过四版默认SHA-1、开启构建及实际文本／调用核对；未逐项实机复现。

[EventScript_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice.mary](data/scripts/us/EventScript_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice.mary.c) · [EventScript_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice.mary](data/scripts/eu/EventScript_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice.mary.c) · [EventScript_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice.mary](data/scripts/de/EventScript_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice.mary.c) · [四版原文](TEXT_SYMBOL_AUDIT.md#a07)

<a id="audit-a08"></a>
### A08．海外女神产前生日选项错位

- **原版表现：** 产前按女神生日、纪念日、玩家生日显示，实际第三项才奖励。
- **正确内容与依据：** JP为纪念日、玩家生日、女神生日；海外现有字符串足够恢复正确菜单。
- **修复方式：** 只调整产前菜单参数顺序，产后已经正确的菜单和判定保持不变。 BUGFIX关闭时保留原文本及引用。
- **验证状态：** 已在完整修复集内通过四版默认SHA-1、开启构建及实际文本／调用核对；未逐项实机复现。

[EventScript_FamilyEvent_HarvestGoddess_EveningDateChoice.mary](data/scripts/us/EventScript_FamilyEvent_HarvestGoddess_EveningDateChoice.mary.c) · [EventScript_FamilyEvent_HarvestGoddess_EveningDateChoice.mary](data/scripts/eu/EventScript_FamilyEvent_HarvestGoddess_EveningDateChoice.mary.c) · [EventScript_FamilyEvent_HarvestGoddess_EveningDateChoice.mary](data/scripts/de/EventScript_FamilyEvent_HarvestGoddess_EveningDateChoice.mary.c) · [四版原文](TEXT_SYMBOL_AUDIT.md#a08)

<a id="audit-a09"></a>
### A09．JP及DE卡莲婚后询问玩家婚姻状态错误

- **原版表现：** JP两个晴天复谈地点的已婚／未婚台词反向；DE三个分支额外显示与婚姻状态相反的话。
- **正确内容与依据：** US／EU在实际玩家已婚条件下询问婚后生活，未婚时劝婚。
- **修复方式：** JP交换四次相关消息引用；DE删除三次错误的额外消息。保留婚礼完成、地点、天气、首谈／复谈条件及其余有效台词。 BUGFIX关闭时保留原文本及引用。
- **验证状态：** 已在完整修复集内通过四版默认SHA-1、开启构建及实际文本／调用核对；未逐项实机复现。

[EventScript_NPCEvent_Karen_DialogueAndGiftResponses.mary](data/scripts/jp/EventScript_NPCEvent_Karen_DialogueAndGiftResponses.mary.c) · [EventScript_NPCEvent_Karen_DialogueAndGiftResponses.mary](data/scripts/de/EventScript_NPCEvent_Karen_DialogueAndGiftResponses.mary.c) · [四版原文](TEXT_SYMBOL_AUDIT.md#a09)


<a id="audit-a10"></a>
### A10．F-3.14节目日期、跨赛季复用与成绩错误

- **原版及地区差异：** JP冬18—20的预告与成绩错序；海外冬18没有显示对应成绩。DE另有第一赛季末及第二赛季多场内容误用别的赛季，海外冬28重复预告前半。具体日期与原文见[四版审计及扩展核对](TEXT_SYMBOL_AUDIT.md#a10)。
- **正确内容与依据：** 实际日期分派、同一天JP／英文完整正文、每场名次及累计积分共同定位；不能仅按相似符号名或同样的前三名配对。德文缺文优先复用同版表格和句式，确无对应正文的部分按JP原义补齐。
- **修复方式：** 对已有正确文本调整调用；错误共用的对象拆出BUGFIX专用文本；缺失正文与成绩在对应对象附近补回。更正Daisy的两处数值，以及四版Sylvia第三赛季第七战少计一分并延续到后三场的问题。没有改变节目播放机制或添加运行时积分计算。
- **验证状态：** 已按四版各120个日期静态核对成绩和预告，并核对链接产物中的文本字节和实际消息调用顺序；四版默认SHA-1及开启构建通过。未逐项实机复现。

[JP节目](data/scripts/jp/EventScript_TV_F314MGrandPrix.mary.c) · [US节目](data/scripts/us/EventScript_TV_F314MGrandPrix.mary.c) · [EU节目](data/scripts/eu/EventScript_TV_F314MGrandPrix.mary.c) · [DE节目](data/scripts/de/EventScript_TV_F314MGrandPrix.mary.c)


## 本轮指南与实际机制（已完成统一构建及产物核对）

本节各项均由BUGFIX控制；完整修复集已通过四版默认及开启构建和静态产物核对，未逐项实机复现。四版原文及调用依据见各项审计链接。

<a id="audit-b01"></a>
### B01．出荷价格指南：按道具名称列出三个品质的鸡蛋并修正海外胡萝卜价格

- **原版及其他版本：** 见[四版原文与依据](TEXT_SYMBOL_AUDIT.md#b01)。
- **正确内容：** `gProductInfo` 的实际价格。应修指南文字，不改价格表迎合错误说明。
- **修复方式：** 四版均列出普通、好、高品质三种鸡蛋，使用各版本道具名称，价格分别为50／60／80G；海外指南以这三行替换原普通蛋、温泉蛋和金蛋三行。S／M／L仅用于说明等级对应，不写入名称。海外胡萝卜改为120G，未改实际商品价格。
- **验证状态：** 审核修订后仅完成静态核对：默认分支、道具名称、区域编码及行宽均保持有效；本次未重新编译，旧构建哈希对应本次审核修订前。

<a id="audit-b02"></a>
### B02．海外三版：图书馆休馆日变更方向写反

- **原版及其他版本：** 见[四版原文与依据](TEXT_SYMBOL_AUDIT.md#b02)。
- **正确内容：** 通知在玛丽与格雷结婚后送出，婚后营业告示明确是星期四休馆。
- **修复方式：** 将休馆日变更改为星期一改星期四，沿用本版既有星期名称。
- **验证状态：** 已在完整修复集内通过四版默认SHA-1、开启构建及文本／行指针核对；未逐项实机复现。

<a id="audit-b03"></a>
### B03．海外三版：牛羊牧场指南说可以卖鸡

- **原版及其他版本：** 见[四版原文与依据](TEXT_SYMBOL_AUDIT.md#b03)。
- **正确内容：** 此处是牛羊商店，实际菜单出售牛、羊，不出售鸡。
- **修复方式：** 只将可出售动物改为牛与羊，保持牛羊牧场的其他说明。
- **验证状态：** 已在完整修复集内通过四版默认SHA-1、开启构建及文本／行指针核对；未逐项实机复现。

<a id="audit-b04"></a>
### B04．海外三版：诊所营业时间表述错误，德版采用24小时制

- **原版及其他版本：** 见[四版原文与依据](TEXT_SYMBOL_AUDIT.md#b04)。
- **正确内容：** 营业告示是09:00至16:00，英文末尾应为下午。DE 表达不够明确，但没有英文这种显式的 AM 错误。用户随后确认德版也按24小时制修为9–16 Uhr。
- **修复方式：** US／EU改为9AM—4PM；DE改为9—16 Uhr，按本版24小时制。
- **验证状态：** 已在完整修复集内通过四版默认SHA-1、开启构建及文本／行指针核对；未逐项实机复现。

<a id="audit-b05"></a>
### B05．海外三版：料理指南多写一个重复选项

- **原版及其他版本：** 见[四版原文与依据](TEXT_SYMBOL_AUDIT.md#b05)。
- **正确内容：** 食材齐全时的实际调用只有三个选项：`FollowRecipe`、`ImproviseRecipe`、`MakeAnotherRecipe`。指南重复列出返回项，不应新增第四个程序选项。
- **修复方式：** 移除重复的“重新开始”解释，恢复现有料理菜单中的“另选食谱”及返回食谱选择说明。
- **验证状态：** 已在完整修复集内通过四版默认SHA-1、开启构建及文本／行指针核对；未逐项实机复现。

<a id="audit-b06"></a>
### B06．DE：秘银锄头误写成秘银镰刀

- **原版及其他版本：** 见[四版原文与依据](TEXT_SYMBOL_AUDIT.md#b06)。
- **正确内容：** 所在段落描述一次耕前方六格土地，是锄头，不是镰刀。
- **修复方式：** 仅锄头段的Mythrilsichel（秘银镰刀）改为同版Mythrilhacke（秘银锄头）；真正的镰刀段不变。
- **验证状态：** 已在完整修复集内通过四版默认SHA-1、开启构建及文本／行指针核对；未逐项实机复现。

<a id="audit-b07"></a>
### B07．DE：计步器“装备”误译成“升级”

- **原版及其他版本：** 见[四版原文与依据](TEXT_SYMBOL_AUDIT.md#b07)。
- **正确内容：** `aufgerüstet` 指升级；这里的操作是装备计步器，程序没有该段所说的计步器升级。
- **修复方式：** 将计步器的升级动词改为装备动词，不新增计步器升级功能。
- **验证状态：** 已在完整修复集内通过四版默认SHA-1、开启构建及文本／行指针核对；未逐项实机复现。

<a id="audit-b08"></a>
### B08．海外三版：四种作物最终收获阶段写成开花

- **原版及其他版本：** 见[四版原文与依据](TEXT_SYMBOL_AUDIT.md#b08)。
- **正确内容：** 这些行描述上述作物结成果实的收获阶段。修复只涉及四种作物，不能把花卉行中的 Flowers／Blüte 一并替换。
- **修复方式：** 将四种可重复收获作物的成熟阶段改为Ripe／Reife，保留实际花卉的开花说明。
- **验证状态：** 已在完整修复集内通过四版默认SHA-1、开启构建及文本／行指针核对；未逐项实机复现。

<a id="audit-b09"></a>
### B09．海外三版：疲劳段落错写成体力效果

- **原版及其他版本：** 见[四版原文与依据](TEXT_SYMBOL_AUDIT.md#b09)。
- **正确内容：** 当前小节讲疲劳，海外复制了体力小节的含义。不是需要修改食物实际恢复字段。
- **修复方式：** 仅疲劳段改为增加疲劳；不修改前面的体力说明或食物数值。
- **验证状态：** 已在完整修复集内通过四版默认SHA-1、开启构建及文本／行指针核对；未逐项实机复现。

<a id="audit-b10"></a>
### B10．DE：冰箱让一次“购买更多”写成“烹饪更多”

- **原版及其他版本：** 见[四版原文与依据](TEXT_SYMBOL_AUDIT.md#b10)。
- **正确内容：** 杂货店购买说明中，德文 `kochen` 是烹饪，原意是购买。
- **修复方式：** 将冰箱扩容的结果改为一次购买更多，保留既有厨房及储物机制。
- **验证状态：** 已在完整修复集内通过四版默认SHA-1、开启构建及文本／行指针核对；未逐项实机复现。

<a id="audit-b11"></a>
### B11．海外三版：霍安出售的种子是否随季节变化，含义写反

- **原版及其他版本：** 见[四版原文与依据](TEXT_SYMBOL_AUDIT.md#b11)。
- **正确内容：** 商店实现连续加入七种种子，没有对这些种子进行季节筛选。US／EU 附近还有一条孤立的 `different seasons.` 残句，可一并核对排版。
- **修复方式：** 明确霍安全年出售相同种子；保留种植仍受季节限制的说明。
- **验证状态：** 已在完整修复集内通过四版默认SHA-1、开启构建及文本／行指针核对；未逐项实机复现。
