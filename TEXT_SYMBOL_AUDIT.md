# 四版文本与调用问题：合并审计及实施清单

基线：`427b63c4c44530b0d046a80d4b0811366afc9da4`。2026-11-16合并两批审计：共72项，E11保留，71项获准处理。原编号不变，补充13项归入B／C／D／E相应大类。

本轮先完成全部源码修复及静态核对，再以 `make -j16` 统一验证四版默认及BUGFIX产物。最终四版默认ROM均与各自baserom逐字节及SHA-1一致，四版BUGFIX构建和产物核对通过；以下按大类、小项顺序提交。验证针对完整修复集，不声称每个中间提交都单独编译过。具体范围和哈希见[本轮验收](BUGFIX.md#reviewed-text-validation-20261116)。

证据来自本工程四版原文、调用和机制的同源交叉核对，不等于独立社区验证或逐项实机复现。US＝EU表示相关原文已核对相同。引用省略部分排版空格与控制符，源码保留实际格式。

补文依次参考本作同语同类文本、重制版、日版含义。纯命名错误另行处理，不据错误符号名交换正确文本。E11不修改；B04包含用户随后确认的德文24小时制修正。

## 实施索引

| 编号 | 原编号 | 问题 | 状态 |
| --- | --- | --- | --- |
| [A01](#a01) | A01 | DE：琳怀孕时，医生错误复用琳的“谢谢” | 已修复；统一构建及产物核对通过 |
| [A02](#a02) | A02 | DE：玛丽怀孕事件末尾，玩家独白复用了玛丽的台词 | 已修复；统一构建及产物核对通过 |
| [A03](#a03) | A03 | DE：里克与卡莲婚礼，里克重复珀布利的调侃 | 已修复；统一构建及产物核对通过 |
| [A04](#a04) | A04 | DE：Nappy 接受一天收获委托，却说工作一周 | 已修复；统一构建及产物核对通过 |
| [A05](#a05) | A05 | DE：一亿条鱼成就显示一千万 | 已修复；统一构建及产物核对通过 |
| [A06](#a06) | A06 | DE：领取贤者锤时显示秘银锤名称 | 已修复；统一构建及产物核对通过 |
| [A07](#a07) | A07 | 海外三版：艾利生日，生育后的选项仍使用生育前内容 | 已修复；统一构建及产物核对通过 |
| [A08](#a08) | A08 | 海外三版：女神生日，生育前选项顺序错位 | 已修复；统一构建及产物核对通过 |
| [A09](#a09) | A09 | JP、DE：卡莲嫁给里克后，对玩家婚姻状态的对话不符 | 已修复；统一构建及产物核对通过 |
| [A10](#a10) | A10 | 四版不同程度存在：F-3.14 节目错序或错误复用 | 已修复；统一构建及产物核对通过 |
| [B01](#b01) | B01 | 出荷价格指南：按道具名称列出三个品质的鸡蛋并修正海外胡萝卜价格 | 审核修订完成；静态核对通过，待统一重验 |
| [B02](#b02) | B02 | 海外三版：图书馆休馆日变更方向写反 | 已修复；统一构建及产物核对通过 |
| [B03](#b03) | B03 | 海外三版：牛羊牧场指南说可以卖鸡 | 已修复；统一构建及产物核对通过 |
| [B04](#b04) | B04 | 海外三版：诊所营业时间表述错误，德版采用24小时制 | 已修复；统一构建及产物核对通过 |
| [B05](#b05) | B05 | 海外三版：料理指南多写一个重复选项 | 已修复；统一构建及产物核对通过 |
| [B06](#b06) | B06 | DE：秘银锄头误写成秘银镰刀 | 已修复；统一构建及产物核对通过 |
| [B07](#b07) | B07 | DE：计步器“装备”误译成“升级” | 已修复；统一构建及产物核对通过 |
| [B08](#b08) | B08 | 海外三版：四种作物最终收获阶段写成开花 | 已修复；统一构建及产物核对通过 |
| [B09](#b09) | B09 | 海外三版：疲劳段落错写成体力效果 | 已修复；统一构建及产物核对通过 |
| [B10](#b10) | B10 | DE：冰箱让一次“购买更多”写成“烹饪更多” | 已修复；统一构建及产物核对通过 |
| [B11](#b11) | B11 | 海外三版：霍安出售的种子是否随季节变化，含义写反 | 已修复；统一构建及产物核对通过 |
| [B12](#b12) | B12 | DE：茶叶与成品茶同名，配方原料也未区分 | 审核修订完成；静态核对通过，待统一重验 |
| [B13](#b13) | 补充1 | 锤子指南：海外漏掉银锤说明，日版次数也存在问题 | 已修复；统一构建及产物核对通过 |
| [B14](#b14) | 补充2 | 房屋“两阶段扩建”误译成“建造二楼” | 已修复；统一构建及产物核对通过 |
| [B15](#b15) | 补充3 | 孵化箱随鸡舍扩建增加，误译成可以购买 | 审核修订完成；静态核对通过，待统一重验 |
| [B16](#b16) | 补充4 | 德文鸡饲料制作提示把“玉米”泛化成“谷物” | 已修复；统一构建及产物核对通过 |
| [C01](#c01) | C01 | 海外三版：巴基尔雨天台词失去原有的晴雨对比 | 已获准，后续分项提交 |
| [C02](#c02) | C02 | 海外三版：玛丽星夜祭把自己做料理写成妈妈今天做蛋糕 | 已获准，后续分项提交 |
| [C03](#c03) | C03 | 海外三版：参赛动物确认，把“带走”写成“送给你” | 已获准，后续分项提交 |
| [C04](#c04) | C04 | 海外三版：巴基尔与安娜贺卡标题把 Anna 写成 Ann | 已获准，后续分项提交 |
| [C05](#c05) | C05 | DE：Lumina 的祖母误写成 Manna | 已获准，后续分项提交 |
| [C06](#c06) | C06 | US／EU：Sebastian 介绍中的 Romana 误写成 Manna | 已获准，后续分项提交 |
| [C07](#c07) | C07 | 海外三版：Gustafa 的祖先经历写成本人经历 | 已获准，后续分项提交 |
| [C08](#c08) | C08 | 海外三版：Griffin 被家人厌弃，翻成因爱家而定居 | 已获准，后续分项提交 |
| [C09](#c09) | C09 | 海外三版：Hardy 入住腾出的房屋，写成跟随 Galen 来村 | 已获准，后续分项提交 |
| [C10](#c10) | C10 | DE：儿子介绍使用了错误的姓名标记 | 已获准，后续分项提交 |
| [C11](#c11) | C11 | 海外三版：一家三口写成三个儿子 | 已获准，后续分项提交 |
| [C12](#c12) | 补充7 | Wally：马拉松教练变成赛事组织者 | 已获准，后续分项提交 |
| [C13](#c13) | 补充8 | Galen：“平时安静”变成“通常很快乐” | 已获准，后续分项提交 |
| [D01](#d01) | D01 | US／EU：Nina 缺少第一段解锁边界 | 已获准，后续分项提交 |
| [D02](#d02) | D02 | 海外三版：Griffin 缺少第二段解锁边界 | 已获准，后续分项提交 |
| [D03](#d03) | D03 | 海外三版：Nak 缺少第二段解锁边界 | 已获准，后续分项提交 |
| [D04](#d04) | D04 | DE：四本指南／贺卡的标题缺失，正文第一句占据固定标题位置 | 已获准，后续分项提交 |
| [D05](#d05) | D05 | DE：食谱中的黄油小标题缺失 | 已获准，后续分项提交 |
| [D06](#d06) | 补充9 | Wally：海外缺两段 | 已获准，后续分项提交 |
| [D07](#d07) | 补充10 | Hugh：海外缺两段 | 已获准，后续分项提交 |
| [D08](#d08) | 补充11 | Samantha：海外缺两段 | 已获准，后续分项提交 |
| [D09](#d09) | 补充12 | Galen：海外缺最后一段 | 已获准，后续分项提交 |
| [D10](#d10) | 补充13 | Daryl：海外缺两段 | 已获准，后续分项提交 |
| [E01](#e01) | E01 | JP：《まことクンちぇんじ》第24集说话人写反 | 已获准，后续分项提交 |
| [E02](#e02) | E02 | DE：同节目第2集漏否定词 | 已获准，后续分项提交 |
| [E03](#e03) | E03 | DE：同节目第13集把竖笛译成录音机 | 已获准，后续分项提交 |
| [E04](#e04) | E04 | 四版：《Card Collector Chisato》第3集卡片数量算错 | 已获准，后续分项提交 |
| [E05](#e05) | E05 | 海外三版：同节目把 S／G 牛奶译成羊奶、山羊奶 | 已获准，后续分项提交 |
| [E06](#e06) | E06 | 海外三版：同节目第1集，把将来发售写成已经发售 | 已获准，后续分项提交 |
| [E07](#e07) | E07 | 海外三版：同节目第11集，把假设写成已经发生 | 已获准，后续分项提交 |
| [E08](#e08) | E08 | 海外三版：同节目第8集标题残留 `<et>` | 已获准，后续分项提交 |
| [E09](#e09) | E09 | DE：《Mechabot Ultror Zero》第1集装饰人员多出 Yellow | 已获准，后续分项提交 |
| [E10](#e10) | E10 | DE：同节目第2集把上午写成明天 | 已获准，后续分项提交 |
| [E11](#e11) | E11 | 四版：入门节目冬21日的初始体力和翻倍说明错误 | 保留不动 |
| [E12](#e12) | E12 | DE：进阶节目冬2日，把最大体力写成10 | 已获准，后续分项提交 |
| [E13](#e13) | E13 | DE：进阶节目冬3日，把矿场写成磨坊 | 已获准，后续分项提交 |
| [E14](#e14) | E14 | DE：钓鱼节目第6集，鲣鱼仍误用金枪鱼名称 | 已获准，后续分项提交 |
| [E15](#e15) | E15 | DE：钓鱼节目第10集，把下游鱼全部说成海鱼 | 已获准，后续分项提交 |
| [E16](#e16) | E16 | DE：钓鱼节目第13集误用了另一鱼种的既有名字 | 已获准，后续分项提交 |
| [E17](#e17) | E17 | US／EU：矿场研究第9集，把“255层没有下行楼梯”写成“没有通向255层的楼梯” | 已获准，后续分项提交 |
| [E18](#e18) | 补充5 | 鱼王条件被译成“这条鱼适合做哪些菜” | 已获准，后续分项提交 |
| [E19](#e19) | 补充6 | 料理对决第2集把糖译成盐 | 已获准，后续分项提交 |
| [F01](#f01) | F01 | US：卡莲初次见面的 `You name` | 已获准，后续分项提交 |
| [F02](#f02) | F02 | JP：味噌汤食谱的锅写成 `なぺ` | 已获准，后续分项提交 |
| [F03](#f03) | F03 | 海外三版：食谱牛奶单词残缺 | 已获准，后续分项提交 |
| [F04](#f04) | F04 | DE：酱油名称出现错误字符 | 已获准，后续分项提交 |

## A．调用、选项与节目顺序

<a id="a01"></a>
### A01．DE：琳怀孕时，医生错误复用琳的“谢谢”

原编号：A01。状态：已修复；统一构建及产物核对通过。

| 版本 | 医生对应位置的原文 |
|---|---|
| JP | `キミの奥さんは病気じゃないよ。`——你的妻子不是生病。 |
| US＝EU | `Your wife is not ill.`——你的妻子不是生病。 |
| DE | `Danke.`——谢谢。 |

**依据：** DE 同一个字符串既用于琳的答谢，又用于医生解释病情。医生身份、对话位置均能确定；DE 玛丽怀孕事件已有 `Deine Frau ist nicht krank.` 可供参考。应拆开错误复用，保留琳原来的答谢。

[医生与琳的实际调用](data/scripts/de/EventScript_FamilyEvent_Ann_PregnancyDiscovery.mary.c)

<a id="a02"></a>
### A02．DE：玛丽怀孕事件末尾，玩家独白复用了玛丽的台词

原编号：A02。状态：已修复；统一构建及产物核对通过。

| 版本 | 事件末尾原文 |
|---|---|
| JP | `もうすぐ、お父さんか…うれしいな。`——快要当爸爸了……真高兴。 |
| US＝EU | `I can't believe I'm about to become a father... This is so great!`——难以相信就要当爸爸了，太好了。 |
| DE | `Meine Eltern werden so glücklich sein! … Gehen wir heim, OK?`——我的父母会很开心……我们回家吧？ |

**依据：** DE 将玛丽“通知父母、邀请玩家回家”的整段话再次用于玩家独白，人物身份不符。不是单纯标签命名问题。

[末尾独白与复用关系](data/scripts/de/EventScript_FamilyEvent_Mary_PregnancyDiscovery.mary.c)

<a id="a03"></a>
### A03．DE：里克与卡莲婚礼，里克重复珀布利的调侃

原编号：A03。状态：已修复；统一构建及产物核对通过。

| 版本 | 里克应说的内容 |
|---|---|
| JP | `そ…そんなわけないだろ？とにかく、結婚式は今日だから、２人とも来てくれよ。`——才、才不是呢。总之今天举行婚礼，你们两个都来吧。 |
| US＝EU | `(Ha!?) What?! Popuri! Anyway, our wedding is today, so see you there!` |
| DE | `Also meinst du, es ist Popuri zu verdanken, dass du heiratest?`——所以你认为，能结婚是多亏了珀布利？ |

**依据：** 同一句 DE 文本先由珀布利说，再切换里克肖像和姓名重复一次。缺的是里克的否认与邀请，原有文本属于珀布利。

[婚礼对话与肖像切换](data/scripts/de/EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_CeremonyWithPopuriIntroduction.mary.c)

<a id="a04"></a>
### A04．DE：Nappy 接受一天收获委托，却说工作一周

原编号：A04。状态：已修复；统一构建及产物核对通过。

| 版本 | 一天委托的确认原文 |
|---|---|
| JP | `わかったの。収穫を１日やるの。`——知道了，收获一天。 |
| US＝EU | `Got it. I'll harvest for 1 day, budum.` |
| DE | `Verstanden. Ich ernte eine Woche für dich, budum.`——知道了，我为你收获一周。 |

**依据：** 一天分支实际传入 `HARVEST_SPRITE_WORK_DAYS_ONE_DAY`，DE 只是错误共用一周的确认文本，工作时长本身没有变。

[委托参数与文本调用](data/scripts/de/EventScript_NPCEvent_Nappy_DialogueAndWorkChoices.mary.c)

<a id="a05"></a>
### A05．DE：一亿条鱼成就显示一千万

原编号：A05。状态：已修复；统一构建及产物核对通过。

| 版本 | 原文数字 |
|---|---|
| JP | `１００００００００匹` |
| US＝EU | `100,000,000 fish!` |
| DE | `10.000.000 Fische` |

**依据：** 实际条件是 `GetTotalFishCaught() >= 100000000`，并设置独立的一亿成就标志；DE 错误复用一千万文本。

[成就阈值与调用](data/scripts/de/EventScript_AchievementEvent_Fishing_MilestoneReward.mary.c)

<a id="a06"></a>
### A06．DE：领取贤者锤时显示秘银锤名称

原编号：A06。状态：已修复；统一构建及产物核对通过。

| 版本 | 原文 |
|---|---|
| JP | `賢者のハンマー` |
| US＝EU | `Mythic Hammer` |
| DE | `Mythrilhammer`——秘银锤。 |

**依据：** 订单实际给予 `ITEM_TOOL_HAMMER_MYTHIC`；DE 道具文本已有正确的 `Mythischer Hammer`，可以直接沿用，不需要另造译名。

[锻冶屋领取分支](data/scripts/de/EventScript_ShopEvent_Blacksmith_OrderCounter.mary.c) · [已有德文道具名称](data/text/de/item_1.cc)

<a id="a07"></a>
### A07．海外三版：艾利生日，生育后的选项仍使用生育前内容

原编号：A07。状态：已修复；统一构建及产物核对通过。

| 版本 | 生育后显示的三个选项，按实际顺序 |
|---|---|
| JP | `自分の誕生日`／`エリィの誕生日`／`{Baby}の誕生日`——玩家／艾利／孩子的生日。 |
| US＝EU | `Our anniversary`／`My birthday`／`Your birthday`——结婚纪念日／玩家生日／艾利生日。 |
| DE | `Unser Hochzeitstag`／`Mein Geburtstag`／`Dein Geburtstag`——同上。 |

**依据：** 生育后的程序把**第二项**判为正确并增加好感，但海外第二项显示“我的生日”；选第三项“你的生日”反而扣好感。应修正产后菜单对应内容，不能改变本来正确的判定位置。

[海外菜单及结果分支](data/scripts/us/EventScript_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice.mary.c)

<a id="a08"></a>
### A08．海外三版：女神生日，生育前选项顺序错位

原编号：A08。状态：已修复；统一构建及产物核对通过。

| 版本 | 生育前实际显示顺序 |
|---|---|
| JP | `結婚記念日`／`自分の誕生日`／`女神様の誕生日` |
| US＝EU | `Your birthday`／`Our anniversary`／`My birthday` |
| DE | `Dein Geburtstag`／`Unser Hochzeitstag`／`Mein Geburtstag` |

**依据：** 程序把第三项作为女神生日的正确答案，海外第三项却是玩家生日。**生育后的菜单对应关系正确**，因此不能把相关指针全局交换。

[女神生日两套菜单](data/scripts/us/EventScript_FamilyEvent_HarvestGoddess_EveningDateChoice.mary.c)

<a id="a09"></a>
### A09．JP、DE：卡莲嫁给里克后，对玩家婚姻状态的对话不符

原编号：A09。状态：已修复；统一构建及产物核对通过。

| 版本 | 原文与实际情况 |
|---|---|
| JP | 对已婚玩家说 `どうして結婚しないの？`——为什么不结婚？对未婚玩家说 `奥さんとは上手くいってる？`——和妻子相处得好吗？ |
| US＝EU | 已婚：`How are you liking married life...?`；未婚：`Why don't you get married, {Player}?`，对应正确。 |
| DE | 同时存在 `Warum heiratest du nicht, {Player}?` 和 `Wie gefällt dir das Eheleben...?`；部分复谈分支连续调用两句，另有已婚分支仍调用劝婚文本。 |

**依据：** 核对的是实际婚姻条件、婚礼完成标志和消息调用，不是根据变量名猜测。JP 是对应关系颠倒；DE 还存在多余调用，需要分别处理具体分支。

[JP 条件](data/scripts/jp/EventScript_NPCEvent_Karen_DialogueAndGiftResponses.mary.c) · [DE 多次消息调用](data/scripts/de/EventScript_NPCEvent_Karen_DialogueAndGiftResponses.mary.c)

<a id="a10"></a>
### A10．四版不同程度存在：F-3.14 节目错序或错误复用

原编号：A10。状态：已修复；统一构建及产物核对通过。

先列实际内容，不把最终重排方案当作已确认修法：

| 日期 | JP 原文摘要 | US＝EU 原文摘要 | DE 原文摘要 |
|---|---|---|---|
| 冬18 | 第八战预告：`第８戦はあさってです。`——第八战后天举行。 | `The 8th match will be the day after tomorrow.` | `Der dritte Wettkampf findet übermorgen statt.`——**第三战**后天举行。 |
| 冬19 | 第二部分预告：`第８戦はあしたです。`——第八战明天举行。 | 第一部分预告：`The eighth match will be the day after tomorrow.` | 第一部分预告：`Der achte Wettkampf findet übermorgen statt.` |
| 冬20 | `第７戦の結果をお伝えします。`——播报**第七战结果**。 | 第二部分预告，仍说第八战“后天”。 | 第二部分预告，仍说第八战“后天”。 |
| 夏19 | 第三战预告：`第３戦はあさってです。` | `The third match will be the day after tomorrow.` | `Die Ergebnisse des 2. F-3.14 MGP Rennens sind:`——变成**第二战成绩**。 |
| 夏09 | 最终战前三名：`すみれ／デイジー／コスモス` | `Sylvia / Daisy / Cosmos` | `Licorice / Sylvia / Lupinus`，复用了另一轮最终战结果。 |

**依据：** 对照实际日期分派、冬21／22的第八战结果，以及前后比赛积分和人物介绍。既有调用错误，也有文本本身的日期、场次错误，不能只改标签名。

[JP 节目](data/scripts/jp/EventScript_TV_F314MGrandPrix.mary.c) · [DE 节目](data/scripts/de/EventScript_TV_F314MGrandPrix.mary.c)



**同根因扩展核对与实现（仍未构建）：**

- 按每版四季各30天的实际分派，逐一核对120个播出位置，不凭 `RaceXX` 标签判断内容。
- JP冬18／19／20恢复为第七战成绩后半、第八战预告前半／后半；海外冬18补回正确成绩。US／EU沿用既有英文成绩格式，DE采用原本错放在另一赛季的德文成绩措辞。
- DE第一赛季第九战正文和成绩、最终战正文和成绩，以及第二赛季第一至第八战正文和成绩，存在跨赛季复用／替换。已按JP对应场次恢复；同版已有句式、参赛者译名、表格格式优先复用，缺失叙事按JP含义补齐，不把“前三名相同”当作整篇内容可复用的依据。
- DE第二赛季第二、第五、第七战预告误介绍第三赛季才出现的Eucomyth，恢复同语已有Amaryllis预告；第九战预告缺少Daisy的部分沿用本版第二战已有介绍。海外冬28恢复最终战预告后半，不再重复前一天内容。
- 海外第一赛季第八战Daisy累计32＋6误写39，改38；US／EU第二赛季第八战第三名Daisy误写加6分，改为与累计分一致的4分。
- 第三赛季第七战Sylvia原累计7分、当次加2分，但JP及海外后续成绩都写成8分。四版该场及下一场累计改9，后两场改11；名次不受影响。依据是每场已显示的得分逐项累加，不把JP错误数字当作正确基准。
- DE缺少场次数字的第三／第四战等标题补回数字。单纯人物译名差异不改；节目结果仍是固定文本，未新增实时积分机制。

以上是A10内部同类遗漏的补齐。120日期、30场成绩已做源码层对应核对；默认分支有效源码仍须保持基线，最终脚本产物及指针尚待统一构建验收。

## B．指南与实际机制

<a id="b01"></a>
### B01．出荷价格指南：按道具名称列出三个品质的鸡蛋并修正海外胡萝卜价格

原编号：B01。状态：审核修订完成；静态核对通过，待统一重验。

| 对象 | JP | US＝EU | DE | 实际价格 |
|---|---|---|---|---|
| 好品质鸡蛋 | `いい品質の卵 ５０Ｇ` | 没有对应品质行 | 没有对应品质行 | 60G |
| 很高品质鸡蛋 | `かなりいい品質の卵 ５０Ｇ` | 没有对应品质行 | 没有对应品质行 | 80G |
| 胡萝卜 | `にんじん １２０Ｇ` | `Carrot 60G` | `Karotte 60G` | 120G |
| 金蛋 | 没有对应行 | `Golden Egg 150G` | `Goldenes Ei 150G` | 100G |

**依据：** `gProductInfo` 的实际价格。应修指南文字，不改价格表迎合错误说明。

[JP 指南](data/text/jp/reference_guide/sell_price.cc) · [US 指南](data/text/us/reference_guide/sell_price.cc) · [实际数据](src/item.cc)

**用户决定（审核修订）：** 四版均采用对应道具的普通、好、高品质鸡蛋名称，分别对应50／60／80G。S／M／L只是在讨论时说明等级，不是显示名称；海外指南以这三种蛋替换原普通蛋、温泉蛋和金蛋三行。胡萝卜修为120G。英文采用 `Regular Quality Egg`、`Good Quality Egg`、`High Quality Egg`，德文采用道具名称 `Gewöhnliches Ei`、`Hochwertiges Ei`、`Sehr hochw. Ei`；日文保留三个实际道具名称。

<a id="b02"></a>
### B02．海外三版：图书馆休馆日变更方向写反

原编号：B02。状态：已修复；统一构建及产物核对通过。

- **JP：** `お休みが月曜日から木曜日に変わりました。`——从星期一改为星期四。
- **US＝EU：** `Our day off is changing from Thursday to Monday.`——星期四改星期一。
- **DE：** `Unser freier Tag ist nun Montag anstatt Donnerstag.`——现在星期一休息，不再是星期四。

**依据：** 通知在玛丽与格雷结婚后送出，婚后营业告示明确是星期四休馆。

[通知原文](data/text/us/reference_guide/notice_marys_library_day_off_change.cc) · [婚前后告示](data/scripts/jp/EventScript_LocationInteraction_InspectTownNorthLibraryHoursSign.mary.c)

<a id="b03"></a>
### B03．海外三版：牛羊牧场指南说可以卖鸡

原编号：B03。状态：已修复；统一构建及产物核对通过。

- **JP：** `牛、羊を売ることもできる。`——也能出售牛、羊。
- **US＝EU：** `or sell your Chickens.`
- **DE：** `oder deine Hühner verkaufen.`——出售你的鸡。

**依据：** 此处是牛羊商店，实际菜单出售牛、羊，不出售鸡。

[指南](data/text/us/reference_guide/yodel_farm.cc) · [商店处理](src/scene_yodel_ranch_shop.cc)

<a id="b04"></a>
### B04．海外三版：诊所营业时间表述错误，德版采用24小时制

原编号：B04。状态：已修复；统一构建及产物核对通过。

- **JP：** `午前９時～午後４時`。
- **US＝EU：** `9AM-4AM`。
- **DE：** `9-4 Uhr`。

**依据：** 营业告示是09:00至16:00，英文末尾应为下午。DE 表达不够明确，但没有英文这种显式的 AM 错误。用户随后确认德版也按24小时制修为9–16 Uhr。

[指南](data/text/us/reference_guide/clinic.cc) · [营业告示](data/scripts/jp/EventScript_LocationInteraction_InspectClinicBusinessHoursSign.mary.c)

<a id="b05"></a>
### B05．海外三版：料理指南多写一个重复选项

原编号：B05。状态：已修复；统一构建及产物核对通过。

- **JP：** `レシピ通りにつくる`／`アレンジしてみる`／`やっぱりやめる`——按食谱／尝试调整／取消。
- **US＝EU：** `Follow the recipe.`／`Improvise on recipe.`／`Start again.`／`Start over.`
- **DE：** `Rezept befolgen.`／`Mit Rezept improvisieren.`／`Erneut beginnen.`／`Erneut beginnen.`

**依据：** 食材齐全时的实际调用只有三个选项：`FollowRecipe`、`ImproviseRecipe`、`MakeAnotherRecipe`。指南重复列出返回项，不应新增第四个程序选项。

[指南](data/text/us/reference_guide/how_to_cook.cc) · [实际菜单调用](src/scene_cooking.cc)

<a id="b06"></a>
### B06．DE：秘银锄头误写成秘银镰刀

原编号：B06。状态：已修复；统一构建及产物核对通过。

- **JP：** `ミスリルのクワ`——秘银锄头。
- **US＝EU：** `Mystrile Hoe`。
- **DE：** `Mythrilsichel`——秘银镰刀。

**依据：** 所在段落描述一次耕前方六格土地，是锄头，不是镰刀。

[工具指南](data/text/de/reference_guide/using_tools_1.cc)

<a id="b07"></a>
### B07．DE：计步器“装备”误译成“升级”

原编号：B07。状态：已修复；统一构建及产物核对通过。

- **JP：** `装備していなくてもいいんだけど、装備して使っても歩数は増やせる。`——不必装备，装备使用也能增加步数。
- **US＝EU：** `It doesn't even have to be equipped, but it works equipped as well.`
- **DE：** `Dieser muss nicht einmal aufgerüstet werden, aber wenn du ihn aufrüstest, funktioniert er auch.`——不必升级，升级后也能用。

**依据：** `aufgerüstet` 指升级；这里的操作是装备计步器，程序没有该段所说的计步器升级。

[计步器段落](data/text/de/reference_guide/using_tools_1.cc)

<a id="b08"></a>
### B08．海外三版：四种作物最终收获阶段写成开花

原编号：B08。状态：已修复；统一构建及产物核对通过。

- **JP：** 番茄、玉米、菠萝、青椒对应 `種－→①－→②－→③－→実`。
- **US＝EU：** 对应末尾为 `Flowers`。
- **DE：** 对应末尾为 `Blüte`。

**依据：** 这些行描述上述作物结成果实的收获阶段。修复只涉及四种作物，不能把花卉行中的 Flowers／Blüte 一并替换。

[四版对应的作物指南](data/text/us/reference_guide/seasonal_crops.cc)

<a id="b09"></a>
### B09．海外三版：疲劳段落错写成体力效果

原编号：B09。状态：已修复；统一构建及产物核对通过。

- **JP：** `食べた物によって回復量は変化。増える場合もある`——视食物而变化，也可能增加疲劳。
- **US＝EU：** `Some foods will deplete Stamina.`——有些食物会消耗体力。
- **DE：** `Manche Nahrungsmittel verringern die Ausdauer.`——有些食物降低体力。

**依据：** 当前小节讲疲劳，海外复制了体力小节的含义。不是需要修改食物实际恢复字段。

[体力／疲劳指南](data/text/us/reference_guide/stamina_and_fatigue.cc)

<a id="b10"></a>
### B10．DE：冰箱让一次“购买更多”写成“烹饪更多”

原编号：B10。状态：已修复；统一构建及产物核对通过。

- **JP：** `『冷蔵庫』があれば、一度にたくさん買える。`
- **US＝EU：** `You can buy more at one time if you have a Refrigerator.`
- **DE：** `Du kannst mehr auf einmal kochen, wenn du einen Kühlschrank hast.`

**依据：** 杂货店购买说明中，德文 `kochen` 是烹饪，原意是购买。

[杂货店指南](data/text/de/reference_guide/supermarket.cc)

<a id="b11"></a>
### B11．海外三版：霍安出售的种子是否随季节变化，含义写反

原编号：B11。状态：已修复；统一构建及产物核对通过。

- **JP：** `季節によって売っている種の種類は変わらない。`——不会随季节变化。
- **US＝EU：** `Different Seeds are sold in different seasons.`——不同季节卖不同种子。
- **DE：** `In verschiedenen Jahreszeiten werden verschiedene Samen verkauft.`——同上。

**依据：** 商店实现连续加入七种种子，没有对这些种子进行季节筛选。US／EU 附近还有一条孤立的 `different seasons.` 残句，可一并核对排版。

[指南](data/text/us/reference_guide/wons_shop.cc) · [商品加入逻辑](src/scene_won_shop.cc)

<a id="b12"></a>
### B12．DE：茶叶与成品茶同名，配方原料也未区分

原编号：B12。状态：审核修订完成；静态核对通过，待统一重验。

- **JP：** 必需材料为 `リラックス茶の葉`。
- **US＝EU：** `Relaxation Tea Leaves`。
- **DE：** `Entspannungtee`——松弛茶。

**依据：** 原版茶叶与成品茶均称Entspannungstee。统一将茶叶道具名、说明首行和指南原料写为 `Entspann.-Teeblätter`（20字符）；这是为适配GBA料理列表20格宽度采用的界面缩写，非官方简称。完整名称 `Entspannungsteeblätter`（22字符）来自重制版德文道具文本。成品茶名称保持原样。

[配方](data/text/de/reference_guide/cookbook_4.cc) · [德文茶与茶叶](data/text/de/item_2.cc)


**显示约束：** 料理列表的道具名区域宽20格，单字节字符按8像素推进；22字符全名会被截掉末尾 `er`。说明及指南统一采用同一缩写，避免三个入口出现不同名称。仅修正DE；JP、US、EU没有原料与成品同名问题。

<a id="b13"></a>
### B13．锤子指南：海外漏掉银锤说明，日版次数也存在问题

原编号：补充1。状态：已修复；统一构建及产物核对通过。

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

**拟纳入：**海外恢复铜、银锤的正确区分；日版也修正农场大石的次数。此项是指南正文，与之前你否决修改的银锤物品说明分开。

来源：[蓄力等级](src/player_actor.cc:29567)、[效果表](src/animal_data.cc:93)、[石块耐久处理](src/field.cc:209)、[日文指南](data/text/jp/reference_guide/using_tools_1.cc)。

<a id="b14"></a>
### B14．房屋“两阶段扩建”误译成“建造二楼”

原编号：补充2。状态：已修复；统一构建及产物核对通过。

| 版本 | 原文 |
|---|---|
| JP | “２段階まで増築できる。”——可以扩建两阶段。 |
| US／EU | “You can also build a second floor.”——还可以建造二楼。 |
| DE | “Du kannst auch ein zweites Stockwerk bauen.”——同样是建造二楼。 |

代码维护的是原始房屋、第一次扩建、第二次扩建三个等级；海外文本把“阶段”译成了“楼层”。同一本海外指南后面还写着扩建两次后可以改造窗户、狗屋、信箱，前后也不一致。

**拟纳入：**修正 US／EU／DE 的这句说明，不改扩建机制。

来源：[木工指南](data/text/us/reference_guide/woodcutters_house.cc)、[房屋扩建等级](src/farm_house.cc:171)。

<a id="b15"></a>
### B15．孵化箱随鸡舍扩建增加，误译成可以购买

原编号：补充3。状态：审核修订完成；静态核对通过，待统一重验。

| 版本 | 原文 |
|---|---|
| JP | “ふか箱も２個に増える。”——孵化箱也增加到两个。 |
| US／EU | “Enables you to buy 2 Incubators.”——使你能够购买两个孵化箱。 |
| DE | “Ermöglicht dir, 2 Brutkästen zu kaufen.”——同样说可以购买。 |

`GetIncubatorCapacity()` 直接根据鸡舍扩建等级返回1或2；这里没有购买孵化箱的步骤。

**拟纳入：**海外三版改为扩建后拥有两个孵化箱。

来源：[指南原文](data/text/de/reference_guide/woodcutters_house.cc)、[孵化箱数量](src/coop.cc:83)。

**补文来源及适配：** 参考重制版US `msg_Book.txt:1575` 的 `You will have two Breeding Bins.`（你将拥有两个繁殖箱），以及DE `msg_Book.txt:1618` 的 `Die Anzahl deiner Zuchtkisten wird sich erhöhen.`（你的繁殖箱数量将增加）。保留GBA术语 `Incubator`／`Brutkasten`，德文复数为 `Brutkästen`，数字均用阿拉伯数字 `2`。德文补足的数量以JP原文和 `GetIncubatorCapacity()` 为据。海外修复句分别为 `You will have 2 Incubators.` 和 `Die Anzahl deiner Brutkästen wird sich auf 2 erhöhen.`；不添加“原先1个”的比较句。

[重制版英文](../SoSFoMTTextDump/SoSFoMTTextDump/US/msg_Book.txt:1575) · [重制版德文](../SoSFoMTTextDump/SoSFoMTTextDump/DE/msg_Book.txt:1618)

<a id="b16"></a>
### B16．德文鸡饲料制作提示把“玉米”泛化成“谷物”

原编号：补充4。状态：已修复；统一构建及产物核对通过。

| 版本 | 原文 |
|---|---|
| JP | “水車小屋にとうもろこしを投げ込むことでも手に入る。”——把玉米投入水车小屋也能得到。 |
| US／EU | “…Feed by putting Corn in the Water Wheel.”——把玉米放入水车获得饲料。 |
| DE | “Wenn du Getreide in das Wasserrad gibst, bekommst du auch Hühnerfutter.”——把谷物放入水车也能得到鸡饲料。 |

四版脚本都明确要求**未包装的玉米**，消耗一个后增加30份鸡饲料。`Getreide` 本身能涵盖玉米，但作为操作说明过于宽泛，会让玩家误以为其他谷物也可以。

**拟纳入：**仅 DE，把材料明确写成玉米；不改其他句意。

来源：[德文指南](data/text/de/reference_guide/poultry_farm.cc)、[水车材料判断](data/scripts/de/EventScript_LocationInteraction_Farm_UseWaterMill.mary.c:28)。


## C．人物、动作与剧情含义

<a id="c01"></a>
### C01．海外三版：巴基尔雨天台词失去原有的晴雨对比

原编号：C01。状态：已获准，后续分项提交。

- **JP 雨天：** `日に当たっているだけじゃ、かれてしまう。`——光晒太阳也会枯萎。
- **US＝EU：** `They need sunshine or they wither away...`——需要阳光，否则会枯萎。
- **DE：** `Sie brauchen Sonne oder sie gehen ein...`——同上。

**依据：** JP 晴天讲“不晒太阳会萎蔫”，雨天讲“只晒太阳也不行”；海外晴雨共用晴天文本，雨水的重要性被反转。正常的晴天句子应保留。

[晴雨分支](data/scripts/jp/EventScript_NPCEvent_Basil_DialogueAndGiftResponses.mary.c)

<a id="c02"></a>
### C02．海外三版：玛丽星夜祭把自己做料理写成妈妈今天做蛋糕

原编号：C02。状态：已获准，后续分项提交。

- **JP：** `ウチではママがケーキとかを作ってたのよ。…今日はママ直伝の料理を作ったんだ。`——以前在娘家妈妈会做蛋糕；今天自己做了妈妈亲传的料理。
- **US＝EU：** `Today my mom made some cake for the Starry Night Festival.`
- **DE：** `Heute hat meine Mutter Kuchen für das Sternennachtfestival gemacht.`

**依据：** 时间和料理制作者均改变。婚后有无孩子共用这段话本身合理，不需要因此拆掉正常共用。

[星夜祭对应台词](data/scripts/jp/EventScript_FestivalEvent_StarryNight_WithSpouseAndChild.mary.c)

<a id="c03"></a>
### C03．海外三版：参赛动物确认，把“带走”写成“送给你”

原编号：C03。状态：已获准，后续分项提交。

- **JP：** `わかった。じゃあ、その鶏／牛／羊を連れていくよ。`——知道了，那我把这只鸡／牛／羊带走。
- **US＝EU：** `It's a deal, then. I'll bring it to you.`
- **DE：** `Ok, abgemacht. Ich werde es dir bringen.`

**依据：** 调用发生在确认参赛、接走动物时，不是比赛后归还。海外三种动物共用一句不是问题，问题是方向写反。

[参赛确认原文](data/text/jp/animal_festival_selection.cc) · [调用位置](src/animal_festival_selection.cc)

<a id="c04"></a>
### C04．海外三版：巴基尔与安娜贺卡标题把 Anna 写成 Ann

原编号：C04。状态：已获准，后续分项提交。

- **JP：** `バジルとアンナからの年賀状`。
- **US＝EU：** 标题 `Card From Basil and Ann`，署名却是 `Basil and Anna`。
- **DE：** 标题 `Karte von Basil und Ann`，署名是 `Basil und Anna`。

**依据：** 同一封信正文署名、发送者身份均为 Anna。文件身份不应跟着错标题改成 Ann。

[贺卡标题与署名](data/text/us/reference_guide/new_year_card_basil_and_anna.cc)

<a id="c05"></a>
### C05．DE：Lumina 的祖母误写成 Manna

原编号：C05。状态：已获准，后续分项提交。

- **JP：** `お屋敷に住むロマナの孫娘。`——住在宅邸的 Romana 的孙女。
- **US＝EU：** `Romana's spoiled but shy granddaughter.`
- **DE：** `Mannas verwöhnte aber schüchterne Enkelin.`

**依据：** 人物关系明确，DE 姓名错误。

[Lumina 介绍](data/text/de/reference_guide/ngc_awl_profiles_lumina.cc)

<a id="c06"></a>
### C06．US／EU：Sebastian 介绍中的 Romana 误写成 Manna

原编号：C06。状态：已获准，后续分项提交。

- **JP：** `いつもロマナのそばにいたいのだが、うるさがられるので…`——想总待在 Romana 身边，但会被嫌烦。
- **US＝EU：** `…but this gets on Manna's nerves…`
- **DE：** `…aber das geht Romana auf die Nerven…`

**依据：** JP／DE 及本段前后的人物关系一致，英文中途换成了另一人。

[Sebastian 介绍](data/text/us/reference_guide/ngc_awl_profiles_sebastian.cc)

<a id="c07"></a>
### C07．海外三版：Gustafa 的祖先经历写成本人经历

原编号：C07。状态：已获准，后续分项提交。

- **JP：** `宮廷に代々仕えていた宮廷詩人の末裔。`——世代服务宫廷的宫廷诗人的后裔。
- **US＝EU：** `He used to serve at the court of a distant empire.`
- **DE：** `Er hat am Hof eines fernen Königreiches gedient.`

**依据：** “后裔”被改成“本人曾供职”，身世主体不同，并非单纯译名差异。

[Gustafa 介绍](data/text/jp/reference_guide/ngc_awl_profiles_gustafa.cc)

<a id="c08"></a>
### C08．海外三版：Griffin 被家人厌弃，翻成因爱家而定居

原编号：C08。状态：已获准，后续分项提交。

- **JP：** `家族に愛想をつかされ、一人放浪の末…`——被家人厌弃，独自漂泊后……
- **US＝EU：** `…love for his family caused him to settle in Forget-me-not Valley.`
- **DE：** `…die Liebe zu seiner Familie hat ihn dazu veranlasst, sich … niederzulassen.`

**依据：** 家庭关系和定居原因被翻成相反含义。此项与后面的解锁标记遗漏是两个独立问题。

[Griffin 介绍](data/text/jp/reference_guide/ngc_awl_profiles_griffin.cc)

<a id="c09"></a>
### C09．海外三版：Hardy 入住腾出的房屋，写成跟随 Galen 来村

原编号：C09。状态：已获准，后续分项提交。

- **JP：** `ニーナの死後、ガリが引っ越したのでその後に住み着くことになる。`——Nina 去世、Galen 搬走后，他住进原来的地方。
- **US＝EU：** `He followed Galen to Forget-me-not Valley after Nina's death.`
- **DE：** `Er ist Galen nach Ninas Tod ins Vergissmeinnicht-Tal gefolgt.`

**依据：** 搬迁关系不同：接替原住处被误译为跟随某人迁来。

[Hardy 介绍](data/text/jp/reference_guide/ngc_awl_profiles_hardy.cc)

<a id="c10"></a>
### C10．DE：儿子介绍使用了错误的姓名标记

原编号：C10。状态：已获准，后续分项提交。

- **JP：** `<cp>の息子。`
- **US＝EU：** `<cp>'s son.`
- **DE：** `<cs>s Sohn.`

**依据：** `<cp>` 是联机主角，`<cs>` 是其儿子。DE 当前变成“儿子自己的儿子”，应修正文标记，标题中的 `<cs>` 则正确。

[儿子介绍](data/text/de/reference_guide/ngc_awl_profiles_child.cc)

<a id="c11"></a>
### C11．海外三版：一家三口写成三个儿子

原编号：C11。状态：已获准，后续分项提交。

- **JP：** `嫁さんと息子の３人で暮らしている。`——与妻子、儿子三人一起生活。
- **US＝EU：** `He lives with his wife and 3 sons.`
- **DE：** `Er lebt mit seiner Frau und 3 Söhnen.`

**依据：** “本人＋妻子＋儿子，共三人”误译成“三个儿子”。

[联机主角介绍](data/text/us/reference_guide/ngc_awl_profiles_player.cc)


<a id="c12"></a>
### C12．Wally：马拉松教练变成赛事组织者

原编号：补充7。状态：已获准，后续分项提交。

| 版本 | 原文 |
|---|---|
| JP | “町の会社でマラソンの監督をしている。”——在城里的公司担任马拉松教练。 |
| US／EU | “He organizes a marathon in town…”——他在城里组织马拉松比赛。 |
| DE | “Er organisiert einen Marathonlauf in der Stadt…”——同样是组织比赛。 |

这是职业含义改变，不是角色译名差异。日文后文还明确交代他退役后成为教练。

**拟纳入：**海外三版修正职业描述。

来源：[日文介绍](data/text/jp/reference_guide/ngc_awl_profiles_wally.cc)、[英文介绍](data/text/us/reference_guide/ngc_awl_profiles_wally.cc)、[德文介绍](data/text/de/reference_guide/ngc_awl_profiles_wally.cc)。

<a id="c13"></a>
### C13．Galen：“平时安静”变成“通常很快乐”

原编号：补充8。状态：已获准，后续分项提交。

| 版本 | 原文 |
|---|---|
| JP | “頑固で気難しいが、普段はおとなしい。”——固执、难相处，但平时很安静。 |
| US／EU | “He can be quite stubborn but is usually happy.”——可能很固执，但通常很快乐。 |
| DE | “Er kann ziemlich störrisch sein, sonst eine Frohnatur.”——可能很固执，其余时候是个乐天派。 |

`おとなしい` 在这里描述安静、温和的性格，不是快乐或乐天。应修正这个词义，不把妻子去世后的悲伤状态提前套到整个介绍。

来源：[日文介绍](data/text/jp/reference_guide/ngc_awl_profiles_galen.cc)、[英文介绍](data/text/us/reference_guide/ngc_awl_profiles_galen.cc)、[德文介绍](data/text/de/reference_guide/ngc_awl_profiles_galen.cc)。

**四、确认缺失的完整人物介绍正文**

这部分也补入校对清单，但与上面明确错译分开：**能确认海外缺了正文，不能据此确定当年是漏译还是主动删节。** 若要恢复，需要补正文及对应解锁标记，单补标记没有作用。

## D．指南结构与缺失正文

<a id="d01"></a>
### D01．US／EU：Nina 缺少第一段解锁边界

原编号：D01。状态：已获准，后续分项提交。

| JP | US＝EU | DE |
|---|---|---|
| `やさしく暖かいおばあちゃん。` → **`<111>`** → 爱丈夫的段落 → `<112>` | `A warm and loving woman.` → **没有 `<111>`** → `She loves her stubborn old husband more than anything.` → `<112>` | `Warme, liebevolle Frau.` → **`<111>`** → 对应爱丈夫段落 → `<112>` |

**依据：** 后续正文仍存在，但 US／EU 少了控制其显示条件的边界，导致提前可见。

[Nina 原文](data/text/us/reference_guide/ngc_awl_profiles_nina.cc)

<a id="d02"></a>
### D02．海外三版：Griffin 缺少第二段解锁边界

原编号：D02。状态：已获准，后续分项提交。

- **JP：** `歌い始める。` → **`<222>`** → 身世段落。
- **US＝EU：** `where he often plays.` → **没有 `<222>`** → `He used to wander, but…`
- **DE：** `dann oft Gitarre.` → **没有 `<222>`** → `Er ist viel gereist, aber…`

**依据：** 后一段身世仍存在，却失去独立解锁限制。

[Griffin 原文](data/text/us/reference_guide/ngc_awl_profiles_griffin.cc)

<a id="d03"></a>
### D03．海外三版：Nak 缺少第二段解锁边界

原编号：D03。状态：已获准，后续分项提交。

- **JP：** 向矿石镇传递信息的段落 → **`<332>`** → `黄色い服を着ている。`
- **US＝EU：** `friends in Mineral Town.` → **没有 `<332>`** → `He likes wearing yellow.`
- **DE：** 对应信息段落 → **没有 `<332>`** → `Er trägt gerne gelb.`

**依据：** 同样是正文保留、控制显示的边界丢失。上述三项的 `<NNN>` 会被读取器用于等级判断，不是普通装饰文本。

[Nak 原文](data/text/us/reference_guide/ngc_awl_profiles_nak.cc) · [边界读取逻辑](src/scene_reference_page.cc)

<a id="d04"></a>
### D04．DE：四本指南／贺卡的标题缺失，正文第一句占据固定标题位置

原编号：D04。状态：已获准，后续分项提交。

| 图书 | JP 标题 | US＝EU 标题 | DE 当前标题 |
|---|---|---|---|
| Samantha | `サンさんの紹介` | `Introducing Samantha` | `Wird meist "Sam" genannt,`——通常称为 Sam， |
| Patrick | `パサランさんの紹介` | `Introducing Patrick` | `Kasseys Zwillingsbruder,`——Kassey 的孪生兄弟， |
| Hardy | `バドックさんの紹介` | `Introducing Hardy` | `Hardy, Romanas Arzt, kommt`——Hardy，Romana 的医生，来到…… |
| Gray 贺卡 | `グレイからの年賀状` | `Gray's New Year Card` | `Frohes Neues Jahr!`——新年快乐！ |

**依据：** 第一行会固定显示，后面的正文才滚动。DE 前三本甚至把一句话拆在标题与正文之间。恢复标题时，原首句要回到正文，不能删掉。

[例：Samantha](data/text/de/reference_guide/ngc_awl_profiles_samantha.cc) · [例：Gray 贺卡](data/text/de/reference_guide/new_year_card_gray.cc)

<a id="d05"></a>
### D05．DE：食谱中的黄油小标题缺失

原编号：D05。状态：已获准，后续分项提交。

- **JP：** `☆バターの作り方`，随后是牛奶、搅拌器。
- **US＝EU：** `☆Butter`，随后是 Milk、Mixer。
- **DE：** 分隔线后直接是 `·Nötige Zutaten`／`Milch`，没有黄油标题。

**依据：** 配方正文完整，但标题丢失；后面的 `☆Butterbrot` 是下一道菜，不能当作本段标题。

[食谱对应段落](data/text/de/reference_guide/cookbook_2.cc)


<a id="d06"></a>
### D06．Wally：海外缺两段

原编号：补充9。状态：已获准，后续分项提交。

JP：

> かつては有名なマラソン選手だったが、足を患い引退、その後監督になる。根っからのスポーツマン。
>
> 息子のヒューを一流のアスリートにするのが夢で毎朝一緒にジョギングしている。

含义：曾是著名马拉松选手，因腿疾退役后成为教练；梦想把儿子培养成一流运动员，每天早晨一起慢跑。

US／EU 在下面这句之后结束：

> They came to Forget-me-not Valley because it's a great place to run.

DE 在对应句之后结束：

> Sie kamen ins Vergissmeinnicht-Tal, weil es ein toller Ort zum Laufen ist.

两者都只保留了搬来山谷适合跑步的介绍，上述两段没有对应译文。来源同第7项。

<a id="d07"></a>
### D07．Hugh：海外缺两段

原编号：补充10。状态：已获准，后续分项提交。

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

来源：[JP](data/text/jp/reference_guide/ngc_awl_profiles_hugh.cc)、[US／EU对应原文](data/text/us/reference_guide/ngc_awl_profiles_hugh.cc)、[DE](data/text/de/reference_guide/ngc_awl_profiles_hugh.cc)。

<a id="d08"></a>
### D08．Samantha：海外缺两段

原编号：补充11。状态：已获准，后续分项提交。

JP：

> 厳格な家庭に育ったため、娘のしつけには厳しい。グラート以上にまじめで保守的 普通が一番と考えている。
>
> 「わすれ谷」には変わった人が多いので、あまり外に出ないようにしている。

含义：由于在严格的家庭长大，对女儿管教严格，比Grant更认真保守，认为平凡最好；觉得山谷里怪人多，所以尽量少出门。

US／EU 仅有：

> People call her "Sam", she is Grant’s wife and Kate's mother. She is reticent and responsible.

DE 对应内容：

> Wird meist "Sam" genannt, sie ist Grants Frau und Kates Mutter. Sie ist zurückhaltend und verantwortungsvoll.

即只有称呼、家庭关系和简短性格介绍。DE 把部分正文放进标题的问题属于前一份清单，和本次缺段不重复计算。

来源：[JP](data/text/jp/reference_guide/ngc_awl_profiles_samantha.cc)、[US／EU对应原文](data/text/us/reference_guide/ngc_awl_profiles_samantha.cc)、[DE](data/text/de/reference_guide/ngc_awl_profiles_samantha.cc)。

<a id="d09"></a>
### D09．Galen：海外缺最后一段

原编号：补充12。状态：已获准，后续分项提交。

JP：

> ニーナがいなくなってからは常に悲しげで、寂しげな生活になっている。

含义：Nina去世后，他一直显得悲伤，过着寂寞的生活。

US／EU 在下面这句结束：

> When Nina died, he built a cottage near her grave on a hill, where he spends all day watching the ocean.

DE 在对应句结束：

> Als Nina starb, hat er eine Hütte auf einem Hügel in der Nähe ihres Grabes gebaut, von wo er den ganzen Tag aufs Meer schaut.

海外保留了墓旁小屋、眺望大海的内容，但没有日版最后这一独立解锁段。来源同第8项。

<a id="d10"></a>
### D10．Daryl：海外缺两段

原编号：补充13。状态：已获准，后续分项提交。

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

来源：[JP](data/text/jp/reference_guide/ngc_awl_profiles_daryl.cc)、[US／EU对应原文](data/text/us/reference_guide/ngc_awl_profiles_daryl.cc)、[DE](data/text/de/reference_guide/ngc_awl_profiles_daryl.cc)。

以上五本合计缺 **9段正文／每个海外版本**。程序仍保留对应人物的分级显示判断，正文缺失会使提高解锁等级后无法显示日版对应的新增介绍。[人物介绍显示条件](src/scene_reference_page.cc:678)



## E．电视节目

<a id="e01"></a>
### E01．JP：《まことクンちぇんじ》第24集说话人写反

原编号：E01。状态：已获准，后续分项提交。

- **JP：** 两处 `誠人（体は真琴だよ）`——诚人，身体是真琴。
- **US＝EU：** `Erin (in Aaron's body)`。
- **DE：** `Erin (in Aarons Körper)`。

**依据：** 本段开头明确是“回到教室的真琴”，老师对其外貌对应的诚人说话；海外身份标注正确。JP 应修显示的说话人，不调整集数或角色映射。

[第24集上下文](data/scripts/jp/EventScript_TV_AaronChanges.mary.c)

<a id="e02"></a>
### E02．DE：同节目第2集漏否定词

原编号：E02。状态：已获准，后续分项提交。

- **JP：** `前を見ないからつまづいて転びそうになっているよ。`——因为没看前面，绊了一下差点摔倒。
- **US＝EU：** `She almost tripped because of not looking where she's going.`
- **DE：** `Sie stolperte fast, weil sie darauf achtete, wo sie hinging.`——因为注意看路，差点绊倒。

**依据：** 原因反转；DE 下一集回顾同一事件时已有正确的 `nicht`，可以用同语原文参照。

[第2、3集](data/scripts/de/EventScript_TV_AaronChanges.mary.c)

<a id="e03"></a>
### E03．DE：同节目第13集把竖笛译成录音机

原编号：E03。状态：已获准，后续分项提交。

- **JP：** `たてぶえのテスト`，之后拿起 `教科書とたてぶえ`。
- **US＝EU：** `recorder test`，之后拿起 `my textbook and recorder`。
- **DE：** `Aufnahmetest`，之后拿起 `Kassettenrekorder`。

**依据：** 音乐课、吹奏测试、“间接接吻”的上下文共同确定 `recorder` 指竖笛，不是录音机。

[第13集](data/scripts/de/EventScript_TV_AaronChanges.mary.c)

<a id="e04"></a>
### E04．四版：《Card Collector Chisato》第3集卡片数量算错

原编号：E04。状态：已获准，后续分项提交。

- **JP：** `全部で１５６種類…あと７０種類でコンプリート`。
- **US＝EU：** `a total of 156 different card types…70 more`。
- **DE：** `insgesamt 156 Kartentypen…noch 70 weitere`。

**依据：** 第2集已明确总计256种、得到186种、还差70种；第3集重述同一批卡片时写成156。随后交换七种，还差63，也支持应为186。

[第2、3集数量关系](data/scripts/jp/EventScript_TV_CardCollectorChisato.mary.c)

<a id="e05"></a>
### E05．海外三版：同节目把 S／G 牛奶译成羊奶、山羊奶

原编号：E05。状态：已获准，后续分项提交。

| 集数 | JP | US＝EU | DE |
|---|---|---|---|
| 第3集 | `Ｓ牛乳` | `Sheep's Milk` | `Schafsmilch` |
| 第7集 | `Ｇ牛乳` | `Goat's Milk` | `Ziegenmilch` |

**依据：** 这里是游戏道具卡片，S／G 为牛奶等级。应沿用现有道具译名，不新增羊奶或山羊奶的物品身份。

[节目原文](data/scripts/us/EventScript_TV_CardCollectorChisato.mary.c) · [已有牛奶名称](data/text/us/item_2.cc)

<a id="e06"></a>
### E06．海外三版：同节目第1集，把将来发售写成已经发售

原编号：E06。状态：已获准，后续分项提交。

- **JP：** `来月に…発売される`——下个月发售。
- **US＝EU：** `Remember the rumor last month… Well, it's happened.`——上个月的传闻，现在已经发生了。
- **DE：** `…das Gerücht letzten Monat… Tja, das ist geschehen.`——同样变成已经发生。

**依据：** 同一段随后仍约定“发售时一起去买”，过去与将来关系冲突。

[第1集](data/scripts/us/EventScript_TV_CardCollectorChisato.mary.c)

<a id="e07"></a>
### E07．海外三版：同节目第11集，把假设写成已经发生

原编号：E07。状态：已获准，后续分项提交。

- **JP：** `３日連続で新しいのが出なかったらすっごい哀しいし…`——如果连续三天没抽到新卡，会很难过……
- **US＝EU：** `I was too upset from not getting any new cards for three days in a row…`
- **DE：** `Ich war zu sauer, dass ich 3 Tage hintereinander keine neuen Karten hatte…`

**依据：** 前文是连续两天没抽到，所以昨天不再去买；海外却写成已连续三天没抽到，与实际行动冲突。

[第8至11集](data/scripts/jp/EventScript_TV_CardCollectorChisato.mary.c)

<a id="e08"></a>
### E08．海外三版：同节目第8集标题残留 `<et>`

原编号：E08。状态：已获准，后续分项提交。

- **JP：** `☆カードコレクターちさとくん`。
- **US＝EU：** `CARD COLLECTOR CHISATO<et>`。
- **DE：** `Kartensammler Chisato<et>`。

**依据：** 当前码表、消息读取器没有把 `<et>` 定义为控制符，会作为文字显示。它与之前的 `ret>`／`<RET>` 是不同的遗漏点；尚不能断定历史来源相同。

[原文](data/scripts/us/EventScript_TV_CardCollectorChisato.mary.c) · [消息读取器](src/ui_text_stream.cc)

<a id="e09"></a>
### E09．DE：《Mechabot Ultror Zero》第1集装饰人员多出 Yellow

原编号：E09。状态：已获准，后续分项提交。

- **JP：** `あかね、あおい、みどりの３人が装飾係で、きいろちゃんはお料理担当。`
- **US＝EU：** `Red, Blue and green are working on the party decorations, while Yellow is in charge of the food.`
- **DE：** `Gelb, Rot, Blau und Grün an der Partydekoration, während Gelb für das Essen…`

**依据：** 日英都是红、蓝、绿负责装饰，黄负责料理；德文把黄重复加入了装饰名单。

[第1集](data/scripts/de/EventScript_TV_MechabotUltrorZero_EpisodeReminders.mary.c)

<a id="e10"></a>
### E10．DE：同节目第2集把上午写成明天

原编号：E10。状态：已获准，后续分项提交。

- **JP：** `午前中は晴れていたはずなのに…雪が…`——上午明明晴着，现在却下雪了。
- **US＝EU：** `…sunny all morning, but all of a sudden it's snowing…`
- **DE：** `…dass es morgen sonnig wird, aber auf einmal schneit es…`——预报明天晴，可现在突然下雪。

**依据：** 德文把作为对照的上午改成明天。US／EU 额外加入“天气预报”的改写，本次不直接等同判定为必须修复；**此项确定范围是 DE 的时间错位**。

[第2集](data/scripts/de/EventScript_TV_MechabotUltrorZero_EpisodeReminders.mary.c)

<a id="e11"></a>
### E11．四版：入门节目冬21日的初始体力和翻倍说明错误

原编号：E11。状态：保留不动。

- **JP：** 初始 `１００だよ`，之后 `最初の２倍までふえる`。
- **US＝EU：** 初始 `100.`，之后 `Stamina by 100%.`
- **DE：** 初始 `100.`，之后 `100 % steigern.`

**依据：** 四版共享实现中初始体力为150，最大值为 `150 + 10 × 力之果实数量`，十颗后250；状态画面也直接显示该值。应修节目数字与“翻倍”说法，不改游戏机制。

[节目](data/scripts/jp/EventScript_TV_LifeOnTheFarm_Beginner.mary.c) · [实际体力实现](src/farmer.cc:11)

<a id="e12"></a>
### E12．DE：进阶节目冬2日，把最大体力写成10

原编号：E12。状态：已获准，后续分项提交。

- **JP：** `最大体力を越えたり、疲労が０より小さくなったりはしない`。
- **US＝EU：** `You can't get better than your maximum Stamina, or reduce your Fatigue below 0…`
- **DE：** `Allerdings ist 10 die max. Ausdauer und 0 der minimale Energieverlust.`

**依据：** 温泉恢复上限是角色当前最大体力，不是10。修文应表达“最大值”，不能简单把10改成另一个固定数字。

[冬2日](data/scripts/de/EventScript_TV_LifeOnTheFarm_Advanced.mary.c)

<a id="e13"></a>
### E13．DE：进阶节目冬3日，把矿场写成磨坊

原编号：E13。状态：已获准，后续分项提交。

- **JP：** `マザーズヒルにある『鉱石場』`。
- **US＝EU：** `the mine on Mother's Hill`。
- **DE：** `Mühle auf dem Mutterberg`——母亲山的磨坊。

**依据：** 后面紧接着讲用锄头挖地、锤子敲石，同一德文段落随后也用 `Mine`。场所译错。

[冬3日](data/scripts/de/EventScript_TV_LifeOnTheFarm_Advanced.mary.c)

<a id="e14"></a>
### E14．DE：钓鱼节目第6集，鲣鱼仍误用金枪鱼名称

原编号：E14。状态：已获准，后续分项提交。

- **JP：** `カツオ`。
- **US＝EU：** `Bonito`。
- **DE：** `Thun-fische`——金枪鱼。

**依据：** 对应鱼种身份已经在鱼类审计中确定；节目漏掉了与鱼记录一致的修正。

[第6集](data/scripts/de/EventScript_TV_FishingHour.mary.c) · [德文鱼记录](data/text/de/fishing_results_data.cc)

<a id="e15"></a>
### E15．DE：钓鱼节目第10集，把下游鱼全部说成海鱼

原编号：E15。状态：已获准，后续分项提交。

- **JP：** `海では「サンマ」…下流では「サケ」「ドジョウ」`。
- **US＝EU：** `Sea Fish … Saury pike, and downstream fish are Salmon and Loach.`
- **DE：** `Meeresfische…Zander, Lachse und Bachschmerlen.`——三者全部列为海鱼。

**依据：** 下游这一地点限定被遗漏。本项修地点关系，不借此更改既有鱼种 ID 或重新命名全部鱼类。

[第10集](data/scripts/de/EventScript_TV_FishingHour.mary.c)

<a id="e16"></a>
### E16．DE：钓鱼节目第13集误用了另一鱼种的既有名字

原编号：E16。状态：已获准，后续分项提交。

- **JP：** `アイナメ`。
- **US＝EU：** `Rock trout`。
- **DE：** `Berg-forellen`。

**依据：** DE 鱼记录中，RockTrout 对应 `Gebirgsforelle`；`Bergforelle` 对应的是 MountainTrout。此处依据游戏现有名称映射修正，不依据现代生物分类擅自重译。

[第13集](data/scripts/de/EventScript_TV_FishingHour.mary.c) · [既有名称映射](data/text/de/fishing_results_data.cc)

<a id="e17"></a>
### E17．US／EU：矿场研究第9集，把“255层没有下行楼梯”写成“没有通向255层的楼梯”

原编号：E17。状态：已获准，后续分项提交。

- **JP：** `地下２５５階で下り階段が見つかったことはありません。`
- **US＝EU：** `we have not found a stairway down to the 255th level.`
- **DE：** `wir haben keine Treppe im 255 Level gesehen.`

**依据：** 同一段明确说已经到过255层几次。正确意思是在255层没找到继续往下的楼梯，而不是到不了255层。

[第9集](data/scripts/us/EventScript_TV_MineResearchGroup.mary.c)


<a id="e18"></a>
### E18．鱼王条件被译成“这条鱼适合做哪些菜”

原编号：补充5。状态：已获准，后续分项提交。

| 版本 | 原文 |
|---|---|
| JP | “釣り上げた人は、魚を使う料理の得意な人で、中でも『焼き魚』『刺身』『お寿司』が得意だそうです。”——钓到它的人擅长鱼料理，尤其擅长烤鱼、刺身和寿司。 |
| US／EU | “The person who fished it said it was good for Sushi, Sashimi, or Grilled Fish.”——钓到它的人说这条鱼适合做寿司、刺身或烤鱼。 |
| DE | “Der erfolgreiche Angler sagte, der Fisch eigne sich für Sushi, Sashimi oder gegrillten Fisch.”——同样变成鱼适合做这些菜。 |

实际钓鱼判断检查玩家是否已经学会这三份食谱，并非检查背包里是否带着三种料理。海外后文虽然保留了“学习鱼料理”的泛泛提示，但把关键三种料理与钓取条件的联系译坏了。

**拟纳入：**海外三版恢复“钓到的人掌握这三种料理”的提示。

来源：[节目原文](data/scripts/us/EventScript_TV_FishingHour.mary.c)、[鱼王食谱条件](src/fishing.cc:893)。

<a id="e19"></a>
### E19．料理对决第2集把糖译成盐

原编号：补充6。状态：已获准，后续分项提交。

| 版本 | B选手使用的调味料 |
|---|---|
| JP | “調味料　さとう”——糖。 |
| US／EU | “Seasoning: Salt”——盐。 |
| DE | “Gewürze: Salz”——盐。 |

这不是同一种材料的不同叫法。炒饭配方数据里糖、盐对应不同效果，糖对体力恢复的修正为−1，盐为＋5，海外改变了节目举例所用材料。

**拟纳入：**海外三版恢复为糖。节目胜负本身是固定文本，不是修改这个词便会改变程序计算出的比赛结果。

来源：[料理节目](data/scripts/us/EventScript_TV_DuelingChefs.mary.c)、[配方与调味效果](src/cooking_recipe.cc)。


## F．拼写

<a id="f01"></a>
### F01．US：卡莲初次见面的 `You name`

原编号：F01。状态：已获准，后续分项提交。

- **JP：** `{Player}くんね。`——你叫……
- **US：** `You name is {Player}, huh?`
- **EU：** `Your name is... {Player}, huh?`
- **DE：** `Du bist {Player}, hm?`

**依据：** US 缺所有格 `Your`，EU 已修正，可直接作为同系列依据。

[US 原文](data/scripts/us/EventScript_NPCEvent_Karen_DialogueAndGiftResponses.mary.c) · [EU 原文](data/scripts/eu/EventScript_NPCEvent_Karen_DialogueAndGiftResponses.mary.c)

<a id="f02"></a>
### F02．JP：味噌汤食谱的锅写成 `なぺ`

原编号：F02。状态：已获准，后续分项提交。

- **JP：** `なぺ`。
- **US＝EU：** `Pot`。
- **DE：** `Topf`。

**依据：** 指锅，应为 `なべ`；同类日文食谱使用正确写法。只是浊点错误。

[味噌汤食谱](data/text/jp/reference_guide/cookbook_1.cc)

<a id="f03"></a>
### F03．海外三版：食谱牛奶单词残缺

原编号：F03。状态：已获准，后续分项提交。

- **JP：** `果物とか牛乳とか草`。
- **US＝EU：** `Fruit, Mil, Grasses`。
- **DE：** `Früchte, Mil, Gräser`。

**依据：** 此处都是牛奶，英文 `Milk`、德文 `Milch` 被截成 `Mil`；可沿用同语现有名称。

[食谱原文](data/text/de/reference_guide/cookbook_4.cc)

<a id="f04"></a>
### F04．DE：酱油名称出现错误字符

原编号：F04。状态：已获准，后续分项提交。

- **JP：** `しょうゆ`。
- **US＝EU：** `Soy Sauce`。
- **DE：** `Soyasoﾟe`。

**依据：** 同语言另一食谱已有 `Soyasoße`。此处 `ﾟ` 不是正常德文拼写，应按已有正确文本修正。

[错误文本](data/text/de/reference_guide/cookbook_4.cc) · [已有正确拼写](data/text/de/reference_guide/cookbook_2.cc)
