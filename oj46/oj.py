class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []
        def dfs(first = 0):
            if (first == n):
                ans.append(nums[:])
            for i in range(first, n):
                nums[first], nums[i] = nums[i], nums[first]
                dfs(first+1)
                nums[first], nums[i] = nums[i], nums[first]
        dfs()
        return ans