package oj554

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func leastBricks(wall [][]int) int {
	var m map[int]int
	m = make(map[int]int)
	for _, v := range wall {
		sum := 0
		for i := 0; i < len(v)-1; i++ {
			sum += v[i]
			m[sum]++
		}
	}
	maxCount := 0
	for k := range m {
		maxCount = max(m[k], maxCount)
	}
	return len(wall) - maxCount
}
