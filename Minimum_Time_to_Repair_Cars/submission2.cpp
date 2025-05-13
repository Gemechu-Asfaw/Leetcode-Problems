class Solution {
public:
    long long getMaximum(vector<int>& ranks, int n){
        int ans = INT_MIN;
        for (int i=0; i<n; i++){
            ans = max(ans, ranks[i]);
        }
        return ans;
    }

    bool isFeasibleSolution(vector<int>& ranks, int cars, long long mid, int n){
        int count = 0;
        for (int i=0; i<n; i++){
            int x = 1;
            while ((long long)ranks[i]*(long long)x*(long long)x <= mid){
                count++;
                x++;
                if (count>=cars){
                    return true;
                }
            }
        }

        return false;
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