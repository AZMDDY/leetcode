package oj896

func isMonotonic(A []int) bool {
	inc := true
	dec := true
	for i := 0; i < len(A)-1; i++ {
		if A[i+1] > A[i] {
			dec = false
		}
		if A[i+1] < A[i] {
			inc = false
		}
	}
	return inc || dec
}
