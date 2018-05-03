#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*
 * The caller of create_num_array() have the responsibility to free the returned array.
 */
int* create_num_array(int *array_size) {
    int *num_array = NULL;
    int count = 0;

    printf("Input the number array size: ");
    scanf("%d", array_size);
    if (*array_size == 0)
        return NULL;

    num_array = (int *)malloc(sizeof(int) * (*array_size));
    if (num_array == NULL) {
        printf("Malloc failure.\n");
        *array_size = 0;
        return NULL;
    }

    printf("Input a number array with array size = %d:\n", *array_size);
    while (count < *array_size) {
        scanf("%d", &(num_array[count]));
        count++;
    }

    return num_array;
}

void print_num_array(int *nums, int numsSize) {
    int i;

    printf("\nThe number array is:\n");
    for (i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
