#include <math.h>

// Helper macro to find maximum and minimum values
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// Large integer boundaries to handle edge cases where a partition falls out of bounds
#define INT_MAX_VAL 2000000
#define INT_MIN_VAL -2000000

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Ensure nums1 is always the smaller array to minimize binary search range
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    int m = nums1Size;
    int n = nums2Size;
    int low = 0;
    int high = m;
    
    while (low <= high) {
        // Find partition boundaries for both arrays
        int i = (low + high) / 2;
        int j = (m + n + 1) / 2 - i;
        
        // Boundaries for array 1
        int maxLeft1 = (i == 0) ? INT_MIN_VAL : nums1[i - 1];
        int minRight1 = (i == m) ? INT_MAX_VAL : nums1[i];
        
        // Boundaries for array 2
        int maxLeft2 = (j == 0) ? INT_MIN_VAL : nums2[j - 1];
        int minRight2 = (j == n) ? INT_MAX_VAL : nums2[j];
        
        // Perfect partition found
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            // If the total combined array size is odd
            if ((m + n) % 2 != 0) {
                return (double)MAX(maxLeft1, maxLeft2);
            }
            // If the total combined array size is even
            return (MAX(maxLeft1, maxLeft2) + MIN(minRight1, minRight2)) / 2.0;
        } 
        // We are too far right in nums1; shift left
        else if (maxLeft1 > minRight2) {
            high = i - 1;
        } 
        // We are too far left in nums1; shift right
        else {
            low = i + 1;
        }
    }
    
    return 0.0;
}
