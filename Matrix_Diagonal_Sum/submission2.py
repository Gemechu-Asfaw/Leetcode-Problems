class Solution(object):
    def diagonalSum(self, mat):

        n = len(mat)
        ans = 0

        # primary diagonal elements
        for i in range(n):
            ans += mat[i][i]

        # secondary diagonal element
        for i in range(n):
            if i != n-i-1:
                ans += mat[i][n-i-1]
        
        return ans