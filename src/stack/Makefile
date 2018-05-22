CC = gcc
CFLAGS = -g -Wall
LIBPATH = -L$(SRCTOP)/../../lib/array/ -L$(SRCTOP)/../../lib/link_list/ -L$(SRCTOP)/../../lib/stack/
LIBS = $(LIBPATH) -lstatic_array_lib -lstatic_stack_lib -lstatic_link_list_lib -lm
CFILES =
HFILES =
OBJS = $(CFILES:%.c=%.o)
EXES = test_array_stack test_two_end_array_stack test_queue_by_two_stacks test_link_list_stack

all: clean $(EXES)
	@echo you have typed command "make $@"

clean:
	@echo "cleaning"
	rm -rf $(OBJS) $(EXES)

test_array_stack: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_array_stack.c $(LIBS)

test_two_end_array_stack: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_two_end_array_stack.c $(LIBS)

test_queue_by_two_stacks: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_queue_by_two_stacks.c $(LIBS)

test_link_list_stack: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_link_list_stack.c $(LIBS)

%.o: %.c $(HFILES)
	$(CC) $(CFLAGS) -c -o $(notdir $@) $< $(LIBS)
