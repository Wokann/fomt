# Build configuration follows the multi-version structure used by pret/pokeruby.

GAME_REGION ?= US
GAME_REVISION ?= 0

# Backward-compatible spelling used by the first region scaffold.
ifneq ($(origin REGION),undefined)
  ifeq ($(REGION),us)
    override GAME_REGION := US
  else ifeq ($(REGION),jp)
    override GAME_REGION := JP
  else
    $(error Unsupported REGION '$(REGION)'; expected us or jp)
  endif
endif

ifneq ($(GAME_REVISION),0)
  $(error Unsupported GAME_REVISION '$(GAME_REVISION)'; only revision 0 is verified)
endif

ifeq ($(GAME_REGION),US)
  BUILD_NAME := fomt
  BASE_ROM := baserom.gba
  REGION_DIR := us
  REGION_DEFINE := REGION_US
  LDS := fomt.lds
  LDS_LINK_PATH := ../../fomt.lds
else ifeq ($(GAME_REGION),JP)
  BUILD_NAME := fomt_jp
  BASE_ROM := baserom_jp.gba
  REGION_DIR := jp
  REGION_DEFINE := REGION_JP
  LDS := fomt_jp.lds
  LDS_LINK_PATH := ../../fomt_jp.lds
else
  $(error Unsupported GAME_REGION '$(GAME_REGION)'; expected US or JP)
endif
