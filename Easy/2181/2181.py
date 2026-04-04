# 2181. Merge Nodes in Between Zeros
# You are given the head of a linked list, which
# contains a series of integers separated by 0's.
# The beginning and end of the linked list will
# have Node.val == 0.
# For every two consecutive 0's, merge all the
# nodes lying in between them into a single node
# whose value is the sum of all the merged nodes.
# The modified list should not contain any 0's.
# Return the head of the modified linked list.

from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: Optional[ListNode] = None):
        self.val = val
        self.next = next

    def __str__(self):
        curr = self
        elements = []
        while curr is not None:
            elements.append(str(curr.val))
            curr = curr.next
        return "\t".join(elements)


def create_linked_list(elements: list[int]) -> Optional[ListNode]:
    dummy = ListNode()
    curr = dummy
    for i in elements:
        curr.next = ListNode(i)
        curr = curr.next
    return dummy.next


class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        curr1 = head.next
        dummy = ListNode()
        curr2 = dummy
        total = 0
        while curr1 is not None:
            total += curr1.val
            if curr1.val == 0:
                curr2.next = ListNode(total)
                curr2 = curr2.next
                total = 0
            curr1 = curr1.next

        return dummy.next


head = create_linked_list([0, 3, 1, 0, 4, 5, 2, 0])
result = Solution().mergeNodes(head)
print(head)
print(result)
