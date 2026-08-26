#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 1; i < m; i++)
      for (int j = 1; j < n; j++)
        if (matrix[i][j] != matrix[i - 1][j - 1])
          return false;
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
