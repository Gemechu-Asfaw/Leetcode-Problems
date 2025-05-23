class Solution(object):
    def searchInsert(self, nums, target):
        
        s = 0
        e = len(nums) - 1

        while s<=e:
            mid = s + (e-s)//2
            if nums[mid]==target:
                return mid
            elif nums[mid]>target:
                e = mid - 1
            else:
                s = mid + 1
        
        return s