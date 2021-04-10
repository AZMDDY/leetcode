class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def maxArea(self, height: List[int]) -> int:
        right, left = 0, len(height) - 1
        ans = 0
        while right < left:
            area = (left - right) * min(height[left], height[right])
            ans = max(area, ans)
            if height[right] < height[left]:
                right += 1
            elif height[right] > height[left]:
                left -= 1
            else:
                right += 1
                left -= 1
        return ans
