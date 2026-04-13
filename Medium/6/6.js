/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function (s, numRows) {
  if (numRows === 1) return s;
  let ans = "";
  const len = s.length;
  for (let i = 0; i < numRows; i++) {
    let idx = i;
    while (idx < len) {
      ans += s[idx];
      // First and last rows
      if (i === 0 || i === numRows - 1) idx += 2 * numRows - 2;
      // Middle rows (vertical)
      else if (idx % (2 * numRows - 2) < numRows)
        idx += 2 * numRows - 2 - 2 * i;
      // Middle rows (diagonal)
      else idx += 2 * i;
    }
  }
  return ans;
};

console.log("It's Showtime Folks!");
console.log(`Solution: ${convert("PAYPALISHIRING", 3)}`);
