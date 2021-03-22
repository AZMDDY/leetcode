# LeetCode —— 200. 岛屿数量

## 题目

![](https://azmddy.github.io/img/20210322080313.png)

## 思路

DFS，标记已经搜索过的点。

## 实现

### C++

```cpp
class Solution {
public:
    void dfs(vector<vector<char>>& gird, int row, int col, int m, int n)
    {
        if (row >= m || col >= n || row < 0 || col < 0 || gird[row][col] == '0') {
            return;
        }
        if (gird[row][col] == '1') {
            gird[row][col] = '-';
            dfs(gird, row + 1, col, m, n);
            dfs(gird, row, col + 1, m, n);
            dfs(gird, row, col - 1, m, n);
            dfs(gird, row - 1, col, m, n);
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, m, n);
                    ans++;
                }
            }
        }
        return ans;
    }
};
```

### Go

```go
func dfs(grid *[][]byte, row int, col int, m int, n int) {
	if row < 0 || col < 0 || row >= m || col >= n || (*grid)[row][col] == '0' {
		return
	}
	if (*grid)[row][col] == '1' {
		(*grid)[row][col] = '-'
		dfs(grid, row+1, col, m, n)
		dfs(grid, row-1, col, m, n)
		dfs(grid, row, col+1, m, n)
		dfs(grid, row, col-1, m, n)
	}
}

func numIslands(grid [][]byte) int {
	m := len(grid)
	n := len(grid[0])
	ans := 0
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == '1' {
				dfs(&grid, i, j, m, n)
				ans++
			}
		}
	}
	return ans
}
```

### Python

```python
class Solution:
    def dfs(self, grid, r, c):
        grid[r][c] = 0
        nr, nc = len(grid), len(grid[0])
        for x, y in [(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)]:
            if 0 <= x < nr and 0 <= y < nc and grid[x][y] == "1":
                self.dfs(grid, x, y)

    def numIslands(self, grid: List[List[str]]) -> int:
        nr = len(grid)
        if nr == 0:
            return 0
        nc = len(grid[0])

        num_islands = 0
        for r in range(nr):
            for c in range(nc):
                if grid[r][c] == "1":
                    num_islands += 1
                    self.dfs(grid, r, c)

        return num_islands
```
