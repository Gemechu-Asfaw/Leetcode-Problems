class Solution(object):
    def spiralOrder(self, matrix):
        
        imin = 0
        imax = len(matrix) - 1
        jmin = 0
        jmax = len(matrix[0]) - 1
        n = (imax+1)*(jmax+1)
        ans = []

        while n>0:

            j = jmin
            while j<=jmax and n>0:
                ans.append(matrix[imin][j])
                j += 1
                n -= 1
            imin += 1
            
            i = imin
            while i<=imax and n>0:
                ans.append(matrix[i][jmax])
                i += 1
                n -= 1
            jmax -= 1

            j = jmax
            while j>=jmin and n>0:
                ans.append(matrix[imax][j])
                j -= 1
                n -= 1
            imax -= 1

            i = imax
            while i>=imin and n>0:
                ans.append(matrix[i][jmin])
                i -= 1
                n -= 1
            jmin += 1
    
        return ans