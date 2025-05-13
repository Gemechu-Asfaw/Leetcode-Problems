class Solution {
public:
    int maxScore(string s) {
        
        int ans, tempAns;
        int n = s.size();

        // initializing the ans
        if (s[0]=='0'){
            ans++;
        }

        for (int i=1; i<n; i++){
            if (s[i]=='1'){
                ans++;
            }
        }

        tempAns = ans;

        for (int i=1; i<n-1; i++){
            if (s[i]=='1'){
                tempAns--;
            } else {
                tempAns++;
            }
            ans = max(ans, tempAns);
        }

        return ans;
    }
};