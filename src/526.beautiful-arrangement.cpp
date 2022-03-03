#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 */

// @lc code=start
class Solution {
 public:
  int countArrangement(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = i + 1;
    int rst = 0;
    permutate(a, 0, rst);
    return rst;
  }

  bool divisible(int i, int j) { return (i % j == 0) || (j % i == 0); }

  void permutate(vector<int>& a, int n, int& rst) {
    if (divisible(a[n], n + 1)) {
      if (n == a.size() - 1) {
        ++rst;
        return;
      }
      permutate(a, n + 1, rst);
    }

    for (int i = n + 1; i < a.size(); ++i) {
      if (!divisible(a[i], n + 1)) continue;
      swap(a[i], a[n]);
      permutate(a, n + 1, rst);
      swap(a[i], a[n]);
    }
  }
};
// @lc code=end
