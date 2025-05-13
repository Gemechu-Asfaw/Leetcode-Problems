class Solution {
public:
    bool isPalindrome(int x) {

        if (x<0){
            return 0;
        }

        int reverse=0, copy=x;
        bool isOverflow = false;

        while (copy){
            if (INT_MAX/10<reverse){
                isOverflow = true;
                break;
            }
            else{
                reverse = reverse*10 + copy%10;
                copy = copy/10;
            }
        }

        if (isOverflow && copy==x%10){
            return 1;
        }
        else if (x==reverse){
            return 1;
        }
        return 0;
    }
};