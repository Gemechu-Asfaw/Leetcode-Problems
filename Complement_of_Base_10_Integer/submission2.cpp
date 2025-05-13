class Solution {
public:
    int bitwiseComplement(int n) {
        
        // Don't write this condition at bottom of code because 1's complement also gives 0
        if (n==0){
            return 1;
        }

        int factor = 1;
        while (factor<=n){
            if (n & factor){
                n = n-factor;
            }
            else{
                n = n+factor;
            }
            factor = factor*2;
        }

        return n;
    }
};