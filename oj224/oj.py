class Solution:
    def calculate(self, s: str) -> int:
        sign = [1]
        ans = 0
        num = 0
        op = 1
        for c in s:
            if c >= '0' and c <= '9':
                num = num * 10 + (int(c) - int('0'))
                continue
            ans += op * num
            num = 0
            if c == '+':
                op = sign[len(sign)-1]
            elif c == '-':
                op = -sign[len(sign)-1]
            elif c == '(':
                sign.append(op)
            elif c == ')':
                sign.pop()
        return ans + op * num
