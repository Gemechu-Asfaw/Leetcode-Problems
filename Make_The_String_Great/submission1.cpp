class Solution {
public:
    bool isEqual(char x, char y){
        if ((x^y)==32){
            return 1;
        } return 0;
    }

    string makeGood(string s) {

        string ans = "";
        for (int i=0; i<s.size(); i++){
            if (ans.empty() || !isEqual(ans[ans.size()-1], s[i])){
                ans.push_back(s[i]);
            } else {
                ans.pop_back();
            }
        }

        return ans;
    }
};