#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include "../../lib/array/static_array_lib.h"

int find_dup(int *nums, int numsSize) {
    int start = 1, end = numsSize - 1, mid = (start + end) / 2;
    int idx;
    int count;

    while (start < end) {
        count = 0;
        printf("start = %d, mid = %d, end = %d", start, mid, end);
        for (idx = 0; idx < numsSize; idx++) {
            if (nums[idx] >= start && nums[idx] <= mid)
                count++;
        }
        printf(" count = %d\n", count);
        if (count > mid - start + 1) {
            printf("In prior.\n");
            end = mid;
        } else {
            printf("In back.\n");
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    printf("start = %d, mid = %d, end = %d\n", start, mid, end);
    return start;
}

int main(int argc, char *argv[]) {
    int numsSize = 0;
    int *nums = create_num_array(&numsSize);
    int dup;

    if (numsSize == 0)
        return 0;
    print_num_array(nums, numsSize);

    dup = find_dup(nums, numsSize);
    printf("\nFound %d as the duplicate\n", dup);

    free(nums);
    return 0;
}
