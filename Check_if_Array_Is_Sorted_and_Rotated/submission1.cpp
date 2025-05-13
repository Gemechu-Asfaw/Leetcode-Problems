class Solution {
public:
    bool check(vector<int>& nums) {
        int penalty = 0, n = nums.size();
        for (int i=0; i<n; i++){
            if (nums[(i+1)%n] < nums[i]){
                penalty++;
            }
        }

        return penalty==0 || penalty==1;
    }
};