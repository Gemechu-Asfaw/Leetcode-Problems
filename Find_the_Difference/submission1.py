class Solution(object):
    def findTheDifference(self, s, t):
        
        occurance = [0 for i in range(26)]
        
        for i in t:
            index = ord(i) - 97
            occurance[index] += 1
        
        for i in s:
            index = ord(i) - 97
            occurance[index] -= 1
        
        ans = "a"
        
        for index, letter in enumerate(occurance):
            if letter>0:
                ans = chr(index+97)
                
        return ans
        