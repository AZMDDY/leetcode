# LeetCode —— 766. 托普利茨矩阵

## 题目

![20210222081602](https://raw.githubusercontent.com/AZMDDY/imgs/master/img/20210222081602.png)

## 思路

直接遍历，比较每个元素和其右下角元素是否相等即可。

## 实现

### C++

```cpp
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (matrix[i][j] != matrix[i + 1][j + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```

## Go

```go
func isToeplitzMatrix(matrix [][]int) bool {
	m := len(matrix)
	n := len(matrix[0])
	for i := 0; i < m-1; i++ {
		for j := 0; j < n-1; j++ {
			if matrix[i][j] != matrix[i+1][j+1] {
				return false
			}
		}
	}
	return true
}
```

## Python

```python
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
```