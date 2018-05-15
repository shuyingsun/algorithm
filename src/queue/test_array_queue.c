#include "../../lib/queue/static_queue_lib.h"
#include "../../lib/array/static_array_lib.h"

int main(int argc, char *argv[]) {
    int val;
    array_queue *my_queue;

    my_queue = create_array_queue();
    if (my_queue == NULL)
        return 0;

    enqueue_array(my_queue, 4);
    printf("After enqueue(Q, 4), queue->head = %d, queue->tail = %d:", my_queue->head, my_queue->tail);
    print_num_array(my_queue->nums, my_queue->queueSize);

    enqueue_array(my_queue, 1);
    printf("After enqueue(Q, 1), queue->head = %d, queue->tail = %d:", my_queue->head, my_queue->tail);
    print_num_array(my_queue->nums, my_queue->queueSize);

    enqueue_array(my_queue, 3);
    printf("After enqueue(Q, 3), queue->head = %d, queue->tail = %d:", my_queue->head, my_queue->tail);
    print_num_array(my_queue->nums, my_queue->queueSize);

    dequeue_array(my_queue, &val);
    printf("After dequeue(Q), queue->head = %d, queue->tail = %d:", my_queue->head, my_queue->tail);
    print_num_array(my_queue->nums, my_queue->queueSize);

    enqueue_array(my_queue, 8);
    printf("After enqueue(Q, 8), queue->head = %d, queue->tail = %d:", my_queue->head, my_queue->tail);
    print_num_array(my_queue->nums, my_queue->queueSize);

    enqueue_array(my_queue, 10);
    printf("After enqueue(Q, 10), queue->head = %d, queue->tail = %d:", my_queue->head, my_queue->tail);
    print_num_array(my_queue->nums, my_queue->queueSize);

    enqueue_array(my_queue, 7);
    printf("After enqueue(Q, 7), queue->head = %d, queue->tail = %d:", my_queue->head, my_queue->tail);
    print_num_array(my_queue->nums, my_queue->queueSize);

    enqueue_array(my_queue, 6);
    printf("After enqueue(Q, 6), queue->head = %d, queue->tail = %d:", my_queue->head, my_queue->tail);
    print_num_array(my_queue->nums, my_queue->queueSize);

    dequeue_array(my_queue, &val);
    printf("After dequeue(Q), queue->head = %d, queue->tail = %d:", my_queue->head, my_queue->tail);
    print_num_array(my_queue->nums, my_queue->queueSize);

    dequeue_array(my_queue, &val);
    printf("After dequeue(Q), queue->head = %d, queue->tail = %d:", my_queue->head, my_queue->tail);
    print_num_array(my_queue->nums, my_queue->queueSize);

    dequeue_array(my_queue, &val);
    printf("After dequeue(Q), queue->head = %d, queue->tail = %d:", my_queue->head, my_queue->tail);
    print_num_array(my_queue->nums, my_queue->queueSize);

    dequeue_array(my_queue, &val);
    printf("After dequeue(Q), queue->head = %d, queue->tail = %d:", my_queue->head, my_queue->tail);
    print_num_array(my_queue->nums, my_queue->queueSize);

    dequeue_array(my_queue, &val);
    printf("After dequeue(Q), queue->head = %d, queue->tail = %d:", my_queue->head, my_queue->tail);
    print_num_array(my_queue->nums, my_queue->queueSize);

    dequeue_array(my_queue, &val);
    printf("After dequeue(Q), queue->head = %d, queue->tail = %d:", my_queue->head, my_queue->tail);
    print_num_array(my_queue->nums, my_queue->queueSize);

    destroy_array_queue(my_queue);
    return 0;
}
