class Solution {
public:
    long long power(long long x, long long n){
        if (n==0){
            return 1;
        } else if (n==1){
            return x;
        } else if (n%2==0){
            return power((x*x)%int(1e9+7), n/2);
        } else {
            return (x*power((x*x)%int(1e9+7), n/2))%int(1e9+7);
        }
    }

    int countGoodNumbers(long long n) {
        return (power(20, n/2)*max(1LL, (n%2)*5))%int(1e9+7);
    }
};