#include <iostream>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int i = 0, j = 0;
    char c;
    bool asterisk = false;
    while (true) {
      if (i == s.length() || j == p.length())
        break;
      if (asterisk) {
        if (s[i] == c || c == '.')
          i++;
        else {
          asterisk = false;
          j++;
        }
      } else {
        if (p[j] == '*') {
          asterisk = true;
          c = p[j - 1];
        } else {
          if (p[j] == s[i] || p[j] == '.') {
            i++;
            j++;
          } else if (j + 1 < p.length() && p[j + 1] == '*') {
            j++;
          } else {
            return false;
          }
        }
      }
    }
    if (asterisk)
      return i == s.length() && j == p.length() - 1 ? true : false;
    return i == s.length() && j == p.length() ? true : false;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  Solution s;
  cout << "Solution: " << s.isMatch("aa", "a") << endl;
  cout << "Solution: " << s.isMatch("aa", "a*") << endl;
  cout << "Solution: " << s.isMatch("aa", ".*") << endl;
  cout << "Solution: " << s.isMatch("ab", ".*") << endl;
  cout << "Solution: " << s.isMatch("aab", "c*a*b") << endl;
  return 0;
}
