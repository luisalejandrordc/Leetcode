// 2. Add Two Numbers
// You are given two non-empty linked lists representing two
// non-negative integers. The digits are stored in reverse
// order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading
// zero, except the number 0 itself.

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

// class Solution {
// public:
//   ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
//     ListNode *head = new ListNode();
//     ListNode *curr = head;
//     int carry = 0;
//     while (l1 != nullptr || l2 != nullptr || carry != 0) {
//       if (l1) {
//         curr->val += l1->val;
//         l1 = l1->next;
//       }
//       if (l2) {
//         curr->val += l2->val;
//         l2 = l2->next;
//       }
//       curr->val += carry;
//       if (curr->val >= 10) {
//         curr->val = curr->val - 10;
//         carry = 1;
//       } else {
//         carry = 0;
//       }
//       if (l1 != nullptr || l2 != nullptr || carry != 0) {
//         curr->next = new ListNode();
//       }
//       curr = curr->next;
//     }
//     return head;
//   }
// };

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode();
    ListNode *curr = dummy;
    int sum = 0, carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
      sum = carry;
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }
      if (sum >= 10) {
        sum = sum - 10;
        carry = 1;
      } else {
        carry = 0;
      }
      curr->next = new ListNode(sum);
      curr = curr->next;
    }
    return dummy->next;
  }
};

ListNode *create_linked_list(vector<int> elements) {
  if (elements.empty())
    return nullptr;
  ListNode *head = new ListNode(elements[0]);
  ListNode *curr = head;
  for (int i = 1; i < elements.size(); i++) {
    curr->next = new ListNode(elements[i]);
    curr = curr->next;
  }
  return head;
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

  ListNode *l1 = create_linked_list({9, 9, 9, 9, 9, 9, 9});
  ListNode *l2 = create_linked_list({9, 9, 9, 9});

  print_linked_list(l1);
  print_linked_list(l2);

  Solution s;
  print_linked_list(s.addTwoNumbers(l1, l2));

  return 0;
}
