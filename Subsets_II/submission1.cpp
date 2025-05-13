class Solution {
private:
    void solve(vector<int>& nums, vector<int> &temp, set<vector<int>> &unique, int index, int n){
        if (index >= n){
            vector<int> temp2 = temp;
            sort(temp2.begin(), temp2.end());
            unique.insert(temp2);
        } else {
            solve(nums, temp, unique, index+1, n);
            temp.push_back(nums[index]);
            solve(nums, temp, unique, index+1, n);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> unique;
        vector<vector<int>> ans;
        vector<int> temp;

        solve(nums, temp, unique, 0, n);

        for (auto x: unique){
            vector<int> arr;
            for (auto y:x){
                arr.push_back(y);
            }
            ans.push_back(arr);
        }

        return ans;
    }
};