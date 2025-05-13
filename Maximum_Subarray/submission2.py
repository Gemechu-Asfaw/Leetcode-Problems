class Solution(object):
    def maxSubArray(self, nums):
        
        sum = nums[0]
        maxSum = nums[0]
        n = len(nums)

        for i in range(1, n):
            if sum<0:
                sum = 0
            sum = sum + nums[i]
            maxSum = max(sum, maxSum)
        
        return maxSum