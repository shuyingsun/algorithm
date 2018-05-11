#include "common.h"

void insertion_sort_dec(int *nums, int numsSize) {
    int i = 0, j = 0;

    for (i = 0; i < numsSize - 1; i++) {
        j = i + 1;
        while (j > 0) {
            if (nums[j] > nums[j - 1]) {
                swap(&(nums[j]), &(nums[j - 1]));
                j--;
            } else {
                break;
            }
        }
    }
    return;
}

void insertion_sort(int *nums, int numsSize) {
    int i = 0, j = 0;

    for (i = 0; i < numsSize - 1; i++) {
        j = i + 1;
        while (j > 0) {
            if (nums[j] < nums[j - 1]) {
                swap(&(nums[j]), &(nums[j - 1]));
                j--;
            } else {
                break;
            }
        }
    }
    return;
}
