class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def climbStairs(self, n: int) -> int:
        p1, p2, p3 = 0, 0, 1
        for _ in range(1, n+1):
            p1 = p2
            p2 = p3
            p3 = p1 + p2
        return p3
