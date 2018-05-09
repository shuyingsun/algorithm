#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>
#include "common.h"
#include "../../lib/array/static_array_lib.h"

#define NUM 10

void counting_sort(int *nums, int *origin_nums, int *result, int numsSize) {
    int idx;
    int *counting = (int *)malloc(sizeof(int) * NUM);

    if (counting == NULL) {
        printf("Malloc failure.\n");
        return;
    }

    bzero(counting, sizeof(int) * NUM);
    for (idx = 0; idx < numsSize; idx++)
        counting[nums[idx]]++;
    for (idx = 1; idx < NUM; idx++)
        counting[idx] += counting[idx - 1];
    for (idx = numsSize - 1; idx >= 0; idx--) {
        counting[nums[idx]]--;
        result[counting[nums[idx]]] = origin_nums[idx];
    }
    free(counting);
}

void radix_sort(int *nums, int numsSize) {
    int max_idx = 0, radix, idx;
    int max = get_max_val(nums, numsSize);
    int *result = (int *)malloc(sizeof(int) * numsSize);
    int *radix_nums = (int *)malloc(sizeof(int) * numsSize);

    printf("The max number is %d.\n", max);
    while (max != 0) {
        max_idx++;
        max /= 10;
    }
    printf("The max number is with %d radixes.\n", max_idx);

    for (radix = 0; radix < max_idx; radix++) {
        for (idx = 0; idx < numsSize; idx++) {
            radix_nums[idx] = nums[idx] / (int)pow(10, radix) % 10;
        }
        printf("\nradix_nums:");
        print_num_array(radix_nums, numsSize);
        counting_sort(radix_nums, nums, result, numsSize);
        for (idx = 0; idx < numsSize; idx++)
            nums[idx] = result[idx];
        printf("\nAfter the %d time of counting sort:", radix + 1);
        print_num_array(nums, numsSize);
    }
    free(radix_nums);
}

int main(int argc, char *argv[]) {
    int numsSize = 0;
    int *nums = create_num_array(&numsSize);

    if (numsSize == 0)
        return 0;
    print_num_array(nums, numsSize);

    radix_sort(nums, numsSize);

    printf("\nAfter sorting:");
    print_num_array(nums, numsSize);

    free(nums);
    return 0;
}
