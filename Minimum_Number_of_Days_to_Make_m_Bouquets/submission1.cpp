class Solution {
private:
    int getMax(vector<int> &bloomDay, int n){
        int maxi = INT_MIN;
        for (int i=0; i<n; i++){
            maxi = max(maxi, bloomDay[i]);
        }
        return maxi;
    }

    bool isFeasibleSolution(vector<int> &bloomDay, int m, int k, int n, int days){
        int bouquets = 0, count = 0;
        for (int i=0; i<n; i++){
            if (bloomDay[i] <= days){
                count++;
                if (count == k){
                    count = 0;
                    bouquets++;
                }
            } else {
                count = 0;
            }
        }

        return bouquets>=m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(), maxi = getMax(bloomDay, n);
        int s = 1, e = maxi, mid;
        int ans = -1;

        while (s<=e){
            mid = s + (e-s)/2;
            if (isFeasibleSolution(bloomDay, m, k, n, mid)){
                ans = mid;
                e = mid-1;
            } else {
                s = mid+1;
            }
        }

        return ans;
    }
};