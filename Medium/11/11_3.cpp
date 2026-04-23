#include <iostream>
#include <vector>

using namespace std;

// Optimal Solution
class Solution {
public:
  int maxArea(const vector<int> &height) {
    int maxAreaVar = 0;
    int l = 0, r = height.size() - 1;
    while (l < r) {
      int w = r - l;
      int h = min(height[l], height[r]);
      maxAreaVar = max(maxAreaVar, w * h);
      if (height[l] < height[r])
        l++;
      else
        r--;
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
