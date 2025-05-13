class Solution {
public:
    long long solve(int n, vector<int>& drink1, vector<int>& drink2, vector<vector<long long>> &dp, int turn){
        if (n<0) return INT_MIN;
        if (n==0) return (turn==0) ? drink1[n] : drink2[n];
        else if (dp[n][turn] != -1) return dp[n][turn];
        long long drinkTaken = (turn==0 ? drink1[n] : drink2[n]) + solve(n-1, drink1, drink2, dp, turn);
        long long drinkNotTaken = solve(n-1, drink1, drink2, dp, (turn+1)%2);
        // cout << n << " " << turn << " ----> " << drinkTaken << endl;
        return dp[n][turn] = max(drinkTaken, drinkNotTaken);
    }

    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        long long energy1 = solve(n-1, energyDrinkA, energyDrinkB, dp, 0);
        long long energy2 = solve(n-1, energyDrinkA, energyDrinkB, dp, 1);
        // cout << energy1 << " " << energy2 << endl;
        // cout << dp[n-1][0] << " " << dp[n-1][1] << endl;
        return max(energy1, energy2);
    }
};