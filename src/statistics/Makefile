CC = gcc
CFLAGS = -g -Wall
LIBPATH = -L$(SRCTOP)/../../lib/array/
LIBS = $(LIBPATH) -lstatic_array_lib
CFILES = ../sort/quick_sort.c randomized_select.c
CFILES_CLEAN = randomized_select.c
HFILES = ../sort/sorting.h
OBJS = $(CFILES:%.c=%.o)
OBJS_CLEAN = $(CFILES_CLEAN:%.c=%.o)
EXES = test_randomized_select

all: clean $(EXES)
	@echo you have typed command "make $@"

clean:
	@echo "cleaning"
	rm -rf $(OBJS_CLEAN) $(EXES)

test_randomized_select: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_randomized_select.c $(LIBS)

%.o: %.c $(HFILES)
	$(CC) $(CFLAGS) -c -o $(notdir $@) $< $(LIBS)
