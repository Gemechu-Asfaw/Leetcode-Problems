class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        
        int mod = int(1e9) + 7;
        if (n==1) return 1;
        
        vector<int> temp(n, 1);
        vector<int> temp2(n, 1);
        
        for (int i=1; i<=k; i++){
            int sum = 0;
            for (int j=1; j<n; j++){
                sum = (sum + temp[j-1])%mod;
                temp2[j] = (temp2[j] + sum)%mod;
            }
            
            for (int j=0; j<n; j++){
                temp[j] = temp2[j];
            }
        }
        
        return temp[n-1];
    }
};