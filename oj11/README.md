# LeetCode —— 11. 盛最多水的容器

## 题目

![](https://azmddy.github.io/img/20210410201942.png)

## 思路

双指针

## 实现

### C++

```cpp
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int right = 0;
        int left = height.size() - 1;
        int area = 0;
        int maxArea = 0;
        while (right < left) {
            area = (left - right) * min(height[right], height[left]);
            if (area > maxArea) {
                maxArea = area;
            }
            if (height[right] < height[left]) {
                right++;
            } else if (height[right] > height[left]) {
                left--;
            } else {
                right++;
                left--;
            }
        }
        return maxArea;
    }
};
```

### Go

```go
func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxArea(height []int) int {
	right, left := 0, len(height)-1
	ans := 0
	for right < left {
		area := (left - right) * min(height[right], height[left])
		ans = max(ans, area)
		if height[right] < height[left] {
			right++
		} else if height[right] > height[left] {
			left--
		} else {
			right++
			left--
		}
	}
	return ans
}

```

### Python

```python
class Solution:
    def maxArea(self, height: List[int]) -> int:
        right, left = 0, len(height) - 1
        ans = 0
        while right < left:
            area = (left - right) * min(height[left], height[right])
            ans = max(area, ans)
            if height[right] < height[left]:
                right += 1
            elif height[right] > height[left]:
                left -= 1
            else:
                right += 1
                left -= 1
        return ans
```
