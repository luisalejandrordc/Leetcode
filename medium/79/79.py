DIRECTIONS = [[-1, 0], [0, 1], [1, 0], [0, -1]]


def dfs(
    board: list[list[str]], word: str, m: int, n: int, x: int, y: int, idx: int
) -> bool:
    if idx == len(word):
        return True
    if x < 0 or x >= m or y < 0 or y >= n:
        return False
    if board[x][y] != word[idx]:
        return False
    temp = board[x][y]
    board[x][y] = "\0"
    for v in DIRECTIONS:
        if dfs(board, word, m, n, x + v[0], y + v[1], idx + 1):
            board[x][y] = temp
            return True
    board[x][y] = temp
    return False


class Solution:
    def exist(self, board: list[list[str]], word: str) -> bool:
        m = len(board)
        n = len(board[0])
        for i in range(m):
            for j in range(n):
                if dfs(board, word, m, n, i, j, 0):
                    return True
        return False


print("It's Showtime Folks!")
board = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]]
word = "ABCCED"
print(f"Result: {Solution().exist(board, word)}")
board = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]]
word = "SEE"
print(f"Result: {Solution().exist(board, word)}")
board = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]]
word = "ABCB"
print(f"Result: {Solution().exist(board, word)}")
