class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long goodPairsCount = 0;
        unordered_map<int, int> freq;

        for (int i=0; i<n; i++){
            freq[nums[i] - i]++;
        }

        for (auto x: freq){
             goodPairsCount = goodPairsCount + (long long)x.second*(x.second-1)/2;
        }

        return (long long)n*(n-1)/2 - goodPairsCount;
    }
};