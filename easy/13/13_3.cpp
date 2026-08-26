#include <iostream>
#include <unordered_map>

using namespace std;

const unordered_map<char, int> ROMANS = {
    {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
    {'C', 100}, {'D', 500}, {'M', 1000},
};

class Solution {
public:
  int romanToInt(string s) {
    int num = 0;
    int len = s.length();
    for (int i = 0; i < len; i++) {
      if (i + 1 < len && ROMANS.at(s[i]) < ROMANS.at(s[i + 1])) {
        num += ROMANS.at(s[i + 1]) - ROMANS.at(s[i]);
        i++;
      } else
        num += ROMANS.at(s[i]);
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
