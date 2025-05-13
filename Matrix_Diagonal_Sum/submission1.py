class Solution(object):
    def diagonalSum(self, mat):

        n = len(mat)
        ans = 0

        for i in range(n):
            ans += mat[i][i]
            if i != n-i-1:
                ans += mat[i][n-i-1]

        return ans