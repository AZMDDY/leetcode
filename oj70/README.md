# LeetCode —— 70. 爬楼梯

## 题目

![](https://azmddy.github.io/img/20210401074303.png)

## 思路

动态规划，f(n) = f(n-1) + f(n-2)

## 实现

### C++

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int p1 = 0;
        int p2 = 0;
        int p3 = 1;
        for(int i = 1; i <= n; i++) {
            p1 = p2;
            p2 = p3;
            p3 = p1 + p2;
        }
        return p3;
    }
};
```

### Go

```go
func climbStairs(n int) int {
	p1, p2 := 0, 0
	p3 := 1
	for i := 1; i <= n; i++ {
		p1 = p2
		p2 = p3
		p3 = p1 + p2
	}
	return p3
}
```

### Python

```python
class Solution:
    def climbStairs(self, n: int) -> int:
        p1, p2, p3 = 0, 0, 1
        for _ in range(1, n+1):
            p1 = p2
            p2 = p3
            p3 = p1 + p2
        return p3
```
