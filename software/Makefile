# Main makefile for application

CC = arm-none-eabi-gcc
COPY = arm-none-eabi-objcopy

ifndef ROOT
$(error ROOT is not set, use one of the example makefiles and set the ROOT path)
endif

ifndef BINARY
$(error BINARY is not set, use one of the example makefiles and set the BINARY name)
endif

.PHONY: all
all: $(BINARY)

# The file paths relative to root directory is retained in the build directory
BUILD_DIR = build

# Get source file for application
APP_SRC_FILES = $(foreach s, $(SRC_PATHS), $(wildcard $(s)/*.c))
# Construct object file paths in build directory relative to the root
APP_OBJ_FILES = $(foreach s, $(APP_SRC_FILES), $(BUILD_DIR)/$(shell realpath --relative-to $(ROOT) $(s:.c=.o)))
OBJ_FILES += $(APP_OBJ_FILES)

CFLAGS += -Os -g -Wall
INC += $(addprefix -I, $(INC_PATHS))

# Set SDK path and include its makefile it will append to source files
SDK_ROOT = sdk
include $(ROOT)/$(SDK_ROOT)/Makefile

# J-Link support
JLINK = JLinkExe -device $(CORE) -if swd -speed 4000
JLINK_FILE = $(BUILD_DIR)/flash.jlink

# Build rules for example
$(APP_OBJ_FILES): $(BUILD_DIR)/%.o: $(ROOT)/%.c
	@mkdir -p $(dir $@)
	@echo Buliding $@ from $<
	$(CC) $(INC) $(CFLAGS) -o $@ -c $<

.PHONY: $(BINARY)
$(BINARY): $(BUILD_DIR)/$(BINARY).hex $(BUILD_DIR)/$(BINARY).bin $(BUILD_DIR)/$(BINARY).elf

.PHONY: flash
flash: $(BINARY) $(JLINK_FILE)
	$(JLINK) $(JLINK_FILE)

$(JLINK_FILE):
	echo "loadfile $(BUILD_DIR)/$(BINARY).hex\nr\nexit\n" > $(JLINK_FILE)

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf
	@mkdir -p $(dir $@)
	@echo Constructing  $@ from object files
	$(COPY) -O ihex $< $@

$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf
	@mkdir -p $(dir $@)
	@echo Constructing  $@ from object files
	$(COPY) -v -O binary $< $@

$(BUILD_DIR)/%.elf: $(OBJ_FILES)
	@mkdir -p $(dir $@)
	@echo Constructing  $@ from object files
	$(CC) $(INC) $(CFLAGS) $(OBJ_FILES) -o $@

clean:
	@rm -rf $(BUILD_DIR)
