class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        
        int row = grid.size(), col = grid[0].size(), ans = 0;
        vector<vector<pair<int,int>>> dp(row, vector<pair<int,int>>(col, {0,0}));
        
        // filling each row on basis of cells
        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++){
                if (j==0){
                    if (grid[i][j] == 'X') dp[i][j] = {1,0};
                    else if (grid[i][j] == 'Y') dp[i][j] = {0,1};
                } else {
                    dp[i][j] = dp[i][j-1];
                    if (grid[i][j] == 'X') dp[i][j].first++;
                    else if (grid[i][j] == 'Y') dp[i][j].second++;
                }
            }
        }
        
        // updating each row with previous row
        for (int i=1; i<row; i++){
            for (int j=0; j<col; j++){
                dp[i][j].first = dp[i][j].first + dp[i-1][j].first;
                dp[i][j].second = dp[i][j].second + dp[i-1][j].second;
            }
        }
        
        // getting the answer
        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++){
                if (dp[i][j].first>=1 && dp[i][j].first==dp[i][j].second) ans++;
            }
        }
        
        return ans;
    }
};