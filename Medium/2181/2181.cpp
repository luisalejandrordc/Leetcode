// 2181. Merge Nodes in Between Zeros
// You are given the head of a linked list, which
// contains a series of integers separated by 0's.
// The beginning and end of the linked list will
// have Node.val == 0.
// For every two consecutive 0's, merge all the
// nodes lying in between them into a single node
// whose value is the sum of all the merged nodes.
// The modified list should not contain any 0's.
// Return the head of the modified linked list.

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeNodes(ListNode *head) {
    ListNode *curr1 = head->next;
    ListNode *dummy = new ListNode();
    ListNode *curr2 = dummy;
    int sum = 0;
    while (curr1 != nullptr) {
      if (curr1->val == 0) {
        curr2->next = new ListNode(sum);
        curr2 = curr2->next;
        sum = 0;
      } else {
        sum += curr1->val;
      }
      curr1 = curr1->next;
    }
    return dummy->next;
  }
};

ListNode *create_linked_list(vector<int> elements) {
  ListNode *dummy = new ListNode();
  ListNode *curr = dummy;
  for (int i = 0; i < elements.size(); i++) {
    curr->next = new ListNode(elements[i]);
    curr = curr->next;
  }
  return dummy->next;
}

void print_linked_list(ListNode *head) {
  ListNode *curr = head;
  while (curr != nullptr) {
    cout << curr->val << "\t";
    curr = curr->next;
  }
  cout << endl;
}

int main() {
  cout << "It's showtime folks!" << endl;
  ListNode *input = create_linked_list({0, 3, 1, 0, 4, 5, 2, 0});
  ListNode *output = Solution().mergeNodes(input);
  print_linked_list(input);
  print_linked_list(output);
  return 0;
}
