import collections


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
