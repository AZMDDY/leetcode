package oj53

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

func maxSubArray(nums []int) int {
	pre, maxAns := 0, nums[0]
	for _, v := range nums {
		pre = max(pre+v, v)
		maxAns = max(maxAns, pre)
	}
	return maxAns
}
