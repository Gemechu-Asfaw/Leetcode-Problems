class Solution(object):
    def modifiedMatrix(self, matrix):
        
        row = len(matrix)
        col = len(matrix[0])
        
        for i in range(col):
            maxi = 0
            
            # traversing to get maximum element
            for j in range(1,row):
                if (matrix[j][i] > matrix[maxi][i]):
                    maxi = j
            
            # traversing to replace -1 with highest element
            for j in range(row):
                if (matrix[j][i]==-1):
                    matrix[j][i] = matrix[maxi][i]
        
        return matrix