# LeetCode —— 503. 下一个更大元素 II

## 题目

![20210306083239](https://raw.githubusercontent.com/AZMDDY/imgs/master/img/20210306083239.png)

## 思路

使用单调栈，保存单调不升的元素。

## 实现

### C++

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> stk;
        for (int i = 0; i < (2 * n - 1); i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
                ans[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }
        return ans;
    }
};
```

### Go

```go
func nextGreaterElements(nums []int) []int {
	n := len(nums)
	ans := make([]int, n)
	for i := range ans {
		ans[i] = -1
	}
	stk := []int{}
	for i := 0; i < n*2-1; i++ {
		for len(stk) > 0 && nums[stk[len(stk)-1]] < nums[i%n] {
			ans[stk[len(stk)-1]] = nums[i%n]
			stk = stk[:len(stk)-1]
		}
		stk = append(stk, i%n)
	}
	return ans
}
```

### Python

```python
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ret = [-1] * n
        stk = list()

        for i in range(n * 2 - 1):
            while stk and nums[stk[-1]] < nums[i % n]:
                ret[stk.pop()] = nums[i % n]
            stk.append(i % n)

        return ret
```
