class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        priority_queue<int> max;
        long long ans = 0, reduced = 0;
        
        for (int i: happiness){
            max.push(i);
        }
        
        while (k--){
            int top = max.top();
            max.pop();
            if (top-reduced > 0){
                ans = ans + top - reduced;
                reduced++;
            } else {
                break;
            }
        }
        
        return ans;
    }
};