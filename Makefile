
NAME=zb
OBJS=netvox.o
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
	find . -name *.o | xargs rm -rf
	rm $(LIBPATH)/*.a -rf
	$(MAKE) -C $(TESTDIR) clean
