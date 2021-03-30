package oj55

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

func canJump(nums []int) bool {
	maxRight := 0
	for i := 0; i < len(nums); i++ {
		if i <= maxRight {
			maxRight = max(i+nums[i], maxRight)
			if maxRight >= (len(nums) - 1) {
				return true
			}
		} else {
			return false
		}
	}
	return false
}
