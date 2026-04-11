from math import floor


def palindromeCenterIndex(s: str, idx: int) -> str:
    # Odd Palindrome
    k = 0
    while idx - k >= 0 and idx + k < len(s) and s[idx - k] == s[idx + k]:
        k += 1
    odd_start = idx - (k - 1)
    odd_len = 1 + 2 * (k - 1)

    # Even Palindrome
    m = 0
    while idx - m >= 0 and idx + 1 + m < len(s) and s[idx - m] == s[idx + 1 + m]:
        m += 1
    even_start = idx - (m - 1)
    even_len = 2 * m

    return (
        s[odd_start : odd_start + odd_len]
        if odd_len > even_len
        else s[even_start : even_start + even_len]
    )


class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans = ""
        i = 0
        while i < len(s) - floor(len(ans) / 2):
            temp = palindromeCenterIndex(s, i)
            if len(temp) > len(ans):
                ans = temp
            i += 1
        return ans


print("It's Showtime Fols!")
print(f"Solution: {Solution().longestPalindrome("cabba")}")
s = "zudfweormatjycujjirzjpyrmaxurectxrtqedmmgergwdvjmjtstdhcihacqnothgttgqfywcpgnuvwglvfiuxteopoyizgehkwuvvkqxbnufkcbodlhdmbqyghkojrgokpwdhtdrwmvdegwycecrgjvuexlguayzcammupgeskrvpthrmwqaqsdcgycdupykppiyhwzwcplivjnnvwhqkkxildtyjltklcokcrgqnnwzzeuqioyahqpuskkpbxhvzvqyhlegmoviogzwuiqahiouhnecjwysmtarjjdjqdrkljawzasriouuiqkcwwqsxifbndjmyprdozhwaoibpqrthpcjphgsfbeqrqqoqiqqdicvybzxhklehzzapbvcyleljawowluqgxxwlrymzojshlwkmzwpixgfjljkmwdtjeabgyrpbqyyykmoaqdambpkyyvukalbrzoyoufjqeftniddsfqnilxlplselqatdgjziphvrbokofvuerpsvqmzakbyzxtxvyanvjpfyvyiivqusfrsufjanmfibgrkwtiuoykiavpbqeyfsuteuxxjiyxvlvgmehycdvxdorpepmsinvmyzeqeiikajopqedyopirmhymozernxzaueljjrhcsofwyddkpnvcvzixdjknikyhzmstvbducjcoyoeoaqruuewclzqqqxzpgykrkygxnmlsrjudoaejxkipkgmcoqtxhelvsizgdwdyjwuumazxfstoaxeqqxoqezakdqjwpkrbldpcbbxexquqrznavcrprnydufsidakvrpuzgfisdxreldbqfizngtrilnbqboxwmwienlkmmiuifrvytukcqcpeqdwwucymgvyrektsnfijdcdoawbcwkkjkqwzffnuqituihjaklvthulmcjrhqcyzvekzqlxgddjoir"
print(f"Solution: {Solution().longestPalindrome(s)}")
