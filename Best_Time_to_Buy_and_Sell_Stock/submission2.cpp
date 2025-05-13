class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, n = prices.size(), maxElement = prices[n-1];
        for (int i=n-2; i>=0; i--){
            ans = max(ans, maxElement-prices[i]);
            maxElement = max(maxElement, prices[i]);
        }

        return ans;
    }
};