class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin(), s.end());

        int n = s.size(), i = 0, j = 0;
        string ans;

        while (s[j] == ' '){
            i++;
            j++;
        }

        while (j<n){
            while (j<n && s[j]!=' '){
                j++;
            }

            for (int k=j-1; k>=i; k--){
                ans.push_back(s[k]);
            }

            while (j<n && s[j]==' '){
                j++;
            }

            if (j!=n){
                ans.push_back(' ');
                i = j;
            }
        }

        return ans;
    }
};