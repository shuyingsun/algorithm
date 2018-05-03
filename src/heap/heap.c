#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "../../lib/array/static_array_lib.h"

bool is_max_heap(int *nums, int idx, int heapSize);
void test_max_heapify(int *nums, int heapSize);
void build_max_heap(int *nums, int heapSize);
void max_heap_sort_inc(int *nums, int heapSize);
int get_left_idx(int idx);
int get_right_idx(int idx);

int main(int argc, char *argv[]) {
    int numsSize = 0;
    int *nums = create_num_array(&numsSize);

    if (numsSize == 0)
        return 0;
    print_num_array(nums, numsSize);

    //test_max_heapify(nums, numsSize);
    max_heap_sort_inc(nums, numsSize);

    free(nums);
    return 0;
}

void max_heapify(int *nums, int idx, int heapSize) {
    int left_idx, right_idx;
    int largest_idx;
    int tmp;

    /* 
     * When idx >= heapSize/2, it would be leaf node,
     * which is already max heap.
     */
    while (idx < heapSize / 2) {
        largest_idx = idx;
        left_idx = get_left_idx(idx);
        right_idx = get_right_idx(idx);

        if (left_idx < heapSize && nums[left_idx] > nums[largest_idx])
            largest_idx = left_idx;
        if (right_idx < heapSize && nums[right_idx] > nums[largest_idx])
            largest_idx = right_idx;

        if (largest_idx == idx)
            break;

        tmp = nums[idx];
        nums[idx] = nums[largest_idx];
        nums[largest_idx] = tmp;
        idx = largest_idx;
    }
}

void test_max_heapify(int *nums, int heapSize) {
    int idx = -1;

    printf("Input an index of the number array to test max_heapify: ");
    scanf("%d", &idx);
    if (idx < 0 || idx >= heapSize) {
        printf("Invalid input.\n");
        return;
    }

    if (!is_max_heap(nums, get_left_idx(idx), heapSize) || !is_max_heap(nums, get_right_idx(idx), heapSize)) {
        printf("Invalid, the left or right sub-tree is not a max heap.\n");
        return;
    }

    max_heapify(nums, idx, heapSize);
    printf("\nAfter max_heapifing for idx %d:", idx);
    print_num_array(nums, heapSize);
}

int get_left_idx(int idx) {
    return 2 * idx + 1;
}

int get_right_idx(int idx) {
    return 2 * (idx + 1);
}

int get_parent_idx(int idx) {
    return (idx - 1) / 2;
}

bool is_max_heap(int *nums, int idx, int heapSize) {
    int left_idx, right_idx;

    /* 
     * When idx >= heapSize/2, it would be leaf node,
     * which is already max heap.
     */
    if (idx >= heapSize / 2)
        return 1;

    left_idx = get_left_idx(idx);
    right_idx = get_right_idx(idx);

    if (left_idx < heapSize && nums[left_idx] > nums[idx])
        return 0;
    if (right_idx < heapSize && nums[right_idx] > nums[idx])
        return 0;
    if (!is_max_heap(nums, left_idx, heapSize) || !is_max_heap(nums, right_idx, heapSize))
        return 0;

    return 1;
}

void build_max_heap(int *nums, int heapSize) {
    int idx = heapSize / 2 - 1;

    while (idx >= 0) {
        max_heapify(nums, idx, heapSize);
        idx--;
    }

    printf("\nAfter building max heap:");
    print_num_array(nums, heapSize);
}

void max_heap_sort_inc(int *nums, int heapSize) {
    int idx;
    int tmp;

    if (nums == NULL)
        return;

    build_max_heap(nums, heapSize);
    for (idx = heapSize - 1; idx > 0; idx--) {
        tmp = nums[idx];
        nums[idx] = nums[0];
        nums[0] = tmp;
        max_heapify(nums, 0, idx);
    }

    printf("\nAfter max heap increase sorting:");
    print_num_array(nums, heapSize);
}
