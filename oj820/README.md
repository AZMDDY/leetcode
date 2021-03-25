# LeetCode —— 820.单词的压缩编码

## 题目

![](https://azmddy.github.io/img/20210325073733.png)

## 思路

反转+排序，判断是否是子字符串。

## 实现

### C++

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words)
    {
        for (auto& w : words) {
            reverse(w.begin(), w.end());
        }
        sort(words.begin(), words.end());
        int ans = 0;
        for (int i = 0; i < words.size() - 1; i++) {
            int size = words[i].size();
            if (words[i] == words[i + 1].substr(0, size)) {
                continue;
            }
            ans += size + 1;
        }
        return ans + words.back().size() + 1;
    }
};
```

### Go

```go
func minimumLengthEncoding(words []string) int {
	out := 0
	m := map[string]bool{}
	for _, w := range words {
		m[w] = true
	}
	for w, _ := range m {
		for i := 1; i < len(w); i++ {
			delete(m, w[i:])
		}
	}
	for w, _ := range m {
		out += len(w) + 1
	}
	return out
}
```

### Python

```python
def minimumLengthEncoding(self, words: List[str]) -> int:
    N = len(words)
    # 反转每个单词
    reversed_words = []
    for word in words:
        reversed_words.append(word[::-1])
    # 字典序排序
    reversed_words.sort()

    res = 0
    for i in range(N):
        if i+1 < N and reversed_words[i+1].startswith(reversed_words[i]):
            # 当前单词是下一个单词的前缀，丢弃
            pass
        else:
            res += len(reversed_words[i]) + 1  # 单词加上一个 '#' 的长度

    return res
```
