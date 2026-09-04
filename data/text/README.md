# Text source layout

Regional text belongs under this directory by domain:

    data/text/us/<domain>.text
    data/text/jp/<domain>.text

The project-root `charmap.txt` is shared by every regional text domain.  Its
Shift-JIS entries include ASCII, so regional text does not need separate
character maps. It is intentionally outside `data/text` so script and
non-script preprocessing use one explicit project-level encoding contract.

Each source file uses the text-preprocessor .string form documented in
tools/textproc.  Generated assembly keeps stable gText_* symbols.  C/C++
tables then reference those symbols.

Game scripts are deliberately outside this directory and remain independently
managed by Mary.  Do not add a script build or link step here.

Do not embed translated text directly in item .def rows.  A .def row describes
structure and IDs; its name and description fields must become gText_* symbol
references during migration.
