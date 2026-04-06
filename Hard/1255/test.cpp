#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<char, int> countWordLetters(const string &word) {
  unordered_map<char, int> freq;
  for (char c : word)
    freq[c]++;
  return freq;
}

string joinLetters(const vector<char> &letters) {
  string word;
  word.reserve(letters.size());
  for (char c : letters)
    word += c;
  return word;
}

vector<unordered_map<char, int>>
reduceWords(vector<unordered_map<char, int>> &words,
            unordered_map<char, int> &letters) {
  vector<unordered_map<char, int>> validWords;
  for (int i = 0; i < words.size(); i++) {
    bool valid = true;
    for (const auto &pair : words[i])
      if (pair.second > letters[pair.first]) {
        valid = false;
        break;
      }
    if (valid) {
      validWords.push_back(words[i]);
    }
  }
  return validWords;
}

unordered_map<char, int> reduceLetters(const unordered_map<char, int> &used,
                                       unordered_map<char, int> available) {
  for (const auto &pair : used)
    available[pair.first] -= pair.second;
  return available;
}

int getWordScore(unordered_map<char, int> &word, vector<int> &score) {
  int wScore = 0;
  for (const auto &pair : word) {
    int idx = int(pair.first) - 97;
    wScore += score[idx] * pair.second;
  }
  return wScore;
}

int recs(vector<unordered_map<char, int>> words,
         unordered_map<char, int> letters, vector<int> &score) {
  words = reduceWords(words, letters);
  if (words.empty()) {
    return 0;
  }
  int highest = 0;
  for (int i = 0; i < words.size(); i++) {
    int wScore = getWordScore(words[i], score);
    vector<unordered_map<char, int>> newWords = words;
    newWords.erase(newWords.begin() + i);
    unordered_map<char, int> newLetters = reduceLetters(words[i], letters);
    int myScore = wScore + recs(newWords, newLetters, score);
    if (myScore > highest)
      highest = myScore;
  }
  return highest;
}

class Solution {
public:
  int maxScoreWords(vector<string> &words, vector<char> &letters,
                    vector<int> &score) {
    int highest = 0;
    vector<unordered_map<char, int>> newWords;
    for (int i = 0; i < words.size(); i++)
      newWords.push_back(countWordLetters(words[i]));
    unordered_map<char, int> newLetters;
    newLetters = countWordLetters(joinLetters(letters));
    return recs(newWords, newLetters, score);
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
  words = {"daeagfh", "acchggghfg", "feggd",  "fhdch",   "dbgadcchfg",
           "b",       "db",         "fgchfe", "baaedddc"};
  letters = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'b', 'b', 'b', 'b', 'b', 'b',
             'b', 'b', 'b', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c',
             'c', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd',
             'd', 'd', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'f',
             'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f',
             'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'h',
             'h', 'h', 'h', 'h', 'h', 'h', 'h', 'h', 'h', 'h', 'h', 'h'};
  score = {2, 1, 9, 2, 10, 5, 7, 8, 0, 0, 0, 0, 0,
           0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0};
  auto start = chrono::high_resolution_clock::now();
  cout << "Solution: " << Solution().maxScoreWords(words, letters, score)
       << endl;
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> duration = end - start;
  cout << "Function took " << duration.count() << " ms to execute." << endl;
  return 0;
}
