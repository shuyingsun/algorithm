#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "../../lib/array/static_array_lib.h"

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

void counting_sort(int *nums, int *result, int range, int numsSize) {
    int idx;
    int *counting = (int *)malloc(sizeof(int) * range);

    if (counting == NULL) {
        printf("Malloc failure.\n");
        return;
    }

    bzero(counting, sizeof(int) * range);
    for (idx = 0; idx < numsSize; idx++)
        counting[nums[idx]]++;
    for (idx = 1; idx < range; idx++)
        counting[idx] += counting[idx - 1];
    print_num_array(counting, range);
    for (idx = numsSize - 1; idx >= 0; idx--) {
        counting[nums[idx]]--;
        result[counting[nums[idx]]] = nums[idx];
    }
    free(counting);
}

int main(int argc, char *argv[]) {
    int numsSize = 0;
    int *nums = create_num_array(&numsSize);
    int *result = NULL;
    int max, min;

    if (numsSize == 0)
        return 0;
    print_num_array(nums, numsSize);

    result = (int *)malloc(sizeof(int) * numsSize);
    if (result == NULL) {
        printf("Malloc failure.\n");
        return 0;
    }

    max = get_max_val(nums, numsSize);
    min = get_min_val(nums, numsSize);
    counting_sort(nums, result, (max - min + 1), numsSize);

    printf("\nAfter sorting:");
    print_num_array(result, numsSize);

    free(nums);
    free(result);
    return 0;
}
