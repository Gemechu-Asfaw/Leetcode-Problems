class Solution {
public:
    int reverse(int x) {

        int ans = 0, copy = x;
        while (copy){
            if (ans > INT_MAX/10 || ans < INT_MIN/10){
                return 0;
            }
            ans = ans*10 + copy%10;
            copy = copy / 10;
        }

        return ans;
    }
};