class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        my_set = {c for c in jewels}
        count = 0
        for c in stones:
            if c in my_set:
                count += 1
        return count


s = Solution()
print(f"Solution: {s.numJewelsInStones("aA", "aAAbbbb")}")
print(f"Solution: {s.numJewelsInStones("z", "ZZ")}")
