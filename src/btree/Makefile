CC = gcc
CFLAGS = -g -Wall $(INCLUDES)
LIBPATH = -L$(SRCTOP)/../../lib/btree/
LIBS = $(LIBPATH) -lstatic_btree_lib
EXES = postorder_traversal

all: clean $(EXES)
	@echo you have typed command "make $@"

clean:
	@echo "cleaning"
	rm -rf $(EXES)

postorder_traversal:
	@echo "makeing $@"
	$(CC) $(CFLAGS) -o $@ postorder_traversal.c $(LIBS)
