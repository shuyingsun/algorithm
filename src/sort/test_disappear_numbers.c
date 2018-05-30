#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include "../../lib/array/static_array_lib.h"

int* find_disappear_numbers(int *nums, int numsSize, int *returnSize) {
    int curr, tmp;
    int *ret = NULL;
    int idx, ret_idx = 0;

    for (idx = 0; idx < numsSize; idx++) {
        curr = nums[idx];
        nums[idx] = 0;

        while (1) {
            if (nums[curr - 1] == curr) {
                break;
            } else if (nums[curr - 1] == 0) {
                nums[curr - 1] = curr;
                break;
            } else {
                tmp = nums[curr - 1];
                nums[curr - 1] = curr;
                curr = tmp;
            }
        }
    }

    *returnSize = 0;
    for (idx = 0; idx < numsSize; idx++) {
        if (nums[idx] == 0)
            (*returnSize)++;
    }

    ret = (int *)malloc(sizeof(int) * (*returnSize));
    for (idx = 0; idx < numsSize; idx++) {
        if (nums[idx] == 0) { 
            ret[ret_idx] = idx + 1;
            ret_idx++;
        }
    }

    return ret;
}

int main(int argc, char *argv[]) {
    int numsSize = 0;
    int *nums = create_num_array(&numsSize);
    int *disappears;
    int disappearsSize;

    if (numsSize == 0)
        return 0;
    print_num_array(nums, numsSize);

    disappears = find_disappear_numbers(nums, numsSize, &disappearsSize);
    printf("Found the disappeared numbers: ");
    print_num_array(disappears, disappearsSize);

    free(disappears);
    free(nums);
    return 0;
}
