#ifndef __STATIC_LINK_LIST_LIB_H__
#define __STATIC_LINK_LIST_LIB_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct link_list_s {
    int val;
    struct link_list_s *next;
} link_list;

link_list* create_link_list();
void destroy_link_list(link_list *head);
void link_list_insert(link_list *head, int val);
link_list* link_list_search(link_list *head, int val);
void link_list_delete(link_list *head, int val);
void print_link_list(link_list *head);

#endif /*  __STATIC_LINK_LIST_LIB_H__ */
