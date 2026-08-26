ROMANS = [
    ["I", 1],
    ["IV", 4],
    ["V", 5],
    ["IX", 9],
    ["X", 10],
    ["XL", 40],
    ["L", 50],
    ["XC", 90],
    ["C", 100],
    ["CD", 400],
    ["D", 500],
    ["CM", 900],
    ["M", 1000],
]


class Solution:
    def intToRoman(self, num: int) -> str:
        s = ""
        for x in reversed(ROMANS):
            while num >= x[1]:
                num -= x[1]
                s += x[0]
        return s


print("It's Showtime Folks!")
sol = Solution()
print(f"Solution: {sol.intToRoman(3)}")
print(f"Solution: {sol.intToRoman(58)}")
print(f"Solution: {sol.intToRoman(1994)}")
print(f"Solution: {sol.intToRoman(3749)}")
