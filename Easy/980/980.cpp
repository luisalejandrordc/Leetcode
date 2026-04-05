#include <iostream>
#include <vector>

using namespace std;

const int DIRECTIONS[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool is_completed(vector<vector<int>> &grid, int &m, int &n) {
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (grid[i][j] == 0)
        return 0;
  return 1;
}

void four_directions(vector<vector<int>> grid, int &m, int &n, int row, int col,
                     int &total) {
  int i, j;
  for (int k = 0; k < 4; k++) {
    i = row + DIRECTIONS[k][0];
    j = col + DIRECTIONS[k][1];
    if ((i >= 0 && i < m) && (j >= 0 && j < n))
      if (grid[i][j] != -1 && grid[i][j] != 1) {
        if (grid[i][j] == 2 && is_completed(grid, m, n)) {
          total += 1;
        }
        if (grid[i][j] == 0) {
          // cout << "(" << i << "," << j << ")" << endl;
          vector<vector<int>> new_grid = grid;
          new_grid[i][j] = 1;
          four_directions(new_grid, m, n, i, j, total);
        }
      }
  }
}

class Solution {
public:
  int uniquePathsIII(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int row = -1, col = -1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          row = i;
          col = j;
          break;
        }
      }
      if (row != -1)
        break;
    }
    int total = 0;
    four_directions(grid, m, n, row, col, total);
    return total;
  }
};

int main() {
  cout << "It's Showtime Folks" << endl;
  vector<vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
  cout << "Solution: " << Solution().uniquePathsIII(grid) << endl;
  return 0;
}
