#include <iostream>

using namespace std;

string palindromeCenterIdx(const string &s, const int &idx) {
  // Odd Palindrome
  int k = 0;
  while (idx - k >= 0 && idx + k < s.length() && s[idx - k] == s[idx + k])
    k++;
  int odd_len = 1 + 2 * (k - 1);

  // Even Palindrome
  int m = 0;
  while (idx - m >= 0 && idx + 1 + m < s.length() &&
         s[idx - m] == s[idx + 1 + m])
    m++;
  int even_len = 2 * m;

  return odd_len > even_len ? s.substr(idx - (k - 1), odd_len)
                            : s.substr(idx - (m - 1), even_len);
}

class Solution {
public:
  string longestPalindrome(string s) {
    string ans;
    for (int i = 0; i < s.length() - floor(ans.length() / 2); i++) {
      string temp = palindromeCenterIdx(s, i);
      if (temp.length() > ans.length())
        ans = temp;
    }
    return ans;
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
