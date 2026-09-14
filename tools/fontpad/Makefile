CC ?= gcc
CFLAGS ?= -Wall -Wextra -Werror -std=c11 -O2

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

.PHONY: all clean

all: fontpad$(EXE)

fontpad$(EXE): fontpad.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) fontpad fontpad.exe
