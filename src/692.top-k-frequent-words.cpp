#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> count;
    for (auto& i : words) ++count[i];

    auto comp = [&count](string& a, string& b) {
      return count[a] == count[b] ? a < b : count[a] > count[b];
    };

    priority_queue<string, vector<string>, decltype(comp)> q(comp);
    for (auto& i : count) q.push(i.second);

    vector<string> rst(k);
    for (int i = 0; i < k; ++i) {
      v[k - 1 - i] = q.top();
      q.pop();
    }
    return rst;
  }
};
// @lc code=end
