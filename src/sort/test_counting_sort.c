#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include "common.h"
#include "../../lib/array/static_array_lib.h"

int main(int argc, char *argv[]) {
    int numsSize = 0;
    int *nums = create_num_array(&numsSize);
    int *result = NULL;
    int max, min;

    if (numsSize == 0)
        return 0;
    print_num_array(nums, numsSize);

    result = (int *)malloc(sizeof(int) * numsSize);
    if (result == NULL) {
        printf("Malloc failure.\n");
        return 0;
    }

    max = get_max_val(nums, numsSize);
    min = get_min_val(nums, numsSize);
    counting_sort(nums, result, min, max, numsSize);

    printf("\nAfter sorting:");
    print_num_array(result, numsSize);

    free(nums);
    free(result);
    return 0;
}
