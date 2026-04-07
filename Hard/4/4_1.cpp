// 4. Median of Two Sorted Arrays
// Given two sorted arrays nums1 and nums2 of size m and n
// respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeArrays(const vector<int> &arr1, const vector<int> &arr2) {
  vector<int> merged;
  merged.reserve(arr1.size() + arr2.size());
  merged.insert(merged.begin(), arr1.begin(), arr1.end());
  merged.insert(merged.begin(), arr2.begin(), arr2.end());
  return merged;
}

vector<int> sortArray(vector<int> arr) {
  int idx = 0;
  while (idx < arr.size() - 1) {
    if (arr[idx] > arr[idx + 1]) {
      int temp = arr[idx];
      arr[idx] = arr[idx + 1];
      arr[idx + 1] = temp;
      if (idx != 0)
        idx--;
    } else {
      idx++;
    }
  }
  return arr;
}

double getMedian(const vector<int> &arr) {
  vector<int> sorted = sortArray(arr);
  if (sorted.size() % 2 == 0) {
    return (sorted[sorted.size() / 2 - 1] + sorted[sorted.size() / 2]) / 2.0;
  }
  return sorted[(sorted.size() - 1) / 2];
}

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    vector<int> merged = mergeArrays(nums1, nums2);
    return getMedian(merged);
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  vector<int> nums1 = {1, 2};
  vector<int> nums2 = {3, 4};
  cout << "Solution: " << Solution().findMedianSortedArrays(nums1, nums2)
       << endl;
  return 0;
}
