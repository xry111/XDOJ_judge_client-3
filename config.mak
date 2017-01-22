# C compiler
CC ?= gcc

# How to invoke compiler as linker
CCLD ?= $(CC)

# C flags
CFLAGS ?= -std=gnu99 -O2 -Wall -Wextra -Wconversion -Wformat=2

# where is pkg-config
PKG_CONFIG ?= pkg-config

# where is libseccomp.pc 
PKG_CONFIG_PATH ?= /usr/lib64/pkgconfig

# cgroup mount point
CG_MOUNT ?= /sys/fs/cgroup/memory
