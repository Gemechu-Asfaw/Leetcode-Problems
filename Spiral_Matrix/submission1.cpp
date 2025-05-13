class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, top = 0, right = n-1, bottom = m-1, count=0;
        vector<int> ans;
        while (count<m*n){

            // Top row
            for (int i=left; i<=right && count<m*n; i++){
                ans.push_back(matrix[top][i]);
                count++;
            }
            top++;

            // Right column
            for (int i=top; i<=bottom && count<m*n; i++){
                ans.push_back(matrix[i][right]);
                count++;
            }
            right--;

            // Bottom row
            for (int i=right; i>=left && count<m*n; i--){
                ans.push_back(matrix[bottom][i]);
                count++;
            }
            bottom--;

            // Left column
            for (int i=bottom; i>=top && count<m*n; i--){
                ans.push_back(matrix[i][left]);
                count++;
            }
            left++;
        }

        return ans;
    }
};