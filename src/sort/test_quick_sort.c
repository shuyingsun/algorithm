#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include "../../lib/array/static_array_lib.h"

extern int partition_count;

int main(int argc, char *argv[]) {
    int numsSize = 0;
    int *nums = create_num_array(&numsSize);

    if (numsSize == 0)
        return 0;
    print_num_array(nums, numsSize);

    //quick_sort_dec(nums, 0, numsSize - 1);
    //hoare_quick_sort_dec(nums, 0, numsSize - 1);
    quick_sort2_inc(nums, 0, numsSize - 1);
    printf("\nAfter quick_sort with %d calling partition():", partition_count);
    print_num_array(nums, numsSize);

    free(nums);
    return 0;
}
