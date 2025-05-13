class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int> &temp, int n, int index){

        if (index==n){
            ans.push_back(temp);
        } else{
            solve(nums, ans, temp, n, index+1);
            temp.push_back(nums[index]);
            solve(nums, ans, temp, n, index+1);
            temp.pop_back();
        } 

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size(), index = 0;
        vector<int> temp;
        solve(nums, ans, temp, n, index);
        return ans;
    }
};