class Solution {
public:
    void getRegion(vector<vector<int>> &land, vector<vector<int>> &visited, int i, int j, int row, int col, vector<int> &coords){

        int x = i, y = j;
        while (x<row && land[x][y]==1){
            x++;
        }

        while (y<col && land[x-1][y]==1){
            y++;
        }

        for (int a=i; a<x; a++){
            for (int b=j; b<y; b++){
                visited[a][b] = 1;
            }
        }

        coords[0] = i;
        coords[1] = j;
        coords[2] = x-1;
        coords[3] = y-1;
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {

        int row = land.size(), col = land[0].size();
        vector<vector<int>> ans, visited(row, vector<int>(col, 0));

        // traversing the matrix in search of unvisited farm land i.e. 1
        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++){
                if (land[i][j]==1 && !visited[i][j]){
                    vector<int> coords = {INT_MAX, INT_MAX, INT_MIN, INT_MIN};
                    getRegion(land, visited, i, j, row, col, coords);
                    ans.push_back(coords);
                }
            }
        }

        return ans;
    }
};