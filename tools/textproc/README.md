# FOMT 文本与布局预处理

这里的宿主端 C++ 工具分为两个职责明确的程序：

1. `fomt-text` 负责文本层。它通过项目内的 FOMT charmap 把 UTF-8 游戏文本
   转为 ROM 字节；它还会把 Reference Guide 等专用文本格式生成标准 C/C++ 的
   文本对象、行指针表和目录表。
2. `fomt-preproc` 负责通用布局层。它接收已转换的标准 C/C++ 源和 `agbcc`/
   `agbcp` 输出的汇编，处理通用段格式，并完成原先由 `align_sections.sh`
   做的可执行段收尾对齐。显式 `ALIGN(n)` 的识别及数据/函数段切换时的对齐
   由编译器处理，不再通过匹配字符数组声明或删除相邻汇编行来修补。

职责划分：

| 位置 | 应处理的内容 | 不应承担的内容 |
| --- | --- | --- |
| `agbcc/cp` | C/C++ 类型与对象身份、ABI、声明属性、目标寻址及指令输出的通用正确性 | 按游戏符号、原始地址、目标字节或特定函数排列凑匹配 |
| 文本工具与预处理器 | 明确输入格式的转码、专用文本格式生成及通用段格式处理 | 猜测变量含义、替换指针目标、改写指令序列或删除疑似重复对象 |
| 游戏源码 | 真实类型、构造析构、内联可见性、对象归属、定义顺序及必要对齐 | 为配合工具猜测而添加虚假对象、无用调用或地址补偿 |

对象增删、改名、文本长度变化不应使工具选择错误的修补目标。目标 SHA-1
用于发现差异，不能作为改写编译输出的规则。现有普通数据段格式转换仍需
按这一标准继续审查；不因没有游戏名或原址常量就直接认定所有处理均已完备。

两者都不依赖 Mary 的工作树。charmap 格式沿用 Mary 的 `HEX=TEXT` 语义，但
版本化存放在本仓库中。

用宿主 C++ 编译器构建两项工具：

    make -C tools/textproc

An optional data-layout pass accepts an explicitly supplied reservation plan:

    tools/textproc/fomt-preproc reserve PLAN OWNER ASSEMBLY

Each non-comment row has three whitespace-separated fields: the object owner,
the actual data symbol, and its input-section capacity in bytes. For example:

    src/example.o gText_Example 32
    src/example.o gExampleTable 16

Only rows matching OWNER are applied. A named object must identify exactly
one `.rodata` input section; `@plain` can identify an unnamed, non-unique
`.rodata` section. Missing or ambiguous reservations fail. The pass appends
zero-filled `.org` capacity directives to selected input sections; GAS rejects
an object that no longer fits. It preserves section names, object `.size`,
instructions and symbolic pointer relocations. It neither determines safe
capacities nor moves objects, so the caller must supply a verified plan.

This is a separate, opt-in command. `fomt-preproc asm` and native builds keep
their existing behavior without a reservation pass.

生成游戏资源前可校验版本化 map：

    tools/textproc/fomt-text validate charmap.txt JP

`fomt-text` 可编码单条文本、解码既有字节，或处理文本源：

    tools/textproc/fomt-text encode CHARMAP REGION INPUT OUTPUT
    tools/textproc/fomt-text decode CHARMAP REGION INPUT OUTPUT
    tools/textproc/fomt-text source CHARMAP REGION INPUT OUTPUT
    tools/textproc/fomt-text cpp CHARMAP REGION INPUT OUTPUT

指南汇总与页面可使用条件指令选择源码：

    tools/textproc/fomt-text guide-collection CHARMAP REGION MANIFEST OUTPUT [-D NAME ...]

区域宏由 REGION 提供，其他无值开关通过重复的 `-D NAME` 传入。
汇总和页面使用同一套 `#if`、`#ifdef`、`#ifndef`、`#elif`、
`#else`、`#endif` 选择规则，然后生成常规 C++。这不是完整的 C 宏展开器。
Makefile 将配置中的 BUGFIX 同时传给指南生成器和 Mary，关闭时保留原版页面。

To recover the editable, visible row source for a regional staff-credit table:

    tools/textproc/fomt-text staff-credits-decode CHARMAP REGION BASEROM OUTPUT

That decode command is an optional ROM comparison/export operation. The normal
staff-credit build reads only `text/<region>/staff_credits.cc`: first
appearance sets physical text-field order, identical encoded rows share a
pointer, and each field contains its C terminator and four-byte zero padding.
The JP/US/EU/DE retail text pools and pointer tables were checked against this
rule; no baseline ROM is read during compilation.

`source` 是普通 C/C++ 词法转换：它可处理 `.c`、`.cc`、`.h`、`.hh` 中的
字符串。正常构建会先运行常规 C 预处理器，因此被包含的头文件内容会与其所属
翻译单元一同经过转换。除了游戏字符串外，源代码会原样保留；尤其是 `ALIGN(n)`、
`SECTION(...)`、结构体初始化、指针表和内联 `asm(...)` 均不由文本工具改写。

`cpp` 用于受约束的普通 C++ 文本定义模块：

    #include "item.hh"

    char const gText_Item_Tool_IronSickle_Name[] =
        "Iron Sickle";

    char const gText_Item_Tool_IronSickle_Description[] =
        "Iron Sickle\r\n"
        "Good for cutting grass.";

A text-related module may define a `char const * const` ROM pointer that refers
to one of the text arrays.  Keep that pointer in the same themed source file,
at its real ROM position after the text it references:

    char const gText_ItemStatus_WrappedAsPresent[] =
        "\r\nwrapped as a present.";

    char const * const gItemStatusWrappedAsPresentTextRef =
        gText_ItemStatus_WrappedAsPresent;

在所有 C/C++ 对象上，Makefile 使用固定流程：常规 CPP → `fomt-text source`
→ `agbcc`/`agbcp` → `fomt-preproc asm` → 汇编器。真实对象及指针重定位由
编译器生成；旧 agbcp 对只读数组身份的错误折叠，在 FoMT 同级 `agbcc`
的 `cp` 分支中按数组类型修正。安装脚本只构建、安装该源码，不再应用补丁。

`fomt-preproc` 只进行通用汇编格式兼容和对象/段对齐处理：不按变量名前缀、
函数名、ROM 地址或字符串内容判断归属，不修改字符串指针，也不补造编译器
未输出的数组。匿名字面量与具名对象即使内容相同，也保留各自的标签和引用；
未引用的库字面量不再被当成可合并副本删除。

此变更需要重新安装工具链。完整 ROM 的匹配状态以项目进度记录为准；
不能使用旧编译器配合已移除猜测修补的新预处理器。

`fomt-preproc` 不重排、替换或补写可执行指令，也不为匹配函数插入代码或
额外的机器码常量。可执行节只执行通用的段末零对齐，实际对象地址和指针
关系由编译器与链接器生成。不匹配的函数应继续维护为显式
汇编，而不是由这个工具改写编译器输出。

`-fhex-asm` 的栈调整立即数直接由编译器正确输出 `#0x...`。
预处理器不再改写该指令的语法或数值。

普通 C/C++ 的 `ALIGN(n)` 始终可用于文本、结构体数组和指针表。例如：

    SomeEntry const gEntries[] ALIGN(4) = {
        { gText_Example },
    };

该属性由编译器生成对应的对象对齐；`fomt-preproc` 保留它，而不会把它替换成
手写汇编或文本专用规则。唯一的旧编译器补正是：对于未分节的一维 `char const`
字符串，若源码明确写了 `ALIGN(1)`，预处理器会移除 `agbcp` 错误附加的对象前
对齐，使该字符串真正从下一字节开始。此规则按声明形状工作，不依赖标签、地址或
函数名；未标注和带 `SECTION` 的遗留对象不会改变。

少数 UI 路径逐个读取 `u8` 或 `u16` 字符码，而不是读取普通 `char` 文本。此类对象仍按
普通数组的形式维护，直接书写区域文本：

    u16 const gExampleGlyphCodes[] = {
        "0123枚",
        0,
    };

`fomt-text source` 会按当前区域的 charmap 把 `u8`/`u16` 数组花括号中的字符串变成
一或双字节的游戏码值。文本工具转换后才是可编译的普通 C/C++ 初始化器；数组末尾的
`0` 是原生表的显式结束码，不是对齐填充。

若原生代码按固定元素数量读取、而原 ROM 没有结束码，只省略数组末尾的 `0`：

    u16 const gExampleGlyphSequence[] = {
        "0123枚",
    };

这不是普通字符串，必须以原始调用方的固定读取长度为依据。

Keep a page-break control in the literal that owns it.  For example, write
`"...{Press}\p"` and start the following text literal on the next source line.
Use a standalone `"\p"` only when the original byte sequence itself begins
with a page break.

For a fixed-stride table that callers index directly, use ordinary C++ array
dimensions and one string per row. The encoded text plus its terminator must
fit the declared row width. When it is shorter, normal C++ array initialization
supplies the remaining zero bytes:

    char const gText_Calendar_SeasonNames[4][7] SECTION(".rodata.calendar.season") ALIGN(1) = {
        "Spring",
        "Summer",
        "Fall  ",
        "Winter"
    };

Most fixed rows should contain only their displayed text. If an original row
has meaningful bytes after its FOMT `00` terminator, write that terminator as
`\x00` and then write the following mapped text or raw bytes. The preprocessor
preserves that explicit zero; the fixed C++ array dimension still supplies any
remaining trailing zero-fill. This is for verified field contents, not normal
line/page controls.

For one fixed zero-filled C string field, use a single array width. The
encoded text plus its terminator must fit the width; `agbcp` supplies the
remaining zero bytes exactly as a normal C++ array initializer would:

    char const gText_NotAvailable[8] SECTION(".rodata.not_available") =
        "N/A ";

Adjacent quoted C++ literals follow Mary’s readable layout for displayed line
breaks. The generated output declares each symbol as a normal escaped C++
string, encodes text with the selected map, and appends the FOMT 00 terminator.
Object layout is therefore produced by `agbcp`, rather than by handwritten
assembler alignment directives. Named controls such as \n, \r, \p, and
{Player} are data-driven: their spelling and bytes come only from the selected
charmap. Use \xNN for an intentional unmapped raw byte.

Migration target:

1. Put every text body under its regional `text/jp`, `text/us`,
   `text/eu`, or `text/de` directory by owning C/C++ data category.
   Duplicate byte-identical content into every applicable regional directory;
   do not create a `text/common` source directory.  For multiple physical
   fragments of one owner, number all fragments from `_1` in physical ROM
   include order; use the bare owner name only when there is one fragment.
2. Keep item, menu, and other C/C++ data tables structural: they point to
   gText_* symbols instead of embedding text literals in their initializers.
   If source entries share an identical original pointer, point both fields at
   the same text symbol rather than emitting a duplicate string or alias.
3. Do not use this tool for game scripts.  Mary independently owns script
   decoding and encoding; this tool only supports non-script text consumed by
   normal C/C++ data structures.
