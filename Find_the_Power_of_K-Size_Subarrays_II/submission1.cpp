class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size(), i=0, j=0; 
        vector<int> ans;

        while (j<n){
            if (nums[j]-nums[i] != j-i){
                i = j;
            }
            if (j>=k-1){
                if (j-i >= k-1){
                    ans.push_back(nums[j]);
                } else {
                    ans.push_back(-1);
                }
            }
            j++;
        }

        return ans;
    }
};