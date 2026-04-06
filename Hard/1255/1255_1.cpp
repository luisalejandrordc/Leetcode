#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

vector<int> countWordLetters(const string &word) {
  vector<int> freq(26, 0);
  for (char c : word)
    freq[c - 'a']++;
  return freq;
}
vector<vector<int>> getNewWords(const vector<string> &words) {
  vector<vector<int>> newWords;
  newWords.reserve(words.size());
  for (string w : words)
    newWords.push_back(countWordLetters(w));
  return newWords;
}

vector<int> getNewLetters(const vector<char> &letters) {
  string word;
  word.reserve(letters.size());
  for (char c : letters)
    word += c;
  return countWordLetters(word);
}

bool isValidWord(const vector<int> &word, const vector<int> &letters) {
  for (int i = 0; i < 26; i++)
    if (word[i] > letters[i])
      return false;
  return true;
}

int getWordScore(const vector<int> &word, const vector<int> &score) {
  int wordScore = 0;
  for (int i = 0; i < 26; i++)
    wordScore += word[i] * score[i];
  return wordScore;
}

int dfs(int i, vector<vector<int>> &words, vector<int> &letters,
        vector<int> &score) {
  if (i == words.size())
    return 0;

  int maxScore = dfs(i + 1, words, letters, score);
  int wordScore = getWordScore(words[i], score);

  if (isValidWord(words[i], letters)) {
    for (int j = 0; j < 26; j++)
      letters[j] -= words[i][j];

    maxScore = max(maxScore, wordScore + dfs(i + 1, words, letters, score));

    for (int j = 0; j < 26; j++) // backtrack
      letters[j] += words[i][j];
  }

  return maxScore;
}

class Solution {
public:
  int maxScoreWords(vector<string> &words, vector<char> &letters,
                    vector<int> &score) {
    vector<vector<int>> newWords = getNewWords(words);
    vector<int> newLetters = getNewLetters(letters);
    return dfs(0, newWords, newLetters, score);
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
