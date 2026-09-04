#pragma once
#include <chrono>
#include <cstddef>
#include <functional>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// std::optional<T> condition
template <typename T> struct is_optional : std::false_type {};
template <typename T> struct is_optional<std::optional<T>> : std::true_type {};
template <typename T>
inline constexpr bool is_optional_v = is_optional<T>::value;

// std::pair<T1, T2> condition
template <typename T> struct is_pair : std::false_type {};
template <typename T1, typename T2>
struct is_pair<std::pair<T1, T2>> : std::true_type {};
template <typename T> inline constexpr bool is_pair_v = is_pair<T>::value;

// std::unordered_map<Key, Value> condition
template <typename T> struct is_unordered_map : std::false_type {};
template <typename Key, typename Value, typename Hash, typename Pred,
          typename Alloc>
struct is_unordered_map<std::unordered_map<Key, Value, Hash, Pred, Alloc>>
    : std::true_type {};
template <typename T>
inline constexpr bool is_unordered_map_v = is_unordered_map<T>::value;

// std_unordered_set<T> condition
template <typename T> struct is_unordered_set : std::false_type {};
template <typename T>
struct is_unordered_set<std::unordered_set<T>> : std::true_type {};
template <typename T>
inline constexpr bool is_unordered_set_v = is_unordered_set<T>{};

// std::vector<T> condition
template <typename T> struct is_vector : std::false_type {};
template <typename T> struct is_vector<std::vector<T>> : std::true_type {};
template <typename T> inline constexpr bool is_vector_v = is_vector<T>::value;

inline void printTitle(const std::string &title) {
  std::string dashes(title.length() + 10, '-');
  std::cout << dashes << std::endl;
  std::cout << "|    " << title << "    |" << std::endl;
  std::cout << dashes << std::endl;
}

template <typename T> inline void print(const T &value, bool addNewLine = true);

template <typename T1, typename T2>
inline void print_pair(const std::pair<T1, T2> &p) {
  std::cout << "(";
  print(p.first, false);
  std::cout << ", ";
  print(p.second, false);
  std::cout << ")";
}

template <std::ranges::input_range Range>
inline void print_sequence(const Range &range) {
  std::cout << "[";
  for (int i = 0; i < range.size(); i++) {
    if (i != 0)
      std::cout << ", ";
    print(range[i], false);
  }
  std::cout << "]";
}

template <typename T>
inline void print_unordered_set(const std::unordered_set<T> &set) {
  std::cout << "{";
  for (auto it = set.begin(); it != set.end(); it++) {
    if (it != set.begin())
      std::cout << ", ";
    print(*it, false);
  }
  std::cout << "}";
}

template <typename T1, typename T2>
inline void print_unordered_map(const std::unordered_map<T1, T2> &map) {
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

template <typename T> inline void print(const T &value, bool addNewLine) {
  // unordered_map
  if constexpr (is_unordered_map_v<T>)
    print_unordered_map(value);
  else if constexpr (is_unordered_set_v<T>)
    print_unordered_set(value);
  else if constexpr (is_optional_v<T>)
    if (value.has_value())
      print(*value, addNewLine);
    else
      std::cout << "null";
  else if constexpr (is_pair_v<T>)
    print_pair(value);
  else if constexpr (std::ranges::input_range<T> &&
                     !std::is_convertible_v<T, std::string_view>)
    print_sequence(value);
  else
    std::cout << value;

  if (addNewLine)
    std::cout << std::endl;
}

template <typename T>
inline void printVector(const std::vector<T> &vec,
                        bool is_initial_call = true) {
  std::cout << "{";
  for (size_t i = 0; i < vec.size(); i++) {
    if (i > 0)
      std::cout << ", ";
    if constexpr (is_vector_v<T>)
      printVector(vec[i], false);
    else {
      if constexpr (is_optional_v<T>) {
        if (vec[i].has_value())
          std::cout << *vec[i];
        else
          std::cout << "null";
      } else
        std::cout << vec[i];
    }
  }
  std::cout << "}";
  if (is_initial_call)
    std::cout << std::endl;
}

template <typename Func, typename... Args>
inline auto timedCall(Func &&func, Args &&...args) {
  auto start = std::chrono::steady_clock::now();
  auto result =
      std::invoke(std::forward<Func>(func), std::forward<Args>(args)...);
  auto end = std::chrono::steady_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "Execution time: " << elapsed.count() << " us" << std::endl;
  return result;
}

template <typename T1, typename T2> struct PairHash {
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);
    // Combine hashes (boost-style combinations)
    return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1 << 6) + (h1 >> 2));
  }
};
