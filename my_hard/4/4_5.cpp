#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();
    if (m > n)
      return findMedianSortedArrays(nums2, nums1);
    int left = 0, right = m;
    int half = (m + n) / 2;
    while (left <= right) {
      int i = (left + right) / 2;
      int j = half - i;
      int maxLeft1 = i == 0 ? INT_MIN : nums1[i - 1];
      int minRight1 = i == m ? INT_MAX : nums1[i];
      int maxLeft2 = j == 0 ? INT_MIN : nums2[j - 1];
      int minRight2 = j == n ? INT_MAX : nums2[j];
      if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
        return (m + n) % 2 == 0
                   ? (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0
                   : min(minRight1, minRight2);
      }
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
