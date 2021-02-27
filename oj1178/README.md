# LeetCode —— 1178. 猜字谜

## 题目

![20210226203452](https://raw.githubusercontent.com/AZMDDY/imgs/master/img/20210226203452.png)

## 思路

朴素的想法是统计`word`和`puzzle`有多少个不同的元素，然后确定`words`中有多少是`puzzle`的子集，还需要保证`puzzle`的首字母在`word`中存在。

对于统计字母，可以用二进制状态压缩。然后就是枚举二进制的子集。

## 实现

### C++

```cpp
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles)
    {
        unordered_map<int, int> frequency;

        for (const string& word : words) {
            int mask = 0;
            for (char ch : word) {
                mask |= (1 << (ch - 'a'));
            }
            if (__builtin_popcount(mask) <= 7) {
                ++frequency[mask];
            }
        }

        vector<int> ans;
        for (const string& puzzle : puzzles) {
            int total = 0;

            for (int choose = 0; choose < (1 << 6); ++choose) {
                // 子集
                int mask = 0;
                for (int i = 0; i < 6; ++i) {
                    if (choose & (1 << i)) {
                        mask |= (1 << (puzzle[i + 1] - 'a'));
                    }
                }
                mask |= (1 << (puzzle[0] - 'a'));
                if (frequency.count(mask)) {
                    total += frequency[mask];
                }
            }
            ans.push_back(total);
        }
        return ans;
    }
};
```

### Go

```go
func findNumOfValidWords(words []string, puzzles []string) []int {
	wordsMap := map[int]int{}
	for _, w := range words {
		m := 0
		for _, c := range w {
			m |= 1 << (c - 'a')
		}
		if bits.OnesCount(uint(m)) <= 7 {
			wordsMap[m]++
		}
	}

	ans := make([]int, len(puzzles))
	for idx, puzzle := range puzzles {
		first := 1 << (puzzle[0] - 'a')
		for i := 0; i < (1 << 6); i++ {
			m := 0
			for j := 0; j < 6; j++ {
				if i>>j&1 == 1 {
					m |= 1 << (puzzle[j+1] - 'a')
				}
			}
			ans[idx] += wordsMap[m|first]
		}
	}

	return ans
}
```

### Python

```python
class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        frequency = collections.Counter()

        for word in words:
            mask = 0
            for ch in word:
                mask |= 1 << (ord(ch) - ord("a"))
            if str(bin(mask)).count("1") <= 7:
                frequency[mask] += 1

        ans = list()
        for puzzle in puzzles:
            total = 0
            for choose in range(1 << 6):
                mask = 0
                for i in range(6):
                    if choose & (1 << i):
                        mask |= 1 << (ord(puzzle[i + 1]) - ord("a"))
                mask |= 1 << (ord(puzzle[0]) - ord("a"))
                if mask in frequency:
                    total += frequency[mask]

            ans.append(total)

        return ans
```
