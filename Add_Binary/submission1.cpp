class Solution {
public:
    string addBinary(string a, string b) {

        int carry = 0;
        int i = a.length()-1;
        int j = b.length()-1;

        string ans;

        while (carry>0 || i>=0 || j>=0){

            int value = carry;

            if (i>=0){
                value = value + a[i]-'0';
                i--;
            }
            if (j>=0){
                value = value + b[j]-'0';
                j--;
            }

            if (value%2){
                ans.push_back('1');
            }
            else{
                ans.push_back('0');
            }

            if (value<2){
                carry = 0;
            }
            else{
                carry = 1;
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};