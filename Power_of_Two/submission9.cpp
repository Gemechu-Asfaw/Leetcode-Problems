class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool result=0;
        while (n){
            if (n==1){
                result = 1;
                break;
            }
            else if (n&1){
                result = 0;
                break;
            }
            else{
                n = n>>1;
            }
        }

        return result;
    }
};