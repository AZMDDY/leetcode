# LeetCode —— 896. 单调数列

## 题目

![20210228204446](https://raw.githubusercontent.com/AZMDDY/imgs/master/img/20210228204446.png)

## 思路

一次遍历， 设置两个单调标志，当遇到不单调递增或不单调递减的情况，置单调标志为false。最终返回两个单调标志是否为true;

## 实现

### C++

```cpp
class Solution {
public:
    bool isMonotonic(vector<int>& A)
    {
        int pFlag = 0;
        int nFlag = 0;
        for (int i = 0; i < (A.size() - 1); i++) {
            if (A[i + 1] - A[i] >= 0) {
                pFlag++;
            }
            if (A[i + 1] - A[i] >= 0) {
                nFlag--;
            }
        }
        return abs(nFlag) == (A.size() - 1) || pFlag == (A.size() - 1);
    }
};
```

### Go

```go
func isMonotonic(A []int) bool {
	inc := true
	dec := true
	for i := 0; i < len(A)-1; i++ {
		if A[i+1] > A[i] {
			dec = false
		}
		if A[i+1] < A[i] {
			inc = false
		}
	}
	return inc || dec
}

```

### Python

```python
class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        inc = True
        dec = True
        for i in range(len(A) - 1):
            if A[i + 1] > A[i]:
                dec = False
            if A[i + 1] < A[i]:
                inc = False
        return inc or dec
```
