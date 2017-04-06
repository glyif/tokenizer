CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -pipe
LIBS=
EXENAME=shell

OFILES=\
	tokenizer.o\
	init_struct.o\
	tokenizer_helper.o

GLOBAL_HEADERS=\
	header.h

# Make goals
all: $(GLOBAL_HEADERS) $(OFILES) main.o
	$(CC) $(CFLAGS) $(OFILES) main.o -o $(EXENAME) $(LIBS)

debug: $(GLOBAL_HEADERS) $(OFILES) main.o
	$(CC) $(CFLAGS) $(OFILES) main.o -o $(EXENAME) $(LIBS) -g

clean:
	rm -f $(OFILES) main.o $(EXENAME)

# Each file exact target
main.o: $(GLOBAL_HEADERS) main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

tokenizer_helper.o: $(GLOBAL_HEADERS) tokenizer.h tokenizer_helper.c
	$(CC) $(CFLAGS) -c tokenizer_helper.c -o tokenizer_helper.o

tokenizer.o: $(GLOBAL_HEADERS) tokenizer.h tokenizer.c
	$(CC) $(CFLAGS) -c tokenizer.c -o tokenizer.o

init_struct.o: $(GLOBAL_HEADERS) tokenizer.h init_struct.c
	$(CC) $(CFLAGS) -c init_struct.c -o init_struct.o
