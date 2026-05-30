// 1255. Maximum Score Words Formed by Letters
// Given a list of words, list of  single letters
// (might be repeating) and score of every character.
// Return the maximum score of any valid set of
// words formed by using the given letters (words[i]
// cannot be used two or more times).
// It is not necessary to use all characters in
// letters and each letter can only be used once.
// Score of letters 'a', 'b', 'c', ... ,'z' is given
// by score[0], score[1], ... , score[25] respectively.

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void print_letters_ascii() {
  string let = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < let.length(); i++) {
    cout << int(let[i]) << endl;
  }
}

void print_unordered_map(unordered_map<char, int> &map) {
  for (const auto &pair : map) {
    cout << pair.first << " - " << pair.second << endl;
  }
}
void print_unordered_map(unordered_map<string, int> &map) {
  for (const auto &pair : map) {
    cout << pair.first << " - " << pair.second << endl;
  }
}

unordered_map<char, int> get_word_letters(string &word) {
  unordered_map<char, int> map;
  for (int i = 0; i < word.length(); i++) {
    map[word[i]]++;
  }
  return map;
}

vector<string> get_subsets(vector<string> elements, int k) {
  if (k == 1) {
    return elements;
  }
  vector<string> result, subsets;
  vector<string> new_elements = elements;
  for (int i = 0; i <= elements.size() - k; i++) {
    new_elements.erase(new_elements.begin());
    subsets = get_subsets(new_elements, k - 1);
    for (int j = 0; j < subsets.size(); j++) {
      result.push_back(elements[i] + subsets[j]);
    }
  }
  return result;
}

class Solution {
public:
  int maxScoreWords(vector<string> &words, vector<char> &letters,
                    vector<int> &score) {
    unordered_map<char, int> map;
    for (int i = 0; i < letters.size(); i++) {
      map[letters[i]]++;
    }
    vector<string> all_words, subsets;
    for (int i = 0; i < words.size(); i++) {
      subsets = get_subsets(words, i + 1);
      for (int j = 0; j < subsets.size(); j++) {
        all_words.push_back(subsets[j]);
      }
    }
    unordered_map<string, int> result;
    int max_score = 0;
    for (int i = 0; i < all_words.size(); i++) {
      if (result.count(all_words[i])) {
        continue;
      }
      unordered_map<char, int> word_letters = get_word_letters(all_words[i]);
      for (const auto &pair : word_letters) {
        if (map[pair.first] < pair.second) {
          result[all_words[i]] = 0;
          break;
        }
        result[all_words[i]] += score[int(pair.first - 97)] * pair.second;
      }
      if (max_score < result[all_words[i]]) {
        max_score = result[all_words[i]];
      }
    }
    // print_unordered_map(result);
    return max_score;
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
