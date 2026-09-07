#pragma once
#include <iostream>
#include <iterator>
#include <vector>

struct ListNode {
  int val;

  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *n) : val(x), next(n) {}

  void print() {
    ListNode *curr = this;
    std::cout << "[";
    while (curr != nullptr) {
      if (curr != this)
        std::cout << ", ";
      std::cout << curr->val;
      curr = curr->next;
    }
    std::cout << "]" << std::endl;
  }

  std::vector<int> toVector() {
    ListNode *curr = this;
    std::vector<int> nums;
    while (curr != nullptr) {
      nums.push_back(curr->val);
      curr = curr->next;
    }
    return nums;
  }
};

template <std::ranges::input_range Range>
  requires std::same_as<std::ranges::range_value_t<Range>, int>
inline ListNode *createLinkedList(const Range &values) {
  ListNode *dummy = new ListNode();
  ListNode *curr = dummy;
  for (const int &x : values) {
    curr->next = new ListNode(x);
    curr = curr->next;
  }
  return dummy->next;
}
