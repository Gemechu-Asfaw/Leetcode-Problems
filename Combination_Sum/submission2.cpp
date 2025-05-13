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
            int element = candidates[index];
            int count = target/element;
            for (int i=0; i<=count; i++){
                solve(candidates, target-i*element, temp, ans, n, index+1);
                temp.push_back(candidates[index]);
            }

            for (int i=0; i<=count; i++){
                temp.pop_back();
            }   
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