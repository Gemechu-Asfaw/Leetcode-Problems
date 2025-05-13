class Solution {
public:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& visited, int i, int j, int n, int m){
        bool ans = grid2[i][j]==grid1[i][j] ? true : false;
        visited[i][j] = 1;
        vector<pair<int, int>> neighbours = {{i-1, j}, {i+1, j}, {i, j-1}, {i, j+1}};
        
        for (auto neighbour : neighbours){
            int newX = neighbour.first, newY = neighbour.second;
            if (newX>=0 && newX<n && newY>=0 && newY<m && !visited[newX][newY] && grid2[newX][newY]==1){
                ans = ans & dfs(grid1, grid2, visited, newX, newY, n, m);
            }
        }
        
        return ans;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size(), ans = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid2[i][j] && !visited[i][j] && dfs(grid1, grid2, visited, i, j, n, m)) ans++;
            }
        }
        
        return ans;
    }
};