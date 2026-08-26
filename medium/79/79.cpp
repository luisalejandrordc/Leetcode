#include <iostream>
#include <utility>
#include <vector>

using namespace std;

const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool dfs(vector<vector<char>> &board, string &word, int m, int n, int x, int y,
         int idx) {
  if (idx == word.length())
    return true;
  if (x < 0 || x >= m || y < 0 || y >= n)
    return false;
  if (board[x][y] != word[idx])
    return false;
  char temp = board[x][y];
  board[x][y] = '\0';
  for (auto &v : DIRECTIONS)
    if (dfs(board, word, m, n, x + v.first, y + v.second, idx + 1)) {
      board[x][y] = temp;
      return true;
    }
  board[x][y] = temp;
  return false;
}

class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    const int m = board.size();
    const int n = board[0].size();
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (dfs(board, word, m, n, i, j, 0))
          return true;
    return false;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  string word = "ABCCED";
  cout << "Result: " << Solution().exist(board, word) << endl;
  word = "ABC";
  cout << "Result: " << Solution().exist(board, word) << endl;
  board = {{'a', 'a'}};
  word = "aaa";
  cout << "Result: " << Solution().exist(board, word) << endl;
  return 0;
}
