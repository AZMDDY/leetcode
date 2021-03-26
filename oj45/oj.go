package oj45

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func jump(nums []int) int {
	pos := len(nums) - 1
	steps := 0
	for pos > 0 {
		for i := 0; i < pos; i++ {
			if nums[i]+i >= pos {
				pos = i
				steps++
				break
			}
		}
	}
	return steps
}
