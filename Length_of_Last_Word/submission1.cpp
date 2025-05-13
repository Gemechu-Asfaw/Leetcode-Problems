class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.size()-1, ans = 0;

        // neglecting the whitespaces at the beginning of the string s
        while (s[index] == 32){
            index--;
        }

        // now counting the words before encountering first whitespace
        while (index>=0 && s[index] != 32){
            index--;
            ans++;
        }

        return ans;
    }
};