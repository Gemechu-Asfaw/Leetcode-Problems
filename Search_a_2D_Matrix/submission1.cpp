class Solution {
public:
    int getRowNo(vector<vector<int>>& matrix, int n, int target){
        int s = 0, e = n-1, mid, ans = -1;
        while (s<=e){
            mid = s + (e-s)/2;
            if (matrix[mid][0] == target){
                return mid;
            } else if (matrix[mid][0] < target){
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int rowNo = getRowNo(matrix, m, target);

        if (rowNo == -1){
            return false;
        }

        int s = 0, e = n-1, mid;
        while (s<=e){
            mid = s + (e-s)/2;
            if (matrix[rowNo][mid] == target){
                return true;
            } else if (matrix[rowNo][mid] < target){
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return false;
    }
};