class Solution {
public:
    bool isSolution(vector<int>& nums, vector<vector<int>> &queries, int n, int x){

        vector<int> prefixSum(n+1, 0);
        int sum = 0;

        for (int i=0; i<x; i++){
            int left = queries[i][0], right = queries[i][1], value = queries[i][2];
            prefixSum[left] = prefixSum[left] + value;
            prefixSum[right+1] = prefixSum[right+1] - value;
        }

        for (int i=0; i<n; i++){
            sum = sum + prefixSum[i];
            if (sum < nums[i]){
                return false;
            }
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        int ans = -1, low = 0, high = q, mid;
        while (low<=high){
            mid = low + (high-low)/2;
            if (isSolution(nums, queries, n, mid)){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};