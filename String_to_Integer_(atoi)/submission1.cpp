class Solution {
public:
    int solve(string s, int ans, int index, int sign, bool isSymbolUsed){
        if (s[index]=='\0' || s[index]=='.' || s[index]==' ' || (isSymbolUsed && (s[index]=='+' || s[index]=='-'))){
            return ans;
        } else {
            if (s[index] == '-' || s[index] == '+'){
                if (s[index] == '-'){
                    sign = -1;
                }
                isSymbolUsed = true;
            } else if (s[index]>='0' && s[index]<='9'){
                int digit = s[index]-'0';
                isSymbolUsed = true;
                if ((ans > INT_MAX/10) || (ans == INT_MAX/10 && digit%10>=INT_MAX%10)){
                    return INT_MAX;
                } else if ((ans < INT_MIN/10) || (ans == INT_MIN/10 && digit%10>=(~INT_MIN%10+1)%10)){
                    return INT_MIN;
                } else {
                    ans = ans*10 + sign*digit;
                }
            } else {
                return ans;
            }
            index++;
            return solve(s, ans, index, sign, isSymbolUsed);
        }
    }

    int myAtoi(string s) {
        int ans = 0, sign = 1, index = 0;
        bool isSymbolUsed = false;

        while (s[index]!='\0' && s[index]==' '){
            index++;
        }

        return solve(s, ans, index, sign, isSymbolUsed);
    }
};