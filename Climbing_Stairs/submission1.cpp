class Solution {

public:
    int climbStairs(int n) {
        int x = 1, y = 1, z;
        for (int i=2; i<=n; i++){
            z = x + y;
            x = y;
            y = z;
        }
        return y;
    }
};