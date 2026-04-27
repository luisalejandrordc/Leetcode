/**
 * @param {number[][]} matrix
 * @return boolean
 */
var isToeplitzMatrix = function (matrix) {
  const m = matrix.length;
  const n = matrix[0].length;
  for (let i = 1; i < m; i++)
    for (let j = 1; j < n; j++)
      if (matrix[i][j] != matrix[i - 1][j - 1]) return false;
  return true;
};

console.log("It's Showtime Folks!");
let matrix1 = [
  [1, 2, 3, 4],
  [5, 1, 2, 3],
  [9, 5, 1, 2],
];
console.log(`Solution: ${isToeplitzMatrix(matrix1)}`);
let matrix2 = [
  [1, 2],
  [2, 2],
];
console.log(`Solution: ${isToeplitzMatrix(matrix2)}`);
