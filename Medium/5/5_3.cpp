#include <iostream>

using namespace std;

string getOddPalindrome(const string &s, const int &idx) {
  int n = 1;
  int len = s.length();
  while (idx - n >= 0 && idx + n < len && s[idx - n] == s[idx + n])
    n++;
  n--;
  return s.substr(idx - n, 2 * n + 1);
}

string getEvenPalindrome(const string &s, const int &idx) {
  int n = 0;
  int len = s.length();
  while (idx - n >= 0 && idx + 1 + n < len && s[idx - n] == s[idx + 1 + n])
    n++;
  n--;
  return s.substr(idx - n, 2 * (n + 1));
}

class Solution {
public:
  string longestPalindrome(const string &s) {
    string pal = "";
    for (int i = 0; i < s.length() - (pal.length() + 1) / 2; i++) {
      string odd = getOddPalindrome(s, i);
      string even = getEvenPalindrome(s, i);
      string longest = odd.length() > even.length() ? odd : even;
      if (longest.length() > pal.length())
        pal = longest;
    }
    return pal;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
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
  return 0;
}
