lib : $(LIB)

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC)) xdoj_jc3_security_code.o
DEP = $(patsubst %.c, %.dep, $(SRC))

CFLAGS += -I../include

$(LIB) : $(OBJ)
	$(CCLD) $(LDFLAGS) --shared -o $@ $^

%.dep : %.c
	$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@:,g' < $@.$$$$ > $@; \
	$(RM) $@.$$$$

sinclude $(DEP)

.PHONY: xdoj_jc3_security_code.o
xdoj_jc3_security_code.o :
	head -c 8 /dev/urandom | hexdump -e "\"%x\"" | \
	sed 's/.*/#include "xdoj_jc3_security_code.h"\nconst uint64_t xdoj_jc3_security_code = 0x&ULL;\n/' | \
	$(CC) -x c $(CFLAGS) - -c -o $@

.PHONY : clean
clean:
	$(RM) $(LIB) $(OBJ) $(DEP)
