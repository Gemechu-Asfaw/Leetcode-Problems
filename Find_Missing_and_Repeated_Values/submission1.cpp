class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> mapping;
        vector<int> ans(2, -1);
        int n = grid.size();

        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                mapping[grid[i][j]]++;
            }
        }

        for (int i=1; i<=n*n; i++){
            if (mapping.find(i)==mapping.end()){
                ans[1] = i;
            } else if (mapping[i] == 2){
                ans[0] = i;
            }
        }

        return ans;
    }
};