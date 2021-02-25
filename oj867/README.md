# LeetCode —— 867. 转置矩阵

## 题目

![20210225073113](https://raw.githubusercontent.com/AZMDDY/imgs/master/img/20210225073113.png)

## 思路

转置矩阵就是把矩阵先顺时针旋转90度，然后翻转每一行。其实是从原$M x N$矩阵得到$N x M$的矩阵，即`ans[j][i] = matrix[i][j]`

## 实现

### C++

```cpp
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n ; j++) {
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};
```

### Go

```go
func transpose(matrix [][]int) [][]int {
	m := len(matrix)
	n := len(matrix[0])
	ans := make([][]int, n)
	for i := 0; i < n; i++ {
		ans[i] = make([]int, m)
		for j := 0; j < m; j++ {
			ans[i][j] = matrix[j][i]
		}
	}
	return ans
}
```

### Python

```python
class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        m, n = len(matrix), len(matrix[0])
        ans = [[0 for i in range(m)] for j in range(n)]
        for i in range(m):
            for j in range(n):
                ans[j][i] = matrix[i][j]
        return ans
```
