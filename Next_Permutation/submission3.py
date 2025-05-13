class Solution(object):
    def getSmallestIndex(self, nums, ptr, n):

        smallest = ptr + 1
        for i in range(ptr+2, n):
            if nums[i] > nums[ptr] and nums[i] < nums[smallest]:
                smallest = i
        return smallest

    def nextPermutation(self, nums):
        
        ptr = -1
        n = len(nums)

        for i in range(n-1):
            if (nums[i]<nums[i+1]):
                ptr = i
        
        if ptr==-1:
            return nums.sort()
        else:
            index = self.getSmallestIndex(nums, ptr, n)
            print(index)
            nums[ptr], nums[index] = nums[index], nums[ptr]
            nums[ptr+1:] = sorted(nums[ptr+1:])
            return nums