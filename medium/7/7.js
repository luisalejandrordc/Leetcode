// const INT_MIN = -Math.pow(2, 31);
// const INT_MAX = -(INT_MIN + 1);
const INT_MIN = -2147483648;
const INT_MAX = 2147483647;

/**
 * @param {number} x
 * @return {number}
 */
var reverse = function (x) {
  let ans = 0;
  while (x != 0) {
    digit = x % 10;
    if (ans > INT_MAX / 10 || (ans == Math.trunc(INT_MAX / 10) && digit > 7))
      return 0;
    if (ans < INT_MIN / 10 || (ans == Math.trunc(INT_MIN / 10) && digit < -8))
      return 0;
    ans = ans * 10 + digit;
    x = Math.trunc(x / 10);
  }
  return ans;
};

console.log(`Solution: ${reverse(123)}`);
console.log(`Solution: ${reverse(-12)}`);
console.log(`Solution: ${reverse(1534236469)}`);
