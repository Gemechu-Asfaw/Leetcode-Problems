class Solution(object):
    def majorityElement(self, nums):
        
        count = 1
        num = nums[0]
        n = len(nums)

        for i in range(1, n):
            if nums[i]==num:
                count += 1
            else:
                count -=1
                if count==0:
                    num = nums[i]
                    count = 1
        
        return num