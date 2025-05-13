class Solution(object):
    def searchElement(self, nums, target, s, e):

        if (s>e):
            return -1
        
        mid = s + (e-s)/2
        if (nums[mid] == target):
            return mid
        elif (nums[mid] > target):
            return self.searchElement(nums, target, s, mid-1)
        else:
            return self.searchElement(nums, target, mid+1, e)

    def search(self, nums, target):
        
        s = 0
        e = len(nums)-1

        return self.searchElement(nums, target, s, e)