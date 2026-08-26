#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const unordered_map<char, vector<char>> KEYS = {
    {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}},
};

void printVector(vector<string> &words) {
  for (string w : words) {
    cout << w << endl;
  }
}

vector<string> recs(string digits) {
  if (digits.length() == 1)
    return {};
  for (char c : digits)
}

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    return {"Hello", "World"};
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  cout << "Solution:" << endl;
  vector<string> words = Solution().letterCombinations("23");
  printVector(words);
}
