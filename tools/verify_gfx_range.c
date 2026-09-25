// Compare a generated graphics payload with one exact reference ROM range.
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int parse_offset(const char *text, long *value)
{
    char *end;
    unsigned long parsed;

    errno = 0;
    parsed = strtoul(text, &end, 0);
    if (errno != 0 || end == text || *end != '\0' || parsed > LONG_MAX)
        return 0;
    *value = (long)parsed;
    return 1;
}

int main(int argc, char **argv)
{
    const char *rom_path = NULL;
    const char *input_path = NULL;
    FILE *rom = NULL;
    FILE *input = NULL;
    long offset = -1;
    long required_length = -1;
    long length;
    long position = 0;
    int result = 1;
    int index;

    for (index = 1; index < argc; index++) {
        if (strcmp(argv[index], "--offset") == 0 && index + 1 < argc) {
            if (!parse_offset(argv[++index], &offset))
                goto usage;
        } else if (strcmp(argv[index], "--length") == 0 && index + 1 < argc) {
            if (!parse_offset(argv[++index], &required_length))
                goto usage;
        } else if (strcmp(argv[index], "--input") == 0 && index + 1 < argc) {
            input_path = argv[++index];
        } else if (argv[index][0] == '-' || rom_path != NULL) {
            goto usage;
        } else {
            rom_path = argv[index];
        }
    }
    if (rom_path == NULL || input_path == NULL || offset < 0)
        goto usage;

    input = fopen(input_path, "rb");
    if (input == NULL) {
        perror(input_path);
        goto done;
    }
    if (fseek(input, 0, SEEK_END) != 0 || (length = ftell(input)) < 0 ||
        fseek(input, 0, SEEK_SET) != 0) {
        perror(input_path);
        goto done;
    }
    if (required_length >= 0 && length != required_length) {
        fprintf(stderr, "%s: expected 0x%lX bytes, got 0x%lX\n",
                input_path, required_length, length);
        goto done;
    }

    rom = fopen(rom_path, "rb");
    if (rom == NULL) {
        perror(rom_path);
        goto done;
    }
    if (fseek(rom, offset, SEEK_SET) != 0) {
        perror(rom_path);
        goto done;
    }
    while (position < length) {
        int actual = fgetc(input);
        int expected = fgetc(rom);
        if (actual == EOF || expected == EOF) {
            fprintf(stderr, "%s: range 0x%lX exceeds the ROM or input file\n",
                    rom_path, offset + position);
            goto done;
        }
        if (actual != expected) {
            fprintf(stderr,
                    "%s: differs from %s at 0x%lX (generated %02X, ROM %02X)\n",
                    rom_path, input_path, offset + position, actual, expected);
            goto done;
        }
        position++;
    }
    printf("%s: %s is byte-identical at 0x%lX\n", rom_path, input_path, offset);
    result = 0;
    goto done;

usage:
    fprintf(stderr, "usage: %s ROM --offset NUMBER --input FILE [--length NUMBER]\n", argv[0]);
done:
    if (rom != NULL)
        fclose(rom);
    if (input != NULL)
        fclose(input);
    return result;
}
