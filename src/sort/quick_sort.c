#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "common.h"
#include "../../lib/array/static_array_lib.h"

int partition_count = 0;

int partition_dec(int *nums, int start, int end) {
    int i = start - 1, j = start;
    int key = nums[end];
    bool same_elements = 1;

    partition_count++;

    // Assume start < end
    while (j < end) {
        if (nums[j] != key)
            same_elements = 0;
        if (nums[j] > key) {
            i++;
            swap(&(nums[i]), &(nums[j]));
        }
        j++;
    }
    i++;
    swap(&(nums[i]), &(nums[end]));

    if (same_elements) 
        return (start + end) / 2;
    return i;
}

int partition(int *nums, int start, int end) {
    int i = start - 1, j = start;
    int key = nums[end];
    bool same_elements = 1;

    partition_count++;

    // Assume start < end
    while (j < end) {
        if (nums[j] != key)
            same_elements = 0;
        if (nums[j] < key) {
            i++;
            swap(&(nums[i]), &(nums[j]));
        }
        j++;
    }
    i++;
    swap(&(nums[i]), &(nums[end]));

    if (same_elements) 
        return (start + end) / 2;
    return i;
}

int randomized_partition(int *nums, int start, int end) {
    int i = start - 1, j = start, random = end;
    int key;
    bool same_elements = 1;

    partition_count++;
    srand(time(NULL));
    random = start + (int)((end - start) * rand() / RAND_MAX);
    if (random < end) {
        swap(&(nums[random]), &(nums[end]));
        printf("The %d time of partition is using %d as key.\n", partition_count, nums[end]);
    }
    key = nums[end];

    // Assume start < end
    while (j < end) {
        if (nums[j] != key)
            same_elements = 0;
        if (nums[j] < key) {
            i++;
            swap(&(nums[i]), &(nums[j]));
        }
        j++;
    }
    i++;
    nums[end] = nums[i];
    nums[i] = key;

    if (same_elements) 
        return (start + end) / 2;
    return i;
}

int randomized_partition_dec(int *nums, int start, int end) {
    int i = start - 1, j = start, random = end;
    int key;
    bool same_elements = 1;

    partition_count++;
    srand(time(NULL));
    random = start + (int)((end - start) * rand() / RAND_MAX);
    if (random < end) {
        swap(&(nums[random]), &(nums[end]));
        printf("The %d time of partition is using %d as key.\n", partition_count, nums[end]);
    }
    key = nums[end];

    // Assume start < end
    while (j < end) {
        if (nums[j] != key)
            same_elements = 0;
        if (nums[j] > key) {
            i++;
            swap(&(nums[i]), &(nums[j]));
        }
        j++;
    }
    i++;
    nums[end] = nums[i];
    nums[i] = key;

    if (same_elements) 
        return (start + end) / 2;
    return i;
}

void quick_sort_dec(int *nums, int start, int end) {
    int mid;

    if (nums == NULL || start >= end)
        return;

    printf("\nbefore partitioning:");
    print_num_array(nums + start, end - start + 1);
    mid = randomized_partition_dec(nums, start, end);
    printf("\nreturned mid: %d", mid);
    print_num_array(nums + start, end - start + 1);
    quick_sort_dec(nums, start, mid - 1);
    quick_sort_dec(nums, mid + 1, end);
}

int hoare_partition_dec(int *nums, int start, int end) {
    int key = nums[start];
    int i = start - 1, j = end + 1;

    partition_count++;

    while (1) {
        do {
            j--;
        } while (nums[j] < key);
        do {
            i++;
        } while (nums[i] > key);
        if (i >= j)
            return j;
        swap(&(nums[i]), &(nums[j]));
    }
}

void hoare_quick_sort_dec(int *nums, int start, int end) {
    int mid;

    if (nums == NULL || start >= end)
        return;

    printf("\nbefore partitioning:");
    print_num_array(nums + start, end - start + 1);
    mid = hoare_partition_dec(nums, start, end);
    printf("\nreturned mid: %d", mid);
    print_num_array(nums + start, end - start + 1);
    hoare_quick_sort_dec(nums, start, mid);
    hoare_quick_sort_dec(nums, mid + 1, end);
}

/*
 * Handling for a situation when more than one elements in nums are the same.
 * @param nums	the number array for sorting
 * @param start	the start index of number array
 * @param end	the end index of number array
 * @param mid1	nums[start ... mid1-1] is larger than nums[mid1]
 * @param mid2	nums[mid1 ... mid2] equals to each other
 * 		nums[mid2+1 ... end] is less than nums[mid1]/nums[mid2]
 */
void partition2_inc(int *nums, int start, int end, int *mid1, int *mid2) {
    int i = start - 1, j = start;
    int key = nums[end];
    *mid1 = start - 1;
    *mid2 = start - 1;

    partition_count++;

    printf("start=%d, end=%d\n", start, end);
    while (j < end) {
        printf("mid1=%d, mid2=%d, i=%d, j=%d, nums[j]=%d, key=%d\n", *mid1, *mid2, i, j, nums[j], key);
        if (nums[j] == key) {
            (*mid2)++;
            swap(&(nums[*mid2]), &(nums[j]));
        } else if (nums[j] < key) {
            i++;
            (*mid1)++;
            (*mid2)++;
            swap(&(nums[i]), &(nums[j]));

            if (*mid1 != *mid2) {
                swap(&(nums[*mid2]), &(nums[j]));
            }
        }
        j++;
    }
    (*mid2)++;
    swap(&(nums[*mid2]), &(nums[end]));
}

void quick_sort2_inc(int *nums, int start, int end) {
    int mid1, mid2;

    if (start >= end)
        return;
    printf("\nbefore partitioning:");
    print_num_array(nums + start, end - start + 1);

    partition2_inc(nums, start, end, &mid1, &mid2);

    printf("\nreturned mid1: %d, mid2: %d", mid1, mid2);
    print_num_array(nums + start, end - start + 1);
    quick_sort2_inc(nums, start, mid1);
    quick_sort2_inc(nums, mid2 + 1, end);
}
