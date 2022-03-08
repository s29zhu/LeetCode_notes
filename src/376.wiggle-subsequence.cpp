#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    vector<int> plus(nums.size(), 1), minus(nums.size(), 1);
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[j] == nums[i]) continue;
        if (nums[j] < nums[i])
          plus[i] = max(plus[i], minus[j] + 1);
        else
          minus[i] = max(minus[i], plus[j] + 1);
      }
    }
    return max(*max_element(plus.begin(), plus.end()),
               *max_element(minus.begin(), minus.end()));
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> v{1,7,4,9,2,5};
  s.wiggleMaxLength(v);
  return 0;
}