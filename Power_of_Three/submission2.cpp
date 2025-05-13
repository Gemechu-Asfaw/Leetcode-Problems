class Solution {
public:
    bool isPowerOfThree(int n) {
        
        int i = 1;
        while (i>0 && i <= INT_MAX){
            if (i==n){
                return true;
            }

            if (i <= INT_MAX/3){
                i = i*3;
            } else {
                break;
            }
        }

        return false;
    }
};