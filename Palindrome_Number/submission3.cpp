class Solution {
public:
    bool isPalindrome(int x) {
        
        // base case : if the number is negative
        if (x<0){
            return 0;
        }

        int y = 0, z = x, bufferDigit;
        while (z){
            if (y > INT_MAX/10){
                bufferDigit = z;
                break;
            }
            y = y*10 + z%10;
            z = z/10;
        }

        if (bufferDigit){
            if (bufferDigit == x%10) return true;
            x = x/10;
        } 
        
        return x==y;
    }
};