class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        num = x
        rev = 0
        while x != 0:
            rev = rev * 10 + x % 10
            x = int(x / 10)
        return num == rev


print(f"Solution: {Solution().isPalindrome(121)}")
print(f"Solution: {Solution().isPalindrome(-121)}")
print(f"Solution: {Solution().isPalindrome(10)}")
print(f"Solution: {Solution().isPalindrome(1234567899)}")
