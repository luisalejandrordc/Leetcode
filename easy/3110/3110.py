# 3110. Score of a String
# You are given a string s. The score of a string
# is defined as the sum of the absolute difference
# between the ASCII values of adjacent characters.
# Return the score of s.


class Solution:
    def scoreOfString(self, s: str) -> int:
        score = 0
        for i in range(len(s) - 1):
            score += abs(ord(s[i]) - ord(s[i + 1]))
        return score


print(f"Solution: {Solution().scoreOfString("zaaz")}")
