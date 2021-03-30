class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxRight = 0
        for i in range(len(nums)):
            if i <= maxRight:
                maxRight = max(maxRight, nums[i] + i)
                if maxRight >= (len(nums)-1):
                    return True
            else:
                return False
        return False
