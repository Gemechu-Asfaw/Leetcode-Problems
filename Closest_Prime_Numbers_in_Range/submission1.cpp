class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        
        vector<int> primes(right+1, 1);
        vector<int> ans(2, -1);
        vector<int> primeVector;
        int ansIndex = 0;
        primes[0] = 0;
        primes[1] = 0;

        for (int i=2; i<=right; i++){
            if (primes[i] == 1){
                for (int j=i*2; j<=right; j=j+i){
                    primes[j] = 0;
                }

                if (i>=left){
                    primeVector.push_back(i);
                }
            }
        }

        if (primeVector.size() < 2){
            return ans;
        }
        
        for (int i=0; i<primeVector.size()-1; i++){
            if ((i==0) || (primeVector[i+1]-primeVector[i] < primeVector[ansIndex+1]-primeVector[ansIndex])){
                ans[0] = primeVector[i];
                ans[1] = primeVector[i+1];
                ansIndex = i;
            }
        }

        return ans;
    }
};