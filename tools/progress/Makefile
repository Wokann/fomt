CC ?= gcc
CFLAGS ?= -Wall -Wextra -Werror -std=c11 -O2

ifeq ($(OS),Windows_NT)
EXE := .exe
endif

.PHONY: all clean

all: progress$(EXE)

progress$(EXE): progress.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $< $(LDFLAGS) -o $@

clean:
	$(RM) progress progress.exe
