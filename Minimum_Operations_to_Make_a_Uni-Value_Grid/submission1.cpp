class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        int m = grid.size(), n = grid[0].size();
        int mod = grid[0][0] % x;
        vector<int> temp;

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]%x != mod){
                    return -1;
                } else {
                    temp.push_back(grid[i][j]);
                }
            }
        }

        sort(temp.begin(), temp.end());
        int target = temp[(m*n)/2], ans = 0;

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                ans = ans + abs(target-grid[i][j])/x;
            }
        }

        return ans;
    }
};