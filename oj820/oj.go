package oj820

import (
	"sort"
	"strings"
)

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func minimumLengthEncoding(words []string) int {
	out := 0
	m := map[string]bool{}
	for _, w := range words {
		m[w] = true
	}
	for w, _ := range m {
		for i := 1; i < len(w); i++ {
			delete(m, w[i:])
		}
	}
	for w, _ := range m {
		out += len(w) + 1
	}
	return out
}
