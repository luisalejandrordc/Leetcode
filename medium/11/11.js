/**
 * @param {number[]}
 * @return {number}
 */
var maxArea = function (height) {
  let maxAreaVar = 0;
  let [l, r] = [0, height.length - 1];
  while (l < r) {
    let w = r - l;
    let h = Math.min(height[l], height[r]);
    maxAreaVar = Math.max(maxAreaVar, w * h);
    if (height[l] < height[r]) l++;
    else r--;
  }
  return maxAreaVar;
};

console.log("It's Showtime Folks!");
console.log(maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]));
console.log(maxArea([1, 2, 3, 4]));
console.log(maxArea([1, 3, 2, 5, 25, 24, 5]));
