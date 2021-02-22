class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        m = len(matrix)
        n = len(matrix[0])
        for row in range(m):
            i, j = 0, row
            while i + 1 < n and j + 1 < m:
                if i + 1 < n and j + 1 < m:
                    if matrix[j][i] != matrix[j + 1][i + 1]:
                        return False
                    j += 1
                    i += 1
        for col in range(n):
            i, j = col, 0
            while i + 1 < n and j + 1 < m:
                if i + 1 < n and j + 1 < m:
                    if matrix[j][i] != matrix[j + 1][i + 1]:
                        return False
                    j += 1
                    i += 1
        return True
