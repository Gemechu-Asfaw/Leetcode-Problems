class Solution {
public:
    bool isLexicographicallyFirst(string x, string y){
        int i = 0;
        while (i<x.size() && i<y.size()){
            if (x[i] == y[i]){
                i++;
            } else if (x[i] < y[i]){
                return true;
            } else {
                return false;
            }
        }

        return x.size() < y.size();
    }
    
    string findCommonResponse(vector<vector<string>>& responses) {
        
        int m = responses.size();
        unordered_map<string, int> occurrence;
        string ans = "";
        int count = 0;
        
        for (int i=0; i<m; i++){
            unordered_set<string> presence;
            for (int j=0; j<responses[i].size(); j++){
                presence.insert(responses[i][j]);
            }

            for (auto x : presence){
                occurrence[x]++;
            }
        }

        for (auto x : occurrence){
            if ((ans.size()==0) || (x.second > count) || (x.second==count && isLexicographicallyFirst(x.first, ans))){
                ans = x.first;
                count = x.second;
            }
        }

        return ans;
    }
};