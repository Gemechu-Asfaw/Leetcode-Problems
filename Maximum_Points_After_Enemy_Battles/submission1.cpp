class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        
        int n = enemyEnergies.size(), i = 0, j= n-1;
        long long ans = 0;
        sort(enemyEnergies.begin(), enemyEnergies.end());
        
        while (j>=0 && i<n){
            
            // taking points as long as we have enough energy
            ans = ans + currentEnergy/enemyEnergies[i];
            currentEnergy = currentEnergy%enemyEnergies[i];
            
            // getting the largest possible energy if we have atleast one point
            if (ans){
                currentEnergy = currentEnergy + enemyEnergies[j];
                j--;
            } else {
                break;
            }
        }
        
        return ans;
    }
};