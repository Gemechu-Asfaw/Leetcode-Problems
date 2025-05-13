class Solution(object):
    def maxProfit(self, prices):
        
        ans = 0
        largest = prices[-1]
        n = len(prices)

        for i in range(n-2, -1, -1):
            ans = max(ans, largest-prices[i])
            largest = max(largest, prices[i])
        
        return ans