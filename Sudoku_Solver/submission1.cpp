class Solution {
private:
    bool isValid(vector<vector<char>>& board, int position, int digit){
        int x = position/9, y = position%9, blockX = x/3, blockY = y/3;

        for (int i=0; i<9; i++){
            if (board[x][i]==digit+'0' || board[i][y]==digit+'0' || board[blockX*3+i/3][blockY*3+i%3]==digit+'0'){
                return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, int position){

        if (position == 81){
            return true;
        }

        if (board[position/9][position%9] != '.'){
            return solve(board, position+1);
        }

        for (int digit=1; digit<=9; digit++){
            if (isValid(board, position, digit)){
                board[position/9][position%9] = digit+'0';
                if (solve(board, position+1)){
                    return true;
                }
                board[position/9][position%9] = '.';
            }
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        int position = 0;
        solve(board, position);
    }
};