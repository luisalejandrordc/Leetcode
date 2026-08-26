#include <iostream>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1)
      return s;
    string ans;
    int len = s.length();
    ans.reserve(len);
    cout << endl;
    for (int i = 0; i < numRows; i++) {
      int idx = i;
      while (idx < len) {
        ans += s[idx];
        // cout << idx << endl;
        if (i == 0 || i == numRows - 1)
          idx += 2 * numRows - 2; // First and last row
        else if (idx % (2 * numRows - 2) < numRows)
          idx += 2 * numRows - 2 - 2 * i; // Middle rows (vertical)
        else
          idx += 2 * i; // Middle rows (diagonal)
      }
    }
    return ans;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  cout << "Solution: " << Solution().convert("PAYPALISHIRING", 3) << endl;
  return 0;
}
