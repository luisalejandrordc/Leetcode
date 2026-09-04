#include "include/singly_linked_list.h"
#include "include/utils.h"
#include <iostream>
#include <optional>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

int main() {
  std::cout << "Hello, World!" << std::endl;
  std::vector<std::optional<int>> nums = {1, 2, std::nullopt, 4, 5};
  std::pair<int, int> p = {1, 2};
  std::unordered_map<int, int> map;
  std::unordered_set<int> set;
  map[1] = 10;
  map[2] = 20;
  map[3] = 30;
  set.insert(3);
  set.insert(11);
  set.insert(2004);
  set.insert(2004);
  print(p);
  print(nums);
  print(map);
  print(set);
  print("hello");
  return 0;
}
