class Solution(object):
    def missingNumber(self, nums):
        
        n = len(nums)
        sum = 0

        for i in range(n):
            sum = sum ^ nums[i]
        
        for i in range(n+1):
            sum = sum ^ i
        
        return sum