#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    int ans = 0;
    bool positive = x >= 0 ? true : false;
    while (x != 0) {
      int digit = x % 10;

      // Checking int overflow [-2147483648, 2147483647]
      if (positive) {
        if ((INT_MAX - (x % 10)) / 10 < ans)
          return 0;
      } else if ((INT_MIN - (x % 10)) / 10 > ans)
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
