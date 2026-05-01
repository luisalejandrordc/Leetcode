#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    int bestSum = nums[0] + nums[1] + nums[2];
    int len = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < len - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int l = i + 1, r = len - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (abs(sum - target) < abs(bestSum - target))
          bestSum = sum;
        if (sum == target)
          return target;
        else if (sum > target) {
          r--;
        } else {
          l++;
        }
      }
    }
    return bestSum;
  }
};

int main() {
  cout << "It's Showtime Folks" << endl;
  Solution s;
  vector<int> nums = {-1, 2, 1, -4};
  cout << "Solution: " << s.threeSumClosest(nums, 1) << endl;
  nums = {0, 0, 0};
  cout << "Solution: " << s.threeSumClosest(nums, 1) << endl;
  nums = {-84, 92, 26, 19, -7, 9, 42, -51, 8, 30, -100, -13, -38};
  cout << "Solution: " << s.threeSumClosest(nums, 78) << endl;
  return 0;
}
