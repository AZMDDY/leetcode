# LeetCode —— 739. 每日温度

## 题目

![](https://azmddy.github.io/img/20210329073817.png)

## 思路

使用单调栈，从栈底到栈顶按温度从高到低插入。

## 实现

### C++

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T)
    {
        int n = T.size();
        vector<int> ans(n, 0);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && T[i] > T[stk.top()]) {
                int preIndex = stk.top();
                ans[preIndex] = i - preIndex;
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};
```

### Go

```go
func dailyTemperatures(T []int) []int {
	n := len(T)
	ans := make([]int, n)
	stk := []int{}
	for i := 0; i < n; i++ {
		for len(stk) > 0 && T[i] > T[stk[len(stk)-1]] {
			preIndex := stk[len(stk)-1]
			ans[preIndex] = i - preIndex
			stk = stk[:len(stk)-1]
		}
		stk = append(stk, i)
	}
	return ans
}
```

### Python

```python
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        n = len(T)
        ans = [0] * n
        stk = []
        for i in range(n):
            while len(stk) > 0 and T[i] > T[stk[-1]]:
                preIndex = stk.pop()
                ans[preIndex] = i - preIndex
            stk.append(i)
        return ans
```
