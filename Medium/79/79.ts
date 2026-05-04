export {};

const DIRECTIONS = [
  [-1, 0],
  [0, 1],
  [1, 0],
  [0, -1],
];

function dfs(
  board: string[][],
  word: string,
  m: number,
  n: number,
  x: number,
  y: number,
  idx: number,
): boolean {
  if (idx == word.length) return true;
  if (x < 0 || x >= m || y < 0 || y >= n) return false;
  if (board[x][y] !== word[idx]) return false;
  const temp = board[x][y];
  board[x][y] = "\0";
  for (const v of DIRECTIONS)
    if (dfs(board, word, m, n, x + v[0], y + v[1], idx + 1)) {
      board[x][y] = temp;
      return true;
    }
  board[x][y] = temp;

  return false;
}
function exist(board: string[][], word: string): boolean {
  const m = board.length;
  const n = board[0].length;
  for (let i = 0; i < m; i++)
    for (let j = 0; j < n; j++)
      if (dfs(board, word, m, n, i, j, 0)) return true;
  return false;
}

console.log("It's Showtime Folks!");
let board = [
  ["A", "B", "C", "E"],
  ["S", "F", "C", "S"],
  ["A", "D", "E", "E"],
];
let word = "ABCCED";
console.log(`Result: ${exist(board, word)}`);
board = [
  ["A", "B", "C", "E"],
  ["S", "F", "C", "S"],
  ["A", "D", "E", "E"],
];
word = "SEE";
console.log(`Result: ${exist(board, word)}`);
board = [
  ["A", "B", "C", "E"],
  ["S", "F", "C", "S"],
  ["A", "D", "E", "E"],
];
word = "ABCB";
console.log(`Result: ${exist(board, word)}`);
