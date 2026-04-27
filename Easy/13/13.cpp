#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, int> dict = {
    {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
    {'C', 100}, {'D', 500}, {'M', 1000},
};

class Solution {
public:
  int romanToInt(string s) {
    int num = 0;
    int len = s.length();
    for (int i = 0; i < len; i++) {
      if (i != len - 1) {
        if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
          num -= 1;
          continue;
        }
        if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
          num -= 10;
          continue;
        }
        if (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
          num -= 100;
          continue;
        }
      }
      num += dict[s[i]];
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
