#include <cstdlib>
#include <iostream>

using namespace std;

class Solution {
public:
  int scoreOfString(string s) {
    int score = 0;
    for (int i = 0; i < s.size() - 1; i++)
      score += abs(int(s[i]) - int(s[i + 1]));
    return score;
  }
};

int main() {
  cout << "Solution: " << Solution().scoreOfString("zaaz") << endl;
  return 0;
}
