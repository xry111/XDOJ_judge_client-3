SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
DEP = $(patsubst %.c, %.dep, $(SRC))
EXE = $(patsubst %.c, %.exe, $(SRC))
SCRIPT = $(patsubst %.c, %.sh, $(SRC))

.PHONY: do_test
do_test : all
	for s in $(SCRIPT); do ./$$s; done

all : $(EXE)

CFLAGS += -I../include
LDFLAGS += -Wl,-rpath=../src -L../src -l$(LIBNAME)

%.exe : %.o
	$(CCLD) $(LDFLAGS) -o $@ $^ 

%.dep : %.c
	$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@:,g' < $@.$$$$ > $@; \
	$(RM) $@.$$$$

sinclude $(DEP)

.PHONY: clean
clean :
	$(RM) $(DEP) $(OBJ) $(EXE)
