class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 1;
        int i=digits.size()-1;

        while (i>=0 && carry==1){
            int value = digits[i] + carry;
            digits[i] = (value)%10;
            carry = value/10;
            i--;
        }

        if (carry==1){
            digits.push_back(1);
            swap(digits[0],digits[digits.size()-1]);
        }
        
        return digits;

    }
};