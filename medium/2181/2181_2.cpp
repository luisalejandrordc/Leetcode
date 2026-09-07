#include "../../include/singly_linked_list.h"
#include "../../include/utils.h"
#include <vector>

// class Solution {
//   public
// }

int main() {
  printTitle("Merge Nodes in Between Zero");
  std::vector<int> nums = {1, 2, 3, 4};
  ListNode *head = createLinkedList(nums);
  std::vector<int> my_nums = head->toVector();
  print(my_nums);
  head->print();
  return 0;
}
