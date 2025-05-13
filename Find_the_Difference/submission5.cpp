class Solution {
public:
    char findTheDifference(string s, string t) {

        int ans = 0;
        int size = s.length();

        for (int i=0; i<=size; i++){
            int character = t[i];
            ans = ans^character;
        }

        for (int i=0; i<size; i++){
            int character = s[i];
            ans = ans^character;
        }

        return char(ans);

    }
};