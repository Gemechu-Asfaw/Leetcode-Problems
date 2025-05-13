class Solution(object):
    def arraySign(self, nums):
        
        negative = 0

        for element in nums:
            if (element < 0):
                negative += 1
            elif (element==0):
                return 0
        
        if (negative%2):
            return -1
        else:
            return 1