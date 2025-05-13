class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size(), expectedNum = nums[0]+1, ans = 0;

        for (int i=1; i<n; i++){
            if (expectedNum <= nums[i]){
                expectedNum = nums[i] + 1;
            } else {
                ans = ans + expectedNum - nums[i];
                expectedNum++;
            }
        }

        return ans;
    }
};