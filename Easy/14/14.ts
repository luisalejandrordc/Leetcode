export {};

function getMinLength(strs: string[]): number {
  let min: number = 2147483647; // 2^32 - 1
  for (let s of strs) if (s.length < min) min = s.length;
  return min;
}

function longestCommonPrefix(strs: string[]): string {
  let s: string = "";
  for (let k = 0; k < getMinLength(strs); k++) {
    for (let i = 0; i < strs.length - 1; i++)
      if (strs[i][k] !== strs[i + 1][k]) return s;
    s += strs[0][k];
  }
  return s;
}

console.log("It's Showtime Folks!");
let strs1 = ["flower", "flow", "flight"];
console.log(`Solution: ${longestCommonPrefix(strs1)}`);
let strs2 = ["dog", "racecar", "car"];
console.log(`Solution: ${longestCommonPrefix(strs2)}`);
