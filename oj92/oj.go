package oj92

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseBetween(head *ListNode, left int, right int) *ListNode {
	p := new(ListNode)
	p.Next = head
	pre := p
	for i := 0; i < left -1; i++ {
		pre = pre.Next
	}
	cur := pre.Next
	for i := 0; i < (right - left); i++ {
		next := cur.Next
		cur.Next = next.Next
		next.Next = pre.Next
		pre.Next = next
	}
	return p.Next
}
