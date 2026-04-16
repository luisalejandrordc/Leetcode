#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    int ans = 0;
    while (x != 0) {
      int digit = x % 10;

      // Checking int overflow [-2147483648, 2147483647]
      if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7))
        return 0;
      if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && digit < -8))
        return 0;

      ans = ans * 10 + (x % 10);
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
