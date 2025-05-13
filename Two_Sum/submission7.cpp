class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> ref;
        vector<int> ans;

        for (int i=0; i<nums.size(); i++){
            int comp = target - nums[i];
            if (ref[comp]>0){
                ans.push_back(i);
                ans.push_back(ref[comp]-1);
            }
            ref[nums[i]] = i+1;
        }

        return ans;
    }
};