class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size(), count = 0;
        sort(nums.begin(), nums.end());

        for (int i=0; i<n; i++){
            if (i==0 || nums[i]==nums[i-1]){
                count++;
            } else {
                if (count & 1){
                    return false;
                }
                count = 1;
            }
        }

        return count%2==0;
    }
};