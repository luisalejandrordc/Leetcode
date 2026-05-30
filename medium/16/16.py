class Solution:
    def threeSumClosest(self, nums: list[int], target: int) -> int:
        best_sum = nums[0] + nums[1] + nums[2]
        length = len(nums)
        nums = sorted(nums)
        for i in range(length - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            l = i + 1
            r = length - 1
            while l < r:
                curr_sum = nums[i] + nums[l] + nums[r]
                if abs(curr_sum - target) < abs(best_sum - target):
                    best_sum = curr_sum
                if curr_sum == target:
                    return target
                if curr_sum < target:
                    l += 1
                else:
                    r -= 1
        return best_sum


print("It's Showtime Folks!")

s = Solution()
nums = [-1, 2, 1, -4]
print(f"Solution: {s.threeSumClosest(nums, 1)}")
nums = [0, 0, 0]
print(f"Solution: {s.threeSumClosest(nums, 1)}")
nums = [-84, 92, 26, 19, -7, 9, 42, -51, 8, 30, -100, -13, -38]
print(f"Solution: {s.threeSumClosest(nums, 78)}")
