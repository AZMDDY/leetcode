# LeetCode —— 304. 二维区域和检索 - 矩阵不可变

## 题目

![20210302193947](https://raw.githubusercontent.com/AZMDDY/imgs/master/img/20210302193947.png)

## 思路

首先可以通过一维前缀和的方式计算每一行的前缀和。其次是可以同过二维前缀和，计算公式： $f(i,j)=f(i−1,j)+f(i,j−1)−f(i−1,j−1)+matrix[i][j]$

## 实现

### C++

```cpp

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix)
    {
        if (matrix.empty()) {
            return;
        }
        prefixMatrix = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                prefixMatrix[i][j + 1] = prefixMatrix[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        if (prefixMatrix.empty()) {
            return 0;
        }

        int ans = 0;
        for (int i = row1; i <= row2; i++) {
            ans += prefixMatrix[i][col2 + 1] - prefixMatrix[i][col1];
        }
        return ans;
    }

private:
    vector<vector<int>> prefixMatrix;
};
```

### Go

```go
type NumMatrix struct {
	prefixMatrix [][]int
}

func Constructor(matrix [][]int) NumMatrix {
	if len(matrix) == 0 {
		return NumMatrix{}
	}

	prefixM := make([][]int, len(matrix)+1)
	prefixM[0] = make([]int, len(matrix[0])+1)
	for i, row := range matrix {
		prefixM[i+1] = make([]int, len(matrix[0])+1)
		for j, k := range row {
			prefixM[i+1][j+1] = prefixM[i+1][j] + prefixM[i][j+1] - prefixM[i][j] + k
		}
	}
	return NumMatrix{prefixM}
}

func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
	return this.prefixMatrix[row2+1][col2+1] - this.prefixMatrix[row1][col2+1] - this.prefixMatrix[row2+1][col1] + this.prefixMatrix[row1][col1]
}
```

### Python

```python
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

```
