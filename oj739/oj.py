class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        n = len(T)
        ans = [0] * n
        stk = []
        for i in range(n):
            while len(stk) > 0 and T[i] > T[stk[-1]]:
                preIndex = stk.pop()
                ans[preIndex] = i - preIndex
            stk.append(i)
        return ans
