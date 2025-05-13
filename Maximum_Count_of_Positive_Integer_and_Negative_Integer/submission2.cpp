class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size(), positive = 0, negative = 0;
        for (int i=0; i<n; i++){
            if (nums[i] > 0){
                positive++;
            } else if (nums[i] < 0){
                negative++;
            }
        }

        return max(positive, negative);
    }
};