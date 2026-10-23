#include <stdio.h>
#include <stdlib.h>

// Helper function to find the bound (leftmost or rightmost) using binary search
int findBound(int* nums, int numsSize, int target, int isLeft) {
    int left = 0;
    int right = numsSize - 1;
    int bound = -1; // Fixed typo here

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            bound = mid; // Record the potential answer
            if (isLeft) {
                right = mid - 1; // Keep searching left for starting position
            } else {
                left = mid + 1; // Keep searching right for ending position
            }
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return bound;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    
    // Find the leftmost and rightmost positions
    result[0] = findBound(nums, numsSize, target, 1);
    result[1] = findBound(nums, numsSize, target, 0);
    
    return result;
}
