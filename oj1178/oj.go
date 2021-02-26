package oj1178

import "math/bits"

func findNumOfValidWords(words []string, puzzles []string) []int {
	wordsMap := map[int]int{}
	for _, w := range words {
		m := 0
		for _, c := range w {
			m |= 1 << (c - 'a')
		}
		if bits.OnesCount(uint(m)) <= 7 {
			wordsMap[m]++
		}
	}

	ans := make([]int, len(puzzles))
	for idx, puzzle := range puzzles {
		first := 1 << (puzzle[0] - 'a')
		for i := 0; i < (1 << 6); i++ {
			m := 0
			for j := 0; j < 6; j++ {
				if i>>j&1 == 1 {
					m |= 1 << (puzzle[j+1] - 'a')
				}
			}
			ans[idx] += wordsMap[m|first]
		}
	}

	return ans
}
