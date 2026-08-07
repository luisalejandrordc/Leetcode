#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

vector<int> getNewLetters(vector<char> &letters) {
  vector<int> newLetters(26, 0);
  for (char c : letters)
    newLetters[c - 'a']++;
  return newLetters;
}

void restoreLetters(string word, vector<int> &letters) {
  for (char c : word) {
    int idx = c - 'a';
    letters[idx]++;
  }
}

int getWordScore(string word, vector<int> &letters, vector<int> &score) {
  int wScore = 0;
  for (int i = 0; i < word.length(); i++) {
    int idx = word[i] - 'a';
    if (letters[idx] == 0) {
      if (i != 0)
        restoreLetters(word.substr(0, i), letters);
      return 0;
    }
    letters[idx]--;
    wScore += score[idx];
  }
  return wScore;
}

int getMaxScoreWords(vector<string> &words, int start, vector<int> &letters,
                     vector<int> &score) {
  if (words.empty())
    return 0;
  int maxScore = 0;
  for (int i = start; i < words.size(); i++) {
    string w = words[i];
    int currentScore = getWordScore(w, letters, score);
    if (currentScore != 0) {
      words.erase(words.begin() + i);
      currentScore += getMaxScoreWords(words, i, letters, score);
      words.insert(words.begin() + i, w);
      restoreLetters(w, letters);
      maxScore = max(maxScore, currentScore);
    }
  }
  return maxScore;
}

class Solution {
public:
  int maxScoreWords(vector<string> &words, vector<char> &letters,
                    vector<int> &score) {
    vector<int> newLetters = getNewLetters(letters);
    return getMaxScoreWords(words, 0, newLetters, score);
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;

  vector<string> words = {"daeagfh", "acchggghfg", "feggd",
                          "fhdch",   "dbgadcchfg", "b",
                          "db",      "fgchfe",     "baaedddc"};
  vector<char> letters = {
      'a', 'a', 'a', 'a', 'a', 'a', 'a', 'b', 'b', 'b', 'b', 'b', 'b',
      'b', 'b', 'b', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c',
      'c', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd',
      'd', 'd', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'f',
      'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f',
      'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'h',
      'h', 'h', 'h', 'h', 'h', 'h', 'h', 'h', 'h', 'h', 'h', 'h'};
  vector<int> score = {2, 1, 9, 2, 10, 5, 7, 8, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0};

  auto start = chrono::high_resolution_clock::now();
  cout << "Solution: " << Solution().maxScoreWords(words, letters, score)
       << endl;
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> elapsedTime = end - start;
  cout << "Elapsed Time: " << elapsedTime.count() << " ms" << endl;

  return 0;
}
