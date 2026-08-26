// 1. Two Sum
// Given an array of integers nums and an integer target,
// return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution,
// and you may not use the same element twice.
// You can return the answer in any order.

/*
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

// 33 ms
// var twoSum = function (nums, target) {
//   for (let i = 0; i < nums.length - 1; i++) {
//     for (let j = i + 1; j < nums.length; j++) {
//       if (nums[i] + nums[j] === target) {
//         return [i, j];
//       }
//     }
//   }
//   return null;
// };

// 73 ms
// var twoSum = function (nums, target) {
//   for (let i = 0; i < nums.length; i++) {
//     const diff = target - nums[i];
//     const idx = nums.indexOf(diff);
//     if (idx !== -1 && idx !== i) {
//       return [i, idx];
//     }
//   }
//   return null;
// };

// 6 ms
// var twoSum = function (nums, target) {
//   const map = new Map(nums.map((value, index) => [value, index]));
//   for (let i = 0; i < nums.length; i++) {
//     const diff = target - nums[i];
//     if (map.has(diff) && map.get(diff)) {
//       const idx = map.get(diff);
//       if (idx !== i) return [i, map.get(diff)];
//     }
//   }
//   return null;
// };

// 1ms
var twoSum = function (nums, target) {
  const map = new Map();
  for (let i = 0; i < nums.length; i++) {
    const diff = target - nums[i];
    if (map.has(diff)) {
      return [i, map.get(diff)];
    }
    map.set(nums[i], i);
  }
  return null;
};

console.log(twoSum([2, 7, 11, 15], 9));
console.log(twoSum([1, 2, 3, 4], 7));
