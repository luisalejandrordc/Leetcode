/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
  let maxPro = 0;
  let minPri = prices[0];
  for (price of prices) {
    minPri = Math.min(minPri, price);
    maxPro = Math.max(maxPro, price - minPri);
  }
  return maxPro;
};

console.log("It's Showtime Folks!");
console.log(`Solution: ${maxProfit([7, 1, 5, 3, 6, 4])}`);
