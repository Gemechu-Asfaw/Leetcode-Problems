class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int ans = 0, digit = 1;
        for (int i=0; i<4; i++){
            int digit1 = (num1/digit)%10, digit2 = (num2/digit)%10, digit3 = (num3/digit)%10;
            ans = ans + (min(digit1, min(digit2, digit3)))*digit;
            digit = digit*10;
        }
        return ans;
    }
};