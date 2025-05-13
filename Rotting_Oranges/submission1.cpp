class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        queue<pair<int, pair<int, int>>> q;

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j] == 2){
                    q.push({0, {i, j}});
                }
            }
        }

        while (!q.empty()){
            pair<int, pair<int, int>> front = q.front();
            int time = front.first;
            int x = front.second.first;
            int y = front.second.second;

            ans = max(ans, time);
            q.pop();

            vector<pair<int, int>> neighbours = {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}};
            for (auto neighbour : neighbours){
                int newX = neighbour.first, newY = neighbour.second;
                if (newX>=0 && newY>=0 && newX<m && newY<n && grid[newX][newY] == 1){
                    grid[newX][newY] = 2;
                    q.push({time+1, {newX, newY}});
                }
            }
        }

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return ans;
    }
};