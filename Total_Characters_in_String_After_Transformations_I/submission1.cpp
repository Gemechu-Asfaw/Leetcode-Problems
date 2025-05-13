class Solution {
public:
    int lengthAfterTransformations(string s, int t) {

        int n = s.size(), ans = 0, mod = int(1e9 + 7);
        vector<int> occurrences(26, 0);

        for (int i=0; i<n; i++){
            int index = s[i] - 'a';
            occurrences[index]++;
        }

        for (int i=0; i<t; i++){
            
            vector<int> current(26, 0);
            
            for (int j=0; j<26; j++){
                if (occurrences[j] != 0){
                    if (j==25){
                        current[0] = (current[0] + occurrences[j]) % mod;
                        current[1] = (current[1] + occurrences[j]) % mod;
                    } else {
                        current[j+1] = (current[j+1] + occurrences[j]) % mod;
                    }
                }
            }

            for (int j=0; j<26; j++){
                occurrences[j] = current[j];
            }
        }

        for (int i=0; i<26; i++){
            ans = (ans + occurrences[i]) % mod;
        }

        return ans;
    }
};