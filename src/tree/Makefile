CC = gcc
CFLAGS = -g -Wall $(INCLUDES)
LIBPATH = -L$(SRCTOP)/../../lib/tree/
LIBS = $(LIBPATH) -lstatic_tree_lib
EXES = test_postorder_traversal test_preorder_traversal test_cs_tree_traversal

all: clean $(EXES)
	@echo you have typed command "make $@"

clean:
	@echo "cleaning"
	rm -rf $(EXES)

test_postorder_traversal:
	@echo "makeing $@"
	$(CC) $(CFLAGS) -o $@ test_postorder_traversal.c $(LIBS)

test_preorder_traversal:
	@echo "makeing $@"
	$(CC) $(CFLAGS) -o $@ test_preorder_traversal.c $(LIBS)

test_cs_tree_traversal:
	@echo "makeing $@"
	$(CC) $(CFLAGS) -o $@ test_cs_tree_traversal.c $(LIBS)
