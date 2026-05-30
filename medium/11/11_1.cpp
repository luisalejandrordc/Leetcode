#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Brute force solution
class Solution {
public:
  int maxArea(vector<int> &height) {
    int maxAreaVar = 0;
    for (int i = 0; i < height.size() - 1; i++)
      for (int j = i + 1; j < height.size(); j++)
        maxAreaVar = max(maxAreaVar, min(height[i], height[j]) * (j - i));
    return maxAreaVar;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  Solution s;
  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << "Solution: " << s.maxArea(height) << endl;
  return 0;
}
