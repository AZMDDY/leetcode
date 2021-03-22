package oj200

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
