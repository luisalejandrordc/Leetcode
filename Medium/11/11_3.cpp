#include <iostream>
#include <vector>

using namespace std;

// Optimal Solution
class Solution {
public:
  int maxArea(const vector<int> &height) {
    int maxAreaVar = 0;
    int curAreaVar = 0;
    int l = 0, r = height.size() - 1;
    while (l < r) {
      curAreaVar = min(height[l], height[r]) * (r - l);
      maxAreaVar = max(maxAreaVar, curAreaVar);
      if (height[l] < height[r])
        l = l + 1;
      else
        r = r - 1;
    }
    return maxAreaVar;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  Solution s;
  cout << "Solution: " << s.maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}) << endl;
  cout << "Solution: " << s.maxArea({1, 2, 3, 4}) << endl;
  return 0;
}
