class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        unordered_map<int,int> mapping;
        vector<int> ans = {-1,-1};

        for (int i=0; i<n; i++){
            if (mapping.find(target-nums[i]) != mapping.end()){
                ans = {i, mapping[target-nums[i]]};
                break;
            } else {
                mapping[nums[i]] = i;
            }
        }

        return ans;
    }
};