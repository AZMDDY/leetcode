# LeetCode —— 1047. 删除字符串中的所有相邻重复项

## 题目

![](https://azmddy.github.io/img/20210309080642.png)

## 思路

通过栈来剔除相同相邻元素。先入栈，然后对比栈顶元素和下一个将要入栈的元素，如果相同就弹出栈顶元素，不同则入栈。·

## 实现

### C++

```cpp
class Solution {
public:
    string removeDuplicates(string S)
    {
        string ans;
        for (char chr : S) {
            if (!ans.empty() && ans.back() == chr) {
                ans.pop_back();
            } else {
                ans.push_back(chr);
            }
        }   
        return ans;
    }
};
```

### Go

```go
func removeDuplicates(S string) string {
	stk := []byte{}
	for i := range S {
		if len(stk) > 0 && stk[len(stk)-1] == S[i] {
			stk = stk[:len(stk)-1]
		} else {
			stk = append(stk, S[i])
		}
	}
	return string(stk)
}
```

### Python

```python
class Solution:
    def removeDuplicates(self, S: str) -> str:
        stk = list()
        for chr in S:
            if len(stk) > 0 and stk[-1] == chr:
                stk.pop()
            else:
                stk.append(chr)
        return "".join(stk)
```
