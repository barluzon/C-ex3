CC=gcc
CFLAGS=-Wall -g
PHONY=all clean
PROGS=isort txtfind

.PHONY: $(PHONY)

all: $(PROGS)

isort: sortingMain.o sorting.o
	$(CC) $(CFLAGS) sortingMain.o sorting.o -o isort

sortingMain.o: sorting.h sortingMain.c
	$(CC) $(CFLAGS) -c sortingMain.c

sorting.o: sorting.h sorting.c
	$(CC) $(CFLAGS) -c sorting.c

txtfind: stringsMain.o strings.o
	$(CC) $(CFLAGS) stringsMain.o strings.o -o txtfind

stringsMain.o: strings.h stringsMain.c
	$(CC) $(CFLAGS) -c stringsMain.c

strings.o: strings.h strings.c
	$(CC) $(CFLAGS) -c strings.c

clean:
	rm -f *.o $(PROGS)