class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int prefixMax = nums[0], suffixMax = nums[n-1];

        vector<int> prefix(n-2), suffix(n-2);

        for (int i=1; i<n-1; i++){
            prefix[i-1] = prefixMax;
            prefixMax = max(prefixMax, nums[i]);
        }

        for (int i=n-2; i>0; i--){
            suffix[i-1] = suffixMax;
            suffixMax = max(suffixMax, nums[i]);
        }

        for (int i=1; i<n-1; i++){
            ans = max(ans, 1LL*(prefix[i-1]-nums[i])*suffix[i-1]);
        }

        return ans;
    }
};