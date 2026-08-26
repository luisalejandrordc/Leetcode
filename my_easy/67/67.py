# 67. Add Binary
# Given two binary strings a and b, return their sum as a binary string.


class Solution:
    def addBinary(self, a: str, b: str) -> str:
        ans = ""
        ia = len(a) - 1
        ib = len(b) - 1
        carry = 0
        while ia >= 0 or ib >= 0 or carry != 0:
            va = int(a[ia]) if ia >= 0 else 0
            vb = int(b[ib]) if ib >= 0 else 0
            total = va + vb + carry
            ans += str(total % 2)
            carry = total // 2
            ia -= 1
            ib -= 1
        return ans[::-1]


print(f"Solution: {Solution().addBinary("11", "1")}")
