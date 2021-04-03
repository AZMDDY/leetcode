# LeetCode —— 1109. 航班预订统计

## 题目

![](https://azmddy.github.io/img/20210403200153.png)

## 思路

首先可以通过暴力法。然后还可以通过等差数组。

## 实现

### C++

```cpp
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n)
    {
        vector<int> ans(n, 0);
        for (auto& book : bookings) {
            ans[book[0] - 1] += book[2];
            if (book[1] < n) {
                ans[book[1]] -= book[2];
            }
        }
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + ans[i];
        }
        return ans;
    }
};
```

### Go

```go
func corpFlightBookings(bookings [][]int, n int) []int {
	ans := make([]int, n)
	for _, book := range bookings {
		ans[book[0]-1] += book[2]
		if book[1] < n {
			ans[book[1]] -= book[2]
		}
	}
	for i := 1; i < n; i++ {
		ans[i] = ans[i-1] + ans[i]
	}
	return ans
}
```

### Python

```python
class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        ans = [0] * n
        for book in bookings:
            ans[book[0]-1] += book[2]
            if book[1] < n:
                ans[book[1]] -= book[2]
        for i in range(1, n):
            ans[i] = ans[i-1] + ans[i]
        return ans
```
