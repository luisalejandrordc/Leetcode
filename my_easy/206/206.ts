export {};

class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

function arrayToLinkedList(nums: number[]): ListNode | null {
  let dummy = new ListNode();
  let curr = dummy;
  for (const n of nums) {
    curr.next = new ListNode(n);
    curr = curr.next;
  }
  return dummy.next;
}

function printLinkedList(head: ListNode | null) {
  let curr: ListNode | null = head;
  let array: number[] = [];
  while (curr !== null) {
    array.push(curr.val);
    curr = curr.next;
  }
  console.log(array);
}

function reverseList(head: ListNode | null): ListNode | null {
  let reversed: ListNode | null = null;
  let curr: ListNode | null = head;
  while (curr !== null) {
    reversed = new ListNode(curr.val, reversed);
    curr = curr.next;
  }
  return reversed;
}

console.log("It's Showtime Folks!");

const nums = [1, 2, 3, 4, 5];
const head = arrayToLinkedList(nums);
printLinkedList(head);
const reversed = reverseList(head);
printLinkedList(reversed);
