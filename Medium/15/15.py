class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        ans = []
        length = len(nums)
        nums.sort()
        for i in range(length - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            l = i + 1
            r = length - 1
            while l < r:
                my_sum = nums[i] + nums[l] + nums[r]
                if my_sum == 0:
                    ans.append([nums[i], nums[l], nums[r]])
                    while l < r and nums[l] == nums[l + 1]:
                        l += 1
                    while l < r and nums[r] == nums[r - 1]:
                        r -= 1
                    l += 1
                    r -= 1
                elif my_sum < 0:
                    l += 1
                else:
                    r -= 1
        return ans


print("It's Showtime Folks!")
nums = [-1, 0, 1, 2, -1, -4]
print(f"Solution: {Solution().threeSum(nums)}")
nums = [0, 1, 1]
print(f"Solution: {Solution().threeSum(nums)}")
nums = [0, 0, 0]
print(f"Solution: {Solution().threeSum(nums)}")
