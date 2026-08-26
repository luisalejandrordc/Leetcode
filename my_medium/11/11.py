class Solution:
    def maxArea(self, height: list[int]) -> int:
        maxAreaVar = 0
        l, r = 0, len(height) - 1
        while l < r:
            w = r - l
            h = min(height[l], height[r])
            maxAreaVar = max(maxAreaVar, w * h)
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return maxAreaVar


print("It's Showtime Folks!")
s = Solution()
print(f"Solution: {s.maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7])}")
print(f"Solution: {s.maxArea([1, 2, 3, 4])}")
print(f"Solution: {s.maxArea([1, 3, 2, 5, 25, 24, 5])}")
