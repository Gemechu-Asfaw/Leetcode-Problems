class Solution(object):
    def missingNumber(self, nums):
        
        n = len(nums)
        sum = 0

        for i in range(n):
            sum = sum ^ nums[i] ^ i
        
        return sum^n