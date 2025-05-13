class Solution {
private:
    bool isFeasibleSolution(vector<int> &nums, int threshold, int n, int mid){
        int sum = 0;
        for (int i=0; i<n; i++){
            sum = sum + nums[i]/mid + min(1, nums[i]%mid);
        }
        return sum <= threshold;
    }

    int getMax(vector<int> &nums, int n){
        int maxi = INT_MIN;
        for (int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size(), maxi = getMax(nums, n), ans = -1;
        int s = 1, e = maxi, mid;

        while (s<=e){
            mid = s + (e-s)/2;
            if (isFeasibleSolution(nums, threshold, n, mid)){
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};