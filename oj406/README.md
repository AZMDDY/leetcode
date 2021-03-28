# LeetCode —— 406. 根据身高重建队列

## 题目

![](https://azmddy.github.io/img/20210328120449.png)

## 思路

题目的意思是就是排序，按照指定的规则排序。对于高个子不会统计前面的矮个子。

## 实现

### C++

```cpp
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        sort(people.begin(), people.end(), [](const vector<int>& p1, const vector<int>& p2) {
            // 先按照身高从高到低排序，如果身高一样，则根据第二个元素正向排序
            return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
        });
        vector<vector<int>> ans;
        for (auto& p : people) {
            ans.insert(ans.begin() + p[1], p);
        }
        return ans;
    }
};
```

### Go

```go
func reconstructQueue(people [][]int) (ans [][]int) {
	sort.Slice(people, func(i, j int) bool {
		a, b := people[i], people[j]
		return a[0] > b[0] || a[0] == b[0] && a[1] < b[1]
	})
	for _, p := range people {
		idx := p[1]
		ans = append(ans[:idx], append([][]int{p}, ans[idx:]...)...)
	}
	return
}
```

### Python

```python

```
