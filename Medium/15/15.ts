export {};

function threeSum(nums: number[]): number[][] {
  let ans: number[][] = [];
  const len = nums.length;
  nums.sort((a, b) => a - b);
  for (let i = 0; i < len; i++) {
    if (i > 0 && nums[i] == nums[i - 1]) continue;
    let l = i + 1;
    let r = len - 1;
    while (l < r) {
      const sum = nums[i] + nums[l] + nums[r];
      if (sum == 0) {
        ans.push([nums[i], nums[l], nums[r]]);
        while (l < r && nums[l] == nums[l + 1]) l++;
        while (l < r && nums[r] == nums[r - 1]) r--;
        l++;
        r--;
      } else if (sum < 0) l++;
      else r--;
    }
  }
  return ans;
}

console.log("It's Showtime Folks!");
let nums = [-1, 0, 1, 2, -1, -4];
console.log("Solution:");
console.log(threeSum(nums));
nums = [0, 1, 1];
console.log("Solution:");
console.log(threeSum(nums));
nums = [0, 0, 0];
console.log("Solution:");
console.log(threeSum(nums));
