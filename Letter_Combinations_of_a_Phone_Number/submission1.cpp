class Solution {
public:
    void solve(string &digits, int index, int n, vector<string> &digitToLetter, string temp, vector<string> &ans){
        if (index >= n){
            if (temp.size() != 0){
                ans.push_back(temp);
            }
        } else {
            int position = digits[index] - '0' - 2;
            for (int i=0; i<digitToLetter[position].size(); i++){
                temp.push_back(digitToLetter[position][i]);
                solve(digits, index+1, n, digitToLetter, temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> digitToLetter = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        int index = 0, n = digits.size();
        string temp = "";
        solve(digits, index, n, digitToLetter, temp, ans);
        return ans;
    }
};