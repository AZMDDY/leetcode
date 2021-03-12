package oj331

import "strings"

func isValidSerialization(preorder string) bool {
	count := 1
	for _, v := range strings.Split(preorder, ",") {
		if count == 0 {
			return false
		}
		if string(v) == "#" {
			count--
		} else {
			count++
		}
	}
	return count == 0
}
