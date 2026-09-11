# FOMT 文本与布局预处理

这里的宿主端 C++ 工具分为两个职责明确的程序：

1. `fomt-text` 负责文本层。它通过项目内的 FOMT charmap 把 UTF-8 游戏文本
   转为 ROM 字节；它还会把 Reference Guide 等专用文本格式生成标准 C/C++ 的
   文本对象、行指针表和目录表。
2. `fomt-preproc` 负责通用布局层。它接收已转换的标准 C/C++ 源和 `agbcc`/
   `agbcp` 输出的汇编，修复旧编译器已验证的匿名字符串副本、修正显式
   `ALIGN(1)` 普通字符串被旧编译器额外提升到四字节边界的情况，并完成原先由
   `align_sections.sh` 做的可执行段收尾对齐。它不区分文本、结构体数组或指针表。

两者都不依赖 Mary 的工作树。charmap 格式沿用 Mary 的 `HEX=TEXT` 语义，但
版本化存放在本仓库中。

用宿主 C++ 编译器构建并测试两项工具：

    make -C tools/textproc test

生成游戏资源前可校验版本化 map：

    tools/textproc/fomt-text validate charmap.txt JP

`fomt-text` 可编码单条文本、解码既有字节，或处理文本源：

    tools/textproc/fomt-text encode CHARMAP REGION INPUT OUTPUT
    tools/textproc/fomt-text decode CHARMAP REGION INPUT OUTPUT
    tools/textproc/fomt-text source CHARMAP REGION INPUT OUTPUT
    tools/textproc/fomt-text cpp CHARMAP REGION INPUT OUTPUT

To recover the editable, visible row source for a regional staff-credit table:

    tools/textproc/fomt-text staff-credits-decode CHARMAP REGION BASEROM OUTPUT

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
→ `agbcc`/`agbcp` → `fomt-preproc asm` → 汇编器。后一步会检查普通
`char const * const` 指针、平面指针数组，以及“源码字段数与汇编 `.word` 数完全
一致”的普通结构体聚合数组；只有匿名 `.LC` 字符串与已命名目标逐字节一致时，才
替换为真实重定位并移除副本。字节/半字数组不会被这一规则猜测或改写。这样一个主题
仍可保留在一个普通 `.rodata` 输入对象中，源文件顺序就是 ROM 顺序。

普通 C/C++ 的 `ALIGN(n)` 始终可用于文本、结构体数组和指针表。例如：

    SomeEntry const gEntries[] ALIGN(4) = {
        { gText_Example },
    };

该属性由编译器生成对应的对象对齐；`fomt-preproc` 保留它，而不会把它替换成
手写汇编或文本专用规则。唯一的旧编译器补正是：对于未分节的一维 `char const`
字符串，若源码明确写了 `ALIGN(1)`，预处理器会移除 `agbcp` 错误附加的对象前
对齐，使该字符串真正从下一字节开始。此规则按声明形状工作，不依赖标签、地址或
函数名；未标注和带 `SECTION` 的遗留对象不会改变。

少数 UI 路径逐个读取 `u16` 字符码，而不是读取普通 `char` 文本。此类对象的
维护源使用显式的非标准标记 `FOMT_GLYPH_TEXT(...)`，以免被误认为普通 C++：

    u16 const gExampleGlyphCodes[] = FOMT_GLYPH_TEXT("0123枚");

`fomt-text source` 会按当前区域的 charmap 把每个字符变成一个一或双字节的
`u16` 码值，并自动追加 `0x0000` 结束码。该标记必须经过文本工具转换后才是
可编译的普通 C/C++ 初始化器；不要手写结束码或对齐填充。

若原生代码按固定元素数量读取、而原 ROM 没有结束码，则使用
`FOMT_GLYPH_SEQUENCE(...)`。它使用相同的 UTF-8 到半字码转换，但绝不追加
`0x0000`；这不是普通字符串，必须以原始调用方的固定读取长度为依据。

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

1. Put regional text bodies under data/text/us and data/text/jp by owning
   C/C++ data category. Put byte-identical fallback text under
   data/text/common.
2. Keep item, menu, and other C/C++ data tables structural: they point to
   gText_* symbols instead of embedding text literals in their initializers.
   If source entries share an identical original pointer, point both fields at
   the same text symbol rather than emitting a duplicate string or alias.
3. Do not use this tool for game scripts.  Mary independently owns script
   decoding and encoding; this tool only supports non-script text consumed by
   normal C/C++ data structures.
