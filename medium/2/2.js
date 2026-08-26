// 2. Add Two Numbers
// You are given two non-empty linked lists representing two
// non-negative integers. The digits are stored in reverse
// order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading
// zero, except the number 0 itself.

class ListNode {
  constructor(val = 0, next = null) {
    this.val = val;
    this.next = next;
  }
}

var addTwoNumbers = function (l1, l2) {
  console.log("It's Showtime Folks");
  dummy = new ListNode();
  curr = dummy;
  let [sum, carry] = [0, 0];
  while (l1 !== null || l2 !== null || carry != 0) {
    sum = carry;
    if (l1) {
      sum += l1.val;
      l1 = l1.next;
    }
    if (l2) {
      sum += l2.val;
      l2 = l2.next;
    }
    if (sum >= 10) {
      sum -= 10;
      carry = 1;
    } else {
      carry = 0;
    }
    curr.next = new ListNode(sum);
    curr = curr.next;
  }
  return dummy.next;
};

var create_linked_list = function (elements) {
  dummy = new ListNode();
  curr = dummy;
  for (let i = 0; i < elements.length; i++) {
    curr.next = new ListNode(elements[i]);
    curr = curr.next;
  }
  return dummy.next;
};

var print_linked_list = function (head) {
  elements = new Array();
  curr = head;
  while (curr !== null) {
    elements.push(curr.val);
    curr = curr.next;
  }
  console.log(elements.join("\t"));
};

let l1 = create_linked_list([9, 9, 9, 9, 9, 9, 9]);
let l2 = create_linked_list([9, 9, 9, 9]);
let res = addTwoNumbers(l1, l2);
print_linked_list(l1);
print_linked_list(l2);
print_linked_list(res);
