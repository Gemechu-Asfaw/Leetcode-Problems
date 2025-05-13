class Solution {
private:
    bool isNonAlphanumeric(char x){
        return !(x>=48 && x<=57) && !(x>=65 && x<=90) && !(x>=97 && x<=122);
    }

    bool isSame(char x, char y){
        return ((x^y) == 0) || ((x^y) == 32);
    }

public:
    bool isPalindrome(string s) {
        int i=0, n = s.size(), j=n-1;
        while (i<j){
            while (i<n && isNonAlphanumeric(s[i])){
                i++;
            }
            while (j>=0 && isNonAlphanumeric(s[j])){
                j--;
            }
            if (i<j && !isSame(s[i],s[j])){
                return false;
            } else {
                i++;
                j--;
            }
        }

        return true;
    }
};