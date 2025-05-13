class Solution {
public:
    int totalMoney(int n) {

        int r = 1, sum = 0;
        for (int i=1; i<=n; i++){
            sum = sum + (r++);
            if (i%7==0){
                r = r-6;
            }
        }

        return sum;
    }
};