#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *arrayToLinkedList(vector<int> &nums, bool cycle) {
  ListNode *dummy = new ListNode();
  ListNode *curr = dummy;
  for (int &n : nums) {
    curr->next = new ListNode(n);
    curr = curr->next;
  }
  if (cycle)
    curr->next = dummy->next;
  return dummy->next;
}

class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *curr = head;
    unordered_set<ListNode *> nodes;
    while (curr != nullptr) {
      if (nodes.count(curr))
        return true;
      nodes.insert(curr);
      curr = curr->next;
    }
    return false;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  Solution s;
  vector<int> nums = {1, 2, 3, 4, 5};
  ListNode *head1 = arrayToLinkedList(nums, false);
  cout << "Has Cycle: " << s.hasCycle(head1) << endl;
  ListNode *head2 = arrayToLinkedList(nums, true);
  cout << "Has Cycle: " << s.hasCycle(head2) << endl;
  return 0;
}
