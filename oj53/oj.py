class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        pre, maxAns = 0, nums[0]
        for i in nums:
            pre = max(pre + i, i)
            maxAns = max(pre, maxAns)
        return maxAns
