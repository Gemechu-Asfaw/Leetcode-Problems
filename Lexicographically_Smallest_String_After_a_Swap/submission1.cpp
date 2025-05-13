class Solution {
public:
    
    string getSmallestString(string s) {
        int n = s.size();
        char x;
        for (int i=0; i<n-1; i++){
            if (s[i]%2==s[i+1]%2 && s[i+1]<s[i]){
                x = s[i];
                s[i] = s[i+1];
                s[i+1] = x;
                break;
            }
        }
        return s;
    }
};