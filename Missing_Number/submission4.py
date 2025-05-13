class Solution(object):
    def missingNumber(self, nums):
        
        n = len(nums)
        sum = 0
        nSum = n*(n+1)/2

        for i in range(n):
            sum += nums[i]
        
        return nSum-sum