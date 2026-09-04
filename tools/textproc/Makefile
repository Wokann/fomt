HOST_CXX ?= g++
HOST_CXXFLAGS ?= -std=c++17 -O2 -Wall -Wextra -Wpedantic

BUILD_DIR := build
PROGRAM := $(BUILD_DIR)/fomt-text
SOURCE := src/fomt_text.cpp

.PHONY: all test clean

all: $(PROGRAM)

$(PROGRAM): $(SOURCE)
	@mkdir -p $(BUILD_DIR)
	$(HOST_CXX) $(HOST_CXXFLAGS) $< -o $@

test: $(PROGRAM)
	$(PROGRAM) self-test

clean:
	$(RM) -r $(BUILD_DIR)
