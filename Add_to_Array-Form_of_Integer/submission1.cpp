class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        reverse(num.begin(),num.end());
        int i = 0, n = num.size(), carry = 0;

        while (k || carry){
            
            int digit = k%10;
            k = k/10;
            
            int sum = digit + carry;

            if (i<n){
                sum = sum + num[i];
                num[i] = sum % 10;
                carry = sum / 10;
            } else {
                num.push_back(sum % 10);
                carry = sum / 10;
            }

            i++;
        }

        reverse(num.begin(),num.end());
        return num;
    }
};