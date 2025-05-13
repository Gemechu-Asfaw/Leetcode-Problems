class Solution {
public:
    bool isPerfectSquare(long long x){

        long long s = 0, e = x, mid;
        while (s<=e){
            mid = s + (e-s)/2;
            if (mid*mid == x){
                return true;
            } else if (mid*mid < x){
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return false;
    }

    bool judgeSquareSum(int c) {
        
        long long num2;
        for (long long i=0; i*i<=c; i++){
            num2 = c - i*i;
            if (isPerfectSquare(num2)){
                return true;
            }
        }

        return false;
    }
};