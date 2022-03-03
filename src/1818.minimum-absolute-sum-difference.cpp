#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=1818 lang=cpp
 *
 * [1818] Minimum Absolute Sum Difference
 */

// @lc code=start
class Solution {
 public:
  int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    vector<int> s = nums1;
    sort(s.begin(), s.end());
    long max_dec = 0, sum = 0;
    for (int i = 0; i < nums2.size(); ++i) {
      long ss = abs(nums2[i] - nums1[i]);
      if (ss > max_dec) {
        long dec = ss - abs(nums2[i] - nearest(s, nums2[i]));
        if (dec > max_dec) max_dec = dec;
      }
      sum += ss;
    }
    return (sum - max_dec) % 1000000007;
  }
  int nearest(const vector<int>& s, int q) {
    if (q <= s.front()) return s.front();
    if (q >= s.back()) return s.back();

    int low = 0, high = s.size() - 1, mid = (low + high) / 2;
    while (low != mid) {
      if (q == s[mid]) return q;
      if (q > s[mid]) low = mid;
      else high = mid;
      mid = (low + high) / 2;
    }
    return abs(q - s[low]) < abs(s[high] - q) ? s[low] : s[high];
  }
};
// @lc code=end

// https://books.halfrost.com/leetcode/ChapterFour/1800~1899/1818.Minimum-Absolute-Sum-Difference/