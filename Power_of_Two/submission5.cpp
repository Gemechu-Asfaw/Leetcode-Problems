class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        int i=1;
        while (i<=n){
            if (i==n){
                return true;
            }
            else if (i>INT_MAX/2){
                return false;
            }
            i = i<<1;
        }

        return false;
    }
};