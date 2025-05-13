class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int i=0; i<n; i++){
            if (nums[i] < 10){
                sum = sum + nums[i];
            } else {
                sum = sum - nums[i];
            }
        }

        return sum != 0;
    }
};