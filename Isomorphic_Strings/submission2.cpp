class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
     int n = s.size();
     unordered_map<char,char> mapping, used;

     for (int i=0; i<n; i++){
        if (mapping.find(s[i]) == mapping.end()){
            mapping[s[i]] = t[i];
            if (used.find(t[i])!=used.end() && used[t[i]]!=s[i]){
                return false;
            } else {
                used[t[i]] = s[i];
            }
        } else if (mapping[s[i]] != t[i]){
            return false;
        }
     }   

     return true;
    }
};