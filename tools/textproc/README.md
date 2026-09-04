# FOMT text preprocessor

This C++ host-side tool converts UTF-8 source text through an explicit FOMT
charmap.  Its map format follows the same `HEX=TEXT` semantics used by Mary,
but it lives in this repository so the multi-language branch does not depend
on a sibling checkout at build time.

The tool deliberately has no dependency on the ROM build.  Text sources and
their generated assembly are reviewed as normal project files; the main
Makefile continues to compile C and C++ normally.

Build and test it with a host C++ compiler:

    make -C tools/textproc test

Validate the versioned project map before generating any game asset:

    tools/textproc/fomt-text validate charmap.txt

Encode one text payload, decode an existing byte range, or generate assembly:

    tools/textproc/fomt-text encode CHARMAP INPUT OUTPUT
    tools/textproc/fomt-text decode CHARMAP INPUT OUTPUT
    tools/textproc/fomt-text asm CHARMAP INPUT OUTPUT

The asm command consumes a constrained, ordinary C++ text-definition form:

    #include "item_text.hh"

    char const gText_Item_Tool_IronSickle_Name[] =
        "Iron Sickle";

    char const gText_Item_Tool_IronSickle_Description[] =
        "Iron Sickle\r\n"
        "Good for cutting grass.";

Adjacent quoted C++ literals follow Mary’s readable layout for displayed line
breaks. The generated output declares each symbol, encodes text with the
selected map, appends the FOMT 00 terminator, and always emits `.align 2, 0`
after the object. Named controls such as \n, \r, \p,
and {Player} are data-driven: their spelling and bytes come only from the
selected charmap.  Use \xNN for an intentional unmapped raw byte.

Migration target:

1. Put text bodies under data/text/us and data/text/jp by owning C/C++ data
   category.
2. Keep item, menu, and other C/C++ data tables structural: they point to
   gText_* symbols instead of embedding text literals in their initializers.
   If source entries share an identical original pointer, point both fields at
   the same text symbol rather than emitting a duplicate string or alias.
3. Do not use this tool for game scripts.  Mary independently owns script
   decoding and encoding; this tool only supports non-script text consumed by
   normal C/C++ data structures.
