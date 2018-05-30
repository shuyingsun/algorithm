#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include "../../lib/array/static_array_lib.h"

typedef struct list_node {
    int val;
    struct list_node *next;
};

int* find_all_duplicated_numbers(int *nums, int numsSize, int *returnSize) {
    int curr, tmp;
    int *ret = NULL;
    int idx;

    struct list_node *node = NULL, *head = (struct list_node *)malloc(sizeof(struct list_node));
    head->next = NULL;

    *returnSize = 0;
    for (idx = 0; idx < numsSize; idx++) {
        curr = nums[idx];
        nums[idx] = 0;

        while (1) {
            if (nums[curr - 1] == curr) {
                (*returnSize)++;
                node = (struct list_node *)malloc(sizeof(struct list_node));
                node->val = curr;
                node->next = head->next;
                head->next = node;
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

    ret = (int *)malloc(sizeof(int) * (*returnSize));
    for (idx = 0; idx < (*returnSize); idx++) {
        node = head->next;
        ret[idx] = node->val;
        head->next = node->next;
        free(node); 
    }

    free(head);
    return ret;
}

int main(int argc, char *argv[]) {
    int numsSize = 0;
    int *nums = create_num_array(&numsSize);
    int *duplicates;
    int duplicatesSize;

    if (numsSize == 0)
        return 0;
    print_num_array(nums, numsSize);

    duplicates = find_all_duplicated_numbers(nums, numsSize, &duplicatesSize);
    printf("Found the duplicated numbers: ");
    print_num_array(duplicates, duplicatesSize);

    free(duplicates);
    free(nums);
    return 0;
}
