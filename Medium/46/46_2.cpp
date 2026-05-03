#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void printVector(vector<int> &nums) {
  cout << "[";
  for (int i = 0; i < nums.size() - 1; i++)
    cout << nums[i] << "\t";
  cout << nums[nums.size() - 1] << "]" << endl;
}

void backtrack(vector<int> &nums, int a, vector<vector<int>> &result) {
  if (a == nums.size() - 1) {
    result.push_back(nums);
    return;
  }
  for (int b = a; b < nums.size(); b++) {
    swap(nums[a], nums[b]);
    backtrack(nums, a + 1, result);
    swap(nums[a], nums[b]);
  }
}

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    backtrack(nums, 0, result);
    return result;
  }
};

int main() {
  cout << "It's Showtime Folks" << endl;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> ans = Solution().permute(nums);
  for (vector<int> v : ans)
    printVector(v);
  return 0;
}
