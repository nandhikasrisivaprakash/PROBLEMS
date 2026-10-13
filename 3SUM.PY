class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        # Sort the array to easily handle duplicates and use two pointers
        nums.sort()
        res = []
        
        for i in range(len(nums) - 2):
            # If the current element is greater than 0, remaining sum cannot be 0
            if nums[i] > 0:
                break
                
            # Skip duplicate values for the first element
            if i > 0 and nums[i] == nums[i - 1]:
                continue
                
            # Initialize two pointers
            left, right = i + 1, len(nums) - 1
            
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                
                if total < 0:
                    left += 1  # Sum is too small, move left pointer right
                elif total > 0:
                    right -= 1  # Sum is too large, move right pointer left
                else:
                    res.append([nums[i], nums[left], nums[right]])
                    
                    # Skip duplicate values for the second element
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    # Skip duplicate values for the third element
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                        
                    # Move both pointers forward after finding a valid triplet
                    left += 1
                    right -= 1
                    
        return res
