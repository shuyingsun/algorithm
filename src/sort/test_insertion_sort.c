#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include "../../lib/array/static_array_lib.h"


int main(int argc, char *argv[]) {
    int numsSize = 0;
    int *nums = create_num_array(&numsSize);

    if (numsSize == 0)
        return 0;
    print_num_array(nums, numsSize);

    insertion_sort(nums, numsSize);
    printf("\nAfter insertion_sort:");
    print_num_array(nums, numsSize);

    free(nums);
    return 0;
}
