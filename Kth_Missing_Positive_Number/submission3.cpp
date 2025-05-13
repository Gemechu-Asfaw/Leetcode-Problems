class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int candidate = 1, n = arr.size();
        for (int i=0; i<n; i++){
            if (arr[i] == candidate){
                candidate++;
            } else {
                int gap = arr[i] - candidate;
                if (gap < k){
                    k = k-gap;
                    candidate = arr[i] + 1;
                } else {
                    return candidate + k - 1;
                }
            }
        }

        return candidate + k - 1;
    }
};