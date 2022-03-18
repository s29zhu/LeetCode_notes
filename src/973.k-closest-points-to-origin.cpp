#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<int> indices(k);
    for (int i = 0; i < k; ++i) indices[i] = i;

    auto comp = [&points](int a, int b) {
      return points[a][0] * points[a][0] + points[a][1] * points[a][1] <
             points[b][0] * points[b][0] + points[b][1] * points[b][1];
    };

    make_heap(indices.begin(), indices.end(), comp);
    for (int i = k; i < points.size(); ++i)
      if (comp(i, indices.front())) {
        pop_heap(indices.begin(), indices.end(), comp);
        indices.back() = i;
        push_heap(indices.begin(), indices.end(), comp);
      }

    vector<vector<int>> rst;
    rst.reserve(k);
    for (auto& i : indices) rst.push_back(points[i]);
    return rst;
  }
};
// @lc code=end

int main() {
  vector<vector<int>> points{{2, 2}, {1, 2}, {1, 1}};
  Solution s;
  auto r = s.kClosest(points, 1);

  return 0;
}