# LeetCode —— 1052爱生气的书店老板

## 题目

![20210223075025](https://raw.githubusercontent.com/AZMDDY/imgs/master/img/20210223075025.png)

## 思路

首先提炼一下题目，题目的要求其实就是在一个数组中求某一段和最大（虽然题目给了两个数组，但我们可以将其视为一个数组，即`a[i] = customers[i] * grumpy[i]`）。对于这种题目，使用`滑动窗口`来解决。

## 实现

### C++

```cpp
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X)
    {
        int len = customers.size();
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (grumpy[i] == 0) {
                sum += customers[i];
            }
        }
        int cut = 0;
        for (int i = 0; i < X; i++) {
            cut += customers[i] * grumpy[i];
        }
        int maxCut = cut;
        for (int i = X; i < len; i++) {
            cut = cut - customers[i - X] * grumpy[i - X] + customers[i] * grumpy[i];
            maxCut = std::max(maxCut, cut);
        }
        return sum + maxCut;
    }
};
```

### Go

```go
// MaxInt Return max(a, b)
func MaxInt(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxSatisfied(customers []int, grumpy []int, X int) int {
	sum := 0
	cnt := 0
	maxCnt := 0
	for i := 0; i < len(customers); i++ {
		if grumpy[i] == 1 {
			cnt += customers[i]
		} else {
			sum += customers[i]
		}
		if i >= X && grumpy[i-X] == 1 {
			cnt -= customers[i-X]
		}
		maxCnt = MaxInt(cnt, maxCnt)
	}
	return sum + maxCnt
}
```

### Python

```python
class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        ans = 0
        cnt = 0
        max_cnt = 0
        for i in range(len(customers)):
            if grumpy[i] == 1:
                cnt = customers[i] + cnt
            else:
                ans = customers[i] + ans

            if i >= X and grumpy[i - X] == 1:
                cnt = cnt - customers[i - X]

            max_cnt = max(max_cnt, cnt)

        return max_cnt + ans
```
