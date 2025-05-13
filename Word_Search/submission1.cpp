class Solution {
private:
    bool solve(vector<vector<char>>& board, string &word, vector<vector<bool>> &visited, int i, int j, int index, int m, int n, int size){
        if (index == size-1){
            return board[i][j]==word[index];
        } else if (board[i][j] != word[index]){
            return false;
        } else {
            vector<pair<int, int>> neighbours = {{i-1, j}, {i+1, j}, {i, j-1}, {i, j+1}};
            visited[i][j] = true;
            bool ans = false;

            for (auto neighbour : neighbours){
                int newX = neighbour.first, newY = neighbour.second;
                if (newX>=0 && newY>=0 && newX<m && newY<n && !visited[newX][newY]){
                    if (solve(board, word, visited, newX, newY, index+1, m, n, size)){
                        ans = true;
                    }
                }
            }

            visited[i][j] = false;
            return ans;
            
        }
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size(), size = word.size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (solve(board, word, visited, i, j, 0, m, n, size)){
                    return true;
                }
            }
        }

        return false;
    }
};