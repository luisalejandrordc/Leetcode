/**
 * @param {number}
 * @return {boolean}
 */
var isPalindrome = function (x) {
  if (x < 0) return false;
  const num = x;
  let rev = 0;
  while (x != 0) {
    digit = x % 10;
    // There is no need to verify that the number is within the 32-bit limit
    rev = rev * 10 + digit;
    x = Math.trunc(x / 10);
  }
  return num == rev;
};

console.log("It's Showtime Folks!");
console.log(`Solution: ${isPalindrome(121)}`);
console.log(`Solution: ${isPalindrome(-121)}`);
console.log(`Solution: ${isPalindrome(10)}`);
console.log(`Solution: ${isPalindrome(1234567899)}`);
