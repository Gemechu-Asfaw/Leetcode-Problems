class Solution {
public:
    bool isFeasibleSolution(vector<int>& nums, int mid, int k, int n){
        int count = 0, i = 0;
        while (i<n){
            if (nums[i] <= mid){
                count++;
                i++;
            }
            i++;
        }
        return count>=k;
    }

    int getMaxi(vector<int>& nums, int n){
        int maxi = INT_MIN;
        for (int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }

    int minCapability(vector<int>& nums, int k) {
        int n = nums.size(), ans = -1;
        int low = 1, high = getMaxi(nums, n), mid;

        while (low<=high){
            mid = low + (high-low)/2;
            if (isFeasibleSolution(nums, mid, k, n)){
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return ans;
    }
};