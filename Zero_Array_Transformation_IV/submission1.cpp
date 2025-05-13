class Solution {
public:
    bool isFeasibleSolution(vector<int>& nums, vector<vector<int>>& queries, int n, int q, int mid){
        
        for (int i=0; i<n; i++){
            
            vector<int> temp(mid, 0);
            
            for (int j=0; j<mid; j++){
                int left = queries[j][0], right = queries[j][1], value = queries[j][2];
                if (left<=i && i<=right){
                    temp[j] = value;
                }
            }

            vector<vector<int>> dp(mid+1, vector<int>(nums[i]+1, 0));
            for (int j=1; j<=nums[i]; j++){
                dp[0][j] = -1;
            }
            
            for (int x=1; x<=mid; x++){
                for (int y=1; y<=nums[i]; y++){
                    int taken = (y-temp[x-1] < 0) ? -1 : dp[x-1][y-temp[x-1]];
                    int notTaken = dp[x-1][y];
                    if (taken==-1 && notTaken==-1){
                        dp[x][y] = -1;
                    } else {
                        dp[x][y] = 0;
                    }
                }
            }

            if (dp[mid][nums[i]]!=0){
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
            if (isFeasibleSolution(nums, queries, n, q, mid)){
                // cout << "Feasible: " << mid << endl;
                ans = mid;
                high = mid-1;
            } else {
                // cout << "Not Feasible: " << mid << endl;
                low = mid+1;
            }
        }

        return ans;
    }
};