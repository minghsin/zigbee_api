OBJS=test.o
EXEC=test

CFLAGS=-I../include
LDFLAGS=
all: $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(CFLAGS) $(LDFLAGS)
clean:
	rm *.o $(EXEC) -rf
