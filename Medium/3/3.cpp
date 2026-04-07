#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// class Solution {
// public:
//   int lengthOfLongestSubstring(string s) {
//     int highest = 0;
//     for (int i = 0; i < s.size() - highest; i++) {
//       unordered_map<char, int> letters;
//       int count = 0;
//       for (int j = i; j < s.size(); j++) {
//         letters[s[j]]++;
//         if (letters[s[j]] > 1)
//           break;
//         else
//           count++;
//       }
//       if (count > highest) {
//         highest = count;
//       }
//     }
//     return highest;
//   }
// };

// int getIndex(const vector<char> &chars, const char &x) {
//   int idx = -1;
//   for (int i = 0; i < chars.size(); i++)
//     if (chars[i] == x) {
//       if (idx != -1)
//         return idx;
//       idx = i;
//     }
//   return -1;
// }
//
// class Solution {
// public:
//   int lengthOfLongestSubstring(string s) {
//     int highest = 0;
//     vector<char> chars;
//     for (int i = 0; i < s.size() - (highest - chars.size()); i++) {
//       chars.push_back(s[i]);
//       int idx = getIndex(chars, s[i]);
//       if (idx == -1) {
//         if (chars.size() > highest)
//           highest = chars.size();
//       } else {
//         if (chars.size() - 1 > highest)
//           highest = chars.size() - 1;
//         chars.erase(chars.begin(), chars.begin() + idx + 1);
//       }
//     }
//     return highest;
//   }
// };

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> visited;
    int l = 0, highest = 0;
    for (int r = 0; r < s.size(); r++) {
      if (visited.count(s[r]) && visited[s[r]] >= l) {
        l = visited[s[r]] + 1;
      }
      visited[s[r]] = r;
      highest = max(highest, r - l + 1);
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
