class Solution {
public:
    void storePermutations(set<string> &ans, string current, vector<int> &used, string &x, int index){
        if (index == current.size()){
            ans.insert(x);
        } else{
            for (int i=0; i<current.size(); i++){
                if (used[i] == 0){
                    used[i] = 1;
                    x.push_back(current[i]);
                    storePermutations(ans, current, used, x, index+1);
                    x.pop_back();
                    used[i] = 0;
                }
            }
        }
    }

    void solve(string &tiles, set<string> &ans, string &current, int index, int n){
        if (index == n){
            if (current.size() > 0){
                string x = "";
                vector<int> used(current.size(), 0);
                storePermutations(ans, current, used, x, 0);
            }
        } else {
            current.push_back(tiles[index]);
            solve(tiles, ans, current, index+1, n);
            current.pop_back();
            solve(tiles, ans, current, index+1, n);
        }
    }

    int numTilePossibilities(string tiles) {
        set<string> ans;
        int n = tiles.size(), index = 0;
        string current = "";
        solve(tiles, ans, current, index, n);
        return ans.size();
    }
};