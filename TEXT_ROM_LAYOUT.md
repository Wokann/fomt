# 文本 ROM 物理地址布局

本表严格以当前 `fomt_jp.map` 与 `fomt_us.map` 的链接结果为准，而不是按目录或主题排序。每个地区分别按实际 GBA ROM 地址升序列出 `.rodata` 输入段；因此文本块之间的指针表、结构/数组、填充和原始 `incbin` 都会显示在相邻行。

“维护源”表示当前应编辑的文件；“文本符号”是链接映射中的 `gText_*` 标签。普通非文本行不猜测 C 类型，只报告已知输入对象、节名和符号，避免把未分析数据误称为数组或结构体。

指南页由 `fomt-text guide-collection` 生成到 `src/reference_guide.o(.rodata.reference_guide)`；按维护规则，指南仅作为一个连续 ROM 块记录起点和终点，不逐页展开。

## 读取规则

- `[文本对象]`：独立 `data/text` 对象，或包含已识别 `gText_*` 的宿主对象。
- `[嵌入文本]`：`data/text` 文件被 `#include` 到 `src/*.c/.cc` 的宿主对象；具体符号以“文本地址索引”为准。
- `[嵌入文本 / 数据]`：区域文本与紧邻的功能数据同属一个宿主对象，按源码顺序共同占用一个可定位的 ROM 区间。
- `[数据]`：文本之间的已命名普通数据；名称和节名就是当前可靠证据。
- `[原始 incbin]`：来自汇编的保留 ROM 数据，尚未当作结构体解出。
- `[指南连续块]`：指南生成器产生的连续区域；只记录整体边界，避免把已知连续块误写成独立物理对象。
- `[Mary 脚本连续块]`：汇编明确标注为脚本相邻/脚本表的数据；只记录边界，不展开内部内容。
- `[填充]`：链接映射中实际存在的 `*fill*` 字节，显示字节值。

## JP：物理 `.rodata` 顺序

范围：`0x080E7A5C`–`0x0813ABCB`。所有行都按当前 ROM 物理地址排序。

| 地址范围 | 链接输入 | 内容状态 | 维护源 / 文本来源 | 已命名内容 |
| --- | --- | --- | --- | --- |
| `0x080E7A5C`–`0x080E7AA1` | `src/sram_proxy_1.o(.rodata)` | [数据] | `src/sram_proxy_1.c/.cc` | `gSramImageSignature`, `gUnk_SramSignatureTrailerBadAllocFirst`, `gUnk_SramSignatureTrailerEmptyText`, `gUnk_SramSignatureTrailerBadAllocSecond`, `gUnk_SramSignatureTrailerBadAllocThird` |
| `0x080E7AA2`–`0x080E7AA3` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080E7AA4`–`0x080E7AC5` | `src/intro_scene_data.o(.rodata.intro_scene_startup_resources)` | [数据] | `src/intro_scene_data.c/.cc` | 运行时字符串 `2` 项<br>`gIntroSceneStartupUnpackSources` |
| `0x080E7AC6`–`0x080E7AC7` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080E7AC8`–`0x080E7B7B` | `src/new_game_menu_data.o(.rodata)` | [嵌入文本] | `data/text/jp/new_game.cc` | 文本 `12` 项（详见下方索引）<br>`gNewGameMenuLabels` |
| `0x080E7B7C`–`0x080E8161` | `data/text/new_game.o(.rodata)` | [文本对象] | `data/text/jp/new_game.cc` | 文本 `39` 项（详见下方索引）<br>运行时字符串 `14` 项<br>`gNewGameNameEntryCharacterRows` |
| `0x080E8162`–`0x080E8163` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080E8164`–`0x080E81A3` | `src/field_data.o(.rodata.field_plot_weather_ordinary)` | [数据] | `src/field_data.c/.cc` | `gFieldPlotOrdinaryWeatherRules` |
| `0x080E81A4`–`0x080E81AB` | `src/field_data.o(.rodata.field_plot_weather_special_3)` | [数据] | `src/field_data.c/.cc` | `gFieldPlotSpecialWeatherRule3` |
| `0x080E81AC`–`0x080E81B3` | `src/field_data.o(.rodata.field_plot_weather_special_4)` | [数据] | `src/field_data.c/.cc` | `gFieldPlotSpecialWeatherRule4` |
| `0x080E81B4`–`0x080E8897` | `src/field_data.o(.rodata.field_plot_growth_transitions)` | [数据] | `src/field_data.c/.cc` | `gFieldPlotGrowthStageTransitions` |
| `0x080E8898`–`0x080E8A6B` | `src/field_data.o(.rodata.field_plot_definitions)` | [数据] | `src/field_data.c/.cc` | `gFieldPlotTypeDefinitions` |
| `0x080E8A6C`–`0x080E8AA4` | `src/shipping_bin.o(.rodata)` | [数据] | `src/shipping_bin.c/.cc` | 无全局符号 |
| `0x080E8AA5`–`0x080E8AB3` | `src/record_player.o(.rodata)` | [数据] | `src/record_player.c/.cc` | 无全局符号 |
| `0x080E8AB4`–`0x080E8B07` | `src/item.o(.rodata)` | [数据] | `data/text/common/fallback.cc` | 无全局符号 |
| `0x080E8B08`–`0x080E9EEA` | `data/text/tool.o(.rodata)` | [文本对象] | `data/text/jp/tool.cc` | 文本 `162` 项（详见下方索引） |
| `0x080E9EEB`–`0x080E9EEB` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x080E9EEC`–`0x080EA2B7` | `src/item.o(.rodata.item_tool)` | [数据] | `data/text/common/fallback.cc` | `gToolInfo` |
| `0x080EA2B8`–`0x080ED3D4` | `data/text/food.o(.rodata)` | [文本对象] | `data/text/jp/food.cc` | 文本 `337` 项（详见下方索引） |
| `0x080ED3D5`–`0x080ED3D7` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 3 字节 |
| `0x080ED3D8`–`0x080EDE87` | `src/item.o(.rodata.item_food)` | [数据] | `data/text/common/fallback.cc` | `gFoodInfo` |
| `0x080EDE88`–`0x080EF734` | `data/text/article.o(.rodata)` | [文本对象] | `data/text/jp/article.cc` | 文本 `187` 项（详见下方索引） |
| `0x080EF735`–`0x080EF737` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 3 字节 |
| `0x080EF738`–`0x080EFBAB` | `src/item.o(.rodata.item_article)` | [数据] | `data/text/common/fallback.cc` | `gArticleInfo` |
| `0x080EFBAC`–`0x080EFD47` | `src/item.o(.rodata.item_product)` | [数据] | `data/text/common/fallback.cc` | `gProductInfo` |
| `0x080EFD48`–`0x080EFD51` | `src/item.o(.rodata.item_product_trailer)` | [数据] | `data/text/common/fallback.cc` | 运行时字符串 `1` 项 |
| `0x080EFD52`–`0x080EFD5D` | `data/text/calendar.o(.rodata.calendar_season)` | [文本对象] | `data/text/jp/calendar.cc` | 文本 `1` 项（详见下方索引） |
| `0x080EFD5E`–`0x080EFD5F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080EFD60`–`0x080EFDA9` | `data/text/calendar.o(.rodata)` | [文本对象] | `data/text/jp/calendar.cc` | 文本 `3` 项（详见下方索引）<br>运行时字符串 `4` 项 |
| `0x080EFDAA`–`0x080EFDCD` | `src/game_state.o(.rodata)` | [数据] | `src/game_state.c/.cc` | `gUnk_080F0566` |
| `0x080EFDCE`–`0x080EFDCF` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080EFDD0`–`0x080EFDF5` | `data/text/load_error.o(.rodata)` | [文本对象] | `data/text/jp/load_error.cc` | 文本 `2` 项（详见下方索引）<br>运行时字符串 `2` 项 |
| `0x080EFDF6`–`0x080EFDF7` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080EFDF8`–`0x080EFEA2` | `src/help_menu.o(.rodata)` | [嵌入文本] | `data/text/jp/help_menu.cc` | 文本 `4` 项（详见下方索引）<br>`gUnk_HelpMenuByteTable` |
| `0x080EFEA3`–`0x080EFEA3` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x080EFEA4`–`0x080EFF5C` | `data/text/animal_memorial.o(.rodata)` | [文本对象] | `data/text/jp/animal_memorial.cc` | 文本 `11` 项（详见下方索引）<br>运行时字符串 `2` 项 |
| `0x080EFF5D`–`0x080F006F` | `src/animal_data.o(.rodata.animal_data_prefix)` | [数据] | `data/text/common/animal_data.cc`<br>`data/text/jp/animal_data.cc` | `gUnk_080F06FD`, `gUnk_080F0704`, `gUnk_080F0718`, `gUnk_080F0730`, `gUnk_080F0748`, `gUnk_080F0770`, … +1 |
| `0x080F0070`–`0x080F06DD` | `src/animal_data.o(.rodata)` | [嵌入文本] | `data/text/common/animal_data.cc`<br>`data/text/jp/animal_data.cc` | 文本 `1` 项（详见下方索引）<br>运行时字符串 `5` 项<br>`gUnk_080F0838`, `gUnk_080F0908`, `gUnk_080F093C`, `gUnk_080F09AC`, `gUnk_080F09C8`, `gUnk_080F0A68`, … +4 |
| `0x080F06DE`–`0x080F06DF` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F06E0`–`0x080F11D1` | `src/entity_ui.o(.rodata)` | [嵌入文本] | `data/text/common/entity_ui.cc`<br>`data/text/jp/entity_ui.cc` | 文本 `1` 项（详见下方索引）<br>运行时字符串 `18` 项<br>`gUnk_080F0E88`, `gUnk_080F0F78`, `gUnk_080F0FCC`, `gUnk_080F1020`, `gUnk_080F1170`, `gUnk_080F1178`, … +41 |
| `0x080F11D2`–`0x080F11D3` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F11D4`–`0x080F11F9` | `src/fixed_labels.o(.rodata)` | [嵌入文本] | `data/text/common/fixed_labels.cc`<br>`data/text/jp/fixed_labels.cc` | 文本 `2` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gFixedLabelsPaddingBeforeUnnamedSetting` |
| `0x080F11FA`–`0x080F11FB` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F11FC`–`0x080F1225` | `src/ui_error.o(.rodata)` | [嵌入文本] | `data/text/common/ui_error.cc`<br>`data/text/jp/ui_error.cc` | 文本 `2` 项（详见下方索引）<br>运行时字符串 `2` 项<br>`gUnk_080F19AE` |
| `0x080F1226`–`0x080F1227` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F1228`–`0x080F12D9` | `src/menu_data.o(.rodata)` | [嵌入文本] | `data/text/common/menu.cc`<br>`data/text/jp/menu.cc` | 文本 `7` 项（详见下方索引）<br>运行时字符串 `3` 项<br>`gMenuEntryIds`, `gMenuEntryLabels`, `gUnk_080F1A66` |
| `0x080F12DA`–`0x080F12DB` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F12DC`–`0x080F2C11` | `src/data_schedules.o(.rodata)` | [数据] | `src/data_schedules.c/.cc` | 运行时字符串 `3` 项<br>`ScheduleInfo_Unk_080F1A80`, `Unk_080F1A80_Schedules`, `Unk_080F1A80_Schedule_1`, `Unk_080F1A80_Schedule_2`, `Unk_080F1A80_Schedule_3`, `Unk_080F1A80_Schedule_4`, … +271 |
| `0x080F2C12`–`0x080F2C13` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F2C14`–`0x080F3B49` | `src/entity_ui.o(.rodata.entity_ui_resource_selector)` | [数据] | `data/text/common/entity_ui.cc`<br>`data/text/jp/entity_ui.cc` | 运行时字符串 `4` 项<br>`gUnk_080F33B8`, `gUnk_080F3408`, `gUnk_080F35E4`, `gUnk_080F3FD8` |
| `0x080F3B4A`–`0x080F3B4B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F3B4C`–`0x080F96F3` | `asm/data/data_080F1A80.o(.rodata.data_080f1a80_suffix)` | [Mary 脚本连续块] | `asm/data/data_080F1A80.s`<br>Mary 独立管理的连续剧情脚本区域（含脚本表入口）；按维护规则不展开内部内容 | 连续脚本相关原始区域；按维护规则不展开内部标签或表 |
| `0x080F96F4`–`0x080F96FF` | `src/script_engine.o(.rodata.script_engine_string_error_prefix)` | [数据] | `src/script_engine.c/.cc` | 无全局符号 |
| `0x080F9700`–`0x080F9720` | `data/text/common/script_engine.o(.rodata)` | [文本对象] | `data/text/common/script_engine.cc` | 文本 `3` 项（详见下方索引）<br>运行时字符串 `1` 项 |
| `0x080F9721`–`0x080F9734` | `src/cooking_festival_data.o(.rodata)` | [数据] | `src/cooking_festival_data.c/.cc` | `gCookingFestivalDishCategoryRatingThresholds` |
| `0x080F9735`–`0x080F9739` | `src/thomas_stocking_data.o(.rodata)` | [数据] | `src/thomas_stocking_data.c/.cc` | `gThomasStockingGiftSelectionWeights` |
| `0x080F973A`–`0x080F973B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F973C`–`0x080F974F` | `src/spouse_gift_data.o(.rodata)` | [数据] | `src/spouse_gift_data.c/.cc` | `gSpouseGiftArticleSelectionEntries` |
| `0x080F9750`–`0x080F9755` | `src/farm_house.o(.rodata)` | [数据] | `src/farm_house.c/.cc` | `gFarmHouseBedXPositions` |
| `0x080F9756`–`0x080F9757` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F9758`–`0x080F97CB` | `src/ui_state.o(.rodata.ui_state_adapters)` | [数据] | `src/ui_state.c/.cc` | 运行时字符串 `2` 项<br>`gUnk_PreUiTextLayoutDigitRows`, `gUnk_PreUiTextLayoutFullWidthSpace`, `gUnk_PreUiTextLayoutFullWidthHyphen`, `gUiTextLayoutPositionTable` |
| `0x080F97CC`–`0x080F97D7` | `src/ui_state.o(.rodata)` | [数据] | `src/ui_state.c/.cc` | `gUiSharedResourceData` |
| `0x080F97D8`–`0x080F996B` | `data/text/new_game_name_entry_preset.o(.rodata)` | [文本对象] | `data/text/jp/new_game.cc` | 文本 `1` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gUnk_NewGameNameEntryPresetAnimalNamesPrefixValue` |
| `0x080F996C`–`0x080F9993` | `src/new_game_name_entry_ui_data.o(.rodata)` | [数据] | `src/new_game_name_entry_ui_data.c/.cc` | `gNewGameNameEntryUiCharacterCodes` |
| `0x080F9994`–`0x080F99AA` | `data/text/frisbee_scoreboard.o(.rodata)` | [文本对象] | `data/text/jp/frisbee.cc` | 文本 `1` 项（详见下方索引） |
| `0x080F99AB`–`0x080F99AB` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x080F99AC`–`0x080F9A73` | `src/animal_festival_ranking.o(.rodata.animal_festival_ranking_score_table)` | [数据] | `src/animal_festival_ranking.c/.cc` | `gAnimalFestivalRankingScoreTable` |
| `0x080F9A74`–`0x080F9A7D` | `src/animal_festival_ranking.o(.rodata.animal_festival_ranking_scoreboard_trailer)` | [数据] | `src/animal_festival_ranking.c/.cc` | 运行时字符串 `1` 项 |
| `0x080F9A7E`–`0x080F9BB1` | `src/animal_festival_ranking.o(.rodata.animal_festival_ranking_data)` | [数据] | `src/animal_festival_ranking.c/.cc` | `gUnk_080FA246`, `gUnk_080FA264`, `gUnk_080FA2E8`, `gUnk_080FA36C`, `gAnimalFestivalRewardChanceWeights` |
| `0x080F9BB2`–`0x080F9BB3` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F9BB4`–`0x080F9BD3` | `src/animal_festival_ranking.o(.rodata.animal_festival_ranking_reward_article_ids)` | [数据] | `src/animal_festival_ranking.c/.cc` | `gAnimalFestivalRewardArticleIds` |
| `0x080F9BD4`–`0x080F9F59` | `data/text/frisbee.o(.rodata)` | [文本对象] | `data/text/jp/frisbee.cc` | 文本 `15` 项（详见下方索引）<br>运行时字符串 `1` 项 |
| `0x080F9F5A`–`0x080F9F5B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F9F5C`–`0x080F9FCB` | `src/animal_festival_ranking.o(.rodata.animal_festival_ranking_random_range_pairs)` | [数据] | `src/animal_festival_ranking.c/.cc` | `gAnimalFestivalRandomRangePairs` |
| `0x080F9FCC`–`0x080FA1DD` | `data/text/animal_festival.o(.rodata)` | [文本对象] | `data/text/jp/animal_festival.cc` | 文本 `1` 项（详见下方索引）<br>运行时字符串 `1` 项 |
| `0x080FA1DE`–`0x080FA27D` | `src/animal_festival_ranking.o(.rodata.animal_festival_livestock_contestant_values)` | [数据] | `src/animal_festival_ranking.c/.cc` | `gAnimalFestivalLivestockContestantValues` |
| `0x080FA27E`–`0x080FA27F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FA280`–`0x080FAA5F` | `src/horse_race_data.o(.rodata)` | [嵌入文本] | `data/text/jp/horse_race.cc` | 文本 `44` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gHorseRaceTicketCharacterCodes`, `gHorseRaceTicketControls`, `gHorseRacePrizeCatalog`, `gHorseRacePrizeItemIds`, `gHorseRacePrizeExchangeCharacterCodes` |
| `0x080FAA60`–`0x080FAA69` | `src/intro_scene_data.o(.rodata.intro_scene_prefix)` | [数据] | `src/intro_scene_data.c/.cc` | 运行时字符串 `1` 项 |
| `0x080FAA6A`–`0x080FAA6B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FAA6C`–`0x080FAABB` | `src/intro_scene_data.o(.rodata)` | [数据] | `src/intro_scene_data.c/.cc` | `gIntroSceneUnpackSources` |
| `0x080FAABC`–`0x080FB10E` | `data/text/intro_scene.o(.rodata)` | [文本对象] | `data/text/jp/intro_scene.cc` | 文本 `28` 项（详见下方索引） |
| `0x080FB10F`–`0x080FB10F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x080FB110`–`0x080FB119` | `src/intro_scene_data.o(.rodata.intro_scene_trailer)` | [数据] | `src/intro_scene_data.c/.cc` | 运行时字符串 `1` 项 |
| `0x080FB11A`–`0x080FB11B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FB11C`–`0x080FB27B` | `data/text/farm_status.o(.rodata)` | [文本对象] | `data/text/jp/farm_status.cc` | 文本 `35` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gAnimalStatusScreenPrefixText`, `gAnimalStatusScreenText` |
| `0x080FB27C`–`0x080FB642` | `data/text/animal_contest.o(.rodata)` | [文本对象] | `data/text/jp/animal_contest.cc` | 文本 `27` 项（详见下方索引）<br>运行时字符串 `1` 项 |
| `0x080FB643`–`0x080FB643` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x080FB644`–`0x080FB761` | `src/farm_status_screen_data.o(.rodata)` | [数据] | `src/farm_status_screen_data.c/.cc` | 运行时字符串 `2` 项<br>`gFarmStatusScreenPreloadedGlyphs`, `gFarmStatusScreenResourceDescriptors`, `gFarmStatusScreenTileLookup`, `gFarmStatusScreenFarmHousePreviews`, `gFarmStatusScreenCoopPreviews`, `gFarmStatusScreenBarnPreviews`, … +1 |
| `0x080FB762`–`0x080FB763` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FB764`–`0x080FB935` | `src/records_screen_data.o(.rodata)` | [嵌入文本] | `data/text/jp/records.cc` | 文本 `33` 项（详见下方索引）<br>运行时字符串 `4` 项<br>`gRecordsScreenMinigameTaskResources`, `gCodeLinkoncePackedCellSizeLookup`, `gUiPreloadedDigitGlyphCodes` |
| `0x080FB936`–`0x080FB937` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FB938`–`0x080FBE87` | `data/text/staff_credits.o(.rodata)` | [文本对象] | `data/text/jp/staff_credits.cc` | 文本 `59` 项（详见下方索引）<br>`gStaffCreditsLines` |
| `0x080FBE88`–`0x080FBE91` | `src/town_map_data.o(.rodata.staff_credits_trailer)` | [数据] | `src/town_map_data.c/.cc` | 运行时字符串 `1` 项 |
| `0x080FBE92`–`0x080FBE99` | `src/town_map_data.o(.rodata.town_map_resource_ids)` | [数据] | `src/town_map_data.c/.cc` | `gTownMapResourceIds` |
| `0x080FBE9A`–`0x080FBE9B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FBE9C`–`0x080FC7E4` | `data/text/town_map.o(.rodata)` | [文本对象] | `data/text/jp/town_map.cc` | 文本 `65` 项（详见下方索引） |
| `0x080FC7E5`–`0x080FC7E7` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 3 字节 |
| `0x080FC7E8`–`0x080FCB07` | `src/town_map_data.o(.rodata.town_map_hotspots)` | [数据] | `src/town_map_data.c/.cc` | `gTownMapHotspots` |
| `0x080FCB08`–`0x080FCCB7` | `src/town_map_data.o(.rodata.town_map_area_lookup)` | [数据] | `src/town_map_data.c/.cc` | `gTownMapAreaLookup`, `gTownMapAreaLookupFallback_034To133`, `gTownMapAreaLookupFallback_134To233` |
| `0x080FCCB8`–`0x080FCCF2` | `src/library_data.o(.rodata.library_opening_hours)` | [嵌入文本] | `data/text/jp/library.cc` | 文本 `1` 项（详见下方索引） |
| `0x080FCCF3`–`0x080FCCF3` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x080FCCF4`–`0x080FD083` | `src/town_map_data.o(.rodata.town_map_area_bounds)` | [数据] | `src/town_map_data.c/.cc` | `gTownMapAreaBounds` |
| `0x080FD084`–`0x080FD08D` | `src/library_data.o(.rodata.library_info)` | [数据] | `data/text/jp/library.cc` | 运行时字符串 `1` 项 |
| `0x080FD08E`–`0x080FD08F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FD090`–`0x080FD0AF` | `src/library_data.o(.rodata.library_initial_entry_ids)` | [数据] | `data/text/jp/library.cc` | `gLibraryInitialEntryIds` |
| `0x080FD0B0`–`0x080FD0CD` | `src/library_data.o(.rodata.library_menu)` | [嵌入文本] | `data/text/jp/library.cc` | 文本 `1` 项（详见下方索引）<br>运行时字符串 `1` 项 |
| `0x080FD0CE`–`0x080FD0CF` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FD0D0`–`0x080FD55D` | `src/poultry_shop_data.o(.rodata)` | [嵌入文本] | `data/text/jp/poultry_shop.cc` | 文本 `34` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gPoultryShopCatalog` |
| `0x080FD55E`–`0x080FD55F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FD560`–`0x080FD80D` | `src/supermarket_data.o(.rodata)` | [嵌入文本] | `data/text/jp/supermarket.cc` | 文本 `11` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gSupermarketCropSeedCatalog`, `gSupermarketAdditionalSeedCatalog` |
| `0x080FD80E`–`0x080FD80F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FD810`–`0x080FD9E1` | `src/clinic_data.o(.rodata)` | [嵌入文本] | `data/text/jp/clinic.cc` | 文本 `9` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gClinicCatalog` |
| `0x080FD9E2`–`0x080FD9E3` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FD9E4`–`0x080FDBED` | `src/inn_shop_data.o(.rodata)` | [嵌入文本] | `data/text/jp/inn_shop.cc` | 文本 `7` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gInnShopMenu` |
| `0x080FDBEE`–`0x080FDBEF` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FDBF0`–`0x080FDF99` | `src/won_shop_data.o(.rodata)` | [嵌入文本] | `data/text/jp/won_shop.cc` | 文本 `12` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gWonShopCatalog` |
| `0x080FDF9A`–`0x080FDF9B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FDF9C`–`0x080FE181` | `src/winery_shop_data.o(.rodata)` | [嵌入文本] | `data/text/jp/winery_shop.cc` | 文本 `9` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gWineryShopCatalog` |
| `0x080FE182`–`0x080FE183` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FE184`–`0x080FE39D` | `src/special_merchant_shop_data.o(.rodata)` | [嵌入文本] | `data/text/jp/special_merchant_shop.cc` | 文本 `9` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gSpecialMerchantShopCatalog` |
| `0x080FE39E`–`0x080FE39F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FE3A0`–`0x080FE539` | `src/beach_cafe_shop_data.o(.rodata)` | [嵌入文本] | `data/text/jp/beach_cafe_shop.cc` | 文本 `7` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gBeachCafeShopMenu` |
| `0x080FE53A`–`0x080FE53B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FE53C`–`0x080FE69E` | `src/blacksmith_menu_data.o(.rodata)` | [嵌入文本] | `data/text/jp/blacksmith.cc` | 文本 `12` 项（详见下方索引） |
| `0x080FE69F`–`0x080FE6A3` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 5 字节 |
| `0x080FE6A4`–`0x080FEC8D` | `src/blacksmith_data.o(.rodata)` | [嵌入文本] | `data/text/jp/blacksmith.cc` | 文本 `20` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gBlacksmithMenuHeader`, `gBlacksmithCatalog` |
| `0x080FEC8E`–`0x080FEC8F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FEC90`–`0x080FF505` | `src/carpenter_data.o(.rodata)` | [嵌入文本] | `data/text/common/carpenter.cc`<br>`data/text/jp/carpenter.cc` | 文本 `52` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gCarpenterCatalog` |
| `0x080FF506`–`0x080FF507` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FF508`–`0x080FF9A1` | `src/livestock_shop.o(.rodata)` | [嵌入文本] | `data/text/jp/livestock_shop.cc` | 文本 `39` 项（详见下方索引）<br>`gLivestockShopCatalog` |
| `0x080FF9A2`–`0x080FF9A3` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FF9A4`–`0x080FFADD` | `data/text/home_storage.o(.rodata)` | [文本对象] | `data/text/jp/home_storage.cc` | 文本 `20` 项（详见下方索引）<br>运行时字符串 `5` 项 |
| `0x080FFADE`–`0x080FFADF` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FFAE0`–`0x080FFD52` | `src/blacksmith_upgrade_data.o(.rodata)` | [嵌入文本] | `data/text/jp/blacksmith.cc` | 文本 `19` 项（详见下方索引） |
| `0x080FFD53`–`0x080FFD53` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x080FFD54`–`0x080FFE6D` | `data/text/gift_wrap.o(.rodata)` | [文本对象] | `data/text/jp/gift_wrap.cc` | 文本 `11` 项（详见下方索引）<br>运行时字符串 `2` 项 |
| `0x080FFE6E`–`0x080FFE6F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FFE70`–`0x081005D5` | `src/link_communication_data.o(.rodata)` | [嵌入文本 / 数据] | `data/text/jp/link_communication.cc`<br>`src/link_communication_data.cc` | 文本 `17` 项（详见下方索引）<br>运行时字符串 `3` 项<br>`gUnk_081007AC`, `gUnk_081007D4`, `gUnk_081007FC`, `gUnk_08100824`, `gUnk_0810084C`, `gUnk_08100874`, … +11<br>`gLinkCommunicationGameCodeA4N`, `gLinkCommunicationGameCodeGYW` |
| `0x081005D6`–`0x081005D7` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x081005D8`–`0x081005D9` | `src/cooking_recipe_inventory_data.o(.rodata.cooking_recipe_inventory_page_break)` | [嵌入文本] | `data/text/common/cooking_recipe_inventory.cc` | 文本 `1` 项（详见下方索引） |
| `0x081005DA`–`0x081005E9` | `src/cooking_recipe_inventory_data.o(.rodata.cooking_recipe_inventory_utensil_values)` | [数据] | `data/text/common/cooking_recipe_inventory.cc` | `gCookingRecipeInventoryUtensilValues` |
| `0x081005EA`–`0x081008F8` | `data/text/recovery_status.o(.rodata)` | [文本对象] | `data/text/jp/recovery_status.cc` | 文本 `2` 项（详见下方索引） |
| `0x081008F9`–`0x081008FB` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 3 字节 |
| `0x081008FC`–`0x08100C23` | `data/text/cooking.o(.rodata)` | [文本对象] | `data/text/jp/cooking.cc` | 文本 `28` 项（详见下方索引） |
| `0x08100C24`–`0x08100C47` | `src/cooking_recipe_inventory_data.o(.rodata.cooking_recipe_inventory_mask_entries)` | [数据] | `data/text/common/cooking_recipe_inventory.cc` | `gCookingRecipeInventoryMaskEntries` |
| `0x08100C48`–`0x08103191` | `src/cooking_recipe_inventory_data.o(.rodata)` | [数据] | `data/text/common/cooking_recipe_inventory.cc` | 运行时字符串 `2` 项<br>`gCookingRecipeDefinitions`, `gCookingRecipeDefinitionPayload` |
| `0x08103192`–`0x08103193` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08103194`–`0x0810319A` | `src/animal.o(.rodata.animal_unnamed)` | [嵌入文本] | `data/text/common/animal.cc` | 文本 `1` 项（详见下方索引） |
| `0x0810319B`–`0x0810319B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x0810319C`–`0x081031FB` | `src/livestock.o(.rodata.livestock_day_update)` | [数据] | `src/livestock.c/.cc` | `gChickenDayUpdateInfo`, `gCowDayUpdateInfo`, `gSheepDayUpdateInfo` |
| `0x081031FC`–`0x08103201` | `src/code_actor_0809C3E0.o(.rodata.actor_state_max_values)` | [数据] | `src/code_actor_0809C3E0.c/.cc` | `gActorStateMaxValues` |
| `0x08103202`–`0x08103203` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08103204`–`0x081032C1` | `src/code_actor_0809C3E0.o(.rodata)` | [数据] | `src/code_actor_0809C3E0.c/.cc` | 运行时字符串 `2` 项<br>`gActorDataSelectionEntries` |
| `0x081032C2`–`0x081032C3` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x081032C4`–`0x08103508` | `data/text/fishing_results.o(.rodata)` | [文本对象] | `data/text/jp/fishing_results.cc` | 文本 `59` 项（详见下方索引） |
| `0x08103509`–`0x0810350B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 3 字节 |
| `0x0810350C`–`0x081035F7` | `src/fishing_results_data.o(.rodata.fishing_record_names)` | [数据] | `src/fishing_results_data.c/.cc` | `gFishingRecordNames` |
| `0x081035F8`–`0x08103601` | `src/fishing_results_data.o(.rodata)` | [数据] | `src/fishing_results_data.c/.cc` | 运行时字符串 `1` 项 |
| `0x08103602`–`0x08103603` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08103604`–`0x08103BFB` | `src/code_actor_0809BFE8.o(.rodata)` | [数据] | `src/code_actor_0809BFE8.c/.cc` | 运行时字符串 `1` 项<br>`gUnk_08103B10`, `gUnk_08103B38`, `gUnk_08103C3C`, `gUnk_08103C74`, `gUnk_08103F84`, `gUnk_08103F98`, … +3 |
| `0x08103BFC`–`0x08103BFC` | `src/character_names_data.o(.rodata.character_names_empty)` | [嵌入文本] | `src/character_names_data.c/.cc` | 文本 `1` 项（详见下方索引） |
| `0x08103BFD`–`0x08103C1A` | `src/bachelorette.o(.rodata)` | [数据] | `src/bachelorette.c/.cc` | `gUnk_BacheloretteLoveThresholds00`, `gUnk_BacheloretteLoveThresholds01`, `gUnk_BacheloretteLoveThresholds02`, `gUnk_BacheloretteLoveThresholds03`, `gUnk_BacheloretteLoveThresholds04`, `gUnk_BacheloretteLoveThresholds05` |
| `0x08103C1B`–`0x08103C1B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x08103C1C`–`0x08103D9A` | `data/text/character_names.o(.rodata)` | [文本对象] | `data/text/jp/character_names.cc` | 文本 `41` 项（详见下方索引） |
| `0x08103D9B`–`0x08103D9B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x08103D9C`–`0x08103EF3` | `src/character_names_data.o(.rodata.character_name_entries)` | [数据] | `src/character_names_data.c/.cc` | `gCharacterNameEntries` |
| `0x08103EF4`–`0x08103EFD` | `src/character_names_data.o(.rodata)` | [数据] | `src/character_names_data.c/.cc` | 运行时字符串 `1` 项 |
| `0x08103EFE`–`0x08103EFF` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08103F00`–`0x08104479` | `src/field_data.o(.rodata.field_item_records)` | [数据] | `src/field_data.c/.cc` | 运行时字符串 `1` 项<br>`gUnk_081043BC` |
| `0x0810447A`–`0x0810447B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x0810447C`–`0x08104955` | `data/text/calendar_events.o(.rodata)` | [文本对象] | `data/text/jp/calendar_events.cc` | 文本 `22` 项（详见下方索引）<br>运行时字符串 `2` 项 |
| `0x08104956`–`0x08104957` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08104958`–`0x08104991` | `data/text/possessive_labels.o(.rodata)` | [文本对象] | `data/text/jp/possessive_labels.cc` | 文本 `6` 项（详见下方索引）<br>运行时字符串 `1` 项 |
| `0x08104992`–`0x08104993` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08104994`–`0x08104998` | `data/text/random_item.o(.rodata)` | [文本对象] | `data/text/jp/random_item.cc` | 文本 `1` 项（详见下方索引） |
| `0x08104999`–`0x0810499B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 3 字节 |
| `0x0810499C`–`0x081049BB` | `src/fishing_results_data.o(.rodata.fishing_record_article_ids)` | [数据] | `src/fishing_results_data.c/.cc` | `gFishingRecordArticleIds` |
| `0x081049BC`–`0x081049F3` | `src/field_data.o(.rodata.field_plot_position_values)` | [数据] | `src/field_data.c/.cc` | `gFieldPlotPositionValues` |
| `0x081049F4`–`0x08104A16` | `src/random_item.o(.rodata.random_item_selection_weights)` | [数据] | `src/random_item.c/.cc` | `gRandomItemSelectionWeights` |
| `0x08104A17`–`0x08104A17` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x08104A18`–`0x08105177` | `src/random_item.o(.rodata.random_item_candidate_configurations)` | [数据] | `src/random_item.c/.cc` | `gRandomItemCandidateConfigurations` |
| `0x08105178`–`0x08105181` | `src/random_item.o(.rodata)` | [数据] | `src/random_item.c/.cc` | 运行时字符串 `1` 项 |
| `0x08105182`–`0x08105183` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08105184`–`0x08105243` | `src/field_data.o(.rodata.field_plot_position_rules)` | [数据] | `src/field_data.c/.cc` | `gFieldPlotPositionRules` |
| `0x08105244`–`0x0810524D` | `src/field_data.o(.rodata)` | [数据] | `src/field_data.c/.cc` | 运行时字符串 `1` 项 |
| `0x0810524E`–`0x0810524F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08105250`–`0x0810528F` | `src/code_0800E2E4.o(.rodata.time_of_day_transition_table)` | [数据] | `src/code_0800E2E4.c/.cc` | `gTimeOfDayTransitionTables` |
| `0x08105290`–`0x08105A23` | `src/code_0800E2E4.o(.rodata.time_of_day_transition_records)` | [数据] | `src/code_0800E2E4.c/.cc` | `gTimeOfDayTransitionRecords_Spring_Morning`, `gTimeOfDayTransitionRecords_Spring_Afternoon`, `gTimeOfDayTransitionRecords_Spring_Evening`, `gTimeOfDayTransitionRecords_Spring_Night`, `gTimeOfDayTransitionRecords_Summer_Morning`, `gTimeOfDayTransitionRecords_Summer_Afternoon`, … +10 |
| `0x08105A24`–`0x08106473` | `src/map_data.o(.rodata.map_data)` | [数据] | `src/map_data.c/.cc` | `gMapData` |
| `0x08106474`–`0x08106C23` | `src/field_data.o(.rodata.field_render_rect_descriptors)` | [数据] | `src/field_data.c/.cc` | `gFieldRenderRectDescriptors` |
| `0x08106C24`–`0x08106D4B` | `src/farm_house.o(.rodata.farm_house_tile_patches)` | [数据] | `src/farm_house.c/.cc` | `gFarmHouseTilePatchData` |
| `0x08106D4C`–`0x08106E7F` | `src/farm_house.o(.rodata.farm_house_visual_descriptors)` | [数据] | `src/farm_house.c/.cc` | `gFarmHouseVisualDescriptors` |
| `0x08106E80`–`0x08106E97` | `src/farm_house.o(.rodata.farm_house_tile_patch_animations)` | [数据] | `src/farm_house.c/.cc` | `gFarmHouseTilePatchAnimations` |
| `0x08106E98`–`0x08106E9F` | `src/field_data.o(.rodata.field_render_resource_first_values)` | [数据] | `src/field_data.c/.cc` | `gUnk_FieldRenderResource_158`, `gUnk_FieldRenderResource_159` |
| `0x08106EA0`–`0x08106EA3` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 4 字节 |
| `0x08106EA4`–`0x08106EAB` | `src/field_data.o(.rodata.field_render_resource_second_values)` | [数据] | `src/field_data.c/.cc` | `gUnk_FieldRenderResource_177`, `gUnk_FieldRenderResource_178` |
| `0x08106EAC`–`0x08106EB7` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 12 字节 |
| `0x08106EB8`–`0x08106ECD` | `src/field_data.o(.rodata.field_render_resource_runtime_strings)` | [数据] | `src/field_data.c/.cc` | 运行时字符串 `2` 项 |
| `0x08106ECE`–`0x08106ECF` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08106ED0`–`0x08106F0B` | `src/field_data.o(.rodata.field_render_parallel_tables)` | [数据] | `src/field_data.c/.cc` | `gFieldRenderParallelTables` |
| `0x08106F0C`–`0x08106F6B` | `src/field_data.o(.rodata.field_render_patch_arguments)` | [数据] | `src/field_data.c/.cc` | `gFieldRenderPatchArgumentData` |
| `0x08106F6C`–`0x08106F75` | `src/field_data.o(.rodata.field_render_patch_arguments_after)` | [数据] | `src/field_data.c/.cc` | 运行时字符串 `1` 项 |
| `0x08106F76`–`0x08106F7E` | `src/farm_house.o(.rodata.farm_house_style_nibble_lookup)` | [数据] | `src/farm_house.c/.cc` | `gFarmHouseStyleNibbleLookupData` |
| `0x08106F7F`–`0x08106F7F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x08106F80`–`0x08106F97` | `src/bachelorette.o(.rodata.bachelorette_marriage_candidate_character_ids)` | [数据] | `src/bachelorette.c/.cc` | `gMarriageCandidateCharacterIds` |
| `0x08106F98`–`0x08106F9F` | `src/field_data.o(.rodata.field_render_seasonal_record_ranges)` | [数据] | `src/field_data.c/.cc` | `gFieldRenderSeasonalRecordRanges` |
| `0x08106FA0`–`0x08106FE7` | `src/field_data.o(.rodata.field_render_lookup_values)` | [数据] | `src/field_data.c/.cc` | `gUnk_FieldRenderLookupValues` |
| `0x08106FE8`–`0x0810703D` | `src/field_data.o(.rodata.field_render_runtime_strings)` | [嵌入文本] | `src/field_data.c/.cc` | 文本 `1` 项（详见下方索引）<br>运行时字符串 `7` 项 |
| `0x0810703E`–`0x08107056` | `src/field_data.o(.rodata.field_render_sorted_values)` | [数据] | `src/field_data.c/.cc` | `gUnk_FieldRenderSortedValues` |
| `0x08107057`–`0x08107057` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x08107058`–`0x0810706D` | `src/field_data.o(.rodata.field_render_sorted_values_runtime_strings)` | [数据] | `src/field_data.c/.cc` | 运行时字符串 `2` 项 |
| `0x0810706E`–`0x0810706F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08107070`–`0x081070AB` | `src/field_data.o(.rodata.unk_080AE894_values)` | [数据] | `src/field_data.c/.cc` | `gUnk_080AE894InitialValues`, `gUnk_080AE894LayoutValues` |
| `0x081070AC`–`0x081070AE` | `src/field_data.o(.rodata.unk_080B0708_default_glyph)` | [嵌入文本] | `src/field_data.c/.cc` | 文本 `1` 项（详见下方索引） |
| `0x081070AF`–`0x081070AF` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x081070B0`–`0x081070CB` | `src/field_data.o(.rodata.unk_080B09B0_index_values)` | [数据] | `src/field_data.c/.cc` | `gUnk_080B09B0IndexValues` |
| `0x081070CC`–`0x081070F3` | `src/field_data.o(.rodata.unk_080B0BB8_values)` | [数据] | `src/field_data.c/.cc` | `gUnk_080B0BB8FirstValues`, `gUnk_080B0BB8SecondValues` |
| `0x081070F4`–`0x0810737A` | `data/text/harvest_sprite_minigames.o(.rodata)` | [文本对象] | `data/text/jp/harvest_sprite_minigames.cc` | 文本 `14` 项（详见下方索引） |
| `0x0810737B`–`0x0810737F` | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_animal_husbandry_match_values)` | [数据] | `src/harvest_sprite.c/.cc` | `gUnk_HarvestSpriteMiniGameAnimalHusbandryMatchValues` |
| `0x08107380`–`0x081073AB` | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_animal_husbandry_u16_tables)` | [数据] | `src/harvest_sprite.c/.cc` | `gUnk_HarvestSpriteMiniGameAnimalHusbandrySelectionValues`, `gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues0`, `gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues1`, `gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues2`, `gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues3` |
| `0x081073AC`–`0x081073B5` | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_animal_husbandry_runtime)` | [数据] | `src/harvest_sprite.c/.cc` | 运行时字符串 `1` 项 |
| `0x081073B6`–`0x081073B8` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 3 字节 |
| `0x081073B9`–`0x081074BC` | `data/text/chicken_festival.o(.rodata)` | [文本对象] | `data/text/jp/chicken_festival.cc` | 文本 `1` 项（详见下方索引） |
| `0x081074BD`–`0x081074BF` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 3 字节 |
| `0x081074C0`–`0x081075E9` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` | [文本对象] | `data/text/jp/harvest_sprite_minigames.cc` | 文本 `11` 项（详见下方索引） |
| `0x081075EA`–`0x08107619` | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_chicken_festival_values)` | [数据] | `src/harvest_sprite.c/.cc` | `gUnk_HarvestSpriteMiniGameChickenFestivalValues` |
| `0x0810761A`–`0x0810761D` | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_chicken_festival_offsets)` | [数据] | `src/harvest_sprite.c/.cc` | `gUnk_HarvestSpriteMiniGameChickenFestivalOffsets` |
| `0x0810761E`–`0x0810761F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08107620`–`0x08107800` | `data/text/harvest_sprite_minigames_chicken_festival_instructions.o(.rodata)` | [文本对象] | `data/text/jp/harvest_sprite_minigames.cc` | 文本 `7` 项（详见下方索引） |
| `0x08107801`–`0x08107803` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 3 字节 |
| `0x08107804`–`0x081078DF` | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_chicken_festival_post_text_data)` | [嵌入文本] | `src/harvest_sprite.c/.cc` | 文本 `1` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gUnk_080BAC9CValues`, `gUnk_080BB890FirstValues`, `gUnk_080BB890TableValues`, `gUnk_080BB890LastValues`, `gUnk_080BC288Values`, `gUnk_080BE954Values` |
| `0x081078E0`–`0x08107A5A` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` | [文本对象] | `data/text/jp/harvest_sprite_minigames.cc` | 文本 `11` 项（详见下方索引） |
| `0x08107A5B`–`0x08107A5B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x08107A5C`–`0x08107AA8` | `data/text/harvest_sprite_minigames_harvest_results.o(.rodata)` | [文本对象] | `data/text/jp/harvest_sprite_minigames.cc` | 文本 `3` 项（详见下方索引） |
| `0x08107AA9`–`0x08107AA9` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x08107AAA`–`0x08107ABF` | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_harvest_results_first_values)` | [数据] | `src/harvest_sprite.c/.cc` | `gUnk_080C09D8Values` |
| `0x08107AC0`–`0x08107ACD` | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_harvest_results_second_values)` | [数据] | `src/harvest_sprite.c/.cc` | `gUnk_080C0B58Values` |
| `0x08107ACE`–`0x08107ACF` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08107AD0`–`0x08107B1B` | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_harvest_results_post_values)` | [嵌入文本] | `src/harvest_sprite.c/.cc` | 文本 `1` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gUnk_080C3B18Values`, `gUnk_080C3B18IndexValues` |
| `0x08107B1C`–`0x08107D36` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` | [文本对象] | `data/text/jp/harvest_sprite_minigames.cc` | 文本 `11` 项（详见下方索引） |
| `0x08107D37`–`0x08107D37` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x08107D38`–`0x08107D88` | `data/text/harvest_sprite_minigames_watering_results.o(.rodata)` | [文本对象] | `data/text/jp/harvest_sprite_minigames.cc` | 文本 `3` 项（详见下方索引） |
| `0x08107D89`–`0x08107D89` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x08107D8A`–`0x08107DAB` | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_watering_results_values)` | [数据] | `src/harvest_sprite.c/.cc` | `gUnk_080C7B38Values`, `gUnk_080C7B64Values` |
| `0x08107DAC`–`0x081189D3` | `src/reference_guide.o(.rodata.reference_guide)` | [指南连续块] | `src/reference_guide.cc`<br>`data/text/jp/reference_guide/*.cc (137 页)`<br>连续生成块；按维护规则不展开页内文本或页指针表 | 连续生成区域；按维护规则仅记录起止 |
| `0x081189D4`–`0x081189F1` | `src/shop_common.o(.rodata.shop_common_digit_glyphs)` | [数据] | `src/shop_common.c/.cc` | 运行时字符串 `1` 项<br>`gUnk_080C85A0DigitGlyphs` |
| `0x081189F2`–`0x081189F3` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x081189F4`–`0x08118A13` | `data/text/shop_common.o(.rodata)` | [文本对象] | `data/text/jp/status_ui.cc` | 文本 `3` 项（详见下方索引）<br>`gShopCommonQuantitySuffixTextRef`, `gShopCommonOwnedQuantityLabelTextRef` |
| `0x08118A14`–`0x08118B93` | `src/shop_common.o(.rodata)` | [数据] | `src/shop_common.c/.cc` | 运行时字符串 `2` 项<br>`gUnk_08117838`, `gUnk_0811783C`, `gUnk_0811785C`, `gUnk_08117860`, `gUnk_0811788C` |
| `0x08118B94`–`0x08118CF3` | `data/text/status_ui.o(.rodata)` | [文本对象] | `data/text/jp/status_ui.cc` | 文本 `26` 项（详见下方索引）<br>`gItemStatusWrappedAsPresentTextRef`, `gItemDiscardConfirmTextRef`, `gItemDiscardCannotDiscardTextRef`, `gItemDiscardCursedTextRef` |
| `0x08118CF4`–`0x08118D17` | `src/font.o(.rodata)` | [数据] | `src/font.c/.cc` | 运行时字符串 `1` 项<br>`gFontSpecialGlyph81CD` |
| `0x08118D18`–`0x0813ABCB` | `asm/data/data_080F9EB8.o(.rodata.static_data_after_item_discard)` | [原始 incbin] | `asm/data/data_080F9EB8.s` | `gUnk_FieldRenderResource_146`, `gUnk_FieldRenderResource_147`, `gUnk_MapDataResource_098`, `gUnk_MapDataResource_099`, `gUnk_FieldRenderResource_120`, `gUnk_FieldRenderResource_121`, … +214 |

## JP：文本地址索引

仅列出普通游戏/界面文本的 `gText_*` 标签，仍按 ROM 地址升序。指南文本已按规则合并为上方的一条连续块，故不在此逐条重复；运行时库字面量保留在上方物理表中，但不混入游戏文本索引。

| 地址 | 文本标签 | 维护源 | 链接输入 |
| --- | --- | --- | --- |
| `0x080E7AC8` | `gText_NewGameMenu_Diary` | `data/text/jp/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E7AD0` | `gText_NewGameMenu_Save` | `data/text/jp/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E7AD8` | `gText_NewGameMenu_Load` | `data/text/jp/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E7AE0` | `gText_NewGameMenu_Blank` | `data/text/jp/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E7AE4` | `gText_NewGameMenu_Data1` | `data/text/jp/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E7AEC` | `gText_NewGameMenu_Data2` | `data/text/jp/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E7AF4` | `gText_NewGameMenu_ControlSettings` | `data/text/jp/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E7B00` | `gText_NewGameMenu_ClockDisplay` | `data/text/jp/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E7B0C` | `gText_NewGameMenu_Yes` | `data/text/jp/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E7B14` | `gText_NewGameMenu_No` | `data/text/jp/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E7B1C` | `gText_NewGameMenu_FaceDisplay` | `data/text/jp/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E7B28` | `gText_NewGameMenu_NameDisplay` | `data/text/jp/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E7B7C` | `gText_NewGameStatus_YearSuffix` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7B84` | `gText_NewGameStatus_SeasonSeparator` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7B8C` | `gText_NewGameStatus_DaySuffix` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7B90` | `gText_NewGameStatus_OpenParen` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7B94` | `gText_NewGameStatus_CloseParen` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7B98` | `gText_NewGameStatus_FarmSuffix` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7BA0` | `gText_NewGameStatus_ReadDiary` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7BAC` | `gText_NewGameStatus_WriteDiary` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7BBC` | `gText_NewGameStatus_NoSavedData` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7BD8` | `gText_NewGameHelp_Controls` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7C28` | `gText_NewGameHelp_ClockDisplay` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7C5C` | `gText_NewGameHelp_FaceDisplay` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7CAC` | `gText_NewGameHelp_NameDisplay` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7CFC` | `gText_NewGameSave_SaveFailed` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7D14` | `gText_NewGameSave_LoadFailed` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7D48` | `gText_NewGameSave_LoadPrompt` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7D5C` | `gText_NewGameSave_Affirmative` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7D64` | `gText_NewGameSave_Negative` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7D6C` | `gText_NewGameSave_OverwritePrompt` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7D94` | `gText_NewGameIdentity_PlayerPrefix` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7D9C` | `gText_NewGameIdentity_FarmPrefix` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7DA4` | `gText_NewGameIdentity_DogPrefix` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7DB8` | `gText_NewGameIdentity_BirthMonthSuffix` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7DC0` | `gText_NewGameIdentity_BirthDaySuffix` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7DC4` | `gText_NewGameIdentity_PlayerName` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7DD4` | `gText_NewGameIdentity_PlayerBirthday` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7DE4` | `gText_NewGameIdentity_FarmName` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7DF4` | `gText_NewGameIdentity_DogName` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7E04` | `gText_NewGameIdentity_Confirm` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7E14` | `gText_NewGameIdentity_Yes` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E7E1C` | `gText_NewGameIdentity_No` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E805C` | `gText_NewGameNameEntry_Placeholder` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E806C` | `gText_NewGameNameEntry_NameLabel` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8074` | `gText_NewGameNameEntry_ModeKatakana` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8090` | `gText_NewGameNameEntry_ModeSymbols` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E80AC` | `gText_NewGameNameEntry_ModeHiragana` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E80C8` | `gText_NewGameNameEntry_Confirm` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E80DC` | `gText_NewGameNameEntry_Yes` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E80E4` | `gText_NewGameNameEntry_No` | `data/text/jp/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8B08` | `gText_Item_Tool_IronSickle_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8B14` | `gText_Item_Tool_IronSickle_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8B54` | `gText_Item_Tool_CopperSickle_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8B60` | `gText_Item_Tool_CopperSickle_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8BA4` | `gText_Item_Tool_SilverSickle_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8BB0` | `gText_Item_Tool_SilverSickle_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8BF4` | `gText_Item_Tool_GoldSickle_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8C00` | `gText_Item_Tool_GoldSickle_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8C44` | `gText_Item_Tool_MystrileSickle_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8C54` | `gText_Item_Tool_MystrileSickle_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8C9C` | `gText_Item_Tool_CursedSickle_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8CAC` | `gText_Item_Tool_CursedSickle_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8CF4` | `gText_Item_Tool_BlessedSickle_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8D00` | `gText_Item_Tool_BlessedSickle_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8D24` | `gText_Item_Tool_MythicSickle_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8D30` | `gText_Item_Tool_MythicSickle_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8D74` | `gText_Item_Tool_IronHoe_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8D80` | `gText_Item_Tool_IronHoe_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8DC0` | `gText_Item_Tool_CopperHoe_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8DCC` | `gText_Item_Tool_CopperHoe_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8E10` | `gText_Item_Tool_SilverHoe_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8E1C` | `gText_Item_Tool_SilverHoe_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8E60` | `gText_Item_Tool_GoldHoe_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8E6C` | `gText_Item_Tool_GoldHoe_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8EB0` | `gText_Item_Tool_MystrileHoe_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8EC0` | `gText_Item_Tool_MystrileHoe_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8F0C` | `gText_Item_Tool_CursedHoe_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8F1C` | `gText_Item_Tool_CursedHoe_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8F64` | `gText_Item_Tool_BlessedHoe_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8F70` | `gText_Item_Tool_BlessedHoe_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8F94` | `gText_Item_Tool_MythicHoe_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8FA0` | `gText_Item_Tool_MythicHoe_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8FE8` | `gText_Item_Tool_IronAxe_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E8FF4` | `gText_Item_Tool_IronAxe_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9028` | `gText_Item_Tool_CopperAxe_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9034` | `gText_Item_Tool_CopperAxe_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9064` | `gText_Item_Tool_SilverAxe_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9070` | `gText_Item_Tool_SilverAxe_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E90A0` | `gText_Item_Tool_GoldAxe_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E90AC` | `gText_Item_Tool_GoldAxe_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E90DC` | `gText_Item_Tool_MystrileAxe_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E90EC` | `gText_Item_Tool_MystrileAxe_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9120` | `gText_Item_Tool_CursedAxe_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9130` | `gText_Item_Tool_CursedAxe_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9178` | `gText_Item_Tool_BlessedAxe_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9184` | `gText_Item_Tool_BlessedAxe_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E91A8` | `gText_Item_Tool_MythicAxe_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E91B4` | `gText_Item_Tool_MythicAxe_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E91E4` | `gText_Item_Tool_IronHammer_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E91F4` | `gText_Item_Tool_IronHammer_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E923C` | `gText_Item_Tool_CopperHammer_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E924C` | `gText_Item_Tool_CopperHammer_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9298` | `gText_Item_Tool_SilverHammer_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E92A8` | `gText_Item_Tool_SilverHammer_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E92EC` | `gText_Item_Tool_GoldHammer_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E92FC` | `gText_Item_Tool_GoldHammer_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9340` | `gText_Item_Tool_MystrileHammer_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9354` | `gText_Item_Tool_MystrileHammer_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E939C` | `gText_Item_Tool_CursedHammer_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E93B0` | `gText_Item_Tool_CursedHammer_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E93FC` | `gText_Item_Tool_BlessedHammer_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E940C` | `gText_Item_Tool_BlessedHammer_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9438` | `gText_Item_Tool_MythicHammer_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9448` | `gText_Item_Tool_MythicHammer_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E948C` | `gText_Item_Tool_WateringCan_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9498` | `gText_Item_Tool_WateringCan_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E94B0` | `gText_Item_Tool_CopperWateringCan_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E94C0` | `gText_Item_Tool_CopperWateringCan_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E94DC` | `gText_Item_Tool_SilverWateringCan_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E94EC` | `gText_Item_Tool_SilverWateringCan_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9508` | `gText_Item_Tool_GoldWateringCan_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9518` | `gText_Item_Tool_GoldWateringCan_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9534` | `gText_Item_Tool_MystrileWateringCan_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9548` | `gText_Item_Tool_MystrileWateringCan_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E956C` | `gText_Item_Tool_CursedWateringCan_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9580` | `gText_Item_Tool_CursedWateringCan_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E95CC` | `gText_Item_Tool_BlessedWateringCan_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E95DC` | `gText_Item_Tool_BlessedWateringCan_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9608` | `gText_Item_Tool_MythicWateringCan_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9618` | `gText_Item_Tool_MythicWateringCan_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9638` | `gText_Item_Tool_FishingRod_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9640` | `gText_Item_Tool_FishingRod_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9658` | `gText_Item_Tool_CopperFishingRod_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9664` | `gText_Item_Tool_CopperFishingRod_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9684` | `gText_Item_Tool_SilverFishingRod_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9690` | `gText_Item_Tool_SilverFishingRod_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E96B0` | `gText_Item_Tool_GoldFishingRod_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E96BC` | `gText_Item_Tool_GoldFishingRod_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E96DC` | `gText_Item_Tool_MystrileFishingRod_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E96F0` | `gText_Item_Tool_MystrileFishingRod_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9714` | `gText_Item_Tool_CursedFishingRod_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9724` | `gText_Item_Tool_CursedFishingRod_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E976C` | `gText_Item_Tool_BlessedFishingRod_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E977C` | `gText_Item_Tool_BlessedFishingRod_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E97A4` | `gText_Item_Tool_MythicFishingRod_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E97B4` | `gText_Item_Tool_MythicFishingRod_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E97D4` | `gText_Item_Tool_CowMiraclePotion_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E97E0` | `gText_Item_Tool_CowMiraclePotion_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9814` | `gText_Item_Tool_SheepMiraclePotion_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9820` | `gText_Item_Tool_SheepMiraclePotion_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9854` | `gText_Item_Tool_TurnipSeeds_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9860` | `gText_Item_Tool_TurnipSeeds_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E987C` | `gText_Item_Tool_PotatoSeeds_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E988C` | `gText_Item_Tool_PotatoSeeds_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E98B0` | `gText_Item_Tool_CucumberSeeds_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E98C0` | `gText_Item_Tool_CucumberSeeds_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E98E0` | `gText_Item_Tool_StrawberrySeeds_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E98EC` | `gText_Item_Tool_StrawberrySeeds_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E990C` | `gText_Item_Tool_CabbageSeeds_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E991C` | `gText_Item_Tool_CabbageSeeds_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E993C` | `gText_Item_Tool_TomatoSeeds_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9948` | `gText_Item_Tool_TomatoSeeds_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9968` | `gText_Item_Tool_CornSeeds_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E997C` | `gText_Item_Tool_CornSeeds_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E99A0` | `gText_Item_Tool_OnionSeeds_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E99B0` | `gText_Item_Tool_OnionSeeds_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E99D0` | `gText_Item_Tool_PumpkinSeeds_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E99E0` | `gText_Item_Tool_PumpkinSeeds_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9A00` | `gText_Item_Tool_PineappleSeeds_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9A14` | `gText_Item_Tool_PineappleSeeds_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9A38` | `gText_Item_Tool_EggplantSeeds_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9A44` | `gText_Item_Tool_EggplantSeeds_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9A60` | `gText_Item_Tool_CarrotSeeds_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9A70` | `gText_Item_Tool_CarrotSeeds_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9A90` | `gText_Item_Tool_SweetPotatoSeeds_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9AA0` | `gText_Item_Tool_SweetPotatoSeeds_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9AC4` | `gText_Item_Tool_SpinachSeeds_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9AD8` | `gText_Item_Tool_SpinachSeeds_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9AFC` | `gText_Item_Tool_GreenPepperSeeds_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9B0C` | `gText_Item_Tool_GreenPepperSeeds_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9B2C` | `gText_Item_Tool_GrassSeeds_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9B38` | `gText_Item_Tool_GrassSeeds_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9B60` | `gText_Item_Tool_MoonDropSeeds_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9B74` | `gText_Item_Tool_MoonDropSeeds_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9B9C` | `gText_Item_Tool_PinkCatSeeds_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9BB0` | `gText_Item_Tool_PinkCatSeeds_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9BD8` | `gText_Item_Tool_MagicSeeds_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9BEC` | `gText_Item_Tool_MagicSeeds_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9C14` | `gText_Item_Tool_ToyFlowerSeeds_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9C28` | `gText_Item_Tool_ToyFlowerSeeds_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9C4C` | `gText_Item_Tool_Brush_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9C54` | `gText_Item_Tool_Brush_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9C90` | `gText_Item_Tool_Milker_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9C9C` | `gText_Item_Tool_Milker_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9CD8` | `gText_Item_Tool_Clipper_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9CE8` | `gText_Item_Tool_Clipper_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9D2C` | `gText_Item_Tool_Bell_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9D34` | `gText_Item_Tool_Bell_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9D5C` | `gText_Item_Tool_AnimalMedicine_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9D68` | `gText_Item_Tool_AnimalMedicine_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9D8C` | `gText_Item_Tool_BlueFeather_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9D98` | `gText_Item_Tool_BlueFeather_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9DD0` | `gText_Item_Tool_Pedometer_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9DD8` | `gText_Item_Tool_Pedometer_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9DE4` | `gText_Item_Tool_TeleportStone_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9DEC` | `gText_Item_Tool_TeleportStone_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9E1C` | `gText_Item_Tool_GemOfTheGoddess_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9E28` | `gText_Item_Tool_GemOfTheGoddess_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9E60` | `gText_Item_Tool_GemOfTheKappa_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9E70` | `gText_Item_Tool_GemOfTheKappa_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9EA8` | `gText_Item_Tool_GemOfTruth_Name` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9EB4` | `gText_Item_Tool_GemOfTruth_Description` | `data/text/jp/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA2B8` | `gText_Item_Food_Turnip_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA2C0` | `gText_Item_Food_Turnip_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA2E8` | `gText_Item_Food_Potato_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA2F4` | `gText_Item_Food_Potato_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA320` | `gText_Item_Food_Cucumber_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA32C` | `gText_Item_Food_Cucumber_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA358` | `gText_Item_Food_Strawberry_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA360` | `gText_Item_Food_Strawberry_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA388` | `gText_Item_Food_Cabbage_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA394` | `gText_Item_Food_Cabbage_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA3C0` | `gText_Item_Food_Tomato_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA3C8` | `gText_Item_Food_Tomato_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA3F0` | `gText_Item_Food_Corn_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA400` | `gText_Item_Food_Corn_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA430` | `gText_Item_Food_Onion_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA43C` | `gText_Item_Food_Onion_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA468` | `gText_Item_Food_Pumpkin_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA474` | `gText_Item_Food_Pumpkin_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA4A0` | `gText_Item_Food_Pineapple_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA4B0` | `gText_Item_Food_Pineapple_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA4E0` | `gText_Item_Food_Eggplant_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA4E8` | `gText_Item_Food_Eggplant_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA510` | `gText_Item_Food_Carrot_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA51C` | `gText_Item_Food_Carrot_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA548` | `gText_Item_Food_SweetPotato_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA554` | `gText_Item_Food_SweetPotato_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA580` | `gText_Item_Food_Spinach_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA590` | `gText_Item_Food_Spinach_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA5C0` | `gText_Item_Food_GreenPepper_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA5CC` | `gText_Item_Food_GreenPepper_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA5F8` | `gText_Item_Food_RegularQualityEgg_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA608` | `gText_Item_Food_RegularQualityEgg_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA644` | `gText_Item_Food_GoodQualityEgg_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA654` | `gText_Item_Food_GoodQualityEgg_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA68C` | `gText_Item_Food_HighQualityEgg_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA6A0` | `gText_Item_Food_HighQualityEgg_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA6E0` | `gText_Item_Food_GoldenEgg_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA6E8` | `gText_Item_Food_GoldenEgg_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA71C` | `gText_Item_Food_PEgg_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA724` | `gText_Item_Food_PEgg_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA758` | `gText_Item_Food_XEgg_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA760` | `gText_Item_Food_XEgg_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA794` | `gText_Item_Food_SpaboiledEgg_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA79C` | `gText_Item_Food_SpaboiledEgg_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA7E0` | `gText_Item_Food_MayonnaiseS_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA7F4` | `gText_Item_Food_MayonnaiseS_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA834` | `gText_Item_Food_MayonnaiseM_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA848` | `gText_Item_Food_MayonnaiseM_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA888` | `gText_Item_Food_MayonnaiseL_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA89C` | `gText_Item_Food_MayonnaiseL_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA8DC` | `gText_Item_Food_MayonnaiseG_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA8F0` | `gText_Item_Food_MayonnaiseG_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA930` | `gText_Item_Food_MayonnaiseP_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA944` | `gText_Item_Food_MayonnaiseP_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA984` | `gText_Item_Food_MayonnaiseX_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA998` | `gText_Item_Food_MayonnaiseX_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA9D8` | `gText_Item_Food_MilkS_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EA9E8` | `gText_Item_Food_MilkS_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAA28` | `gText_Item_Food_MilkM_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAA38` | `gText_Item_Food_MilkM_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAA78` | `gText_Item_Food_MilkL_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAA88` | `gText_Item_Food_MilkL_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAAC8` | `gText_Item_Food_MilkG_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAAD8` | `gText_Item_Food_MilkG_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAB18` | `gText_Item_Food_MilkP_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAB28` | `gText_Item_Food_MilkP_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAB68` | `gText_Item_Food_MilkX_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAB78` | `gText_Item_Food_MilkX_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EABB8` | `gText_Item_Food_CheeseS_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EABC8` | `gText_Item_Food_CheeseS_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAC04` | `gText_Item_Food_CheeseM_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAC14` | `gText_Item_Food_CheeseM_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAC50` | `gText_Item_Food_CheeseL_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAC60` | `gText_Item_Food_CheeseL_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAC9C` | `gText_Item_Food_CheeseG_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EACAC` | `gText_Item_Food_CheeseG_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EACE8` | `gText_Item_Food_CheeseP_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EACF8` | `gText_Item_Food_CheeseP_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAD34` | `gText_Item_Food_CheeseX_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAD44` | `gText_Item_Food_CheeseX_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAD80` | `gText_Item_Food_Apple_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAD88` | `gText_Item_Food_Apple_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EADC4` | `gText_Item_Food_Honey_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EADD0` | `gText_Item_Food_Honey_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAE10` | `gText_Item_Food_BambooShoot_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAE1C` | `gText_Item_Food_BambooShoot_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAE5C` | `gText_Item_Food_WildGrapes_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAE6C` | `gText_Item_Food_WildGrapes_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAEB0` | `gText_Item_Food_Mushroom_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAEB8` | `gText_Item_Food_Mushroom_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAEF8` | `gText_Item_Food_PoisonousMushroom_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAF04` | `gText_Item_Food_PoisonousMushroom_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAF48` | `gText_Item_Food_Truffle_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAF54` | `gText_Item_Food_Truffle_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAF8C` | `gText_Item_Food_BlueGrass_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAF94` | `gText_Item_Food_BlueGrass_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAFD0` | `gText_Item_Food_GreenGrass_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAFD8` | `gText_Item_Food_GreenGrass_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB014` | `gText_Item_Food_RedGrass_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB01C` | `gText_Item_Food_RedGrass_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB05C` | `gText_Item_Food_YellowGrass_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB064` | `gText_Item_Food_YellowGrass_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB0A8` | `gText_Item_Food_OrangeGrass_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB0B0` | `gText_Item_Food_OrangeGrass_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB0F0` | `gText_Item_Food_PurpleGrass_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB0F8` | `gText_Item_Food_PurpleGrass_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB13C` | `gText_Item_Food_IndigoGrass_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB144` | `gText_Item_Food_IndigoGrass_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB17C` | `gText_Item_Food_BlackGrass_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB184` | `gText_Item_Food_BlackGrass_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB1C8` | `gText_Item_Food_WhiteGrass_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB1D0` | `gText_Item_Food_WhiteGrass_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB214` | `gText_Item_Food_QueenOfTheNight_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB220` | `gText_Item_Food_QueenOfTheNight_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB25C` | `gText_Item_Food_Bodigizer_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB26C` | `gText_Item_Food_Bodigizer_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB290` | `gText_Item_Food_BodigizerXl_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB2A4` | `gText_Item_Food_BodigizerXl_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB2D4` | `gText_Item_Food_Turbojolt_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB2E4` | `gText_Item_Food_Turbojolt_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB308` | `gText_Item_Food_TurbojoltXl_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB31C` | `gText_Item_Food_TurbojoltXl_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB34C` | `gText_Item_Food_Wine_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB354` | `gText_Item_Food_Wine_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB38C` | `gText_Item_Food_GrapeJuice_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB39C` | `gText_Item_Food_GrapeJuice_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB3E0` | `gText_Item_Food_RiceBall_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB3EC` | `gText_Item_Food_RiceBall_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB424` | `gText_Item_Food_Bread_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB42C` | `gText_Item_Food_Bread_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB460` | `gText_Item_Food_Oil_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB464` | `gText_Item_Food_Oil_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB494` | `gText_Item_Food_Flower_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB49C` | `gText_Item_Food_Flower_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB4D0` | `gText_Item_Food_CurryPowder_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB4DC` | `gText_Item_Food_CurryPowder_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB514` | `gText_Item_Food_MuffinMix_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB520` | `gText_Item_Food_MuffinMix_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB558` | `gText_Item_Food_Chocolate_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB568` | `gText_Item_Food_Chocolate_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB5A4` | `gText_Item_Food_RelaxTeaLeaves_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB5B8` | `gText_Item_Food_RelaxTeaLeaves_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB5F4` | `gText_Item_Food_SugdwApple_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB608` | `gText_Item_Food_SugdwApple_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB65C` | `gText_Item_Food_HmsgbApple_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB670` | `gText_Item_Food_HmsgbApple_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB6CC` | `gText_Item_Food_AepfeApple_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB6E0` | `gText_Item_Food_AepfeApple_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB738` | `gText_Item_Food_BuckwheatFlour_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB740` | `gText_Item_Food_BuckwheatFlour_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB774` | `gText_Item_Food_WildGrapeJuice_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB780` | `gText_Item_Food_WildGrapeJuice_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB7B0` | `gText_Item_Food_Salad_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB7B8` | `gText_Item_Food_Salad_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB7F4` | `gText_Item_Food_CurryRice_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB804` | `gText_Item_Food_CurryRice_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB84C` | `gText_Item_Food_Stew_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB858` | `gText_Item_Food_Stew_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB89C` | `gText_Item_Food_MisoSoup_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB8A4` | `gText_Item_Food_MisoSoup_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB8E0` | `gText_Item_Food_StirFry_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB8EC` | `gText_Item_Food_StirFry_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB92C` | `gText_Item_Food_FriedRice_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB938` | `gText_Item_Food_FriedRice_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB978` | `gText_Item_Food_SavoryPancake_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB984` | `gText_Item_Food_SavoryPancake_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB9C4` | `gText_Item_Food_Sandwich_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB9D4` | `gText_Item_Food_Sandwich_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBA20` | `gText_Item_Food_FruitJuice_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBA34` | `gText_Item_Food_FruitJuice_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBA74` | `gText_Item_Food_VegetableJuice_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBA84` | `gText_Item_Food_VegetableJuice_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBAC0` | `gText_Item_Food_MixedJuice_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBAD4` | `gText_Item_Food_MixedJuice_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBB1C` | `gText_Item_Food_FruitLatte_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBB30` | `gText_Item_Food_FruitLatte_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBB78` | `gText_Item_Food_VegetableLatte_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBB88` | `gText_Item_Food_VegetableLatte_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBBCC` | `gText_Item_Food_MixedLatte_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBBE0` | `gText_Item_Food_MixedLatte_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBC28` | `gText_Item_Food_StrawberryMilk_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBC34` | `gText_Item_Food_StrawberryMilk_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBC78` | `gText_Item_Food_StrawberryJam_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBC88` | `gText_Item_Food_StrawberryJam_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBCCC` | `gText_Item_Food_TomatoJuice_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBCDC` | `gText_Item_Food_TomatoJuice_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBD1C` | `gText_Item_Food_PickledTurnip_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBD2C` | `gText_Item_Food_PickledTurnip_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBD6C` | `gText_Item_Food_FrenchFries_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBD7C` | `gText_Item_Food_FrenchFries_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBDC4` | `gText_Item_Food_Pickles_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBDD8` | `gText_Item_Food_Pickles_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBE20` | `gText_Item_Food_Ketchup_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBE2C` | `gText_Item_Food_Ketchup_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBE6C` | `gText_Item_Food_Popcorn_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBE7C` | `gText_Item_Food_Popcorn_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBEC4` | `gText_Item_Food_CornFlakes_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBED4` | `gText_Item_Food_CornFlakes_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBF20` | `gText_Item_Food_BakedCorn_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBF34` | `gText_Item_Food_BakedCorn_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBF80` | `gText_Item_Food_PineappleJuice_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBF90` | `gText_Item_Food_PineappleJuice_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBFD8` | `gText_Item_Food_PumpkinPudding_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBFE8` | `gText_Item_Food_PumpkinPudding_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC030` | `gText_Item_Food_PumpkinStew_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC044` | `gText_Item_Food_PumpkinStew_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC08C` | `gText_Item_Food_HappyEggplant_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC098` | `gText_Item_Food_HappyEggplant_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC0D4` | `gText_Item_Food_SweetPotatoes_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC0E4` | `gText_Item_Food_SweetPotatoes_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC12C` | `gText_Item_Food_BakedSweetPotato_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC138` | `gText_Item_Food_BakedSweetPotato_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC17C` | `gText_Item_Food_Greens_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC188` | `gText_Item_Food_Greens_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC1CC` | `gText_Item_Food_ScrambledEggs_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC1D4` | `gText_Item_Food_ScrambledEggs_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC20C` | `gText_Item_Food_Omelet_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC218` | `gText_Item_Food_Omelet_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC254` | `gText_Item_Food_OmeletRice_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC260` | `gText_Item_Food_OmeletRice_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC29C` | `gText_Item_Food_BoiledEgg_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC2A4` | `gText_Item_Food_BoiledEgg_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC2DC` | `gText_Item_Food_HotMilk_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC2EC` | `gText_Item_Food_HotMilk_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC328` | `gText_Item_Food_Butter_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC330` | `gText_Item_Food_Butter_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC36C` | `gText_Item_Food_CheeseCake_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC37C` | `gText_Item_Food_CheeseCake_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC3C0` | `gText_Item_Food_CheeseFondue_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC3D4` | `gText_Item_Food_CheeseFondue_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC41C` | `gText_Item_Food_ApplePie_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC42C` | `gText_Item_Food_ApplePie_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC46C` | `gText_Item_Food_AppleJam_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC47C` | `gText_Item_Food_AppleJam_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC4C0` | `gText_Item_Food_AppleSouffl_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC4CC` | `gText_Item_Food_AppleSouffl_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC50C` | `gText_Item_Food_MushroomRice_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC51C` | `gText_Item_Food_MushroomRice_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC560` | `gText_Item_Food_BambooRice_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC570` | `gText_Item_Food_BambooRice_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC5B8` | `gText_Item_Food_TruffleRice_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC5C8` | `gText_Item_Food_TruffleRice_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC610` | `gText_Item_Food_Sushi_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC618` | `gText_Item_Food_Sushi_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC658` | `gText_Item_Food_JamBun_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC664` | `gText_Item_Food_JamBun_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC6A4` | `gText_Item_Food_DinnerRole_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC6B4` | `gText_Item_Food_DinnerRole_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC6F4` | `gText_Item_Food_RaisinBread_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC700` | `gText_Item_Food_RaisinBread_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC740` | `gText_Item_Food_GrapeJam_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC750` | `gText_Item_Food_GrapeJam_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC794` | `gText_Item_Food_CurryBread_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC7A0` | `gText_Item_Food_CurryBread_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC7E0` | `gText_Item_Food_Sashimi_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC7E8` | `gText_Item_Food_Sashimi_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC824` | `gText_Item_Food_GrilledFish_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC82C` | `gText_Item_Food_GrilledFish_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC864` | `gText_Item_Food_ChirashiSushi_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC870` | `gText_Item_Food_ChirashiSushi_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC8B8` | `gText_Item_Food_Pizza_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC8C0` | `gText_Item_Food_Pizza_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC8F8` | `gText_Item_Food_Noodles_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC900` | `gText_Item_Food_Noodles_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC944` | `gText_Item_Food_CurryNoodles_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC954` | `gText_Item_Food_CurryNoodles_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC998` | `gText_Item_Food_TempuraNoodles_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC9A8` | `gText_Item_Food_TempuraNoodles_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC9EC` | `gText_Item_Food_FriedNoodles_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC9F8` | `gText_Item_Food_FriedNoodles_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECA38` | `gText_Item_Food_BuckwheatNoodles_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECA44` | `gText_Item_Food_BuckwheatNoodles_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECA80` | `gText_Item_Food_NoodlesWTempura_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECA8C` | `gText_Item_Food_NoodlesWTempura_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECACC` | `gText_Item_Food_FriedBuckwheatNoodles_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECAD8` | `gText_Item_Food_FriedBuckwheatNoodles_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECB14` | `gText_Item_Food_BuckwheatChips_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECB20` | `gText_Item_Food_BuckwheatChips_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECB5C` | `gText_Item_Food_Cookies_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECB68` | `gText_Item_Food_Cookies_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECBA8` | `gText_Item_Food_ChocolateCookies_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECBB8` | `gText_Item_Food_ChocolateCookies_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECC00` | `gText_Item_Food_Tempura_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECC08` | `gText_Item_Food_Tempura_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECC4C` | `gText_Item_Food_IceCream_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECC5C` | `gText_Item_Food_IceCream_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECC94` | `gText_Item_Food_Cake_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECC9C` | `gText_Item_Food_Cake_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECCD0` | `gText_Item_Food_ChocolateCake_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECCE4` | `gText_Item_Food_ChocolateCake_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECD24` | `gText_Item_Food_RelaxationTea_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECD38` | `gText_Item_Food_RelaxationTea_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECD78` | `gText_Item_Food_Toast_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECD84` | `gText_Item_Food_Toast_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECDC0` | `gText_Item_Food_FrenchToast_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECDD4` | `gText_Item_Food_FrenchToast_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECE18` | `gText_Item_Food_Pudding_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECE20` | `gText_Item_Food_Pudding_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECE54` | `gText_Item_Food_MountainStew_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECE60` | `gText_Item_Food_MountainStew_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECE9C` | `gText_Item_Food_MoonDumplings_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECEA8` | `gText_Item_Food_MoonDumplings_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECEF0` | `gText_Item_Food_RiceCake_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECEF8` | `gText_Item_Food_RiceCake_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECF38` | `gText_Item_Food_RoastedRiceCake_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECF44` | `gText_Item_Food_RoastedRiceCake_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECF84` | `gText_Item_Food_ElliLeaves_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECF8C` | `gText_Item_Food_ElliLeaves_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECFD0` | `gText_Item_Food_FailedDish_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECFE8` | `gText_Item_Food_FailedDish_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED01C` | `gText_Item_Food_FailedDrink_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED02C` | `gText_Item_Food_FailedPotDish_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED044` | `gText_Item_Food_FailedDessert_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED054` | `gText_Item_Food_FailedBread_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED064` | `gText_Item_Food_FailedNoodles_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED074` | `gText_Item_Food_SmallFish_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED07C` | `gText_Item_Food_SmallFish_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED0C0` | `gText_Item_Food_MediumFish_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED0C8` | `gText_Item_Food_MediumFish_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED10C` | `gText_Item_Food_LargeFish_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED114` | `gText_Item_Food_LargeFish_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED158` | `gText_Item_Food_ToastedRiceBall_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED168` | `gText_Item_Food_ToastedRiceBall_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED1AC` | `gText_Item_Food_TempuraRice_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED1B8` | `gText_Item_Food_TempuraRice_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED1FC` | `gText_Item_Food_EggOverRice_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED208` | `gText_Item_Food_EggOverRice_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED248` | `gText_Item_Food_RiceGruel_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED250` | `gText_Item_Food_RiceGruel_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED294` | `gText_Item_Food_Pancakes_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED2A4` | `gText_Item_Food_Pancakes_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED2E8` | `gText_Item_Food_FishSticks_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED2F4` | `gText_Item_Food_FishSticks_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED338` | `gText_Item_Food_CandiedPotato_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED344` | `gText_Item_Food_CandiedPotato_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED388` | `gText_Item_Food_PotatoPancakes_Name` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED394` | `gText_Item_Food_PotatoPancakes_Description` | `data/text/jp/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EDE88` | `gText_Item_Article_MoonDropGrass_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EDE9C` | `gText_Item_Article_MoonDropGrass_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EDED0` | `gText_Item_Article_PinkCatGrass_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EDEE4` | `gText_Item_Article_PinkCatGrass_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EDF18` | `gText_Item_Article_BlueMagicGrass_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EDF30` | `gText_Item_Article_BlueMagicGrass_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EDF68` | `gText_Item_Article_RedMagicGrass_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EDF80` | `gText_Item_Article_RedMagicGrass_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EDFB4` | `gText_Item_Article_ToyFlower_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EDFC4` | `gText_Item_Article_ToyFlower_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EDFF4` | `gText_Item_Article_WoolS_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE004` | `gText_Item_Article_WoolS_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE028` | `gText_Item_Article_WoolM_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE038` | `gText_Item_Article_WoolM_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE05C` | `gText_Item_Article_WoolL_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE06C` | `gText_Item_Article_WoolL_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE090` | `gText_Item_Article_WoolG_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE0A0` | `gText_Item_Article_WoolG_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE0C4` | `gText_Item_Article_WoolP_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE0D4` | `gText_Item_Article_WoolP_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE0F8` | `gText_Item_Article_WoolX_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE108` | `gText_Item_Article_WoolX_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE12C` | `gText_Item_Article_YarnS_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE13C` | `gText_Item_Article_YarnS_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE178` | `gText_Item_Article_YarnM_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE188` | `gText_Item_Article_YarnM_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE1C4` | `gText_Item_Article_YarnL_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE1D4` | `gText_Item_Article_YarnL_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE210` | `gText_Item_Article_YarnG_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE220` | `gText_Item_Article_YarnG_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE25C` | `gText_Item_Article_YarnP_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE26C` | `gText_Item_Article_YarnP_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE2A8` | `gText_Item_Article_YarnX_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE2B8` | `gText_Item_Article_YarnX_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE2F4` | `gText_Item_Article_JunkOre_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE300` | `gText_Item_Article_JunkOre_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE348` | `gText_Item_Article_Copper_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE34C` | `gText_Item_Article_Copper_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE388` | `gText_Item_Article_Silver_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE38C` | `gText_Item_Article_Silver_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE3C8` | `gText_Item_Article_Gold_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE3CC` | `gText_Item_Article_Gold_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE408` | `gText_Item_Article_Mystrile_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE414` | `gText_Item_Article_Mystrile_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE454` | `gText_Item_Article_Orichalc_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE464` | `gText_Item_Article_Orichalc_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE4AC` | `gText_Item_Article_Adamantite_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE4BC` | `gText_Item_Article_Adamantite_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE508` | `gText_Item_Article_MoonStone_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE518` | `gText_Item_Article_MoonStone_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE550` | `gText_Item_Article_SandRose_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE560` | `gText_Item_Article_SandRose_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE598` | `gText_Item_Article_PinkDiamond_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE5AC` | `gText_Item_Article_PinkDiamond_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE5F0` | `gText_Item_Article_Alexandrite_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE604` | `gText_Item_Article_Alexandrite_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE648` | `gText_Item_Article_MythicStone_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE654` | `gText_Item_Article_MythicStone_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE69C` | `gText_Item_Article_Diamond_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE6AC` | `gText_Item_Article_Diamond_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE6E8` | `gText_Item_Article_Emerald_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE6F4` | `gText_Item_Article_Emerald_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE730` | `gText_Item_Article_Ruby_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE738` | `gText_Item_Article_Ruby_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE768` | `gText_Item_Article_Topaz_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE774` | `gText_Item_Article_Topaz_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE7A8` | `gText_Item_Article_Peridot_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE7B4` | `gText_Item_Article_Peridot_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE7E8` | `gText_Item_Article_Fluorite_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE7F0` | `gText_Item_Article_Fluorite_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE820` | `gText_Item_Article_Agate_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE828` | `gText_Item_Article_Agate_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE858` | `gText_Item_Article_Amethyst_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE864` | `gText_Item_Article_Amethyst_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE898` | `gText_Item_Article_HarvestGoddessJewel_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE8A4` | `gText_Item_Article_HarvestGoddessJewel_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE8E0` | `gText_Item_Article_KappaJewel_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE8EC` | `gText_Item_Article_KappaJewel_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE92C` | `gText_Item_Article_JewelOfTruth_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE938` | `gText_Item_Article_JewelOfTruth_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE964` | `gText_Item_Article_TheSpringSun_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE970` | `gText_Item_Article_TheSpringSun_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE9A4` | `gText_Item_Article_TheSummerSun_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE9B0` | `gText_Item_Article_TheAutumnSun_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE9BC` | `gText_Item_Article_TheWinterSun_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE9C8` | `gText_Item_Article_Bracelet_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE9D8` | `gText_Item_Article_Bracelet_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEA14` | `gText_Item_Article_Necklace_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEA20` | `gText_Item_Article_Necklace_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEA58` | `gText_Item_Article_Earrings_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEA64` | `gText_Item_Article_Earrings_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEA9C` | `gText_Item_Article_Broach_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEAA8` | `gText_Item_Article_Broach_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEAE0` | `gText_Item_Article_Weeds_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEAE8` | `gText_Item_Article_Weeds_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEB1C` | `gText_Item_Article_Stones_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEB20` | `gText_Item_Article_Stones_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEB58` | `gText_Item_Article_Branches_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEB5C` | `gText_Item_Article_Branches_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEB94` | `gText_Item_Article_Lithograph_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEBA0` | `gText_Item_Article_Lithograph_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEBE8` | `gText_Item_Article_MessageInABottle_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEBF8` | `gText_Item_Article_MessageInABottle_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEC44` | `gText_Item_Article_Ball_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEC4C` | `gText_Item_Article_Ball_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEC6C` | `gText_Item_Article_PirateTreasure_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEC78` | `gText_Item_Article_PirateTreasure_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EECB0` | `gText_Item_Article_FossilOfFish_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EECC0` | `gText_Item_Article_FossilOfFish_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EED00` | `gText_Item_Article_EmptyCan_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EED08` | `gText_Item_Article_EmptyCan_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EED1C` | `gText_Item_Article_Boots_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EED24` | `gText_Item_Article_Boots_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EED34` | `gText_Item_Article_FishBones_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EED3C` | `gText_Item_Article_FishBones_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EED50` | `gText_Item_Article_KarensWine_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EED60` | `gText_Item_Article_KarensWine_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEDAC` | `gText_Item_Article_PopurisMudBall_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEDBC` | `gText_Item_Article_PopurisMudBall_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEE00` | `gText_Item_Article_AnnsMusicBox_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEE14` | `gText_Item_Article_AnnsMusicBox_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEE60` | `gText_Item_Article_MarysGreatBook_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEE74` | `gText_Item_Article_MarysGreatBook_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEEBC` | `gText_Item_Article_EllisPressedFlower_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEECC` | `gText_Item_Article_EllisPressedFlower_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEF14` | `gText_Item_Article_Album1_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEF20` | `gText_Item_Article_Album1_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEF44` | `gText_Item_Article_Album2_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEF50` | `gText_Item_Article_Album2_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEF74` | `gText_Item_Article_Album3_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEF80` | `gText_Item_Article_Album3_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEFA4` | `gText_Item_Article_Album4_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEFB0` | `gText_Item_Article_Album4_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEFD8` | `gText_Item_Article_Album5_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEFE4` | `gText_Item_Article_Album5_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF010` | `gText_Item_Article_Album6_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF01C` | `gText_Item_Article_Album6_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF048` | `gText_Item_Article_Album7_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF054` | `gText_Item_Article_Album7_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF078` | `gText_Item_Article_Album8_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF084` | `gText_Item_Article_Album8_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF0A8` | `gText_Item_Article_Album9_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF0B4` | `gText_Item_Article_Album9_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF0D8` | `gText_Item_Article_Album10_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF0E8` | `gText_Item_Article_Album10_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF10C` | `gText_Item_Article_Album11_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF11C` | `gText_Item_Article_Album11_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF15C` | `gText_Item_Article_Album12_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF16C` | `gText_Item_Article_Album12_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF1AC` | `gText_Item_Article_Album13_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF1BC` | `gText_Item_Article_Album13_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF1FC` | `gText_Item_Article_Album14_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF20C` | `gText_Item_Article_Album14_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF24C` | `gText_Item_Article_Album15_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF25C` | `gText_Item_Article_Album15_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF29C` | `gText_Item_Article_Bandaid_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF2AC` | `gText_Item_Article_Bandaid_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF2F0` | `gText_Item_Article_Book_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF2F4` | `gText_Item_Article_Book_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF348` | `gText_Item_Article_Perfume_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF350` | `gText_Item_Article_Perfume_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF390` | `gText_Item_Article_Photo_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF398` | `gText_Item_Article_Photo_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF3D8` | `gText_Item_Article_PlantEncyclopedia_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF3E4` | `gText_Item_Article_PlantEncyclopedia_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF428` | `gText_Item_Article_Invitation_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF430` | `gText_Item_Article_Invitation_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF46C` | `gText_Item_Article_Dress_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF474` | `gText_Item_Article_Dress_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF4B4` | `gText_Item_Article_FacialPack_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF4C4` | `gText_Item_Article_FacialPack_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF510` | `gText_Item_Article_SkinLotion_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF518` | `gText_Item_Article_SkinLotion_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF558` | `gText_Item_Article_Sunblock_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF564` | `gText_Item_Article_Sunblock_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF5A4` | `gText_Item_Article_Lumber_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF5AC` | `gText_Item_Article_Lumber_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF5F0` | `gText_Item_Article_GoldenLumber_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF5FC` | `gText_Item_Article_GoldenLumber_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF630` | `gText_Item_Article_AnimalFodder_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF638` | `gText_Item_Article_AnimalFodder_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF670` | `gText_Item_Article_ChickenFeed_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF67C` | `gText_Item_Article_ChickenFeed_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF6A4` | `gText_Item_Article_Lottery_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF6AC` | `gText_Item_Article_Lottery_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF6EC` | `gText_Item_Article_Frisbee_Name` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF6F8` | `gText_Item_Article_Frisbee_Description` | `data/text/jp/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFD52` | `gText_Calendar_SeasonNames` | `data/text/jp/calendar.cc` | `data/text/calendar.o(.rodata.calendar_season)` |
| `0x080EFD60` | `gText_Calendar_None` | `data/text/jp/calendar.cc` | `data/text/calendar.o(.rodata)` |
| `0x080EFD63` | `gText_Calendar_WeekdayNames` | `data/text/jp/calendar.cc` | `data/text/calendar.o(.rodata)` |
| `0x080EFD98` | `gText_CalendarTrailerFallbackNone` | `data/text/jp/calendar.cc` | `data/text/calendar.o(.rodata)` |
| `0x080EFDD0` | `gText_LoadError` | `data/text/jp/load_error.cc` | `data/text/load_error.o(.rodata)` |
| `0x080EFDE8` | `gText_LoadErrorFallbackNone` | `data/text/jp/load_error.cc` | `data/text/load_error.o(.rodata)` |
| `0x080EFDF8` | `gText_HelpMenu_Crops` | `data/text/jp/help_menu.cc` | `src/help_menu.o(.rodata)` |
| `0x080EFE08` | `gText_HelpMenu_Animals` | `data/text/jp/help_menu.cc` | `src/help_menu.o(.rodata)` |
| `0x080EFE18` | `gText_HelpMenu_UsefulTips` | `data/text/jp/help_menu.cc` | `src/help_menu.o(.rodata)` |
| `0x080EFE24` | `gText_HelpMenu_Exit` | `data/text/jp/help_menu.cc` | `src/help_menu.o(.rodata)` |
| `0x080EFEA4` | `gText_AnimalMemorial_LineBreak` | `data/text/jp/animal_memorial.cc` | `data/text/animal_memorial.o(.rodata)` |
| `0x080EFEA8` | `gText_AnimalMemorial_Continue` | `data/text/jp/animal_memorial.cc` | `data/text/animal_memorial.o(.rodata)` |
| `0x080EFEAC` | `gText_AnimalMemorial_PageBreak` | `data/text/jp/animal_memorial.cc` | `data/text/animal_memorial.o(.rodata)` |
| `0x080EFEB0` | `gText_AnimalMemorial_Header` | `data/text/jp/animal_memorial.cc` | `data/text/animal_memorial.o(.rodata)` |
| `0x080EFEB8` | `gText_AnimalMemorial_FarmPrefix` | `data/text/jp/animal_memorial.cc` | `data/text/animal_memorial.o(.rodata)` |
| `0x080EFEC8` | `gText_AnimalMemorial_PassedAway` | `data/text/jp/animal_memorial.cc` | `data/text/animal_memorial.o(.rodata)` |
| `0x080EFEDC` | `gText_AnimalMemorial_NamesIntro` | `data/text/jp/animal_memorial.cc` | `data/text/animal_memorial.o(.rodata)` |
| `0x080EFEF8` | `gText_AnimalMemorial_PrayerIntro` | `data/text/jp/animal_memorial.cc` | `data/text/animal_memorial.o(.rodata)` |
| `0x080EFF0C` | `gText_AnimalMemorial_PrayerEnding` | `data/text/jp/animal_memorial.cc` | `data/text/animal_memorial.o(.rodata)` |
| `0x080EFF28` | `gText_AnimalMemorial_PassedNaturalLife` | `data/text/jp/animal_memorial.cc` | `data/text/animal_memorial.o(.rodata)` |
| `0x080EFF58` | `gText_AnimalMemorialFallbackNone` | `data/text/jp/animal_memorial.cc` | `data/text/animal_memorial.o(.rodata)` |
| `0x080F0090` | `gText_AnimalDataFallbackNone` | `data/text/jp/animal_data.cc` | `src/animal_data.o(.rodata)` |
| `0x080F06E0` | `gText_NotAvailable` | `data/text/jp/entity_ui.cc` | `src/entity_ui.o(.rodata)` |
| `0x080F11D4` | `gText_Moneybags` | `data/text/jp/fixed_labels.cc` | `src/fixed_labels.o(.rodata)` |
| `0x080F11E4` | `gText_UnnamedSetting` | `data/text/jp/fixed_labels.cc` | `src/fixed_labels.o(.rodata)` |
| `0x080F11FC` | `gText_Fallback_Error` | `data/text/common/ui_error.cc` | `src/ui_error.o(.rodata)` |
| `0x080F1204` | `gText_Fallback_None` | `data/text/jp/ui_error.cc` | `src/ui_error.o(.rodata)` |
| `0x080F1244` | `gText_Menu_Diary` | `data/text/jp/menu.cc` | `src/menu_data.o(.rodata)` |
| `0x080F124C` | `gText_Menu_Rucksack` | `data/text/jp/menu.cc` | `src/menu_data.o(.rodata)` |
| `0x080F125C` | `gText_Menu_WorldMap` | `data/text/jp/menu.cc` | `src/menu_data.o(.rodata)` |
| `0x080F1268` | `gText_Menu_FarmMap` | `data/text/jp/menu.cc` | `src/menu_data.o(.rodata)` |
| `0x080F1274` | `gText_Menu_Earnings` | `data/text/jp/menu.cc` | `src/menu_data.o(.rodata)` |
| `0x080F127C` | `gText_Menu_Memo` | `data/text/jp/menu.cc` | `src/menu_data.o(.rodata)` |
| `0x080F1288` | `gText_Menu_Tutorial` | `data/text/jp/menu.cc` | `src/menu_data.o(.rodata)` |
| `0x080F9700` | `gText_AScriptEngine_InvalidStringId` | `data/text/common/script_engine.cc` | `data/text/common/script_engine.o(.rodata)` |
| `0x080F9714` | `gText_ScriptEngineUi_Error` | `data/text/common/script_engine.cc` | `data/text/common/script_engine.o(.rodata)` |
| `0x080F971C` | `gText_ScriptEngineUi_FallbackNone` | `data/text/common/script_engine.cc` | `data/text/common/script_engine.o(.rodata)` |
| `0x080F97E6` | `gText_NameEntry_PresetAnimalNames` | `data/text/jp/new_game.cc` | `data/text/new_game_name_entry_preset.o(.rodata)` |
| `0x080F9994` | `gText_Frisbee_TournamentScoreboard` | `data/text/jp/frisbee.cc` | `data/text/frisbee_scoreboard.o(.rodata)` |
| `0x080F9BD4` | `gText_Frisbee_ExplanationQuestion` | `data/text/jp/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080F9BF0` | `gText_Frisbee_Yes` | `data/text/jp/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080F9BF8` | `gText_Frisbee_No` | `data/text/jp/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080F9C00` | `gText_Frisbee_ExplanationCursorTiming` | `data/text/jp/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080F9C84` | `gText_Frisbee_ExplanationGreenZone` | `data/text/jp/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080F9CCC` | `gText_Frisbee_ExplanationRedZone` | `data/text/jp/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080F9D48` | `gText_Frisbee_ExplanationPractice` | `data/text/jp/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080F9E48` | `gText_Frisbee_ExplanationTournament` | `data/text/jp/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080F9E8C` | `gText_Frisbee_ExplainAgain` | `data/text/jp/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080F9EA8` | `gText_Frisbee_ThrowAgain` | `data/text/jp/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080F9EC4` | `gText_Frisbee_TournamentFinished` | `data/text/jp/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080F9EDC` | `gText_Frisbee_PlayAgain` | `data/text/jp/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080F9EF4` | `gText_Frisbee_DogNoLongerWantsToPlay` | `data/text/jp/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080F9F24` | `gText_Frisbee_FoundItem` | `data/text/jp/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080F9F34` | `gText_Frisbee_FoundNothing` | `data/text/jp/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080F9FD6` | `gText_AnimalFestival_LivestockContestantNames` | `data/text/jp/animal_festival.cc` | `data/text/animal_festival.o(.rodata)` |
| `0x080FA280` | `gText_HorseRace_BuyTicketDeclined` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA294` | `gText_HorseRace_Yes` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA29C` | `gText_HorseRace_No` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA2A4` | `gText_HorseRace_ComeAgain` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA2B4` | `gText_HorseRace_TakeYourTime` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA2D0` | `gText_HorseRace_TicketPurchaseConfirmation` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA2E4` | `gText_HorseRace_TicketPurchaseApproval` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA30C` | `gText_HorseRace_TicketPurchaseEncouragement` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA330` | `gText_HorseRace_ChangeMind` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA344` | `gText_HorseRace_ExplanationQuestion` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA360` | `gText_HorseRace_ExplanationBasics` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA418` | `gText_HorseRace_ExplanationGreenStamina` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA454` | `gText_HorseRace_ExplanationYellowStamina` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA490` | `gText_HorseRace_ExplanationRedStamina` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA4FC` | `gText_HorseRace_ExplanationStaminaRecovery` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA578` | `gText_HorseRace_ExplanationUnderstoodQuestion` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA588` | `gText_HorseRace_ExplanationUnderstood` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA594` | `gText_HorseRace_ExplanationRepeat` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA5A8` | `gText_HorseRace_StartRace` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA5C0` | `gText_HorseRace_RaceStartAnnouncement` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA608` | `gText_HorseRace_RaceResults` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA658` | `gText_HorseRace_RacePayouts` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA688` | `gText_HorseRace_MedalExchangeExplanation` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA73C` | `gText_HorseRace_TicketPurchaseTitle` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA758` | `gText_HorseRace_TicketPurchaseConfirm` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA764` | `gText_HorseRace_TicketPurchaseMedalsToWin` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA77C` | `gText_HorseRace_TicketControls_DPadUpDown` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA78C` | `gText_HorseRace_TicketControls_SelectHorse` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA7A8` | `gText_HorseRace_TicketControls_DPadLeftRight` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA7B8` | `gText_HorseRace_TicketControls_ChangeQuantity` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA7D4` | `gText_HorseRace_TicketControls_LRButtons` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA7E8` | `gText_HorseRace_TicketControls_ChangeQuantityByTen` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA808` | `gText_HorseRace_TicketControls_ChangeQuantityByTenContinuation` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA80C` | `gText_HorseRace_TicketControls_MoveCursorToConfirm` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA828` | `gText_HorseRace_TicketControls_Buy` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA848` | `gText_HorseRace_TicketControls_Cancel` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA9A0` | `gText_HorseRace_PrizeExchangePrompt` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA9B8` | `gText_HorseRace_PrizeExchangeYes` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA9C0` | `gText_HorseRace_PrizeExchangeNo` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA9C8` | `gText_HorseRace_PrizeExchangeComeAgain` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA9D8` | `gText_HorseRace_PrizeExchangeTakeYourTime` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FA9F4` | `gText_HorseRace_PrizeSelectionConfirmation` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAA04` | `gText_HorseRace_PrizeExchangeLeaveConfirmation` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAA18` | `gText_HorseRace_PrizeExchangeInsufficientMedals` | `data/text/jp/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAABC` | `gText_IntroScene_MotherName` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FAAC0` | `gText_IntroScene_MotherTravelGreeting` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FAB08` | `gText_IntroScene_FatherName` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FAB0C` | `gText_IntroScene_FatherFishingInvitation` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FAB5C` | `gText_IntroScene_MotherCannotFindPlayer` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FAB94` | `gText_IntroScene_PlayerResponseWhat` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FABA4` | `gText_IntroScene_OldManName` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FABB0` | `gText_IntroScene_OldManFindsPlayer` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FAC58` | `gText_IntroScene_MotherThanksOldMan` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FAC90` | `gText_IntroScene_FatherExplainsVacation` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FACF8` | `gText_IntroScene_OldManOffersStay` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FAD50` | `gText_IntroScene_FatherAsksAboutStay` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FAD6C` | `gText_IntroScene_OldManWelcomesFamily` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FADB4` | `gText_IntroScene_MotherTellsPlayerToPlay` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FADF0` | `gText_IntroScene_UnknownName` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FADF8` | `gText_IntroScene_UnknownCallsPlayer` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FAE14` | `gText_IntroScene_UnknownFindsPlayer` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FAE1C` | `gText_IntroScene_GirlName` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FAE24` | `gText_IntroScene_GirlThinksPlayerDead` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FAE58` | `gText_IntroScene_GirlInvitesPlayerToPlay` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FAEAC` | `gText_IntroScene_GirlAsksPlayerStory` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FAF28` | `gText_IntroScene_OldManFarewell` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FAFBC` | `gText_IntroScene_OldManRequestsLetter` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FAFF4` | `gText_IntroScene_OldManGivesAddress` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB034` | `gText_IntroScene_GirlSaysGoodbye` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB054` | `gText_IntroScene_GirlAsksPlayerToReturn` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB0B0` | `gText_IntroScene_OldManNotesFriend` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB0F4` | `gText_IntroScene_OldManWaitsForLetter` | `data/text/jp/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB11C` | `gText_FarmStatus_OverviewTitle` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB128` | `gText_FarmStatus_CounterBirds` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB12C` | `gText_FarmStatus_CounterHeads` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB130` | `gText_FarmStatus_CounterAnimals` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB134` | `gText_FarmStatus_CounterSheets` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB138` | `gText_FarmStatus_CounterPieces` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB13C` | `gText_FarmStatus_CounterLongObjects` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB140` | `gText_FarmStatus_GoldUnit` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB144` | `gText_FarmStatus_Healthy` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB14C` | `gText_FarmStatus_Unhappy` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB154` | `gText_FarmStatus_Sick` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB15C` | `gText_FarmStatus_Spring` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB160` | `gText_FarmStatus_Summer` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB164` | `gText_FarmStatus_Autumn` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB168` | `gText_FarmStatus_Winter` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB16C` | `gText_FarmStatus_AgeUnit` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB170` | `gText_FarmStatus_DayUnit` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB174` | `gText_FarmStatus_ChickenList` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB17C` | `gText_FarmStatus_CattleList` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB184` | `gText_FarmStatus_SheepList` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB18C` | `gText_FarmStatus_HarvestSpriteList` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB1A0` | `gText_FarmStatus_DaysRemaining` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB1A8` | `gText_FarmStatus_WorkAssignment` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB1B4` | `gText_FarmStatus_NotAssigned` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB1C4` | `gText_FarmStatus_EarningsReport` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB1D0` | `gText_FarmStatus_PlusSign` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB1D4` | `gText_FarmStatus_MinusSign` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB1D8` | `gText_FarmStatus_MonthSuffix` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB1E0` | `gText_FarmStatus_YearLabel` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB1E8` | `gText_FarmStatus_Income` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB1F0` | `gText_FarmStatus_Expenses` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB1F8` | `gText_FarmStatus_ToolLevelList` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB20C` | `gText_FarmStatus_ToolUpgradeInProgress` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB214` | `gText_FarmStatus_ToolUpgradeAvailable` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB220` | `gText_FarmStatus_PercentSign` | `data/text/jp/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB27C` | `gText_AnimalContest_ChickenConfirmation` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB294` | `gText_AnimalContest_Yes` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB29C` | `gText_AnimalContest_No` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB2A4` | `gText_AnimalContest_CowConfirmation` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB2BC` | `gText_AnimalContest_SheepConfirmation` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB2D4` | `gText_AnimalContest_BabyChickIneligible` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB308` | `gText_AnimalContest_AdultCowIneligible` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB338` | `gText_AnimalContest_AdultSheepIneligible` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB368` | `gText_AnimalContest_SickChickenIneligible` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB39C` | `gText_AnimalContest_SickCowIneligible` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB3CC` | `gText_AnimalContest_SickSheepIneligible` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB3FC` | `gText_AnimalContest_PregnantCowIneligible` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB42C` | `gText_AnimalContest_PregnantSheepIneligible` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB45C` | `gText_AnimalContest_ShornSheepIneligible` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB490` | `gText_AnimalContest_ChickenEntryAccepted` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB4BC` | `gText_AnimalContest_ChickenSelectionPrompt` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB4E4` | `gText_AnimalContest_CowEntryAccepted` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB510` | `gText_AnimalContest_CowSelectionPrompt` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB53C` | `gText_AnimalContest_SheepEntryAccepted` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB568` | `gText_AnimalContest_SheepSelectionPrompt` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB594` | `gText_AnimalContest_ChickenEntryDeclinedQuestion` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB5B0` | `gText_AnimalContest_LivestockEntryDeclinedQuestion` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB5C4` | `gText_AnimalContest_ChickenEntryDeclinedResponse` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB5F0` | `gText_AnimalContest_LivestockEntryDeclinedResponse` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB624` | `gText_AnimalContest_FinalConfirmation` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB634` | `gText_AnimalContest_FinalYes` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB63C` | `gText_AnimalContest_FinalNo` | `data/text/jp/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB764` | `gText_Records_NumberShipped` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB76C` | `gText_Records_ShippedCountSuffix` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB770` | `gText_Records_Fishing` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB778` | `gText_Records_Name` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB780` | `gText_Records_MaximumSize` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB78C` | `gText_Records_Results` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB794` | `gText_Records_FishUnit` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB798` | `gText_Records_MeterUnit` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB79C` | `gText_Records_CentimeterUnit` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB7A4` | `gText_Records_Separator` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB7A8` | `gText_Records_Other` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB7B0` | `gText_Records_MiniGameRecords` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB7CC` | `gText_Records_Harvest` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB7D4` | `gText_Records_AnimalHusbandry` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB7E0` | `gText_Records_Watering` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB7E8` | `gText_Records_Frisbee` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB7F4` | `gText_Records_SecondsUnit` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB7F8` | `gText_Records_IncomeExpenses` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB814` | `gText_Records_HighestAmount` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB820` | `gText_Records_Earned` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB82C` | `gText_Records_Used` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB838` | `gText_Records_GoldUnit` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB83C` | `gText_Records_LongestLivingAnimal` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB858` | `gText_Records_Chicken` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB85C` | `gText_Records_Cow` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB860` | `gText_Records_Sheep` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB864` | `gText_Records_YearsUnit` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB868` | `gText_Records_MonthsUnit` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB870` | `gText_Records_DaysUnit` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB874` | `gText_Records_MineDepth` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB890` | `gText_Records_BelowGround` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB898` | `gText_Records_FloorUnit` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB89C` | `gText_Records_MolesWhacked` | `data/text/jp/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FB938` | `gText_StaffCredits_Line000` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FB944` | `gText_StaffCredits_EmptyLine` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FB948` | `gText_StaffCredits_Line004` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FB95C` | `gText_StaffCredits_Line006` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FB968` | `gText_StaffCredits_Line007` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FB974` | `gText_StaffCredits_Line008` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FB980` | `gText_StaffCredits_Line009` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FB98C` | `gText_StaffCredits_Line010` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FB998` | `gText_StaffCredits_Line011` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FB9A4` | `gText_StaffCredits_Line015` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FB9B0` | `gText_StaffCredits_Line017` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FB9C0` | `gText_StaffCredits_Line018` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FB9D4` | `gText_StaffCredits_Line019` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FB9E0` | `gText_StaffCredits_Line020` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FB9EC` | `gText_StaffCredits_Line021` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FB9FC` | `gText_StaffCredits_Line022` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBA0C` | `gText_StaffCredits_Line026` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBA18` | `gText_StaffCredits_Line028` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBA24` | `gText_StaffCredits_Line032` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBA34` | `gText_StaffCredits_Line034` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBA40` | `gText_StaffCredits_Line035` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBA4C` | `gText_StaffCredits_Line036` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBA58` | `gText_StaffCredits_Line037` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBA64` | `gText_StaffCredits_Line038` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBA70` | `gText_StaffCredits_Line039` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBA7C` | `gText_StaffCredits_Line043` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBA88` | `gText_StaffCredits_Line045` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBA94` | `gText_StaffCredits_Line046` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBAA0` | `gText_StaffCredits_Line047` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBAAC` | `gText_StaffCredits_Line051` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBAC0` | `gText_StaffCredits_Line053` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBACC` | `gText_StaffCredits_Line054` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBAD8` | `gText_StaffCredits_Line055` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBAE4` | `gText_StaffCredits_Line056` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBAF0` | `gText_StaffCredits_Line057` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBAFC` | `gText_StaffCredits_Line058` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBB04` | `gText_StaffCredits_Line059` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBB10` | `gText_StaffCredits_Line063` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBB20` | `gText_StaffCredits_Line065` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBB2C` | `gText_StaffCredits_Line069` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBB3C` | `gText_StaffCredits_Line071` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBB48` | `gText_StaffCredits_Line075` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBB58` | `gText_StaffCredits_Line077` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBB64` | `gText_StaffCredits_Line081` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBB80` | `gText_StaffCredits_Line082` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBB9C` | `gText_StaffCredits_Line084` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBBA4` | `gText_StaffCredits_Line088` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBBBC` | `gText_StaffCredits_Line090` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBBD4` | `gText_StaffCredits_Line094` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBBF0` | `gText_StaffCredits_Line096` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBBFC` | `gText_StaffCredits_Line097` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBC08` | `gText_StaffCredits_Line101` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBC20` | `gText_StaffCredits_Line103` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBC2C` | `gText_StaffCredits_Line104` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBC38` | `gText_StaffCredits_Line108` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBC50` | `gText_StaffCredits_Line110` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBC60` | `gText_StaffCredits_Line114` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBC74` | `gText_StaffCredits_Line116` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBC80` | `gText_StaffCredits_Line126` | `data/text/jp/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FBE9C` | `gText_TownMap_PlayerFarmNameSuffix` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FBEA4` | `gText_TownMap_PlayerFarmDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FBEB8` | `gText_TownMap_PlayerFarmLabel` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FBEC0` | `gText_TownMap_MountainCottageLabel` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FBECC` | `gText_TownMap_SeasideCottageLabel` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FBED8` | `gText_TownMap_TownCottageLabel` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FBEE4` | `gText_TownMap_TimeWindowSeasonDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FBF08` | `gText_TownMap_TimeWindowDateDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FBF2C` | `gText_TownMap_TimeWindowDayDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FBF50` | `gText_TownMap_TimeWindowTimeDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FBF74` | `gText_TownMap_TimeWindowWeatherDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FBF98` | `gText_TownMap_TimeWindowLabel` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FBFA8` | `gText_TownMap_BasilHouseLabel` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FBFB8` | `gText_TownMap_MaryLibraryDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FBFE4` | `gText_TownMap_MaryLibraryHours` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC020` | `gText_TownMap_EllenHouseLabel` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC030` | `gText_TownMap_MayorHouseLabel` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC040` | `gText_TownMap_SupermarketDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC07C` | `gText_TownMap_SupermarketHours` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC0B8` | `gText_TownMap_MineralClinicDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC0F0` | `gText_TownMap_MineralClinicHours` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC12C` | `gText_TownMap_ChurchDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC168` | `gText_TownMap_ChurchHours` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC18C` | `gText_TownMap_AjaWineryDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC1D4` | `gText_TownMap_AjaWineryHours` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC210` | `gText_TownMap_DukeCellarLabel` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC22C` | `gText_TownMap_DougsInnDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC26C` | `gText_TownMap_DougsInnHours` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC2A4` | `gText_TownMap_HarvestSpritesHomeDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC2D0` | `gText_TownMap_HarvestSpritesHomeHours` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC300` | `gText_TownMap_ZackHouseDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC338` | `gText_TownMap_ZackHouseLabel` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC348` | `gText_TownMap_KaiSeasideLodgeDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC370` | `gText_TownMap_KaiSeasideLodgeHours` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC3BC` | `gText_TownMap_SaibaraBlacksmithDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC3F8` | `gText_TownMap_SaibaraBlacksmithHours` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC434` | `gText_TownMap_YodelFarmDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC458` | `gText_TownMap_YodelFarmHours` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC494` | `gText_TownMap_PoultryFarmDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC4B4` | `gText_TownMap_PoultryFarmHours` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC4F0` | `gText_TownMap_WoodcutterHouseDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC524` | `gText_TownMap_WoodcutterHouseHours` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC55C` | `gText_TownMap_LakeMineDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC584` | `gText_TownMap_LakeMineLabel` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC590` | `gText_TownMap_SpringMineDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC5B8` | `gText_TownMap_SpringMineLabel` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC5C4` | `gText_TownMap_HotSpringDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC5E4` | `gText_TownMap_HotSpringLabel` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC5EC` | `gText_TownMap_Empty` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC5F0` | `gText_TownMap_NorthMineralTownDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC620` | `gText_TownMap_NorthMineralTownLabel` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC634` | `gText_TownMap_RearChurchDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC658` | `gText_TownMap_RearChurchLabel` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC660` | `gText_TownMap_RoseSquareDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC68C` | `gText_TownMap_RoseSquareLabel` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC698` | `gText_TownMap_MineralBeachDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC6E4` | `gText_TownMap_MineralBeachLabel` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC6F4` | `gText_TownMap_SouthMineralTownDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC730` | `gText_TownMap_SouthMineralTownLabel` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC744` | `gText_TownMap_ForestDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC75C` | `gText_TownMap_ForestLabel` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC760` | `gText_TownMap_MothersHillPeakDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC790` | `gText_TownMap_MothersHillPeakLabel` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC7A4` | `gText_TownMap_MothersHillDescription` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC7D8` | `gText_TownMap_MothersHillLabel` | `data/text/jp/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCCB8` | `gText_Library_OpeningHours` | `data/text/jp/library.cc` | `src/library_data.o(.rodata.library_opening_hours)` |
| `0x080FD0B0` | `gText_Library_Menu` | `data/text/jp/library.cc` | `src/library_data.o(.rodata.library_menu)` |
| `0x080FD0D0` | `gText_PoultryShop_Empty` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD0D4` | `gText_PoultryShop_BuyChicken` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD0E0` | `gText_PoultryShop_SellChicken` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD150` | `gText_PoultryShop_PageBreak` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD154` | `gText_PoultryShop_StatusSick` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD16C` | `gText_PoultryShop_StatusUnhappy` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD184` | `gText_PoultryShop_StatusHealthy` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD19C` | `gText_PoultryShop_StatusSpacer` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD1A0` | `gText_PoultryShop_Age` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD1B8` | `gText_PoultryShop_Spring` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD1BC` | `gText_PoultryShop_Summer` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD1C0` | `gText_PoultryShop_Autumn` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD1C4` | `gText_PoultryShop_Winter` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD1C8` | `gText_PoultryShop_DailySellingPrice` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD1E0` | `gText_PoultryShop_Currency` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD1E4` | `gText_PoultryShop_InsufficientGold` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD20C` | `gText_PoultryShop_FeedBinFull` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD238` | `gText_PoultryShop_BlankLinePair` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD240` | `gText_PoultryShop_InventoryFull` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD264` | `gText_PoultryShop_CoopFull` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD28C` | `gText_PoultryShop_NameChickenPrompt` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD2B8` | `gText_PoultryShop_NoChickensToSell` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD2E0` | `gText_PoultryShop_NotInterested` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD2F4` | `gText_PoultryShop_PurchaseDeclined` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD308` | `gText_PoultryShop_PricePrompt` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD31C` | `gText_PoultryShop_Yes` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD324` | `gText_PoultryShop_No` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD32C` | `gText_PoultryShop_FeedPurchaseComplete` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD3A0` | `gText_PoultryShop_PurchaseDeliveryPartial` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD418` | `gText_PoultryShop_MedicinePurchaseComplete` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD47C` | `gText_PoultryShop_PurchaseComplete` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD498` | `gText_PoultryShop_ChickenPurchaseComplete` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD4EC` | `gText_PoultryShop_PurchaseMorePrompt` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD500` | `gText_PoultryShop_ChickenSold` | `data/text/jp/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD5C8` | `gText_Supermarket_EquipmentCapacityFull` | `data/text/jp/supermarket.cc` | `src/supermarket_data.o(.rodata)` |
| `0x080FD5F0` | `gText_Supermarket_BlankLinePair` | `data/text/jp/supermarket.cc` | `src/supermarket_data.o(.rodata)` |
| `0x080FD5F8` | `gText_Supermarket_InsufficientGold` | `data/text/jp/supermarket.cc` | `src/supermarket_data.o(.rodata)` |
| `0x080FD620` | `gText_Supermarket_ThankYou` | `data/text/jp/supermarket.cc` | `src/supermarket_data.o(.rodata)` |
| `0x080FD63C` | `gText_Supermarket_PurchaseConfirmation` | `data/text/jp/supermarket.cc` | `src/supermarket_data.o(.rodata)` |
| `0x080FD650` | `gText_Supermarket_PurchaseMorePrompt` | `data/text/jp/supermarket.cc` | `src/supermarket_data.o(.rodata)` |
| `0x080FD664` | `gText_Supermarket_EquipmentDelivery` | `data/text/jp/supermarket.cc` | `src/supermarket_data.o(.rodata)` |
| `0x080FD6B0` | `gText_Supermarket_EquipmentDeliveryPartial` | `data/text/jp/supermarket.cc` | `src/supermarket_data.o(.rodata)` |
| `0x080FD748` | `gText_Supermarket_SeedDelivery` | `data/text/jp/supermarket.cc` | `src/supermarket_data.o(.rodata)` |
| `0x080FD798` | `gText_Supermarket_SeedDeliveryPartial` | `data/text/jp/supermarket.cc` | `src/supermarket_data.o(.rodata)` |
| `0x080FD7F4` | `gText_Supermarket_SeedPurchaseConfirmation` | `data/text/jp/supermarket.cc` | `src/supermarket_data.o(.rodata)` |
| `0x080FD830` | `gText_Clinic_InventoryFull` | `data/text/jp/clinic.cc` | `src/clinic_data.o(.rodata)` |
| `0x080FD878` | `gText_Clinic_BlankLinePair` | `data/text/jp/clinic.cc` | `src/clinic_data.o(.rodata)` |
| `0x080FD880` | `gText_Clinic_InsufficientGold` | `data/text/jp/clinic.cc` | `src/clinic_data.o(.rodata)` |
| `0x080FD8C8` | `gText_Clinic_NoAdditionalPurchase` | `data/text/jp/clinic.cc` | `src/clinic_data.o(.rodata)` |
| `0x080FD8E4` | `gText_Clinic_NoPurchaseRestAdvice` | `data/text/jp/clinic.cc` | `src/clinic_data.o(.rodata)` |
| `0x080FD91C` | `gText_Clinic_PurchaseMorePrompt` | `data/text/jp/clinic.cc` | `src/clinic_data.o(.rodata)` |
| `0x080FD930` | `gText_Clinic_Delivery` | `data/text/jp/clinic.cc` | `src/clinic_data.o(.rodata)` |
| `0x080FD970` | `gText_Clinic_DeliveryPartial` | `data/text/jp/clinic.cc` | `src/clinic_data.o(.rodata)` |
| `0x080FD9B8` | `gText_Clinic_PurchaseComplete` | `data/text/jp/clinic.cc` | `src/clinic_data.o(.rodata)` |
| `0x080FD9E4` | `gText_InnShop_WaterDescription` | `data/text/jp/inn_shop.cc` | `src/inn_shop_data.o(.rodata)` |
| `0x080FDA04` | `gText_InnShop_BoxLunchDescription` | `data/text/jp/inn_shop.cc` | `src/inn_shop_data.o(.rodata)` |
| `0x080FDA30` | `gText_InnShop_Empty` | `data/text/jp/inn_shop.cc` | `src/inn_shop_data.o(.rodata)` |
| `0x080FDA34` | `gText_InnShop_MilkDescription` | `data/text/jp/inn_shop.cc` | `src/inn_shop_data.o(.rodata)` |
| `0x080FDB50` | `gText_InnShop_InsufficientGold` | `data/text/jp/inn_shop.cc` | `src/inn_shop_data.o(.rodata)` |
| `0x080FDB74` | `gText_InnShop_NoOrder` | `data/text/jp/inn_shop.cc` | `src/inn_shop_data.o(.rodata)` |
| `0x080FDBAC` | `gText_InnShop_OrderComplete` | `data/text/jp/inn_shop.cc` | `src/inn_shop_data.o(.rodata)` |
| `0x080FDC40` | `gText_WonShop_ToolCapacityFull` | `data/text/jp/won_shop.cc` | `src/won_shop_data.o(.rodata)` |
| `0x080FDC84` | `gText_WonShop_ItemCapacityFull` | `data/text/jp/won_shop.cc` | `src/won_shop_data.o(.rodata)` |
| `0x080FDCC8` | `gText_WonShop_BlankLinePair` | `data/text/jp/won_shop.cc` | `src/won_shop_data.o(.rodata)` |
| `0x080FDCD0` | `gText_WonShop_ArticleDelivery` | `data/text/jp/won_shop.cc` | `src/won_shop_data.o(.rodata)` |
| `0x080FDD4C` | `gText_WonShop_ArticleDeliveryMultiple` | `data/text/jp/won_shop.cc` | `src/won_shop_data.o(.rodata)` |
| `0x080FDDCC` | `gText_WonShop_PurchaseComplete` | `data/text/jp/won_shop.cc` | `src/won_shop_data.o(.rodata)` |
| `0x080FDDEC` | `gText_WonShop_InsufficientGold` | `data/text/jp/won_shop.cc` | `src/won_shop_data.o(.rodata)` |
| `0x080FDE28` | `gText_WonShop_PurchaseMorePrompt` | `data/text/jp/won_shop.cc` | `src/won_shop_data.o(.rodata)` |
| `0x080FDE5C` | `gText_WonShop_NoPurchase` | `data/text/jp/won_shop.cc` | `src/won_shop_data.o(.rodata)` |
| `0x080FDE84` | `gText_WonShop_NoAdditionalPurchase` | `data/text/jp/won_shop.cc` | `src/won_shop_data.o(.rodata)` |
| `0x080FDEA4` | `gText_WonShop_ToolDelivery` | `data/text/jp/won_shop.cc` | `src/won_shop_data.o(.rodata)` |
| `0x080FDF18` | `gText_WonShop_ToolDeliveryMultiple` | `data/text/jp/won_shop.cc` | `src/won_shop_data.o(.rodata)` |
| `0x080FDFAC` | `gText_WineryShop_InventoryFull` | `data/text/jp/winery_shop.cc` | `src/winery_shop_data.o(.rodata)` |
| `0x080FDFFC` | `gText_WineryShop_BlankLinePair` | `data/text/jp/winery_shop.cc` | `src/winery_shop_data.o(.rodata)` |
| `0x080FE004` | `gText_WineryShop_InsufficientGold` | `data/text/jp/winery_shop.cc` | `src/winery_shop_data.o(.rodata)` |
| `0x080FE034` | `gText_WineryShop_ReturnCustomer` | `data/text/jp/winery_shop.cc` | `src/winery_shop_data.o(.rodata)` |
| `0x080FE058` | `gText_WineryShop_NoPurchase` | `data/text/jp/winery_shop.cc` | `src/winery_shop_data.o(.rodata)` |
| `0x080FE088` | `gText_WineryShop_DeliveryRemainder` | `data/text/jp/winery_shop.cc` | `src/winery_shop_data.o(.rodata)` |
| `0x080FE0EC` | `gText_WineryShop_DeliveryAll` | `data/text/jp/winery_shop.cc` | `src/winery_shop_data.o(.rodata)` |
| `0x080FE14C` | `gText_WineryShop_PurchaseComplete` | `data/text/jp/winery_shop.cc` | `src/winery_shop_data.o(.rodata)` |
| `0x080FE15C` | `gText_WineryShop_PurchaseMorePrompt` | `data/text/jp/winery_shop.cc` | `src/winery_shop_data.o(.rodata)` |
| `0x080FE1FC` | `gText_SpecialMerchantShop_RecordPlayerDescription` | `data/text/jp/special_merchant_shop.cc` | `src/special_merchant_shop_data.o(.rodata)` |
| `0x080FE228` | `gText_SpecialMerchantShop_InsufficientGold` | `data/text/jp/special_merchant_shop.cc` | `src/special_merchant_shop_data.o(.rodata)` |
| `0x080FE240` | `gText_SpecialMerchantShop_InventoryFull` | `data/text/jp/special_merchant_shop.cc` | `src/special_merchant_shop_data.o(.rodata)` |
| `0x080FE278` | `gText_SpecialMerchantShop_BlankLinePair` | `data/text/jp/special_merchant_shop.cc` | `src/special_merchant_shop_data.o(.rodata)` |
| `0x080FE280` | `gText_SpecialMerchantShop_PurchaseComplete` | `data/text/jp/special_merchant_shop.cc` | `src/special_merchant_shop_data.o(.rodata)` |
| `0x080FE2C0` | `gText_SpecialMerchantShop_RecordPlayerDelivery` | `data/text/jp/special_merchant_shop.cc` | `src/special_merchant_shop_data.o(.rodata)` |
| `0x080FE310` | `gText_SpecialMerchantShop_PurchaseCompleteShort` | `data/text/jp/special_merchant_shop.cc` | `src/special_merchant_shop_data.o(.rodata)` |
| `0x080FE328` | `gText_SpecialMerchantShop_ArticleDelivery` | `data/text/jp/special_merchant_shop.cc` | `src/special_merchant_shop_data.o(.rodata)` |
| `0x080FE37C` | `gText_SpecialMerchantShop_PurchaseMorePrompt` | `data/text/jp/special_merchant_shop.cc` | `src/special_merchant_shop_data.o(.rodata)` |
| `0x080FE3A0` | `gText_BeachCafeShop_WaterDescription` | `data/text/jp/beach_cafe_shop.cc` | `src/beach_cafe_shop_data.o(.rodata)` |
| `0x080FE3C0` | `gText_BeachCafeShop_EmptyDescription` | `data/text/jp/beach_cafe_shop.cc` | `src/beach_cafe_shop_data.o(.rodata)` |
| `0x080FE3C4` | `gText_BeachCafeShop_SpaghettiDescription` | `data/text/jp/beach_cafe_shop.cc` | `src/beach_cafe_shop_data.o(.rodata)` |
| `0x080FE3E8` | `gText_BeachCafeShop_SnowConeDescription` | `data/text/jp/beach_cafe_shop.cc` | `src/beach_cafe_shop_data.o(.rodata)` |
| `0x080FE4A0` | `gText_BeachCafeShop_InsufficientGold` | `data/text/jp/beach_cafe_shop.cc` | `src/beach_cafe_shop_data.o(.rodata)` |
| `0x080FE4B8` | `gText_BeachCafeShop_NoOrder` | `data/text/jp/beach_cafe_shop.cc` | `src/beach_cafe_shop_data.o(.rodata)` |
| `0x080FE4F4` | `gText_BeachCafeShop_OrderComplete` | `data/text/jp/beach_cafe_shop.cc` | `src/beach_cafe_shop_data.o(.rodata)` |
| `0x080FE53C` | `gText_Blacksmith_ToolUpgradeMenuLabel` | `data/text/jp/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FE550` | `gText_Blacksmith_ToolUpgradeTitle` | `data/text/jp/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FE55C` | `gText_Blacksmith_Empty` | `data/text/jp/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FE560` | `gText_Blacksmith_MakeMayonnaiseMaker` | `data/text/jp/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FE57C` | `gText_Blacksmith_CostAdamantite` | `data/text/jp/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FE5D0` | `gText_Blacksmith_MakeCheeseMaker` | `data/text/jp/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FE5E8` | `gText_Blacksmith_MakeYarnMaker` | `data/text/jp/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FE600` | `gText_Blacksmith_MakeNecklace` | `data/text/jp/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FE614` | `gText_Blacksmith_CostOrichalc` | `data/text/jp/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FE668` | `gText_Blacksmith_MakeEarrings` | `data/text/jp/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FE67C` | `gText_Blacksmith_MakeBracelet` | `data/text/jp/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FE690` | `gText_Blacksmith_MakeBroach` | `data/text/jp/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FE77C` | `gText_Blacksmith_InsufficientGoldAdamantite` | `data/text/jp/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FE7EC` | `gText_Blacksmith_InsufficientGoldOrichalc` | `data/text/jp/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FE858` | `gText_Blacksmith_MakerFiveDays` | `data/text/jp/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FE888` | `gText_Blacksmith_MakerOneDay` | `data/text/jp/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FE8B8` | `gText_Blacksmith_InsufficientOreAdamantite` | `data/text/jp/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FE950` | `gText_Blacksmith_InsufficientOreOrichalc` | `data/text/jp/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FE9E4` | `gText_Blacksmith_SelectToolAndOre` | `data/text/jp/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FEA18` | `gText_Blacksmith_InsufficientGold` | `data/text/jp/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FEA34` | `gText_Blacksmith_EquipmentFull` | `data/text/jp/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FEA5C` | `gText_Blacksmith_NeedAnythingElse` | `data/text/jp/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FEA78` | `gText_Blacksmith_NothingElse` | `data/text/jp/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FEA94` | `gText_Blacksmith_PurchaseComplete` | `data/text/jp/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FEAB4` | `gText_Blacksmith_Delivery` | `data/text/jp/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FEB30` | `gText_Blacksmith_PurchaseMore` | `data/text/jp/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FEB48` | `gText_Blacksmith_MakeIt` | `data/text/jp/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FEB58` | `gText_Blacksmith_DontMakeIt` | `data/text/jp/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FEB6C` | `gText_Blacksmith_StartWork` | `data/text/jp/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FEBB0` | `gText_Blacksmith_CannotChangeMind` | `data/text/jp/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FEBE4` | `gText_Blacksmith_NoToolToUpgrade` | `data/text/jp/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FEC2C` | `gText_Blacksmith_NoOreToUpgrade` | `data/text/jp/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FEC90` | `gText_Carpenter_Lumber` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FEC98` | `gText_Carpenter_GoldenLumber` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FECA4` | `gText_Carpenter_HouseExtension` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FECB4` | `gText_Carpenter_HouseExtensionFirstCost` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FED08` | `gText_Carpenter_HouseExtensionSecondCost` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FED5C` | `gText_Carpenter_AddBathtub` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FED70` | `gText_Carpenter_BathtubCost` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FEDC4` | `gText_Carpenter_ExpandChickenCoop` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FEDD8` | `gText_Carpenter_ChickenCoopCost` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FEE2C` | `gText_Carpenter_ExpandBarn` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FEE40` | `gText_Carpenter_BarnCost` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FEE98` | `gText_Carpenter_BuildVacationHouse` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FEEA8` | `gText_Carpenter_VacationHouseCost` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FEF00` | `gText_Carpenter_RemodelWindow` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FEF14` | `gText_Carpenter_Rebuild` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FEF20` | `gText_Carpenter_RemodelDoghouse` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FEF34` | `gText_Carpenter_RemodelMailbox` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FEF48` | `gText_Carpenter_SquareWindowWithShutters` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FEF5C` | `gText_Carpenter_WindowCost` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FEF98` | `gText_Carpenter_SquareWindowWithoutShutters` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FEFAC` | `gText_Carpenter_RoundWindow` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FEFB4` | `gText_Carpenter_RedDoghouse` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FEFC0` | `gText_Carpenter_DoghouseCost` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FEFFC` | `gText_Carpenter_BlueDoghouse` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF008` | `gText_Carpenter_StrangeDoghouse` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF01C` | `gText_Carpenter_RedMailbox` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF028` | `gText_Carpenter_MailboxCost` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF064` | `gText_Carpenter_BlueMailbox` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF070` | `gText_Carpenter_StrangeMailbox` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF214` | `gText_Carpenter_InitialPageBreak` | `data/text/common/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF218` | `gText_Carpenter_RebuildRequirements` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF238` | `gText_Carpenter_InsufficientGold` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF250` | `gText_Carpenter_LumberBinFull` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF27C` | `gText_Carpenter_LumberHeader` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF288` | `gText_Carpenter_EquipmentFull` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF2B0` | `gText_Carpenter_GoldenLumberHeader` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF2C0` | `gText_Carpenter_CannotAcceptAnotherJob` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF30C` | `gText_Carpenter_InsufficientLumber` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF328` | `gText_Carpenter_ThreeDayConfirmation` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF35C` | `gText_Carpenter_NeedAnythingElse` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF378` | `gText_Carpenter_AreYouSureNow` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF390` | `gText_Carpenter_SameCurrentShape` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF3AC` | `gText_Carpenter_StoreLumber` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF3E0` | `gText_Carpenter_DeliveryAll` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF430` | `gText_Carpenter_DeliverySome` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF480` | `gText_Carpenter_PurchaseComplete` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF490` | `gText_Carpenter_Build` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF498` | `gText_Carpenter_DontBuild` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF4A4` | `gText_Carpenter_Upgrade` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF4B0` | `gText_Carpenter_DontUpgrade` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF4BC` | `gText_Carpenter_StartUpgradeTomorrow` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF4E8` | `gText_Carpenter_NeedAnythingMore` | `data/text/jp/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF508` | `gText_LivestockShop_Empty` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF50C` | `gText_LivestockShop_BuyCow` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF518` | `gText_LivestockShop_BuySheep` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF524` | `gText_LivestockShop_SellCow` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF530` | `gText_LivestockShop_SellSheep` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF618` | `gText_LivestockShop_PageBreak` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF61C` | `gText_LivestockShop_StatusSick` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF634` | `gText_LivestockShop_StatusUnhappy` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF64C` | `gText_LivestockShop_StatusHealthy` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF664` | `gText_LivestockShop_StatusSpacer` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF668` | `gText_LivestockShop_Age` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF680` | `gText_LivestockShop_Spring` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF684` | `gText_LivestockShop_Summer` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF688` | `gText_LivestockShop_Autumn` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF68C` | `gText_LivestockShop_Winter` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF690` | `gText_LivestockShop_DailySellingPrice` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF6A8` | `gText_LivestockShop_Currency` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF6AC` | `gText_LivestockShop_SecondaryDailySellingPrice` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF6C4` | `gText_LivestockShop_InsufficientGold` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF6E4` | `gText_LivestockShop_FeedBinFull` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF70C` | `gText_LivestockShop_BlankLinePair` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF714` | `gText_LivestockShop_InventoryFull` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF740` | `gText_LivestockShop_BarnFull` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF758` | `gText_LivestockShop_NameAnimalPrompt` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF788` | `gText_LivestockShop_NoCowsToSell` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF7A4` | `gText_LivestockShop_NoSheepToSell` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF7C0` | `gText_LivestockShop_ComeAgain` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF7FC` | `gText_LivestockShop_PurchaseConfirmation` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF810` | `gText_LivestockShop_PricePrompt` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF820` | `gText_LivestockShop_Yes` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF828` | `gText_LivestockShop_No` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF830` | `gText_LivestockShop_FeedPurchaseComplete` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF870` | `gText_LivestockShop_PurchaseDeliveryPartial` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF8BC` | `gText_LivestockShop_PurchaseDeliveryAll` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF900` | `gText_LivestockShop_PurchaseComplete` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF910` | `gText_LivestockShop_AnimalPurchaseComplete` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF944` | `gText_LivestockShop_PurchaseMorePrompt` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF960` | `gText_LivestockShop_PurchaseDeclinedPrefix` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF974` | `gText_LivestockShop_AnimalDelivery` | `data/text/jp/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FF9B0` | `gText_Fridge_EmptyDescription` | `data/text/jp/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x080FF9B4` | `gText_Fridge_WrappedGiftWarning` | `data/text/jp/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x080FF9F4` | `gText_Fridge_Yes` | `data/text/jp/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x080FF9FC` | `gText_Fridge_No` | `data/text/jp/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x080FFA04` | `gText_Fridge_Items` | `data/text/jp/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x080FFA0C` | `gText_Fridge_Title` | `data/text/jp/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x080FFA20` | `gText_HomeStorage_ConfirmationYes` | `data/text/jp/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x080FFA28` | `gText_HomeStorage_ConfirmationNo` | `data/text/jp/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x080FFA30` | `gText_HomeStorage_EmptyDescription` | `data/text/jp/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x080FFA34` | `gText_HomeStorage_CategoryTools` | `data/text/jp/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x080FFA3C` | `gText_HomeStorage_CategoryItems` | `data/text/jp/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x080FFA50` | `gText_Shelf_EmptyDescription` | `data/text/jp/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x080FFA54` | `gText_Shelf_WrappedGiftWarning` | `data/text/jp/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x080FFA94` | `gText_Shelf_Yes` | `data/text/jp/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x080FFA9C` | `gText_Shelf_No` | `data/text/jp/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x080FFAA4` | `gText_Shelf_Items` | `data/text/jp/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x080FFAAC` | `gText_Shelf_Title` | `data/text/jp/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x080FFAC0` | `gText_ToolChest_EmptyDescription` | `data/text/jp/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x080FFAC4` | `gText_ToolChest_HeaderTools` | `data/text/jp/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x080FFACC` | `gText_ToolChest_Title` | `data/text/jp/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x080FFAE0` | `gText_BlacksmithUpgrade_EmptyDescription` | `data/text/jp/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x080FFAE4` | `gText_BlacksmithUpgrade_Tools` | `data/text/jp/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x080FFAEC` | `gText_BlacksmithUpgrade_Items` | `data/text/jp/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x080FFAF4` | `gText_BlacksmithUpgrade_SelectTool` | `data/text/jp/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x080FFB1C` | `gText_BlacksmithUpgrade_CursedTool` | `data/text/jp/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x080FFB54` | `gText_BlacksmithUpgrade_SelectOre` | `data/text/jp/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x080FFB80` | `gText_BlacksmithUpgrade_CannotUpgradeTool` | `data/text/jp/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x080FFB98` | `gText_BlacksmithUpgrade_InvalidUpgradeOre` | `data/text/jp/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x080FFBF0` | `gText_BlacksmithUpgrade_CannotChangeMind` | `data/text/jp/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x080FFC24` | `gText_BlacksmithUpgrade_InsufficientExperience` | `data/text/jp/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x080FFC50` | `gText_BlacksmithUpgrade_AlreadyUpgradedWithOre` | `data/text/jp/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x080FFC88` | `gText_BlacksmithUpgrade_DowngradeConfirmation` | `data/text/jp/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x080FFCCC` | `gText_BlacksmithUpgrade_WorkOrderPrefix` | `data/text/jp/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x080FFCDC` | `gText_BlacksmithUpgrade_WorkOrderGoldSuffix` | `data/text/jp/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x080FFCE4` | `gText_BlacksmithUpgrade_WorkOrderDaysSuffix` | `data/text/jp/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x080FFD04` | `gText_BlacksmithUpgrade_InsufficientGoldPageBreak` | `data/text/jp/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x080FFD08` | `gText_BlacksmithUpgrade_InsufficientGold` | `data/text/jp/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x080FFD44` | `gText_BlacksmithUpgrade_ResultYes` | `data/text/jp/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x080FFD4C` | `gText_BlacksmithUpgrade_ResultNo` | `data/text/jp/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x080FFD60` | `gText_GiftWrap_EmptyDescription` | `data/text/jp/gift_wrap.cc` | `data/text/gift_wrap.o(.rodata)` |
| `0x080FFD64` | `gText_GiftWrap_CannotWrap` | `data/text/jp/gift_wrap.cc` | `data/text/gift_wrap.o(.rodata)` |
| `0x080FFD9C` | `gText_GiftWrap_Confirm` | `data/text/jp/gift_wrap.cc` | `data/text/gift_wrap.o(.rodata)` |
| `0x080FFDAC` | `gText_GiftWrap_Yes` | `data/text/jp/gift_wrap.cc` | `data/text/gift_wrap.o(.rodata)` |
| `0x080FFDB4` | `gText_GiftWrap_No` | `data/text/jp/gift_wrap.cc` | `data/text/gift_wrap.o(.rodata)` |
| `0x080FFDBC` | `gText_GiftWrap_DogWarning` | `data/text/jp/gift_wrap.cc` | `data/text/gift_wrap.o(.rodata)` |
| `0x080FFDD8` | `gText_GiftWrap_Tools` | `data/text/jp/gift_wrap.cc` | `data/text/gift_wrap.o(.rodata)` |
| `0x080FFDE0` | `gText_GiftWrap_Items` | `data/text/jp/gift_wrap.cc` | `data/text/gift_wrap.o(.rodata)` |
| `0x080FFDE8` | `gText_GiftWrap_Recommendation` | `data/text/jp/gift_wrap.cc` | `data/text/gift_wrap.o(.rodata)` |
| `0x080FFE18` | `gText_GiftWrap_Complete` | `data/text/jp/gift_wrap.cc` | `data/text/gift_wrap.o(.rodata)` |
| `0x080FFE48` | `gText_GiftWrap_SelectItem` | `data/text/jp/gift_wrap.cc` | `data/text/gift_wrap.o(.rodata)` |
| `0x080FFE70` | `gText_LinkCommunication_Waiting` | `data/text/jp/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x080FFEBC` | `gText_LinkCommunication_SendingGameData` | `data/text/jp/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x080FFEDC` | `gText_LinkCommunication_TestingConnection` | `data/text/jp/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x080FFEF4` | `gText_LinkCommunication_CannotResendPreviousData` | `data/text/jp/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x080FFF24` | `gText_LinkCommunication_ProceedQuestion` | `data/text/jp/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x080FFF2C` | `gText_LinkCommunication_Yes` | `data/text/jp/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x080FFF34` | `gText_LinkCommunication_No` | `data/text/jp/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x080FFF3C` | `gText_LinkCommunication_WaitingForOtherPlayer` | `data/text/jp/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x080FFF74` | `gText_LinkCommunication_NowSendingData` | `data/text/jp/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x080FFF8C` | `gText_LinkCommunication_DataExchangeFailed` | `data/text/jp/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x080FFFC0` | `gText_LinkCommunication_QuitCommunication` | `data/text/jp/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x080FFFE0` | `gText_LinkCommunication_OtherPlayerCanceled` | `data/text/jp/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x08100004` | `gText_LinkCommunication_IncompatibleGameData` | `data/text/jp/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x08100060` | `gText_LinkCommunication_ExchangeRestriction` | `data/text/jp/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x081000D4` | `gText_LinkCommunication_ActionQuestion` | `data/text/jp/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x081000F4` | `gText_LinkCommunication_Declined` | `data/text/jp/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x08100118` | `gText_LinkCommunication_Complete` | `data/text/jp/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x081005D8` | `gText_Cooking_Recipe_PageBreak` | `data/text/common/cooking_recipe_inventory.cc` | `src/cooking_recipe_inventory_data.o(.rodata.cooking_recipe_inventory_page_break)` |
| `0x081005EA` | `gText_StaminaRecoveryStatus` | `data/text/jp/recovery_status.cc` | `data/text/recovery_status.o(.rodata)` |
| `0x081006EF` | `gText_FatigueRecoveryStatus` | `data/text/jp/recovery_status.cc` | `data/text/recovery_status.o(.rodata)` |
| `0x081008FC` | `gText_Cooking_SeasoningSet` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x0810090C` | `gText_Cooking_CompleteUtensilSelection` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100948` | `gText_Cooking_WrappedGiftDescription` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100974` | `gText_Cooking_FollowRecipe` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100988` | `gText_Cooking_ImproviseRecipe` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x0810099C` | `gText_Cooking_MakeAnotherRecipe` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x081009B0` | `gText_Cooking_NotEnoughIngredients` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x081009C8` | `gText_Cooking_UseTheseIngredients` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x081009DC` | `gText_Cooking_RestartIngredients` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x081009F4` | `gText_Cooking_RestartUtensils` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100A10` | `gText_Cooking_ResultFailure` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100A24` | `gText_Cooking_ResultSuccessNewRecipe` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100A50` | `gText_Cooking_ResultSuccess` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100A64` | `gText_Cooking_ResultComparison` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100A84` | `gText_Cooking_Recipe_MakeThis` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100AA0` | `gText_Cooking_Recipe_LeavePreviousAsIs` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100ABC` | `gText_Cooking_Recipe_ViewCurrent` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100AD0` | `gText_Cooking_Recipe_Rewrite` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100AEC` | `gText_Cooking_Recipe_LeaveNewAsIs` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100B08` | `gText_Cooking_Recipe_ViewNew` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100B24` | `gText_Cooking_Recipe_IngredientsRequired` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100B50` | `gText_Cooking_Recipe_ListTitle` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100B68` | `gText_Cooking_Recipe_Utensils` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100B70` | `gText_Cooking_Recipe_Ingredients` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100B78` | `gText_Cooking_Recipe_UseIngredients` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100B84` | `gText_Cooking_Recipe_Empty` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100B88` | `gText_Cooking_Recipe_StorageHeader` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100B95` | `gText_Cooking_Recipe_SelectionNames` | `data/text/jp/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08103194` | `gText_Animal_Unnamed` | `data/text/common/animal.cc` | `src/animal.o(.rodata.animal_unnamed)` |
| `0x081032C4` | `gText_FishingRecord_PirateFortune` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081032D0` | `gText_FishingRecord_FossilOfFish` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081032E0` | `gText_FishingRecord_PowerBerry` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081032EC` | `gText_FishingRecord_MessageBottle` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081032FC` | `gText_FishingRecord_EmptyCan` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103304` | `gText_FishingRecord_Branch` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103308` | `gText_FishingRecord_FishBones` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103310` | `gText_FishingRecord_Boots` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103318` | `gText_FishingRecord_RockTrout` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103324` | `gText_FishingRecord_Scad` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x0810332C` | `gText_FishingRecord_Fatminnow` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103338` | `gText_FishingRecord_CherrySalmon` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103340` | `gText_FishingRecord_Pigfish` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103348` | `gText_FishingRecord_Sardine` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103350` | `gText_FishingRecord_MountainTrout` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103358` | `gText_FishingRecord_Whitefish` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103360` | `gText_FishingRecord_Eel` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103368` | `gText_FishingRecord_Bitterling` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103374` | `gText_FishingRecord_Bonito` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x0810337C` | `gText_FishingRecord_Fluke` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103384` | `gText_FishingRecord_Filefish` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103390` | `gText_FishingRecord_GoldenCarp` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x0810339C` | `gText_FishingRecord_SilverCarp22` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081033A8` | `gText_FishingRecord_KelpBass` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081033B0` | `gText_FishingRecord_Bighead` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081033BC` | `gText_FishingRecord_Salmon` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081033C4` | `gText_FishingRecord_Mackerel` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081033CC` | `gText_FishingRecord_Needlefish` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081033D4` | `gText_FishingRecord_SpanishMackerel` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081033DC` | `gText_FishingRecord_SauryPike` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081033E4` | `gText_FishingRecord_Dorado` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081033EC` | `gText_FishingRecord_RedSnapper` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081033F4` | `gText_FishingRecord_Cod` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081033FC` | `gText_FishingRecord_Roach` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103408` | `gText_FishingRecord_BrownHakeling` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103410` | `gText_FishingRecord_RainbowTrout` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x0810341C` | `gText_FishingRecord_Herring` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103424` | `gText_FishingRecord_SilverCarp37` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103430` | `gText_FishingRecord_Sandfish` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x0810343C` | `gText_FishingRecord_Flounder` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103444` | `gText_FishingRecord_Blowfish` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x0810344C` | `gText_FishingRecord_BlackBass` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x0810345C` | `gText_FishingRecord_Yellowtail` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103464` | `gText_FishingRecord_Bluegill` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103470` | `gText_FishingRecord_CrucianCarp` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x0810347C` | `gText_FishingRecord_Greenling` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103484` | `gText_FishingRecord_Tuna` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x0810348C` | `gText_FishingRecord_OceanSunfish` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103498` | `gText_FishingRecord_Lionfish` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081034A4` | `gText_FishingRecord_Rockfish` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081034AC` | `gText_FishingRecord_LargeSalmon` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081034B4` | `gText_FishingRecord_Snakehead` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081034C0` | `gText_FishingRecord_LakeSmelt` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081034CC` | `gText_FishingRecord_JapaneseHuchen` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081034D4` | `gText_FishingRecord_Monkfish` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081034E0` | `gText_FishingRecord_Catfish` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081034EC` | `gText_FishingRecord_Carp` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081034F4` | `gText_FishingRecord_Coelacanth` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103504` | `gText_FishingRecord_Squid` | `data/text/jp/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103BFC` | `gText_CharacterName_Empty` | 未在 `data/text` 源中直接命名；请以宿主对象核对 | `src/character_names_data.o(.rodata.character_names_empty)` |
| `0x08103C1C` | `gText_CharacterName_Lillia` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103C24` | `gText_CharacterName_Rick` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103C2C` | `gText_CharacterName_Popuri` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103C34` | `gText_CharacterName_Barley` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103C3C` | `gText_CharacterName_May` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103C44` | `gText_CharacterName_Saibara` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103C50` | `gText_CharacterName_Gray` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103C58` | `gText_CharacterName_Duke` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103C64` | `gText_CharacterName_Manna` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103C6C` | `gText_CharacterName_Basil` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103C74` | `gText_CharacterName_Anna` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103C7C` | `gText_CharacterName_Mary` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103C84` | `gText_CharacterName_Thomas` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103C90` | `gText_CharacterName_Harris` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103C98` | `gText_CharacterName_Ellen` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103CA0` | `gText_CharacterName_Stu` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103CA8` | `gText_CharacterName_Jeff` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103CB0` | `gText_CharacterName_Sasha` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103CBC` | `gText_CharacterName_Karen` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103CC4` | `gText_CharacterName_Doctor` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103CD0` | `gText_CharacterName_Elli` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103CD8` | `gText_CharacterName_Carter` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103CE4` | `gText_CharacterName_Cliff` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103CEC` | `gText_CharacterName_Doug` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103CF4` | `gText_CharacterName_Ann` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103CFC` | `gText_CharacterName_Kai` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103D04` | `gText_CharacterName_Gotz` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103D0C` | `gText_CharacterName_Zack` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103D14` | `gText_CharacterName_Won` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103D1C` | `gText_CharacterName_Gourmet` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103D28` | `gText_CharacterName_HarvestGoddess` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103D34` | `gText_CharacterName_Kappa` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103D3C` | `gText_CharacterName_Van` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103D44` | `gText_CharacterName_LouOrRuby` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103D4C` | `gText_CharacterName_Staid` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103D58` | `gText_CharacterName_Nappy` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103D64` | `gText_CharacterName_Bold` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103D70` | `gText_CharacterName_Chef` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103D7C` | `gText_CharacterName_Aqua` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103D84` | `gText_CharacterName_Hoggy` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08103D90` | `gText_CharacterName_Timid` | `data/text/jp/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x0810447C` | `gText_Calendar_DynamicSeasonNames` | `data/text/jp/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x081044B0` | `gText_Calendar_Festival_NewYearFestival` | `data/text/jp/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x081044F8` | `gText_Calendar_Festival_SpringThanksgiving` | `data/text/jp/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x0810451C` | `gText_Calendar_Festival_SpringHorseRace` | `data/text/jp/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104568` | `gText_Calendar_Festival_CookingFestival` | `data/text/jp/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x081045B0` | `gText_Calendar_Festival_BeachDay` | `data/text/jp/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x081045FC` | `gText_Calendar_Festival_ChickenFestival` | `data/text/jp/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104644` | `gText_Calendar_Festival_CowFestival` | `data/text/jp/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x0810468C` | `gText_Calendar_Festival_FireworksFestival` | `data/text/jp/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x081046D8` | `gText_Calendar_Festival_MusicFestival` | `data/text/jp/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104718` | `gText_Calendar_Festival_HarvestFestival` | `data/text/jp/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104760` | `gText_Calendar_Festival_FullMoonFestival` | `data/text/jp/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x081047AC` | `gText_Calendar_Festival_FallHorseRace` | `data/text/jp/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x081047F8` | `gText_Calendar_Festival_SheepFestival` | `data/text/jp/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104840` | `gText_Calendar_Festival_PumpkinFestival` | `data/text/jp/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104864` | `gText_Calendar_Festival_WinterThanksgiving` | `data/text/jp/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104888` | `gText_Calendar_Festival_StarryNightFestival` | `data/text/jp/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x081048A8` | `gText_Calendar_Festival_YearEndGathering` | `data/text/jp/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x081048DC` | `gText_Calendar_Festival_Marriage` | `data/text/jp/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x081048FC` | `gText_Calendar_Festival_WeddingAnniversary` | `data/text/jp/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x0810491C` | `gText_Calendar_Festival_NoPlans` | `data/text/jp/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104944` | `gText_Calendar_FallbackNone` | `data/text/jp/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104958` | `gText_Possessive_Horse` | `data/text/jp/possessive_labels.cc` | `data/text/possessive_labels.o(.rodata)` |
| `0x08104960` | `gText_Possessive_Cow` | `data/text/jp/possessive_labels.cc` | `data/text/possessive_labels.o(.rodata)` |
| `0x08104968` | `gText_Possessive_Sheep` | `data/text/jp/possessive_labels.cc` | `data/text/possessive_labels.o(.rodata)` |
| `0x08104970` | `gText_Possessive_Chicken` | `data/text/jp/possessive_labels.cc` | `data/text/possessive_labels.o(.rodata)` |
| `0x08104978` | `gText_Possessive_Child` | `data/text/jp/possessive_labels.cc` | `data/text/possessive_labels.o(.rodata)` |
| `0x08104980` | `gText_Possessive_Player` | `data/text/jp/possessive_labels.cc` | `data/text/possessive_labels.o(.rodata)` |
| `0x08104994` | `gText_RandomItem_NotAvailable` | `data/text/jp/random_item.cc` | `data/text/random_item.o(.rodata)` |
| `0x0810702C` | `gText_FieldRenderFallbackNone` | 未在 `data/text` 源中直接命名；请以宿主对象核对 | `src/field_data.o(.rodata.field_render_runtime_strings)` |
| `0x081070AC` | `gText_080B0708DefaultGlyph` | 未在 `data/text` 源中直接命名；请以宿主对象核对 | `src/field_data.o(.rodata.unk_080B0708_default_glyph)` |
| `0x081070F4` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_ExplanationQuestion` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x08107108` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_Yes` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x08107110` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_No` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x08107118` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_Introduction` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x08107148` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_FeedingInstructions` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x08107200` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_ChickenBehaviorInstructions` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x081072B4` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_WatchInstructions` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x081072E8` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_UnderstandQuestion` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x081072F8` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_UnderstandYes` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x08107304` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_UnderstandAgain` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x08107310` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_Start` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x0810732C` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_ScorePrefix` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x08107338` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_ScoreResultSuffix` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x0810734C` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_ScoreSummary` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x081073B9` | `gText_ChickenFestival_ContestantNames` | `data/text/jp/chicken_festival.cc` | `data/text/chicken_festival.o(.rodata)` |
| `0x081074C0` | `gText_HarvestSpriteMiniGame_ChickenFestival_SemiFinalsAnnouncement` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` |
| `0x081074D8` | `gText_HarvestSpriteMiniGame_ChickenFestival_FinalRoundAnnouncement` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` |
| `0x0810752C` | `gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationQuestion` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` |
| `0x0810754C` | `gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationNo` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` |
| `0x0810755C` | `gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationYes` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` |
| `0x0810756C` | `gText_HarvestSpriteMiniGame_ChickenFestival_RoundOneStart` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` |
| `0x08107588` | `gText_HarvestSpriteMiniGame_ChickenFestival_SemiFinalsStart` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` |
| `0x081075A4` | `gText_HarvestSpriteMiniGame_ChickenFestival_FinalsStart` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` |
| `0x081075BC` | `gText_HarvestSpriteMiniGame_ChickenFestival_Start` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` |
| `0x081075CC` | `gText_HarvestSpriteMiniGame_ChickenFestival_Stop` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` |
| `0x081075DC` | `gText_HarvestSpriteMiniGame_ChickenFestival_WinnerSuffix` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` |
| `0x08107620` | `gText_HarvestSpriteMiniGame_ChickenFestival_UnderstandQuestion` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_instructions.o(.rodata)` |
| `0x08107630` | `gText_HarvestSpriteMiniGame_ChickenFestival_UnderstandYes` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_instructions.o(.rodata)` |
| `0x0810763C` | `gText_HarvestSpriteMiniGame_ChickenFestival_Introduction` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_instructions.o(.rodata)` |
| `0x0810766C` | `gText_HarvestSpriteMiniGame_ChickenFestival_Rules` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_instructions.o(.rodata)` |
| `0x0810771C` | `gText_HarvestSpriteMiniGame_ChickenFestival_Encouragement` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_instructions.o(.rodata)` |
| `0x08107788` | `gText_HarvestSpriteMiniGame_ChickenFestival_CautionAtRingEdge` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_instructions.o(.rodata)` |
| `0x081077D0` | `gText_HarvestSpriteMiniGame_ChickenFestival_CautionLeavingRing` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_instructions.o(.rodata)` |
| `0x081078C0` | `gText_080BE728DigitZero` | 未在 `data/text` 源中直接命名；请以宿主对象核对 | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_chicken_festival_post_text_data)` |
| `0x081078E0` | `gText_HarvestSpriteMiniGame_Harvest_ExplanationQuestion` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` |
| `0x081078F4` | `gText_HarvestSpriteMiniGame_Harvest_Yes` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` |
| `0x081078FC` | `gText_HarvestSpriteMiniGame_Harvest_No` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` |
| `0x08107904` | `gText_HarvestSpriteMiniGame_Harvest_Introduction` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` |
| `0x0810792C` | `gText_HarvestSpriteMiniGame_Harvest_Instructions` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` |
| `0x08107968` | `gText_HarvestSpriteMiniGame_Harvest_FatigueWarning` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` |
| `0x081079CC` | `gText_HarvestSpriteMiniGame_Harvest_RestInstructions` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` |
| `0x08107A18` | `gText_HarvestSpriteMiniGame_Harvest_UnderstandQuestion` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` |
| `0x08107A28` | `gText_HarvestSpriteMiniGame_Harvest_UnderstandYes` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` |
| `0x08107A34` | `gText_HarvestSpriteMiniGame_Harvest_UnderstandAgain` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` |
| `0x08107A40` | `gText_HarvestSpriteMiniGame_Harvest_Start` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` |
| `0x08107A5C` | `gText_HarvestSpriteMiniGame_Harvest_ScorePrefix` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_results.o(.rodata)` |
| `0x08107A68` | `gText_HarvestSpriteMiniGame_Harvest_ScoreResultSuffix` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_results.o(.rodata)` |
| `0x08107A7C` | `gText_HarvestSpriteMiniGame_Harvest_ScoreSummary` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_results.o(.rodata)` |
| `0x08107AFC` | `gText_080C38E4DigitZero` | 未在 `data/text` 源中直接命名；请以宿主对象核对 | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_harvest_results_post_values)` |
| `0x08107B1C` | `gText_HarvestSpriteMiniGame_Watering_ExplanationQuestion` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` |
| `0x08107B30` | `gText_HarvestSpriteMiniGame_Watering_Yes` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` |
| `0x08107B38` | `gText_HarvestSpriteMiniGame_Watering_No` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` |
| `0x08107B40` | `gText_HarvestSpriteMiniGame_Watering_Introduction` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` |
| `0x08107B6C` | `gText_HarvestSpriteMiniGame_Watering_Instructions` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` |
| `0x08107BD8` | `gText_HarvestSpriteMiniGame_Watering_SuccessInstructions` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` |
| `0x08107C70` | `gText_HarvestSpriteMiniGame_Watering_MistakeWarning` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` |
| `0x08107CF4` | `gText_HarvestSpriteMiniGame_Watering_UnderstandQuestion` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` |
| `0x08107D04` | `gText_HarvestSpriteMiniGame_Watering_UnderstandYes` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` |
| `0x08107D10` | `gText_HarvestSpriteMiniGame_Watering_UnderstandAgain` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` |
| `0x08107D1C` | `gText_HarvestSpriteMiniGame_Watering_Start` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` |
| `0x08107D38` | `gText_HarvestSpriteMiniGame_Watering_ScorePrefix` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_results.o(.rodata)` |
| `0x08107D44` | `gText_HarvestSpriteMiniGame_Watering_ScoreResultSuffix` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_results.o(.rodata)` |
| `0x08107D58` | `gText_HarvestSpriteMiniGame_Watering_ScoreSummary` | `data/text/jp/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_results.o(.rodata)` |
| `0x081189F4` | `gText_ShopCommon_GoldUnit` | `data/text/jp/status_ui.cc` | `data/text/shop_common.o(.rodata)` |
| `0x081189F8` | `gText_ShopCommon_QuantitySuffix` | `data/text/jp/status_ui.cc` | `data/text/shop_common.o(.rodata)` |
| `0x08118A00` | `gText_ShopCommon_OwnedQuantityLabel` | `data/text/jp/status_ui.cc` | `data/text/shop_common.o(.rodata)` |
| `0x08118B94` | `gText_ToolStatus_GemOfTruth` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118BA4` | `gText_ToolStatus_EnergyLabel` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118BAC` | `gText_ToolStatus_ValueSeparator` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118BB0` | `gText_ToolStatus_EnergyFatigueLineBreak` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118BB4` | `gText_ToolStatus_FatigueLabel` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118BBC` | `gText_ToolStatus_FatigueMaximum` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118BC8` | `gText_ToolStatus_PedometerLabel` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118BD4` | `gText_ToolStatus_PedometerStepsSuffix` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118BD8` | `gText_ToolStatus_DescriptionQuoteOpen` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118BDC` | `gText_ToolStatus_DescriptionQuoteClose` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118BE0` | `gText_ToolStatus_RemainingSquaresPrefix` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118BE8` | `gText_ToolStatus_RemainingSquaresSuffix` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118BF4` | `gText_AnimalStatus_Dog` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118BFC` | `gText_AnimalStatus_Puppy` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118C04` | `gText_AnimalStatus_Chicken` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118C0C` | `gText_AnimalStatus_Chick` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118C18` | `gText_AnimalStatus_Sick` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118C20` | `gText_AnimalStatus_Unhappy` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118C2C` | `gText_AnimalStatus_Healthy` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118C34` | `gText_ItemStatus_BasketName` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118C3C` | `gText_ItemStatus_BasketDescription` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118C58` | `gText_ItemStatus_BasketHoldingSuffix` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118C68` | `gText_ItemStatus_WrappedAsPresent` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118C98` | `gText_ItemDiscard_Confirm` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118CB4` | `gText_ItemDiscard_CannotDiscard` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08118CD0` | `gText_ItemDiscard_Cursed` | `data/text/jp/status_ui.cc` | `data/text/status_ui.o(.rodata)` |

## US：物理 `.rodata` 顺序

范围：`0x080E862C`–`0x08139A87`。所有行都按当前 ROM 物理地址排序。

| 地址范围 | 链接输入 | 内容状态 | 维护源 / 文本来源 | 已命名内容 |
| --- | --- | --- | --- | --- |
| `0x080E862C`–`0x080E8680` | `src/sram_proxy_1.o(.rodata)` | [数据] | `src/sram_proxy_1.c/.cc` | `gSramImageSignature`, `gUnk_SramSignatureTrailerBadAllocFirst`, `gUnk_SramSignatureTrailerEmptyText`, `gUnk_SramSignatureTrailerBadAllocSecond`, `gUnk_SramSignatureTrailerBadAllocThird`, `gUnk_SramSignatureTrailerError`, … +1 |
| `0x080E8681`–`0x080E8683` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 3 字节 |
| `0x080E8684`–`0x080E86A5` | `src/intro_scene_data.o(.rodata.intro_scene_startup_resources)` | [数据] | `src/intro_scene_data.c/.cc` | 运行时字符串 `2` 项<br>`gIntroSceneStartupUnpackSources` |
| `0x080E86A6`–`0x080E86A7` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080E86A8`–`0x080E874B` | `src/new_game_menu_data.o(.rodata)` | [嵌入文本] | `data/text/us/new_game.cc` | 文本 `14` 项（详见下方索引）<br>`gNewGameMenuLabels` |
| `0x080E874C`–`0x080E8CC1` | `data/text/new_game.o(.rodata)` | [文本对象] | `data/text/us/new_game.cc` | 文本 `34` 项（详见下方索引）<br>运行时字符串 `14` 项<br>`gNewGameNameEntryCharacterRows` |
| `0x080E8CC2`–`0x080E8CC3` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080E8CC4`–`0x080E8D03` | `src/field_data.o(.rodata.field_plot_weather_ordinary)` | [数据] | `src/field_data.c/.cc` | `gFieldPlotOrdinaryWeatherRules` |
| `0x080E8D04`–`0x080E8D0B` | `src/field_data.o(.rodata.field_plot_weather_special_3)` | [数据] | `src/field_data.c/.cc` | `gFieldPlotSpecialWeatherRule3` |
| `0x080E8D0C`–`0x080E8D13` | `src/field_data.o(.rodata.field_plot_weather_special_4)` | [数据] | `src/field_data.c/.cc` | `gFieldPlotSpecialWeatherRule4` |
| `0x080E8D14`–`0x080E93F7` | `src/field_data.o(.rodata.field_plot_growth_transitions)` | [数据] | `src/field_data.c/.cc` | `gFieldPlotGrowthStageTransitions` |
| `0x080E93F8`–`0x080E95CB` | `src/field_data.o(.rodata.field_plot_definitions)` | [数据] | `src/field_data.c/.cc` | `gFieldPlotTypeDefinitions` |
| `0x080E95CC`–`0x080E9604` | `src/shipping_bin.o(.rodata)` | [数据] | `src/shipping_bin.c/.cc` | 无全局符号 |
| `0x080E9605`–`0x080E9613` | `src/record_player.o(.rodata)` | [数据] | `src/record_player.c/.cc` | 无全局符号 |
| `0x080E9614`–`0x080E9667` | `src/item.o(.rodata)` | [数据] | `data/text/common/fallback.cc` | 无全局符号 |
| `0x080E9668`–`0x080EAB09` | `data/text/tool.o(.rodata)` | [文本对象] | `data/text/us/tool.cc` | 文本 `162` 项（详见下方索引） |
| `0x080EAB0A`–`0x080EAB0B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080EAB0C`–`0x080EAED7` | `src/item.o(.rodata.item_tool)` | [数据] | `data/text/common/fallback.cc` | `gToolInfo` |
| `0x080EAED8`–`0x080EDCD6` | `data/text/food.o(.rodata)` | [文本对象] | `data/text/us/food.cc` | 文本 `335` 项（详见下方索引） |
| `0x080EDCD7`–`0x080EDCD7` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x080EDCD8`–`0x080EE787` | `src/item.o(.rodata.item_food)` | [数据] | `data/text/common/fallback.cc` | `gFoodInfo` |
| `0x080EE788`–`0x080EFED1` | `data/text/article.o(.rodata)` | [文本对象] | `data/text/us/article.cc` | 文本 `185` 项（详见下方索引） |
| `0x080EFED2`–`0x080EFED3` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080EFED4`–`0x080F0347` | `src/item.o(.rodata.item_article)` | [数据] | `data/text/common/fallback.cc` | `gArticleInfo` |
| `0x080F0348`–`0x080F04E3` | `src/item.o(.rodata.item_product)` | [数据] | `data/text/common/fallback.cc` | `gProductInfo` |
| `0x080F04E4`–`0x080F04ED` | `src/item.o(.rodata.item_product_trailer)` | [数据] | `data/text/common/fallback.cc` | 运行时字符串 `1` 项 |
| `0x080F04EE`–`0x080F0509` | `data/text/calendar.o(.rodata.calendar_season)` | [文本对象] | `data/text/us/calendar.cc` | 文本 `1` 项（详见下方索引） |
| `0x080F050A`–`0x080F050B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F050C`–`0x080F0565` | `data/text/calendar.o(.rodata)` | [文本对象] | `data/text/us/calendar.cc` | 文本 `3` 项（详见下方索引）<br>运行时字符串 `4` 项 |
| `0x080F0566`–`0x080F0589` | `src/game_state.o(.rodata)` | [数据] | `src/game_state.c/.cc` | `gUnk_080F0566` |
| `0x080F058A`–`0x080F058B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F058C`–`0x080F05B5` | `data/text/load_error.o(.rodata)` | [文本对象] | `data/text/us/load_error.cc` | 文本 `2` 项（详见下方索引）<br>运行时字符串 `2` 项 |
| `0x080F05B6`–`0x080F05B7` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F05B8`–`0x080F0650` | `src/help_menu.o(.rodata)` | [嵌入文本] | `data/text/us/help_menu.cc` | 文本 `4` 项（详见下方索引）<br>`gUnk_HelpMenuByteTable` |
| `0x080F0651`–`0x080F0653` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 3 字节 |
| `0x080F0654`–`0x080F06FC` | `data/text/animal_memorial.o(.rodata)` | [文本对象] | `data/text/us/animal_memorial.cc` | 文本 `11` 项（详见下方索引）<br>运行时字符串 `2` 项 |
| `0x080F06FD`–`0x080F080F` | `src/animal_data.o(.rodata.animal_data_prefix)` | [数据] | `data/text/common/animal_data.cc`<br>`data/text/us/animal_data.cc` | `gUnk_080F06FD`, `gUnk_080F0704`, `gUnk_080F0718`, `gUnk_080F0730`, `gUnk_080F0748`, `gUnk_080F0770`, … +1 |
| `0x080F0810`–`0x080F0E7D` | `src/animal_data.o(.rodata)` | [嵌入文本] | `data/text/common/animal_data.cc`<br>`data/text/us/animal_data.cc` | 文本 `1` 项（详见下方索引）<br>运行时字符串 `5` 项<br>`gUnk_080F0838`, `gUnk_080F0908`, `gUnk_080F093C`, `gUnk_080F09AC`, `gUnk_080F09C8`, `gUnk_080F0A68`, … +4 |
| `0x080F0E7E`–`0x080F0E7F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F0E80`–`0x080F1971` | `src/entity_ui.o(.rodata)` | [嵌入文本] | `data/text/common/entity_ui.cc`<br>`data/text/us/entity_ui.cc` | 文本 `1` 项（详见下方索引）<br>运行时字符串 `18` 项<br>`gUnk_080F0E88`, `gUnk_080F0F78`, `gUnk_080F0FCC`, `gUnk_080F1020`, `gUnk_080F1170`, `gUnk_080F1178`, … +41 |
| `0x080F1972`–`0x080F1973` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F1974`–`0x080F199D` | `src/fixed_labels.o(.rodata)` | [嵌入文本] | `data/text/common/fixed_labels.cc`<br>`data/text/us/fixed_labels.cc` | 文本 `2` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gFixedLabelsPaddingBeforeUnnamedSetting` |
| `0x080F199E`–`0x080F199F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F19A0`–`0x080F19C9` | `src/ui_error.o(.rodata)` | [嵌入文本] | `data/text/common/ui_error.cc`<br>`data/text/us/ui_error.cc` | 文本 `2` 项（详见下方索引）<br>运行时字符串 `2` 项<br>`gUnk_080F19AE` |
| `0x080F19CA`–`0x080F19CB` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F19CC`–`0x080F1A7D` | `src/menu_data.o(.rodata)` | [嵌入文本] | `data/text/common/menu.cc`<br>`data/text/us/menu.cc` | 文本 `7` 项（详见下方索引）<br>运行时字符串 `3` 项<br>`gMenuEntryIds`, `gMenuEntryLabels`, `gUnk_080F1A66` |
| `0x080F1A7E`–`0x080F1A7F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F1A80`–`0x080F33B5` | `src/data_schedules.o(.rodata)` | [数据] | `src/data_schedules.c/.cc` | 运行时字符串 `1` 项<br>`ScheduleInfo_Unk_080F1A80`, `Unk_080F1A80_Schedules`, `Unk_080F1A80_Schedule_1`, `Unk_080F1A80_Schedule_2`, `Unk_080F1A80_Schedule_3`, `Unk_080F1A80_Schedule_4`, … +271 |
| `0x080F33B6`–`0x080F33B7` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F33B8`–`0x080F42ED` | `src/entity_ui.o(.rodata.entity_ui_resource_selector)` | [数据] | `data/text/common/entity_ui.cc`<br>`data/text/us/entity_ui.cc` | 运行时字符串 `4` 项<br>`gUnk_080F33B8`, `gUnk_080F3408`, `gUnk_080F35E4`, `gUnk_080F3FD8` |
| `0x080F42EE`–`0x080F42EF` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F42F0`–`0x080F9E97` | `asm/data/data_080F1A80.o(.rodata.data_080f1a80_suffix)` | [Mary 脚本连续块] | `asm/data/data_080F1A80.s`<br>Mary 独立管理的连续剧情脚本区域（含脚本表入口）；按维护规则不展开内部内容 | 连续脚本相关原始区域；按维护规则不展开内部标签或表 |
| `0x080F9E98`–`0x080F9EA1` | `src/script_engine.o(.rodata)` | [数据] | `src/script_engine.c/.cc` | 无全局符号 |
| `0x080F9EA2`–`0x080F9EA3` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F9EA4`–`0x080F9EC4` | `data/text/common/script_engine.o(.rodata)` | [文本对象] | `data/text/common/script_engine.cc` | 文本 `3` 项（详见下方索引）<br>运行时字符串 `1` 项 |
| `0x080F9EC5`–`0x080F9ED8` | `src/cooking_festival_data.o(.rodata)` | [数据] | `src/cooking_festival_data.c/.cc` | `gCookingFestivalDishCategoryRatingThresholds` |
| `0x080F9ED9`–`0x080F9EDD` | `src/thomas_stocking_data.o(.rodata)` | [数据] | `src/thomas_stocking_data.c/.cc` | `gThomasStockingGiftSelectionWeights` |
| `0x080F9EDE`–`0x080F9EDF` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F9EE0`–`0x080F9EF3` | `src/spouse_gift_data.o(.rodata)` | [数据] | `src/spouse_gift_data.c/.cc` | `gSpouseGiftArticleSelectionEntries` |
| `0x080F9EF4`–`0x080F9EF9` | `src/farm_house.o(.rodata)` | [数据] | `src/farm_house.c/.cc` | `gFarmHouseBedXPositions` |
| `0x080F9EFA`–`0x080F9EFB` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080F9EFC`–`0x080F9F6F` | `src/ui_state.o(.rodata.ui_state_adapters)` | [数据] | `src/ui_state.c/.cc` | 运行时字符串 `2` 项<br>`gUnk_PreUiTextLayoutDigitRows`, `gUnk_PreUiTextLayoutFullWidthSpace`, `gUnk_PreUiTextLayoutFullWidthHyphen`, `gUiTextLayoutPositionTable` |
| `0x080F9F70`–`0x080F9F7B` | `src/ui_state.o(.rodata)` | [数据] | `src/ui_state.c/.cc` | `gUiSharedResourceData` |
| `0x080F9F7C`–`0x080FA12D` | `data/text/new_game_name_entry_preset.o(.rodata)` | [文本对象] | `data/text/us/new_game.cc` | 文本 `1` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gUnk_NewGameNameEntryPresetAnimalNamesPrefixValue` |
| `0x080FA12E`–`0x080FA157` | `src/new_game_name_entry_ui_data.o(.rodata)` | [数据] | `src/new_game_name_entry_ui_data.c/.cc` | `gNewGameNameEntryUiCharacterCodes` |
| `0x080FA158`–`0x080FA173` | `data/text/frisbee_scoreboard.o(.rodata)` | [文本对象] | `data/text/us/frisbee.cc` | 文本 `1` 项（详见下方索引） |
| `0x080FA174`–`0x080FA23B` | `src/animal_festival_ranking.o(.rodata.animal_festival_ranking_score_table)` | [数据] | `src/animal_festival_ranking.c/.cc` | `gAnimalFestivalRankingScoreTable` |
| `0x080FA23C`–`0x080FA245` | `src/animal_festival_ranking.o(.rodata.animal_festival_ranking_scoreboard_trailer)` | [数据] | `src/animal_festival_ranking.c/.cc` | 运行时字符串 `1` 项 |
| `0x080FA246`–`0x080FA379` | `src/animal_festival_ranking.o(.rodata.animal_festival_ranking_data)` | [数据] | `src/animal_festival_ranking.c/.cc` | `gUnk_080FA246`, `gUnk_080FA264`, `gUnk_080FA2E8`, `gUnk_080FA36C`, `gAnimalFestivalRewardChanceWeights` |
| `0x080FA37A`–`0x080FA37B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FA37C`–`0x080FA39B` | `src/animal_festival_ranking.o(.rodata.animal_festival_ranking_reward_article_ids)` | [数据] | `src/animal_festival_ranking.c/.cc` | `gAnimalFestivalRewardArticleIds` |
| `0x080FA39C`–`0x080FA719` | `data/text/frisbee.o(.rodata)` | [文本对象] | `data/text/us/frisbee.cc` | 文本 `15` 项（详见下方索引）<br>运行时字符串 `1` 项 |
| `0x080FA71A`–`0x080FA71B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FA71C`–`0x080FA78B` | `src/animal_festival_ranking.o(.rodata.animal_festival_ranking_random_range_pairs)` | [数据] | `src/animal_festival_ranking.c/.cc` | `gAnimalFestivalRandomRangePairs` |
| `0x080FA78C`–`0x080FA99D` | `data/text/animal_festival.o(.rodata)` | [文本对象] | `data/text/us/animal_festival.cc` | 文本 `1` 项（详见下方索引）<br>运行时字符串 `1` 项 |
| `0x080FA99E`–`0x080FAA3D` | `src/animal_festival_ranking.o(.rodata.animal_festival_livestock_contestant_values)` | [数据] | `src/animal_festival_ranking.c/.cc` | `gAnimalFestivalLivestockContestantValues` |
| `0x080FAA3E`–`0x080FAA3F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FAA40`–`0x080FB1D7` | `src/horse_race_data.o(.rodata)` | [嵌入文本] | `data/text/us/horse_race.cc` | 文本 `43` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gHorseRaceTicketCharacterCodes`, `gHorseRaceTicketControls`, `gHorseRacePrizeCatalog`, `gHorseRacePrizeItemIds`, `gHorseRacePrizeExchangeCharacterCodes` |
| `0x080FB1D8`–`0x080FB1E1` | `src/intro_scene_data.o(.rodata.intro_scene_prefix)` | [数据] | `src/intro_scene_data.c/.cc` | 运行时字符串 `1` 项 |
| `0x080FB1E2`–`0x080FB1E3` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FB1E4`–`0x080FB233` | `src/intro_scene_data.o(.rodata)` | [数据] | `src/intro_scene_data.c/.cc` | `gIntroSceneUnpackSources` |
| `0x080FB234`–`0x080FB816` | `data/text/intro_scene.o(.rodata)` | [文本对象] | `data/text/us/intro_scene.cc` | 文本 `28` 项（详见下方索引） |
| `0x080FB817`–`0x080FB817` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x080FB818`–`0x080FB821` | `src/intro_scene_data.o(.rodata.intro_scene_trailer)` | [数据] | `src/intro_scene_data.c/.cc` | 运行时字符串 `1` 项 |
| `0x080FB822`–`0x080FB823` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FB824`–`0x080FB9C7` | `data/text/farm_status.o(.rodata)` | [文本对象] | `data/text/us/farm_status.cc` | 文本 `29` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gAnimalStatusScreenPrefixText`, `gAnimalStatusScreenText` |
| `0x080FB9C8`–`0x080FBD2E` | `data/text/animal_contest.o(.rodata)` | [文本对象] | `data/text/us/animal_contest.cc` | 文本 `24` 项（详见下方索引）<br>运行时字符串 `1` 项 |
| `0x080FBD2F`–`0x080FBD2F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x080FBD30`–`0x080FBE79` | `src/farm_status_screen_data.o(.rodata)` | [数据] | `src/farm_status_screen_data.c/.cc` | 运行时字符串 `2` 项<br>`gFarmStatusScreenPreloadedGlyphs`, `gFarmStatusScreenResourceDescriptors`, `gFarmStatusScreenTileLookup`, `gFarmStatusScreenFarmHousePreviews`, `gFarmStatusScreenCoopPreviews`, `gFarmStatusScreenBarnPreviews`, … +1 |
| `0x080FBE7A`–`0x080FBE7B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FBE7C`–`0x080FC0A1` | `src/records_screen_data.o(.rodata)` | [嵌入文本] | `data/text/us/records.cc` | 文本 `33` 项（详见下方索引）<br>运行时字符串 `4` 项<br>`gRecordsScreenMinigameTaskResources`, `gCodeLinkoncePackedCellSizeLookup`, `gUiPreloadedDigitGlyphCodes` |
| `0x080FC0A2`–`0x080FC0A3` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FC0A4`–`0x080FC6B7` | `data/text/staff_credits.o(.rodata)` | [文本对象] | `data/text/us/staff_credits.cc` | 文本 `65` 项（详见下方索引）<br>`gStaffCreditsLines` |
| `0x080FC6B8`–`0x080FC6C1` | `src/town_map_data.o(.rodata.staff_credits_trailer)` | [数据] | `src/town_map_data.c/.cc` | 运行时字符串 `1` 项 |
| `0x080FC6C2`–`0x080FC6C9` | `src/town_map_data.o(.rodata.town_map_resource_ids)` | [数据] | `src/town_map_data.c/.cc` | `gTownMapResourceIds` |
| `0x080FC6CA`–`0x080FC6CB` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FC6CC`–`0x080FD07D` | `data/text/town_map.o(.rodata)` | [文本对象] | `data/text/us/town_map.cc` | 文本 `65` 项（详见下方索引） |
| `0x080FD07E`–`0x080FD07F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FD080`–`0x080FD39F` | `src/town_map_data.o(.rodata.town_map_hotspots)` | [数据] | `src/town_map_data.c/.cc` | `gTownMapHotspots` |
| `0x080FD3A0`–`0x080FD54F` | `src/town_map_data.o(.rodata.town_map_area_lookup)` | [数据] | `src/town_map_data.c/.cc` | `gTownMapAreaLookup`, `gTownMapAreaLookupFallback_034To133`, `gTownMapAreaLookupFallback_134To233` |
| `0x080FD550`–`0x080FD582` | `src/library_data.o(.rodata.library_opening_hours)` | [嵌入文本] | `data/text/us/library.cc` | 文本 `1` 项（详见下方索引） |
| `0x080FD583`–`0x080FD583` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x080FD584`–`0x080FD913` | `src/town_map_data.o(.rodata.town_map_area_bounds)` | [数据] | `src/town_map_data.c/.cc` | `gTownMapAreaBounds` |
| `0x080FD914`–`0x080FD91D` | `src/library_data.o(.rodata.library_info)` | [数据] | `data/text/us/library.cc` | 运行时字符串 `1` 项 |
| `0x080FD91E`–`0x080FD91F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FD920`–`0x080FD93F` | `src/library_data.o(.rodata.library_initial_entry_ids)` | [数据] | `data/text/us/library.cc` | `gLibraryInitialEntryIds` |
| `0x080FD940`–`0x080FD961` | `src/library_data.o(.rodata.library_menu)` | [嵌入文本] | `data/text/us/library.cc` | 文本 `1` 项（详见下方索引）<br>运行时字符串 `1` 项 |
| `0x080FD962`–`0x080FD963` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FD964`–`0x080FDDD5` | `src/poultry_shop_data.o(.rodata)` | [嵌入文本] | `data/text/us/poultry_shop.cc` | 文本 `34` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gPoultryShopCatalog` |
| `0x080FDDD6`–`0x080FDDD7` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FDDD8`–`0x080FE04D` | `src/supermarket_data.o(.rodata)` | [嵌入文本] | `data/text/us/supermarket.cc` | 文本 `10` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gSupermarketCropSeedCatalog`, `gSupermarketAdditionalSeedCatalog` |
| `0x080FE04E`–`0x080FE04F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FE050`–`0x080FE261` | `src/clinic_data.o(.rodata)` | [嵌入文本] | `data/text/us/clinic.cc` | 文本 `9` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gClinicCatalog` |
| `0x080FE262`–`0x080FE263` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FE264`–`0x080FE481` | `src/inn_shop_data.o(.rodata)` | [嵌入文本] | `data/text/us/inn_shop.cc` | 文本 `7` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gInnShopMenu` |
| `0x080FE482`–`0x080FE483` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FE484`–`0x080FE73D` | `src/won_shop_data.o(.rodata)` | [嵌入文本] | `data/text/us/won_shop.cc` | 文本 `10` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gWonShopCatalog` |
| `0x080FE73E`–`0x080FE73F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FE740`–`0x080FE8F9` | `src/winery_shop_data.o(.rodata)` | [嵌入文本] | `data/text/us/winery_shop.cc` | 文本 `8` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gWineryShopCatalog` |
| `0x080FE8FA`–`0x080FE8FB` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FE8FC`–`0x080FEAF1` | `src/special_merchant_shop_data.o(.rodata)` | [嵌入文本] | `data/text/us/special_merchant_shop.cc` | 文本 `9` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gSpecialMerchantShopCatalog` |
| `0x080FEAF2`–`0x080FEAF3` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FEAF4`–`0x080FEC79` | `src/beach_cafe_shop_data.o(.rodata)` | [嵌入文本] | `data/text/us/beach_cafe_shop.cc` | 文本 `7` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gBeachCafeShopMenu` |
| `0x080FEC7A`–`0x080FEC7B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FEC7C`–`0x080FED8B` | `src/blacksmith_menu_data.o(.rodata)` | [嵌入文本] | `data/text/us/blacksmith.cc` | 文本 `12` 项（详见下方索引） |
| `0x080FED8C`–`0x080FF359` | `src/blacksmith_data.o(.rodata)` | [嵌入文本] | `data/text/us/blacksmith.cc` | 文本 `20` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gBlacksmithCatalog` |
| `0x080FF35A`–`0x080FF35B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FF35C`–`0x080FFB5D` | `src/carpenter_data.o(.rodata)` | [嵌入文本] | `data/text/common/carpenter.cc`<br>`data/text/us/carpenter.cc` | 文本 `53` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gCarpenterCatalog` |
| `0x080FFB5E`–`0x080FFB5F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x080FFB60`–`0x08100023` | `src/livestock_shop.o(.rodata)` | [嵌入文本] | `data/text/us/livestock_shop.cc` | 文本 `42` 项（详见下方索引）<br>`gLivestockShopCatalog` |
| `0x08100024`–`0x08100165` | `data/text/home_storage.o(.rodata)` | [文本对象] | `data/text/us/home_storage.cc` | 文本 `20` 项（详见下方索引）<br>运行时字符串 `5` 项 |
| `0x08100166`–`0x08100167` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08100168`–`0x081003E2` | `src/blacksmith_upgrade_data.o(.rodata)` | [嵌入文本] | `data/text/us/blacksmith.cc` | 文本 `21` 项（详见下方索引） |
| `0x081003E3`–`0x081003E3` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x081003E4`–`0x081004DD` | `data/text/gift_wrap.o(.rodata)` | [文本对象] | `data/text/us/gift_wrap.cc` | 文本 `11` 项（详见下方索引）<br>运行时字符串 `2` 项 |
| `0x081004DE`–`0x081004DF` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x081004E0`–`0x08100ABD` | `src/link_communication_data.o(.rodata)` | [嵌入文本 / 数据] | `data/text/us/link_communication.cc`<br>`src/link_communication_data.cc` | 文本 `17` 项（详见下方索引）<br>运行时字符串 `3` 项<br>`gUnk_081007AC`, `gUnk_081007D4`, `gUnk_081007FC`, `gUnk_08100824`, `gUnk_0810084C`, `gUnk_08100874`, … +11<br>`gLinkCommunicationGameCodeA4N`, `gLinkCommunicationGameCodeGYW` |
| `0x08100ABE`–`0x08100ABF` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08100AC0`–`0x08100AC1` | `src/cooking_recipe_inventory_data.o(.rodata.cooking_recipe_inventory_page_break)` | [嵌入文本] | `data/text/common/cooking_recipe_inventory.cc` | 文本 `1` 项（详见下方索引） |
| `0x08100AC2`–`0x08100AD1` | `src/cooking_recipe_inventory_data.o(.rodata.cooking_recipe_inventory_utensil_values)` | [数据] | `data/text/common/cooking_recipe_inventory.cc` | `gCookingRecipeInventoryUtensilValues` |
| `0x08100AD2`–`0x08100DE0` | `data/text/recovery_status.o(.rodata)` | [文本对象] | `data/text/us/recovery_status.cc` | 文本 `2` 项（详见下方索引） |
| `0x08100DE1`–`0x08100DE3` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 3 字节 |
| `0x08100DE4`–`0x081010E7` | `data/text/cooking.o(.rodata)` | [文本对象] | `data/text/us/cooking.cc` | 文本 `28` 项（详见下方索引） |
| `0x081010E8`–`0x0810110B` | `src/cooking_recipe_inventory_data.o(.rodata.cooking_recipe_inventory_mask_entries)` | [数据] | `data/text/common/cooking_recipe_inventory.cc` | `gCookingRecipeInventoryMaskEntries` |
| `0x0810110C`–`0x08103655` | `src/cooking_recipe_inventory_data.o(.rodata)` | [数据] | `data/text/common/cooking_recipe_inventory.cc` | 运行时字符串 `2` 项<br>`gCookingRecipeDefinitions`, `gCookingRecipeDefinitionPayload` |
| `0x08103656`–`0x08103657` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08103658`–`0x0810365E` | `src/animal.o(.rodata.animal_unnamed)` | [嵌入文本] | `data/text/common/animal.cc` | 文本 `1` 项（详见下方索引） |
| `0x0810365F`–`0x0810365F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x08103660`–`0x081036BF` | `src/livestock.o(.rodata.livestock_day_update)` | [数据] | `src/livestock.c/.cc` | `gChickenDayUpdateInfo`, `gCowDayUpdateInfo`, `gSheepDayUpdateInfo` |
| `0x081036C0`–`0x081036C5` | `src/code_actor_0809C3E0.o(.rodata.actor_state_max_values)` | [数据] | `src/code_actor_0809C3E0.c/.cc` | `gActorStateMaxValues` |
| `0x081036C6`–`0x081036C7` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x081036C8`–`0x08103785` | `src/code_actor_0809C3E0.o(.rodata)` | [数据] | `src/code_actor_0809C3E0.c/.cc` | 运行时字符串 `2` 项<br>`gActorDataSelectionEntries` |
| `0x08103786`–`0x08103787` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08103788`–`0x08103A15` | `data/text/fishing_results.o(.rodata)` | [文本对象] | `data/text/us/fishing_results.cc` | 文本 `58` 项（详见下方索引） |
| `0x08103A16`–`0x08103A17` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08103A18`–`0x08103B03` | `src/fishing_results_data.o(.rodata.fishing_record_names)` | [数据] | `src/fishing_results_data.c/.cc` | `gFishingRecordNames` |
| `0x08103B04`–`0x08103B0D` | `src/fishing_results_data.o(.rodata)` | [数据] | `src/fishing_results_data.c/.cc` | 运行时字符串 `1` 项 |
| `0x08103B0E`–`0x08103B0F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08103B10`–`0x08104107` | `src/code_actor_0809BFE8.o(.rodata)` | [数据] | `src/code_actor_0809BFE8.c/.cc` | 运行时字符串 `1` 项<br>`gUnk_08103B10`, `gUnk_08103B38`, `gUnk_08103C3C`, `gUnk_08103C74`, `gUnk_08103F84`, `gUnk_08103F98`, … +3 |
| `0x08104108`–`0x08104108` | `src/character_names_data.o(.rodata.character_names_empty)` | [嵌入文本] | `src/character_names_data.c/.cc` | 文本 `1` 项（详见下方索引） |
| `0x08104109`–`0x08104126` | `src/bachelorette.o(.rodata)` | [数据] | `src/bachelorette.c/.cc` | `gUnk_BacheloretteLoveThresholds00`, `gUnk_BacheloretteLoveThresholds01`, `gUnk_BacheloretteLoveThresholds02`, `gUnk_BacheloretteLoveThresholds03`, `gUnk_BacheloretteLoveThresholds04`, `gUnk_BacheloretteLoveThresholds05` |
| `0x08104127`–`0x08104127` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x08104128`–`0x08104255` | `data/text/character_names.o(.rodata)` | [文本对象] | `data/text/us/character_names.cc` | 文本 `41` 项（详见下方索引） |
| `0x08104256`–`0x08104257` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08104258`–`0x081043AF` | `src/character_names_data.o(.rodata.character_name_entries)` | [数据] | `src/character_names_data.c/.cc` | `gCharacterNameEntries` |
| `0x081043B0`–`0x081043B9` | `src/character_names_data.o(.rodata)` | [数据] | `src/character_names_data.c/.cc` | 运行时字符串 `1` 项 |
| `0x081043BA`–`0x081043BB` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x081043BC`–`0x08104935` | `src/field_data.o(.rodata.field_item_records)` | [数据] | `src/field_data.c/.cc` | 运行时字符串 `1` 项<br>`gUnk_081043BC` |
| `0x08104936`–`0x08104937` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08104938`–`0x08104E09` | `data/text/calendar_events.o(.rodata)` | [文本对象] | `data/text/us/calendar_events.cc` | 文本 `22` 项（详见下方索引）<br>运行时字符串 `2` 项 |
| `0x08104E0A`–`0x08104E0B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08104E0C`–`0x08104E49` | `data/text/possessive_labels.o(.rodata)` | [文本对象] | `data/text/us/possessive_labels.cc` | 文本 `6` 项（详见下方索引）<br>运行时字符串 `1` 项 |
| `0x08104E4A`–`0x08104E4B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08104E4C`–`0x08104E50` | `data/text/random_item.o(.rodata)` | [文本对象] | `data/text/us/random_item.cc` | 文本 `1` 项（详见下方索引） |
| `0x08104E51`–`0x08104E53` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 3 字节 |
| `0x08104E54`–`0x08104E73` | `src/fishing_results_data.o(.rodata.fishing_record_article_ids)` | [数据] | `src/fishing_results_data.c/.cc` | `gFishingRecordArticleIds` |
| `0x08104E74`–`0x08104EAB` | `src/field_data.o(.rodata.field_plot_position_values)` | [数据] | `src/field_data.c/.cc` | `gFieldPlotPositionValues` |
| `0x08104EAC`–`0x08104ECE` | `src/random_item.o(.rodata.random_item_selection_weights)` | [数据] | `src/random_item.c/.cc` | `gRandomItemSelectionWeights` |
| `0x08104ECF`–`0x08104ECF` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x08104ED0`–`0x0810562F` | `src/random_item.o(.rodata.random_item_candidate_configurations)` | [数据] | `src/random_item.c/.cc` | `gRandomItemCandidateConfigurations` |
| `0x08105630`–`0x08105639` | `src/random_item.o(.rodata)` | [数据] | `src/random_item.c/.cc` | 运行时字符串 `1` 项 |
| `0x0810563A`–`0x0810563B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x0810563C`–`0x081056FB` | `src/field_data.o(.rodata.field_plot_position_rules)` | [数据] | `src/field_data.c/.cc` | `gFieldPlotPositionRules` |
| `0x081056FC`–`0x08105705` | `src/field_data.o(.rodata)` | [数据] | `src/field_data.c/.cc` | 运行时字符串 `1` 项 |
| `0x08105706`–`0x08105707` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08105708`–`0x08105747` | `src/code_0800E2E4.o(.rodata.time_of_day_transition_table)` | [数据] | `src/code_0800E2E4.c/.cc` | `gTimeOfDayTransitionTables` |
| `0x08105748`–`0x08105EDB` | `src/code_0800E2E4.o(.rodata.time_of_day_transition_records)` | [数据] | `src/code_0800E2E4.c/.cc` | `gTimeOfDayTransitionRecords_Spring_Morning`, `gTimeOfDayTransitionRecords_Spring_Afternoon`, `gTimeOfDayTransitionRecords_Spring_Evening`, `gTimeOfDayTransitionRecords_Spring_Night`, `gTimeOfDayTransitionRecords_Summer_Morning`, `gTimeOfDayTransitionRecords_Summer_Afternoon`, … +10 |
| `0x08105EDC`–`0x0810692B` | `src/map_data.o(.rodata.map_data)` | [数据] | `src/map_data.c/.cc` | `gMapData` |
| `0x0810692C`–`0x081070DB` | `src/field_data.o(.rodata.field_render_rect_descriptors)` | [数据] | `src/field_data.c/.cc` | `gFieldRenderRectDescriptors` |
| `0x081070DC`–`0x08107203` | `src/farm_house.o(.rodata.farm_house_tile_patches)` | [数据] | `src/farm_house.c/.cc` | `gFarmHouseTilePatchData` |
| `0x08107204`–`0x08107337` | `src/farm_house.o(.rodata.farm_house_visual_descriptors)` | [数据] | `src/farm_house.c/.cc` | `gFarmHouseVisualDescriptors` |
| `0x08107338`–`0x0810734F` | `src/farm_house.o(.rodata.farm_house_tile_patch_animations)` | [数据] | `src/farm_house.c/.cc` | `gFarmHouseTilePatchAnimations` |
| `0x08107350`–`0x08107357` | `src/field_data.o(.rodata.field_render_resource_first_values)` | [数据] | `src/field_data.c/.cc` | `gUnk_FieldRenderResource_158`, `gUnk_FieldRenderResource_159` |
| `0x08107358`–`0x0810735B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 4 字节 |
| `0x0810735C`–`0x08107363` | `src/field_data.o(.rodata.field_render_resource_second_values)` | [数据] | `src/field_data.c/.cc` | `gUnk_FieldRenderResource_177`, `gUnk_FieldRenderResource_178` |
| `0x08107364`–`0x0810736F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 12 字节 |
| `0x08107370`–`0x08107385` | `src/field_data.o(.rodata.field_render_resource_runtime_strings)` | [数据] | `src/field_data.c/.cc` | 运行时字符串 `2` 项 |
| `0x08107386`–`0x08107387` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x08107388`–`0x081073C3` | `src/field_data.o(.rodata.field_render_parallel_tables)` | [数据] | `src/field_data.c/.cc` | `gFieldRenderParallelTables` |
| `0x081073C4`–`0x08107423` | `src/field_data.o(.rodata.field_render_patch_arguments)` | [数据] | `src/field_data.c/.cc` | `gFieldRenderPatchArgumentData` |
| `0x08107424`–`0x0810742D` | `src/field_data.o(.rodata.field_render_patch_arguments_after)` | [数据] | `src/field_data.c/.cc` | 运行时字符串 `1` 项 |
| `0x0810742E`–`0x08107436` | `src/farm_house.o(.rodata.farm_house_style_nibble_lookup)` | [数据] | `src/farm_house.c/.cc` | `gFarmHouseStyleNibbleLookupData` |
| `0x08107437`–`0x08107437` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x08107438`–`0x0810744F` | `src/bachelorette.o(.rodata.bachelorette_marriage_candidate_character_ids)` | [数据] | `src/bachelorette.c/.cc` | `gMarriageCandidateCharacterIds` |
| `0x08107450`–`0x08107457` | `src/field_data.o(.rodata.field_render_seasonal_record_ranges)` | [数据] | `src/field_data.c/.cc` | `gFieldRenderSeasonalRecordRanges` |
| `0x08107458`–`0x0810749F` | `src/field_data.o(.rodata.field_render_lookup_values)` | [数据] | `src/field_data.c/.cc` | `gUnk_FieldRenderLookupValues` |
| `0x081074A0`–`0x081074F5` | `src/field_data.o(.rodata.field_render_runtime_strings)` | [嵌入文本] | `src/field_data.c/.cc` | 文本 `1` 项（详见下方索引）<br>运行时字符串 `7` 项 |
| `0x081074F6`–`0x08107510` | `src/field_data.o(.rodata.field_render_sorted_values)` | [数据] | `src/field_data.c/.cc` | `gUnk_FieldRenderSortedValues` |
| `0x08107511`–`0x08107513` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 3 字节 |
| `0x08107514`–`0x08107529` | `src/field_data.o(.rodata.field_render_sorted_values_runtime_strings)` | [数据] | `src/field_data.c/.cc` | 运行时字符串 `2` 项 |
| `0x0810752A`–`0x0810752B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x0810752C`–`0x08107567` | `src/field_data.o(.rodata.unk_080AE894_values)` | [数据] | `src/field_data.c/.cc` | `gUnk_080AE894InitialValues`, `gUnk_080AE894LayoutValues` |
| `0x08107568`–`0x08107569` | `src/field_data.o(.rodata.unk_080B0708_default_glyph)` | [嵌入文本] | `src/field_data.c/.cc` | 文本 `1` 项（详见下方索引） |
| `0x0810756A`–`0x0810756B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x0810756C`–`0x08107587` | `src/field_data.o(.rodata.unk_080B09B0_index_values)` | [数据] | `src/field_data.c/.cc` | `gUnk_080B09B0IndexValues` |
| `0x08107588`–`0x081075AF` | `src/field_data.o(.rodata.unk_080B0BB8_values)` | [数据] | `src/field_data.c/.cc` | `gUnk_080B0BB8FirstValues`, `gUnk_080B0BB8SecondValues` |
| `0x081075B0`–`0x0810787B` | `data/text/harvest_sprite_minigames.o(.rodata)` | [文本对象] | `data/text/us/harvest_sprite_minigames.cc` | 文本 `15` 项（详见下方索引） |
| `0x0810787C`–`0x08107880` | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_animal_husbandry_match_values)` | [数据] | `src/harvest_sprite.c/.cc` | `gUnk_HarvestSpriteMiniGameAnimalHusbandryMatchValues` |
| `0x08107881`–`0x08107881` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x08107882`–`0x081078AD` | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_animal_husbandry_u16_tables)` | [数据] | `src/harvest_sprite.c/.cc` | `gUnk_HarvestSpriteMiniGameAnimalHusbandrySelectionValues`, `gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues0`, `gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues1`, `gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues2`, `gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues3` |
| `0x081078AE`–`0x081078AF` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x081078B0`–`0x081078B9` | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_animal_husbandry_runtime)` | [数据] | `src/harvest_sprite.c/.cc` | 运行时字符串 `1` 项 |
| `0x081078BA`–`0x081078BB` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x081078BC`–`0x081078BC` | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_animal_husbandry_runtime_empty)` | [嵌入文本] | `src/harvest_sprite.c/.cc` | 文本 `1` 项（详见下方索引） |
| `0x081078BD`–`0x081079C0` | `data/text/chicken_festival.o(.rodata)` | [文本对象] | `data/text/us/chicken_festival.cc` | 文本 `1` 项（详见下方索引） |
| `0x081079C1`–`0x081079C3` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 3 字节 |
| `0x081079C4`–`0x08107ACB` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` | [文本对象] | `data/text/us/harvest_sprite_minigames.cc` | 文本 `11` 项（详见下方索引） |
| `0x08107ACC`–`0x08107AFB` | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_chicken_festival_values)` | [数据] | `src/harvest_sprite.c/.cc` | `gUnk_HarvestSpriteMiniGameChickenFestivalValues` |
| `0x08107AFC`–`0x08107AFF` | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_chicken_festival_offsets)` | [数据] | `src/harvest_sprite.c/.cc` | `gUnk_HarvestSpriteMiniGameChickenFestivalOffsets` |
| `0x08107B00`–`0x08107CFA` | `data/text/harvest_sprite_minigames_chicken_festival_instructions.o(.rodata)` | [文本对象] | `data/text/us/harvest_sprite_minigames.cc` | 文本 `8` 项（详见下方索引） |
| `0x08107CFB`–`0x08107CFB` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x08107CFC`–`0x08107DD7` | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_chicken_festival_post_text_data)` | [嵌入文本] | `src/harvest_sprite.c/.cc` | 文本 `1` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gUnk_080BAC9CValues`, `gUnk_080BB890FirstValues`, `gUnk_080BB890TableValues`, `gUnk_080BB890LastValues`, `gUnk_080BC288Values`, `gUnk_080BE954Values` |
| `0x08107DD8`–`0x08107F5E` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` | [文本对象] | `data/text/us/harvest_sprite_minigames.cc` | 文本 `11` 项（详见下方索引） |
| `0x08107F5F`–`0x08107F5F` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x08107F60`–`0x08107FAF` | `data/text/harvest_sprite_minigames_harvest_results.o(.rodata)` | [文本对象] | `data/text/us/harvest_sprite_minigames.cc` | 文本 `4` 项（详见下方索引） |
| `0x08107FB0`–`0x08107FC5` | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_harvest_results_first_values)` | [数据] | `src/harvest_sprite.c/.cc` | `gUnk_080C09D8Values` |
| `0x08107FC6`–`0x08107FD3` | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_harvest_results_second_values)` | [数据] | `src/harvest_sprite.c/.cc` | `gUnk_080C0B58Values` |
| `0x08107FD4`–`0x0810801F` | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_harvest_results_post_values)` | [嵌入文本] | `src/harvest_sprite.c/.cc` | 文本 `1` 项（详见下方索引）<br>运行时字符串 `1` 项<br>`gUnk_080C3B18Values`, `gUnk_080C3B18IndexValues` |
| `0x08108020`–`0x08108216` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` | [文本对象] | `data/text/us/harvest_sprite_minigames.cc` | 文本 `11` 项（详见下方索引） |
| `0x08108217`–`0x08108217` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x08108218`–`0x08108266` | `data/text/harvest_sprite_minigames_watering_results.o(.rodata)` | [文本对象] | `data/text/us/harvest_sprite_minigames.cc` | 文本 `4` 项（详见下方索引） |
| `0x08108267`–`0x08108267` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 1 字节 |
| `0x08108268`–`0x08108289` | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_watering_results_values)` | [数据] | `src/harvest_sprite.c/.cc` | `gUnk_080C7B38Values`, `gUnk_080C7B64Values` |
| `0x0810828A`–`0x0810828B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x0810828C`–`0x081177EB` | `src/reference_guide.o(.rodata.reference_guide)` | [指南连续块] | `src/reference_guide.cc`<br>`data/text/us/reference_guide/*.cc (138 页)`<br>连续生成块；按维护规则不展开页内文本或页指针表 | 连续生成区域；按维护规则仅记录起止 |
| `0x081177EC`–`0x08117809` | `src/shop_common.o(.rodata.shop_common_digit_glyphs)` | [数据] | `src/shop_common.c/.cc` | 运行时字符串 `1` 项<br>`gUnk_080C85A0DigitGlyphs` |
| `0x0811780A`–`0x0811780B` | `*fill*` | [填充] | 链接脚本填充字节 `00` | 2 字节 |
| `0x0811780C`–`0x0811782B` | `data/text/shop_common.o(.rodata)` | [文本对象] | `data/text/us/status_ui.cc` | 文本 `3` 项（详见下方索引）<br>`gShopCommonQuantitySuffixTextRef`, `gShopCommonOwnedQuantityLabelTextRef` |
| `0x0811782C`–`0x081179AB` | `src/shop_common.o(.rodata)` | [数据] | `src/shop_common.c/.cc` | 运行时字符串 `2` 项<br>`gUnk_08117838`, `gUnk_0811783C`, `gUnk_0811785C`, `gUnk_08117860`, `gUnk_0811788C` |
| `0x081179AC`–`0x08117B13` | `data/text/status_ui.o(.rodata)` | [文本对象] | `data/text/us/status_ui.cc` | 文本 `25` 项（详见下方索引）<br>`gItemStatusWrappedAsPresentTextRef`, `gItemDiscardConfirmTextRef`, `gItemDiscardCannotDiscardTextRef`, `gItemDiscardCursedTextRef` |
| `0x08117B14`–`0x08117BD3` | `src/font.o(.rodata)` | [数据] | `src/font.c/.cc` | 运行时字符串 `1` 项<br>`gFontSpecialGlyphBlocks`, `gFontSpecialGlyphC3` |
| `0x08117BD4`–`0x08139A87` | `asm/data/data_080F9EB8.o(.rodata.static_data_after_item_discard)` | [原始 incbin] | `asm/data/data_080F9EB8.s` | `gUnk_FieldRenderResource_146`, `gUnk_FieldRenderResource_147`, `gUnk_MapDataResource_098`, `gUnk_MapDataResource_099`, `gUnk_FieldRenderResource_120`, `gUnk_FieldRenderResource_121`, … +214 |

## US：文本地址索引

仅列出普通游戏/界面文本的 `gText_*` 标签，仍按 ROM 地址升序。指南文本已按规则合并为上方的一条连续块，故不在此逐条重复；运行时库字面量保留在上方物理表中，但不混入游戏文本索引。

| 地址 | 文本标签 | 维护源 | 链接输入 |
| --- | --- | --- | --- |
| `0x080E86A8` | `gText_NewGameMenu_Diary` | `data/text/us/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E86B0` | `gText_NewGameMenu_Save` | `data/text/us/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E86B8` | `gText_NewGameMenu_Load` | `data/text/us/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E86C0` | `gText_NewGameMenu_Blank` | `data/text/us/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E86C4` | `gText_NewGameMenu_Data1` | `data/text/us/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E86CC` | `gText_NewGameMenu_Data2` | `data/text/us/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E86D4` | `gText_NewGameMenu_ControlSettings` | `data/text/us/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E86DC` | `gText_NewGameMenu_ControlOption1` | `data/text/us/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E86E0` | `gText_NewGameMenu_ControlOption2` | `data/text/us/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E86E4` | `gText_NewGameMenu_ClockDisplay` | `data/text/us/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E86EC` | `gText_NewGameMenu_Yes` | `data/text/us/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E86F0` | `gText_NewGameMenu_No` | `data/text/us/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E86F4` | `gText_NewGameMenu_FaceDisplay` | `data/text/us/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E86FC` | `gText_NewGameMenu_NameDisplay` | `data/text/us/new_game.cc` | `src/new_game_menu_data.o(.rodata)` |
| `0x080E874C` | `gText_NewGameStatus_YearSuffix` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8754` | `gText_NewGameStatus_SeasonSeparator` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8758` | `gText_NewGameStatus_DaySuffix` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8760` | `gText_NewGameStatus_OpenParen` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8764` | `gText_NewGameStatus_CloseParen` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8768` | `gText_NewGameStatus_FarmSuffix` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8770` | `gText_NewGameStatus_ReadDiary` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E877C` | `gText_NewGameStatus_WriteDiary` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E878C` | `gText_NewGameStatus_NoSavedData` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E87A4` | `gText_NewGameHelp_Controls` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E87FC` | `gText_NewGameHelp_ClockDisplay` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8828` | `gText_NewGameHelp_FaceDisplay` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8878` | `gText_NewGameHelp_NameDisplay` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E88C8` | `gText_NewGameSave_SaveFailed` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E88D8` | `gText_NewGameSave_LoadFailed` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E890C` | `gText_NewGameSave_LoadPrompt` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8914` | `gText_NewGameSave_OverwritePrompt` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8934` | `gText_NewGameIdentity_PlayerPrefix` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E893C` | `gText_NewGameIdentity_FarmPrefix` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8944` | `gText_NewGameIdentity_DogPrefix` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8958` | `gText_NewGameIdentity_PlayerName` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8968` | `gText_NewGameIdentity_PlayerBirthday` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8978` | `gText_NewGameIdentity_FarmName` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8988` | `gText_NewGameIdentity_DogName` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8998` | `gText_NewGameIdentity_Confirm` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E89A4` | `gText_NewGameIdentity_Yes` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E89A8` | `gText_NewGameIdentity_No` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8BE4` | `gText_NewGameNameEntry_Placeholder` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8BF4` | `gText_NewGameNameEntry_NameLabel` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8BFC` | `gText_NewGameNameEntry_EndLatin` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8C14` | `gText_NewGameNameEntry_EndFullWidth` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8C2C` | `gText_NewGameNameEntry_Confirm` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8C44` | `gText_NewGameNameEntry_Yes` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E8C48` | `gText_NewGameNameEntry_No` | `data/text/us/new_game.cc` | `data/text/new_game.o(.rodata)` |
| `0x080E9668` | `gText_Item_Tool_IronSickle_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9674` | `gText_Item_Tool_IronSickle_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E96B0` | `gText_Item_Tool_CopperSickle_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E96C0` | `gText_Item_Tool_CopperSickle_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9704` | `gText_Item_Tool_SilverSickle_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9714` | `gText_Item_Tool_SilverSickle_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9758` | `gText_Item_Tool_GoldSickle_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9764` | `gText_Item_Tool_GoldSickle_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E97A4` | `gText_Item_Tool_MystrileSickle_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E97B4` | `gText_Item_Tool_MystrileSickle_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E97F8` | `gText_Item_Tool_CursedSickle_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9808` | `gText_Item_Tool_CursedSickle_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9844` | `gText_Item_Tool_BlessedSickle_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9854` | `gText_Item_Tool_BlessedSickle_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E988C` | `gText_Item_Tool_MythicSickle_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E989C` | `gText_Item_Tool_MythicSickle_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E98E0` | `gText_Item_Tool_IronHoe_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E98EC` | `gText_Item_Tool_IronHoe_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9928` | `gText_Item_Tool_CopperHoe_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9934` | `gText_Item_Tool_CopperHoe_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9978` | `gText_Item_Tool_SilverHoe_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9984` | `gText_Item_Tool_SilverHoe_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E99C8` | `gText_Item_Tool_GoldHoe_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E99D4` | `gText_Item_Tool_GoldHoe_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9A14` | `gText_Item_Tool_MystrileHoe_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9A24` | `gText_Item_Tool_MystrileHoe_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9A64` | `gText_Item_Tool_CursedHoe_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9A70` | `gText_Item_Tool_CursedHoe_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9AA8` | `gText_Item_Tool_BlessedHoe_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9AB4` | `gText_Item_Tool_BlessedHoe_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9AE8` | `gText_Item_Tool_MythicHoe_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9AF4` | `gText_Item_Tool_MythicHoe_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9B30` | `gText_Item_Tool_IronAxe_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9B3C` | `gText_Item_Tool_IronAxe_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9B78` | `gText_Item_Tool_CopperAxe_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9B84` | `gText_Item_Tool_CopperAxe_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9BB8` | `gText_Item_Tool_SilverAxe_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9BC4` | `gText_Item_Tool_SilverAxe_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9BF8` | `gText_Item_Tool_GoldAxe_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9C04` | `gText_Item_Tool_GoldAxe_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9C38` | `gText_Item_Tool_MystrileAxe_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9C48` | `gText_Item_Tool_MystrileAxe_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9C80` | `gText_Item_Tool_CursedAxe_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9C8C` | `gText_Item_Tool_CursedAxe_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9CC0` | `gText_Item_Tool_BlessedAxe_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9CCC` | `gText_Item_Tool_BlessedAxe_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9D00` | `gText_Item_Tool_MythicAxe_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9D0C` | `gText_Item_Tool_MythicAxe_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9D40` | `gText_Item_Tool_IronHammer_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9D4C` | `gText_Item_Tool_IronHammer_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9D8C` | `gText_Item_Tool_CopperHammer_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9D9C` | `gText_Item_Tool_CopperHammer_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9DE8` | `gText_Item_Tool_SilverHammer_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9DF8` | `gText_Item_Tool_SilverHammer_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9E34` | `gText_Item_Tool_GoldHammer_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9E40` | `gText_Item_Tool_GoldHammer_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9E84` | `gText_Item_Tool_MystrileHammer_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9E94` | `gText_Item_Tool_MystrileHammer_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9EDC` | `gText_Item_Tool_CursedHammer_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9EEC` | `gText_Item_Tool_CursedHammer_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9F28` | `gText_Item_Tool_BlessedHammer_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9F38` | `gText_Item_Tool_BlessedHammer_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9F74` | `gText_Item_Tool_MythicHammer_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9F84` | `gText_Item_Tool_MythicHammer_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9FCC` | `gText_Item_Tool_WateringCan_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9FDC` | `gText_Item_Tool_WateringCan_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080E9FFC` | `gText_Item_Tool_CopperWateringCan_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA010` | `gText_Item_Tool_CopperWateringCan_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA034` | `gText_Item_Tool_SilverWateringCan_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA048` | `gText_Item_Tool_SilverWateringCan_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA06C` | `gText_Item_Tool_GoldWateringCan_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA080` | `gText_Item_Tool_GoldWateringCan_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA0A4` | `gText_Item_Tool_MystrileWateringCan_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA0BC` | `gText_Item_Tool_MystrileWateringCan_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA0E4` | `gText_Item_Tool_CursedWateringCan_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA0F8` | `gText_Item_Tool_CursedWateringCan_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA138` | `gText_Item_Tool_BlessedWateringCan_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA150` | `gText_Item_Tool_BlessedWateringCan_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA180` | `gText_Item_Tool_MythicWateringCan_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA194` | `gText_Item_Tool_MythicWateringCan_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA1B8` | `gText_Item_Tool_FishingRod_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA1C4` | `gText_Item_Tool_FishingRod_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA1DC` | `gText_Item_Tool_CopperFishingRod_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA1F0` | `gText_Item_Tool_CopperFishingRod_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA214` | `gText_Item_Tool_SilverFishingRod_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA228` | `gText_Item_Tool_SilverFishingRod_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA24C` | `gText_Item_Tool_GoldFishingRod_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA260` | `gText_Item_Tool_GoldFishingRod_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA284` | `gText_Item_Tool_MystrileFishingRod_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA29C` | `gText_Item_Tool_MystrileFishingRod_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA2C4` | `gText_Item_Tool_CursedFishingRod_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA2D8` | `gText_Item_Tool_CursedFishingRod_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA318` | `gText_Item_Tool_BlessedFishingRod_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA32C` | `gText_Item_Tool_BlessedFishingRod_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA370` | `gText_Item_Tool_MythicFishingRod_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA384` | `gText_Item_Tool_MythicFishingRod_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA3A8` | `gText_Item_Tool_CowMiraclePotion_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA3BC` | `gText_Item_Tool_CowMiraclePotion_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA3F0` | `gText_Item_Tool_SheepMiraclePotion_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA408` | `gText_Item_Tool_SheepMiraclePotion_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA440` | `gText_Item_Tool_TurnipSeeds_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA450` | `gText_Item_Tool_TurnipSeeds_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA474` | `gText_Item_Tool_PotatoSeeds_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA484` | `gText_Item_Tool_PotatoSeeds_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA4A8` | `gText_Item_Tool_CucumberSeeds_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA4B8` | `gText_Item_Tool_CucumberSeeds_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA4DC` | `gText_Item_Tool_StrawberrySeeds_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA4F0` | `gText_Item_Tool_StrawberrySeeds_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA518` | `gText_Item_Tool_CabbageSeeds_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA528` | `gText_Item_Tool_CabbageSeeds_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA54C` | `gText_Item_Tool_TomatoSeeds_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA55C` | `gText_Item_Tool_TomatoSeeds_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA580` | `gText_Item_Tool_CornSeeds_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA58C` | `gText_Item_Tool_CornSeeds_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA5AC` | `gText_Item_Tool_OnionSeeds_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA5B8` | `gText_Item_Tool_OnionSeeds_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA5D8` | `gText_Item_Tool_PumpkinSeeds_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA5E8` | `gText_Item_Tool_PumpkinSeeds_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA60C` | `gText_Item_Tool_PineappleSeeds_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA61C` | `gText_Item_Tool_PineappleSeeds_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA640` | `gText_Item_Tool_EggplantSeeds_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA650` | `gText_Item_Tool_EggplantSeeds_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA674` | `gText_Item_Tool_CarrotSeeds_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA684` | `gText_Item_Tool_CarrotSeeds_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA6A4` | `gText_Item_Tool_SweetPotatoSeeds_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA6B8` | `gText_Item_Tool_SweetPotatoSeeds_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA6E0` | `gText_Item_Tool_SpinachSeeds_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA6F0` | `gText_Item_Tool_SpinachSeeds_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA710` | `gText_Item_Tool_GreenPepperSeeds_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA724` | `gText_Item_Tool_GreenPepperSeeds_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA74C` | `gText_Item_Tool_GrassSeeds_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA758` | `gText_Item_Tool_GrassSeeds_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA784` | `gText_Item_Tool_MoonDropSeeds_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA794` | `gText_Item_Tool_MoonDropSeeds_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA7C0` | `gText_Item_Tool_PinkCatSeeds_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA7D0` | `gText_Item_Tool_PinkCatSeeds_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA7FC` | `gText_Item_Tool_MagicSeeds_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA808` | `gText_Item_Tool_MagicSeeds_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA828` | `gText_Item_Tool_ToyFlowerSeeds_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA83C` | `gText_Item_Tool_ToyFlowerSeeds_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA864` | `gText_Item_Tool_Brush_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA86C` | `gText_Item_Tool_Brush_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA8A4` | `gText_Item_Tool_Milker_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA8AC` | `gText_Item_Tool_Milker_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA8DC` | `gText_Item_Tool_Clipper_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA8E4` | `gText_Item_Tool_Clipper_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA914` | `gText_Item_Tool_Bell_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA91C` | `gText_Item_Tool_Bell_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA950` | `gText_Item_Tool_AnimalMedicine_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA960` | `gText_Item_Tool_AnimalMedicine_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA990` | `gText_Item_Tool_BlueFeather_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA9A0` | `gText_Item_Tool_BlueFeather_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA9D8` | `gText_Item_Tool_Pedometer_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA9E4` | `gText_Item_Tool_Pedometer_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EA9F0` | `gText_Item_Tool_TeleportStone_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EAA00` | `gText_Item_Tool_TeleportStone_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EAA38` | `gText_Item_Tool_GemOfTheGoddess_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EAA4C` | `gText_Item_Tool_GemOfTheGoddess_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EAA80` | `gText_Item_Tool_GemOfTheKappa_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EAA94` | `gText_Item_Tool_GemOfTheKappa_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EAAC8` | `gText_Item_Tool_GemOfTruth_Name` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EAAD8` | `gText_Item_Tool_GemOfTruth_Description` | `data/text/us/tool.cc` | `data/text/tool.o(.rodata)` |
| `0x080EAED8` | `gText_Item_Food_Turnip_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAEE0` | `gText_Item_Food_Turnip_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAF04` | `gText_Item_Food_Potato_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAF0C` | `gText_Item_Food_Potato_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAF30` | `gText_Item_Food_Cucumber_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAF3C` | `gText_Item_Food_Cucumber_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAF64` | `gText_Item_Food_Strawberry_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAF70` | `gText_Item_Food_Strawberry_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAF98` | `gText_Item_Food_Cabbage_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAFA0` | `gText_Item_Food_Cabbage_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAFC4` | `gText_Item_Food_Tomato_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAFCC` | `gText_Item_Food_Tomato_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAFF0` | `gText_Item_Food_Corn_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EAFF8` | `gText_Item_Food_Corn_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB01C` | `gText_Item_Food_Onion_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB024` | `gText_Item_Food_Onion_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB048` | `gText_Item_Food_Pumpkin_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB050` | `gText_Item_Food_Pumpkin_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB074` | `gText_Item_Food_Pineapple_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB080` | `gText_Item_Food_Pineapple_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB0A8` | `gText_Item_Food_Eggplant_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB0B4` | `gText_Item_Food_Eggplant_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB0DC` | `gText_Item_Food_Carrot_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB0E4` | `gText_Item_Food_Carrot_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB108` | `gText_Item_Food_SweetPotato_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB118` | `gText_Item_Food_SweetPotato_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB144` | `gText_Item_Food_Spinach_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB14C` | `gText_Item_Food_Spinach_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB170` | `gText_Item_Food_GreenPepper_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB180` | `gText_Item_Food_GreenPepper_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB1AC` | `gText_Item_Food_RegularQualityEgg_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB1C0` | `gText_Item_Food_RegularQualityEgg_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB1F0` | `gText_Item_Food_GoodQualityEgg_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB204` | `gText_Item_Food_GoodQualityEgg_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB234` | `gText_Item_Food_HighQualityEgg_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB248` | `gText_Item_Food_HighQualityEgg_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB278` | `gText_Item_Food_GoldenEgg_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB284` | `gText_Item_Food_GoldenEgg_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB2AC` | `gText_Item_Food_PEgg_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB2B4` | `gText_Item_Food_PEgg_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB2D8` | `gText_Item_Food_XEgg_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB2E0` | `gText_Item_Food_XEgg_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB304` | `gText_Item_Food_SpaboiledEgg_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB314` | `gText_Item_Food_SpaboiledEgg_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB358` | `gText_Item_Food_MayonnaiseS_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB368` | `gText_Item_Food_MayonnaiseS_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB3A0` | `gText_Item_Food_MayonnaiseM_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB3B0` | `gText_Item_Food_MayonnaiseM_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB3E8` | `gText_Item_Food_MayonnaiseL_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB3F8` | `gText_Item_Food_MayonnaiseL_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB430` | `gText_Item_Food_MayonnaiseG_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB440` | `gText_Item_Food_MayonnaiseG_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB478` | `gText_Item_Food_MayonnaiseP_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB488` | `gText_Item_Food_MayonnaiseP_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB4C0` | `gText_Item_Food_MayonnaiseX_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB4D0` | `gText_Item_Food_MayonnaiseX_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB508` | `gText_Item_Food_MilkS_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB514` | `gText_Item_Food_MilkS_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB54C` | `gText_Item_Food_MilkM_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB558` | `gText_Item_Food_MilkM_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB590` | `gText_Item_Food_MilkL_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB59C` | `gText_Item_Food_MilkL_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB5D4` | `gText_Item_Food_MilkG_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB5E0` | `gText_Item_Food_MilkG_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB618` | `gText_Item_Food_MilkP_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB624` | `gText_Item_Food_MilkP_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB65C` | `gText_Item_Food_MilkX_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB668` | `gText_Item_Food_MilkX_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB6A0` | `gText_Item_Food_CheeseS_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB6AC` | `gText_Item_Food_CheeseS_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB6DC` | `gText_Item_Food_CheeseM_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB6E8` | `gText_Item_Food_CheeseM_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB718` | `gText_Item_Food_CheeseL_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB724` | `gText_Item_Food_CheeseL_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB754` | `gText_Item_Food_CheeseG_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB760` | `gText_Item_Food_CheeseG_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB790` | `gText_Item_Food_CheeseP_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB79C` | `gText_Item_Food_CheeseP_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB7CC` | `gText_Item_Food_CheeseX_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB7D8` | `gText_Item_Food_CheeseX_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB808` | `gText_Item_Food_Apple_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB810` | `gText_Item_Food_Apple_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB848` | `gText_Item_Food_Honey_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB850` | `gText_Item_Food_Honey_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB888` | `gText_Item_Food_BambooShoot_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB898` | `gText_Item_Food_BambooShoot_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB8DC` | `gText_Item_Food_WildGrapes_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB8E8` | `gText_Item_Food_WildGrapes_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB92C` | `gText_Item_Food_Mushroom_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB938` | `gText_Item_Food_Mushroom_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB978` | `gText_Item_Food_PoisonousMushroom_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB98C` | `gText_Item_Food_PoisonousMushroom_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB9D4` | `gText_Item_Food_Truffle_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EB9DC` | `gText_Item_Food_Truffle_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBA10` | `gText_Item_Food_BlueGrass_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBA1C` | `gText_Item_Food_BlueGrass_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBA64` | `gText_Item_Food_GreenGrass_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBA70` | `gText_Item_Food_GreenGrass_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBAB8` | `gText_Item_Food_RedGrass_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBAC4` | `gText_Item_Food_RedGrass_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBB00` | `gText_Item_Food_YellowGrass_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBB10` | `gText_Item_Food_YellowGrass_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBB50` | `gText_Item_Food_OrangeGrass_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBB60` | `gText_Item_Food_OrangeGrass_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBB94` | `gText_Item_Food_PurpleGrass_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBBA4` | `gText_Item_Food_PurpleGrass_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBBDC` | `gText_Item_Food_IndigoGrass_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBBEC` | `gText_Item_Food_IndigoGrass_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBC2C` | `gText_Item_Food_BlackGrass_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBC38` | `gText_Item_Food_BlackGrass_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBC70` | `gText_Item_Food_WhiteGrass_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBC7C` | `gText_Item_Food_WhiteGrass_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBCB4` | `gText_Item_Food_QueenOfTheNight_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBCC8` | `gText_Item_Food_QueenOfTheNight_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBD0C` | `gText_Item_Food_Bodigizer_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBD18` | `gText_Item_Food_Bodigizer_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBD40` | `gText_Item_Food_BodigizerXl_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBD50` | `gText_Item_Food_BodigizerXl_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBD84` | `gText_Item_Food_Turbojolt_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBD90` | `gText_Item_Food_Turbojolt_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBDB8` | `gText_Item_Food_TurbojoltXl_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBDC8` | `gText_Item_Food_TurbojoltXl_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBDFC` | `gText_Item_Food_Wine_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBE04` | `gText_Item_Food_Wine_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBE40` | `gText_Item_Food_GrapeJuice_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBE4C` | `gText_Item_Food_GrapeJuice_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBE90` | `gText_Item_Food_RiceBall_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBE9C` | `gText_Item_Food_RiceBall_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBED4` | `gText_Item_Food_Bread_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBEDC` | `gText_Item_Food_Bread_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBF10` | `gText_Item_Food_Oil_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBF14` | `gText_Item_Food_Oil_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBF44` | `gText_Item_Food_Flower_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBF4C` | `gText_Item_Food_Flower_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBF80` | `gText_Item_Food_CurryPowder_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBF90` | `gText_Item_Food_CurryPowder_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBFC8` | `gText_Item_Food_MuffinMix_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EBFD4` | `gText_Item_Food_MuffinMix_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC00C` | `gText_Item_Food_Chocolate_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC018` | `gText_Item_Food_Chocolate_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC050` | `gText_Item_Food_RelaxTeaLeaves_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC064` | `gText_Item_Food_RelaxTeaLeaves_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC0AC` | `gText_Item_Food_SugdwApple_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC0B8` | `gText_Item_Food_SugdwApple_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC100` | `gText_Item_Food_HmsgbApple_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC10C` | `gText_Item_Food_HmsgbApple_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC150` | `gText_Item_Food_AepfeApple_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC15C` | `gText_Item_Food_AepfeApple_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC19C` | `gText_Item_Food_BuckwheatFlour_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC1AC` | `gText_Item_Food_BuckwheatFlour_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC1E8` | `gText_Item_Food_WildGrapeJuice_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC1FC` | `gText_Item_Food_WildGrapeJuice_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC220` | `gText_Item_Food_Salad_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC228` | `gText_Item_Food_Salad_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC268` | `gText_Item_Food_CurryRice_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC274` | `gText_Item_Food_CurryRice_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC2B4` | `gText_Item_Food_Stew_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC2BC` | `gText_Item_Food_Stew_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC2F0` | `gText_Item_Food_MisoSoup_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC2FC` | `gText_Item_Food_MisoSoup_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC338` | `gText_Item_Food_StirFry_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC344` | `gText_Item_Food_StirFry_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC380` | `gText_Item_Food_FriedRice_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC38C` | `gText_Item_Food_FriedRice_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC3C8` | `gText_Item_Food_SavoryPancake_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC3D8` | `gText_Item_Food_SavoryPancake_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC420` | `gText_Item_Food_Sandwich_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC42C` | `gText_Item_Food_Sandwich_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC464` | `gText_Item_Food_FruitJuice_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC470` | `gText_Item_Food_FruitJuice_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC4B4` | `gText_Item_Food_VegetableJuice_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC4C4` | `gText_Item_Food_VegetableJuice_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC50C` | `gText_Item_Food_MixedJuice_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC518` | `gText_Item_Food_MixedJuice_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC55C` | `gText_Item_Food_FruitLatte_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC568` | `gText_Item_Food_FruitLatte_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC5AC` | `gText_Item_Food_VegetableLatte_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC5BC` | `gText_Item_Food_VegetableLatte_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC5F8` | `gText_Item_Food_MixedLatte_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC604` | `gText_Item_Food_MixedLatte_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC644` | `gText_Item_Food_StrawberryMilk_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC654` | `gText_Item_Food_StrawberryMilk_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC69C` | `gText_Item_Food_StrawberryJam_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC6AC` | `gText_Item_Food_StrawberryJam_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC6F4` | `gText_Item_Food_TomatoJuice_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC704` | `gText_Item_Food_TomatoJuice_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC74C` | `gText_Item_Food_PickledTurnip_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC75C` | `gText_Item_Food_PickledTurnip_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC798` | `gText_Item_Food_FrenchFries_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC7A8` | `gText_Item_Food_FrenchFries_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC7E8` | `gText_Item_Food_Pickles_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC7F0` | `gText_Item_Food_Pickles_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC828` | `gText_Item_Food_Ketchup_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC830` | `gText_Item_Food_Ketchup_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC870` | `gText_Item_Food_Popcorn_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC878` | `gText_Item_Food_Popcorn_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC8B4` | `gText_Item_Food_CornFlakes_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC8C0` | `gText_Item_Food_CornFlakes_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC900` | `gText_Item_Food_BakedCorn_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC90C` | `gText_Item_Food_BakedCorn_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC948` | `gText_Item_Food_PineappleJuice_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC958` | `gText_Item_Food_PineappleJuice_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC9A0` | `gText_Item_Food_PumpkinPudding_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC9B0` | `gText_Item_Food_PumpkinPudding_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EC9F0` | `gText_Item_Food_PumpkinStew_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECA00` | `gText_Item_Food_PumpkinStew_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECA40` | `gText_Item_Food_HappyEggplant_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECA50` | `gText_Item_Food_HappyEggplant_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECA94` | `gText_Item_Food_SweetPotatoes_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECAA4` | `gText_Item_Food_SweetPotatoes_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECAE0` | `gText_Item_Food_BakedSweetPotato_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECAF4` | `gText_Item_Food_BakedSweetPotato_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECB38` | `gText_Item_Food_Greens_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECB40` | `gText_Item_Food_Greens_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECB7C` | `gText_Item_Food_ScrambledEggs_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECB8C` | `gText_Item_Food_ScrambledEggs_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECBCC` | `gText_Item_Food_Omelet_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECBD4` | `gText_Item_Food_Omelet_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECC0C` | `gText_Item_Food_OmeletRice_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECC18` | `gText_Item_Food_OmeletRice_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECC58` | `gText_Item_Food_BoiledEgg_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECC64` | `gText_Item_Food_BoiledEgg_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECCA4` | `gText_Item_Food_HotMilk_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECCB0` | `gText_Item_Food_HotMilk_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECCEC` | `gText_Item_Food_Butter_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECCF4` | `gText_Item_Food_Butter_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECD2C` | `gText_Item_Food_CheeseCake_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECD38` | `gText_Item_Food_CheeseCake_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECD78` | `gText_Item_Food_CheeseFondue_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECD88` | `gText_Item_Food_CheeseFondue_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECDCC` | `gText_Item_Food_ApplePie_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECDD8` | `gText_Item_Food_ApplePie_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECE14` | `gText_Item_Food_AppleJam_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECE20` | `gText_Item_Food_AppleJam_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECE60` | `gText_Item_Food_AppleSouffl_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECE70` | `gText_Item_Food_AppleSouffl_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECEB4` | `gText_Item_Food_MushroomRice_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECEC4` | `gText_Item_Food_MushroomRice_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECF04` | `gText_Item_Food_BambooRice_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECF10` | `gText_Item_Food_BambooRice_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECF54` | `gText_Item_Food_TruffleRice_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECF64` | `gText_Item_Food_TruffleRice_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECFA0` | `gText_Item_Food_Sushi_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECFA8` | `gText_Item_Food_Sushi_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECFD8` | `gText_Item_Food_JamBun_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ECFE0` | `gText_Item_Food_JamBun_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED01C` | `gText_Item_Food_DinnerRole_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED028` | `gText_Item_Food_DinnerRole_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED06C` | `gText_Item_Food_RaisinBread_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED07C` | `gText_Item_Food_RaisinBread_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED0BC` | `gText_Item_Food_GrapeJam_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED0C8` | `gText_Item_Food_GrapeJam_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED104` | `gText_Item_Food_CurryBread_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED110` | `gText_Item_Food_CurryBread_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED154` | `gText_Item_Food_Sashimi_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED15C` | `gText_Item_Food_Sashimi_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED198` | `gText_Item_Food_GrilledFish_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED1A8` | `gText_Item_Food_GrilledFish_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED1E8` | `gText_Item_Food_ChirashiSushi_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED1F8` | `gText_Item_Food_ChirashiSushi_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED240` | `gText_Item_Food_Pizza_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED248` | `gText_Item_Food_Pizza_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED280` | `gText_Item_Food_Noodles_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED288` | `gText_Item_Food_Noodles_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED2BC` | `gText_Item_Food_CurryNoodles_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED2CC` | `gText_Item_Food_CurryNoodles_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED314` | `gText_Item_Food_TempuraNoodles_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED324` | `gText_Item_Food_TempuraNoodles_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED364` | `gText_Item_Food_FriedNoodles_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED374` | `gText_Item_Food_FriedNoodles_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED3B0` | `gText_Item_Food_BuckwheatNoodles_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED3C4` | `gText_Item_Food_BuckwheatNoodles_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED400` | `gText_Item_Food_NoodlesWTempura_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED414` | `gText_Item_Food_NoodlesWTempura_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED45C` | `gText_Item_Food_BuckwheatChips_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED46C` | `gText_Item_Food_BuckwheatChips_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED4B4` | `gText_Item_Food_Cookies_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED4BC` | `gText_Item_Food_Cookies_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED4F4` | `gText_Item_Food_ChocolateCookies_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED508` | `gText_Item_Food_ChocolateCookies_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED548` | `gText_Item_Food_Tempura_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED550` | `gText_Item_Food_Tempura_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED580` | `gText_Item_Food_IceCream_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED58C` | `gText_Item_Food_IceCream_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED5C4` | `gText_Item_Food_Cake_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED5CC` | `gText_Item_Food_Cake_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED5FC` | `gText_Item_Food_ChocolateCake_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED60C` | `gText_Item_Food_ChocolateCake_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED64C` | `gText_Item_Food_RelaxationTea_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED65C` | `gText_Item_Food_RelaxationTea_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED69C` | `gText_Item_Food_Toast_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED6A4` | `gText_Item_Food_Toast_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED6D4` | `gText_Item_Food_FrenchToast_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED6E4` | `gText_Item_Food_FrenchToast_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED724` | `gText_Item_Food_Pudding_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED72C` | `gText_Item_Food_Pudding_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED764` | `gText_Item_Food_MountainStew_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED774` | `gText_Item_Food_MountainStew_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED7B4` | `gText_Item_Food_MoonDumplings_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED7C4` | `gText_Item_Food_MoonDumplings_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED80C` | `gText_Item_Food_RiceCake_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED818` | `gText_Item_Food_RiceCake_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED858` | `gText_Item_Food_RoastedRiceCake_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED86C` | `gText_Item_Food_RoastedRiceCake_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED8B0` | `gText_Item_Food_ElliLeaves_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED8BC` | `gText_Item_Food_ElliLeaves_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED900` | `gText_Item_Food_FailedDish_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED90C` | `gText_Item_Food_FailedDish_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED93C` | `gText_Item_Food_FailedDrink_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED94C` | `gText_Item_Food_FailedPotDish_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED95C` | `gText_Item_Food_FailedDessert_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED96C` | `gText_Item_Food_FailedBread_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED97C` | `gText_Item_Food_FailedNoodles_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED98C` | `gText_Item_Food_SmallFish_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED998` | `gText_Item_Food_SmallFish_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED9D8` | `gText_Item_Food_MediumFish_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080ED9E4` | `gText_Item_Food_MediumFish_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EDA28` | `gText_Item_Food_LargeFish_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EDA34` | `gText_Item_Food_LargeFish_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EDA74` | `gText_Item_Food_ToastedRiceBall_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EDA88` | `gText_Item_Food_ToastedRiceBall_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EDAC8` | `gText_Item_Food_TempuraRice_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EDAD8` | `gText_Item_Food_TempuraRice_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EDB14` | `gText_Item_Food_EggOverRice_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EDB24` | `gText_Item_Food_EggOverRice_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EDB68` | `gText_Item_Food_RiceGruel_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EDB74` | `gText_Item_Food_RiceGruel_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EDBAC` | `gText_Item_Food_Pancakes_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EDBB8` | `gText_Item_Food_Pancakes_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EDBF0` | `gText_Item_Food_FishSticks_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EDBFC` | `gText_Item_Food_FishSticks_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EDC34` | `gText_Item_Food_CandiedPotato_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EDC44` | `gText_Item_Food_CandiedPotato_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EDC88` | `gText_Item_Food_PotatoPancakes_Name` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EDC98` | `gText_Item_Food_PotatoPancakes_Description` | `data/text/us/food.cc` | `data/text/food.o(.rodata)` |
| `0x080EE788` | `gText_Item_Article_MoonDropGrass_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE798` | `gText_Item_Article_MoonDropGrass_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE7D0` | `gText_Item_Article_PinkCatGrass_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE7E0` | `gText_Item_Article_PinkCatGrass_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE818` | `gText_Item_Article_BlueMagicGrass_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE82C` | `gText_Item_Article_BlueMagicGrass_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE864` | `gText_Item_Article_RedMagicGrass_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE874` | `gText_Item_Article_RedMagicGrass_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE8AC` | `gText_Item_Article_ToyFlower_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE8B8` | `gText_Item_Article_ToyFlower_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE8EC` | `gText_Item_Article_WoolS_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE8F8` | `gText_Item_Article_WoolS_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE918` | `gText_Item_Article_WoolM_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE924` | `gText_Item_Article_WoolM_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE944` | `gText_Item_Article_WoolL_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE950` | `gText_Item_Article_WoolL_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE970` | `gText_Item_Article_WoolG_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE97C` | `gText_Item_Article_WoolG_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE99C` | `gText_Item_Article_WoolP_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE9A8` | `gText_Item_Article_WoolP_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE9C8` | `gText_Item_Article_YarnS_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EE9D4` | `gText_Item_Article_YarnS_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEA08` | `gText_Item_Article_YarnM_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEA14` | `gText_Item_Article_YarnM_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEA48` | `gText_Item_Article_YarnL_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEA54` | `gText_Item_Article_YarnL_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEA88` | `gText_Item_Article_YarnG_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEA94` | `gText_Item_Article_YarnG_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEAC8` | `gText_Item_Article_YarnP_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEAD4` | `gText_Item_Article_YarnP_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEB08` | `gText_Item_Article_YarnX_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEB14` | `gText_Item_Article_YarnX_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEB48` | `gText_Item_Article_JunkOre_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEB54` | `gText_Item_Article_JunkOre_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEB90` | `gText_Item_Article_Copper_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEB98` | `gText_Item_Article_Copper_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEBCC` | `gText_Item_Article_Silver_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEBD4` | `gText_Item_Article_Silver_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEC08` | `gText_Item_Article_Gold_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEC10` | `gText_Item_Article_Gold_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEC40` | `gText_Item_Article_Mystrile_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEC4C` | `gText_Item_Article_Mystrile_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEC80` | `gText_Item_Article_Orichalc_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEC8C` | `gText_Item_Article_Orichalc_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EECC0` | `gText_Item_Article_Adamantite_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EECCC` | `gText_Item_Article_Adamantite_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EED00` | `gText_Item_Article_MoonStone_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EED0C` | `gText_Item_Article_MoonStone_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EED44` | `gText_Item_Article_SandRose_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EED50` | `gText_Item_Article_SandRose_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EED88` | `gText_Item_Article_PinkDiamond_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EED98` | `gText_Item_Article_PinkDiamond_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEDD0` | `gText_Item_Article_Alexandrite_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEDDC` | `gText_Item_Article_Alexandrite_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEE14` | `gText_Item_Article_MythicStone_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEE24` | `gText_Item_Article_MythicStone_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEE64` | `gText_Item_Article_Diamond_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEE6C` | `gText_Item_Article_Diamond_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEE9C` | `gText_Item_Article_Emerald_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEEA4` | `gText_Item_Article_Emerald_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEED4` | `gText_Item_Article_Ruby_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEEDC` | `gText_Item_Article_Ruby_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEF10` | `gText_Item_Article_Topaz_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEF18` | `gText_Item_Article_Topaz_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEF4C` | `gText_Item_Article_Peridot_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEF54` | `gText_Item_Article_Peridot_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEF88` | `gText_Item_Article_Fluorite_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEF94` | `gText_Item_Article_Fluorite_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEFCC` | `gText_Item_Article_Agate_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EEFD4` | `gText_Item_Article_Agate_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF008` | `gText_Item_Article_Amethyst_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF014` | `gText_Item_Article_Amethyst_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF04C` | `gText_Item_Article_HarvestGoddessJewel_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF064` | `gText_Item_Article_HarvestGoddessJewel_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF0AC` | `gText_Item_Article_KappaJewel_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF0B8` | `gText_Item_Article_KappaJewel_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF0F8` | `gText_Item_Article_JewelOfTruth_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF108` | `gText_Item_Article_JewelOfTruth_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF13C` | `gText_Item_Article_TheSpringSun_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF14C` | `gText_Item_Article_TheSpringSun_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF16C` | `gText_Item_Article_TheSummerSun_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF17C` | `gText_Item_Article_TheAutumnSun_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF18C` | `gText_Item_Article_TheWinterSun_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF19C` | `gText_Item_Article_Bracelet_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF1A8` | `gText_Item_Article_Bracelet_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF1DC` | `gText_Item_Article_Necklace_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF1E8` | `gText_Item_Article_Necklace_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF21C` | `gText_Item_Article_Earrings_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF228` | `gText_Item_Article_Earrings_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF25C` | `gText_Item_Article_Broach_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF264` | `gText_Item_Article_Broach_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF294` | `gText_Item_Article_Weeds_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF29C` | `gText_Item_Article_Weeds_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF2D0` | `gText_Item_Article_Stones_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF2D8` | `gText_Item_Article_Stones_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF31C` | `gText_Item_Article_Branches_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF328` | `gText_Item_Article_Branches_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF368` | `gText_Item_Article_Lithograph_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF374` | `gText_Item_Article_Lithograph_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF3C4` | `gText_Item_Article_MessageInABottle_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF3D8` | `gText_Item_Article_MessageInABottle_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF41C` | `gText_Item_Article_Ball_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF424` | `gText_Item_Article_Ball_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF438` | `gText_Item_Article_PirateTreasure_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF448` | `gText_Item_Article_PirateTreasure_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF488` | `gText_Item_Article_FossilOfFish_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF498` | `gText_Item_Article_FossilOfFish_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF4CC` | `gText_Item_Article_EmptyCan_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF4D8` | `gText_Item_Article_EmptyCan_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF4F0` | `gText_Item_Article_Boots_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF4F8` | `gText_Item_Article_Boots_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF50C` | `gText_Item_Article_FishBones_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF518` | `gText_Item_Article_FishBones_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF530` | `gText_Item_Article_KarensWine_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF540` | `gText_Item_Article_KarensWine_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF584` | `gText_Item_Article_PopurisMudBall_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF598` | `gText_Item_Article_PopurisMudBall_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF5CC` | `gText_Item_Article_AnnsMusicBox_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF5DC` | `gText_Item_Article_AnnsMusicBox_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF624` | `gText_Item_Article_MarysGreatBook_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF638` | `gText_Item_Article_MarysGreatBook_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF674` | `gText_Item_Article_EllisPressedFlower_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF688` | `gText_Item_Article_EllisPressedFlower_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF6D0` | `gText_Item_Article_Album1_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF6D8` | `gText_Item_Article_Album1_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF6FC` | `gText_Item_Article_Album2_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF704` | `gText_Item_Article_Album2_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF724` | `gText_Item_Article_Album3_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF72C` | `gText_Item_Article_Album3_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF750` | `gText_Item_Article_Album4_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF758` | `gText_Item_Article_Album4_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF778` | `gText_Item_Article_Album5_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF780` | `gText_Item_Article_Album5_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF7A4` | `gText_Item_Article_Album6_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF7AC` | `gText_Item_Article_Album6_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF7D0` | `gText_Item_Article_Album7_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF7D8` | `gText_Item_Article_Album7_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF7FC` | `gText_Item_Article_Album8_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF804` | `gText_Item_Article_Album8_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF828` | `gText_Item_Article_Album9_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF830` | `gText_Item_Article_Album9_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF854` | `gText_Item_Article_Album10_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF860` | `gText_Item_Article_Album10_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF880` | `gText_Item_Article_Album11_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF88C` | `gText_Item_Article_Album11_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF8D0` | `gText_Item_Article_Album12_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF8DC` | `gText_Item_Article_Album12_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF920` | `gText_Item_Article_Album13_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF92C` | `gText_Item_Article_Album13_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF970` | `gText_Item_Article_Album14_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF97C` | `gText_Item_Article_Album14_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF9C0` | `gText_Item_Article_Album15_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EF9CC` | `gText_Item_Article_Album15_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFA10` | `gText_Item_Article_Bandaid_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFA1C` | `gText_Item_Article_Bandaid_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFA50` | `gText_Item_Article_Book_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFA58` | `gText_Item_Article_Book_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFAAC` | `gText_Item_Article_Perfume_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFAB4` | `gText_Item_Article_Perfume_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFAF4` | `gText_Item_Article_Photo_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFAFC` | `gText_Item_Article_Photo_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFB38` | `gText_Item_Article_PlantEncyclopedia_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFB4C` | `gText_Item_Article_PlantEncyclopedia_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFB98` | `gText_Item_Article_Invitation_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFBA4` | `gText_Item_Article_Invitation_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFBE4` | `gText_Item_Article_Dress_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFBEC` | `gText_Item_Article_Dress_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFC28` | `gText_Item_Article_FacialPack_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFC34` | `gText_Item_Article_FacialPack_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFC74` | `gText_Item_Article_SkinLotion_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFC80` | `gText_Item_Article_SkinLotion_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFCC8` | `gText_Item_Article_Sunblock_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFCD4` | `gText_Item_Article_Sunblock_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFD08` | `gText_Item_Article_Lumber_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFD10` | `gText_Item_Article_Lumber_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFD48` | `gText_Item_Article_GoldenLumber_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFD58` | `gText_Item_Article_GoldenLumber_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFD98` | `gText_Item_Article_AnimalFodder_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFDA8` | `gText_Item_Article_AnimalFodder_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFDE8` | `gText_Item_Article_ChickenFeed_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFDF8` | `gText_Item_Article_ChickenFeed_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFE34` | `gText_Item_Article_Lottery_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFE3C` | `gText_Item_Article_Lottery_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFE94` | `gText_Item_Article_Frisbee_Name` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080EFE9C` | `gText_Item_Article_Frisbee_Description` | `data/text/us/article.cc` | `data/text/article.o(.rodata)` |
| `0x080F04EE` | `gText_Calendar_SeasonNames` | `data/text/us/calendar.cc` | `data/text/calendar.o(.rodata.calendar_season)` |
| `0x080F050C` | `gText_Calendar_None` | `data/text/us/calendar.cc` | `data/text/calendar.o(.rodata)` |
| `0x080F050F` | `gText_Calendar_WeekdayNames` | `data/text/us/calendar.cc` | `data/text/calendar.o(.rodata)` |
| `0x080F0554` | `gText_CalendarTrailerFallbackNone` | `data/text/us/calendar.cc` | `data/text/calendar.o(.rodata)` |
| `0x080F058C` | `gText_LoadError` | `data/text/us/load_error.cc` | `data/text/load_error.o(.rodata)` |
| `0x080F05A8` | `gText_LoadErrorFallbackNone` | `data/text/us/load_error.cc` | `data/text/load_error.o(.rodata)` |
| `0x080F05B8` | `gText_HelpMenu_Crops` | `data/text/us/help_menu.cc` | `src/help_menu.o(.rodata)` |
| `0x080F05C0` | `gText_HelpMenu_Animals` | `data/text/us/help_menu.cc` | `src/help_menu.o(.rodata)` |
| `0x080F05C8` | `gText_HelpMenu_UsefulTips` | `data/text/us/help_menu.cc` | `src/help_menu.o(.rodata)` |
| `0x080F05D4` | `gText_HelpMenu_Exit` | `data/text/us/help_menu.cc` | `src/help_menu.o(.rodata)` |
| `0x080F0654` | `gText_AnimalMemorial_LineBreak` | `data/text/us/animal_memorial.cc` | `data/text/animal_memorial.o(.rodata)` |
| `0x080F0658` | `gText_AnimalMemorial_Continue` | `data/text/us/animal_memorial.cc` | `data/text/animal_memorial.o(.rodata)` |
| `0x080F065C` | `gText_AnimalMemorial_PageBreak` | `data/text/us/animal_memorial.cc` | `data/text/animal_memorial.o(.rodata)` |
| `0x080F0660` | `gText_AnimalMemorial_Header` | `data/text/us/animal_memorial.cc` | `data/text/animal_memorial.o(.rodata)` |
| `0x080F067C` | `gText_AnimalMemorial_FarmPrefix` | `data/text/us/animal_memorial.cc` | `data/text/animal_memorial.o(.rodata)` |
| `0x080F0684` | `gText_AnimalMemorial_FarmSuffix` | `data/text/us/animal_memorial.cc` | `data/text/animal_memorial.o(.rodata)` |
| `0x080F068C` | `gText_AnimalMemorial_PassedAway` | `data/text/us/animal_memorial.cc` | `data/text/animal_memorial.o(.rodata)` |
| `0x080F069C` | `gText_AnimalMemorial_NamesIntro` | `data/text/us/animal_memorial.cc` | `data/text/animal_memorial.o(.rodata)` |
| `0x080F06B4` | `gText_AnimalMemorial_PrayerIntro` | `data/text/us/animal_memorial.cc` | `data/text/animal_memorial.o(.rodata)` |
| `0x080F06D0` | `gText_AnimalMemorial_PrayerEnding` | `data/text/us/animal_memorial.cc` | `data/text/animal_memorial.o(.rodata)` |
| `0x080F06F8` | `gText_AnimalMemorialFallbackNone` | `data/text/us/animal_memorial.cc` | `data/text/animal_memorial.o(.rodata)` |
| `0x080F0830` | `gText_AnimalDataFallbackNone` | `data/text/us/animal_data.cc` | `src/animal_data.o(.rodata)` |
| `0x080F0E80` | `gText_NotAvailable` | `data/text/us/entity_ui.cc` | `src/entity_ui.o(.rodata)` |
| `0x080F1974` | `gText_Moneybags` | `data/text/us/fixed_labels.cc` | `src/fixed_labels.o(.rodata)` |
| `0x080F1984` | `gText_UnnamedSetting` | `data/text/us/fixed_labels.cc` | `src/fixed_labels.o(.rodata)` |
| `0x080F19A0` | `gText_Fallback_Error` | `data/text/common/ui_error.cc` | `src/ui_error.o(.rodata)` |
| `0x080F19A8` | `gText_Fallback_None` | `data/text/us/ui_error.cc` | `src/ui_error.o(.rodata)` |
| `0x080F19E8` | `gText_Menu_Diary` | `data/text/us/menu.cc` | `src/menu_data.o(.rodata)` |
| `0x080F19F0` | `gText_Menu_Rucksack` | `data/text/us/menu.cc` | `src/menu_data.o(.rodata)` |
| `0x080F19FC` | `gText_Menu_WorldMap` | `data/text/us/menu.cc` | `src/menu_data.o(.rodata)` |
| `0x080F1A08` | `gText_Menu_FarmMap` | `data/text/us/menu.cc` | `src/menu_data.o(.rodata)` |
| `0x080F1A14` | `gText_Menu_Earnings` | `data/text/us/menu.cc` | `src/menu_data.o(.rodata)` |
| `0x080F1A20` | `gText_Menu_Memo` | `data/text/us/menu.cc` | `src/menu_data.o(.rodata)` |
| `0x080F1A28` | `gText_Menu_Tutorial` | `data/text/us/menu.cc` | `src/menu_data.o(.rodata)` |
| `0x080F9EA4` | `gText_AScriptEngine_InvalidStringId` | `data/text/common/script_engine.cc` | `data/text/common/script_engine.o(.rodata)` |
| `0x080F9EB8` | `gText_ScriptEngineUi_Error` | `data/text/common/script_engine.cc` | `data/text/common/script_engine.o(.rodata)` |
| `0x080F9EC0` | `gText_ScriptEngineUi_FallbackNone` | `data/text/common/script_engine.cc` | `data/text/common/script_engine.o(.rodata)` |
| `0x080F9F8A` | `gText_NameEntry_PresetAnimalNames` | `data/text/us/new_game.cc` | `data/text/new_game_name_entry_preset.o(.rodata)` |
| `0x080FA158` | `gText_Frisbee_TournamentScoreboard` | `data/text/us/frisbee.cc` | `data/text/frisbee_scoreboard.o(.rodata)` |
| `0x080FA39C` | `gText_Frisbee_ExplanationQuestion` | `data/text/us/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080FA3B8` | `gText_Frisbee_Yes` | `data/text/us/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080FA3BC` | `gText_Frisbee_No` | `data/text/us/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080FA3C0` | `gText_Frisbee_ExplanationCursorTiming` | `data/text/us/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080FA458` | `gText_Frisbee_ExplanationGreenZone` | `data/text/us/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080FA49C` | `gText_Frisbee_ExplanationRedZone` | `data/text/us/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080FA510` | `gText_Frisbee_ExplanationPractice` | `data/text/us/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080FA614` | `gText_Frisbee_ExplanationTournament` | `data/text/us/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080FA660` | `gText_Frisbee_ExplainAgain` | `data/text/us/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080FA670` | `gText_Frisbee_ThrowAgain` | `data/text/us/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080FA684` | `gText_Frisbee_TournamentFinished` | `data/text/us/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080FA6A0` | `gText_Frisbee_PlayAgain` | `data/text/us/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080FA6AC` | `gText_Frisbee_DogNoLongerWantsToPlay` | `data/text/us/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080FA6E0` | `gText_Frisbee_FoundItem` | `data/text/us/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080FA6F4` | `gText_Frisbee_FoundNothing` | `data/text/us/frisbee.cc` | `data/text/frisbee.o(.rodata)` |
| `0x080FA796` | `gText_AnimalFestival_LivestockContestantNames` | `data/text/us/animal_festival.cc` | `data/text/animal_festival.o(.rodata)` |
| `0x080FAA40` | `gText_HorseRace_BuyTicketDeclined` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAA5C` | `gText_HorseRace_Yes` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAA60` | `gText_HorseRace_No` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAA64` | `gText_HorseRace_ComeAgain` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAA74` | `gText_HorseRace_TakeYourTime` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAA88` | `gText_HorseRace_TicketPurchaseConfirmation` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAAA4` | `gText_HorseRace_TicketPurchaseApproval` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAACC` | `gText_HorseRace_ChangeMind` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAAE0` | `gText_HorseRace_ExplanationQuestion` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAAFC` | `gText_HorseRace_ExplanationBasics` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAB94` | `gText_HorseRace_ExplanationGreenStamina` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FABE0` | `gText_HorseRace_ExplanationYellowStamina` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAC24` | `gText_HorseRace_ExplanationRedStamina` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAC8C` | `gText_HorseRace_ExplanationStaminaRecovery` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAD08` | `gText_HorseRace_ExplanationUnderstoodQuestion` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAD20` | `gText_HorseRace_ExplanationUnderstood` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAD28` | `gText_HorseRace_ExplanationRepeat` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAD34` | `gText_HorseRace_StartRace` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAD50` | `gText_HorseRace_RaceStartAnnouncement` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAD94` | `gText_HorseRace_RaceResults` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FADDC` | `gText_HorseRace_RacePayouts` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAE00` | `gText_HorseRace_MedalExchangeExplanation` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAE9C` | `gText_HorseRace_TicketPurchaseTitle` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAEB8` | `gText_HorseRace_TicketPurchaseConfirm` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAEC4` | `gText_HorseRace_TicketPurchaseMedalsToWin` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAEDC` | `gText_HorseRace_TicketControls_DPadUpDown` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAEF4` | `gText_HorseRace_TicketControls_SelectHorse` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAF10` | `gText_HorseRace_TicketControls_DPadLeftRight` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAF28` | `gText_HorseRace_TicketControls_ChangeQuantity` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAF44` | `gText_HorseRace_TicketControls_LRButtons` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAF54` | `gText_HorseRace_TicketControls_ChangeQuantityByTen` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAF70` | `gText_HorseRace_TicketControls_ChangeQuantityByTenContinuation` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAF7C` | `gText_HorseRace_TicketControls_MoveCursorToConfirm` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAF94` | `gText_HorseRace_TicketControls_Buy` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FAFAC` | `gText_HorseRace_TicketControls_Cancel` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FB108` | `gText_HorseRace_PrizeExchangePrompt` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FB120` | `gText_HorseRace_PrizeExchangeYes` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FB124` | `gText_HorseRace_PrizeExchangeNo` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FB128` | `gText_HorseRace_PrizeExchangeComeAgain` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FB140` | `gText_HorseRace_PrizeExchangeTakeYourTime` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FB158` | `gText_HorseRace_PrizeSelectionConfirmation` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FB164` | `gText_HorseRace_PrizeExchangeLeaveConfirmation` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FB17C` | `gText_HorseRace_PrizeExchangeInsufficientMedals` | `data/text/us/horse_race.cc` | `src/horse_race_data.o(.rodata)` |
| `0x080FB234` | `gText_IntroScene_MotherName` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB23C` | `gText_IntroScene_MotherTravelGreeting` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB27C` | `gText_IntroScene_FatherName` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB284` | `gText_IntroScene_FatherFishingInvitation` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB2D0` | `gText_IntroScene_MotherCannotFindPlayer` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB2F4` | `gText_IntroScene_PlayerResponseWhat` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB300` | `gText_IntroScene_OldManName` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB308` | `gText_IntroScene_OldManFindsPlayer` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB398` | `gText_IntroScene_MotherThanksOldMan` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB3CC` | `gText_IntroScene_FatherExplainsVacation` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB420` | `gText_IntroScene_OldManOffersStay` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB46C` | `gText_IntroScene_FatherAsksAboutStay` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB484` | `gText_IntroScene_OldManWelcomesFamily` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB4D4` | `gText_IntroScene_MotherTellsPlayerToPlay` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB51C` | `gText_IntroScene_UnknownName` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB520` | `gText_IntroScene_UnknownCallsPlayer` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB534` | `gText_IntroScene_UnknownFindsPlayer` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB53C` | `gText_IntroScene_GirlName` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB544` | `gText_IntroScene_GirlThinksPlayerDead` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB578` | `gText_IntroScene_GirlInvitesPlayerToPlay` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB5D4` | `gText_IntroScene_GirlAsksPlayerStory` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB634` | `gText_IntroScene_OldManFarewell` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB6C0` | `gText_IntroScene_OldManRequestsLetter` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB710` | `gText_IntroScene_OldManGivesAddress` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB738` | `gText_IntroScene_GirlSaysGoodbye` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB754` | `gText_IntroScene_GirlAsksPlayerToReturn` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB7A0` | `gText_IntroScene_OldManNotesFriend` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB7F0` | `gText_IntroScene_OldManWaitsForLetter` | `data/text/us/intro_scene.cc` | `data/text/intro_scene.o(.rodata)` |
| `0x080FB824` | `gText_FarmStatus_OverviewTitle` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB830` | `gText_FarmStatus_CountFieldPadding` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB834` | `gText_FarmStatus_GoldUnit` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB838` | `gText_FarmStatus_Healthy` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB844` | `gText_FarmStatus_Unhappy` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB850` | `gText_FarmStatus_Sick` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB85C` | `gText_FarmStatus_Spring` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB864` | `gText_FarmStatus_Summer` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB86C` | `gText_FarmStatus_Autumn` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB874` | `gText_FarmStatus_Winter` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB87C` | `gText_FarmStatus_AgeUnit` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB880` | `gText_FarmStatus_ChickenList` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB894` | `gText_FarmStatus_CattleList` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB8A4` | `gText_FarmStatus_SheepList` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB8B4` | `gText_FarmStatus_HarvestSpriteList` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB8C8` | `gText_FarmStatus_DayAbbreviation` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB8CC` | `gText_FarmStatus_DaysRemaining` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB8D4` | `gText_FarmStatus_WorkAssignment` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB8E0` | `gText_FarmStatus_NotAssigned` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB8F0` | `gText_FarmStatus_EarningsReport` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB904` | `gText_FarmStatus_PlusSign` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB908` | `gText_FarmStatus_MinusSign` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB90C` | `gText_FarmStatus_YearLabel` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB914` | `gText_FarmStatus_Income` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB91C` | `gText_FarmStatus_Expenses` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB928` | `gText_FarmStatus_ToolLevelList` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB93C` | `gText_FarmStatus_ToolShopLabel` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB944` | `gText_FarmStatus_ToolUpgradeQuestion` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB950` | `gText_FarmStatus_PercentSign` | `data/text/us/farm_status.cc` | `data/text/farm_status.o(.rodata)` |
| `0x080FB9C8` | `gText_AnimalContest_ChickenConfirmation` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB9DC` | `gText_AnimalContest_Yes` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB9E0` | `gText_AnimalContest_No` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB9E4` | `gText_AnimalContest_CowConfirmation` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FB9F4` | `gText_AnimalContest_SheepConfirmation` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FBA08` | `gText_AnimalContest_BabyChickIneligible` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FBA3C` | `gText_AnimalContest_AdultCowIneligible` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FBA70` | `gText_AnimalContest_AdultSheepIneligible` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FBAA8` | `gText_AnimalContest_SickChickenIneligible` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FBAE0` | `gText_AnimalContest_SickCowIneligible` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FBB14` | `gText_AnimalContest_SickSheepIneligible` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FBB4C` | `gText_AnimalContest_PregnantCowIneligible` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FBB80` | `gText_AnimalContest_PregnantSheepIneligible` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FBBB8` | `gText_AnimalContest_ShornSheepIneligible` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FBBEC` | `gText_AnimalContest_EntryAccepted` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FBC18` | `gText_AnimalContest_ChickenSelectionPrompt` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FBC48` | `gText_AnimalContest_CowSelectionPrompt` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FBC70` | `gText_AnimalContest_SheepSelectionPrompt` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FBC9C` | `gText_AnimalContest_EntryDeclinedQuestion` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FBCB8` | `gText_AnimalContest_ChickenEntryDeclinedResponse` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FBCE0` | `gText_AnimalContest_LivestockEntryDeclinedResponse` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FBD18` | `gText_AnimalContest_FinalConfirmation` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FBD28` | `gText_AnimalContest_FinalYes` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FBD2C` | `gText_AnimalContest_FinalNo` | `data/text/us/animal_contest.cc` | `data/text/animal_contest.o(.rodata)` |
| `0x080FBE7C` | `gText_Records_NumberShipped` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBE8C` | `gText_Records_ShippedCountSuffix` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBE90` | `gText_Records_Fishing` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBE9C` | `gText_Records_Name` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBEA4` | `gText_Records_MaximumSize` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBEB4` | `gText_Records_Results` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBEC0` | `gText_Records_FishUnit` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBEC8` | `gText_Records_MeterUnit` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBECC` | `gText_Records_CentimeterUnit` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBED4` | `gText_Records_Separator` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBED8` | `gText_Records_Other` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBEE0` | `gText_Records_MiniGameRecords` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBEFC` | `gText_Records_Harvest` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBF08` | `gText_Records_AnimalHusbandry` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBF1C` | `gText_Records_Watering` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBF28` | `gText_Records_Frisbee` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBF34` | `gText_Records_SecondsUnit` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBF3C` | `gText_Records_IncomeExpenses` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBF58` | `gText_Records_HighestAmount` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBF68` | `gText_Records_Earned` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBF74` | `gText_Records_Used` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBF80` | `gText_Records_GoldUnit` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBF84` | `gText_Records_LongestLivingAnimal` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBFA0` | `gText_Records_Chicken` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBFAC` | `gText_Records_Cow` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBFB4` | `gText_Records_Sheep` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBFBC` | `gText_Records_YearsUnit` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBFC4` | `gText_Records_MonthsUnit` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBFC8` | `gText_Records_DaysUnit` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBFCC` | `gText_Records_MineDepth` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBFE8` | `gText_Records_MineDepthPadding` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FBFF0` | `gText_Records_BelowGround` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FC008` | `gText_Records_MolesWhacked` | `data/text/us/records.cc` | `src/records_screen_data.o(.rodata)` |
| `0x080FC0A4` | `gText_StaffCredits_Line000` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC0AC` | `gText_StaffCredits_EmptyLine` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC0B0` | `gText_StaffCredits_Line004` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC0C0` | `gText_StaffCredits_Line006` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC0D0` | `gText_StaffCredits_Line007` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC0E0` | `gText_StaffCredits_Line008` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC0F0` | `gText_StaffCredits_Line009` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC100` | `gText_StaffCredits_Line010` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC110` | `gText_StaffCredits_Line011` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC120` | `gText_StaffCredits_Line015` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC12C` | `gText_StaffCredits_Line017` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC13C` | `gText_StaffCredits_Line018` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC14C` | `gText_StaffCredits_Line019` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC158` | `gText_StaffCredits_Line020` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC16C` | `gText_StaffCredits_Line021` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC17C` | `gText_StaffCredits_Line022` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC18C` | `gText_StaffCredits_Line026` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC194` | `gText_StaffCredits_Line028` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC1A4` | `gText_StaffCredits_Line032` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC1B0` | `gText_StaffCredits_Line034` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC1C4` | `gText_StaffCredits_Line035` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC1D4` | `gText_StaffCredits_Line036` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC1E4` | `gText_StaffCredits_Line037` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC1F0` | `gText_StaffCredits_Line038` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC1F8` | `gText_StaffCredits_Line039` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC204` | `gText_StaffCredits_Line040` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC210` | `gText_StaffCredits_Line044` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC21C` | `gText_StaffCredits_Line046` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC228` | `gText_StaffCredits_Line047` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC238` | `gText_StaffCredits_Line048` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC248` | `gText_StaffCredits_Line052` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC258` | `gText_StaffCredits_Line054` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC264` | `gText_StaffCredits_Line055` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC278` | `gText_StaffCredits_Line056` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC28C` | `gText_StaffCredits_Line057` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC29C` | `gText_StaffCredits_Line058` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC2B0` | `gText_StaffCredits_Line059` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC2C4` | `gText_StaffCredits_Line060` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC2D4` | `gText_StaffCredits_Line064` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC2E0` | `gText_StaffCredits_Line066` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC2F0` | `gText_StaffCredits_Line070` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC2F8` | `gText_StaffCredits_Line072` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC304` | `gText_StaffCredits_Line076` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC310` | `gText_StaffCredits_Line078` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC320` | `gText_StaffCredits_Line082` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC334` | `gText_StaffCredits_Line084` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC344` | `gText_StaffCredits_Line088` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC350` | `gText_StaffCredits_Line090` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC360` | `gText_StaffCredits_Line094` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC378` | `gText_StaffCredits_Line096` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC38C` | `gText_StaffCredits_Line097` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC39C` | `gText_StaffCredits_Line101` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC3B0` | `gText_StaffCredits_Line103` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC3C4` | `gText_StaffCredits_Line104` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC3D4` | `gText_StaffCredits_Line108` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC3E8` | `gText_StaffCredits_Line110` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC3F8` | `gText_StaffCredits_Line113` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC418` | `gText_StaffCredits_Line115` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC428` | `gText_StaffCredits_Line117` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC440` | `gText_StaffCredits_Line118` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC450` | `gText_StaffCredits_Line119` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC460` | `gText_StaffCredits_Line121` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC478` | `gText_StaffCredits_Line122` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC488` | `gText_StaffCredits_Line125` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC4A0` | `gText_StaffCredits_Line126` | `data/text/us/staff_credits.cc` | `data/text/staff_credits.o(.rodata)` |
| `0x080FC6CC` | `gText_TownMap_PlayerFarmNameSuffix` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC6D4` | `gText_TownMap_PlayerFarmDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC6E8` | `gText_TownMap_PlayerFarmLabel` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC6F0` | `gText_TownMap_MountainCottageLabel` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC704` | `gText_TownMap_SeasideCottageLabel` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC714` | `gText_TownMap_TownCottageLabel` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC724` | `gText_TownMap_TimeWindowSeasonDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC750` | `gText_TownMap_TimeWindowDateDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC774` | `gText_TownMap_TimeWindowDayDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC798` | `gText_TownMap_TimeWindowTimeDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC7C0` | `gText_TownMap_TimeWindowWeatherDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC7E8` | `gText_TownMap_TimeWindowLabel` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC7F4` | `gText_TownMap_BasilHouseLabel` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC804` | `gText_TownMap_MaryLibraryDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC82C` | `gText_TownMap_MaryLibraryHours` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC860` | `gText_TownMap_EllenHouseLabel` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC870` | `gText_TownMap_MayorHouseLabel` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC880` | `gText_TownMap_SupermarketDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC8C4` | `gText_TownMap_SupermarketHours` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC8FC` | `gText_TownMap_MineralClinicDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC928` | `gText_TownMap_MineralClinicHours` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC95C` | `gText_TownMap_ChurchDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC99C` | `gText_TownMap_ChurchHours` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC9B4` | `gText_TownMap_AjaWineryDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FC9F0` | `gText_TownMap_AjaWineryHours` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCA20` | `gText_TownMap_DukeCellarLabel` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCA30` | `gText_TownMap_DougsInnDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCA88` | `gText_TownMap_DougsInnHours` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCAB4` | `gText_TownMap_HarvestSpritesHomeDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCAF0` | `gText_TownMap_HarvestSpritesHomeHours` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCB18` | `gText_TownMap_ZackHouseDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCB4C` | `gText_TownMap_ZackHouseLabel` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCB5C` | `gText_TownMap_KaiSeasideLodgeDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCB88` | `gText_TownMap_KaiSeasideLodgeHours` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCBC0` | `gText_TownMap_SaibaraBlacksmithDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCC0C` | `gText_TownMap_SaibaraBlacksmithHours` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCC48` | `gText_TownMap_YodelFarmDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCC6C` | `gText_TownMap_YodelFarmHours` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCC9C` | `gText_TownMap_PoultryFarmDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCCBC` | `gText_TownMap_PoultryFarmHours` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCCEC` | `gText_TownMap_WoodcutterHouseDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCD2C` | `gText_TownMap_WoodcutterHouseHours` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCD64` | `gText_TownMap_LakeMineDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCD90` | `gText_TownMap_LakeMineLabel` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCD9C` | `gText_TownMap_SpringMineDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCDCC` | `gText_TownMap_SpringMineLabel` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCDD8` | `gText_TownMap_HotSpringDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCE08` | `gText_TownMap_HotSpringLabel` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCE14` | `gText_TownMap_Empty` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCE18` | `gText_TownMap_NorthMineralTownDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCE50` | `gText_TownMap_NorthMineralTownLabel` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCE6C` | `gText_TownMap_RearChurchDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCEA0` | `gText_TownMap_RearChurchLabel` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCEB0` | `gText_TownMap_RoseSquareDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCED8` | `gText_TownMap_RoseSquareLabel` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCEE4` | `gText_TownMap_MineralBeachDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCF28` | `gText_TownMap_MineralBeachLabel` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCF38` | `gText_TownMap_SouthMineralTownDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCF8C` | `gText_TownMap_SouthMineralTownLabel` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCFA8` | `gText_TownMap_ForestDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCFD4` | `gText_TownMap_ForestLabel` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FCFDC` | `gText_TownMap_MothersHillPeakDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FD014` | `gText_TownMap_MothersHillPeakLabel` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FD02C` | `gText_TownMap_MothersHillDescription` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FD070` | `gText_TownMap_MothersHillLabel` | `data/text/us/town_map.cc` | `data/text/town_map.o(.rodata)` |
| `0x080FD550` | `gText_Library_OpeningHours` | `data/text/us/library.cc` | `src/library_data.o(.rodata.library_opening_hours)` |
| `0x080FD940` | `gText_Library_Menu` | `data/text/us/library.cc` | `src/library_data.o(.rodata.library_menu)` |
| `0x080FD964` | `gText_PoultryShop_Empty` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD968` | `gText_PoultryShop_BuyChicken` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD978` | `gText_PoultryShop_SellChicken` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD9EC` | `gText_PoultryShop_PageBreak` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD9F0` | `gText_PoultryShop_StatusSick` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FD9FC` | `gText_PoultryShop_StatusUnhappy` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDA10` | `gText_PoultryShop_StatusHealthy` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDA20` | `gText_PoultryShop_StatusSpacer` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDA24` | `gText_PoultryShop_Age` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDA40` | `gText_PoultryShop_Spring` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDA48` | `gText_PoultryShop_Summer` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDA50` | `gText_PoultryShop_Autumn` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDA58` | `gText_PoultryShop_Winter` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDA60` | `gText_PoultryShop_DailySellingPrice` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDA78` | `gText_PoultryShop_Currency` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDA7C` | `gText_PoultryShop_InsufficientGold` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDAA8` | `gText_PoultryShop_FeedBinFull` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDAD4` | `gText_PoultryShop_BlankLinePair` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDADC` | `gText_PoultryShop_InventoryFull` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDB0C` | `gText_PoultryShop_CoopFull` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDB38` | `gText_PoultryShop_NameChickenPrompt` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDB6C` | `gText_PoultryShop_NoChickensToSell` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDB9C` | `gText_PoultryShop_NotInterested` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDBC4` | `gText_PoultryShop_PurchaseDeclined` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDBE8` | `gText_PoultryShop_PricePromptPrefix` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDBF8` | `gText_PoultryShop_Yes` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDBFC` | `gText_PoultryShop_No` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDC00` | `gText_PoultryShop_FeedPurchaseComplete` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDC58` | `gText_PoultryShop_PurchaseDeliveryPartial` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDCBC` | `gText_PoultryShop_MedicinePurchaseComplete` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDD04` | `gText_PoultryShop_PurchaseComplete` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDD1C` | `gText_PoultryShop_ChickenPurchaseComplete` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDD68` | `gText_PoultryShop_PurchaseMorePrompt` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDD84` | `gText_PoultryShop_ChickenSold` | `data/text/us/poultry_shop.cc` | `src/poultry_shop_data.o(.rodata)` |
| `0x080FDE40` | `gText_Supermarket_EquipmentCapacityFull` | `data/text/us/supermarket.cc` | `src/supermarket_data.o(.rodata)` |
| `0x080FDE70` | `gText_Supermarket_BlankLinePair` | `data/text/us/supermarket.cc` | `src/supermarket_data.o(.rodata)` |
| `0x080FDE78` | `gText_Supermarket_InsufficientGold` | `data/text/us/supermarket.cc` | `src/supermarket_data.o(.rodata)` |
| `0x080FDEAC` | `gText_Supermarket_ThankYou` | `data/text/us/supermarket.cc` | `src/supermarket_data.o(.rodata)` |
| `0x080FDEC4` | `gText_Supermarket_PurchaseConfirmation` | `data/text/us/supermarket.cc` | `src/supermarket_data.o(.rodata)` |
| `0x080FDEDC` | `gText_Supermarket_PurchaseMorePrompt` | `data/text/us/supermarket.cc` | `src/supermarket_data.o(.rodata)` |
| `0x080FDEF8` | `gText_Supermarket_EquipmentDelivery` | `data/text/us/supermarket.cc` | `src/supermarket_data.o(.rodata)` |
| `0x080FDF50` | `gText_Supermarket_DeliveryPartial` | `data/text/us/supermarket.cc` | `src/supermarket_data.o(.rodata)` |
| `0x080FDFE4` | `gText_Supermarket_SeedDelivery` | `data/text/us/supermarket.cc` | `src/supermarket_data.o(.rodata)` |
| `0x080FE034` | `gText_Supermarket_SeedPurchaseConfirmation` | `data/text/us/supermarket.cc` | `src/supermarket_data.o(.rodata)` |
| `0x080FE070` | `gText_Clinic_InventoryFull` | `data/text/us/clinic.cc` | `src/clinic_data.o(.rodata)` |
| `0x080FE0BC` | `gText_Clinic_BlankLinePair` | `data/text/us/clinic.cc` | `src/clinic_data.o(.rodata)` |
| `0x080FE0C4` | `gText_Clinic_InsufficientGold` | `data/text/us/clinic.cc` | `src/clinic_data.o(.rodata)` |
| `0x080FE10C` | `gText_Clinic_NoAdditionalPurchase` | `data/text/us/clinic.cc` | `src/clinic_data.o(.rodata)` |
| `0x080FE134` | `gText_Clinic_NoPurchaseRestAdvice` | `data/text/us/clinic.cc` | `src/clinic_data.o(.rodata)` |
| `0x080FE180` | `gText_Clinic_PurchaseMorePrompt` | `data/text/us/clinic.cc` | `src/clinic_data.o(.rodata)` |
| `0x080FE19C` | `gText_Clinic_Delivery` | `data/text/us/clinic.cc` | `src/clinic_data.o(.rodata)` |
| `0x080FE1E8` | `gText_Clinic_DeliveryPartial` | `data/text/us/clinic.cc` | `src/clinic_data.o(.rodata)` |
| `0x080FE238` | `gText_Clinic_PurchaseComplete` | `data/text/us/clinic.cc` | `src/clinic_data.o(.rodata)` |
| `0x080FE264` | `gText_InnShop_WaterDescription` | `data/text/us/inn_shop.cc` | `src/inn_shop_data.o(.rodata)` |
| `0x080FE284` | `gText_InnShop_BoxLunchDescription` | `data/text/us/inn_shop.cc` | `src/inn_shop_data.o(.rodata)` |
| `0x080FE2BC` | `gText_InnShop_Empty` | `data/text/us/inn_shop.cc` | `src/inn_shop_data.o(.rodata)` |
| `0x080FE2C0` | `gText_InnShop_MilkDescription` | `data/text/us/inn_shop.cc` | `src/inn_shop_data.o(.rodata)` |
| `0x080FE3D4` | `gText_InnShop_InsufficientGold` | `data/text/us/inn_shop.cc` | `src/inn_shop_data.o(.rodata)` |
| `0x080FE404` | `gText_InnShop_NoOrder` | `data/text/us/inn_shop.cc` | `src/inn_shop_data.o(.rodata)` |
| `0x080FE448` | `gText_InnShop_OrderComplete` | `data/text/us/inn_shop.cc` | `src/inn_shop_data.o(.rodata)` |
| `0x080FE4D4` | `gText_WonShop_ToolCapacityFull` | `data/text/us/won_shop.cc` | `src/won_shop_data.o(.rodata)` |
| `0x080FE50C` | `gText_WonShop_ItemCapacityFull` | `data/text/us/won_shop.cc` | `src/won_shop_data.o(.rodata)` |
| `0x080FE540` | `gText_WonShop_BlankLinePair` | `data/text/us/won_shop.cc` | `src/won_shop_data.o(.rodata)` |
| `0x080FE548` | `gText_WonShop_Delivery` | `data/text/us/won_shop.cc` | `src/won_shop_data.o(.rodata)` |
| `0x080FE5C8` | `gText_WonShop_DeliveryMultiple` | `data/text/us/won_shop.cc` | `src/won_shop_data.o(.rodata)` |
| `0x080FE63C` | `gText_WonShop_PurchaseComplete` | `data/text/us/won_shop.cc` | `src/won_shop_data.o(.rodata)` |
| `0x080FE66C` | `gText_WonShop_InsufficientGold` | `data/text/us/won_shop.cc` | `src/won_shop_data.o(.rodata)` |
| `0x080FE6B0` | `gText_WonShop_PurchaseMorePrompt` | `data/text/us/won_shop.cc` | `src/won_shop_data.o(.rodata)` |
| `0x080FE6E4` | `gText_WonShop_NoPurchase` | `data/text/us/won_shop.cc` | `src/won_shop_data.o(.rodata)` |
| `0x080FE708` | `gText_WonShop_NoAdditionalPurchase` | `data/text/us/won_shop.cc` | `src/won_shop_data.o(.rodata)` |
| `0x080FE750` | `gText_WineryShop_InventoryFull` | `data/text/us/winery_shop.cc` | `src/winery_shop_data.o(.rodata)` |
| `0x080FE7A0` | `gText_WineryShop_BlankLinePair` | `data/text/us/winery_shop.cc` | `src/winery_shop_data.o(.rodata)` |
| `0x080FE7A8` | `gText_WineryShop_InsufficientGold` | `data/text/us/winery_shop.cc` | `src/winery_shop_data.o(.rodata)` |
| `0x080FE7E0` | `gText_WineryShop_ReturnCustomer` | `data/text/us/winery_shop.cc` | `src/winery_shop_data.o(.rodata)` |
| `0x080FE800` | `gText_WineryShop_NoPurchase` | `data/text/us/winery_shop.cc` | `src/winery_shop_data.o(.rodata)` |
| `0x080FE82C` | `gText_WineryShop_Delivery` | `data/text/us/winery_shop.cc` | `src/winery_shop_data.o(.rodata)` |
| `0x080FE8AC` | `gText_WineryShop_PurchaseComplete` | `data/text/us/winery_shop.cc` | `src/winery_shop_data.o(.rodata)` |
| `0x080FE8C0` | `gText_WineryShop_PurchaseMorePrompt` | `data/text/us/winery_shop.cc` | `src/winery_shop_data.o(.rodata)` |
| `0x080FE974` | `gText_SpecialMerchantShop_RecordPlayerDescription` | `data/text/us/special_merchant_shop.cc` | `src/special_merchant_shop_data.o(.rodata)` |
| `0x080FE988` | `gText_SpecialMerchantShop_InsufficientGold` | `data/text/us/special_merchant_shop.cc` | `src/special_merchant_shop_data.o(.rodata)` |
| `0x080FE9A8` | `gText_SpecialMerchantShop_InventoryFull` | `data/text/us/special_merchant_shop.cc` | `src/special_merchant_shop_data.o(.rodata)` |
| `0x080FE9CC` | `gText_SpecialMerchantShop_BlankLinePair` | `data/text/us/special_merchant_shop.cc` | `src/special_merchant_shop_data.o(.rodata)` |
| `0x080FE9D4` | `gText_SpecialMerchantShop_PurchaseComplete` | `data/text/us/special_merchant_shop.cc` | `src/special_merchant_shop_data.o(.rodata)` |
| `0x080FEA00` | `gText_SpecialMerchantShop_RecordPlayerDelivery` | `data/text/us/special_merchant_shop.cc` | `src/special_merchant_shop_data.o(.rodata)` |
| `0x080FEA4C` | `gText_SpecialMerchantShop_PurchaseCompleteShort` | `data/text/us/special_merchant_shop.cc` | `src/special_merchant_shop_data.o(.rodata)` |
| `0x080FEA5C` | `gText_SpecialMerchantShop_ArticleDelivery` | `data/text/us/special_merchant_shop.cc` | `src/special_merchant_shop_data.o(.rodata)` |
| `0x080FEAC0` | `gText_SpecialMerchantShop_PurchaseMorePrompt` | `data/text/us/special_merchant_shop.cc` | `src/special_merchant_shop_data.o(.rodata)` |
| `0x080FEAF4` | `gText_BeachCafeShop_WaterDescription` | `data/text/us/beach_cafe_shop.cc` | `src/beach_cafe_shop_data.o(.rodata)` |
| `0x080FEB14` | `gText_BeachCafeShop_EmptyDescription` | `data/text/us/beach_cafe_shop.cc` | `src/beach_cafe_shop_data.o(.rodata)` |
| `0x080FEB18` | `gText_BeachCafeShop_SpaghettiDescription` | `data/text/us/beach_cafe_shop.cc` | `src/beach_cafe_shop_data.o(.rodata)` |
| `0x080FEB3C` | `gText_BeachCafeShop_SnowConeDescription` | `data/text/us/beach_cafe_shop.cc` | `src/beach_cafe_shop_data.o(.rodata)` |
| `0x080FEBEC` | `gText_BeachCafeShop_InsufficientGold` | `data/text/us/beach_cafe_shop.cc` | `src/beach_cafe_shop_data.o(.rodata)` |
| `0x080FEC14` | `gText_BeachCafeShop_NoOrder` | `data/text/us/beach_cafe_shop.cc` | `src/beach_cafe_shop_data.o(.rodata)` |
| `0x080FEC44` | `gText_BeachCafeShop_OrderComplete` | `data/text/us/beach_cafe_shop.cc` | `src/beach_cafe_shop_data.o(.rodata)` |
| `0x080FEC7C` | `gText_Blacksmith_ToolUpgradeMenuLabel` | `data/text/us/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FEC94` | `gText_Blacksmith_ToolUpgradeTitle` | `data/text/us/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FECA4` | `gText_Blacksmith_Empty` | `data/text/us/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FECA8` | `gText_Blacksmith_MakeMayonnaiseMaker` | `data/text/us/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FECC0` | `gText_Blacksmith_CostAdamantite` | `data/text/us/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FECF8` | `gText_Blacksmith_MakeCheeseMaker` | `data/text/us/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FED0C` | `gText_Blacksmith_MakeYarnMaker` | `data/text/us/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FED1C` | `gText_Blacksmith_MakeNecklace` | `data/text/us/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FED2C` | `gText_Blacksmith_CostOrichalc` | `data/text/us/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FED60` | `gText_Blacksmith_MakeEarrings` | `data/text/us/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FED70` | `gText_Blacksmith_MakeBracelet` | `data/text/us/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FED80` | `gText_Blacksmith_MakeBroach` | `data/text/us/blacksmith.cc` | `src/blacksmith_menu_data.o(.rodata)` |
| `0x080FEE68` | `gText_Blacksmith_InsufficientGoldAdamantite` | `data/text/us/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FEED8` | `gText_Blacksmith_InsufficientGoldOrichalc` | `data/text/us/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FEF44` | `gText_Blacksmith_MakerFiveDays` | `data/text/us/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FEF78` | `gText_Blacksmith_MakerOneDay` | `data/text/us/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FEFAC` | `gText_Blacksmith_InsufficientOreAdamantite` | `data/text/us/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FF040` | `gText_Blacksmith_InsufficientOreOrichalc` | `data/text/us/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FF0D0` | `gText_Blacksmith_SelectToolAndOre` | `data/text/us/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FF10C` | `gText_Blacksmith_InsufficientGold` | `data/text/us/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FF138` | `gText_Blacksmith_EquipmentFull` | `data/text/us/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FF15C` | `gText_Blacksmith_NeedAnythingElse` | `data/text/us/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FF178` | `gText_Blacksmith_NothingElse` | `data/text/us/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FF1A0` | `gText_Blacksmith_PurchaseComplete` | `data/text/us/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FF1B0` | `gText_Blacksmith_Delivery` | `data/text/us/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FF200` | `gText_Blacksmith_PurchaseMore` | `data/text/us/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FF228` | `gText_Blacksmith_MakeIt` | `data/text/us/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FF230` | `gText_Blacksmith_DontMakeIt` | `data/text/us/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FF240` | `gText_Blacksmith_StartWork` | `data/text/us/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FF270` | `gText_Blacksmith_CannotChangeMind` | `data/text/us/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FF29C` | `gText_Blacksmith_NoToolToUpgrade` | `data/text/us/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FF2EC` | `gText_Blacksmith_NoOreToUpgrade` | `data/text/us/blacksmith.cc` | `src/blacksmith_data.o(.rodata)` |
| `0x080FF35C` | `gText_Carpenter_Lumber` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF364` | `gText_Carpenter_GoldenLumber` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF374` | `gText_Carpenter_HouseExtension` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF384` | `gText_Carpenter_HouseExtensionFirstCost` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF3CC` | `gText_Carpenter_HouseExtensionSecondCost` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF410` | `gText_Carpenter_AddBathtub` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF420` | `gText_Carpenter_BathtubCost` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF464` | `gText_Carpenter_ExpandChickenCoop` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF474` | `gText_Carpenter_ChickenCoopCost` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF4C0` | `gText_Carpenter_ExpandBarn` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF4D0` | `gText_Carpenter_BarnCost` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF510` | `gText_Carpenter_BuildVacationHouse` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF520` | `gText_Carpenter_VacationHouseCost` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF568` | `gText_Carpenter_RemodelWindow` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF578` | `gText_Carpenter_Rebuild` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF584` | `gText_Carpenter_RemodelDoghouse` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF598` | `gText_Carpenter_RemodelMailbox` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF5A4` | `gText_Carpenter_SquareWindowWithShutters` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF5B8` | `gText_Carpenter_WindowCost` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF5DC` | `gText_Carpenter_SquareWindowWithoutShutters` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF5F0` | `gText_Carpenter_RoundWindow` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF600` | `gText_Carpenter_RedDoghouse` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF610` | `gText_Carpenter_DoghouseCost` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF634` | `gText_Carpenter_BlueDoghouse` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF644` | `gText_Carpenter_StrangeDoghouse` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF658` | `gText_Carpenter_RedMailbox` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF664` | `gText_Carpenter_MailboxCost` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF688` | `gText_Carpenter_BlueMailbox` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF698` | `gText_Carpenter_StrangeMailbox` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF838` | `gText_Carpenter_InitialPageBreak` | `data/text/common/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF83C` | `gText_Carpenter_RebuildRequirements` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF858` | `gText_Carpenter_InsufficientGold` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF878` | `gText_Carpenter_LumberBinFull` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF8A4` | `gText_Carpenter_LumberHeader` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF8B0` | `gText_Carpenter_EquipmentFull` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF8DC` | `gText_Carpenter_GoldenLumberHeader` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF8F0` | `gText_Carpenter_CannotAcceptAnotherJob` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF944` | `gText_Carpenter_InsufficientLumber` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF968` | `gText_Carpenter_ThreeDayConfirmation` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF998` | `gText_Carpenter_NeedAnythingElse` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF9B8` | `gText_Carpenter_AreYouSureNow` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF9CC` | `gText_Carpenter_SameCurrentShape` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FF9F4` | `gText_Carpenter_StoreLumber` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FFA24` | `gText_Carpenter_DeliveryAll` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FFA70` | `gText_Carpenter_DeliverySome` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FFABC` | `gText_Carpenter_PurchaseComplete` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FFACC` | `gText_Carpenter_Build` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FFAD4` | `gText_Carpenter_DontBuild` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FFAE0` | `gText_Carpenter_Upgrade` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FFAE8` | `gText_Carpenter_DontUpgrade` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FFAF8` | `gText_Carpenter_StartUpgradeTomorrow` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FFB2C` | `gText_Carpenter_ConfirmUpgrade` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FFB3C` | `gText_Carpenter_NeedAnythingMore` | `data/text/us/carpenter.cc` | `src/carpenter_data.o(.rodata)` |
| `0x080FFB60` | `gText_LivestockShop_Empty` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFB64` | `gText_LivestockShop_BuyCow` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFB6C` | `gText_LivestockShop_BuySheep` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFB78` | `gText_LivestockShop_SellCow` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFB84` | `gText_LivestockShop_SellSheep` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFC6C` | `gText_LivestockShop_PageBreak` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFC70` | `gText_LivestockShop_StatusSick` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFC80` | `gText_LivestockShop_StatusUnhappy` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFC90` | `gText_LivestockShop_StatusHealthy` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFCA0` | `gText_LivestockShop_StatusSpacer` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFCA4` | `gText_LivestockShop_Age` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFCC0` | `gText_LivestockShop_Spring` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFCC8` | `gText_LivestockShop_Summer` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFCD0` | `gText_LivestockShop_Autumn` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFCD8` | `gText_LivestockShop_Winter` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFCE0` | `gText_LivestockShop_DailySellingPrice` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFCF4` | `gText_LivestockShop_Currency` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFCF8` | `gText_LivestockShop_SecondaryStatusSick` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFD08` | `gText_LivestockShop_SecondaryAge` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFD24` | `gText_LivestockShop_SecondaryDailySellingPrice` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFD3C` | `gText_LivestockShop_InsufficientGold` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFD5C` | `gText_LivestockShop_FeedBinFull` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFD90` | `gText_LivestockShop_BlankLinePair` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFD98` | `gText_LivestockShop_InventoryFull` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFDBC` | `gText_LivestockShop_BarnFull` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFDD4` | `gText_LivestockShop_NameAnimalPrompt` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFDF8` | `gText_LivestockShop_NoCowsToSell` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFE24` | `gText_LivestockShop_NoSheepToSell` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFE50` | `gText_LivestockShop_ComeAgain` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFE88` | `gText_LivestockShop_PurchaseConfirmation` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFE9C` | `gText_LivestockShop_PricePromptPrefix` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFEA8` | `gText_LivestockShop_PricePromptSuffix` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFEAC` | `gText_LivestockShop_Yes` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFEB0` | `gText_LivestockShop_No` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFEB4` | `gText_LivestockShop_FeedPurchaseComplete` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFEEC` | `gText_LivestockShop_PurchaseDeliveryPartial` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFF38` | `gText_LivestockShop_PurchaseDeliveryAll` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFF84` | `gText_LivestockShop_PurchaseComplete` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFF94` | `gText_LivestockShop_AnimalPurchaseComplete` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFFC4` | `gText_LivestockShop_PurchaseMorePrompt` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFFE8` | `gText_LivestockShop_PurchaseDeclinedPrefix` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x080FFFFC` | `gText_LivestockShop_AnimalDelivery` | `data/text/us/livestock_shop.cc` | `src/livestock_shop.o(.rodata)` |
| `0x08100030` | `gText_Fridge_EmptyDescription` | `data/text/us/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x08100034` | `gText_Fridge_WrappedGiftWarning` | `data/text/us/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x08100084` | `gText_Fridge_Yes` | `data/text/us/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x08100088` | `gText_Fridge_No` | `data/text/us/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x0810008C` | `gText_Fridge_Items` | `data/text/us/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x08100094` | `gText_Fridge_Title` | `data/text/us/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x081000A8` | `gText_HomeStorage_ConfirmationYes` | `data/text/us/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x081000AC` | `gText_HomeStorage_ConfirmationNo` | `data/text/us/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x081000B0` | `gText_HomeStorage_EmptyDescription` | `data/text/us/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x081000B4` | `gText_HomeStorage_CategoryTools` | `data/text/us/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x081000BC` | `gText_HomeStorage_CategoryItems` | `data/text/us/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x081000D0` | `gText_Shelf_EmptyDescription` | `data/text/us/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x081000D4` | `gText_Shelf_WrappedGiftWarning` | `data/text/us/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x08100120` | `gText_Shelf_Yes` | `data/text/us/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x08100124` | `gText_Shelf_No` | `data/text/us/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x08100128` | `gText_Shelf_Items` | `data/text/us/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x08100130` | `gText_Shelf_Title` | `data/text/us/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x08100144` | `gText_ToolChest_EmptyDescription` | `data/text/us/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x08100148` | `gText_ToolChest_HeaderTools` | `data/text/us/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x08100150` | `gText_ToolChest_Title` | `data/text/us/home_storage.cc` | `data/text/home_storage.o(.rodata)` |
| `0x08100168` | `gText_BlacksmithUpgrade_EmptyDescription` | `data/text/us/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x0810016C` | `gText_BlacksmithUpgrade_Tools` | `data/text/us/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x08100174` | `gText_BlacksmithUpgrade_Items` | `data/text/us/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x0810017C` | `gText_BlacksmithUpgrade_SelectTool` | `data/text/us/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x081001A4` | `gText_BlacksmithUpgrade_CursedTool` | `data/text/us/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x081001D4` | `gText_BlacksmithUpgrade_SelectOre` | `data/text/us/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x08100208` | `gText_BlacksmithUpgrade_CannotUpgradeTool` | `data/text/us/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x08100224` | `gText_BlacksmithUpgrade_InvalidUpgradeOre` | `data/text/us/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x0810026C` | `gText_BlacksmithUpgrade_CannotChangeMind` | `data/text/us/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x0810029C` | `gText_BlacksmithUpgrade_InsufficientExperience` | `data/text/us/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x081002D8` | `gText_BlacksmithUpgrade_AlreadyUpgradedWithOre` | `data/text/us/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x08100314` | `gText_BlacksmithUpgrade_DowngradeConfirmation` | `data/text/us/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x08100350` | `gText_BlacksmithUpgrade_WorkOrderPrefix` | `data/text/us/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x08100360` | `gText_BlacksmithUpgrade_WorkOrderGoldSuffix` | `data/text/us/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x08100368` | `gText_BlacksmithUpgrade_WorkOrderDaysPrefix` | `data/text/us/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x0810037C` | `gText_BlacksmithUpgrade_WorkOrderDaysSuffix` | `data/text/us/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x08100388` | `gText_BlacksmithUpgrade_WorkOrderQuestion` | `data/text/us/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x08100398` | `gText_BlacksmithUpgrade_InsufficientGoldPageBreak` | `data/text/us/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x0810039C` | `gText_BlacksmithUpgrade_InsufficientGold` | `data/text/us/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x081003DC` | `gText_BlacksmithUpgrade_ResultYes` | `data/text/us/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x081003E0` | `gText_BlacksmithUpgrade_ResultNo` | `data/text/us/blacksmith.cc` | `src/blacksmith_upgrade_data.o(.rodata)` |
| `0x081003F0` | `gText_GiftWrap_EmptyDescription` | `data/text/us/gift_wrap.cc` | `data/text/gift_wrap.o(.rodata)` |
| `0x081003F4` | `gText_GiftWrap_CannotWrap` | `data/text/us/gift_wrap.cc` | `data/text/gift_wrap.o(.rodata)` |
| `0x08100420` | `gText_GiftWrap_Confirm` | `data/text/us/gift_wrap.cc` | `data/text/gift_wrap.o(.rodata)` |
| `0x08100430` | `gText_GiftWrap_Yes` | `data/text/us/gift_wrap.cc` | `data/text/gift_wrap.o(.rodata)` |
| `0x08100434` | `gText_GiftWrap_No` | `data/text/us/gift_wrap.cc` | `data/text/gift_wrap.o(.rodata)` |
| `0x08100438` | `gText_GiftWrap_DogWarning` | `data/text/us/gift_wrap.cc` | `data/text/gift_wrap.o(.rodata)` |
| `0x08100450` | `gText_GiftWrap_Tools` | `data/text/us/gift_wrap.cc` | `data/text/gift_wrap.o(.rodata)` |
| `0x08100458` | `gText_GiftWrap_Items` | `data/text/us/gift_wrap.cc` | `data/text/gift_wrap.o(.rodata)` |
| `0x08100460` | `gText_GiftWrap_Recommendation` | `data/text/us/gift_wrap.cc` | `data/text/gift_wrap.o(.rodata)` |
| `0x08100490` | `gText_GiftWrap_Complete` | `data/text/us/gift_wrap.cc` | `data/text/gift_wrap.o(.rodata)` |
| `0x081004BC` | `gText_GiftWrap_SelectItem` | `data/text/us/gift_wrap.cc` | `data/text/gift_wrap.o(.rodata)` |
| `0x081004E0` | `gText_LinkCommunication_Waiting` | `data/text/us/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x08100524` | `gText_LinkCommunication_SendingGameData` | `data/text/us/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x08100540` | `gText_LinkCommunication_TestingConnection` | `data/text/us/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x08100558` | `gText_LinkCommunication_CannotResendPreviousData` | `data/text/us/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x08100588` | `gText_LinkCommunication_ProceedQuestion` | `data/text/us/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x0810058C` | `gText_LinkCommunication_Yes` | `data/text/us/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x08100590` | `gText_LinkCommunication_No` | `data/text/us/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x08100594` | `gText_LinkCommunication_WaitingForOtherPlayer` | `data/text/us/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x081005D8` | `gText_LinkCommunication_NowSendingData` | `data/text/us/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x081005EC` | `gText_LinkCommunication_DataExchangeFailed` | `data/text/us/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x08100610` | `gText_LinkCommunication_QuitCommunication` | `data/text/us/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x08100638` | `gText_LinkCommunication_OtherPlayerCanceled` | `data/text/us/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x08100678` | `gText_LinkCommunication_IncompatibleGameData` | `data/text/us/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x081006C4` | `gText_LinkCommunication_ExchangeRestriction` | `data/text/us/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x0810073C` | `gText_LinkCommunication_ActionQuestion` | `data/text/us/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x08100758` | `gText_LinkCommunication_Declined` | `data/text/us/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x08100790` | `gText_LinkCommunication_Complete` | `data/text/us/link_communication.cc` | `src/link_communication_data.o(.rodata)` |
| `0x08100AC0` | `gText_Cooking_Recipe_PageBreak` | `data/text/common/cooking_recipe_inventory.cc` | `src/cooking_recipe_inventory_data.o(.rodata.cooking_recipe_inventory_page_break)` |
| `0x08100AD2` | `gText_StaminaRecoveryStatus` | `data/text/us/recovery_status.cc` | `data/text/recovery_status.o(.rodata)` |
| `0x08100BD7` | `gText_FatigueRecoveryStatus` | `data/text/us/recovery_status.cc` | `data/text/recovery_status.o(.rodata)` |
| `0x08100DE4` | `gText_Cooking_SeasoningSet` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100DF4` | `gText_Cooking_CompleteUtensilSelection` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100E28` | `gText_Cooking_WrappedGiftDescription` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100E34` | `gText_Cooking_FollowRecipe` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100E48` | `gText_Cooking_ImproviseRecipe` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100E5C` | `gText_Cooking_MakeAnotherRecipe` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100E74` | `gText_Cooking_NotEnoughIngredients` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100E90` | `gText_Cooking_ImproviseAnyway` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100EA4` | `gText_Cooking_UseTheseIngredients` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100EBC` | `gText_Cooking_RestartIngredients` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100ED8` | `gText_Cooking_RestartUtensils` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100EF0` | `gText_Cooking_ResultFailure` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100F04` | `gText_Cooking_ResultSuccessNewRecipe` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100F30` | `gText_Cooking_ResultSuccess` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100F44` | `gText_Cooking_ResultComparison` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100F78` | `gText_Cooking_Recipe_MakeThis` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100F90` | `gText_Cooking_Recipe_LeaveAsIs` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100FA4` | `gText_Cooking_Recipe_ViewCurrent` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100FBC` | `gText_Cooking_Recipe_Rewrite` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100FCC` | `gText_Cooking_Recipe_ViewNew` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08100FE0` | `gText_Cooking_Recipe_IngredientsRequired` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08101008` | `gText_Cooking_Recipe_ListTitle` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08101020` | `gText_Cooking_Recipe_Utensils` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x0810102C` | `gText_Cooking_Recipe_Ingredients` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08101038` | `gText_Cooking_Recipe_UseIngredients` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08101044` | `gText_Cooking_Recipe_Empty` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08101048` | `gText_Cooking_Recipe_StorageHeader` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08101059` | `gText_Cooking_Recipe_SelectionNames` | `data/text/us/cooking.cc` | `data/text/cooking.o(.rodata)` |
| `0x08103658` | `gText_Animal_Unnamed` | `data/text/common/animal.cc` | `src/animal.o(.rodata.animal_unnamed)` |
| `0x08103788` | `gText_FishingRecord_PirateFortune` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103798` | `gText_FishingRecord_FossilOfFish` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081037A8` | `gText_FishingRecord_PowerBerry` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081037B4` | `gText_FishingRecord_MessageBottle` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081037C4` | `gText_FishingRecord_EmptyCan` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081037D0` | `gText_FishingRecord_Branch` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081037D8` | `gText_FishingRecord_FishBones` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081037E4` | `gText_FishingRecord_Boots` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081037EC` | `gText_FishingRecord_RockTrout` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081037F8` | `gText_FishingRecord_Scad` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103800` | `gText_FishingRecord_Fatminnow` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x0810380C` | `gText_FishingRecord_CherrySalmon` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x0810381C` | `gText_FishingRecord_Pigfish` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103824` | `gText_FishingRecord_Sardine` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x0810382C` | `gText_FishingRecord_MountainTrout` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x0810383C` | `gText_FishingRecord_Whitefish` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103848` | `gText_FishingRecord_Eel` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x0810384C` | `gText_FishingRecord_Bitterling` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103858` | `gText_FishingRecord_Bonito` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103860` | `gText_FishingRecord_Fluke` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103868` | `gText_FishingRecord_Filefish` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103874` | `gText_FishingRecord_GoldenCarp` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103880` | `gText_FishingRecord_SilverCarp22` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x0810388C` | `gText_FishingRecord_KelpBass` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103898` | `gText_FishingRecord_Bighead` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081038A0` | `gText_FishingRecord_Salmon` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081038A8` | `gText_FishingRecord_Mackerel` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081038B4` | `gText_FishingRecord_Needlefish` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081038C0` | `gText_FishingRecord_SpanishMackerel` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081038D0` | `gText_FishingRecord_SauryPike` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081038DC` | `gText_FishingRecord_Dorado` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081038E4` | `gText_FishingRecord_RedSnapper` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081038F0` | `gText_FishingRecord_Cod` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081038F4` | `gText_FishingRecord_Roach` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081038FC` | `gText_FishingRecord_BrownHakeling` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x0810390C` | `gText_FishingRecord_RainbowTrout` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x0810391C` | `gText_FishingRecord_Herring` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103924` | `gText_FishingRecord_Sandfish` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103930` | `gText_FishingRecord_Flounder` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x0810393C` | `gText_FishingRecord_Blowfish` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103948` | `gText_FishingRecord_BlackBass` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103954` | `gText_FishingRecord_Yellowtail` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103960` | `gText_FishingRecord_Bluegill` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x0810396C` | `gText_FishingRecord_CrucianCarp` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x0810397C` | `gText_FishingRecord_Greenling` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103988` | `gText_FishingRecord_Tuna` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103990` | `gText_FishingRecord_OceanSunfish` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081039A0` | `gText_FishingRecord_Lionfish` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081039AC` | `gText_FishingRecord_Rockfish` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081039B8` | `gText_FishingRecord_LargeSalmon` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081039C4` | `gText_FishingRecord_Snakehead` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081039D0` | `gText_FishingRecord_LakeSmelt` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081039DC` | `gText_FishingRecord_JapaneseHuchen` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081039E8` | `gText_FishingRecord_Monkfish` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081039F4` | `gText_FishingRecord_Catfish` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x081039FC` | `gText_FishingRecord_Carp` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103A04` | `gText_FishingRecord_Coelacanth` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08103A10` | `gText_FishingRecord_Squid` | `data/text/us/fishing_results.cc` | `data/text/fishing_results.o(.rodata)` |
| `0x08104108` | `gText_CharacterName_Empty` | 未在 `data/text` 源中直接命名；请以宿主对象核对 | `src/character_names_data.o(.rodata.character_names_empty)` |
| `0x08104128` | `gText_CharacterName_Lillia` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08104130` | `gText_CharacterName_Rick` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08104138` | `gText_CharacterName_Popuri` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08104140` | `gText_CharacterName_Barley` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08104148` | `gText_CharacterName_May` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x0810414C` | `gText_CharacterName_Saibara` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08104154` | `gText_CharacterName_Gray` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x0810415C` | `gText_CharacterName_Duke` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08104164` | `gText_CharacterName_Manna` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x0810416C` | `gText_CharacterName_Basil` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08104174` | `gText_CharacterName_Anna` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x0810417C` | `gText_CharacterName_Mary` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08104184` | `gText_CharacterName_Thomas` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x0810418C` | `gText_CharacterName_Harris` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08104194` | `gText_CharacterName_Ellen` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x0810419C` | `gText_CharacterName_Stu` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x081041A0` | `gText_CharacterName_Jeff` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x081041A8` | `gText_CharacterName_Sasha` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x081041B0` | `gText_CharacterName_Karen` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x081041B8` | `gText_CharacterName_Doctor` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x081041C0` | `gText_CharacterName_Elli` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x081041C8` | `gText_CharacterName_Carter` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x081041D0` | `gText_CharacterName_Cliff` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x081041D8` | `gText_CharacterName_Doug` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x081041E0` | `gText_CharacterName_Ann` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x081041E4` | `gText_CharacterName_Kai` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x081041E8` | `gText_CharacterName_Gotz` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x081041F0` | `gText_CharacterName_Zack` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x081041F8` | `gText_CharacterName_Won` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x081041FC` | `gText_CharacterName_Gourmet` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08104204` | `gText_CharacterName_HarvestGoddess` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08104210` | `gText_CharacterName_Kappa` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08104218` | `gText_CharacterName_Van` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x0810421C` | `gText_CharacterName_LouOrRuby` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08104220` | `gText_CharacterName_Staid` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08104228` | `gText_CharacterName_Nappy` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08104230` | `gText_CharacterName_Bold` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08104238` | `gText_CharacterName_Chef` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08104240` | `gText_CharacterName_Aqua` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08104248` | `gText_CharacterName_Hoggy` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08104250` | `gText_CharacterName_Timid` | `data/text/us/character_names.cc` | `data/text/character_names.o(.rodata)` |
| `0x08104938` | `gText_Calendar_DynamicSeasonNames` | `data/text/us/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x0810497C` | `gText_Calendar_Festival_NewYearFestival` | `data/text/us/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x081049C4` | `gText_Calendar_Festival_SpringThanksgiving` | `data/text/us/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x081049F8` | `gText_Calendar_Festival_SpringHorseRace` | `data/text/us/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104A40` | `gText_Calendar_Festival_CookingFestival` | `data/text/us/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104A84` | `gText_Calendar_Festival_BeachDay` | `data/text/us/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104AC4` | `gText_Calendar_Festival_ChickenFestival` | `data/text/us/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104B08` | `gText_Calendar_Festival_CowFestival` | `data/text/us/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104B4C` | `gText_Calendar_Festival_FireworksFestival` | `data/text/us/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104B94` | `gText_Calendar_Festival_MusicFestival` | `data/text/us/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104BD4` | `gText_Calendar_Festival_HarvestFestival` | `data/text/us/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104C18` | `gText_Calendar_Festival_FullMoonFestival` | `data/text/us/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104C54` | `gText_Calendar_Festival_FallHorseRace` | `data/text/us/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104C98` | `gText_Calendar_Festival_SheepFestival` | `data/text/us/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104CDC` | `gText_Calendar_Festival_PumpkinFestival` | `data/text/us/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104D04` | `gText_Calendar_Festival_WinterThanksgiving` | `data/text/us/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104D28` | `gText_Calendar_Festival_StarryNightFestival` | `data/text/us/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104D58` | `gText_Calendar_Festival_YearEndGathering` | `data/text/us/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104D98` | `gText_Calendar_Festival_Marriage` | `data/text/us/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104DB8` | `gText_Calendar_Festival_WeddingAnniversary` | `data/text/us/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104DDC` | `gText_Calendar_Festival_NoPlans` | `data/text/us/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104DF8` | `gText_Calendar_FallbackNone` | `data/text/us/calendar_events.cc` | `data/text/calendar_events.o(.rodata)` |
| `0x08104E0C` | `gText_Possessive_Horse` | `data/text/us/possessive_labels.cc` | `data/text/possessive_labels.o(.rodata)` |
| `0x08104E14` | `gText_Possessive_Cow` | `data/text/us/possessive_labels.cc` | `data/text/possessive_labels.o(.rodata)` |
| `0x08104E1C` | `gText_Possessive_Sheep` | `data/text/us/possessive_labels.cc` | `data/text/possessive_labels.o(.rodata)` |
| `0x08104E24` | `gText_Possessive_Chicken` | `data/text/us/possessive_labels.cc` | `data/text/possessive_labels.o(.rodata)` |
| `0x08104E30` | `gText_Possessive_Child` | `data/text/us/possessive_labels.cc` | `data/text/possessive_labels.o(.rodata)` |
| `0x08104E38` | `gText_Possessive_Player` | `data/text/us/possessive_labels.cc` | `data/text/possessive_labels.o(.rodata)` |
| `0x08104E4C` | `gText_RandomItem_NotAvailable` | `data/text/us/random_item.cc` | `data/text/random_item.o(.rodata)` |
| `0x081074E4` | `gText_FieldRenderFallbackNone` | 未在 `data/text` 源中直接命名；请以宿主对象核对 | `src/field_data.o(.rodata.field_render_runtime_strings)` |
| `0x08107568` | `gText_080B0708DefaultGlyph` | 未在 `data/text` 源中直接命名；请以宿主对象核对 | `src/field_data.o(.rodata.unk_080B0708_default_glyph)` |
| `0x081075B0` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_ExplanationQuestion` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x081075CC` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_Yes` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x081075D0` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_No` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x081075D4` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_Introduction` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x08107608` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_FeedingInstructions` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x081076C8` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_ChickenBehaviorInstructions` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x081077A4` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_WatchInstructions` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x081077E4` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_UnderstandQuestion` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x081077F8` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_UnderstandYes` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x08107808` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_UnderstandAgain` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x08107818` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_Start` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x0810782C` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_ScorePrefix` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x08107834` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_ScoreResultPrefix` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x08107844` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_ScoreResultSuffix` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x08107850` | `gText_HarvestSpriteMiniGame_AnimalHusbandry_ScoreSummary` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames.o(.rodata)` |
| `0x081078BC` | `gText_HarvestSpriteMiniGameAnimalHusbandryEmpty` | 未在 `data/text` 源中直接命名；请以宿主对象核对 | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_animal_husbandry_runtime_empty)` |
| `0x081078BD` | `gText_ChickenFestival_ContestantNames` | `data/text/us/chicken_festival.cc` | `data/text/chicken_festival.o(.rodata)` |
| `0x081079C4` | `gText_HarvestSpriteMiniGame_ChickenFestival_SemiFinalsAnnouncement` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` |
| `0x081079E0` | `gText_HarvestSpriteMiniGame_ChickenFestival_FinalRoundAnnouncement` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` |
| `0x08107A30` | `gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationQuestion` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` |
| `0x08107A4C` | `gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationNo` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` |
| `0x08107A58` | `gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationYes` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` |
| `0x08107A68` | `gText_HarvestSpriteMiniGame_ChickenFestival_RoundOneStart` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` |
| `0x08107A80` | `gText_HarvestSpriteMiniGame_ChickenFestival_SemiFinalsStart` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` |
| `0x08107A9C` | `gText_HarvestSpriteMiniGame_ChickenFestival_FinalsStart` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` |
| `0x08107AB4` | `gText_HarvestSpriteMiniGame_ChickenFestival_Start` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` |
| `0x08107ABC` | `gText_HarvestSpriteMiniGame_ChickenFestival_Stop` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` |
| `0x08107AC4` | `gText_HarvestSpriteMiniGame_ChickenFestival_WinnerSuffix` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_opening.o(.rodata)` |
| `0x08107B00` | `gText_HarvestSpriteMiniGame_ChickenFestival_UnderstandQuestion` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_instructions.o(.rodata)` |
| `0x08107B14` | `gText_HarvestSpriteMiniGame_ChickenFestival_UnderstandYes` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_instructions.o(.rodata)` |
| `0x08107B1C` | `gText_HarvestSpriteMiniGame_ChickenFestival_UnderstandAgain` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_instructions.o(.rodata)` |
| `0x08107B28` | `gText_HarvestSpriteMiniGame_ChickenFestival_Introduction` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_instructions.o(.rodata)` |
| `0x08107B5C` | `gText_HarvestSpriteMiniGame_ChickenFestival_Rules` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_instructions.o(.rodata)` |
| `0x08107C18` | `gText_HarvestSpriteMiniGame_ChickenFestival_Encouragement` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_instructions.o(.rodata)` |
| `0x08107CB0` | `gText_HarvestSpriteMiniGame_ChickenFestival_CautionAtRingEdge` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_instructions.o(.rodata)` |
| `0x08107CE0` | `gText_HarvestSpriteMiniGame_ChickenFestival_CautionLeavingRing` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_chicken_festival_instructions.o(.rodata)` |
| `0x08107DB8` | `gText_080BE728DigitZero` | 未在 `data/text` 源中直接命名；请以宿主对象核对 | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_chicken_festival_post_text_data)` |
| `0x08107DD8` | `gText_HarvestSpriteMiniGame_Harvest_ExplanationQuestion` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` |
| `0x08107DF4` | `gText_HarvestSpriteMiniGame_Harvest_Yes` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` |
| `0x08107DF8` | `gText_HarvestSpriteMiniGame_Harvest_No` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` |
| `0x08107DFC` | `gText_HarvestSpriteMiniGame_Harvest_Introduction` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` |
| `0x08107E24` | `gText_HarvestSpriteMiniGame_Harvest_Instructions` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` |
| `0x08107E58` | `gText_HarvestSpriteMiniGame_Harvest_FatigueWarning` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` |
| `0x08107EC8` | `gText_HarvestSpriteMiniGame_Harvest_RestInstructions` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` |
| `0x08107F18` | `gText_HarvestSpriteMiniGame_Harvest_UnderstandQuestion` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` |
| `0x08107F2C` | `gText_HarvestSpriteMiniGame_Harvest_UnderstandYes` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` |
| `0x08107F3C` | `gText_HarvestSpriteMiniGame_Harvest_UnderstandAgain` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` |
| `0x08107F4C` | `gText_HarvestSpriteMiniGame_Harvest_Start` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_instructions.o(.rodata)` |
| `0x08107F60` | `gText_HarvestSpriteMiniGame_Harvest_ScorePrefix` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_results.o(.rodata)` |
| `0x08107F68` | `gText_HarvestSpriteMiniGame_Harvest_ScoreResultPrefix` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_results.o(.rodata)` |
| `0x08107F78` | `gText_HarvestSpriteMiniGame_Harvest_ScoreResultSuffix` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_results.o(.rodata)` |
| `0x08107F84` | `gText_HarvestSpriteMiniGame_Harvest_ScoreSummary` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_harvest_results.o(.rodata)` |
| `0x08108000` | `gText_080C38E4DigitZero` | 未在 `data/text` 源中直接命名；请以宿主对象核对 | `src/harvest_sprite.o(.rodata.harvest_sprite_minigames_harvest_results_post_values)` |
| `0x08108020` | `gText_HarvestSpriteMiniGame_Watering_ExplanationQuestion` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` |
| `0x0810803C` | `gText_HarvestSpriteMiniGame_Watering_Yes` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` |
| `0x08108040` | `gText_HarvestSpriteMiniGame_Watering_No` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` |
| `0x08108044` | `gText_HarvestSpriteMiniGame_Watering_Introduction` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` |
| `0x08108070` | `gText_HarvestSpriteMiniGame_Watering_Instructions` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` |
| `0x081080EC` | `gText_HarvestSpriteMiniGame_Watering_SuccessInstructions` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` |
| `0x08108168` | `gText_HarvestSpriteMiniGame_Watering_MistakeWarning` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` |
| `0x081081D8` | `gText_HarvestSpriteMiniGame_Watering_UnderstandQuestion` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` |
| `0x081081E4` | `gText_HarvestSpriteMiniGame_Watering_UnderstandYes` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` |
| `0x081081F4` | `gText_HarvestSpriteMiniGame_Watering_UnderstandAgain` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` |
| `0x08108204` | `gText_HarvestSpriteMiniGame_Watering_Start` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_instructions.o(.rodata)` |
| `0x08108218` | `gText_HarvestSpriteMiniGame_Watering_ScorePrefix` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_results.o(.rodata)` |
| `0x08108220` | `gText_HarvestSpriteMiniGame_Watering_ScoreResultPrefix` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_results.o(.rodata)` |
| `0x08108230` | `gText_HarvestSpriteMiniGame_Watering_ScoreResultSuffix` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_results.o(.rodata)` |
| `0x0810823C` | `gText_HarvestSpriteMiniGame_Watering_ScoreSummary` | `data/text/us/harvest_sprite_minigames.cc` | `data/text/harvest_sprite_minigames_watering_results.o(.rodata)` |
| `0x0811780C` | `gText_ShopCommon_GoldUnit` | `data/text/us/status_ui.cc` | `data/text/shop_common.o(.rodata)` |
| `0x08117810` | `gText_ShopCommon_QuantitySuffix` | `data/text/us/status_ui.cc` | `data/text/shop_common.o(.rodata)` |
| `0x08117818` | `gText_ShopCommon_OwnedQuantityLabel` | `data/text/us/status_ui.cc` | `data/text/shop_common.o(.rodata)` |
| `0x081179AC` | `gText_ToolStatus_GemOfTruth` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x081179BC` | `gText_ToolStatus_EnergyLabel` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x081179C4` | `gText_ToolStatus_ValueSeparator` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x081179C8` | `gText_ToolStatus_EnergyFatigueLineBreak` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x081179CC` | `gText_ToolStatus_FatigueLabel` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x081179D8` | `gText_ToolStatus_FatigueMaximum` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x081179E0` | `gText_ToolStatus_PedometerLabel` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x081179F0` | `gText_ToolStatus_PedometerStepsSuffix` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x081179F8` | `gText_ToolStatus_DescriptionQuotePrefix` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x081179FC` | `gText_ToolStatus_RemainingSquaresSuffix` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08117A0C` | `gText_AnimalStatus_Dog` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08117A14` | `gText_AnimalStatus_Puppy` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08117A1C` | `gText_AnimalStatus_Chicken` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08117A28` | `gText_AnimalStatus_Chick` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08117A30` | `gText_AnimalStatus_Sick` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08117A38` | `gText_AnimalStatus_Unhappy` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08117A44` | `gText_AnimalStatus_Healthy` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08117A50` | `gText_ItemStatus_BasketName` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08117A5C` | `gText_ItemStatus_BasketDescription` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08117A78` | `gText_ItemStatus_BasketHoldingPrefix` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08117A84` | `gText_ItemStatus_BasketHoldingSuffix` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08117A8C` | `gText_ItemStatus_WrappedAsPresent` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08117AA8` | `gText_ItemDiscard_Confirm` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08117AC0` | `gText_ItemDiscard_CannotDiscard` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |
| `0x08117AE0` | `gText_ItemDiscard_Cursed` | `data/text/us/status_ui.cc` | `data/text/status_ui.o(.rodata)` |

## 维护源覆盖检查

- 维护源总数：`379`。已由物理表或文本索引反查到：`379`。未映射：`0`。

本文件不把 Mary 独立管理的剧情脚本区当作普通文本源；脚本区域仍由 Mary 的脚本表和编译流程维护。
