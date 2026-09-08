#pragma once
#include <complex>
#include <filesystem>
#include <iostream>
#include <optional>
#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *l, TreeNode *r) : val(0), left(l), right(r) {}

  void print() {
    std::cout << "[";
    std::queue<TreeNode *> nodes;
    nodes.push(this);
    int realNodes = 1;
    while (realNodes > 0) {
      TreeNode *curr = nodes.front();
      if (curr != this)
        std::cout << ", ";
      if (curr == nullptr) {
        std::cout << "null";
        nodes.push(nullptr);
        nodes.push(nullptr);
      } else {
        realNodes--;
        std::cout << curr->val;
        nodes.push(curr->left);
        nodes.push(curr->right);
        if (curr->left != nullptr)
          realNodes++;
        if (curr->right != nullptr)
          realNodes++;
      }
      nodes.pop();
    }
    std::cout << "]" << std::endl;
  }

  std::vector<std::optional<int>> toVector() {
    std::vector<std::optional<int>> nums;
    std::queue<TreeNode *> nodes;
    int realNodes = 1;
    nodes.push(this);
    while (realNodes > 0) {
      TreeNode *curr = nodes.front();
      if (curr == nullptr) {
        nums.push_back(std::nullopt);
        nodes.push(nullptr);
        nodes.push(nullptr);
      } else {
        realNodes--;
        nums.push_back(curr->val);
        nodes.push(curr->left);
        nodes.push(curr->right);
        if (curr->left != nullptr)
          realNodes++;
        if (curr->right != nullptr)
          realNodes++;
      }
      nodes.pop();
    }
    return nums;
  }
};

inline TreeNode *toBinaryTree(const std::vector<std::optional<int>> &nums) {
  if (nums.empty() || !nums[0].has_value())
    return nullptr;
  TreeNode *root = new TreeNode(*nums[0]);
  std::queue<TreeNode *> nodes;
  nodes.push(root);
  bool onLeft = true;
  for (auto it = nums.begin() + 1; it < nums.end(); it++) {
    TreeNode *curr = nodes.front();
    if (onLeft) {
      curr->left = it->has_value() ? new TreeNode(**it) : nullptr;
      nodes.push(curr->left);
    } else {
      curr->right = it->has_value() ? new TreeNode(**it) : nullptr;
      nodes.push(curr->right);
      nodes.pop();
    }
    onLeft = !onLeft;
  }
  return root;
}
