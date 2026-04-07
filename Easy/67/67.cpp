// 67. Add Binary
// Given two binary strings a and b, return their sum as a binary string.

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

string reverseString(const string &s) {
  string r;
  r.reserve(s.length());
  for (int i = s.length() - 1; i >= 0; i--)
    r += s[i];
  return r;
}

class Solution {
public:
  string addBinary(const string &a, const string &b) {
    string ans;
    ans.reserve(max(a.length(), b.length()));
    int ia = a.length() - 1;
    int ib = b.length() - 1;
    int carry = 0;
    while (ia >= 0 || ib >= 0 || carry != 0) {
      int va = ia >= 0 ? a[ia] - '0' : 0;
      int vb = ib >= 0 ? b[ib] - '0' : 0;
      int sum = va + vb + carry;
      ans += to_string(sum % 2);
      carry = floor(sum / 2);
      ia--;
      ib--;
    }
    return reverseString(ans);
  }
};

int main() {
  cout << "Solution: " << Solution().addBinary("11", "1") << endl;
  return 0;
}
