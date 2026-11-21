/* Report FoMT decompilation evidence from an existing build. */
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
    ROM_BASE = 0x08000000, ROM_HEADER = 0xc0,
    SHT_SYMTAB = 2, SHT_RELA = 4, SHT_NOBITS = 8, SHT_REL = 9,
    SHF_ALLOC = 2, SHF_EXEC = 4, STT_OBJECT = 1, STT_FUNC = 2,
    R_ARM_V4BX = 40
};

static const char *const regions[] = {"jp", "us", "eu", "de"};
static const char *const region_labels[] = {"JP", "US", "EU", "DE"};

static void fail(const char *fmt, ...)
{
    va_list args;
    fputs("progress: ", stderr);
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fputc('\n', stderr);
    exit(EXIT_FAILURE);
}

static void *allocate(size_t n, size_t width)
{
    void *result = calloc(n ? n : 1, width);
    if (!result)
        fail("out of memory");
    return result;
}

static void *grow(void *data, size_t *capacity, size_t width)
{
    *capacity = *capacity ? *capacity * 2 : 16;
    void *result = realloc(data, *capacity * width);
    if (!result)
        fail("out of memory");
    return result;
}

#define PUSH(list, item) do { \
    if ((list).count == (list).capacity) \
        (list).items = grow((list).items, &(list).capacity, sizeof(*(list).items)); \
    (list).items[(list).count++] = (item); \
} while (0)

#define LENGTH(array) (sizeof(array) / sizeof((array)[0]))

static char *copy_string(const char *text, size_t length)
{
    char *copy = allocate(length + 1, 1);
    memcpy(copy, text, length);
    return copy;
}

static char *path_join(const char *left, const char *right)
{
    size_t length = strlen(left) + strlen(right) + 2;
    char *path = allocate(length, 1);
    snprintf(path, length, "%s/%s", left, right);
    return path;
}

static char *suffix_path(const char *stem, const char *suffix)
{
    size_t length = strlen(stem) + strlen(suffix) + 1;
    char *path = allocate(length, 1);
    snprintf(path, length, "%s%s", stem, suffix);
    return path;
}

static bool starts(const char *text, const char *prefix)
{
    return strncmp(text, prefix, strlen(prefix)) == 0;
}

static bool ends(const char *text, const char *suffix)
{
    size_t length = strlen(text), tail = strlen(suffix);
    return length >= tail && strcmp(text + length - tail, suffix) == 0;
}

static char *skip_space(char *p)
{
    while (isspace((unsigned char)*p))
        ++p;
    return p;
}

static char *word(char **cursor)
{
    char *start = skip_space(*cursor);
    char *end = start;
    while (*end && !isspace((unsigned char)*end))
        ++end;
    if (*end)
        *end++ = '\0';
    *cursor = end;
    return start;
}

static char *line(char **cursor)
{
    char *start = *cursor;
    char *end = strchr(start, '\n');
    if (end) {
        *end = '\0';
        *cursor = end + 1;
    } else {
        end = start + strlen(start);
        *cursor = end;
    }
    while (end > start && isspace((unsigned char)end[-1]))
        *--end = '\0';
    return start;
}

typedef struct {
    unsigned char *data;
    size_t size;
} Blob;

static Blob read_file(const char *path, bool required)
{
    FILE *file = fopen(path, "rb");
    if (!file) {
        if (required)
            fail("cannot open %s", path);
        return (Blob){0};
    }
    if (fseek(file, 0, SEEK_END))
        fail("cannot seek in %s", path);
    long length = ftell(file);
    if (length < 0 || fseek(file, 0, SEEK_SET))
        fail("cannot determine the size of %s", path);
    Blob result = {allocate((size_t)length + 1, 1), (size_t)length};
    if (fread(result.data, 1, result.size, file) != result.size || fclose(file))
        fail("cannot read %s", path);
    return result;
}

static bool within(size_t size, size_t offset, size_t length)
{
    return offset <= size && length <= size - offset;
}

static const unsigned char *bytes(Blob blob, size_t offset, size_t length)
{
    if (!within(blob.size, offset, length))
        fail("truncated input at offset 0x%zx", offset);
    return blob.data + offset;
}

static const char *string_at(Blob blob, size_t offset)
{
    if (offset >= blob.size || !memchr(blob.data + offset, 0, blob.size - offset))
        fail("unterminated input string at offset 0x%zx", offset);
    return (const char *)blob.data + offset;
}

static uint32_t u16(const unsigned char *p)
{
    return p[0] | (uint32_t)p[1] << 8;
}

static uint32_t u32(const unsigned char *p)
{
    return u16(p) | u16(p + 2) << 16;
}

typedef struct {
    const char *name;
    uint32_t type, flags, address, offset, size, link, info, stride;
} Section;

typedef struct {
    Blob blob;
    Section *sections;
    size_t count;
    const Section *symtab;
} Elf;

static Elf parse_elf(Blob blob)
{
    const unsigned char *header = bytes(blob, 0, 52);
    if (memcmp(header, "\177ELF\1\1\1", 7) || u16(header + 18) != 40)
        fail("expected little-endian ARM ELF32");
    uint32_t offset = u32(header + 32), stride = u16(header + 46);
    uint32_t count = u16(header + 48), names_index = u16(header + 50);
    if (stride < 40 || names_index >= count)
        fail("invalid ELF section header table");
    const unsigned char *table = bytes(blob, offset, (size_t)stride * count);
    uint32_t names = u32(table + names_index * stride + 16);
    Elf elf = {blob, allocate(count, sizeof(Section)), count, NULL};
    for (size_t i = 0; i < count; ++i) {
        const unsigned char *row = table + i * stride;
        Section *s = &elf.sections[i];
        *s = (Section){string_at(blob, (size_t)names + u32(row)), u32(row + 4),
                       u32(row + 8), u32(row + 12), u32(row + 16), u32(row + 20),
                       u32(row + 24), u32(row + 28), u32(row + 36)};
        if (s->type == SHT_SYMTAB) {
            if (s->stride < 16 || s->link >= count)
                fail("invalid ELF symbol table");
            elf.symtab = s;
        }
    }
    return elf;
}

static void release_elf(Elf elf)
{
    free(elf.sections);
    free(elf.blob.data);
}

static const Section *section_named(Elf elf, const char *name)
{
    for (size_t i = 0; i < elf.count; ++i) {
        if (strcmp(elf.sections[i].name, name) == 0)
            return &elf.sections[i];
    }
    return NULL;
}

typedef struct {
    const char *name;
    uint32_t address, size, type, section;
} Symbol;

static size_t symbol_count(Elf elf)
{
    return elf.symtab ? elf.symtab->size / elf.symtab->stride : 0;
}

static Symbol get_symbol(Elf elf, size_t index)
{
    const unsigned char *p = bytes(elf.blob, elf.symtab->offset + index * elf.symtab->stride, 16);
    uint32_t type = p[12] & 15;
    uint32_t value = u32(p + 4);
    size_t names = elf.sections[elf.symtab->link].offset;
    return (Symbol){string_at(elf.blob, names + u32(p)), type == STT_FUNC ? value & ~1u : value,
                    u32(p + 8), type, u16(p + 14)};
}

/* Traditional ar archives, including GNU and BSD long names. */
static Blob archive_member(Blob archive, const char *member)
{
    if (!within(archive.size, 0, 8) || memcmp(archive.data, "!<arch>\n", 8))
        fail("expected a regular ar archive");
    const char *names = NULL;
    size_t names_size = 0;
    for (size_t offset = 8; offset < archive.size;) {
        const unsigned char *header = bytes(archive, offset, 60);
        if (memcmp(header + 58, "`\n", 2))
            fail("invalid archive member header");
        char size_field[11], name[17];
        memcpy(size_field, header + 48, 10);
        size_field[10] = 0;
        memcpy(name, header, 16);
        name[16] = 0;
        for (size_t i = 16; i && name[i - 1] == ' '; --i)
            name[i - 1] = 0;
        size_t size = strtoul(size_field, NULL, 10);
        const unsigned char *data = bytes(archive, offset + 60, size);
        offset += 60 + size + (size & 1);
        if (strcmp(name, "//") == 0) {
            names = (const char *)data;
            names_size = size;
            continue;
        }
        const char *actual_name = name;
        size_t length = strlen(name);
        if (starts(name, "#1/")) {
            length = strtoul(name + 3, NULL, 10);
            if (length > size)
                fail("truncated BSD archive member name");
            actual_name = (const char *)data;
            data += length;
            size -= length;
            while (length && actual_name[length - 1] == '\0')
                --length;
        } else if (name[0] == '/' && isdigit((unsigned char)name[1])) {
            size_t index = strtoul(name + 1, NULL, 10);
            if (index >= names_size)
                fail("invalid GNU archive member name");
            actual_name = names + index;
            length = 0;
            while (index + length < names_size && actual_name[length] != '\n')
                ++length;
        }
        if (length && actual_name[length - 1] == '/')
            --length;
        if (strlen(member) == length && memcmp(actual_name, member, length) == 0)
            return (Blob){(unsigned char *)copy_string((const char *)data, size), size};
    }
    return (Blob){0};
}

static Blob read_object(const char *root, const char *build, const char *name)
{
    const char *archive = strstr(name, ".a(");
    if (!archive) {
        char *path = path_join(build, name);
        Blob contents = ends(name, ".o") ? read_file(path, false) : (Blob){0};
        free(path);
        return contents;
    }
    if (!ends(name, ")"))
        return (Blob){0};
    char *archive_name = copy_string(name, (size_t)(archive - name) + 2);
    char *path = path_join(build, archive_name);
    Blob contents = read_file(path, false);
    free(path);
    if (!contents.data) {
        const char *basename = strrchr(archive_name, '/');
        char *dir = path_join(root, "tools/agbcc/lib");
        path = path_join(dir, basename ? basename + 1 : archive_name);
        contents = read_file(path, false);
        free(path);
        free(dir);
    }
    free(archive_name);
    if (!contents.data)
        return (Blob){0};
    const char *member_name = archive + 3;
    char *member = copy_string(member_name, strlen(member_name) - 1);
    Blob result = archive_member(contents, member);
    free(member);
    free(contents.data);
    return result;
}

typedef struct {
    uint32_t address, size;
    const char *section, *owner;
    const Section *output;
} Row;

typedef struct {
    Row *items;
    size_t count, capacity;
    Blob text;
} Map;

static bool number(const char *text, uint32_t *value)
{
    char *end;
    unsigned long long n = strtoull(text, &end, 0);
    if (end == text || *end || n > UINT32_MAX)
        return false;
    *value = (uint32_t)n;
    return true;
}

static Map read_map(const char *path, Elf elf)
{
    Map map = {0};
    map.text = read_file(path, true);
    bool *seen = allocate(elf.count, sizeof(*seen));
    bool layout = false, output_header = false;
    const Section *output = NULL;
    const char *pending = NULL;
    char *cursor = (char *)map.text.data;
    while (*cursor) {
        char *row = line(&cursor);
        if (strcmp(row, "Linker script and memory map") == 0)
            layout = true;
        if (!layout || !*row)
            continue;
        bool top_level = !isspace((unsigned char)*row);
        char *field = word(&row);
        if (top_level) {
            output = section_named(elf, field);
            if (output && (!(output->flags & SHF_ALLOC) || !output->size))
                output = NULL;
            output_header = output != NULL;
            pending = NULL;
            if (output_header)
                field = word(&row);
        }
        if (!output)
            continue;
        if (output_header) {
            if (!*field)
                continue;
            uint32_t address, size;
            if (!number(field, &address) || !number(word(&row), &size) ||
                address != output->address || size != output->size)
                fail("map and ELF disagree on output section %s", output->name);
            seen[output - elf.sections] = true;
            output_header = false;
            continue;
        }
        if (!starts(field, "0x")) {
            pending = ends(field, ")") ? NULL : field;
            field = word(&row);
            if (!*field)
                continue;
        }
        uint32_t address, size;
        if (pending && number(field, &address) && number(word(&row), &size) && size) {
            if (address < output->address || !within(output->size, address - output->address, size))
                fail("map input outside %s at 0x%08x", output->name, address);
            const char *owner = strcmp(pending, "*fill*") ? skip_space(row) : "";
            PUSH(map, ((Row){address, size, pending, owner, output}));
        }
        pending = NULL;
    }
    for (size_t i = 0; i < elf.count; ++i) {
        Section *s = &elf.sections[i];
        if ((s->flags & SHF_ALLOC) && s->size && !seen[i])
            fail("allocated section %s is missing in the map", s->name);
    }
    free(seen);
    return map;
}

typedef struct {
    char **items;
    size_t count, capacity;
} Names;

static bool has_name(Names names, const char *name)
{
    for (size_t i = 0; i < names.count; ++i) {
        if (strcmp(names.items[i], name) == 0)
            return true;
    }
    return false;
}

static void release_names(Names names)
{
    for (size_t i = 0; i < names.count; ++i)
        free(names.items[i]);
    free(names.items);
}

static bool identifier(int ch)
{
    return isalnum((unsigned char)ch) || ch == '_' || ch == '~';
}

static bool asm_identifier(int ch)
{
    return identifier(ch) || ch == '.' || ch == '$';
}

static char *quoted_end(char *start)
{
    char quote = *start++;
    while (*start && *start != quote) {
        if (*start == '\\' && start[1])
            ++start;
        ++start;
    }
    return start;
}

typedef struct {
    Names naked, assembly;
    bool ambiguous;
} Hints;

static void asm_line(Hints *hints, char *begin, const char *end)
{
    begin = skip_space(begin);
    if (begin >= end)
        return;
    char *p = begin;
    while (p < end && asm_identifier(*p))
        ++p;
    if (p == begin)
        return;
    if (*p == ':') {
        PUSH(hints->assembly, copy_string(begin, p - begin));
        return;
    }
    bool size = p - begin == 5 && strncmp(begin, ".size", 5) == 0;
    bool function_end = p - begin >= 9 && strncmp(p - 9, "_func_end", 9) == 0;
    bool function_start = p - begin >= 11 && strncmp(p - 11, "_func_start", 11) == 0;
    if (size || function_start || function_end) {
        begin = skip_space(p);
        p = begin;
        while (p < end && asm_identifier(*p))
            ++p;
        if (p > begin)
            PUSH(hints->assembly, copy_string(begin, p - begin));
        else if (size || function_end)
            hints->ambiguous = true;
    }
}

static void asm_literal(Hints *hints, char *begin, char *end)
{
    for (char *p = begin; p < end; ++p) {
        if (p[0] == '\\' && p + 1 < end) {
            if (p[1] == 'n') {
                asm_line(hints, begin, p);
                begin = p + 2;
            }
            ++p;
        }
    }
    asm_line(hints, begin, end);
}

static void add_naked(Hints *hints, char *p, Names scopes)
{
    char *name = NULL, *name_end = NULL;
    int templates = 0;
    while (*p && *p != ';' && *p != '{' && *p != '}') {
        if (*p == '(' && templates == 0)
            break;
        if (*p == '<')
            ++templates;
        if (*p == '>' && templates)
            --templates;
        if (templates == 0 && identifier(*p)) {
            name = p;
            while (identifier(*p))
                ++p;
            name_end = p;
        } else {
            ++p;
        }
    }
    if (*p != '(' || !name) {
        hints->ambiguous = true;
        return;
    }
    Names explicit_scopes = {0};
    char *qualifier = name;
    while (qualifier[-1] == ':' && qualifier[-2] == ':') {
        char *end = qualifier - 2;
        char *begin = end;
        while (identifier(begin[-1]))
            --begin;
        if (begin == end)
            break;
        PUSH(explicit_scopes, copy_string(begin, end - begin));
        qualifier = begin;
    }
    /*
     * Match the old GNU mangling after the method name. Unqualified functions
     * use just the name, including template instances from the same source.
     */
    size_t length = (size_t)(name_end - name);
    char *mangled = copy_string(name, length);
    size_t count = explicit_scopes.count;
    if (!count) {
        for (size_t i = 0; i < scopes.count; ++i)
            count += scopes.items[i] != NULL;
    }
    if (count) {
        free(mangled);
        Names owners = explicit_scopes.count ? explicit_scopes : scopes;
        size_t capacity = length + 32;
        for (size_t i = 0; i < owners.count; ++i) {
            if (owners.items[i])
                capacity += strlen(owners.items[i]) + 16;
        }
        mangled = allocate(capacity, 1);
        memcpy(mangled, name, length);
        length += (size_t)snprintf(mangled + length, capacity - length, "__");
        if (count > 1)
            length += (size_t)snprintf(mangled + length, capacity - length, "Q%zu", count);
        for (size_t i = 0; i < owners.count; ++i) {
            const char *owner = owners.items[explicit_scopes.count ? owners.count - i - 1 : i];
            if (owner)
                length += (size_t)snprintf(mangled + length, capacity - length, "%zu%s",
                                           strlen(owner), owner);
        }
    }
    PUSH(hints->naked, mangled);
    release_names(explicit_scopes);
}

static Hints scan_source(Blob text)
{
    Hints hints = {0};
    char *p = (char *)text.data;
    if (!strstr(p, "asm") && !strstr(p, "NAKED") && !strstr(p, "naked"))
        return hints;
    Names scopes = {0};
    char *pending_class = NULL;
    while (*p) {
        if (*p == '#' || starts(p, "//")) {
            char *end = strchr(p, '\n');
            p = end ? end + 1 : p + strlen(p);
        } else if (starts(p, "/*")) {
            char *end = strstr(p + 2, "*/");
            p = end ? end + 2 : p + strlen(p);
        } else if (*p == '"' || *p == '\'') {
            char *end = quoted_end(p);
            if (*p == '"')
                asm_literal(&hints, p + 1, end);
            p = end + (*end != '\0');
        } else if (*p == '{') {
            PUSH(scopes, pending_class);
            pending_class = NULL;
            ++p;
        } else if (*p == '}' || *p == ';') {
            if (*p == '}' && scopes.count)
                free(scopes.items[--scopes.count]);
            free(pending_class);
            pending_class = NULL;
            ++p;
        } else if (identifier(*p)) {
            const char *begin = p;
            while (identifier(*p))
                ++p;
            size_t length = p - begin;
            if ((length == 6 && !memcmp(begin, "struct", 6)) ||
                (length == 5 && (!memcmp(begin, "class", 5) || !memcmp(begin, "union", 5)))) {
                char *name = skip_space(p), *end = name;
                while (identifier(*end))
                    ++end;
                free(pending_class);
                pending_class = end > name ? copy_string(name, end - name) : NULL;
            } else if (length == 5 && !memcmp(begin, "NAKED", 5)) {
                add_naked(&hints, p, scopes);
            } else if (length == 13 && !memcmp(begin, "__attribute__", 13)) {
                char *attribute = skip_space(p);
                if (starts(attribute, "((")) {
                    char *value = skip_space(attribute + 2);
                    char *end = starts(value, "naked") ? skip_space(value + 5) : value;
                    if (starts(end, "))"))
                        add_naked(&hints, end + 2, scopes);
                }
            }
        } else {
            ++p;
        }
    }
    free(pending_class);
    release_names(scopes);
    return hints;
}

typedef struct {
    char *path;
    Hints hints;
} CachedSource;

static struct {
    CachedSource **items;
    size_t count, capacity;
} source_cache;

static const Hints *source_hints(const char *path)
{
    for (size_t i = 0; i < source_cache.count; ++i) {
        CachedSource *entry = source_cache.items[i];
        if (strcmp(entry->path, path) == 0)
            return &entry->hints;
    }
    Blob contents = read_file(path, false);
    if (!contents.data)
        return NULL;
    CachedSource *entry = allocate(1, sizeof(*entry));
    entry->path = copy_string(path, strlen(path));
    entry->hints = scan_source(contents);
    free(contents.data);
    PUSH(source_cache, entry);
    return &entry->hints;
}

static void release_source_cache(void)
{
    for (size_t i = 0; i < source_cache.count; ++i) {
        CachedSource *entry = source_cache.items[i];
        free(entry->path);
        release_names(entry->hints.naked);
        release_names(entry->hints.assembly);
        free(entry);
    }
    free(source_cache.items);
}

typedef enum { NO_SOURCE, COMPILER_SOURCE, ASM_SOURCE, GENERATED_ASM } Origin;

typedef struct {
    Origin origin;
    const Hints **items;
    size_t count, capacity;
    Names compiler_ends;
    bool has_compiler_asm, ambiguous;
} Source;

static void add_hints(Source *source, const char *path)
{
    const Hints *hints = source_hints(path);
    if (!hints)
        return;
    if (hints->naked.count || hints->assembly.count)
        PUSH(*source, hints);
    source->ambiguous |= hints->ambiguous;
}

static void read_dependencies(Source *source, const char *root, Blob deps)
{
    char *cursor = strchr((char *)deps.data, ':');
    if (!cursor)
        return;
    ++cursor;
    while (*cursor) {
        while (*cursor == ' ' || *cursor == '\t')
            ++cursor;
        if (*cursor == '\\' && (cursor[1] == '\r' || cursor[1] == '\n')) {
            ++cursor;
            if (*cursor == '\r')
                ++cursor;
            ++cursor;
            continue;
        }
        if (!*cursor || *cursor == '\n' || *cursor == '\r')
            break;
        char *begin = cursor;
        while (*cursor && !isspace((unsigned char)*cursor)) {
            if (*cursor == '\\' && cursor[1] == ' ')
                ++cursor;
            ++cursor;
        }
        char *name = copy_string(begin, cursor - begin), *out = name;
        for (char *in = name; *in; ++in) {
            if (*in == '\\' && in[1] == ' ')
                ++in;
            *out++ = *in;
        }
        *out = 0;
        if (ends(name, ".h") || ends(name, ".hh")) {
            char *path = path_join(root, name);
            add_hints(source, path);
            free(path);
        }
        free(name);
    }
}

static void read_compiler_ends(Source *source, Blob assembly)
{
    char *cursor = (char *)assembly.data;
    while (*cursor) {
        char *row = skip_space(line(&cursor));
        if (strcmp(word(&row), ".size") != 0)
            continue;
        row = skip_space(row);
        char *comma = strchr(row, ',');
        if (!comma)
            continue;
        *comma++ = 0;
        comma = skip_space(comma);
        if (!starts(comma, ".Lfe"))
            continue;
        comma += 4;
        if (!isdigit((unsigned char)*comma))
            continue;
        while (isdigit((unsigned char)*comma))
            ++comma;
        if (*comma == '-' && strcmp(row, comma + 1) == 0)
            PUSH(source->compiler_ends, copy_string(row, strlen(row)));
    }
}

static char *find_source(const char *stem, Origin *origin, bool generated)
{
    const char *const suffixes[] = {".c", ".cc", ".s"};
    for (size_t i = 0; i < LENGTH(suffixes); ++i) {
        char *path = suffix_path(stem, suffixes[i]);
        FILE *file = fopen(path, "rb");
        if (file) {
            fclose(file);
            *origin = i < 2 ? COMPILER_SOURCE : generated ? GENERATED_ASM : ASM_SOURCE;
            return path;
        }
        free(path);
    }
    return NULL;
}

static Source inspect_source(const char *root, const char *build, int region, const char *owner)
{
    Source source = {0};
    if (!ends(owner, ".o"))
        return source;
    char *object_stem = copy_string(owner, strlen(owner) - 2);
    char *repo_stem = path_join(root, object_stem);
    char *build_stem = path_join(build, object_stem);
    char *path = find_source(repo_stem, &source.origin, false);
    if (!path && starts(object_stem, "data/text/")) {
        char *text_dir = path_join(root, "data/text");
        char *region_dir = path_join(text_dir, regions[region]);
        char *regional_stem = path_join(region_dir, object_stem + strlen("data/text/"));
        path = find_source(regional_stem, &source.origin, false);
        free(regional_stem);
        free(region_dir);
        free(text_dir);
    }
    if (!path)
        path = find_source(build_stem, &source.origin, true);
    if (source.origin == COMPILER_SOURCE) {
        add_hints(&source, path);
        char *deps_path = suffix_path(build_stem, ".d");
        Blob deps = read_file(deps_path, false);
        if (deps.data)
            read_dependencies(&source, root, deps);
        free(deps.data);
        free(deps_path);
        char *asm_path = suffix_path(build_stem, ".s");
        Blob assembly = read_file(asm_path, false);
        if (assembly.data) {
            source.has_compiler_asm = true;
            read_compiler_ends(&source, assembly);
        }
        free(assembly.data);
        free(asm_path);
    }
    free(path);
    free(build_stem);
    free(repo_stem);
    free(object_stem);
    return source;
}

static bool handwritten_function(Source source, const char *symbol)
{
    for (size_t i = 0; i < source.count; ++i) {
        const Hints *hints = source.items[i];
        if (has_name(hints->assembly, symbol))
            return true;
        for (size_t j = 0; j < hints->naked.count; ++j) {
            const char *name = hints->naked.items[j];
            if (strcmp(name, symbol) == 0)
                return true;
            /* Skip a leading double underscore in a reserved identifier. */
            const char *qualifier = strstr(name + (starts(name, "__") ? 2 : 0), "__");
            size_t length = qualifier ? (size_t)(qualifier - name) : strlen(name);
            if (strncmp(name, symbol, length) || !starts(symbol + length, "__"))
                continue;
            if (!qualifier || starts(symbol + length + 2 + strspn(symbol + length + 2, "CV"),
                                     qualifier + 2))
                return true;
        }
    }
    return false;
}

typedef struct {
    const char *name;
    unsigned width;
    bool branch;
} RelocType;

static const RelocType reloc_types[256] = {
    [1] = {"PC24", 4, true},
    [2] = {"ABS32", 4, false},
    [3] = {"REL32", 4, false},
    [5] = {"ABS16", 2, false},
    [8] = {"ABS8", 1, false},
    [10] = {"THM_CALL", 4, true},
    [27] = {"PLT32", 4, true},
    [28] = {"CALL", 4, true},
    [29] = {"JUMP24", 4, true},
    [30] = {"THM_JUMP24", 4, true},
    [38] = {"TARGET1", 4, false},
    [R_ARM_V4BX] = {"V4BX", 4, false},
    [42] = {"PREL31", 4, false},
    [102] = {"THM_JUMP11", 2, true},
    [103] = {"THM_JUMP8", 2, true}
};

typedef struct {
    uint32_t offset;
    unsigned type;
} Relocation;

typedef struct {
    Relocation *items;
    size_t count, capacity;
} Relocations;

static int compare_relocations(const void *a, const void *b)
{
    uint32_t left = ((const Relocation *)a)->offset, right = ((const Relocation *)b)->offset;
    return (left > right) - (left < right);
}

static Relocations read_relocations(Elf elf, const Section *input)
{
    Relocations relocs = {0};
    for (size_t i = 0; i < elf.count; ++i) {
        const Section *candidate = &elf.sections[i];
        if ((candidate->type != SHT_REL && candidate->type != SHT_RELA) ||
            candidate->info != (size_t)(input - elf.sections))
            continue;
        if (candidate->stride < 8 || candidate->size % candidate->stride)
            fail("invalid relocation table %s", candidate->name);
        const unsigned char *data = bytes(elf.blob, candidate->offset, candidate->size);
        for (size_t offset = 0; offset < candidate->size; offset += candidate->stride) {
            unsigned type = data[offset + 4];
            if (type)
                PUSH(relocs, ((Relocation){u32(data + offset), type}));
        }
    }
    if (relocs.count > 1)
        qsort(relocs.items, relocs.count, sizeof(*relocs.items), compare_relocations);
    return relocs;
}

static bool matches_linked_input(Elf linked, Row row, Elf elf, const Section *input,
                                  Relocations relocs)
{
    if (input->size != row.size)
        return false;
    if (input->type == SHT_NOBITS)
        return row.output->type == SHT_NOBITS;
    const unsigned char *original = bytes(elf.blob, input->offset, row.size);
    if (row.output->type == SHT_NOBITS) {
        /* ld can put zero-initialized PROGBITS in a NOLOAD output section. */
        for (size_t i = 0; i < row.size; ++i) {
            if (original[i])
                return false;
        }
        return true;
    }
    size_t offset = (size_t)row.output->offset + row.address - row.output->address;
    const unsigned char *result = bytes(linked.blob, offset, row.size);
    size_t end = 0;
    for (size_t i = 0; i < relocs.count; ++i) {
        Relocation r = relocs.items[i];
        size_t width = reloc_types[r.type].width;
        if (!width || !within(row.size, r.offset, width))
            return false;
        if (r.offset > end && memcmp(original + end, result + end, r.offset - end))
            return false;
        if (r.offset + width > end)
            end = r.offset + width;
    }
    return memcmp(original + end, result + end, row.size - end) == 0;
}

static bool compiler_object(Elf elf)
{
    for (size_t i = 0; i < symbol_count(elf); ++i) {
        if (strcmp(get_symbol(elf, i).name, ".gcc2_compiled.") == 0)
            return true;
    }
    return false;
}

enum CodeKind { C_CPP, ASSEMBLY, ARCHIVE_LIBRARY, MAPPED_DATA, UNATTRIBUTED,
                CODE_PADDING, CODE_UNKNOWN, CODE_KINDS };
enum DataKind { C_CPP_OBJECTS, GENERATED_ASSEMBLY, ASSEMBLY_OR_BINARY,
                COMMON, DATA_PADDING, DATA_UNKNOWN, DATA_KINDS };

static const char *const code_keys[] = {
    "c_cpp", "assembly", "archive_library", "mapped_data", "unattributed_instructions",
    "padding", "unknown"
};
static const char *const data_keys[] = {
    "c_cpp_objects", "generated_assembly", "assembly_or_binary", "common", "padding", "unknown"
};

typedef struct {
    char *name;
    bool bss;
    size_t counts[DATA_KINDS], relocations[256];
} Segment;

typedef struct {
    const char *name;
    size_t size;
} InputCount;

typedef struct {
    InputCount *items;
    size_t count, capacity;
} InputCounts;

typedef struct {
    uint32_t *items;
    size_t count, capacity;
} Addresses;

typedef struct {
    char digest[41], expected[41];
    bool hash_match, loads_match, has_baserom, baserom_match;
} Verification;

typedef struct {
    int region;
    char *elf, *build;
    Verification verification;
    size_t code[CODE_KINDS], text_relocations[256], iwram_relocations[256];
    size_t c_entries, known_entries, bytes_checked, compiler_assembly_objects;
    InputCounts unverified, unattributed;
    struct { Segment *items; size_t count, capacity; } segments;
    Addresses fixed_locations;
} Report;

static uint32_t rotate_left(uint32_t x, unsigned n)
{
    return (x << n) | (x >> (32 - n));
}

static void sha1(Blob blob, char digest[41])
{
    uint32_t hash[] = {0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476, 0xc3d2e1f0};
    uint64_t bits = (uint64_t)blob.size * 8;
    size_t padded = (blob.size + 72) / 64 * 64;
    for (size_t offset = 0; offset < padded; offset += 64) {
        uint32_t words[80] = {0};
        for (size_t i = 0; i < 64; ++i) {
            size_t index = offset + i;
            unsigned byte = 0;
            if (index < blob.size)
                byte = blob.data[index];
            else if (index == blob.size)
                byte = 0x80;
            else if (index >= padded - 8)
                byte = (unsigned)(bits >> ((padded - 1 - index) * 8)) & 0xff;
            words[i / 4] = (words[i / 4] << 8) | byte;
        }
        for (size_t i = 16; i < 80; ++i)
            words[i] = rotate_left(words[i - 3] ^ words[i - 8] ^ words[i - 14] ^ words[i - 16], 1);
        uint32_t a = hash[0], b = hash[1], c = hash[2], d = hash[3], e = hash[4];
        for (size_t i = 0; i < 80; ++i) {
            uint32_t f, constant;
            if (i < 20) {
                f = (b & c) | (~b & d);
                constant = 0x5a827999;
            } else if (i < 40) {
                f = b ^ c ^ d;
                constant = 0x6ed9eba1;
            } else if (i < 60) {
                f = (b & c) | (b & d) | (c & d);
                constant = 0x8f1bbcdc;
            } else {
                f = b ^ c ^ d;
                constant = 0xca62c1d6;
            }
            uint32_t next = rotate_left(a, 5) + f + e + constant + words[i];
            e = d;
            d = c;
            c = rotate_left(b, 30);
            b = a;
            a = next;
        }
        hash[0] += a;
        hash[1] += b;
        hash[2] += c;
        hash[3] += d;
        hash[4] += e;
    }
    for (size_t i = 0; i < LENGTH(hash); ++i)
        snprintf(digest + i * 8, 9, "%08x", hash[i]);
}

static bool rom_matches_loads(Blob rom, Elf elf)
{
    const unsigned char *header = elf.blob.data;
    uint32_t offset = u32(header + 28), stride = u16(header + 42), count = u16(header + 44);
    if (stride < 32)
        return false;
    bool checked = false;
    for (size_t i = 0; i < count; ++i) {
        const unsigned char *row = bytes(elf.blob, offset + i * stride, 32);
        uint32_t physical = u32(row + 12), size = u32(row + 16);
        if (u32(row) != 1 || !size)
            continue;
        if (physical < ROM_BASE || !within(rom.size, physical - ROM_BASE, size))
            return false;
        uint32_t start = physical - ROM_BASE;
        uint32_t skip = start < ROM_HEADER ? ROM_HEADER - start : 0;
        if (skip > size)
            skip = size;
        const unsigned char *payload = bytes(elf.blob, u32(row + 4), size);
        if (memcmp(payload + skip, rom.data + start + skip, size - skip))
            return false;
        checked = true;
    }
    return checked;
}

static Verification verify_rom(const char *root, int region, const char *prefix, Elf elf)
{
    char checksum[32], base[32];
    snprintf(checksum, sizeof(checksum), "fomt_%s.sha1", regions[region]);
    snprintf(base, sizeof(base), "baserom_%s.gba", regions[region]);
    char *rom_path = suffix_path(prefix, ".gba");
    char *base_path = path_join(root, base);
    char *expected_path = path_join(root, checksum);
    Blob rom = read_file(rom_path, true);
    Blob baserom = read_file(base_path, false);
    Blob expected = read_file(expected_path, true);
    Verification result = {0};
    sha1(rom, result.digest);
    char *digest = skip_space((char *)expected.data);
    if (strlen(digest) < 40 || isxdigit((unsigned char)digest[40]))
        fail("invalid SHA-1 in %s", expected_path);
    for (size_t i = 0; i < 40; ++i) {
        if (!isxdigit((unsigned char)digest[i]))
            fail("invalid SHA-1 in %s", expected_path);
        result.expected[i] = (char)tolower((unsigned char)digest[i]);
    }
    result.hash_match = strcmp(result.digest, result.expected) == 0;
    result.loads_match = rom_matches_loads(rom, elf);
    result.has_baserom = baserom.data != NULL;
    result.baserom_match = baserom.size == rom.size && baserom.data &&
                           memcmp(baserom.data, rom.data, rom.size) == 0;
    free(rom.data);
    free(baserom.data);
    free(expected.data);
    free(rom_path);
    free(base_path);
    free(expected_path);
    return result;
}

static bool rom_verified(Verification v)
{
    return v.hash_match && v.loads_match && (!v.has_baserom || v.baserom_match);
}

static size_t sum(const size_t *values, size_t count)
{
    size_t result = 0;
    for (size_t i = 0; i < count; ++i)
        result += values[i];
    return result;
}

static bool input_is_code(Row row)
{
    return (row.output->flags & SHF_EXEC) &&
           !starts(row.section, ".rodata") && !starts(row.section, ".data");
}

static Segment *segment_for(Report *report, Row row)
{
    const char *name = row.output->name;
    char *combined = NULL;
    if (row.output->flags & SHF_EXEC) {
        char *prefix = suffix_path(name, ":");
        name = combined = suffix_path(prefix, row.section);
        free(prefix);
    }
    for (size_t i = 0; i < report->segments.count; ++i) {
        Segment *segment = &report->segments.items[i];
        if (strcmp(segment->name, name) == 0) {
            free(combined);
            return segment;
        }
    }
    Segment segment = {0};
    segment.name = combined ? combined : copy_string(name, strlen(name));
    segment.bss = row.output->type == SHT_NOBITS;
    PUSH(report->segments, segment);
    return &report->segments.items[report->segments.count - 1];
}

static int compare_layout(const void *a, const void *b)
{
    const Row *left = a, *right = b;
    if (left->output != right->output)
        return left->output < right->output ? -1 : 1;
    return (left->address > right->address) - (left->address < right->address);
}

static int compare_owners(const void *a, const void *b)
{
    return strcmp(((const Row *)a)->owner, ((const Row *)b)->owner);
}

static size_t header_bytes(Row row)
{
    if (strcmp(row.output->name, ".text") || row.address >= ROM_BASE + ROM_HEADER)
        return 0;
    size_t remaining = ROM_BASE + ROM_HEADER - row.address;
    return remaining < row.size ? remaining : row.size;
}

static void count_gaps(Report *report, Elf elf, Map map)
{
    if (map.count > 1)
        qsort(map.items, map.count, sizeof(*map.items), compare_layout);
    size_t index = 0;
    for (size_t i = 0; i < elf.count; ++i) {
        const Section *s = &elf.sections[i];
        if (!(s->flags & SHF_ALLOC) || !s->size)
            continue;
        uint32_t address = s->address;
        size_t gap = 0;
        while (index < map.count && map.items[index].output == s) {
            Row row = map.items[index++];
            if (row.address < address)
                fail("overlapping input ranges in %s", s->name);
            gap += row.address - address;
            address = row.address + row.size;
        }
        gap += s->size - (address - s->address);
        if (!gap || strcmp(s->name, ".pad") == 0)
            continue;
        Row row = {s->address, s->size, s->name, "", s};
        if (input_is_code(row))
            report->code[CODE_UNKNOWN] += gap;
        else
            segment_for(report, row)->counts[DATA_UNKNOWN] += gap;
    }
}

static bool is_mapping(Symbol symbol)
{
    const char *name = symbol.name;
    return name[0] == '$' && strchr("atd", name[1]) && name[1] &&
           (name[2] == 0 || name[2] == '.');
}

enum { FUNCTION_ENTRY = 1, CPP_ENTRY = 2, ASM_ENTRY = 4, CPP_BYTE = 8 };

static size_t count_code(Report *report, Row row, Elf elf, const Section *input,
                         Source source, size_t begin, bool archive)
{
    unsigned char *marks = allocate(row.size, 1);
    char *mappings = allocate(row.size, 1);
    for (size_t i = 0; i < symbol_count(elf); ++i) {
        Symbol symbol = get_symbol(elf, i);
        if (symbol.section != (size_t)(input - elf.sections) || symbol.address >= row.size)
            continue;
        if (is_mapping(symbol))
            mappings[symbol.address] = symbol.name[1];
        if (symbol.type != STT_FUNC || symbol.address < begin)
            continue;
        marks[symbol.address] |= FUNCTION_ENTRY;
        if (handwritten_function(source, symbol.name)) {
            marks[symbol.address] |= ASM_ENTRY;
        } else if (source.origin == COMPILER_SOURCE && !source.ambiguous && symbol.size &&
                   within(row.size, symbol.address, symbol.size) &&
                   (!source.has_compiler_asm || has_name(source.compiler_ends, symbol.name))) {
            marks[symbol.address] |= CPP_ENTRY;
            size_t end = symbol.address + symbol.size;
            for (size_t j = symbol.address; j < end; ++j)
                marks[j] |= CPP_BYTE;
        }
    }
    size_t unattributed = 0;
    bool handwritten = source.origin == ASM_SOURCE || source.origin == GENERATED_ASM;
    char mode = 0;
    for (size_t i = 0; i < row.size; ++i) {
        if (mappings[i])
            mode = mappings[i];
        if (i < begin)
            continue;
        if (marks[i] & FUNCTION_ENTRY) {
            ++report->known_entries;
            if (source.origin != ASM_SOURCE && source.origin != GENERATED_ASM)
                handwritten = (marks[i] & ASM_ENTRY) != 0;
        }
        report->c_entries += (marks[i] & CPP_ENTRY) != 0 && !archive;
        enum CodeKind kind;
        if (archive)
            kind = ARCHIVE_LIBRARY;
        else if (marks[i] & CPP_BYTE)
            kind = C_CPP;
        else if (mode == 'a' || mode == 't')
            kind = handwritten ? ASSEMBLY : UNATTRIBUTED;
        else if (mode == 'd')
            kind = MAPPED_DATA;
        else
            kind = CODE_UNKNOWN;
        ++report->code[kind];
        unattributed += kind == UNATTRIBUTED;
    }
    free(marks);
    free(mappings);
    return unattributed;
}

static size_t count_data_objects(Elf elf, const Section *input)
{
    unsigned char *covered = allocate(input->size, 1);
    for (size_t i = 0; i < symbol_count(elf); ++i) {
        Symbol symbol = get_symbol(elf, i);
        if (symbol.section == (size_t)(input - elf.sections) && symbol.type == STT_OBJECT &&
            within(input->size, symbol.address, symbol.size))
            memset(covered + symbol.address, 1, symbol.size);
    }
    size_t count = 0;
    for (size_t i = 0; i < input->size; ++i)
        count += covered[i];
    free(covered);
    return count;
}

static void count_owner(Report *report, const char *root, const char *build, Elf linked,
                        const Row *rows, size_t count)
{
    const char *owner = rows[0].owner;
    Blob contents = read_object(root, build, owner);
    Elf elf = contents.data ? parse_elf(contents) : (Elf){0};
    Source source = inspect_source(root, build, report->region, owner);
    if (source.origin == COMPILER_SOURCE && !compiler_object(elf))
        source.origin = NO_SOURCE;
    report->compiler_assembly_objects += source.has_compiler_asm && contents.data != NULL;
    bool archive = strstr(owner, ".a(") != NULL;
    size_t unverified = 0, unattributed = 0;

    for (size_t i = 0; i < count; ++i) {
        Row row = rows[i];
        if (strcmp(row.output->name, ".pad") == 0)
            continue;
        size_t begin = header_bytes(row), size = row.size - begin;
        if (!size)
            continue;
        bool code = input_is_code(row);
        Segment *segment = code ? NULL : segment_for(report, row);
        if (strcmp(row.section, "*fill*") == 0) {
            if (code)
                report->code[CODE_PADDING] += size;
            else
                segment->counts[DATA_PADDING] += size;
            continue;
        }
        if (segment && strcmp(row.section, "COMMON") == 0) {
            segment->counts[COMMON] += size;
            continue;
        }
        const Section *input = section_named(elf, row.section);
        Relocations relocs = input ? read_relocations(elf, input) : (Relocations){0};
        if (!input || !matches_linked_input(linked, row, elf, input, relocs)) {
            if (code)
                report->code[CODE_UNKNOWN] += size;
            else
                segment->counts[DATA_UNKNOWN] += size;
            if (*owner)
                unverified += size;
            free(relocs.items);
            continue;
        }
        if (row.output->type != SHT_NOBITS)
            report->bytes_checked += size;
        size_t *refs;
        if (strcmp(row.output->name, ".iwram") == 0)
            refs = report->iwram_relocations;
        else
            refs = code ? report->text_relocations : segment->relocations;
        for (size_t j = 0; j < relocs.count; ++j) {
            Relocation r = relocs.items[j];
            if (r.type != R_ARM_V4BX && r.offset >= begin)
                ++refs[r.type];
        }
        free(relocs.items);
        if (code) {
            unattributed += count_code(report, row, elf, input, source, begin, archive);
        } else if (source.origin == COMPILER_SOURCE) {
            size_t objects = count_data_objects(elf, input);
            segment->counts[C_CPP_OBJECTS] += objects;
            segment->counts[DATA_UNKNOWN] += size - objects;
        } else {
            enum DataKind kind = source.origin == ASM_SOURCE ? ASSEMBLY_OR_BINARY : DATA_UNKNOWN;
            if (source.origin == GENERATED_ASM)
                kind = GENERATED_ASSEMBLY;
            segment->counts[kind] += size;
        }
    }

    if (unverified)
        PUSH(report->unverified, ((InputCount){copy_string(owner, strlen(owner)), unverified}));
    if (unattributed)
        PUSH(report->unattributed, ((InputCount){copy_string(owner, strlen(owner)), unattributed}));
    release_names(source.compiler_ends);
    free(source.items);
    release_elf(elf);
}

static Addresses read_fixed_locations(const char *root, int region)
{
    char name[32];
    snprintf(name, sizeof(name), "fomt_%s.lds", regions[region]);
    char *path = path_join(root, name);
    Blob contents = read_file(path, true);
    free(path);
    char *cursor = (char *)contents.data;
    char *comment;
    while ((comment = strstr(cursor, "/*")) != NULL) {
        char *end = strstr(comment + 2, "*/");
        if (!end)
            break;
        for (char *p = comment; p < end + 2; ++p) {
            if (*p != '\n')
                *p = ' ';
        }
        cursor = end + 2;
    }
    cursor = (char *)contents.data;
    Addresses locations = {0};
    bool seen_base = false;
    while (*cursor) {
        char *p = skip_space(line(&cursor));
        if (*p++ != '.')
            continue;
        p = skip_space(p);
        if (*p++ != '=')
            continue;
        p = skip_space(p);
        bool parenthesized = *p == '(';
        if (parenthesized)
            p = skip_space(p + 1);
        if (!isdigit((unsigned char)*p))
            continue;
        char *end;
        unsigned long long address = strtoull(p, &end, 0);
        end = skip_space(end);
        if (parenthesized && *end == ')')
            end = skip_space(end + 1);
        if (*end != ';' || address > UINT32_MAX)
            continue;
        if (address == ROM_BASE && !seen_base) {
            seen_base = true;
            continue;
        }
        PUSH(locations, (uint32_t)address);
    }
    free(contents.data);
    return locations;
}

static int compare_segments(const void *a, const void *b)
{
    return strcmp(((const Segment *)a)->name, ((const Segment *)b)->name);
}

static Report report_region(const char *root, int region, const char *build_override,
                            const char *elf_override)
{
    char name[32];
    snprintf(name, sizeof(name), "fomt_%s", regions[region]);
    char *prefix = path_join(root, name);
    if (elf_override) {
        free(prefix);
        if (!ends(elf_override, ".elf"))
            fail("--elf needs an .elf file");
        prefix = copy_string(elf_override, strlen(elf_override) - 4);
    }
    char *build_dir = path_join(root, "build");
    char *build = build_override ? copy_string(build_override, strlen(build_override)) :
                                  path_join(build_dir, regions[region]);
    free(build_dir);
    Report report = {0};
    report.region = region;
    report.elf = suffix_path(prefix, ".elf");
    report.build = build;
    Elf elf = parse_elf(read_file(report.elf, true));
    report.verification = verify_rom(root, region, prefix, elf);
    char *map_path = suffix_path(prefix, ".map");
    Map map = read_map(map_path, elf);
    free(map_path);
    free(prefix);
    count_gaps(&report, elf, map);
    if (map.count > 1)
        qsort(map.items, map.count, sizeof(*map.items), compare_owners);
    for (size_t i = 0; i < map.count;) {
        size_t end = i + 1;
        while (end < map.count && strcmp(map.items[i].owner, map.items[end].owner) == 0)
            ++end;
        count_owner(&report, root, build, elf, map.items + i, end - i);
        i = end;
    }
    if (report.segments.count > 1)
        qsort(report.segments.items, report.segments.count, sizeof(*report.segments.items),
              compare_segments);
    report.fixed_locations = read_fixed_locations(root, region);
    free(map.items);
    free(map.text.data);
    release_elf(elf);
    return report;
}

static void merge_relocations(size_t *total, const size_t *counts)
{
    for (size_t i = 0; i < LENGTH(reloc_types); ++i)
        total[i] += counts[i];
}

static void print_report(const Report *reports, size_t count)
{
    puts("| Region | C/C++ | Assembly | Archive libraries | Code-section data | "
         "Unattributed instructions | Linker padding | Unknown | Code layout | "
         "C/C++ entries / known | ROM SHA-1 / ELF loads |");
    puts("| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | --- |");
    for (size_t i = 0; i < count; ++i) {
        const Report *r = &reports[i];
        size_t total = sum(r->code, CODE_KINDS);
        printf("| %s | %zu", region_labels[r->region], r->code[C_CPP]);
        if (total)
            printf(" (%.2f%%)", r->code[C_CPP] * 100.0 / total);
        for (size_t j = C_CPP + 1; j < CODE_KINDS; ++j)
            printf(" | %zu", r->code[j]);
        printf(" | %zu | %zu / %zu | %s |\n", total, r->c_entries, r->known_entries,
               rom_verified(r->verification) ? "match" : "mismatch");
    }

    const char *const titles[] = {"ROM data and resources", "RAM BSS"};
    for (size_t bss = 0; bss < LENGTH(titles); ++bss) {
        printf("\n### %s (bytes)\n\n", titles[bss]);
        puts("| Region | Segment | C/C++ objects | Generated assembly | Assembly / binary | "
             "COMMON | Padding | Unknown | Total |");
        puts("| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |");
        for (size_t i = 0; i < count; ++i) {
            const Report *r = &reports[i];
            for (size_t j = 0; j < r->segments.count; ++j) {
                const Segment *segment = &r->segments.items[j];
                if (segment->bss != (bool)bss)
                    continue;
                printf("| %s | %s", region_labels[r->region], segment->name);
                for (size_t k = 0; k < DATA_KINDS; ++k)
                    printf(" | %zu", segment->counts[k]);
                printf(" | %zu |\n", sum(segment->counts, DATA_KINDS));
            }
        }
    }

    puts("\n### Dynamic linkage evidence\n");
    puts("| Region | Checked linked input bytes | ABS32 sites | Branch sites | Other sites | "
         "Explicit LDS locations | Fully audited bytes |");
    puts("| --- | ---: | ---: | ---: | ---: | ---: | --- |");
    for (size_t i = 0; i < count; ++i) {
        const Report *r = &reports[i];
        size_t total[256] = {0}, branches = 0;
        merge_relocations(total, r->text_relocations);
        merge_relocations(total, r->iwram_relocations);
        for (size_t j = 0; j < r->segments.count; ++j)
            merge_relocations(total, r->segments.items[j].relocations);
        for (size_t j = 0; j < LENGTH(reloc_types); ++j) {
            if (reloc_types[j].branch)
                branches += total[j];
        }
        printf("| %s | %zu | %zu | %zu | %zu | %zu | Not measured |\n",
               region_labels[r->region], r->bytes_checked, total[2], branches,
               sum(total, LENGTH(total)) - total[2] - branches, r->fixed_locations.count);
    }
    puts("\nLiteral LDS assignments exclude the ROM base. Relocation sites are counted from input "
         "sections checked against the ELF outside the relocation fields. Implicit references, "
         "length constraints and address expressions still require audit. See RELOCATION_AUDIT.md.");
    puts("Code layout excludes the cartridge header and IWRAM initialization data. C/C++ function "
         "spans include compiler literal pools. Assembly counts ARM/Thumb-mapped instructions "
         "with known source provenance.");
    for (size_t i = 0; i < count; ++i) {
        const Report *r = &reports[i];
        size_t unknown = 0;
        for (size_t j = 0; j < r->unverified.count; ++j)
            unknown += r->unverified.items[j].size;
        printf("%s: %zu input objects with retained compiler assembly, "
               "%zu input objects with unverified contributions (%zu bytes).\n",
               region_labels[r->region], r->compiler_assembly_objects, r->unverified.count, unknown);
    }
}

static void json_string(FILE *file, const char *value)
{
    fputc('"', file);
    for (; *value; ++value) {
        unsigned char byte = (unsigned char)*value;
        if (byte == '\\' || byte == '"')
            fprintf(file, "\\%c", byte);
        else if (byte < 0x20)
            fprintf(file, "\\u%04x", byte);
        else
            fputc(byte, file);
    }
    fputc('"', file);
}

static void json_counts(FILE *file, const char *const *keys, const size_t *counts, size_t count)
{
    fputc('{', file);
    for (size_t i = 0; i < count; ++i)
        fprintf(file, "%s\"%s\":%zu", i ? "," : "", keys[i], counts[i]);
    fputc('}', file);
}

static void json_input_counts(FILE *file, InputCounts inputs)
{
    fputc('{', file);
    for (size_t i = 0; i < inputs.count; ++i) {
        if (i)
            fputc(',', file);
        json_string(file, inputs.items[i].name);
        fprintf(file, ":%zu", inputs.items[i].size);
    }
    fputc('}', file);
}

static void json_segments(FILE *file, const Report *report, bool bss)
{
    fputc('{', file);
    bool first = true;
    for (size_t i = 0; i < report->segments.count; ++i) {
        const Segment *segment = &report->segments.items[i];
        if (segment->bss != bss)
            continue;
        if (!first)
            fputc(',', file);
        first = false;
        json_string(file, segment->name);
        fputc(':', file);
        json_counts(file, data_keys, segment->counts, DATA_KINDS);
    }
    fputc('}', file);
}

static void json_relocations(FILE *file, const char *segment, const size_t *counts, bool *first)
{
    if (!*first)
        fputc(',', file);
    *first = false;
    json_string(file, segment);
    fputs(":{", file);
    bool first_type = true;
    for (size_t i = 0; i < LENGTH(reloc_types); ++i) {
        if (!counts[i])
            continue;
        fprintf(file, "%s\"%s\":%zu", first_type ? "" : ",", reloc_types[i].name, counts[i]);
        first_type = false;
    }
    fputc('}', file);
}

static const char *json_bool(bool value)
{
    return value ? "true" : "false";
}

static void write_json(const char *path, const Report *reports, size_t count)
{
    FILE *file = fopen(path, "wb");
    if (!file)
        fail("cannot write %s", path);
    fputs("[\n", file);
    for (size_t i = 0; i < count; ++i) {
        const Report *r = &reports[i];
        Verification v = r->verification;
        fprintf(file, "%s  {\"region\":\"%s\",\"elf\":", i ? ",\n" : "", regions[r->region]);
        json_string(file, r->elf);
        fputs(",\"build\":", file);
        json_string(file, r->build);
        fprintf(file, ",\n   \"verification\":{\"sha1\":\"%s\",\"expected_sha1\":\"%s\","
                      "\"sha1_match\":%s,\"elf_loads_match\":%s,\"baserom_match\":%s},\n   \"code\":",
                v.digest, v.expected, json_bool(v.hash_match), json_bool(v.loads_match),
                v.has_baserom ? json_bool(v.baserom_match) : "null");
        json_counts(file, code_keys, r->code, CODE_KINDS);
        fputs(",\n   \"data\":", file);
        json_segments(file, r, false);
        fputs(",\n   \"bss\":", file);
        json_segments(file, r, true);
        fprintf(file, ",\n   \"functions\":{\"c_cpp\":%zu,\"known_entries\":%zu},"
                      "\n   \"evidence\":{\"available_compiler_assembly_objects\":%zu,"
                      "\"linked_rom_input_bytes_checked\":%zu},\n   \"unverified_inputs\":",
                r->c_entries, r->known_entries, r->compiler_assembly_objects, r->bytes_checked);
        json_input_counts(file, r->unverified);
        fputs(",\n   \"unattributed_instructions\":", file);
        json_input_counts(file, r->unattributed);
        fputs(",\n   \"dynamic_linkage\":{\"linked_input_relocations\":{", file);
        bool first = true;
        json_relocations(file, ".text", r->text_relocations, &first);
        json_relocations(file, ".iwram", r->iwram_relocations, &first);
        for (size_t j = 0; j < r->segments.count; ++j) {
            const Segment *segment = &r->segments.items[j];
            if (!starts(segment->name, ".iwram:"))
                json_relocations(file, segment->name, segment->relocations, &first);
        }
        fputs("},\"explicit_lds_locations\":[", file);
        for (size_t j = 0; j < r->fixed_locations.count; ++j)
            fprintf(file, "%s\"0x%08X\"", j ? "," : "", r->fixed_locations.items[j]);
        fputs("],\"closed_coverage_bytes\":null}}", file);
    }
    fputs("\n]\n", file);
    if (ferror(file) || fclose(file))
        fail("cannot write %s", path);
}

static void release_report(Report report)
{
    for (size_t i = 0; i < report.segments.count; ++i)
        free(report.segments.items[i].name);
    for (size_t i = 0; i < report.unverified.count; ++i)
        free((void *)report.unverified.items[i].name);
    for (size_t i = 0; i < report.unattributed.count; ++i)
        free((void *)report.unattributed.items[i].name);
    free(report.unverified.items);
    free(report.unattributed.items);
    free(report.segments.items);
    free(report.fixed_locations.items);
    free(report.elf);
    free(report.build);
}

static void usage(void)
{
    puts("Usage: progress [jp us eu de] [--root DIR] [--json FILE]\n"
         "Report FoMT decompilation evidence from existing build artifacts.\n"
         "Run from the repository root or set --root. All four regions are the default.\n"
         "  --build DIR  Use this build directory for one selected region.\n"
         "  --elf FILE   Use this ELF and its companion map and ROM for one region.\n"
         "  --json FILE  Also write machine-readable results to FILE.");
}

int main(int argc, char **argv)
{
    const char *root = ".", *json = NULL, *build = NULL, *elf = NULL;
    int selected[LENGTH(regions)];
    size_t count = 0;
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
            usage();
            return EXIT_SUCCESS;
        }
        const char **option = NULL;
        if (strcmp(argv[i], "--root") == 0)
            option = &root;
        else if (strcmp(argv[i], "--json") == 0)
            option = &json;
        else if (strcmp(argv[i], "--build") == 0)
            option = &build;
        else if (strcmp(argv[i], "--elf") == 0)
            option = &elf;
        if (option) {
            if (i + 1 == argc)
                fail("missing value for %s", argv[i]);
            *option = argv[++i];
            continue;
        }
        size_t region = 0;
        while (region < LENGTH(regions) && strcmp(argv[i], regions[region]) != 0)
            ++region;
        if (region == LENGTH(regions))
            fail("unknown argument %s (see --help)", argv[i]);
        for (size_t j = 0; j < count; ++j) {
            if (selected[j] == (int)region)
                fail("duplicate region %s", argv[i]);
        }
        selected[count++] = (int)region;
    }
    if ((build || elf) && count != 1)
        fail("--build and --elf each require one selected region");
    if (!count) {
        for (; count < LENGTH(regions); ++count)
            selected[count] = (int)count;
    }

    Report reports[LENGTH(regions)];
    bool verified = true;
    for (size_t i = 0; i < count; ++i) {
        reports[i] = report_region(root, selected[i], build, elf);
        verified &= rom_verified(reports[i].verification);
    }
    print_report(reports, count);
    if (json)
        write_json(json, reports, count);
    for (size_t i = 0; i < count; ++i)
        release_report(reports[i]);
    release_source_cache();
    return verified ? EXIT_SUCCESS : EXIT_FAILURE;
}
