class Solution {
public:
    int myAtoi(string s) {

        // INT_MAX : 2147483647
        // E.g.    : 2147483648
        
        int i = 0, n = s.size(), ans = 0, sign = 1;
        bool isSymbolUsed = false;

        while (i<n && s[i]==' '){
            i++;
        }

        while (i<n){
            char character = s[i];
            if (character == '-' || character == '+'){
                if (isSymbolUsed){
                    break;
                } else if (character == '-'){
                    sign = -1;
                }
                isSymbolUsed = true;
            } else if (character>='0' && character<='9'){
                int digit = character - '0';
                if ((ans > INT_MAX/10) || (ans==INT_MAX/10 && INT_MAX%10<=digit)){
                    return INT_MAX;
                } else if ((ans < INT_MIN/10) || (ans==INT_MIN/10 && (~INT_MIN%10+1)%10<=digit)){
                    return INT_MIN;
                } else {
                    ans = ans*10 + sign*digit;
                }
                isSymbolUsed = true;
            } else {
                break;
            }
            i++;
        }

        return ans;
    }
};