class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans = 1;
        ans = (ans * m * n)/2;
        return ans;
    }
};