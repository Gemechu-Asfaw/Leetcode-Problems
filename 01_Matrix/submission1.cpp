class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> ans(m, vector<int>(n));

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (mat[i][j] == 0){
                    visited[i][j] = true;
                    q.push({0 , {i, j}});
                }
            }
        }

        while (!q.empty()){
            pair<int, pair<int, int>> front = q.front();
            int value = front.first, x = front.second.first, y = front.second.second;
            vector<pair<int, int>> neighbours = {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}};

            q.pop();
            ans[x][y] = value;

            for (auto neighbour : neighbours){
                int newX = neighbour.first, newY = neighbour.second, newValue = value + 1;
                if (newX>=0 && newY>=0 && newX<m && newY<n && !visited[newX][newY]){
                    q.push({newValue, {newX, newY}});
                    visited[newX][newY] = true;
                }
            }
        }

        return ans;
    }
};