def getMinLength(strs: list[str]) -> int:
    mi = 2147483647  # 2^32 - 1
    for s in strs:
        mi = min(mi, len(s))
    return mi


class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        s = ""
        for k in range(getMinLength(strs)):
            for i in range(len(strs) - 1):
                if strs[i][k] != strs[i + 1][k]:
                    return s
            s += strs[0][k]
        return s


print("It's Showtime Folks!")
sol = Solution()
strs1 = ["flower", "flow", "flight"]
print(f"Solution: {sol.longestCommonPrefix(strs1)}")
strs2 = ["dog", "racecar", "car"]
print(f"Solution: {sol.longestCommonPrefix(strs2)}")
