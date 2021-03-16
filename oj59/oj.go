package oj59

func generateMatrix(n int) [][]int {
	matrix := make([][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = make([]int, n)
	}
	left := 0
	right := n - 1
	up := 0
	down := n - 1
	target := n * n
	num := 1
	for num <= target {
		for i := left; i <= right; i++ {
			matrix[up][i] = num
			num++
		}
		up++
		for i := up; i <= down; i++ {
			matrix[i][right] = num
			num++
		}
		right--
		for i := right; i >= left; i-- {
			matrix[down][i] = num
			num++
		}
		down--
		for i := down; i >= up; i-- {
			matrix[i][left] = num
			num++
		}
		left++
	}
	return matrix
}
