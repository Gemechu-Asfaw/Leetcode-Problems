class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0, n = num1.size(), m = num2.size();
        string ans = "";

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i=0; i<max(m,n); i++){
            int digit = carry;
            if (i < n) digit = digit + num1[i] - '0';
            if (i < m) digit = digit + num2[i] - '0';
            ans.push_back(digit%10 + '0');
            carry = digit/10;
        }

        if (carry){
            ans.push_back(carry + '0');
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};