#include "../../include/utils.h"
#include <functional>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int recs(vector<int> &coins, int idx, int amount,
         unordered_map<pair<int, int>, int, PairHash<int, int>> &history) {
  int quantity = amount / coins[idx];
  int remainder = amount - quantity * coins[idx];
  if (remainder == 0)
    return quantity;
  if (idx == coins.size() - 1)
    return -1;
  int result = INT_MAX;
  while (quantity >= 0) {
    pair<int, int> next = {idx + 1, remainder};
    if (!history.count(next))
      history[next] = recs(coins, next.first, next.second, history);
    if (history.at(next) != -1)
      result = min(result, history.at(next) + quantity);
    remainder += coins[idx];
    quantity--;
  }
  return result == INT_MAX ? -1 : result;
}

int coinChange(vector<int> &coins, int amount) {
  sort(coins.begin(), coins.end(), greater<>());
  unordered_map<pair<int, int>, int, PairHash<int, int>> history;
  return recs(coins, 0, amount, history);
}

// This solution is technically correct, it scans all possible ways
// to make up the given amount, but it takes too much time, because
// of multiple repetitions of recursion states instead of saving
// those previous results and resuing them
int recs3(vector<int> &coins, int idx, int amount) {
  int quantity = amount / coins[idx];
  int remainder = amount - quantity * coins[idx];
  if (remainder == 0)
    return quantity;
  if (idx == coins.size() - 1)
    return -1;
  int result = INT_MAX;
  while (quantity >= 0) {
    int counter = recs3(coins, idx + 1, remainder);
    if (counter != -1)
      result = min(result, counter + quantity);
    remainder += coins[idx];
    quantity--;
  }
  return result == INT_MAX ? -1 : result;
}

int coinChange3(vector<int> &coins, int amount) {
  sort(coins.begin(), coins.end(), greater<>());
  return recs3(coins, 0, amount);
}

// This greedy solution has a problem: using as many of the largest coin
// as possible does not mean you'll get the most optimal result (minimum)
// Example: coins = {4, 3, 1}, amount = 6 -> Expected result = 2
int recs2(vector<int> &coins, int idx, int amount) {
  int quantity = amount / coins[idx];
  int remainder = amount - quantity * coins[idx];
  if (remainder == 0)
    return quantity;
  if (idx == coins.size() - 1)
    return -1;
  while (quantity >= 0) {
    int counter = recs2(coins, idx + 1, remainder);
    if (counter != -1)
      return counter + quantity;
    remainder += coins[idx];
    quantity--;
  }
  return -1;
}

int coinChange2(vector<int> &coins, int amount) {
  sort(coins.begin(), coins.end(), greater<>());
  return recs2(coins, 0, amount);
}

// This solution does not consider all possible ways to make up the amount
// It is restricted by taking away the largest coins from amount without
// considering that maybe taking less or even none of them could end up
// making up the amount successfully
int coinChange1(vector<int> &coins, int amount) {
  sort(coins.begin(), coins.end(), greater<>());
  int counter = 0;
  for (const int coin : coins)
    while (amount >= coin) {
      amount -= coin;
      counter++;
    }
  return amount == 0 ? counter : -1;
}

int main() {
  printTitle("Coin Change");
  vector<int> coins = {288, 160, 10, 249, 40, 77, 314, 429};
  int amount = 9208;
  cout << "Solution: " << coinChange(coins, amount) << endl;

  return 0;
}
