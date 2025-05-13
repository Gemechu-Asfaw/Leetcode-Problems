class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if (n==1) return nums[0];

        int x = nums[0], y = max(nums[0], nums[1]);
        for (int i=2; i<n; i++){
            int first = y;
            int second = nums[i] + x;
            x = y;
            y = max(first, second);
        }

        return y;
    }
};