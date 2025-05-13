class Solution(object):
    def maxSubArray(self, nums):
        
        sum = nums[0]
        maxi = nums[0]
        i = 1

        while i<len(nums):
            if sum<0:
                sum = 0
            sum += nums[i]
            maxi = max(sum,maxi)
            i += 1
        
        return maxi