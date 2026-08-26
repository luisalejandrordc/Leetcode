// 1255. Maximum Score Words Formed by Letters
// Given a list of words, list of  single letters (might
// be repeating) and score of every character.
// Return the maximum score of any valid set of words
// formed by using the given letters (words[i] cannot be
// used two or more times).
// It is not necessary to use all characters in letters
// and each letter can only be used once. Score of
// letters 'a', 'b', 'c', ... ,'z' is given by score[0],
// score[1], ... , score[25] respectively.

/**
 * @param {string} word
 * @return {number[]}
 */
function countWordLetters(word) {
  let freq = new Array(26).fill(0);
  for (c of word) {
    freq[c.charCodeAt() - 97]++;
  }
  return freq;
}

/**
 * @param {number[]} word
 * @param {number[]} letters
 * @return {boolean}
 */
function isValidWord(word, letters) {
  for (let i = 0; i < 26; i++) {
    if (word[i] > letters[i]) {
      return false;
    }
  }
  return true;
}

/**
 * @param {number[]} word
 * @param {number[]} score
 * @return {number}
 */
function getWordScore(word, score) {
  let wordScore = 0;
  for (let i = 0; i < 26; i++) {
    wordScore += word[i] * score[i];
  }
  return wordScore;
}

/**
 * @param {number} i
 * @param {number[][]} words
 * @param {number[]} letters
 * @param {number[]} score
 * @return {number}
 */
function dfs(i, words, letters, score) {
  if (i === words.length) return 0;
  let maxScore = dfs(i + 1, words, letters, score);
  if (isValidWord(words[i], letters)) {
    let wordScore = getWordScore(words[i], score);
    letters = letters.map((let, idx) => let - words[i][idx]);
    maxScore = Math.max(
      maxScore,
      wordScore + dfs(i + 1, words, letters, score),
    );
    letters = letters.map((let, idx) => let + words[i][idx]);
  }
  return maxScore;
}

/**
 * @param {string[]} words
 * @param {character[]} letters
 * @param {number[]} score
 * @return {number}
 * */
var maxScoreWords = function (words, letters, score) {
  letters = countWordLetters(letters.join(""));
  words = words.map((w) => countWordLetters(w));
  return dfs(0, words, letters, score);
};

const start = new Date();

const words = ["e", "bac", "baeba", "eb", "bbbbd", "cad", "c", "c"];
const letters = [
  "a",
  "a",
  "a",
  "a",
  "a",
  "a",
  "a",
  "b",
  "b",
  "b",
  "b",
  "b",
  "b",
  "c",
  "c",
  "c",
  "c",
  "c",
  "c",
  "d",
  "d",
  "d",
  "d",
  "d",
  "d",
  "d",
  "e",
  "e",
  "e",
  "e",
];
const score = [
  8, 4, 6, 8, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
];

console.log(`Solution: ${maxScoreWords(words, letters, score)}`);

const elapsedTime = new Date() - start;
console.log(`Elapsed Time: ${elapsedTime} ms`);
