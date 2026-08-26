DICT = {
    "I": 1,
    "V": 5,
    "X": 10,
    "L": 50,
    "C": 100,
    "D": 500,
    "M": 1000,
}


class Solution:
    def romanToInt(self, s: str) -> int:
        num = 0
        length = len(s)
        for i in range(length):
            if i != length - 1:
                if s[i] == "I" and (s[i + 1] in "VX"):
                    num -= 1
                    continue
                if s[i] == "X" and (s[i + 1] in "LC"):
                    num -= 10
                    continue
                if s[i] == "C" and (s[i + 1] in "DM"):
                    num -= 100
                    continue
            num += DICT.get(s[i], 0)
        return num


print("It's Showtime Folks!")
sol = Solution()
print(f"Solution: {sol.romanToInt("III")}")
print(f"Solution: {sol.romanToInt("LVIII")}")
print(f"Solution: {sol.romanToInt("MCMXCIV")}")
