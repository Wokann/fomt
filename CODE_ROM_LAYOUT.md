# 代码 ROM 物理布局

本文件记录已从原始代码 `incbin` 提升为实际 ARM/Thumb 汇编的连续模块。地址以各地区基准 ROM 的物理地址为准；一个模块即使在原始布局中被已编译的 C/C++ 输入节穿插，也仍由同一个源汇编文件维护。

## `asm/code_actor_0809BFE8.s`

JP 原先有 19 段原始 Thumb 代码和 9 个 `.thumb_set` 偏移别名。现已逐段发射真实指令、跳表和数据池；9 个对外入口直接在其真实物理位置定义，不保留 `.set`、`.thumb_set`、代码 `incbin` 或伪造的加偏移匹配。US、EU、DE 原先已由同一模块的标准汇编分支发射，因此四版在该模块均为可读汇编层级。

| JP 物理范围 | 输入节 | 对外入口（如有） |
| --- | --- | --- |
| `0x0809BB98`–`0x0809BC63` | `.text.code_actor_0809C160` | — |
| `0x0809BD50`–`0x0809BD63` | `.text.code_actor_0809C318` | — |
| `0x0809BDC4`–`0x0809BDF3` | `.text.code_actor_0809C38C` | — |
| `0x0809BDF4`–`0x0809BE17` | `.text.code_actor_0809C3BC` | — |
| `0x0809BE18`–`0x0809BE57` | `.text.code_actor_0809C3E0` | — |
| `0x0809BE58`–`0x0809BE7B` | `.text.code_actor_0809C420` | — |
| `0x0809BE7C`–`0x0809BEAB` | `.text.code_actor_0809C444` | — |
| `0x0809BEAC`–`0x0809BEEB` | `.text.code_actor_0809C474` | — |
| `0x0809BEEC`–`0x0809BF1B` | `.text.code_actor_0809C4B4` | — |
| `0x0809BF1C`–`0x0809BF23` | `.text.code_actor_0809C4E4` | — |
| `0x0809BF24`–`0x0809BFEB` | `.text.code_actor_0809C4EC` | `func_0809C510` |
| `0x0809C07C`–`0x0809C0CB` | `.text.code_actor_0809C644` | — |
| `0x0809C0F4`–`0x0809C7AF` | `.text.code_actor_0809C6BC` | `func_0809C6BC` |
| `0x0809C868`–`0x0809C8B3` | `.text.code_actor_0809CE30` | — |
| `0x0809C8C4`–`0x0809CE4F` | `.text.code_actor_0809CE8C` | `func_0809CE8C`、`func_0809CF34` |
| `0x0809CEA8`–`0x0809D20F` | `.text.code_actor_0809D470` | `func_0809D470`、`func_0809D79C` |
| `0x0809D320`–`0x0809D963` | `.text.code_actor_0809D8E8` | `func_0809D8E8`、`func_0809D9B4`、`func_0809DA00` |
| `0x0809DB50`–`0x0809DBAB` | `.text.code_actor_0809E118` | — |
| `0x0809DBEC`–`0x0809DD0B` | `.text.code_actor_0809E1B4` | — |

## `asm/code_entities_080320DC.s`

该模块原有的 JP 分支含 9 段原始 Thumb 代码和多个 `.thumb_set` 入口别名；西方共用分支也含 226 处原始 `.byte` 指令及 14 个入口别名。现已按四个基准 ROM 的实际指令边界分别发射 JP、US、EU、DE 分支：所有公开入口均在各自真实位置直接定义，未能可靠命名的内部入口只使用同节局部标签。四个分支均不保留代码 `incbin`、原始指令 `.byte`、`.set` 或 `.thumb_set`；区域间真实的调用/资源布局差异以各自分支的直接符号表达。`0x08034A70` 的 JP `gUnk_080F221C` 指针仍保持在两段代码之间。

`func_080A05E8 + 0x3B4` 是对尚未提升的 `code_809E804` JP 代码内局部位置的已验证真实跳转，不是区域伪匹配；待该宿主模块完成时会改为其直接局部标签。US、EU、DE 构造器段的 `__ewram_bss_end + 0x170` 是经过 ROM 核验的 EWRAM 布局常量，不是 ROM 地址或区域偏移匹配。

| JP 物理范围 | 输入节 | 备注 |
| --- | --- | --- |
| `0x080321C0`–`0x0803224B` | `.text` | `func_0803242C` |
| `0x08032250`–`0x08032693` | `.text.entity_ui_default_no_action_after` | 默认动作与区域分类前逻辑 |
| `0x080326C8`–`0x08032793` | `.text.entity_ui_region_classification_after` | 区域分类逻辑 |
| `0x080327C4`–`0x080336A7` | `.text.entity_ui_constructor_after` | 构造、访问器与任务逻辑 |
| `0x080336BC`–`0x080338B7` | `.text.entity_ui_harvest_sprite_task_experience_after` | 精灵任务经验逻辑 |
| `0x08033918`–`0x08033FDB` | `.text.entity_ui_unknown_flag_after` | 原始名称未知的标志处理逻辑 |
| `0x08033FF4`–`0x0803498F` | `.text.entity_ui_animation_lookup_after` | 动画查找与位置逻辑 |
| `0x080349F8`–`0x08034A6F` | `.text.entity_ui_resource_setup_after` | 资源设置前段 |
| `0x08034A70`–`0x08034A73` | 同上 | `gUnk_080F221C` 指针 |
| `0x08034A74`–`0x08034A7F` | 同上 | 资源设置尾部返回路径 |

| 输入节 | JP 物理范围 | US 物理范围 | EU 物理范围 | DE 物理范围 |
| --- | --- | --- | --- | --- |
| `.text` | `0x080321C0`–`0x0803224B` | `0x0803242C`–`0x080324B7` | `0x08032440`–`0x080324CB` | `0x08032340`–`0x080323CB` |
| `.text.entity_ui_default_no_action_after` | `0x08032250`–`0x08032693` | `0x080324BC`–`0x080328FF` | `0x080324D0`–`0x08032913` | `0x080323D0`–`0x08032813` |
| `.text.entity_ui_region_classification_after` | `0x080326C8`–`0x08032793` | `0x08032934`–`0x080329FF` | `0x08032948`–`0x08032A13` | `0x08032848`–`0x08032913` |
| `.text.entity_ui_constructor_after` | `0x080327C4`–`0x080336A7` | `0x08032A30`–`0x08033913` | `0x08032A44`–`0x08033927` | `0x08032944`–`0x08033827` |
| `.text.entity_ui_harvest_sprite_task_experience_after` | `0x080336BC`–`0x080338B7` | `0x08033928`–`0x08033B23` | `0x0803393C`–`0x08033B37` | `0x0803383C`–`0x08033A37` |
| `.text.entity_ui_unknown_flag_after` | `0x08033918`–`0x08033FDB` | `0x08033B84`–`0x08034247` | `0x08033B98`–`0x0803425B` | `0x08033A98`–`0x0803415B` |
| `.text.entity_ui_animation_lookup_after` | `0x08033FF4`–`0x0803498F` | `0x08034260`–`0x08034BFB` | `0x08034274`–`0x08034C0F` | `0x08034174`–`0x08034B0F` |
| `.text.entity_ui_resource_setup_after` | `0x080349F8`–`0x08034A7F` | `0x08034C64`–`0x08034CEB` | `0x08034C78`–`0x08034CFF` | `0x08034B78`–`0x08034BFF` |

核验：四个区域均以 WSL 构建并与各自基准 ROM 的 SHA-1 完全一致后，才将模块标记为完成。

## `asm/code_entities_08034CEC.s`

该实体 UI 后续模块原先在 JP 分支保留 65 段代码 `incbin`，西方分支保留 89 处原始指令 `.byte`；现已按 JP、US、EU、DE 的各自 ROM 指令边界完整发射为 Thumb 汇编。所有四区分支均不再含代码 `incbin`、原始指令 `.byte`、`.set` 或 `.thumb_set`。对未具备可靠外部名称的内部函数，仅保留同节局部标签；literal pool、跳表、vtable 地址和对齐填充仍作为数据保留。

审计额外识别出旧源中未命名的小型函数入口，特别是西方模块末尾的访问器与状态更新函数。它们已作为真实反汇编入口处理，而非以 `.4byte` 伪装。JP 跨模块的五个调用目标也已在 `asm/code_entities.s` 的原始块内直接标注为 `func_0801FE14`、`func_0801FE58`、`func_0801FF04`、`func_080201F4`、`func_080212B0`；调用方不再使用 `code_entities_jp_raw_start + 偏移`。

| 区域 | 输入节 | 物理范围 |
| --- | --- | --- |
| JP | `.text` | `0x08035114`–`0x0803A517` |
| US | `.text` | `0x08035380`–`0x0803A8A3` |
| EU | `.text` | `0x08035394`–`0x0803A8B7` |
| DE | `.text` | `0x08035294`–`0x0803A7B7` |

核验：四个区域按顺序使用 WSL 构建，并与各自基准 ROM 的 SHA-1 完全一致。

## `asm/code_0803A8A4.s`

该控制代码模块原先在 JP 分支保留连续的代码 `incbin`，US、EU、DE 分支则混有原始指令 `.byte`。现已为四个基准 ROM 分别发射真实 Thumb 指令、literal pool、跳表与原始对齐填充。所有区域分支均不再含代码 `incbin`、原始指令 `.byte`、`.set` 或 `.thumb_set`；跨段的 `func_0803B660` 调用已在 JP 的真实入口直接定义，不使用别名或函数加偏移伪匹配。

仍无法可靠命名的 ROM 资源地址只保留为 literal pool 数据，不作为代码入口伪造符号；其所属资产容器继续按原始资源块维护。四版之间的代码差异由各自的 `REGION_JP`、`REGION_US`、`REGION_EU`、`REGION_DE` 分支直接表达。

| 输入节 | JP 物理范围 | US 物理范围 | EU 物理范围 | DE 物理范围 |
| --- | --- | --- | --- | --- |
| `.text` | `0x0803A518`–`0x0803BB77` | `0x0803A8A4`–`0x0803BDE3` | `0x0803A8B8`–`0x0803BDF7` | `0x0803A7B8`–`0x0803BCF7` |
| `.text.code_0803BDFC` | `0x0803BB90`–`0x0803BC2F` | `0x0803BDFC`–`0x0803BE9B` | `0x0803BE10`–`0x0803BEAF` | `0x0803BD10`–`0x0803BDAF` |
| `.text.code_0803BF14` | `0x0803BCA8`–`0x0803C2AB` | `0x0803BF14`–`0x0803C517` | `0x0803BF28`–`0x0803C52B` | `0x0803BE28`–`0x0803C42B` |
| `.text.code_0803C54C` | `0x0803C2E0`–`0x0803E07F` | `0x0803C54C`–`0x0803E40B` | `0x0803C560`–`0x0803E41F` | `0x0803C460`–`0x0803E303` |
| `.text.code_0803E448` | `0x0803E0BC`–`0x0803EB07` | `0x0803E448`–`0x0803EE93` | `0x0803E45C`–`0x0803EEA7` | `0x0803E340`–`0x0803ED8B` |

核验：四个区域以 WSL 依次完整构建，并与各自基准 ROM 的 SHA-1 完全一致。五个输入节的对象输出大小也与上述 LDS 边界逐一一致。

## `asm/code_0803EE94.s`（进行中）

该汇编汇总模块的首个物理输入节从一个 228 项的脚本 UI 跳转表开始；它不是 Thumb 函数首指令，故不会把该表错误反汇编为代码。已独立完成其中边界明确的 `func_08045584`：JP 的 `0x080451F8`–`0x0804524B` 现在由真实 Thumb 指令、literal pool 和局部标签发射，和既有 US、EU、DE 汇编处于相同表示层级。

该函数调用的 `func_080A0878` 也已在 `asm/code_809E804.s` 的 JP 原始代码块内按其真实物理入口直接定义；调用点不再保留 `func_080A05E8 + 0x290` 形式的别名/偏移伪引用。其余 `code_0803EE94` 子段仍在逐一审计，不将本条目误记为整个汇总模块已完成。

| 入口 | JP 物理范围 | US 物理范围 | EU 物理范围 | DE 物理范围 |
| --- | --- | --- | --- | --- |
| `func_08045584` | `0x080451F8`–`0x0804524B` | `0x08045584`–`0x080455D7` | `0x08045598`–`0x080455EB` | `0x0804547C`–`0x080454CF` |

核验：JP、US、EU、DE 均以 WSL 完整构建，并分别通过各自基准 ROM 的 SHA-1 校验。
