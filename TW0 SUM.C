class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // C++ allows you to use vectors and standard sorting easily
        struct Number {
            int value;
            int index;
        };

        int n = nums.size();
        vector<Number> numPairs(n);
        for (int i = 0; i < n; i++) {
            numPairs[i].value = nums[i];
            numPairs[i].index = i;
        }

        // Sort using a C++ lambda expression
        sort(numPairs.begin(), numPairs.end(), [](const Number& a, const Number& b) {
            return a.value < b.value;
        });

        int left = 0;
        int right = n - 1;

        while (left < right) {
            int current_sum = numPairs[left].value + numPairs[right].value;
            if (current_sum == target) {
                return {numPairs[left].index, numPairs[right].index};
            } else if (current_sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};
