class Solution {
public:
    bool isPossible(vector<string> &board, int rowNo, int colNo, int n){
        int i = 1;
        while (rowNo-i>=0){
            if (board[rowNo-i][colNo] == 'Q'){
                return false;
            }
            i++;
        }

        i = 1;
        while (rowNo-i>=0 && colNo-i>=0){
            if (board[rowNo-i][colNo-i] == 'Q'){
                return false;
            }
            i++;
        }

        i = 1;
        while (rowNo-i>=0 && colNo+i<n){
            if (board[rowNo-i][colNo+i] == 'Q'){
                return false;
            }
            i++;
        }

        return true;
    }

    void solve(vector<vector<string>> &ans, vector<string> &board, int index, int n){

        if (index>=n){
            ans.push_back(board);
        }

        for (int i=0; i<n; i++){
            if (isPossible(board, index, i, n)){
                board[index][i] = 'Q';
                solve(ans, board, index+1, n);
                board[index][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string temp = "";
        int index = 0;
        for (int i=0; i<n; i++){
            temp.push_back('.');
        }
        vector<string> board(n, temp);
        solve(ans, board, index, n);
        return ans;
    }
};