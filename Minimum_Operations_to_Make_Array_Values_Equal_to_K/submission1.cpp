class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mini = INT_MAX, n = nums.size();
        unordered_set<int> unique;

        for (int i=0; i<n; i++){
            unique.insert(nums[i]);
            mini = min(mini, nums[i]);
        }

        if (k < mini){
            return unique.size();
        } else if (k == mini){
            return unique.size()-1;
        } else {
            return -1;
        }
    }
};