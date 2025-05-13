class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int size = nums.size();
        int i=0, j=size-1;
        while (i<j){

            // Even Case
            while (i<size && nums[i]%2==0){
                i++;
            }

            // Odd Case
            while (j>=0 && nums[j]%2){
                j--;
            }

            // Swapping
            if (i<j){
                swap(nums[i++],nums[j--]);
            }
        }

        return nums;
    }
};