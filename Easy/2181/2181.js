// 2181. Merge Nodes in Between Zeros
// You are given the head of a linked list, which
// contains a series of integers separated by 0's.
// The beginning and end of the linked list will
// have Node.val == 0.
// For every two consecutive 0's, merge all the
// nodes lying in between them into a single node
// whose value is the sum of all the merged nodes.
// The modified list should not contain any 0's.
// Return the head of the modified linked list.

class ListNode {
  constructor(val = 0, next = null) {
    this.val = val;
    this.next = next;
  }
}

// var mergeNodes = function (head) {
//   let curr1 = head;
//   let dummy = new ListNode();
//   let curr2 = dummy;
//   let sum = 0;
//   while (curr1 !== null) {
//     if (curr1.val === 0 && sum !== 0) {
//       curr2.next = new ListNode(sum);
//       curr2 = curr2.next;
//       sum = 0;
//     } else {
//       sum += curr1.val;
//     }
//     curr1 = curr1.next;
//   }
//   return dummy.next;
// };

var mergeNodes = function (head) {
  let curr1 = head.next;
  let dummy = new ListNode();
  let curr2 = dummy;
  let sum = 0;
  while (curr1 !== null) {
    if (curr1.val === 0) {
      curr2.next = new ListNode(sum);
      curr2 = curr2.next;
      sum = 0;
    } else {
      sum += curr1.val;
    }
    curr1 = curr1.next;
  }
  return dummy.next;
};

var create_linked_list = function (elements) {
  let dummy = new ListNode();
  let curr = dummy;
  for (let i = 0; i < elements.length; i++) {
    curr.next = new ListNode(elements[i]);
    curr = curr.next;
  }
  return dummy.next;
};

var print_linked_list = function (head) {
  let elements = new Array();
  let curr = head;
  while (curr !== null) {
    elements.push(curr.val);
    curr = curr.next;
  }
  console.log(elements.join("\t"));
};

input = create_linked_list([0, 3, 1, 0, 4, 5, 2, 0]);
output = mergeNodes(input);
print_linked_list(input);
print_linked_list(output);
