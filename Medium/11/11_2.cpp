#include <iostream>
#include <vector>

using namespace std;

// Optimal Solution
class Solution {
public:
  int maxArea(vector<int> &height) {
    int maxAreaVar = 0;
    int s = 0;
    for (int i = 1; i < height.size(); i++) {
      if (height[i] - height[s] > i - s)
        s = i;
      maxAreaVar = max(maxAreaVar, min(height[s], height[i]) * (i - s));
    }
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
