class Solution {
public:
    int scoreOfString(string s) {
        
        int i = 0, ans = 0;
        while (s[i+1] != 0){
            ans = ans + abs(s[i] - s[i+1]);
            i++;
        }
        
        return ans;
    }
};