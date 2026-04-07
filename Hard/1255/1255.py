# 1255. Maximum Score Words Formed by Letters
# Given a list of words, list of  single letters (might
# be repeating) and score of every character.
# Return the maximum score of any valid set of words
# formed by using the given letters (words[i] cannot be
# used two or more times).
# It is not necessary to use all characters in letters
# and each letter can only be used once. Score of
# letters 'a', 'b', 'c', ... ,'z' is given by score[0],
# score[1], ... , score[25] respectively.


def get_new_words(words: list[str]) -> list[list[int]]:
    new_words = []
    for w in words:
        new_words.append(count_letters(w))
    return new_words


def get_new_letters(letters: list[str]) -> list[int]:
    return count_letters("".join(letters))


def count_letters(word: str) -> list[int]:
    freq = [0 for _ in range(26)]
    for c in word:
        freq[ord(c) - 97] += 1
    return freq


def is_valid_word(word: list[int], letters: list[int]) -> bool:
    for i in range(26):
        if word[i] > letters[i]:
            return False
    return True


def get_word_score(word: list[int], score: list[int]) -> int:
    word_score = 0
    for i in range(26):
        word_score += word[i] * score[i]
    return word_score


def dfs(i: int, words: list[list[int]], letters: list[int], score: list[int]) -> int:
    if i == len(words):
        return 0
    max_score = dfs(i + 1, words, letters, score)
    if is_valid_word(words[i], letters):
        word_score = get_word_score(words[i], score)
        letters = [let - words[i][idx] for idx, let in enumerate(letters)]
        max_score = max(max_score, word_score + dfs(i + 1, words, letters, score))
        letters = [let + words[i][idx] for idx, let in enumerate(letters)]
    return max_score


class Solution:
    def maxScoreWords(
        self, words: list[str], letters: list[str], score: list[int]
    ) -> int:
        newWords = get_new_words(words)
        newLetters = get_new_letters(letters)
        return dfs(0, newWords, newLetters, score)


words = ["xxxz", "ax", "bx", "cx"]
letters = ["z", "a", "b", "c", "x", "x", "x"]
score = [4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10]
print(f"Solution: {Solution().maxScoreWords(words, letters, score)}")
