class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        vector<int> vertices = {INT_MAX, INT_MIN, INT_MIN, INT_MAX};
        int row = grid.size(), col = grid[0].size();
        
        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++){
                if (grid[i][j] == 1){
                    vertices[0] = (i < vertices[0]) ? i : vertices[0];
                    vertices[1] = (j > vertices[1]) ? j : vertices[1];
                    vertices[2] = (i > vertices[2]) ? i : vertices[2];
                    vertices[3] = (j < vertices[3]) ? j : vertices[3];
                }
            }
        }
        
        return (vertices[2] - vertices[0] + 1)*(vertices[1] - vertices[3] + 1);
    }
};