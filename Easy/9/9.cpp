#include <climits>
#include <iostream>

using namespace std;

// Reverse the number and compare it to the original to verify if it is a
// palindrome or not
class Solution {
public:
  bool isPalindrome(int x) {
    int num = x;
    if (x < 0)
      return false;
    int rev = 0;
    while (x != 0) {
      int digit = x % 10;
      if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7))
        return false;
      if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8))
        return false;
      rev = rev * 10 + digit;
      x = x / 10;
    }
    return num == rev;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  cout << "Solution: " << Solution().isPalindrome(121) << endl;
  cout << "Solution: " << Solution().isPalindrome(-121) << endl;
  cout << "Solution: " << Solution().isPalindrome(10) << endl;
  cout << "Solution: " << Solution().isPalindrome(1234567899) << endl;
  return 0;
}
