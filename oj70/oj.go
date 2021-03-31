package oj70

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func climbStairs(n int) int {
	p1, p2 := 0, 0
	p3 := 1
	for i := 1; i <= n; i++ {
		p1 = p2
		p2 = p3
		p3 = p1 + p2
	}
	return p3
}
