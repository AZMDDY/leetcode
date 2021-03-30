class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        m = {}
        for w in wall:
            count = 0
            for i in range(len(w)-1):
                count += w[i]
                if m.__contains__(count):
                    m[count] += 1
                else:
                    m[count] = 1
        max_count = 0
        for k in m:
            max_count = max(max_count, m[k])
        return len(wall) - max_count
