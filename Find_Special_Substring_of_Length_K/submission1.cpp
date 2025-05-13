class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.size(), length = 0;
        char unique = 0;
        for (int i=0; i<=n; i++){
            if (i==n) return length==k;
            if (s[i] == unique){
                length++;
            } else {
                if (length == k){
                    return true;
                }
                unique = s[i];
                length = 1;
            }
        }

        return false;
    }
};