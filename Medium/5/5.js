/**
 * @param {string} s
 * @param {number} idx
 * @return {string}
 */
function palindromeCenterIdx(s, idx) {
  // Odd Palindrome
  let k = 0;
  while (idx - k >= 0 && idx + k < s.length && s[idx - k] == s[idx + k]) k++;
  const odd_len = 1 + 2 * (k - 1);

  // Even Palindrome
  let m = 0;
  while (idx - m >= 0 && idx + 1 + m < s.length && s[idx - m] == s[idx + 1 + m])
    m++;
  const even_len = 2 * m;

  return odd_len > even_len
    ? s.slice(idx - (k - 1), idx - (k - 1) + odd_len)
    : s.slice(idx - (m - 1), idx - (m - 1) + even_len);
}

/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function (s) {
  let ans = "";
  for (let i = 0; i < s.length - Math.floor(ans.length / 2); i++) {
    let temp = palindromeCenterIdx(s, i);
    if (temp.length > ans.length) ans = temp;
  }
  return ans;
};

let s = "cabba";
console.log(`Solution: ${longestPalindrome(s)}`);
s =
  "zudfweormatjycujjirzjpyrmaxurectxrtqedmmgergwdvjmjtstdhcihacqnothgttgqfywcpgnuvwglvfiuxteopoyizgehkwuvvkqxbnufkcbodlhdmbqyghkojrgokpwdhtdrwmvdegwycecrgjvuexlguayzcammupgeskrvpthrmwqaqsdcgycdupykppiyhwzwcplivjnnvwhqkkxildtyjltklcokcrgqnnwzzeuqioyahqpuskkpbxhvzvqyhlegmoviogzwuiqahiouhnecjwysmtarjjdjqdrkljawzasriouuiqkcwwqsxifbndjmyprdozhwaoibpqrthpcjphgsfbeqrqqoqiqqdicvybzxhklehzzapbvcyleljawowluqgxxwlrymzojshlwkmzwpixgfjljkmwdtjeabgyrpbqyyykmoaqdambpkyyvukalbrzoyoufjqeftniddsfqnilxlplselqatdgjziphvrbokofvuerpsvqmzakbyzxtxvyanvjpfyvyiivqusfrsufjanmfibgrkwtiuoykiavpbqeyfsuteuxxjiyxvlvgmehycdvxdorpepmsinvmyzeqeiikajopqedyopirmhymozernxzaueljjrhcsofwyddkpnvcvzixdjknikyhzmstvbducjcoyoeoaqruuewclzqqqxzpgykrkygxnmlsrjudoaejxkipkgmcoqtxhelvsizgdwdyjwuumazxfstoaxeqqxoqezakdqjwpkrbldpcbbxexquqrznavcrprnydufsidakvrpuzgfisdxreldbqfizngtrilnbqboxwmwienlkmmiuifrvytukcqcpeqdwwucymgvyrektsnfijdcdoawbcwkkjkqwzffnuqituihjaklvthulmcjrhqcyzvekzqlxgddjoir";
console.log(`Solution: ${longestPalindrome(s)}`);
