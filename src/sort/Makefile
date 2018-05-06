CC = gcc
CFLAGS = -g -Wall $(INCLUDES)
LIBPATH = -L$(SRCTOP)/../../lib/array/
LIBS = $(LIBPATH) -lstatic_array_lib
EXES = quick_sort counting_sort radix_sort

all: clean $(EXES)
	@echo you have typed command "make $@"

clean:
	@echo "cleaning"
	rm -rf $(EXES)

quick_sort:
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ quick_sort.c $(LIBS)

counting_sort:
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ counting_sort.c $(LIBS)

radix_sort:
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ radix_sort.c $(LIBS) -lm
