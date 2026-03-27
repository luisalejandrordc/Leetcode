// 1. Two Sum
// Given an array of integers nums and an integer target,
// return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution,
// and you may not use the same element twice.
// You can return the answer in any order.

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// 43 ms
// class Solution {
// public:
//   vector<int> twoSum(vector<int> &nums, int target) {
//     for (int i = 0; i < nums.size() - 1; i++) {
//       for (int j = i + 1; j < nums.size(); j++) {
//         if (nums[i] + nums[j] == target) {
//           return {i, j};
//         }
//       }
//     }
//     return {};
//   }
// };

// 10 ms
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      map[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++) {
      int diff = target - nums[i];
      if (map.count(diff)) {
        int idx = map[diff];
        if (idx != i) {
          return {i, idx};
        }
      }
    }
    return {};
  }
};

int main() {
  cout << "It's Showtime Folks" << endl;

  Solution s;
  vector<int> v = {2, 7, 11, 15};
  vector<int> res = s.twoSum(v, 9);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << "\t";
  }

  return 0;
}
