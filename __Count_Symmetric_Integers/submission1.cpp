class Solution {
public:
    bool isSymmetric(int n){
        int length = 0, x = n, sum1 = 0, sum2 = 0;
        while (x){
            x = x/10;
            length++;
        }

        if ((length&1)==0){
            for (int i=0; i<length; i++){
                if (i<length/2){
                    sum1 = sum1 + n%10;
                } else {
                    sum2 = sum2 + n%10;
                }
                n = n/10;
            }

            return sum1==sum2;
        } else {
            return false;
        }
    }

    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i=low; i<=high; i++){
            if (isSymmetric(i)){
                ans++;
            }
        }
        return ans;
    }
};