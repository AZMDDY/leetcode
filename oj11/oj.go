package oj11

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxArea(height []int) int {
	right, left := 0, len(height)-1
	ans := 0
	for right < left {
		area := (left - right) * min(height[right], height[left])
		ans = max(ans, area)
		if height[right] < height[left] {
			right++
		} else if height[right] > height[left] {
			left--
		} else {
			right++
			left--
		}
	}
	return ans
}
