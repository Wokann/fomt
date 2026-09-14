/*
 * FoMT 8x12 font record bridge for gbagfx.
 *
 * gbagfx operates on whole 8x8 tiles.  FoMT's single-width glyphs are one
 * byte per row for twelve rows, so this tool appends or verifies four blank
 * rows per glyph while keeping the actual font bytes lossless.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { NATIVE_RECORD_SIZE = 12, PADDED_RECORD_SIZE = 16 };

static void Fail(const char *message)
{
    fprintf(stderr, "fontpad: %s\n", message);
    exit(EXIT_FAILURE);
}

static uint8_t *ReadFile(const char *path, size_t *size)
{
    FILE *file = fopen(path, "rb");
    if (file == NULL)
        Fail("cannot open input");
    if (fseek(file, 0, SEEK_END) != 0)
        Fail("cannot seek input");
    long length = ftell(file);
    if (length < 0)
        Fail("cannot measure input");
    if (fseek(file, 0, SEEK_SET) != 0)
        Fail("cannot rewind input");
    uint8_t *data = malloc((size_t)length == 0 ? 1 : (size_t)length);
    if (data == NULL)
        Fail("out of memory");
    if (fread(data, 1, (size_t)length, file) != (size_t)length)
        Fail("cannot read input");
    fclose(file);
    *size = (size_t)length;
    return data;
}

static void WriteFile(const char *path, const uint8_t *data, size_t size)
{
    FILE *file = fopen(path, "wb");
    if (file == NULL)
        Fail("cannot open output");
    if (fwrite(data, 1, size, file) != size)
        Fail("cannot write output");
    if (fclose(file) != 0)
        Fail("cannot close output");
}

static size_t ParsePositive(const char *text, const char *description)
{
    char *end;
    unsigned long value = strtoul(text, &end, 10);
    if (*text == '\0' || *end != '\0' || value == 0)
        Fail(description);
    return (size_t)value;
}

static void PackGrid(const uint8_t *input, size_t glyphCount, size_t columns,
                     const char *outputPath)
{
    size_t rows = (glyphCount + columns - 1) / columns;
    size_t outputSize = rows * columns * PADDED_RECORD_SIZE;
    uint8_t *output = calloc(outputSize == 0 ? 1 : outputSize, 1);
    if (output == NULL)
        Fail("out of memory");

    for (size_t row = 0; row < rows; row++) {
        for (size_t tileRow = 0; tileRow < 2; tileRow++) {
            for (size_t column = 0; column < columns; column++) {
                size_t glyph = row * columns + column;
                if (glyph >= glyphCount)
                    continue;
                const uint8_t *source = input + glyph * NATIVE_RECORD_SIZE;
                uint8_t *destination = output
                    + ((row * 2 + tileRow) * columns + column) * 8;
                size_t copySize = tileRow == 0 ? 8 : 4;
                memcpy(destination, source + tileRow * 8, copySize);
            }
        }
    }

    WriteFile(outputPath, output, outputSize);
    free(output);
}

static void TrimGrid(const uint8_t *input, size_t inputSize, size_t columns,
                     size_t glyphCount, const char *outputPath)
{
    size_t rows = (glyphCount + columns - 1) / columns;
    size_t expectedSize = rows * columns * PADDED_RECORD_SIZE;
    if (inputSize != expectedSize)
        Fail("PNG tile data has an unexpected grid size");
    uint8_t *output = malloc(glyphCount == 0 ? 1 : glyphCount * NATIVE_RECORD_SIZE);
    if (output == NULL)
        Fail("out of memory");

    for (size_t row = 0; row < rows; row++) {
        for (size_t column = 0; column < columns; column++) {
            size_t glyph = row * columns + column;
            const uint8_t *top = input + (row * 2 * columns + column) * 8;
            const uint8_t *bottom = input + ((row * 2 + 1) * columns + column) * 8;
            if (glyph >= glyphCount) {
                for (size_t byte = 0; byte < 8; byte++) {
                    if (top[byte] != 0 || bottom[byte] != 0)
                        Fail("PNG changed a grid padding tile");
                }
                continue;
            }
            if (bottom[4] != 0 || bottom[5] != 0 || bottom[6] != 0 || bottom[7] != 0)
                Fail("PNG changed the four padding rows of an 8x12 glyph");
            uint8_t *destination = output + glyph * NATIVE_RECORD_SIZE;
            memcpy(destination, top, 8);
            memcpy(destination + 8, bottom, 4);
        }
    }

    WriteFile(outputPath, output, glyphCount * NATIVE_RECORD_SIZE);
    free(output);
}

int main(int argc, char **argv)
{
    if (argc == 5 && strcmp(argv[1], "pack-grid-12-to-16") == 0) {
        size_t inputSize;
        uint8_t *input = ReadFile(argv[2], &inputSize);
        if (inputSize % NATIVE_RECORD_SIZE != 0)
            Fail("input does not contain complete font records");
        PackGrid(input, inputSize / NATIVE_RECORD_SIZE,
                 ParsePositive(argv[4], "grid column count must be positive"), argv[3]);
        free(input);
        return EXIT_SUCCESS;
    }
    if (argc == 6 && strcmp(argv[1], "trim-grid-12-from-16") == 0) {
        size_t inputSize;
        uint8_t *input = ReadFile(argv[2], &inputSize);
        TrimGrid(input, inputSize,
                 ParsePositive(argv[4], "grid column count must be positive"),
                 ParsePositive(argv[5], "glyph count must be positive"), argv[3]);
        free(input);
        return EXIT_SUCCESS;
    }
    if (argc != 4 || (strcmp(argv[1], "pad-12-to-16") != 0 && strcmp(argv[1], "trim-12-from-16") != 0)) {
        fprintf(stderr, "Usage: %s pad-12-to-16 INPUT OUTPUT\n", argv[0]);
        fprintf(stderr, "       %s trim-12-from-16 INPUT OUTPUT\n", argv[0]);
        fprintf(stderr, "       %s pack-grid-12-to-16 INPUT OUTPUT COLUMNS\n", argv[0]);
        fprintf(stderr, "       %s trim-grid-12-from-16 INPUT OUTPUT COLUMNS GLYPHS\n", argv[0]);
        return EXIT_FAILURE;
    }

    const int pad = strcmp(argv[1], "pad-12-to-16") == 0;
    const size_t sourceStride = pad ? NATIVE_RECORD_SIZE : PADDED_RECORD_SIZE;
    const size_t destinationStride = pad ? PADDED_RECORD_SIZE : NATIVE_RECORD_SIZE;
    size_t inputSize;
    uint8_t *input = ReadFile(argv[2], &inputSize);
    if (inputSize % sourceStride != 0)
        Fail("input does not contain complete font records");
    size_t count = inputSize / sourceStride;
    uint8_t *output = calloc(count == 0 ? 1 : count, destinationStride);
    if (output == NULL)
        Fail("out of memory");

    for (size_t index = 0; index < count; index++) {
        const uint8_t *source = input + index * sourceStride;
        uint8_t *destination = output + index * destinationStride;
        if (!pad && (source[12] != 0 || source[13] != 0 || source[14] != 0 || source[15] != 0))
            Fail("PNG changed the four padding rows of an 8x12 glyph");
        memcpy(destination, source, NATIVE_RECORD_SIZE);
    }

    WriteFile(argv[3], output, count * destinationStride);
    free(output);
    free(input);
    return EXIT_SUCCESS;
}
