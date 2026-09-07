#pragma oncea

struct DListNode {
  int val;
  DListNode *next;
  DListNode *prev;

  DListNode() : val(0), next(nullptr), prev(nullptr) {}
  DListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};
