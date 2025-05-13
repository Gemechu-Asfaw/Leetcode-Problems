class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int s = 0, m = 0, n = nums.size(), e=n-1;

        while (m<e){

            while (m<n && nums[m] != 2){
                if (nums[m] == 0){
                    swap(nums[m], nums[s]);
                    s++;
                }
                m++;
            }

            while (e>=0 && nums[e] == 2){
                e--;
            }

            if (m < e){
                swap(nums[m], nums[e]);
            }
        }
    }
};