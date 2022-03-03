#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
 public:
  int numTrees(int n) {
    vector<int> v(n + 1, 0);
    v[0] = 1;
    v[1] = 1;
    for (int i = 2; i <= n; ++i)
      for (int j = 0; j < i; ++j) v[i] += v[j] * v[i - 1 - j];
    return v[n];
  }
};
// @lc code=end

int main() {
  Solution s;
  int a = s.numTrees(4);

  return 0;
}