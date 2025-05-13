class Solution {
public:
    int getIndex(vector<int>& nums, int value){
        int s = 0, e = nums.size()-1, mid;
        while (s<=e){
            mid = s + (e-s)/2;
            if (nums[mid] >= value){
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return s;
    }

    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int positiveIndex = getIndex(nums, 1);
        int negativeIndex = getIndex(nums, 0) - 1;
        return max(negativeIndex+1, n-positiveIndex);
    }
};