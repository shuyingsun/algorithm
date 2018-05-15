CC = gcc
CFLAGS = -g -Wall
LIBPATH = -L$(SRCTOP)/../../lib/array/ -L$(SRCTOP)/../../lib/queue/
LIBS = $(LIBPATH) -lstatic_array_lib -lstatic_queue_lib -lm
CFILES =
HFILES =
OBJS = $(CFILES:%.c=%.o)
EXES = test_array_queue

all: clean $(EXES)
	@echo you have typed command "make $@"

clean:
	@echo "cleaning"
	rm -rf $(OBJS) $(EXES)

test_array_queue: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_array_queue.c $(LIBS)

%.o: %.c $(HFILES)
	$(CC) $(CFLAGS) -c -o $(notdir $@) $< $(LIBS)
