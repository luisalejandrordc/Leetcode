#include <iostream>
#include <vector>

using namespace std;

int getMinLength(vector<string> &strs) {
  int min = INT_MAX;
  for (string c : strs)
    if (c.length() < min)
      min = c.length();
  return min;
}

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string s = "";
    int min = getMinLength(strs);
    for (int k = 0; k < min; k++) {
      for (int i = 0; i < strs.size() - 1; i++)
        if (strs[i][k] != strs[i + 1][k])
          return s;
      s += strs[0][k];
    }
    return s;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  Solution s;
  vector<string> strs = {"flower", "flow", "flight"};
  cout << "Solution: " << s.longestCommonPrefix(strs) << endl;
  strs = {"dog", "racecar", "car"};
  cout << "Solution: " << s.longestCommonPrefix(strs) << endl;
  return 0;
}
