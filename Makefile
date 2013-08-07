# Travis Whitaker 2012
# twhitak@its.jnj.com

CC = clang
CFLAGS =
INCLUDE = -I./include
EXECUTABLE = csvparse

all: csvparse.o fileIO.o
	$(CC) $(CFLAGS) $(INCLUDE) -o $(EXECUTABLE) csvparse.o fileIO.o src/main.c

csvparse.o:
	$(CC) -c $(CFLAGS) $(INCLUDE) src/csvparse.c

fileIO.o:
	$(CC) -c $(CFLAGS) $(INCLUDE) src/fileIO.c

install:
	cp $(EXECUTABLE) /usr/local/bin

uninstall:
	rm -f /usr/local/bin/$(EXECUTABLE)

clean:
	rm -f *.o
	rm -f $(EXECUTABLE)
