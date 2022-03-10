# This makefile is responsible for compiling the code
# provided in the SDK. This code is not intended to be modified so it
# is not checked into the repository. If the user modifies the code
# inside the SDK by accident a warning should be printed when make is
# called.
#
# This makefile should be included by another makefile.

ifndef ROOT
$(error ROOT is not set)
endif

ifndef SDK_ROOT
$(error SDK_ROOT is not set)
endif

SDK_PATH = $(SDK_ROOT)/SDK_2_11_0_LPC51U68
SDK_SHA1SUM = $(SDK_ROOT)/sdk_sha1sum

ifeq ($(wildcard $(ROOT)/$(SDK_PATH)/*),)
$(error $(SDK_PATH) does not exist, please run $(SDK_ROOT)/extract.sh)
endif

ifndef BUILD_DIR
$(error BUILD_DIR is not set, it is set by the root makefile)
endif

#SDK_SRC_DIRS = \
#devices/LPC51U68 \
#devices/LPC51U68/gcc \
#devices/LPC51U68/drivers \
#rtos/freertos/freertos_kernel \
#rtos/freertos/freertos_kernel/portable/GCC/ARM_CM0 \
#rtos/freertos/freertos_kernel/portable/MemMang \

SDK_SRC_REL = \
devices/LPC51U68/system_LPC51U68.c \
devices/LPC51U68/drivers/fsl_gpio.c \
devices/LPC51U68/drivers/fsl_reset.c \
devices/LPC51U68/utilities/fsl_sbrk.c \
#devices/LPC51U68/utilities/debug_console_lite/fsl_assert.c \
#devices/LPC51U68/utilities/debug_console_lite/fsl_debug_console.c \
#devices/LPC51U68/utilities/fsl_assert.c \

#SDK_SRC_PATHS = $(addprefix $(ROOT)/$(SDK_PATH)/, $(SDK_SRC_DIRS))
#ALL_SDK_SRC_FILES += $(foreach s, $(SDK_SRC_PATHS), $(wildcard $(s)/*.c))
SDK_SRC_FILES = $(addprefix $(ROOT)/$(SDK_PATH)/, $(SDK_SRC_REL))
SDK_SRC_FILES += $(ROOT)/$(SDK_ROOT)/sys.c

# Remove RTOS related files for now
#SDK_SRC_FILES += $(filter-out %_freertos.c, $(ALL_SDK_SRC_FILES))

SDK_OBJ_FILES = $(foreach s, $(SDK_SRC_FILES), $(BUILD_DIR)/$(shell realpath --relative-to $(ROOT) $(s:.c=.o)))

SDK_S_REL = \
devices/LPC51U68/gcc/startup_LPC51U68.S \
#SDK_S_FILES += $(foreach s, $(SDK_SRC_PATHS), $(wildcard $(s)/*.S))
SDK_S_FILES = $(addprefix $(ROOT)/$(SDK_PATH)/, $(SDK_S_REL))
SDK_SOBJ_FILES = $(foreach s, $(SDK_S_FILES), $(BUILD_DIR)/$(shell realpath --relative-to $(ROOT) $(s).o))

OBJ_FILES += $(SDK_OBJ_FILES) $(SDK_SOBJ_FILES)

#C_FLAGS = -Os -g -DDEBUG -DCPU_LPC51U68JBD64 -DMCUXPRESSO_SDK -mcpu=cortex-m0plus -Wall -mfloat-abi=soft -mthumb -MMD -MP -fno-common -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -mapcs -std=gnu99
CORE = lpc51u68
CFLAGS += -DCPU_LPC51U68JBD64  -mcpu=cortex-m0plus
#CFLAGS += -lgcc -lc -lm
#-lcr_newlib_nohost
#-DMCUXPRESSO_SDK
#-nostdlib

# Linker script for LPC51U68
LINKER_FILE = $(ROOT)/$(SDK_PATH)/devices/LPC51U68/gcc/LPC51U68_flash.ld
CFLAGS += -T$(LINKER_FILE)

# Static library for LPC51U68
#LIB_PATH = $(ROOT)/$(SDK_PATH)/devices/LPC51U68/gcc
# libpower.a
#LIB_FILE = power
#CFLAGS += -L$(LIB_PATH) -l$(LIB_FILE)

# Add include paths for SDK
SDK_INC_DIRS = \
devices/LPC51U68 \
devices/LPC51U68/drivers \
CMSIS/Core/Include \
#SDK_INC_DIRS = $(SDK_SRC_DIRS) \
#rtos/freertos/freertos_kernel/include \
#rtos/freertos/freertos_kernel/template/ARM_CM0 \
#rtos/freertos/freertos_kernel/portable/GCC/ARM_CM0 \

SDK_INC_PATHS = $(addprefix $(ROOT)/$(SDK_PATH)/, $(SDK_INC_DIRS))
SDK_INC = $(addprefix -I, $(SDK_INC_PATHS))
INC += $(SDK_INC)

# Build rules for SDK
$(SDK_OBJ_FILES): $(BUILD_DIR)/%.o: $(ROOT)/%.c
	@mkdir -p $(dir $@)
	@echo Buliding $@ from $<
	$(CC) $(SDK_INC) $(CFLAGS) -o $@ -c $<

$(SDK_SOBJ_FILES): $(BUILD_DIR)/%.o: $(ROOT)/%
	@mkdir -p $(dir $@)
	@echo Buliding $@ from $<
	$(CC) $(SDK_INC) $(CFLAGS) -o $@ -c $<
