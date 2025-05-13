class Solution {
public:
    int findLarger(vector<int>& nums, int i, int key){
        // int index = nums[i];
        while (true){
            if (nums[i] > key) return i;
            else i++;
        }
    }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n-2;
        while (i>=0){
            if (nums[i] < nums[i+1]) break;
            else i--;
        }

        if (i<0){
            reverse(nums.begin(), nums.end());
        } else {
            sort(nums.begin()+i+1, nums.end());
            int index = findLarger(nums, i+1, nums[i]);
            swap(nums[i], nums[index]);
        }
    }
};