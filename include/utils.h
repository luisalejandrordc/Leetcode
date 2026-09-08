#pragma once
#include <array>
#include <chrono>
#include <cstddef>
#include <functional>
#include <iostream>
#include <iterator>
#include <optional>
#include <ranges>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

template <typename T> void print(const T &value, bool addNewLine = true);

namespace detail {
//----------------------------------
// TYPE TRAIT
// is_sequence_v condition -> std::vector, std::array, or T[N] (except char[N])
//----------------------------------

template <typename T> struct is_sequence : std::false_type {};

template <typename T, typename Alloc>
struct is_sequence<std::vector<T, Alloc>> : std::true_type {};

template <typename T, std::size_t N>
struct is_sequence<std::array<T, N>> : std::true_type {};

template <typename T, std::size_t N>
struct is_sequence<T[N]> : std::true_type {};

template <std::size_t N> struct is_sequence<char[N]> : std::false_type {};

template <typename T>
inline constexpr bool is_sequence_v = is_sequence<T>::value;

//----------------------------------
// TYPE TRAIT
// is_unordered_map_v condition -> std::unordered_map
//----------------------------------

template <typename T> struct is_unordered_map : std::false_type {};

template <typename Key, typename Value, typename Hash, typename Pred,
          typename Alloc>
struct is_unordered_map<std::unordered_map<Key, Value, Hash, Pred, Alloc>>
    : std::true_type {};

template <typename T>
inline constexpr bool is_unordered_map_v = is_unordered_map<T>::value;

//----------------------------------
// TYPE TRAIT
// is_unordered_set_v condition -> std::unordered_set
//----------------------------------

template <typename T> struct is_unordered_set : std::false_type {};

template <typename Value, typename Hash, typename Pred, typename Alloc>
struct is_unordered_set<std::unordered_set<Value, Hash, Pred, Alloc>>
    : std::true_type {};

template <typename T>
inline constexpr bool is_unordered_set_v = is_unordered_set<T>{};

//----------------------------------
// TYPE TRAIT
// is_optional_v condition -> std::optional
//----------------------------------

template <typename T> struct is_optional : std::false_type {};

template <typename T> struct is_optional<std::optional<T>> : std::true_type {};

template <typename T>
inline constexpr bool is_optional_v = is_optional<T>::value;

//----------------------------------
// TYPE TRAIT
// is_pair_v condition -> std::pair
//----------------------------------

template <typename T> struct is_pair : std::false_type {};

template <typename T1, typename T2>
struct is_pair<std::pair<T1, T2>> : std::true_type {};

template <typename T> inline constexpr bool is_pair_v = is_pair<T>::value;

//----------------------------------
// PRINT IMPLEMENTATION
//----------------------------------

template <typename T> void printSequence(const T &sequence) {
  std::cout << "[";
  for (auto it = std::begin(sequence); it != std::end(sequence); it++) {
    if (it != std::begin(sequence))
      std::cout << ", ";
    print(*it, false);
  }
  std::cout << "]";
}

template <typename T1, typename T2>
void printUnorderedMap(const std::unordered_map<T1, T2> &map) {
  std::cout << "{";
  for (auto it = map.begin(); it != map.end(); it++) {
    if (it != map.begin())
      std::cout << ", ";
    print(it->first, false);
    std::cout << ": ";
    print(it->second, false);
  }
  std::cout << "}";
}

template <typename T> void printUnorderedSet(const std::unordered_set<T> &set) {
  std::cout << "{";
  for (auto it = set.begin(); it != set.end(); it++) {
    if (it != set.begin())
      std::cout << ", ";
    print(*it, false);
  }
  std::cout << "}";
}

template <typename T1, typename T2>
void printPair(const std::pair<T1, T2> &pair) {
  std::cout << "(";
  print(pair.first, false);
  std::cout << ", ";
  print(pair.second, false);
  std::cout << ")";
}

template <typename T> void printOptional(const std::optional<T> &optional) {
  if (optional.has_value())
    print(*optional, false);
  else
    std::cout << "null";
}
} // namespace detail

//----------------------------------
// GENERAL PRINT FUNCTION
//----------------------------------

template <typename T> void print(const T &value, bool addNewLine) {
  if constexpr (detail::is_sequence_v<T>)
    detail::printSequence(value);
  else if constexpr (detail::is_unordered_map_v<T>)
    detail::printUnorderedMap(value);
  else if constexpr (detail::is_unordered_set_v<T>)
    detail::printUnorderedSet(value);
  else if constexpr (detail::is_pair_v<T>)
    detail::printPair(value);
  else if constexpr (detail::is_optional_v<T>)
    detail::printOptional(value);
  else
    std::cout << value;

  if (addNewLine)
    std::cout << std::endl;
}

//----------------------------------
// PRINT TITLE FUNCTION
//----------------------------------

inline void printTitle(const std::string &title) {
  std::string dashes(title.length() + 10, '-');
  std::cout << dashes << std::endl;
  std::cout << "|    " << title << "    |" << std::endl;
  std::cout << dashes << std::endl;
}

//----------------------------------
// TIMED CALL FUNCTION
//----------------------------------

template <typename Func, typename... Args>
auto timedCall(Func &&func, Args &&...args) {
  auto start = std::chrono::steady_clock::now();
  auto result =
      std::invoke(std::forward<Func>(func), std::forward<Args>(args)...);
  auto end = std::chrono::steady_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "Execution time: " << elapsed.count() << " us" << std::endl;
  return result;
}

//----------------------------------
// PAIR HASH FUNCTION
//----------------------------------

template <typename T1, typename T2> struct PairHash {
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);
    // Combine hashes (boost-style combinations)
    return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1 << 6) + (h1 >> 2));
  }
};
