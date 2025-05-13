class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> ans;
        int n = nums.size(), addNum = int(1e5+1);

        for (int i=0; i<n; i++){
            int index = (nums[i])%addNum - 1;
            nums[index] = nums[index] + addNum;
            if (nums[index]/addNum == 2){
                ans.push_back(index+1);
            }
        }

        return ans;
    }
};