class Solution {
public:
    static bool cmp(int a, int b){
        return a > b;
    }

    long long maximumTotalSum(vector<int>& maximumHeight) {
        long long ans = 0;
        int n = maximumHeight.size();
        sort(maximumHeight.begin(), maximumHeight.end(), cmp);
        for (int i=0; i<n; i++){
            if (i==0){
                ans = ans + maximumHeight[i];
            } else {
                maximumHeight[i] = min(maximumHeight[i], maximumHeight[i-1]-1);
                if (maximumHeight[i] <= 0) return -1;
                ans = ans + maximumHeight[i];
            }
        }
        return ans;
    }
};