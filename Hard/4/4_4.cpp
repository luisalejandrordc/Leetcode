#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();
    if (m > n)
      return findMedianSortedArrays(nums2, nums1);
    int left = -1, right = m - 1;
    int half = (m + n) / 2;
    while (left <= right) {
      int i = floor((left + right) / 2);
      int j = half - i - 2;
      int maxLeft1 = i == -1 ? INT_MIN : nums1[i];
      int maxLeft2 = j == -1 ? INT_MIN : nums2[j];
      int minRight1 = i == m - 1 ? INT_MAX : nums1[i + 1];
      int minRight2 = j == n - 1 ? INT_MAX : nums2[j + 1];
      if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1)
        return (m + n) % 2 == 0
                   ? (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0
                   : min(minRight1, minRight2);
      if (maxLeft1 > minRight2)
        right = i - 1;
      else
        left = i + 1;
    }
    return 0.0;
  }
};

int main() {
  cout << "It's Showtime Folks!" << endl;
  vector<int> nums1 = {1, 3};
  vector<int> nums2 = {2};
  cout << "Solution: " << Solution().findMedianSortedArrays(nums1, nums2)
       << endl;
  return 0;
}
