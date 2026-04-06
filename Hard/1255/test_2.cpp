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

class Solution {
public:
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

  int maxScoreWords(vector<string> &words, vector<char> &letters,
                    vector<int> &score) {
    vector<vector<int>> newWords = getNewWords(words);
    vector<int> newLetters = getNewLetters(letters);
    return dfs(0, newWords, newLetters, score);
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  vector<string> words = {"e", "bac", "baeba", "eb", "bbbbd", "cad", "c", "c"};
  vector<char> letters = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'b', 'b', 'b',
                          'b', 'b', 'b', 'c', 'c', 'c', 'c', 'c', 'c', 'd',
                          'd', 'd', 'd', 'd', 'd', 'd', 'e', 'e', 'e', 'e'};
  vector<int> score = {8, 4, 6, 8, 5, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  auto start = chrono::high_resolution_clock::now();
  cout << "Solution: " << Solution().maxScoreWords(words, letters, score)
       << endl;
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> duration = end - start;
  cout << "Function took " << duration.count() << " ms to execute." << endl;
  return 0;
}
