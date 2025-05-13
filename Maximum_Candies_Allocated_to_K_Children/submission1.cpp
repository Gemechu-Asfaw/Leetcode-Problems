class Solution {
public:
    int getMaximum(vector<int>& candies, int n){
        int ans = INT_MIN;
        for (int i=0; i<n; i++){
            ans = max(ans, candies[i]);
        }
        return ans;
    }

    bool isFeasibleSolution(vector<int>& candies, int n, long long k, int x){
        long long count = 0;
        for (int i=0; i<n; i++){
            count = count + (long long)candies[i]/x;
        }
        return count>=k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int ans = 0, n = candies.size(), maxCandy = getMaximum(candies, n);
        int low = 1, high = maxCandy, mid;
        while (low <= high){
            mid = low + (high-low)/2;
            if (isFeasibleSolution(candies, n, k, mid)){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};