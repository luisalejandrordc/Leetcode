#pragma once

#include <iterator>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *n) : val(x), next(n) {}
};

template <std::ranges::input_range Range>
  requires std::same_as<std::ranges::range_value_t<Range>, int>
inline ListNode *toLinkedList(const Range &values) {
  ListNode *dummy = new ListNode();
  ListNode *curr = dummy;
  for (const int &x : values) {
    curr->next = new ListNode(x);
    curr = curr->next;
  }
  return dummy->next;
}
