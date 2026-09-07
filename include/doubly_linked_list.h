#include <ranges>
#include <stdexcept>
#include <utility>
#include <vector>
#pragma oncea
#include <iostream>

struct DListNode {
  int val;
  DListNode *next;
  DListNode *prev;

  DListNode() : val(0), next(nullptr), prev(nullptr) {}
  DListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
  DListNode(int x, DListNode *n, DListNode *p) : val(x), next(n), prev(p) {}

  void print(bool moveForward = true) {
    DListNode *curr = this;
    std::cout << "[";
    while (curr != nullptr) {
      if (curr != this)
        std::cout << ", ";
      std::cout << curr->val;
      curr = moveForward ? curr->next : curr->prev;
    }
    std::cout << "]" << std::endl;
  }

  std::vector<int> toVector(bool moveForward = true) {
    DListNode *curr = this;
    std::vector<int> nums;
    while (curr != nullptr) {
      nums.push_back(curr->val);
      curr = moveForward ? curr->next : curr->prev;
    }
    return nums;
  }
};

template <std::ranges::input_range Range>
DListNode *toDLinkedList(const Range &values) {
  DListNode *dummy = new DListNode();
  DListNode *curr = dummy;
  for (const int &x : values) {
    curr->next = new DListNode(x, nullptr, curr);
    curr = curr->next;
  }
  if (dummy->next != nullptr)
    dummy->next->prev = nullptr;
  return dummy->next;
}
