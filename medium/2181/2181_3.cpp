#include "../../include/singly_linked_list.h"
#include "../../include/utils.h"
#include <vector>

class Solution {
public:
  ListNode *mergeNodes(ListNode *head) {
    ListNode *dummy = new ListNode();
    ListNode *curr = dummy;
    bool newNode;
    while (head != nullptr) {
      if (head->val != 0) {
        if (newNode) {
          curr->next = head;
          curr = head;
          newNode = false;
        } else
          curr->val += head->val;
      } else
        newNode = true;
      head = head->next;
    }
    curr->next = nullptr;
    return dummy->next;
  }
};

int main() {
  printTitle("Merge Nodes in Between Zeros");
  std::vector<int> nums = {0, 3, 1, 0, 4, 5, 2, 0};
  ListNode *head = toLinkedList(nums);
  ListNode *ans = timedCall(&Solution::mergeNodes, Solution(), head);
  head->print();
  ans->print();
  return 0;
}
