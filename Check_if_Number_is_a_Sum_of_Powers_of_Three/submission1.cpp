class Solution {
public:
    int solve(int n, int power){
        if (n==0){
            return true;
        } else if (power > n){
            return false;
        } else {
            return solve(n, power*3) || solve(n-power, power*3);
        }
    }

    bool checkPowersOfThree(int n) {
        int power = 1;
        return solve(n, power);
    }
};