#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../sort/sorting.h"

int randomized_select(int *nums, int start, int end, int idx) {
    int mid = start, k;

    while (start < end) {
        mid = randomized_partition(nums, start, end);
        k = mid - start + 1;

        if (idx == k)
            return nums[mid];

        if (idx < k) {
            end = mid - 1;
        } else {
            start = mid + 1;
            idx -= k;
        }
    }
    // always start == end
    return nums[start];
}
