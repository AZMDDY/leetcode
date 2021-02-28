# LeetCode —— 303. 区域和检索 - 数组不可变

## 题目

![20210301062837](https://raw.githubusercontent.com/AZMDDY/imgs/master/img/20210301062837.png)

## 思路

使用前缀和的方法快速解决。计算出数组的所有前缀和。

## 实现

### C++

```cpp
class NumArray {
public:
    NumArray(vector<int>& nums)
    {
        prefixSums.assign(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }
    }

    int sumRange(int i, int j) { return prefixSums[j + 1] - prefixSums[i]; }

private:
    vector<int> prefixSums;
};

```

### Go

```
type NumArray struct {
	prefixSums []int
}

func Constructor(nums []int) NumArray {
	prefixSums := make([]int, len(nums)+1)
	for i, v := range nums {
		prefixSums[i+1] = prefixSums[i] + v
	}
	return NumArray{prefixSums}
}

func (this *NumArray) SumRange(i int, j int) int {
	return this.prefixSums[j+1] - this.prefixSums[i]
}

```

### Python

```python
class NumArray:
    def __init__(self, nums: List[int]):
        self.prefixSums = [0]
        for num in nums:
            self.prefixSums.append(num + self.prefixSums[-1])

    def sumRange(self, i: int, j: int) -> int:
        return self.prefixSums[j + 1] - self.prefixSums[i]

```
