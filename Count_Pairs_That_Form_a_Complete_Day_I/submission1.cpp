class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        
        unordered_map<int, int> mapping;
        int n = hours.size(), ans = 0, remaining;
        
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