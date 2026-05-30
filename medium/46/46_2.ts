export {};

function backtrack(nums: number[], a: number, result: number[][]) {
  if (a === nums.length - 1) {
    result.push([...nums]); // push a copy of nums
    return;
  }
  for (let b = a; b < nums.length; b++) {
    [nums[a], nums[b]] = [nums[b], nums[a]];
    backtrack(nums, a + 1, result);
    [nums[a], nums[b]] = [nums[b], nums[a]];
  }
}

function permute(nums: number[]): number[][] {
  let result: number[][] = [];
  backtrack(nums, 0, result);
  return result;
}

console.log("It's Showtime Folks!");
console.log(permute([1, 2, 3]));
