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

ListNode *arrayToLinkedList(vector<int> &nums) {
  ListNode *dummy = new ListNode();
  ListNode *curr = dummy;
  for (int &n : nums) {
    curr->next = new ListNode(n);
    curr = curr->next;
  }
  return dummy->next;
}

void printLinkedList(ListNode *head) {
  ListNode *curr = head;
  cout << "[";
  while (curr != nullptr) {
    cout << curr->val;
    curr = curr->next;
    if (curr != nullptr)
      cout << "\t";
  }
  cout << "]" << endl;
}

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *reversed = nullptr;
    ListNode *curr = head;
    while (curr != nullptr) {
      reversed = new ListNode(curr->val, reversed);
      curr = curr->next;
    }
    return reversed;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  vector<int> nums = {1, 2, 3, 4, 5};
  ListNode *head = arrayToLinkedList(nums);
  printLinkedList(head);
  ListNode *reversed = Solution().reverseList(head);
  printLinkedList(reversed);
  return 0;
}
