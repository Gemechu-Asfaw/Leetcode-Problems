class Solution(object):
    def countPrefixSuffixPairs(self, words):
        
        n = len(words)
        ans = 0
        
        for i in range(n):
            for j in range(i+1, n):
                if len(words[j]) >= len(words[i]):
                    
                    s1 = 0
                    e1 = len(words[j]) - 1
                    e2 = len(words[i]) - 1
                    flag = True
                    
                    while s1 < len(words[i]):
                        if words[i][s1]==words[j][s1] and words[i][e2]==words[j][e1]:
                            s1 += 1
                            e1 -= 1
                            e2 -= 1
                        else:
                            flag = False
                            break
                    
                    if flag:
                        ans += 1
        
        return ans