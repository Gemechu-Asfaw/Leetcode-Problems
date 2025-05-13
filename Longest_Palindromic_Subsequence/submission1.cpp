class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> previous(n+1, 0);
        vector<int> current(n+1, 0);

        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                if (s[i-1] == s[n-j]){
                    current[j] = 1 + previous[j-1];
                } else {
                    current[j] = max(previous[j], current[j-1]);
                }
            }

            previous = current;
        }

        return previous[n];
    }
};