class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapping;
        unordered_map<char, bool> isUsed;
        int n = s.size();

        for (int i=0; i<n; i++){
            if (mapping.find(s[i]) == mapping.end() && isUsed[t[i]]==false){
                mapping[s[i]] = t[i];
                isUsed[t[i]] = true;
            } else if (mapping[s[i]] != t[i]){
                return false;
            }
        }

        return true;
    }
};