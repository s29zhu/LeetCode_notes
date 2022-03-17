#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
 public:
  int subarraySum(const vector<int>& nums, int k) {
    unordered_map<int, int> counts{make_pair(0, 1)};
    int s = 0, r = 0;
    for (auto i : nums) {
      s += i;
      r += counts[s - k];
      counts[s] += 1;
    }
    return r;
  }
};
// @lc code=end

int main() {
  Solution s;
  cout << s.subarraySum({-1, -1, 1}, 0) << endl;
  return 0;
}