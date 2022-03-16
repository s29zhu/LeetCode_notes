#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=1570 lang=cpp
 *
 * [1570] Dot Product of Two Sparse Vectors
 */

// @lc code=start
class SparseVector {
  vector<array<int, 2>> data;

 public:
  SparseVector(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) data.push_back({i, nums[i]});
  }

  // Return the dotProduct of two sparse vectors
  int dotProduct(SparseVector& vec) {
    int i = 0, j = 0, rst = 0;
    while (i < data.size() && j < vec.data.size()) {
      if (data[i][0] == vec.data[j][0])
        rst += data[i++][1] * vec.data[j++][1];
      else if (data[i][0] < vec.data[j][0])
        i++;
      else
        j++;
    }
    return rst;
  }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
// @lc code=end
