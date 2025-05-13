class Solution {
public:
    int passThePillow(int n, int time) {
        int ans = time%(2*n-2);
        return ans<n ? ans+1 : 2*n-ans-1;
    }
};