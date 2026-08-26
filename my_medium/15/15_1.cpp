#include <iostream>
#include <vector>

using namespace std;

void printSolution(const vector<vector<int>> &sol) {
  cout << "Solution:" << endl;
  for (vector<int> v : sol) {
    cout << "[\t";
    for (int x : v)
      cout << x << "\t";
    cout << "]" << endl;
  }
}

vector<vector<int>> getCombinations(vector<int> &nums, int k, int start = 0) {
  vector<vector<int>> coms;
  if (k == 1) {
    for (int i = start; i < nums.size(); i++)
      coms.push_back({nums[i]});
    return coms;
  }
  for (int i = start; i <= nums.size() - k; i++) {
    for (vector<int> com : getCombinations(nums, k - 1, i + 1)) {
      com.insert(com.begin(), nums[i]);
      coms.push_back(com);
    }
  }
  return coms;
}

void orderArray(vector<int> &nums) {
  int i = 0;
  while (i < nums.size() - 1) {
    if (nums[i] > nums[i + 1]) {
      int temp = nums[i];
      nums[i] = nums[i + 1];
      nums[i + 1] = temp;
      if (i > 0)
        i--;
    } else
      i++;
  }
}

bool alreadyExists(vector<vector<int>> &nums, vector<int> &com) {
  for (vector<int> rec : nums) {
    bool exists = true;
    for (int i = 0; i < rec.size(); i++)
      if (rec[i] != com[i])
        exists = false;
    if (exists)
      return true;
  }
  return false;
}

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    orderArray(nums);
    for (vector<int> com : getCombinations(nums, 3)) {
      int sum = 0;
      for (int num : com)
        sum += num;
      if (sum == 0 && !alreadyExists(ans, com))
        ans.push_back(com);
    }
    return ans;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  Solution s;
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  printSolution(s.threeSum(nums));
  nums = {-15, 10,  0,  -2,  14,  -1,  -10, -14, 10,  12,  6,   -6,  10,  2,
          -11, -9,  2,  13,  2,   -9,  -14, -12, -10, -12, 13,  13,  -10, -3,
          2,   -11, 3,  -6,  6,   10,  7,   5,   -13, 4,   -2,  12,  1,   -11,
          14,  -4,  6,  -12, -6,  -14, 8,   11,  -8,  1,   7,   -3,  5,   5,
          -13, 10,  9,  -3,  6,   -10, 6,   -3,  7,   -9,  -13, 9,   10,  0,
          -1,  -11, 4,  -10, -8,  -13, -15, 2,   -12, 8,   -2,  -12, -14, -10,
          -8,  6,   2,  -5,  -7,  -11, 7,   14,  -6,  -10, -12, 8,   -4,  -10,
          -5,  14,  -3, 9,   -12, 8,   14,  -13};
  printSolution(s.threeSum(nums));
  return 0;
}
