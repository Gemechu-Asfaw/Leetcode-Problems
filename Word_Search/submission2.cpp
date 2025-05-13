class Solution {
public:
    bool search(vector<vector<char>>& board, vector<vector<int>> &visited, string word, int index, int i, int j, int row, int col){

        if (index == word.size()-1){
            if (board[i][j] == word[index]){
                return true;
            } return false;
        } else if (word[index] != board[i][j]){
            return false;
        } 

        visited[i][j] = 1;
        vector<pair<int,int>> neighbours = {{i-1,j}, {i+1,j}, {i,j-1}, {i,j+1}};
        int newX, newY;

        bool result = false;
        for (auto neighbour : neighbours){
            newX = neighbour.first;
            newY = neighbour.second;
            if (newX>=0 && newX<row && newY>=0 && newY<col && visited[newX][newY]==0){
                if (search(board, visited, word, index+1, newX, newY, row, col)){
                    result = true;
                    break;
                }
            }
        }

        visited[i][j] = 0;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        int row = board.size(), col = board[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));

        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++){
                if (search(board, visited, word, 0, i, j, row, col)){
                    return true;
                }
            }
        }

        return false;
    }
};