#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    for (int i = nums.size() - 1; i > 0; --i) {
      if (nums[i] > nums[i - 1]) {
        reverse(nums.begin() + i, nums.end());
        for (int j = i; j < nums.size(); ++j)
          if (nums[j] > nums[i - 1]) {
            swap(nums[j], nums[i - 1]);
            return;
          }
      }
    }
    reverse(nums.begin(), nums.end());
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> v{2, 4, 3, 1};
  s.nextPermutation(v);
  return 0;
}