# 980. Unique Paths III
# You are given an m x n integer array grid where grid[i][j] could be:
# 1 representing the starting square. There is exactly one starting square.
# 2 representing the ending square. There is exactly one ending square.
# 0 representing empty squares we can walk over.
# -1 representing obstacles that we cannot walk over.
# Return the number of 4-directional walks from the starting square to the
# ending square, that walk over every non-obstacle square exactly once.

DIRECTIONS = [(-1, 0), (0, 1), (1, 0), (0, -1)]

OBSTACLE = -1
EMPTY = 0
START = 1
END = 2


def find_start(grid: list[list[int]], m: int, n: int) -> list[int]:
    for i in range(m):
        for j in range(n):
            if grid[i][j] == START:
                return [i, j]
    return [0, 0]


def find_empty_cells(grid: list[list[int]], m: int, n: int) -> int:
    rem = 0
    for i in range(m):
        for j in range(n):
            if grid[i][j] == 0:
                rem += 1
    return rem


def dfs(
    grid: list[list[int]], m: int, n: int, r: int, c: int, rem: int, cnt: list[int]
):
    for direc in DIRECTIONS:
        i = r + direc[0]
        j = c + direc[1]
        if 0 <= i < m and 0 <= j < n:
            if grid[i][j] == END and rem == 0:
                cnt[0] += 1
            elif grid[i][j] == EMPTY:
                grid[i][j] = OBSTACLE
                dfs(grid, m, n, i, j, rem - 1, cnt)
                grid[i][j] = EMPTY


class Solution:
    def uniquePathsIII(self, grid: list[list[int]]) -> int:
        m, n = len(grid), len(grid[0])
        [r, c] = find_start(grid, m, n)
        rem = find_empty_cells(grid, m, n)
        cnt = [0]
        dfs(grid, m, n, r, c, rem, cnt)
        return cnt[0]


print("It's Showtime Folks!")
grid = [[1, 0, 0, 0], [0, 0, 0, 0], [0, 0, 2, -1]]
print(f"Solution: {Solution().uniquePathsIII(grid)}")
