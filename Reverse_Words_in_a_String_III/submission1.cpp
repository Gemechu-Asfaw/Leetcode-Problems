class Solution {
public:
    void swapWord(string &s, int i, int j){
        while (i<j){
            swap(s[i++],s[j--]);
        }
    }

    string reverseWords(string s) {
        
        int size = s.size();
        int i=0;
        
        while (i<size){
            int j=i;
            while (s[j]!=32 && s[j]!=0){
                j++;
            }
            swapWord(s,i,j-1);
            i = j+1;
        }

        return s;

    }
};