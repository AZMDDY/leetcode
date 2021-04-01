# LeetCode —— 53. 最大子序和

## 题目

![](https://azmddy.github.io/img/20210402074243.png)

## 思路

贪心算法，如果一段连续的数组加上后一个数，比后一个数小，则舍弃前面的一段，从这个数重新开始。

## 实现

### C++

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int pre = 0;
        int maxAns = nums[0];
        for (auto& n : nums) {
            pre = max(pre + n, n);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};
```

### Go

```go
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxSubArray(nums []int) int {
	pre, maxAns := 0, nums[0]
	for _, v := range nums {
		pre = max(pre+v, v)
		maxAns = max(maxAns, pre)
	}
	return maxAns
}
```

### Python

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        pre, maxAns = 0, nums[0]
        for i in nums:
            pre = max(pre + i, i)
            maxAns = max(pre, maxAns)
        return maxAns
```
