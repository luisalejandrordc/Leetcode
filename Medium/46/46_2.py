import math


def backtrack(nums: list[int], a: int, result: list[list[int]]):
    if a == len(nums) - 1:
        result.append(nums.copy())
        return
    for b in range(a, len(nums)):
        nums[a], nums[b] = nums[b], nums[a]
        backtrack(nums, a + 1, result)
        nums[a], nums[b] = nums[b], nums[a]


class Solution:
    def permute(self, nums: list[int]) -> list[list[int]]:
        result = []
        backtrack(nums, 0, result)
        return result


print("It's Showtime Folks!")
nums = [1, 2, 3]
result = Solution().permute(nums)
print(result)
print(len(result) == math.factorial(len(nums)))
