class Solution {
public:
    int bitwiseComplement(int n) {

        if (n==0){
            return 1;
        }

        int complement=0, factor=1;
        while (n){
            if (n%2==0){
                complement = complement + factor;
            }
            factor = factor*2;
            n = n/2;
        }

        return complement;
    }
};