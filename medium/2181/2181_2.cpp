#include "../../include/doubly_linked_list.h"
#include "../../include/singly_linked_list.h"
#include "../../include/utils.h"
#include <vector>

// class Solution {
//   public
// }

int main() {
  printTitle("Merge Nodes in Between Zero");
  std::vector<int> nums = {1, 2, 3, 4};
  ListNode *head = toLinkedList(nums);
  std::vector<int> my_nums = head->toVector();
  print(my_nums);
  head->print();

  std::vector<int> nums2 = {2, 4, 6, 8};
  DListNode *my_head = toDLinkedList(nums2);
  DListNode *curr = my_head;
  my_head->print();
  while (curr->next != nullptr)
    curr = curr->next;
  curr->print(false);
  return 0;
}
