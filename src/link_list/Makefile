CC = gcc
CFLAGS = -g -Wall
LIBPATH = -L$(SRCTOP)/../../lib/link_list/
LIBS = $(LIBPATH) -lstatic_link_list_lib
CFILES =
HFILES =
OBJS = $(CFILES:%.c=%.o)
EXES = test_link_list test_circular_link_list test_link_list_reverse

all: clean $(EXES)
	@echo you have typed command "make $@"

clean:
	@echo "cleaning"
	rm -rf $(OBJS) $(EXES)

test_link_list: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_link_list.c $(LIBS)

test_circular_link_list: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_circular_link_list.c $(LIBS)

test_link_list_reverse: $(OBJS)
	@echo "making $@"
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJS)) test_link_list_reverse.c $(LIBS)

%.o: %.c $(HFILES)
	$(CC) $(CFLAGS) -c -o $(notdir $@) $< $(LIBS)
