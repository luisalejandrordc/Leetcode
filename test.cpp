#include <iostream>
#include <vector>

using namespace std;

void print_vector_string(vector<string> elements) {
  for (int i = 0; i < elements.size(); i++) {
    cout << elements[i] << "\t";
  }
  cout << endl;
}

vector<string> get_subsets(vector<string> elements, int k) {
  if (k == 1) {
    return elements;
  }
  vector<string> result, subsets;
  vector<string> new_elements = elements;
  for (int i = 0; i <= elements.size() - k; i++) {
    new_elements.erase(new_elements.begin());
    subsets = get_subsets(new_elements, k - 1);
    for (int j = 0; j < subsets.size(); j++) {
      result.push_back(elements[i] + subsets[j]);
    }
  }
  return result;
}

int main() {
  vector<string> words = {"dog", "cat", "dad", "good"};
  vector<string> result = get_subsets(words, 3);
  print_vector_string(result);
  return 0;
}
