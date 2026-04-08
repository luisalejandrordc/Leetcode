#include <chrono>
#include <iostream>

using namespace std;

int addNumbers(const int &a, const int &b) {
  // Adding two numbers
  return a + b;
}

void printElapsedTime(const int &a, const int &b,
                      int(myFunction)(const int &, const int &)) {
  auto start = chrono::high_resolution_clock::now();
  cout << "Inputs: " << a << " - " << b << endl;
  cout << "Output: " << myFunction(a, b) << endl; // Execution
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> elapsedTime = end - start;
  cout << "Elapsed Time: " << elapsedTime.count() << endl;
}

int main() {
  printElapsedTime(12, 18, addNumbers);
  return 0;
}
