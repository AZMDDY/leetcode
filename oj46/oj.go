package oj46

func permute(nums []int) [][]int {
	var dfs func(ans *[][]int, nums []int, first int, n int)
	dfs = func(ans *[][]int, nums []int, first int, n int) {
		if first == n {
			tmp := make([]int, n, n)
			copy(tmp, nums)
			*ans = append(*ans, tmp)
			return
		}
		for i := first; i < n; i++ {
			nums[first], nums[i] = nums[i], nums[first]
			dfs(ans, nums, first+1, n)
			nums[first], nums[i] = nums[i], nums[first]
		}
	}

	var ans [][]int
	dfs(&ans, nums, 0, len(nums))
	return ans
}
