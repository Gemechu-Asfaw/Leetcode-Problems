class Solution(object):
    def majorityElement(self, nums):
       
        occurance = defaultdict(int)

        for num in nums:
            occurance[num] += 1
        
        for key,value in occurance.items():
            if value>len(nums)//2:
                return key