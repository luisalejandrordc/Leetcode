#include <iostream>
#include <vector>

using namespace std;

// Good attempt, but incorrect
class Solution {
public:
  int maxArea(const vector<int> &height) {
    int maxAreaVar = 0;
    int l = 0;
    for (int i = 1; i < height.size(); i++) {
      if (height[i] - height[l] > i - l)
        l = i;
      maxAreaVar = max(maxAreaVar, min(height[l], height[i]) * (i - l));
    }
    return maxAreaVar;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  Solution s;
  cout << "Solution: " << s.maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}) << endl;
  cout << "Solution: " << s.maxArea({1, 2, 3, 4}) << endl;
  cout << "Solution: " << s.maxArea({1, 3, 2, 5, 25, 24, 5}) << endl;
  return 0;
}
