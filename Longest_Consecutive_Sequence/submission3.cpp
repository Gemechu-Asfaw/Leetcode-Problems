class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), ans = 0, current = 0;
        sort(nums.begin(), nums.end());

        for (int i=0; i<n; i++){
            if (i==0 || nums[i]-nums[i-1]==1) current++;
            else if (nums[i]-nums[i-1]!=0) current = 1;
            ans = max(ans, current);
        }

        return ans;
    }
};