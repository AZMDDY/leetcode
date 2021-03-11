# LeetCode —— 基本计算器 II

## 题目

![](https://azmddy.github.io/img/20210311080735.png)

## 思路

使用栈，先计算乘除，将其都转换成加法运算。

## 实现

### C++

```cpp
class Solution {
public:
    int calculate(string s)
    {
        vector<int> stk;
        int num = 0;
        char sign = '+';
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + static_cast<int>(s[i] - '0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == (s.size() - 1)) {
                switch (sign) {
                    case '+': {
                        stk.push_back(num);
                    } break;
                    case '-': {
                        stk.push_back(-num);
                    } break;
                    case '*': {
                        stk.back() *= num;
                    } break;
                    case '/': {
                        stk.back() /= num;
                        break;
                    }
                }
                sign = s[i];
                num = 0;
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};
```

### Go

```go
func calculate(s string) (ans int) {
	stack := []int{}
	preSign := '+'
	num := 0
	for i, ch := range s {
		isDigit := '0' <= ch && ch <= '9'
		if isDigit {
			num = num*10 + int(ch-'0')
		}
		if !isDigit && ch != ' ' || i == len(s)-1 {
			switch preSign {
			case '+':
				stack = append(stack, num)
			case '-':
				stack = append(stack, -num)
			case '*':
				stack[len(stack)-1] *= num
			default:
				stack[len(stack)-1] /= num
			}
			preSign = ch
			num = 0
		}
	}
	for _, v := range stack {
		ans += v
	}
	return
}
```

### Python

```python
class Solution:
    def calculate(self, s: str) -> int:
        stk = []
        num = 0
        sign = '+'
        for i in range(len(s)):
            if (s[i] >= '0' and s[i] <= '9'):
                num = num * 10 + (int(s[i])-int('0'))

            if ((s[i] < '0' or s[i] > '9') and s[i] != ' ' or i == (len(s)-1)):
                if (sign == '+'):
                    stk.append(num)
                elif (sign == '-'):
                    stk.append(-num)
                elif (sign == '*'):
                    stk[len(stk)-1] *= num
                elif (sign == '/'):
                    stk[len(stk)-1] = int(stk[len(stk)-1] / num)
                sign = s[i]
                num = 0
        ans = 0
        for i in range(len(stk)):
            ans += stk[i]
        return ans
```
