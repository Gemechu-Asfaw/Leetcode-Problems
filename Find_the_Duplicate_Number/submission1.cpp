class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int addNum = int(1e5+1), ans;
        for (int i=0; i<nums.size(); i++){
            int index = (nums[i])%addNum;
            nums[index] += addNum;
            if (nums[index]/addNum > 1){
                ans = index;
                break;
            }
        }

        return ans;
    }
};