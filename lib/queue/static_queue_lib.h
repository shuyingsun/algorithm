#ifndef __STATIC_QUEUE_LIB_H__
#define __STATIC_QUEUE_LIB_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>
#include "../link_list/static_link_list_lib.h"

typedef struct array_queue_s {
    int *nums;
    int queueSize;
    int head;
    int tail;
} array_queue;

typedef struct link_list_queue_s {
    link_list *head;
    link_list *tail;
} link_list_queue;

typedef struct stack_by_two_queues_s {
    array_queue *queue1;
    array_queue *queue2;
} stack_by_two_queues;

typedef enum {
    FROM_HEAD = 0,
    FROM_TAIL
} deque_direction;

array_queue* create_array_queue(int queueSize);
void destroy_array_queue(array_queue *queue);
bool is_array_queue_empty(array_queue queue);
bool is_array_queue_full(array_queue queue);
void enqueue_array(array_queue *queue, int val);
void dequeue_array(array_queue *queue, int *val);
void enqueue_deque_array(array_queue *queue, int val, deque_direction dir);
void dequeue_deque_array(array_queue *queue, int *val, deque_direction dir);

link_list_queue* create_link_list_queue();
void destroy_link_list_queue(link_list_queue *queue);
bool is_link_list_queue_empty(link_list_queue queue);
bool is_link_list_queue_full(link_list_queue queue);
void enqueue_link_list(link_list_queue *queue, int val);
bool dequeue_link_list(link_list_queue *queue, int *val);

stack_by_two_queues* create_stack_by_two_queues(int stackSize);
void destroy_stack_by_two_queues(stack_by_two_queues *stack);
bool is_stack_by_two_queues_empty(stack_by_two_queues stack);
bool is_stack_by_two_queues_full(stack_by_two_queues stack);
void push_by_two_queues(stack_by_two_queues *stack, int val);
bool pop_by_two_queues(stack_by_two_queues *stack, int *val);

#endif /* __STATIC_QUEUE_LIB_H__ */
