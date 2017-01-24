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

.PHONY: xdoj_jc3_security_code.h
xdoj_jc3_security_code.h :
	head -c 8 /dev/urandom | hexdump -e "\"%x\"" | \
	sed 's/.*/#define XDOJ_JC3_SECURITY_CODE 0x&ULL\n/' > $@

.PHONY : clean
clean:
	$(RM) $(LIB) $(OBJ) $(DEP) xdoj_jc3_security_code.h
