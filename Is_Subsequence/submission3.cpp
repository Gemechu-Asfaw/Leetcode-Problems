class Solution {
public:
    bool isSubsequence(string s, string t) {

        int size1 = s.length();
        int size2 = t.length();

        int i=0, j=0;

        while (i<size1 & j<size2){
            
            if (s[i]==t[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }

        if (i==size1){
            return true;
        }

        return false;
    }
};