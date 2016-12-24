lib : $(LIB)

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
DEP = $(patsubst %.c, %.dep, $(SRC))

CFLAGS += -I../include

$(LIB) : $(OBJ)
	$(CCLD) $(LDFLAGS) --shared -o $@ $^

%.dep : %.c
	$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@:,g' < $@.$$$$ > $@; \
	$(RM) $@.$$$$

sinclude $(DEP)

.PHONY : clean
clean:
	$(RM) $(LIB) $(OBJ) $(DEP)
