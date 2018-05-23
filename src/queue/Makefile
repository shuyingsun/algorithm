CC = gcc
CFLAGS = -g -Wall
LIBPATH = -L$(SRCTOP)/../../lib/array/ -L$(SRCTOP)/../../lib/queue/ -L$(SRCTOP)/../../lib/link_list/
LIBS = $(LIBPATH) -lstatic_array_lib -lstatic_queue_lib -lstatic_link_list_lib -lm
CFILES =
HFILES =
OBJS = $(CFILES:%.c=%.o)
EXES = test_array_queue test_array_dequeue test_stack_by_two_queues test_link_list_queue

all: clean $(EXES)
	@echo you have typed command "make $@"

clean:
	@echo "cleaning"
	rm -rf $(OBJS) $(EXES)

test_array_queue: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_array_queue.c $(LIBS)

test_array_dequeue: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_array_dequeue.c $(LIBS)

test_stack_by_two_queues: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_stack_by_two_queues.c $(LIBS)

test_link_list_queue: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_link_list_queue.c $(LIBS)

%.o: %.c $(HFILES)
	$(CC) $(CFLAGS) -c -o $(notdir $@) $< $(LIBS)
