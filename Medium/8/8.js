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
      let digit = Number(c);
      num = num * 10 + digit;
    } else if (c == "-") {
      negative = true;
      started = true;
    } else if (c == "+") {
      started = true;
    } else return num;
  }
  return num;
};

// let nums = new Array(20).fill(0).map((n, i) => i + 1);
// for (n of nums) console.log(n);

console.log("It's Showtime Folks!");
console.log(`Solution: ${myAtoi("123")}`);
console.log(`Solution: ${myAtoi("-042")}`);
console.log(`Solution: ${myAtoi("1337c0d3")}`);
console.log(`Solution: ${myAtoi("2147483648")}`);
