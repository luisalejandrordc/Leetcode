#include <iostream>
#include <vector>

using namespace std;

void printAns(vector<vector<char>> s) {
  for (int i = 0; i < s.size(); i++) {
    for (char c : s[i])
      cout << c << "\t";
    cout << endl;
  }
}

string joinString(vector<vector<char>> s) {
  string ans;
  for (int i = 0; i < s.size(); i++)
    for (char c : s[i])
      if (c != '\0')
        ans += c;
  return ans;
}

class Solution {
public:
  string convert(string s, int numRows) {
    vector<vector<char>> ans;
    ans.resize(numRows);
    int nC = numRows > 1
                 ? s.length() -
                       (numRows - 1) * ceil(s.length() / (2 * (numRows - 1)))
                 : s.length();
    cout << endl << nC << " " << ceil(s.length() / (2 * (numRows - 1))) << endl;
    for (int i = 0; i < numRows; i++)
      ans[i].resize(nC);
    int k = 0, i = 0, j = 0;
    bool reset = false;
    while (k < s.length()) {
      if (numRows == 1 || j % (numRows - 1) == 0) {
        if (reset) {
          reset = false;
          i = 0;
        }
        if (i < numRows) {
          ans[i][j] = s[k++];
          i++;
        } else {
          reset = true;
          i--;
          j++;
        }
      } else {
        i--;
        ans[i][j] = s[k++];
        j++;
      }
    }
    cout << endl;
    printAns(ans);
    return joinString(ans);
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  cout << "Solution: " << Solution().convert("PAYPALISHIRING", 3) << endl;
  return 0;
}
