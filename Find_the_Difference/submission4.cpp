class Solution {
public:
    char findTheDifference(string s, string t) {

        char ans = 0;
        int size = s.length();

        for (int i=0; i<=size; i++){
            char character = t[i];
            ans = ans^character;
        }

        for (int i=0; i<size; i++){
            char character = s[i];
            ans = ans^character;
        }

        return ans;

    }
};