#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include "../../lib/array/static_array_lib.h"

int find_first_missing_positive(int *nums, int numsSize) {
    int idx;
    int curr, tmp;

    for (idx = 0; idx < numsSize; idx++) {
        curr = nums[idx];
        if (curr <= 0 || curr > numsSize) {
            nums[idx] = 0;
            continue;
        }

        nums[idx] = 0;
        while (1) {
            if (nums[curr - 1] == curr) {
                break;
            } else if (nums[curr - 1] <= 0 || nums[curr - 1] > numsSize) {
                nums[curr - 1] = curr;
                break;
            } else {
                tmp = nums[curr - 1];
                nums[curr - 1] = curr;
                curr = tmp;
            }
        }
    }

    for (idx = 0; idx < numsSize; idx++) {
        if (nums[idx] != idx + 1)
            return idx + 1;
    }
    return idx + 1;
}

int main(int argc, char *argv[]) {
    int numsSize = 0;
    int *nums = create_num_array(&numsSize);
    int missing_positive;

    if (numsSize == 0)
        return 0;
    print_num_array(nums, numsSize);

    missing_positive = find_first_missing_positive(nums, numsSize);
    printf("\nFound %d as the missing positive\n", missing_positive);

    free(nums);
    return 0;
}
