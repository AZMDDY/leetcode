package oj1052

// MaxInt Return max(a, b)
func MaxInt(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxSatisfied(customers []int, grumpy []int, X int) int {
	sum := 0
	cnt := 0
	maxCnt := 0
	for i := 0; i < len(customers); i++ {
		if grumpy[i] == 1 {
			cnt += customers[i]
		} else {
			sum += customers[i]
		}
		if i >= X && grumpy[i-X] == 1 {
			cnt -= customers[i-X]
		}
		maxCnt = MaxInt(cnt, maxCnt)
	}
	return sum + maxCnt
}
