CC = gcc
CFLAGS = -g -Wall $(INCLUDES)
LIBPATH = -L$(SRCTOP)/../../lib/array/
LIBS = $(LIBPATH) -lstatic_array_lib
EXES = heap

all: clean $(EXES)
	@echo you have typed command "make $@"

clean:
	@echo "cleaning"
	rm -rf $(EXES)

heap:
	@echo "makeing $@"
	$(CC) $(CFLAGS) -o $@ heap.c $(LIBS)
