#include <stdio.h>
#include <stdlib.h>
#include "selecting.h"
#include "../../lib/array/static_array_lib.h"

extern int partition_count;

int main(int argc, char *argv[]) {
    int numsSize = 0;
    int *nums = create_num_array(&numsSize);
    int idx, key;

    if (numsSize == 0)
        return 0;
    print_num_array(nums, numsSize);

    for (idx = 1; idx <= numsSize; idx++) {
        key = randomized_select(nums, 0, numsSize - 1, idx);
        printf("\nFound %d as the %dst least number after %d calling randomized_select():", key, idx, partition_count);
    }

    free(nums);
    return 0;
}
