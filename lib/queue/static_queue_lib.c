#include "static_queue_lib.h"

array_queue* create_array_queue(int queueSize) {
    array_queue *new_queue = NULL;
    int *new_nums = NULL;

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

link_list_queue* create_link_list_queue() {
    link_list_queue *new_queue = NULL;
    link_list *new_link_list = NULL;

    new_queue = (link_list_queue *)malloc(sizeof(link_list_queue));
    if (new_queue == NULL) {
        printf("Malloc failure for new_queue.\n");
        return NULL;
    }

    new_link_list = create_link_list();
    if (new_link_list == NULL) {
        printf("Malloc failure for new_link_list.\n");
        free(new_queue);
        return NULL;
    }

    new_queue->head = new_link_list;
    new_queue->tail = new_link_list;
    return new_queue;
}

stack_by_two_queues* create_stack_by_two_queues(int stackSize) {
    stack_by_two_queues *new_stack = NULL;
    array_queue *new_queue1 = NULL, *new_queue2 = NULL;

    new_stack = (stack_by_two_queues *)malloc(sizeof(stack_by_two_queues));
    if (new_stack == NULL) {
        printf("Malloc failure for new_stack.\n");
        return NULL;
    }

    new_queue1 = create_array_queue(stackSize);
    if (new_queue1 == NULL) {
        free(new_stack);
        printf("Malloc failure for new_queue1.\n");
        return NULL;
    }

    new_queue2 = create_array_queue(stackSize);
    if (new_queue2 == NULL) {
        free(new_queue1);
        free(new_stack);
        printf("Malloc failure for new_queue2.\n");
        return NULL;
    }

    new_stack->queue1 = new_queue1;
    new_stack->queue2 = new_queue2;

    return new_stack;
}

void destroy_array_queue(array_queue *queue) {
    if (queue == NULL)
        return;
    if (queue->nums != NULL)
        free(queue->nums);
    free(queue);
}

void destroy_link_list_queue(link_list_queue *queue) {
    if (queue == NULL)
        return;
    destroy_link_list(queue->head);
    free(queue);
}

void destroy_stack_by_two_queues(stack_by_two_queues *stack) {
    if (stack == NULL)
        return;
    destroy_array_queue(stack->queue1);
    destroy_array_queue(stack->queue2);
}

bool is_array_queue_empty(array_queue queue) {
    return (queue.head == queue.tail);
}

bool is_link_list_queue_empty(link_list_queue queue) {
    return (queue.head == queue.tail);
}

bool is_stack_by_two_queues_empty(stack_by_two_queues stack) {
    return (is_array_queue_empty(*(stack.queue1)) && is_array_queue_empty(*(stack.queue2)));
}

bool is_array_queue_full(array_queue queue) {
    return (queue.head == (queue.tail + 1) % queue.queueSize);
}

bool is_link_list_queue_full(link_list_queue queue) {
    return false;
}

bool is_stack_by_two_queues_full(stack_by_two_queues stack) {
    return (is_array_queue_full(*(stack.queue1)) || is_array_queue_full(*(stack.queue2)));
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

void enqueue_link_list(link_list_queue *queue, int val) {
    link_list *node = (link_list *)malloc(sizeof(link_list));

    if (node == NULL) {
        printf("Malloc failure for new link list node.\n");
        return;
    }

    node->val = val;
    queue->tail->next = node;
    queue->tail = node;
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

bool dequeue_link_list(link_list_queue *queue, int *val) {
    if (is_link_list_queue_empty(*queue)) {
        printf("The queue is empty, dequeue failed.\n");
        return false;
    }

    link_list_delete_first_element(queue->head, val);

    if (queue->head->next == NULL)
        queue->tail = queue->head;
    return true;
}

void push_by_two_queues(stack_by_two_queues *stack, int val) {
    if (is_stack_by_two_queues_full(*stack)) {
        printf("The stack is full, push failed.\n");
        return;
    }

    /* In queue1 and queue2, there will be one empty, and one with elements inside */
    if (!is_array_queue_empty(*(stack->queue1))) {
        // enqueue the non-empty queue1
        enqueue_array(stack->queue1, val);
        return;
    }

    // queue1 is empty, enqueue queue2
    enqueue_array(stack->queue2, val);
    return;
}

bool pop_by_two_queues(stack_by_two_queues *stack, int *val) {
    int queue_val;

    if (is_stack_by_two_queues_empty(*stack)) {
        printf("The stack is empty, pop failed.\n");
        return false;
    }

    /* In queue1 and queue2, there will be one empty, and one with elements inside */
    if (!is_array_queue_empty(*(stack->queue1))) {
        // queue2 would be empty, pop from queue1 to queue2
        while (true) {
            dequeue_array(stack->queue1, &queue_val);
            if (is_array_queue_empty(*(stack->queue1))) {
                *val = queue_val;
                return true;
            }
            enqueue_array(stack->queue2, queue_val);
        }
    }

    // queue1 would be empty, pop from queue2 to queue1
    while (true) {
        dequeue_array(stack->queue2, &queue_val);
        if (is_array_queue_empty(*(stack->queue2))) {
            *val = queue_val;
            return true;
        }
        enqueue_array(stack->queue1, queue_val);
    }
}
