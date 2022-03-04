# This makefile is responsible for compiling the code
# provided in the SDK. This code is not intended to be modified so it
# is not checked into the repository. If the user modifies the code
# inside the SDK by accident a warning should be printed when make is
# called.
#
# This makefile should be included by another makefile.

ifndef SDK_ROOT
$(error SDK_ROOT is not set)
endif

SDK_PATH = $(SDK_ROOT)/SDK_2_11_0_LPC51U68
SDK_SHA1SUM = $(SDK_ROOT)/sdk_sha1sum

ifeq ($(wildcard $(SDK_PATH)/*),)
$(error $(SDK_PATH) does not exist, please run $(SDK_ROOT)/extract.sh)
endif
