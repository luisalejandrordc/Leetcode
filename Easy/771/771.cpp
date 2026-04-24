#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int numJewelsInStones(const string &jewels, const string &stones) {
    unordered_set<char> set;
    for (char c : jewels)
      set.insert(c);
    int count = 0;
    for (char c : stones) {
      if (set.count(c))
        count++;
    }
    return count;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  Solution s;
  cout << "Solution: " << s.numJewelsInStones("aA", "aAAbbbb") << endl;
  cout << "Solution: " << s.numJewelsInStones("z", "ZZ") << endl;
  return 0;
}
