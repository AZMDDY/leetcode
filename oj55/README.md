# LeetCode —— 55. 跳跃游戏

## 题目

![](https://azmddy.github.io/img/20210331073531.png)

## 思路

使用贪心算法，记录每一个位置能达到的最远距离。

## 实现

### C++

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int maxIdx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i <= maxIdx) {
                maxIdx = max(i + nums[i], maxIdx);
                if (maxIdx >= nums.size() - 1) {
                    return true;
                }
            } else {
                return false;
            }
        }
        return false;
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

func canJump(nums []int) bool {
	maxRight := 0
	for i := 0; i < len(nums); i++ {
		if i <= maxRight {
			maxRight = max(i+nums[i], maxRight)
			if maxRight >= (len(nums) - 1) {
				return true
			}
		} else {
			return false
		}
	}
	return false
}
```

### Python

```python
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxRight = 0
        for i in range(len(nums)):
            if i <= maxRight:
                maxRight = max(maxRight, nums[i] + i)
                if maxRight >= (len(nums)-1):
                    return True
            else:
                return False
        return False
```
