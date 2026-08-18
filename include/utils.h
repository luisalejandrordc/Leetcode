#pragma once
#include <chrono>
#include <cstddef>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

inline void printTitle(const std::string &title) {
  std::string dashes(title.length() + 10, '-');
  std::cout << dashes << std::endl;
  std::cout << "|    " << title << "    |" << std::endl;
  std::cout << dashes << std::endl;
}

template <typename T> inline void printVector(const std::vector<T> &vec) {
  std::cout << "{";
  for (int i = 0; i < vec.size(); i++) {
    if (i > 0)
      std::cout << ", ";
    std::cout << vec[i];
  }
  std::cout << "}" << std::endl;
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
}

template <typename T1, typename T2> struct PairHash {
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);
    // Combine hashes (boost-style combinations)
    return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1 << 6) + (h1 >> 2));
  }
};
