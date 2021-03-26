# LeetCode —— 45. 跳跃游戏 II

## 题目

![](https://azmddy.github.io/img/20210326073545.png)

## 思路

第一种方法是采用贪心，从终点向前找最远能到达终点的那个点。
第二种方法是正向查找，对于每一个点A都有一个最远能达到的点B，那从A到B中间有比B更远的点C，那么我们就应该从A到C。

## 实现

### C++

```cpp
class Solution {
public:
    int jump(vector<int>& nums)
    {
        int len = nums.size();
        int end = 0;
        int maxPos = 0;
        int steps = 0;
        for (int i = 0; i < len - 1; i++) {
            maxPos = max(maxPos, i + nums[i]);
            if (i == end) {
                end = maxPos;
                steps++;
            }
        }
        return steps;
    }
};
```

### Go

```go
func jump(nums []int) int {
	pos := len(nums) - 1
	steps := 0
	for pos > 0 {
		for i := 0; i < pos; i++ {
			if nums[i]+i >= pos {
				pos = i
				steps++
				break
			}
		}
	}
	return steps
}
```

### Python

```python
class Solution:
    def jump(self, nums: List[int]) -> int:
        m = len(nums)
        maxPos = 0
        steps = 0
        end = 0
        for i in range(m - 1):
            maxPos = max(maxPos, i + nums[i])
            if i == end:
                end = maxPos
                steps +=1
        return steps
```
