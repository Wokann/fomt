# Build configuration follows the multi-version structure used by pret/pokeruby.

GAME_REGION ?= US
GAME_REVISION ?= 0

# Backward-compatible spelling used by the first region scaffold.
ifneq ($(origin REGION),undefined)
  ifeq ($(REGION),us)
    override GAME_REGION := US
  else ifeq ($(REGION),jp)
    override GAME_REGION := JP
  else ifeq ($(REGION),eu)
    override GAME_REGION := EU
  else ifeq ($(REGION),de)
    override GAME_REGION := DE
  else
    $(error Unsupported REGION '$(REGION)'; expected us, jp, eu, or de)
  endif
endif

ifneq ($(GAME_REVISION),0)
  $(error Unsupported GAME_REVISION '$(GAME_REVISION)'; only revision 0 is verified)
endif

ifeq ($(GAME_REGION),US)
  BUILD_NAME := fomt_us
  BASE_ROM := baserom_us.gba
  REGION_DIR := us
  REGION_DEFINE := REGION_US
  LDS := fomt_us.lds
  LDS_LINK_PATH := ../../fomt_us.lds
else ifeq ($(GAME_REGION),JP)
  BUILD_NAME := fomt_jp
  BASE_ROM := baserom_jp.gba
  REGION_DIR := jp
  REGION_DEFINE := REGION_JP
  LDS := fomt_jp.lds
  LDS_LINK_PATH := ../../fomt_jp.lds
else ifeq ($(GAME_REGION),EU)
  BUILD_NAME := fomt_eu
  BASE_ROM := baserom_eu.gba
  REGION_DIR := eu
  REGION_DEFINE := REGION_EU
  LDS := fomt_eu.lds
  LDS_LINK_PATH := ../../fomt_eu.lds
else ifeq ($(GAME_REGION),DE)
  BUILD_NAME := fomt_de
  BASE_ROM := baserom_de.gba
  REGION_DIR := de
  REGION_DEFINE := REGION_DE
  LDS := fomt_de.lds
  LDS_LINK_PATH := ../../fomt_de.lds
else
  $(error Unsupported GAME_REGION '$(GAME_REGION)'; expected US, JP, EU, or DE)
endif
