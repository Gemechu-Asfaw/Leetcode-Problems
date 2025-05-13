class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int i=0, n = nums.size();
        int occurance = n/3;
        vector<int> ans;

        sort(nums.begin(),nums.end());
        while (i<n){

            int lower = i;
            int upper = lower;
            while (upper<n && nums[upper]==nums[lower]){
                upper++;
            }
            int size = upper-lower;

            if (size>occurance){
                ans.push_back(nums[lower]);
            }

            i = upper;
        }

        return ans;
    }
};