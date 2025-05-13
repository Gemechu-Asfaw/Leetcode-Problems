class Solution(object):
    def repeatedSubstringPattern(self, s):
        
        index = 0
        substring = s[index]
        
        while (len(substring) < len(s)):
            if (len(s) % len(substring) == 0):
                
                flag = True
                for i in range(0, len(s), len(substring)):
                    if (substring != s[i:i+len(substring)]):
                        flag = False
                
                if (flag == True):
                    return True
            
            index += 1
            substring += s[index]
        
        return False