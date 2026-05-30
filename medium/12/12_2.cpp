#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<pair<string, int>> ROMANS = {
    {"I", 1},   {"IV", 4},   {"V", 5},    {"IX", 9},  {"X", 10},
    {"XL", 40}, {"L", 50},   {"XC", 90},  {"C", 100}, {"CD", 400},
    {"D", 500}, {"CM", 900}, {"M", 1000},
};

class Solution {
public:
  string intToRoman(int num) {
    string s = "";
    while (num > 0)
      for (int i = ROMANS.size() - 1; i >= 0; i--)
        if (num >= ROMANS[i].second) {
          num -= ROMANS[i].second;
          s += ROMANS[i].first;
          break;
        }
    return s;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  Solution s;
  cout << "Solution: " << s.intToRoman(3) << endl;
  cout << "Solution: " << s.intToRoman(58) << endl;
  cout << "Solution: " << s.intToRoman(1994) << endl;
  cout << "Solution: " << s.intToRoman(3749) << endl;
  return 0;
}
