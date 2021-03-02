# LeetCode —— 338. 比特位计数

## 题目

![20210303073752](https://raw.githubusercontent.com/AZMDDY/imgs/master/img/20210303073752.png)

## 思路

最直接的想法是计算每一个数的二进制位1的个数，利用`x=x&(x-1)`来对`x`进行反复操作，直到为0,操作的次数即为该数的二进制位为1的个数。

动态规划的方法是利用奇偶数的性质。对于偶数，其二进制数最低位是0,其二进制1的个数和其右移一位得到的奇数的二进制1的个数相同;同理，对于奇数，其二进制数最低位是1,其二进制1的个数等于其右移一位得到的偶数的二进制1的个数加一。即：
$$bits[x] = bits[x>>1]; x为偶数$$
$$bits[x] = bits[x>>1]+1; x为奇数$$

## 实现

### C++

```cpp
class Solution {
public:
    vector<int> countBits(int num)
    {
        vector<int> bits(num + 1, 0);
        for (int i = 1; i <= num; i++) {
            bits[i] = bits[i >> 1] + (i & 1);
        }
        return bits;
    }
};
```

### Go

```go
func countBits(num int) []int {
	bits := make([]int, num+1)
	for i := 1; i <= num; i++ {
		bits[i] = bits[i>>1] + (i & 1)
	}
	return bits
}
```

### Python

```python
class Solution:
    def countBits(self, num: int) -> List[int]:
        bits = [0] * (num + 1)
        for i in range(1, num + 1):
            bits[i] = bits[i >> 1] + (i & 1)
        return bits

```
