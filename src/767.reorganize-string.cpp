#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */

// @lc code=start
class Solution {
 public:
  string reorganizeString(string s) {
    unordered_map<char, int> counts;
    for (auto& i : s) ++counts[i];
    priority_queue<pair<int, char>> q;
    for (auto& i : counts) q.push({i.second, i.first});
    string rst;
    while (q.size() > 1) {
      array<pair<int, char>, 2> c;
      for (int i = 0; i < 2; ++i) {
        c[i] = q.top();
        q.pop();
        rst.push_back(c[i].second);
      }
      for (int i = 0; i < 2; ++i)
        if (c[i].first > 1) q.push({c[i].first - 1, c[i].second});
    }
    if (q.size() == 1) {
      return q.top().first > 1 ? "" : rst + q.top().second;
    }
    return rst;
  }
};
// @lc code=end
