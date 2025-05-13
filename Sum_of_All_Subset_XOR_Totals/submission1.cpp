class Solution {
public:
    void getAns(vector<int>& nums, int n, int &ans, int temp){
        if (n<0){
            ans = ans + temp;
        } else {
            getAns(nums, n-1, ans, temp^nums[n]);
            getAns(nums, n-1, ans, temp);
        }
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), ans = 0, temp = 0;
        getAns(nums, n-1, ans, temp);
        return ans;
    }
};