# Sample makefile for an example application
PROJECT_ABS = $(abspath .)
ROOT_ABS = $(shell git rev-parse --show-toplevel)/software

# The following variables should be set for an example to compile
# Root of the software directory, everything relates to this path in the build dir
ROOT = $(shell realpath --relative-to $(PROJECT_ABS) $(ROOT_ABS))
# Paths where source files are located for this example (can be multiple paths)
SRC_PATHS = . src
# Paths where header files are located for this example (can be multiple paths)
INC_PATHS = src
# Name of the binary
BINARY = blink

# The root makefile takes care of finding and building files
include $(ROOT)/Makefile

