# LeetCode —— 224. 基本计算器

## 题目

![image-20210310075540032](https://azmddy.github.io/img/image-20210310075540032.png)

## 思路

使用栈来保存当前运算的正负号，遇到括号就根据括号左边的符号来转换括号内的符号，从而脱去括号。

## 实现

### C++

```cpp
class Solution {
public:
    int calculate(string s)
    {
        stack<int> sign;
        sign.push(1);
        int ans = 0;
        int num = 0;
        int op = 1;
        for (auto& chr : s) {
            if (chr >= '0' && chr <= '9') {
                num = num * 10 + (chr - '0');
                continue;
            }
            ans += op * num;
            num = 0;
            if (chr == '+') {
                op = sign.top();
            } else if (chr == '-') {
                op = -sign.top();
            } else if (chr == '(') {
                sign.push(op);
            } else if (chr == ')') {
                sign.pop();
            }
        }
        return ans + op * num;
    }
};
```

### Go

```go
func calculate(s string) int {
	sign := []int{}
	sign = append(sign, 1)
	ans := 0
	num := 0
	op := 1
	for _, v := range s {
		if v >= '0' && v <= '9' {
			num = num*10 + int(v-'0')
			continue
		}
		ans += num * op
		num = 0
		if v == '+' {
			op = sign[len(sign)-1]
		} else if v == '-' {
			op = -sign[len(sign)-1]
		} else if v == '(' {
			sign = append(sign, op)
		} else if v == ')' {
			sign = sign[:len(sign)-1]
		}
	}
	return ans + op*num
}
```

### Python

```python
class Solution:
    def calculate(self, s: str) -> int:
        sign = [1]
        ans = 0
        num = 0
        op = 1
        for c in s:
            if c >= '0' and c <= '9':
                num = num * 10 + (int(c) - int('0'))
                continue
            ans += op * num
            num = 0
            if c == '+':
                op = sign[len(sign)-1]
            elif c == '-':
                op = -sign[len(sign)-1]
            elif c == '(':
                sign.append(op)
            elif c == ')':
                sign.pop()
        return ans + op * num
```
