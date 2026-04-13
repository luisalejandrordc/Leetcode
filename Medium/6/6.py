class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        ans = ""
        length = len(s)
        for i in range(numRows):
            idx = i
            while idx < length:
                ans += s[idx]
                if i in (0, numRows - 1):
                    idx += 2 * numRows - 2
                elif idx % (2 * numRows - 2) < numRows:
                    idx += 2 * numRows - 2 - 2 * i
                else:
                    idx += 2 * i
        return ans


print("It's Showtime Folks!")
print(f"Solution: {Solution().convert("PAYPALISHIRING", 3)}")
