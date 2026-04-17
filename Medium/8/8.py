# 32-bit signed integer limits
INT_MIN = -2147483648
INT_MAX = 2147483647
DIGITS = {str(x) for x in range(10)}


class Solution:
    def myAtoi(self, s: str) -> int:
        num = 0
        negative = False
        started = False
        for c in s:
            if c == " " and not started:
                continue
            if c in DIGITS:
                started = True
                digit = int(c) if not negative else -int(c)
                if num > INT_MAX / 10 or (num == int(INT_MAX / 10) and digit > 7):
                    return INT_MAX
                if num < INT_MIN / 10 or (num == int(INT_MIN / 10) and digit < -8):
                    return INT_MIN
                num = num * 10 + digit
            elif c == "+" and not started:
                negative = False
                started = True
            elif c == "-" and not started:
                negative = True
                started = True
            else:
                break
        return num


print(f"Solution: {Solution().myAtoi("123")}")
print(f"Solution: {Solution().myAtoi("-042")}")
print(f"Solution: {Solution().myAtoi("1337c0d3")}")
print(f"Solution: {Solution().myAtoi("2147483648")}")
