# Text source layout

Regional text belongs under this directory by its owning data structure:

    data/text/us/ and data/text/jp/
        tool.cc, food.cc, article.cc
        game_state.cc, help_menu.cc, animal_memorial.cc
        menu.cc, fixed_labels.cc, ui_error.cc
        new_game_menu.cc, new_game_status.cc, new_game_help.cc
        new_game_save.cc, new_game_identity.cc
        new_game_name_entry.cc, new_game_name_entry_ui.cc
        fishing_results.cc
        character_names.cc
        reference_guide/
            harvest_sprite_minigames.cc
            festival_hints.cc

    data/text/common/
        fallback.cc       item fallbacks compiled with src/item.cc
        menu.cc           runtime strings compiled with src/menu_data.cc
        ui_error.cc       fallback/runtime strings compiled with src/ui_error.cc
        script_engine.cc  non-script error strings compiled with src/script_engine.cc

Keep categories separate even when their entries are linked beside one another:
each text source corresponds to the C/C++ structure that owns its text
pointers. A source-owned text fragment is included at its exact physical point
inside the owning `src/<module>.cc`; it remains under `data/text` and is listed
in `TEXT_FRAGMENT_SOURCES` so it does not produce a second object.
Reference Guide sources are grouped under each region's `reference_guide/`
directory, with one source per verified guide category.  Their small pointer
tables and declarations are centralized in `src/reference_guide.cc` and
`include/reference_guide.hh`.

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
zero-initializes any remaining bytes in the fixed row. Normal text objects do
not need per-string section attributes: their owning source module and linker
order preserve the ROM layout.

When a verified fixed field contains nonzero bytes after an embedded FOMT
terminator, express that boundary as `\x00` followed by ordinary mapped text
or raw `\xNN` bytes. `textproc` retains the explicit terminator while C++ still
zero-initializes any remaining field capacity.

`common/fallback.cc` is included directly by `src/item.cc` because its small
item fallback strings are byte-identical in both regions.

`common/ui_error.cc` is included at its owning module's physical ROM
position. `common/script_engine_*.cc` are linked as ordinary physical text
fragments. The non-display fixed SRAM signature is kept with its owning
`src/sram_proxy_1.c` save-verifier module.

Game scripts are deliberately outside this directory and remain independently
managed by Mary.  Do not add a script build or link step here.

Do not embed item-text literals in C/C++ info-table initializers.  Every
name/description pointer field must reference a gText_* symbol defined by the
appropriate regional text source.
