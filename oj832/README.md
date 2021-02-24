# LeetCode —— 832. 翻转图像

## 题目

![20210224080119](https://raw.githubusercontent.com/AZMDDY/imgs/master/img/20210224080119.png)

## 思路

直接模拟，先进行翻转，然后使用双指针进行替换。但可以注意到一点，当每行对称的两个元素不一样的时候，进行翻转和反转操作后，值没有发生变化，所以我们只需要对每行对称的两个相同的元素进行异或操作就可以了。

## 实现

### C++

```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A)
    {
        for (auto& row : A) {
            for (int i = 0; i < (row.size() + 1) / 2; i++) {
                if (row[i] == row[row.size() - i - 1]) {
                    row[i] = row[row.size() - i - 1] = 1 - row[i];
                }
            }
        }
        return A;
    }
};
```

### Go

```go
func flipAndInvertImage(A [][]int) [][]int {
	for _, v := range A {
		for i := 0; i < int((len(v)+1)/2); i++ {
			if v[i] == v[len(v)-i-1] {
				v[i], v[len(v)-i-1] = 1-v[i], 1-v[len(v)-i-1]
			}
		}
	}
	return A
}
```

### Python

```python
class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        for row in A:
            for j in range((len(row) + 1) // 2):
                if row[j] == row[-1 - j]:
                    row[j] = row[-1 - j] = 1 - row[j]
        return A
```
