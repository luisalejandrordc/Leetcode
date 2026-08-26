#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(const vector<int> &prices) {
    int maxPro = 0;
    int minPri = prices[0];
    for (int price : prices) {
      minPri = min(minPri, price);
      maxPro = max(maxPro, price - minPri);
    }
    return maxPro;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  Solution s;
  cout << "Solution: " << s.maxProfit({7, 1, 5, 3, 6, 4}) << endl;
  return 0;
}
