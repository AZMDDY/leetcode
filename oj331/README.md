# LeetCode —— 331. 验证二叉树的前序序列化

## 题目

![](https://azmddy.github.io/img/20210312082038.png)

## 思路

利用满二叉树叶子节点数比非叶子节点数多1的性质。

## 实现

### C++

```cpp
class Solution {
public:
    bool isValidSerialization(string preorder)
    {
        int n = preorder.size();
        int ans = 1;
        if (n == 0 || preorder[0] == '#') {
            return n <= 1;
        }
        for (int i = 1; i < n - 1; i++) {
            if (preorder[i] == ',') {
                if (preorder[i + 1] != '#') {
                    ans++;
                } else {
                    ans--;
                }
            }
            // 先遍历的非叶子节点总比叶子节点多
            if (ans < 0 && i != (n - 2)) {
                return false;
            }
        }
        return ans == -1;
    }
};
```

### Go

```go
func isValidSerialization(preorder string) bool {
	count := 1
	for _, v := range strings.Split(preorder, ",") {
		if count == 0 {
			return false
		}
		if string(v) == "#" {
			count--
		} else {
			count++
		}
	}
	return count == 0
}
```

### Python

```python
class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        degree = 1
        for node in preorder.split(','):
            if degree == 0:
                return False
            if node == '#':
                degree -= 1
            else:
                degree += 1
        return degree == 0
```
