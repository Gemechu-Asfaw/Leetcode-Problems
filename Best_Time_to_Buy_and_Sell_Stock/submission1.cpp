class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(), ans = 0, maxi = prices[n-1];
        for (int i=n-1; i>=0; i--){
            ans = max(ans, maxi-prices[i]);
            maxi = max(maxi, prices[i]);
        }

        return ans;
    }
};