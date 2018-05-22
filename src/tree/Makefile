CC = gcc
CFLAGS = -g -Wall $(INCLUDES)
LIBPATH = -L$(SRCTOP)/../../lib/tree/
LIBS = $(LIBPATH) -lstatic_tree_lib
EXES = postorder_traversal

all: clean $(EXES)
	@echo you have typed command "make $@"

clean:
	@echo "cleaning"
	rm -rf $(EXES)

postorder_traversal:
	@echo "makeing $@"
	$(CC) $(CFLAGS) -o $@ postorder_traversal.c $(LIBS)
