class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0], occurance = 1, n = nums.size();
        for (int i=1; i<n; i++){
            if (nums[i] == ans) occurance++;
            else occurance--;
            if (!occurance){
                ans = nums[i];
                occurance = 1;
            }
        }
        return ans;
    }
};