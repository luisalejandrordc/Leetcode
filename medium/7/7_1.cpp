#include <cmath>
#include <iostream>

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
    for (int i = 0; i < numDigits; i++) {
      ans += (x % 10) * pow(10, numDigits - 1 - i);
      x /= 10;
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
