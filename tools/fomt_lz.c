// FoMT's native Raw-LZ2/Raw-LZ3 and Huffman-8/LZ3 stream codec. The 0x70 header is a stream header,
// not a graphics format or a filename extension. Bit words are little-endian
// while bits within each word are read most-significant first.
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *data;
    size_t size;
    size_t capacity;
    uint32_t word;
    unsigned used;
} BitWriter;

typedef struct {
    unsigned char const *data;
    size_t size;
    size_t offset;
    uint32_t word;
    unsigned remaining;
} BitReader;

typedef struct {
    unsigned start;
    unsigned width;
} LadderEntry;

typedef struct {
    int child[2];
    int symbol;
} HuffNode;

typedef struct {
    unsigned code[256];
    unsigned bits[256];
    unsigned count[16];
} HuffModel;

typedef struct {
    uint64_t frequency;
    unsigned serial;
    int left;
    int right;
    int symbol;
} HuffBuildNode;

static void fail(char const *message)
{
    fprintf(stderr, "fomt-lz: %s\n", message);
    exit(EXIT_FAILURE);
}

static void reserve(BitWriter *writer, size_t additional)
{
    size_t needed = writer->size + additional;
    if (needed <= writer->capacity)
        return;
    size_t capacity = writer->capacity ? writer->capacity : 64;
    while (capacity < needed) {
        if (capacity > SIZE_MAX / 2)
            fail("encoded stream is too large");
        capacity *= 2;
    }
    unsigned char *data = realloc(writer->data, capacity);
    if (!data)
        fail("out of memory");
    writer->data = data;
    writer->capacity = capacity;
}

static void emit_word(BitWriter *writer)
{
    reserve(writer, 4);
    for (unsigned index = 0; index < 4; index++)
        writer->data[writer->size++] = (unsigned char)(writer->word >> (index * 8));
    writer->word = 0;
    writer->used = 0;
}

static void write_bits(BitWriter *writer, uint32_t value, unsigned count)
{
    if (count > 32 || (count < 32 && (value >> count) != 0))
        fail("value does not fit in the stream field");
    for (unsigned bit = count; bit > 0; bit--) {
        writer->word |= ((value >> (bit - 1)) & 1u) << (31 - writer->used);
        if (++writer->used == 32)
            emit_word(writer);
    }
}

static void finish_bits(BitWriter *writer)
{
    if (writer->used)
        emit_word(writer);
}

static int read_bits(BitReader *reader, unsigned count, uint32_t *value)
{
    if (count > 32)
        return 0;
    *value = 0;
    for (unsigned bit = 0; bit < count; bit++) {
        if (!reader->remaining) {
            if (reader->offset + 4 > reader->size)
                return 0;
            reader->word = 0;
            for (unsigned index = 0; index < 4; index++)
                reader->word |= (uint32_t)reader->data[reader->offset++] << (index * 8);
            reader->remaining = 32;
        }
        *value = (*value << 1) | ((reader->word >> (--reader->remaining)) & 1u);
    }
    return 1;
}

static unsigned parse_width(char const **cursor)
{
    char *end;
    errno = 0;
    unsigned long value = strtoul(*cursor, &end, 10);
    if (errno || end == *cursor || value < 1 || value > 16)
        fail("ladder widths must be in 1..16");
    *cursor = end;
    return (unsigned)value;
}

static void parse_ladder(char const *spec, LadderEntry *entries, unsigned count)
{
    char const *cursor = spec;
    unsigned start = 1;
    int compact = strlen(spec) == count;
    for (unsigned index = 0; index < count && compact; index++)
        if (spec[index] < '1' || spec[index] > '9')
            compact = 0;
    if (compact) {
        for (unsigned index = 0; index < count; index++) {
            entries[index].start = start;
            entries[index].width = (unsigned)(spec[index] - '0');
            start += 1u << entries[index].width;
        }
        return;
    }
    for (unsigned index = 0; index < count; index++) {
        entries[index].start = start;
        entries[index].width = parse_width(&cursor);
        start += 1u << entries[index].width;
        if (index + 1 < count) {
            if (*cursor++ != ',')
                fail("expected comma-separated ladder widths");
        } else if (*cursor) {
            fail("unexpected text after the ladder widths");
        }
    }
}

static unsigned parse_size(char const *text)
{
    char *end;
    errno = 0;
    unsigned long value = strtoul(text, &end, 0);
    if (errno || end == text || *end || value > 0x40000)
        fail("invalid slot size");
    return (unsigned)value;
}

static unsigned char *read_file(char const *path, size_t *size)
{
    FILE *file = fopen(path, "rb");
    if (!file)
        fail("cannot open input file");
    if (fseek(file, 0, SEEK_END) != 0)
        fail("cannot seek input file");
    long length = ftell(file);
    if (length < 0 || fseek(file, 0, SEEK_SET) != 0)
        fail("cannot size input file");
    *size = (size_t)length;
    unsigned char *data = malloc(*size ? *size : 1);
    if (!data)
        fail("out of memory");
    size_t read = fread(data, 1, *size, file);
    int closed = fclose(file);
    if (read != *size || closed != 0)
        fail("cannot read input file");
    return data;
}

static unsigned char *read_file_parts(char const *first_path,
                                       char const *second_path, size_t *size)
{
    unsigned char *first = read_file(first_path, size);
    if (!second_path)
        return first;
    size_t second_size;
    unsigned char *second = read_file(second_path, &second_size);
    if (second_size > SIZE_MAX - *size)
        fail("combined source is too large");
    unsigned char *combined = realloc(first, *size + second_size);
    if (!combined)
        fail("out of memory");
    memcpy(combined + *size, second, second_size);
    *size += second_size;
    free(second);
    return combined;
}

static void write_file(char const *path, unsigned char const *data, size_t size)
{
    FILE *file = fopen(path, "wb");
    if (!file)
        fail("cannot create output file");
    size_t written = fwrite(data, 1, size, file);
    int closed = fclose(file);
    if (written != size || closed != 0)
        fail("cannot write output file");
}

static void write_vli_bits(BitWriter *writer, unsigned value, unsigned atom_bits)
{
    unsigned digits[16];
    unsigned count = 0;
    unsigned digit_bits = atom_bits - 1;
    unsigned mask = (1u << digit_bits) - 1;
    do {
        digits[count++] = value & mask;
        value >>= digit_bits;
    } while (value);
    for (unsigned index = count; index > 0; index--)
        write_bits(writer, (digits[index - 1] << 1) | (index > 1), atom_bits);
}

static void write_vli(BitWriter *writer, unsigned value)
{
    write_vli_bits(writer, value, 3);
}

static unsigned longest_match(unsigned char const *data, size_t size,
                              size_t position, unsigned max_distance,
                              unsigned *best_distance)
{
    unsigned best_length = 0;
    unsigned limit = (unsigned)(position / 2);
    if (limit > max_distance)
        limit = max_distance;
    *best_distance = 0;
    for (unsigned distance = 1; distance <= limit; distance++) {
        size_t candidate = position - 2 * distance;
        unsigned length = 0;
        while (position + length < size &&
               data[candidate + length] == data[position + length])
            length++;
        length &= ~1u;
        if (length > best_length) {
            best_length = length;
            *best_distance = distance;
            if (best_length == size - position)
                break;
        }
    }
    return best_length;
}

static unsigned char *encode_lz3(unsigned char const *source, size_t size,
                                 LadderEntry const ladder[3], size_t *packed_size)
{
    if (!size || size > 0x40000 || (size & 1))
        fail("Raw-LZ3 source size must be even and in 2..0x40000");
    BitWriter writer = {0};
    write_bits(&writer, 3, 8); // raw atoms, LZ mode 3, no differential filter
    for (unsigned index = 0; index < 3; index++)
        write_bits(&writer, ladder[index].width - 1, 4);
    unsigned max_distance = ladder[2].start + (1u << ladder[2].width) - 1;
    size_t position = 0;
    while (position < size) {
        unsigned distance;
        unsigned pairs = longest_match(source, size, position, max_distance, &distance) / 2;
        if (pairs < 2) {
            unsigned literal_pairs = 1;
            size_t probe = position + 2;
            while (probe < size) {
                unsigned probe_distance;
                if (longest_match(source, size, probe, max_distance,
                                  &probe_distance) / 2 >= 2)
                    break;
                literal_pairs++;
                probe += 2;
            }
            if (literal_pairs > 8) {
                write_bits(&writer, 1, 1);
                write_bits(&writer, 3, 2);
                write_vli(&writer, literal_pairs - 1);
                write_bits(&writer, 0, 1);
                for (unsigned index = 0; index < literal_pairs; index++) {
                    write_bits(&writer, source[position] << 8 | source[position + 1], 16);
                    position += 2;
                }
            } else {
                write_bits(&writer, 0, 1);
                write_bits(&writer, source[position] << 8 | source[position + 1], 16);
                position += 2;
            }
            continue;
        }
        unsigned index = 0;
        while (index < 3 && distance >= ladder[index].start + (1u << ladder[index].width))
            index++;
        if (index == 3)
            fail("match distance exceeds the declared ladder");
        write_bits(&writer, 1, 1);
        if (pairs >= 10) {
            write_bits(&writer, 3, 2);
            write_vli(&writer, (pairs - 2) >> 3);
            write_bits(&writer, 1, 1);
            write_bits(&writer, index, 2);
            write_bits(&writer, distance - ladder[index].start, ladder[index].width);
            write_bits(&writer, (pairs - 2) & 7, 3);
        } else {
            write_bits(&writer, index, 2);
            write_bits(&writer, distance - ladder[index].start, ladder[index].width);
            write_bits(&writer, pairs - 2, 3);
        }
        position += 2 * pairs;
    }
    finish_bits(&writer);
    *packed_size = writer.size + 4;
    unsigned char *packed = malloc(*packed_size);
    if (!packed)
        fail("out of memory");
    uint32_t header = ((uint32_t)size << 8) | 0x70;
    for (unsigned index = 0; index < 4; index++)
        packed[index] = (unsigned char)(header >> (index * 8));
    memcpy(packed + 4, writer.data, writer.size);
    free(writer.data);
    return packed;
}

static unsigned longest_match_lz2(unsigned char const *data, size_t size,
                                  size_t position, unsigned max_distance,
                                  unsigned *best_distance)
{
    unsigned best_length = 0;
    unsigned limit = (unsigned)position;
    if (limit > max_distance)
        limit = max_distance;
    *best_distance = 0;
    for (unsigned distance = 1; distance <= limit; distance++) {
        unsigned length = 0;
        while (position + length < size &&
               data[position + length] == data[position + length - distance])
            length++;
        if (length > best_length) {
            best_length = length;
            *best_distance = distance;
            if (best_length == size - position)
                break;
        }
    }
    return best_length;
}

static unsigned char *encode_lz1(unsigned char const *source, size_t size,
                                 LadderEntry const ladder[4], size_t *packed_size)
{
    if (!size || size > 0x40000)
        fail("Raw-LZ1 source size must be in 1..0x40000");
    BitWriter writer = {0};
    write_bits(&writer, 1, 8); // raw atoms, LZ mode 1, no differential filter
    for (unsigned index = 0; index < 4; index++)
        write_bits(&writer, ladder[index].width - 1, 4);
    unsigned max_distance = ladder[3].start + (1u << ladder[3].width) - 1;
    size_t position = 0;
    while (position < size) {
        unsigned distance;
        unsigned length = longest_match_lz2(source, size, position,
                                             max_distance, &distance);
        if (length < 3) {
            write_bits(&writer, 0, 1);
            write_bits(&writer, source[position++], 8);
            continue;
        }
        if (length > 18)
            length = 18;
        unsigned index = 0;
        while (index < 4 && distance >= ladder[index].start + (1u << ladder[index].width))
            index++;
        if (index == 4)
            fail("Raw-LZ1 match distance exceeds the ladder");
        write_bits(&writer, 1, 1);
        write_bits(&writer, index, 2);
        write_bits(&writer, distance - ladder[index].start, ladder[index].width);
        write_bits(&writer, length - 3, 4);
        position += length;
    }
    finish_bits(&writer);
    *packed_size = writer.size + 4;
    unsigned char *packed = malloc(*packed_size);
    if (!packed)
        fail("out of memory");
    uint32_t header = ((uint32_t)size << 8) | 0x70;
    for (unsigned index = 0; index < 4; index++)
        packed[index] = (unsigned char)(header >> (index * 8));
    memcpy(packed + 4, writer.data, writer.size);
    free(writer.data);
    return packed;
}

static unsigned char *encode_lz2(unsigned char const *source, size_t size,
                                 LadderEntry const ladder[7], int literal_tail,
                                 unsigned literal_threshold,
                                 size_t *packed_size)
{
    if (!size || size > 0x40000)
        fail("Raw-LZ2 source size must be in 1..0x40000");
    BitWriter writer = {0};
    write_bits(&writer, 2, 8); // raw atoms, LZ mode 2, no differential filter
    for (unsigned index = 0; index < 7; index++)
        write_bits(&writer, ladder[index].width - 1, 4);
    unsigned max_distance = ladder[6].start + (1u << ladder[6].width) - 1;
    size_t position = 0;
    while (position < size) {
        unsigned distance;
        unsigned length = longest_match_lz2(source, size, position,
                                             max_distance, &distance);
        if (length < 3) {
            unsigned run = 1;
            size_t probe = position + 1;
            while (probe < size) {
                unsigned probe_distance;
                unsigned probe_length = longest_match_lz2(source, size, probe,
                                                           max_distance,
                                                           &probe_distance);
                if (probe_length >= 3) {
                    // Some retail streams keep a final three-byte match in
                    // the preceding extended literal instead of emitting a
                    // separate lookup. This is a reusable encoder strategy,
                    // selected explicitly for streams that use it.
                    if (literal_tail && probe_length == 3 &&
                        probe + probe_length == size) {
                        run += probe_length;
                        probe += probe_length;
                    }
                    break;
                }
                run++;
                probe++;
            }
            if (run >= literal_threshold) {
                write_bits(&writer, 1, 1);
                write_bits(&writer, 7, 3);
                write_vli_bits(&writer, run - 1, 4);
                write_bits(&writer, 0, 1);
                for (unsigned index = 0; index < run; index++)
                    write_bits(&writer, source[position++], 8);
            } else {
                write_bits(&writer, 0, 1);
                write_bits(&writer, source[position++], 8);
            }
            continue;
        }
        unsigned index = 0;
        while (index < 7 && distance >= ladder[index].start + (1u << ladder[index].width))
            index++;
        if (index == 7)
            fail("Raw-LZ2 match distance exceeds the ladder");
        write_bits(&writer, 1, 1);
        if (length >= 19) {
            write_bits(&writer, 7, 3);
            write_vli_bits(&writer, (length - 3) >> 4, 4);
            write_bits(&writer, 1, 1);
            write_bits(&writer, index, 3);
            write_bits(&writer, distance - ladder[index].start, ladder[index].width);
            write_bits(&writer, (length - 3) & 15, 4);
        } else {
            write_bits(&writer, index, 3);
            write_bits(&writer, distance - ladder[index].start, ladder[index].width);
            write_bits(&writer, length - 3, 4);
        }
        position += length;
    }
    finish_bits(&writer);
    *packed_size = writer.size + 4;
    unsigned char *packed = malloc(*packed_size);
    if (!packed)
        fail("out of memory");
    uint32_t header = ((uint32_t)size << 8) | 0x70;
    for (unsigned index = 0; index < 4; index++)
        packed[index] = (unsigned char)(header >> (index * 8));
    memcpy(packed + 4, writer.data, writer.size);
    free(writer.data);
    return packed;
}

static unsigned read_vli_bits(BitReader *reader, unsigned atom_bits)
{
    unsigned value = 0;
    uint32_t atom;
    do {
        if (!read_bits(reader, atom_bits, &atom) || value > 0x40000)
            fail("truncated or oversized variable-length integer");
        value = (value << (atom_bits - 1)) | (atom >> 1);
    } while (atom & 1);
    return value;
}

static unsigned read_vli(BitReader *reader)
{
    return read_vli_bits(reader, 3);
}

static unsigned char *decode_lz3(unsigned char const *packed, size_t packed_size,
                                 LadderEntry ladder[3], size_t *decoded_size)
{
    if (packed_size < 8 || packed[0] != 0x70)
        fail("not a FoMT native 0x70 stream");
    *decoded_size = (size_t)packed[1] | ((size_t)packed[2] << 8)
                  | ((size_t)packed[3] << 16);
    if (!*decoded_size || *decoded_size > 0x40000 || (*decoded_size & 1))
        fail("invalid Raw-LZ3 decoded size");
    BitReader reader = {packed, packed_size, 4, 0, 0};
    uint32_t value;
    if (!read_bits(&reader, 8, &value) || value != 3)
        fail("this codec requires raw atoms, LZ mode 3 and no filter");
    unsigned start = 1;
    for (unsigned index = 0; index < 3; index++) {
        if (!read_bits(&reader, 4, &value))
            fail("truncated LZ3 ladder");
        ladder[index].start = start;
        ladder[index].width = value + 1;
        start += 1u << ladder[index].width;
    }
    unsigned char *output = malloc(*decoded_size);
    if (!output)
        fail("out of memory");
    size_t written = 0;
    while (written < *decoded_size) {
        if (!read_bits(&reader, 1, &value))
            fail("truncated LZ3 command");
        unsigned pairs = 1;
        unsigned distance = 0;
        if (value) {
            if (!read_bits(&reader, 2, &value))
                fail("truncated LZ3 command type");
            unsigned index = value;
            if (index == 3) {
                unsigned count = read_vli(&reader);
                if (!read_bits(&reader, 1, &value))
                    fail("truncated extended LZ3 command");
                if (!value) {
                    pairs = count + 1;
                } else {
                    if (!read_bits(&reader, 2, &value) || value == 3)
                        fail("invalid extended LZ3 ladder index");
                    index = value;
                    if (!read_bits(&reader, ladder[index].width, &value))
                        fail("truncated extended LZ3 distance");
                    distance = ladder[index].start + value;
                    if (!read_bits(&reader, 3, &value))
                        fail("truncated extended LZ3 length");
                    pairs = (count << 3) + value + 2;
                }
            } else {
                if (!read_bits(&reader, ladder[index].width, &value))
                    fail("truncated LZ3 distance");
                distance = ladder[index].start + value;
                if (!read_bits(&reader, 3, &value))
                    fail("truncated LZ3 length");
                pairs = value + 2;
            }
        }
        if (pairs > (*decoded_size - written) / 2)
            fail("LZ3 command exceeds decoded size");
        if (distance) {
            if (distance > written / 2)
                fail("LZ3 lookup precedes decoded data");
            for (unsigned byte = 0; byte < pairs * 2; byte++) {
                output[written] = output[written - distance * 2];
                written++;
            }
        } else {
            for (unsigned byte = 0; byte < pairs * 2; byte++) {
                if (!read_bits(&reader, 8, &value))
                    fail("truncated LZ3 literal");
                output[written++] = (unsigned char)value;
            }
        }
    }
    return output;
}

static int add_huff_node(HuffNode nodes[512], unsigned *count, int symbol)
{
    if (*count >= 512)
        fail("Huffman-8 tree has too many nodes");
    unsigned index = (*count)++;
    nodes[index].child[0] = -1;
    nodes[index].child[1] = -1;
    nodes[index].symbol = symbol;
    return (int)index;
}

static void read_huff_tree(BitReader *reader, HuffNode nodes[512],
                           unsigned *node_count, unsigned symbol_bits)
{
    *node_count = 0;
    add_huff_node(nodes, node_count, -1);
    unsigned path = 0;
    for (unsigned depth = 0; depth < symbol_bits * 2; depth++) {
        uint32_t count;
        if (!read_bits(reader, symbol_bits, &count))
            fail("truncated Huffman-8 tree count");
        path <<= 1;
        for (unsigned entry = 0; entry < count; entry++) {
            if (path >= (1u << (depth + 1)))
                fail("Huffman-8 code exceeds its declared depth");
            int node = 0;
            for (unsigned step = 0; step < depth; step++) {
                unsigned branch = (path >> (depth - step)) & 1u;
                if (nodes[node].child[branch] == -1)
                    nodes[node].child[branch] = add_huff_node(nodes, node_count, -1);
                node = nodes[node].child[branch];
                if (nodes[node].symbol != -1)
                    fail("Huffman-8 tree has a code beneath a leaf");
            }
            unsigned branch = path & 1u;
            uint32_t symbol;
            if (!read_bits(reader, symbol_bits, &symbol))
                fail("truncated Huffman-8 tree symbol");
            if (nodes[node].child[branch] != -1)
                fail("Huffman-8 tree repeats a code");
            nodes[node].child[branch] = add_huff_node(nodes, node_count, (int)symbol);
            path++;
        }
    }
    for (unsigned index = 0; index < *node_count; index++) {
        if (nodes[index].symbol == -1 &&
            (nodes[index].child[0] == -1 || nodes[index].child[1] == -1))
            fail("Huffman-8 tree is incomplete");
    }
}

static unsigned read_huff_symbol(BitReader *reader, HuffNode const nodes[512])
{
    int node = 0;
    for (unsigned depth = 0; depth < 17; depth++) {
        if (nodes[node].symbol != -1)
            return (unsigned)nodes[node].symbol;
        uint32_t branch;
        if (!read_bits(reader, 1, &branch))
            fail("truncated Huffman-8 literal");
        node = nodes[node].child[branch];
        if (node < 0)
            fail("invalid Huffman-8 code");
    }
    fail("Huffman-8 code exceeds the maximum length");
    return 0;
}

static unsigned char *decode_huff_lz3(unsigned char const *packed, size_t packed_size,
                                      LadderEntry ladder[3], size_t *decoded_size,
                                      unsigned symbol_bits)
{
    if (packed_size < 8 || packed[0] != 0x70)
        fail("not a FoMT native 0x70 stream");
    *decoded_size = (size_t)packed[1] | ((size_t)packed[2] << 8)
                  | ((size_t)packed[3] << 16);
    if (!*decoded_size || *decoded_size > 0x40000 || (*decoded_size & 1))
        fail("invalid Huffman/LZ3 decoded size");
    BitReader reader = {packed, packed_size, 4, 0, 0};
    uint32_t value;
    if (!read_bits(&reader, 8, &value) ||
        value != (symbol_bits == 4 ? 0x0Bu : 0x13u))
        fail("stream format is not the requested Huffman/LZ3 codec");
    HuffNode nodes[512];
    unsigned node_count;
    read_huff_tree(&reader, nodes, &node_count, symbol_bits);
    unsigned start = 1;
    for (unsigned index = 0; index < 3; index++) {
        if (!read_bits(&reader, 4, &value))
            fail("truncated Huffman-8/LZ3 ladder");
        ladder[index].start = start;
        ladder[index].width = value + 1;
        start += 1u << ladder[index].width;
    }
    unsigned char *output = malloc(*decoded_size);
    if (!output)
        fail("out of memory");
    size_t written = 0;
    while (written < *decoded_size) {
        if (!read_bits(&reader, 1, &value))
            fail("truncated Huffman-8/LZ3 command");
        unsigned pairs = 1;
        unsigned distance = 0;
        if (value) {
            if (!read_bits(&reader, 2, &value))
                fail("truncated Huffman-8/LZ3 command type");
            unsigned index = value;
            if (index == 3) {
                unsigned count = read_vli(&reader);
                if (!read_bits(&reader, 1, &value))
                    fail("truncated extended Huffman-8/LZ3 command");
                if (!value) {
                    pairs = count + 1;
                } else {
                    if (!read_bits(&reader, 2, &value) || value == 3)
                        fail("invalid extended Huffman-8/LZ3 ladder index");
                    index = value;
                    if (!read_bits(&reader, ladder[index].width, &value))
                        fail("truncated extended Huffman-8/LZ3 distance");
                    distance = ladder[index].start + value;
                    if (!read_bits(&reader, 3, &value))
                        fail("truncated extended Huffman-8/LZ3 length");
                    pairs = (count << 3) + value + 2;
                }
            } else {
                if (!read_bits(&reader, ladder[index].width, &value))
                    fail("truncated Huffman-8/LZ3 distance");
                distance = ladder[index].start + value;
                if (!read_bits(&reader, 3, &value))
                    fail("truncated Huffman-8/LZ3 length");
                pairs = value + 2;
            }
        }
        if (pairs > (*decoded_size - written) / 2)
            fail("Huffman-8/LZ3 command exceeds decoded size");
        if (distance) {
            if (distance > written / 2)
                fail("Huffman-8/LZ3 lookup precedes decoded data");
            for (unsigned byte = 0; byte < pairs * 2; byte++) {
                output[written] = output[written - distance * 2];
                written++;
            }
        } else {
            for (unsigned byte = 0; byte < pairs * 2; byte++) {
                unsigned atom = read_huff_symbol(&reader, nodes);
                if (symbol_bits == 4)
                    atom = (atom << 4) | read_huff_symbol(&reader, nodes);
                output[written++] = (unsigned char)atom;
            }
        }
    }
    return output;
}

static unsigned char *decode_huff8_lz3(unsigned char const *packed, size_t packed_size,
                                       LadderEntry ladder[3], size_t *decoded_size)
{
    return decode_huff_lz3(packed, packed_size, ladder, decoded_size, 8);
}

static int huff_build_less(HuffBuildNode const *nodes, int left, int right)
{
    if (nodes[left].frequency != nodes[right].frequency)
        return nodes[left].frequency < nodes[right].frequency;
    return nodes[left].serial < nodes[right].serial;
}

static void huff_assign_depths(HuffBuildNode const *nodes, int node,
                               unsigned depth, unsigned lengths[256])
{
    if (nodes[node].symbol >= 0) {
        lengths[nodes[node].symbol] = depth;
        return;
    }
    huff_assign_depths(nodes, nodes[node].left, depth + 1, lengths);
    huff_assign_depths(nodes, nodes[node].right, depth + 1, lengths);
}

static void huff_balanced_lengths(uint64_t const frequency[256],
                                  unsigned lengths[256], unsigned count,
                                  unsigned symbol_bits)
{
    unsigned symbols[256];
    unsigned total = 0;
    for (unsigned symbol = 0; symbol < 256; symbol++) {
        if (!frequency[symbol])
            continue;
        unsigned position = total++;
        while (position &&
               (frequency[symbols[position - 1]] < frequency[symbol] ||
                (frequency[symbols[position - 1]] == frequency[symbol] &&
                 symbols[position - 1] > symbol))) {
            symbols[position] = symbols[position - 1];
            position--;
        }
        symbols[position] = symbol;
    }
    if (total != count || count < 2)
        fail("invalid Huffman alphabet");
    if (count == (1u << symbol_bits)) {
        lengths[symbols[0]] = symbol_bits - 1;
        for (unsigned index = 1; index < count - 2; index++)
            lengths[symbols[index]] = symbol_bits;
        lengths[symbols[count - 2]] = symbol_bits + 1;
        lengths[symbols[count - 1]] = symbol_bits + 1;
        return;
    }
    unsigned shallow = 0;
    while ((1u << (shallow + 1)) <= count)
        shallow++;
    unsigned shallow_count = (1u << (shallow + 1)) - count;
    for (unsigned index = 0; index < count; index++)
        lengths[symbols[index]] = shallow + (index >= shallow_count);
}

static void huff_model(unsigned char const *data, size_t size, HuffModel *model,
                       unsigned symbol_bits)
{
    if (!size)
        fail("Huffman literal stream is empty");
    unsigned alphabet_size = 1u << symbol_bits;
    uint64_t frequency[256] = {0};
    unsigned order[256];
    unsigned count = 0;
    for (size_t index = 0; index < size; index++) {
        unsigned symbol = data[index];
        if (symbol >= alphabet_size)
            fail("Huffman symbol exceeds its alphabet");
        if (!frequency[symbol])
            order[count++] = symbol;
        frequency[symbol]++;
    }
    if (count == 1) {
        unsigned extra = (order[0] + 1) & (alphabet_size - 1);
        frequency[extra] = 1;
        order[count++] = extra;
    }
    HuffBuildNode nodes[512];
    int active[512];
    unsigned node_count = 0;
    unsigned active_count = 0;
    for (unsigned index = 0; index < count; index++) {
        unsigned symbol = order[index];
        nodes[node_count] = (HuffBuildNode){frequency[symbol], node_count, -1, -1, (int)symbol};
        active[active_count++] = (int)node_count++;
    }
    while (active_count > 1) {
        unsigned first = 0;
        for (unsigned index = 1; index < active_count; index++)
            if (huff_build_less(nodes, active[index], active[first]))
                first = index;
        int left = active[first];
        active[first] = active[--active_count];
        unsigned second = 0;
        for (unsigned index = 1; index < active_count; index++)
            if (huff_build_less(nodes, active[index], active[second]))
                second = index;
        int right = active[second];
        active[second] = active[--active_count];
        nodes[node_count] = (HuffBuildNode){
            nodes[left].frequency + nodes[right].frequency, node_count,
            left, right, -1
        };
        active[active_count++] = (int)node_count++;
    }
    unsigned lengths[256] = {0};
    huff_assign_depths(nodes, active[0], 0, lengths);
    unsigned by_length[16] = {0};
    int fallback = 0;
    for (unsigned symbol = 0; symbol < alphabet_size; symbol++) {
        if (!lengths[symbol])
            continue;
        if (lengths[symbol] > symbol_bits * 2) {
            fallback = 1;
            break;
        }
        by_length[lengths[symbol] - 1]++;
    }
    for (unsigned length = 0; length < symbol_bits * 2; length++)
        if (by_length[length] >= alphabet_size)
            fallback = 1;
    if (fallback) {
        memset(lengths, 0, sizeof(lengths));
        huff_balanced_lengths(frequency, lengths, count, symbol_bits);
    }
    memset(model, 0, sizeof(*model));
    unsigned code = 0;
    for (unsigned length = 1; length <= symbol_bits * 2; length++) {
        code <<= 1;
        for (unsigned symbol = 0; symbol < alphabet_size; symbol++) {
            if (lengths[symbol] != length)
                continue;
            model->code[symbol] = code++;
            model->bits[symbol] = length;
            model->count[length - 1]++;
        }
        if (model->count[length - 1] >= alphabet_size)
            fail("Huffman depth count exceeds its native field");
    }
}

static int huff_model_equal(HuffModel const *left, HuffModel const *right)
{
    return memcmp(left, right, sizeof(*left)) == 0;
}

static void write_huff_tree(BitWriter *writer, HuffModel const *model,
                            unsigned symbol_bits)
{
    for (unsigned length = 1; length <= symbol_bits * 2; length++) {
        write_bits(writer, model->count[length - 1], symbol_bits);
        for (unsigned symbol = 0; symbol < (1u << symbol_bits); symbol++)
            if (model->bits[symbol] == length)
                write_bits(writer, symbol, symbol_bits);
    }
}

typedef struct {
    unsigned pairs[3];
    unsigned distance[3];
} Lz3Matches;

typedef struct {
    uint64_t cost;
    unsigned source;
    unsigned end;
    unsigned index;
    unsigned distance;
    size_t next;
} Lz3Range;

typedef struct {
    unsigned kind;
    unsigned pairs;
    unsigned index;
    unsigned distance;
} Lz3Operation;

typedef struct {
    Lz3Range *ranges;
    size_t range_count;
    size_t range_capacity;
    size_t *pending;
    size_t *heap;
    size_t heap_count;
    size_t heap_capacity;
} Lz3Planner;

static uint32_t lz3_key(unsigned char const *source)
{
    return (uint32_t)source[0] | ((uint32_t)source[1] << 8) |
           ((uint32_t)source[2] << 16) | ((uint32_t)source[3] << 24);
}

static unsigned lz3_hash(uint32_t key)
{
    key ^= key >> 16;
    key *= 0x7FEB352Du;
    return (key ^ (key >> 15)) & 0xFFFFu;
}

static Lz3Matches *precompute_lz3_matches(unsigned char const *source, size_t size,
                                           LadderEntry const ladder[3],
                                           unsigned candidate_limit)
{
    size_t pair_count = size / 2;
    Lz3Matches *matches = calloc(pair_count, sizeof(*matches));
    int *previous = malloc(pair_count * sizeof(*previous));
    int *heads = malloc(65536 * sizeof(*heads));
    if (!matches || !previous || !heads)
        fail("out of memory");
    for (unsigned index = 0; index < 65536; index++)
        heads[index] = -1;
    unsigned maximum_distance = ladder[2].start + (1u << ladder[2].width) - 1;
    for (size_t pair = 0; pair < pair_count; pair++) {
        previous[pair] = -1;
        if (pair + 1 == pair_count)
            continue;
        size_t position = pair * 2;
        uint32_t key = lz3_key(source + position);
        unsigned bucket = lz3_hash(key);
        unsigned candidates = 0;
        for (int candidate = heads[bucket]; candidate >= 0; candidate = previous[candidate]) {
            unsigned distance = (unsigned)(pair - (size_t)candidate);
            if (distance > maximum_distance)
                break;
            if (lz3_key(source + (size_t)candidate * 2) != key)
                continue;
            if (++candidates > candidate_limit)
                break;
            size_t lower = 0;
            size_t upper = size - position;
            while (lower < upper) {
                size_t probe = lower + (upper - lower + 1) / 2;
                if (memcmp(source + (size_t)candidate * 2,
                           source + position, probe) == 0)
                    lower = probe;
                else
                    upper = probe - 1;
            }
            unsigned pairs = (unsigned)(lower / 2);
            if (pairs < 2)
                continue;
            for (unsigned index = 0; index < 3; index++) {
                if (distance < ladder[index].start + (1u << ladder[index].width)) {
                    if (pairs > matches[pair].pairs[index]) {
                        matches[pair].pairs[index] = pairs;
                        matches[pair].distance[index] = distance;
                    }
                    break;
                }
            }
        }
        previous[pair] = heads[bucket];
        heads[bucket] = (int)pair;
    }
    free(heads);
    free(previous);
    return matches;
}

static int lz3_range_less(Lz3Range const *ranges, size_t left, size_t right)
{
    Lz3Range const *a = &ranges[left];
    Lz3Range const *b = &ranges[right];
    if (a->cost != b->cost)
        return a->cost < b->cost;
    if (a->source != b->source)
        return a->source < b->source;
    if (a->index != b->index)
        return a->index < b->index;
    if (a->distance != b->distance)
        return a->distance < b->distance;
    return a->end < b->end;
}

static void lz3_heap_push(Lz3Planner *planner, size_t range)
{
    if (planner->heap_count == planner->heap_capacity) {
        size_t capacity = planner->heap_capacity ? planner->heap_capacity * 2 : 64;
        size_t *grown = realloc(planner->heap, capacity * sizeof(*grown));
        if (!grown)
            fail("out of memory");
        planner->heap = grown;
        planner->heap_capacity = capacity;
    }
    size_t position = planner->heap_count++;
    while (position) {
        size_t parent = (position - 1) / 2;
        if (!lz3_range_less(planner->ranges, range, planner->heap[parent]))
            break;
        planner->heap[position] = planner->heap[parent];
        position = parent;
    }
    planner->heap[position] = range;
}

static void lz3_heap_pop(Lz3Planner *planner)
{
    size_t replacement = planner->heap[--planner->heap_count];
    if (!planner->heap_count)
        return;
    size_t position = 0;
    while (position * 2 + 1 < planner->heap_count) {
        size_t child = position * 2 + 1;
        if (child + 1 < planner->heap_count &&
            lz3_range_less(planner->ranges, planner->heap[child + 1],
                           planner->heap[child]))
            child++;
        if (!lz3_range_less(planner->ranges, planner->heap[child], replacement))
            break;
        planner->heap[position] = planner->heap[child];
        position = child;
    }
    planner->heap[position] = replacement;
}

static void lz3_schedule(Lz3Planner *planner, unsigned source,
                          unsigned start, unsigned end, unsigned pair_count,
                          uint64_t cost, unsigned index, unsigned distance)
{
    if (start < source + 2)
        start = source + 2;
    if (end > pair_count)
        end = pair_count;
    if (start > end)
        return;
    if (planner->range_count == planner->range_capacity) {
        size_t capacity = planner->range_capacity ? planner->range_capacity * 2 : 1024;
        Lz3Range *grown = realloc(planner->ranges, capacity * sizeof(*grown));
        if (!grown)
            fail("out of memory");
        planner->ranges = grown;
        planner->range_capacity = capacity;
    }
    size_t record = planner->range_count++;
    planner->ranges[record] = (Lz3Range){
        cost, source, end, index, distance, planner->pending[start]
    };
    planner->pending[start] = record;
}

static Lz3Operation *plan_huff_lz3(unsigned char const *source, size_t size,
                                    HuffModel const *model,
                                    LadderEntry const ladder[3],
                                    Lz3Matches const *matches, size_t *operation_count,
                                    unsigned symbol_bits)
{
    unsigned pair_count = (unsigned)(size / 2);
    uint64_t *costs = malloc(((size_t)pair_count + 1) * sizeof(*costs));
    Lz3Operation *choices = calloc((size_t)pair_count + 1, sizeof(*choices));
    Lz3Operation *operations = malloc((size_t)pair_count * sizeof(*operations));
    Lz3Planner planner = {0};
    planner.pending = malloc(((size_t)pair_count + 1) * sizeof(*planner.pending));
    if (!costs || !choices || !operations || !planner.pending)
        fail("out of memory");
    for (unsigned index = 0; index <= pair_count; index++) {
        costs[index] = UINT64_MAX;
        planner.pending[index] = SIZE_MAX;
    }
    costs[0] = 0;
    for (unsigned pair = 0; pair < pair_count; pair++) {
        for (size_t record = planner.pending[pair]; record != SIZE_MAX;
             record = planner.ranges[record].next)
            lz3_heap_push(&planner, record);
        while (planner.heap_count &&
               planner.ranges[planner.heap[0]].end < pair)
            lz3_heap_pop(&planner);
        if (planner.heap_count) {
            Lz3Range const *best = &planner.ranges[planner.heap[0]];
            if (best->cost < costs[pair]) {
                costs[pair] = best->cost;
                choices[pair] = (Lz3Operation){1, pair - best->source,
                                                best->index, best->distance};
            }
        }
        if (costs[pair] == UINT64_MAX)
            fail("Huffman/LZ3 planner cannot cover the source");
        unsigned first = source[(size_t)pair * 2];
        unsigned second = source[(size_t)pair * 2 + 1];
        unsigned first_bits = symbol_bits == 4
            ? model->bits[first >> 4] + model->bits[first & 15u]
            : model->bits[first];
        unsigned second_bits = symbol_bits == 4
            ? model->bits[second >> 4] + model->bits[second & 15u]
            : model->bits[second];
        if (!first_bits || !second_bits)
            fail("Huffman model omitted a required literal");
        unsigned literal_bits = first_bits + second_bits;
        uint64_t literal_cost = costs[pair] + 1 + literal_bits;
        if (literal_cost < costs[pair + 1]) {
            costs[pair + 1] = literal_cost;
            choices[pair + 1] = (Lz3Operation){0, 1, 0, 0};
        }
        for (unsigned index = 0; index < 3; index++) {
            unsigned maximum = matches[pair].pairs[index];
            if (!maximum)
                continue;
            unsigned distance = matches[pair].distance[index];
            unsigned short_end = pair + (maximum < 9 ? maximum : 9);
            lz3_schedule(&planner, pair, pair + 2, short_end, pair_count,
                         costs[pair] + 1 + 2 + ladder[index].width + 3,
                         index, distance);
            unsigned minimum_pairs = 10;
            for (unsigned digits = 1; minimum_pairs <= maximum; digits++) {
                unsigned minimum_count = digits == 1 ? 1 : 1u << (2 * (digits - 1));
                unsigned maximum_count = (1u << (2 * digits)) - 1;
                unsigned start_pairs = minimum_count * 8 + 2;
                unsigned end_pairs = maximum_count * 8 + 9;
                if (start_pairs < minimum_pairs)
                    start_pairs = minimum_pairs;
                if (end_pairs > maximum)
                    end_pairs = maximum;
                if (start_pairs <= end_pairs)
                    lz3_schedule(&planner, pair, pair + start_pairs,
                                 pair + end_pairs, pair_count,
                                 costs[pair] + 1 + 2 + digits * 3 + 1 + 2 +
                                     ladder[index].width + 3,
                                 index, distance);
                minimum_pairs = maximum_count * 8 + 10;
            }
        }
    }
    *operation_count = 0;
    unsigned cursor = pair_count;
    while (cursor) {
        Lz3Operation choice = choices[cursor];
        if (!choice.pairs || choice.pairs > cursor)
            fail("Huffman-8/LZ3 planner produced an invalid path");
        operations[(*operation_count)++] = choice;
        cursor -= choice.pairs;
    }
    for (size_t left = 0, right = *operation_count - 1; left < right; left++, right--) {
        Lz3Operation swap = operations[left];
        operations[left] = operations[right];
        operations[right] = swap;
    }
    free(planner.heap);
    free(planner.pending);
    free(planner.ranges);
    free(choices);
    free(costs);
    return operations;
}

static unsigned vli_bit_cost(unsigned value, unsigned atom_bits)
{
    unsigned digits = 1;
    value >>= atom_bits - 1;
    while (value) {
        digits++;
        value >>= atom_bits - 1;
    }
    return digits * atom_bits;
}

static unsigned char *encode_lz3_optimal(unsigned char const *source, size_t size,
                                          LadderEntry const ladder[3], size_t *packed_size)
{
    if (!size || size > 0x40000 || (size & 1))
        fail("Raw-LZ3 source size must be even and in 2..0x40000");
    // Dynamic planning is useful for small fixed-slot art; larger raw streams
    // retain the linear-space greedy encoder rather than a quadratic search.
    if (size > 0x2000)
        return encode_lz3(source, size, ladder, packed_size);
    unsigned pair_count = (unsigned)(size / 2);
    Lz3Matches *matches = precompute_lz3_matches(source, size, ladder, 512);
    uint64_t *costs = malloc(((size_t)pair_count + 1) * sizeof(*costs));
    Lz3Operation *choices = calloc((size_t)pair_count + 1, sizeof(*choices));
    Lz3Operation *operations = malloc((size_t)pair_count * sizeof(*operations));
    if (!costs || !choices || !operations)
        fail("out of memory");
    for (unsigned pair = 0; pair <= pair_count; pair++)
        costs[pair] = UINT64_MAX;
    costs[0] = 0;
    for (unsigned pair = 0; pair < pair_count; pair++) {
        if (costs[pair] == UINT64_MAX)
            continue;
        uint64_t cost = costs[pair] + 17;
        if (cost < costs[pair + 1]) {
            costs[pair + 1] = cost;
            choices[pair + 1] = (Lz3Operation){0, 1, 0, 0};
        }
        for (unsigned pairs = 8; pairs <= pair_count - pair; pairs++) {
            cost = costs[pair] + 4 + vli_bit_cost(pairs - 1, 3) + pairs * 16;
            unsigned target = pair + pairs;
            if (cost < costs[target]) {
                costs[target] = cost;
                choices[target] = (Lz3Operation){2, pairs, 0, 0};
            }
        }
        for (unsigned index = 0; index < 3; index++) {
            unsigned maximum = matches[pair].pairs[index];
            unsigned distance = matches[pair].distance[index];
            for (unsigned pairs = 2; pairs <= maximum; pairs++) {
                unsigned bits = pairs <= 9
                    ? 1 + 2 + ladder[index].width + 3
                    : 1 + 2 + vli_bit_cost((pairs - 2) >> 3, 3) + 1 + 2 +
                          ladder[index].width + 3;
                unsigned target = pair + pairs;
                cost = costs[pair] + bits;
                if (cost < costs[target]) {
                    costs[target] = cost;
                    choices[target] = (Lz3Operation){1, pairs, index, distance};
                }
            }
        }
    }
    Lz3Operation *ordered = operations;
    size_t operation_count = 0;
    unsigned cursor = pair_count;
    while (cursor) {
        Lz3Operation choice = choices[cursor];
        if (!choice.pairs || choice.pairs > cursor)
            fail("Raw-LZ3 planner produced an invalid path");
        ordered[operation_count++] = choice;
        cursor -= choice.pairs;
    }
    for (size_t left = 0, right = operation_count - 1; left < right; left++, right--) {
        Lz3Operation swap = ordered[left];
        ordered[left] = ordered[right];
        ordered[right] = swap;
    }
    free(matches);
    free(costs);
    free(choices);

    BitWriter writer = {0};
    write_bits(&writer, 3, 8);
    for (unsigned index = 0; index < 3; index++)
        write_bits(&writer, ladder[index].width - 1, 4);
    size_t position = 0;
    for (size_t operation = 0; operation < operation_count; operation++) {
        Lz3Operation const *choice = &ordered[operation];
        if (choice->kind == 0) {
            write_bits(&writer, 0, 1);
            write_bits(&writer, source[position] << 8 | source[position + 1], 16);
        } else if (choice->kind == 2) {
            write_bits(&writer, 1, 1);
            write_bits(&writer, 3, 2);
            write_vli(&writer, choice->pairs - 1);
            write_bits(&writer, 0, 1);
            for (unsigned pair = 0; pair < choice->pairs; pair++) {
                size_t at = position + (size_t)pair * 2;
                write_bits(&writer, source[at] << 8 | source[at + 1], 16);
            }
        } else {
            write_bits(&writer, 1, 1);
            if (choice->pairs <= 9) {
                write_bits(&writer, choice->index, 2);
            } else {
                write_bits(&writer, 3, 2);
                write_vli(&writer, (choice->pairs - 2) >> 3);
                write_bits(&writer, 1, 1);
                write_bits(&writer, choice->index, 2);
            }
            write_bits(&writer, choice->distance - ladder[choice->index].start,
                       ladder[choice->index].width);
            write_bits(&writer, (choice->pairs - 2) & 7, 3);
        }
        position += (size_t)choice->pairs * 2;
    }
    free(ordered);
    finish_bits(&writer);
    *packed_size = writer.size + 4;
    unsigned char *packed = malloc(*packed_size);
    if (!packed)
        fail("out of memory");
    uint32_t header = ((uint32_t)size << 8) | 0x70;
    for (unsigned index = 0; index < 4; index++)
        packed[index] = (unsigned char)(header >> (index * 8));
    memcpy(packed + 4, writer.data, writer.size);
    free(writer.data);
    return packed;
}

static void write_huff_byte(BitWriter *writer, HuffModel const *model,
                            unsigned symbol)
{
    if (!model->bits[symbol])
        fail("Huffman-8 model omitted an emitted literal");
    write_bits(writer, model->code[symbol], model->bits[symbol]);
}

static void huff_byte_model(unsigned char const *source, size_t size,
                            HuffModel *model, unsigned symbol_bits);
static void write_huff_atom_byte(BitWriter *writer, HuffModel const *model,
                                  unsigned value, unsigned symbol_bits);

static unsigned char *encode_huff_lz3(unsigned char const *source, size_t size,
                                      LadderEntry const ladder[3], size_t *packed_size,
                                      unsigned symbol_bits)
{
    if (!size || size > 0x40000 || (size & 1))
        fail("Huffman/LZ3 source size must be even and in 2..0x40000");
    Lz3Matches *matches = precompute_lz3_matches(source, size, ladder, 96);
    unsigned char *literals = malloc(size);
    if (!literals)
        fail("out of memory");
    HuffModel model, next_model;
    huff_byte_model(source, size, &model, symbol_bits);
    Lz3Operation *operations = NULL;
    size_t operation_count = 0;
    int converged = 0;
    for (unsigned iteration = 0; iteration < 8; iteration++) {
        operations = plan_huff_lz3(source, size, &model, ladder,
                                    matches, &operation_count, symbol_bits);
        size_t literal_size = 0;
        size_t position = 0;
        for (size_t index = 0; index < operation_count; index++) {
            size_t length = (size_t)operations[index].pairs * 2;
            if (!operations[index].kind) {
                memcpy(literals + literal_size, source + position, length);
                literal_size += length;
            }
            position += length;
        }
        huff_byte_model(literals, literal_size, &next_model, symbol_bits);
        if (huff_model_equal(&model, &next_model)) {
            converged = 1;
            break;
        }
        model = next_model;
        free(operations);
        operations = NULL;
    }
    if (!converged)
        operations = plan_huff_lz3(source, size, &model, ladder,
                                    matches, &operation_count, symbol_bits);
    free(literals);
    free(matches);

    BitWriter writer = {0};
    write_bits(&writer, symbol_bits == 4 ? 0x0B : 0x13, 8);
    write_huff_tree(&writer, &model, symbol_bits);
    for (unsigned index = 0; index < 3; index++)
        write_bits(&writer, ladder[index].width - 1, 4);
    size_t position = 0;
    for (size_t index = 0; index < operation_count; index++) {
        Lz3Operation const *operation = &operations[index];
        if (!operation->kind) {
            unsigned run_pairs = operation->pairs;
            size_t following = index + 1;
            while (following < operation_count && !operations[following].kind) {
                run_pairs += operations[following].pairs;
                following++;
            }
            unsigned extended_cost = 1 + 2 + vli_bit_cost(run_pairs - 1, 3) + 1;
            if (extended_cost < run_pairs) {
                write_bits(&writer, 1, 1);
                write_bits(&writer, 3, 2);
                write_vli(&writer, run_pairs - 1);
                write_bits(&writer, 0, 1);
                for (unsigned byte = 0; byte < run_pairs * 2; byte++)
                    write_huff_atom_byte(&writer, &model, source[position + byte],
                                         symbol_bits);
                position += (size_t)run_pairs * 2;
                index = following - 1;
                continue;
            }
            write_bits(&writer, 0, 1);
            write_huff_atom_byte(&writer, &model, source[position], symbol_bits);
            write_huff_atom_byte(&writer, &model, source[position + 1], symbol_bits);
        } else {
            write_bits(&writer, 1, 1);
            if (operation->pairs <= 9) {
                write_bits(&writer, operation->index, 2);
            } else {
                write_bits(&writer, 3, 2);
                write_vli(&writer, (operation->pairs - 2) >> 3);
                write_bits(&writer, 1, 1);
                write_bits(&writer, operation->index, 2);
            }
            write_bits(&writer,
                       operation->distance - ladder[operation->index].start,
                       ladder[operation->index].width);
            write_bits(&writer, (operation->pairs - 2) & 7u, 3);
        }
        position += (size_t)operation->pairs * 2;
    }
    free(operations);
    if (position != size)
        fail("Huffman-8/LZ3 planner did not consume the full source");
    finish_bits(&writer);
    *packed_size = writer.size + 4;
    unsigned char *packed = malloc(*packed_size);
    if (!packed)
        fail("out of memory");
    uint32_t header = ((uint32_t)size << 8) | 0x70;
    for (unsigned index = 0; index < 4; index++)
        packed[index] = (unsigned char)(header >> (index * 8));
    memcpy(packed + 4, writer.data, writer.size);
    free(writer.data);
    return packed;
}

static unsigned char *encode_huff8_lz3(unsigned char const *source, size_t size,
                                        LadderEntry const ladder[3], size_t *packed_size)
{
    return encode_huff_lz3(source, size, ladder, packed_size, 8);
}

static unsigned char *decode_lz1(unsigned char const *packed, size_t packed_size,
                                 LadderEntry ladder[4], size_t *decoded_size)
{
    if (packed_size < 8 || packed[0] != 0x70)
        fail("not a FoMT native 0x70 stream");
    *decoded_size = (size_t)packed[1] | ((size_t)packed[2] << 8)
                  | ((size_t)packed[3] << 16);
    if (!*decoded_size || *decoded_size > 0x40000)
        fail("invalid Raw-LZ1 decoded size");
    BitReader reader = {packed, packed_size, 4, 0, 0};
    uint32_t value;
    if (!read_bits(&reader, 8, &value) || value != 1)
        fail("this codec requires raw atoms, LZ mode 1 and no filter");
    unsigned start = 1;
    for (unsigned index = 0; index < 4; index++) {
        if (!read_bits(&reader, 4, &value))
            fail("truncated LZ1 ladder");
        ladder[index].start = start;
        ladder[index].width = value + 1;
        start += 1u << ladder[index].width;
    }
    unsigned char *output = malloc(*decoded_size);
    if (!output)
        fail("out of memory");
    size_t written = 0;
    while (written < *decoded_size) {
        if (!read_bits(&reader, 1, &value))
            fail("truncated LZ1 command");
        if (!value) {
            if (!read_bits(&reader, 8, &value))
                fail("truncated LZ1 literal");
            output[written++] = (unsigned char)value;
            continue;
        }
        if (!read_bits(&reader, 2, &value))
            fail("truncated LZ1 ladder index");
        unsigned index = value;
        if (!read_bits(&reader, ladder[index].width, &value))
            fail("truncated LZ1 distance");
        unsigned distance = ladder[index].start + value;
        if (!read_bits(&reader, 4, &value))
            fail("truncated LZ1 length");
        unsigned length = value + 3;
        if (distance > written || length > *decoded_size - written)
            fail("invalid LZ1 lookup");
        for (unsigned byte = 0; byte < length; byte++) {
            output[written] = output[written - distance];
            written++;
        }
    }
    return output;
}

static unsigned char *decode_lz2(unsigned char const *packed, size_t packed_size,
                                 LadderEntry ladder[7], size_t *decoded_size)
{
    if (packed_size < 12 || packed[0] != 0x70)
        fail("not a FoMT native 0x70 stream");
    *decoded_size = (size_t)packed[1] | ((size_t)packed[2] << 8)
                  | ((size_t)packed[3] << 16);
    if (!*decoded_size || *decoded_size > 0x40000)
        fail("invalid Raw-LZ2 decoded size");
    BitReader reader = {packed, packed_size, 4, 0, 0};
    uint32_t value;
    if (!read_bits(&reader, 8, &value) || value != 2)
        fail("this codec requires raw atoms, LZ mode 2 and no filter");
    unsigned start = 1;
    for (unsigned index = 0; index < 7; index++) {
        if (!read_bits(&reader, 4, &value))
            fail("truncated LZ2 ladder");
        ladder[index].start = start;
        ladder[index].width = value + 1;
        start += 1u << ladder[index].width;
    }
    unsigned char *output = malloc(*decoded_size);
    if (!output)
        fail("out of memory");
    size_t written = 0;
    while (written < *decoded_size) {
        if (!read_bits(&reader, 1, &value))
            fail("truncated LZ2 command");
        unsigned length = 1;
        unsigned distance = 0;
        if (value) {
            if (!read_bits(&reader, 3, &value))
                fail("truncated LZ2 command type");
            unsigned index = value;
            if (index == 7) {
                unsigned count = read_vli_bits(&reader, 4);
                if (!read_bits(&reader, 1, &value))
                    fail("truncated extended LZ2 command");
                if (!value) {
                    length = count + 1;
                } else {
                    if (!read_bits(&reader, 3, &value) || value == 7)
                        fail("invalid extended LZ2 ladder index");
                    index = value;
                    if (!read_bits(&reader, ladder[index].width, &value))
                        fail("truncated extended LZ2 distance");
                    distance = ladder[index].start + value;
                    if (!read_bits(&reader, 4, &value))
                        fail("truncated extended LZ2 length");
                    length = (count << 4) + value + 3;
                }
            } else {
                if (!read_bits(&reader, ladder[index].width, &value))
                    fail("truncated LZ2 distance");
                distance = ladder[index].start + value;
                if (!read_bits(&reader, 4, &value))
                    fail("truncated LZ2 length");
                length = value + 3;
            }
        }
        if (length > *decoded_size - written)
            fail("LZ2 command exceeds decoded size");
        if (distance) {
            if (distance > written)
                fail("LZ2 lookup precedes decoded data");
            for (unsigned byte = 0; byte < length; byte++) {
                output[written] = output[written - distance];
                written++;
            }
        } else {
            for (unsigned byte = 0; byte < length; byte++) {
                if (!read_bits(&reader, 8, &value))
                    fail("truncated LZ2 literal");
                output[written++] = (unsigned char)value;
            }
        }
    }
    return output;
}

static void apply_differential(unsigned char *data, size_t size, unsigned filter)
{
    unsigned accumulator = 0;
    if (filter == 0)
        return;
    if (filter == 1) {
        for (size_t index = 0; index < size; index++) {
            unsigned high = ((data[index] >> 4) + accumulator) & 15u;
            unsigned low = ((data[index] & 15u) + high) & 15u;
            data[index] = (unsigned char)((high << 4) | low);
            accumulator = low;
        }
    } else if (filter == 2) {
        for (size_t index = 0; index < size; index++) {
            accumulator = (accumulator + data[index]) & 255u;
            data[index] = (unsigned char)accumulator;
        }
    } else if (filter == 3) {
        if (size & 1)
            fail("word differential filter requires an even decoded size");
        for (size_t index = 0; index < size; index += 2) {
            unsigned value = data[index] | ((unsigned)data[index + 1] << 8);
            accumulator = (accumulator + value) & 65535u;
            data[index] = (unsigned char)accumulator;
            data[index + 1] = (unsigned char)(accumulator >> 8);
        }
    } else if (filter == 4) {
        if (size & 1)
            fail("interleaved differential filter requires an even decoded size");
        unsigned odd = 0;
        for (size_t index = 0; index < size; index += 2) {
            accumulator = (accumulator + data[index]) & 255u;
            odd = (odd + data[index + 1]) & 255u;
            data[index] = (unsigned char)accumulator;
            data[index + 1] = (unsigned char)odd;
        }
    } else {
        fail("unsupported differential filter");
    }
}

static unsigned char *inverse_differential(unsigned char const *source,
                                            size_t size, unsigned filter)
{
    unsigned char *atoms = malloc(size);
    if (!atoms)
        fail("out of memory");
    unsigned accumulator = 0;
    if (filter == 0) {
        memcpy(atoms, source, size);
    } else if (filter == 1) {
        for (size_t index = 0; index < size; index++) {
            unsigned high = source[index] >> 4;
            unsigned low = source[index] & 15u;
            atoms[index] = (unsigned char)((((high - accumulator) & 15u) << 4) |
                                            ((low - high) & 15u));
            accumulator = low;
        }
    } else if (filter == 2) {
        for (size_t index = 0; index < size; index++) {
            atoms[index] = (unsigned char)(source[index] - accumulator);
            accumulator = source[index];
        }
    } else if (filter == 3) {
        if (size & 1)
            fail("word differential filter requires an even source size");
        for (size_t index = 0; index < size; index += 2) {
            unsigned value = source[index] | ((unsigned)source[index + 1] << 8);
            unsigned difference = (value - accumulator) & 65535u;
            atoms[index] = (unsigned char)difference;
            atoms[index + 1] = (unsigned char)(difference >> 8);
            accumulator = value;
        }
    } else if (filter == 4) {
        if (size & 1)
            fail("interleaved differential filter requires an even source size");
        unsigned odd = 0;
        for (size_t index = 0; index < size; index += 2) {
            atoms[index] = (unsigned char)(source[index] - accumulator);
            atoms[index + 1] = (unsigned char)(source[index + 1] - odd);
            accumulator = source[index];
            odd = source[index + 1];
        }
    } else {
        fail("unsupported differential filter");
    }
    return atoms;
}

static unsigned char *decode_huff_lz2(unsigned char const *packed, size_t packed_size,
                                      LadderEntry ladder[7], size_t *decoded_size,
                                      unsigned symbol_bits)
{
    if (packed_size < 8 || packed[0] != 0x70)
        fail("not a FoMT native 0x70 stream");
    *decoded_size = (size_t)packed[1] | ((size_t)packed[2] << 8)
                  | ((size_t)packed[3] << 16);
    if (!*decoded_size || *decoded_size > 0x40000)
        fail("invalid Huffman/LZ2 decoded size");
    BitReader reader = {packed, packed_size, 4, 0, 0};
    uint32_t value;
    if (!read_bits(&reader, 8, &value) ||
        (value & 31u) != (symbol_bits == 4 ? 0x0Au : 0x12u) ||
        (value >> 5) > 4)
        fail("stream format is not the requested Huffman/LZ2 codec");
    unsigned filter = value >> 5;
    HuffNode nodes[512];
    unsigned node_count;
    read_huff_tree(&reader, nodes, &node_count, symbol_bits);
    unsigned start = 1;
    for (unsigned index = 0; index < 7; index++) {
        if (!read_bits(&reader, 4, &value))
            fail("truncated Huffman/LZ2 ladder");
        ladder[index].start = start;
        ladder[index].width = value + 1;
        start += 1u << ladder[index].width;
    }
    unsigned char *output = malloc(*decoded_size);
    if (!output)
        fail("out of memory");
    size_t written = 0;
    while (written < *decoded_size) {
        if (!read_bits(&reader, 1, &value))
            fail("truncated Huffman/LZ2 command");
        unsigned length = 1;
        unsigned distance = 0;
        if (value) {
            if (!read_bits(&reader, 3, &value))
                fail("truncated Huffman/LZ2 command type");
            unsigned index = value;
            if (index == 7) {
                unsigned count = read_vli_bits(&reader, 4);
                if (!read_bits(&reader, 1, &value))
                    fail("truncated extended Huffman/LZ2 command");
                if (!value) {
                    length = count + 1;
                } else {
                    if (!read_bits(&reader, 3, &value) || value == 7)
                        fail("invalid extended Huffman/LZ2 ladder index");
                    index = value;
                    if (!read_bits(&reader, ladder[index].width, &value))
                        fail("truncated extended Huffman/LZ2 distance");
                    distance = ladder[index].start + value;
                    if (!read_bits(&reader, 4, &value))
                        fail("truncated extended Huffman/LZ2 length");
                    length = (count << 4) + value + 3;
                }
            } else {
                if (!read_bits(&reader, ladder[index].width, &value))
                    fail("truncated Huffman/LZ2 distance");
                distance = ladder[index].start + value;
                if (!read_bits(&reader, 4, &value))
                    fail("truncated Huffman/LZ2 length");
                length = value + 3;
            }
        }
        if (length > *decoded_size - written)
            fail("Huffman/LZ2 command exceeds decoded size");
        if (distance) {
            if (distance > written)
                fail("Huffman/LZ2 lookup precedes decoded data");
            for (unsigned byte = 0; byte < length; byte++) {
                output[written] = output[written - distance];
                written++;
            }
        } else {
            for (unsigned byte = 0; byte < length; byte++) {
                unsigned atom = read_huff_symbol(&reader, nodes);
                if (symbol_bits == 4)
                    atom = (atom << 4) | read_huff_symbol(&reader, nodes);
                output[written++] = (unsigned char)atom;
            }
        }
    }
    apply_differential(output, *decoded_size, filter);
    return output;
}

typedef struct {
    unsigned length[7];
    unsigned distance[7];
} Lz2Matches;

typedef struct {
    unsigned kind;
    unsigned length;
    unsigned index;
    unsigned distance;
} Lz2Operation;

static Lz2Matches *precompute_lz2_matches(unsigned char const *source, size_t size,
                                           LadderEntry const ladder[7])
{
    Lz2Matches *matches = calloc(size, sizeof(*matches));
    int *previous = malloc(size * sizeof(*previous));
    int *heads = malloc(65536 * sizeof(*heads));
    if (!matches || !previous || !heads)
        fail("out of memory");
    for (unsigned index = 0; index < 65536; index++)
        heads[index] = -1;
    unsigned maximum_distance = ladder[6].start + (1u << ladder[6].width) - 1;
    for (size_t position = 0; position + 3 <= size; position++) {
        uint32_t key = (uint32_t)source[position] |
                       ((uint32_t)source[position + 1] << 8) |
                       ((uint32_t)source[position + 2] << 16);
        unsigned bucket = lz3_hash(key);
        unsigned candidates = 0;
        for (int candidate = heads[bucket]; candidate >= 0;
             candidate = previous[candidate]) {
            unsigned distance = (unsigned)(position - (size_t)candidate);
            if (distance > maximum_distance)
                break;
            if (source[candidate] != source[position] ||
                source[candidate + 1] != source[position + 1] ||
                source[candidate + 2] != source[position + 2])
                continue;
            if (++candidates > 48)
                break;
            size_t lower = 3;
            size_t upper = size - position;
            if (upper > 0x400)
                upper = 0x400;
            while (lower < upper) {
                size_t probe = lower + (upper - lower + 1) / 2;
                if (memcmp(source + candidate, source + position, probe) == 0)
                    lower = probe;
                else
                    upper = probe - 1;
            }
            for (unsigned index = 0; index < 7; index++) {
                if (distance < ladder[index].start + (1u << ladder[index].width)) {
                    if (lower > matches[position].length[index]) {
                        matches[position].length[index] = (unsigned)lower;
                        matches[position].distance[index] = distance;
                    }
                    break;
                }
            }
        }
        previous[position] = heads[bucket];
        heads[bucket] = (int)position;
    }
    free(heads);
    free(previous);
    return matches;
}

static void lz2_try_lookup(size_t position, unsigned length, unsigned index,
                            unsigned distance, LadderEntry const ladder[7],
                            uint64_t const *costs, Lz2Operation *choices,
                            uint64_t *new_costs)
{
    unsigned bits = length <= 18 ? 1 + 3 + ladder[index].width + 4
        : 1 + 3 + vli_bit_cost((length - 3) >> 4, 4) + 1 + 3 +
              ladder[index].width + 4;
    size_t target = position + length;
    uint64_t candidate = costs[position] + bits;
    if (candidate < new_costs[target]) {
        new_costs[target] = candidate;
        choices[target] = (Lz2Operation){1, length, index, distance};
    }
}

static Lz2Operation *plan_huff_lz2(unsigned char const *source, size_t size,
                                    HuffModel const *model,
                                    LadderEntry const ladder[7],
                                    Lz2Matches const *matches,
                                    unsigned symbol_bits, size_t *operation_count)
{
    uint64_t *costs = malloc((size + 1) * sizeof(*costs));
    Lz2Operation *choices = calloc(size + 1, sizeof(*choices));
    Lz2Operation *operations = malloc(size * sizeof(*operations));
    if (!costs || !choices || !operations)
        fail("out of memory");
    for (size_t index = 0; index <= size; index++)
        costs[index] = UINT64_MAX;
    costs[0] = 0;
    for (size_t position = 0; position < size; position++) {
        if (costs[position] == UINT64_MAX)
            fail("Huffman/LZ2 planner cannot cover the source");
        unsigned value = source[position];
        unsigned literal_bits = symbol_bits == 4
            ? model->bits[value >> 4] + model->bits[value & 15u]
            : model->bits[value];
        if (!literal_bits)
            fail("Huffman model omitted a required literal");
        uint64_t literal_cost = costs[position] + 1 + literal_bits;
        if (literal_cost < costs[position + 1]) {
            costs[position + 1] = literal_cost;
            choices[position + 1] = (Lz2Operation){0, 1, 0, 0};
        }
        for (unsigned index = 0; index < 7; index++) {
            unsigned maximum = matches[position].length[index];
            unsigned distance = matches[position].distance[index];
            if (!maximum)
                continue;
            unsigned short_end = maximum < 18 ? maximum : 18;
            for (unsigned length = 3; length <= short_end; length++)
                lz2_try_lookup(position, length, index, distance, ladder,
                               costs, choices, costs);
            unsigned long_end = maximum < 34 ? maximum : 34;
            for (unsigned length = 19; length <= long_end; length++)
                lz2_try_lookup(position, length, index, distance, ladder,
                               costs, choices, costs);
            for (unsigned length = 50; length <= maximum; length += 16)
                lz2_try_lookup(position, length, index, distance, ladder,
                               costs, choices, costs);
            if (maximum >= 19 && maximum > 34 &&
                (maximum < 50 || (maximum - 50) % 16))
                lz2_try_lookup(position, maximum, index, distance, ladder,
                               costs, choices, costs);
        }
    }
    *operation_count = 0;
    size_t cursor = size;
    while (cursor) {
        Lz2Operation choice = choices[cursor];
        if (!choice.length || choice.length > cursor)
            fail("Huffman/LZ2 planner produced an invalid path");
        operations[(*operation_count)++] = choice;
        cursor -= choice.length;
    }
    for (size_t left = 0, right = *operation_count - 1; left < right; left++, right--) {
        Lz2Operation swap = operations[left];
        operations[left] = operations[right];
        operations[right] = swap;
    }
    free(choices);
    free(costs);
    return operations;
}

static void huff_byte_model(unsigned char const *source, size_t size,
                            HuffModel *model, unsigned symbol_bits)
{
    if (symbol_bits == 8) {
        huff_model(source, size, model, 8);
        return;
    }
    unsigned char *symbols = malloc(size * 2);
    if (!symbols)
        fail("out of memory");
    for (size_t index = 0; index < size; index++) {
        symbols[index * 2] = source[index] >> 4;
        symbols[index * 2 + 1] = source[index] & 15u;
    }
    huff_model(symbols, size * 2, model, 4);
    free(symbols);
}

static void write_huff_atom_byte(BitWriter *writer, HuffModel const *model,
                                  unsigned value, unsigned symbol_bits)
{
    if (symbol_bits == 4) {
        write_huff_byte(writer, model, value >> 4);
        write_huff_byte(writer, model, value & 15u);
    } else {
        write_huff_byte(writer, model, value);
    }
}

static unsigned char *encode_huff_lz2(unsigned char const *source, size_t size,
                                      LadderEntry const ladder[7],
                                      unsigned symbol_bits, unsigned filter,
                                      size_t *packed_size)
{
    if (!size || size > 0x40000)
        fail("Huffman/LZ2 source size must be in 1..0x40000");
    unsigned char *atoms = inverse_differential(source, size, filter);
    Lz2Matches *matches = precompute_lz2_matches(atoms, size, ladder);
    unsigned char *literals = malloc(size);
    if (!literals)
        fail("out of memory");
    HuffModel model, next_model;
    huff_byte_model(atoms, size, &model, symbol_bits);
    Lz2Operation *operations = NULL;
    size_t operation_count = 0;
    int converged = 0;
    for (unsigned iteration = 0; iteration < 8; iteration++) {
        operations = plan_huff_lz2(atoms, size, &model, ladder, matches,
                                    symbol_bits, &operation_count);
        size_t literal_size = 0;
        size_t position = 0;
        for (size_t index = 0; index < operation_count; index++) {
            if (!operations[index].kind)
                literals[literal_size++] = atoms[position];
            position += operations[index].length;
        }
        huff_byte_model(literals, literal_size, &next_model, symbol_bits);
        if (huff_model_equal(&model, &next_model)) {
            converged = 1;
            break;
        }
        model = next_model;
        free(operations);
        operations = NULL;
    }
    if (!converged)
        operations = plan_huff_lz2(atoms, size, &model, ladder, matches,
                                    symbol_bits, &operation_count);
    free(literals);
    free(matches);

    BitWriter writer = {0};
    write_bits(&writer, (filter << 5) | (symbol_bits == 4 ? 0x0Au : 0x12u), 8);
    write_huff_tree(&writer, &model, symbol_bits);
    for (unsigned index = 0; index < 7; index++)
        write_bits(&writer, ladder[index].width - 1, 4);
    size_t position = 0;
    for (size_t index = 0; index < operation_count; index++) {
        Lz2Operation const *operation = &operations[index];
        if (!operation->kind) {
            unsigned run = operation->length;
            size_t following = index + 1;
            while (following < operation_count && !operations[following].kind) {
                run += operations[following].length;
                following++;
            }
            unsigned extended_cost = 1 + 3 + vli_bit_cost(run - 1, 4) + 1;
            if (extended_cost < run) {
                write_bits(&writer, 1, 1);
                write_bits(&writer, 7, 3);
                write_vli_bits(&writer, run - 1, 4);
                write_bits(&writer, 0, 1);
                for (unsigned byte = 0; byte < run; byte++)
                    write_huff_atom_byte(&writer, &model, atoms[position + byte],
                                         symbol_bits);
                position += run;
                index = following - 1;
                continue;
            }
            write_bits(&writer, 0, 1);
            write_huff_atom_byte(&writer, &model, atoms[position], symbol_bits);
        } else {
            write_bits(&writer, 1, 1);
            if (operation->length <= 18) {
                write_bits(&writer, operation->index, 3);
            } else {
                write_bits(&writer, 7, 3);
                write_vli_bits(&writer, (operation->length - 3) >> 4, 4);
                write_bits(&writer, 1, 1);
                write_bits(&writer, operation->index, 3);
            }
            write_bits(&writer,
                       operation->distance - ladder[operation->index].start,
                       ladder[operation->index].width);
            write_bits(&writer, (operation->length - 3) & 15u, 4);
        }
        position += operation->length;
    }
    free(operations);
    free(atoms);
    if (position != size)
        fail("Huffman/LZ2 planner did not consume the full source");
    finish_bits(&writer);
    *packed_size = writer.size + 4;
    unsigned char *packed = malloc(*packed_size);
    if (!packed)
        fail("out of memory");
    uint32_t header = ((uint32_t)size << 8) | 0x70;
    for (unsigned index = 0; index < 4; index++)
        packed[index] = (unsigned char)(header >> (index * 8));
    memcpy(packed + 4, writer.data, writer.size);
    free(writer.data);
    return packed;
}

static void usage(void)
{
    fail("usage: fomt-lz encode-lz2 SOURCE OUTPUT LADDER SLOT_SIZE "
         "[--literal-tail] | "
         "encode-lz3|encode-huff8-lz3 SOURCE OUTPUT LADDER SLOT_SIZE | "
         "rebuild-native SOURCE ORIGINAL OUTPUT [TAIL] | "
         "rebuild-huff8-lz3 SOURCE ORIGINAL OUTPUT LADDER SLOT_SIZE | "
         "rebuild-huff4-lz2|rebuild-huff8-lz2 "
         "SOURCE ORIGINAL OUTPUT LADDER SLOT_SIZE | "
         "decode-lz2|decode-lz3|decode-huff4-lz3|decode-huff8-lz3|"
         "decode-huff4-lz2|decode-huff8-lz2 SOURCE OUTPUT | "
         "verify-native SOURCE PACKED [TAIL] | "
         "verify-lz2|verify-lz3|verify-huff4-lz3|verify-huff8-lz3|"
         "verify-huff4-lz2|verify-huff8-lz2 SOURCE PACKED [LADDER]");
}

int main(int argc, char **argv)
{
    if (argc < 4)
        usage();
    if (strcmp(argv[1], "rebuild-native") == 0) {
        if ((argc != 5 && argc != 6) || strcmp(argv[3], argv[4]) == 0)
            usage();
        size_t source_size, original_size, decoded_size;
        unsigned char *source = read_file_parts(argv[2], argc == 6 ? argv[5] : NULL,
                                                &source_size);
        unsigned char *original = read_file(argv[3], &original_size);
        if (original_size < 8 || original[0] != 0x70)
            fail("rebuild reference is not a FoMT native stream");
        BitReader reader = {original, original_size, 4, 0, 0};
        uint32_t format;
        if (!read_bits(&reader, 8, &format))
            fail("truncated native stream format");
        unsigned symbol_bits = (format & 31u) == 0x0Au || format == 0x0Bu ? 4 : 8;
        int raw = format >= 1 && format <= 3;
        int lz2 = (format & 31u) == 0x0Au || (format & 31u) == 0x12u;
        if (!raw && !lz2 && format != 0x0B && format != 0x13)
            fail("rebuild-native does not support this FoMT stream format");
        LadderEntry ladder[7], check_ladder[7];
        unsigned char *decoded;
        if (format == 1)
            decoded = decode_lz1(original, original_size, ladder, &decoded_size);
        else if (format == 2)
            decoded = decode_lz2(original, original_size, ladder, &decoded_size);
        else if (format == 3)
            decoded = decode_lz3(original, original_size, ladder, &decoded_size);
        else if (lz2)
            decoded = decode_huff_lz2(original, original_size, ladder,
                                      &decoded_size, symbol_bits);
        else
            decoded = decode_huff_lz3(original, original_size, ladder,
                                      &decoded_size, symbol_bits);
        if (source_size != decoded_size)
            fail("edited source changed the original decoded size");
        if (memcmp(source, decoded, source_size) == 0) {
            write_file(argv[4], original, original_size);
        } else {
            size_t packed_size;
            unsigned char *packed;
            if (format == 1)
                packed = encode_lz1(source, source_size, ladder, &packed_size);
            else if (format == 2)
                packed = encode_lz2(source, source_size, ladder, 0, 9,
                                    &packed_size);
            else if (format == 3)
                packed = encode_lz3_optimal(source, source_size, ladder, &packed_size);
            else if (lz2)
                packed = encode_huff_lz2(source, source_size, ladder, symbol_bits,
                                        format >> 5, &packed_size);
            else
                packed = encode_huff_lz3(source, source_size, ladder, &packed_size,
                                         symbol_bits);
            if (format == 2 && packed_size > original_size) {
                // A different literal packing can fit a tight native slot.
                // Keep the established encoder when it already fits.
                free(packed);
                packed = encode_lz2(source, source_size, ladder, 0, 10,
                                    &packed_size);
            }
            if (packed_size > original_size)
                fail("edited native stream exceeds its reference slot");
            size_t check_size;
            unsigned char *check;
            if (format == 1)
                check = decode_lz1(packed, packed_size, check_ladder, &check_size);
            else if (format == 2)
                check = decode_lz2(packed, packed_size, check_ladder, &check_size);
            else if (format == 3)
                check = decode_lz3(packed, packed_size, check_ladder, &check_size);
            else if (lz2)
                check = decode_huff_lz2(packed, packed_size, check_ladder,
                                        &check_size, symbol_bits);
            else
                check = decode_huff_lz3(packed, packed_size, check_ladder,
                                        &check_size, symbol_bits);
            if (check_size != source_size || memcmp(check, source, source_size) != 0)
                fail("edited native stream does not reproduce its source");
            free(check);
            unsigned char *resized = realloc(packed, original_size);
            if (!resized)
                fail("out of memory");
            packed = resized;
            memset(packed + packed_size, 0, original_size - packed_size);
            write_file(argv[4], packed, original_size);
            free(packed);
        }
        free(decoded);
        free(original);
        free(source);
    } else if (strcmp(argv[1], "rebuild-huff4-lz2") == 0 ||
        strcmp(argv[1], "rebuild-huff8-lz2") == 0) {
        if (argc != 7 || strcmp(argv[3], argv[4]) == 0)
            usage();
        unsigned symbol_bits = strcmp(argv[1], "rebuild-huff4-lz2") == 0 ? 4 : 8;
        LadderEntry expected[7], actual[7];
        parse_ladder(argv[5], expected, 7);
        unsigned slot_size = parse_size(argv[6]);
        if (!slot_size)
            fail("rebuild requires a fixed packed slot size");
        size_t source_size, original_size, decoded_size;
        unsigned char *source = read_file(argv[2], &source_size);
        unsigned char *original = read_file(argv[3], &original_size);
        if (original_size != slot_size)
            fail("original stream size does not match its declared slot");
        unsigned char *decoded = decode_huff_lz2(
            original, original_size, actual, &decoded_size, symbol_bits
        );
        if (source_size != decoded_size)
            fail("edited source changed the original decoded size");
        for (unsigned index = 0; index < 7; index++)
            if (actual[index].width != expected[index].width)
                fail("original stream ladder differs from the declared ladder");
        if (memcmp(source, decoded, source_size) == 0) {
            write_file(argv[4], original, original_size);
        } else {
            BitReader reader = {original, original_size, 4, 0, 0};
            uint32_t format;
            if (!read_bits(&reader, 8, &format))
                fail("truncated Huffman/LZ2 format");
            size_t packed_size;
            unsigned char *packed = encode_huff_lz2(
                source, source_size, expected, symbol_bits, format >> 5, &packed_size
            );
            if (packed_size > slot_size)
                fail("edited Huffman/LZ2 stream exceeds its declared slot");
            size_t check_size;
            unsigned char *check = decode_huff_lz2(
                packed, packed_size, actual, &check_size, symbol_bits
            );
            if (check_size != source_size || memcmp(check, source, source_size) != 0)
                fail("edited Huffman/LZ2 stream does not reproduce its source");
            free(check);
            unsigned char *resized = realloc(packed, slot_size);
            if (!resized)
                fail("out of memory");
            packed = resized;
            memset(packed + packed_size, 0, slot_size - packed_size);
            write_file(argv[4], packed, slot_size);
            free(packed);
        }
        free(decoded);
        free(original);
        free(source);
    } else if (strcmp(argv[1], "rebuild-huff8-lz3") == 0) {
        if (argc != 7 || strcmp(argv[3], argv[4]) == 0)
            usage();
        LadderEntry expected[3], actual[3];
        parse_ladder(argv[5], expected, 3);
        unsigned slot_size = parse_size(argv[6]);
        if (!slot_size)
            fail("rebuild requires a fixed packed slot size");
        size_t source_size, original_size, decoded_size;
        unsigned char *source = read_file(argv[2], &source_size);
        unsigned char *original = read_file(argv[3], &original_size);
        if (original_size != slot_size)
            fail("original stream size does not match its declared slot");
        unsigned char *decoded = decode_huff8_lz3(
            original, original_size, actual, &decoded_size
        );
        if (source_size != decoded_size)
            fail("edited source changed the original decoded size");
        for (unsigned index = 0; index < 3; index++)
            if (actual[index].width != expected[index].width)
                fail("original stream ladder differs from the declared ladder");
        if (memcmp(source, decoded, source_size) == 0) {
            write_file(argv[4], original, original_size);
        } else {
            size_t packed_size;
            unsigned char *packed = encode_huff8_lz3(
                source, source_size, expected, &packed_size
            );
            if (packed_size > slot_size)
                fail("edited Huffman-8/LZ3 stream exceeds its declared slot");
            size_t check_size;
            unsigned char *check = decode_huff8_lz3(
                packed, packed_size, actual, &check_size
            );
            if (check_size != source_size || memcmp(check, source, source_size) != 0)
                fail("edited Huffman-8/LZ3 stream does not reproduce its source");
            free(check);
            unsigned char *resized = realloc(packed, slot_size);
            if (!resized)
                fail("out of memory");
            packed = resized;
            memset(packed + packed_size, 0, slot_size - packed_size);
            write_file(argv[4], packed, slot_size);
            free(packed);
        }
        free(decoded);
        free(original);
        free(source);
    } else if (strcmp(argv[1], "encode-lz2") == 0 ||
        strcmp(argv[1], "encode-lz3") == 0 ||
        strcmp(argv[1], "encode-huff8-lz3") == 0) {
        int lz2 = strcmp(argv[1], "encode-lz2") == 0;
        int huff8 = strcmp(argv[1], "encode-huff8-lz3") == 0;
        if (argc != 6 && !(lz2 && argc == 7 &&
                           strcmp(argv[6], "--literal-tail") == 0))
            usage();
        int literal_tail = argc == 7;
        LadderEntry ladder[7];
        parse_ladder(argv[4], ladder, lz2 ? 7 : 3);
        unsigned slot_size = parse_size(argv[5]);
        size_t source_size, packed_size;
        unsigned char *source = read_file(argv[2], &source_size);
        unsigned char *packed = lz2
            ? encode_lz2(source, source_size, ladder, literal_tail, 9,
                         &packed_size)
            : huff8 ? encode_huff8_lz3(source, source_size, ladder, &packed_size)
                    : encode_lz3(source, source_size, ladder, &packed_size);
        if (huff8) {
            LadderEntry decoded_ladder[3];
            size_t decoded_size;
            unsigned char *decoded = decode_huff8_lz3(
                packed, packed_size, decoded_ladder, &decoded_size
            );
            if (decoded_size != source_size || memcmp(decoded, source, source_size) != 0)
                fail("encoded Huffman-8/LZ3 stream does not reproduce its source");
            free(decoded);
        }
        if (slot_size && packed_size > slot_size)
            fail("encoded stream exceeds its declared slot");
        if (slot_size && packed_size < slot_size) {
            packed = realloc(packed, slot_size);
            if (!packed)
                fail("out of memory");
            memset(packed + packed_size, 0, slot_size - packed_size);
            packed_size = slot_size;
        }
        write_file(argv[3], packed, packed_size);
        free(packed);
        free(source);
    } else if (strcmp(argv[1], "decode-lz2") == 0 ||
               strcmp(argv[1], "decode-lz3") == 0 ||
               strcmp(argv[1], "decode-huff8-lz3") == 0 ||
               strcmp(argv[1], "decode-huff4-lz3") == 0 ||
               strcmp(argv[1], "decode-huff4-lz2") == 0 ||
               strcmp(argv[1], "decode-huff8-lz2") == 0) {
        if (argc != 4)
            usage();
        int lz2 = strcmp(argv[1], "decode-lz2") == 0;
        int huff8 = strcmp(argv[1], "decode-huff8-lz3") == 0;
        int huff4_lz3 = strcmp(argv[1], "decode-huff4-lz3") == 0;
        int huff4_lz2 = strcmp(argv[1], "decode-huff4-lz2") == 0;
        int huff8_lz2 = strcmp(argv[1], "decode-huff8-lz2") == 0;
        size_t packed_size, decoded_size;
        unsigned char *packed = read_file(argv[2], &packed_size);
        LadderEntry ladder[7];
        unsigned char *decoded = lz2
            ? decode_lz2(packed, packed_size, ladder, &decoded_size)
            : (huff4_lz2 || huff8_lz2)
                ? decode_huff_lz2(packed, packed_size, ladder, &decoded_size,
                                  huff4_lz2 ? 4 : 8)
            : huff4_lz3 ? decode_huff_lz3(packed, packed_size, ladder,
                                           &decoded_size, 4)
            : huff8 ? decode_huff8_lz3(packed, packed_size, ladder, &decoded_size)
                    : decode_lz3(packed, packed_size, ladder, &decoded_size);
        write_file(argv[3], decoded, decoded_size);
        free(decoded);
        free(packed);
    } else if (strcmp(argv[1], "verify-native") == 0) {
        if (argc != 4 && argc != 5)
            usage();
        size_t source_size, packed_size, decoded_size;
        unsigned char *source = read_file_parts(argv[2], argc == 5 ? argv[4] : NULL,
                                                &source_size);
        unsigned char *packed = read_file(argv[3], &packed_size);
        if (packed_size < 8 || packed[0] != 0x70)
            fail("verify-native input is not a FoMT native stream");
        BitReader reader = {packed, packed_size, 4, 0, 0};
        uint32_t format;
        if (!read_bits(&reader, 8, &format))
            fail("truncated native stream format");
        LadderEntry ladder[7];
        unsigned char *decoded;
        if (format == 1)
            decoded = decode_lz1(packed, packed_size, ladder, &decoded_size);
        else if (format == 2)
            decoded = decode_lz2(packed, packed_size, ladder, &decoded_size);
        else if (format == 3)
            decoded = decode_lz3(packed, packed_size, ladder, &decoded_size);
        else if ((format & 31u) == 0x0Au || (format & 31u) == 0x12u)
            decoded = decode_huff_lz2(packed, packed_size, ladder,
                                      &decoded_size, (format & 31u) == 0x0Au ? 4 : 8);
        else if (format == 0x0B || format == 0x13)
            decoded = decode_huff_lz3(packed, packed_size, ladder, &decoded_size,
                                      format == 0x0B ? 4 : 8);
        else
            fail("verify-native does not support this stream format");
        if (source_size != decoded_size || memcmp(source, decoded, source_size) != 0)
            fail("decoded native stream does not match the source");
        free(decoded);
        free(packed);
        free(source);
    } else if (strcmp(argv[1], "verify-lz2") == 0 ||
               strcmp(argv[1], "verify-lz3") == 0 ||
               strcmp(argv[1], "verify-huff8-lz3") == 0 ||
               strcmp(argv[1], "verify-huff4-lz3") == 0 ||
               strcmp(argv[1], "verify-huff4-lz2") == 0 ||
               strcmp(argv[1], "verify-huff8-lz2") == 0) {
        if (argc != 4 && argc != 5)
            usage();
        int lz2 = strcmp(argv[1], "verify-lz2") == 0;
        int huff8 = strcmp(argv[1], "verify-huff8-lz3") == 0;
        int huff4_lz3 = strcmp(argv[1], "verify-huff4-lz3") == 0;
        int huff4_lz2 = strcmp(argv[1], "verify-huff4-lz2") == 0;
        int huff8_lz2 = strcmp(argv[1], "verify-huff8-lz2") == 0;
        unsigned count = lz2 || huff4_lz2 || huff8_lz2 ? 7 : 3;
        size_t source_size, packed_size, decoded_size;
        unsigned char *source = read_file(argv[2], &source_size);
        unsigned char *packed = read_file(argv[3], &packed_size);
        LadderEntry expected[7], actual[7];
        if (argc == 5)
            parse_ladder(argv[4], expected, count);
        unsigned char *decoded = lz2
            ? decode_lz2(packed, packed_size, actual, &decoded_size)
            : (huff4_lz2 || huff8_lz2)
                ? decode_huff_lz2(packed, packed_size, actual, &decoded_size,
                                  huff4_lz2 ? 4 : 8)
            : huff4_lz3 ? decode_huff_lz3(packed, packed_size, actual,
                                           &decoded_size, 4)
            : huff8 ? decode_huff8_lz3(packed, packed_size, actual, &decoded_size)
                    : decode_lz3(packed, packed_size, actual, &decoded_size);
        if (source_size != decoded_size || memcmp(source, decoded, source_size) != 0)
            fail("decoded stream does not match the source");
        for (unsigned index = 0; index < count && argc == 5; index++)
            if (expected[index].width != actual[index].width)
                fail("stream ladder does not match the declared ladder");
        free(decoded);
        free(packed);
        free(source);
    } else {
        usage();
    }
    return EXIT_SUCCESS;
}
