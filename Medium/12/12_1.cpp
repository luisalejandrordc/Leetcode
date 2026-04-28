#include <iostream>
#include <utility>
#include <vector>

using namespace std;

const vector<pair<char, int>> ROMAN = {
    {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
    {'C', 100}, {'D', 500}, {'M', 1000},
};

int getStartDigit(int num) {
  while (num >= 10)
    num /= 10;
  return num;
}

class Solution {
public:
  string intToRoman(int num) {
    string s = "";
    while (num != 0) {
      int start = getStartDigit(num);
      if (start == 4) {
        if (num < 5) {
          s += "IV";
          num -= 4;
        } else if (num < 50) {
          s += "XL";
          num -= 40;
        } else if (num < 500) {
          s += "CD";
          num -= 400;
        }
      } else if (start == 9) {
        if (num < 10) {
          s += "IX";
          num -= 9;
        } else if (num < 100) {
          s += "XC";
          num -= 90;
        } else if (num < 1000) {
          s += "CM";
          num -= 900;
        }
      } else {
        for (int i = ROMAN.size() - 1; i >= 0; i--) {
          if (ROMAN[i].second <= num) {
            s += ROMAN[i].first;
            num -= ROMAN[i].second;
            break;
          }
        }
      }
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
