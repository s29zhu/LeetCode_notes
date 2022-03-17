#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */

// @lc code=start
class Solution {
  vector<int> indices;
  random_device rd;
  mt19937 gen;
  std::uniform_int_distribution<> distrib;

 public:
  Solution(vector<int>& w) : gen(rd()) {
    indices.resize(w.size(), 0);
    indices[0] = w[0];
    for (int i = 1; i < w.size(); ++i) indices[i] = indices[i - 1] + w[i];
    distrib.param(
        uniform_int_distribution<int>::param_type{0, indices.back() - 1});
  }

  int pickIndex() {
    return upper_bound(indices.begin(), indices.end(), distrib(gen)) -
           indices.begin();
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end
