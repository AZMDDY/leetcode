class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ans = []
        if len(matrix) == 0:
            return ans
        u = 0
        d = len(matrix)-1
        l = 0
        r = len(matrix[0])-1
        while True:
            for i in range(l, r+1):
                ans.append(matrix[u][i])
            u += 1
            if u > d:
                break

            for i in range(u, d+1):
                ans.append(matrix[i][r])
            r -= 1
            if r < l:
                break

            for i in range(r, l-1, -1):
                ans.append(matrix[d][i])
            d -= 1
            if d < u:
                break

            for i in range(d, u-1, -1):
                ans.append(matrix[i][l])
            l += 1
            if l > r:
                break
        return ans
