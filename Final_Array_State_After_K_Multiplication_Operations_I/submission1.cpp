class Solution {
public:
    int getMinimum(vector<int> &nums, int n){
        int minimum = 0;
        for (int i=1; i<n; i++){
            if (nums[i] < nums[minimum]) minimum = i;
        }
        return minimum;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        int n = nums.size();
        for (int i=0; i<k; i++){
            int minimum = getMinimum(nums, n);
            nums[minimum] = nums[minimum] * multiplier;
        }

        return nums;
    }
};