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
  for (int x : nums) {
    curr->next = new ListNode(x);
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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *curr1 = list1;
    ListNode *curr2 = list2;
    ListNode *dummy = new ListNode();
    ListNode *curr = dummy;
    while (curr1 != nullptr && curr2 != nullptr) {
      if (curr1->val <= curr2->val) {
        curr->next = new ListNode(curr1->val);
        curr1 = curr1->next;
      } else {
        curr->next = new ListNode(curr2->val);
        curr2 = curr2->next;
      }
      curr = curr->next;
    }
    while (curr1 != nullptr) {
      curr->next = new ListNode(curr1->val);
      curr1 = curr1->next;
      curr = curr->next;
    }
    while (curr2 != nullptr) {
      curr->next = new ListNode(curr2->val);
      curr2 = curr2->next;
      curr = curr->next;
    }
    return dummy->next;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  vector<int> nums1 = {1, 2, 4};
  ListNode *list1 = arrayToLinkedList(nums1);
  vector<int> nums2 = {1, 3, 4};
  ListNode *list2 = arrayToLinkedList(nums2);
  ListNode *solution = Solution().mergeTwoLists(list1, list2);
  printLinkedList(solution);
  return 0;
}
