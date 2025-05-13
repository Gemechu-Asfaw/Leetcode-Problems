class Solution {
public:
    long long getMaximum(vector<int>& ranks, int n){
        int ans = INT_MIN;
        for (int i=0; i<n; i++){
            ans = max(ans, ranks[i]);
        }
        return ans;
    }

    bool isFeasibleSolution(vector<int>& ranks, int cars, long long time, int n){
        long long count = 0;
        for (int i=0; i<n; i++){
            count = count + (long long)sqrt(time/ranks[i]);
        }

        return count>=(long long)cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        long long low = 0, high = getMaximum(ranks, n)*cars*cars, mid;
        long long ans = 0;
        while (low<=high){
            mid = low + (high-low)/2;
            if (isFeasibleSolution(ranks, cars, mid, n)){
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return ans;
    }
};