export {};

const closeToOpen = new Map([
  [")", "("],
  ["]", "["],
  ["}", "{"],
]);

function isValid(s: string): boolean {
  let history: string[] = [];
  for (const c of s) {
    if (closeToOpen.has(c)) {
      if (
        history.length === 0 ||
        history[history.length - 1] !== closeToOpen.get(c)
      )
        return false;
      history.pop();
    } else history.push(c);
  }
  return history.length === 0 ? true : false;
}

console.log("It's Showtime Folks!");
console.log(`Solution: ${isValid("()")}`);
console.log(`Solution: ${isValid("()[]{}")}`);
console.log(`Solution: ${isValid("(]")}`);
console.log(`Solution: ${isValid("([])")}`);
console.log(`Solution: ${isValid("([)]")}`);
