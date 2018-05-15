#include "static_queue_lib.h"

array_queue* create_array_queue() {
    int queueSize;
    array_queue *new_queue = NULL;
    int *new_nums = NULL;

    printf("Please input an integer larger than 1 to specify the size of queue: ");
    scanf("%d", &queueSize);

    if (queueSize <= 1) {
        printf("Invalid stack size!\n");
        return NULL;
    }

    new_queue = (array_queue *)malloc(sizeof(array_queue));
    if (new_queue == NULL) {
        printf("Malloc failure for new_queue.\n");
        return NULL;
    }

    new_nums = (int *)malloc(sizeof(int) * queueSize);
    if (new_nums == NULL) {
        printf("Malloc failure for new_nums.\n");
        free(new_queue);
        return NULL;
    }

    new_queue->nums = new_nums;
    new_queue->queueSize = queueSize;
    new_queue->head = 0;
    new_queue->tail = 0;

    return new_queue;
}

void destroy_array_queue(array_queue *queue) {
    if (queue == NULL)
        return;
    if (queue->nums != NULL)
        free(queue->nums);
    free(queue);
}

bool is_array_queue_empty(array_queue queue) {
    return (queue.head == queue.tail);
}

bool is_array_queue_full(array_queue queue) {
    return (queue.head == (queue.tail + 1) % queue.queueSize);
}

void enqueue_array(array_queue *queue, int val) {
    if (is_array_queue_full(*queue)) {
        printf("The queue is full, enqueue failed.\n");
        return;
    }
    queue->nums[queue->tail] = val;
    queue->tail = (queue->tail + 1) % queue->queueSize;
}

void enqueue_deque_array(array_queue *queue, int val, deque_direction dir) {
    int idx;
    if (is_array_queue_full(*queue)) {
        printf("The queue is full, enqueue failed.\n");
        return;
    }
    if (dir == FROM_HEAD) {
        idx = (queue->head + queue->queueSize - 1) % queue->queueSize;
        queue->nums[idx] = val;
        queue->head = idx;
        return;
    }
    queue->nums[queue->tail] = val;
    queue->tail = (queue->tail + 1) % queue->queueSize;
}

void dequeue_array(array_queue *queue, int *val) {
    if (is_array_queue_empty(*queue)) {
        printf("The queue is empty, dequeue failed.\n");
        return;
    }
    *val = queue->nums[queue->head];
    queue->head = (queue->head + 1) % queue->queueSize;
}

void dequeue_deque_array(array_queue *queue, int *val, deque_direction dir) {
    int idx;
    if (is_array_queue_empty(*queue)) {
        printf("The queue is empty, dequeue failed.\n");
        return;
    }
    if (dir == FROM_TAIL) {
        *val = queue->nums[queue->tail];
        idx = (queue->tail + queue->queueSize - 1) % queue->queueSize;
        queue->tail = idx;
        return;
    }
    *val = queue->nums[queue->head];
    queue->head = (queue->head + 1) % queue->queueSize;
}
