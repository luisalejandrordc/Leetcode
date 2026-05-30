// 3. Longest Substring Without Repeating Characters
// Given a string s, find the length of the longest
// substring without duplicate characters.

/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
  let highest = 0;
  let [l, r] = [0, 0];
  let visited = new Map();
  while (r < s.length && s.length - l > highest) {
    if (visited.has(s[r]) && visited.get(s[r]) >= l) {
      l = visited.get(s[r]) + 1;
    }
    visited.set(s[r], r);
    highest = Math.max(highest, r - l + 1);
    r++;
  }
  return highest;
};

console.log("It's Showtime Folks!");
let s =
  "abcaefghibjkclmnopqraastuvwxyzABCDEFFGHIJKLMMNOPQRSTUUVWXYYZ0123456789!@#abcaefghibjkclmnopq";
console.log(`Solution: ${lengthOfLongestSubstring(s)}`);
