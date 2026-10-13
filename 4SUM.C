#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    long long valA = *(const int *)a;
    long long valB = *(const int *)b;
    if (valA < valB) return -1;
    if (valA > valB) return 1;
    return 0;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned arrays and *returnColumnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize < 4) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Sort the array to easily handle duplicates and use two-pointer technique
    qsort(nums, numsSize, sizeof(int), compare);

    // Estimate initial capacity for the result array
    int capacity = 16;
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 3; i++) {
        // Skip duplicate values for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // Pruning optimizations to improve execution speed
        if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break; 
        if ((long long)nums[i] + nums[numsSize - 3] + nums[numsSize - 2] + nums[numsSize - 1] < target) continue;

        for (int j = i + 1; j < numsSize - 2; j++) {
            // Skip duplicate values for the second element
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // More pruning optimizations
            if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
            if ((long long)nums[i] + nums[j] + nums[numsSize - 2] + nums[numsSize - 1] < target) continue;

            int left = j + 1;
            int right = numsSize - 1;

            while (left < right) {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {
                    // Expand capacity if the result array is full
                    if (*returnSize >= capacity) {
                        capacity *= 2;
                        result = (int**)realloc(result, capacity * sizeof(int*));
                        *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
                    }

                    // Store the found quadruplet
                    result[*returnSize] = (int*)malloc(4 * sizeof(int));
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[left];
                    result[*returnSize][3] = nums[right];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    // Skip duplicates for the third and fourth elements
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return result;
}
