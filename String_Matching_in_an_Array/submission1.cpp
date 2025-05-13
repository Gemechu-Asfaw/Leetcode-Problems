class Solution {
public:
    bool isSubString(string x, string y){

        int i = 0, j = 0, m = x.size(), n = y.size();

        while (i < m && j < n){
            if (x[i] == y[j]){
                i++;
                j++;
            } else {
                j = j - i + 1;
                i = 0;
            }
        }

        if (i == m) return true;
        else return false;
    }

    bool isPresent(vector<string> ans, string word){
        for (string x : ans){
            if (x == word) return true;
        }

        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        
        vector<string> ans;
        int n = words.size();

        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                if (words[i].size() > words[j].size()){
                    if (!isPresent(ans, words[j]) && isSubString(words[j], words[i])) ans.push_back(words[j]);
                } else {
                    if (!isPresent(ans, words[i]) && isSubString(words[i], words[j])) ans.push_back(words[i]);
                }
            }
        }

        return ans;
    }
};