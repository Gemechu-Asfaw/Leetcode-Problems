class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int current = INT_MAX, n = cost.size();
        vector<int> ans(n);

        for (int i=0; i<n; i++){
            current = min(current, cost[i]);
            ans[i] = current;
        }

        return ans;
    }
};