class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 1;
        int i=0, j=digits.size()-1;

        reverse(digits.begin(), digits.end());

        while (i<=j && carry==1){
            int value = digits[i] + carry;
            digits[i] = (value)%10;
            carry = value/10;
            i++;
        }

        if (carry==1)
            digits.push_back(1);
        
        reverse(digits.begin(), digits.end());
        return digits;

    }
};