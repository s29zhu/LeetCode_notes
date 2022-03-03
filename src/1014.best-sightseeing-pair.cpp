#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
class Solution {
 public:
  int maxScoreSightseeingPair(vector<int>& values) {
    auto score = [&values](int p1, int p2) {
      return values[p1] + values[p2] + p1 - p2;
    };
    int f = 0, best_score = score(0, 1);
    for (int i = 1; i < values.size(); ++i) {
      best_score = max(score(f, i), best_score);
      if (values[i] + i - f > values[f]) f = i;
    }
    return best_score;
  }
};
// @lc code=end
