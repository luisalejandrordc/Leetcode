export {};

const DICT = new Map([
  ["I", 1],
  ["V", 5],
  ["X", 10],
  ["L", 50],
  ["C", 100],
  ["D", 500],
  ["M", 1000],
]);

function romanToInt(s: string): number {
  const len = s.length;
  let num = 0;
  for (let i = 0; i < len; i++) {
    if (i != len - 1) {
      if (s[i] == "I" && (s[i + 1] == "V" || s[i + 1] == "X")) {
        num -= 1;
        continue;
      }
      if (s[i] == "X" && (s[i + 1] == "L" || s[i + 1] == "C")) {
        num -= 10;
        continue;
      }
      if (s[i] == "C" && (s[i + 1] == "D" || s[i + 1] == "M")) {
        num -= 100;
        continue;
      }
    }
    num += DICT.get(s[i]) ?? 0;
  }
  return num;
}

console.log("It's Showtime Folks!");
console.log(`Solution: ${romanToInt("III")}`);
console.log(`Solution: ${romanToInt("LVIII")}`);
console.log(`Solution: ${romanToInt("MCMXCIV")}`);
