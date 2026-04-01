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
    def __init__(self, val: int = 0, next: Optional[ListNode] = None):
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


class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummy = ListNode()
        curr = dummy
        total, carry = 0, 0
        while l1 is not None or l2 is not None or carry != 0:
            total = 0
            if l1:
                total += l1.val
                l1 = l1.next
            if l2:
                total += l2.val
                l2 = l2.next
            total += carry
            if total >= 10:
                total -= 10
                carry = 1
            else:
                carry = 0
            curr.next = ListNode(total)
            curr = curr.next
        return dummy.next


def create_linked_list(elements: list[int]) -> ListNode | None:
    dummy = ListNode()
    curr = dummy
    for x in elements:
        curr.next = ListNode(x)
        curr = curr.next
    return dummy.next


l1 = create_linked_list([9, 9, 9, 9, 9, 9, 9])
l2 = create_linked_list([9, 9, 9, 9])
print(l1)
print(l2)
print(Solution().addTwoNumbers(l1, l2))
