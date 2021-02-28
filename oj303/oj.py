class NumArray:
    def __init__(self, nums: List[int]):
        self.prefixSums = [0]
        for num in nums:
            self.prefixSums.append(num + self.prefixSums[-1])

    def sumRange(self, i: int, j: int) -> int:
        return self.prefixSums[j + 1] - self.prefixSums[i]
