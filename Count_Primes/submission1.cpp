class Solution {
public:
    int countPrimes(int n) {

        if (n==0 || n==1) return 0;

        vector<int> primes(n, 1);
        int ans = 0;
        primes[0] = 0;
        primes[1] = 0;

        for (int i=2; i<n; i++){
            if (primes[i] == 1){
                for (int j=2*i; j<n; j=j+i){
                    primes[j] = 0;
                }
            }
        }

        for (int i=0; i<n; i++){
            if (primes[i] == 1){
                ans++;
            }
        }

        return ans;
    }
};