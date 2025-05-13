class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        
        sum = 0
        ans = 0

        for num in nums:
            if num==1:
                sum += 1
                ans = max(sum, ans)
            else:
                sum = 0
        
        return ans