package oj338

func countBits(num int) []int {
	bits := make([]int, num+1)
	for i := 1; i <= num; i++ {
		bits[i] = bits[i>>1] + (i & 1)
	}
	return bits
}
