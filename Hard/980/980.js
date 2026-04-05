// 980. Unique Paths III
// You are given an m x n integer array grid where grid[i][j] could be:
// 1 representing the starting square. There is exactly one starting square.
// 2 representing the ending square. There is exactly one ending square.
// 0 representing empty squares we can walk over.
// -1 representing obstacles that we cannot walk over.
// Return the number of 4-directional walks from the starting square to the
// ending square, that walk over every non-obstacle square exactly once.

const DIRECTIONS = [
  [-1, 0],
  [0, 1],
  [1, 0],
  [0, -1],
];

const EMPTY = 0;
const START = 1;
const END = 2;
const OBSTACLE = -1;

/**
 * @param {number[][]} grid
 * @param {number} m
 * @param {number} n
 * @return {number[]}
 */
function findStart(grid, m, n) {
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (grid[i][j] == START) return [i, j];
    }
  }
}

function countEmptySpaces(grid, m, n) {
  let count = 0;
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (grid[i][j] == EMPTY) count++;
    }
  }
  return count;
}

/**
 * @param {number[][]} grid
 * @param {number} m
 * @param {number} n
 * @param {number} i
 * @param {number} j
 * @param {number} r
 * @param {number[]} total
 * @return
 */
function evaluateFourDirections(grid, m, n, r, c, e, total) {
  for (let k = 0; k < 4; k++) {
    let i = r + DIRECTIONS[k][0];
    let j = c + DIRECTIONS[k][1];
    if (i >= 0 && i < m && j >= 0 && j < n) {
      if (grid[i][j] != START && grid[i][j] != OBSTACLE) {
        if (grid[i][j] == END && e == 0) {
          total[0]++;
        }
        if (grid[i][j] == 0) {
          let temp = grid[i][j];
          grid[i][j] = OBSTACLE;
          evaluateFourDirections(grid, m, n, i, j, e - 1, total);
          grid[i][j] = temp;
        }
      }
    }
  }
}

/**
 * @param {number[][]} grid
 * @return {number}
 */
var uniquePathsIII = function (grid) {
  let m = grid.length;
  let n = grid[0].length;
  let [r, c] = findStart(grid, m, n);
  let e = countEmptySpaces(grid, m, n);
  let total = [0];
  evaluateFourDirections(grid, m, n, r, c, e, total);
  return total[0];
};

console.log("It's Showtime Folks!");

let grid = [
  [1, 0, 0, 0],
  [0, 0, 0, 0],
  [0, 0, 2, -1],
];
let result = uniquePathsIII(grid);
console.log(`Result: ${result}`);
