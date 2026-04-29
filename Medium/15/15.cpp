#include <iostream>
#include <vector>

using namespace std;

void printSolution(const vector<vector<int>> &sol) {
  cout << "Solution: ";
  for (vector<int> v : sol) {
    cout << "[\t";
    for (int x : v)
      cout << x << "\t";
    cout << "] \t";
  }
  cout << endl;
}

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    cout << endl;
    return {{0, 1, -1}};
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  Solution s;
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  printSolution(s.threeSum(nums));
  return 0;
}
