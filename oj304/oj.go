package oj304

type NumMatrix struct {
	prefixMatrix [][]int
}

func Constructor(matrix [][]int) NumMatrix {
	if len(matrix) == 0 {
		return NumMatrix{}
	}

	prefixM := make([][]int, len(matrix)+1)
	prefixM[0] = make([]int, len(matrix[0])+1)
	for i, row := range matrix {
		prefixM[i+1] = make([]int, len(matrix[0])+1)
		for j, k := range row {
			prefixM[i+1][j+1] = prefixM[i+1][j] + prefixM[i][j+1] - prefixM[i][j] + k
		}
	}
	return NumMatrix{prefixM}
}

func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
	return this.prefixMatrix[row2+1][col2+1] - this.prefixMatrix[row1][col2+1] - this.prefixMatrix[row2+1][col1] + this.prefixMatrix[row1][col1]
}
