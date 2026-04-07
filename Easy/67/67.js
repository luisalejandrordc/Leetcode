// 67. Add Binary
// Given two binary strings a and b, return their sum as a binary string.

/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */

// var addBinary = function (a, b) {
//   let max = a.length > b.length ? a.length : b.length;
//   let sum = [];
//   for (let i = 0; i < max; i++) {
//     if (a[i] === undefined || b[i] === undefined) {
//       sum[i] = a[i] === undefined ? b[i] : a[i];
//     } else {
//       if (a[i] === "1" && b[i] === "1") {
//         sum[i] = "0";
//       } else {
//         sum[i] = String(Number(a[i]) + Number(b[i]));
//       }
//     }
//     if (a[i] === 0 || b[i] === 0) {
//       console.log("Hello");
//     }
//   }
//   return sum;
// };

/**
 * @param {string} s
 * @return s
 */
function reverseString(s) {
  return s.split("").reverse().join("");
}

/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 * */
// var addBinary = function (a, b) {
//   ra = reverseString(a);
//   rb = reverseString(b);
//   let ans = "";
//   let i = 0;
//   let carry = 0;
//   while (i < Math.max(ra.length, rb.length) || carry !== 0) {
//     let va = ra[i] !== undefined ? Number(ra[i]) : 0;
//     let vb = rb[i] !== undefined ? Number(rb[i]) : 0;
//     let sum = va + vb + carry;
//     if (sum > 1) {
//       carry = 1;
//       ans += sum - 2;
//     } else {
//       carry = 0;
//       ans += sum;
//     }
//     i++;
//   }
//   return reverseString(ans);
// };

/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 * */
var addBinary = function (a, b) {
  let ans = new Array();
  let ia = a.length - 1;
  let ib = b.length - 1;
  let carry = 0;
  while (ia >= 0 || ib >= 0 || carry !== 0) {
    let va = ia >= 0 ? Number(a[ia]) : 0;
    let vb = ib >= 0 ? Number(b[ib]) : 0;
    let sum = va + vb + carry;
    ans.push(sum % 2);
    carry = Math.floor(sum / 2);
    ia--;
    ib--;
  }
  return ans.reverse().join("");
};

console.log(`Solution: ${addBinary("1010", "1011")}`);
