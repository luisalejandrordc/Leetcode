// 980. Unique Paths III
// You are given an m x n integer array grid where grid[i][j] could be:
// 1 representing the starting square. There is exactly one starting square.
// 2 representing the ending square. There is exactly one ending square.
// 0 representing empty squares we can walk over.
// -1 representing obstacles that we cannot walk over.
// Return the number of 4-directional walks from the starting square to the
// ending square, that walk over every non-obstacle square exactly once.

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

const int DIRECTIONS[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
const int EMPTY = 0;
const int START = 1;
const int END = 2;
const int OBSTACLE = -1;

pair<int, int> findStart(vector<vector<int>> &grid, pair<int, int> &size) {
  for (int i = 0; i < size.first; i++)
    for (int j = 0; j < size.second; j++)
      if (grid[i][j] == START)
        return {i, j};
  return {-1, -1};
}

int countEmptyCells(vector<vector<int>> &grid, pair<int, int> &size) {
  int count = 0;
  for (int i = 0; i < size.first; i++)
    for (int j = 0; j < size.second; j++)
      if (grid[i][j] == EMPTY)
        count++;
  return count;
}

// DFS (Depth-First Search) vs BFS (Breath-First Search)
void dfs(vector<vector<int>> &grid, pair<int, int> &size, pair<int, int> coords,
         int empty, int &total) {
  int i, j;
  for (int k = 0; k < 4; k++) {
    i = coords.first + DIRECTIONS[k][0];
    j = coords.second + DIRECTIONS[k][1];
    if (i >= 0 && i < size.first && j >= 0 && j < size.second)
      if (grid[i][j] != START && grid[i][j] != OBSTACLE) {
        if (grid[i][j] == 2 && empty == 0)
          total++;
        if (grid[i][j] == 0) {
          // cout << "(" << i << "," << j << ")" << endl;
          int temp = grid[i][j];
          grid[i][j] = OBSTACLE;
          dfs(grid, size, {i, j}, empty - 1, total);
          grid[i][j] = temp;
        }
      }
  }
}

class Solution {
public:
  int uniquePathsIII(vector<vector<int>> &grid) {
    pair<int, int> size = {grid.size(), grid[0].size()};
    pair<int, int> coords = findStart(grid, size);
    int empty = countEmptyCells(grid, size);
    int total = 0;
    dfs(grid, size, coords, empty, total);
    return total;
  }
};

int main() {
  cout << "It's Showtime Folks" << endl;
  vector<vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
  cout << "Solution: " << Solution().uniquePathsIII(grid) << endl;
  return 0;
}
