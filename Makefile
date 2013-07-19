
NAME=zb
OBJS=zigbee_api.o
LIB=libzb.a
LIBPATH=lib

TESTDIR=sample

CFLAGS= -I./include
LDFLAGS=

.PHONY: test all clean

all: $(LIB)

$(LIB): $(OBJS)
	mkdir -p $(LIBPATH)
	$(AR) rcs $(LIBPATH)/$(LIB) $(OBJS)

test:
	$(MAKE) -C $(TESTDIR)

clean:
	rm $(LIBPATH)/*.a *.o -rf
	$(MAKE) -C $(TESTDIR) clean
