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

int main(int argc, char **argv)
{
    if (argc != 4 || (strcmp(argv[1], "pad-12-to-16") != 0 && strcmp(argv[1], "trim-12-from-16") != 0)) {
        fprintf(stderr, "Usage: %s pad-12-to-16 INPUT OUTPUT\n", argv[0]);
        fprintf(stderr, "       %s trim-12-from-16 INPUT OUTPUT\n", argv[0]);
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
