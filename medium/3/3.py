# 3. Longest Substring Without Repeating Characters
# Given a string s, find the length of the longest
# substring without duplicate characters.


# class Solution:
#     def lengthOfLongestSubstring(self, s: str) -> int:
#         highest, l = 0, 0
#         visited = {}
#         for r in range(len(s)):
#             idx = visited.get(s[r], -1)
#             if idx >= l:
#                 l = idx + 1
#             visited[s[r]] = r
#             highest = max(highest, r - l + 1)
#         return highest


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        highest, r, l = 0, 0, 0
        visited = {}
        size = len(s)
        while r < size and size - l > highest:
            idx = visited.get(s[r], -1)
            if idx >= l:
                l = idx + 1
            visited[s[r]] = r
            highest = max(highest, r - l + 1)
            r += 1
        return highest


s = "abcabcbb"
s = "abcaefghibjkclmnopqraastuvwxyzABCDEFFGHIJKLMMNOPQRSTUUVWXYYZ0123456789!@#abcaefghibjkclmnopq"
print(f"Solution: {Solution().lengthOfLongestSubstring(s)}")
