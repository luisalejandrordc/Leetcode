from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: Optional[ListNode] = None):
        self.val = val
        self.next = next


def arrayToLinkedList(nums: list[int]) -> Optional[ListNode]:
    dummy = ListNode()
    curr = dummy
    for n in nums:
        curr.next = ListNode(n)
        curr = curr.next
    return dummy.next


def printLinkedList(head: Optional[ListNode]):
    array = []
    curr = head
    while curr is not None:
        array.append(curr.val)
        curr = curr.next
    print(array)


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        reversed = None
        curr = head
        while curr is not None:
            reversed = ListNode(curr.val, reversed)
            curr = curr.next
        return reversed


print("It's Showtime Folks!")
nums = [1, 2, 3, 4, 5]
head = arrayToLinkedList(nums)
printLinkedList(head)
reversed = Solution().reverseList(head)
printLinkedList(reversed)
