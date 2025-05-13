class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, int k, int n, int start){
        if (start == 10){
            if (k==0 && n==0){
                ans.push_back(temp);
            }
        } else {
            temp.push_back(start);
            solve(ans, temp, k-1, n-start, start+1);
            temp.pop_back();
            solve(ans, temp, k, n, start+1);
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        int start = 1;
        solve(ans, temp, k, n, start);
        return ans;
    }
};