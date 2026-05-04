#include <iostream>
#include <vector>

using namespace std;

int getMinLength(vector<string> &words) {
  int minLength = INT_MAX;
  for (string s : words)
    minLength = min(minLength, int(s.length()));
  return minLength;
}

class Solution {
public:
  string longestCommonPrefix(vector<string> &words) {
    if (words.size() == 1)
      return words[0];
    string s = "";
    int minLength = getMinLength(words);
    for (int i = 0; i < minLength; i++) {
      for (int j = 1; j < words.size(); j++)
        if (words[j][i] != words[j - 1][i])
          return s;
      s += words[0][i];
    }
    return s;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  Solution s;
  vector<string> strs = {"flower", "flow", "flight"};
  cout << "Solution: " << s.longestCommonPrefix(strs) << endl;
  strs = {"keys", "keyboard", "keywords"};
  cout << "Solution: " << s.longestCommonPrefix(strs) << endl;
  strs = {"dog", "racecar", "car"};
  cout << "Solution: " << s.longestCommonPrefix(strs) << endl;
  return 0;
}
