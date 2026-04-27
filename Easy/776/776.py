class Solution:
    def isToeplitzMatrix(self, matrix: list[list[int]]) -> bool:
        m = len(matrix)
        n = len(matrix[0])
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] != matrix[i - 1][j - 1]:
                    return False
        return True


print("It's Showtime Folks!")
s = Solution()
matrix1 = [
    [1, 2, 3, 4],
    [5, 1, 2, 3],
    [9, 5, 1, 2],
]
print(f"Solution: {s.isToeplitzMatrix(matrix1)}")
matrix2 = [
    [1, 2],
    [2, 2],
]
print(f"Solution: {s.isToeplitzMatrix(matrix2)}")
