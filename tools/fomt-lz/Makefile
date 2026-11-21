HOSTCC ?= $(CC)
CFLAGS ?= -std=c11 -Wall -Wextra -Werror -O2

ifeq ($(OS),Windows_NT)
EXE := .exe
endif

.PHONY: all clean

all: fomt-lz$(EXE)

fomt-lz$(EXE): fomt_lz.c Makefile
	$(HOSTCC) $(CPPFLAGS) $(CFLAGS) $< $(LDFLAGS) -o $@

clean:
	$(RM) fomt-lz fomt-lz.exe
