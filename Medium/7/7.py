# import math

# INT_MIN = -math.pow(2, 31)
# INT_MAX = -(INT_MIN + 1)
INT_MIN = -2147483648
INT_MAX = 2147483647


# Implement C++ modulus operator
def cpp_mod(a: int, b: int) -> int:
    return a - b * int(a / b)


class Solution:
    def reverse(self, x: int) -> int:
        ans = 0
        while x != 0:
            digit = cpp_mod(x, 10)
            if ans > INT_MAX / 10 or (ans == int(INT_MAX / 10) and digit > 7):
                return 0
            if ans < INT_MIN / 10 or (ans == int(INT_MIN / 10) and digit < -8):
                return 0
            ans = ans * 10 + digit
            x = int(x / 10)
        return ans


print("It's Showtime Folks!")
print(f"Solution: {Solution().reverse(123)}")
print(f"Solution: {Solution().reverse(-12)}")
print(f"Solution: {Solution().reverse(1534236469)}")
