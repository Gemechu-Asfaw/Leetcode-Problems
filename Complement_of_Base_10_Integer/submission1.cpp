class Solution {
public:
    int bitwiseComplement(int n) {
        
        if (n==0){
            return 1;
        }

        int mask = 1, num = n;
        while (n>1){
            mask = (mask<<1)+1;
            n = n>>1;
        }

        return mask^num;
    }
};