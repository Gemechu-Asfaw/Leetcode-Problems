class Solution {
public:
    int getDigitSum(int num){
        int ans = 0;
        while (num){
            ans = ans + num%10;
            num = num/10;
        }
        return ans;
    }

    int minElement(vector<int>& nums) {
        int ans = INT_MAX, n = nums.size();
        for (int i=0; i<n; i++){
            ans = min(ans, getDigitSum(nums[i]));
        }
        return ans;
    }
};