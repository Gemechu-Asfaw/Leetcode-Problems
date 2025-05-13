class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int row = grid.size(), col = grid[0].size();
        vector<pair<int,int>> rowCount(row, make_pair(0,0));
        vector<pair<int,int>> colCount(col, make_pair(0,0));
        vector<vector<int>> diff(row, vector<int>(col, 0));

        // Traversing entire grid and filling the values in rowCount and colCount
        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++){
                if (grid[i][j] == 0){
                    rowCount[i].first++;
                    colCount[j].first++;
                }else{
                    rowCount[i].second++;
                    colCount[j].second++;
                }
            }
        }

        // traversing the diff and filling the values
        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++){
                diff[i][j] = rowCount[i].second + colCount[j].second - rowCount[i].first - colCount[j].first;
            }
        }

        return diff;
    }
};