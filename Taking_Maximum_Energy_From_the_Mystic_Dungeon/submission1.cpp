class Solution {
public:
    void getMax(vector<int> &energies, vector<int> energy, int k, int n){
        
        for (int i=0; i<k; i++){
            int j = i, maxi = energies[i];
            while (j+k < n){
                energies[i] = energies[i] - energy[j];
                maxi = max(maxi, energies[i]);
                j = j + k;
            }
            
            energies[i] = maxi;
        }
    }
    
    int maximumEnergy(vector<int>& energy, int k) {
        
        vector<int> energies(k, 0);
        int n = energy.size(), ans = INT_MIN;
        
        for (int i=0; i<k; i++){
            int j = i;
            while (j < n){
                energies[i] = energies[i] + energy[j];
                j = j + k;
            }
        }
        
        getMax(energies, energy, k, n);
        
        for (int i=0 ;i<k; i++){
            ans = max(ans, energies[i]);
        }
        
        return ans;
    }
};