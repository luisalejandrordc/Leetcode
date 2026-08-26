class Solution:
    def permute(self, nums: list[int]) -> list[list[int]]:
        if len(nums) == 0:
            return [[]]
        result = []
        for i in range(len(nums)):
            temp = nums[i]
            nums.pop(i)
            for v in self.permute(nums):
                result.append([temp] + v)
            nums.insert(i, temp)
        return result


print("It's Showtime Folks!")
print(Solution().permute([1, 2, 3]))
