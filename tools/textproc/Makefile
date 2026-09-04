HOST_CXX ?= g++
HOST_CXXFLAGS ?= -std=c++17 -O2 -Wall -Wextra -Wpedantic

PROGRAM := fomt-text
SOURCE := fomt_text.cpp

.PHONY: all test clean

all: $(PROGRAM)

$(PROGRAM): $(SOURCE)
	$(HOST_CXX) $(HOST_CXXFLAGS) $< -o $@

test: $(PROGRAM)
	./$(PROGRAM) self-test

clean:
	$(RM) $(PROGRAM)
