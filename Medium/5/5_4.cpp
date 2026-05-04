#include <chrono>
#include <iostream>
#include <utility>

using namespace std;

pair<int, int> getOddPalindrome(const string &s, const int &idx) {
  int n = 1;
  int len = s.length();
  while (idx - n >= 0 && idx + n < len && s[idx - n] == s[idx + n])
    n++;
  n--;
  return {idx - n, 2 * n + 1};
}

pair<int, int> getEvenPalindrome(const string &s, const int &idx) {
  int n = 0;
  int len = s.length();
  while (idx - n >= 0 && idx + 1 + n < len && s[idx - n] == s[idx + 1 + n])
    n++;
  n--;
  return {idx - n, 2 * (n + 1)};
}

class Solution {
public:
  string longestPalindrome(const string &s) {
    pair<int, int> pal = {0, 0};
    for (int i = 0; i < s.length() - (pal.second + 1) / 2; i++) {
      pair<int, int> odd = getOddPalindrome(s, i);
      pair<int, int> even = getEvenPalindrome(s, i);
      pair<int, int> longest = odd.second > even.second ? odd : even;
      if (longest.second > pal.second)
        pal = longest;
    }
    return s.substr(pal.first, pal.second);
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  auto start = chrono::high_resolution_clock::now();
  cout << "Solution: " << Solution().longestPalindrome("cabba") << endl;
  cout << "Solution: "
       << Solution().longestPalindrome(
              "zudfweormatjycujjirzjpyrmaxurectxrtqedmmgergwdvjmjtstdhcihacqnot"
              "hgttgqfywcpgnuvwglvfiuxteopoyizgehkwuvvkqxbnufkcbodlhdmbqyghkojr"
              "gokpwdhtdrwmvdegwycecrgjvuexlguayzcammupgeskrvpthrmwqaqsdcgycdup"
              "ykppiyhwzwcplivjnnvwhqkkxildtyjltklcokcrgqnnwzzeuqioyahqpuskkpbx"
              "hvzvqyhlegmoviogzwuiqahiouhnecjwysmtarjjdjqdrkljawzasriouuiqkcww"
              "qsxifbndjmyprdozhwaoibpqrthpcjphgsfbeqrqqoqiqqdicvybzxhklehzzapb"
              "vcyleljawowluqgxxwlrymzojshlwkmzwpixgfjljkmwdtjeabgyrpbqyyykmoaq"
              "dambpkyyvukalbrzoyoufjqeftniddsfqnilxlplselqatdgjziphvrbokofvuer"
              "psvqmzakbyzxtxvyanvjpfyvyiivqusfrsufjanmfibgrkwtiuoykiavpbqeyfsu"
              "teuxxjiyxvlvgmehycdvxdorpepmsinvmyzeqeiikajopqedyopirmhymozernxz"
              "aueljjrhcsofwyddkpnvcvzixdjknikyhzmstvbducjcoyoeoaqruuewclzqqqxz"
              "pgykrkygxnmlsrjudoaejxkipkgmcoqtxhelvsizgdwdyjwuumazxfstoaxeqqxo"
              "qezakdqjwpkrbldpcbbxexquqrznavcrprnydufsidakvrpuzgfisdxreldbqfiz"
              "ngtrilnbqboxwmwienlkmmiuifrvytukcqcpeqdwwucymgvyrektsnfijdcdoawb"
              "cwkkjkqwzffnuqituihjaklvthulmcjrhqcyzvekzqlxgddjoir")
       << endl;
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> duration = end - start;
  cout << "Total Duration: " << duration.count() << endl;
  return 0;
}
