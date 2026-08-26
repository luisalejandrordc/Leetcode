# 1. Two Sum
# Given an array of integers nums and an integer target,
# return indices of the two numbers such that they add up to target.
# You may assume that each input would have exactly one solution,
# and you may not use the same element twice.
# You can return the answer in any order.


# 2225 ms
# class Solution(object):
#     def twoSum(self, nums: list[int], target: int) -> list[int]:
#         for i in range(len(nums) - 1):
#             for j in range(i + 1, len(nums)):
#                 if nums[i] + nums[j] == target:
#                     return [i, j]


# 1ms
class Solution(object):
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        mydict = {n: i for i, n in enumerate(nums)}
        for i in range(len(nums) - 1):
            diff = target - nums[i]
            idx = mydict.get(diff, -1)
            if idx not in [-1, i]:
                return [i, idx]


s = Solution()
print(s.twoSum([2, 7, 11, 15], 9))
print(s.twoSum([1, 2, 3, 4], 7))
