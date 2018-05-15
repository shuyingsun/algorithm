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

array_queue* create_array_queue();
void destroy_array_queue(array_queue *queue);
bool is_array_queue_empty(array_queue queue);
bool is_array_queue_full(array_queue queue);
void enqueue_array(array_queue *queue, int val);
void dequeue_array(array_queue *queue, int *val);
