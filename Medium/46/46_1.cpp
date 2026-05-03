#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &nums) {
  cout << "[";
  for (int i = 0; i < nums.size() - 1; i++)
    cout << nums[i] << "\t";
  cout << nums[nums.size() - 1] << "]" << endl;
}

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    // Base condition
    if (nums.size() == 0)
      return {{}};
    // Recursion
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size(); i++) {
      int temp = nums[i];
      nums.erase(nums.begin() + i);
      for (vector<int> &v : permute(nums)) {
        v.insert(v.begin(), temp);
        ans.push_back(v);
      }
      nums.insert(nums.begin() + i, temp);
    }
    return ans;
  }
};

int main() {
  cout << "It's Showtime Folks" << endl;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> ans = Solution().permute(nums);
  for (vector<int> &v : ans)
    printVector(v);
  return 0;
}
