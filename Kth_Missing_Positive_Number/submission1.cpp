class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int s = 0, e = n-1, mid;
        while (s<e){
            mid = s + (e-s)/2;
            if (arr[mid] - (mid+1) >= k){
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        int gap = arr[s] - (s+1);
        if (gap >= k){
            return arr[s] - (gap-k) - 1;
        } else {
            return arr[s] + (k-gap);
        }
    }
};