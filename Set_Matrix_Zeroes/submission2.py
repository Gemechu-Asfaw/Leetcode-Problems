class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        
        row = len(matrix)
        col = len(matrix[0])
        rowNo = [0 for _ in range(row)]
        colNo = [0 for _ in range(col)]

        # tracking all the zeros
        for i in range(row):
            for j in range(col):
                if matrix[i][j] == 0:
                    rowNo[i] = 1
                    colNo[j] = 1
        
        # Replacing each element with 0 of entire row
        for i in range(row):
            if rowNo[i]==1:
                for j in range(col):
                    matrix[i][j] = 0
        
        # Replacing each element with 0 of entire column
        for i in range(col):
            if colNo[i]==1:
                for j in range(row):
                    matrix[j][i] = 0