class Solution {
public:
    int getPalimdromeLength(string &x, string &y){
        string temp = x + y;
        int i=0, j = temp.size()-1;
        while (i<j){
            if (temp[i]!=temp[j]){
                return 0;
            } else {
                i++;
                j--;
            }
        }

        return temp.size();
    }

    int longestPalindrome(string s, string t) {
        int m = s.size(), n = t.size(), ans = 0;
        vector<string> substrings1 = {""}, substrings2 = {""};

        

        for (int i=0; i<m; i++){
            string curr = "";
            for (int j=i; j<m; j++){
                curr.push_back(s[j]);
                substrings1.push_back(curr);
            }
        }

        for (int i=0; i<n; i++){
            string curr = "";
            for (int j=i; j<n; j++){
                curr.push_back(t[j]);
                substrings2.push_back(curr);
            }
        }

        for (string x : substrings1){
            for (string y : substrings2){
                ans = max(ans, getPalimdromeLength(x, y));
            }
        }

        return ans;
    }
};