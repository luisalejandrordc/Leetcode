#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int highest = 0;
    for (int i = 0; i < s.size() - highest; i++) {
      unordered_map<char, int> letters;
      int count = 0;
      for (int j = i; j < s.size(); j++) {
        letters[s[j]]++;
        if (letters[s[j]] > 1)
          break;
        else
          count++;
      }
      if (count > highest) {
        highest = count;
      }
    }
    return highest;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  string s = "abcabcbb";
  cout << "Solution: " << Solution().lengthOfLongestSubstring(s) << endl;
  return 0;
}
