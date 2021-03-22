# LeetCode —— 46. 全排列

## 题目

![](https://azmddy.github.io/img/20210321091954.png)

## 思路

可以使用回溯法进行遍历，对已经选过的数字可以用辅助数组进行标记，也可以划分范围所需选择的范围。

## 实现

### C++

```cpp
class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& output, int first, int len)
    {
        if (first == len) {
            ans.emplace_back(output);
            return;
        }
        for (int i = first; i < len; i++) {
            swap(output[i], output[first]);
            dfs(ans, output, first + 1, len);
            swap(output[i], output[first]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;
        dfs(ans, nums, 0, nums.size());
        return ans;
    }
};
```

### Go

```go
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
```

### Python

```python
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []
        def dfs(first = 0):
            if (first == n):
                ans.append(nums[:])
            for i in range(first, n):
                nums[first], nums[i] = nums[i], nums[first]
                dfs(first+1)
                nums[first], nums[i] = nums[i], nums[first]
        dfs()
        return ans
```
