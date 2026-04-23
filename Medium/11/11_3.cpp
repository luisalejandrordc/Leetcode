#include <iostream>
#include <vector>

using namespace std;

// Good attempt, but incorrect
class Solution {
public:
  int maxArea(vector<int> &height) {
    int maxAreaVar = 0;
    int l = 0;
    for (int i = 1; i < height.size(); i++) {
      if (height[i] - height[l] > i - l) {
        cout << i << endl;
        l = i;
      }
      maxAreaVar = max(maxAreaVar, min(height[l], height[i]) * (i - l));
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
