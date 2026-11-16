.SUFFIXES:
.SECONDARY:
.DELETE_ON_ERROR:
.DEFAULT_GOAL := all

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
ARM_CC1PLUS := tools/agbcc/bin/agbcp_arm$(EXE)
HOSTCC ?= cc

OLD_CC1  := tools/agbcc/bin/old_agbcc$(EXE)

# ROM header values live in config.mk, as in pret/pokeruby.  The small host
# tool writes them only after objcopy has produced the flat GBA image.
GBAFIX_DIR := tools/gbafix
GBAFIX := $(GBAFIX_DIR)/gbafix$(EXE)

# Host-side graphics tools.  gbagfx is vendored from pokeemerald under its
# original licence; fontpad only bridges FoMT's 8x12 1bpp glyph records to
# gbagfx's 8x8-tile input without changing the authored PNG workflow.
GFX_TOOL_DIR := tools/gbagfx
GFX_TOOL := $(GFX_TOOL_DIR)/gbagfx$(EXE)
FOMT_LZ_TOOL := tools/fomt-lz$(EXE)
GFX_TOOL_SOURCES := $(wildcard $(GFX_TOOL_DIR)/*.c $(GFX_TOOL_DIR)/*.h) $(GFX_TOOL_DIR)/Makefile
SCANINC_DIR := tools/scaninc
SCANINC := $(SCANINC_DIR)/scaninc$(EXE)
SCANINC_SOURCES := $(wildcard $(SCANINC_DIR)/*.cpp $(SCANINC_DIR)/*.h) $(SCANINC_DIR)/Makefile
FONT_PAD_DIR := tools/fontpad
FONT_PAD := $(FONT_PAD_DIR)/fontpad$(EXE)
OAM_PACK_DIR := tools/oam_pack
OAM_PACK := $(OAM_PACK_DIR)/oam_pack$(EXE)
GFX_RANGE_VERIFY := tools/verify-gfx-range$(EXE)
# ================
# = BUILD CONFIG =
# ================

INCFLAGS     := $(foreach dir, $(INCLUDE_DIRS), -I "$(dir)")

CPPFLAGS := $(INCFLAGS) -iquote $(BUILD_DIR) -I . -iquote . -iquote include -Wno-trigraphs -fno-exceptions -D$(REGION_DEFINE)=1
CFLAGS   := -g -mthumb-interwork -Wimplicit -Wparentheses -Werror -O2 -fhex-asm
CXXFLAGS := -quiet -fno-exceptions -fno-rtti -fvtable-thunks $(CFLAGS)
ASFLAGS  := $(INCFLAGS) -I . -I include -mcpu=arm7tdmi --defsym $(REGION_DEFINE)=1
SCANINC_DEFINES := -D$(REGION_DEFINE) $(addprefix -U,$(filter-out $(REGION_DEFINE),REGION_JP REGION_US REGION_EU REGION_DE))

ROM := $(BUILD_NAME).gba
ELF := $(ROM:.gba=.elf)
MAP := $(ROM:.gba=.map)

C_SRCS := $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/rt/*.c)
C_OBJS := $(C_SRCS:%.c=$(BUILD_DIR)/%.o)

CXX_SRCS := $(filter-out $(SRC_DIR)/reference_guide.cc,$(wildcard $(SRC_DIR)/*.cc $(SRC_DIR)/rt/*.cc))
CXX_OBJS := $(CXX_SRCS:%.cc=$(BUILD_DIR)/%.o)

ASM_SRCS := $(wildcard $(SRC_DIR)/*.s $(ASM_DIR)/*.s)
ASM_OBJS := $(ASM_SRCS:%.s=$(BUILD_DIR)/%.o)

DATA_ASM_SRCS := $(wildcard $(DATA_ASM_DIR)/*.s)
DATA_ASM_OBJS := $(DATA_ASM_SRCS:%.s=$(BUILD_DIR)/%.o)

ALL_OBJS := $(C_OBJS) $(CXX_OBJS) $(ASM_OBJS) $(DATA_ASM_OBJS)
ALL_DEPS := $(ALL_OBJS:%.o=%.d)

include graphics_file_rules.mk

SUBDIRS := $(sort $(dir $(ALL_OBJS)))
$(shell mkdir -p $(SUBDIRS))

# ===========
# = RECIPES =
# ===========

all: $(ROM)

fomt_us:
	@$(MAKE) GAME_REGION=US GAME_REVISION=0 compare

fomt_jp:
	@$(MAKE) GAME_REGION=JP GAME_REVISION=0 compare

fomt_eu:
	@$(MAKE) GAME_REGION=EU GAME_REVISION=0 compare

fomt_de:
	@$(MAKE) GAME_REGION=DE GAME_REVISION=0 compare

# Every regional target builds and verifies its corresponding base ROM.
compare_eu:
	@$(MAKE) GAME_REGION=EU GAME_REVISION=0 compare

compare_de:
	@$(MAKE) GAME_REGION=DE GAME_REVISION=0 compare

# US and JP targets build and verify their corresponding base ROM.

compare: $(ROM)
	tr -d '\r' < $(BUILD_NAME).sha1 | sha1sum -c -

.PHONY: all fomt_us fomt_jp fomt_eu fomt_de compare_eu compare_de compare

TEXT_TOOL_DIR := tools/textproc
TEXT_TOOL := $(TEXT_TOOL_DIR)/fomt-text$(EXE)
TEXT_PREPROC := $(TEXT_TOOL_DIR)/fomt-preproc$(EXE)
TEXT_TOOLS := $(TEXT_TOOL) $(TEXT_PREPROC)
# Select one encoding table for C/C++, guides, and Mary scripts.
TEXT_CHARMAP ?= charmap.txt

ifeq ($(GAME_REGION),JP)
TEXT_REGION := jp
else ifeq ($(GAME_REGION),EU)
TEXT_REGION := eu
else ifeq ($(GAME_REGION),DE)
TEXT_REGION := de
else
TEXT_REGION := us
endif

# Every ordinary .cc file joins the same C++ compilation channel below.  Files
# included at a physical point inside an owning src module must not also become
# standalone objects.  Enumerate existing text files with wildcard, then use
# the actual src include relation to select those fragments.  Renaming or
# adding an included fragment therefore needs no Makefile update.
TEXT_FRAGMENT_CANDIDATES := $(wildcard data/text/$(TEXT_REGION)/*.cc)
FOMT_TEXT_INCLUDE_LPAREN := (
FOMT_TEXT_INCLUDE_RPAREN := )
FOMT_TEXT_INCLUDE_REGEX_LPAREN := \(
FOMT_TEXT_INCLUDE_REGEX_RPAREN := \)
TEXT_FRAGMENT_REGION_INCLUDES := $(shell grep -RhoE '^#include FOMT_TEXT_INCLUDE$(FOMT_TEXT_INCLUDE_REGEX_LPAREN)[[:alnum:]_]+\.cc$(FOMT_TEXT_INCLUDE_REGEX_RPAREN)' $(SRC_DIR) include | cut -d '$(FOMT_TEXT_INCLUDE_LPAREN)' -f2 | tr -d '$(FOMT_TEXT_INCLUDE_RPAREN)' | sed 's|^|data/text/$(TEXT_REGION)/|' | sort | uniq)
TEXT_FRAGMENT_INCLUDES := $(TEXT_FRAGMENT_REGION_INCLUDES)
TEXT_FRAGMENT_SOURCES := $(sort $(filter $(TEXT_FRAGMENT_CANDIDATES),$(TEXT_FRAGMENT_INCLUDES)))

# The staff-credit source and the Reference Guide pages use their own visible
# authoring formats.  The staff source is lowered in-place by its owning
# src/staff_credits.cc unit; guide pages remain a generated aggregate source.
STAFF_CREDITS_SOURCE := data/text/$(TEXT_REGION)/staff_credits.cc

REGION_TEXT_SOURCES := $(filter-out $(TEXT_FRAGMENT_SOURCES) $(STAFF_CREDITS_SOURCE),$(wildcard data/text/$(TEXT_REGION)/*.cc))
REGION_TEXT_ORDINARY_OBJS := $(patsubst data/text/$(TEXT_REGION)/%.cc,$(BUILD_DIR)/data/text/%.o,$(REGION_TEXT_SOURCES))
REGION_TEXT_ORDINARY_DEPS := $(REGION_TEXT_ORDINARY_OBJS:.o=.d)
REGION_TEXT_OBJS := $(REGION_TEXT_ORDINARY_OBJS)
REGION_TEXT_DEPS := $(REGION_TEXT_ORDINARY_DEPS)

# The manifest records directory order, physical ROM-group order, and whether
# an auxiliary page participates in the master directory.
GUIDE_COLLECTION_MANIFEST := src/reference_guide.cc
GUIDE_PAGE_SOURCES := $(wildcard data/text/$(TEXT_REGION)/reference_guide/*.cc)
GUIDE_GENERATED_SOURCE := $(BUILD_DIR)/src/reference_guide.cc
GUIDE_GENERATED_OBJ := $(BUILD_DIR)/src/reference_guide.o
GUIDE_GENERATED_DEP := $(BUILD_DIR)/src/reference_guide.d

MARY_TOOL_DIR := tools/mary
MARY_TOOL := $(MARY_TOOL_DIR)/mary$(EXE)
MARY_TOOL_SOURCES := $(wildcard $(MARY_TOOL_DIR)/src/*.cc $(MARY_TOOL_DIR)/src/*.hh) $(MARY_TOOL_DIR)/Makefile
MARY_SOURCE_DIR := data/scripts/$(REGION_DIR)
MARY_OUTPUT_DIR := $(BUILD_DIR)/data/scripts
MARY_LIBRARY := $(MARY_SOURCE_DIR)/fomt_callables.mary.h
MARY_SCRIPT_TABLE := $(MARY_SOURCE_DIR)/fomt_scripts.mary.h
MARY_CONSTANTS := include/fomt_constants.mary.h
MARY_SOURCES := $(wildcard $(MARY_SOURCE_DIR)/*.mary.c)
MARY_BUNDLE_STAMP := $(MARY_OUTPUT_DIR)/.mary-bundle.stamp
MARY_SCRIPTS_ASM := $(MARY_OUTPUT_DIR)/scripts.s
MARY_SCRIPT_TABLE_ASM := $(MARY_OUTPUT_DIR)/script_table.s
MARY_SCRIPTS_BIN := $(MARY_OUTPUT_DIR)/scripts.bin
MARY_BUNDLE_DEP := $(MARY_OUTPUT_DIR)/scripts.d
MARY_BUNDLE_OUTPUTS := $(MARY_SCRIPTS_ASM) $(MARY_SCRIPT_TABLE_ASM) $(MARY_SCRIPTS_BIN) $(MARY_BUNDLE_DEP)
MARY_SCRIPTS_OBJ := $(MARY_OUTPUT_DIR)/scripts.o
MARY_SCRIPT_TABLE_OBJ := $(MARY_OUTPUT_DIR)/script_table.o

ALL_OBJS += $(REGION_TEXT_OBJS) $(GUIDE_GENERATED_OBJ) $(MARY_SCRIPTS_OBJ) $(MARY_SCRIPT_TABLE_OBJ)
ALL_DEPS += $(REGION_TEXT_DEPS) $(GUIDE_GENERATED_DEP) $(MARY_BUNDLE_DEP)

.SECONDARY: $(GUIDE_GENERATED_SOURCE) $(MARY_BUNDLE_OUTPUTS)

# Bootstrap generated type metadata before scanning headers. Only actual
# include users acquire a normal dependency on it in their compiler .d file.
$(ALL_DEPS): | $(INTRO_SCENE_SIZE_HEADER) $(UI_GRAPHICS_SIZE_HEADER)

$(TEXT_TOOLS): $(TEXT_TOOL_DIR)/fomt_text.cpp $(TEXT_TOOL_DIR)/fomt_preproc.cpp $(TEXT_TOOL_DIR)/Makefile
	@$(MAKE) -C $(TEXT_TOOL_DIR) $(notdir $@)

$(GBAFIX): $(GBAFIX_DIR)/gbafix.c $(GBAFIX_DIR)/Makefile
	@$(MAKE) -C $(GBAFIX_DIR) $(notdir $@)

$(SCANINC): $(SCANINC_SOURCES)
	@$(MAKE) -C $(SCANINC_DIR) $(notdir $@)

$(MARY_TOOL): $(MARY_TOOL_SOURCES)
	@$(MAKE) -C $(MARY_TOOL_DIR) $(notdir $@)

$(FOMT_LZ_TOOL): tools/fomt_lz.c
	@$(HOSTCC) -std=c11 -Wall -Wextra -Werror -O2 $< -o $@

$(GFX_RANGE_VERIFY): tools/verify_gfx_range.c
	@$(HOSTCC) -std=c11 -Wall -Wextra -Werror -O2 $< -o $@

# Mary owns the complete packed RIFF script stream.  Its three headers remain
# explicit inputs: callables and slot names live with the selected scripts,
# while the C/C++-shared constant table lives in include/.
# Use the same optional fixes for native code and Mary scripts.
MARY_BUGFIX_FLAG = $(shell $(CPP) -dM include/config.h | awk '$$2 == "BUGFIX" { print "-D BUGFIX" }')
$(MARY_BUNDLE_STAMP): include/config.h $(MARY_TOOL) $(MARY_SOURCES) $(MARY_LIBRARY) $(MARY_SCRIPT_TABLE) $(MARY_CONSTANTS) $(TEXT_CHARMAP)
	@mkdir -p $(MARY_OUTPUT_DIR)
	@$(MARY_TOOL) bundle $(MARY_SOURCE_DIR) -o $(MARY_OUTPUT_DIR) --layout packed --library $(MARY_LIBRARY) --script-table $(MARY_SCRIPT_TABLE) --constants $(MARY_CONSTANTS) --charmap $(TEXT_CHARMAP) -D MARY_FOMT_$(GAME_REGION) $(MARY_BUGFIX_FLAG)
	@touch $@

$(MARY_BUNDLE_OUTPUTS): $(MARY_BUNDLE_STAMP)

$(MARY_SCRIPTS_OBJ): $(MARY_SCRIPTS_ASM)
	@echo "AS $<"
	@$(AS) $(ASFLAGS) $< -o $@

$(MARY_SCRIPT_TABLE_OBJ): $(MARY_SCRIPT_TABLE_ASM)
	@echo "AS $<"
	@$(AS) $(ASFLAGS) $< -o $@

# Every ordinary C/C++ unit first becomes a normal preprocessed source file.
# fomt-text then lowers only its quoted game text to FOMT byte literals; it
# leaves ALIGN(n), SECTION(...), structures, and pointer tables as C/C++.
# fomt-preproc consumes the resulting source plus agbcc/agbcp assembly to
# normalize assembly syntax and data/executable-section alignment. The
# compiler owns object definitions and their pointer relocations.
# Preserve CPP line markers: agbcp uses the original file boundaries for
# interface/implementation pragmas as well as source diagnostics.
define FOMT_COMPILE_CPP
@mkdir -p $(dir $(basename $@).fomt-preprocessed.cc)
@$(CPP) $(1) $(CPPFLAGS) $< > $(basename $@).fomt-preprocessed.cc
@$(TEXT_TOOL) source $(TEXT_CHARMAP) $(GAME_REGION) $(basename $@).fomt-preprocessed.cc $(basename $@).fomt-text.cc $(FOMT_TEXT_SOURCE_ARGS)
@$(CC1PLUS) $(CXXFLAGS) -o $(basename $@).s $(basename $@).fomt-text.cc
@$(TEXT_PREPROC) asm $(basename $@).fomt-text.cc $(basename $@).s
@$(AS) $(ASFLAGS) $(basename $@).s -o $@
endef

define FOMT_COMPILE_C
@mkdir -p $(dir $(basename $@).fomt-preprocessed.c)
@$(CPP) $(1) $(CPPFLAGS) $< > $(basename $@).fomt-preprocessed.c
@$(TEXT_TOOL) source $(TEXT_CHARMAP) $(GAME_REGION) $(basename $@).fomt-preprocessed.c $(basename $@).fomt-text.c $(FOMT_TEXT_SOURCE_ARGS)
@$(CC1) $(CFLAGS) -o $(basename $@).s $(basename $@).fomt-text.c
@$(TEXT_PREPROC) asm $(basename $@).fomt-text.c $(basename $@).s
@$(AS) $(ASFLAGS) $(basename $@).s -o $@
endef

# Every article remains a deliberately non-C++ text source.  One collection
# invocation emits one physical C++ object: master directory, group text, and
# the matching line-pointer tables in exact ROM order.
$(GUIDE_GENERATED_SOURCE): $(GUIDE_COLLECTION_MANIFEST) $(GUIDE_PAGE_SOURCES) $(TEXT_TOOL) $(TEXT_CHARMAP) include/config.h
	@mkdir -p $(dir $@)
	$(TEXT_TOOL) guide-collection $(TEXT_CHARMAP) $(GAME_REGION) $(GUIDE_COLLECTION_MANIFEST) $@ $(MARY_BUGFIX_FLAG)

$(BUILD_DIR)/src/reference_guide.d: $(GUIDE_GENERATED_SOURCE)
	@$(CPP) $(CPPFLAGS) $< -o $@ -MM -MG -MP -MT $(BUILD_DIR)/src/reference_guide.o

$(BUILD_DIR)/src/reference_guide.o: $(GUIDE_GENERATED_SOURCE) $(BUILD_DIR)/src/reference_guide.d $(TEXT_TOOLS) $(TEXT_CHARMAP) $(CC1PLUS)
	@echo "CP $<"
	$(call FOMT_COMPILE_CPP,)

# The selected regional .cc sources map to the region-neutral object paths
# used by the linker scripts.  Their recipe is the same universal pipeline as
# every other C++ translation unit; no text-specific staging source is made.
$(REGION_TEXT_ORDINARY_DEPS): $(BUILD_DIR)/data/text/%.d: data/text/$(TEXT_REGION)/%.cc
	@mkdir -p $(dir $@)
	@$(CPP) $(CPPFLAGS) $< -o $@ -MM -MG -MP -MT $@ -MT $(BUILD_DIR)/data/text/$*.o

$(REGION_TEXT_ORDINARY_OBJS): $(BUILD_DIR)/data/text/%.o: data/text/$(TEXT_REGION)/%.cc $(BUILD_DIR)/data/text/%.d $(TEXT_TOOLS) $(TEXT_CHARMAP) $(CC1PLUS)
	@echo "CP $<"
	$(call FOMT_COMPILE_CPP,)

# ROM from ELF
$(ROM): $(ELF) $(GBAFIX) config.mk
	$(OBJCOPY) -O binary $< $@
	@$(GBAFIX) $@ -p -t"$(TITLE)" -c$(GAME_CODE) -m$(MAKER_CODE) -r$(GAME_REVISION) --silent

# ELF
$(ELF): $(ALL_OBJS) $(LDS)
	@echo "LD $(LDS) $(ALL_OBJS:$(BUILD_DIR)/%=%)"
	@cd $(BUILD_DIR) && $(LD) -T $(LDS_LINK_PATH) -Map "$(abspath $(MAP))" -L../../tools/agbcc/lib -lgcc -lc $(ALL_OBJS:$(BUILD_DIR)/%=%) -o "$(abspath $@)"
	@$(STRIP) -N .gcc2_compiled. $(ELF)

# C dependency file
$(BUILD_DIR)/%.d: %.c
	@mkdir -p $(dir $@)
	@$(CPP) $(CPPFLAGS) $< -o $@ -MM -MG -MP -MT $@ -MT $(BUILD_DIR)/$*.o

# C object
$(BUILD_DIR)/%.o: %.c $(BUILD_DIR)/%.d $(TEXT_TOOLS) $(TEXT_CHARMAP) $(CC1)
	@echo "CC $<"
	$(call FOMT_COMPILE_C,)

# C++ dependency file
$(BUILD_DIR)/%.d: %.cc
	@mkdir -p $(dir $@)
	@$(CPP) $(CPPFLAGS) $< -o $@ -MM -MG -MP -MT $@ -MT $(BUILD_DIR)/$*.o

# C++ object
$(BUILD_DIR)/%.o: %.cc $(BUILD_DIR)/%.d $(TEXT_TOOLS) $(TEXT_CHARMAP) $(CC1PLUS)
	@echo "CP $<"
	$(call FOMT_COMPILE_CPP,)

# This remains the ordinary C++ rule above.  Its explicit authoring marker
# needs only the selected visible-credit input; field layout is source-derived.
$(BUILD_DIR)/src/staff_credits.o: FOMT_TEXT_SOURCE_ARGS := $(STAFF_CREDITS_SOURCE)
$(BUILD_DIR)/src/staff_credits.o: $(STAFF_CREDITS_SOURCE)

# Scan before assembly so a missing generated resource can be built from its
# authored source. Nested include edits also update the dependency graph.
$(BUILD_DIR)/%.d: %.s $(SCANINC) Makefile config.mk
	@mkdir -p $(dir $@)
	@$(SCANINC) -M $@ $(SCANINC_DEFINES) $(INCFLAGS) -I . -I include $<

# ASM object
$(BUILD_DIR)/%.o: %.s $(BUILD_DIR)/%.d
	@echo "AS $<"
	@$(AS) $(ASFLAGS) $< -o $@

# These classes have one definition owner and no separately retained weak code.
# Keep their compiler-owned tables in the ordinary read-only section.
$(BUILD_DIR)/src/scene.o \
$(BUILD_DIR)/src/town_map_selection.o \
$(BUILD_DIR)/src/scene_sprite_group.o \
$(BUILD_DIR)/src/scene_sprite_indexed.o \
$(BUILD_DIR)/src/frisbee_scoreboard_lifetimes.o \
$(BUILD_DIR)/src/frisbee_lifetimes.o \
$(BUILD_DIR)/src/horse_race_lifetimes.o \
$(BUILD_DIR)/src/farm_status_screen_lifetimes.o \
$(BUILD_DIR)/src/animal_festival_selection_lifetimes.o \
$(BUILD_DIR)/src/new_game_birthday_input_lifetimes.o \
$(BUILD_DIR)/src/farm_map_screen_lifetimes.o \
$(BUILD_DIR)/src/records_screen_lifetimes.o \
$(BUILD_DIR)/src/scroll_menu_lifetimes.o \
$(BUILD_DIR)/src/staff_credits_lifetimes.o \
$(BUILD_DIR)/src/town_map_lifetimes.o \
$(BUILD_DIR)/src/scene_reference_page_lifetimes.o \
$(BUILD_DIR)/src/script_engine_lifetimes.o \
$(BUILD_DIR)/src/script_jump_table_search.o \
$(BUILD_DIR)/src/farming_tutorial.o \
$(BUILD_DIR)/src/farming_tutorial_transition_lifetimes.o \
$(BUILD_DIR)/src/scene_gamecube_link_lifetimes.o \
$(BUILD_DIR)/src/gamecube_link_scene_lifetimes.o \
$(BUILD_DIR)/src/farming_tutorial_world_lifetimes.o \
$(BUILD_DIR)/src/farming_tutorial_map_lifetimes.o \
$(BUILD_DIR)/src/farming_tutorial_player_lifetimes.o \
$(BUILD_DIR)/src/player_actor_lifetimes.o \
$(BUILD_DIR)/src/npc_actor_lifetimes.o \
$(BUILD_DIR)/src/scene_cooking_lifetimes.o \
$(BUILD_DIR)/src/scene_calendar_lifetimes.o \
$(BUILD_DIR)/src/scene_minigames.o \
$(BUILD_DIR)/src/scene_minigames_lifetimes.o \
$(BUILD_DIR)/src/scene_animal_care_minigame_lifetimes.o \
$(BUILD_DIR)/src/scene_chicken_festival_lifetimes.o \
$(BUILD_DIR)/src/scene_harvesting_minigame_lifetimes.o \
$(BUILD_DIR)/src/scene_watering_minigame_lifetimes.o \
$(BUILD_DIR)/src/event_state_search.o \
$(BUILD_DIR)/src/harvest_sprite_target_search.o \
$(BUILD_DIR)/src/hardware_linked_list.o \
$(BUILD_DIR)/src/hardware_linked_list_lifetimes.o \
$(BUILD_DIR)/src/hardware_sound_command_lifetimes.o \
$(BUILD_DIR)/src/game_menu_lifetimes.o \
$(BUILD_DIR)/src/game_menu_selection.o \
$(BUILD_DIR)/src/ui_text_commands.o \
$(BUILD_DIR)/src/scene_text_variable_lifetimes.o \
$(BUILD_DIR)/src/hardware_blend.o \
$(BUILD_DIR)/src/hardware_interrupt_guard.o \
$(BUILD_DIR)/src/font_draw.o \
$(BUILD_DIR)/src/scroll_state.o \
$(BUILD_DIR)/src/game_object.o \
$(BUILD_DIR)/src/entity.o \
$(BUILD_DIR)/src/entity_actor.o \
$(BUILD_DIR)/src/animal_actor_tables.o \
$(BUILD_DIR)/src/animal_actor.o \
$(BUILD_DIR)/src/harvest_sprite_actor.o \
$(BUILD_DIR)/src/new_game_identity.o \
$(BUILD_DIR)/src/new_game_name_input.o \
$(BUILD_DIR)/src/wild_dog_actor.o \
$(BUILD_DIR)/src/font_decimal.o \
$(BUILD_DIR)/src/game_scene_controller.o \
$(BUILD_DIR)/src/world_prop_entities.o \
$(BUILD_DIR)/src/ui_text_window.o \
$(BUILD_DIR)/src/scene_menu_transitions.o \
$(BUILD_DIR)/src/intro_scene_factory.o \
$(BUILD_DIR)/src/intro_scene_lifetimes.o \
$(BUILD_DIR)/src/new_game_menu_lifetimes.o \
$(BUILD_DIR)/src/new_game_menu_factory.o \
$(BUILD_DIR)/src/new_game_name_entry_factory.o \
$(BUILD_DIR)/src/new_game_name_entry_lifetimes.o \
$(BUILD_DIR)/src/name_entry_lifetimes.o \
$(BUILD_DIR)/src/town_map_transition_lifetimes.o \
$(BUILD_DIR)/src/town_map_transition.o \
$(BUILD_DIR)/src/scene_clock_transition_lifetimes.o \
$(BUILD_DIR)/src/scene_clock_transition.o \
$(BUILD_DIR)/src/game_scene_return.o \
$(BUILD_DIR)/src/game_scene_return_lifetimes.o \
$(BUILD_DIR)/src/gamecube_link_scene.o \
$(BUILD_DIR)/src/new_game_identity_lifetimes.o \
$(BUILD_DIR)/src/new_game_name_input_lifetimes.o \
$(BUILD_DIR)/src/main_menu_widget_lifetimes.o \
$(BUILD_DIR)/src/main_menu_widget.o: CXXFLAGS += -fno-weak

$(BUILD_DIR)/src/ui_state.o: CXXFLAGS += -fno-weak

# Keep the out-of-line search owner's top-tested loop form.
$(BUILD_DIR)/src/scene_reference_page_lifetimes.o: CXXFLAGS += -fno-rerun-loop-opt

# Native standalone entries coexist with the callers' inline definitions.
$(BUILD_DIR)/src/farm_map_screen_lifetimes.o: CXXFLAGS += -fno-implement-inlines
$(BUILD_DIR)/src/animal_actor_lifetimes.o: CXXFLAGS += -fno-weak
$(BUILD_DIR)/src/harvest_sprite_actor_lifetimes.o \
$(BUILD_DIR)/src/world_prop_lifetimes.o: CXXFLAGS += -fno-weak -fno-implement-inlines


$(BUILD_DIR)/src/hardware_blend_tables.o: CXXFLAGS += -fno-weak

# These out-of-line definitions own their class tables without forcing inline members.
$(BUILD_DIR)/src/game_scene.o \
$(BUILD_DIR)/src/game_scene_tables.o \
$(BUILD_DIR)/src/game_scene_state.o \
$(BUILD_DIR)/src/game_scene_state_tables.o \
$(BUILD_DIR)/src/game_scene_controller_tables.o \
$(BUILD_DIR)/src/game_world_tables.o \
$(BUILD_DIR)/src/game_world.o \
$(BUILD_DIR)/src/game_world_interface.o \
$(BUILD_DIR)/src/scene_sprite_tables.o \
$(BUILD_DIR)/src/scene_sprite.o \
$(BUILD_DIR)/src/intro_story_scene.o \
$(BUILD_DIR)/src/resource_archive.o \
$(BUILD_DIR)/src/hardware_manager_tables.o \
$(BUILD_DIR)/src/hardware_context.o \
$(BUILD_DIR)/src/hardware_context_tables.o \
$(BUILD_DIR)/src/world_map_tables.o \
$(BUILD_DIR)/src/saved_map_tree.o \
$(BUILD_DIR)/src/shop_scene_tables.o \
$(BUILD_DIR)/src/resource_sprite_renderer_tables.o \
$(BUILD_DIR)/src/shop_common_tables.o \
$(BUILD_DIR)/src/script_engine_base_tables.o \
$(BUILD_DIR)/src/scene_gamecube_link.o \
$(BUILD_DIR)/src/hardware_sound.o \
$(BUILD_DIR)/src/ui_vcount.o \
$(BUILD_DIR)/src/hardware_dma_copy.o \
$(BUILD_DIR)/src/map_clock_status_lifetimes.o \
$(BUILD_DIR)/src/entity_visual_controller.o \
$(BUILD_DIR)/src/status_screen_transitions.o \
$(BUILD_DIR)/src/world_ambient_behaviors.o \
$(BUILD_DIR)/src/world_sprite_effects.o: CXXFLAGS += -fno-weak -fno-implement-inlines

$(BUILD_DIR)/src/hardware_context_commands.o \
$(BUILD_DIR)/src/hardware_dma_copy_commands.o \
$(BUILD_DIR)/src/ui_text_window_commands.o \
$(BUILD_DIR)/src/entity_actor_lifetimes.o: CXXFLAGS += -fno-weak
$(BUILD_DIR)/src/world_map_command_lifetimes.o: CXXFLAGS += -fno-weak

$(BUILD_DIR)/src/intro_story_lifetimes.o \
$(BUILD_DIR)/src/name_entry.o: CXXFLAGS += -fno-weak

$(BUILD_DIR)/src/resource_archive_provider.o \
$(BUILD_DIR)/src/resource_archive_lifetimes.o: CXXFLAGS += -fno-weak

# overrides for matching
# IWRAM sorting is native ARM code, not Thumb. Use the installed ARM frontend
# through the ordinary C++ channel. Its frameless ARM output matches the
# original ABI; this old frontend rejects -fhex-asm and warns about debug
# information without a frame pointer, so omit only those two compiler options.
$(BUILD_DIR)/src/iwram_sort.o: CC1PLUS := $(ARM_CC1PLUS)
$(BUILD_DIR)/src/iwram_sort.o: CXXFLAGS := $(filter-out -g -fhex-asm,$(CXXFLAGS)) -fomit-frame-pointer -mcpu=arm7tdmi
$(BUILD_DIR)/src/iwram_sort.o: $(ARM_CC1PLUS)

$(BUILD_DIR)/src/m4a.o: CC1 := $(OLD_CC1)
$(BUILD_DIR)/src/m4a.o: $(OLD_CC1)

# JoyBus keeps its C operations and native protocol bodies in ROM order.
# Its real IWRAM variables use BSS storage instead of linker-address aliases.
$(BUILD_DIR)/src/joy_bus.o: CFLAGS += -fno-common

# The original newlib string routines use the older C compiler with interwork.
# Keep the ordinary C channel, including its generic zero-filled text tail.
$(BUILD_DIR)/src/libc_string.o: CC1 := $(OLD_CC1)
$(BUILD_DIR)/src/libc_string.o: $(OLD_CC1)
$(BUILD_DIR)/src/libc_string.o: CFLAGS += -fno-builtin

# The original SRAM library's RAM-copy loops and literal pools match at -O1.
# Keep its SDK identification and compiler-generated address constants together
# in default .rodata, as well as all six functions in physical .text order.
$(BUILD_DIR)/src/libsram.o: CFLAGS := $(filter-out -O2,$(CFLAGS)) -O1

clean:
	@echo "RM $(ROM) $(ELF) $(MAP) $(BUILD_DIR)"
	@rm -f $(ROM) $(ELF) $(MAP) 
	@rm -rf $(BUILD_DIR)/

.PHONY: clean

# Region wrappers recurse into compare; only the actual build invocation
# needs compiler/assembler dependency discovery. NODEP=1 is available for
# direct host-tool or resource-only commands, as in pret's Makefile.
NODEP ?= 0
RULES_NO_SCAN := clean fomt_us fomt_jp fomt_eu fomt_de compare_eu compare_de
ifneq ($(NODEP),1)
ifneq (,$(filter-out $(RULES_NO_SCAN),$(if $(MAKECMDGOALS),$(MAKECMDGOALS),all)))
-include $(ALL_DEPS)
endif
endif
.PRECIOUS: $(BUILD_DIR)/%.d
