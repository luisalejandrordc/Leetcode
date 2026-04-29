#include <iostream>
#include <vector>

using namespace std;

void printSolution(const vector<vector<int>> &sol) {
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

int main() {
  cout << "It's Showtime Folks!" << endl;
  vector<int> nums = {1, 2, 3, 4};
  printSolution(getCombinations(nums, 3));
  return 0;
}
