package oj739

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func dailyTemperatures(T []int) []int {
	n := len(T)
	ans := make([]int, n)
	stk := []int{}
	for i := 0; i < n; i++ {
		for len(stk) > 0 && T[i] > T[stk[len(stk)-1]] {
			preIndex := stk[len(stk)-1]
			ans[preIndex] = i - preIndex
			stk = stk[:len(stk)-1]
		}
		stk = append(stk, i)
	}
	return ans
}
