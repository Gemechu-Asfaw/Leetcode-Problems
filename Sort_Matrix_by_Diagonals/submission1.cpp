class Solution {
public:
    static bool cmp(int &a, int &b){
        return b<a;
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Bottom-left triangle + Diagonal
        for (int i=0; i<n; i++){
            vector<int> diagonal;
            for (int j=0; j<n-i; j++){
                diagonal.push_back(grid[i+j][j]);
            }

            sort(diagonal.begin(), diagonal.end(), cmp);
            for (int j=0; j<n-i; j++){
                grid[i+j][j] = diagonal[j];
            }
        }

        // Top right triangle
        for (int j=1; j<n; j++){
            vector<int> diagonal;
            for (int i=0; i<n-j; i++){
                diagonal.push_back(grid[i][i+j]);
            }

            sort(diagonal.begin(), diagonal.end());
            for (int i=0; i<n-j; i++){
                grid[i][i+j] = diagonal[i];
            }
        }

        return grid;
    }
};