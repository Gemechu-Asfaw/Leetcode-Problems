class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.size(), i = 0;
        string result = "";
        while (i<n){
            int character = 0;
            for (int j=0; j<k; j++){
                character = (character + (s[i+j]-'a')) % 26;
            }
            result.push_back(character+'a');
            i = i + k;
        }
        return result;
    }
};