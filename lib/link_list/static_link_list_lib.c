#include "static_link_list_lib.h"

/*
 * Link list here is a link list with head node
 * The head is not carrying a value
 */

link_list* create_link_list() {
    link_list *head = (link_list *)malloc(sizeof(link_list));

    if (head == NULL)
        printf("Malloc failure for head of link_list.\n");

    return head;
}

void destroy_link_list(link_list *head) {
    link_list *curr = NULL;

    if (head == NULL)
        return;

    curr = head->next;
    while (curr != NULL) {
        head->next = curr->next;
        free(curr);
        curr = head->next;
    }

    free(head);
    return;
}

void link_list_insert(link_list *head, int val) {
    link_list *node = NULL;

    if (head == NULL)
        return;

    node = (link_list *)malloc(sizeof(link_list));
    if (node == NULL)
        return;

    node->val = val;
    node->next = head->next;
    head->next = node;
    return;
}

link_list* link_list_search(link_list *head, int val) {
    link_list *curr = NULL;

    if (head == NULL)
        return NULL;

    curr = head->next;
    while (curr != NULL) {
        if (curr->val == val)
            break;
        curr = curr->next;
    }

    return curr;
}

void link_list_delete(link_list *head, int val) {
    link_list *priv = NULL, *curr = NULL;

    if (head == NULL)
        return;

    priv = head;
    curr = head->next;
    while (curr != NULL) {
        if (curr->val == val) {
            priv->next = curr->next;
            free(curr);
            return;
        }
        priv = curr;
        curr = curr->next;
    }
    printf("Cannot find %d in the link list.\n", val);
    return;
}

void print_link_list(link_list *head) {
    link_list *curr = NULL;

    if (head == NULL)
        return;

    printf("The link list has values: ");
    curr = head->next;
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }

    printf("\n");
    return;
}
