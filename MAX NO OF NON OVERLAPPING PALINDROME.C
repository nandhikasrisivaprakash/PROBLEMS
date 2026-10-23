#include <string>
#include <algorithm>

class Solution {
private:
    // Helper function to check if a substring s[left...right] is a palindrome
    bool isPalindrome(const std::string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

public:
    int maxPalindromes(std::string s, int k) {
        int n = s.length();
        int count = 0;
        int last_end = -1; // Tracks the end index of the last chosen palindrome

        // Iterate through every possible right-boundary index
        for (int r = 0; r < n; ++r) {
            // 1. Check for a valid palindrome of length k ending at index r
            int l1 = r - k + 1;
            if (l1 > last_end && isPalindrome(s, l1, r)) {
                count++;
                last_end = r; // Update the boundary
                continue;     // Move to the next right-boundary
            }

            // 2. Check for a valid palindrome of length k + 1 ending at index r
            int l2 = r - k;
            if (l2 > last_end && isPalindrome(s, l2, r)) {
                count++;
                last_end = r; // Update the boundary
                continue;     // Move to the next right-boundary
            }
        }

        return count;
    }
};
