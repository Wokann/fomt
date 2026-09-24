/*
 * Minimal binary GBA header fixer.
 *
 * Its command-line interface deliberately matches the subset used by
 * pret/pokeruby's gbafix workflow: title, game code, maker code, revision,
 * and power-of-two padding.  Unlike the historical utility, this project
 * applies it after objcopy, so it only needs to operate on a flat .gba file.
 */

#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    HEADER_SIZE = 0xC0,
    TITLE_OFFSET = 0xA0,
    TITLE_SIZE = 12,
    GAME_CODE_OFFSET = 0xAC,
    GAME_CODE_SIZE = 4,
    MAKER_CODE_OFFSET = 0xB0,
    MAKER_CODE_SIZE = 2,
    FIXED_VALUE_OFFSET = 0xB2,
    DEVICE_TYPE_OFFSET = 0xB4,
    REVISION_OFFSET = 0xBC,
    COMPLEMENT_OFFSET = 0xBD,
};

static void PrintUsage(char const *program)
{
    fprintf(stderr,
            "Usage: %s <rom.gba> [-p] [-t<title>] [-c<game-code>] "
            "[-m<maker-code>] [-r<revision>] [--silent]\n",
            program);
}

static int SetFixedField(uint8_t *header, size_t offset, size_t width,
                         char const *value, char const *fieldName,
                         int exactLength)
{
    size_t length = strlen(value);

    if ((exactLength && length != width) || (!exactLength && length > width))
    {
        fprintf(stderr, "%s must contain %s%u characters\n", fieldName,
                exactLength ? "exactly " : "at most ", (unsigned)width);
        return 0;
    }

    memset(header + offset, 0, width);
    memcpy(header + offset, value, length);
    return 1;
}

static int ParseRevision(char const *value, uint8_t *result)
{
    char *end;
    unsigned long parsed;

    errno = 0;
    parsed = strtoul(value, &end, 0);
    if (errno != 0 || *value == '\0' || *end != '\0' || parsed > 0xFF)
    {
        fprintf(stderr, "Invalid game revision '%s'\n", value);
        return 0;
    }

    *result = (uint8_t)parsed;
    return 1;
}

static uint8_t CalculateComplement(uint8_t const *header)
{
    uint8_t sum = 0;
    size_t index;

    for (index = TITLE_OFFSET; index < COMPLEMENT_OFFSET; ++index)
        sum = (uint8_t)(sum + header[index]);

    return (uint8_t)(-(0x19 + sum));
}

static int PadToPowerOfTwo(FILE *file, long size)
{
    long targetSize = 1;
    long remaining;

    while (targetSize < size)
    {
        if (targetSize > LONG_MAX / 2)
        {
            fprintf(stderr, "ROM is too large to pad safely\n");
            return 0;
        }
        targetSize *= 2;
    }

    if (targetSize == size)
        return 1;

    if (fseek(file, 0, SEEK_END) != 0)
    {
        perror("Unable to seek ROM for padding");
        return 0;
    }

    remaining = targetSize - size;
    while (remaining-- != 0)
    {
        if (fputc(0xFF, file) == EOF)
        {
            perror("Unable to pad ROM");
            return 0;
        }
    }

    return 1;
}

int main(int argc, char **argv)
{
    char const *path = NULL;
    char const *title = NULL;
    char const *gameCode = NULL;
    char const *makerCode = NULL;
    char const *revisionValue = NULL;
    FILE *file;
    uint8_t header[HEADER_SIZE];
    uint8_t revision = 0;
    int pad = 0;
    int silent = 0;
    int index;
    long size;

    for (index = 1; index < argc; ++index)
    {
        char const *argument = argv[index];

        if (strcmp(argument, "--silent") == 0)
        {
            silent = 1;
        }
        else if (strcmp(argument, "-p") == 0)
        {
            pad = 1;
        }
        else if (strncmp(argument, "-t", 2) == 0)
        {
            title = argument + 2;
        }
        else if (strncmp(argument, "-c", 2) == 0)
        {
            gameCode = argument + 2;
        }
        else if (strncmp(argument, "-m", 2) == 0)
        {
            makerCode = argument + 2;
        }
        else if (strncmp(argument, "-r", 2) == 0)
        {
            revisionValue = argument + 2;
        }
        else if (argument[0] == '-')
        {
            PrintUsage(argv[0]);
            return EXIT_FAILURE;
        }
        else if (path == NULL)
        {
            path = argument;
        }
        else
        {
            PrintUsage(argv[0]);
            return EXIT_FAILURE;
        }
    }

    if (path == NULL)
    {
        PrintUsage(argv[0]);
        return EXIT_FAILURE;
    }

    file = fopen(path, "r+b");
    if (file == NULL)
    {
        perror(path);
        return EXIT_FAILURE;
    }

    if (fseek(file, 0, SEEK_END) != 0 || (size = ftell(file)) < HEADER_SIZE)
    {
        perror("Unable to read ROM size");
        fclose(file);
        return EXIT_FAILURE;
    }

    if (fseek(file, 0, SEEK_SET) != 0 ||
        fread(header, sizeof(header), 1, file) != 1)
    {
        perror("Unable to read GBA header");
        fclose(file);
        return EXIT_FAILURE;
    }

    if ((title != NULL && !SetFixedField(header, TITLE_OFFSET, TITLE_SIZE,
                                          title, "Title", 0)) ||
        (gameCode != NULL &&
         !SetFixedField(header, GAME_CODE_OFFSET, GAME_CODE_SIZE, gameCode,
                        "Game code", 1)) ||
        (makerCode != NULL &&
         !SetFixedField(header, MAKER_CODE_OFFSET, MAKER_CODE_SIZE, makerCode,
                        "Maker code", 1)) ||
        (revisionValue != NULL && !ParseRevision(revisionValue, &revision)))
    {
        fclose(file);
        return EXIT_FAILURE;
    }

    header[FIXED_VALUE_OFFSET] = 0x96;
    header[DEVICE_TYPE_OFFSET] = 0;
    if (revisionValue != NULL)
        header[REVISION_OFFSET] = revision;
    header[COMPLEMENT_OFFSET] = CalculateComplement(header);

    if (fseek(file, 0, SEEK_SET) != 0 ||
        fwrite(header, sizeof(header), 1, file) != 1)
    {
        perror("Unable to write GBA header");
        fclose(file);
        return EXIT_FAILURE;
    }

    if (pad && !PadToPowerOfTwo(file, size))
    {
        fclose(file);
        return EXIT_FAILURE;
    }

    if (fclose(file) != 0)
    {
        perror("Unable to close ROM");
        return EXIT_FAILURE;
    }

    if (!silent)
        puts("ROM header fixed.");
    return EXIT_SUCCESS;
}
