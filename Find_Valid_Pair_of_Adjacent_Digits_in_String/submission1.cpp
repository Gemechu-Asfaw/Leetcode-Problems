class Solution {
public:
    string findValidPair(string s) {
        int arr[10] = {0};
        int n = s.size();
        string ans = "";

        for (int i=0; i<n; i++){
            arr[s[i]-'0']++;
        }

        for (int i=0; i<n-1; i++){
            if ((s[i]!=s[i+1]) && (arr[s[i]-'0']==s[i]-'0') && (arr[s[i+1]-'0']==s[i+1]-'0')){
                ans.push_back(s[i]);
                ans.push_back(s[i+1]);
                break;
            }
        }

        return ans;
    }
};