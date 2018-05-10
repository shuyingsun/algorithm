#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "../../lib/array/static_array_lib.h"

extern int partition_count;

int main(int argc, char *argv[]) {
    int numsSize = 0;
    int *nums = create_num_array(&numsSize);
    int idx, key;

    if (numsSize == 0)
        return 0;
    print_num_array(nums, numsSize);

    printf("Select a number from the array, enter an index no larger than %d: ", numsSize);
    scanf("%d", &idx);

    key = randomized_select(nums, 0, numsSize - 1, idx);
    printf("\nFound %d after %d calling randomized_select():", key, partition_count);
    print_num_array(nums, numsSize);

    free(nums);
    return 0;
}
