class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), i = 0;
        stack<string> words;
        string ans = "";

        while (i<n){
            string temp = "";
            while (i<n && s[i]==' ') i++;
            while (i<n && s[i]!=' '){
                temp.push_back(s[i]);
                i++;
            }
            words.push(temp);
            while (i<n && s[i]==' ') i++;
        }

        while (!words.empty()){
            if (ans==""){
                ans = ans + words.top();
            } else {
                ans = ans + " " + words.top();
            }
            words.pop();
        }

        return ans;
    }
};