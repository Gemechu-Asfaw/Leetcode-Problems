class Solution(object):
    def mergeAlternately(self, word1, word2):
        
        word = ""
        i = 0
        
        while (i<len(word1) and i<len(word2)):
            word = word + word1[i] + word2[i]
            i = i + 1
        
        while i<len(word1):
            word = word + word1[i]
            i = i + 1
        
        while i<len(word2):
            word = word + word2[i]
            i = i + 1
            
        return word