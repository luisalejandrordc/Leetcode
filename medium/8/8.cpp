#include <climits>
#include <iostream>
#include <unordered_set>

using namespace std;

const int POS_LIM = INT_MAX / 10;
const int NEG_LIM = INT_MIN / 10;
const unordered_set<char> DIGITS = [] {
  unordered_set<char> s;
  for (int i = 0; i < 10; i++)
    s.insert('0' + i);
  return s;
}();

class Solution {
public:
  int myAtoi(const string s) {
    int num = 0;
    bool negative = false;
    bool started = false;
    for (char c : s) {
      if (c == ' ' && !started)
        continue;
      if (DIGITS.count(c)) {
        started = true;
        int digit = !negative ? c - '0' : '0' - c;
        if (num > POS_LIM || (num == POS_LIM && digit > 7))
          return INT_MAX;
        if (num < NEG_LIM || (num == NEG_LIM && digit < -8))
          return INT_MIN;
        num = num * 10 + digit;
      } else if (c == '-' && !started) {
        started = true;
        negative = true;
      } else if (c == '+' && !started) {
        started = true;
      } else
        return num;
    }
    return num;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  cout << "Solution: " << Solution().myAtoi("123") << endl;
  cout << "Solution: " << Solution().myAtoi("-042") << endl;
  cout << "Solution: " << Solution().myAtoi("1337c0d3") << endl;
  cout << "Solution: " << Solution().myAtoi("2147483648") << endl;
  return 0;
}
