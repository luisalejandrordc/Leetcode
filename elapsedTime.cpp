#include <chrono>
#include <iostream>

using namespace std;

int addNumbers(const int &a, const int &b) {
  // Adding two numbers
  return a + b;
}

double getElapsedTime(const int &a, const int &b,
                      int(myFunction)(const int &, const int &)) {
  auto start = chrono::high_resolution_clock::now();
  int output = myFunction(a, b); // Execution
  // cout << "Inputs: " << a << " - " << b << endl;
  // cout << "Output: " << output << endl;
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> elapsedTime = end - start;
  return elapsedTime.count();
}

int main() {
  double totalTime = 0;
  int num = 1000;
  for (int i = 0; i < num; i++)
    totalTime += getElapsedTime(12, 18, addNumbers);
  cout << "Total Elapsed Time: " << totalTime << " ms" << endl;
  cout << "Average Elapsed Time: " << totalTime / num << " ms" << endl;
  return 0;
}
