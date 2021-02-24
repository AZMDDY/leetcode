class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        for row in A:
            for j in range((len(row) + 1) // 2):
                if row[j] == row[-1 - j]:
                    row[j] = row[-1 - j] = 1 - row[j]
        return A