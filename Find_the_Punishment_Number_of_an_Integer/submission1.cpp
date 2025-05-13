class Solution {
public:
    int isValid(int x, int y, int sum, int digit){
        if (y == 0){
            return x == sum;
        } else {
            return isValid(x, y/10, sum+(y%10)*digit, digit*10) || isValid(x, y/10, sum+(y%10)*digit, 1);
        }
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i=1; i<=n; i++){
            if (isValid(i, i*i, 0, 1)){
                ans = ans + i*i;
            }
        }

        return ans;
    }
};