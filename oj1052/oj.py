class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        ans = 0
        cnt = 0
        max_cnt = 0
        for i in range(len(customers)):
            if grumpy[i] == 1:
                cnt = customers[i] + cnt
            else:
                ans = customers[i] + ans

            if i >= X and grumpy[i - X] == 1:
                cnt = cnt - customers[i - X]
                
            max_cnt = max(max_cnt, cnt)

        return max_cnt + ans