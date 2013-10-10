# Travis Whitaker 2013
# twhitak@its.jnj.com

CC = clang
CFLAGS = -O2
INCLUDE = -I./include
EXECUTABLE = csvgen

all: csvgen.o
	$(CC) $(CFLAGS) $(INCLUDE) -o $(EXECUTABLE) csvgen.o src/main.c

csvgen.o:
	$(CC) -c $(CFLAGS) $(INCLUDE) src/csvgen.c

install:
	cp $(EXECUTABLE) /usr/local/bin

uninstall:
	rm -f /usr/local/bin/$(EXECUTABLE)

clean:
	rm -f *.o
	rm -f $(EXECUTABLE)
	rm -f debug-csvgen

debug: csvgen.o.debug
	$(CC) -O0 -g $(INCLUDE) -o debug-csvgen csvgen.o src/main.c

csvgen.o.debug:
	$(CC) -c -O0 -g $(INCLUDE) src/csvgen.c
