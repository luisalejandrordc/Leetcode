#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_set<char> openBrackets = {'(', '[', '{'};
unordered_map<char, char> closeToOpen = {{')', '('}, {']', '['}, {'}', '{'}};

class Solution {
public:
  bool isValid(string s) {
    // Last open bracket must be the first to be closed (LIFO)
    stack<char> history;
    for (char c : s) {
      if (openBrackets.count(c))
        history.push(c);
      else {
        if (history.empty() || history.top() != closeToOpen[c])
          return false;
        history.pop();
      }
    }
    return history.empty() ? true : false;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  Solution s;
  cout << "Solution: " << s.isValid("()") << endl;
  cout << "Solution: " << s.isValid("()[]{}") << endl;
  cout << "Solution: " << s.isValid("(]") << endl;
  cout << "Solution: " << s.isValid("([])") << endl;
  cout << "Solution: " << s.isValid("([)]") << endl;
  return 0;
}
