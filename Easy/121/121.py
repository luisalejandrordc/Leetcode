class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        maxPro = 0
        minPri = prices[0]
        for price in prices:
            minPri = min(minPri, price)
            maxPro = max(maxPro, price - minPri)
        return maxPro


print("It's Showtime Folks!")
print(f"Solution: {Solution().maxProfit([7, 1, 5, 3, 6, 4])}")
