class Solution {
public:
    int numberOfSubstrings(string s, int k) {

        int n = s.size(), ans = 0;

        for (int i=0; i<n; i++){
            unordered_map<char, int> mapping;
            for (int j=i; j<n; j++){
                mapping[s[j]]++;
                if (mapping[s[j]] >= k){
                    ans = ans + n - j;
                    break;
                }
            }
        }

        return ans;
    }
};