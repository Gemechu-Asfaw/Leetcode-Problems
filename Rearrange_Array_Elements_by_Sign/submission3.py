class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        
        arr1 = []
        arr2 = []
        n = len(nums)
        
        for i in range(n):
            element = nums[i]
            if element<0:
                arr1.append(0)
                arr1.append(element)
            else:
                arr2.append(element)
                arr2.append(0)
        
        for i in range(0, n, 2):
            arr2[i+1] = arr1[i+1]
        
        return arr2