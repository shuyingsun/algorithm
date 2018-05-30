CC = gcc
CFLAGS = -g -Wall
LIBPATH = -L$(SRCTOP)/../../lib/array/
LIBS = $(LIBPATH) -lstatic_array_lib -lm
CFILES = common.c quick_sort.c counting_sort.c radix_sort.c insertion_sort.c randomized_select.c linear_time_select.c
HFILES = common.h sorting.h selecting.h
OBJS = $(CFILES:%.c=%.o)
EXES = test_quick_sort test_counting_sort test_radix_sort test_insertion_sort test_randomized_select test_linear_time_select test_find_dup test_first_missing_positive test_disappear_numbers test_find_all_dup

all: clean $(EXES)
	@echo you have typed command "make $@"

clean:
	@echo "cleaning"
	rm -rf $(OBJS) $(EXES)

test_quick_sort: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_quick_sort.c $(LIBS)

test_counting_sort: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_counting_sort.c $(LIBS)

test_radix_sort: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_radix_sort.c $(LIBS)

%.o: %.c $(HFILES)
	$(CC) $(CFLAGS) -c -o $(notdir $@) $< $(LIBS)

test_insertion_sort: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_insertion_sort.c $(LIBS)

test_randomized_select: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_randomized_select.c $(LIBS)

test_linear_time_select: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_linear_time_select.c $(LIBS)

test_find_dup: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_find_dup.c $(LIBS)

test_first_missing_positive: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_first_missing_positive.c $(LIBS)

test_disappear_numbers: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_disappear_numbers.c $(LIBS)

test_find_all_dup: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_find_all_dup.c $(LIBS)
