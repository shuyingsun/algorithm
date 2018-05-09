int get_max_val(int *nums, int numsSize) {
    int max = nums[0];
    int idx;

    for (idx = 1; idx < numsSize; idx++) {
        if (nums[idx] > max)
            max = nums[idx];
    }

    return max;
}

int get_min_val(int *nums, int numsSize) {
    int min = nums[0];
    int idx;

    for (idx = 1; idx < numsSize; idx++) {
        if (nums[idx] < min)
            min = nums[idx];
    }

    return min;
}
