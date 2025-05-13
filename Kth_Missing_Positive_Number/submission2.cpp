class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int contender = 1, n = arr.size();
        for (int i=0; i<n; i++){
            if (arr[i] == contender){
                contender++;
            } else {
                int gap = arr[i] - contender;
                if (gap < k){
                    contender = contender + gap + 1;
                    k = k - gap;
                } else {
                    return arr[i]-(gap - k) - 1;
                }
            }
        }

        return arr[n-1] + k;
    }
};