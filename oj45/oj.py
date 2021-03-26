class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def jump(self, nums: List[int]) -> int:
        m = len(nums)
        maxPos = 0
        steps = 0
        end = 0
        for i in range(m - 1):
            maxPos = max(maxPos, i + nums[i])
            if i == end:
                end = maxPos
                steps +=1
        return steps