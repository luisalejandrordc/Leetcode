export {};

const ROMANS: [string, number][] = [
  ["I", 1],
  ["IV", 4],
  ["V", 5],
  ["IX", 9],
  ["X", 10],
  ["XL", 40],
  ["L", 50],
  ["XC", 90],
  ["C", 100],
  ["CD", 400],
  ["D", 500],
  ["CM", 900],
  ["M", 1000],
];

function intToRoman(num: number): string {
  let s = "";
  for (let i = ROMANS.length - 1; i >= 0; i--) {
    while (num >= ROMANS[i][1]) {
      num -= ROMANS[i][1];
      s += ROMANS[i][0];
    }
  }
  return s;
}

console.log("It's Showtime Folks!");
console.log(`Solution: ${intToRoman(3)}`);
console.log(`Solution: ${intToRoman(58)}`);
console.log(`Solution: ${intToRoman(1994)}`);
console.log(`Solution: ${intToRoman(3749)}`);
