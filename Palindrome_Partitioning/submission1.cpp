class Solution {
private:
    bool isPalimdrome(string &word){
        int s = 0, e = word.size()-1;
        while (s<e){
            if (word[s] != word[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }

    bool isFeasibleSolution(vector<string> &temp){
        for (string word : temp){
            if (!isPalimdrome(word)){
                return false;
            }
        }
        return true;
    }

public:
    void solve(vector<vector<string>> &ans, vector<string> &temp, string &s, int index, int n){
        if (index == n){
            if (isFeasibleSolution(temp)){
                ans.push_back(temp);
            }
            return;
        }

        if (temp.size() > 0){
            temp[temp.size()-1].push_back(s[index]);
            solve(ans, temp, s, index+1, n);
            temp[temp.size()-1].pop_back();
        }

        string x(1, s[index]);
        temp.push_back(x);
        solve(ans, temp, s, index+1, n);
        temp.pop_back();
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        int index = 0, n = s.size();

        solve(ans, temp, s, index, n);
        
        return ans;
    }
};