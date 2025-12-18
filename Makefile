# [etersai 2025]
PROGRAM_NAME:= NCgine
CC:= gcc
CFLAGS+= -std=c99 -Wall -Wextra -g -O0 -DDEBUG
# -Wno-unused-function -Wno-unused-parameter -pedantic
# LDLIBS= -lncurses or -pdcurses

ifeq ($(OS),Windows_NT)
 $(error [$(PROGRAM_NAME)]For Windows builds pls use build.bat)
endif

ifeq ($(MAKECMDGOALS),clean)
 # for only clean skip platform detection
else
 UNAME_S := $(shell uname -s)
 ifeq ($(UNAME_S),Linux)
  MACHINE := LINUX
  CFLAGS += -D_POSIX_C_SOURCE=200809L
  SRC_PLATFORM := src/engine/platform/p_linux.c
  $(info [$(PROGRAM_NAME)] $(MACHINE) detected)
 else ifeq ($(UNAME_S),Darwin)
  MACHINE := MACOS
  $(info [$(PROGRAM_NAME)] $(MACHINE) detected)
  $(error [$(PROGRAM_NAME)] $(MACHINE) not supported!)
 else
  MACHINE := $(UNAME_S)
  $(info [$(PROGRAM_NAME)] Unknown system: $(MACHINE))
  $(error [$(PROGRAM_NAME)] $(MACHINE) not supported!)
 endif
endif

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): generate_bin
	$(CC) -o bin/$(PROGRAM_NAME) $(CFLAGS) \
	src/main.c \
	src/engine/ncgine.c \
	$(SRC_PLATFORM)

generate_bin:
	@mkdir -p bin/plugins
	
clean:
	@rm -rf bin
	
# Use := by default (faster, predictable)
# Use += to add to existing variables (u can do this => make CFLAGS="-O2")
# Use = only when you need lazy evaluation (TIME = $(shell date), TIME will get evaluated every time it's used.)
# Use ?= for user-overridable defaults
#
# Memory trick: := means "set it NOW", = means "set it later"
