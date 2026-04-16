#include <climits>
#include <cmath>
#include <iostream>
#include <ostream>

using namespace std;

int getNumberDigits(int x) {
  int count = 0;
  while (true) {
    x = x / 10;
    count++;
    if (x == 0)
      break;
  }
  return count;
}

class Solution {
public:
  int reverse(int x) {
    int ans = 0;
    int numDigits = getNumberDigits(x);
    while (true) {
      // ans += (x % 10) * pow(10, numDigits - 1 - i);
      ans = ans * 10 + (x % 10);
      x = x / 10;
      if (x == 0)
        break;
    }
    return ans;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  cout << "Solution: " << Solution().reverse(123) << endl;
  cout << "Solution: " << Solution().reverse(-12) << endl;
  return 0;
}
