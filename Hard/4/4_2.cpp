// 4. Median of Two Sorted Arrays
// Given two sorted arrays nums1 and nums2 of size m and n
// respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> arr) {
  for (int i : arr)
    cout << i << "\t";
  cout << endl;
}

double getMedian(const vector<int> &arr) {
  int s = arr.size();
  if (s % 2 == 0) {
    return (arr[s / 2 - 1] + arr[s / 2]) / 2.0;
  }
  return arr[(s - 1) / 2];
}

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int size = nums1.size() + nums2.size();
    int i1 = 0, i2 = 0;
    vector<int> merged;
    merged.reserve(size);

    while (i1 < nums1.size() && i2 < nums2.size()) {
      if (nums1[i1] > nums2[i2])
        merged.push_back(nums2[i2++]);
      else
        merged.push_back(nums1[i1++]);
    }
    while (i1 < nums1.size())
      merged.push_back(nums1[i1++]);
    while (i2 < nums2.size())
      merged.push_back(nums2[i2++]);

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
