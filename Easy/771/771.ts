export {};

function numJewelsInStones(jewels: string, stones: string): number {
  let mySet = new Set();
  for (let c of jewels) mySet.add(c);
  let count: number = 0;
  for (let c of stones) if (mySet.has(c)) count++;
  return count;
}

console.log(`Solution: ${numJewelsInStones("aA", "aAAbbbb")}`);
console.log(`Solution: ${numJewelsInStones("z", "ZZ")}`);
