CC = gcc
CFLAGS = -g -Wall
CFILES = static_stack_lib.c
OBJS = $(CFILES:%.c=%.o)
LIBS = $(OBJS:%.o=lib%.a)

all: clean $(LIBS)
	@echo you have typed command "make $@"

clean:
	@echo "cleaning"
	rm -rf ./*.a
	rm -rf ./*.o

%.o: %.c
	$(CC) $(CFLAGS) -c -o $(notdir $@) $<

$(LIBS): $(OBJS)
	ar rcs $(notdir $@) $(notdir $(OBJS)) $^
