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
