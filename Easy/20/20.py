closedToOpen = {
    ")": "(",
    "]": "[",
    "}": "{",
}


class Solution:
    def isValid(self, s: str) -> bool:
        history = []
        for c in s:
            if closedToOpen.get(c):
                if len(history) == 0 or history[-1] != closedToOpen.get(c):
                    return False
                history.pop()
            else:
                history.append(c)
        return len(history) == 0


print("It's Showtime Folks!")
s = Solution()
print(f"Solution: {s.isValid("()")}")
print(f"Solution: {s.isValid("()[]{}")}")
print(f"Solution: {s.isValid("(]")}")
print(f"Solution: {s.isValid("([])")}")
print(f"Solution: {s.isValid("([)]")}")
