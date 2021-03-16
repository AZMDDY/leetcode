# LeetCode —— 59. 螺旋矩阵 II

## 题目

![](https://azmddy.github.io/img/20210316073553.png)

## 思路

直接模拟。

## 实现

### C++

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int left = 0;
        int right = n - 1;
        int up = 0;
        int down = n - 1;
        int num = 1;
        int target = n * n;
        while (num <= target) {
            for (int i = left; i <= right; i++) {
                matrix[up][i] = num++;
            }
            up++;
            for (int i = up; i <= down; i++) {
                matrix[i][right] = num++;
            }
            right--;
            for (int i = right; i >= left; i--) {
                matrix[down][i] = num++;
            }
            down--;
            for (int i = down; i >= up; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
        return matrix;
    }
};
```

### Go

```go
func generateMatrix(n int) [][]int {
	matrix := make([][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = make([]int, n)
	}
	left := 0
	right := n - 1
	up := 0
	down := n - 1
	target := n * n
	num := 1
	for num <= target {
		for i := left; i <= right; i++ {
			matrix[up][i] = num
			num++
		}
		up++
		for i := up; i <= down; i++ {
			matrix[i][right] = num
			num++
		}
		right--
		for i := right; i >= left; i-- {
			matrix[down][i] = num
			num++
		}
		down--
		for i := down; i >= up; i-- {
			matrix[i][left] = num
			num++
		}
		left++
	}
	return matrix
}
```

### Python

```python
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        left, right, up, down = 0, n-1, 0, n-1
        matrix = [[0 for _ in range(n)] for _ in range(n)]
        num, target = 1, n * n
        while num <= target:
            for i in range(left, right+1):
                matrix[up][i] = num
                num += 1
            up += 1
            for i in range(up, down+1):
                matrix[i][right] = num
                num += 1
            right -= 1
            for i in range(right, left-1, -1):
                matrix[down][i] = num
                num += 1
            down -= 1
            for i in range(down, up-1, -1):
                matrix[i][left] = num
                num += 1
            left += 1
        return matrix
```
