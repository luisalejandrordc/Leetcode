/**
 * @param {string} jewels
 * @param {string} stones
 * @return {number}
 */
var numJewelsInStones = function (jewels, stones) {
  let set = new Set();
  for (c of jewels) set.add(c);
  let count = 0;
  for (c of stones) if (set.has(c)) count++;
  return count;
};

console.log(`Solution: ${numJewelsInStones("aA", "aAAbbbb")}`);
console.log(`Solution: ${numJewelsInStones("z", "ZZ")}`);
