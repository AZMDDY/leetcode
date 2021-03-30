# LeetCode —— 554. 砖墙

## 题目

![](https://azmddy.github.io/img/20210330073825.png)

## 思路

记录每一行的中不同位置边界出现的次数。

## 实现

### C++

```cpp
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall)
    {
        unordered_map<int, int> m;
        for (auto& row : wall) {
            int sum = 0;
            for (int i = 0; i < row.size() - 1; i++) {
                sum += row[i];
                m[sum]++;
            }
        }
        int maxCount = 0;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            maxCount = max(maxCount, iter->second);
        }
        return wall.size() - maxCount;
    }
};
```

### Go

```go
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func leastBricks(wall [][]int) int {
	var m map[int]int
	m = make(map[int]int)
	for _, v := range wall {
		sum := 0
		for i := 0; i < len(v)-1; i++ {
			sum += v[i]
			m[sum]++
		}
	}
	maxCount := 0
	for k := range m {
		maxCount = max(m[k], maxCount)
	}
	return len(wall) - maxCount
}
```

### Python

```python
class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        m = {}
        for w in wall:
            count = 0
            for i in range(len(w)-1):
                count += w[i]
                if m.__contains__(count):
                    m[count] += 1
                else:
                    m[count] = 1
        max_count = 0
        for k in m:
            max_count = max(max_count, m[k])
        return len(wall) - max_count
```
