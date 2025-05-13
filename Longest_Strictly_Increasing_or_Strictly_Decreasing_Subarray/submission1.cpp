class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 1, incr = 1, decr = 1;
        for (int i=1; i<n; i++){

            // Maintaining incr and decr variable to track longest strictly increasing and longest strictly decreasing subarray respectively
            if (nums[i] > nums[i-1]){
                incr++;
                decr = 1;
            } else if (nums[i] < nums[i-1]){
                decr++;
                incr = 1;
            } else {
                incr = 1;
                decr = 1;
            }

            ans = max(ans, max(incr, decr));
        }

        return ans;
    }
};