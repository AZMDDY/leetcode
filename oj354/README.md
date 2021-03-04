# LeetCode ——

## 题目

![20210304075201](https://raw.githubusercontent.com/AZMDDY/imgs/master/img/20210304075201.png)

## 思路

对宽度进行排序，然后对高度进行`最长递增子序列`计算。

## 实现

### C++

```cpp
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        if (envelopes.empty()) {
            return 0;
        }

        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(),
             [](const auto& e1, const auto& e2) { return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]); });

        vector<int> f(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[j][1] < envelopes[i][1]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        return *max_element(f.begin(), f.end());
    }
};

```

### Go

```go

func maxEnvelopes(envelopes [][]int) int {
	n := len(envelopes)
	if n == 0 {
		return 0
	}

	sort.Slice(envelopes, func(i, j int) bool {
		a, b := envelopes[i], envelopes[j]
		return a[0] < b[0] || a[0] == b[0] && a[1] > b[1]
	})

	f := make([]int, n)
	for i := range f {
		f[i] = 1
	}
	for i := 1; i < n; i++ {
		for j := 0; j < i; j++ {
			if envelopes[j][1] < envelopes[i][1] {
				f[i] = max(f[i], f[j]+1)
			}
		}
	}
	return max(f...)
}

func max(a ...int) int {
	res := a[0]
	for _, v := range a[1:] {
		if v > res {
			res = v
		}
	}
	return res
}
```

### Python

```python
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        if not envelopes:
            return 0

        n = len(envelopes)
        envelopes.sort(key=lambda x: (x[0], -x[1]))

        f = [1] * n
        for i in range(n):
            for j in range(i):
                if envelopes[j][1] < envelopes[i][1]:
                    f[i] = max(f[i], f[j] + 1)

        return max(f)
```
