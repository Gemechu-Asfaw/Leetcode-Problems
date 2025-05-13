class Solution {
public:
    bool isPalindrome(int x) {
        
        // base case : if the number is negative
        if (x<0){
            return 0;
        }

        int y = 0, z = x;
        while (z){
            if (y > INT_MAX/10) return false;
            y = y*10 + z%10;
            z = z/10;
        }

        return x==y;
    }
};