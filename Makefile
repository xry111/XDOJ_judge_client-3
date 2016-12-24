# configs

CC ?= gcc
CCLD ?= $(CC)
CFLAGS ?= -std=c99 -O2 -Wall -Wextra -Wconversion -Wformat=2
export PKG_CONFIG_PATH ?= /usr/lib64/pkgconfig
export CG_MOUNT ?= /sys/fs/cgroup/memory

# end configs

LIBNAME = xdojjc3
LIB = lib$(LIBNAME).so

SRC = $(wildcard src/*.c)

LDFLAGS += `pkg-config --libs libseccomp`
CFLAGS += -fPIC -Iinclude `pkg-config --cflags libseccomp`

export CC CCLD CFLAGS LDFLAGS LIBNAME LIB

EXE = xdoj_judge_client3
SRC = $(wildcard *.c)
DEP = $(patsubst %.c, %.dep, $(SRC))
OBJ = $(patsubst %.c, %.o, $(SRC))

all : $(EXE)

$(EXE) : $(OBJ) recursive_lib
	$(CCLD) $(LDFLAGS) -o $@ $< -L./src -l$(LIBNAME)

.PHONY : recursive_lib
recursive_lib :
	make -C src

%.dep : %.c
	$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@:,g' < $@.$$$$ > $@; \
	$(RM) $@.$$$$

sinclude $(DEP)

.PHONY : clean
clean:
	make -C src clean
	make -C tests clean
	$(RM) $(EXE) $(OBJ) $(DEP)

.PHONY : check
check : recursive_lib
	make -C tests
