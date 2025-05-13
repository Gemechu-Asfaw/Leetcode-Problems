class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0, e = nums.size()-1, mid;
        while (s<=e){
            if (s==e) return nums[s];

            mid = s + (e-s)/2;
            if (mid%2==0){
                if (nums[mid]==nums[mid-1]){
                    e = mid-2;
                } else {
                    s = mid;
                }
            } else {
                if (nums[mid]!=nums[mid-1]){
                    e = mid-1;
                } else {
                    s = mid+1;
                }
            }
        }

        return -1;
    }
};