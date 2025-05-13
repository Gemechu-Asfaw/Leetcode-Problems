class Solution {
public:
    void solve(int n, int i, string current, vector<string> &ans){
        if (i==n){
            for (int itr=0; itr<n; itr++){
                if (itr<n-1 && current[itr]==current[itr+1] && current[itr]=='0') return;
            }
            ans.push_back(current);
        } else {
            solve(n, i+1, current+"0", ans);
            solve(n, i+1, current+"1", ans);
        }
    }
    
    vector<string> validStrings(int n) {
        vector<string> ans;
        solve(n, 0, "", ans);
        return ans;
    }
};