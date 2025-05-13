class Solution(object):
    def countMatchingSubarrays(self, nums, pattern):
        
        ans = 0
        
        for i in range(len(nums)-len(pattern)):
            isCorrect = True
            for j in range(len(pattern)):
                if (pattern[j]==-1 and (nums[i+j+1]>=nums[i+j])):
                    isCorrect = False
                    break
                elif (pattern[j]==0 and (nums[i+j+1]>nums[i+j] or nums[i+j+1]<nums[i+j])):
                    isCorrect = False
                    break
                elif (pattern[j]==1 and (nums[i+j+1]<=nums[i+j])):
                      isCorrect = False
                      break
                
            if (isCorrect):
                ans += 1
        
        return ans