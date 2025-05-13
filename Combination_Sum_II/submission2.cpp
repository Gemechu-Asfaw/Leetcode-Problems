class Solution {
public:
    void solve(vector<pair<int, int>> &arr, vector<int> &temp, int target, vector<vector<int>> &ans, int index, int n){
        if (target < 0){
            return;
        } else if (index==n){
            if (temp.size()>0 && target==0){
                ans.push_back(temp);
            }
        } else {
            solve(arr, temp, target, ans, index+1, n);
            cout << arr[index].first << endl;
            for (int i=1; i<=arr[index].second; i++){
                temp.push_back(arr[index].first);
                solve(arr, temp, target-i*arr[index].first, ans, index+1, n);
            }

            for (int i=1; i<=arr[index].second; i++){
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<pair<int, int>> arr;
        unordered_map<int, int> mapping;
        vector<vector<int>> ans;
        vector<int> temp;

        for (int i=0; i<candidates.size(); i++){
            mapping[candidates[i]]++;
        }

        for (auto pair : mapping){
            arr.push_back({pair.first, pair.second});
        }

        int n = arr.size(), index = 0;
        solve(arr, temp, target, ans, index, n);
        return ans;
    }
};