# C compiler
CC = gcc

# How to invoke compiler as linker
CCLD = $(CC)

# C flags
CFLAGS = -std=gnu99 -O2 -Wall -Wextra -Wconversion -Wformat=2 -Wcast-qual \
  -Wcast-align -Wwrite-strings -Wstrict-prototypes -Wmissing-prototypes \
  -Wc++-compat -Wmissing-declarations -Wvla

# where is pkg-config
PKG_CONFIG = pkg-config

# where is libseccomp.pc 
PKG_CONFIG_PATH = /usr/lib64/pkgconfig

# cgroup mount point
CG_MOUNT = /sys/fs/cgroup/memory

# additional namespaces(7) support.
# while mount namespaces and user namespaces are necessary, others
# are optional.

# uncomment to use IPC namespaces 
CFLAGS += -D_XDOJ_JC3_USE_IPC_NS

# uncomment to use network namespaces
CFLAGS += -D_XDOJ_JC3_USE_NET_NS

# uncomment to use PID namespaces
CFLAGS += -D_XDOJ_JC3_USE_PID_NS

# uncomment to use UTS namespaces
CFLAGS += -D_XDOJ_JC3_USE_UTS_NS
