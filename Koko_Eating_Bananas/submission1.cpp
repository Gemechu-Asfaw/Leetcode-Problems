class Solution {
public:
    int maxElement(vector<int>& piles, int n){
        int maxi= -1;
        for (int i=0; i<n; i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    bool isValid(vector<int> &piles, int mid, int n, int h){
        long long sum = 0;
        for (int i=0; i<n; i++){
            sum = sum + (long long)ceil(1.0*piles[i]/mid);
        }
        return sum <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), s = 1, e = maxElement(piles, n), mid;
        int ans = INT_MAX;
        while (s<=e){
            mid = s + (e-s)/2;
            if (isValid(piles, mid, n, h)){
                ans = mid;
                e = mid-1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};