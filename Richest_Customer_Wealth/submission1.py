class Solution(object):
    def maximumWealth(self, accounts):
        
        ans = 0
        row = len(accounts)
        col = len(accounts[0])

        for i in range(row):
            sum = 0
            for j in range(col):
                sum += accounts[i][j]
            ans = max(ans, sum)
        
        return ans