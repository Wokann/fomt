HOST_CXX ?= g++
HOST_CXXFLAGS ?= -std=c++17 -O2 -Wall -Wextra -Wpedantic

ifeq ($(OS),Windows_NT)
  EXE := .exe
else
  EXE :=
endif

# MSYS cannot execute an extensionless PE image emitted by MinGW.  Keep the
# host tool names platform-native while retaining the same Unix paths on CI.
TEXT_PROGRAM := fomt-text$(EXE)
PREPROC_PROGRAM := fomt-preproc$(EXE)
PROGRAMS := $(TEXT_PROGRAM) $(PREPROC_PROGRAM)
TEXT_SOURCE := fomt_text.cpp
PREPROC_SOURCE := fomt_preproc.cpp

.PHONY: all test clean

all: $(PROGRAMS)

$(TEXT_PROGRAM): $(TEXT_SOURCE)
	$(HOST_CXX) $(HOST_CXXFLAGS) $< -o $@

$(PREPROC_PROGRAM): $(PREPROC_SOURCE)
	$(HOST_CXX) $(HOST_CXXFLAGS) $< -o $@

test: $(PROGRAMS)
	./$(TEXT_PROGRAM) self-test
	./$(PREPROC_PROGRAM) self-test

clean:
	$(RM) $(PROGRAMS)
