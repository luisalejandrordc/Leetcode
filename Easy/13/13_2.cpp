#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

const unordered_map<string, int> ROMANS = {
    {"I", 1},   {"IV", 4},   {"V", 5},    {"IX", 9},  {"X", 10},
    {"XL", 40}, {"L", 50},   {"XC", 90},  {"C", 100}, {"CD", 400},
    {"D", 500}, {"CM", 900}, {"M", 1000},
};

class Solution {
public:
  int romanToInt(string s) {
    int num = 0;
    int len = s.length();
    for (int i = 0; i < len; i++) {
      string d = string(1, s[i]);
      if (i != len - 1) {
        d += s[i + 1];
        if (ROMANS.count(d)) {
          num += ROMANS.at(d);
          i++;
          continue;
        } else
          d.pop_back();
      }
      num += ROMANS.at(d);
    }
    return num;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  Solution s;
  cout << "Solution: " << s.romanToInt("III") << endl;
  cout << "Solution: " << s.romanToInt("LVIII") << endl;
  cout << "Solution: " << s.romanToInt("MCMXCIV") << endl;
  return 0;
}
