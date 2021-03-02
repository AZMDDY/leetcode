class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        if len(matrix) == 0:
            return

        m, n = len(matrix), len(matrix[0])

        self.prefixM = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                self.prefixM[i + 1][j + 1] = (
                    self.prefixM[i][j + 1]
                    + self.prefixM[i + 1][j]
                    - self.prefixM[i][j]
                    + matrix[i][j]
                )

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return (
            self.prefixM[row2 + 1][col2 + 1]
            - self.prefixM[row1][col2 + 1]
            - self.prefixM[row2 + 1][col1]
            + self.prefixM[row1][col1]
        )
