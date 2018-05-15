#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct array_queue_s {
    int *nums;
    int queueSize;
    int head;
    int tail;
} array_queue;

typedef enum {
    FROM_HEAD = 0,
    FROM_TAIL
} deque_direction;

array_queue* create_array_queue();
void destroy_array_queue(array_queue *queue);
bool is_array_queue_empty(array_queue queue);
bool is_array_queue_full(array_queue queue);
void enqueue_array(array_queue *queue, int val);
void dequeue_array(array_queue *queue, int *val);
void enqueue_deque_array(array_queue *queue, int val, deque_direction dir);
void dequeue_deque_array(array_queue *queue, int *val, deque_direction dir);
