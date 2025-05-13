class Solution {
public:
    bool isBalanced(string num) {

        int n = num.size(), odd = 0, even = 0;
        
        for (int i=0; i<n; i++){
            if (i%2==0) odd = odd + num[i] - 48;
            else even = even + num[i] - 48;
        }

        return odd==even;
    }
};