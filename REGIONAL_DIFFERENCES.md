# 矿石镇四版差异

本页描述默认关闭 `BUGFIX` 的 JP、US、EU、DE 原版。以实际机制、数据读写和玩家可见影响分类；属于缺陷的条目指向 [BUGFIX](BUGFIX.md)，正常本地化与地区规则不自动修正。来源为同一工程的四版代码、脚本、数据及基准 ROM；未独立运行复现的地方只写静态可确认的结果。

本页不将旧候选数量当作当前机制数量或本轮构建结果。原始全仓扫描保留于 [逐项索引](REGIONAL_DIFFERENCES.tsv)，其基线为 `97f83743`，不等同于当前工作区验收。已排除的社区问题、相同规则的大段说明和未确认可达的潜在缺陷不列入正式差异。

## 结算、养成与事件条件

| 机制 | JP | US／EU／DE | 玩家影响、依据与处理 |
| --- | --- | --- | --- |
| 睡眠时长恢复 | 先把时间设为 06:00，再保存时间；恢复函数因此按 24 小时计算 | 保存真实入睡小时后才设为 06:00，按到次日早晨的小时数计算 | 小时恢复为每小时体力 +7、疲劳 −2。普通床另有固定 +50、−5；JP 因而额外获得过多恢复，通常压住了后续睡过头分支。[缺陷与计算边界](BUGFIX.md#jp-sleep-time) |
| 冬季牧草 | 没有冬季停止生长的判断；换季时不重置牧草生长状态 | 入冬时把已有牧草设为阶段 7、计数 0；冬季不推进生长 | 会改变越冬生长状态与春季恢复生长的起点，并非译文差异。尚不据此断言冬季可割草或放牧。[每日与换季更新](src/field.cc) |
| 幼牛、幼羊出生好感度 | 幼牛无条件取随机数并对母牛好感度的一半取模；幼羊路径以空对象调用好感度读取器 | 从实际母畜读取好感度，只有一半好感度大于 1 时才取随机数并取模 | 修正母羊读取来源及零除数风险；低好感度情形的随机数消耗也不同。JP 的实际异常结果未做运行验证。[缺陷记录](BUGFIX.md#jp-birth-affection) |
| 婚期避让表 | 不包含年内索引 89、114 | 增加这两项，即秋 30 日、冬 25 日 | 婚期候选会额外避开这两天；不是单纯日历显示修改。[日期表和查询](src/wedding_date.cc) · [婚期计算调用](src/script_engine.cc) |
| 婚期的生日冲突 | 订婚后查询已婚配偶；生日与避让表按固定顺序各检查，顺延后不重新检查全部条件 | 使用本次婚约对象，并在每次顺延后重新检查双方生日与避让表 | JP 可能安排在未婚妻生日，或在避开其他日期后落到玩家生日。[待修复问题](BUGFIX.md#jp-wedding-birthdays) |
| 医生的两段下午行程 | 两套外出日程的切换点为 600、627 | 切换点为 601、628 | 调度使用从 06:00 起算的分钟，因此从 16:00／16:27 改为 16:01／16:28；相同路径晚一分钟开始及结束。仅适用于选中这两套日程时，不能推广为医生所有活动都推迟。[日程选择与路径](src/npc_schedule_doctor.cc) · [时间比较](src/npc_schedule_search.cc) · [分钟换算](src/npc_entity.cc) |
| 扩建畜棚的三格调查属性 | 网格坐标 `(11,6)`、`(11,7)`、`(11,8)` 使用属性项 3，调查脚本为 `0x016B` | 三格改为属性项 2，调查脚本为 0 | 两属性项的阻挡位相同，仅取消这三格的“木桶”调查文本，不是允许穿过墙壁。坐标以 8 像素格计、从 0 起算。[网格和属性](src/map_terrain.cc) · [地图选择](src/map_selection.c) · [调查脚本](data/scripts/jp/EventScript_LocationInteraction_InspectTownAndFarmBuildingBarrel.mary.c) |
| 动物照料最高记录 | 从动物照料记录字段读取 | 动物照料栏再次读取收获记录字段 | 海外版两个小游戏栏目显示相同成绩，但动物照料的真实成绩仍独立保存；不是没有结算小游戏奖励。[待修复问题与读写证据](BUGFIX.md#overseas-animal-care-record) |
| 获奖牛羊的出售价格 | 好感度超过 200 且获奖时，累计户外不足 600 小时：牛 7,000 G、羊 5,000 G；达到 600 小时：牛 6,000 G、羊 4,000 G | 同样两档依次为牛 6,000／7,000 G、羊 4,000／5,000 G | JP 两个高等级的售价分支与海外相反，达到户外时间门槛反而少卖 1,000 G；报价直接用于实际入账，不是文本错误。[完整售价与入账链](#livestock-sale-prices) |

冬季牧草的类型判定已追到收割返回值及 `Barn::AddStoredBushels(1)` 的入库调用；保留为地区生长规则差异，不把它扩张为已确认冬季可割草或放牧。[田地更新](src/field.cc) · [收割入库](src/game_world.cc)

<a id="livestock-sale-prices"></a>
### 获奖牛羊出售价格

下表按 `Livestock::GetProductRank()` 的五个返回值排列；条件是累计户外时间，不能改写成连续放牧时间。等级 3、4 还要求好感度超过 200 且已经获奖。

| 基础等级与条件 | JP 牛 | US／EU／DE 牛 | JP 羊 | US／EU／DE 羊 |
| --- | ---: | ---: | ---: | ---: |
| 0：好感度 ≤ 100 | 3,000 | 3,000 | 2,000 | 2,000 |
| 1：100 < 好感度 ≤ 200 | 4,000 | 4,000 | 2,500 | 2,500 |
| 2：好感度 > 200，未获奖 | 5,000 | 5,000 | 3,000 | 3,000 |
| 3：获奖、累计户外 < 600 小时 | 7,000 | 6,000 | 5,000 | 4,000 |
| 4：获奖、累计户外 ≥ 600 小时 | 6,000 | 7,000 | 4,000 | 5,000 |

`GetAnimalSalePrice` 的牛、羊跳转表在 JP 各交换了等级 3、4 的目标。`Run` 将返回值保存为出售列表项的价格，确认后把同一字段直接传给 `AddMoneyToAccount`，随后移除动物。因此，在其他条件不变且未触及持金上限时，JP 获奖动物达到 600 小时反而少收入 1,000 G；海外则多收入 1,000 G。这里不使用牛羊生产时额外抽取 X 级产物的随机分支。[基础等级条件](src/livestock.cc) · [两张跳表、列表写入与出售确认](src/scene_yodel_ranch_shop.cc) · [金钱写入及上限](src/money_account.cc)

这是已确认的数值行为和海外调整；JP 的反向等级价格已接入工作区的[可选修复](BUGFIX.md#jp-livestock-sale-prices)，默认关闭时仍保留上述原版行为。

## 流程与输入反馈

| 范围 | 原版地区行为与玩家影响 | 处理与依据 |
| --- | --- | --- |
| 04:44／16:44 电视 | JP 两入口调用隐藏节目；海外遗漏后用未赋值频道变量分派，时间未变时反复重入。 | 海外可选修复：[电视流程](BUGFIX.md#tv-444)。 |
| 艾利昵称 | US／EU 第二选项确认 Honey 但不保存；JP／DE 会写回。 | US／EU 可选修复：[昵称](BUGFIX.md#elli-nickname)。 |
| 德版电视频道与节目 | 春 19 日贯穿到 20 日并覆盖输入；人物介绍第 36 项未取得频道输入。其他地区无这两处遗漏。 | 两项分别修正：[春 19 日](BUGFIX.md#de-farm-tv) · [频道输入](BUGFIX.md#de-profile-tv)。 |
| 联机重试 | JP 新消息不重置场景缓存；旧值为完成状态时可提前创建重试选项。海外将缓存设为 4。 | JP 可选修复：[重试状态](BUGFIX.md#jp-link-retry)。尚未运行复现全部断线时序。 |
| 新手教学退出 | 海外进入退出状态后跳过 Start 再次退出检查；JP 没有这层状态保护，满足淡出空闲和对话条件的新按键事件可能再次启动淡出。 | 保留为输入防重入差异，未接入 BUGFIX；不能表述为持续按住 Start 必然卡死。[教学状态机](src/farming_tutorial.cc) · [按键事件](src/hardware_input.cc) · [淡出](src/hardware_blend.cc) |
| 音乐节入场状态 | 海外转入开幕前多写一次阶段 1；四版正常卡特对话入口此前已写相同值。 | 实际存在重复写入，但正常入口没有改变演奏资格、奖励或退场条件，不作 BUGFIX。[对话入口](data/scripts/jp/EventScript_NPCEvent_Carter_DialogueAndGiftResponses.mary.c) · [海外入场](data/scripts/us/EventScript_FestivalEvent_MusicFestival_EntryCheck_Carter.mary.c) |

<a id="goddess-rps-options"></a>
### 女神猜拳的显示选项

三个选项按位置返回 `CHOICE_OPTION_1/2/3`。四版对应分支实际依次执行石头、剪刀、布：第一项对随机结果 0／1／2 得到平／胜／负，第二项负／平／胜，第三项胜／负／平，结果消息也按这个顺序描述玩家出拳。DE 仅将倒计时消息复用，未重排胜负分支。

| 菜单位置／实际出拳 | JP 显示 | US、EU 显示 | DE 显示 |
| --- | --- | --- | --- |
| 1／石头 | ぐー（石头） | Rock（石头） | Schere（剪刀，错误） |
| 2／剪刀 | ちょき（剪刀） | Paper（布，错误） | Stein（石头，错误） |
| 3／布 | ぱー（布） | Scissors（剪刀，错误） | Papier（布） |

因此 US／EU 的第二、三项错位，DE 的第一、二项错位。选择显示的手势后，会进入另一手势的结果与胜负分支；不是随机结果或赢局累加的公式改变。因为三个实际手势仍各有一个入口，此问题本身也不等于修改了胜率。`ChoiceRock`／`ChoiceScissors`／`ChoicePaper` 标识符现按各自文字的实际含义命名；声明与引用一起替换，未改变原版选项次序或 BUGFIX 逻辑。[JP 脚本](data/scripts/jp/EventScript_TV_HarvestGoddessRockPaperScissors.mary.c) · [US](data/scripts/us/EventScript_TV_HarvestGoddessRockPaperScissors.mary.c) · [EU](data/scripts/eu/EventScript_TV_HarvestGoddessRockPaperScissors.mary.c) · [DE](data/scripts/de/EventScript_TV_HarvestGoddessRockPaperScissors.mary.c) · [选项返回值](include/fomt_constants.mary.h)

## 文字、名称与显示

| 范围 | 原版地区差异 | 玩家影响与处理 |
| --- | --- | --- |
| 商品价格与身份 | JP 小／大鱼价倒置；海外炒荞麦面、X 羊毛复用另一等级／菜品文本；DE 收集宝玉复用成品名字、XL 药品复用普通药名字。 | 价格影响实际收益，其余主要造成物品身份误认。分别见 [鱼价](BUGFIX.md#fish-prices)、[炒荞麦面](BUGFIX.md#fried-soba)、[羊毛](BUGFIX.md#wool-x)、[宝玉](BUGFIX.md#de-jewels)、[德版食物](BUGFIX.md#de-food)。 |
| 钓鱼记录名 | 海外 37 复用 22；DE 的 46 还复用 18。JP 分别区分鱼种，US／EU 的 18／46 也独立。 | 名称混淆，记录 ID、数量及尺寸仍独立。[鱼名修复](BUGFIX.md#fish-record-names)。 |
| 包装农具 | JP／US 用基础编号取图标，EU／DE 根据保存的升级记录转换编号。 | 只影响包装界面的背包及手持图标，不使工具降级。[修复](BUGFIX.md#wrapping-tool-icons)。 |
| 动物照料最高记录 | JP 读取照料记录，海外错读收获记录。 | 成绩保存正确，记录页显示错误；尚未修复。[读写证据与状态](BUGFIX.md#overseas-animal-care-record)。 |
| 对话语言与角色 | 海外来访星期、休息日、人物指代、物品名等存在错译；US／EU 部分已调用消息仍为日文／德文，DE 联机确认仍为 Yes／No。 | 已核实对象及实际正确含义统一列在 [文本修复清单](BUGFIX.md#localization-text)，不把错误译文推断为事件条件或奖励改变。 |
| 羊祭接待桌 | JP 的共用接待脚本 `0x0194` 分别调用牛祭、羊祭提示；US／EU／DE 两个分支共用含 Cows／Kühe（牛）的文字。直接交谈的羊祭脚本 `0x04FC` 四版均无此误称。 | 羊祭被说成牛祭，只影响提示，不改变评审动物或结果；接待分支没有年份限制。海外 BUGFIX 仿照 JP 分开消息，复用各版本已有羊祭台词。[调用与修复](BUGFIX.md#sheep-reception-text)。 |
| DE 收获结果栏目 | 用动物照料的 Gefüttert／Vergessen（已喂食／遗忘），JP／US／EU 对应收获／失败。 | 计分仍取收获与失败次数，仅修栏目为 Geerntet／Fehler。[DE 文本](data/text/de/scene_harvesting_minigame_2.cc) · [消费者](src/scene_harvesting_minigame.cc) · [修复](BUGFIX.md#localization-text)。 |
| 普通鱼竿说明 | US／EU 缺首行分隔，读取器越过终止零拼入下一个对象；JP／DE 有分隔。 | 补齐说明两行，保持原菜单逻辑。[说明读取](src/game_menu.cc) · [文本修复](BUGFIX.md#localization-text)。 |
| 钓获消息行宽 | US／EU 的漂流瓶、海贼宝藏展开后超过 28 格；DE 四种长鱼名的模板多一尾空格。 | 回绕同一行覆盖开头；仅修这些模板，不添加自动换页。[消息与修复](BUGFIX.md#localization-text)。 |
| 换行残留与满行空格 | US／EU／DE 的部分脚本含字面量 `ret>` 或 `<RET>`，四版均发现正文满行后还有空格的情况。 | 记号会按普通字符显示，多余空格会覆盖行首；仅修已核实的对应原文，不给引擎增加新控制符。[范围与依据](BUGFIX.md#localization-text)。 |
| 凯贺卡签名 | US／EU／DE 的原 ROM 均含制表字节 `09`；JP 直接用空格排签名。 | 源码转义写法虽不同，实际前三版字节相同。指南不解释制表控制，保留真实缩进并去除该前缀。[页面](data/text/us/reference_guide/birthday_card_kai.cc) · [修复](BUGFIX.md#localization-text)。 |
| 联机商人英文名 | GBA 海外姓名栏为 Lou，英语自我介绍为 Van；跨作品还存在 Ruby／Lou 的命名沿革。 | 采用本作自我介绍及当时商人的 Van，不解释为误用了重制版另一角色的名字。[历史与取舍](BUGFIX.md#van-name-history)。 |

<a id="cooking-wrapped-description"></a>
### 料理材料包装说明

料理材料选择状态 `func_080962F0` 另有一处海外显示缺陷。选中非空且已包装物品时，JP 把物品名和包装说明拼入同一个缓冲区，再交给文本窗口；海外三版先把 `A wrapped`／`Gepackt` 拷入另一个最多七字节的临时缓冲区，又将物品名拼向该临时区，但最终仍传入原来的**仅有物品名**的缓冲区。由此包装说明未进入实际显示文本；不是商品包装标志被清除。海外该函数在既有匹配快照中的代码与重定位完全一致。已追到 `func_08050DC8` 将指针直接交给 `UiStatePayload::SetText`，没有在下游补入包装说明。这里登记静态确认的显示缺陷，不扩展为材料消费／配方判定已完成审计，也未实施 BUGFIX 或运行复现。[拼接与实参](src/scene_cooking.cc) · [窗口适配器](src/ui_state.cc) · [JP 说明](data/text/jp/scene_cooking_2.cc) · [US](data/text/us/scene_cooking_2.cc) · [EU](data/text/eu/scene_cooking_2.cc) · [DE](data/text/de/scene_cooking_2.cc)

此项尚未接入开关，后续按整个料理文件高级语言化后处理，状态见 [BUGFIX](BUGFIX.md#cooking-wrapped-description)。

<a id="guide-name-boundaries"></a>
### 指南标记与名称缓冲区

`ExpandReferencePageText` 四版均把普通内容按两个字节复制，只在本轮第一个字节为 `<` 时识别 `<p>`、`<f>`、`<cp>` 等名称标记。海外单字节文字使部分标记落在被跳过的位置。对现有四版指南的名称标记逐行筛查，以下六个地区／行组合未被识别；原文及终止零已在对应 baserom 核对。

| 版本 | 图书／原始行 | 标记起点（本行字节偏移，从 0 算） | 原版文本地址 |
| --- | --- | ---: | --- |
| US | 养鸡场给玩家与珀布利的贺年卡：`Dear <p> and`（亲爱的玩家与……） | 5 | `0x08115CC8` |
| EU | 同上 | 5 | `0x08115D20` |
| DE | 同一贺年卡：`Lieber <p> und`（亲爱的玩家与……） | 7 | `0x08117B28` |
| US | 托马斯与哈里斯的生子贺信：`he and <f>`（他与玩家牧场） | 7 | `0x08117198` |
| EU | 同上 | 7 | `0x081171F0` |
| DE | 高仓介绍：`Arbeitet mit <cp> auf der`（与联机玩家在……工作） | 13 | `0x0810FB3C` |

实际影响是名称没有展开，原标记字节进入绘制器。四版单字节字模表中的 `<`、`>`、`p`、`f` 都是有效字模，普通绘制器也不再展开指南变量，因此不能把社区的“漏字”描述直接写成这里必然隐藏整段文字。JP 现有名称标记没有命中该步长问题；DE 托马斯贺信的 `<f>` 在偏移 4，能正常展开。`<f>` 的实际来源是**牧场名**，不是社区猜测的配偶名。[展开与显示](src/scene_reference_page.cc) · [字模索引](src/font_data.s) · [绘制器](src/font_draw.cc) · [US 养鸡场贺卡](data/text/us/reference_guide/new_year_card_poultry_farm_player_and_popuri.cc) · [US 托马斯贺信](data/text/us/reference_guide/newborn_congratulations_thomas_and_harris.cc) · [DE 高仓介绍](data/text/de/reference_guide/ngc_awl_profiles_takakura.cc)

另有独立的边界风险：该函数限制的是最多 14 轮，而不是写入字节数；名称一次可以写入多个字节。标题和正文调用者均使用 `char text[32]`。JP 的联机玩家介绍标题在名称后还有 24 字节文字／全角空格，名称达到 8 字节时，加终止零就要 33 字节，超过局部数组。DE 高仓介绍另一行 `er ein Freund von <cp>s`（他是联机玩家父亲的朋友）也可超过此数组；普通路径还会复制落在一对字节中第二位的终止零后继续读下一对，不能只按可见字符串长度计算写入上界。按接收端允许的最长名称和原 ROM 后继字节静态推演，这两处分别写入 39 字节和 39 字节（含最终终止零）。这是缓冲区越界证据，**尚未运行确认具体破坏或崩溃症状**；GC 对端实际可输入长度仍须与具体 AWL 版本另核，不把接收协议上限当作对端界面上限。[JP 标题](data/text/jp/reference_guide/ngc_awl_profiles_player.cc) · [DE 正文](data/text/de/reference_guide/ngc_awl_profiles_takakura.cc) · [接收端解码](src/gamecube_link_save.cc) · [名称字段](include/game_state_types.hh)

展开函数入口为 JP `0x0807A2B0`、US `0x0807A708`、EU `0x0807A71C`、DE `0x0807A600`；既有原版取证中，四版各 368 字节与对应 baserom 一致；这不是本轮修复后的验收记录。以上是原版代码与文本组合问题。[最小修复](BUGFIX.md#guide-name-expansion)保留原有 14 次循环与名称复制规则：JP 删除上述标题尾空格，海外只补普通内容第二字节的结束符／标记起点判断，不引入通用截断。

另外，DE `Arbeitet mit <cp> auf der` 原先漏展开名称；恢复识别后，12 字节名称使整行含结束符达到 34 字节。因此 BUGFIX 下按原用词将前两行改排为 `Arbeitet mit <cp>`、`auf der Farm.`、`Es wird gesagt, dass` 三行，再接原有正文。高仓页面增加一行，指南生成器自动重建行指针表；总目录仍为 137 项。另一行 `er ein Freund von <cp>s` 在同样名称长度下含结束符恰为 32 字节，及时停止后不再复制后继数据。

静态范围：现有原版 US／EU 名称行在允许的最长名称下最多写入 25 字节，未发现这组文本的缓冲区越界；仍有上表所列的标记漏展开。实际标题／窗口布局限制与缓冲区容量不是同一概念，本修复不新增自动换行或统一 28 字节裁剪。

### 界面本地化与演出

| 范围 | 地区差异与实际影响 | 边界与依据 |
| --- | --- | --- |
| 购买数量选择器 | JP 多绘制一个数量后缀图块；金额使用双格数字，海外使用窄数字。数量上限、按金钱限制数量及方向键增减逻辑相同。[实现](src/ui_quantity_selector.cc) | 本处是显示调整，没有发现海外放宽购买上限。 |
| 飞盘界面 | DE 对资源组 `0x1A` 的一次精灵提交将横坐标从 160 改为 158，纵坐标 16 不变。[调用与精灵提交](src/frisbee_core.cc) | 该差异影响界面位置，不是投掷距离或狗的能力。 |
| 料理祭评审停顿 | DE 一处等待从 240 帧增至 480 帧，其他判定语句相同。[DE 评审](data/scripts/de/EventScript_FestivalEvent_CookingFestival_Judging.mary.c) | 延长演出等待；这处差异没有修改评分公式。 |
| 时钟显示 | DE 的相关脚本保留下午小时数，其他版减 12。HUD 正午另有区别：JP 将 12 减成 0、仍显示下午标记，US／EU 特判 12、不减；DE 直接显示小时值。午夜传入 0 时 US／EU 也保持 0，不能概括成严格的 1–12 小时制。[时钟脚本](data/scripts/de/EventScript_SystemMenu_ClockCalendarDisplay.mary.c) · [HUD](src/map_clock_status.cc) · [小时字段调用](src/game_scene_state.cc) | 改变显示，不改变游戏一天长度或事件判断所读取的小时字段。 |
| 参赛动物的获奖标记 | JP 的鸡列表会检查获奖标志；海外版还在牛、羊列表增加同类检查及 2×2 图块绘制。[选择画面](src/animal_festival_selection.cc) · [获奖标志读取](src/animal.cc) | 已定位的新增分支只绘制标记，不写入动物状态，不应解释成海外改了获奖资格或产物等级。图案外观未在本轮运行确认。 |
| 酒庄购买后的送货提示 | JP、DE 区分全部送入冰箱与部分送入；US、EU 使用同一条送货消息。地区分支位于向手持物、背包、冰箱分配物品之后。[分配与提示](src/scene_winery_shop.cc) · [JP 文本](data/text/jp/scene_winery_shop.cc) · [US 文本](data/text/us/scene_winery_shop.cc) | 该分支影响反馈文字，不改变本次实际扣款或分配数量。 |
| 鸡祭场景的精灵位置 | `UpdateUnkPhase0` 为 `sprite_96C` 的绘制参数设置相同横坐标 96，纵坐标在 JP、DE 为 8，在 US、EU 为 10。[初始化](src/scene_chicken_festival.cc) · [位置字段](include/resource_handle.hh) | 这处数值差异是显示对象下移 2 像素，不是比赛时长或鸡的能力；尚未给该精灵图案臆定名称。 |
| 工作人员名单过渡 | JP 在滚动计数超过 127 后进入后续滚动；海外在超过 138 后额外淡出、更新字幕、淡入，再进入后续滚动。[状态机与绘制](src/staff_credits.cc) | 不只是名单文字不同，演出状态机也不同；这些阈值是状态机计数，不能直接当作表内有效文本数。 |

| 界面 | 具体地区调整 | 依据 |
| --- | --- | --- |
| 日历星期标题 | 初始横坐标 JP 为 10，海外为 6；每列仍加 34，共七列。 | [日历绘制](src/scene_calendar_core.cc) |
| 料理标题与选择 | JP 以双字节／16 像素字形，海外以单字节／8 像素字形组织标题和材料项；标题一处为 11／22 字形，对应同一 176 像素宽度。未公开配方名使用全角／半角问号。 | [料理界面](src/scene_cooking.cc) |
| 动物状态页 | 健康、季节、日期的字形宽度改变，海外扩大缓存及 tilemap；状态图块选择值 JP 为 `0x38/0x44/0x50`，海外为 `0x38/0x48/0x58`。这些是图块位置，不是疾病等级。 | [状态页](src/farm_status_screen.cc) |
| 精灵及农具状态页 | 三种能力条的图块基址、工作日数单位与 DE 文本区宽度不同；农具提示、条形图基址及数字字宽随地区改变。数值到条长及等级读取仍走对应原字段。 | [状态页](src/farm_status_screen.cc) · [精灵经验](src/harvest_sprite.cc) |
| 收入、记录及滚动菜单 | JP 数字通常为 2×2 图块，海外为 1×2；海外对象中的文字缓存／位置相应改变。DE 部分标题再扩大。它们不改变金额字段或记录容量。 | [记录页](src/records_screen.cc) · [收入页](src/farm_status_screen.cc) · [滚动菜单](src/scroll_menu.cc) |
| 飞盘成绩板 | JP／海外每个数字字形 128／64 字节，标题缓存宽 22／27 图块，姓名行跨度 13／14 字节。 | [显示初始化](src/frisbee_scoreboard.cc) · [结构](include/frisbee_scoreboard.hh) |
| 新游戏确认与日期输入 | 确认值区同为 12 tile，标签区 JP 12、海外 14；生日输入的列步长按字宽调整，写回仍为四季各 30 天。 | [确认](src/new_game_identity.cc) · [生日输入](src/new_game_birthday_input.cc) |
| 存档摘要 | JP 把宽数字放在年／日后缀前；海外把 Years／Jahre、Day／Tag 放在数字前，并调整季节间隔。仅格式化摘要，不改存档日期。 | [摘要](src/new_game_menu.cc) |
| 动物悼词 | JP／海外名字与提示拼接顺序不同；DE 自然死亡另用开头与牧场前缀。 | [消息生成](src/game_scene.cc) · [DE 文本](data/text/de/game_scene.cc) |
| 赛马轮次及购票提示 | 轮次数横坐标 JP／US、EU／DE 为 16／32／136；玩家参赛时 JP 取鼓励消息，海外仍用一般购票询问。 | [赛马界面](src/horse_race.cc) |
| 商店送货提示 | JP 杂货店按装备、食品及部分送货选择不同文案，海外复用部分消息；JP 霍安商店另区分普通物品和工具，海外复用消息。选句在实际分配之后，不改变扣款与分配数量。 | [杂货店](src/scene_supermarket.cc) · [霍安](src/scene_won_shop.cc) |
| 开场 | JP 资源 8 初始 Y 为 −56，海外 −96；JP 额外提交资源 9；对应归档组号也有偏移。 | [开场场景](src/intro_scene.cc)。未把匿名资源猜作新增游戏功能。 |

## 编码、数据布局与系统接口

| 主题 | JP | US | EU | DE | 实现与影响 |
| --- | --- | --- | --- | --- | --- |
| GBA / GameCube 联机识别 | A4NJ / GYWJ | A4NE / GYWE | A4NP / GYWP | A4ND / GYWP | 左列为本机游戏代码，右列为对端代码。德版与欧版共用对端代码；这些是协议字节。[连接代码](src/gamecube_link_save.cc) |
| 命名键盘 | 每页 6 行 | 6 行 | 6 行 | 7 行 | 每版都存 3 页，每行 15 个双字节槽与结束符。德版额外一行，按钮在画面上也下移一格。[数据布局](include/new_game_data.hh) · [键盘绘制](src/new_game_name_input.cc) |
| 命名输入容量与快捷键 | 6 个双字节字符；Select 可循环切换键盘页 | 12 个单字节字符；无 Select 切页分支 | 同 US | 同 US | 四版仍可使用画面上的前后翻页选项；仅快捷键与字符处理单位不同。删除按各自字符宽度移位，全为空格／占位符时不能确认。[输入、删除和规范化](src/new_game_name_input.cc) |
| 新游戏控制选项 | 复用 Data1、Data2 两个标签 | 独立标签 | 独立标签 | 独立标签 | 行表中的两条指针随地区选择，表结构一致。[菜单行表](src/new_game_menu.cc) |
| 指南续页 | 无独立续页表 | 道具操作 | 道具操作 | 使用工具、克里夫与琳的新生儿贺信 | 137 项主目录分别对应 137、138、138、139 张物理页面行表。续页与首页共用图书 ID，仅首页进入目录。[指南清单](src/reference_guide.cc) |
| 特殊字模 | 0x81CD 的 24 字节字模 | 14 组 12 字节字模与 0xC3 字模 | 同 US | 同 US | 这些是渲染资源的地区分支；单双字节通用字库也各自有独立索引。[字模声明](include/font.hh) |

| 范围 | 地区差异 | 调用上的含义与依据 |
| --- | --- | --- |
| 联机名称包 | JP 三个名称字段各 8 字节，最多 7 个协议索引；海外各 13 字节、最多 12 个。JP 从双字节取码，海外从单字节取码。 | 是协议差异，不能只改游戏代码假定跨区互传；不等于整个 SRAM 布局不同。[结构](include/gamecube_link_save.hh) · [编解码](src/gamecube_link_save.cc)。JP 最后字符边界另见 [BUGFIX](BUGFIX.md#jp-link-last-character)。 |
| 场景文本变量 | JP 每槽最多 20 编码字节，海外 22；经对齐均占 24 字节。截取按字节，非完整字符。 | 超长替换值会截短，不能用结构总大小推出相同容量；未断言现有原文已截断双字节。[文本槽](include/scene_text_variables.hh) · [写入](src/scene_text_variables.cc) · [FixedStr](include/utility/fixed_str.hh) |
| 日历名称数组 | 季节／星期行步长 JP 为 3／3 字节，海外为 7／5，项数始终 4／7。 | 取址乘法不同来自数组布局，而非日期编码改变。[声明](include/calendar.hh) · [读取](src/calendar.cc) |
| 串行寄存器初始化 | EU／DE 在启动及复位路径额外配置串行寄存器，JP／US 对应复位入口直接返回。 | 已确认硬件状态初始化差异，未据此命名某个具体断线缺陷；保持地区实现。[启动](src/main.cc) · [复位](src/joy_bus.c) |
| 场景返回编号 | JP 与海外部分商店／菜单返回编号差 1，发送与接收方各自配套。 | 不代表增加／删除同等数量的场景。[类型](include/game_scene.hh) · [发送](src/game_scene.cc) · [接收](src/game_scene_state.cc) |
| 商店图块／调色板槽位 | 海外用两个源指针映射复用九个 OBJ 槽位，JP 对应路径直接提交资源。 | 显示资源管理变化，非商品库存或可买数量改变。[显示](src/shop_common.cc) · [槽位结构](include/shop_resource_slots.hh) · [插入释放](src/shop_resource_slots.cc) |
| GameScene 构造入口 | 海外额外保留接收 `GameStateSaveImage *` 的构造重载，内部固定创建恢复请求 2。 | 是入口保留差异；正常控制器显式传入请求对象，不能仅凭重载断言新增游戏模式。[构造](src/game_scene.cc) · [控制器](src/game_scene_controller.cc) |
| ROM 头 | JP `BOKUMONOGBA / 99`，US／EU `HARVESTMOGBA / E9`，DE `HARVESTMOGER / E9`。 | 标题与厂商识别字段。[配置](config.mk) |
| 字符编码 | 海外附加单字节符号和西文字符，DE 使用 ä、ü、ö、ß 等。 | 地区编码表与读取字宽需配套，不视为普通文本字节可直接跨版替换。[码表](charmap.txt) |

## 脚本调用与播放方式

本表按忽略文本符号名后的原版语句差异排列。普通消息、慢速消息、追加消息分别采用 `0x100`、`0x40`、0 的提交速率，并改变分段体验；电视消息还返回频道输入，不能统称为“仅速度不同”。已确认为缺陷的行链接 BUGFIX，重复赋值和正常本地化保留其实际边界。[接口](data/scripts/jp/fomt_callables.mary.h) · [提交](src/game_scene.cc)

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
| [03DC](data/scripts/us/EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay.mary.c) | JP / US=EU=DE | JP 先设 06:00 再保存包含时间的次日状态，导致睡眠小时恢复按 24 小时计算；海外版先保存真实时间。[机制影响](BUGFIX.md#jp-sleep-time) |
| [03E1](data/scripts/de/EventScript_NPCEvent_Popuri_DialogueAndGiftResponses.mary.c) | JP=US=EU / DE | DE 在珀布利日常对话中多一次 TalkMessage。 |
| [03E5](data/scripts/us/EventScript_NPCEvent_Zack_DialogueAndGiftResponses.mary.c) | JP=DE / US=EU | US/EU 在扎克日常对话中多一次 TalkMessage。 |
| [03F0](data/scripts/de/EventScript_NPCEvent_Karen_DialogueAndGiftResponses.mary.c) | JP / US=EU / DE | 卡莲的对话在头像表情、切换次数和 DE 文本分段上存在差异。 |
| [03FD](data/scripts/us/EventScript_NPCEvent_Manna_DialogueAndGiftResponses.mary.c) | JP=DE / US=EU | US/EU 将玛娜日常对话中的一处慢速文本改用普通对话。 |
| [0414](data/scripts/de/EventScript_TV_LifeOnTheFarm_Beginner.mary.c) | JP=US=EU / DE | 德版春 19 日节目少一个 break，会继续播放 20 日节目。[缺陷记录](BUGFIX.md#de-farm-tv) |
| [0418](data/scripts/de/EventScript_TV_MineralTownFriends_CharacterProfiles.mary.c) | JP / US=EU / DE | 人物介绍节目中的慢速台词数和调用类型不同；DE 第 36 号人物节目没有读取频道输入，随后分派到天气频道。[缺陷记录](BUGFIX.md#de-profile-tv) |
| [0432](data/scripts/us/EventScript_FestivalEvent_NewYearsDayFestivalDialogue_Manna.mary.c) | JP / US=EU=DE | 海外版本改变玛娜新年对话中一处文本速度。 |
| [0445](data/scripts/de/EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Manna.mary.c) | JP / US=EU / DE | 玛娜赛马场对话的慢速台词数不同。 |
| [0468](data/scripts/de/EventScript_FestivalEvent_CookingFestival_Judging.mary.c) | JP=US=EU / DE | 料理祭评审的一次等待由其他版的 240 帧变为 DE 的 480 帧。 |
| [04B4](data/scripts/us/EventScript_FestivalEvent_MusicFestival_EntryCheck_Carter.mary.c) | JP / US=EU=DE | 海外版在转入音乐祭开幕脚本前显式写入 FESTIVAL_PHASE_INITIAL；四版卡特普通交谈调用此前已设置同值，正常交谈入场路径没有因此改变资格、奖励或退场条件。 |

## 已确认错误的源码名称整理

命名依据依次采用本作已有的正确本地化文本、重制版对应名称；两者都不存在时才考虑重新翻译日文。地区正式名称不同本身不构成错误，不以日文直译或音译统一覆盖已有本地化名称。源码以英文鱼名命名，不附记录编号或另拼鱼种后缀；过长名称采用明确记录且经确认的界面短写。数值 ID、对象顺序及默认行为不变。

| 原标识符 | 修正与依据 |
| --- | --- |
| `gText_FishingRecord_SilverCarp22` / `FISHING_RECORD_SILVER_CARP_22` | 改为 `gText_FishingRecord_SilverCrucian` / `FISHING_RECORD_SILVER_CRUCIAN`。JP 槽 22 为银鲫（ギンブナ），英文鱼名为 silver crucian carp；原英文／德文显示名 Silver Carp／Silberkarpfen 对应的却是鲢鱼。US／EU 的 BUGFIX 显示文本采用 14 字符界面短写 Silver Crucian，DE 采用重制版原名 Ginbuna。 |
| `gText_FishingRecord_SilverCarp37` / `FISHING_RECORD_SILVER_CARP_37` | 移除数字后缀，使用 `gText_FishingRecord_SilverCarp` / `FISHING_RECORD_SILVER_CARP`。JP ハクレン（鲢鱼）对应 Silver Carp／Silberkarpfen，显示名称正确。槽 44 ヘラブナ已有的 `CrucianCarp` 标识符和显示名称保留。 |
| JP／DE 猜拳 `ChoiceRock` / `ChoicePaper` / `ChoiceScissors` | JP「ちょき」「ぱー」及 DE「Schere」「Stein」「Papier」原标签与自身文字不符；使用本作 US／EU 已有的正确 Rock／Scissors／Paper 名称，声明和调用目标一起更名。 |

依据：[日版鱼名](data/text/jp/fishing_results_data.cc)、[鱼名指针表](src/fishing_results_data.cc)、[纪录 ID](include/fomt_constants.mary.h)、[既有鱼名问题](BUGFIX.md#fish-record-names)、[JP 猜拳](data/scripts/jp/EventScript_TV_HarvestGoddessRockPaperScissors.mary.c)、[DE 猜拳](data/scripts/de/EventScript_TV_HarvestGoddessRockPaperScissors.mary.c)。重制版名称取自同级 `SoSFoMTTextDump/SoSFoMTTextDump/JA/msg_Item.txt` 与 `US/msg_Item.txt` 的对应鱼名序列：キンブナ／ギンブナ／クエ对应 Goldfish／Crucian Carp／Longtooth Grouper；不是仅凭相似英文词推断。

Silver Crucian Carp 是已有英文鱼名：[1998 年研究中的 Japanese silver crucian carp／ginbuna](https://pubmed.ncbi.nlm.nih.gov/9546204/)、[2019 年研究中的 silver crucian carp／ginbuna](https://pubmed.ncbi.nlm.nih.gov/31347186/)。重制版英文泛称 Crucian Carp 会与另一鱼种重名，本次采用完整英文名的界面短写 Silver Crucian，变量同步采用 SilverCrucian；该短写由用户确认，不宣称是已查证的官方简称。[国立环境研究所](https://www.nies.go.jp/biodiversity/invasive/DB/detail/50060.html) 则将 Silver carp 对应到ハクレン。原版两个记录共用同名字串本身不是结构错误，修复对象是记录 22 的鱼种显示名。

验证（2026-11-15）：最终标识符下，JP／US／EU／DE 默认完整构建均与各自 baserom 逐字节及 SHA-1 一致。开启 BUGFIX 后，使用正常编译配方重新编译四版完整的 `fishing_results_data.cc`，核对记录 22、37、44 的共 12 项字符串及指针重定位；均正确，22 与 44 保持独立对象。本次开启 BUGFIX 的验证范围为该模块，不代表重新验证了整版 BUGFIX ROM。旧标识符在源码中的引用已清除。

海外未开启 BUGFIX 时，原错误文本沿用 `gText_FishingRecord_SilverCarp` 标签，由记录 22／37 共用；开启后记录 22 使用 `gText_FishingRecord_SilverCrucian`，记录 37 使用独立的 `gText_FishingRecord_SilverCarp`。这使源码标签直接反映修复前后的实际文本身份；记录 ID 的常量仍按真实鱼种命名，数值不变。

## 证据与验收边界

### 四版物品目录复核（2026-11-15）

按各类物品的数值 ID 对照四版全部 81 项工具、171 项食物及 95 项其他道具，检查名称、说明、同表及跨表指针复用；不依赖相似英文名称配对。新确认的季节提示、出货提示、材料用途、料理配料与名称漏翻等问题，统一记录在 [BUGFIX 的物品说明审计](BUGFIX.md#item-description-audit)，不在此重复列为正常地区差异。

面粉、烤苹果和餐包统一使用 `Flour`、`BakedApple`、`DinnerRoll` 标签；BUGFIX 只选择显示文本，不为原版误译或错拼另建物品标签。德版 `Apfelauflauf` 保留现有本地化名称。

差异按默认原版归类；开关后的实现状态统一以 [BUGFIX 验收记录](BUGFIX.md#本轮验收记录) 为准。不把旧快照或局部函数匹配写成本轮四版整 ROM 通过。

未具名资源的内部内容、计算形成的间接引用、特定输入／断线时序和 GameCube 对端实际名称输入上限，不由这份静态差异表全部保证。只有候选字节不同而未追清用途的内容，不列为已确认玩法差异；也不以这里的条目数宣称全 ROM 差异已经穷尽。

## 新增文本调用差异（2026-11-16，待统一构建验收）

原文及条件见[合并审计](TEXT_SYMBOL_AUDIT.md)。这些不是新增机制：修复使显示内容与既有事件条件相符。

| 审计项 | 原版地区差异 | 修复记录 |
| --- | --- | --- |
| A01 | 医生与琳共用 `Danke.`（谢谢），医生未解释病情。 JP／US／EU在此说明妻子不是生病；DE玛丽怀孕事件已有 `Deine Frau ist nicht krank.`（你的妻子不是生病）。 | [德版琳怀孕时医生复用答谢](BUGFIX.md#audit-a01) |
| A02 | 黑屏中的玩家独白重复玛丽通知父母、邀请回家的话。 JP及英文是玩家即将当父亲的喜悦；复用DE琳怀孕末尾已有的玩家独白。 | [德版玛丽怀孕末尾复用妻子台词](BUGFIX.md#audit-a02) |
| A03 | 切换到里克姓名及肖像后仍重复珀布利的调侃。 JP里克否认并邀请两人参加今天的婚礼；DE普通婚礼已有 `Unsere Hochzeit ist heute.`（今天是我们的婚礼）。重制版未找到对应情敌婚礼台词。 | [德版里克婚礼重复珀布利调侃](BUGFIX.md#audit-a03) |
| A04 | 一天与一周的确认共用一周文本，实际工作参数仍为一天。 其他版本分别提供一天和一周的收获确认。新增德文沿用既有收获确认句式，并参考一天浇水句中的 einen Tag（一天）；这些仅为措辞依据，实际只替换一天收获分支，三天和一周分支保持原样。 | [德版Nappy一天收获委托说成一周](BUGFIX.md#audit-a04) |
| A05 | 一亿阈值的分支仍显示10.000.000。 四版条件均为100000000，JP／US／EU显示一亿。 | [德版一亿鱼成就复用一千万台词](BUGFIX.md#audit-a05) |
| A06 | 领取 `ITEM_TOOL_HAMMER_MYTHIC` 时变量填入Mythrilhammer。 其他版本区分两种锤；本版物品表已有Mythischer Hammer（贤者锤）。 | [德版贤者锤领取提示使用秘银锤名](BUGFIX.md#audit-a06) |
| A07 | 产后继续显示纪念日、玩家生日、艾利生日，但第二选项才是正确答案。 JP产后为玩家、艾利、孩子生日；孩子称呼沿用同语言女神生日选项。 | [海外艾利产后生日选项错位](BUGFIX.md#audit-a07) |
| A08 | 产前按女神生日、纪念日、玩家生日显示，实际第三项才奖励。 JP为纪念日、玩家生日、女神生日；海外现有字符串足够恢复正确菜单。 | [海外女神产前生日选项错位](BUGFIX.md#audit-a08) |
| A09 | JP两个晴天复谈地点的已婚／未婚台词反向；DE三个分支额外显示与婚姻状态相反的话。 US／EU在实际玩家已婚条件下询问婚后生活，未婚时劝婚。 | [JP及DE卡莲婚后询问玩家婚姻状态错误](BUGFIX.md#audit-a09) |


### F-3.14节目跨赛季内容及积分（A10）

四版播放机制仍按季节、日期选择固定消息。差异在实际消息映射和正文，不是比赛机制不同：JP冬18—20错序；海外冬18缺对应成绩，冬28重复前半预告；DE第一赛季末和第二赛季多场引用了其他赛季的正文／成绩。另有海外Daisy数值错误，以及JP也存在的Sylvia累计少一分。修复逐场以日期、叙事、当次名次和累计分交叉核对；相关补文不更改实际电视输入或日历流程。见[完整范围及依据](TEXT_SYMBOL_AUDIT.md#a10)、[修复及验证状态](BUGFIX.md#audit-a10)。


## 本轮指南、剧情与电视文本差异（已完成统一构建及产物核对）

本节仅记录已纳入本轮修复的实际内容差异；相同问题四版共有时明确列出，不把补文当作新机制。详细原文集中保留在合并审计，修复及依据链接到BUGFIX。

| 审计项 | 原版差异／问题 | 修复记录 |
| --- | --- | --- |
| [B01](TEXT_SYMBOL_AUDIT.md#b01) | 出荷价格指南：按道具名称列出三个品质的鸡蛋并修正海外胡萝卜价格 | [实现与验证边界](BUGFIX.md#audit-b01) |
| [B02](TEXT_SYMBOL_AUDIT.md#b02) | 海外三版：图书馆休馆日变更方向写反 | [实现与验证边界](BUGFIX.md#audit-b02) |
| [B03](TEXT_SYMBOL_AUDIT.md#b03) | 海外三版：牛羊牧场指南说可以卖鸡 | [实现与验证边界](BUGFIX.md#audit-b03) |
| [B04](TEXT_SYMBOL_AUDIT.md#b04) | 海外三版：诊所营业时间表述错误，德版采用24小时制 | [实现与验证边界](BUGFIX.md#audit-b04) |
| [B05](TEXT_SYMBOL_AUDIT.md#b05) | 海外三版：料理指南多写一个重复选项 | [实现与验证边界](BUGFIX.md#audit-b05) |
| [B06](TEXT_SYMBOL_AUDIT.md#b06) | DE：秘银锄头误写成秘银镰刀 | [实现与验证边界](BUGFIX.md#audit-b06) |
| [B07](TEXT_SYMBOL_AUDIT.md#b07) | DE：计步器“装备”误译成“升级” | [实现与验证边界](BUGFIX.md#audit-b07) |
| [B08](TEXT_SYMBOL_AUDIT.md#b08) | 海外三版：四种作物最终收获阶段写成开花 | [实现与验证边界](BUGFIX.md#audit-b08) |
| [B09](TEXT_SYMBOL_AUDIT.md#b09) | 海外三版：疲劳段落错写成体力效果 | [实现与验证边界](BUGFIX.md#audit-b09) |
| [B10](TEXT_SYMBOL_AUDIT.md#b10) | DE：冰箱让一次“购买更多”写成“烹饪更多” | [实现与验证边界](BUGFIX.md#audit-b10) |
| [B11](TEXT_SYMBOL_AUDIT.md#b11) | 海外三版：霍安出售的种子是否随季节变化，含义写反 | [实现与验证边界](BUGFIX.md#audit-b11) |
| [B12](TEXT_SYMBOL_AUDIT.md#b12) | DE：茶叶与成品茶同名，配方原料也未区分；三处统一用20字符缩写，完整重制版名为22字符 | [实现与验证边界](BUGFIX.md#audit-b12) |
| [B13](TEXT_SYMBOL_AUDIT.md#b13) | 锤子指南：海外漏掉银锤说明，日版次数也存在问题 | [实现与验证边界](BUGFIX.md#audit-b13) |
| [B14](TEXT_SYMBOL_AUDIT.md#b14) | 房屋“两阶段扩建”误译成“建造二楼” | [实现与验证边界](BUGFIX.md#audit-b14) |
| [B15](TEXT_SYMBOL_AUDIT.md#b15) | 孵化箱随鸡舍扩建增加，误译成可以购买；修复参考重制版句式，保留GBA术语并用数字2 | [实现与验证边界](BUGFIX.md#audit-b15) |
| [B16](TEXT_SYMBOL_AUDIT.md#b16) | 德文鸡饲料制作提示把“玉米”泛化成“谷物” | [实现与验证边界](BUGFIX.md#audit-b16) |
| [C01](TEXT_SYMBOL_AUDIT.md#c01) | 海外三版：巴基尔雨天台词失去原有的晴雨对比 | [实现与验证边界](BUGFIX.md#audit-c01) |
| [C02](TEXT_SYMBOL_AUDIT.md#c02) | 海外三版：玛丽星夜祭把自己做料理写成妈妈今天做蛋糕；修复在GBA原句上改正制作者与时态 | [实现与验证边界](BUGFIX.md#audit-c02) |
| [C03](TEXT_SYMBOL_AUDIT.md#c03) | 海外三版：参赛动物确认，把“带走”写成“送给你” | [实现与验证边界](BUGFIX.md#audit-c03) |
| [C04](TEXT_SYMBOL_AUDIT.md#c04) | 海外三版：巴基尔与安娜贺卡标题把 Anna 写成 Ann | [实现与验证边界](BUGFIX.md#audit-c04) |
| [C05](TEXT_SYMBOL_AUDIT.md#c05) | DE：Lumina 的祖母误写成 Manna | [实现与验证边界](BUGFIX.md#audit-c05) |
