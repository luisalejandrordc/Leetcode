#include "../../include/utils.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  vector<int> countLetters(vector<char> &letters) {
    vector<int> foo(26, 0);
    for (char &c : letters)
      foo[c - 'a']++;
    return foo;
  }

  bool canBeFormed(string &word, vector<int> letters) {
    for (char &c : word) {
      if (letters[c - 'a'] == 0)
        return false;
      letters[c - 'a']--;
    }
    return true;
  }

  void removeLetters(string &word, vector<int> &letters) {
    for (char &c : word)
      letters[c - 'a']--;
  }

  void restoreLetters(string &word, vector<int> &letters) {
    for (char &c : word)
      letters[c - 'a']++;
  }

  int getScore(string &word, vector<int> &score) {
    int myScore = 0;
    for (char &c : word)
      myScore += score[c - 'a'];
    return myScore;
  }

  int dfs(vector<string> &words, vector<int> &letters, vector<int> &score,
          int start) {
    // base case
    if (start == words.size())
      return 0;
    // explore remaining words
    int maxScore = 0;
    for (int i = start; i < words.size(); i++) {
      if (canBeFormed(words[i], letters)) {
        int myScore = getScore(words[i], score);
        removeLetters(words[i], letters);
        maxScore = max(maxScore, myScore + dfs(words, letters, score, i + 1));
        restoreLetters(words[i], letters);
      }
    }
    return maxScore;
  }

public:
  int maxScoreWords(vector<string> &words, vector<char> &letters,
                    vector<int> &score) {
    vector<int> newLetters = countLetters(letters);
    return dfs(words, newLetters, score, 0);
  }
};

int main() {
  printTitle("Maximum Score Words Formed By Letters");
  vector<string> words = {"dog", "cat", "dad", "good"};
  vector<char> letters = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
  vector<int> score = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0,
                       0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int out =
      timedCall(&Solution::maxScoreWords, Solution{}, words, letters, score);
  cout << "Output: " << out << endl;
  return 0;
}
