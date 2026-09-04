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

Import the reviewed Mary-compatible JP map once with the companion PowerShell
script.  The copy is checksum-verified and becomes a normal project asset;
the ROM build never needs the sibling Mary checkout afterward.

    powershell -ExecutionPolicy Bypass -File tools/textproc/scripts/import_mary_charmap.ps1 \
      -MaryCharmap ../mary/charmap_jp.txt

Validate an imported map before generating any game asset:

    tools/textproc/build/fomt-text validate charmap_jp.txt

Encode one text payload, decode an existing byte range, or generate assembly:

    tools/textproc/build/fomt-text encode CHARMAP INPUT OUTPUT
    tools/textproc/build/fomt-text decode CHARMAP INPUT OUTPUT
    tools/textproc/build/fomt-text asm CHARMAP INPUT OUTPUT

The asm input uses an intentionally small, conventional assembly-shaped
format:

    gText_Item_IronSickle_Name:
        .string "Iron Sickle"

    gText_Item_IronSickle_Description:
        .string "Iron Sickle\r\nGood for cutting grass."

The generated output declares each symbol, encodes text with the selected
map, and appends the FOMT 00 terminator.  Named controls such as \n, \r, \p,
and {Player} are data-driven: their spelling and bytes come only from the
selected charmap.  Use \xNN for an intentional unmapped raw byte.

Migration target:

1. Put text bodies under data/text/us and data/text/jp by domain.
2. Keep item, menu, and other C/C++ data tables structural: they point to
   gText_* symbols instead of embedding text literals in .def rows.
3. Do not use this tool for game scripts.  Mary independently owns script
   decoding and encoding; this tool only supports non-script text consumed by
   normal C/C++ data structures.
