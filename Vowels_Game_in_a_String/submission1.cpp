class Solution {
public:
    bool doesAliceWin(string s) {
        int n = s.size(), vowelCount = 0;
        for (int i=0; i<n; i++){
            if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                vowelCount++;
            }
        }

        return vowelCount>0;
    }
};