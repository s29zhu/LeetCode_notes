#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
 public:
  int trap(vector<int>& height) {
    int rst = 0;
    stack<int> s;
    for (int i = 0; i < height.size(); ++i) {
      while (!s.empty() && height[i] > height[s.top()]) {
        int t = s.top();
        s.pop();
        if (s.empty()) break;
        rst +=
            (i - s.top() - 1) * (min(height[i], height[s.top()]) - height[t]);
      }
      s.push(i);
    }
    return rst;
  }

  /*   int trap(vector<int>& height) {
      int water = 0, N = height.size();
      vector<int> indices(N, 0);
      for (int i = 0; i < N; ++i) indices[i] = i;
      sort(indices.begin(), indices.end(),
           [&height](int i, int j) { return height[i] > height[j]; });
      int start = indices[0], end = indices[0];
      for (int i = 1; i < N; ++i) {
        int j = indices[i];
        if (j < start) {
          water += height[j] * (start - j - 1);
          start = j;
        } else if (j > end) {
          water += height[j] * (j - end - 1);
          end = j;
        } else {
          water -= height[j];
        }
      }
      return water;
    }
   */
};
// @lc code=end

int main() {
  Solution s;
  vector<int> h{12, 2, 1, 5, 1, 3, 1};
  int r = s.trap(h);
  cout << r << endl;
  return 0;
}