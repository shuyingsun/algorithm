#include <stdio.h>

int get_max_val(int *nums, int numsSize) {
    int max = nums[0];
    int idx;

    for (idx = 1; idx < numsSize; idx++) {
        if (nums[idx] > max)
            max = nums[idx];
    }

    return max;
}

int get_min_val(int *nums, int numsSize) {
    int min = nums[0];
    int idx;

    for (idx = 1; idx < numsSize; idx++) {
        if (nums[idx] < min)
            min = nums[idx];
    }

    return min;
}

void swap(int *a,int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int get_index(int *nums, int numsSize, int val) {
    int idx;

    for (idx = 0; idx < numsSize; idx++) {
        if (nums[idx] == val)
            return idx;
    }

    printf("Cannot find %d.\n", val);
    return -1;
}
