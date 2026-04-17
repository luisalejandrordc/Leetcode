// 32-bit signed integer limits
INT_MIN = -2147483648;
INT_MAX = 2147483647;
POS_LIM = Math.trunc(INT_MAX / 10);
NEG_LIM = Math.trunc(INT_MIN / 10);
const DIGITS = new Set(
  Array(10)
    .fill(0)
    .map((_, i) => String(i)),
);

/**
 * @param {string} s
 * @return {number}
 */
var myAtoi = function (s) {
  let num = 0;
  let started = false;
  let negative = false;
  for (c of s) {
    if (c == " " && !started) continue;
    if (DIGITS.has(c)) {
      started = true;
      let digit = !negative ? Number(c) : -Number(c);
      if (num > POS_LIM || (num == POS_LIM && digit > 7)) return INT_MAX;
      if (num < NEG_LIM || (num == NEG_LIM && digit < -8)) return INT_MIN;
      num = num * 10 + digit;
    } else if (c == "-" && !started) {
      negative = true;
      started = true;
    } else if (c == "+" && !started) {
      started = true;
    } else return num;
  }
  return num;
};

console.log("It's Showtime Folks!");
console.log(`Solution: ${myAtoi("123")}`);
console.log(`Solution: ${myAtoi("-042")}`);
console.log(`Solution: ${myAtoi("1337c0d3")}`);
console.log(`Solution: ${myAtoi("2147483648")}`);
