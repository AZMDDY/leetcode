class Solution:
    def calculate(self, s: str) -> int:
        stk = []
        num = 0
        sign = '+'
        for i in range(len(s)):
            if (s[i] >= '0' and s[i] <= '9'):
                num = num * 10 + (int(s[i])-int('0'))

            if ((s[i] < '0' or s[i] > '9') and s[i] != ' ' or i == (len(s)-1)):
                if (sign == '+'):
                    stk.append(num)
                elif (sign == '-'):
                    stk.append(-num)
                elif (sign == '*'):
                    stk[len(stk)-1] *= num
                elif (sign == '/'):
                    stk[len(stk)-1] = int(stk[len(stk)-1] / num)
                sign = s[i]
                num = 0
        ans = 0
        for i in range(len(stk)):
            ans += stk[i]
        return ans
