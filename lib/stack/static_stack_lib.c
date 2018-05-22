#include "static_stack_lib.h"

/*
 * Create a new stack with specified stack size
 * If success, return stack size
 * If failure, return -1
 */
array_stack* create_array_stack(int stackSize) {
    array_stack* new_stack = NULL;
    int *new_nums = NULL;

    new_stack = (array_stack *)malloc(sizeof(array_stack));
    if (new_stack == NULL) {
        printf("Malloc failure for new_stack.\n");
        return NULL;
    }

    new_nums = (int *)malloc(sizeof(int) * stackSize);
    if (new_nums == NULL) {
        printf("Malloc failure for new_nums.\n");
        free(new_stack);
        return NULL;
    }

    new_stack->nums = new_nums;
    new_stack->stackSize = stackSize;
    new_stack->top = -1;

    return new_stack;
}

two_end_array_stack* create_two_end_array_stack(int stackSize) {
    two_end_array_stack* new_stack = NULL;
    int *new_nums = NULL;

    new_stack = (two_end_array_stack *)malloc(sizeof(two_end_array_stack));
    if (new_stack == NULL) {
        printf("Malloc failure for new_stack.\n");
        return NULL;
    }

    new_nums = (int *)malloc(sizeof(int) * stackSize);
    if (new_nums == NULL) {
        printf("Malloc failure for new_nums.\n");
        free(new_stack);
        return NULL;
    }

    new_stack->nums = new_nums;
    new_stack->stackSize = stackSize;
    new_stack->top1 = -1;
    new_stack->top2 = stackSize;

    return new_stack;
}

queue_by_two_stacks* create_queue_by_two_stacks(int queueSize) {
    queue_by_two_stacks *new_queue = NULL;
    array_stack *new_stack1 = NULL, *new_stack2 = NULL;

    new_queue = (queue_by_two_stacks *)malloc(sizeof(queue_by_two_stacks));
    if (new_queue == NULL) {
        printf("Malloc failure for new_queue.\n");
        return NULL;
    }

    new_stack1 = create_array_stack(queueSize);
    if (new_stack1 == NULL) {
        printf("Create new_stack1 failed.\n");
        free(new_queue);
        return NULL;
    }

    new_stack2 = create_array_stack(queueSize);
    if (new_stack2 == NULL) {
        printf("Create new_stack2 failed.\n");
        free(new_stack1);
        free(new_queue);
        return NULL;
    }

    new_queue->stack1 = new_stack1;
    new_queue->stack2 = new_stack2;

    return new_queue;
}

link_list_stack* create_link_list_stack() {
    link_list_stack *new_stack = NULL;
    link_list *new_head = NULL;

    new_stack = (link_list_stack *)malloc(sizeof(link_list_stack));
    if (new_stack == NULL) {
        printf("Malloc new_stack failed.\n");
        return NULL;
    }

    new_head = create_link_list();
    if (new_head == NULL) {
        printf("Malloc link_list failed.\n");
        free(new_stack);
        return NULL;
    }

    new_stack->head = new_head;
    return new_stack;
} 

void destroy_array_stack(array_stack *stack) {
    if (stack == NULL)
        return;
    if (stack->nums != NULL)
        free(stack->nums);
    free(stack);
}

void destroy_two_end_array_stack(two_end_array_stack *stack) {
    if (stack == NULL)
        return;
    if (stack->nums != NULL)
        free(stack->nums);
    free(stack);
}

void destroy_queue_by_two_stacks(queue_by_two_stacks *queue) {
    if (queue == NULL)
        return;
    destroy_array_stack(queue->stack1);
    destroy_array_stack(queue->stack2);
}

void destroy_link_list_stack(link_list_stack *stack) {
    if (stack == NULL)
        return;
    destroy_link_list(stack->head);
    free(stack);
}

/*
 * Check whether the stack is full
 * If full, return TRUE
 * Else, return FALSE
 */
bool is_array_stack_full(array_stack stack) {
    return (stack.top == stack.stackSize - 1);
}

bool is_two_end_array_stack_full(two_end_array_stack stack) {
    return (stack.top1 == stack.top2 - 1);
}

bool is_queue_by_two_stacks_full(queue_by_two_stacks queue) {
    return is_array_stack_full(*(queue.stack1));
}

bool is_link_list_stack_full(link_list_stack stack) {
    return false;
}

/*
 * Check whether the stack is empty
 * If empty, return TRUE
 * Else, return FALSE
 */
bool is_array_stack_empty(array_stack stack) {
    return (stack.top == -1);
}

bool is_two_end_array_stack_empty(two_end_array_stack stack, bool is_forward) {
    if (is_forward)
        return stack.top1 == -1;
    return stack.top2 == stack.stackSize;
}

bool is_queue_by_two_stacks_empty(queue_by_two_stacks queue) {
    return (is_array_stack_empty(*(queue.stack1)) && is_array_stack_empty(*(queue.stack2)));
}

bool is_link_list_stack_empty(link_list_stack stack) {
    return (stack.head->next == NULL);
}

/*
 * Insert a new element with specified value into the stack
 * If success, return the updated top
 * If failure, return -1
 */
int push_array_stack(array_stack *stack, int val) {
    if (is_array_stack_full(*stack)) {
        printf("The stack is full, push failed.\n");
        return -1;
    }
    stack->top++;
    stack->nums[stack->top] = val;
    return stack->top;
}

int push_two_end_array_stack(two_end_array_stack *stack, int val, bool is_forward) {
    if (is_two_end_array_stack_full(*stack)) {
        printf("The stack is full, push failed.\n");
        return -1;
    }
    if (is_forward) {
        stack->top1++;
        stack->nums[stack->top1] = val;
        return stack->top1;
    }
    stack->top2--;
    stack->nums[stack->top2] = val;
    return stack->top2;
}

void enqueue_by_two_stacks(queue_by_two_stacks *queue, int val) {
    if (is_queue_by_two_stacks_full(*queue)) {
        printf("The queue is full, enqueue failed.\n");
        return;
    }
    push_array_stack(queue->stack1, val);
}

void push_link_list_stack(link_list_stack *stack, int val) {
    link_list_insert(stack->head, val);
}

/*
 * Delete top element from the stack, the value of top element would be saved in param @val
 * If success, return the updated top
 * If failure, return -1
 */
int pop_array_stack(array_stack *stack, int *val) {
    if (is_array_stack_empty(*stack)) {
        printf("The stack is empty, pop failed.\n");
        return -1;
    }
    *val = stack->nums[stack->top];
    stack->top -= 1;
    return stack->top;
}

int pop_two_end_array_stack(two_end_array_stack *stack, int *val, bool is_forward) {
    if (is_two_end_array_stack_empty(*stack, is_forward)) {
        printf("The stack is empty, pop failed.\n");
        return -1;
    }
    if (is_forward) {
        *val = stack->nums[stack->top1];
        stack->top1--;
        return stack->top1;
    }
    *val = stack->nums[stack->top2];
    stack->top2++;
    return stack->top2;
}

bool dequeue_by_two_stacks(queue_by_two_stacks *queue, int *val) {
    if (is_queue_by_two_stacks_empty(*queue)) {
        printf("The queue is empty, dequeue failed.\n");
        return false;
    }
    if (is_array_stack_empty(*(queue->stack2))) {
        while (!is_array_stack_empty(*(queue->stack1))) {
            pop_array_stack(queue->stack1, val);
            push_array_stack(queue->stack2, *val);
        }
    }
    pop_array_stack(queue->stack2, val);
    return true;
}

int pop_link_list_stack(link_list_stack *stack, int *val) {
    if (is_link_list_stack_empty(*stack)) {
        printf("The stack is empty, pop failed.\n");
        return -1;
    }

    link_list_delete_first_element(stack->head, val);
    return 1;
}
