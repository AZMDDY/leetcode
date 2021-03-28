package oj406

import "sort"

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func reconstructQueue(people [][]int) (ans [][]int) {
	sort.Slice(people, func(i, j int) bool {
		a, b := people[i], people[j]
		return a[0] > b[0] || a[0] == b[0] && a[1] < b[1]
	})
	for _, p := range people {
		idx := p[1]
		ans = append(ans[:idx], append([][]int{p}, ans[idx:]...)...)
	}
	return
}
