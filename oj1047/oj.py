class Solution:
    def removeDuplicates(self, S: str) -> str:
        stk = list()
        for chr in S:
            if len(stk) > 0 and stk[-1] == chr:
                stk.pop()
            else:
                stk.append(chr)
        return "".join(stk)
