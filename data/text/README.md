# Text source layout

Regional text belongs under this directory by its owning data structure:

    data/text/us/tool.cc
    data/text/us/food.cc
    data/text/us/article.cc
    data/text/us/calendar.cc
    data/text/us/help_menu.cc
    data/text/us/animal_memorial.cc
    data/text/us/load_error.cc
    data/text/us/menu.cc
    data/text/jp/tool.cc
    data/text/jp/food.cc
    data/text/jp/article.cc
    data/text/jp/calendar.cc
    data/text/jp/help_menu.cc
    data/text/jp/animal_memorial.cc
    data/text/jp/load_error.cc
    data/text/jp/menu.cc
    data/text/common/fallback.cc

Keep categories separate even when their entries are linked beside one another:
each source corresponds to the C/C++ structure that owns its text pointers.

The project-root `charmap.txt` is shared by every regional text category.  Its
Shift-JIS entries include ASCII, so regional text does not need separate
character maps. It is intentionally outside `data/text` so script and
non-script preprocessing use one explicit project-level encoding contract.

Each regional source file includes `item_text.hh` and uses ordinary C++
`char const` definitions. The host-side text preprocessor converts their UTF-8
string literals with `charmap.txt` into generated escaped C++ source, which
`agbcp` compiles into the stable `gText_*` symbols. C/C++ tables then reference
those symbols directly. When two table entries intentionally share one ROM
string, both table fields point to the same canonical symbol; do not create a
second text object or an assembler alias.

`calendar.cc` demonstrates fixed-row text arrays: the C++ dimensions are the
actual ROM row strides used by the callers. The text preprocessor verifies
every encoded row, including its terminator, has exactly that width. Its
section attributes only preserve the pre-existing ROM placement; the source
still contains ordinary UTF-8 C++ strings and no handwritten assembler.

`common/fallback.cc` is included directly by `src/item.cc` because its small
fallback strings are byte-identical in both regions. It does not need regional
selection or generated source files.

Game scripts are deliberately outside this directory and remain independently
managed by Mary.  Do not add a script build or link step here.

Do not embed item-text literals in C/C++ info-table initializers.  Every
name/description pointer field must reference a gText_* symbol defined by the
appropriate regional text source.
