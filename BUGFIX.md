# 原版问题与可选修复

本文按问题类型统一记录JP、US、EU、DE原版中的缺陷。每项直接列出原版内容、版本差异、判断依据、修复方式及相关文件；正常地区规则不自动视为BUG。依据以本工程的代码、数据和脚本为主，补文参考按本作同语同类文本、重制版、日版含义的顺序选择；具体采用来源在条目内说明。

## 启用方法

在 [include/config.h](include/config.h) 中取消以下定义的注释：

```c
#define BUGFIX
```

然后使用原有构建命令，例如：

```sh
make -j16 GAME_REGION=JP all
```

美版、欧版、德版分别将 `GAME_REGION` 改为 `US`、`EU`、`DE`。[Makefile](Makefile) 会把同一个开关传给原生源码和Mary脚本。重新注释该定义即可恢复原版内容；不需单独修改Mary的宏。当前索引所列问题均已接入此开关。

## 分类索引

新增问题按类型放入对应章节，沿用“受影响版本、原版内容与差异、判断依据、修复方式、相关文件”的结构，同时补入该分类的索引。一个根因只建立一个条目，相关版本和出现位置写在同一项；保留稳定锚点供源码与其他文档引用。

| 分类 | 内容 | 条目数 |
| --- | --- | ---: |
| [流程控制、读取边界与联机](#category-control) | 循环终止、表读取边界、频道输入、协议和窗口状态。 | 8 |
| [养成、经济与事件条件](#category-mechanics) | 实际恢复、价格、好感度、种植、矿层掉落及事件条件。 | 11 |
| [菜单选项、记录与显示](#category-interface) | 选项对应、图标、计数标签、帮助与操作提示。 | 16 |
| [道具身份、名称与说明](#category-items) | 道具指针复用、物品名称、用途、配料与说明文字。 | 24 |
| [剧情对话、人物与称呼](#category-dialogue) | 对话调用、人物身份、时间和剧情含义。 | 36 |
| [指南结构、正文与玩法说明](#category-guides) | 标题、解锁边界、缺失介绍及指南规则。 | 33 |
| [电视节目内容](#category-television) | 节目错序、成绩、机制提示和故事文字。 | 22 |
| **合计** | | **150** |

<a id="category-control"></a>
## 流程控制、读取边界与联机

| 问题 | 受影响版本 | 开关支持 |
| --- | --- | --- |
| [脚本加载器多读末尾块头](#riff-end) | 四版 | 已接入 |
| [矿洞权重复制上限互换与湖矿深层误判](#mine-item-weight-copy-bounds) | 四版 | 已接入 |
| [指南名称标记漏展开与缓冲区越界](#guide-name-expansion) | 四版（标记漏展开已命中 US／EU／DE 原文） | 已接入 |
| [海外 4:44 电视反复重入](#tv-444) | US、EU、DE | 已接入 |
| [人物介绍节目未接收频道输入](#de-profile-tv) | DE | 已接入 |
| [联机失败消息沿用旧窗口状态](#jp-link-retry) | JP | 已接入 |
| [联机名称拒收最后一个有效字符](#jp-link-last-character) | JP | 已接入 |
| [春 19 日入门节目贯穿下一日分支](#de-farm-tv) | DE | 已接入 |

<a id="riff-end"></a>
### 脚本加载器多读末尾块头

**受影响版本：** 四版。

**原版内容与差异：**

RIFF 的 `length` 是从脚本开头起算的结束位置；原循环仍在 `offset == length` 时读取八字节块头。四版各 1,328 个正常脚本均会读到块外。终点后的后继内容不属于当前脚本块，不能继续作为块头读取。

**判断依据：**

读到终点就停止；四版都存在此问题，没有正常地区实现可直接沿用。依据是 RIFF 边界与读取器消费关系。

**修复方式：**

四版把 `offset <= length` 改为 `offset < length`。范围仅为合法脚本的终点判定。

**相关文件：** [加载器](src/script_vm.cc)

<a id="mine-item-weight-copy-bounds"></a>
### 矿洞权重复制上限互换与湖矿深层误判

**受影响版本：** 四版。

**原版内容与差异：**

当前矿层的权重复制函数把湖矿和泉矿的列数互换。矿种判断将 10 位地图编号按有符号数比较，湖矿 B204–B255（`0x200–0x233`）因此进入泉矿分支，并用泉矿起点计算楼层。四版行为相同。

| 矿洞 | 权重类型 | 原版复制列数 | 实际列数 |
| --- | --- | ---: | ---: |
| 湖矿 | 埋藏 | 5 | 10 |
| 湖矿 | 岩石 | 10 | 14 |
| 泉矿 | 埋藏 | 10 | 5 |
| 泉矿 | 岩石 | 14 | 10 |

**判断依据：**

湖矿分支少复制 5 个埋藏权重和 4 个岩石权重。泉矿分支从选定的权重行及相应道具编号表越界读取，读出的编号也可能导致写入越过调用方缓冲区。湖矿 B203 的地图编号为 `0x1FF`，B204 的编号 `0x200` 置位第 10 位，有符号比较将它判为泉矿。楼层减法使用完整编号，B204 因为减去泉矿起点 `0x34`，向泉矿权重行选择器传入 460。原版四版中尚未发现此复制函数的直接调用者，实际游玩影响仍未确认。

**修复方式：**

开启 `BUGFIX` 时，矿种判断使用无符号比较，楼层减法按选中的矿种起点计算。湖矿分支的埋藏和岩石复制上限分别为 10 和 14，泉矿分支分别为 5 和 10。关闭开关时使用原版比较类型和复制上限。

**相关文件：** [权重复制](src/mine_floor.cc#L949) · [地图编号字段](include/actor.hh#L16) · [权重行宽](include/mine_floor_items.h) · [道具编号与权重表](src/mine_floor_items.c) · [原版入口审计](CODE_ROM_LAYOUT.md#L13096)

<a id="guide-name-expansion"></a>
### 指南名称标记漏展开与缓冲区越界

**受影响版本：** 四版（标记漏展开已命中 US／EU／DE 原文）。

**原版内容与差异：**

普通内容固定按两个字节推进，海外落在奇数字节偏移的名称标记被漏过。四版“最多十四轮”也不限制实际写入字节数；一次名称展开可写入多字节，调用者的 32 字节缓冲区可能被越过。

**判断依据：**

正确识别现有名称标记，在字符串结束处停止读取，且现有文本展开后应容纳于调用者的缓冲区。现有海外指南有六个漏展开的地区／行组合；JP标题尾空格及DE高仓介绍在展开最大长度名称时会越界。

**修复方式：**

JP 仅在 BUGFIX 下删除联机玩家介绍标题的尾部全角空格；接收名称占满 14 字节时，标题含结束符为 25 字节。海外保留原来的双字节复制、名称展开及 14 次循环上限，仅在普通内容第二字节为 `00` 时复制首字节后结束，为 `<` 时只复制首字节并前进一字节，让下一轮识别完整标记。`00`／`3C` 均不是合法 Shift-JIS 尾字节。DE 高仓介绍前两行按原用词重新分为三行，为正常展开的姓名留出空间。

现有名称标记包括 `<p>`、`<f>`、`<cp>`、`<cf>`、`<cs>`。例 `Dear <p> and` 中 `<` 落在普通两字节步进的第二字节时会被跳过。保持原14次循环，不添加通用截断或自动换行；JP尾空格与DE高仓介绍按现有名称长度调整。

**相关文件：** [实现与调用者](src/scene_reference_page.cc) · [名称字段](include/game_state_types.hh)

<a id="tv-444"></a>
### 海外 4:44 电视反复重入

**受影响版本：** US、EU、DE。

**原版内容与差异：**

初始入口与换台入口在 04:44、16:44 都漏调隐藏节目，随后读取本分支未赋值的 `var_1`。VM 初值 0 对应天气频道，于是重入换台脚本；若时间仍在原分钟，会重复进入。

**判断依据：**

JP 在设为无信号后调用隐藏节目，由该节目处理播放和结束。海外也保留了完整节目本体，应从两处入口转入它。

**修复方式：**

只为三个海外版的两个入口补上本版隐藏节目调用；保留节目原有星期、日期、重复次数和文本。

**相关文件：** [JP 入口](data/scripts/jp/EventScript_TV_ChannelDispatcher.mary.c) · [US 初始入口](data/scripts/us/EventScript_TV_ChannelDispatcher.mary.c) · [US 换台入口](data/scripts/us/EventScript_TV_EntertainmentChannel.mary.c) · [隐藏节目](data/scripts/us/EventScript_TV_4AMHiddenBroadcast.mary.c) · [VM 初始化](src/script_vm.cc)

<a id="de-profile-tv"></a>
### 人物介绍节目未接收频道输入

**受影响版本：** DE。

**原版内容与差异：**

第 36 项改用无返回值的慢速对话，关闭窗口后又读取尚未赋值的 `var_0`；默认值 0 把流程转入天气频道，忽略本应接收的频道选择。

**判断依据：**

JP、US、EU 使用 `var_0 = ShowTelevisionMessage(...)`，将输入送入后续分派。

**修复方式：**

仅恢复 DE 该项的电视消息调用与返回值保存；其他慢速台词保持原样。与 4:44 问题分开处理。

**相关文件：** [DE 分派](data/scripts/de/EventScript_TV_MineralTownFriends_CharacterProfiles.mary.c) · [US 对照](data/scripts/us/EventScript_TV_MineralTownFriends_CharacterProfiles.mary.c) · [频道定义](include/fomt_constants.mary.h)

<a id="jp-link-retry"></a>
### 联机失败消息沿用旧窗口状态

**受影响版本：** JP。

**原版内容与差异：**

协议同次更新先进入 `EnterRetry` 再调用 `PollRetry`。新消息只重置窗口自身，未重置场景缓存；缓存仍为完成状态 3 时，选择框可能在失败消息首次绘制前出现。

**判断依据：**

海外将场景缓存设为 4，等待新消息完成。

**修复方式：**

JP 在重试入口同步设置 `ui_state = 4`，不改变通信协议或存档内容。

**相关文件：** [场景与协议调用顺序](src/scene_gamecube_link.cc) · [重试回调实现](include/scene_gamecube_link_callbacks.hh) · [窗口状态](src/ui_state.cc)

<a id="jp-link-last-character"></a>
### 联机名称拒收最后一个有效字符

**受影响版本：** JP。

**原版内容与差异：**

编码发送一基索引，0 为结束符；接收端却按未减 1 的值检查范围，拒绝最后合法字符 `※`，并停止读取后续字符。

**判断依据：**

海外先减 1 再检查，与编码端覆盖的非终止字符范围相同。

**修复方式：**

JP 按一基协议修正边界，不扩大字符表、包长或存档字段。

**相关文件：** [编解码](src/gamecube_link_save.cc) · [JP 字符表](data/text/jp/gamecube_link_save.cc) · [协议结构](include/gamecube_link_save.hh)

<a id="de-farm-tv"></a>
### 春 19 日入门节目贯穿下一日分支

**受影响版本：** DE。

**原版内容与差异：**

春 19 日消息后少 `break`，连续播放春 20 日内容，并以第二次调用返回值覆盖第一次频道输入。

**判断依据：**

JP、US、EU 在春 19 日消息后结束该分支。

**修复方式：**

仅补 DE 分支结束；保持 19 日消息及频道选择。

**相关文件：** [DE 节目](data/scripts/de/EventScript_TV_LifeOnTheFarm_Beginner.mary.c) · [US 对照](data/scripts/us/EventScript_TV_LifeOnTheFarm_Beginner.mary.c)

<a id="category-mechanics"></a>
## 养成、经济与事件条件

| 问题 | 受影响版本 | 开关支持 |
| --- | --- | --- |
| [小鱼与大鱼出货价倒置](#fish-prices) | JP | 已接入 |
| [获奖牛羊的高等级售价倒置](#jp-livestock-sale-prices) | JP | 已接入 |
| [入睡时间被早晨时间覆盖](#jp-sleep-time) | JP | 已接入 |
| [幼畜出生好感度计算错误](#jp-birth-affection) | JP | 已接入 |
| [艾利确认第二个昵称但未保存](#elli-nickname) | US、EU | 已接入 |
| [婚期未完整避开双方生日及节日事件](#jp-wedding-birthdays) | JP | 已接入 |
| [玩家已娶别人仍显示琳的爱心](#ann-heart) | 四版 | 已接入 |
| [JP及DE卡莲婚后询问玩家婚姻状态错误](#audit-a09) | JP、DE | 已接入 |
| [杂货店咖喱粉货架报价错误](#curry-powder-price) | US、EU、DE | 已接入 |
| [湖矿 B201–B250 的整十层选错岩石权重](#lake-mine-decade-rock-weights) | 四版 | 已接入 |
| [日版牧草在冬季继续生长](#jp-winter-grass-growth) | JP | 已接入 |

<a id="fish-prices"></a>
### 小鱼与大鱼出货价倒置

**受影响版本：** JP。

**原版内容与差异：**

小、中、大鱼分别卖 200、120、50 G，与日版游戏内《出货价格》矛盾。

**判断依据：**

JP 指南及三个海外版数据均为 50、120、200 G。

**修复方式：**

仅交换 JP 小鱼和大鱼的出货价格，中鱼与其他物品不变。

**相关文件：** [商品表](src/item.cc) · [JP 指南](data/text/jp/reference_guide/sell_price.cc) · [US 指南](data/text/us/reference_guide/sell_price.cc)

<a id="jp-livestock-sale-prices"></a>
### 获奖牛羊的高等级售价倒置

**受影响版本：** JP。

**原版内容与差异：**

基础等级 3／4 的牛为 7,000／6,000 G，羊为 5,000／4,000 G。两档均已获奖且好感度超过 200；累计户外达到 600 小时后等级升至 4，却少卖 1,000 G。报价直接用于入账。

**判断依据：**

海外同档牛为 6,000／7,000 G，羊为 4,000／5,000 G；较高等级对应较高价格。

**修复方式：**

仅交换 JP 牛、羊两组高等级返回值，保留低等级和未知种类的原有默认值；不改变生产 X 级产物的随机过程。

**相关文件：** [售价与入账](src/scene_yodel_ranch_shop.cc) · [等级条件](src/livestock.cc)

<a id="jp-sleep-time"></a>
### 入睡时间被早晨时间覆盖

**受影响版本：** JP。

**原版内容与差异：**

先设为 06:00，再保存包含当前时间的次日状态，后续按保存的 6 计算出 24 小时恢复。小时效果为体力 +7／疲劳 −2，普通床另加 +50／−5；边界裁剪前合计 +218／−53，普通床流程因而压住了要求剩余疲劳至少 50 的睡过头分支。

**判断依据：**

海外先保存实际入睡时间，再设为 06:00；恢复小时数为 `(hour <= 5 ? 6 : 30) - hour`。JP 有睡过头代码，问题是前序过量恢复，不能概括成所有过夜路径都不晚起。

**修复方式：**

只交换 JP 次日过渡脚本的两条调用顺序；固定床效果、花瓶与早餐逻辑不改。

**相关文件：** [JP 过渡](data/scripts/jp/EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay.mary.c) · [US 对照](data/scripts/us/EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay.mary.c) · [保存与恢复](src/game_scene.cc) · [床效果](data/scripts/jp/EventScript_LocationInteraction_FarmhouseBedSleepChoice.mary.c) · [晚起判断](data/scripts/jp/EventScript_SystemEvent_SleepRecoveryAndCursedHammerSickleBlessing.mary.c)

<a id="jp-birth-affection"></a>
### 幼畜出生好感度计算错误

**受影响版本：** JP。

**原版内容与差异：**

幼牛路径无条件对母牛好感度的一半取模，低好感度可能令除数为 0；幼羊路径还以空对象作为好感度读取器的接收者。

**判断依据：**

海外读取实际母畜，且只在半好感度大于 1 时调用随机数及取模。应以正确母畜、有效除数计算。

**修复方式：**

JP 对齐这两条计算路径；低好感度的随机数消耗随之与海外一致。不猜测空对象在 BIOS／开放总线环境下必然产生何种崩溃。

**相关文件：** [四版出生实现](src/barn.cc) · [母羊路径原生取证](docs/mary-native-audit/animals/barn_birth_followup_audit.md)

<a id="elli-nickname"></a>
### 艾利确认第二个昵称但未保存

**受影响版本：** US、EU。

**原版内容与差异：**

选择 Honey（亲爱的）后显示确认，却未调用写回函数，实际昵称保留旧值。

**判断依据：**

JP、DE 在确认前调用 `SetPlayerNicknameForSpouse` 保存所选文本。

**修复方式：**

仅在 US、EU 第二选项补上写回，采用当前选项已有字符串；不改其他昵称分支。

**相关文件：** [US](data/scripts/us/EventScript_LoveEvent_Elli_NicknameChoice.mary.c) · [JP](data/scripts/jp/EventScript_LoveEvent_Elli_NicknameChoice.mary.c) · [DE](data/scripts/de/EventScript_LoveEvent_Elli_NicknameChoice.mary.c)

<a id="jp-wedding-birthdays"></a>
### 婚期未完整避开双方生日及节日事件

**受影响版本：** JP。

**原版内容与差异：**

订婚计数达到 5 后立即查询只在计数大于 5 时返回配偶的函数，得到 0 而漏查未婚妻生日；日期经过避让表顺延后，也不重新检查全部生日条件。JP 的避让表另漏掉秋 30 日南瓜祭和冬 25 日托马斯袜子送礼日；海外三版已包含这两天。

**判断依据：**

海外保存婚约对象，并在顺延后重查双方生日及避让条件。例如候选春 17 日、玩家生日春 19 日时，JP 避开春 17、18 日后可能落在未重查的春 19 日。四版日历均登记秋 30 日南瓜祭，每日更新也均在冬 25 日选择托马斯袜子礼物；不是 JP 没有这些事件。日历登记的 17 个固定节日，海外避让表全部包含，JP 只缺秋 30 日；冬 25 日属于日历列表之外的送礼事件。海外表共 27 项，JP 原表为 25 项。

**修复方式：**

JP 开启 `BUGFIX` 后采用海外版已有的婚期计算流程：用本次婚约对象取得生日，每次顺延后重新检查双方生日和避让条件；同时在自己的日期避让表中补入秋 30 日和冬 25 日，与海外已有规则一致。海外三版保持原有流程和表内容。关闭开关时仍使用原版 JP 实现和 25 项日期表。

**相关文件：** [婚期计算](src/script_engine.cc) · [订婚／已婚查询](src/npc_collection.cc) · [日期表](src/wedding_date.cc) · [日历节日](src/scene_calendar_core.cc) · [JP 每日更新](data/scripts/jp/EventScript_SystemEvent_ResetDailyWorldState.mary.c) · [原生证据](docs/mary-native-audit/events/event_state_registration.md)

<a id="ann-heart"></a>
### 玩家已娶别人仍显示琳的爱心

**受影响版本：** 四版。

**原版内容与差异：**

琳尚未与克里夫结婚、玩家已娶其他候补时，在旅馆后屋的重复对话直接显示琳的爱心；首谈会检查其他候补与女神的婚姻标志。

**判断依据：**

重复对话应沿用本版首谈已有的婚姻条件，而非改变琳作为玩家配偶时的正常爱心。四版此处相同。

**修复方式：**

四版重复对话加上首谈条件；保留琳与玩家及与克里夫的原有婚后分支。

**相关文件：** [JP 对话](data/scripts/jp/EventScript_NPCEvent_Ann_DialogueAndGiftResponses.mary.c) · [US 对话](data/scripts/us/EventScript_NPCEvent_Ann_DialogueAndGiftResponses.mary.c)

<a id="audit-a09"></a>
### JP及DE卡莲婚后询问玩家婚姻状态错误

**受影响版本：** JP、DE。

**原版内容与差异：**

| 版本 | 原文与实际情况 |
|---|---|
| JP | 对已婚玩家说 `どうして結婚しないの？`——为什么不结婚？对未婚玩家说 `奥さんとは上手くいってる？`——和妻子相处得好吗？ |
| US＝EU | 已婚：`How are you liking married life...?`；未婚：`Why don't you get married, {Player}?`，对应正确。 |
| DE | 同时存在 `Warum heiratest du nicht, {Player}?` 和 `Wie gefällt dir das Eheleben...?`；部分复谈分支连续调用两句，另有已婚分支仍调用劝婚文本。 |

**判断依据：**

核对的是实际婚姻条件、婚礼完成标志和消息调用，不是根据变量名猜测。JP 是对应关系颠倒；DE 还存在多余调用，需要分别处理具体分支。

US／EU在实际玩家已婚条件下询问婚后生活，未婚时劝婚。

**修复方式：**

JP交换四次相关消息引用；DE删除三次错误的额外消息。保留婚礼完成、地点、天气、首谈／复谈条件及其余有效台词。 BUGFIX关闭时保留原文本及引用。

**相关文件：** [JP 条件](data/scripts/jp/EventScript_NPCEvent_Karen_DialogueAndGiftResponses.mary.c) · [US对应文件](data/scripts/us/EventScript_NPCEvent_Karen_DialogueAndGiftResponses.mary.c) · [EU对应文件](data/scripts/eu/EventScript_NPCEvent_Karen_DialogueAndGiftResponses.mary.c) · [DE对应文件](data/scripts/de/EventScript_NPCEvent_Karen_DialogueAndGiftResponses.mary.c)

<a id="curry-powder-price"></a>
### 杂货店咖喱粉货架报价错误

**受影响版本：** US、EU、DE。

**原版内容与差异：**

调查杂货店咖喱粉货架时，海外台词报每份 100 G，JP 报 50 G。

**判断依据：**

杂货店实际每份收取 50 G。海外三个版本的购物教学也都报 50 G。

**修复方式：**

沿用各版购物教学的价格，将货架台词中的 100 G 改为 50 G。

**相关文件：** [实际购买](src/scene_supermarket.cc) · [US](data/scripts/us/EventScript_ShopEvent_Supermarket_CurryPowderPurchase.mary.c) · [EU](data/scripts/eu/EventScript_ShopEvent_Supermarket_CurryPowderPurchase.mary.c) · [DE](data/scripts/de/EventScript_ShopEvent_Supermarket_CurryPowderPurchase.mary.c) · [购物教学](data/scripts/us/EventScript_TutorialEvent_Shopping_BuyItemsAtStoreCounter.mary.c)

<a id="lake-mine-decade-rock-weights"></a>
### 湖矿 B201–B250 的整十层选错岩石权重

**受影响版本：** 四版。

**原版内容与差异：**

四版 GBA 发行版在 B210、B220、B230、B240、B250 均选岩石权重表索引 43。该行的亚历山大石和粉红钻石权重均为 0，B210 的埋藏表也没有亚历山大石。女版 JP（选择器 `0x080A23A0`）与 US（`0x080A2960`）在这五层也都返回 43。所核六份 GBA ROM 的岩石权重表完全相同，共 56 行，每行 14 字节。

**判断依据：**

逐层核对 GBA 四版从入口（0）到 B255 的 256 个选择结果，56 行中只有索引 53 从未被选中。B201–B250 中，末位 1–9 的楼层依次对应索引 44–52。索引 43 原用于 B120、B140、B160、B180，索引 54 和 55 分别用于 B251–B254 和 B255。索引 53 的位置正好对应这五个整十层，且亚历山大石和粉红钻石的权重各为 1。

GBA 四版《矿场研究》第 8 集都报告在湖矿 B210 发现亚历山大石，PC 重制版的同集英文文本也保留了这条报告。PC 重制版的岩石表确认这五层均可产出两种宝石。RanchStory 转引角川 2019 年官方完全指南，将两种宝石在这五层的掉落率各列为 0.8%，日本玩家的逐层游玩记录也列出相同分布。[RanchStory 湖矿表](https://wiki.ranchstory.farm/index.php/Lake_Mine_%28Story_of_Seasons%3A_Friends_of_Mineral_Town%29) · [日本玩家逐层游玩记录](https://yoshinoso.com/articles/bokumonosmt-play-0034/)

GBA 时期的两份民间攻略记载有别。2007 年中文攻略把两种宝石都列入这五层，2004 年英文采矿 FAQ 的亚历山大石楼层则与所核发行版相符。[2007 年中文攻略](https://pr055.pixnet.net/blog/posts/1006209534) · [2004 年英文采矿 FAQ](https://gamefaqs.gamespot.com/gba/589702-harvest-moon-friends-of-mineral-town/faqs/28178)

**修复方式：**

让 B210、B220、B230、B240、B250 使用 GBA 原有的索引 53，两种宝石在该行的取样率各为 1/256。

**相关文件：** [岩石权重选择](src/mine_floor.cc) · [权重行索引](include/mine_weight_rows.h) · [权重表](src/mine_floor_items.c) · 矿场研究第 8 集（[JP](data/scripts/jp/EventScript_TV_MineResearchGroup.mary.c) · [US](data/scripts/us/EventScript_TV_MineResearchGroup.mary.c) · [EU](data/scripts/eu/EventScript_TV_MineResearchGroup.mary.c) · [DE](data/scripts/de/EventScript_TV_MineResearchGroup.mary.c)）

<a id="jp-winter-grass-growth"></a>
### 日版牧草在冬季继续生长

**受影响版本：** JP。

**原版内容与差异：**

JP 入冬时保留牧草原有生长阶段及计数，未成熟的牧草在冬季仍推进。US、EU、DE 入冬时把现有牧草置为阶段 7、计数 0，冬季暂停推进。

**判断依据：**

JP 秋 23 日农舍入门节目说牧草冬季埋在雪下，到春天才重新生长。海外节目和重制版节目也支持冬季停长。两处田地更新共同决定冬季牧草的状态。

**修复方式：**

JP 同时采用海外版的入冬重置和冬季停长逻辑。

**相关文件：** [田地每日与换季更新](src/field.cc) · [JP 秋 23 日节目](data/scripts/jp/EventScript_TV_LifeOnTheFarm_Beginner.mary.c) · [US 对照](data/scripts/us/EventScript_TV_LifeOnTheFarm_Beginner.mary.c) · [地区差异](REGIONAL_DIFFERENCES.md)

<a id="category-interface"></a>
## 菜单选项、记录与显示

| 问题 | 受影响版本 | 开关支持 |
| --- | --- | --- |
| [包装画面把升级农具画成基础农具](#wrapping-tool-icons) | JP、US | 已接入 |
| [动物照料栏目显示了收获最高记录](#overseas-animal-care-record) | US、EU、DE | 已接入 |
| [料理材料的包装说明未送入窗口](#cooking-wrapped-description) | US、EU、DE | 已接入 |
| [女神猜拳显示手势与实际分支不一致](#goddess-rps-options) | US、EU、DE | 已接入 |
| [海外艾利产后生日选项错位](#audit-a07) | US、EU、DE | 已接入 |
| [海外女神产前生日选项错位](#audit-a08) | US、EU、DE | 已接入 |
| [钓获提示长名称覆盖行首](#fishing-message-width) | US、EU、DE | 已接入 |
| [德版联机确认选项残留英语](#de-link-options) | DE | 已接入 |
| [德版收获结果误用喂食栏目](#de-harvest-labels) | DE | 已接入 |
| [原文残留ret>／<RET>换行记号](#text-control-literals) | US、EU、DE | 已接入 |
| [满行后的多余空格覆盖行首](#text-trailing-space) | JP、US、EU、DE | 已接入 |
| [海外凯生日贺卡签名残留制表字节](#kai-card-tab) | US、EU、DE | 已接入 |
| [赛马兑奖退出问句的肯否含义反向](#horse-race-prize-exit-prompt) | US、EU、DE | 已接入 |
| [赛马购票帮助指向不存在的 OK 选项](#horse-race-ticket-confirm-help) | US、EU、DE | 已接入 |
| [鸡祭出界警告多出否定词](#chicken-festival-ring-warning) | US、EU | 已接入 |
| [德版酒庄帮工选项把拒绝拆成两项](#de-winery-work-options) | DE | 已接入 |

<a id="wrapping-tool-icons"></a>
### 包装画面把升级农具画成基础农具

**受影响版本：** JP、US。

**原版内容与差异：**

背包和手持两条路径直接用基础工具编号取图标，显示未反映保存的升级等级；工具本身并未降级。

**判断依据：**

EU、DE 在两条路径都通过 `Farmer::GetUpgradedTool` 转换为实际升级编号。

**修复方式：**

JP、US 同步两条图标路径，保持物品状态、包装费和升级记录不变。

**相关文件：** [包装绘制](src/scene_gift_wrapping.cc) · [升级映射](src/farmer.cc)

<a id="overseas-animal-care-record"></a>
### 动物照料栏目显示了收获最高记录

**受影响版本：** US、EU、DE。

**原版内容与差异：**

标题是动物照料，数值却再次读取 `sprite_harvesting_record`；两个栏目显示同一收获记录。实际动物照料成绩仍独立保存，不是成绩被覆盖或奖励未结算。

**判断依据：**

JP 对应行读取 `sprite_animal_care_record`；小游戏结束时四版也都写入这个独立字段。

**修复方式：**

开启 `BUGFIX` 时，仅将海外动物照料栏的调用由 `GetUnknown13()` 改为 `GetUnknown18()`，读取独立保存的 `sprite_animal_care_record`。收获栏、浇水栏、记录写入和 JP 原有调用均不变。关闭开关时保留海外错误读取。

**相关文件：** [记录页](src/records_screen.cc) · [字段](include/game_state_types.hh) · [读写器](src/game_state.cc) · [成绩提交](src/scene_minigames.cc)

<a id="cooking-wrapped-description"></a>
### 料理材料的包装说明未送入窗口

**受影响版本：** US、EU、DE。

**原版内容与差异：**

选中已包装物品时，把包装说明及物品名拼到另一个临时缓冲区，却把原来的仅含名字的缓冲区传给窗口；包装说明不显示，物品的包装标志没有消失。

**判断依据：**

JP 拼入同一个缓冲区并把它传给窗口。下游 `UiStatePayload::SetText` 直接采用所传指针，不会补上遗漏说明。

**修复方式：**

开启 `BUGFIX` 时，海外三版把已有背包说明 `gText_ItemStatus_WrappedAsPresent` 追加到真正传给窗口的物品名缓冲区：US／EU 为 `
wrapped as a present.`，DE 为 `
als Geschenk verpackt.`。不再构造未被使用的七字节前缀；原 `A wrapped` 有九个字符，仅改显示指针也无法显示完整内容。拼接沿用原 128 字节说明区，正文最多 127 字节并补结束符。JP 原本正确的拼接、包装标志及料理材料处理保持不变；关闭开关时保留原版行为。

**相关文件：** [拼接与传参](src/scene_cooking.cc) · [窗口适配器](src/ui_state.cc) · [US 既有包装说明](data/text/us/game_menu_1.cc) · [EU](data/text/eu/game_menu_1.cc) · [DE](data/text/de/game_menu_1.cc)

<a id="goddess-rps-options"></a>
### 女神猜拳显示手势与实际分支不一致

**受影响版本：** US、EU、DE。

**原版内容与差异：**

实际选项顺序均为石头、剪刀、布；US／EU 显示石头、布、剪刀，DE 显示剪刀、石头、布。按显示选择可能进入另一手势的结果分支。

**判断依据：**

JP 的菜单显示与三条胜负／结果消息分支一致。

**修复方式：**

仅重排三个海外版 `TalkChoice3` 的文本实参，不改随机数、胜负判断、连胜累加或奖金。

**相关文件：** [JP 脚本](data/scripts/jp/EventScript_TV_HarvestGoddessRockPaperScissors.mary.c) · [US 脚本](data/scripts/us/EventScript_TV_HarvestGoddessRockPaperScissors.mary.c)

<a id="audit-a07"></a>
### 海外艾利产后生日选项错位

**受影响版本：** US、EU、DE。

**原版内容与差异：**

| 版本 | 生育后显示的三个选项，按实际顺序 |
|---|---|
| JP | `自分の誕生日`／`エリィの誕生日`／`{Baby}の誕生日`——玩家／艾利／孩子的生日。 |
| US＝EU | `Our anniversary`／`My birthday`／`Your birthday`——结婚纪念日／玩家生日／艾利生日。 |
| DE | `Unser Hochzeitstag`／`Mein Geburtstag`／`Dein Geburtstag`——同上。 |

**判断依据：**

生育后的程序把**第二项**判为正确并增加好感，但海外第二项显示“我的生日”；选第三项“你的生日”反而扣好感。应修正产后菜单对应内容，不能改变本来正确的判定位置。

JP产后为玩家、艾利、孩子生日；孩子称呼沿用同语言女神生日选项。

**修复方式：**

恢复孩子生日选项，并按原来的正确答案位置重排产后菜单；产前菜单与好感判定不改。 BUGFIX关闭时保留原文本及引用。

**相关文件：** [海外菜单及结果分支](data/scripts/us/EventScript_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice.mary.c) · [JP对应文件](data/scripts/jp/EventScript_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice.mary.c) · [EU对应文件](data/scripts/eu/EventScript_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice.mary.c) · [DE对应文件](data/scripts/de/EventScript_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice.mary.c)

<a id="audit-a08"></a>
### 海外女神产前生日选项错位

**受影响版本：** US、EU、DE。

**原版内容与差异：**

| 版本 | 生育前实际显示顺序 |
|---|---|
| JP | `結婚記念日`／`自分の誕生日`／`女神様の誕生日` |
| US＝EU | `Your birthday`／`Our anniversary`／`My birthday` |
| DE | `Dein Geburtstag`／`Unser Hochzeitstag`／`Mein Geburtstag` |

**判断依据：**

程序把第三项作为女神生日的正确答案，海外第三项却是玩家生日。**生育后的菜单对应关系正确**，因此不能把相关指针全局交换。

JP为纪念日、玩家生日、女神生日；海外现有字符串足够恢复正确菜单。

**修复方式：**

只调整产前菜单参数顺序，产后已经正确的菜单和判定保持不变。 BUGFIX关闭时保留原文本及引用。

**相关文件：** [女神生日两套菜单](data/scripts/us/EventScript_FamilyEvent_HarvestGoddess_EveningDateChoice.mary.c) · [JP对应文件](data/scripts/jp/EventScript_FamilyEvent_HarvestGoddess_EveningDateChoice.mary.c) · [EU对应文件](data/scripts/eu/EventScript_FamilyEvent_HarvestGoddess_EveningDateChoice.mary.c) · [DE对应文件](data/scripts/de/EventScript_FamilyEvent_HarvestGoddess_EveningDateChoice.mary.c)

<a id="fishing-message-width"></a>
### 钓获提示长名称覆盖行首

**受影响版本：** US、EU、DE。

**原版内容与差异：**

US／EU原You fished a {Var1}.中漂流瓶、海贼宝藏展开为33／29格；DE尺寸模板的长鱼名加尾空格后为29格。

**判断依据：**

窗口一行28格，超出后回到本行开头覆盖已有字形；JP对应布局没有此问题。

**修复方式：**

英文特殊物品名移到下一行；DE三个尺寸模板去掉鱼名后的多余空格，不改鱼种名或引擎换行规则。

**相关文件：** [JP](data/scripts/jp/EventScript_AchievementEvent_Fishing_MilestoneReward.mary.c) · [US](data/scripts/us/EventScript_AchievementEvent_Fishing_MilestoneReward.mary.c) · [EU](data/scripts/eu/EventScript_AchievementEvent_Fishing_MilestoneReward.mary.c) · [DE](data/scripts/de/EventScript_AchievementEvent_Fishing_MilestoneReward.mary.c) · [钓获取名](src/fishing.cc) · [回绕规则](src/ui_text_rows.cc)

<a id="de-link-options"></a>
### 德版联机确认选项残留英语

**受影响版本：** DE。

**原版内容与差异：**

确认菜单显示Yes／No。

**判断依据：**

此处是德语玩家使用的通用确认选项；本作Ja／Nein是现成德文。

**修复方式：**

改为Ja／Nein，不交换选项返回值。

**相关文件：** [JP](data/text/jp/scene_gamecube_link.cc) · [US](data/text/us/scene_gamecube_link.cc) · [EU](data/text/eu/scene_gamecube_link.cc) · [DE](data/text/de/scene_gamecube_link.cc)

<a id="de-harvest-labels"></a>
### 德版收获结果误用喂食栏目

**受影响版本：** DE。

**原版内容与差异：**

标题使用Gefüttert／Vergessen（已喂食／遗忘）。

**判断依据：**

JP／US／EU是收获与失败；本栏实际读取收获数和失败数。

**修复方式：**

改为Geerntet／Fehler，不改小游戏成绩。

**相关文件：** [JP](data/text/jp/scene_harvesting_minigame_2.cc) · [US](data/text/us/scene_harvesting_minigame_2.cc) · [EU](data/text/eu/scene_harvesting_minigame_2.cc) · [DE](data/text/de/scene_harvesting_minigame_2.cc) · [成绩读取](src/scene_harvesting_minigame.cc)

<a id="text-control-literals"></a>
### 原文残留ret>／<RET>换行记号

**受影响版本：** US、EU、DE。

**原版内容与差异：**

部分文本把ret>或<RET>作为字面字符显示。

**判断依据：**

当前读取器没有对应控制分支；上下文在此需要换行。没有证据确定其历史生成来源。

**修复方式：**

在已确认应换行的位置改为实际\r\n，不新增控制符解释器。

对应的文本文件：

- US：[NPCEvent_Ann_DialogueAndGiftResponses](data/scripts/us/EventScript_NPCEvent_Ann_DialogueAndGiftResponses.mary.c) · [NPCEvent_Harris_DialogueAndGiftResponses](data/scripts/us/EventScript_NPCEvent_Harris_DialogueAndGiftResponses.mary.c) · [TV_FairyAndMeHisStory](data/scripts/us/EventScript_TV_FairyAndMeHisStory.mary.c) · [TV_MyDearPrincess](data/scripts/us/EventScript_TV_MyDearPrincess.mary.c)
- EU：[NPCEvent_Ann_DialogueAndGiftResponses](data/scripts/eu/EventScript_NPCEvent_Ann_DialogueAndGiftResponses.mary.c) · [NPCEvent_Harris_DialogueAndGiftResponses](data/scripts/eu/EventScript_NPCEvent_Harris_DialogueAndGiftResponses.mary.c) · [TV_FairyAndMeHisStory](data/scripts/eu/EventScript_TV_FairyAndMeHisStory.mary.c) · [TV_MyDearPrincess](data/scripts/eu/EventScript_TV_MyDearPrincess.mary.c)
- DE：[NPCEvent_Duke_GrapeHarvestInvitation](data/scripts/de/EventScript_NPCEvent_Duke_GrapeHarvestInvitation.mary.c) · [TV_MechabotUltrorZero_EpisodeReminders](data/scripts/de/EventScript_TV_MechabotUltrorZero_EpisodeReminders.mary.c) · [TV_MyDearPrincess](data/scripts/de/EventScript_TV_MyDearPrincess.mary.c) · [TV_StarLilyBanditGirl](data/scripts/de/EventScript_TV_StarLilyBanditGirl.mary.c)

**相关文件：** [JP](data/scripts/jp/EventScript_TV_MechabotUltrorZero_EpisodeReminders.mary.c) · [US](data/scripts/us/EventScript_TV_MechabotUltrorZero_EpisodeReminders.mary.c) · [EU](data/scripts/eu/EventScript_TV_MechabotUltrorZero_EpisodeReminders.mary.c) · [DE](data/scripts/de/EventScript_TV_MechabotUltrorZero_EpisodeReminders.mary.c) · [控制符读取](src/ui_text_stream.cc)

<a id="text-trailing-space"></a>
### 满行后的多余空格覆盖行首

**受影响版本：** JP、US、EU、DE。

**原版内容与差异：**

部分正文已经占满28个半角格，末尾仍附加空格。

**判断依据：**

读取器达到列边界后回到同一行开头，额外空格会擦掉行首字符。

**修复方式：**

只删除已确认导致覆盖的尾空格；保留正常缩进与有效空行，不添加自动换页或全局重排。

对应的文本文件：

- JP：[NPCEvent_Barley_DialogueAndGiftResponses](data/scripts/jp/EventScript_NPCEvent_Barley_DialogueAndGiftResponses.mary.c) · [NPCEvent_Saibara_DialogueAndGiftResponses](data/scripts/jp/EventScript_NPCEvent_Saibara_DialogueAndGiftResponses.mary.c)
- US：[FamilyEvent_Doug_BirthdayGiftFromAnn](data/scripts/us/EventScript_FamilyEvent_Doug_BirthdayGiftFromAnn.mary.c) · [FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice](data/scripts/us/EventScript_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice.mary.c) · [FestivalEvent_ChickenFestival_PreTournamentDialogue_Barley](data/scripts/us/EventScript_FestivalEvent_ChickenFestival_PreTournamentDialogue_Barley.mary.c) · [FestivalEvent_CookingFestival_Judging](data/scripts/us/EventScript_FestivalEvent_CookingFestival_Judging.mary.c) · [FestivalEvent_FireworksFestival_PostFestivalDialogue](data/scripts/us/EventScript_FestivalEvent_FireworksFestival_PostFestivalDialogue.mary.c) · [NPCEvent_DougAndDuke_Argument_FollowupHarrisDialogue](data/scripts/us/EventScript_NPCEvent_DougAndDuke_Argument_FollowupHarrisDialogue.mary.c) · [NPCEvent_Gray_DialogueAndGiftResponses](data/scripts/us/EventScript_NPCEvent_Gray_DialogueAndGiftResponses.mary.c) · [NPCEvent_Kai_LeavesAfterSummer](data/scripts/us/EventScript_NPCEvent_Kai_LeavesAfterSummer.mary.c) · [TV_StEmeraldAcademy](data/scripts/us/EventScript_TV_StEmeraldAcademy.mary.c) · [TutorialEvent_CropFarmingInstructions](data/scripts/us/EventScript_TutorialEvent_CropFarmingInstructions.mary.c)
- EU：[FamilyEvent_Doug_BirthdayGiftFromAnn](data/scripts/eu/EventScript_FamilyEvent_Doug_BirthdayGiftFromAnn.mary.c) · [FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice](data/scripts/eu/EventScript_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice.mary.c) · [FestivalEvent_ChickenFestival_PreTournamentDialogue_Barley](data/scripts/eu/EventScript_FestivalEvent_ChickenFestival_PreTournamentDialogue_Barley.mary.c) · [FestivalEvent_CookingFestival_Judging](data/scripts/eu/EventScript_FestivalEvent_CookingFestival_Judging.mary.c) · [FestivalEvent_FireworksFestival_PostFestivalDialogue](data/scripts/eu/EventScript_FestivalEvent_FireworksFestival_PostFestivalDialogue.mary.c) · [NPCEvent_DougAndDuke_Argument_FollowupHarrisDialogue](data/scripts/eu/EventScript_NPCEvent_DougAndDuke_Argument_FollowupHarrisDialogue.mary.c) · [NPCEvent_Gray_DialogueAndGiftResponses](data/scripts/eu/EventScript_NPCEvent_Gray_DialogueAndGiftResponses.mary.c) · [NPCEvent_Kai_LeavesAfterSummer](data/scripts/eu/EventScript_NPCEvent_Kai_LeavesAfterSummer.mary.c) · [TV_StEmeraldAcademy](data/scripts/eu/EventScript_TV_StEmeraldAcademy.mary.c) · [TutorialEvent_CropFarmingInstructions](data/scripts/eu/EventScript_TutorialEvent_CropFarmingInstructions.mary.c)
- DE：[AchievementEvent_Fishing_MilestoneReward](data/scripts/de/EventScript_AchievementEvent_Fishing_MilestoneReward.mary.c) · [FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice](data/scripts/de/EventScript_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice.mary.c) · [NPCEvent_HarvestGoddess_OfferingsAndMatchmakingChoices](data/scripts/de/EventScript_NPCEvent_HarvestGoddess_OfferingsAndMatchmakingChoices.mary.c) · [NPCEvent_Sasha_DialogueAndGiftResponses](data/scripts/de/EventScript_NPCEvent_Sasha_DialogueAndGiftResponses.mary.c) · [TV_F314MGrandPrix](data/scripts/de/EventScript_TV_F314MGrandPrix.mary.c) · [TV_HarvestTheater](data/scripts/de/EventScript_TV_HarvestTheater.mary.c) · [TV_LifeOnTheFarm_Advanced](data/scripts/de/EventScript_TV_LifeOnTheFarm_Advanced.mary.c) · [TV_MechabotUltror](data/scripts/de/EventScript_TV_MechabotUltror.mary.c) · [TV_StarLilyBanditGirl](data/scripts/de/EventScript_TV_StarLilyBanditGirl.mary.c)

**相关文件：** [列号回绕](src/ui_text_rows.cc) · [四版脚本文本](data/scripts)

<a id="kai-card-tab"></a>
### 海外凯生日贺卡签名残留制表字节

**受影响版本：** US、EU、DE。

**原版内容与差异：**

三版原文的签名前均有字节09，源码有实际制表符或转义表示。

**判断依据：**

指南此处不解释制表控制；JP直接使用空格缩进。转义写法不同不表示实际字节不同。

**修复方式：**

移除制表前缀，保留原签名缩进。

**相关文件：** [JP](data/text/jp/reference_guide/birthday_card_kai.cc) · [US](data/text/us/reference_guide/birthday_card_kai.cc) · [EU](data/text/eu/reference_guide/birthday_card_kai.cc) · [DE](data/text/de/reference_guide/birthday_card_kai.cc)

<a id="horse-race-prize-exit-prompt"></a>
### 赛马兑奖退出问句的肯否含义反向

**受影响版本：** US、EU、DE。

**原版内容与差异：**

在奖品列表按 B 时，JP 问是否不兑换了。US、EU、DE 却问是否兑换。

**判断依据：**

该确认框中选择 Yes／Ja 会退出，No／Nein 回到奖品列表。

**修复方式：**

英文改用 `Not exchange for a prize?`，德文改用 `Nicht gegen Preis tauschen?`，都表示“不兑换奖品吗？”。两句均适配 28 列窗口。

**相关文件：** [分支](src/horse_race_medal_exchange.cc) · [JP](data/text/jp/horse_race_medal_exchange_2.cc) · [US](data/text/us/horse_race_medal_exchange_2.cc) · [EU](data/text/eu/horse_race_medal_exchange_2.cc) · [DE](data/text/de/horse_race_medal_exchange_2.cc)

<a id="horse-race-ticket-confirm-help"></a>
### 赛马购票帮助指向不存在的 OK 选项

**受影响版本：** US、EU、DE。

**原版内容与差异：**

海外购票帮助让玩家把光标移到 `OK`。JP 帮助与菜单均使用「決定」（确认）。

**判断依据：**

US、EU 的第五项为 `Enter`（确认），DE 为 `Mitmach.`（参加）。将光标移到该项并按 A 进入购票确认。

**修复方式：**

帮助改用实际显示的选项名称，德文沿用 `Mitmach.` 自带的句点。

**相关文件：** [菜单和帮助入口](src/horse_race.cc) · [US](data/text/us/horse_race_2.cc) · [EU](data/text/eu/horse_race_2.cc) · [DE](data/text/de/horse_race_2.cc)

<a id="chicken-festival-ring-warning"></a>
### 鸡祭出界警告多出否定词

**受影响版本：** US、EU。

**原版内容与差异：**

英文鸡祭开场玩法说明连续写了两个 `not`（不）。

**判断依据：**

JP 和 DE 都提醒玩家助威时小心别把自家的鸡赶出擂台。英文多出的否定词使警告反向。

**修复方式：**

删除第二行开头多出的 `not `，保留后续台词、换页和按键等待。

**相关文件：** [讲解流程](src/scene_chicken_festival.cc) · [JP](data/text/jp/scene_chicken_festival_2.cc) · [US](data/text/us/scene_chicken_festival_2.cc) · [EU](data/text/eu/scene_chicken_festival_2.cc) · [DE](data/text/de/scene_chicken_festival_2.cc)

<a id="de-winery-work-options"></a>
### 德版酒庄帮工选项把拒绝拆成两项

**受影响版本：** DE。

**原版内容与差异：**

第一年秋15日酒庄帮工中，第一项进入接受分支，第二项进入拒绝分支。JP选项是 `手伝う`／`やめておく`（帮忙／还是算了），US／EU是 `Of course.`／`Sorry, I can't.`（当然／抱歉，我不能）。DE却拆成 `Sorry`／`ich kann nicht.`（抱歉／我不能），第一项文字与实际接受行为不符。

**判断依据：**

四版的选择顺序及两个结果分支对应，没有脚本分支错位；错误仅在德文选项。接受后是否空手仍由原有条件检查。本作德版找书帮忙选项已有 `Gerne.`（乐意帮忙），可用于明确接受。

**修复方式：**

仅在BUGFIX开启时把DE两个选项改为 `Gerne.`／`Sorry, ich kann nicht.`（乐意帮忙／抱歉，我不能帮忙）；不调整选项引用顺序、帮工流程、报酬或克里夫的在场条件。

**相关文件：** [DE](data/scripts/de/EventScript_NPCEvent_Cliff_PermanentWineryJob.mary.c) · [JP](data/scripts/jp/EventScript_NPCEvent_Cliff_PermanentWineryJob.mary.c) · [US](data/scripts/us/EventScript_NPCEvent_Cliff_PermanentWineryJob.mary.c) · [EU](data/scripts/eu/EventScript_NPCEvent_Cliff_PermanentWineryJob.mary.c)

<a id="category-items"></a>
## 道具身份、名称与说明

<a id="item-description-audit"></a>
| 问题 | 受影响版本 | 开关支持 |
| --- | --- | --- |
| [炒荞麦面复用炒乌冬面文本](#fried-soba) | US、EU、DE | 已接入 |
| [X 级羊毛复用 P 级文本](#wool-x) | US、EU、DE | 已接入 |
| [收集用宝玉与合成秘宝同名](#de-jewels) | DE | 已接入 |
| [加强药 XL 名称与失败料理语言错误](#de-food) | DE | 已接入 |
| [不同鱼种复用同一显示名](#fish-record-names) | US、EU、DE（第二组仅 DE） | 已接入 |
| [DE：茶叶与成品茶同名，配方原料也未区分](#audit-b12) | DE | 已接入 |
| [畜棚及牛羊商店把牧草称作鸡饲料](#barn-fodder-text) | US、EU、DE | 已接入 |
| [德版把面粉译成花](#flour-name) | DE | 已接入 |
| [普通鱼竿说明缺少行分隔](#fishing-rod-lines) | US、EU | 已接入 |
| [黄玉说明错用红宝石标题且正文破损](#topaz-description) | US、EU | 已接入 |
| [餐包名称误拼为Dinner Role](#dinner-roll-spelling) | US、EU | 已接入 |
| [烤苹果误译为Apple Souffl?](#baked-apple-name) | US、EU | 已接入 |
| [露的德文料理名与物品表不一致](#lou-apple-dish) | DE | 已接入 |
| [操作说明：花种 `0x42/0x43`](#flower-seasons) | US、EU、DE | 已接入 |
| [操作说明：红色魔术草 `0x03`](#red-flower-shipping) | US、EU、DE | 已接入 |
| [用途错配：金刚石 `0x17`](#adamantite-use) | DE | 已接入 |
| [身份错译：赏月团子 `0x96`](#moon-dumplings) | US、EU | 已接入 |
| [配料遗漏：混合果汁 `0x56`](#mixed-juice) | US、EU、DE | 已接入 |
| [句子残缺：混合奶 `0x59`、番茄酱 `0x60`](#mixed-milk-ketchup) | DE | 已接入 |
| [句子残缺：X 牛奶 `0x21`](#milk-x-description) | DE | 已接入 |
| [食用类型：吐司 `0x92`](#toast-description) | DE | 已接入 |
| [漏翻：唱片 13 `0x4C`](#record13-language) | DE | 已接入 |
| [排版缺损：味噌汤 `0x4F`](#miso-soup-lines) | DE | 已接入 |
| [拼写：苹果 `0x28`、菠萝汁 `0x64`](#food-spelling) | US、EU | 已接入 |

<a id="fried-soba"></a>
### 炒荞麦面复用炒乌冬面文本

**受影响版本：** US、EU、DE。

**原版内容与差异：**

食物 `0x89` 复用 `0x86` 的名字和说明，两种菜谱显示同名。

**判断依据：**

JP `0x89` 为「焼きそば」（炒荞麦面），与炒乌冬面不同。

**修复方式：**

为海外 `0x89` 使用独立名称及说明；英文 Fried Soba、德文 Gebratene Soba 是本工程补译，图标与属性保持原值。

**相关文件：** [食物表](src/item.cc) · [JP](data/text/jp/item_2.cc) · [US](data/text/us/item_2.cc) · [DE](data/text/de/item_2.cc)

<a id="wool-x"></a>
### X 级羊毛复用 P 级文本

**受影响版本：** US、EU、DE。

**原版内容与差异：**

物品 `0x0A` 的图标独立，名字与说明却取 `0x09` 的 P 级文本。

**判断依据：**

JP 的 X 级名称和说明与其等级一致。

**修复方式：**

海外两处均改用 X 级文本，措辞沿用各版本羊毛说明风格，不改变产物属性。

**相关文件：** [物品表](src/item.cc) · [JP](data/text/jp/item_3.cc) · [EU](data/text/eu/item_3.cc)

<a id="de-jewels"></a>
### 收集用宝玉与合成秘宝同名

**受影响版本：** DE。

**原版内容与差异：**

收集物 `0x26`、`0x27` 取用对应成品工具的名字，独立说明仍要求集齐九个，零件与成品无法从名字区分。

**判断依据：**

JP、US、EU 分别命名收集物和成品。

**修复方式：**

DE 收集物改用 Kappa-Juwelteil、Wahrheitsjuwelteil（河童／真实宝玉部件），同步说明首行；成品保留原名。这两个名称为本工程补译。

**相关文件：** [收集物指针表](src/item.cc) · [DE 工具](data/text/de/item_1.cc) · [DE 收集物](data/text/de/item_3.cc)

<a id="de-food"></a>
### 加强药 XL 名称与失败料理语言错误

**受影响版本：** DE。

**原版内容与差异：**

食物 `0x3A` 说明写 Bodigizer XL，名字却指向普通药；`0x9B–0x9D` 的失败料理名称和说明仍为英文。

**判断依据：**

另外三版加强药名称区分 XL；DE 自己的说明首行及失败料理表中已有正确德文。

**修复方式：**

采用 DE 现有 XL 名称及 Misserfolg（失败）说明。三个漏翻名称补为 `Missl. Getränk`（失败饮料）、`Missl. Topfgericht`（失败锅料理）、`Missl. Dessert`（失败甜点），沿用本作 `Missl. Gericht` 的简称形式及既有 Getränk／Dessert 词汇，锅料理按 JP「鍋に入ってるの」补译。三者最长 17 个单字节字符。重制版 DE 的对应失败料理位置为空，故这些是有本作模板依据的补译，不能标成重制版官方译名。默认分支保留英文名称及原指针。

**相关文件：** [食物表](src/item.cc) · [DE 文本](data/text/de/item_2.cc)

<a id="fish-record-names"></a>
### 不同鱼种复用同一显示名

**受影响版本：** US、EU、DE（第二组仅 DE）。

**原版内容与差异：**

海外记录 37 复用 22 的名称；DE 记录 46 又复用 18，两项都显示 Thunfisch（金枪鱼）。记录编号和统计字段仍独立。

**判断依据：**

JP 22／37 为ギンブナ／ハクレン；18／46 为カツオ／マグロ（鲣／金枪鱼）。US、EU 的后一组也分别命名。

**修复方式：**

记录 22 的英文鱼名为 Silver Crucian Carp，US／EU 采用经确认的 14 字符界面短写 Silver Crucian，避免与槽 44 的 Crucian Carp 重名；该短写不宣称是游戏官方简称。DE 沿用重制版德文 Ginbuna，37 保留正确的 Silver Carp／Silberkarpfen。DE 18 为 Bonito，46 独立为 Thunfisch。不改钓获数量、体长或编号。重制版名称来自同级 `SoSFoMTTextDump/SoSFoMTTextDump` 的 JA、US、DE `msg_Item.txt`。

Silver Crucian 为 14 字符，原钓获提示 `You fished a {Var1}.` 展开后为 28 格；纪录界面名称复制上限为 20 字节，因此无需修改提示换行或渲染程序。英文显示文本为 `Silver Crucian`，变量采用 `SilverCrucian`，不附记录编号或日文鱼种后缀。

英文鱼名依据：银鲫ギンブナ／ginbuna在[1998年研究](https://pubmed.ncbi.nlm.nih.gov/9546204/)和[2019年研究](https://pubmed.ncbi.nlm.nih.gov/31347186/)中称为silver crucian carp。重制版US的Crucian Carp泛称会与另一鱼种同名，因此界面采用完整英文名的短写；这个短写不是官方简称。

**相关文件：** [名称表](src/fishing_results_data.cc) · [JP 文本](data/text/jp/fishing_results_data.cc) · [DE 文本](data/text/de/fishing_results_data.cc) · [记录编号](include/fomt_constants.mary.h) · [US鱼名](data/text/us/fishing_results_data.cc) · [EU鱼名](data/text/eu/fishing_results_data.cc)

<a id="audit-b12"></a>
### DE：茶叶与成品茶同名，配方原料也未区分

**受影响版本：** DE。

**原版内容与差异：**

- **JP：** 必需材料为 `リラックス茶の葉`。
- **US＝EU：** `Relaxation Tea Leaves`。
- **DE：** `Entspannungtee`——松弛茶。

**判断依据：**

JP及US／EU的茶叶原料与成品茶名称不同，DE两者原道具名和说明首行却都为Entspannungstee。重制版德文道具文本第915行明确使用Entspannungsteeblätter（22字符）。料理列表道具名区域只有20格，完整名称会被截掉末尾er，因此采用20字符的界面短写。

**修复方式：**

原版茶叶与成品茶均称Entspannungstee。统一将茶叶道具名、说明首行和指南原料写为 `Entspann.-Teeblätter`（20字符）；这是为适配GBA料理列表20格宽度采用的界面缩写，非官方简称。完整名称 `Entspannungsteeblätter`（22字符）来自重制版德文道具文本。成品茶名称保持原样。

**相关文件：** [配方](data/text/de/reference_guide/cookbook_4.cc) · [JP对应文件](data/text/jp/reference_guide/cookbook_4.cc) · [US对应文件](data/text/us/reference_guide/cookbook_4.cc) · [EU对应文件](data/text/eu/reference_guide/cookbook_4.cc) · [德文茶与茶叶](data/text/de/item_2.cc) · [JP对应文件](data/text/jp/item_2.cc) · [US对应文件](data/text/us/item_2.cc) · [EU对应文件](data/text/eu/item_2.cc) · [料理列表20格区域](src/scene_cooking.cc:11698) · [绘制边界](src/font_draw.cc:240) · [重制版德文道具名](../SoSFoMTTextDump/SoSFoMTTextDump/DE/msg_Item.txt:915)

<a id="barn-fodder-text"></a>
### 畜棚及牛羊商店把牧草称作鸡饲料

**受影响版本：** US、EU、DE。

**原版内容与差异：**

畜棚空仓写There is no Chicken Feed；DE使用Hühnerfutter，牛羊商店购买确认也有相同误称。

**判断依据：**

牛羊使用牧草；本作Fodder／Viehfutter为现成对应名，鸡饲料是另一个道具和仓库。

**修复方式：**

畜棚及受影响的牛羊商店句子改用Fodder／Viehfutter，保留鸡舍的正确称谓。

**相关文件：** [JP](data/scripts/jp/EventScript_LocationInteraction_InspectBarnFeedStorageEmptyNotice.mary.c) · [US](data/scripts/us/EventScript_LocationInteraction_InspectBarnFeedStorageEmptyNotice.mary.c) · [EU](data/scripts/eu/EventScript_LocationInteraction_InspectBarnFeedStorageEmptyNotice.mary.c) · [DE](data/scripts/de/EventScript_LocationInteraction_InspectBarnFeedStorageEmptyNotice.mary.c) · [JP](data/text/jp/scene_yodel_ranch_shop_2.cc) · [US](data/text/us/scene_yodel_ranch_shop_2.cc) · [EU](data/text/eu/scene_yodel_ranch_shop_2.cc) · [DE](data/text/de/scene_yodel_ranch_shop_2.cc)

<a id="flour-name"></a>
### 德版把面粉译成花

**受影响版本：** DE。

**原版内容与差异：**

名称Blume，说明首行也写Blume（花）。

**判断依据：**

JP为小麦粉，US／EU为Flour；这是料理原料，不是花卉。

**修复方式：**

名称及说明首行统一改为Mehl，保留正确Flour源码身份。

**相关文件：** [JP](data/text/jp/item_2.cc) · [US](data/text/us/item_2.cc) · [EU](data/text/eu/item_2.cc) · [DE](data/text/de/item_2.cc)

<a id="fishing-rod-lines"></a>
### 普通鱼竿说明缺少行分隔

**受影响版本：** US、EU。

**原版内容与差异：**

原文Fishing RodFor fishing.把标题和正文粘成一行。

**判断依据：**

JP／DE及其他鱼竿有标题与说明分隔；菜单格式化循环依赖换行，不在终止零处停止，缺分隔会越过对象读取铜鱼竿文本。

**修复方式：**

补成Fishing Rod、For fishing.两行及必要分隔；第三个空字符串只表示源码布局，不额外插入换行。

**相关文件：** [JP](data/text/jp/item_1.cc) · [US](data/text/us/item_1.cc) · [EU](data/text/eu/item_1.cc) · [DE](data/text/de/item_1.cc) · [说明读取](src/game_menu.cc)

<a id="topaz-description"></a>
### 黄玉说明错用红宝石标题且正文破损

**受影响版本：** US、EU。

**原版内容与差异：**

Topaz的说明首行写Ruby，正文也有破损。

**判断依据：**

这是黄玉独立文本对象，不是正常Ruby说明的合法共用；JP及物品ID表确定其身份。

**修复方式：**

恢复Topaz标题和对应黄玉说明，不把对象改为红宝石。

**相关文件：** [JP](data/text/jp/item_3.cc) · [US](data/text/us/item_3.cc) · [EU](data/text/eu/item_3.cc) · [DE](data/text/de/item_3.cc)

<a id="dinner-roll-spelling"></a>
### 餐包名称误拼为Dinner Role

**受影响版本：** US、EU。

**原版内容与差异：**

名称和说明首行均写Dinner Role。

**判断依据：**

本物品是面包卷，正确英文为Dinner Roll；Role表示角色。

**修复方式：**

名称及说明首行改为Dinner Roll，源码标签沿用正确DinnerRoll身份。

**相关文件：** [JP](data/text/jp/item_2.cc) · [US](data/text/us/item_2.cc) · [EU](data/text/eu/item_2.cc) · [DE](data/text/de/item_2.cc)

<a id="baked-apple-name"></a>
### 烤苹果误译为Apple Souffl?

**受影响版本：** US、EU。

**原版内容与差异：**

名称及说明首行写Apple Souffl?。

**判断依据：**

JP为焼きりんご（烤苹果），不是苹果舒芙蕾；DE既有烤苹果称呼不属于同一错误。

**修复方式：**

英文名称及说明首行改为Baked Apple，DE原称保留；源码标签采用BakedApple。

**相关文件：** [JP](data/text/jp/item_2.cc) · [US](data/text/us/item_2.cc) · [EU](data/text/eu/item_2.cc) · [DE](data/text/de/item_2.cc)

<a id="lou-apple-dish"></a>
### 露的德文料理名与物品表不一致

**受影响版本：** DE。

**原版内容与差异：**

露提到Apfel-Souffl?，而本版对应物品有正确烤苹果译名。

**判断依据：**

实际料理ID与本版食品名称对应；应优先沿用已有名称。

**修复方式：**

改用本版Apfelauflauf，不另译料理名。

**相关文件：** [JP](data/scripts/jp/EventScript_NPCEvent_LouOrRuby_DailyDialogueAndCookingRecipes.mary.c) · [US](data/scripts/us/EventScript_NPCEvent_LouOrRuby_DailyDialogueAndCookingRecipes.mary.c) · [EU](data/scripts/eu/EventScript_NPCEvent_LouOrRuby_DailyDialogueAndCookingRecipes.mary.c) · [DE](data/scripts/de/EventScript_NPCEvent_LouOrRuby_DailyDialogueAndCookingRecipes.mary.c) · [JP](data/text/jp/item_2.cc) · [US](data/text/us/item_2.cc) · [EU](data/text/eu/item_2.cc) · [DE](data/text/de/item_2.cc)

<a id="flower-seasons"></a>
### 操作说明：花种 `0x42/0x43`

**受影响版本：** US、EU、DE。

**原版内容与差异：**

US／EU／DE 额外写可在秋季种植

**判断依据：**

月落草种仅春、猫薄荷种仅夏；JP 种子、四版成品花说明一致，`FieldPlot::DayUpdate` 的作物 15／16 分别检查春／夏

**修复方式：**

沿用同版种子的春／夏现成句式，移除秋季

**相关文件：** [物品与出货表](src/item.cc) · [JP](data/text/jp/item_1.cc) · [US](data/text/us/item_1.cc) · [EU](data/text/eu/item_1.cc) · [DE](data/text/de/item_1.cc) · [JP](data/text/jp/item_2.cc) · [US](data/text/us/item_2.cc) · [EU](data/text/eu/item_2.cc) · [DE](data/text/de/item_2.cc) · [JP](data/text/jp/item_3.cc) · [US](data/text/us/item_3.cc) · [EU](data/text/eu/item_3.cc) · [DE](data/text/de/item_3.cc) · [作物季节判断](src/field.cc)

<a id="red-flower-shipping"></a>
### 操作说明：红色魔术草 `0x03`

**受影响版本：** US、EU、DE。

**原版内容与差异：**

US／EU／DE 写不可出货，误导玩家丢弃或不出售

**判断依据：**

JP 写可以出货；`gProductInfo[0x42]` 为红花提供 200 的出货价

**修复方式：**

仅改为可以出货，蓝花仍不可出货

**相关文件：** [物品与出货表](src/item.cc) · [JP](data/text/jp/item_1.cc) · [US](data/text/us/item_1.cc) · [EU](data/text/eu/item_1.cc) · [DE](data/text/de/item_1.cc) · [JP](data/text/jp/item_2.cc) · [US](data/text/us/item_2.cc) · [EU](data/text/eu/item_2.cc) · [DE](data/text/de/item_2.cc) · [JP](data/text/jp/item_3.cc) · [US](data/text/us/item_3.cc) · [EU](data/text/eu/item_3.cc) · [DE](data/text/de/item_3.cc)

<a id="adamantite-use"></a>
### 用途错配：金刚石 `0x17`

**受影响版本：** DE。

**原版内容与差异：**

DE 错写用于制作首饰，与奥利哈钢说明的用途相同

**判断依据：**

JP／US／EU 写用于制作加工机；同版加工机说明使用 Maschine

**修复方式：**

改为用于制作机器，保留矿石名称

**相关文件：** [物品与出货表](src/item.cc) · [JP](data/text/jp/item_1.cc) · [US](data/text/us/item_1.cc) · [EU](data/text/eu/item_1.cc) · [DE](data/text/de/item_1.cc) · [JP](data/text/jp/item_2.cc) · [US](data/text/us/item_2.cc) · [EU](data/text/eu/item_2.cc) · [DE](data/text/de/item_2.cc) · [JP](data/text/jp/item_3.cc) · [US](data/text/us/item_3.cc) · [EU](data/text/eu/item_3.cc) · [DE](data/text/de/item_3.cc)

<a id="moon-dumplings"></a>
### 身份错译：赏月团子 `0x96`

**受影响版本：** US、EU。

**原版内容与差异：**

US／EU 写烤蔬菜串，DE 写 Gemüse-Kebab（蔬菜烤串）

**判断依据：**

JP 是串在签上的圆团子；名称仍为 Moon Dumplings／Mondklöße

**修复方式：**

按 JP 直译圆团子串，不更换原名称

**相关文件：** [物品与出货表](src/item.cc) · [JP](data/text/jp/item_1.cc) · [US](data/text/us/item_1.cc) · [EU](data/text/eu/item_1.cc) · [DE](data/text/de/item_1.cc) · [JP](data/text/jp/item_2.cc) · [US](data/text/us/item_2.cc) · [EU](data/text/eu/item_2.cc) · [DE](data/text/de/item_2.cc) · [JP](data/text/jp/item_3.cc) · [US](data/text/us/item_3.cc) · [EU](data/text/eu/item_3.cc) · [DE](data/text/de/item_3.cc)

<a id="mixed-juice"></a>
### 配料遗漏：混合果汁 `0x56`

**受影响版本：** US、EU、DE。

**原版内容与差异：**

US／EU／DE 沿用水果汁配料，仅列水果

**判断依据：**

JP 同时列蔬菜与水果；本作混合奶的配料也保留两者

**修复方式：**

补齐水果和蔬菜，不更改物品属性

**相关文件：** [物品与出货表](src/item.cc) · [JP](data/text/jp/item_1.cc) · [US](data/text/us/item_1.cc) · [EU](data/text/eu/item_1.cc) · [DE](data/text/de/item_1.cc) · [JP](data/text/jp/item_2.cc) · [US](data/text/us/item_2.cc) · [EU](data/text/eu/item_2.cc) · [DE](data/text/de/item_2.cc) · [JP](data/text/jp/item_3.cc) · [US](data/text/us/item_3.cc) · [EU](data/text/eu/item_3.cc) · [DE](data/text/de/item_3.cc)

<a id="mixed-milk-ketchup"></a>
### 句子残缺：混合奶 `0x59`、番茄酱 `0x60`

**受影响版本：** DE。

**原版内容与差异：**

DE 分别停在“水果、蔬菜和”“用新鲜的”

**判断依据：**

JP／US／EU 分别明确牛奶、番茄

**修复方式：**

补齐遗漏的 Milch／Tomaten；混合奶配料行恰为 28 字符，保留原末行饮用／赠送说明，仍为三行

**相关文件：** [物品与出货表](src/item.cc) · [JP](data/text/jp/item_1.cc) · [US](data/text/us/item_1.cc) · [EU](data/text/eu/item_1.cc) · [DE](data/text/de/item_1.cc) · [JP](data/text/jp/item_2.cc) · [US](data/text/us/item_2.cc) · [EU](data/text/eu/item_2.cc) · [DE](data/text/de/item_2.cc) · [JP](data/text/jp/item_3.cc) · [US](data/text/us/item_3.cc) · [EU](data/text/eu/item_3.cc) · [DE](data/text/de/item_3.cc)

<a id="milk-x-description"></a>
### 句子残缺：X 牛奶 `0x21`

**受影响版本：** DE。

**原版内容与差异：**

DE 末行重复饮用句片段，漏掉出货说明

**判断依据：**

同版其他五级牛奶说明完整

**修复方式：**

保留 X 标题，沿用其他牛奶正文

**相关文件：** [物品与出货表](src/item.cc) · [JP](data/text/jp/item_1.cc) · [US](data/text/us/item_1.cc) · [EU](data/text/eu/item_1.cc) · [DE](data/text/de/item_1.cc) · [JP](data/text/jp/item_2.cc) · [US](data/text/us/item_2.cc) · [EU](data/text/eu/item_2.cc) · [DE](data/text/de/item_2.cc) · [JP](data/text/jp/item_3.cc) · [US](data/text/us/item_3.cc) · [EU](data/text/eu/item_3.cc) · [DE](data/text/de/item_3.cc)

<a id="toast-description"></a>
### 食用类型：吐司 `0x92`

**受影响版本：** DE。

**原版内容与差异：**

DE 沿用饮料的 Selbertrinken（自己喝）

**判断依据：**

JP／US／EU 为可食用面包；同版相邻食品已有 Selberessen

**修复方式：**

使用同版食物的“食用或赠送”句式

**相关文件：** [物品与出货表](src/item.cc) · [JP](data/text/jp/item_1.cc) · [US](data/text/us/item_1.cc) · [EU](data/text/eu/item_1.cc) · [DE](data/text/de/item_1.cc) · [JP](data/text/jp/item_2.cc) · [US](data/text/us/item_2.cc) · [EU](data/text/eu/item_2.cc) · [DE](data/text/de/item_2.cc) · [JP](data/text/jp/item_3.cc) · [US](data/text/us/item_3.cc) · [EU](data/text/eu/item_3.cc) · [DE](data/text/de/item_3.cc)

<a id="record13-language"></a>
### 漏翻：唱片 13 `0x4C`

**受影响版本：** DE。

**原版内容与差异：**

DE 的三行说明完整遗留英文

**判断依据：**

同版唱片 11／12／14／15 已有相同奖励模板

**修复方式：**

套用邻项德文，只将胜数写为 70

**相关文件：** [物品与出货表](src/item.cc) · [JP](data/text/jp/item_1.cc) · [US](data/text/us/item_1.cc) · [EU](data/text/eu/item_1.cc) · [DE](data/text/de/item_1.cc) · [JP](data/text/jp/item_2.cc) · [US](data/text/us/item_2.cc) · [EU](data/text/eu/item_2.cc) · [DE](data/text/de/item_2.cc) · [JP](data/text/jp/item_3.cc) · [US](data/text/us/item_3.cc) · [EU](data/text/eu/item_3.cc) · [DE](data/text/de/item_3.cc)

<a id="miso-soup-lines"></a>
### 排版缺损：味噌汤 `0x4F`

**受影响版本：** DE。

**原版内容与差异：**

DE 标题直接粘到正文，缺少换行

**判断依据：**

JP／US／EU 分隔标题与说明，同版其他汤类也如此

**修复方式：**

补回一个 `\r\n`，不重译

**相关文件：** [物品与出货表](src/item.cc) · [JP](data/text/jp/item_1.cc) · [US](data/text/us/item_1.cc) · [EU](data/text/eu/item_1.cc) · [DE](data/text/de/item_1.cc) · [JP](data/text/jp/item_2.cc) · [US](data/text/us/item_2.cc) · [EU](data/text/eu/item_2.cc) · [DE](data/text/de/item_2.cc) · [JP](data/text/jp/item_3.cc) · [US](data/text/us/item_3.cc) · [EU](data/text/eu/item_3.cc) · [DE](data/text/de/item_3.cc)

<a id="food-spelling"></a>
### 拼写：苹果 `0x28`、菠萝汁 `0x64`

**受影响版本：** US、EU。

**原版内容与差异：**

US／EU 分别写 eated、Pinapple

**判断依据：**

同版物品已有 eaten、Pineapple

**修复方式：**

只修正错误拼写

**相关文件：** [物品与出货表](src/item.cc) · [JP](data/text/jp/item_1.cc) · [US](data/text/us/item_1.cc) · [EU](data/text/eu/item_1.cc) · [DE](data/text/de/item_1.cc) · [JP](data/text/jp/item_2.cc) · [US](data/text/us/item_2.cc) · [EU](data/text/eu/item_2.cc) · [DE](data/text/de/item_2.cc) · [JP](data/text/jp/item_3.cc) · [US](data/text/us/item_3.cc) · [EU](data/text/eu/item_3.cc) · [DE](data/text/de/item_3.cc)

<a id="category-dialogue"></a>
## 剧情对话、人物与称呼

<a id="localization-text"></a>
| 问题 | 受影响版本 | 开关支持 |
| --- | --- | --- |
| [羊祭接待桌使用牛祭提示](#sheep-reception-text) | US、EU、DE | 已接入 |
| [德版琳怀孕时医生复用答谢](#audit-a01) | DE | 已接入 |
| [德版玛丽怀孕末尾复用妻子台词](#audit-a02) | DE | 已接入 |
| [德版里克婚礼重复珀布利调侃](#audit-a03) | DE | 已接入 |
| [德版Nappy一天收获委托说成一周](#audit-a04) | DE | 已接入 |
| [德版一亿鱼成就复用一千万台词](#audit-a05) | DE | 已接入 |
| [德版贤者锤领取提示使用秘银锤名](#audit-a06) | DE | 已接入 |
| [海外三版：巴基尔雨天台词失去原有的晴雨对比](#audit-c01) | US、EU、DE | 已接入 |
| [海外三版：玛丽星夜祭把自己做料理写成妈妈今天做蛋糕](#audit-c02) | US、EU、DE | 已接入 |
| [海外三版：参赛动物确认，把“带走”写成“送给你”](#audit-c03) | US、EU、DE | 已接入 |
| [海外三版：巴基尔与安娜贺卡标题把 Anna 写成 Ann](#audit-c04) | US、EU、DE | 已接入 |
| [DE：Lumina 的祖母误写成 Manna](#audit-c05) | DE | 已接入 |
| [US／EU：Sebastian 介绍中的 Romana 误写成 Manna](#audit-c06) | US、EU | 已接入 |
| [海外三版：Gustafa 的祖先经历写成本人经历](#audit-c07) | US、EU、DE | 已接入 |
| [海外三版：Griffin 被家人厌弃，翻成因爱家而定居](#audit-c08) | US、EU、DE | 已接入 |
| [海外三版：Hardy 入住腾出的房屋，写成跟随 Galen 来村](#audit-c09) | US、EU、DE | 已接入 |
| [DE：儿子介绍使用了错误的姓名标记](#audit-c10) | DE | 已接入 |
| [海外三版：一家三口写成三个儿子](#audit-c11) | US、EU、DE | 已接入 |
| [Wally：马拉松教练变成赛事组织者](#audit-c12) | US、EU、DE | 已接入 |
| [Galen：“平时安静”变成“通常很快乐”](#audit-c13) | US、EU、DE | 已接入 |
| [US：卡莲初次见面的 `You name`](#audit-f01) | US | 已接入 |
| [露自我介绍中的来访星期错误](#lou-visit-day) | US、EU、DE | 已接入 |
| [玛娜把自己说成另一位在场者](#manna-duke-reference) | US、EU、DE | 已接入 |
| [莉莉娅在女儿婚礼后声称自己嫁给凯](#lillia-wedding) | US、EU、DE | 已接入 |
| [联机商人姓名错译为 Lou／Lu](#van-name-history) | US、EU、DE | 已接入 |
| [料理来访者未使用同期英文名 Ruby](#ruby-name) | US、EU、DE | 已接入 |
| [玩家生日晚餐的妻子问候误用婴儿语](#spouse-birthday-baby-talk) | US、EU | 已接入 |
| [安娜普通赠礼答谢误提生日](#anna-gift-birthday) | US、EU | 已接入 |
| [卡特葡萄园兼职提示及选项残留德语](#carter-untranslated) | US、EU | 已接入 |
| [精灵香水答谢残留日文](#nappy-perfume) | US、EU | 已接入 |
| [扎克牧场生活夸奖残留日文](#zack-untranslated) | US、EU | 已接入 |
| [人物和物件名称的英文拼写错误](#english-spelling) | US、EU | 已接入 |
| [玩家拒绝采葡萄时杜克向未到场的克里夫讲话](#winery-job-decline-duke-dialogue) | US、EU、DE | 已接入 |
| [德版珀布利谈新生儿时多播一条英文](#de-popuri-newborn-dialogue) | DE | 已接入 |
| [德版珀布利在孩子学步事件中重复同一句](#de-popuri-child-first-steps) | DE | 已接入 |
| [德版玛娜恭维杰夫时夸奖对象颠倒](#de-manna-flatters-jeff) | DE | 已接入 |

<a id="sheep-reception-text"></a>
### 羊祭接待桌使用牛祭提示

**受影响版本：** US、EU、DE。

**原版内容与差异：**

共用接待脚本 `0x0194` 在羊祭开始评审分支仍调用牛祭消息，US／EU 显示 `Cows`（牛），DE 显示 `Kühe`（牛）。这是隔着接待桌交谈的入口；直接与巴利交谈的羊祭脚本 `0x04FC` 文本正常。受影响分支没有年份判断，不能限定为第一年；错误只在提示文字，不改变羊的评审与结果。

**判断依据：**

JP 在同一接待脚本分别使用牛祭和羊祭消息。海外也应在羊祭分支调用适用的消息，不能误用牛祭文字。

**修复方式：**

仅在海外三版 `BUGFIX` 下增加独立羊祭提示，并替换羊祭分支的一次 `TalkMessage`。羊祭声明与 JP 一样放在文本表末尾的 `Table` 之后；牛祭标签统一为 JP 的 `CowContestJudgingStartPrompt`，关闭开关时仍保留羊祭误用牛祭文本的原行为。复用各版本 `0x04FC` 已有的三行台词、换行和等待符：US／EU 为 `It's time for the judging / to begin! / Are you ready?`（评审要开始了，准备好了吗？），DE 为 `Es ist Zeit für die / Bewertung! / Bist du soweit?`（到评审时间了，准备好了吗？）。不另行补译；牛祭仍调用原消息，JP 不改。

**相关文件：** [JP](data/scripts/jp/EventScript_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice.mary.c) · [US](data/scripts/us/EventScript_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice.mary.c) · [EU](data/scripts/eu/EventScript_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice.mary.c) · [DE](data/scripts/de/EventScript_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice.mary.c) · [US](data/scripts/us/EventScript_FestivalEvent_SheepFestival_StartJudgingChoice_Barley.mary.c) · [EU](data/scripts/eu/EventScript_FestivalEvent_SheepFestival_StartJudgingChoice_Barley.mary.c) · [DE](data/scripts/de/EventScript_FestivalEvent_SheepFestival_StartJudgingChoice_Barley.mary.c)

<a id="audit-a01"></a>
### 德版琳怀孕时医生复用答谢

**受影响版本：** DE。

**原版内容与差异：**

| 版本 | 医生对应位置的原文 |
|---|---|
| JP | `キミの奥さんは病気じゃないよ。`——你的妻子不是生病。 |
| US＝EU | `Your wife is not ill.`——你的妻子不是生病。 |
| DE | `Danke.`——谢谢。 |

**判断依据：**

DE 同一个字符串既用于琳的答谢，又用于医生解释病情。医生身份、对话位置均能确定；DE 玛丽怀孕事件已有 `Deine Frau ist nicht krank.` 可供参考。应拆开错误复用，保留琳原来的答谢。

JP／US／EU在此说明妻子不是生病；DE玛丽怀孕事件已有 `Deine Frau ist nicht krank.`（你的妻子不是生病）。

**修复方式：**

在琳答谢之后新增独立医生文本，仅切换医生的那次调用，琳答谢保留。 BUGFIX关闭时保留原文本及引用。

**相关文件：** [医生与琳的实际调用](data/scripts/de/EventScript_FamilyEvent_Ann_PregnancyDiscovery.mary.c) · [JP对应文件](data/scripts/jp/EventScript_FamilyEvent_Ann_PregnancyDiscovery.mary.c) · [US对应文件](data/scripts/us/EventScript_FamilyEvent_Ann_PregnancyDiscovery.mary.c) · [EU对应文件](data/scripts/eu/EventScript_FamilyEvent_Ann_PregnancyDiscovery.mary.c) · [EventScript_FamilyEvent_Mary_PregnancyDiscovery.mary](data/scripts/de/EventScript_FamilyEvent_Mary_PregnancyDiscovery.mary.c) · [JP对应文件](data/scripts/jp/EventScript_FamilyEvent_Mary_PregnancyDiscovery.mary.c) · [US对应文件](data/scripts/us/EventScript_FamilyEvent_Mary_PregnancyDiscovery.mary.c) · [EU对应文件](data/scripts/eu/EventScript_FamilyEvent_Mary_PregnancyDiscovery.mary.c)

<a id="audit-a02"></a>
### 德版玛丽怀孕末尾复用妻子台词

**受影响版本：** DE。

**原版内容与差异：**

| 版本 | 事件末尾原文 |
|---|---|
| JP | `もうすぐ、お父さんか…うれしいな。`——快要当爸爸了……真高兴。 |
| US＝EU | `I can't believe I'm about to become a father... This is so great!`——难以相信就要当爸爸了，太好了。 |
| DE | `Meine Eltern werden so glücklich sein! … Gehen wir heim, OK?`——我的父母会很开心……我们回家吧？ |

**判断依据：**

DE 将玛丽“通知父母、邀请玩家回家”的整段话再次用于玩家独白，人物身份不符。不是单纯标签命名问题。

JP及英文是玩家即将当父亲的喜悦；复用DE琳怀孕末尾已有的玩家独白。

**修复方式：**

在文本表末尾恢复玩家独白，仅替换事件结尾引用，不改变玛丽先前台词。 BUGFIX关闭时保留原文本及引用。

**相关文件：** [末尾独白与复用关系](data/scripts/de/EventScript_FamilyEvent_Mary_PregnancyDiscovery.mary.c) · [JP对应文件](data/scripts/jp/EventScript_FamilyEvent_Mary_PregnancyDiscovery.mary.c) · [US对应文件](data/scripts/us/EventScript_FamilyEvent_Mary_PregnancyDiscovery.mary.c) · [EU对应文件](data/scripts/eu/EventScript_FamilyEvent_Mary_PregnancyDiscovery.mary.c) · [EventScript_FamilyEvent_Ann_PregnancyDiscovery.mary](data/scripts/de/EventScript_FamilyEvent_Ann_PregnancyDiscovery.mary.c) · [JP对应文件](data/scripts/jp/EventScript_FamilyEvent_Ann_PregnancyDiscovery.mary.c) · [US对应文件](data/scripts/us/EventScript_FamilyEvent_Ann_PregnancyDiscovery.mary.c) · [EU对应文件](data/scripts/eu/EventScript_FamilyEvent_Ann_PregnancyDiscovery.mary.c)

<a id="audit-a03"></a>
### 德版里克婚礼重复珀布利调侃

**受影响版本：** DE。

**原版内容与差异：**

| 版本 | 里克应说的内容 |
|---|---|
| JP | `そ…そんなわけないだろ？とにかく、結婚式は今日だから、２人とも来てくれよ。`——才、才不是呢。总之今天举行婚礼，你们两个都来吧。 |
| US＝EU | `(Ha!?) What?! Popuri! Anyway, our wedding is today, so see you there!` |
| DE | `Also meinst du, es ist Popuri zu verdanken, dass du heiratest?`——所以你认为，能结婚是多亏了珀布利？ |

**判断依据：**

同一句 DE 文本先由珀布利说，再切换里克肖像和姓名重复一次。缺的是里克的否认与邀请，原有文本属于珀布利。

JP里克否认并邀请两人参加今天的婚礼；DE普通婚礼已有 `Unsere Hochzeit ist heute.`（今天是我们的婚礼）。重制版未找到对应情敌婚礼台词。

**修复方式：**

沿用本作邀请句，按JP补齐否认与邀请双方；保留珀布利原调用。 BUGFIX关闭时保留原文本及引用。

**相关文件：** [婚礼对话与肖像切换](data/scripts/de/EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_CeremonyWithPopuriIntroduction.mary.c) · [JP对应文件](data/scripts/jp/EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_CeremonyWithPopuriIntroduction.mary.c) · [US对应文件](data/scripts/us/EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_CeremonyWithPopuriIntroduction.mary.c) · [EU对应文件](data/scripts/eu/EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_CeremonyWithPopuriIntroduction.mary.c) · [EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_Ceremony.mary](data/scripts/de/EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_Ceremony.mary.c) · [JP对应文件](data/scripts/jp/EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_Ceremony.mary.c) · [US对应文件](data/scripts/us/EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_Ceremony.mary.c) · [EU对应文件](data/scripts/eu/EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_Ceremony.mary.c)

<a id="audit-a04"></a>
### 德版Nappy一天收获委托说成一周

**受影响版本：** DE。

**原版内容与差异：**

| 版本 | 一天委托的确认原文 |
|---|---|
| JP | `わかったの。収穫を１日やるの。`——知道了，收获一天。 |
| US＝EU | `Got it. I'll harvest for 1 day, budum.` |
| DE | `Verstanden. Ich ernte eine Woche für dich, budum.`——知道了，我为你收获一周。 |

**判断依据：**

一天分支实际传入 `HARVEST_SPRITE_WORK_DAYS_ONE_DAY`，DE 只是错误共用一周的确认文本，工作时长本身没有变。

其他版本分别提供一天和一周的收获确认。新增德文沿用既有收获确认句式，并参考一天浇水句中的 einen Tag（一天）；这些仅为措辞依据，实际只替换一天收获分支，三天和一周分支保持原样。

**修复方式：**

增加一天收获确认，仅替换一天分支；工作参数不改。 BUGFIX关闭时保留原文本及引用。

**相关文件：** [委托参数与文本调用](data/scripts/de/EventScript_NPCEvent_Nappy_DialogueAndWorkChoices.mary.c) · [JP对应文件](data/scripts/jp/EventScript_NPCEvent_Nappy_DialogueAndWorkChoices.mary.c) · [US对应文件](data/scripts/us/EventScript_NPCEvent_Nappy_DialogueAndWorkChoices.mary.c) · [EU对应文件](data/scripts/eu/EventScript_NPCEvent_Nappy_DialogueAndWorkChoices.mary.c)

<a id="audit-a05"></a>
### 德版一亿鱼成就复用一千万台词

**受影响版本：** DE。

**原版内容与差异：**

| 版本 | 原文数字 |
|---|---|
| JP | `１００００００００匹` |
| US＝EU | `100,000,000 fish!` |
| DE | `10.000.000 Fische` |

**判断依据：**

实际条件是 `GetTotalFishCaught() >= 100000000`，并设置独立的一亿成就标志；DE 错误复用一千万文本。

四版条件均为100000000，JP／US／EU显示一亿。

**修复方式：**

复制本版完整成就消息，仅将数字修为100.000.000，拆开错误复用。 BUGFIX关闭时保留原文本及引用。

**相关文件：** [成就阈值与调用](data/scripts/de/EventScript_AchievementEvent_Fishing_MilestoneReward.mary.c) · [JP对应文件](data/scripts/jp/EventScript_AchievementEvent_Fishing_MilestoneReward.mary.c) · [US对应文件](data/scripts/us/EventScript_AchievementEvent_Fishing_MilestoneReward.mary.c) · [EU对应文件](data/scripts/eu/EventScript_AchievementEvent_Fishing_MilestoneReward.mary.c)

<a id="audit-a06"></a>
### 德版贤者锤领取提示使用秘银锤名

**受影响版本：** DE。

**原版内容与差异：**

| 版本 | 原文 |
|---|---|
| JP | `賢者のハンマー` |
| US＝EU | `Mythic Hammer` |
| DE | `Mythrilhammer`——秘银锤。 |

**判断依据：**

订单实际给予 `ITEM_TOOL_HAMMER_MYTHIC`；DE 道具文本已有正确的 `Mythischer Hammer`，可以直接沿用，不需要另造译名。

其他版本区分两种锤；本版物品表已有Mythischer Hammer（贤者锤）。

**修复方式：**

新增正确工具名称，仅替换贤者锤订单的文本变量引用；实际给予物品不改。 BUGFIX关闭时保留原文本及引用。

**相关文件：** [锻冶屋领取分支](data/scripts/de/EventScript_ShopEvent_Blacksmith_OrderCounter.mary.c) · [JP对应文件](data/scripts/jp/EventScript_ShopEvent_Blacksmith_OrderCounter.mary.c) · [US对应文件](data/scripts/us/EventScript_ShopEvent_Blacksmith_OrderCounter.mary.c) · [EU对应文件](data/scripts/eu/EventScript_ShopEvent_Blacksmith_OrderCounter.mary.c) · [已有德文道具名称](data/text/de/item_1.cc) · [JP对应文件](data/text/jp/item_1.cc) · [US对应文件](data/text/us/item_1.cc) · [EU对应文件](data/text/eu/item_1.cc)

<a id="audit-c01"></a>
### 海外三版：巴基尔雨天台词失去原有的晴雨对比

**受影响版本：** US、EU、DE。

**原版内容与差异：**

- **JP 雨天：** `日に当たっているだけじゃ、かれてしまう。`——光晒太阳也会枯萎。
- **US＝EU：** `They need sunshine or they wither away...`——需要阳光，否则会枯萎。
- **DE：** `Sie brauchen Sonne oder sie gehen ein...`——同上。

**判断依据：**

JP 晴天讲“不晒太阳会萎蔫”，雨天讲“只晒太阳也不行”；海外晴雨共用晴天文本，雨水的重要性被反转。正常的晴天句子应保留。

**修复方式：**

恢复雨天重复对话的独立文本及引用，晴天对话保留。对应重制版US／DE普通对话已有“人和植物过度曝晒都会枯萎”的句子，采用该句并按本作窗口分行。

**相关文件：** [晴雨分支](data/scripts/jp/EventScript_NPCEvent_Basil_DialogueAndGiftResponses.mary.c) · [US对应文件](data/scripts/us/EventScript_NPCEvent_Basil_DialogueAndGiftResponses.mary.c) · [EU对应文件](data/scripts/eu/EventScript_NPCEvent_Basil_DialogueAndGiftResponses.mary.c) · [DE对应文件](data/scripts/de/EventScript_NPCEvent_Basil_DialogueAndGiftResponses.mary.c)

<a id="audit-c02"></a>
### 海外三版：玛丽星夜祭把自己做料理写成妈妈今天做蛋糕

**受影响版本：** US、EU、DE。

**原版内容与差异：**

- **JP：** `ウチではママがケーキとかを作ってたのよ。…今日はママ直伝の料理を作ったんだ。`——以前在娘家妈妈会做蛋糕；今天自己做了妈妈亲传的料理。
- **US＝EU：** `Today my mom made some cake for the Starry Night Festival.`
- **DE：** `Heute hat meine Mutter Kuchen für das Sternennachtfestival gemacht.`

**判断依据：**

时间和料理制作者均改变。婚后有无孩子共用这段话本身合理，不需要因此拆掉正常共用。

母亲以前准备料理；今天由玛丽使用母亲的食谱做饭。有／无孩子继续共用这段话。

**修复方式：**

在GBA既有英文／德文上最小修正：把母亲今天做饭改为母亲以前做饭，补明今天玛丽使用母亲食谱做饭；保留原结尾“Tell me what you think of everything!”／“Sag mir, wie du alles findest!”。日版原文用于核对制作者与时态。重制版只作含义交叉参考，不采用其称呼、家庭描述或结尾，不新增昵称。仅按GBA行宽调整控制符及分行，保留既有节日名称和有／无孩子共用关系。

**相关文件：** [星夜祭对应台词](data/scripts/jp/EventScript_FestivalEvent_StarryNight_WithSpouseAndChild.mary.c) · [US对应文件](data/scripts/us/EventScript_FestivalEvent_StarryNight_WithSpouseAndChild.mary.c) · [EU对应文件](data/scripts/eu/EventScript_FestivalEvent_StarryNight_WithSpouseAndChild.mary.c) · [DE对应文件](data/scripts/de/EventScript_FestivalEvent_StarryNight_WithSpouseAndChild.mary.c) · [重制版英文原文](../SoSFoMTTextDump/SoSFoMTTextDump/US/msg_Scr_Year.txt:2520) · [重制版德文原文](../SoSFoMTTextDump/SoSFoMTTextDump/DE/msg_Scr_Year.txt:2733)

<a id="audit-c03"></a>
### 海外三版：参赛动物确认，把“带走”写成“送给你”

**受影响版本：** US、EU、DE。

**原版内容与差异：**

- **JP：** `わかった。じゃあ、その鶏／牛／羊を連れていくよ。`——知道了，那我把这只鸡／牛／羊带走。
- **US＝EU：** `It's a deal, then. I'll bring it to you.`
- **DE：** `Ok, abgemacht. Ich werde es dir bringen.`

**判断依据：**

调用发生在确认参赛、接走动物时，不是比赛后归还。海外三种动物共用一句不是问题，问题是方向写反。

**修复方式：**

参赛确认改为带走动物，不再说送给玩家；继续供现有动物选择共用。

**相关文件：** [参赛确认原文](data/text/jp/animal_festival_selection.cc) · [US对应文件](data/text/us/animal_festival_selection.cc) · [EU对应文件](data/text/eu/animal_festival_selection.cc) · [DE对应文件](data/text/de/animal_festival_selection.cc) · [调用位置](src/animal_festival_selection.cc)

<a id="audit-c04"></a>
### 海外三版：巴基尔与安娜贺卡标题把 Anna 写成 Ann

**受影响版本：** US、EU、DE。

**原版内容与差异：**

- **JP：** `バジルとアンナからの年賀状`。
- **US＝EU：** 标题 `Card From Basil and Ann`，署名却是 `Basil and Anna`。
- **DE：** 标题 `Karte von Basil und Ann`，署名是 `Basil und Anna`。

**判断依据：**

同一封信正文署名、发送者身份均为 Anna。文件身份不应跟着错标题改成 Ann。

**修复方式：**

贺卡标题Ann改为本作已有的Anna；不改人物身份或收信条件。

**相关文件：** [贺卡标题与署名](data/text/us/reference_guide/new_year_card_basil_and_anna.cc) · [JP对应文件](data/text/jp/reference_guide/new_year_card_basil_and_anna.cc) · [EU对应文件](data/text/eu/reference_guide/new_year_card_basil_and_anna.cc) · [DE对应文件](data/text/de/reference_guide/new_year_card_basil_and_anna.cc)

<a id="audit-c05"></a>
### DE：Lumina 的祖母误写成 Manna

**受影响版本：** DE。

**原版内容与差异：**

- **JP：** `お屋敷に住むロマナの孫娘。`——住在宅邸的 Romana 的孙女。
- **US＝EU：** `Romana's spoiled but shy granddaughter.`
- **DE：** `Mannas verwöhnte aber schüchterne Enkelin.`

**判断依据：**

人物关系明确，DE 姓名错误。

**修复方式：**

Lumina祖母改为本作已有的Romana，不再指向Manna。

**相关文件：** [Lumina 介绍](data/text/de/reference_guide/ngc_awl_profiles_lumina.cc) · [JP对应文件](data/text/jp/reference_guide/ngc_awl_profiles_lumina.cc) · [US对应文件](data/text/us/reference_guide/ngc_awl_profiles_lumina.cc) · [EU对应文件](data/text/eu/reference_guide/ngc_awl_profiles_lumina.cc)

<a id="audit-c06"></a>
### US／EU：Sebastian 介绍中的 Romana 误写成 Manna

**受影响版本：** US、EU。

**原版内容与差异：**

- **JP：** `いつもロマナのそばにいたいのだが、うるさがられるので…`——想总待在 Romana 身边，但会被嫌烦。
- **US＝EU：** `…but this gets on Manna's nerves…`
- **DE：** `…aber das geht Romana auf die Nerven…`

**判断依据：**

JP／DE 及本段前后的人物关系一致，英文中途换成了另一人。

**修复方式：**

Sebastian服务对象改为本作已有的Romana。

**相关文件：** [Sebastian 介绍](data/text/us/reference_guide/ngc_awl_profiles_sebastian.cc) · [JP对应文件](data/text/jp/reference_guide/ngc_awl_profiles_sebastian.cc) · [EU对应文件](data/text/eu/reference_guide/ngc_awl_profiles_sebastian.cc) · [DE对应文件](data/text/de/reference_guide/ngc_awl_profiles_sebastian.cc)

<a id="audit-c07"></a>
### 海外三版：Gustafa 的祖先经历写成本人经历

**受影响版本：** US、EU、DE。

**原版内容与差异：**

- **JP：** `宮廷に代々仕えていた宮廷詩人の末裔。`——世代服务宫廷的宫廷诗人的后裔。
- **US＝EU：** `He used to serve at the court of a distant empire.`
- **DE：** `Er hat am Hof eines fernen Königreiches gedient.`

**判断依据：**

“后裔”被改成“本人曾供职”，身世主体不同，并非单纯译名差异。

**修复方式：**

按JP保留家族世代服务宫廷的身世，将主语从本人改为祖先。

**相关文件：** [Gustafa 介绍](data/text/jp/reference_guide/ngc_awl_profiles_gustafa.cc) · [US对应文件](data/text/us/reference_guide/ngc_awl_profiles_gustafa.cc) · [EU对应文件](data/text/eu/reference_guide/ngc_awl_profiles_gustafa.cc) · [DE对应文件](data/text/de/reference_guide/ngc_awl_profiles_gustafa.cc)

<a id="audit-c08"></a>
### 海外三版：Griffin 被家人厌弃，翻成因爱家而定居

**受影响版本：** US、EU、DE。

**原版内容与差异：**

- **JP：** `家族に愛想をつかされ、一人放浪の末…`——被家人厌弃，独自漂泊后……
- **US＝EU：** `…love for his family caused him to settle in Forget-me-not Valley.`
- **DE：** `…die Liebe zu seiner Familie hat ihn dazu veranlasst, sich … niederzulassen.`

**判断依据：**

家庭关系和定居原因被翻成相反含义。此项与后面的解锁标记遗漏是两个独立问题。

**修复方式：**

按JP恢复四处流浪、被家人厌弃及独自来到谷地的先后关系，不增添定居动机。

**相关文件：** [Griffin 介绍](data/text/jp/reference_guide/ngc_awl_profiles_griffin.cc) · [US对应文件](data/text/us/reference_guide/ngc_awl_profiles_griffin.cc) · [EU对应文件](data/text/eu/reference_guide/ngc_awl_profiles_griffin.cc) · [DE对应文件](data/text/de/reference_guide/ngc_awl_profiles_griffin.cc)

<a id="audit-c09"></a>
### 海外三版：Hardy 入住腾出的房屋，写成跟随 Galen 来村

**受影响版本：** US、EU、DE。

**原版内容与差异：**

- **JP：** `ニーナの死後、ガリが引っ越したのでその後に住み着くことになる。`——Nina 去世、Galen 搬走后，他住进原来的地方。
- **US＝EU：** `He followed Galen to Forget-me-not Valley after Nina's death.`
- **DE：** `Er ist Galen nach Ninas Tod ins Vergissmeinnicht-Tal gefolgt.`

**判断依据：**

搬迁关系不同：接替原住处被误译为跟随某人迁来。

**修复方式：**

明确Nina去世、Galen搬出之后，Hardy才入住旧居；不再说两人结伴来到村子。

**相关文件：** [Hardy 介绍](data/text/jp/reference_guide/ngc_awl_profiles_hardy.cc) · [US对应文件](data/text/us/reference_guide/ngc_awl_profiles_hardy.cc) · [EU对应文件](data/text/eu/reference_guide/ngc_awl_profiles_hardy.cc) · [DE对应文件](data/text/de/reference_guide/ngc_awl_profiles_hardy.cc)

<a id="audit-c10"></a>
### DE：儿子介绍使用了错误的姓名标记

**受影响版本：** DE。

**原版内容与差异：**

- **JP：** `<cp>の息子。`
- **US＝EU：** `<cp>'s son.`
- **DE：** `<cs>s Sohn.`

**判断依据：**

`<cp>` 是联机主角，`<cs>` 是其儿子。DE 当前变成“儿子自己的儿子”，应修正文标记，标题中的 `<cs>` 则正确。

**修复方式：**

仅正文的父亲姓名标记改为<cp>，标题的孩子姓名<cs>保持。

**相关文件：** [儿子介绍](data/text/de/reference_guide/ngc_awl_profiles_child.cc) · [JP对应文件](data/text/jp/reference_guide/ngc_awl_profiles_child.cc) · [US对应文件](data/text/us/reference_guide/ngc_awl_profiles_child.cc) · [EU对应文件](data/text/eu/reference_guide/ngc_awl_profiles_child.cc)

<a id="audit-c11"></a>
### 海外三版：一家三口写成三个儿子

**受影响版本：** US、EU、DE。

**原版内容与差异：**

- **JP：** `嫁さんと息子の３人で暮らしている。`——与妻子、儿子三人一起生活。
- **US＝EU：** `He lives with his wife and 3 sons.`
- **DE：** `Er lebt mit seiner Frau und 3 Söhnen.`

**判断依据：**

“本人＋妻子＋儿子，共三人”误译成“三个儿子”。

**修复方式：**

按JP一家三口恢复为夫妻及一个儿子，不再写成三个儿子。

**相关文件：** [联机主角介绍](data/text/us/reference_guide/ngc_awl_profiles_player.cc) · [JP对应文件](data/text/jp/reference_guide/ngc_awl_profiles_player.cc) · [EU对应文件](data/text/eu/reference_guide/ngc_awl_profiles_player.cc) · [DE对应文件](data/text/de/reference_guide/ngc_awl_profiles_player.cc)

<a id="audit-c12"></a>
### Wally：马拉松教练变成赛事组织者

**受影响版本：** US、EU、DE。

**原版内容与差异：**

| 版本 | 原文 |
|---|---|
| JP | “町の会社でマラソンの監督をしている。”——在城里的公司担任马拉松教练。 |
| US／EU | “He organizes a marathon in town…”——他在城里组织马拉松比赛。 |
| DE | “Er organisiert einen Marathonlauf in der Stadt…”——同样是组织比赛。 |

这是职业含义改变，不是角色译名差异。日文后文还明确交代他退役后成为教练。

**判断依据：**

**修复方式：**

恢复在城里公司任马拉松教练的职业，以及与妻子和儿子住在谷地；不误写本人居住在城里。

**相关文件：** [日文介绍](data/text/jp/reference_guide/ngc_awl_profiles_wally.cc) · [US对应文件](data/text/us/reference_guide/ngc_awl_profiles_wally.cc) · [EU对应文件](data/text/eu/reference_guide/ngc_awl_profiles_wally.cc) · [DE对应文件](data/text/de/reference_guide/ngc_awl_profiles_wally.cc)

<a id="audit-c13"></a>
### Galen：“平时安静”变成“通常很快乐”

**受影响版本：** US、EU、DE。

**原版内容与差异：**

| 版本 | 原文 |
|---|---|
| JP | “頑固で気難しいが、普段はおとなしい。”——固执、难相处，但平时很安静。 |
| US／EU | “He can be quite stubborn but is usually happy.”——可能很固执，但通常很快乐。 |
| DE | “Er kann ziemlich störrisch sein, sonst eine Frohnatur.”——可能很固执，其余时候是个乐天派。 |

`おとなしい` 在这里描述安静、温和的性格，不是快乐或乐天。应修正这个词义，不把妻子去世后的悲伤状态提前套到整个介绍。

**四、确认缺失的完整人物介绍正文**

**判断依据：**

**修复方式：**

将通常很快乐改为通常很安静，保留失去妻子的上下文。

**相关文件：** [日文介绍](data/text/jp/reference_guide/ngc_awl_profiles_galen.cc) · [US对应文件](data/text/us/reference_guide/ngc_awl_profiles_galen.cc) · [EU对应文件](data/text/eu/reference_guide/ngc_awl_profiles_galen.cc) · [DE对应文件](data/text/de/reference_guide/ngc_awl_profiles_galen.cc)

<a id="audit-f01"></a>
### US：卡莲初次见面的 `You name`

**受影响版本：** US。

**原版内容与差异：**

- **JP：** `{Player}くんね。`——你叫……
- **US：** `You name is {Player}, huh?`
- **EU：** `Your name is... {Player}, huh?`
- **DE：** `Du bist {Player}, hm?`

**判断依据：**

US 缺所有格 `Your`，EU 已修正，可直接作为同系列依据。

**修复方式：**

仅US把You name改为Your name，EU已有正确所有格。

**相关文件：** [US 原文](data/scripts/us/EventScript_NPCEvent_Karen_DialogueAndGiftResponses.mary.c) · [JP对应文件](data/scripts/jp/EventScript_NPCEvent_Karen_DialogueAndGiftResponses.mary.c) · [EU对应文件](data/scripts/eu/EventScript_NPCEvent_Karen_DialogueAndGiftResponses.mary.c) · [DE对应文件](data/scripts/de/EventScript_NPCEvent_Karen_DialogueAndGiftResponses.mary.c)

<a id="lou-visit-day"></a>
### 露自我介绍中的来访星期错误

**受影响版本：** US、EU、DE。

**原版内容与差异：**

原文称每周一（Monday／Montag）来访。

**判断依据：**

实际来访日为星期日，JP对应介绍及来访条件一致。

**修复方式：**

仅把错误星期改为星期日。

**相关文件：** [JP](data/scripts/jp/EventScript_NPCEvent_LouOrRuby_Introduction.mary.c) · [US](data/scripts/us/EventScript_NPCEvent_LouOrRuby_Introduction.mary.c) · [EU](data/scripts/eu/EventScript_NPCEvent_LouOrRuby_Introduction.mary.c) · [DE](data/scripts/de/EventScript_NPCEvent_LouOrRuby_Introduction.mary.c)

<a id="manna-duke-reference"></a>
### 玛娜把自己说成另一位在场者

**受影响版本：** US、EU、DE。

**原版内容与差异：**

玛娜说只剩“Manna and me”（我和玛娜）；DE也把同一处称谓写成Manna。

**判断依据：**

说话人已经是玛娜，此处应指她与Duke；JP和同场景人物关系可确定。

**修复方式：**

仅把这处Manna改为Duke，保留其余句子。

**相关文件：** [JP](data/scripts/jp/EventScript_NPCEvent_Cliff_PermanentWineryJob.mary.c) · [US](data/scripts/us/EventScript_NPCEvent_Cliff_PermanentWineryJob.mary.c) · [EU](data/scripts/eu/EventScript_NPCEvent_Cliff_PermanentWineryJob.mary.c) · [DE](data/scripts/de/EventScript_NPCEvent_Cliff_PermanentWineryJob.mary.c)

<a id="lillia-wedding"></a>
### 莉莉娅在女儿婚礼后声称自己嫁给凯

**受影响版本：** US、EU、DE。

**原版内容与差异：**

US／EU：Everybody I love is here to celebrate my marriage with Kai.；DE也称大家来庆祝“我和凯的婚礼”。

**判断依据：**

此处说话者是新娘珀布利的母亲莉莉娅。JP表达女儿成为新娘，自己仍未习惯的感想。

**修复方式：**

按GBA日文补译女儿出嫁的感想；不采用重制版角色身份反推台词。

**相关文件：** [JP](data/scripts/jp/EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue.mary.c) · [US](data/scripts/us/EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue.mary.c) · [EU](data/scripts/eu/EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue.mary.c) · [DE](data/scripts/de/EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue.mary.c)

<a id="van-name-history"></a>
### 联机商人姓名错译为 Lou／Lu

**受影响版本：** US、EU、DE。

**原版内容与差异：**

姓名栏为 Lou／Lu，但角色日文名为バァン，英语自我介绍明确写 Van。同一时期 NGC《A Wonderful Life》和 NDS《Harvest Moon DS》中的商人也叫 Van。这是 GBA 的姓名错译，不是商人跨作品改名。

**判断依据：**

GBA 姓名栏和自我介绍直接冲突；JP 的バァン及同期联动商人的 Van 确定身份。旅馆料理角色 Ruby／Lou 的名称沿革属于另一人，不能用来解释商人的错误名字。

**修复方式：**

开启 `BUGFIX` 时把海外商人姓名栏改为 Van；关闭时保留 Lou／Lu。角色 ID、变量名和其他事件不变。

**相关文件：** [US 自我介绍](data/scripts/us/EventScript_NPCEvent_Van_Introduction.mary.c) · [JP 姓名](data/text/jp/npc_collection.cc) · [US 姓名](data/text/us/npc_collection.cc) · [EU 姓名](data/text/eu/npc_collection.cc) · [DE 姓名](data/text/de/npc_collection.cc)

<a id="ruby-name"></a>
### 料理来访者未使用同期英文名 Ruby

**受影响版本：** US、EU、DE。

**原版内容与差异：**

海外姓名栏为 Lu，自我介绍为 Lou；JP 为ルウ。但本作自己的 NGC 人物介绍标题、正文、人物选择菜单及 Rock 简介已经使用 Ruby，构成本作内部的命名不一致。该角色是 NGC 联动作品的旅馆料理经营者，NGC 和 NDS 的同期英文名也为 Ruby。

**判断依据：**

本作 [Ruby 的 NGC 人物介绍](data/text/us/reference_guide/ngc_awl_profiles_ruby.cc)、[Rock 简介中的父母称呼](data/text/us/reference_guide/ngc_awl_profiles_rock.cc)和 [NGC 人物选择菜单](data/scripts/us/EventScript_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser.mary.c)均直接写 Ruby；EU、DE 对应内容也一致。因此这次修复不是单纯借用其他作品的名字，而是与本作已存在的同一角色介绍统一。

| 作品时期 | 料理旅馆经营者 | 旅行商人 |
| --- | --- | --- |
| NGC《A Wonderful Life》英文版 | Ruby | Van |
| 本作 GBA US／EU／DE | 姓名栏 Lu、自介 Lou | 姓名栏 Lou／Lu，英语自介 Van |
| NDS《Harvest Moon DS》英文版 | Ruby | Van |
|《Story of Seasons: Friends of Mineral Town》重制版 | Lou | Van |

NGC 的[联机资料](https://fogu.com/hm/hmawl/gbaconnection.php)、NDS 的 [Ruby](https://fogu.com/hm6/chan3/villagers/ruby.php)／[Van](https://fogu.com/hm6/chan3/villagers/van.php) 页面及重制版 [Lou 的旧名说明](https://fogu.com/sos3/mineral_town/villagers/lou.html)互相印证。跨作品名称历史主要来自同一社区攻略站；本作原文则直接由下列源码核对。

**命名取舍：** NGC、NDS 的 Ruby 符合本作 GBA 联动所处的时代；重制版的 Lou 是较远时期的变更。本项目选择同期的 Ruby，不用后来的 Lou 覆盖旧时代的联动身份。

**修复方式：**

开启 `BUGFIX` 时，海外姓名栏 Lu 和自我介绍 Lou 均改为 Ruby；JP 的ルウ不变。关闭时保留原文。保留 `LouOrRuby`／`CHARACTER_LOU_OR_RUBY` 标识符和角色 ID，不涉及人物顺序或事件机制。

**相关文件：** [US 姓名](data/text/us/npc_collection.cc) · [EU 姓名](data/text/eu/npc_collection.cc) · [DE 姓名](data/text/de/npc_collection.cc) · [US 自介](data/scripts/us/EventScript_NPCEvent_LouOrRuby_Introduction.mary.c) · [EU 自介](data/scripts/eu/EventScript_NPCEvent_LouOrRuby_Introduction.mary.c) · [DE 自介](data/scripts/de/EventScript_NPCEvent_LouOrRuby_Introduction.mary.c)

<a id="spouse-birthday-baby-talk"></a>
### 玩家生日晚餐的妻子问候误用婴儿语

**受影响版本：** US、EU。

**原版内容与差异：**

琳／艾利在玩家生日晚餐说婴儿式问候。

**判断依据：**

消息调用位于妻子姓名栏及头像后，并在是否生育的分支之前；JP是工作结束后的问候。

**修复方式：**

按JP补译妻子的问候，不改孩子正常婴儿语。

**相关文件：** [JP](data/scripts/jp/EventScript_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice.mary.c) · [US](data/scripts/us/EventScript_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice.mary.c) · [EU](data/scripts/eu/EventScript_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice.mary.c) · [DE](data/scripts/de/EventScript_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice.mary.c) · [JP](data/scripts/jp/EventScript_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice.mary.c) · [US](data/scripts/us/EventScript_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice.mary.c) · [EU](data/scripts/eu/EventScript_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice.mary.c) · [DE](data/scripts/de/EventScript_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice.mary.c)

<a id="anna-gift-birthday"></a>
### 安娜普通赠礼答谢误提生日

**受影响版本：** US、EU。

**原版内容与差异：**

普通赠礼句把这次礼物称作生日礼物。

**判断依据：**

此消息可在普通赠礼分支调用；生日额外效果由独立条件处理。

**修复方式：**

去除错误生日限定，不改礼物好感及生日乘数。

**相关文件：** [JP](data/scripts/jp/EventScript_NPCEvent_Anna_DialogueAndGiftResponses.mary.c) · [US](data/scripts/us/EventScript_NPCEvent_Anna_DialogueAndGiftResponses.mary.c) · [EU](data/scripts/eu/EventScript_NPCEvent_Anna_DialogueAndGiftResponses.mary.c) · [DE](data/scripts/de/EventScript_NPCEvent_Anna_DialogueAndGiftResponses.mary.c)

<a id="carter-untranslated"></a>
### 卡特葡萄园兼职提示及选项残留德语

**受影响版本：** US、EU。

**原版内容与差异：**

原提示含Ein Teilzeitjob auf dem Weingut…，选项为Von Job erzählen／Nicht erzählen。

**判断依据：**

JP为告知兼职机会；本作其他村民有对应英文选项，重制版有对应兼职提示。

**修复方式：**

提示参考对应重制版英文，选项沿用本作Tell about the job／Don’t tell的句式。

**相关文件：** [JP](data/scripts/jp/EventScript_NPCEvent_Carter_DialogueAndGiftResponses.mary.c) · [US](data/scripts/us/EventScript_NPCEvent_Carter_DialogueAndGiftResponses.mary.c) · [EU](data/scripts/eu/EventScript_NPCEvent_Carter_DialogueAndGiftResponses.mary.c) · [DE](data/scripts/de/EventScript_NPCEvent_Carter_DialogueAndGiftResponses.mary.c)

<a id="nappy-perfume"></a>
### 精灵香水答谢残留日文

**受影响版本：** US、EU。

**原版内容与差异：**

英语脚本的香水答谢仍为わぁ～、いい香りなの。（哇，好香。）

**判断依据：**

这是已经被英语对话调用的日文，重制版有对应赠礼反应可参考。

**修复方式：**

补为英语香味答谢，不改礼物判断或好感。

**相关文件：** [JP](data/scripts/jp/EventScript_NPCEvent_Nappy_DialogueAndWorkChoices.mary.c) · [US](data/scripts/us/EventScript_NPCEvent_Nappy_DialogueAndWorkChoices.mary.c) · [EU](data/scripts/eu/EventScript_NPCEvent_Nappy_DialogueAndWorkChoices.mary.c) · [DE](data/scripts/de/EventScript_NPCEvent_Nappy_DialogueAndWorkChoices.mary.c)

<a id="zack-untranslated"></a>
### 扎克牧场生活夸奖残留日文

**受影响版本：** US、EU。

**原版内容与差异：**

{Player}、けっこう牧場がにあってんじゃねぇか？…これでも、ほめてんだぜ～。仍以日文显示。

**判断依据：**

JP含义是牧场生活很适合玩家，下一页明确这是夸奖。

**修复方式：**

按GBA日文直译并保留原两页及最后的夸奖说明，不额外添加情绪台词。

**相关文件：** [JP](data/scripts/jp/EventScript_NPCEvent_Zack_DialogueAndGiftResponses.mary.c) · [US](data/scripts/us/EventScript_NPCEvent_Zack_DialogueAndGiftResponses.mary.c) · [EU](data/scripts/eu/EventScript_NPCEvent_Zack_DialogueAndGiftResponses.mary.c) · [DE](data/scripts/de/EventScript_NPCEvent_Zack_DialogueAndGiftResponses.mary.c)

<a id="english-spelling"></a>
### 人物和物件名称的英文拼写错误

**受影响版本：** US、EU。

**原版内容与差异：**

出现Sopha、Barely、Lillian、ready Basil、anythign等与对象或句意不符的写法。

**判断依据：**

Sofa、Barley、Lillia、Basil及anything可由本作其他正确文本和对应人物确认；不把正常地区译名差异当作错误。

**修复方式：**

仅修对应单词，不改角色ID或脚本条件。

**相关文件：** [JP](data/scripts/jp/EventScript_LocationInteraction_InspectClinic1FSofa.mary.c) · [US](data/scripts/us/EventScript_LocationInteraction_InspectClinic1FSofa.mary.c) · [EU](data/scripts/eu/EventScript_LocationInteraction_InspectClinic1FSofa.mary.c) · [DE](data/scripts/de/EventScript_LocationInteraction_InspectClinic1FSofa.mary.c) · [JP](data/scripts/jp/EventScript_NPCEvent_Manna_DialogueAndGiftResponses.mary.c) · [US](data/scripts/us/EventScript_NPCEvent_Manna_DialogueAndGiftResponses.mary.c) · [EU](data/scripts/eu/EventScript_NPCEvent_Manna_DialogueAndGiftResponses.mary.c) · [DE](data/scripts/de/EventScript_NPCEvent_Manna_DialogueAndGiftResponses.mary.c) · [JP](data/text/jp/scene_special_merchant_shop.cc) · [US](data/text/us/scene_special_merchant_shop.cc) · [EU](data/text/eu/scene_special_merchant_shop.cc) · [DE](data/text/de/scene_special_merchant_shop.cc) · [JP](data/scripts/jp/EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Ann.mary.c) · [US](data/scripts/us/EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Ann.mary.c) · [EU](data/scripts/eu/EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Ann.mary.c) · [DE](data/scripts/de/EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Ann.mary.c) · [JP](data/scripts/jp/EventScript_NPCEvent_Anna_DialogueAndGiftResponses.mary.c) · [US](data/scripts/us/EventScript_NPCEvent_Anna_DialogueAndGiftResponses.mary.c) · [EU](data/scripts/eu/EventScript_NPCEvent_Anna_DialogueAndGiftResponses.mary.c) · [DE](data/scripts/de/EventScript_NPCEvent_Anna_DialogueAndGiftResponses.mary.c)

<a id="winery-job-decline-duke-dialogue"></a>
### 玩家拒绝采葡萄时杜克向未到场的克里夫讲话

**受影响版本：** US、EU、DE。

**原版内容与差异：**

第 1 年秋 15 日的酒庄事件中，玩家拒绝当天帮忙且此前未告诉克里夫，海外杜克却欢迎克里夫并表示要教他做事。JP 的对应台词是劝玩家不用道歉，并说自己会加油。

**判断依据：**

该分支中克里夫没有入场。重制版同一分支的英语和德语都保留了劝慰及杜克自己尽力做的两层意思。玩家已邀请克里夫后拒绝帮忙有独立台词。

**修复方式：**

将重制版对应的英语和德语原句按 GBA 行宽分成两页，末句放在第二页。分支条件及淡出后的独立收尾照旧。

**相关文件：** [酒庄事件入口](data/scripts/jp/EventScript_LocationTransition_EnterAjaWinery1FWithEventDispatch.mary.c) · [JP](data/scripts/jp/EventScript_NPCEvent_Cliff_PermanentWineryJob.mary.c) · [US](data/scripts/us/EventScript_NPCEvent_Cliff_PermanentWineryJob.mary.c) · [EU](data/scripts/eu/EventScript_NPCEvent_Cliff_PermanentWineryJob.mary.c) · [DE](data/scripts/de/EventScript_NPCEvent_Cliff_PermanentWineryJob.mary.c)

<a id="de-popuri-newborn-dialogue"></a>
### 德版珀布利谈新生儿时多播一条英文

**受影响版本：** DE。

**原版内容与差异：**

婚后分娩事件已结束、孩子 0–59 天时，在 06:00–11:59 的农舍首谈中，德版先播放一条带 `//` 的英文，再播放意思相同的德文。

**判断依据：**

JP、US、EU 在对应分支只说一次孩子可爱。DE 已有与场景对应的德语。

**修复方式：**

移除多余的英文文本和播放调用，保留 `Ahhh....Er ist sooo süß!`（啊……他真可爱！）。

**相关文件：** [DE](data/scripts/de/EventScript_NPCEvent_Popuri_DialogueAndGiftResponses.mary.c) · [JP 对照](data/scripts/jp/EventScript_NPCEvent_Popuri_DialogueAndGiftResponses.mary.c) · [US 对照](data/scripts/us/EventScript_NPCEvent_Popuri_DialogueAndGiftResponses.mary.c)

<a id="de-popuri-child-first-steps"></a>
### 德版珀布利在孩子学步事件中重复同一句

**受影响版本：** DE。

**原版内容与差异：**

孩子第一次走路的事件中，德版连续两次调用珀布利说明孩子今早开始走路、自己差点哭出来的对话。

**判断依据：**

JP、US、EU 的第二句感叹孩子长得很快，本作德版玛丽的育儿日常对话有同义句。

**修复方式：**

保留学步第一句，第二次调用改为珀布利的独立对话 `Er wird einfach so schnell groß!`（他长得真快呀！）。

**相关文件：** [珀布利学步事件](data/scripts/de/EventScript_FamilyEvent_Popuri_ChildFirstSteps.mary.c) · [玛丽的德语原句](data/scripts/de/EventScript_NPCEvent_Mary_DialogueAndGiftResponses.mary.c) · [JP 对照](data/scripts/jp/EventScript_FamilyEvent_Popuri_ChildFirstSteps.mary.c) · [US 对照](data/scripts/us/EventScript_FamilyEvent_Popuri_ChildFirstSteps.mary.c)

<a id="de-manna-flatters-jeff"></a>
### 德版玛娜恭维杰夫时夸奖对象颠倒

**受影响版本：** DE。

**原版内容与差异：**

玛娜在杂货店称赞杰夫后问价。JP为 `わたしもホレてしまいそうよ。`（连我都快喜欢上你了），US／EU为 `I might develop a crush on you myself!`（我自己都快喜欢上你了）。DE的 `Ich bin zum Verlieben!` 却成了“我很招人喜欢”，把被称赞的人从杰夫换成玛娜自己。

**判断依据：**

前文始终是玛娜恭维杰夫，后续由杰夫回应并给她优惠；英日对应文本也明确指向杰夫。德版三处消息速度不同是独立的地区演出，不因此改变。

**修复方式：**

仅在BUGFIX开启时将德文第一句改为 `Ich könnte mich glatt in dich verlieben!`（我简直要喜欢上你了！），按现有行宽分行，恢复英日同一场景的含义。保留原问价两行、杰夫半价答复、肖像和消息调用顺序。

**相关文件：** [DE](data/scripts/de/EventScript_NPCEvent_Manna_FlattersJeff.mary.c) · [JP](data/scripts/jp/EventScript_NPCEvent_Manna_FlattersJeff.mary.c) · [US](data/scripts/us/EventScript_NPCEvent_Manna_FlattersJeff.mary.c) · [EU](data/scripts/eu/EventScript_NPCEvent_Manna_FlattersJeff.mary.c)

<a id="category-guides"></a>
## 指南结构、正文与玩法说明

| 问题 | 受影响版本 | 开关支持 |
| --- | --- | --- |
| [出荷价格指南：按道具名称列出三个品质的鸡蛋并修正海外胡萝卜价格](#audit-b01) | JP、US、EU、DE | 已接入 |
| [海外三版：图书馆休馆日变更方向写反](#audit-b02) | US、EU、DE | 已接入 |
| [海外三版：牛羊牧场指南说可以卖鸡](#audit-b03) | US、EU、DE | 已接入 |
| [海外三版：诊所营业时间表述错误，德版采用24小时制](#audit-b04) | US、EU、DE | 已接入 |
| [海外三版：料理指南多写一个重复选项](#audit-b05) | US、EU、DE | 已接入 |
| [DE：秘银锄头误写成秘银镰刀](#audit-b06) | DE | 已接入 |
| [DE：计步器“装备”误译成“升级”](#audit-b07) | DE | 已接入 |
| [海外三版：四种作物最终收获阶段写成开花](#audit-b08) | US、EU、DE | 已接入 |
| [海外三版：疲劳段落错写成体力效果](#audit-b09) | US、EU、DE | 已接入 |
| [DE：冰箱让一次“购买更多”写成“烹饪更多”](#audit-b10) | DE | 已接入 |
| [海外三版：霍安出售的种子是否随季节变化，含义写反](#audit-b11) | US、EU、DE | 已接入 |
| [锤子指南：海外漏掉银锤说明，日版次数也存在问题](#audit-b13) | JP、US、EU、DE | 已接入 |
| [房屋“两阶段扩建”误译成“建造二楼”](#audit-b14) | US、EU、DE | 已接入 |
| [孵化箱随鸡舍扩建增加，误译成可以购买](#audit-b15) | US、EU、DE | 已接入 |
| [德文鸡饲料制作提示把“玉米”泛化成“谷物”](#audit-b16) | DE | 已接入 |
| [US／EU：Nina 缺少第一段解锁边界](#audit-d01) | US、EU | 已接入 |
| [海外三版：Griffin 缺少第二段解锁边界](#audit-d02) | US、EU、DE | 已接入 |
| [海外三版：Nak 缺少第二段解锁边界](#audit-d03) | US、EU、DE | 已接入 |
| [DE：四本指南／贺卡的标题缺失，正文第一句占据固定标题位置](#audit-d04) | DE | 已接入 |
| [DE：食谱中的黄油小标题缺失](#audit-d05) | DE | 已接入 |
| [Wally：海外缺两段](#audit-d06) | US、EU、DE | 已接入 |
| [Hugh：海外缺两段](#audit-d07) | US、EU、DE | 已接入 |
| [Samantha：海外缺两段](#audit-d08) | US、EU、DE | 已接入 |
| [Galen：海外缺最后一段](#audit-d09) | US、EU、DE | 已接入 |
| [Daryl：海外缺两段](#audit-d10) | US、EU、DE | 已接入 |
| [JP：味噌汤食谱的锅写成 `なぺ`](#audit-f02) | JP | 已接入 |
| [海外三版：食谱牛奶单词残缺](#audit-f03) | US、EU、DE | 已接入 |
| [DE：酱油名称出现错误字符](#audit-f04) | DE | 已接入 |
| [酒庄告示休息日错误](#winery-day-off) | US、EU、DE | 已接入 |
| [巨石说明把五级锤条件写成玩家当前等级](#huge-stone-description) | US、EU、DE | 已接入 |
| [出货价格指南的黄玉与红宝石价格错误](#guide-topaz-ruby-prices) | 四版 | 已接入 |
| [魔术草指南少写一天成长时间](#guide-magic-grass-growth-days) | 四版 | 已接入 |
| [秋季作物清单漏列红薯](#guide-fall-sweet-potato) | US、EU、DE | 已接入 |

<a id="audit-b01"></a>
### 出荷价格指南：按道具名称列出三个品质的鸡蛋并修正海外胡萝卜价格

**受影响版本：** JP、US、EU、DE。

**原版内容与差异：**

| 对象 | JP | US＝EU | DE | 实际价格 |
|---|---|---|---|---|
| 好品质鸡蛋 | `いい品質の卵 ５０Ｇ` | 没有对应品质行 | 没有对应品质行 | 60G |
| 很高品质鸡蛋 | `かなりいい品質の卵 ５０Ｇ` | 没有对应品质行 | 没有对应品质行 | 80G |
| 胡萝卜 | `にんじん １２０Ｇ` | `Carrot 60G` | `Karotte 60G` | 120G |
| 金蛋 | 没有对应行 | `Golden Egg 150G` | `Goldenes Ei 150G` | 100G |

**判断依据：**

`gProductInfo` 的实际价格。应修指南文字，不改价格表迎合错误说明。

**对应名称：** 四版均采用对应道具的普通、好、高品质鸡蛋名称，分别对应50／60／80G。S／M／L只是在讨论时说明等级，不是显示名称；海外指南以这三种蛋替换原普通蛋、温泉蛋和金蛋三行。胡萝卜修为120G。英文采用 `Regular Quality Egg`、`Good Quality Egg`、`High Quality Egg`，德文采用道具名称 `Gewöhnliches Ei`、`Hochwertiges Ei`、`Sehr hochw. Ei`；日文保留三个实际道具名称。

**修复方式：**

四版均列出普通、好、高品质三种鸡蛋，使用各版本道具名称，价格分别为50／60／80G；海外指南以这三行替换原普通蛋、温泉蛋和金蛋三行。S／M／L仅用于说明等级对应，不写入名称。海外胡萝卜改为120G，未改实际商品价格。

**相关文件：** [JP 指南](data/text/jp/reference_guide/sell_price.cc) · [US对应文件](data/text/us/reference_guide/sell_price.cc) · [EU对应文件](data/text/eu/reference_guide/sell_price.cc) · [DE对应文件](data/text/de/reference_guide/sell_price.cc) · [实际数据](src/item.cc)

<a id="audit-b02"></a>
### 海外三版：图书馆休馆日变更方向写反

**受影响版本：** US、EU、DE。

**原版内容与差异：**

- **JP：** `お休みが月曜日から木曜日に変わりました。`——从星期一改为星期四。
- **US＝EU：** `Our day off is changing from Thursday to Monday.`——星期四改星期一。
- **DE：** `Unser freier Tag ist nun Montag anstatt Donnerstag.`——现在星期一休息，不再是星期四。

**判断依据：**

通知在玛丽与格雷结婚后送出，婚后营业告示明确是星期四休馆。

**修复方式：**

将休馆日变更改为星期一改星期四，沿用本版既有星期名称。

**相关文件：** [通知原文](data/text/us/reference_guide/notice_marys_library_day_off_change.cc) · [JP对应文件](data/text/jp/reference_guide/notice_marys_library_day_off_change.cc) · [EU对应文件](data/text/eu/reference_guide/notice_marys_library_day_off_change.cc) · [DE对应文件](data/text/de/reference_guide/notice_marys_library_day_off_change.cc) · [婚前后告示](data/scripts/jp/EventScript_LocationInteraction_InspectTownNorthLibraryHoursSign.mary.c) · [US对应文件](data/scripts/us/EventScript_LocationInteraction_InspectTownNorthLibraryHoursSign.mary.c) · [EU对应文件](data/scripts/eu/EventScript_LocationInteraction_InspectTownNorthLibraryHoursSign.mary.c) · [DE对应文件](data/scripts/de/EventScript_LocationInteraction_InspectTownNorthLibraryHoursSign.mary.c)

<a id="audit-b03"></a>
### 海外三版：牛羊牧场指南说可以卖鸡

**受影响版本：** US、EU、DE。

**原版内容与差异：**

- **JP：** `牛、羊を売ることもできる。`——也能出售牛、羊。
- **US＝EU：** `or sell your Chickens.`
- **DE：** `oder deine Hühner verkaufen.`——出售你的鸡。

**判断依据：**

此处是牛羊商店，实际菜单出售牛、羊，不出售鸡。

**修复方式：**

只将可出售动物改为牛与羊，保持牛羊牧场的其他说明。

**相关文件：** [指南](data/text/us/reference_guide/yodel_farm.cc) · [JP对应文件](data/text/jp/reference_guide/yodel_farm.cc) · [EU对应文件](data/text/eu/reference_guide/yodel_farm.cc) · [DE对应文件](data/text/de/reference_guide/yodel_farm.cc) · [商店处理](src/scene_yodel_ranch_shop.cc)

<a id="audit-b04"></a>
### 海外三版：诊所营业时间表述错误，德版采用24小时制

**受影响版本：** US、EU、DE。

**原版内容与差异：**

- **JP：** `午前９時～午後４時`。
- **US＝EU：** `9AM-4AM`。
- **DE：** `9-4 Uhr`。

**判断依据：**

营业告示是09:00至16:00，英文末尾应为下午。DE 表达不够明确，但没有英文这种显式的 AM 错误。用户随后确认德版也按24小时制修为9–16 Uhr。

**修复方式：**

US／EU改为9AM—4PM；DE改为9—16 Uhr，按本版24小时制。

**相关文件：** [指南](data/text/us/reference_guide/clinic.cc) · [JP对应文件](data/text/jp/reference_guide/clinic.cc) · [EU对应文件](data/text/eu/reference_guide/clinic.cc) · [DE对应文件](data/text/de/reference_guide/clinic.cc) · [营业告示](data/scripts/jp/EventScript_LocationInteraction_InspectClinicBusinessHoursSign.mary.c) · [US对应文件](data/scripts/us/EventScript_LocationInteraction_InspectClinicBusinessHoursSign.mary.c) · [EU对应文件](data/scripts/eu/EventScript_LocationInteraction_InspectClinicBusinessHoursSign.mary.c) · [DE对应文件](data/scripts/de/EventScript_LocationInteraction_InspectClinicBusinessHoursSign.mary.c)

<a id="audit-b05"></a>
### 海外三版：料理指南多写一个重复选项

**受影响版本：** US、EU、DE。

**原版内容与差异：**

- **JP：** `レシピ通りにつくる`／`アレンジしてみる`／`やっぱりやめる`——按食谱／尝试调整／取消。
- **US＝EU：** `Follow the recipe.`／`Improvise on recipe.`／`Start again.`／`Start over.`
- **DE：** `Rezept befolgen.`／`Mit Rezept improvisieren.`／`Erneut beginnen.`／`Erneut beginnen.`

**判断依据：**

食材齐全时的实际调用只有三个选项：`FollowRecipe`、`ImproviseRecipe`、`MakeAnotherRecipe`。指南重复列出返回项，不应新增第四个程序选项。

**修复方式：**

移除重复的“重新开始”解释，恢复现有料理菜单中的“另选食谱”及返回食谱选择说明。

**相关文件：** [指南](data/text/us/reference_guide/how_to_cook.cc) · [JP对应文件](data/text/jp/reference_guide/how_to_cook.cc) · [EU对应文件](data/text/eu/reference_guide/how_to_cook.cc) · [DE对应文件](data/text/de/reference_guide/how_to_cook.cc) · [实际菜单调用](src/scene_cooking.cc)

<a id="audit-b06"></a>
### DE：秘银锄头误写成秘银镰刀

**受影响版本：** DE。

**原版内容与差异：**

- **JP：** `ミスリルのクワ`——秘银锄头。
- **US＝EU：** `Mystrile Hoe`。
- **DE：** `Mythrilsichel`——秘银镰刀。

**判断依据：**

所在段落描述一次耕前方六格土地，是锄头，不是镰刀。

**修复方式：**

仅锄头段的Mythrilsichel（秘银镰刀）改为同版Mythrilhacke（秘银锄头）；真正的镰刀段不变。

**相关文件：** [工具指南](data/text/de/reference_guide/using_tools_1.cc) · [JP对应文件](data/text/jp/reference_guide/using_tools_1.cc) · [US对应文件](data/text/us/reference_guide/using_tools_1.cc) · [EU对应文件](data/text/eu/reference_guide/using_tools_1.cc)

<a id="audit-b07"></a>
### DE：计步器“装备”误译成“升级”

**受影响版本：** DE。

**原版内容与差异：**

- **JP：** `装備していなくてもいいんだけど、装備して使っても歩数は増やせる。`——不必装备，装备使用也能增加步数。
- **US＝EU：** `It doesn't even have to be equipped, but it works equipped as well.`
- **DE：** `Dieser muss nicht einmal aufgerüstet werden, aber wenn du ihn aufrüstest, funktioniert er auch.`——不必升级，升级后也能用。

**判断依据：**

`aufgerüstet` 指升级；这里的操作是装备计步器，程序没有该段所说的计步器升级。

**修复方式：**

将计步器的升级动词改为装备动词，不新增计步器升级功能。

**相关文件：** [计步器段落](data/text/de/reference_guide/using_tools_1.cc) · [JP对应文件](data/text/jp/reference_guide/using_tools_1.cc) · [US对应文件](data/text/us/reference_guide/using_tools_1.cc) · [EU对应文件](data/text/eu/reference_guide/using_tools_1.cc)

<a id="audit-b08"></a>
### 海外三版：四种作物最终收获阶段写成开花

**受影响版本：** US、EU、DE。

**原版内容与差异：**

- **JP：** 番茄、玉米、菠萝、青椒对应 `種－→①－→②－→③－→実`。
- **US＝EU：** 对应末尾为 `Flowers`。
- **DE：** 对应末尾为 `Blüte`。

**判断依据：**

这些行描述上述作物结成果实的收获阶段。修复只涉及四种作物，不能把花卉行中的 Flowers／Blüte 一并替换。

**修复方式：**

将四种可重复收获作物的成熟阶段改为Ripe／Reife，保留实际花卉的开花说明。

**相关文件：** [四版对应的作物指南](data/text/us/reference_guide/seasonal_crops.cc) · [JP对应文件](data/text/jp/reference_guide/seasonal_crops.cc) · [EU对应文件](data/text/eu/reference_guide/seasonal_crops.cc) · [DE对应文件](data/text/de/reference_guide/seasonal_crops.cc)

<a id="audit-b09"></a>
### 海外三版：疲劳段落错写成体力效果

**受影响版本：** US、EU、DE。

**原版内容与差异：**

- **JP：** `食べた物によって回復量は変化。増える場合もある`——视食物而变化，也可能增加疲劳。
- **US＝EU：** `Some foods will deplete Stamina.`——有些食物会消耗体力。
- **DE：** `Manche Nahrungsmittel verringern die Ausdauer.`——有些食物降低体力。

**判断依据：**

当前小节讲疲劳，海外复制了体力小节的含义。不是需要修改食物实际恢复字段。

**修复方式：**

仅疲劳段改为增加疲劳；不修改前面的体力说明或食物数值。

**相关文件：** [体力／疲劳指南](data/text/us/reference_guide/stamina_and_fatigue.cc) · [JP对应文件](data/text/jp/reference_guide/stamina_and_fatigue.cc) · [EU对应文件](data/text/eu/reference_guide/stamina_and_fatigue.cc) · [DE对应文件](data/text/de/reference_guide/stamina_and_fatigue.cc)

<a id="audit-b10"></a>
### DE：冰箱让一次“购买更多”写成“烹饪更多”

**受影响版本：** DE。

**原版内容与差异：**

- **JP：** `『冷蔵庫』があれば、一度にたくさん買える。`
- **US＝EU：** `You can buy more at one time if you have a Refrigerator.`
- **DE：** `Du kannst mehr auf einmal kochen, wenn du einen Kühlschrank hast.`

**判断依据：**

杂货店购买说明中，德文 `kochen` 是烹饪，原意是购买。

**修复方式：**

将冰箱扩容的结果改为一次购买更多，保留既有厨房及储物机制。

**相关文件：** [杂货店指南](data/text/de/reference_guide/supermarket.cc) · [JP对应文件](data/text/jp/reference_guide/supermarket.cc) · [US对应文件](data/text/us/reference_guide/supermarket.cc) · [EU对应文件](data/text/eu/reference_guide/supermarket.cc)

<a id="audit-b11"></a>
### 海外三版：霍安出售的种子是否随季节变化，含义写反

**受影响版本：** US、EU、DE。

**原版内容与差异：**

- **JP：** `季節によって売っている種の種類は変わらない。`——不会随季节变化。
- **US＝EU：** `Different Seeds are sold in different seasons.`——不同季节卖不同种子。
- **DE：** `In verschiedenen Jahreszeiten werden verschiedene Samen verkauft.`——同上。

**判断依据：**

商店实现连续加入七种种子，没有对这些种子进行季节筛选。US／EU 附近还有一条孤立的 `different seasons.` 残句，可一并核对排版。

**修复方式：**

明确霍安全年出售相同种子；保留种植仍受季节限制的说明。

**相关文件：** [指南](data/text/us/reference_guide/wons_shop.cc) · [JP对应文件](data/text/jp/reference_guide/wons_shop.cc) · [EU对应文件](data/text/eu/reference_guide/wons_shop.cc) · [DE对应文件](data/text/de/reference_guide/wons_shop.cc) · [商品加入逻辑](src/scene_won_shop.cc)

<a id="audit-b13"></a>
### 锤子指南：海外漏掉银锤说明，日版次数也存在问题

**受影响版本：** JP、US、EU、DE。

**原版内容与差异：**

| 版本 | 相关原文及含义 |
|---|---|
| JP | 铜锤：“壊すまで６回叩く必要がある。”；银锤：“『岩』……６回”“『大きな石』だと３回”。即铜锤碎大石6次，银锤碎岩6次、碎大石3次。 |
| US／EU | “Copper Hammer… smash huge Stones with six tries and large Stones in only three tries.”——把碎两类石头的能力都归给铜锤，没有银锤那一段。 |
| DE | “Mit einem Kupferhammer… riesige Steine mit 6 Schlägen und große Steine mit nur 3 Schlägen…”——同样归给铜锤。 |

实际核对到的**农场石块、充分蓄力**处理是：

| 锤子 | 大石 | 岩 |
|---|---:|---:|
| 铜锤 | 3次 | 不能破坏 |
| 银锤 | 2次 | 6次 |
| 秘银锤 | 1次 | 2次 |

依据是蓄力等级、工具效果表，以及两类石块的初始耐久和每击扣除公式；四格组成的石块分别更新各格，不是同一耐久被连扣四次。因此不能直接把日文次数搬到海外版。

**判断依据：**

**修复方式：**

按已核实的充分蓄力条件改为铜锤大石3次、银锤大石2次／岩石6次、秘银1／2次。海外补银阶；不修改此前否决的银锤物品描述。

**相关文件：** [蓄力等级](src/player_actor.cc:29567) · [效果表](src/animal_data.cc:93) · [石块耐久处理](src/field.cc:209) · [日文指南](data/text/jp/reference_guide/using_tools_1.cc) · [US对应文件](data/text/us/reference_guide/using_tools_1.cc) · [EU对应文件](data/text/eu/reference_guide/using_tools_1.cc) · [DE对应文件](data/text/de/reference_guide/using_tools_1.cc)

<a id="audit-b14"></a>
### 房屋“两阶段扩建”误译成“建造二楼”

**受影响版本：** US、EU、DE。

**原版内容与差异：**

| 版本 | 原文 |
|---|---|
| JP | “２段階まで増築できる。”——可以扩建两阶段。 |
| US／EU | “You can also build a second floor.”——还可以建造二楼。 |
| DE | “Du kannst auch ein zweites Stockwerk bauen.”——同样是建造二楼。 |

代码维护的是原始房屋、第一次扩建、第二次扩建三个等级；海外文本把“阶段”译成了“楼层”。同一本海外指南后面还写着扩建两次后可以改造窗户、狗屋、信箱，前后也不一致。

**判断依据：**

**修复方式：**

海外改为房屋可扩建两次，不再把第二阶段写成建造二楼。

**相关文件：** [木工指南](data/text/us/reference_guide/woodcutters_house.cc) · [JP对应文件](data/text/jp/reference_guide/woodcutters_house.cc) · [EU对应文件](data/text/eu/reference_guide/woodcutters_house.cc) · [DE对应文件](data/text/de/reference_guide/woodcutters_house.cc) · [房屋扩建等级](src/farm_house.cc:171)

<a id="audit-b15"></a>
### 孵化箱随鸡舍扩建增加，误译成可以购买

**受影响版本：** US、EU、DE。

**原版内容与差异：**

| 版本 | 原文 |
|---|---|
| JP | “ふか箱も２個に増える。”——孵化箱也增加到两个。 |
| US／EU | “Enables you to buy 2 Incubators.”——使你能够购买两个孵化箱。 |
| DE | “Ermöglicht dir, 2 Brutkästen zu kaufen.”——同样说可以购买。 |

`GetIncubatorCapacity()` 直接根据鸡舍扩建等级返回1或2；这里没有购买孵化箱的步骤。

**判断依据：**

参考重制版US `msg_Book.txt:1575` 的 `You will have two Breeding Bins.`（你将拥有两个繁殖箱），以及DE `msg_Book.txt:1618` 的 `Die Anzahl deiner Zuchtkisten wird sich erhöhen.`（你的繁殖箱数量将增加）。保留GBA术语 `Incubator`／`Brutkasten`，德文复数为 `Brutkästen`，数字均用阿拉伯数字 `2`。德文补足的数量以JP原文和 `GetIncubatorCapacity()` 为据。

**修复方式：**

US／EU采用 `You will have 2 Incubators.`；DE采用 `Die Anzahl deiner Brutkästen wird sich auf 2 erhöhen.`。按指南宽度分行，不另加“instead of 1／statt einem”，不改扩建机制。

**相关文件：** [指南原文](data/text/de/reference_guide/woodcutters_house.cc) · [JP对应文件](data/text/jp/reference_guide/woodcutters_house.cc) · [US对应文件](data/text/us/reference_guide/woodcutters_house.cc) · [EU对应文件](data/text/eu/reference_guide/woodcutters_house.cc) · [孵化箱数量](src/coop.cc:83) · [重制版英文](../SoSFoMTTextDump/SoSFoMTTextDump/US/msg_Book.txt:1575) · [重制版德文](../SoSFoMTTextDump/SoSFoMTTextDump/DE/msg_Book.txt:1618)

<a id="audit-b16"></a>
### 德文鸡饲料制作提示把“玉米”泛化成“谷物”

**受影响版本：** DE。

**原版内容与差异：**

| 版本 | 原文 |
|---|---|
| JP | “水車小屋にとうもろこしを投げ込むことでも手に入る。”——把玉米投入水车小屋也能得到。 |
| US／EU | “…Feed by putting Corn in the Water Wheel.”——把玉米放入水车获得饲料。 |
| DE | “Wenn du Getreide in das Wasserrad gibst, bekommst du auch Hühnerfutter.”——把谷物放入水车也能得到鸡饲料。 |

四版脚本都明确要求**未包装的玉米**，消耗一个后增加30份鸡饲料。`Getreide` 本身能涵盖玉米，但作为操作说明过于宽泛，会让玩家误以为其他谷物也可以。

**判断依据：**

**修复方式：**

按既有饲料制作原料将Getreide（谷物）限定为Mais（玉米）。

**相关文件：** [德文指南](data/text/de/reference_guide/poultry_farm.cc) · [JP对应文件](data/text/jp/reference_guide/poultry_farm.cc) · [US对应文件](data/text/us/reference_guide/poultry_farm.cc) · [EU对应文件](data/text/eu/reference_guide/poultry_farm.cc) · [水车材料判断](data/scripts/de/EventScript_LocationInteraction_Farm_UseWaterMill.mary.c:28) · [JP对应文件](data/scripts/jp/EventScript_LocationInteraction_Farm_UseWaterMill.mary.c:28) · [US对应文件](data/scripts/us/EventScript_LocationInteraction_Farm_UseWaterMill.mary.c:28) · [EU对应文件](data/scripts/eu/EventScript_LocationInteraction_Farm_UseWaterMill.mary.c:28)

<a id="audit-d01"></a>
### US／EU：Nina 缺少第一段解锁边界

**受影响版本：** US、EU。

**原版内容与差异：**

| JP | US＝EU | DE |
|---|---|---|
| `やさしく暖かいおばあちゃん。` → **`<111>`** → 爱丈夫的段落 → `<112>` | `A warm and loving woman.` → **没有 `<111>`** → `She loves her stubborn old husband more than anything.` → `<112>` | `Warme, liebevolle Frau.` → **`<111>`** → 对应爱丈夫段落 → `<112>` |

**判断依据：**

后续正文仍存在，但 US／EU 少了控制其显示条件的边界，导致提前可见。

**修复方式：**

在现有第一段后恢复<111>，正文不重写。

**相关文件：** [Nina 原文](data/text/us/reference_guide/ngc_awl_profiles_nina.cc) · [JP对应文件](data/text/jp/reference_guide/ngc_awl_profiles_nina.cc) · [EU对应文件](data/text/eu/reference_guide/ngc_awl_profiles_nina.cc) · [DE对应文件](data/text/de/reference_guide/ngc_awl_profiles_nina.cc)

<a id="audit-d02"></a>
### 海外三版：Griffin 缺少第二段解锁边界

**受影响版本：** US、EU、DE。

**原版内容与差异：**

- **JP：** `歌い始める。` → **`<222>`** → 身世段落。
- **US＝EU：** `where he often plays.` → **没有 `<222>`** → `He used to wander, but…`
- **DE：** `dann oft Gitarre.` → **没有 `<222>`** → `Er ist viel gereist, aber…`

**判断依据：**

后一段身世仍存在，却失去独立解锁限制。

**修复方式：**

在既有第二段之后恢复<222>，与Griffin其他段落修复一起保留完整正文。

**相关文件：** [Griffin 原文](data/text/us/reference_guide/ngc_awl_profiles_griffin.cc) · [JP对应文件](data/text/jp/reference_guide/ngc_awl_profiles_griffin.cc) · [EU对应文件](data/text/eu/reference_guide/ngc_awl_profiles_griffin.cc) · [DE对应文件](data/text/de/reference_guide/ngc_awl_profiles_griffin.cc)

<a id="audit-d03"></a>
### 海外三版：Nak 缺少第二段解锁边界

**受影响版本：** US、EU、DE。

**原版内容与差异：**

- **JP：** 向矿石镇传递信息的段落 → **`<332>`** → `黄色い服を着ている。`
- **US＝EU：** `friends in Mineral Town.` → **没有 `<332>`** → `He likes wearing yellow.`
- **DE：** 对应信息段落 → **没有 `<332>`** → `Er trägt gerne gelb.`

**判断依据：**

同样是正文保留、控制显示的边界丢失。上述三项的 `<NNN>` 会被读取器用于等级判断，不是普通装饰文本。

**修复方式：**

在现有第二段后恢复<332>，不调整解锁函数。

**相关文件：** [Nak 原文](data/text/us/reference_guide/ngc_awl_profiles_nak.cc) · [JP对应文件](data/text/jp/reference_guide/ngc_awl_profiles_nak.cc) · [EU对应文件](data/text/eu/reference_guide/ngc_awl_profiles_nak.cc) · [DE对应文件](data/text/de/reference_guide/ngc_awl_profiles_nak.cc) · [边界读取逻辑](src/scene_reference_page.cc)

<a id="audit-d04"></a>
### DE：四本指南／贺卡的标题缺失，正文第一句占据固定标题位置

**受影响版本：** DE。

**原版内容与差异：**

| 图书 | JP 标题 | US＝EU 标题 | DE 当前标题 |
|---|---|---|---|
| Samantha | `サンさんの紹介` | `Introducing Samantha` | `Wird meist "Sam" genannt,`——通常称为 Sam， |
| Patrick | `パサランさんの紹介` | `Introducing Patrick` | `Kasseys Zwillingsbruder,`——Kassey 的孪生兄弟， |
| Hardy | `バドックさんの紹介` | `Introducing Hardy` | `Hardy, Romanas Arzt, kommt`——Hardy，Romana 的医生，来到…… |
| Gray 贺卡 | `グレイからの年賀状` | `Gray's New Year Card` | `Frohes Neues Jahr!`——新年快乐！ |

**判断依据：**

第一行会固定显示，后面的正文才滚动。DE 前三本甚至把一句话拆在标题与正文之间。恢复标题时，原首句要回到正文，不能删掉。

**修复方式：**

DE四页补回固定标题，同时把原本占据标题的有效第一句保留到正文开头；不删除原内容。

**相关文件：** [例：Samantha](data/text/de/reference_guide/ngc_awl_profiles_samantha.cc) · [JP对应文件](data/text/jp/reference_guide/ngc_awl_profiles_samantha.cc) · [US对应文件](data/text/us/reference_guide/ngc_awl_profiles_samantha.cc) · [EU对应文件](data/text/eu/reference_guide/ngc_awl_profiles_samantha.cc) · [例：Gray 贺卡](data/text/de/reference_guide/new_year_card_gray.cc) · [JP对应文件](data/text/jp/reference_guide/new_year_card_gray.cc) · [US对应文件](data/text/us/reference_guide/new_year_card_gray.cc) · [EU对应文件](data/text/eu/reference_guide/new_year_card_gray.cc)

<a id="audit-d05"></a>
### DE：食谱中的黄油小标题缺失

**受影响版本：** DE。

**原版内容与差异：**

- **JP：** `☆バターの作り方`，随后是牛奶、搅拌器。
- **US＝EU：** `☆Butter`，随后是 Milk、Mixer。
- **DE：** 分隔线后直接是 `·Nötige Zutaten`／`Milch`，没有黄油标题。

**判断依据：**

配方正文完整，但标题丢失；后面的 `☆Butterbrot` 是下一道菜，不能当作本段标题。

**修复方式：**

在原黄油材料列表前恢复☆Butter（黄油）小标题，保留后续黄油面包标题。

**相关文件：** [食谱对应段落](data/text/de/reference_guide/cookbook_2.cc) · [JP对应文件](data/text/jp/reference_guide/cookbook_2.cc) · [US对应文件](data/text/us/reference_guide/cookbook_2.cc) · [EU对应文件](data/text/eu/reference_guide/cookbook_2.cc)

<a id="audit-d06"></a>
### Wally：海外缺两段

**受影响版本：** US、EU、DE。

**原版内容与差异：**

JP：

> かつては有名なマラソン選手だったが、足を患い引退、その後監督になる。根っからのスポーツマン。
>
> 息子のヒューを一流のアスリートにするのが夢で毎朝一緒にジョギングしている。

含义：曾是著名马拉松选手，因腿疾退役后成为教练；梦想把儿子培养成一流运动员，每天早晨一起慢跑。

US／EU 在下面这句之后结束：

> They came to Forget-me-not Valley because it's a great place to run.

DE 在对应句之后结束：

> Sie kamen ins Vergissmeinnicht-Tal, weil es ein toller Ort zum Laufen ist.

两者都只保留了搬来山谷适合跑步的介绍，上述两段没有对应译文。

**判断依据：**

**修复方式：**

Wally补回因腿病退役后当教练，以及希望儿子成为一流运动员、每天陪他慢跑两段；恢复<041>／<042>分界，已有标记不重复插入。

**相关文件：** [JP人物介绍](data/text/jp/reference_guide/ngc_awl_profiles_wally.cc) · [US对应文件](data/text/us/reference_guide/ngc_awl_profiles_wally.cc) · [EU对应文件](data/text/eu/reference_guide/ngc_awl_profiles_wally.cc) · [DE对应文件](data/text/de/reference_guide/ngc_awl_profiles_wally.cc)

<a id="audit-d07"></a>
### Hugh：海外缺两段

**受影响版本：** US、EU、DE。

**原版内容与差异：**

JP：

> グラートの娘ケイトが大の苦手。小さいころはよくいじめられ泣かされていた。
>
> 歩き出す前から父親のトレーニングを受けていたためやがて父親を追い越し一流のランナーになるだろう。

含义：很怕Grant的女儿Kate，小时候经常被欺负哭；从学会走路之前便接受父亲训练，将来可能超越父亲成为一流跑者。

US／EU 仅有：

> Wally's only son, Hugh is rebellious but loves to run with his father.

DE 仅有：

> Wallys einziger Sohn Hugh ist rebellisch, aber läuft gerne mit seinem Vater.

即只介绍他是Wally的独子、叛逆但喜欢跟父亲跑步。

**判断依据：**

**修复方式：**

Hugh补回害怕童年欺负他的Kate，以及从学步前接受父亲训练、将来可能超越父亲两段；保留<061>并恢复<062>。

**相关文件：** [JP](data/text/jp/reference_guide/ngc_awl_profiles_hugh.cc) · [US对应文件](data/text/us/reference_guide/ngc_awl_profiles_hugh.cc) · [EU对应文件](data/text/eu/reference_guide/ngc_awl_profiles_hugh.cc) · [DE对应文件](data/text/de/reference_guide/ngc_awl_profiles_hugh.cc)

<a id="audit-d08"></a>
### Samantha：海外缺两段

**受影响版本：** US、EU、DE。

**原版内容与差异：**

JP：

> 厳格な家庭に育ったため、娘のしつけには厳しい。グラート以上にまじめで保守的 普通が一番と考えている。
>
> 「わすれ谷」には変わった人が多いので、あまり外に出ないようにしている。

含义：由于在严格的家庭长大，对女儿管教严格，比Grant更认真保守，认为平凡最好；觉得山谷里怪人多，所以尽量少出门。

US／EU 仅有：

> People call her "Sam", she is Grant’s wife and Kate's mother. She is reticent and responsible.

DE 对应内容：

> Wird meist "Sam" genannt, sie ist Grants Frau und Kates Mutter. Sie ist zurückhaltend und verantwortungsvoll.

即只有称呼、家庭关系和简短性格介绍。DE 把部分正文放进标题的问题属于对应标题缺失问题，和缺段不重复计算。

**判断依据：**

**修复方式：**

Samantha补回严格保守、认为普通最好，以及经常待在家中两段；恢复<081>／<082>。

**相关文件：** [JP](data/text/jp/reference_guide/ngc_awl_profiles_samantha.cc) · [US对应文件](data/text/us/reference_guide/ngc_awl_profiles_samantha.cc) · [EU对应文件](data/text/eu/reference_guide/ngc_awl_profiles_samantha.cc) · [DE对应文件](data/text/de/reference_guide/ngc_awl_profiles_samantha.cc)

<a id="audit-d09"></a>
### Galen：海外缺最后一段

**受影响版本：** US、EU、DE。

**原版内容与差异：**

JP：

> ニーナがいなくなってからは常に悲しげで、寂しげな生活になっている。

含义：Nina去世后，他一直显得悲伤，过着寂寞的生活。

US／EU 在下面这句结束：

> When Nina died, he built a cottage near her grave on a hill, where he spends all day watching the ocean.

DE 在对应句结束：

> Als Nina starb, hat er eine Hütte auf einem Hügel in der Nähe ihres Grabes gebaut, von wo er den ganzen Tag aufs Meer schaut.

海外保留了墓旁小屋、眺望大海的内容，但没有日版最后这一独立解锁段。

**判断依据：**

**修复方式：**

Galen补回妻子去世后一直悲伤、生活寂寞的末段，并恢复<102>；保留已有迁居正文。

**相关文件：** [JP人物介绍](data/text/jp/reference_guide/ngc_awl_profiles_galen.cc) · [US对应文件](data/text/us/reference_guide/ngc_awl_profiles_galen.cc) · [EU对应文件](data/text/eu/reference_guide/ngc_awl_profiles_galen.cc) · [DE对应文件](data/text/de/reference_guide/ngc_awl_profiles_galen.cc)

<a id="audit-d10"></a>
### Daryl：海外缺两段

**受影响版本：** US、EU、DE。

**原版内容与差异：**

JP：

> 幼いころ、体の養生のため空気の良い牧場に移ったが、そこで牛に襲われ大怪我を負い、それ以降牛に対してトラウマを持っている。
>
> 彼の研究は動物のクローンに関するものらしく、特に優秀な牛をクローンによって増やし、大儲けしようとしているらしい。

含义：小时候去牧场养病，被牛袭击重伤后留下心理阴影；研究动物克隆，似乎想通过复制优秀的牛赚大钱。

US／EU 仅有：

> A scientist who moved to Forget-me-not Valley to pursue his research.

DE 仅有：

> Ein Wissenschaftler, der wegen seiner Studien ins Vergissmeinnicht-Tal zog.

即只有“为了研究搬来山谷的科学家”。

**判断依据：**

**修复方式：**

Daryl补回童年被牛重伤后怕牛、研究克隆优良牛发财两段；恢复<121>／<122>。

**相关文件：** [JP](data/text/jp/reference_guide/ngc_awl_profiles_daryl.cc) · [US对应文件](data/text/us/reference_guide/ngc_awl_profiles_daryl.cc) · [EU对应文件](data/text/eu/reference_guide/ngc_awl_profiles_daryl.cc) · [DE对应文件](data/text/de/reference_guide/ngc_awl_profiles_daryl.cc) · [人物介绍显示条件](src/scene_reference_page.cc:678)

<a id="audit-f02"></a>
### JP：味噌汤食谱的锅写成 `なぺ`

**受影响版本：** JP。

**原版内容与差异：**

- **JP：** `なぺ`。
- **US＝EU：** `Pot`。
- **DE：** `Topf`。

**判断依据：**

指锅，应为 `なべ`；同类日文食谱使用正确写法。只是浊点错误。

**修复方式：**

JP食谱なぺ改为已有正确锅名なべ。

**相关文件：** [味噌汤食谱](data/text/jp/reference_guide/cookbook_1.cc) · [US对应文件](data/text/us/reference_guide/cookbook_1.cc) · [EU对应文件](data/text/eu/reference_guide/cookbook_1.cc) · [DE对应文件](data/text/de/reference_guide/cookbook_1.cc)

<a id="audit-f03"></a>
### 海外三版：食谱牛奶单词残缺

**受影响版本：** US、EU、DE。

**原版内容与差异：**

- **JP：** `果物とか牛乳とか草`。
- **US＝EU：** `Fruit, Mil, Grasses`。
- **DE：** `Früchte, Mil, Gräser`。

**判断依据：**

此处都是牛奶，英文 `Milk`、德文 `Milch` 被截成 `Mil`；可沿用同语现有名称。

**修复方式：**

海外食谱Mil补全为Milk／Milch，使用本版既有牛奶名称。

**相关文件：** [食谱原文](data/text/de/reference_guide/cookbook_4.cc) · [JP对应文件](data/text/jp/reference_guide/cookbook_4.cc) · [US对应文件](data/text/us/reference_guide/cookbook_4.cc) · [EU对应文件](data/text/eu/reference_guide/cookbook_4.cc)

<a id="audit-f04"></a>
### DE：酱油名称出现错误字符

**受影响版本：** DE。

**原版内容与差异：**

- **JP：** `しょうゆ`。
- **US＝EU：** `Soy Sauce`。
- **DE：** `Soyasoﾟe`。

**判断依据：**

同语言另一食谱已有 `Soyasoße`。此处 `ﾟ` 不是正常德文拼写，应按已有正确文本修正。

**修复方式：**

DE食谱Soyasoﾟe改为另一本食谱已有的Soyasoße（酱油）。

**相关文件：** [错误文本](data/text/de/reference_guide/cookbook_4.cc) · [JP对应文件](data/text/jp/reference_guide/cookbook_4.cc) · [US对应文件](data/text/us/reference_guide/cookbook_4.cc) · [EU对应文件](data/text/eu/reference_guide/cookbook_4.cc) · [已有正确拼写](data/text/de/reference_guide/cookbook_2.cc) · [JP对应文件](data/text/jp/reference_guide/cookbook_2.cc) · [US对应文件](data/text/us/reference_guide/cookbook_2.cc) · [EU对应文件](data/text/eu/reference_guide/cookbook_2.cc)

<a id="winery-day-off"></a>
### 酒庄告示休息日错误

**受影响版本：** US、EU、DE。

**原版内容与差异：**

告示写星期日休息。

**判断依据：**

酒庄实际星期六休息；同作营业说明及脚本的休息日判断一致。

**修复方式：**

告示改星期六，不改营业日程。

**相关文件：** [JP](data/scripts/jp/EventScript_LocationInteraction_InspectAjaWineryBusinessHoursSign.mary.c) · [US](data/scripts/us/EventScript_LocationInteraction_InspectAjaWineryBusinessHoursSign.mary.c) · [EU](data/scripts/eu/EventScript_LocationInteraction_InspectAjaWineryBusinessHoursSign.mary.c) · [DE](data/scripts/de/EventScript_LocationInteraction_InspectAjaWineryBusinessHoursSign.mary.c)

<a id="huge-stone-description"></a>
### 巨石说明把五级锤条件写成玩家当前等级

**受影响版本：** US、EU、DE。

**原版内容与差异：**

原句误称“你的锤已经是LV5，所以不能击碎”。

**判断依据：**

JP是“即使LV5也无法击碎”；这个调查说明不等于已检查玩家当前锤等级。

**修复方式：**

保留原石头名称、三行结构及等待位置，改为即使五级锤也无法击碎。

**相关文件：** [JP](data/scripts/jp/EventScript_LocationInteraction_InspectHugeStoneUnbreakableWithLevel5Hammer.mary.c) · [US](data/scripts/us/EventScript_LocationInteraction_InspectHugeStoneUnbreakableWithLevel5Hammer.mary.c) · [EU](data/scripts/eu/EventScript_LocationInteraction_InspectHugeStoneUnbreakableWithLevel5Hammer.mary.c) · [DE](data/scripts/de/EventScript_LocationInteraction_InspectHugeStoneUnbreakableWithLevel5Hammer.mary.c)

<a id="guide-topaz-ruby-prices"></a>
### 出货价格指南的黄玉与红宝石价格错误

**受影响版本：** 四版。

**原版内容与差异：**

《出货价格》的矿石栏把黄玉写为 75 G、红宝石写为 78 G。

**判断依据：**

四版物品表和出货箱实际采用的价格为黄玉 70 G、红宝石 75 G。

**修复方式：**

把指南中的两个数字改为实际出货价，沿用各版排版。

**相关文件：** [物品价格](src/item.cc) · [出货结算](src/shipping_bin.cc) · [JP](data/text/jp/reference_guide/sell_price.cc) · [US](data/text/us/reference_guide/sell_price.cc) · [EU](data/text/eu/reference_guide/sell_price.cc) · [DE](data/text/de/reference_guide/sell_price.cc)

<a id="guide-magic-grass-growth-days"></a>
### 魔术草指南少写一天成长时间

**受影响版本：** 四版。

**原版内容与差异：**

季节作物指南将魔术草的四个成长阶段写为 3、2、2、2 天。

**判断依据：**

田地的魔术草成长表在第 3、6、8、10 天变更阶段，第二阶段需要 3 天。

**修复方式：**

把四版指南中的成长阶段改为 3、3、2、2 天。

**相关文件：** [成长表](src/field_data.cc) · [每日更新](src/field.cc) · [JP](data/text/jp/reference_guide/seasonal_crops.cc) · [US](data/text/us/reference_guide/seasonal_crops.cc) · [EU](data/text/eu/reference_guide/seasonal_crops.cc) · [DE](data/text/de/reference_guide/seasonal_crops.cc)

<a id="guide-fall-sweet-potato"></a>
### 秋季作物清单漏列红薯

**受影响版本：** US、EU、DE。

**原版内容与差异：**

JP 种植指南的秋季作物清单列有红薯，海外三版漏列。

**判断依据：**

红薯可以在秋季种植，海外各版已有相应作物及名称。

**修复方式：**

照 JP 顺序在茄子后补入红薯，英语用 `Sweet Potato`，德语用 `Süßkartoffeln`。

**相关文件：** [JP](data/text/jp/reference_guide/raising_crops.cc) · [US](data/text/us/reference_guide/raising_crops.cc) · [EU](data/text/eu/reference_guide/raising_crops.cc) · [DE](data/text/de/reference_guide/raising_crops.cc) · [田地季节判断](src/field.cc)

<a id="category-television"></a>
## 电视节目内容

| 问题 | 受影响版本 | 开关支持 |
| --- | --- | --- |
| [F-3.14节目日期、跨赛季复用与成绩错误](#audit-a10) | JP、US、EU、DE | 已接入 |
| [JP：《まことクンちぇんじ》第24集说话人写反](#audit-e01) | JP | 已接入 |
| [DE：同节目第2集漏否定词](#audit-e02) | DE | 已接入 |
| [DE：同节目第13集把竖笛译成录音机](#audit-e03) | DE | 已接入 |
| [四版：《Card Collector Chisato》第3集卡片数量算错](#audit-e04) | JP、US、EU、DE | 已接入 |
| [海外三版：同节目把 S／G 牛奶译成羊奶、山羊奶](#audit-e05) | US、EU、DE | 已接入 |
| [海外三版：同节目第1集，把将来发售写成已经发售](#audit-e06) | US、EU、DE | 已接入 |
| [海外三版：同节目第11集，把假设写成已经发生](#audit-e07) | US、EU、DE | 已接入 |
| [海外三版：同节目第8集标题残留 `<et>`](#audit-e08) | US、EU、DE | 已接入 |
| [DE：《Mechabot Ultror Zero》第1集装饰人员多出 Yellow](#audit-e09) | DE | 已接入 |
| [DE：同节目第2集把上午写成明天](#audit-e10) | DE | 已接入 |
| [四版：入门节目初始体力及增长比例错误](#audit-e11) | JP、US、EU、DE | 已接入 |
| [DE：进阶节目冬2日，把最大体力写成10](#audit-e12) | DE | 已接入 |
| [DE：进阶节目冬3日，把矿场写成磨坊](#audit-e13) | DE | 已接入 |
| [DE：钓鱼节目第6集，鲣鱼仍误用金枪鱼名称](#audit-e14) | DE | 已接入 |
| [DE：钓鱼节目第10集，把下游鱼全部说成海鱼](#audit-e15) | DE | 已接入 |
| [DE：钓鱼节目第13集误用了另一鱼种的既有名字](#audit-e16) | DE | 已接入 |
| [US／EU：矿场研究第9集，把“255层没有下行楼梯”写成“没有通向255层的楼梯”](#audit-e17) | US、EU | 已接入 |
| [鱼王条件被译成“这条鱼适合做哪些菜”](#audit-e18) | US、EU、DE | 已接入 |
| [料理对决第2集把糖译成盐](#audit-e19) | US、EU、DE | 已接入 |
| [英文电视台词残留日文助词](#tv-japanese-particles) | US、EU | 已接入 |
| [德版别墅春季雨天预报把明天说成今天](#de-villa-tv-spring-rain) | DE | 已接入 |

<a id="audit-a10"></a>
### F-3.14节目日期、跨赛季复用与成绩错误

**受影响版本：** JP、US、EU、DE。

**原版内容与差异：**

| 日期 | JP 原文摘要 | US＝EU 原文摘要 | DE 原文摘要 |
|---|---|---|---|
| 冬18 | 第八战预告：`第８戦はあさってです。`——第八战后天举行。 | `The 8th match will be the day after tomorrow.` | `Der dritte Wettkampf findet übermorgen statt.`——**第三战**后天举行。 |
| 冬19 | 第二部分预告：`第８戦はあしたです。`——第八战明天举行。 | 第一部分预告：`The eighth match will be the day after tomorrow.` | 第一部分预告：`Der achte Wettkampf findet übermorgen statt.` |
| 冬20 | `第７戦の結果をお伝えします。`——播报**第七战结果**。 | 第二部分预告，仍说第八战“后天”。 | 第二部分预告，仍说第八战“后天”。 |
| 夏19 | 第三战预告：`第３戦はあさってです。` | `The third match will be the day after tomorrow.` | `Die Ergebnisse des 2. F-3.14 MGP Rennens sind:`——变成**第二战成绩**。 |
| 夏09 | 最终战前三名：`すみれ／デイジー／コスモス` | `Sylvia / Daisy / Cosmos` | `Licorice / Sylvia / Lupinus`，复用了另一轮最终战结果。 |

**判断依据：**

对照实际日期分派、冬21／22的第八战结果，以及前后比赛积分和人物介绍。既有调用错误，也有文本本身的日期、场次错误，不能只改标签名。

**其他原版错误与修正：**

- 按每版四季各30天的实际分派，逐一核对120个播出位置，不凭 `RaceXX` 标签判断内容。
- JP冬18／19／20恢复为第七战成绩后半、第八战预告前半／后半；海外冬18补回正确成绩。US／EU沿用既有英文成绩格式，DE采用原本错放在另一赛季的德文成绩措辞。
- DE第一赛季第九战正文和成绩、最终战正文和成绩，以及第二赛季第一至第八战正文和成绩，存在跨赛季复用／替换。已按JP对应场次恢复；同版已有句式、参赛者译名、表格格式优先复用，缺失叙事按JP含义补齐，不把“前三名相同”当作整篇内容可复用的依据。
- DE第二赛季第二、第五、第七战预告误介绍第三赛季才出现的Eucomyth，恢复同语已有Amaryllis预告；第九战预告缺少Daisy的部分沿用本版第二战已有介绍。海外冬28恢复最终战预告后半，不再重复前一天内容。
- 海外第一赛季第八战Daisy累计32＋6误写39，改38；US／EU第二赛季第八战第三名Daisy误写加6分，改为与累计分一致的4分。
- 第三赛季第七战Sylvia原累计7分、当次加2分，但JP及海外后续成绩都写成8分。四版该场及下一场累计改9，后两场改11；名次不受影响。依据是每场已显示的得分逐项累加，不把JP错误数字当作正确基准。
- DE缺少场次数字的第三／第四战等标题补回数字。单纯人物译名差异不改；节目结果仍是固定文本，未新增实时积分机制。

实际日期分派、同一天JP／英文完整正文、每场名次及累计积分共同定位；不能仅按相似符号名或同样的前三名配对。德文缺文优先复用同版表格和句式，确无对应正文的部分按JP原义补齐。

**修复方式：**

对已有正确文本调整调用；错误共用的对象拆出BUGFIX专用文本；缺失正文与成绩在对应对象附近补回。更正Daisy的两处数值，以及四版Sylvia第三赛季第七战少计一分并延续到后三场的问题。没有改变节目播放机制或添加运行时积分计算。

**相关文件：** [JP 节目](data/scripts/jp/EventScript_TV_F314MGrandPrix.mary.c) · [US对应文件](data/scripts/us/EventScript_TV_F314MGrandPrix.mary.c) · [EU对应文件](data/scripts/eu/EventScript_TV_F314MGrandPrix.mary.c) · [DE对应文件](data/scripts/de/EventScript_TV_F314MGrandPrix.mary.c)

<a id="audit-e01"></a>
### JP：《まことクンちぇんじ》第24集说话人写反

**受影响版本：** JP。

**原版内容与差异：**

- **JP：** 两处 `誠人（体は真琴だよ）`——诚人，身体是真琴。
- **US＝EU：** `Erin (in Aaron's body)`。
- **DE：** `Erin (in Aarons Körper)`。

**判断依据：**

本段开头明确是“回到教室的真琴”，老师对其外貌对应的诚人说话；海外身份标注正确。JP 应修显示的说话人，不调整集数或角色映射。

**修复方式：**

只将第24集两处说话人改为真琴（身体是诚人），保留交换身体剧情及其余集数。

**相关文件：** [第24集上下文](data/scripts/jp/EventScript_TV_AaronChanges.mary.c) · [US对应文件](data/scripts/us/EventScript_TV_AaronChanges.mary.c) · [EU对应文件](data/scripts/eu/EventScript_TV_AaronChanges.mary.c) · [DE对应文件](data/scripts/de/EventScript_TV_AaronChanges.mary.c)

<a id="audit-e02"></a>
### DE：同节目第2集漏否定词

**受影响版本：** DE。

**原版内容与差异：**

- **JP：** `前を見ないからつまづいて転びそうになっているよ。`——因为没看前面，绊了一下差点摔倒。
- **US＝EU：** `She almost tripped because of not looking where she's going.`
- **DE：** `Sie stolperte fast, weil sie darauf achtete, wo sie hinging.`——因为注意看路，差点绊倒。

**判断依据：**

原因反转；DE 下一集回顾同一事件时已有正确的 `nicht`，可以用同语原文参照。

**修复方式：**

补回nicht（不），按窗口宽度分行；以同版第3集回顾中的否定为依据。

**相关文件：** [第2、3集](data/scripts/de/EventScript_TV_AaronChanges.mary.c) · [JP对应文件](data/scripts/jp/EventScript_TV_AaronChanges.mary.c) · [US对应文件](data/scripts/us/EventScript_TV_AaronChanges.mary.c) · [EU对应文件](data/scripts/eu/EventScript_TV_AaronChanges.mary.c)

<a id="audit-e03"></a>
### DE：同节目第13集把竖笛译成录音机

**受影响版本：** DE。

**原版内容与差异：**

- **JP：** `たてぶえのテスト`，之后拿起 `教科書とたてぶえ`。
- **US＝EU：** `recorder test`，之后拿起 `my textbook and recorder`。
- **DE：** `Aufnahmetest`，之后拿起 `Kassettenrekorder`。

**判断依据：**

音乐课、吹奏测试、“间接接吻”的上下文共同确定 `recorder` 指竖笛，不是录音机。

**修复方式：**

音乐课测试与拿起的物品统一改为Blockflöte（竖笛），同步调整冠词，移除重复的und（和）。

**相关文件：** [第13集](data/scripts/de/EventScript_TV_AaronChanges.mary.c) · [JP对应文件](data/scripts/jp/EventScript_TV_AaronChanges.mary.c) · [US对应文件](data/scripts/us/EventScript_TV_AaronChanges.mary.c) · [EU对应文件](data/scripts/eu/EventScript_TV_AaronChanges.mary.c)

<a id="audit-e04"></a>
### 四版：《Card Collector Chisato》第3集卡片数量算错

**受影响版本：** JP、US、EU、DE。

**原版内容与差异：**

- **JP：** `全部で１５６種類…あと７０種類でコンプリート`。
- **US＝EU：** `a total of 156 different card types…70 more`。
- **DE：** `insgesamt 156 Kartentypen…noch 70 weitere`。

**判断依据：**

第2集已明确总计256种、得到186种、还差70种；第3集重述同一批卡片时写成156。随后交换七种，还差63，也支持应为186。

**修复方式：**

四版将第3集156改186，依据256−70及前后交换卡片的数量；不改卡片总数。

**相关文件：** [第2、3集数量关系](data/scripts/jp/EventScript_TV_CardCollectorChisato.mary.c) · [US对应文件](data/scripts/us/EventScript_TV_CardCollectorChisato.mary.c) · [EU对应文件](data/scripts/eu/EventScript_TV_CardCollectorChisato.mary.c) · [DE对应文件](data/scripts/de/EventScript_TV_CardCollectorChisato.mary.c)

<a id="audit-e05"></a>
### 海外三版：同节目把 S／G 牛奶译成羊奶、山羊奶

**受影响版本：** US、EU、DE。

**原版内容与差异：**

| 集数 | JP | US＝EU | DE |
|---|---|---|---|
| 第3集 | `Ｓ牛乳` | `Sheep's Milk` | `Schafsmilch` |
| 第7集 | `Ｇ牛乳` | `Goat's Milk` | `Ziegenmilch` |

**判断依据：**

这里是游戏道具卡片，S／G 为牛奶等级。应沿用现有道具译名，不新增羊奶或山羊奶的物品身份。

**修复方式：**

第3集S牛奶和第7集全部G牛奶引用沿用本版物品名称Milk／Milch (S/G)，不新增羊奶或山羊奶。

**相关文件：** [节目原文](data/scripts/us/EventScript_TV_CardCollectorChisato.mary.c) · [JP对应文件](data/scripts/jp/EventScript_TV_CardCollectorChisato.mary.c) · [EU对应文件](data/scripts/eu/EventScript_TV_CardCollectorChisato.mary.c) · [DE对应文件](data/scripts/de/EventScript_TV_CardCollectorChisato.mary.c) · [已有牛奶名称](data/text/us/item_2.cc) · [JP对应文件](data/text/jp/item_2.cc) · [EU对应文件](data/text/eu/item_2.cc) · [DE对应文件](data/text/de/item_2.cc)

<a id="audit-e06"></a>
### 海外三版：同节目第1集，把将来发售写成已经发售

**受影响版本：** US、EU、DE。

**原版内容与差异：**

- **JP：** `来月に…発売される`——下个月发售。
- **US＝EU：** `Remember the rumor last month… Well, it's happened.`——上个月的传闻，现在已经发生了。
- **DE：** `…das Gerücht letzten Monat… Tja, das ist geschehen.`——同样变成已经发生。

**判断依据：**

同一段随后仍约定“发售时一起去买”，过去与将来关系冲突。

**修复方式：**

恢复下个月发售的将来时，保留随后约定发售时一起购买的对话。

**相关文件：** [第1集](data/scripts/us/EventScript_TV_CardCollectorChisato.mary.c) · [JP对应文件](data/scripts/jp/EventScript_TV_CardCollectorChisato.mary.c) · [EU对应文件](data/scripts/eu/EventScript_TV_CardCollectorChisato.mary.c) · [DE对应文件](data/scripts/de/EventScript_TV_CardCollectorChisato.mary.c)

<a id="audit-e07"></a>
### 海外三版：同节目第11集，把假设写成已经发生

**受影响版本：** US、EU、DE。

**原版内容与差异：**

- **JP：** `３日連続で新しいのが出なかったらすっごい哀しいし…`——如果连续三天没抽到新卡，会很难过……
- **US＝EU：** `I was too upset from not getting any new cards for three days in a row…`
- **DE：** `Ich war zu sauer, dass ich 3 Tage hintereinander keine neuen Karten hatte…`

**判断依据：**

前文是连续两天没抽到，所以昨天不再去买；海外却写成已连续三天没抽到，与实际行动冲突。

**修复方式：**

把连续三天抽不到新卡改为假设，保留昨天未购买、接受八种卡片后回家的事实。

**相关文件：** [第8至11集](data/scripts/jp/EventScript_TV_CardCollectorChisato.mary.c) · [US对应文件](data/scripts/us/EventScript_TV_CardCollectorChisato.mary.c) · [EU对应文件](data/scripts/eu/EventScript_TV_CardCollectorChisato.mary.c) · [DE对应文件](data/scripts/de/EventScript_TV_CardCollectorChisato.mary.c)

<a id="audit-e08"></a>
### 海外三版：同节目第8集标题残留 `<et>`

**受影响版本：** US、EU、DE。

**原版内容与差异：**

- **JP：** `☆カードコレクターちさとくん`。
- **US＝EU：** `CARD COLLECTOR CHISATO<et>`。
- **DE：** `Kartensammler Chisato<et>`。

**判断依据：**

当前码表、消息读取器没有把 `<et>` 定义为控制符，会作为文字显示。它与之前的 `ret>`／`<RET>` 是不同的遗漏点；尚不能断定历史来源相同。

**修复方式：**

只移除<et>字面标签，不新增控制符解释。

**相关文件：** [原文](data/scripts/us/EventScript_TV_CardCollectorChisato.mary.c) · [JP对应文件](data/scripts/jp/EventScript_TV_CardCollectorChisato.mary.c) · [EU对应文件](data/scripts/eu/EventScript_TV_CardCollectorChisato.mary.c) · [DE对应文件](data/scripts/de/EventScript_TV_CardCollectorChisato.mary.c) · [消息读取器](src/ui_text_stream.cc)

<a id="audit-e09"></a>
### DE：《Mechabot Ultror Zero》第1集装饰人员多出 Yellow

**受影响版本：** DE。

**原版内容与差异：**

- **JP：** `あかね、あおい、みどりの３人が装飾係で、きいろちゃんはお料理担当。`
- **US＝EU：** `Red, Blue and green are working on the party decorations, while Yellow is in charge of the food.`
- **DE：** `Gelb, Rot, Blau und Grün an der Partydekoration, während Gelb für das Essen…`

**判断依据：**

日英都是红、蓝、绿负责装饰，黄负责料理；德文把黄重复加入了装饰名单。

**修复方式：**

从装饰人员名单移除Yellow／Gelb，保留其负责料理及四人共同过生日的叙事。

**相关文件：** [第1集](data/scripts/de/EventScript_TV_MechabotUltrorZero_EpisodeReminders.mary.c) · [JP对应文件](data/scripts/jp/EventScript_TV_MechabotUltrorZero_EpisodeReminders.mary.c) · [US对应文件](data/scripts/us/EventScript_TV_MechabotUltrorZero_EpisodeReminders.mary.c) · [EU对应文件](data/scripts/eu/EventScript_TV_MechabotUltrorZero_EpisodeReminders.mary.c)

<a id="audit-e10"></a>
### DE：同节目第2集把上午写成明天

**受影响版本：** DE。

**原版内容与差异：**

- **JP：** `午前中は晴れていたはずなのに…雪が…`——上午明明晴着，现在却下雪了。
- **US＝EU：** `…sunny all morning, but all of a sudden it's snowing…`
- **DE：** `…dass es morgen sonnig wird, aber auf einmal schneit es…`——预报明天晴，可现在突然下雪。

**判断依据：**

德文把作为对照的上午改成明天。US／EU 额外加入“天气预报”的改写，不直接等同判定为必须修复；**此项确定范围是 DE 的时间错位**。

**修复方式：**

只修DE为当天上午，不改变US／EU既有表述或另造时间设定。

**相关文件：** [第2集](data/scripts/de/EventScript_TV_MechabotUltrorZero_EpisodeReminders.mary.c) · [JP对应文件](data/scripts/jp/EventScript_TV_MechabotUltrorZero_EpisodeReminders.mary.c) · [US对应文件](data/scripts/us/EventScript_TV_MechabotUltrorZero_EpisodeReminders.mary.c) · [EU对应文件](data/scripts/eu/EventScript_TV_MechabotUltrorZero_EpisodeReminders.mary.c)

<a id="audit-e11"></a>
### 四版：入门节目初始体力及增长比例错误

**受影响版本：** JP、US、EU、DE。

**原版内容与差异：**

- **JP：** 初始 `１００だよ`，之后 `最初の２倍までふえる`。
- **US＝EU：** 初始 `100.`，之后 `Stamina by 100%.`
- **DE：** 初始 `100.`，之后 `100 % steigern.`

**判断依据：**

四版共享实现中初始体力为150，最大值为 `150 + 10 × 力之果实数量`，十颗后250；状态画面也直接显示该值。应修节目数字与“翻倍”说法，不改游戏机制。

`Farmer` 初始体力为150，上限为 `150 + 10 × 力之果实数量`；十颗后250。即5/3倍、增加66又2/3%。

**修复方式：**

BUGFIX下初始值改为150；JP显示1.67倍，US／EU显示增加66.67%，DE显示增加66,67%。采用用户指定的两位小数近似值；其余台词用词及控制符不改，JP只做必要分行。保留默认原文和原有游戏机制。

**相关文件：** [节目](data/scripts/jp/EventScript_TV_LifeOnTheFarm_Beginner.mary.c) · [US对应文件](data/scripts/us/EventScript_TV_LifeOnTheFarm_Beginner.mary.c) · [EU对应文件](data/scripts/eu/EventScript_TV_LifeOnTheFarm_Beginner.mary.c) · [DE对应文件](data/scripts/de/EventScript_TV_LifeOnTheFarm_Beginner.mary.c) · [实际体力实现](src/farmer.cc:11)

<a id="audit-e12"></a>
### DE：进阶节目冬2日，把最大体力写成10

**受影响版本：** DE。

**原版内容与差异：**

- **JP：** `最大体力を越えたり、疲労が０より小さくなったりはしない`。
- **US＝EU：** `You can't get better than your maximum Stamina, or reduce your Fatigue below 0…`
- **DE：** `Allerdings ist 10 die max. Ausdauer und 0 der minimale Energieverlust.`

**判断依据：**

温泉恢复上限是角色当前最大体力，不是10。修文应表达“最大值”，不能简单把10改成另一个固定数字。

**修复方式：**

将固定10改为角色当前体力上限，疲劳最低0；不修改实际恢复机制。

**相关文件：** [冬2日](data/scripts/de/EventScript_TV_LifeOnTheFarm_Advanced.mary.c) · [JP对应文件](data/scripts/jp/EventScript_TV_LifeOnTheFarm_Advanced.mary.c) · [US对应文件](data/scripts/us/EventScript_TV_LifeOnTheFarm_Advanced.mary.c) · [EU对应文件](data/scripts/eu/EventScript_TV_LifeOnTheFarm_Advanced.mary.c)

<a id="audit-e13"></a>
### DE：进阶节目冬3日，把矿场写成磨坊

**受影响版本：** DE。

**原版内容与差异：**

- **JP：** `マザーズヒルにある『鉱石場』`。
- **US＝EU：** `the mine on Mother's Hill`。
- **DE：** `Mühle auf dem Mutterberg`——母亲山的磨坊。

**判断依据：**

后面紧接着讲用锄头挖地、锤子敲石，同一德文段落随后也用 `Mine`。场所译错。

**修复方式：**

将Mühle（磨坊）改为同段已有的Mine（矿场）。

**相关文件：** [冬3日](data/scripts/de/EventScript_TV_LifeOnTheFarm_Advanced.mary.c) · [JP对应文件](data/scripts/jp/EventScript_TV_LifeOnTheFarm_Advanced.mary.c) · [US对应文件](data/scripts/us/EventScript_TV_LifeOnTheFarm_Advanced.mary.c) · [EU对应文件](data/scripts/eu/EventScript_TV_LifeOnTheFarm_Advanced.mary.c)

<a id="audit-e14"></a>
### DE：钓鱼节目第6集，鲣鱼仍误用金枪鱼名称

**受影响版本：** DE。

**原版内容与差异：**

- **JP：** `カツオ`。
- **US＝EU：** `Bonito`。
- **DE：** `Thun-fische`——金枪鱼。

**判断依据：**

对应鱼种身份已经在鱼类审计中确定；节目漏掉了与鱼记录一致的修正。

**修复方式：**

沿用已修鱼记录中的Bonito（鲣鱼），仅第6集替换错误金枪鱼名称。

**相关文件：** [第6集](data/scripts/de/EventScript_TV_FishingHour.mary.c) · [JP对应文件](data/scripts/jp/EventScript_TV_FishingHour.mary.c) · [US对应文件](data/scripts/us/EventScript_TV_FishingHour.mary.c) · [EU对应文件](data/scripts/eu/EventScript_TV_FishingHour.mary.c) · [德文鱼记录](data/text/de/fishing_results_data.cc) · [JP对应文件](data/text/jp/fishing_results_data.cc) · [US对应文件](data/text/us/fishing_results_data.cc) · [EU对应文件](data/text/eu/fishing_results_data.cc)

<a id="audit-e15"></a>
### DE：钓鱼节目第10集，把下游鱼全部说成海鱼

**受影响版本：** DE。

**原版内容与差异：**

- **JP：** `海では「サンマ」…下流では「サケ」「ドジョウ」`。
- **US＝EU：** `Sea Fish … Saury pike, and downstream fish are Salmon and Loach.`
- **DE：** `Meeresfische…Zander, Lachse und Bachschmerlen.`——三者全部列为海鱼。

**判断依据：**

下游这一地点限定被遗漏。本项修地点关系，不借此更改既有鱼种 ID 或重新命名全部鱼类。

**修复方式：**

补回Lachs／Bachschmerle（鲑鱼／泥鳅）的下游地点，保持原有鱼种名。

**相关文件：** [第10集](data/scripts/de/EventScript_TV_FishingHour.mary.c) · [JP对应文件](data/scripts/jp/EventScript_TV_FishingHour.mary.c) · [US对应文件](data/scripts/us/EventScript_TV_FishingHour.mary.c) · [EU对应文件](data/scripts/eu/EventScript_TV_FishingHour.mary.c)

<a id="audit-e16"></a>
### DE：钓鱼节目第13集误用了另一鱼种的既有名字

**受影响版本：** DE。

**原版内容与差异：**

- **JP：** `アイナメ`。
- **US＝EU：** `Rock trout`。
- **DE：** `Berg-forellen`。

**判断依据：**

DE 鱼记录中，RockTrout 对应 `Gebirgsforelle`；`Bergforelle` 对应的是 MountainTrout。此处依据游戏现有名称映射修正，不依据现代生物分类擅自重译。

**修复方式：**

沿用同版RockTrout记录的Gebirgsforelle，避免误用另一鱼种Bergforelle。

**相关文件：** [第13集](data/scripts/de/EventScript_TV_FishingHour.mary.c) · [JP对应文件](data/scripts/jp/EventScript_TV_FishingHour.mary.c) · [US对应文件](data/scripts/us/EventScript_TV_FishingHour.mary.c) · [EU对应文件](data/scripts/eu/EventScript_TV_FishingHour.mary.c) · [既有名称映射](data/text/de/fishing_results_data.cc) · [JP对应文件](data/text/jp/fishing_results_data.cc) · [US对应文件](data/text/us/fishing_results_data.cc) · [EU对应文件](data/text/eu/fishing_results_data.cc)

<a id="audit-e17"></a>
### US／EU：矿场研究第9集，把“255层没有下行楼梯”写成“没有通向255层的楼梯”

**受影响版本：** US、EU。

**原版内容与差异：**

- **JP：** `地下２５５階で下り階段が見つかったことはありません。`
- **US＝EU：** `we have not found a stairway down to the 255th level.`
- **DE：** `wir haben keine Treppe im 255 Level gesehen.`

**判断依据：**

同一段明确说已经到过255层几次。正确意思是在255层没找到继续往下的楼梯，而不是到不了255层。

**修复方式：**

将down to（下到）改为down from（从该层继续下行），明确已经抵达255层但未发现更深楼梯。

**相关文件：** [第9集](data/scripts/us/EventScript_TV_MineResearchGroup.mary.c) · [JP对应文件](data/scripts/jp/EventScript_TV_MineResearchGroup.mary.c) · [EU对应文件](data/scripts/eu/EventScript_TV_MineResearchGroup.mary.c) · [DE对应文件](data/scripts/de/EventScript_TV_MineResearchGroup.mary.c)

<a id="audit-e18"></a>
### 鱼王条件被译成“这条鱼适合做哪些菜”

**受影响版本：** US、EU、DE。

**原版内容与差异：**

| 版本 | 原文 |
|---|---|
| JP | “釣り上げた人は、魚を使う料理の得意な人で、中でも『焼き魚』『刺身』『お寿司』が得意だそうです。”——钓到它的人擅长鱼料理，尤其擅长烤鱼、刺身和寿司。 |
| US／EU | “The person who fished it said it was good for Sushi, Sashimi, or Grilled Fish.”——钓到它的人说这条鱼适合做寿司、刺身或烤鱼。 |
| DE | “Der erfolgreiche Angler sagte, der Fisch eigne sich für Sushi, Sashimi oder gegrillten Fisch.”——同样变成鱼适合做这些菜。 |

实际钓鱼判断检查玩家是否已经学会这三份食谱，并非检查背包里是否带着三种料理。海外后文虽然保留了“学习鱼料理”的泛泛提示，但把关键三种料理与钓取条件的联系译坏了。

**判断依据：**

**修复方式：**

恢复钓到鱼王的人会做寿司、刺身和烤鱼的提示，使用本作既有菜名与日文原义；实际食谱判定不改。

**相关文件：** [节目原文](data/scripts/us/EventScript_TV_FishingHour.mary.c) · [JP对应文件](data/scripts/jp/EventScript_TV_FishingHour.mary.c) · [EU对应文件](data/scripts/eu/EventScript_TV_FishingHour.mary.c) · [DE对应文件](data/scripts/de/EventScript_TV_FishingHour.mary.c) · [鱼王食谱条件](src/fishing.cc:893)

<a id="audit-e19"></a>
### 料理对决第2集把糖译成盐

**受影响版本：** US、EU、DE。

**原版内容与差异：**

| 版本 | B选手使用的调味料 |
|---|---|
| JP | “調味料　さとう”——糖。 |
| US／EU | “Seasoning: Salt”——盐。 |
| DE | “Gewürze: Salz”——盐。 |

这不是同一种材料的不同叫法。炒饭配方数据里糖、盐对应不同效果，糖对体力恢复的修正为−1，盐为＋5，海外改变了节目举例所用材料。

**判断依据：**

**修复方式：**

只将第2集B选手调味料改为Sugar／Zucker（糖）；其他集的盐、固定比赛结果保留。

**相关文件：** [料理节目](data/scripts/us/EventScript_TV_DuelingChefs.mary.c) · [JP对应文件](data/scripts/jp/EventScript_TV_DuelingChefs.mary.c) · [EU对应文件](data/scripts/eu/EventScript_TV_DuelingChefs.mary.c) · [DE对应文件](data/scripts/de/EventScript_TV_DuelingChefs.mary.c) · [配方与调味效果](src/cooking_recipe.cc)

<a id="tv-japanese-particles"></a>
### 英文电视台词残留日文助词

**受影响版本：** US、EU。

**原版内容与差异：**

英文正文中出现this type of magic to beは、her sister, Cosmos. Theは，以及off and ran to the oppositeに。

**判断依据：**

这些助词既不是英文单词，也不是文本控制符；删除后仍为对应英文句子。

**修复方式：**

只移除已经确认混入英文的は／に，不改节目分派。

**相关文件：** [JP](data/scripts/jp/EventScript_TV_F314MGrandPrix.mary.c) · [US](data/scripts/us/EventScript_TV_F314MGrandPrix.mary.c) · [EU](data/scripts/eu/EventScript_TV_F314MGrandPrix.mary.c) · [DE](data/scripts/de/EventScript_TV_F314MGrandPrix.mary.c) · [JP](data/scripts/jp/EventScript_TV_StEmeraldAcademy.mary.c) · [US](data/scripts/us/EventScript_TV_StEmeraldAcademy.mary.c) · [EU](data/scripts/eu/EventScript_TV_StEmeraldAcademy.mary.c) · [DE](data/scripts/de/EventScript_TV_StEmeraldAcademy.mary.c)

<a id="de-villa-tv-spring-rain"></a>
### 德版别墅春季雨天预报把明天说成今天

**受影响版本：** DE。

**原版内容与差异：**

镇上别墅电视的春季雨天预报以 `Das Wetter von heute!`（今天的天气！）开头。其他三版均说明是明天的天气。

**判断依据：**

该频道读取明日天气。德版同一节目相邻的春季晴天预报使用 `Hier das Wetter für morgen!`（这是明天的天气预报！）。

**修复方式：**

用相邻预报的首句替换德版雨天首句。

**相关文件：** [别墅电视入口](src/map_terrain.cc) · [DE](data/scripts/de/EventScript_TV_EntertainmentChannelWeatherForecast.mary.c) · [JP 对照](data/scripts/jp/EventScript_TV_EntertainmentChannelWeatherForecast.mary.c) · [US 对照](data/scripts/us/EventScript_TV_EntertainmentChannelWeatherForecast.mary.c)
