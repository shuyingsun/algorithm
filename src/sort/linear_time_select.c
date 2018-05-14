#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include "common.h"
#include "../../lib/array/static_array_lib.h"

#define GROUP_SIZE 5

int linear_time_select(int *nums, int start, int end, int idx) {
    int numsSize = end - start + 1;
    int ngroups;
    int i, sub_start, sub_end, median_idx = -1, mid, k;
    int *medians = NULL, median;

    // printf("\nIn this linear_time_select():");
    // print_num_array(nums + start, end - start + 1);


    if (start == end)
        return nums[start];

    if (numsSize % GROUP_SIZE == 0) {
        ngroups = numsSize / GROUP_SIZE;
    } else {
        ngroups = numsSize / GROUP_SIZE + 1;
    }

    medians = (int *)malloc(sizeof(int) * ngroups);
    if (medians == NULL) {
        printf("Malloc failured.\n");
        return nums[start];
    }

    // Find #ngroups medians
    for (i = 0; i < ngroups; i++) {
        sub_start = start + i * GROUP_SIZE;
        sub_end = (sub_start + GROUP_SIZE - 1) < end ? (sub_start + GROUP_SIZE - 1) : end;
        // Insertion_sort for sub array nums[sub_start...sub_end]
        insertion_sort(nums + sub_start, sub_end - sub_start + 1);
        medians[i] = nums[(sub_start + sub_end) / 2];
    }
    // printf("Found the medians:");
    // print_num_array(medians, ngroups);

    // Find median from the medians
    for (i = 0; i < ngroups; i++)
        // Insertion_sort for array medians[]
        insertion_sort(medians, ngroups);
    median = medians[ngroups / 2];
    // printf("The median of medians[] is %d.\n", median);

    // Get the index of median in nums[]
    median_idx = start + get_index(nums + start, end - start + 1, median);
    if (median_idx == -1) {
        free(medians);
        return nums[start];
    }
    // printf("The median %d has index=%d.\n", median, median_idx);

    swap(&(nums[median_idx]), &(nums[end]));
    // printf("After swapping the median.");
    // print_num_array(nums + start, end - start + 1);
    mid = partition(nums, start, end);
    // printf("After partition, found mid=%d:", mid);
    // print_num_array(nums + start, end - start + 1);

    k = mid - start + 1;

    if (idx == k) {
        free(medians);
        return nums[mid];
    }
    if (idx < k) {
        free(medians);
        return linear_time_select(nums, start, mid - 1, idx);
    }
    free(medians);
    return linear_time_select(nums, mid + 1, end, idx - k);
}
