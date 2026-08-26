export {};

function permute(nums: number[]): number[][] {
  if (nums.length === 0) return [[]];
  let result: number[][] = [];
  for (let i = 0; i < nums.length; i++) {
    const temp = nums.splice(i, 1)[0];
    for (const v of permute(nums)) {
      v.unshift(temp);
      result.push(v);
    }
    nums.splice(i, 0, temp);
  }
  return result;
}

console.log("It's Showtime Folks!");
console.log(permute([1, 2, 3]));
