class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n/2;
        vector<int> temp(n);

        // storing the elements of nums into temp such that first n/2 elements are positive and rest n/2 elements are negative
        for (int i=0; i<n; i++){
            if (nums[i]>0) temp[l++] = nums[i];
            else temp[r++] = nums[i];
        }

        // placing first n/2 elements at odd indices
        for (int i=0; i<n/2; i++){
            nums[i*2] = temp[i];
        }

        // placing first n/2 elements at even indices
        for (int i=0; i<n/2; i++){
            nums[i*2+1] = temp[i+n/2];
        }

        return nums;
    }
};