package oj832

func flipAndInvertImage(A [][]int) [][]int {
	for _, v := range A {
		for i := 0; i < int((len(v)+1)/2); i++ {
			if v[i] == v[len(v)-i-1] {
				v[i], v[len(v)-i-1] = 1-v[i], 1-v[len(v)-i-1]
			}
		}
	}
	return A
}
