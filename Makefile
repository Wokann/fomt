.SUFFIXES:

# ==================
# = PROJECT CONFIG =
# ==================

include config.mk

INCLUDE_DIRS := \
  tools/agbcc/include \
  tools/libagbc++ \
  tools/libsix/include

SRC_DIR = src
ASM_DIR = asm
DATA_ASM_DIR = asm/data
BUILD_DIR = build/$(REGION_DIR)

# ====================
# = TOOL DEFINITIONS =
# ====================

TOOLCHAIN ?= $(DEVKITARM)

ifneq (,$(TOOLCHAIN))
  export PATH := $(TOOLCHAIN)/bin:$(PATH)
endif

PREFIX := arm-none-eabi-

export OBJCOPY := $(PREFIX)objcopy
export AS := $(PREFIX)as
export CPP := $(PREFIX)cpp
export LD := $(PREFIX)ld
export STRIP := $(PREFIX)strip

ifeq ($(OS),Windows_NT)
  EXE := .exe
else
  EXE :=
endif

CC1      := tools/agbcc/bin/agbcc$(EXE)
CC1PLUS  := tools/agbcc/bin/agbcp$(EXE)

OLD_CC1  := tools/agbcc/bin/old_agbcc$(EXE)

# ================
# = BUILD CONFIG =
# ================

INCFLAGS     := $(foreach dir, $(INCLUDE_DIRS), -I "$(dir)")

CPPFLAGS := $(INCFLAGS) -iquote . -iquote include -Wno-trigraphs -fno-exceptions -D$(REGION_DEFINE)=1
CFLAGS   := -g -mthumb-interwork -Wimplicit -Wparentheses -Werror -O2 -fhex-asm
CXXFLAGS := -quiet -fno-exceptions -fno-rtti -fvtable-thunks $(CFLAGS)
ASFLAGS  := $(INCFLAGS) -I . -I include -mcpu=arm7tdmi --defsym $(REGION_DEFINE)=1

ROM := $(BUILD_NAME).gba
ELF := $(ROM:.gba=.elf)
MAP := $(ROM:.gba=.map)

C_SRCS := $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/rt/*.c)
C_OBJS := $(C_SRCS:%.c=$(BUILD_DIR)/%.o)

CXX_SRCS := $(wildcard $(SRC_DIR)/*.cc $(SRC_DIR)/rt/*.cc)
CXX_OBJS := $(CXX_SRCS:%.cc=$(BUILD_DIR)/%.o)


ASM_SRCS := $(wildcard $(SRC_DIR)/*.s $(ASM_DIR)/*.s)
ASM_OBJS := $(ASM_SRCS:%.s=$(BUILD_DIR)/%.o)

DATA_ASM_SRCS := $(wildcard $(DATA_ASM_DIR)/*.s)
DATA_ASM_OBJS := $(DATA_ASM_SRCS:%.s=$(BUILD_DIR)/%.o)

ALL_OBJS := $(C_OBJS) $(CXX_OBJS) $(ASM_OBJS) $(DATA_ASM_OBJS)
ALL_DEPS := $(ALL_OBJS:%.o=%.d)

SUBDIRS := $(sort $(dir $(ALL_OBJS)))
$(shell mkdir -p $(SUBDIRS))

# ===========
# = RECIPES =
# ===========

fomt_us:
	@$(MAKE) GAME_REGION=US GAME_REVISION=0 compare

fomt_jp:
	@$(MAKE) GAME_REGION=JP GAME_REVISION=0 compare

# Both regional targets build and verify their corresponding base ROM.

compare: $(ROM)
	sha1sum -c $(BUILD_NAME).sha1

.PHONY: fomt_us fomt_jp compare

TEXT_TOOL_DIR := tools/textproc
TEXT_TOOL := $(TEXT_TOOL_DIR)/fomt-text
TEXT_COMMON_SOURCES := data/text/common/ui_error.cc

ifeq ($(GAME_REGION),JP)
TEXT_REGION := jp
TEXT_SOURCES := data/text/jp/tool.cc data/text/jp/food.cc data/text/jp/article.cc data/text/jp/calendar.cc data/text/jp/help_menu.cc data/text/jp/animal_memorial.cc data/text/jp/load_error.cc data/text/jp/menu.cc data/text/jp/not_available.cc data/text/jp/fixed_labels.cc data/text/jp/new_game_menu.cc data/text/jp/new_game_status.cc data/text/jp/new_game_help.cc data/text/jp/new_game_save.cc data/text/jp/new_game_identity.cc data/text/jp/new_game_name_entry.cc
else
TEXT_REGION := us
TEXT_SOURCES := data/text/us/tool.cc data/text/us/food.cc data/text/us/article.cc data/text/us/calendar.cc data/text/us/help_menu.cc data/text/us/animal_memorial.cc data/text/us/load_error.cc data/text/us/menu.cc data/text/us/not_available.cc data/text/us/fixed_labels.cc data/text/us/new_game_menu.cc data/text/us/new_game_status.cc data/text/us/new_game_help.cc data/text/us/new_game_save.cc data/text/us/new_game_identity.cc data/text/us/new_game_name_entry.cc
endif

TEXT_GENERATED_SOURCES := $(patsubst data/text/$(TEXT_REGION)/%.cc,$(BUILD_DIR)/data/text/%.cc,$(TEXT_SOURCES))
TEXT_OBJS := $(TEXT_GENERATED_SOURCES:.cc=.o)
TEXT_DEPS := $(TEXT_GENERATED_SOURCES:.cc=.d)
TEXT_COMMON_GENERATED_SOURCES := $(patsubst data/text/common/%.cc,$(BUILD_DIR)/data/text/common/%.cc,$(TEXT_COMMON_SOURCES))
TEXT_COMMON_OBJS := $(TEXT_COMMON_GENERATED_SOURCES:.cc=.o)
TEXT_COMMON_DEPS := $(TEXT_COMMON_GENERATED_SOURCES:.cc=.d)

ALL_OBJS += $(TEXT_OBJS) $(TEXT_COMMON_OBJS)
ALL_DEPS += $(TEXT_DEPS) $(TEXT_COMMON_DEPS)

.SECONDARY: $(TEXT_GENERATED_SOURCES) $(TEXT_COMMON_GENERATED_SOURCES)

$(TEXT_TOOL): $(TEXT_TOOL_DIR)/fomt_text.cpp $(TEXT_TOOL_DIR)/Makefile
	@$(MAKE) -C $(TEXT_TOOL_DIR) $(notdir $@)

$(BUILD_DIR)/data/text/%.cc: data/text/$(TEXT_REGION)/%.cc $(TEXT_TOOL) charmap.txt
	@mkdir -p $(dir $@)
	$(TEXT_TOOL) cpp charmap.txt $< $@

$(BUILD_DIR)/data/text/common/%.cc: data/text/common/%.cc $(TEXT_TOOL) charmap.txt
	@mkdir -p $(dir $@)
	$(TEXT_TOOL) cpp charmap.txt $< $@

$(BUILD_DIR)/data/text/%.d: $(BUILD_DIR)/data/text/%.cc
	@$(CPP) $(CPPFLAGS) $< -o $@ -MM -MG -MT $(BUILD_DIR)/data/text/$*.o

$(BUILD_DIR)/data/text/%.o: $(BUILD_DIR)/data/text/%.cc $(BUILD_DIR)/data/text/%.d
	@echo "CP $<"
	@$(CPP) $(CPPFLAGS) $< | ($(CC1PLUS) $(CXXFLAGS) -o $(BUILD_DIR)/data/text/$*.s || false)
	@sed 's/\r$$//' tools/scripts/align_sections.sh | bash -s -- $(BUILD_DIR)/data/text/$*.s
	@$(AS) $(ASFLAGS) $(BUILD_DIR)/data/text/$*.s -o $@

# ROM from ELF
%.gba: %.elf
	$(OBJCOPY) -O binary $< $@

# ELF
$(ELF): $(ALL_OBJS) $(LDS)
	@echo "LD $(LDS) $(ALL_OBJS:$(BUILD_DIR)/%=%)"
	@cd $(BUILD_DIR) && $(LD) -T $(LDS_LINK_PATH) -Map ../../$(MAP) -L../../tools/agbcc/lib -lgcc -lc $(ALL_OBJS:$(BUILD_DIR)/%=%) -o ../../$@
	@$(STRIP) -N .gcc2_compiled. $(ELF)

# C dependency file
$(BUILD_DIR)/%.d: %.c
	@$(CPP) $(CPPFLAGS) $< -o $@ -MM -MG -MT $@ -MT $(BUILD_DIR)/$*.o

# C object
$(BUILD_DIR)/%.o: %.c $(BUILD_DIR)/%.d
	@echo "CC $<"
	@$(CPP) $(CPPFLAGS) $< | $(CC1) $(CFLAGS) -o $(BUILD_DIR)/$*.s
	@sed 's/\r$$//' tools/scripts/align_sections.sh | bash -s -- $(BUILD_DIR)/$*.s
	@$(AS) $(ASFLAGS) $(BUILD_DIR)/$*.s -o $@ 

# C++ dependency file
$(BUILD_DIR)/%.d: %.cc
	@$(CPP) $(CPPFLAGS) $< -o $@ -MM -MG -MT $@ -MT $(BUILD_DIR)/$*.o

# C++ object
$(BUILD_DIR)/%.o: %.cc $(BUILD_DIR)/%.d
	@echo "CP $<"
	@$(CPP) $(CPPFLAGS) $< | ($(CC1PLUS) $(CXXFLAGS) -o $(BUILD_DIR)/$*.s || false)
	@sed 's/\r$$//' tools/scripts/align_sections.sh | bash -s -- $(BUILD_DIR)/$*.s
	@$(AS) $(ASFLAGS) $(BUILD_DIR)/$*.s -o $@

# ASM dependency file (dummy, generated with the object)
$(BUILD_DIR)/%.d: $(BUILD_DIR)/%.o
	@touch $@

# ASM object
$(BUILD_DIR)/%.o: %.s
	@echo "AS $<"
	@$(AS) $(ASFLAGS) $< -o $@ --MD $(BUILD_DIR)/$*.d

# overrides for matching
$(BUILD_DIR)/src/m4a.o: CC1 := $(OLD_CC1)

clean:
	@echo "RM $(ROM) $(ELF) $(MAP) $(BUILD_DIR)"
	@rm -f $(ROM) $(ELF) $(MAP) 
	@rm -rf $(BUILD_DIR)/

.PHONY: clean

ifneq (clean,$(MAKECMDGOALS))
-include $(ALL_DEPS)
.PRECIOUS: $(BUILD_DIR)/%.d
endif
