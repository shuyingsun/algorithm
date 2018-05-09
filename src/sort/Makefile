CC = gcc
CFLAGS = -g -Wall
LIBPATH = -L$(SRCTOP)/../../lib/array/
LIBS = $(LIBPATH) -lstatic_array_lib
CFILES = common.c
HFILES = common.h
OBJS = $(CFILES:%.c=%.o)
EXES = quick_sort counting_sort radix_sort

all: clean $(EXES)
	@echo you have typed command "make $@"

clean:
	@echo "cleaning"
	rm -rf $(OBJS) $(EXES)

quick_sort:
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ quick_sort.c $(LIBS)

counting_sort: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) counting_sort.c $(LIBS)

radix_sort: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) radix_sort.c $(LIBS) -lm

%.o: %.c $(HFILES)
	$(CC) $(CFLAGS) -c -o $(notdir $@) $<
