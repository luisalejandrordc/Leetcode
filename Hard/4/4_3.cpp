// 4. Median of Two Sorted Arrays
// Given two sorted arrays nums1 and nums2 of size m and n
// respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

#include <chrono>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void addToQueue(queue<int> &queue, int x) {
  if (queue.size() == 2)
    queue.pop();
  queue.push(x);
}

queue<int> getMediums(const vector<int> &nums1, const vector<int> &nums2,
                      const int &size) {
  int i1 = 0, i2 = 0;
  int limit = size % 2 == 0 ? size / 2 : (size - 1) / 2;
  queue<int> mediums;
  while (i1 < nums1.size() && i2 < nums2.size()) {
    if (nums1[i1] < nums2[i2]) {
      addToQueue(mediums, nums1[i1]);
      i1++;
    } else {
      addToQueue(mediums, nums2[i2]);
      i2++;
    }
    if (i1 + i2 > limit)
      return mediums;
  }
  while (i1 < nums1.size()) {
    addToQueue(mediums, nums1[i1]);
    i1++;
    if (i1 + i2 > limit)
      return mediums;
  }
  while (i2 < nums2.size()) {
    addToQueue(mediums, nums2[i2]);
    i2++;
    if (i1 + i2 > limit)
      return mediums;
  }
  return mediums;
}

double getMedian(const vector<int> &arr) {
  int s = arr.size();
  if (s % 2 == 0) {
    return (arr[s / 2 - 1] + arr[s / 2]) / 2.0;
  }
  return arr[(s - 1) / 2];
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
  int size = nums1.size() + nums2.size();
  queue<int> mediums = getMediums(nums1, nums2, size);
  return size % 2 == 0 ? (mediums.back() + mediums.front()) / 2.0
                       : mediums.back();
}

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int size = nums1.size() + nums2.size();
    queue<int> mediums = getMediums(nums1, nums2, size);
    return size % 2 == 0 ? (mediums.back() + mediums.front()) / 2.0
                         : mediums.back();
  }
};

double test(vector<int> &nums1, vector<int> &nums2) {
  int size = nums1.size() + nums2.size();
  queue<int> mediums = getMediums(nums1, nums2, size);
  return size % 2 == 0 ? (mediums.back() + mediums.front()) / 2.0
                       : mediums.back();
}
void printElapsedTime(double(func)(vector<int> &, vector<int> &)) {
  auto start = chrono::high_resolution_clock::now();
  vector<int> nums1 = {1, 2};
  vector<int> nums2 = {3, 4};
  cout << "Soltion: " << func(nums1, nums2) << endl;
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> elapsedTime = end - start;
  cout << "Elapsed Time: " << elapsedTime.count() << " ms" << endl;
}

int main() {
  cout << "It's Showtime Folks!" << endl;
  vector<int> nums1 = {1, 2};
  vector<int> nums2 = {3, 4};

  // Measure Elapsed Time
  auto start = chrono::high_resolution_clock::now();
  cout << "Solution: " << Solution().findMedianSortedArrays(nums1, nums2)
       << endl;
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> elapsedTime = end - start;
  cout << "Time Elapsed: " << elapsedTime.count() << " ms" << endl;
  cout << endl;
  printElapsedTime(test);
  return 0;
}
