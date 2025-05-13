class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        
        unordered_map<int, long long> mapping;
        int n = hours.size(), remaining;
        long long ans = 0;
        
        for (int i=0; i<n; i++){
            remaining = hours[i]%24;
            if (remaining==0){
                ans = ans + mapping[0];
            } else {
                ans = ans + mapping[24-remaining];
            }
            mapping[remaining]++;
        }
        
        return ans;
    }
};