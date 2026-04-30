#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &nums) {
  int len = nums.size();
  cout << "[";
  for (int i = 0; i < len; i++) {
    cout << nums[i];
    if (i != len - 1)
      cout << "\t";
  }
  cout << "]" << endl;
}

void sortVector(vector<int> &nums) {
  int i = 0;
  while (i < nums.size() - 1) {
    if (nums[i] > nums[i + 1]) {
      swap(nums[i], nums[i + 1]);
      if (i > 0)
        i--;
    } else
      i++;
  }
}

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    int len = nums.size();
    sort(nums.begin(), nums.end());
    // sortVector(nums);
    for (int i = 0; i < len - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int l = i + 1, r = len - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum == 0) {
          ans.push_back({nums[i], nums[l], nums[r]});
          while (l < r && nums[l] == nums[l + 1])
            l++;
          l++;
          while (l < r && nums[r] == nums[r - 1])
            r--;
          r--;
        } else if (sum < 0)
          l++;
        else
          r--;
      }
    }
    return ans;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  // Testcase 1
  cout << "Testcase 1:" << endl;
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> ans = Solution().threeSum(nums);
  for (vector<int> v : ans)
    printVector(v);
  // Testcase 2
  cout << "Testcase 2:" << endl;
  nums = {-1, 0, 1, 0};
  ans = Solution().threeSum(nums);
  for (vector<int> v : ans)
    printVector(v);
  // Testcase 3
  cout << "Testcase 3:" << endl;
  nums = {-15, 10,  0,  -2,  14,  -1,  -10, -14, 10,  12,  6,   -6,  10,  2,
          -11, -9,  2,  13,  2,   -9,  -14, -12, -10, -12, 13,  13,  -10, -3,
          2,   -11, 3,  -6,  6,   10,  7,   5,   -13, 4,   -2,  12,  1,   -11,
          14,  -4,  6,  -12, -6,  -14, 8,   11,  -8,  1,   7,   -3,  5,   5,
          -13, 10,  9,  -3,  6,   -10, 6,   -3,  7,   -9,  -13, 9,   10,  0,
          -1,  -11, 4,  -10, -8,  -13, -15, 2,   -12, 8,   -2,  -12, -14, -10,
          -8,  6,   2,  -5,  -7,  -11, 7,   14,  -6,  -10, -12, 8,   -4,  -10,
          -5,  14,  -3, 9,   -12, 8,   14,  -13};
  ans = Solution().threeSum(nums);
  for (vector<int> v : ans)
    printVector(v);
  return 0;
}
