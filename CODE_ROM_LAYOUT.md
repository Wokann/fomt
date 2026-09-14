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

核验：四个区域均以 WSL 构建并与各自基准 ROM 的 SHA-1 完全一致后，才将模块标记为完成。
