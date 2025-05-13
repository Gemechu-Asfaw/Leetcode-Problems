class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<=0){
            return false;
        }
        return (INT_MAX/2+1)%n==0;
    }
};