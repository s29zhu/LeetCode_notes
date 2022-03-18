#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<>> h;
    for (int i = 0; i < k; ++i) h.push(nums[i]);
    for (int i = k; i < nums.size(); ++i)
      if (h.top() < nums[i]) {
        h.pop();
        h.push(nums[i]);
      }
    return h.top();
  }
};
// @lc code=end
