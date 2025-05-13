class Solution {
public:
    long long powerFunc(long long x, long long n){
        if (n==0){
            return 1;
        } else if (n==1){
            return x;
        } else if (n%2==0){
            return powerFunc((x*x)%int(1e9+7), n/2);
        } else {
            return (x * powerFunc((x*x)%int(1e9+7), n/2))%int(1e9+7);
        }
    }

    int countGoodNumbers(long long n) {
        int ans = powerFunc(20, n/2);
        if (n%2){
            ans  = (1LL*ans*5)%int(1e9+7); 
        }
        return ans;
    }
};