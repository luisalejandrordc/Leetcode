#include <iostream>
#include <vector>

using namespace std;

bool verifyDiagonal(vector<vector<int>> &matrix, int i, int j, int m, int n) {
  int num = matrix[i][j];
  while (i < m && j < n)
    if (matrix[i++][j++] != num)
      return false;
  return true;
}

class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int i = m - 1, j = 0;
    while (i >= 0) {
      if (!verifyDiagonal(matrix, i, j, m, n))
        return false;
      i--;
    }
    i = 0;
    while (j < n) {
      if (!verifyDiagonal(matrix, i, j, m, n))
        return false;
      j++;
    }
    return true;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  Solution s;
  vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}};
  cout << "Solution: " << s.isToeplitzMatrix(matrix) << endl;
  matrix = {{1, 2}, {2, 2}};
  cout << "Solution: " << s.isToeplitzMatrix(matrix) << endl;
  return 0;
}
