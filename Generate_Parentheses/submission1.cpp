class Solution {
public:
    void solve(vector<string> &ans, string &temp, int open, int close){
        if (close<=0){
            ans.push_back(temp);
        } else {
            if (open>0){
                temp.push_back('(');
                solve(ans, temp, open-1, close);
                temp.pop_back();
            }

            if (close > open){
                temp.push_back(')');
                solve(ans, temp, open, close-1);
                temp.pop_back();
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        solve(ans, temp, n, n);
        return ans;
    }
};