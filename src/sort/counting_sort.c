#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "../../lib/array/static_array_lib.h"

void counting_sort(int *nums, int *result, int min, int max, int numsSize) {
    int idx;
    int range = max - min + 1;
    int *counting = (int *)malloc(sizeof(int) * range);

    if (counting == NULL) {
        printf("Malloc failure.\n");
        return;
    }

    bzero(counting, sizeof(int) * range);
    for (idx = 0; idx < numsSize; idx++)
        counting[nums[idx] - min]++;
    for (idx = 1; idx < range; idx++)
        counting[idx] += counting[idx - 1];
    print_num_array(counting, range);
    for (idx = numsSize - 1; idx >= 0; idx--) {
        counting[nums[idx] - min]--;
        result[counting[nums[idx] - min]] = nums[idx];
    }
    free(counting);
}
