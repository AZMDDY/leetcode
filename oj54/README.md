# LeetCode —— 54. 螺旋矩阵

## 题目

![](https://azmddy.github.io/img/20210315074025.png)

## 思路

直接模拟，定义遍历的上下边界，不断循环即可。

## 实现

### C++

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> ans;
        if (matrix.empty()) {
            return ans;
        }
        int upLimit = 0;
        int downLimit = matrix.size() - 1;
        int leftLimit = 0;
        int rightLimit = matrix[0].size() - 1;
        while (true) {
            for (int i = leftLimit; i <= rightLimit; i++) {
                ans.push_back(matrix[upLimit][i]);
            }
            if (++upLimit > downLimit) {
                break;
            }
            for (int i = upLimit; i <= downLimit; i++) {
                ans.push_back(matrix[i][rightLimit];)
            }
            if (--rightLimit < leftLimit) {
                break;
            }
            for (int i = rightLimit; i >= leftLimit; i--) {
                ans.push_back(matrix[downLimit][i]);
            }
            if (--downLimit < upLimit) {
                break;
            }
            for (int i = downLimit; i >= upLimit; i--) {
                ans.push_back(matrix[i][leftLimit]);
            }
            if (++leftLimit > rightLimit) {
                break;
            }
        }
        return ans;
    }
};
```

### Go

```go
func spiralOrder(matrix [][]int) []int {
	ans := []int{}
	if len(matrix) == 0 {
		return ans
	}
	leftLimit := 0
	rightLimit := len(matrix[0]) - 1
	upLimit := 0
	downLimit := len(matrix) - 1
	for {
		for i := leftLimit; i <= rightLimit; i++ {
			ans = append(ans, matrix[upLimit][i])
		}
		upLimit += 1
		if upLimit > downLimit {
			break
		}
		for i := upLimit; i <= downLimit; i++ {
			ans = append(ans, matrix[i][rightLimit])
		}
		rightLimit -= 1
		if rightLimit < leftLimit {
			break
		}
		for i := rightLimit; i >= leftLimit; i-- {
			ans = append(ans, matrix[downLimit][i])
		}
		downLimit -= 1
		if downLimit < upLimit {
			break
		}
		for i := downLimit; i >= upLimit; i-- {
			ans = append(ans, matrix[i][leftLimit])
		}
		leftLimit += 1
		if leftLimit > rightLimit {
			break
		}
	}
	return ans
}
```

### Python

```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ans = []
        if len(matrix) == 0:
            return ans
        u = 0
        d = len(matrix)-1
        l = 0
        r = len(matrix[0])-1
        while True:
            for i in range(l, r+1):
                ans.append(matrix[u][i])
            u += 1
            if u > d:
                break

            for i in range(u, d+1):
                ans.append(matrix[i][r])
            r -= 1
            if r < l:
                break

            for i in range(r, l-1, -1):
                ans.append(matrix[d][i])
            d -= 1
            if d < u:
                break

            for i in range(d, u-1, -1):
                ans.append(matrix[i][l])
            l += 1
            if l > r:
                break
        return ans
```
