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

static unsigned char *encode_lz2(unsigned char const *source, size_t size,
                                 LadderEntry const ladder[7], int literal_tail,
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
            // A nine-byte extended literal is present in retail Raw-LZ2 data.
            if (run >= 9) {
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

static void read_huff8_tree(BitReader *reader, HuffNode nodes[512], unsigned *node_count)
{
    *node_count = 0;
    add_huff_node(nodes, node_count, -1);
    unsigned path = 0;
    for (unsigned depth = 0; depth < 16; depth++) {
        uint32_t count;
        if (!read_bits(reader, 8, &count))
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
            if (!read_bits(reader, 8, &symbol))
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

static unsigned read_huff8_byte(BitReader *reader, HuffNode const nodes[512])
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

static unsigned char *decode_huff8_lz3(unsigned char const *packed, size_t packed_size,
                                       LadderEntry ladder[3], size_t *decoded_size)
{
    if (packed_size < 8 || packed[0] != 0x70)
        fail("not a FoMT native 0x70 stream");
    *decoded_size = (size_t)packed[1] | ((size_t)packed[2] << 8)
                  | ((size_t)packed[3] << 16);
    if (!*decoded_size || *decoded_size > 0x40000 || (*decoded_size & 1))
        fail("invalid Huffman-8/LZ3 decoded size");
    BitReader reader = {packed, packed_size, 4, 0, 0};
    uint32_t value;
    if (!read_bits(&reader, 8, &value) || value != 0x13)
        fail("this codec requires Huffman-8 atoms, LZ mode 3 and no filter");
    HuffNode nodes[512];
    unsigned node_count;
    read_huff8_tree(&reader, nodes, &node_count);
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
            for (unsigned byte = 0; byte < pairs * 2; byte++)
                output[written++] = (unsigned char)read_huff8_byte(&reader, nodes);
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

static void usage(void)
{
    fail("usage: fomt-lz encode-lz2 SOURCE OUTPUT LADDER SLOT_SIZE "
         "[--literal-tail] | "
         "encode-lz3 SOURCE OUTPUT LADDER SLOT_SIZE | "
         "decode-lz2|decode-lz3|decode-huff8-lz3 SOURCE OUTPUT | "
         "verify-lz2|verify-lz3|verify-huff8-lz3 SOURCE PACKED [LADDER]");
}

int main(int argc, char **argv)
{
    if (argc < 4)
        usage();
    if (strcmp(argv[1], "encode-lz2") == 0 || strcmp(argv[1], "encode-lz3") == 0) {
        int lz2 = strcmp(argv[1], "encode-lz2") == 0;
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
            ? encode_lz2(source, source_size, ladder, literal_tail, &packed_size)
            : encode_lz3(source, source_size, ladder, &packed_size);
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
               strcmp(argv[1], "decode-huff8-lz3") == 0) {
        if (argc != 4)
            usage();
        int lz2 = strcmp(argv[1], "decode-lz2") == 0;
        int huff8 = strcmp(argv[1], "decode-huff8-lz3") == 0;
        size_t packed_size, decoded_size;
        unsigned char *packed = read_file(argv[2], &packed_size);
        LadderEntry ladder[7];
        unsigned char *decoded = lz2
            ? decode_lz2(packed, packed_size, ladder, &decoded_size)
            : huff8 ? decode_huff8_lz3(packed, packed_size, ladder, &decoded_size)
                    : decode_lz3(packed, packed_size, ladder, &decoded_size);
        write_file(argv[3], decoded, decoded_size);
        free(decoded);
        free(packed);
    } else if (strcmp(argv[1], "verify-lz2") == 0 ||
               strcmp(argv[1], "verify-lz3") == 0 ||
               strcmp(argv[1], "verify-huff8-lz3") == 0) {
        if (argc != 4 && argc != 5)
            usage();
        int lz2 = strcmp(argv[1], "verify-lz2") == 0;
        int huff8 = strcmp(argv[1], "verify-huff8-lz3") == 0;
        unsigned count = lz2 ? 7 : 3;
        size_t source_size, packed_size, decoded_size;
        unsigned char *source = read_file(argv[2], &source_size);
        unsigned char *packed = read_file(argv[3], &packed_size);
        LadderEntry expected[7], actual[7];
        if (argc == 5)
            parse_ladder(argv[4], expected, count);
        unsigned char *decoded = lz2
            ? decode_lz2(packed, packed_size, actual, &decoded_size)
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
