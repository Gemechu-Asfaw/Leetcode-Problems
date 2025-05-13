class Solution {
public:
    void solve(vector<int> &candidates, int target, vector<int> &temp, vector<vector<int>> &ans, int n, int index){
        if (target < 0){
            return;
        } else if (index == n){
            if (target == 0){
                ans.push_back(temp);
            }
        }else{
            temp.push_back(candidates[index]);
            solve(candidates, target-candidates[index], temp, ans, n, index);
            temp.pop_back();
            solve(candidates, target, temp, ans, n, index+1);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size(), index = 0;
        solve(candidates, target, temp, ans, n, index);
        return ans;
    }
};