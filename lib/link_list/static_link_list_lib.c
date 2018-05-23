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

link_list* create_circular_link_list() {
    link_list *head = (link_list *)malloc(sizeof(link_list));

    if (head == NULL) {
        printf("Malloc failure for head of link_list.\n");
        return NULL;
    }

    head->next = head;
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

void destroy_circular_link_list(link_list *head) {
    link_list *curr = NULL;

    if (head == NULL)
        return;

    curr = head->next;
    while (curr != head) {
        head->next = curr->next;
        free(curr);
        curr = head->next;
    }

    free(head);
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
}

void circular_link_list_insert(link_list *head, int val) {
    link_list *node = NULL;

    if (head == NULL)
        return;

    node = (link_list *)malloc(sizeof(link_list));
    if (node == NULL)
        return;

    node->val = val;
    node->next = head->next;
    head->next = node;
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

link_list* circular_link_list_search(link_list *head, int val) {
    link_list *curr = NULL;

    if (head == NULL)
        return NULL;

    curr = head->next;
    while (curr != head) {
        if (curr->val == val)
            return curr;
        curr = curr->next;
    }
    printf("Cannot find %d in the link list.\n", val);
    return NULL;
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

void circular_link_list_delete(link_list *head, int val) {
    link_list *priv = NULL, *curr = NULL;

    if (head == NULL)
        return;

    priv = head;
    curr = head->next;
    while (curr != head) {
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

void link_list_delete_first_element(link_list *head, int *val) {
    link_list *node = NULL;

    if (head == NULL)
        return;

    node = head->next;
    if (node == NULL) {
        printf("The link list is empty, delete failed.\n");
        return;
    }

    head->next = node->next;
    *val = node->val;

    free(node); 
    return;
}

bool circular_link_list_delete_first_element(link_list *head, int *val) {
    link_list *node = NULL;

    if (head == NULL)
        return false;

    node = head->next;
    if (node == head) {
        printf("The circular link list is empty, delete failed.\n");
        return false;
    }

    head->next = node->next;
    free(node);
    return true;
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

void print_circular_link_list(link_list *head) {
    link_list *curr = NULL;

    if (head == NULL)
        return;

    printf("The circular link list has values: ");
    curr = head->next;
    while(curr != head) {
        printf("%d ", curr->val);
        curr = curr->next;
    }

    printf("\n");
    return;
}
