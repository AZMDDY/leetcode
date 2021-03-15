package oj54

func spiralOrder(matrix [][]int) []int {
	ans := []int{}
	if len(matrix) == 0 {
		return ans
	}
	leftLimit := 0
	rightLimit := len(matrix[0]) - 1
	upLimit := 0
	downLimit := len(matrix) - 1
	for {
		for i := leftLimit; i <= rightLimit; i++ {
			ans = append(ans, matrix[upLimit][i])
		}
		upLimit += 1
		if upLimit > downLimit {
			break
		}
		for i := upLimit; i <= downLimit; i++ {
			ans = append(ans, matrix[i][rightLimit])
		}
		rightLimit -= 1
		if rightLimit < leftLimit {
			break
		}
		for i := rightLimit; i >= leftLimit; i-- {
			ans = append(ans, matrix[downLimit][i])
		}
		downLimit -= 1
		if downLimit < upLimit {
			break
		}
		for i := downLimit; i >= upLimit; i-- {
			ans = append(ans, matrix[i][leftLimit])
		}
		leftLimit += 1
		if leftLimit > rightLimit {
			break
		}
	}
	return ans
}
