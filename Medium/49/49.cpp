#include "../../include/utils.h"
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

string sortString(string s) {
  int idx = 1;
  while (idx < s.size())
    if (s[idx] < s[idx - 1]) {
      swap(s[idx], s[idx - 1]);
      if (idx > 1)
        idx--;
    } else
      idx++;
  return s;
}

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> anagrams;
    unordered_map<string, vector<string>> groups;
    for (const string &s : strs) {
      string key = sortString(s);
      // sort(key.begin(), key.end());
      groups[key].push_back(s);
    }
    for (const auto &item : groups)
      anagrams.push_back(item.second);
    return anagrams;
  }
};

int main() {
  printTitle("Group Anagrams");
  cout << "Solution:" << endl;
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> solution = Solution().groupAnagrams(strs);
  for (const auto &v : solution)
    printVector(v);
  return 0;
}
