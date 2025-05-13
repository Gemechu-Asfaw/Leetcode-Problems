class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 1, current = 0, i = 0, j = 0;
        while (j < n){
            while ((current & nums[j]) != 0){
                current = current ^ nums[i];
                i++;
            }

            if ((current & nums[j]) == 0){
                current = current ^ nums[j];
                ans = max(ans, j-i+1);
                j++;
            } 
        }

        return ans;
    }
};