CXX ?= g++
CXXFLAGS ?= -O2 -Wall -Wextra -Wpedantic

SRCS := $(wildcard src/*.cc)
HEADERS := $(wildcard src/*.hh)
CORE_SRCS := $(filter-out src/main.cc,$(SRCS))

ifeq ($(OS),Windows_NT)
EXE := .exe
LDLIBS += -lshell32
LDFLAGS += -static
else
EXE :=
endif

.PHONY: all check clean

all: mary$(EXE)

mary$(EXE): $(SRCS) $(HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -std=c++17 $(SRCS) -o $@ $(LDFLAGS) $(LDLIBS)

mary-check$(EXE): tests/roundtrip.cc $(CORE_SRCS) $(HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -std=c++17 -Isrc tests/roundtrip.cc $(CORE_SRCS) -o $@ $(LDFLAGS) $(LDLIBS)

check: mary$(EXE) mary-check$(EXE)
	./mary$(EXE) --help
	./mary-check$(EXE)

clean:
	$(RM) mary mary.exe mary-check mary-check.exe
