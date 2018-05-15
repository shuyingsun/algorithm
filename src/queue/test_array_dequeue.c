#include "../../lib/queue/static_queue_lib.h"
#include "../../lib/array/static_array_lib.h"

int main(int argc, char *argv[]) {
    int val;
    array_queue *my_dequeue;

    my_dequeue = create_array_queue();
    if (my_dequeue == NULL)
        return 0;

    enqueue_deque_array(my_dequeue, 4, FROM_HEAD);
    printf("After enqueue(Q, 4) from head, queue->head = %d, queue->tail = %d:", my_dequeue->head, my_dequeue->tail);
    print_num_array(my_dequeue->nums, my_dequeue->queueSize);

    enqueue_deque_array(my_dequeue, 1, FROM_TAIL);
    printf("After enqueue(Q, 1) from tail, queue->head = %d, queue->tail = %d:", my_dequeue->head, my_dequeue->tail);
    print_num_array(my_dequeue->nums, my_dequeue->queueSize);

    enqueue_deque_array(my_dequeue, 3, FROM_TAIL);
    printf("After enqueue(Q, 3) from tail, queue->head = %d, queue->tail = %d:", my_dequeue->head, my_dequeue->tail);
    print_num_array(my_dequeue->nums, my_dequeue->queueSize);

    dequeue_deque_array(my_dequeue, &val, FROM_HEAD);
    printf("After dequeue(Q) from head, queue->head = %d, queue->tail = %d:", my_dequeue->head, my_dequeue->tail);
    print_num_array(my_dequeue->nums, my_dequeue->queueSize);

    enqueue_deque_array(my_dequeue, 8, FROM_HEAD);
    printf("After enqueue(Q, 8) from head, queue->head = %d, queue->tail = %d:", my_dequeue->head, my_dequeue->tail);
    print_num_array(my_dequeue->nums, my_dequeue->queueSize);

    enqueue_deque_array(my_dequeue, 10, FROM_HEAD);
    printf("After enqueue(Q, 10) from head, queue->head = %d, queue->tail = %d:", my_dequeue->head, my_dequeue->tail);
    print_num_array(my_dequeue->nums, my_dequeue->queueSize);

    enqueue_deque_array(my_dequeue, 7, FROM_TAIL);
    printf("After enqueue(Q, 7) from tail, queue->head = %d, queue->tail = %d:", my_dequeue->head, my_dequeue->tail);
    print_num_array(my_dequeue->nums, my_dequeue->queueSize);

    enqueue_deque_array(my_dequeue, 6, FROM_HEAD);
    printf("After enqueue(Q, 6) from head, queue->head = %d, queue->tail = %d:", my_dequeue->head, my_dequeue->tail);
    print_num_array(my_dequeue->nums, my_dequeue->queueSize);

    dequeue_deque_array(my_dequeue, &val, FROM_TAIL);
    printf("After dequeue(Q) from tail, queue->head = %d, queue->tail = %d:", my_dequeue->head, my_dequeue->tail);
    print_num_array(my_dequeue->nums, my_dequeue->queueSize);

    dequeue_deque_array(my_dequeue, &val, FROM_TAIL);
    printf("After dequeue(Q) from tail, queue->head = %d, queue->tail = %d:", my_dequeue->head, my_dequeue->tail);
    print_num_array(my_dequeue->nums, my_dequeue->queueSize);

    dequeue_deque_array(my_dequeue, &val, FROM_HEAD);
    printf("After dequeue(Q) from head, queue->head = %d, queue->tail = %d:", my_dequeue->head, my_dequeue->tail);
    print_num_array(my_dequeue->nums, my_dequeue->queueSize);

    dequeue_deque_array(my_dequeue, &val, FROM_TAIL);
    printf("After dequeue(Q) from tail, queue->head = %d, queue->tail = %d:", my_dequeue->head, my_dequeue->tail);
    print_num_array(my_dequeue->nums, my_dequeue->queueSize);

    dequeue_deque_array(my_dequeue, &val, FROM_HEAD);
    printf("After dequeue(Q) from head, queue->head = %d, queue->tail = %d:", my_dequeue->head, my_dequeue->tail);
    print_num_array(my_dequeue->nums, my_dequeue->queueSize);

    dequeue_deque_array(my_dequeue, &val, FROM_HEAD);
    printf("After dequeue(Q) from head, queue->head = %d, queue->tail = %d:", my_dequeue->head, my_dequeue->tail);
    print_num_array(my_dequeue->nums, my_dequeue->queueSize);

    enqueue_deque_array(my_dequeue, 66, FROM_HEAD);
    printf("After enqueue(Q, 66) from head, queue->head = %d, queue->tail = %d:", my_dequeue->head, my_dequeue->tail);
    print_num_array(my_dequeue->nums, my_dequeue->queueSize);

    destroy_array_queue(my_dequeue);
    return 0;
}
