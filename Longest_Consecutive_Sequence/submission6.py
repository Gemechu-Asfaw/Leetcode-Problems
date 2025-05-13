class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        n = len(nums)
        if n==0 or n==1:
            return n
        
        nums.sort()
        i = 0
        ans = 0
        
        while i<n:
            j = i+1
            sum = 1
            while (j<n and nums[j]-nums[j-1] <=1):
                if (nums[j]-nums[j-1] == 1):
                    sum += 1
                j += 1
            
            ans = max(ans,sum)
            i = j
        
        return ans