package oj867

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
