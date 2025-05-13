class Solution {
public:
    int maxOperations(string s) {
        
        int ans = 0, onePassed = 0, n = s.size();
        for (int i=0; i<n; i++){
            if (s[i] == '1'){
                onePassed++;
            } else if (s[i] == '0' && (i==n-1 || s[i+1]=='1')){
                ans = ans + onePassed;
            }
        }

        return ans;
    }
};