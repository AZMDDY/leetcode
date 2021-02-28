package oj303

type NumArray struct {
	prefixSums []int
}

func Constructor(nums []int) NumArray {
	prefixSums := make([]int, len(nums)+1)
	for i, v := range nums {
		prefixSums[i+1] = prefixSums[i] + v
	}
	return NumArray{prefixSums}
}

func (this *NumArray) SumRange(i int, j int) int {
	return this.prefixSums[j+1] - this.prefixSums[i]
}
