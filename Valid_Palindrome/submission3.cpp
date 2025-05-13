class Solution {
public:

    char lower(char x){
        if (x>='A' && x<='Z'){
            return x-'A'+'a';
        }
        return x;
    }

    bool isPalindrome(string s) {
        
        int i=0, j=s.size()-1;
        while (i<j){

            while (i<j && !isalnum(s[i])){
                i++;
            }

            while (i<j && !isalnum(s[j])){
                j--;
            }

            if (lower(s[i++]) != lower(s[j--])){
                return false;
            }
        }

        return true;
    }
};