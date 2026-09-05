# Text source layout

Regional text belongs under this directory by its owning data structure:

    data/text/us/ and data/text/jp/
        tool.cc, food.cc, article.cc
        calendar.cc, help_menu.cc, animal_memorial.cc
        load_error.cc, menu.cc, not_available.cc, fixed_labels.cc
        new_game_menu.cc, new_game_status.cc, new_game_help.cc
        new_game_save.cc, new_game_identity.cc
        new_game_name_entry.cc, new_game_name_entry_ui.cc

    data/text/common/
        fallback.cc       item fallbacks compiled with src/item.cc
        ui_error.cc       shared UI fallback text
        sram_signature.cc shared fixed-width SRAM header

Keep categories separate even when their entries are linked beside one another:
each source corresponds to the C/C++ structure that owns its text pointers.

The project-root `charmap.txt` is shared by every regional text category.  Its
Shift-JIS entries include ASCII, so regional text does not need separate
character maps. It is intentionally outside `data/text` so script and
non-script preprocessing use one explicit project-level encoding contract.

Each source includes its owning declaration header and uses ordinary C++
`char const` definitions. The host-side text preprocessor converts their UTF-8
string literals with `charmap.txt` into generated escaped C++ source, which
`agbcp` compiles into stable symbols. C/C++ tables then reference those symbols
directly. When two table entries intentionally share one ROM string, both
fields point to the canonical symbol; use a regional preprocessor name mapping
when two source-level semantic names are needed, rather than creating a second
text object or an assembler alias.

`calendar.cc` demonstrates fixed-row text arrays: the C++ dimensions are the
actual ROM row strides used by the callers. The text preprocessor verifies
every encoded row, including its terminator, fits that width; ordinary C++
zero-initializes any remaining bytes in the fixed row. Its section attributes
only preserve the pre-existing ROM placement; the source still contains
ordinary UTF-8 C++ strings and no handwritten assembler.

When a verified fixed field contains nonzero bytes after an embedded FOMT
terminator, express that boundary as `\x00` followed by ordinary mapped text
or raw `\xNN` bytes. `textproc` retains the explicit terminator while C++ still
zero-initializes any remaining field capacity.

`common/fallback.cc` is included directly by `src/item.cc` because its small
item fallback strings are byte-identical in both regions. `common/ui_error.cc`
and `common/sram_signature.cc` are generated through the text preprocessor and
linked into both regional ROMs. The latter is not display text: its explicit
32-byte array is the persisted SRAM signature used by the save verifier.

Game scripts are deliberately outside this directory and remain independently
managed by Mary.  Do not add a script build or link step here.

Do not embed item-text literals in C/C++ info-table initializers.  Every
name/description pointer field must reference a gText_* symbol defined by the
appropriate regional text source.
