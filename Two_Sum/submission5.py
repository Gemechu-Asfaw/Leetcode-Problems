class Solution(object):
    def twoSum(self, nums, target):
        
        occurance = {}
        for index, element in enumerate(nums):
            if target-element in occurance.keys():
                return [index, occurance[target-element]]
            occurance[element] = index