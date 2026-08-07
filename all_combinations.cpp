#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> getNCombinations(vector<char> &letters, int n) {
  vector<string> combinations, base;
  if (n == 1) {
    for (char c : letters)
      combinations.push_back(string(1, c));
    return combinations;
  } else
    base = getNCombinations(letters, n - 1);
  for (string s : base) {
    int idx = 0;
    char c = s.back();
    while (c != letters[idx])
      idx++;
    idx++;
    while (idx < letters.size()) {
      string ns = s;
      ns += letters[idx];
      combinations.push_back(ns);
      idx++;
    }
  }
  return combinations;
}

vector<string> getAllCombinations(vector<char> &letters) {
  vector<string> combinations;
  for (int n = 1; n <= letters.size(); n++) {
    for (string s : getNCombinations(letters, n))
      combinations.push_back(s);
  }
  return combinations;
}

int main() {
  cout << "All Posible Non-Empty Combinations" << endl;
  vector<char> letters = {'A', 'B', 'C', 'D'};
  vector<string> combinations = getNCombinations(letters, 3);
  for (string s : combinations)
    cout << s << endl;
  return 0;
}
