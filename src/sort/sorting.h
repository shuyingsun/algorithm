void counting_sort(int *nums, int *result, int min, int max, int numsSize);


int partition_dec(int *nums, int start, int end);
int randomized_partition_dec(int *nums, int start, int end);
void quick_sort_dec(int *nums, int start, int end);

int hoare_partition_dec(int *nums, int start, int end);
void hoare_quick_sort_dec(int *nums, int start, int end);

void partition2_inc(int *nums, int start, int end, int *mid1, int *mid2);
void quick_sort2_inc(int *nums, int start, int end);


void radix_counting_sort(int *nums, int *origin_nums, int *result, int numsSize);
void radix_sort(int *nums, int numsSize);
