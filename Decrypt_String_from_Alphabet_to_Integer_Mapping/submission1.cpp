class Solution {
public:
    string freqAlphabets(string s) {
        
        string ans;
        int i = 0, n = s.size();

        while (i<n){
            if (i+2<n && s[i+2]=='#'){
                ans.push_back(char((s[i]-48)*10 + s[i+1]-48) + 97 - 1);
                i = i + 3;
            } else{
                ans.push_back(s[i] - 48 + 97 - 1);
                i++;
            }
        }

        return ans;
    }
};