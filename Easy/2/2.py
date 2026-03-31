# 2. Add Two Numbers
# You are given two non-empty linked lists representing two
# non-negative integers. The digits are stored in reverse
# order, and each of their nodes contains a single digit.
# Add the two numbers and return the sum as a linked list.
# You may assume the two numbers do not contain any leading
# zero, except the number 0 itself.

from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __str__(self) -> str:
        elements = []
        node = self
        while True:
            elements.append(str(node.val))
            node = node.next
            if node is None:
                break
        return "\t".join(elements)

    def append(self, val):
        node = self
        while True:
            if node.next is None:
                node.next = val
                return
            node = node.next


class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        result = ListNode(l1.val + l2.val)
        node1 = l1.next
        node2 = l2.next
        add = 0
        while True:
            if node1 is not None and node2 is not None:
                s = node1.val + node2.val
                val = s if s < 10 else s - 10
                result.append(ListNode(val + add))
                add = 0 if s < 10 else 1
                node1 = node1.next
                node2 = node2.next
            elif node1 is None and node2 is not None:
                result.append(ListNode(node2.val + add))
                add = 0
                node2 = node2.next
            elif node2 is None and node1 is not None:
                result.append(ListNode(node1.val + add))
                add = 0
                node1 = node1.next
            else:
                break
        return result


l1 = ListNode(2, ListNode(4, ListNode(3)))
l2 = ListNode(5, ListNode(6, ListNode(4)))
print(Solution().addTwoNumbers(l1, l2))
