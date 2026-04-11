#include <iostream>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    string ans;
    for (int i = 0; i < s.length() - ans.length(); i++) {
      for (int j = 1; j < s.length() - i + 1; j++) {
        string temp1 = s.substr(i, j);
        string temp2;
        temp2.reserve(temp1.length());
        for (int k = j - 1; k >= 0; k--)
          temp2 += temp1[k];
        if (temp1 == temp2 && ans.length() < j)
          ans = temp1;
      }
    }
    return ans.length() != 0 ? ans : s;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
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
