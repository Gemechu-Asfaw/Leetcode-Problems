class Solution {
public:
    string clearDigits(string s) {
        stack<char> letters;
        int n = s.size();
        string ans;

        for (int i=0; i<n; i++){
            if (s[i] >= 97 && s[i]<=122){
                letters.push(s[i]);
            } else {
               letters.pop();
            }
        }

        while (!letters.empty()){
            ans.push_back(letters.top());
            letters.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};