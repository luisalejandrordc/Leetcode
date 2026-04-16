#include <iostream>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    int ans = 0;
    while (true) {
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
