#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution {
 public:
  int groups(vector<int>& w, int w_max) {
    int groups = 1;
    int sum = w[0];
    for (int i = 1; i < w.size(); i++) {
      if (sum + w[i] <= w_max) {
        sum += w[i];
      } else {
        ++groups;
        sum = 0;
      }
    }
    return groups;
  }

  int shipWithinDays(vector<int>& w, int days) {
    int low = *max_element(w.begin(), w.end());
    int high = accumulate(w.begin(), w.end(), 0);

    while (low <= high) {
      int mid = (low + high) / 2;
      if (groups(w, mid) > days)
        low = mid + 1;
      else
        high = mid - 1;
    }
    return low;
  }
};
// @lc code=end
