class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int single_digit = 0, double_digit = 0, n = nums.size();
        for (int i=0; i<n; i++){
            if (nums[i] < 10){
                single_digit = single_digit + nums[i];
            } else {
                double_digit = double_digit + nums[i];
            }
        }

        return single_digit != double_digit;
    }
};